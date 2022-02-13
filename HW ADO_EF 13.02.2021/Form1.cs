using System;
using System.Linq;
using System.Windows.Forms;

namespace ADO_EF
{
    public partial class Form1 : Form
    {
        private readonly Model.FirmContext Firm;
        private readonly Random random = new();

        public Form1()
        {
            InitializeComponent();
            Firm = new Model.FirmContext();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //Firm.InstallDepartments();
            //Firm.InstallManagers();
            //Firm.InstallProducts();

            labelDepartments.Text = Firm.Departments.Count().ToString();
            labelManagers.Text = Firm.Managers.Count().ToString();
            labelProducts.Text = Firm.Products.Count().ToString();
            labelSales.Text = Firm.Sales.Count().ToString();
        }

        private void buttonDepartments_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            foreach (var dep in
                Firm.Departments.OrderBy(d => d.Name))
            {
                listBox1.Items.Add(dep);
            }
        }

        private void buttonManagers_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();

            foreach (var man in
                     Firm.Managers.OrderBy(d => d.Name))
            {
                listBox1.Items.Add(man);
            }

        }

        private void buttonProdPrice_Click(object sender, EventArgs e)
        {
            var query = Firm.Products
                .Where(p => p.Price > 100)
                .OrderByDescending(p => p.Price);

            listBox1.Items.Clear();
            foreach (Model.Product p in query)
            {
                listBox1.Items.Add(p);
            }
        }

        private void buttonGenerate_Click(object sender, EventArgs e)
        {
            buttonGenerate.Enabled = false;
            #region Генерация и обновление статистики
            // Count:
            int n = 0;
            try
            {
                n = Convert.ToInt32(genCnt.Text);
            }
            catch
            {
                MessageBox.Show("Количество не распознано");
                return;
            }
            // Generation

            while (n > 0)
            {
                Firm.Sales.Add(new Model.Sale
                {
                    Id = Guid.NewGuid(),

                    Id_Manager = Firm.Managers          // Случайная выборка - вар. 1
                        .OrderBy(m => m.Id)             // Упорядочиваем по Id (можно любое поле)
                        .Skip(                          // Пропускаем первые элементы результата
                            random.Next(                //  в количестве - случайное число
                                Firm.Managers.Count())) //   в пределах размера исходной коллекции
                        .First()                        // Выбираем первый элемент (после отступа)
                        .Id,                            // Берем из него Id

                    Id_Product = Firm.Products          // Случайная выборка - вар. 2
                        .OrderBy(                       // Используем тот факт, что запрос будет переведен в SQL
                            p => Guid.NewGuid())        //  здесь получится ORDER BY NEWID() - вся таблица сортируется в случайном порядке
                        .First()                        // Выбираем первый элемент (из всего результата)
                        .Id,                            // Берем из него Id

                    Cnt = random.Next(1, 10),

                    Moment = DateTime.Parse("2021-01-01")
                        .AddSeconds(random.Next(60 * 60 * 24 * 365))
                });

                --n;
            }
            Firm.SaveChanges();

            // Displaying
            labelSales.Text = Firm.Sales.Count().ToString();
            #endregion
            buttonGenerate.Enabled = true;
        }

        private void buttonSalesAll_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            foreach (var item in
                Firm.Sales
                .Join(Firm.Managers, s => s.Id_Manager, m => m.Id,
                (Sale, Manager) => new { Sale, Manager })
                .Join(Firm.Products, SM => SM.Sale.Id_Product, p => p.Id,
                (SM, Product) => new { SM.Sale, SM.Manager, Product })

            )
            {
                listBox1.Items.Add(
                    item.Sale.Moment.ToShortDateString()
                    + " "
                    + item.Manager.Surname
                        + " " + item.Manager.Name.Substring(0, 1) + "."
                        + " " + item.Manager.SecName.Substring(0, 1) + "."
                    );
            }

        }
    }
}
