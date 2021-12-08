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
    /// Interaction logic for DateTime.xaml
    /// </summary>
    public partial class DT : Window
    {
        public DT()
        {
            InitializeComponent();
        }

        private void DoneButton_Click(object sender, RoutedEventArgs e)
        {
            //Хранить датувремя лучше всего как timestamp
            DateTime dateTime = DTPicker.SelectedDate.Value;
            DTText.Text = "ToString: " + dateTime.ToString()
                          + "\nToBinary: " + dateTime.ToBinary()
                          + "\nToLocalTime: " + dateTime.ToLocalTime()
                          + "\nToLongDateString " + dateTime.ToLongDateString()
                          + "\nToLongTimeString " + dateTime.ToLongTimeString()
                          + "\nToShortDateString " + dateTime.ToShortDateString()
                          + "\nToShortTimeString " + dateTime.ToShortTimeString()
                          + "\nToUniversalTime " + dateTime.ToUniversalTime();
            string iso8601; /*= string.Format("{0}-{1}-{2}:{3}:{4}:{5}.{6}");*/
            iso8601 = dateTime.Year.ToString();
            iso8601 += "-" + (dateTime.Month < 10 ? "0" + dateTime.Month.ToString() : dateTime.Month.ToString());
            iso8601 += "-" + (dateTime.Day < 10 ? "0" + dateTime.Day.ToString() : dateTime.Day.ToString());
            iso8601 += " " + dateTime.Hour;
            iso8601 += ":" + dateTime.Minute;
            iso8601 += ":" + dateTime.Second;
            iso8601 += "." + dateTime.Millisecond;


            //dateTime.Month > 10 ? "0" + dateTime.Month : dateTime.Month, dateTime.Day, dateTime.Hour, dateTime.Minute, dateTime.Second, dateTime.Millisecond);

            DTText.Text += "\nISO-8601: " + iso8601;
        }
    }
}


/* Дата и время
 * 
 * Есть множество форматов представления даты/времени:
 * - SQL
 * - Email
 * - Internet
 * + локализация (нац. стандарты)
 * 
 * Наиболее общее представоение даты/времени в программировании - TIMESTAMP
 * TIMESTAMP - количество секунд или миллисекунд, прошедших с определенного момента времени (старт первой Unix машины, 01/01/1970)
 * 
 * Просто дата без времени - это самое начало даты, не конец и не средина. Если 8 число со временем 00:01, то сравнение с 8 числом 00:00 будет некорректным
 * 
 * В БД при сравнении дат нужно "отрезать" время
 * 
 * 
 * 
 * 
 * 
 * 
 */