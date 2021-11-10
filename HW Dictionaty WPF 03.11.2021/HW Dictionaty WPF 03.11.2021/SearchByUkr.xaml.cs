using System.Linq;
using System.Text.RegularExpressions;
using System.Windows;

namespace HW_Dictionary_WPF_03._11._2021
{
    /// <summary>
    /// Interaction logic for SearchByUkr.xaml
    /// </summary>
    public partial class SearchByUkr : Window
    {
        public SearchByUkr()
        {
            InitializeComponent();
        }

        private void Search_Click(object sender, RoutedEventArgs e)
        {
            Regex r = new(@"^[а-яА-Я-]+$");

            if (!r.IsMatch(SearchWordTextBlockUkr.Text))
            {
                MessageBox.Show("Неправильно ввели Укр. слово!");
                return;
            }

            var res = MainWindow.dic.FirstOrDefault((p) => p.Key == SearchWordTextBlockUkr.Text);

            TextBlockRus.Text = res.Key != null ? res.Value : "Не найдено!";
        }
    }
}
