namespace ADO_EF.Migrations
{
    using System.Data.Entity.Migrations;

    public partial class Sales : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.Sales",
                c => new
                {
                    Id = c.Guid(nullable: false),
                    Id_Manager = c.Guid(nullable: false),
                    Id_Product = c.Guid(nullable: false),
                    Cnt = c.Int(nullable: false),
                    Moment = c.DateTime(nullable: false),
                })
                .PrimaryKey(t => t.Id);

        }

        public override void Down()
        {
            DropTable("dbo.Sales");
        }
    }
}
