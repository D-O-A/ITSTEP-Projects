using System.Windows;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for Portal.xaml
    /// </summary>
    public partial class Portal : Window
    {
        public Portal()
        {
            InitializeComponent();
        }

        private void Serialization_Click(object sender, RoutedEventArgs e)
        {
            new MainWindow().Show();
        }

        private void FracCalc_Click(object sender, RoutedEventArgs e)
        {
            new FracCalc().Show();

            //Dictionary<string, string> dic = new Dictionary<string, string>();
            //dic.Add("1", "one");
            //dic.Add("2", "two");

            //var res = dic.Where((p) => p.Key == "1").FirstOrDefault();
            //res = dic.Where((p) => p.Value == "two").FirstOrDefault();
            //res = dic.Where((p) => p.Value == "tw2").FirstOrDefault();

        }

        private void Strings_Click(object sender, RoutedEventArgs e)
        {
            new Strings().Show(); //немодальный режим
        }

        private void Tabs_Click(object sender, RoutedEventArgs e)
        {
            this.Hide();
            new Tabs().ShowDialog(); // модальный режим, окно, которое блокирует доступ к предидущему окну
            this.Show();
        }

        private void Tanks_Click(object sender, RoutedEventArgs e)
        {
            this.Hide();
            new Tanks().ShowDialog();
            this.Show();
        }

        private void Minesweeper_Click(object sender, RoutedEventArgs e)
        {
            Hide();
            new Minesweeper().ShowDialog();
            Show();
        }

        private void Arkanoid_Click(object sender, RoutedEventArgs e)
        {
            Hide();
            new Arkanoid().ShowDialog();
            Show();
        }

        private void Styles_Click(object sender, RoutedEventArgs e)
        {
            Hide();
            new Styles().ShowDialog();
            Show();
        }

        private void DnD_Click(object sender, RoutedEventArgs e)
        {
            Hide();
            new DnD().ShowDialog();
            Show();
        }
    }
}
