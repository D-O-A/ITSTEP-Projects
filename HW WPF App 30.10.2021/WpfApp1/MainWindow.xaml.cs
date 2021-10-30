using System;
using System.IO;
using System.Xml.Serialization;
using System.Collections.Generic;
using System.IO.Pipes;
using System.Windows;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        List<Product> products = new List<Product>();

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            //write file
            // Файлы (открытие файлов) относятся к неуправляемым ресурсам
            // зборщик мусора или платформа не в состоянии закрыть файл автоматически.
            // Наша программа должна позаботиться об этом закрытии.

            // Для обобщения работы с неуправляемыми ресурсами существует блок "using(){}"
            // То, что создается в этом блоке, разрушается (вызывается метод Dispose() ) после окончания блока
            // 

            using (StreamWriter writer = new StreamWriter("data.txt", true))
            {
                writer.Write(TextMessage.Text);
            }
        }
        private void Button_Click2(object sender, RoutedEventArgs e)
        {
            // read file
            //  Операции ввода/вывода, в случае неудачи, выбрасывают исключения
            //  Если исключения не отлавливаются, то оно разрушает программу (ОС получает недопустимую операцию)
            //  Для того, чтобы обработать исключения, потенциально опасные операции берут в блок try-catch
            //  

            try
            {
                using (StreamReader reader = new StreamReader("dataT.txt"))
                {
                    TextMessage.Text = reader.ReadToEnd();
                }

            }
            catch (IOException ex)
            {
                // блок выполняется, если будет исключение
                MessageBox.Show(ex.Message);
            }
            finally
            {
                //блок выполнится в любом случае, было исключение или нет, даже если есть return

            }
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            //draw
            TextMessage.Text += "(((;";
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            #region//  создать объект с данными из полей ввода 
            Product product = null;

            try
            {
                product = new Product
                {
                    SN = Convert.ToInt32(SN.Text),
                    Name = Name.Text,
                    Price = Convert.ToDecimal(Price.Text),
                    Discount = Convert.ToDecimal(Discount.Text)
                };
            }
            catch (FormatException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch (OverflowException ex)
            {
                MessageBox.Show(ex.Message);
            }

            if (product == null)
            {
                return;
            }
            #endregion

            TextMessage.Clear();
            //добавляем объект в коллекцию
            products.Add(product);
            //выводим в текстовое поле
            TextMessage.Text += " " + product.SN + "\t" + product.Name + "\t" + product.Price + "\t" + product.Discount;

            #region сереализуем объект


            #endregion
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            #region сериализуем коллекцию

            //using System.Xml.Serialization;
            //Создаем сереализатор. Ему нужен тип, с которым работает

            XmlSerializer serializer = new XmlSerializer(products.GetType());

            //создаем файл, в который будем сохранять результаты сериализации

            using (var writer = new StreamWriter("product.xml"))
            {
                // сериализуем объект
                serializer.Serialize(writer, products);
                MessageBox.Show("Сериализовано");
            }

            #endregion
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            try
            {
                using (StreamReader reader = new StreamReader("product.xml"))
                {
                    XmlSerializer serializer = new XmlSerializer(typeof(List<Product>));
                    products = (List<Product>)serializer.Deserialize(reader);

                }

                ShowProducts();
            }
            catch
            {
                MessageBox.Show("Ошибка чтения");
            }
        }

        private void ShowProducts(ProductComparers sorter = ProductComparers.BySN)
        {
            switch (sorter)
            {
                case ProductComparers.BySN:
                    products.Sort();
                    break;
                case ProductComparers.ByName:
                    products.Sort(new Product.NameComparer());
                    break;
                case ProductComparers.ByPrice:
                    products.Sort(new Product.PriceComparer());
                    break;
                case ProductComparers.ByDiscountAsc:
                    products.Sort(new Product.DiscountAscComparer());
                    break;
                case ProductComparers.ByDiscountDesc:
                    products.Sort(new Product.DiscountDescComparer());
                    break;
                case ProductComparers.ByPriceDiscount:
                    products.Sort(new Product.PriceDiscountComparer());
                    break;
            }

            TextMessage.Clear();
            //products.Sort(new Product.NameComparer());
            foreach (var p in products)
            {
                TextMessage.Text += p + "\n";
            }
        }

        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            ShowProducts();
        }

        private void Button_Click_6(object sender, RoutedEventArgs e)
        {
            ShowProducts(ProductComparers.ByName);
        }

        private void Button_Click_7(object sender, RoutedEventArgs e)
        {
            ShowProducts(ProductComparers.ByPrice);
        }

        private void Button_Click_8(object sender, RoutedEventArgs e)
        {
            ShowProducts(ProductComparers.ByDiscountAsc);
        }

        private void Button_Click_9(object sender, RoutedEventArgs e)
        {
            ShowProducts(ProductComparers.ByDiscountDesc);
        }

        private void Button_Click_10(object sender, RoutedEventArgs e)
        {
            ShowProducts(ProductComparers.ByPriceDiscount);
        }
    }


    public class Product : IComparable<Product>
    {
        //prop сниппет 
        public int SN { get; set; }
        public string Name { get; set; }
        public decimal Price { get; set; }
        public decimal Discount { get; set; }

        public int CompareTo(Product other)
        {
            //return SN.CompareTo(other.SN);
            if (SN < other.SN) return -1;
            if (SN > other.SN) return 1;
            return 0;
        }

        //как перегружать ToString !!!!!!!!!!!!!!!!!!!!!!!
        public override string ToString()
        {
            return String.Format("{0, -7} {1} {2} , {3}% ", SN, Name, Price, Discount);
            //                   номер аргумента, - выравние в лево, кол-во знакомест, 
        }

        public class PriceComparer : IComparer<Product>
        {
            public int Compare(Product x, Product y)
            {
                return x.Price.CompareTo(y.Price);
            }
        }
        public class NameComparer : IComparer<Product>
        {
            public int Compare(Product x, Product y)
            {
                return x.Name.CompareTo(y.Name);
            }
        }

        public class DiscountAscComparer : IComparer<Product>
        {
            public int Compare(Product x, Product y)
            {
                return x.Discount.CompareTo(y.Discount);
            }
        }

        public class DiscountDescComparer : IComparer<Product>
        {
            public int Compare(Product x, Product y)
            {
                return y.Discount.CompareTo(x.Discount);

            }
        }

        public class PriceDiscountComparer : IComparer<Product>
        {
            public int Compare(Product x, Product y)
            {
                decimal product1 = x.Price - (x.Discount * x.Price / 100);
                decimal product2 = y.Price - (y.Discount * y.Price / 100);

                switch (product1.CompareTo(product2))
                {
                    case 1:
                        return 1;
                    case 0:
                        return x.Name.CompareTo(y.Name);
                    case -1:
                        return -1;
                }
                return 0;
            }
        }
    }

    public enum ProductComparers
    {
        BySN,
        ByName,
        ByPrice,
        ByDiscountAsc,
        ByDiscountDesc,
        ByPriceDiscount
    }
}
