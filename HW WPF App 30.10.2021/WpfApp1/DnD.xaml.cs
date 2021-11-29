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
        private FrameworkElement draggedObject;
        private FrameworkElement phantomObject;

        private Point touchPoint;
        private Point initialPoint;

        public DnD()
        {
            InitializeComponent();
            draggedObject = null;
            phantomObject = null;
        }

        private void Mouse_Up(object sender, MouseButtonEventArgs e)
        {
            if (draggedObject != null)
            {
                try
                {
                    switch (e.ChangedButton)
                    {
                        case MouseButton.Left: //дз
                            if (Canvas.GetLeft(draggedObject) < 400)
                            {
                                //возвращаем в исходную позицию
                                Canvas.SetLeft(draggedObject, initialPoint.X);
                                Canvas.SetTop(draggedObject, initialPoint.Y);
                            }

                            draggedObject = null;
                            Field.ReleaseMouseCapture(); // освобождение мыши
                            break;
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }

            try
            {

                Canvas.SetLeft(SubjectEllipse, Canvas.GetLeft(phantomObject));
                Canvas.SetTop(SubjectEllipse, Canvas.GetTop(phantomObject));
            }
            catch(Exception)
            {
            }

            //******* Phantom ********
            if (phantomObject != null)
            {
                Field.Children.Remove(phantomObject);
                Field.ReleaseMouseCapture();
                phantomObject = null;
            }
        }
        private void Mouse_Move(object sender, MouseEventArgs e)
        {
            if (draggedObject != null)
            {
                Canvas.SetLeft(draggedObject, e.GetPosition(Field).X - touchPoint.X);
                Canvas.SetTop(draggedObject, e.GetPosition(Field).Y - touchPoint.Y);
            }

            //******* Phantom ********
            if (phantomObject != null)
            {
                Canvas.SetLeft(phantomObject, e.GetPosition(Field).X - touchPoint.X);
                Canvas.SetTop(phantomObject, e.GetPosition(Field).Y - touchPoint.Y);
            }
        }
        private void Subject_MouseDown(object sender, MouseButtonEventArgs e)
        {
            switch (e.ChangedButton)
            {
                case MouseButton.Left:
                    draggedObject = sender as FrameworkElement;

                    if (draggedObject == null)
                    {
                        return;
                    }

                    touchPoint = e.GetPosition(draggedObject);
                    initialPoint.X = Canvas.GetLeft(draggedObject);
                    initialPoint.Y = Canvas.GetTop(draggedObject);
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

        private void Ellipse_MouseDown(object sender, MouseButtonEventArgs e)
        {
            // Вариация с фантомным объектом
            Ellipse proto = sender as Ellipse;
            phantomObject = new Ellipse
            {
                Width = proto.Width,
                Height = proto.Height,
                Stroke = Brushes.Tomato
            };
            Field.Children.Add(phantomObject);
            Field.CaptureMouse();
            Canvas.SetLeft(phantomObject, Canvas.GetLeft(proto));
            Canvas.SetTop(phantomObject, Canvas.GetTop(proto));
            touchPoint = e.GetPosition(proto);
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
 * 
 * 
 * Событийное программирвание (Событийно ориентированная модель) хорошо показывает себя в задачах расширяемости
 * BIOS дает эту самую модель
 * 
 * 
 */
