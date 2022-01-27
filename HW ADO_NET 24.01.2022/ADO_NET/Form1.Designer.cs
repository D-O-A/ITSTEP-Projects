
namespace ADO_NET
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
            this.components = new System.ComponentModel.Container();
            this.button1 = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.buttonCreate = new System.Windows.Forms.Button();
            this.buttonInsert = new System.Windows.Forms.Button();
            this.buttonDisconnect = new System.Windows.Forms.Button();
            this.buttonSelect = new System.Windows.Forms.Button();
            this.SelectModel = new System.Windows.Forms.Button();
            this.contextDbBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.contextDbBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.contextDbBindingSource2 = new System.Windows.Forms.BindingSource(this.components);
            this.contextDbBindingSource3 = new System.Windows.Forms.BindingSource(this.components);
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.contextDbBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.contextDbBindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.contextDbBindingSource2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.contextDbBindingSource3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Segoe UI", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button1.Location = new System.Drawing.Point(27, 60);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(160, 42);
            this.button1.TabIndex = 0;
            this.button1.Text = "Connect DB";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 15;
            this.listBox1.Location = new System.Drawing.Point(206, 55);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(325, 364);
            this.listBox1.TabIndex = 1;
            // 
            // buttonCreate
            // 
            this.buttonCreate.Font = new System.Drawing.Font("Segoe UI", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.buttonCreate.Location = new System.Drawing.Point(27, 108);
            this.buttonCreate.Name = "buttonCreate";
            this.buttonCreate.Size = new System.Drawing.Size(160, 42);
            this.buttonCreate.TabIndex = 2;
            this.buttonCreate.Text = "Create table";
            this.buttonCreate.UseVisualStyleBackColor = true;
            this.buttonCreate.Click += new System.EventHandler(this.buttonCreate_Click);
            // 
            // buttonInsert
            // 
            this.buttonInsert.Font = new System.Drawing.Font("Segoe UI", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.buttonInsert.Location = new System.Drawing.Point(27, 156);
            this.buttonInsert.Name = "buttonInsert";
            this.buttonInsert.Size = new System.Drawing.Size(160, 42);
            this.buttonInsert.TabIndex = 3;
            this.buttonInsert.Text = "Insert Line";
            this.buttonInsert.UseVisualStyleBackColor = true;
            this.buttonInsert.Click += new System.EventHandler(this.buttonInsert_Click);
            // 
            // buttonDisconnect
            // 
            this.buttonDisconnect.Font = new System.Drawing.Font("Segoe UI", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.buttonDisconnect.Location = new System.Drawing.Point(27, 300);
            this.buttonDisconnect.Name = "buttonDisconnect";
            this.buttonDisconnect.Size = new System.Drawing.Size(160, 42);
            this.buttonDisconnect.TabIndex = 4;
            this.buttonDisconnect.Text = "Disconnect DB";
            this.buttonDisconnect.UseVisualStyleBackColor = true;
            this.buttonDisconnect.Click += new System.EventHandler(this.buttonDisconnect_Click);
            // 
            // buttonSelect
            // 
            this.buttonSelect.Font = new System.Drawing.Font("Segoe UI", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.buttonSelect.Location = new System.Drawing.Point(27, 204);
            this.buttonSelect.Name = "buttonSelect";
            this.buttonSelect.Size = new System.Drawing.Size(160, 42);
            this.buttonSelect.TabIndex = 5;
            this.buttonSelect.Text = "SELECT *";
            this.buttonSelect.UseVisualStyleBackColor = true;
            this.buttonSelect.Click += new System.EventHandler(this.buttonSelect_Click);
            // 
            // SelectModel
            // 
            this.SelectModel.Font = new System.Drawing.Font("Segoe UI", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.SelectModel.Location = new System.Drawing.Point(27, 252);
            this.SelectModel.Name = "SelectModel";
            this.SelectModel.Size = new System.Drawing.Size(160, 42);
            this.SelectModel.TabIndex = 6;
            this.SelectModel.Text = "SELECT * (Model)";
            this.SelectModel.UseVisualStyleBackColor = true;
            this.SelectModel.Click += new System.EventHandler(this.SelectModel_Click);
            // 
            // contextDbBindingSource
            // 
            this.contextDbBindingSource.DataSource = typeof(ADO_NET.Models.ContextDb);
            // 
            // contextDbBindingSource1
            // 
            this.contextDbBindingSource1.DataSource = typeof(ADO_NET.Models.ContextDb);
            // 
            // contextDbBindingSource2
            // 
            this.contextDbBindingSource2.DataSource = typeof(ADO_NET.Models.ContextDb);
            // 
            // contextDbBindingSource3
            // 
            this.contextDbBindingSource3.DataSource = typeof(ADO_NET.Models.ContextDb);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(537, 55);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 25;
            this.dataGridView1.Size = new System.Drawing.Size(380, 364);
            this.dataGridView1.TabIndex = 7;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(946, 450);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.SelectModel);
            this.Controls.Add(this.buttonSelect);
            this.Controls.Add(this.buttonDisconnect);
            this.Controls.Add(this.buttonInsert);
            this.Controls.Add(this.buttonCreate);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.contextDbBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.contextDbBindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.contextDbBindingSource2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.contextDbBindingSource3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button buttonCreate;
        private System.Windows.Forms.Button buttonInsert;
        private System.Windows.Forms.Button buttonDisconnect;
        private System.Windows.Forms.Button buttonSelect;
        private System.Windows.Forms.Button SelectModel;
        private System.Windows.Forms.BindingSource contextDbBindingSource;
        private System.Windows.Forms.BindingSource contextDbBindingSource1;
        private System.Windows.Forms.BindingSource contextDbBindingSource2;
        private System.Windows.Forms.BindingSource contextDbBindingSource3;
        private System.Windows.Forms.DataGridView dataGridView1;
    }
}

