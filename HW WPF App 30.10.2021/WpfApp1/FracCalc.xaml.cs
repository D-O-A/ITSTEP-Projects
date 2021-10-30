using System;
using System.Windows;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for FracCalc.xaml
    /// </summary>
    public partial class FracCalc : Window
    {
        public FracCalc()
        {
            InitializeComponent();
        }
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            numerator1.Clear();
            numerator2.Clear();
            numerator3.Content = "";
            denominator1.Clear();
            denominator2.Clear();
            denominator3.Content = "";
        }

        private void Equals_Click(object sender, RoutedEventArgs e)
        {
            if (numerator1.Text.Equals(String.Empty))
            {
                MessageBox.Show("Введите числитель 1");
                return;
            }
            //первая дробь

            Fraction frac1;

            try
            {
                frac1 = new Fraction
                {
                    Numerator = Convert.ToInt32(numerator1.Text),
                    Denominator = Convert.ToInt32(denominator1.Text)
                };
            }
            catch
            {
                MessageBox.Show("Неправильная запись дроби 1");
                return;
            }

            if (numerator2.Text.Equals(String.Empty))
            {
                MessageBox.Show("Введите числитель 2");
                return;
            }
            //вторая дробь
        
            Fraction frac2;

            try
            {
                frac2 = new Fraction
                {
                    Numerator = Convert.ToInt32(numerator2.Text),
                    Denominator = Convert.ToInt32(denominator2.Text)
                };
            }
            catch
            {
                MessageBox.Show("Неправильная запись дроби 2");
                return;
            }

            //результаты действий
            Fraction res = null;
            if (rbMul.IsChecked.Value)
            {
                res = frac1* frac2;
            }

            if (rbDiv.IsChecked.Value)
            {
                res = frac1 / frac2;
            }

            if (rbPlus.IsChecked.Value)
            {
                res = frac1 + frac2;
            }


            //не выбрана операция
            if (res == null)
            {
                MessageBox.Show("Выберите операцию");
                return;
            }


            //отображение
            numerator3.Content = res.Numerator.ToString();
            denominator3.Content = res.Denominator.ToString();
        }
    }

    public class Fraction
    {
        public int Numerator { get; set; }
        public int Denominator { get; set; }

        //перегрузка операторов
        //отличия от крестов:
        /* Описываются как методы, но принимают 2 параметра
         * задаются для класса, то есть в статическом виде
         */

        public static Fraction operator*(Fraction f1, Fraction f2)
        {
            return new Fraction
            {
                Numerator = f1.Numerator * f2.Numerator,
                Denominator = f1.Denominator * f2.Denominator
            };
        }

        public static Fraction operator /(Fraction f1, Fraction f2)
        {
            return new Fraction
            {
                Numerator = f1.Numerator * f2.Denominator,
                Denominator = f1.Denominator * f2.Numerator
            };
        }

        public static Fraction operator +(Fraction f1, Fraction f2)
        {
            return new Fraction
            {
                Numerator = f1.Numerator * f2.Denominator + f2.Numerator * f1.Denominator,
                Denominator = f1.Denominator * f2.Denominator
            };
        }

    }
}
