using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using System.Text.RegularExpressions;
using System.Windows;

namespace HW_Dictionary_WPF_03._11._2021
{
    /// <summary>
    /// Interaction logic for AddWordWindow.xaml
    /// </summary>
    public partial class AddWordWindow : Window
    {

        public AddWordWindow()
        {
            InitializeComponent();
        }

        private void AddButton(object sender, RoutedEventArgs e)
        {
            try
            {
                Regex ukr = new(@"^[А-ЩЬЮЯҐЄІЇа-щьюяґєії'-]+$");
                Regex rus = new(@"^[а-яА-Я-]+$");

                if (!ukr.IsMatch(AddWordTextBlockUkr.Text))
                {
                    MessageBox.Show("Неправильно ввели Укр. слово!");
                    return;
                }

                if (!rus.IsMatch(AddWordTextBlockRus.Text))
                {
                    MessageBox.Show("Неправильно ввели Рус. слово!");
                    return;
                }

                MainWindow.dic.Add(AddWordTextBlockUkr.Text, AddWordTextBlockRus.Text);

                string jsonString = JsonSerializer.Serialize<Dictionary<string, string>>(MainWindow.dic);
                File.WriteAllText(MainWindow.fileName, jsonString);

                ConfirmLabel.Content = "Добавлено!";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void AddWordTextBlockUkr_OnGotFocus(object sender, RoutedEventArgs e)
        {
            ConfirmLabel.Content = "";
        }


        private void AddWordTextBlockRus_OnGotFocus(object sender, RoutedEventArgs e)
        {
            ConfirmLabel.Content = "";
        }
    }
}
