using System.Linq;
using System.Text.RegularExpressions;
using System.Windows;

namespace HW_Dictionaty_WPF_03._11._2021
{
    /// <summary>
    /// Interaction logic for SearchByRus.xaml
    /// </summary>
    public partial class SearchByRus : Window
    {
        public SearchByRus()
        {
            InitializeComponent();
        }

        private void Search_Click(object sender, RoutedEventArgs e)
        {
            Regex r = new Regex(@"^[а-яА-Я-]+$");

            if (!r.IsMatch(SearchWordTextBlockRus.Text))
            {
                MessageBox.Show("Неправильно ввели Укр. слово!");
                return;
            }

            var res = MainWindow.dic.FirstOrDefault((p) => p.Value == SearchWordTextBlockRus.Text);

            TextBlockUkr.Text = res.Value != null ? res.Key : "Не найдено!";
        }
    }
}
