using System;
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
using System.Windows.Shapes;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for Tabs.xaml
    /// </summary>
    public partial class Tabs : Window
    {
        private bool mouseHold;

        public Tabs()
        {
            InitializeComponent();
            mouseHold = false;
        }

        private void StackPanel_MouseMove(object sender, MouseEventArgs e)
        {
            MouseX.Text = e.GetPosition(this).X.ToString();
            MouseY.Text = e.GetPosition(this).Y.ToString();

            if(mouseHold)
            {
                var p = new Ellipse
                {
                    Fill = Brushes.Blue,
                    Width = 10,
                    Height = 10
                };

                Canvas.Children.Add(p);
                Canvas.SetLeft(p, e.GetPosition(Canvas).X);
                Canvas.SetTop(p, e.GetPosition(Canvas).Y);
            }
        }

        private void Canvas_MouseDown(object sender, MouseButtonEventArgs e)
        {
            mouseHold = true;

            var p = new Ellipse
            {
                Fill = (e.ChangedButton == MouseButton.Left) ? Brushes.Red : Brushes.Blue,
                Width = 10,
                Height = 10
            };

            Canvas.Children.Add(p);
            Canvas.SetLeft(p, e.GetPosition(Canvas).X);
            Canvas.SetTop(p, e.GetPosition(Canvas).Y);
        }

        private void Canvas_MouseUp(object sender, MouseButtonEventArgs e)
        {
            mouseHold = false;

            if (e.ChangedButton == MouseButton.Middle)
            {
                Canvas.Children.Clear();
            }
        }

        private void window_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            var r = new Rectangle
            {
                Fill = Brushes.LimeGreen,
                Width = 15,
                Height = 15
            };

            Canvas.Children.Add(r);
            Canvas.SetLeft(r, e.GetPosition(Canvas).X);
            Canvas.SetTop(r, e.GetPosition(Canvas).Y);
        }
    }
}
