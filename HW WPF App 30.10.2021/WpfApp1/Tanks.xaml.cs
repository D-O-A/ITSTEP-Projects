using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Shapes;
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

        // снаряды
        private readonly List<Bullet> bullets;
        private uint hitCounter = 0;
        private readonly Random rX;
        private readonly Random rY;

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

            bullets = new List<Bullet>();
            rX = new Random();
            rY = new Random();
            TankImage.RenderTransform = rotate0;
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
                    break;
                case HoldKey.Right:
                    coord = Canvas.GetLeft(TankImage);
                    if (coord <= this.Width - TankImage.Width - 21)
                    {
                        coord += 10;
                        Canvas.SetLeft(TankImage, coord);
                    }
                    TankImage.RenderTransform = rotate90;
                    break;
                case HoldKey.Up:
                    coord = Canvas.GetTop(TankImage);
                    if (coord >= 10)
                    {
                        coord -= 10;
                        Canvas.SetTop(TankImage, coord);
                    }
                    TankImage.RenderTransform = rotate0;
                    break;
                case HoldKey.Down:
                    coord = Canvas.GetTop(TankImage);
                    if (coord <= this.Height - TankImage.Width - 43)
                    {
                        coord += 10;
                        Canvas.SetTop(TankImage, coord);
                    }
                    TankImage.RenderTransform = rotate180;
                    break;
            }

            // полет снарядов
            Bullet toRemove = null;
            foreach (var bullet in bullets)
            {
                double bulletX = Canvas.GetLeft(bullet.Image) + bullet.Vx;
                double bulletY = Canvas.GetTop(bullet.Image) + bullet.Vy;

                Canvas.SetLeft(bullet.Image, bulletX);
                Canvas.SetTop(bullet.Image, bulletY);

                bullet.Trace += Math.Abs(bullet.Vx) + Math.Abs(bullet.Vy);  // abs (absolute value) делает отрицательные числа положительными
                // излет
                if (bullet.Trace > 300 || bulletX < 0 || bulletY < 0 || bulletX > Field.Width || bulletY > Field.Height)  // вылет за пределы поля
                {
                    // убираем с холста
                    Field.Children.Remove(bullet.Image);
                    // помечаем на удаление
                    toRemove = bullet;
                }
            }
            if (toRemove != null)
            {
                bullets.Remove(toRemove);
            }

            Collisions();
        }

        private void Collisions() // попадание снаряда в мишень
        {
            Bullet toRemove = null;
            foreach (var bullet in bullets)
            {
                double centerX = Canvas.GetLeft(bullet.Image) + bullet.Image.Width / 2;
                double centerY = Canvas.GetTop(bullet.Image) + bullet.Image.Height / 2;

                double targetX = Canvas.GetLeft(Enemy) + Enemy.Width / 2;
                double targetY = Canvas.GetTop(Enemy) + Enemy.Height / 2;

                // попадание - расстояние между центрами меньше суммы радиусов
                double distance = Math.Sqrt(
                    (centerX - targetX) * (centerX - targetX) +
                    (centerY - targetX) * (centerY - targetY)
                    );

                if (distance < bullet.Image.Width / 2 + Enemy.Width / 2)
                {
                    Enemy.Width -= 10;
                    Enemy.Height -= 10;
                    toRemove = bullet;

                    //Если размер достиг 20, то убираем и рисуем в новом месте (в мишень размером 20 и меньше очень ненадежно регистрируются попадания)
                    if (Enemy.Width <= 20 && Enemy.Height <= 20)
                    {
                        Canvas.SetLeft(Enemy, rX.Next(5, 700));
                        Canvas.SetTop(Enemy, rY.Next(5, 350));
                        Enemy.Width = 100;
                        Enemy.Height = 100;
                    }

                    //после попадания рисуем в новом месте
                    //координаты меньше размеров поля чтобы избежать попадания мишени в "мертвые зоны" (невозможно попасть по мишени)
                    Canvas.SetLeft(Enemy, rX.Next(10, 700));
                    Canvas.SetTop(Enemy, rY.Next(10, 350));

                    hitCounter++;
                    HitCounterLabel.Content = "Hits: " + hitCounter.ToString();
                }

            }
            if (toRemove != null)
            {
                bullets.Remove(toRemove);
                Field.Children.Remove(toRemove.Image);
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

                case Key.Space: //выстрел
                    // Создаем снаряд (если его нет)
                    if (bullets.Count < 6)
                    {
                        // выставляем координаты
                        // где танк?
                        double tankX = Canvas.GetLeft(TankImage);
                        double tankY = Canvas.GetTop(TankImage);
                        int vx = 0;
                        int vy = 0;
                        const int bulletRadius = 5;
                        // как он повернут?
                        if (TankImage.RenderTransform == rotate0)
                        {
                            // вверх
                            tankX += TankImage.Width / 2 - bulletRadius;
                            //vx = 0;
                            vy = -20;
                        }
                        if (TankImage.RenderTransform == rotate90)
                        {
                            // вправо
                            tankX += TankImage.Width;
                            tankY += TankImage.Height / 2 - bulletRadius;
                            vx = 20;
                            //vy = 0;
                        }
                        if (TankImage.RenderTransform == rotate180)
                        {
                            // вниз
                            tankX += TankImage.Width / 2 - bulletRadius;
                            tankY += TankImage.Height;
                            //vx = 0;
                            vy = 20;
                        }
                        if (TankImage.RenderTransform == rotate270)
                        {
                            // влево
                            tankY += TankImage.Height / 2 - bulletRadius;
                            vx = -20;
                            //vy = 0;
                        }

                        var bullet = new Bullet
                        {
                            Image = new Ellipse
                            {
                                Fill = Brushes.RosyBrown,
                                Width = 2 * bulletRadius,
                                Height = 2 * bulletRadius
                            },

                            Vx = vx,
                            Vy = vy,
                            Trace = 0
                        };
                        // добавляем на канвас
                        Field.Children.Add(bullet.Image);
                        Canvas.SetLeft(bullet.Image, tankX);
                        Canvas.SetTop(bullet.Image, tankY);
                        // включаем в коллекцию
                        bullets.Add(bullet);
                    }
                    break;
            }
        }

        private void Window_PreviewKeyUp(object sender, KeyEventArgs e)
        {
            switch (e.Key)
            {
                case Key.Left:
                    if (holdKey == HoldKey.Left)
                    {
                        holdKey = HoldKey.None;
                    }
                    break;

                case Key.Right:
                    if (holdKey == HoldKey.Right)
                    {
                        holdKey = HoldKey.None;
                    }
                    break;

                case Key.Up:
                    if (holdKey == HoldKey.Up)
                    {
                        holdKey = HoldKey.None;
                    }
                    break;

                case Key.Down:
                    if (holdKey == HoldKey.Down)
                    {
                        holdKey = HoldKey.None;
                    }
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

    public class Bullet
    {
        public Ellipse Image { get; set; }
        public int Vx { get; set; } // V - velocity
        public int Vy { get; set; }
        public int Trace { get; set; } //проделанный путь (длина)

    }
}
