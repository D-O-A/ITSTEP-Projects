using System;
using System.Text.RegularExpressions;
using System.Windows;

namespace HW_Dictionaty_WPF_03._11._2021
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
                Regex r = new Regex(@"^[а-яА-Я-]+$");

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
                ConfirmLabel.Content = "Добавлено!";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void SaveButton(object sender, RoutedEventArgs e)
        {

            //XmlSerializer serializer = new XmlSerializer(typeof(Dictionary<string, string>));

            //using (StreamWriter writer = new StreamWriter("dictionary.dic"))
            //{
            //    serializer.Serialize(writer, dic);
            //    MessageBox.Show("Сохранено!");
            //}

            Close();
        }
    }
}
