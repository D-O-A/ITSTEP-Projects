namespace ADO_EF.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class MainDepOptional : DbMigration
    {
        public override void Up()
        {
            AlterColumn("dbo.Managers", "Id_main_dep", c => c.Guid());
        }
        
        public override void Down()
        {
            AlterColumn("dbo.Managers", "Id_main_dep", c => c.Guid(nullable: false));
        }
    }
}
