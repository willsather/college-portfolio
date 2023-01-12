using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace COVID_Dashboard
{
    public partial class Dashboard_Form : Form
    {
        private readonly Statistics _stats;
        private Data _minnesotaSet;
        private Data _americanSet;

        public Dashboard_Form()
        {
            InitializeComponent();

            this._stats = new Statistics();

            this.PopulateForm();
            this.PopulateGraph();
        }

        private void PopulateForm()
        {
            // American Numbers
            this._americanSet = this._stats.AmericanSet;

            lbUsaCases.Text = String.Format("Total American Cases: {0:n0}", this._americanSet.Cases);
            lbUsaRecoveries.Text = String.Format("Total American Recoveries: {0:n0}", this._americanSet.Recoveries);
            lbUsaDeaths.Text = String.Format("Total American Deaths: {0:n0}", this._americanSet.Deaths);

            // Minnesota Numbers
            this._minnesotaSet = this._stats.MinnesotaSet;

            lbMnCases.Text = String.Format("Total Minnesotan Cases: {0:n0}", this._minnesotaSet.Cases);
            lbMnRecoveries.Text = String.Format("Total Minnesotan Recoveries: {0:n0}", this._minnesotaSet.Recoveries);
            lbMnDeaths.Text = String.Format("Total Minnesotan Deaths: {0:n0}", this._minnesotaSet.Deaths);
        }

        private void PopulateGraph()
        {
            this.dashboardChart.Series["America"].Points.AddXY("Cases", this._americanSet.Cases);
            this.dashboardChart.Series["America"].Points.AddXY("Recoveries", this._americanSet.Recoveries);
            this.dashboardChart.Series["America"].Points.AddXY("Deaths", this._americanSet.Deaths);

            this.dashboardChart.Series["Minnesota"].Points.AddXY("Cases", this._minnesotaSet.Cases);
            this.dashboardChart.Series["Minnesota"].Points.AddXY("Recoveries", this._minnesotaSet.Recoveries);
            this.dashboardChart.Series["Minnesota"].Points.AddXY("Deaths", this._minnesotaSet.Deaths);
        }

    }
}
