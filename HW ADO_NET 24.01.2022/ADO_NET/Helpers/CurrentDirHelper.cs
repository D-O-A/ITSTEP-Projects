using System.Windows.Forms;

namespace ADO_NET.Helpers
{
    public class CurrentDirHelper
    {
        public static string GetCurrentDir()
        {
            string currentDir = Application.StartupPath;
            int binIndex = currentDir.IndexOf(@"\bin\");

            return binIndex == -1 ? currentDir : currentDir.Substring(0, binIndex);
        }
    }

}
