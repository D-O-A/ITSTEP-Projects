using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace ADO_NET.Helpers
{
    public class RadioButtonBuilderHelper
    {
        public static List<RadioButton> BuildRadioButton(Dictionary<string, string> connectionStrings, Point point)
        {
            if (connectionStrings.Count is 0)
            {
                return new List<RadioButton>();
            }

            var radioButtons = new List<RadioButton>();

            foreach (var key in connectionStrings.Keys)
            {
                radioButtons.Add(RadioButtonInitializer(key, point));
                point.X += key.Length + 100;
            }

            return radioButtons;
        }

        private static RadioButton RadioButtonInitializer(string key, Point point)
        {
            RadioButton buffer = new RadioButton()
            {
                AutoSize = true,
                Location = new System.Drawing.Point(point.X, point.Y),
                Name = key,
                Size = new System.Drawing.Size(86, 19),
                TabIndex = 8,
                TabStop = true,
                Text = key,
                UseVisualStyleBackColor = true
            };
            
            return buffer;
        }
    }
}
