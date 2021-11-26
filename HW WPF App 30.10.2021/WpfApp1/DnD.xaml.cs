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
    /// Interaction logic for DnD.xaml
    /// </summary>
    public partial class DnD : Window
    {
        private bool isDragged;
        private Point touchPoint;

        public DnD()
        {
            InitializeComponent();
            isDragged = false;
        }

        private void Mouse_Up(object sender, MouseButtonEventArgs e)
        {
            touchPoint.X = Canvas.GetLeft(Subject) + Subject.Width / 2;
            touchPoint.Y = Canvas.GetTop(Subject) + Subject.Height / 2;
                
            switch (e.ChangedButton)
            {
                case MouseButton.Left:
                    isDragged = false;
                    if ((touchPoint.X < Canvas.GetLeft(LandingZone) || touchPoint.X > Canvas.GetLeft(LandingZone) + LandingZone.Width)
                        || (touchPoint.Y < Canvas.GetTop(LandingZone) || touchPoint.Y > Canvas.GetTop(LandingZone) + LandingZone.Height))
                    {
                        Canvas.SetLeft(Subject, 100);
                        Canvas.SetTop(Subject, 75);
                        Field.ReleaseMouseCapture();
                    }
                    else
                    {
                        Field.ReleaseMouseCapture(); // освобождение мыши
                    }
                    break;
            }
        }

        private void Mouse_Move(object sender, MouseEventArgs e)
        {
            if (isDragged)
            {
                Canvas.SetLeft(Subject, e.GetPosition(Field).X - touchPoint.X);
                Canvas.SetTop(Subject, e.GetPosition(Field).Y - touchPoint.Y);
            }
        }

        private void Subject_MouseDown(object sender, MouseButtonEventArgs e)
        {
            switch (e.ChangedButton)
            {
                case MouseButton.Left:
                    isDragged = true;
                    touchPoint = e.GetPosition(Subject);
                    Field.CaptureMouse(); // захват - события
                    // мыши будут попадать в это окно, даже если указатель из него выйдет
                    break;
                case MouseButton.Middle:
                    break;
                case MouseButton.Right:
                    break;
                case MouseButton.XButton1:
                    break;
                case MouseButton.XButton2:
                    break;
            }

    }
}
}
/* DnD (Drag 'n' Drop)
 * Технология визуального интерфейса, связанная с "перетсаскиваним" объектов мышью
 * 
 * Для реализации необходимо:
 * - по событию нажатия перейти в режим "перетаскивания"
 * - по событию движения менять позицию объекта
 * - по событию "отжатия" - зафиксировать новую позицию
 * 
 * Вариации:
 * "фантомы" - копии объектов, перетягиваемые вместо оригиналов
 * "контейнеры" - если не попадаем в контейнер, "перетягивание" отменяется
 * 
 * Особенности:
 * - событие нажатия получает сам объект, тогда как движение и "отжатие" - все окно
 * Иначе при резких движениях курсор уходит с объекта и он треяет события
 * - для перетягивания за точку "взятия" необходимо запоминать координаты этой точки в событии "нажатия",
 * а корректировать в событии движеия мыши
 * - похожая на п.1 ситуация возможна с окном:
 * при выходе указателя мыши из окна "теряется" событие "отжатия" кнопки.
 * Решается "захватом" указателя на время нажатия
 * 
 * 
 */
