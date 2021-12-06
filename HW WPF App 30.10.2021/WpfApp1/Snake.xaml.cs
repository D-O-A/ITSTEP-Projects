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
    /// Interaction logic for Snake.xaml
    /// </summary>
    public partial class Snake : Window
    {
        private readonly List<Segment> Python;
        private readonly DispatcherTimer timer;
        private MoveDirection moveDirection;
        public static readonly Random r = new Random();
        private Food fruit;
        private List<int> foodIndexes;

        public Snake()
        {
            InitializeComponent();


            timer = new DispatcherTimer
            {
                Interval = TimeSpan.FromMilliseconds(300)
            };
            //timer.Tick += TimerTickBW;
            timer.Tick += TimerTickColor;

            Python = new List<Segment>();
            for (int i = 0; i < 5; i++)
            {
                Python.Add(new Segment
                {
                    Figure = new Ellipse
                    {
                        Width = 20,
                        Height = 20,
                        Fill = new SolidColorBrush(Color.FromRgb((byte)r.Next(0, 250), (byte)r.Next(0, 250), (byte)r.Next(0, 250)))/*Brushes.Turquoise*/
                    },
                    X = 400 + i * 20,
                    Y = 100
                });

            }

            fruit = new Food();
            foodIndexes = new List<int>();

        }

        // 1. (Простое решение) Хвостовой сегмент перенести вперед
        private void TimerTickBW(object sender, EventArgs e)
        {
            Segment tail = Python.First(); // ссылка на 1й элемент 
            Segment head = Python.Last(); // ссылка на последний элемент
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

        // 2. (Сложное решение) Двигаем все сегменты
        private void TimerTickColor(object sender, EventArgs e)
        {
            Segment head = Python[0];

            #region Движение змейки




            /*
            for (int i = Python.Count - 1; i >= 1; i--)
            {
                Segment seg = Python[i];
                Segment seg_1 = Python[i - 1];
                seg.X = seg_1.X;
                seg.Y = seg_1.Y;
            }
            */

            // Коррекция - еда "мигрирует" в хвост

            #region С одной едой


            //int foodIndex = -1;
            //for (int i = Python.Count - 1; i >= 1; i--)
            //{
            //    //проходим все элементы, проверяем на еду
            //    if (Python[i] as Food != null)
            //    {
            //        foodIndex = i;
            //    }
            //}

            //if (foodIndex != -1)
            //{
            //    Segment food = Python[foodIndex];

            //    //еда в змейке
            //    if (foodIndex == Python.Count - 1)
            //    {
            //        //еда в самом хвосте - меняем ее на обычный сегмент
            //        Python[foodIndex] = new Segment
            //        {
            //            X = food.X,
            //            Y = food.Y,
            //            Figure = new Ellipse
            //            {
            //                Width = food.Figure.Width,
            //                Height = food.Figure.Height,
            //                Fill = (food.Figure as Rectangle).Fill
            //            }
            //        };
            //        // убираем с поля
            //        Field.Children.Remove(food.Figure);

            //    }
            //    else
            //    {
            //        //еда в середине - сдвигаем ее на 1 позицию
            //        Python.Remove(food);
            //        Python.Insert(foodIndex + 1, food);
            //    }

            //}
            #endregion

            foodIndexes.Clear();

            for (int i = 1; i < Python.Count; i++)
            {
                if ((Python[i] as Food) != null)
                {
                    foodIndexes.Add(i);
                }
            }

            foreach (int foodIndex in foodIndexes)
            { 
                Segment food = Python[foodIndex];

                //еда в змейке
                if (foodIndex == Python.Count - 1)
                {
                    //еда в самом хвосте - меняем ее на обычный сегмент
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
                    // убираем с поля
                    Field.Children.Remove(food.Figure);

                }
                else
                {
                    //еда в середине - сдвигаем ее на 1 позицию
                    Python.Remove(food);
                    Python.Insert(foodIndex + 1, food);
                }

            }

            for (int i = Python.Count - 1; i >= 1; i--)
            {
                Segment seg = Python[i];
                Segment seg_1 = Python[i - 1];
                seg.X = seg_1.X;
                seg.Y = seg_1.Y;
            }

            switch (moveDirection)
            {
                case MoveDirection.Left:
                    head.X -= 20;
                    break;
                case MoveDirection.Right:
                    head.X += 20;
                    break;
                case MoveDirection.Up:
                    head.Y -= 20;
                    break;
                case MoveDirection.Down:
                    head.Y += 20;
                    break;
            }

            // голова после "шага" попала в ячейку с едой:
            if (Python[0].X == fruit.X && Python[0].Y == fruit.Y)
            {
                // делаем еще один шаг в том направлении
                switch (moveDirection)
                {
                    case MoveDirection.Left:
                        head.X -= 20;
                        break;
                    case MoveDirection.Right:
                        head.X += 20;
                        break;
                    case MoveDirection.Up:
                        head.Y -= 20;
                        break;
                    case MoveDirection.Down:
                        head.Y += 20;
                        break;
                }
                // вставляем "еду" в змейку сразу за головой
                Python.Insert(1, fruit);
                // генерируем новую "еду"
                fruit = new Food();
                // проверяем чтобы не попала на змею
                bool collision;
                do
                {
                    collision = false;

                    fruit.X = Snake.r.Next(1, 40) * 20;
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
            #endregion

            #region Выход за пределы экрана

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

        public void Show(Canvas field)  // тип связи - зависимость
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
                Fill = new SolidColorBrush(Color.FromRgb((byte)Snake.r.Next(0, 250), (byte)Snake.r.Next(0, 250),
                    (byte)Snake.r.Next(0, 250))) /*Brushes.Turquoise*/
            };
            X = Snake.r.Next(1, 40) * 20;
            Y = 300;
        }
    }
}



/*
 * Силы связи: (от сильной к слабой)
 * Наследование (обобщение)
 * Композиция - объект для своей жизни создает другой объект, жизненный цикл зависит от включенного объекта
 * Агрегация - жизненный цикл не зависит от включенного объекта
 * Ассоциация - В одном объекте есть переменная или поле типа другого объекта.
 * Зависимость - Слабая зависимость, потому что всегда можно "легко" переписать
 * 
 * 
 * 
 */