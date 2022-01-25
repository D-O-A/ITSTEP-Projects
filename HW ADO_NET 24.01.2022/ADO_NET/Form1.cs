using System;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace ADO_NET
{
    public partial class Form1 : Form
    {
        private readonly SqlConnection _connection;
        private readonly string _tableName;

        public Form1()
        {
            InitializeComponent();
            _connection = new SqlConnection(
                @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=J:\GitHub\HW ADO_NET 24.01.2022\ADO_NET\Database1.mdf;Integrated Security=True"
            // - Desktop DB
            //Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename="J:\GitHub\HW ADO_NET 24.01.2022\ADO_NET\Database1.mdf";Integrated Security=True
            );

            _tableName = "Nums";
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

            if (IsTableExists()) return;

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
    }
}