using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
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
        private DispatcherTimer timer;
        private MoveDirection moveDirection;
        private Random r;

        public Snake()
        {
            InitializeComponent();

            r = new Random();

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


        private void TimerTickColor(object sender, EventArgs e)
        {
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
                    Python[0].X -= 20;
                    break;
                case MoveDirection.Right:
                    Python[0].X += 20;
                    break;
                case MoveDirection.Up:
                    Python[0].Y -= 20;
                    break;
                case MoveDirection.Down:
                    Python[0].Y += 20;
                    break;
            }

            ShowPython();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            ShowPython();
            moveDirection = MoveDirection.Left;
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