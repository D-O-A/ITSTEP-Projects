using System;
using System.Diagnostics.SymbolStore;
using System.Text.RegularExpressions;
using System.Windows;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for Strings.xaml
    /// </summary>
    public partial class Strings : Window
    {
        delegate string StringProcessor(string str);
        //typedef int Processor(int);

        delegate string StringArrayProcessor(string[] words);

        StringProcessor reverser, shuffler;
        //StringProcessor[] processor = new StringProcessor[2];

        private readonly StringArrayProcessor reverseArray, shuffleArray;

        string ReverseArray(string[] words)
        {
            string res = null;

            foreach (var word in words)
            {
                res = word + " " + res;
            }

            return res;
        }

        string ShuffleArray(string[] words)
        {
            string res = "";

            int N = words.Length;
            int[] nums = new int[N];

            for (int i = 0; i < N; i++)
            {
                nums[i] = i;
            }

            var rnd = new Random();
            int n1, n2;

            for (int i = 0; i < N; i++)
            {
                n1 = rnd.Next(N);
                do
                {
                    n2 = rnd.Next(N);

                } while (n1 == n2);

                (nums[n1], nums[n2]) = (nums[n2], nums[n1]);
            }

            for (int i = 0; i < N; i++)
            {
                res += words[nums[i]] + " ";
            }

            return res;
        }

        string wordsReverse(string str)
        {
            string[] words = str.Split(' ');
            string res = null;

            foreach (var word in words)
            {
                res = word + " " + res;
            }
            return res;
        }

        string wordShuffler(string str)
        {
            string[] words = str.Split(' ');
            string res = "";
            //сколько слов? готовим массив с числами 0, 1, 2...

            //такой стиль называется смешивание абстракций
            int N = words.Length;
            int[] nums = new int[N];

            for (int i = 0; i < N; i++)
            {
                nums[i] = i;
            }

            //перемешиваем массив - генерируем 2 случайных индекса и меняем значения в массиве

            var rnd = new Random();

            int n1, n2;

            for (int i = 0; i < N; i++)
            {
                n1 = rnd.Next(N);
                do
                {
                    n2 = rnd.Next(N);

                } while (n1 == n2);

                //поменять местами nums[n1] и nums[n2]
                //int temp = nums[n1];
                //nums[n1] = nums[n2];
                //nums[n2] = temp;

                //решарпер подсказал через "деконструктор"
                (nums[n1], nums[n2]) = (nums[n2], nums[n1]);
            }

            for (int i = 0; i < N; i++)
            {
                res += words[nums[i]] + " ";
            }

            return res;
        }

        public Strings()
        {
            InitializeComponent();
            reverser = wordsReverse;
            shuffler = wordShuffler;
            reverseArray = ReverseArray;
            shuffleArray = ShuffleArray;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Label.Text = reverser(TextBlock.Text);
        }

        private void ClearRight_Click(object sender, RoutedEventArgs e)
        {
            Label.Text = "";
        }

        private void ShuffleDelegateArray_Click(object sender, RoutedEventArgs e)
        {
            string[] words = TextBlock.Text.Split(' ');
            Label.Text = shuffleArray(words);
        }

        private void Digits_Click(object sender, RoutedEventArgs e)
        {
            //Регулярные выражения (Regular Expressions, regex)
            //Специальные средства для работы со строками:
            //-проверка по шаблону / поиск шаблона
            //-разбиение по шаблону-разделителю
            //-поиск-замена

            //Особенности:
            //использование спец. символов
            // \d (digit) - любая цифра
            // \D (non-digit) - любая НЕ цифра
            // \s (space)
            // \S (non-space)
            // \w (word-sym)  - то, что может быть в слове
            // \W (non-word)
            //квантификаторы ( quantifiers - указатели количества)
            // +  -  1 и более
            // *  -  0 и более
            // ?  -  0-1
            // {3} - ровно 3
            // {3,5} - от трех до пяти
            //символы-якоря
            // ^  -  начало 
            // $  -  конец
            //множества (один из)
            // [123]  -  1 или 2 или 3
            // [1 2 3] - 1 или 2 или 3 или пробел (!аккуратно!)
            // [1,2,3] - 1 или 2 или 3 или запятая (!аккуратно!)
            // [0-9]  -  диапазон
            // [a-z] - [a-zA-Z] [0-9a-f](hexidecimal) [а-пюя]
            // [^123]  -  любой символ, кроме 1,2,3
            //  

            Regex digits = new Regex(@"^\s+[123]{3}\s+$");

            if (digits.IsMatch(TextBlock2.Text))
            {
                result2.Text = "Yes";
            }
            else
            {
                result2.Text = "No";
            }
        }

        private void Email_Click(object sender, RoutedEventArgs e)
        {
            Regex email = new Regex(@"^\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$");

            if (email.IsMatch(TextBlock2.Text))
            {
                result2.Text = "Yes";
            }
            else
            {
                result2.Text = "No";
            }
        }

        private void Name_Click(object sender, RoutedEventArgs e)
        {
            Regex name = new Regex(@"^([a-z]{1}[']{1})?[A-Z]{1}[a-z]+([-]{1}[A-Z]{1}[a-z]+)?$");

            if (name.IsMatch(TextBlock2.Text))
            {
                result2.Text = "Yep";
            }
            else
            {
                result2.Text = "Nope";
            }
        }

        private void ReverseDelegateArray_Click(object sender, RoutedEventArgs e)
        {
            string[] words = TextBlock.Text.Split(' ');
            Label.Text = reverseArray(words);
        }

        private void Shuffle_Click(object sender, RoutedEventArgs e)
        {
            Label.Text = shuffler(TextBlock.Text);
        }
    }
}
