using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace WpfApp1
{
    /// <summary>
    /// Логика взаимодействия для Snake.xaml
    /// </summary>
    public partial class Snake : Window
    {
        public static Random random;

        private readonly List<Segment> Python;
        private readonly DispatcherTimer timer;
        MoveDirection moveDirection;
        private Food fruit;
        private readonly List<int> foodIndexes;

        public Snake()
        {
            InitializeComponent();

            random = new Random();

            timer = new DispatcherTimer { Interval = TimeSpan.FromMilliseconds(300) };


            timer.Tick += TimerTick;

            Python = new List<Segment>();
            for (int i = 0; i < 5; ++i)
            {
                Python.Add(new Segment
                {
                    Figure = new Ellipse()
                    {
                        Width = 20,
                        Height = 20,
                        Fill = new SolidColorBrush(
                            Color.FromRgb(
                                (byte)random.Next(100, 250),
                                (byte)random.Next(100, 250),
                                (byte)random.Next(100, 250)))
                    },
                    X = 400 + i * 20,
                    Y = 100
                });
            }

            fruit = new Food();
            foodIndexes = new List<int>();
        }

        private void TimerTick(object sender, EventArgs e)
        {
            Segment head = Python[0];


            #region Движение змейки
            /*
            for (int i = Python.Count - 1; i >= 1; --i)
            {
                Segment seg = Python[i];
                Segment seg_1 = Python[i - 1];
                seg.X = seg_1.X;
                seg.Y = seg_1.Y;
            }*/
            // Коррекция - еда "мигрирует" в хвост
            #endregion
            #region С одной едой
            /*
            int foodIndex = -1;
            for (int i = Python.Count - 1; i >= 1; --i)
            {   // проходим все элементы, проверяем на еду
                if((Python[i] as Food) != null)
                {
                    foodIndex = i;
                }
            }
            if(foodIndex != -1)
            {   // food inside
                Segment food = Python[foodIndex];
                if (foodIndex == Python.Count - 1)
                {   // еда в самом хвосте - меняем ее на сегмент
                    Python[foodIndex] = new Segment
                    {
                        X = food.X,
                        Y = food.Y,
                        Figure = new Ellipse
                        {
                            Width = food.Figure.Width,
                            Height = food.Figure.Height,
                            Fill = (food.Figure as Rectangle).Fill
                        }
                    };
                    // Убираем с поля
                    Field.Children.Remove(food.Figure);
                }
                else
                {   // еда в середине - сдвигаем ее на 1 позицию
                    Python.Remove(food);
                    Python.Insert(foodIndex + 1, food);
                }
            }
            */
            #endregion

            foodIndexes.Clear();
            for (int i = 1; i < Python.Count; ++i)
            {
                if ((Python[i] as Food) != null)
                {
                    foodIndexes.Add(i);
                }
            }

            for (int i = Python.Count - 1; i > 28; i++)
            {
                timer.Stop();
                if (MessageBoxResult.OK == MessageBox.Show("You won!", "Winner", MessageBoxButton.OK))
                {
                    this.Close();
                }

                return;
            }

            foreach (int foodIndex in foodIndexes)
            {
                Segment food = Python[foodIndex];
                if (foodIndex == Python.Count - 1)
                {   // еда в самом хвосте - меняем ее на сегмент
                    Python[foodIndex] = new Segment
                    {
                        X = food.X,
                        Y = food.Y,
                        Figure = new Ellipse
                        {
                            Width = food.Figure.Width,
                            Height = food.Figure.Height,
                            Fill = (food.Figure as Rectangle).Fill
                        }
                    };

                    // Убираем с поля
                    Field.Children.Remove(food.Figure);
                }
                else
                {   // еда в середине - сдвигаем ее на 1 позицию
                    Python.Remove(food);
                    Python.Insert(foodIndex + 1, food);
                }
            }

            for (int i = Python.Count - 1; i >= 1; --i)
            {
                Segment seg = Python[i];
                Segment seg_1 = Python[i - 1];
                seg.X = seg_1.X;
                seg.Y = seg_1.Y;
            }

            switch (moveDirection)
            {
                case MoveDirection.Left: head.X -= 20; break;
                case MoveDirection.Right: head.X += 20; break;
                case MoveDirection.Up: head.Y -= 20; break;
                case MoveDirection.Down: head.Y += 20; break;
            }

            foreach (Segment seg in Python)
            {
                if (head.X == seg.X && head.Y == seg.Y && head != seg)
                {
                    timer.Stop();
                    MessageBox.Show("You lose!!!", "Looser");
                    this.Close();
                    return;
                }
            }
            // голова после "шага" попала в ячейку с едой:
            if (head.X == fruit.X && head.Y == fruit.Y)
            {
                // делаем еще один шаг в том же направлении
                switch (moveDirection)
                {
                    case MoveDirection.Left: head.X -= 20; break;
                    case MoveDirection.Right: head.X += 20; break;
                    case MoveDirection.Up: head.Y -= 20; break;
                    case MoveDirection.Down: head.Y += 20; break;
                }



                // вставляем "еду" в змейку сразу за головой
                Python.Insert(1, fruit);  // 1 - индекс вставки
                // генерируем новую еду
                fruit = new Food();
                // проверяем чтобы не попала на змею
                bool collision;
                do
                {
                    collision = false;
                    fruit.X = random.Next(1, 40) * 20;
                    foreach (Segment seg in Python)
                    {
                        if (Math.Abs(seg.X - fruit.X) <= seg.Figure.Width)
                        {
                            collision = true;
                        }
                    }
                } while (collision);
                // отображаем ее 
                fruit.Show(Field);
            }


            #region Выход за поле
            if (moveDirection == MoveDirection.Left && head.X < 0)
            {
                head.X = Field.Width - Field.Width % head.Figure.Width;
            }
            if (moveDirection == MoveDirection.Right && head.X >= Field.Width - Field.Width % head.Figure.Width)
            {
                head.X = 0;
            }
            if (moveDirection == MoveDirection.Down && head.Y >= Field.Height - Field.Height % head.Figure.Height)
            {
                head.Y = 0;
            }
            if (moveDirection == MoveDirection.Up && head.Y < 0)
            {
                head.Y = Field.Height - Field.Height % head.Figure.Height;
            }
            #endregion

            ShowPython();
        }

        // 1. (Простое решение) Хвостовой сегмент перенести вперед
        private void TimerTickBW(object sender, EventArgs e)
        {
            Segment tail = Python.First();  // ссылка на 1й элемент
            Segment head = Python.Last();
            Python.Remove(tail);
            switch (moveDirection)
            {
                case MoveDirection.Left:
                    tail.X = head.X - tail.Figure.Width;
                    tail.Y = head.Y;
                    break;
                case MoveDirection.Right:
                    tail.X = head.X + tail.Figure.Width;
                    tail.Y = head.Y;
                    break;
                case MoveDirection.Up:
                    tail.X = head.X;
                    tail.Y = head.Y - tail.Figure.Height;
                    break;
                case MoveDirection.Down:
                    tail.X = head.X;
                    tail.Y = head.Y + tail.Figure.Height;
                    break;
            }
            Python.Add(tail);
            tail.Show(Field);
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            ShowPython();
            moveDirection = MoveDirection.Left;
            fruit.Show(Field);
            timer.Start();
        }

        private void ShowPython()
        {
            foreach (var segment in Python)
            {
                segment.Show(Field);
            }
        }

        private void Window_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            switch (e.Key)
            {
                case Key.Left:
                    if (moveDirection != MoveDirection.Right)
                    {
                        moveDirection = MoveDirection.Left;
                    }

                    break;
                case Key.Right:
                    if (moveDirection != MoveDirection.Left)
                    {
                        moveDirection = MoveDirection.Right;
                    }

                    break;
                case Key.Up:
                    if (moveDirection != MoveDirection.Down)
                    {
                        moveDirection = MoveDirection.Up;
                    }

                    break;
                case Key.Down:
                    if (moveDirection != MoveDirection.Up)
                    {
                        moveDirection = MoveDirection.Down;
                    }

                    break;
            }
        }
    }

    public enum MoveDirection
    {
        Left,
        Right,
        Up,
        Down
    }

    public class Segment
    {
        // Композиция - сильная связь с объектом FrameworkElement
        public FrameworkElement Figure { get; set; }
        public double X { get; set; }
        public double Y { get; set; }

        public void Show(Canvas field)
        {
            if (!field.Children.Contains(Figure))
            {
                field.Children.Add(Figure);
            }
            Canvas.SetLeft(Figure, X);
            Canvas.SetTop(Figure, Y);
        }
    }

    public class Food : Segment
    {
        public Food()
        {
            Figure = new Rectangle
            {

                Width = 20,
                Height = 20,
                Fill = new SolidColorBrush(
                       Color.FromRgb(
                           (byte)Snake.random.Next(100, 250),
                           (byte)Snake.random.Next(100, 250),
                           (byte)Snake.random.Next(100, 250)))
            };
            X = Snake.random.Next(1, 40) * 20;
            Y = Snake.random.Next(20) * 20;
        }
    }
}


/*
    ***** 0
     *****0    
      ****0*
       ***0**
       

            0*****
             ******
 */

