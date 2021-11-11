using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for Minesweeper.xaml
    /// </summary>
    public partial class Minesweeper : Window
    {
        public Minesweeper()
        {
            InitializeComponent();
            for (int x = 0; x < App.SizeX; x++)
            {
                for (int y = 0; y < App.SizeY; y++)
                {
                    var mineLabel = new MineLabel
                    {
                        X = x,
                        Y = y,
                        Content = "\x224b",
                        FontSize = 30,
                        VerticalContentAlignment = VerticalAlignment.Center,
                        HorizontalContentAlignment = HorizontalAlignment.Center
                    };
                    mineLabel.MouseDown += MineLabel_MouseDown;
                    Field.Children.Add(mineLabel);
                }
            }
        }

        private void MineLabel_MouseDown(object sender, MouseButtonEventArgs e)
        {
            var mineLabel = sender as MineLabel;
            var r = new Random();

            if (mineLabel == null)
            {
                return;
            }

            mineLabel.Content = r.Next(0, 9);

            switch (mineLabel.Content)
            {
                case 0:
                    mineLabel.Background = Brushes.Crimson;
                    break;
                case 1:
                    mineLabel.Background = Brushes.Orange;
                    break;
                case 2:
                    mineLabel.Background = Brushes.GreenYellow;
                    break;
                case 3:
                    mineLabel.Background = Brushes.DarkGreen;
                    break;
                case 4:
                    mineLabel.Background = Brushes.DarkBlue;
                    break;
                case 5:
                    mineLabel.Background = Brushes.DeepSkyBlue;
                    break;
                case 6:
                    mineLabel.Background = Brushes.BlueViolet;
                    break;
                case 7:
                    mineLabel.Background = Brushes.DeepPink;
                    break;
                case 8:
                    mineLabel.Background = Brushes.Brown;
                    break;
            }
            //MessageBox.Show("Click " + mineLabel.X + " " + mineLabel.Y);
        }
    }

    class MineLabel : Label
    {
        public int X { get; set; }
        public int Y { get; set; }
    }
}
