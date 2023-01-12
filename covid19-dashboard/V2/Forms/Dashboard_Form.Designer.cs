using System;

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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series3 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series4 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.lbUsaCases = new System.Windows.Forms.Label();
            this.lbMnCases = new System.Windows.Forms.Label();
            this.lbUsaRecoveries = new System.Windows.Forms.Label();
            this.lbMnRecoveries = new System.Windows.Forms.Label();
            this.lbUsaDeaths = new System.Windows.Forms.Label();
            this.lbMnDeaths = new System.Windows.Forms.Label();
            this.dashboardChart = new System.Windows.Forms.DataVisualization.Charting.Chart();
            ((System.ComponentModel.ISupportInitialize)(this.dashboardChart)).BeginInit();
            this.SuspendLayout();
            // 
            // lbUsaCases
            // 
            this.lbUsaCases.AutoSize = true;
            this.lbUsaCases.Location = new System.Drawing.Point(21, 25);
            this.lbUsaCases.Name = "lbUsaCases";
            this.lbUsaCases.Size = new System.Drawing.Size(0, 25);
            this.lbUsaCases.TabIndex = 1;
            // 
            // lbMnCases
            // 
            this.lbMnCases.AutoSize = true;
            this.lbMnCases.Location = new System.Drawing.Point(21, 87);
            this.lbMnCases.Name = "lbMnCases";
            this.lbMnCases.Size = new System.Drawing.Size(0, 25);
            this.lbMnCases.TabIndex = 3;
            // 
            // lbUsaRecoveries
            // 
            this.lbUsaRecoveries.AutoSize = true;
            this.lbUsaRecoveries.Location = new System.Drawing.Point(21, 194);
            this.lbUsaRecoveries.Name = "lbUsaRecoveries";
            this.lbUsaRecoveries.Size = new System.Drawing.Size(0, 25);
            this.lbUsaRecoveries.TabIndex = 4;
            // 
            // lbMnRecoveries
            // 
            this.lbMnRecoveries.AutoSize = true;
            this.lbMnRecoveries.Location = new System.Drawing.Point(21, 243);
            this.lbMnRecoveries.Name = "lbMnRecoveries";
            this.lbMnRecoveries.Size = new System.Drawing.Size(0, 25);
            this.lbMnRecoveries.TabIndex = 6;
            // 
            // lbUsaDeaths
            // 
            this.lbUsaDeaths.AutoSize = true;
            this.lbUsaDeaths.Location = new System.Drawing.Point(21, 347);
            this.lbUsaDeaths.Name = "lbUsaDeaths";
            this.lbUsaDeaths.Size = new System.Drawing.Size(0, 25);
            this.lbUsaDeaths.TabIndex = 8;
            // 
            // lbMnDeaths
            // 
            this.lbMnDeaths.AutoSize = true;
            this.lbMnDeaths.Location = new System.Drawing.Point(21, 398);
            this.lbMnDeaths.Name = "lbMnDeaths";
            this.lbMnDeaths.Size = new System.Drawing.Size(0, 25);
            this.lbMnDeaths.TabIndex = 10;
            // 
            // dashboardChart
            // 
            this.dashboardChart.Anchor = System.Windows.Forms.AnchorStyles.None;
            chartArea2.Name = "ChartArea1";
            this.dashboardChart.ChartAreas.Add(chartArea2);
            legend2.Name = "Legend1";
            this.dashboardChart.Legends.Add(legend2);
            this.dashboardChart.Location = new System.Drawing.Point(817, 87);
            this.dashboardChart.Name = "dashboardChart";
            this.dashboardChart.Palette = System.Windows.Forms.DataVisualization.Charting.ChartColorPalette.Excel;
            series3.BorderColor = System.Drawing.Color.Transparent;
            series3.BorderWidth = 0;
            series3.ChartArea = "ChartArea1";
            series3.Color = System.Drawing.Color.DarkGreen;
            series3.Legend = "Legend1";
            series3.Name = "Minnesota";
            series4.ChartArea = "ChartArea1";
            series4.Color = System.Drawing.Color.DarkRed;
            series4.Legend = "Legend1";
            series4.Name = "America";
            this.dashboardChart.Series.Add(series3);
            this.dashboardChart.Series.Add(series4);
            this.dashboardChart.Size = new System.Drawing.Size(655, 456);
            this.dashboardChart.TabIndex = 12;
            this.dashboardChart.Text = "chart1";
            // 
            // Dashboard_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkGray;
            this.ClientSize = new System.Drawing.Size(1484, 810);
            this.Controls.Add(this.dashboardChart);
            this.Controls.Add(this.lbMnDeaths);
            this.Controls.Add(this.lbUsaDeaths);
            this.Controls.Add(this.lbMnRecoveries);
            this.Controls.Add(this.lbUsaRecoveries);
            this.Controls.Add(this.lbMnCases);
            this.Controls.Add(this.lbUsaCases);
            this.Name = "Dashboard_Form";
            this.Text = "Dashboard_Form";
            ((System.ComponentModel.ISupportInitialize)(this.dashboardChart)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label lbUsaCases;
        private System.Windows.Forms.Label lbMnCases;
        private System.Windows.Forms.Label lbUsaRecoveries;
        private System.Windows.Forms.Label lbMnRecoveries;
        private System.Windows.Forms.Label lbUsaDeaths;
        private System.Windows.Forms.Label lbMnDeaths;
        private System.Windows.Forms.DataVisualization.Charting.Chart dashboardChart;
    }
}