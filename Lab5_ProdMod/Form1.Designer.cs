namespace Lab5_ProdMod
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.RULES_TB = new System.Windows.Forms.TextBox();
            this.Target_BOX = new System.Windows.Forms.Panel();
            this.Axiom_BOX = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.Res_TB = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.Forward_B = new System.Windows.Forms.Button();
            this.Back_B = new System.Windows.Forms.Button();
            this.Clear_B = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // RULES_TB
            // 
            this.RULES_TB.BackColor = System.Drawing.Color.LemonChiffon;
            this.RULES_TB.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.RULES_TB.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.RULES_TB.Location = new System.Drawing.Point(10, 24);
            this.RULES_TB.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.RULES_TB.Multiline = true;
            this.RULES_TB.Name = "RULES_TB";
            this.RULES_TB.ReadOnly = true;
            this.RULES_TB.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.RULES_TB.Size = new System.Drawing.Size(322, 727);
            this.RULES_TB.TabIndex = 0;
            // 
            // Target_BOX
            // 
            this.Target_BOX.AutoScroll = true;
            this.Target_BOX.BackColor = System.Drawing.Color.PeachPuff;
            this.Target_BOX.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Target_BOX.Location = new System.Drawing.Point(490, 24);
            this.Target_BOX.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Target_BOX.Name = "Target_BOX";
            this.Target_BOX.Size = new System.Drawing.Size(289, 727);
            this.Target_BOX.TabIndex = 2;
            // 
            // Axiom_BOX
            // 
            this.Axiom_BOX.BackColor = System.Drawing.Color.PaleTurquoise;
            this.Axiom_BOX.Location = new System.Drawing.Point(337, 24);
            this.Axiom_BOX.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Axiom_BOX.Name = "Axiom_BOX";
            this.Axiom_BOX.Size = new System.Drawing.Size(150, 726);
            this.Axiom_BOX.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.MediumSpringGreen;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(334, 7);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "АКСИОМЫ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.MediumSpringGreen;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(488, 7);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(45, 15);
            this.label2.TabIndex = 4;
            this.label2.Text = "ЦЕЛИ";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.MediumSpringGreen;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(8, 7);
            this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(94, 15);
            this.label3.TabIndex = 5;
            this.label3.Text = "ПРОДУКЦИИ";
            // 
            // Res_TB
            // 
            this.Res_TB.BackColor = System.Drawing.Color.Lavender;
            this.Res_TB.Location = new System.Drawing.Point(783, 24);
            this.Res_TB.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Res_TB.Multiline = true;
            this.Res_TB.Name = "Res_TB";
            this.Res_TB.ReadOnly = true;
            this.Res_TB.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.Res_TB.Size = new System.Drawing.Size(546, 727);
            this.Res_TB.TabIndex = 6;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.MediumSpringGreen;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(781, 7);
            this.label4.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(57, 15);
            this.label4.TabIndex = 7;
            this.label4.Text = "ВЫВОД";
            // 
            // Forward_B
            // 
            this.Forward_B.BackColor = System.Drawing.Color.MediumSpringGreen;
            this.Forward_B.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Forward_B.Location = new System.Drawing.Point(1333, 24);
            this.Forward_B.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Forward_B.Name = "Forward_B";
            this.Forward_B.Size = new System.Drawing.Size(101, 98);
            this.Forward_B.TabIndex = 8;
            this.Forward_B.Text = "Прямой вывод";
            this.Forward_B.UseVisualStyleBackColor = false;
            this.Forward_B.Click += new System.EventHandler(this.Forward_B_Click);
            // 
            // Back_B
            // 
            this.Back_B.BackColor = System.Drawing.Color.MediumSpringGreen;
            this.Back_B.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Back_B.Location = new System.Drawing.Point(1333, 127);
            this.Back_B.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Back_B.Name = "Back_B";
            this.Back_B.Size = new System.Drawing.Size(101, 98);
            this.Back_B.TabIndex = 9;
            this.Back_B.Text = "Обратный вывод";
            this.Back_B.UseVisualStyleBackColor = false;
            this.Back_B.Click += new System.EventHandler(this.Back_B_Click);
            // 
            // Clear_B
            // 
            this.Clear_B.BackColor = System.Drawing.Color.LightCoral;
            this.Clear_B.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Clear_B.Location = new System.Drawing.Point(1332, 229);
            this.Clear_B.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Clear_B.Name = "Clear_B";
            this.Clear_B.Size = new System.Drawing.Size(101, 98);
            this.Clear_B.TabIndex = 10;
            this.Clear_B.Text = "Очистить вывод";
            this.Clear_B.UseVisualStyleBackColor = false;
            this.Clear_B.Click += new System.EventHandler(this.Clear_B_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.ClientSize = new System.Drawing.Size(1443, 774);
            this.Controls.Add(this.Clear_B);
            this.Controls.Add(this.Back_B);
            this.Controls.Add(this.Forward_B);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.Res_TB);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Axiom_BOX);
            this.Controls.Add(this.Target_BOX);
            this.Controls.Add(this.RULES_TB);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox RULES_TB;
        private System.Windows.Forms.Panel Target_BOX;
        private System.Windows.Forms.Panel Axiom_BOX;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox Res_TB;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button Forward_B;
        private System.Windows.Forms.Button Back_B;
        private System.Windows.Forms.Button Clear_B;
    }
}

