using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Threading;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for Tanks.xaml
    /// </summary>
    public partial class Tanks : Window
    {
        readonly RotateTransform rotate0 = new RotateTransform(0, 50, 50);
        readonly RotateTransform rotate90 = new RotateTransform(90, 50, 50);
        readonly RotateTransform rotate180 = new RotateTransform(180, 50, 50);
        readonly RotateTransform rotate270 = new RotateTransform(270, 50, 50);
        readonly DispatcherTimer timer; //внутренние события - генерируются приложением
        // наиболее популярные - события таймера - периодически посылаемое событие
        // с запуском делегата

        // признак нажатия кнопок
        HoldKey holdKey;

        public Tanks()
        {
            InitializeComponent();
            //создаем таймер
            timer = new DispatcherTimer();
            //задаем интервал тиков
            timer.Interval = TimeSpan.FromMilliseconds(100);
            //делегат - запускаемая функция
            timer.Tick += Timer_Tick; //делегаты расширяются через +=
            //запускаем таймер
            timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            double coord;

            switch (holdKey)
            {
                case HoldKey.None:
                    break;
                case HoldKey.Left:
                    coord = Canvas.GetLeft(TankImage);
                    if (coord >= 10)
                    {
                        coord -= 10;
                        Canvas.SetLeft(TankImage, coord);
                    }
                    TankImage.RenderTransform = rotate270;
                    holdKey = HoldKey.None;
                    break;
                case HoldKey.Right:
                    coord = Canvas.GetLeft(TankImage);
                    if (coord <= this.Width - TankImage.Width - 21)
                    {
                        coord += 10;
                        Canvas.SetLeft(TankImage, coord);
                    }
                    TankImage.RenderTransform = rotate90;
                    holdKey = HoldKey.None;
                    break;
                case HoldKey.Up:
                    coord = Canvas.GetTop(TankImage);
                    if (coord >= 10)
                    {
                        coord -= 10;
                        Canvas.SetTop(TankImage, coord);
                    }
                    TankImage.RenderTransform = rotate0;
                    holdKey = HoldKey.None;
                    break;
                case HoldKey.Down:
                    coord = Canvas.GetTop(TankImage);
                    if (coord <= this.Height - TankImage.Width - 43)
                    {
                        coord += 10;
                        Canvas.SetTop(TankImage, coord);
                    }
                    TankImage.RenderTransform = rotate180;
                    holdKey = HoldKey.None;
                    break;
            }
        }

        private void Window_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.Key)
            {
                case Key.Left:
                    holdKey = HoldKey.Left;
                    break;

                case Key.Right:
                    holdKey = HoldKey.Right;
                    break;

                case Key.Up:
                    holdKey = HoldKey.Up;
                    break;

                case Key.Down:
                    holdKey = HoldKey.Down;
                    break;
            }
        }
    }

    public enum HoldKey
    {
        None,
        Left,
        Right,
        Up,
        Down
    }
}
