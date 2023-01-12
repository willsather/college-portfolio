namespace COVID_Dashboard
{
    partial class Symptoms_Form
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Symptoms_Form));
            this.labelSymptoms = new System.Windows.Forms.Label();
            this.symptomTextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // labelSymptoms
            // 
            this.labelSymptoms.AutoSize = true;
            this.labelSymptoms.Location = new System.Drawing.Point(85, 189);
            this.labelSymptoms.Name = "labelSymptoms";
            this.labelSymptoms.Size = new System.Drawing.Size(0, 25);
            this.labelSymptoms.TabIndex = 0;
            // 
            // symptomTextBox
            // 
            this.symptomTextBox.BackColor = System.Drawing.Color.DarkGray;
            this.symptomTextBox.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.symptomTextBox.Location = new System.Drawing.Point(55, 55);
            this.symptomTextBox.Multiline = true;
            this.symptomTextBox.Name = "symptomTextBox";
            this.symptomTextBox.Size = new System.Drawing.Size(798, 449);
            this.symptomTextBox.TabIndex = 1;
            this.symptomTextBox.Text = resources.GetString("symptomTextBox.Text");
            // 
            // Symptoms_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkGray;
            this.ClientSize = new System.Drawing.Size(1095, 631);
            this.Controls.Add(this.symptomTextBox);
            this.Controls.Add(this.labelSymptoms);
            this.Name = "Symptoms_Form";
            this.Text = "Symptoms_Form";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelSymptoms;
        private System.Windows.Forms.TextBox symptomTextBox;
    }
}