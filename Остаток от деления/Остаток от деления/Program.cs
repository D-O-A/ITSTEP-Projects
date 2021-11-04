using System;

namespace Остаток_от_деления
{
    class Program
    {
        static void Main()
        {
            do
            {
                Console.WriteLine("Введите делимое:");
                int num1 = Int32.Parse(Console.ReadLine());
                Console.WriteLine("Введите делитель:");
                int num2 = Int32.Parse(Console.ReadLine());

                Console.WriteLine("Остаток от деления = " + num1 % num2);

            } while (true);
        }
    }
}
