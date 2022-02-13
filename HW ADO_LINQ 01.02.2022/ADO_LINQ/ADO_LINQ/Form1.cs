using System;
using System.Windows.Forms;

namespace ADO_LINQ
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //Models.Firm firm = Program.DiContainer.Resolve<Models.Firm>();


            //var query = from d in firm.Departments select d;

            MessageBox.Show("NICE");
        }

        public string GetCurrentDir()
        {
            string currentDir = Application.StartupPath;
            int binIndex = currentDir.IndexOf(@"\bin\");

            return binIndex == -1 ? currentDir : currentDir.Substring(0, binIndex);
        }
    }
}
