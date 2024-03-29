﻿using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for Minesweeper.xaml
    /// </summary>
    public partial class Minesweeper : Window
    {
        private readonly Random random;
        private bool winFlag;

        public Minesweeper()
        {
            InitializeComponent();
            random = new Random();
            //SystemSounds.Exclamation.Play();

            for (int y = 0; y < App.SizeY; y++)
            {
                for (int x = 0; x < App.SizeX; x++)
                {
                    var mineLabel = new MineLabel
                    {
                        X = x,
                        Y = y,
                        labelState = LabelState.Unvisited,
                        FontSize = 30,
                        VerticalContentAlignment = VerticalAlignment.Center,
                        HorizontalContentAlignment = HorizontalAlignment.Center
                    };
                    mineLabel.MouseDown += MineLabel_MouseDown;
                    this.RegisterName("label_" + x + "_" + y, mineLabel);
                    Field.Children.Add(mineLabel);
                }
            }
            Restart();
        }

        private void MineLabel_MouseDown(object sender, MouseButtonEventArgs e)
        {
            var mineLabel = sender as MineLabel;
            winFlag = true;

            if (mineLabel == null)
            {
                return;
            }

            if (e.LeftButton == MouseButtonState.Pressed)
            {
                //если клик на мину - конец
                if (mineLabel.IsMine)
                {
                    if (MessageBoxResult.Yes == MessageBox.Show("Еще раз?", "Бух!", MessageBoxButton.YesNo))
                    {
                        Restart();
                        return;
                    }
                    else
                    {
                        this.Close();
                    }
                }
                else
                {
                    mineLabel.labelState = LabelState.Open;
                }
            }
            if (e.RightButton == MouseButtonState.Pressed)
            {
                if (mineLabel.labelState == LabelState.Unvisited)
                {
                    mineLabel.Content = "\x2690";
                    mineLabel.labelState = LabelState.Flagged;
                }
                else if (mineLabel.labelState == LabelState.Flagged)
                {
                    mineLabel.Content = "\x224b";
                    mineLabel.labelState = LabelState.Unvisited;
                }
                return;
            }

            //определяем соседей
            int x = mineLabel.X;
            int y = mineLabel.Y;
            //массив предполагаемых имен:
            string[] names =
            {
                "label_" + (x-1) + "_" + (y-1),
                "label_" + (x-1) + "_" + (y),
                "label_" + (x-1) + "_" + (y+1),
                "label_" + (x)   + "_" + (y-1),
                "label_" + (x)   + "_" + (y+1),
                "label_" + (x+1) + "_" + (y-1),
                "label_" + (x+1) + "_" + (y),
                "label_" + (x+1) + "_" + (y+1)
            };
            //счетчик мин
            int mines = 0;
            //цикл по именам
            foreach (string name in names)
            {
                // Ищем по имени (ссылку на Label)
                MineLabel label = this.FindName(name) as MineLabel;
                if (label != null) //такое имя найдено
                {
                    // Проверяем мина ли это
                    if (label.IsMine)
                    {
                        //увеличиваем счетчик
                        mines++;
                    }
                }
            }
            mineLabel.Content = mines.ToString();

            switch (mines)
            {
                case 0:
                    mineLabel.Foreground = Brushes.Crimson;
                    break;
                case 1:
                    mineLabel.Foreground = Brushes.Orange;
                    break;
                case 2:
                    mineLabel.Foreground = Brushes.GreenYellow;
                    break;
                case 3:
                    mineLabel.Foreground = Brushes.DarkGreen;
                    break;
                case 4:
                    mineLabel.Foreground = Brushes.DarkBlue;
                    break;
                case 5:
                    mineLabel.Foreground = Brushes.DeepSkyBlue;
                    break;
                case 6:
                    mineLabel.Foreground = Brushes.BlueViolet;
                    break;
                case 7:
                    mineLabel.Foreground = Brushes.DeepPink;
                    break;
                case 8:
                    mineLabel.Foreground = Brushes.Brown;
                    break;
            }

            foreach (var child in Field.Children)
            {
                MineLabel label = child as MineLabel;
                if (label.labelState == LabelState.Unvisited && !label.IsMine)
                {
                    winFlag = false;
                }
            }

            if (winFlag)
            {
                MessageBox.Show("Победа, победа, вместо обеда!", "YOU WON!");
                Close();
            }
        }

        private void Restart()
        {
            foreach (var child in Field.Children)
            {
                MineLabel label = child as MineLabel;
                if (label != null)
                {
                    bool isMine = random.Next(8) == 0;
                    label.IsMine = isMine;
                    label.Content = "\x224b";
                    label.Foreground = Brushes.Black;
                    label.labelState = LabelState.Unvisited;
                }
            }

            winFlag = true;
        }
    }

    class MineLabel : Label
    {
        public int X { get; set; }
        public int Y { get; set; }
        public bool IsMine { get; set; }

        public LabelState labelState;
    }

    enum LabelState
    {
        Unvisited,
        Flagged,
        Open
    }
}
