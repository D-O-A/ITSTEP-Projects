using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for Snake.xaml
    /// </summary>
    public partial class Snake : Window
    {
        private readonly List<Segment> Python;

        public Snake()
        {
            InitializeComponent();
            Python = new List<Segment>();
            for (int i = 0; i < 5; i++)
            {
                Python.Add(new Segment
                {
                    Figure = new Ellipse
                    {
                        Width = 20,
                        Height = 20,
                        Fill = Brushes.Turquoise
                    },
                    X = 100 + i * 10,
                    Y = 100
                });

            }
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            foreach (var segment in Python)
            {
                segment.Show(Field);
            }
        }
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
 * Композиция
 * Агрегация
 * Ассоциация
 * Зависимость
 * 
 * 
 * 
 * 