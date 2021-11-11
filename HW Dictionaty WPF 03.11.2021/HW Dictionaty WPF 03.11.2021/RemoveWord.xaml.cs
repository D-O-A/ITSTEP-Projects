using System.Windows;

namespace HW_Dictionary_WPF_03._11._2021
{
    /// <summary>
    /// Interaction logic for RemoveWord.xaml
    /// </summary>
    public partial class RemoveWord : Window
    {
        public RemoveWord()
        {
            InitializeComponent();
        }

        private void Remove_Click(object sender, RoutedEventArgs e)
        {
            TextBlockResult.Text = MainWindow.dic.Remove(SearchWordTextBlockUkr.Text) ? "Слово удалено!" : "Слово не найдено!";
        }
    }
}
