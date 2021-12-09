using System;
using System.Windows;


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

            string iso8601 =
                $"{dateTime.Year}-{(dateTime.Month < 10 ? "0" + dateTime.Month : dateTime.Month.ToString())}" +
                $"-{(dateTime.Day < 10 ? "0" + dateTime.Day : dateTime.Day.ToString())}" +
                $" {(dateTime.Hour < 10 ? "0" + dateTime.Hour : dateTime.Hour.ToString())}" +
                $":{(dateTime.Minute < 10 ? "0" + dateTime.Minute : dateTime.Minute.ToString())}" +
                $":{(dateTime.Second < 10 ? "0" + dateTime.Second : dateTime.Second.ToString())}";

            //https://www.w3.org/Protocols/rfc822/#z28 Стандарт RFC-1123. По документации подходит под RFC-2822 вариант ниже
            string rfc2822 = dateTime.ToString("R");

            string question = dateTime.ToString("O"); //По документации именно это является стандартом 8601 а не то, что мы писали сверху?
           
            string rfc3339 = $"{dateTime.Year}-{(dateTime.Month < 10 ? "0" + dateTime.Month : dateTime.Month.ToString())}" +
                             $"-{(dateTime.Day < 10 ? "0" + dateTime.Day : dateTime.Day.ToString())}" +
                             $"T{(dateTime.Hour < 10 ? "0" + dateTime.Hour : dateTime.Hour.ToString())}" +
                             $":{(dateTime.Minute < 10 ? "0" + dateTime.Minute : dateTime.Minute.ToString())}" +
                             $":{(dateTime.Second < 10 ? "0" + dateTime.Second : dateTime.Second.ToString())} " + dateTime.ToString("zzz");


            DTText.Text += "\nISO-8601: " + iso8601;
            DTText.Text += "\nRFC-2822: " + rfc2822;
            DTText.Text += "\nRFC-3339: " + rfc3339;
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
 * Наиболее общее представление даты/времени в программировании - TIMESTAMP
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