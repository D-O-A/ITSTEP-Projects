using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ADO_LINQ.Context
{
    public class AppContext
    {
        public string GetProjectPath()
        {
            string currentDir = Application.StartupPath;
            int binIndex = currentDir.IndexOf(@"\bin\");

            return binIndex == -1 ? currentDir : currentDir.Substring(0, binIndex);
        }
    }
}
