using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using System.Windows;


namespace HW_Dictionary_WPF_03._11._2021
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        internal static Dictionary<string, string> dic = new();
        internal const string fileName = "Dictionary.dic";
        public MainWindow()
        {
            InitializeComponent();
            Deserialize();
        }

        private void AddWord_Click(object sender, RoutedEventArgs e)
        {
            this.Hide();
            new AddWordWindow().ShowDialog();
            this.Show();
        }

        private void Examine_Click(object sender, RoutedEventArgs e)
        {
            Hide();
            new Examine().ShowDialog();
            Show();
        }

        private void SearchByUkr_Click(object sender, RoutedEventArgs e)
        {
            Hide();
            new SearchByUkr().ShowDialog();
            Show();
        }

        private void SearchByRus_Click(object sender, RoutedEventArgs e)
        {
            Hide();
            new SearchByRus().ShowDialog();
            Show();
        }

        private void RemoveWord_Click(object sender, RoutedEventArgs e)
        {
            Hide();
            new RemoveWord().ShowDialog();
            Show();
        }

        private void Deserialize()
        {
            try
            {
                string jsonString = File.ReadAllText(fileName);
                dic = JsonSerializer.Deserialize<Dictionary<string, string>>(jsonString) ?? throw new InvalidOperationException();
            }
            catch (FileNotFoundException)
            {
                //ignored
            }
            catch (InvalidOperationException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
