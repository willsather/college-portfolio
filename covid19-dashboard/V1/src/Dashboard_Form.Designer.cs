namespace COVID_Dashboard
{
    partial class Dashboard_Form
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.TotalCaseNumber = new System.Windows.Forms.Label();
            this.TotalCaseLabel = new System.Windows.Forms.Label();
            this.TotalAmericanLabel = new System.Windows.Forms.Label();
            this.TotalAmericanNumber = new System.Windows.Forms.Label();
            this.TotalInternationalRecoveries = new System.Windows.Forms.Label();
            this.TotalInternationalRecoveriesNumber = new System.Windows.Forms.Label();
            this.AmericanRecoveriesNumber = new System.Windows.Forms.Label();
            this.TotalAmericanRecoveriesLabel = new System.Windows.Forms.Label();
            this.InternationalDeathNumber = new System.Windows.Forms.Label();
            this.InternationalDeathLabel = new System.Windows.Forms.Label();
            this.AmericanDeathNumber = new System.Windows.Forms.Label();
            this.AmericanDeathLabel = new System.Windows.Forms.Label();
            this.dashboardChart = new System.Windows.Forms.DataVisualization.Charting.Chart();
            ((System.ComponentModel.ISupportInitialize)(this.dashboardChart)).BeginInit();
            this.SuspendLayout();
            // 
            // TotalCaseNumber
            // 
            this.TotalCaseNumber.AutoSize = true;
            this.TotalCaseNumber.Location = new System.Drawing.Point(290, 25);
            this.TotalCaseNumber.Name = "TotalCaseNumber";
            this.TotalCaseNumber.Size = new System.Drawing.Size(0, 25);
            this.TotalCaseNumber.TabIndex = 0;
            // 
            // TotalCaseLabel
            // 
            this.TotalCaseLabel.AutoSize = true;
            this.TotalCaseLabel.Location = new System.Drawing.Point(21, 25);
            this.TotalCaseLabel.Name = "TotalCaseLabel";
            this.TotalCaseLabel.Size = new System.Drawing.Size(263, 25);
            this.TotalCaseLabel.TabIndex = 1;
            this.TotalCaseLabel.Text = "Total International Cases: ";
            // 
            // TotalAmericanLabel
            // 
            this.TotalAmericanLabel.AutoSize = true;
            this.TotalAmericanLabel.Location = new System.Drawing.Point(21, 87);
            this.TotalAmericanLabel.Name = "TotalAmericanLabel";
            this.TotalAmericanLabel.Size = new System.Drawing.Size(235, 25);
            this.TotalAmericanLabel.TabIndex = 3;
            this.TotalAmericanLabel.Text = "Total American Cases: ";
            // 
            // TotalAmericanNumber
            // 
            this.TotalAmericanNumber.AutoSize = true;
            this.TotalAmericanNumber.Location = new System.Drawing.Point(284, 87);
            this.TotalAmericanNumber.Name = "TotalAmericanNumber";
            this.TotalAmericanNumber.Size = new System.Drawing.Size(0, 25);
            this.TotalAmericanNumber.TabIndex = 2;
            // 
            // TotalInternationalRecoveries
            // 
            this.TotalInternationalRecoveries.AutoSize = true;
            this.TotalInternationalRecoveries.Location = new System.Drawing.Point(21, 194);
            this.TotalInternationalRecoveries.Name = "TotalInternationalRecoveries";
            this.TotalInternationalRecoveries.Size = new System.Drawing.Size(310, 25);
            this.TotalInternationalRecoveries.TabIndex = 4;
            this.TotalInternationalRecoveries.Text = "Total International Recoveries: ";
            // 
            // TotalInternationalRecoveriesNumber
            // 
            this.TotalInternationalRecoveriesNumber.AutoSize = true;
            this.TotalInternationalRecoveriesNumber.Location = new System.Drawing.Point(347, 194);
            this.TotalInternationalRecoveriesNumber.Name = "TotalInternationalRecoveriesNumber";
            this.TotalInternationalRecoveriesNumber.Size = new System.Drawing.Size(0, 25);
            this.TotalInternationalRecoveriesNumber.TabIndex = 5;
            // 
            // AmericanRecoveriesNumber
            // 
            this.AmericanRecoveriesNumber.AutoSize = true;
            this.AmericanRecoveriesNumber.Location = new System.Drawing.Point(347, 243);
            this.AmericanRecoveriesNumber.Name = "AmericanRecoveriesNumber";
            this.AmericanRecoveriesNumber.Size = new System.Drawing.Size(0, 25);
            this.AmericanRecoveriesNumber.TabIndex = 7;
            // 
            // TotalAmericanRecoveriesLabel
            // 
            this.TotalAmericanRecoveriesLabel.AutoSize = true;
            this.TotalAmericanRecoveriesLabel.Location = new System.Drawing.Point(21, 243);
            this.TotalAmericanRecoveriesLabel.Name = "TotalAmericanRecoveriesLabel";
            this.TotalAmericanRecoveriesLabel.Size = new System.Drawing.Size(282, 25);
            this.TotalAmericanRecoveriesLabel.TabIndex = 6;
            this.TotalAmericanRecoveriesLabel.Text = "Total American Recoveries: ";
            // 
            // InternationalDeathNumber
            // 
            this.InternationalDeathNumber.AutoSize = true;
            this.InternationalDeathNumber.Location = new System.Drawing.Point(331, 347);
            this.InternationalDeathNumber.Name = "InternationalDeathNumber";
            this.InternationalDeathNumber.Size = new System.Drawing.Size(0, 25);
            this.InternationalDeathNumber.TabIndex = 9;
            // 
            // InternationalDeathLabel
            // 
            this.InternationalDeathLabel.AutoSize = true;
            this.InternationalDeathLabel.Location = new System.Drawing.Point(21, 347);
            this.InternationalDeathLabel.Name = "InternationalDeathLabel";
            this.InternationalDeathLabel.Size = new System.Drawing.Size(270, 25);
            this.InternationalDeathLabel.TabIndex = 8;
            this.InternationalDeathLabel.Text = "Total International Deaths: ";
            // 
            // AmericanDeathNumber
            // 
            this.AmericanDeathNumber.AutoSize = true;
            this.AmericanDeathNumber.Location = new System.Drawing.Point(331, 398);
            this.AmericanDeathNumber.Name = "AmericanDeathNumber";
            this.AmericanDeathNumber.Size = new System.Drawing.Size(0, 25);
            this.AmericanDeathNumber.TabIndex = 11;
            // 
            // AmericanDeathLabel
            // 
            this.AmericanDeathLabel.AutoSize = true;
            this.AmericanDeathLabel.Location = new System.Drawing.Point(21, 398);
            this.AmericanDeathLabel.Name = "AmericanDeathLabel";
            this.AmericanDeathLabel.Size = new System.Drawing.Size(242, 25);
            this.AmericanDeathLabel.TabIndex = 10;
            this.AmericanDeathLabel.Text = "Total American Deaths: ";
            // 
            // dashboardChart
            // 
            this.dashboardChart.Anchor = System.Windows.Forms.AnchorStyles.None;
            chartArea1.Name = "ChartArea1";
            this.dashboardChart.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.dashboardChart.Legends.Add(legend1);
            this.dashboardChart.Location = new System.Drawing.Point(419, 38);
            this.dashboardChart.Name = "dashboardChart";
            this.dashboardChart.Palette = System.Windows.Forms.DataVisualization.Charting.ChartColorPalette.Excel;
            series1.BorderColor = System.Drawing.Color.Transparent;
            series1.BorderWidth = 0;
            series1.ChartArea = "ChartArea1";
            series1.Color = System.Drawing.Color.DarkGreen;
            series1.Legend = "Legend1";
            series1.Name = "International";
            series2.ChartArea = "ChartArea1";
            series2.Color = System.Drawing.Color.DarkRed;
            series2.Legend = "Legend1";
            series2.Name = "America";
            this.dashboardChart.Series.Add(series1);
            this.dashboardChart.Series.Add(series2);
            this.dashboardChart.Size = new System.Drawing.Size(655, 456);
            this.dashboardChart.TabIndex = 12;
            this.dashboardChart.Text = "chart1";
            // 
            // Dashboard_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkGray;
            this.ClientSize = new System.Drawing.Size(1156, 621);
            this.Controls.Add(this.dashboardChart);
            this.Controls.Add(this.AmericanDeathNumber);
            this.Controls.Add(this.AmericanDeathLabel);
            this.Controls.Add(this.InternationalDeathNumber);
            this.Controls.Add(this.InternationalDeathLabel);
            this.Controls.Add(this.AmericanRecoveriesNumber);
            this.Controls.Add(this.TotalAmericanRecoveriesLabel);
            this.Controls.Add(this.TotalInternationalRecoveriesNumber);
            this.Controls.Add(this.TotalInternationalRecoveries);
            this.Controls.Add(this.TotalAmericanLabel);
            this.Controls.Add(this.TotalAmericanNumber);
            this.Controls.Add(this.TotalCaseLabel);
            this.Controls.Add(this.TotalCaseNumber);
            this.Name = "Dashboard_Form";
            this.Text = "Dashboard_Form";
            ((System.ComponentModel.ISupportInitialize)(this.dashboardChart)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label TotalCaseNumber;
        private System.Windows.Forms.Label TotalCaseLabel;
        private System.Windows.Forms.Label TotalAmericanLabel;
        private System.Windows.Forms.Label TotalAmericanNumber;
        private System.Windows.Forms.Label TotalInternationalRecoveries;
        private System.Windows.Forms.Label TotalInternationalRecoveriesNumber;
        private System.Windows.Forms.Label AmericanRecoveriesNumber;
        private System.Windows.Forms.Label TotalAmericanRecoveriesLabel;
        private System.Windows.Forms.Label InternationalDeathNumber;
        private System.Windows.Forms.Label InternationalDeathLabel;
        private System.Windows.Forms.Label AmericanDeathNumber;
        private System.Windows.Forms.Label AmericanDeathLabel;
        private System.Windows.Forms.DataVisualization.Charting.Chart dashboardChart;
    }
}