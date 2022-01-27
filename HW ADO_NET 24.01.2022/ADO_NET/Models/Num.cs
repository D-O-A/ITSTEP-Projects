using System;
using System.Collections.Generic;
using System.Data.SqlClient;

namespace ADO_NET.Models
{
    //ORM - класс со структурой, как у таблицы БД
    public class Num
    {
        public string Id { get; set; }
        public int Val { get; set; }
    }

    //Context - окружение, отражение всей БД - набора таблиц
    public class ContextDb
    {
        public List<Num> Nums;

        public ContextDb(SqlConnection connection)
        {
            if (connection is null)
            {
                throw new ArgumentNullException("Connection is NULL");
            }
            //        0   1
            using var cmd = new SqlCommand($@"SELECT id, num FROM Nums", connection);

            try
            {
                var result = cmd.ExecuteReader();
                Nums = new List<Num>();

                while (result.Read())
                {
                    Nums.Add(new Num { Id = result.GetGuid(0).ToString(), Val = result.GetInt32(1) });
                }

                result.Close();
            }
            catch
            {
                throw;
            }
        }
    }
}
