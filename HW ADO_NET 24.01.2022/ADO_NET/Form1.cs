﻿using ADO_NET.Models;
using Microsoft.Extensions.Configuration;
using System;
using System.Data;
using System.Data.SqlClient;
using System.IO;
using System.Windows.Forms;

namespace ADO_NET
{
    public partial class Form1 : Form
    {
        private SqlConnection _connection;
        private readonly string _tableName;
        private readonly IConfiguration _configuration;
        private string dbMode = string.Empty;

        public Form1()
        {


            //вынести в хелпер
            string currentDir = Application.StartupPath;
            int binIndex = currentDir.IndexOf(@"\bin\");

            //добавить метод проверки радиокнопок (без обработчика событий)
            //решить вопрос если радиокнопки не отмечены то ЕХ
            // проверить в радиокнопках если выбрана после того, как открыто подключение
            // напомнить про присоединенный\отсоединенный режим

            string projectPath = binIndex == -1 ? currentDir : currentDir.Substring(0, binIndex);

            //для себя, чтоб можно было легко менять строки
            //var connectionStrings = new Dictionary<string, string>{
            //    { "Desktop DB", @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=J:\GitHub\HW ADO_NET 24.01.2022\ADO_NET\Database1.mdf;Integrated Security=True" },
            //    { "Laptop DB", @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\vladislav.yavorskiy\OneDrive\Документы\ШАГ\HW ADO_NET 24.01.2022\ADO_NET\Database1.mdf;Integrated Security=True" }
            //};

            try
            {
                _configuration = new ConfigurationBuilder()
                    .AddJsonFile(projectPath + @"\appsettings.json")
                    .Build();
            }
            catch (FileNotFoundException ex)
            {
                MessageBox.Show(ex.Message);
                Close();
                Application.Exit();
                return;
            }


            _tableName = "Nums";

            InitializeComponent();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            try
            {
                if (SqlConnectionChecker())
                {
                    MessageBox.Show(@"Connection is already opened");
                    return;
                }

                _connection.Open();
                listBox1.Items.Add("Connected");
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void buttonCreate_Click(object sender, EventArgs e)
        {
            if (!SqlConnectionChecker())
            {
                MessageBox.Show(@"Open connection first");
                return;
            }

            if (IsTableExists())
            {
                return;
            }

            SqlCommand cmd = new SqlCommand();

            cmd.Connection = _connection;
            // создание таблицы
            cmd.CommandText = $@"
                CREATE TABLE {_tableName}(
                  id  UNIQUEIDENTIFIER PRIMARY KEY,
                  num INT
                ) ";

            try
            {
                cmd.ExecuteNonQuery();
                listBox1.Items.Add("CREATE TABLE Ok");
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void buttonInsert_Click(object sender, EventArgs e)
        {
            if (!SqlConnectionChecker())
            {
                MessageBox.Show(@"Open connection first");
                return;
            }

            using SqlCommand cmd = new SqlCommand();

            cmd.Connection = _connection;
            cmd.CommandText = @$"INSERT INTO {_tableName}"
                              + " VALUES( NEWID(), "
                              + DateTime.Now.Millisecond
                              + ")";

            try
            {
                cmd.ExecuteNonQuery();
                listBox1.Items.Add("INSERT Ok");
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void buttonDisconnect_Click(object sender, EventArgs e)
        {
            try
            {
                if (!SqlConnectionChecker())
                {
                    MessageBox.Show(@"Connection is already closed");
                    return;
                }

                _connection.Close();
                listBox1.Items.Add("Disconnected");
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private bool SqlConnectionChecker()
        {
            return _connection.State is ConnectionState.Open; //best practices от Microsoft'а подъехали))
        }

        private bool IsTableExists()
        {
            //не хватило мне мозгов придумать красивее решение

            SqlCommand cmd = new SqlCommand();
            bool tableExists = true;

            cmd.Connection = _connection;
            cmd.CommandText = $@"SELECT COUNT(*) FROM {_tableName}";

            try
            {
                cmd.ExecuteScalar();
            }
            catch (SqlException)
            {
                tableExists = false;
            }

            return tableExists;
        }

        private void buttonSelect_Click(object sender, EventArgs e)
        {
            if (!SqlConnectionChecker())
            {
                MessageBox.Show(@"Open connection first");
                return;
            }

            using var cmd = new SqlCommand($@"SELECT * FROM {_tableName}", _connection);

            try
            {
                SqlDataReader result = cmd.ExecuteReader();
                listBox1.Items.Add("==================");

                while (result.Read())
                {
                    //пример
                    //result.GetGuid(0); //от начала результата
                    //result.GetInt32(1);

                    listBox1.Items.Add(string.Format($"{result.GetGuid("id")} - {result.GetInt32("num")}"));
                }

                result.Close();
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void SelectModel_Click(object sender, EventArgs e)
        {
            if (!SqlConnectionChecker())
            {
                MessageBox.Show(@"Open connection first");
                return;
            }

            ContextDb data = new ContextDb(_connection);

            try
            {
                //поздно уже играться чтобы поле масштабировалось, и так сойдет
                //может на паре подскажете)
                dataGridView1.DataSource = data.Nums;

                listBox1.Items.Add("++++++++++++++++++");
                foreach (var row in data.Nums)
                {
                    listBox1.Items.Add(string.Format($"{row.Id} - {row.Val}"));
                }
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void LaptopDb_CheckedChanged(object sender, EventArgs e)
        {
            if (LaptopDb.Checked)
            {
                dbMode = "laptopDb";
                try
                {
                    _connection = new SqlConnection(_configuration.GetConnectionString(dbMode));
                }
                catch (SqlException ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
        }

        private void DesktopDb_CheckedChanged(object sender, EventArgs e)
        {
            if (DesktopDb.Checked)
            {
                dbMode = "desktopDb";
                try
                {
                    _connection = new SqlConnection(_configuration.GetConnectionString(dbMode));
                }
                catch (SqlException ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
        }
    }
}