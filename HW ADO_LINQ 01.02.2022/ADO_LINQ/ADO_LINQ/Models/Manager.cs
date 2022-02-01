using System;

namespace ADO_LINQ.Models
{
    public class Manager
    {
        public Guid Id { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public string SecName { get; set; }
        public Guid IdMainDep { get; set; }
        public Guid IdSecDep { get; set; }
        public Guid IdChief { get; set; }




    }
}
