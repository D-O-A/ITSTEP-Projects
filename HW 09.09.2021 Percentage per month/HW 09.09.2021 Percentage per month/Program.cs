using System;

namespace HW_09._09._2021_Percentage_per_month
{
    class Program
    {
        static void Main()
        {
            do
            {
                try
                {
                    decimal totalAmount = 1000;

                    Console.WriteLine("Введите желаемый % от 1000:");

                    decimal percentage = decimal.Parse(Console.ReadLine());
                    int counter = new(); //читал, что по умолчанию оператор new инициализирует нулем)

                    while (totalAmount < 1500)
                    {
                        totalAmount += percentage * 1000 / 100;
                        counter++;
                    }

                    Console.WriteLine($"Через {counter} месяцев размер вклада превысит 1500.");
                }
                catch (FormatException ex)
                {
                    Console.WriteLine(ex.Message);
                }

            } while (true);
        }
    }
}
