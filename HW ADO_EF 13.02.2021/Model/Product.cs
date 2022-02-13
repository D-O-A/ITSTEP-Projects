using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ADO_EF.Model
{
    class Product
    {
        public Guid Id { get; set; }
        public String Name { get; set; }

        // ! типу FLOAT в БД соответствует тип double 
        public double Price { get; set; }

        public override string ToString()
        {
            return $"{Name} - {Price} грн";
        }
    }
}
