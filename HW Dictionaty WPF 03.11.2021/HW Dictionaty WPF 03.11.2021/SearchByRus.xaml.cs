using System.Linq;
using System.Text.RegularExpressions;
using System.Windows;

namespace HW_Dictionary_WPF_03._11._2021
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
            Regex rus = new(@"^[а-яА-Я-]+$");

            if (!rus.IsMatch(SearchWordTextBlockRus.Text))
            {
                MessageBox.Show("Неправильно ввели Рус. слово!");
                return;
            }

            var res = MainWindow.dic.FirstOrDefault((p) => p.Value == SearchWordTextBlockRus.Text);

            TextBlockUkr.Text = res.Value != null ? res.Key : "Не найдено!";
        }
    }
}
