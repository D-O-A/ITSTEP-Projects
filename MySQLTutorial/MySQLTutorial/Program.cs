using System;
using MySql.Data;
using MySql.Data.MySqlClient;

namespace MySQLTutorial
{
    internal class Program
    {
        static void Main(string[] args)
        {

            var db = new DBConnect("localhost", "giraffe", "root", "password");

            db.Insert(Console.ReadLine());

        }
    }

    class DBConnect
    {
        private MySqlConnection connection;
        private string server;
        private string database;
        private string uid;
        private string password;

        //Constructor
        public DBConnect()
        {
            Initialize();
        }

        public DBConnect(string dbServerName, string dbName, string dbUserName, string dbPassword)
        {
            Initialize(dbServerName, dbName, dbUserName, dbPassword);
        }

        //Initialize values
        private void Initialize()
        {
            server = "localhost"; //адрес локального сервера
            database = "giraffe"; //имя созданной БД
            uid = "root"; //имя пользователя по умолчанию для локального сервера
            password = "password"; //свой заданный пароль

            string connectionString = "SERVER=" + server + ";" + "DATABASE=" + database + ";" + "UID=" + uid + ";" + "PASSWORD=" + password + ";";

            connection = new MySqlConnection(connectionString);
        }

        private void Initialize(string dbServerName, string dbName, string dbUserName, string dbPassword)
        {
            server = dbServerName;
            database = dbName;
            uid = dbUserName;
            password = dbPassword;

            string connectionString = "SERVER=" + server + ";" + "DATABASE=" +
                                      database + ";" + "UID=" + uid + ";" + "PASSWORD=" + password + ";";

            connection = new MySqlConnection(connectionString);
        }

        //open connection to database
        private bool OpenConnection()
        {
            try
            {
                connection.Open();
                Console.WriteLine("Connection opened");
                return true;
            }
            catch (MySqlException ex)
            {
                Console.WriteLine(ex.Message);
                return false;
            }
        }

        ////Close connection
        private bool CloseConnection()
        {
            try
            {
                connection.Close();
                return true;
            }
            catch (MySqlException ex)
            {
                Console.WriteLine(ex.Message);
                return false;
            }
        }

        ////Insert statement
        public void Insert(string sqlQuery)
        {
            string query = sqlQuery;

            //open connection
            if (OpenConnection())
            {
                //create command and assign the query and connection from the constructor
                var cmd = new MySqlCommand(query, connection);
                
                try
                {
                    //Execute command
                    Console.WriteLine("Rows affected: " + cmd.ExecuteNonQuery());
                }
                catch (MySqlException ex)
                {
                    Console.WriteLine(ex.Message);
                    return;
                }

                Console.WriteLine("Query executed");
                //close connection
                CloseConnection();
            }
        }

        ////Update statement
        //public void Update()
        //{
        //}

        ////Delete statement
        //public void Delete()
        //{
        //}

        ////Select statement
        //public List<string>[] Select()
        //{
        //}

        ////Count statement
        //public int Count()
        //{
        //}

        ////Backup
        //public void Backup()
        //{
        //}

        ////Restore
        //public void Restore()
        //{
        //}
    }
}
