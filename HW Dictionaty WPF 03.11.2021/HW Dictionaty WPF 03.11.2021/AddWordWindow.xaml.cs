using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Windows;
using System.Text.Json;
using System.Text.Json.Serialization;

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
                Regex r = new(@"^[а-яА-Я-]+$");

                if (!r.IsMatch(AddWordTextBlockUkr.Text))
                {
                    MessageBox.Show("Неправильно ввели Укр. слово!");
                }

                if (!r.IsMatch(AddWordTextBlockRus.Text))
                {
                    MessageBox.Show("Неправильно ввели Рус. слово!");
                    return;
                }

                MainWindow.dic.Add(AddWordTextBlockUkr.Text, AddWordTextBlockRus.Text);

                //string fileName = "Dictionary.dic";
                //string jsonString = JsonSerializer.Serialize<Dictionary<string, string>>(MainWindow.dic);
                //File.WriteAllText(fileName, jsonString);

                ConfirmLabel.Content = "Добавлено!";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
