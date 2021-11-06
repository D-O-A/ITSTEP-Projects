using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
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

            if (mouseHold)
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
            const int defaultFontSize = 12;
            const int defaultAngle = 0;

            if (e.ChangedButton == MouseButton.Middle)
            {
                //Back to default values
                X.FontSize = defaultFontSize;
                Y.FontSize = defaultFontSize;
                MouseX.FontSize = defaultFontSize;
                MouseY.FontSize = defaultFontSize;
                XAngle.Angle = defaultAngle;
                YAngle.Angle = defaultAngle;
                MouseXAngle.Angle = defaultAngle;
                MouseYAngle.Angle = defaultAngle;
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

        private void Window_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            bool mouseWheelUp = e.Delta > 0;
            const int angleChange = 10;
            //координаты текстблоков
            (int xStart, int xEnd, int yStart, int yEnd) xyRange = (5, 105, 35, 45);

            //x = 5-105
            //y = 35-45

            //отлов исключения чтобы не вылетало приложение если размер текста = 0
            try
            {
                switch (mouseWheelUp)
                {
                    case true when (e.GetPosition(this).X >= xyRange.xStart && e.GetPosition(this).X <= xyRange.xEnd) &&
                                   (e.GetPosition(this).Y >= xyRange.yStart && e.GetPosition(this).Y <= xyRange.yEnd):
                        X.FontSize++;
                        XAngle.Angle += angleChange;

                        Y.FontSize++;
                        YAngle.Angle += angleChange;

                        MouseX.FontSize++;
                        MouseXAngle.Angle += angleChange;

                        MouseY.FontSize++;
                        MouseYAngle.Angle += angleChange;
                        break;

                    case false
                        when (e.GetPosition(this).X >= xyRange.xStart && e.GetPosition(this).X <= xyRange.xEnd) &&
                             (e.GetPosition(this).Y >= xyRange.yStart && e.GetPosition(this).Y <= xyRange.yEnd):
                        X.FontSize--;
                        XAngle.Angle -= angleChange;

                        Y.FontSize--;
                        YAngle.Angle -= angleChange;

                        MouseX.FontSize--;
                        MouseXAngle.Angle -= angleChange;

                        MouseY.FontSize--;
                        MouseYAngle.Angle -= angleChange;
                        break;
                }
            }
            catch
            {
                // ignored
            }
        }
    }
}
