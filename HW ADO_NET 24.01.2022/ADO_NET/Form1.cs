using ADO_NET.Helpers;
using ADO_NET.Models;
using Microsoft.Extensions.Configuration;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace ADO_NET
{
    public partial class Form1 : Form
    {
        private readonly SqlConnection _connection;
        private readonly string _tableName;
        private readonly Dictionary<string, string> _connectionStrings;
        private readonly List<RadioButton> _radioButtons;

        public Form1()
        {
            // напомнить про присоединенный\отсоединенный режим
            IConfiguration configuration;
            _connectionStrings = new Dictionary<string, string>();
            _radioButtons = new List<RadioButton>();
            _connection = new SqlConnection();
            _tableName = "Nums";
            var radioButtonCoord = new Point(27, 12);

            try
            {
                configuration = new ConfigurationBuilder()
                    .AddJsonFile(CurrentDirHelper.GetCurrentDir() + @"\appsettings.json")
                    .Build();
            }
            catch (FileNotFoundException ex)
            {
                MessageBox.Show(ex.Message);
                Close();
                Application.Exit();
                return;
            }
            catch (InvalidDataException ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }

            foreach (var connectionString in configuration.GetSection("ConnectionStrings").GetChildren())
            {
                _connectionStrings.Add(connectionString.Key, connectionString.Value);
            }

            _radioButtons = RadioButtonBuilderHelper.BuildRadioButton(_connectionStrings, radioButtonCoord);

            foreach (var button in _radioButtons)
            {
                Controls.Add(button);
            }

            InitializeComponent();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            ConnectionCreator(_radioButtons);

            try
            {
                if (SqlConnectionChecker())
                {
                    //MessageBox.Show(@"Connection is already opened");
                    listBox1.Items.Add("Connection is already opened");
                    return;
                }

                OpenConnection();
            }
            catch (SqlException ex)
            {
                //MessageBox.Show(ex.Message);
                listBox1.Items.Add(ex.Message);
            }
        }

        private void buttonCreate_Click(object sender, EventArgs e)
        {
            if (!SqlConnectionChecker())
            {
                //MessageBox.Show(@"Open connection first");
                listBox1.Items.Add("Open connection first");
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
                //MessageBox.Show(ex.Message);
                listBox1.Items.Add(ex.Message);
            }
        }

        private void buttonInsert_Click(object sender, EventArgs e)
        {
            if (!SqlConnectionChecker())
            {
                //MessageBox.Show(@"Open connection first");
                listBox1.Items.Add("Open connection first");
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
                //MessageBox.Show(ex.Message);
                listBox1.Items.Add(ex.Message);
            }
        }

        private void buttonDisconnect_Click(object sender, EventArgs e)
        {
            try
            {
                if (!SqlConnectionChecker())
                {
                    //MessageBox.Show(@"Connection is already closed");
                    listBox1.Items.Add("Connection is already closed");
                    return;
                }

                CloseConnection();
            }
            catch (SqlException ex)
            {
                //MessageBox.Show(ex.Message);
                listBox1.Items.Add(ex.Message);
            }
        }

        private bool SqlConnectionChecker()
        {
            return _connection.State is ConnectionState.Open; //best practices от Microsoft'а подъехали))
        }

        private bool IsTableExists()
        {
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
                //MessageBox.Show(@"Open connection first");
                listBox1.Items.Add("Open connection first");
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
                //MessageBox.Show(ex.Message);
                listBox1.Items.Add(ex.Message);
            }
            catch (Exception ex)
            {
                //MessageBox.Show(ex.Message);
                listBox1.Items.Add(ex.Message);
            }
        }

        private void SelectModel_Click(object sender, EventArgs e)
        {
            if (!SqlConnectionChecker())
            {
                //MessageBox.Show(@"Open connection first");
                listBox1.Items.Add("Open connection first");
                return;
            }

            ContextDb data = new ContextDb(_connection);

            try
            {
                dataGridView1.DataSource = data.Nums;

                listBox1.Items.Add("++++++++++++++++++");
                foreach (var row in data.Nums)
                {
                    listBox1.Items.Add(string.Format($"{row.Id} - {row.Val}"));
                }
            }
            catch (SqlException ex)
            {
                //MessageBox.Show(ex.Message);
                listBox1.Items.Add(ex.Message);
            }
            catch (Exception ex)
            {
                //MessageBox.Show(ex.Message);
                listBox1.Items.Add(ex.Message);
            }
        }

        private void ConnectionCreator(List<RadioButton> buttons)
        {
            foreach (var button in buttons.Where(button => button.Checked))
            {
                try
                {
                    if (!IsConnectionStringEmpty(_connection))
                    {
                        return;
                    }

                    _connection.ConnectionString = _connectionStrings.FirstOrDefault(c => c.Key == button.Name).Value;
                }
                catch (SqlException ex)
                {
                    //MessageBox.Show(ex.Message);
                    listBox1.Items.Add(ex.Message);
                }
                catch (ArgumentException)
                {
                    //MessageBox.Show("Wrong connection string format");
                    listBox1.Items.Add("Wrong connection string format");
                }
            }
        }

        private void OpenConnection()
        {
            try
            {
                if (_connectionStrings.Count is 0)
                {
                    //MessageBox.Show("Connections not found");
                    listBox1.Items.Add("Connection not found");
                    return;
                }

                _connection.Open();
                listBox1.Items.Add("Connected");
            }
            catch (SqlException)
            {
                //MessageBox.Show(ex.Message);
                listBox1.Items.Add("Failed to connect to database");
                _connection.ConnectionString = string.Empty;
            }
            catch (Exception)
            {
                //MessageBox.Show("Connection string not found");
                listBox1.Items.Add("Connection string not found");
            }
        }

        private void CloseConnection()
        {
            try
            {
                _connection.Close();
                _connection.ConnectionString = string.Empty;
                listBox1.Items.Add("Disconnected");
            }
            catch (SqlException ex)
            {
                //MessageBox.Show(ex.Message);
                listBox1.Items.Add(ex.Message);
            }
        }

        private bool IsConnectionStringEmpty(SqlConnection connection)
        {
            return connection.ConnectionString == string.Empty;
        }
    }
}