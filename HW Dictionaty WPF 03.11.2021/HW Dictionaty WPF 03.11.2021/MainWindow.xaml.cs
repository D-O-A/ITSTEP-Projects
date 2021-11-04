using System.Windows;

namespace HW_Dictionaty_WPF_03._11._2021
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void AddWord_Click(object sender, RoutedEventArgs e)
        {
            new AddWordWindow().Show();
        }
    }
}
