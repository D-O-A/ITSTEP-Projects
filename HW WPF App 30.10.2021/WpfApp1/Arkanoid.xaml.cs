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
    /// Interaction logic for Arkanoid.xaml
    /// </summary>
    public partial class Arkanoid : Window
    {
        private HoldKey holdKey;
        readonly DispatcherTimer Timer;
        private readonly List<Rectangle> Bricks;
        private readonly List<Ellipse> Balls;

        /* ------- README ---------
         мои служебные вещи, модификатор "следующего уровня", также переменные для подсчета времени прохождения уровня и сид для генерации случайных значений
        
        В конструкторе задается значение "1" и передается в Restart(); для цикла в цикле, при срабатывании условия выигрыша инкриминируется и опять передается в метод Restart(); 
        который рисует шарик и кирпичи. Дальше цикл в цикле в методе Restart(); рисует новый ряд кирпичей опираясь на значение модификатора.
        
        Random нужен для случайной генерации цвета шарика.

        Дальше нехитрые манипуляции с DateTime и TimeSpan чтобы четко высчитать пройденное кол-во секунд от начала игры, ибо опираться на тик таймера
        очень ненадежно.
        */
        private readonly Random r;
        private DateTime timer;
        private TimeSpan timeToComplete;
        private int modifier;

        public Arkanoid()
        {
            InitializeComponent();
            Timer = new DispatcherTimer
            {
                Interval = TimeSpan.FromMilliseconds(20),

            };
            Timer.Tick += Timer_Tick;
            Timer.Tick += Timer_Tick_Ship;
            Timer.Tick += Timer_Tick_Bricks;

            Bricks = new List<Rectangle>();
            Balls = new List<Ellipse>();
            r = new Random();
            modifier = 1;
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            //все, что было тут раннее перенес в Restart();
            Restart(modifier);
        }
        //private void Timer_Tick_Struct(object sender, EventArgs e)
        //{
        //    foreach (var Ball in Balls)
        //    {
        //        #region движение шариков
        //        BallData data = (BallData)Ball.Tag;  // unboxing (распаковка) - это копия

        //        double ballX = Canvas.GetLeft(Ball);
        //        double ballY = Canvas.GetTop(Ball);

        //        if (ballY > Field.Height - Ball.Height)   // ниже края поля - проигрыш
        //        {
        //            Timer.Stop();
        //            MessageBox.Show("Game Over", "Looser", MessageBoxButton.OK, MessageBoxImage.Exclamation);
        //        }

        //        if (ballY + Ball.Height >= Canvas.GetTop(Ship)) // нижняя область отражения
        //        {
        //            double shipX = Canvas.GetLeft(Ship);
        //            // проверяем по горизонтали - или шарик над кареткой
        //            if (ballX >= shipX - Ball.Width / 2  // левый край каретки
        //                && ballX <= shipX - Ball.Width / 2 + Ship.Width) // правый край каретки
        //            {
        //                //ballY = Field.Height - Ball.Height;
        //                data.Vy = -Math.Abs(data.Vy);  // изменение копии - не меняет Tag
        //                Ball.Tag             // рефлексия - самоанализ
        //                    .GetType()       // Получаем данные о типе (Ball.Tag)
        //                    .GetField("Vy")  // Получаем данные о поле "Vy"
        //                    ?.SetValue(      // меняем такое поле
        //                    Ball.Tag,        // в объекте Ball.Tag
        //                    data.Vy);        // на значение data.Vy
        //            }
        //        }

        //        if (ballX >= Field.Width - Ball.Width)
        //        {
        //            ballX = Field.Width - Ball.Width;
        //            data.Vx = -data.Vx;
        //            Ball.Tag.GetType().GetField("Vx")?.SetValue(Ball.Tag, data.Vx);
        //        }

        //        if (ballX <= 0)
        //        {
        //            ballX = 0;
        //            data.Vx = -data.Vx;
        //            Ball.Tag.GetType().GetField("Vx")?.SetValue(Ball.Tag, data.Vx);
        //        }

        //        if (ballY <= 0)
        //        {
        //            ballY = 0;
        //            data.Vy = -data.Vy;
        //            Ball.Tag.GetType().GetField("Vy")?.SetValue(Ball.Tag, data.Vy);
        //        }

        //        Canvas.SetTop(Ball, ballY + data.Vy);
        //        Canvas.SetLeft(Ball, ballX + data.Vx);

        //        //Ball.Tag = data;  // новая упаковка - новый объект
        //        #endregion
        //    }
        //}
        private void Timer_Tick(object sender, EventArgs e)
        {
            timeToComplete = DateTime.Now - timer;

            List<Ellipse> toRemove = new List<Ellipse>();
            foreach (var Ball in Balls)
            {
                #region движение шариков
                BallData data = (BallData)Ball.Tag;  // Ref: data - это ссылка

                double ballX = Canvas.GetLeft(Ball);
                double ballY = Canvas.GetTop(Ball);

                if (ballY > Field.Height - Ball.Height)   // ниже края поля - проигрыш
                {
                    toRemove.Add(Ball);
                }

                if (ballY + Ball.Height >= Canvas.GetTop(Ship)) // нижняя область отражения
                {
                    double shipX = Canvas.GetLeft(Ship);
                    // проверяем по горизонтали - или шарик над кареткой
                    if (ballX >= shipX - Ball.Width / 2  // левый край каретки
                        && ballX <= shipX - Ball.Width / 2 + Ship.Width) // правый край каретки
                    {
                        data.Vy = -Math.Abs(data.Vy); // изменение по ссылке - меняет Tag
                        if (holdKey == HoldKey.Left)
                        {
                            data.Vx -= 2;
                        }

                        if (holdKey == HoldKey.Right)
                        {
                            data.Vx += 2;
                        }
                    }
                }

                if (ballX >= Field.Width - Ball.Width)
                {
                    ballX = Field.Width - Ball.Width;
                    data.Vx = -data.Vx;
                }

                if (ballX <= 0)
                {
                    ballX = 0;
                    data.Vx = -data.Vx;
                }

                if (ballY <= 0)
                {
                    ballY = 0;
                    data.Vy = -data.Vy;
                }

                Canvas.SetTop(Ball, ballY + data.Vy);
                Canvas.SetLeft(Ball, ballX + data.Vx);

            }
            #endregion

            foreach (var rem in toRemove)
            {
                Balls.Remove(rem);
                Field.Children.Remove(rem);
            }

            if (Balls.Count == 0)
            {
                Timer.Stop();
                MessageBox.Show("Game Over", "Looser", MessageBoxButton.OK, MessageBoxImage.Exclamation);
                Close();
            }

        }
        private void Timer_Tick_Ship(object sender, EventArgs e)
        {
            #region движение каретки
            double dx = 0;
            if (holdKey == HoldKey.Left)
            {
                if (Canvas.GetLeft(Ship) != 0)
                {
                    dx = -10;
                }
            }
            if (holdKey == HoldKey.Right)
            {
                if (Canvas.GetLeft(Ship) != Field.Width - Ship.Width)
                {
                    dx = 10;
                }
            }
            if (dx != 0)
            {
                Canvas.SetLeft(Ship, Canvas.GetLeft(Ship) + dx);
            }

            #endregion
        }
        private void Timer_Tick_Bricks(object sender, EventArgs e)
        {
            List<Rectangle> toRemove = new List<Rectangle>();
            List<Ellipse> toDuplicate = new List<Ellipse>();

            if (Bricks.Count == 0)
            {
                Timer.Stop();
                if (MessageBoxResult.Yes == MessageBox.Show($"Время прохождения - {timeToComplete.Seconds.ToString()} секунд.\nЕще раз?", "Победа, победа, вместо обеда!", MessageBoxButton.YesNo))
                {
                    modifier++;
                    Restart(modifier);

                }
                else
                {
                    this.Close();
                }

            }

            foreach (var Ball in Balls)
            {
                BallData data = (BallData)Ball.Tag;
                double ballX = Canvas.GetLeft(Ball);
                double ballY = Canvas.GetTop(Ball);

                foreach (var Brick in Bricks)
                {
                    double brickX = Canvas.GetLeft(Brick);
                    double brickY = Canvas.GetTop(Brick);
                    bool strike = false;

                    //сверху
                    if (ballY + Ball.Height >= brickY
                        && ballY + Ball.Height <= brickY + Math.Abs(2 * data.Vy)
                        && ballX >= brickX - Ball.Width / 1.5
                        && ballX <= brickX - Ball.Width / 1.5 + Brick.Width)
                    {
                        strike = true;
                        data.Vy = -Math.Abs(data.Vy);
                    }
                    //снизу
                    else if (ballY <= brickY + Brick.Height
                        && ballY >= brickY + Brick.Height - Math.Abs(2 * data.Vy)
                        && ballX >= brickX - Ball.Width / 1.5
                        && ballX <= brickX - Ball.Width / 1.5 + Brick.Width)
                    {
                        strike = true;
                        data.Vy = Math.Abs(data.Vy);
                    }
                    //слева
                    else if (ballX + Ball.Width >= brickX
                        && ballX + Ball.Width <= brickX + Math.Abs(2 * data.Vy)
                        && ballY >= brickY - Ball.Height / 1.5
                        && ballY <= brickY - Ball.Height / 1.5 + Brick.Height)
                    {
                        strike = true;
                        data.Vx = -Math.Abs(data.Vx);
                    }
                    //справа
                    else if (ballX <= brickX + Brick.Width
                        && ballX >= brickX + Brick.Width - Math.Abs(2 * data.Vy)
                        && ballY >= brickY - Ball.Height / 1.5
                        && ballY <= brickY - Ball.Height / 1.5 + Brick.Height)
                    {
                        strike = true;
                        data.Vx = Math.Abs(data.Vx);
                    }
                    //точное попадание в угол
                    else if (Math.Abs(brickX + Brick.Width - ballX - Ball.Width / 2) < Ball.Width / 2
                        && Math.Abs(brickY + Brick.Height - ballY - Ball.Height / 2) < Ball.Height / 2

                        || Math.Abs(brickX - ballX - Ball.Width / 2) < Ball.Width / 2
                        && Math.Abs(brickY + Brick.Height - ballY - Ball.Height / 2) < Ball.Height / 2

                        || Math.Abs(brickX + Brick.Width - ballX - Ball.Width / 2) < Ball.Width / 2
                        && Math.Abs(brickY - ballY - Ball.Height / 2) < Ball.Height / 2

                        || Math.Abs(brickX - ballX - Ball.Width / 2) < Ball.Width / 2
                        && Math.Abs(brickY - ballY - Ball.Height / 2) < Ball.Height / 2)
                    {
                        data.Vx = -data.Vx;
                        data.Vy = -data.Vy;
                        strike = true;
                    }

                    if (strike) //шарик столкнулся с кирпичем
                    {
                        //кирпич на удаление
                        if (!toRemove.Contains(Brick))
                        {
                            toRemove.Add(Brick);
                        }
                        //шарик на дубликат
                        if (!toDuplicate.Contains(Ball))
                        {
                            toDuplicate.Add(Ball);
                        }

                    }
                }
            }
            foreach (var rem in toRemove)
            {
                Bricks.Remove(rem);
                Field.Children.Remove(rem);
            }
            foreach (var dup in toDuplicate)
            {
                Ellipse newBall = new Ellipse
                {
                    Width = dup.Width,
                    Height = dup.Height,
                    Fill = new SolidColorBrush(Color.FromRgb(Convert.ToByte(r.Next(0, 250)), Convert.ToByte(r.Next(0, 250)), Convert.ToByte(r.Next(0, 250)))),
                    Tag = new BallData
                    {
                        Vx = (dup.Tag as BallData).Vx + 1,
                        Vy = -(dup.Tag as BallData).Vy
                    }
                };

                Balls.Add(newBall);
                Field.Children.Add(newBall);
                Canvas.SetLeft(newBall, Canvas.GetLeft(dup));
                Canvas.SetTop(newBall, Canvas.GetTop(dup));
            }

        }

        private void Restart(int modifier)
        {
            Ball1.Tag = (object)new BallData  // boxing (упаковка)
            {
                Vx = 5,
                Vy = -5
            };

            holdKey = HoldKey.None;

            // если "прошли уровень", то надо очистить все мячики из коллекции и с канваса, а потом добавить только один мячик.
            if (Balls.Count > 0)
            {
                foreach (var ball in Balls)
                {
                    Field.Children.Remove(ball);
                }
                Balls.Clear();
                Canvas.SetLeft(Ball1, 370);
                Canvas.SetTop(Ball1, 200);
                Balls.Add(Ball1);
                Field.Children.Add(Ball1);
            }
            else
            {
                //это условие нужно для первичного запуска игры, так как изначально коллекция шариков пуста.
                //поскольку при первичном запуске первый мячик создается в xaml'е, то добавлять в коде не нужно
                Balls.Add(Ball1);
            }

            for (int j = 1; j <= modifier; j++)
            {
                for (int i = 0; i < 9; i++)
                {
                    Rectangle rectangle =
                        new Rectangle
                        {
                            Width = 70,
                            Height = 20,
                            Fill = Brushes.DarkGoldenrod
                        };

                    Field.Children.Add(rectangle);

                    Canvas.SetLeft(rectangle, 35 + 80 * i);
                    Canvas.SetTop(rectangle, 25 * j);

                    Bricks.Add(rectangle);
                }
            }

            timer = DateTime.Now;
            Timer.Start();
        }

        private void Window_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Left)
            {
                holdKey = HoldKey.Left;
            }
            if (e.Key == Key.Right)
            {
                holdKey = HoldKey.Right;
            }
            if (e.Key == Key.Escape)
            {
                if (Timer.IsEnabled)
                {
                    Timer.Stop();
                }
                else
                {
                    Timer.Start();
                }
            }
        }

        private void Window_PreviewKeyUp(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Left && holdKey == HoldKey.Left)
            {
                holdKey = HoldKey.None;
            }
            if (e.Key == Key.Right && holdKey == HoldKey.Right)
            {
                holdKey = HoldKey.None;
            }
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            Timer.Stop();
        }
    }

    class BallData //Информация о шарике
    {
        public double Vx;
        public double Vy;
    }
}
