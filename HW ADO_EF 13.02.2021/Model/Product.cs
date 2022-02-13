using System;

namespace ADO_EF.Model
{
    internal class Product
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
