using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace IncrementalCalculator_21._10._2021
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            //при запуске окна считывает значение и размер шрифта из файла.
            //если не найдет файл для считывания, то отловится исключение и будет назначено значение "0" с размером шрифта 12
            try
            {
                using (var reader = new StreamReader("data.bin"))
                {
                    Number.Text = reader.ReadLine();
                    Number.FontSize = double.Parse(reader.ReadToEnd());
                }
            }
            catch(Exception)
            {
            }
        }

        private void Increment(object sender, RoutedEventArgs e)
        {
            int buffer = int.Parse(Number.Text);
            buffer++;
            Number.Text = buffer.ToString();
            Number.FontSize++;
        }

        private void Decrement(object sender, RoutedEventArgs e)
        {
            //нужен отлов на случай когда размер шрифта равен 0 (накликали на "-")
            try
            {
                int buffer = int.Parse(Number.Text);
                buffer--;
                Number.Text = buffer.ToString();
                Number.FontSize--;
            }
            catch(Exception)
            {
            }
        }

        private void WriteToFile(object sender, RoutedEventArgs e)
        {
            //сохраняем число и размер шрифта
            using(var writer = new StreamWriter("data.bin"))
            {
                writer.WriteLine(Number.Text);
                writer.Write(Number.FontSize);
            }
        }

        private void ReadFromFile(object sender, RoutedEventArgs e)
        {
            try
            {
                using (var reader = new StreamReader("data.bin"))
                {
                    Number.Text = reader.ReadLine();
                    Number.FontSize = double.Parse(reader.ReadToEnd());
                }
            }
            catch(IOException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
