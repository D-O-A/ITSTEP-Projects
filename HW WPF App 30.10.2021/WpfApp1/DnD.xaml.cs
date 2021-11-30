using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
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
        private FrameworkElement prototypeObject;

        private Point touchPoint;
        private Point landingZoneCenter;
        private Point subjectCenter;
        private Point initialPoint;
        private double heightModifier;

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

                            subjectCenter.X = Canvas.GetLeft(draggedObject) + draggedObject.Width / 2;
                            subjectCenter.Y = Canvas.GetTop(draggedObject) + draggedObject.Height / 2;

                            if ((subjectCenter.X < Canvas.GetLeft(LandingZone) || subjectCenter.X > Canvas.GetLeft(LandingZone) + LandingZone.Width)
                                || (subjectCenter.Y < Canvas.GetTop(LandingZone) || subjectCenter.Y > Canvas.GetTop(LandingZone) + LandingZone.Height))
                            {
                                //возвращаем в исходную позицию
                                Canvas.SetLeft(draggedObject, initialPoint.X);
                                Canvas.SetTop(draggedObject, initialPoint.Y);
                            }
                            else
                            {
                                // модификатор размера по Y для центрирования чтобы фигурки размешались одна под другой.
                                // если модификатор больше, чем можно "вместить" фигурки, то обнуляем и начинаем центрировать снова с верха допустимой зоны
                                // но все равно фигурки могут "наслаиваться" друг на друга
                                if (heightModifier > Canvas.GetTop(LandingZone) + LandingZone.Height / 3.5)
                                {
                                    heightModifier = 0;
                                }

                                Canvas.SetLeft(draggedObject, landingZoneCenter.X);
                                Canvas.SetTop(draggedObject, landingZoneCenter.Y + heightModifier);
                                heightModifier += 60;
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

            //******* Phantom ********
            if (phantomObject != null)
            {
                subjectCenter.X = Canvas.GetLeft(phantomObject) + phantomObject.Width / 2;
                subjectCenter.Y = Canvas.GetTop(phantomObject) + phantomObject.Height / 2;

                Field.Children.Remove(phantomObject);

                if ((subjectCenter.X < Canvas.GetLeft(LandingZone) || subjectCenter.X > Canvas.GetLeft(LandingZone) + LandingZone.Width)
                    || (subjectCenter.Y < Canvas.GetTop(LandingZone) || subjectCenter.Y > Canvas.GetTop(LandingZone) + LandingZone.Height))
                {
                    Canvas.SetLeft(phantomObject, initialPoint.X);
                    Canvas.SetTop(phantomObject, initialPoint.Y);
                }
                else
                {
                    if (heightModifier > Canvas.GetTop(LandingZone) + LandingZone.Height / 3.5)
                    {
                        heightModifier = 0;
                    }

                    Canvas.SetLeft(prototypeObject, landingZoneCenter.X);
                    Canvas.SetTop(prototypeObject, landingZoneCenter.Y + heightModifier);
                    heightModifier += 60;
                }

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

                    landingZoneCenter.X = Canvas.GetLeft(LandingZone) + LandingZone.Width / 4;
                    landingZoneCenter.Y = Canvas.GetTop(LandingZone) + 10;

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
            prototypeObject = sender as FrameworkElement;

            if (prototypeObject == null)
            {
                return;
            }

            // ellipse конечно в идеале только для фантомов, которые имеют форму круга, а для "квадратных" фантомов лучше создавать rectangle и другой обработчик событий
            phantomObject = new Ellipse
            {
                Width = prototypeObject.Width,
                Height = prototypeObject.Height,
                Stroke = Brushes.Black
            };
            Field.Children.Add(phantomObject);
            Field.CaptureMouse();

            landingZoneCenter.X = Canvas.GetLeft(LandingZone) + LandingZone.Width / 4;
            landingZoneCenter.Y = Canvas.GetTop(LandingZone) + 10;

            initialPoint.X = Canvas.GetLeft(phantomObject);
            initialPoint.Y = Canvas.GetTop(phantomObject);

            Canvas.SetLeft(phantomObject, Canvas.GetLeft(prototypeObject));
            Canvas.SetTop(phantomObject, Canvas.GetTop(prototypeObject));
            touchPoint = e.GetPosition(prototypeObject);
        }
    }
}
/* DnD (Drag 'n' Drop)
 * Технология визуального интерфейса, связанная с "перетаскиванием" объектов мышью
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
 * а корректировать в событии движения мыши
 * - похожая на п.1 ситуация возможна с окном:
 * при выходе указателя мыши из окна "теряется" событие "отжатия" кнопки.
 * Решается "захватом" указателя на время нажатия
 * 
 * 
 * 
 * 
 * Событийное программирование (Событийно ориентированная модель) хорошо показывает себя в задачах расширяемости
 * BIOS дает эту самую модель
 * 
 * 
 */
