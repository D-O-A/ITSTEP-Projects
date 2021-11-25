using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using System.Text.RegularExpressions;
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
            Regex ukr = new(@"^[А-ЩЬЮЯҐЄІЇа-щьюяґєії'-]+$");

            if (!ukr.IsMatch(SearchWordTextBlockUkr.Text))
            {
                MessageBox.Show("Неправильно ввели Укр. слово!");
                return;
            }

            if (MainWindow.dic.Remove(SearchWordTextBlockUkr.Text))
            {
                TextBlockResult.Text = "Слово удалено!";

                string jsonString = JsonSerializer.Serialize<Dictionary<string, string>>(MainWindow.dic);
                File.WriteAllText(MainWindow.fileName, jsonString);
            }
            else
            {
                TextBlockResult.Text = "Слово не найдено!";
            }
        }

        private void SearchWordTextBlockUkr_OnGotFocus(object sender, RoutedEventArgs e)
        {
            TextBlockResult.Text = "";
        }
    }
}
