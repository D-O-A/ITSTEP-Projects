namespace ADO_EF.Migrations
{
    using System.Data.Entity.Migrations;

    public partial class Init : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.Departments",
                c => new
                {
                    Id = c.Guid(nullable: false),
                    Name = c.String(),
                })
                .PrimaryKey(t => t.Id);

            CreateTable(
                "dbo.Managers",
                c => new
                {
                    Id = c.Guid(nullable: false),
                    Surname = c.String(),
                    Name = c.String(),
                    SecName = c.String(),
                    Id_main_dep = c.Guid(nullable: false),
                    Id_sec_dep = c.Guid(),
                    Id_chief = c.Guid(),
                })
                .PrimaryKey(t => t.Id);

        }

        public override void Down()
        {
            DropTable("dbo.Managers");
            DropTable("dbo.Departments");
        }
    }
}
