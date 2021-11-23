using System.Windows;
using System.Windows.Controls;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for Styles.xaml
    /// </summary>
    public partial class Styles : Window
    {
        public Styles()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            uniGrid.Children.Add(new Label { Content = "Label 9" });
        }

        private void Button_Click2(object sender, RoutedEventArgs e)
        {
            uniGrid.Children.Add(new Label { Content = "Label Big", Style = FindResource("BigCentered") as Style });
        }

        private void Button_Click3(object sender, RoutedEventArgs e)
        {

        }
    }
}
