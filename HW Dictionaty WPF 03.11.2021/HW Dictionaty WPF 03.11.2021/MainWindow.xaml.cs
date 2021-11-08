using System.Collections.Generic;
using System.Windows;

namespace HW_Dictionary_WPF_03._11._2021
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        internal static Dictionary<string, string> dic = new();

        public MainWindow()
        {
            InitializeComponent();
        }

        private void AddWord_Click(object sender, RoutedEventArgs e)
        {
            this.Hide();
            new AddWordWindow().ShowDialog();
            this.Show();
        }

        private void Examine_Click(object sender, RoutedEventArgs e)
        {
            Hide();
            new Examine().ShowDialog();
            Show();
        }

        private void SearchByUkr_Click(object sender, RoutedEventArgs e)
        {
            Hide();
            new SearchByUkr().ShowDialog();
            Show();
        }

        private void SearchByRus_Click(object sender, RoutedEventArgs e)
        {
            Hide();
            new SearchByRus().ShowDialog();
            Show();
        }
    }
}
