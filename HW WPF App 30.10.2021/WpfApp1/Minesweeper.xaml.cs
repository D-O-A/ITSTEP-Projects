using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

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
            if (mineLabel == null)
            {
                return;
            }
            MessageBox.Show("Click " + mineLabel.X + " " + mineLabel.Y);
        }
    }

    class MineLabel : Label
    {
        public int X { get; set; }
        public int Y { get; set; }
    }
}
