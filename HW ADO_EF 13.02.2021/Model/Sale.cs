using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ADO_EF.Model
{
    public class Sale
    {
        public Guid     Id { get; set; }
        public Guid     Id_Manager { get; set; }
        public Guid     Id_Product { get; set; }
        public int      Cnt { get; set; }
        public DateTime Moment { get; set; }

        public override string ToString()
        {
            return $"{Moment.ToShortDateString()} {Cnt} pcs {Id_Product.ToString().Substring(25)}-{Id_Manager.ToString().Substring(25)}";
        }
    }
}
