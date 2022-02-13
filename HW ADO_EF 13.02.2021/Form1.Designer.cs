
namespace ADO_EF
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonDepartments = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.buttonProdPrice = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonGenerate = new System.Windows.Forms.Button();
            this.genCnt = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.labelDepartments = new System.Windows.Forms.Label();
            this.labelManagers = new System.Windows.Forms.Label();
            this.labelProducts = new System.Windows.Forms.Label();
            this.labelSales = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.buttonSalesAll = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.buttonManagers = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonDepartments
            // 
            this.buttonDepartments.Location = new System.Drawing.Point(12, 12);
            this.buttonDepartments.Name = "buttonDepartments";
            this.buttonDepartments.Size = new System.Drawing.Size(91, 23);
            this.buttonDepartments.TabIndex = 0;
            this.buttonDepartments.Text = "Departments";
            this.buttonDepartments.UseVisualStyleBackColor = true;
            this.buttonDepartments.Click += new System.EventHandler(this.buttonDepartments_Click);
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 15;
            this.listBox1.Location = new System.Drawing.Point(159, 12);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(373, 334);
            this.listBox1.TabIndex = 1;
            // 
            // buttonProdPrice
            // 
            this.buttonProdPrice.Location = new System.Drawing.Point(12, 69);
            this.buttonProdPrice.Name = "buttonProdPrice";
            this.buttonProdPrice.Size = new System.Drawing.Size(91, 23);
            this.buttonProdPrice.TabIndex = 2;
            this.buttonProdPrice.Text = "by Price";
            this.buttonProdPrice.UseVisualStyleBackColor = true;
            this.buttonProdPrice.Click += new System.EventHandler(this.buttonProdPrice_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.buttonGenerate);
            this.groupBox1.Controls.Add(this.genCnt);
            this.groupBox1.Location = new System.Drawing.Point(556, 148);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(141, 124);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Sales";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(131, 15);
            this.label1.TabIndex = 2;
            this.label1.Text = "Cгенерировать записи";
            // 
            // buttonGenerate
            // 
            this.buttonGenerate.Location = new System.Drawing.Point(6, 84);
            this.buttonGenerate.Name = "buttonGenerate";
            this.buttonGenerate.Size = new System.Drawing.Size(75, 23);
            this.buttonGenerate.TabIndex = 1;
            this.buttonGenerate.Text = "Generate";
            this.buttonGenerate.UseVisualStyleBackColor = true;
            this.buttonGenerate.Click += new System.EventHandler(this.buttonGenerate_Click);
            // 
            // genCnt
            // 
            this.genCnt.Location = new System.Drawing.Point(6, 50);
            this.genCnt.Name = "genCnt";
            this.genCnt.Size = new System.Drawing.Size(100, 23);
            this.genCnt.TabIndex = 0;
            this.genCnt.Text = "100";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.labelDepartments);
            this.groupBox2.Controls.Add(this.labelManagers);
            this.groupBox2.Controls.Add(this.labelProducts);
            this.groupBox2.Controls.Add(this.labelSales);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Location = new System.Drawing.Point(554, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(143, 103);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Статистика БД";
            // 
            // labelDepartments
            // 
            this.labelDepartments.AutoSize = true;
            this.labelDepartments.Location = new System.Drawing.Point(99, 21);
            this.labelDepartments.Name = "labelDepartments";
            this.labelDepartments.Size = new System.Drawing.Size(13, 15);
            this.labelDepartments.TabIndex = 7;
            this.labelDepartments.Text = "0";
            // 
            // labelManagers
            // 
            this.labelManagers.AutoSize = true;
            this.labelManagers.Location = new System.Drawing.Point(99, 39);
            this.labelManagers.Name = "labelManagers";
            this.labelManagers.Size = new System.Drawing.Size(13, 15);
            this.labelManagers.TabIndex = 6;
            this.labelManagers.Text = "0";
            // 
            // labelProducts
            // 
            this.labelProducts.AutoSize = true;
            this.labelProducts.Location = new System.Drawing.Point(99, 57);
            this.labelProducts.Name = "labelProducts";
            this.labelProducts.Size = new System.Drawing.Size(13, 15);
            this.labelProducts.TabIndex = 5;
            this.labelProducts.Text = "0";
            // 
            // labelSales
            // 
            this.labelSales.AutoSize = true;
            this.labelSales.Location = new System.Drawing.Point(99, 75);
            this.labelSales.Name = "labelSales";
            this.labelSales.Size = new System.Drawing.Size(13, 15);
            this.labelSales.TabIndex = 4;
            this.labelSales.Text = "0";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(11, 75);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(54, 15);
            this.label5.TabIndex = 3;
            this.label5.Text = "Продаж:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(11, 57);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(55, 15);
            this.label4.TabIndex = 2;
            this.label4.Text = "Товаров:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(11, 39);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(82, 15);
            this.label3.TabIndex = 1;
            this.label3.Text = "Сотрудников:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(11, 21);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 15);
            this.label2.TabIndex = 0;
            this.label2.Text = "Отделов:";
            // 
            // buttonSalesAll
            // 
            this.buttonSalesAll.Location = new System.Drawing.Point(6, 22);
            this.buttonSalesAll.Name = "buttonSalesAll";
            this.buttonSalesAll.Size = new System.Drawing.Size(129, 23);
            this.buttonSalesAll.TabIndex = 4;
            this.buttonSalesAll.Text = "Все";
            this.buttonSalesAll.UseVisualStyleBackColor = true;
            this.buttonSalesAll.Click += new System.EventHandler(this.buttonSalesAll_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.buttonSalesAll);
            this.groupBox3.Location = new System.Drawing.Point(12, 110);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(141, 162);
            this.groupBox3.TabIndex = 5;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Продажи";
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Location = new System.Drawing.Point(18, 181);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(129, 23);
            this.dateTimePicker1.TabIndex = 6;
            // 
            // buttonManagers
            // 
            this.buttonManagers.Location = new System.Drawing.Point(12, 40);
            this.buttonManagers.Name = "buttonManagers";
            this.buttonManagers.Size = new System.Drawing.Size(91, 23);
            this.buttonManagers.TabIndex = 7;
            this.buttonManagers.Text = "Managers";
            this.buttonManagers.UseVisualStyleBackColor = true;
            this.buttonManagers.Click += new System.EventHandler(this.buttonManagers_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonManagers);
            this.Controls.Add(this.dateTimePicker1);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.buttonProdPrice);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.buttonDepartments);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonDepartments;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button buttonProdPrice;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonGenerate;
        private System.Windows.Forms.TextBox genCnt;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label labelDepartments;
        private System.Windows.Forms.Label labelManagers;
        private System.Windows.Forms.Label labelProducts;
        private System.Windows.Forms.Label labelSales;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button buttonSalesAll;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private System.Windows.Forms.Button buttonManagers;
    }
}

