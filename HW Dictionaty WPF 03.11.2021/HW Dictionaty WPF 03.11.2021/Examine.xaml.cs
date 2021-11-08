using System;
using System.Windows;

namespace HW_Dictionary_WPF_03._11._2021
{
    /// <summary>
    /// Interaction logic for Examine.xaml
    /// </summary>
    public partial class Examine : Window
    {
        public Examine()
        {
            try
            {
                InitializeComponent();

                foreach (var pair in MainWindow.dic)
                {
                    TextBlockUkr.Text += pair.Key + "\n";
                    TextBlockRus.Text += pair.Value + "\n";
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

    }
}
