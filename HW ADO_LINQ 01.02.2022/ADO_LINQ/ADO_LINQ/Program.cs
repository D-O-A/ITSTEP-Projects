using Microsoft.Extensions.Configuration;
using Microsoft.Practices.Unity;  // Unity container
using System;
using System.Windows.Forms;

namespace ADO_LINQ
{
    static class Program
    {
        //public static UnityContainer DiContainer;
        public static UnityContainer ConfigContainer;
        public static UnityContainer ProjectPathContainer;

        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            //DiContainer = new UnityContainer();
            //ConfigContainer = new UnityContainer();
            //ProjectPathContainer = new UnityContainer();

            //Вариант 1
            //DiContainer.RegisterInstance(typeof(IConfiguration),
            //    new ConfigurationBuilder()
            //    .AddJsonFile(CurrentDirHelper.GetCurrentDir() + "appsettings.json")
            //    .Build());

            //Вариант 2
            //ProjectPathContainer.RegisterInstance(typeof(AppContext), new Context.AppContext());

            //ConfigContainer.RegisterInstance(typeof(IConfiguration),
            //    new ConfigurationBuilder()
            //        .AddJsonFile( ProjectPathContainer.Resolve<Context.AppContext> + "appsettings.json")
            //        .Build());


            Application.SetHighDpiMode(HighDpiMode.SystemAware);
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
