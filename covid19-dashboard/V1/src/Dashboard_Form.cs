using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace COVID_Dashboard
{
    public partial class Dashboard_Form : Form
    {
        public Dashboard_Form()
        {
            InitializeComponent();
            string _TotalInternationalCaseNumber = getInternationalTotalCases();
            string _TotalInternationalRecoveriesNumber = getInternationalTotalRecoveries();
            string _TotalInternationalDeathNumber = getInternationalTotalDeaths();

            string _AmericanCaseNumber = getAmericanTotalCases();
            string _AmericanRecoveriesNumber = getAmericanTotalRecoveries();
            string _AmericanDeathNumber = getAmericanTotalDeaths();

            // International Numbers
            TotalCaseNumber.Text = _TotalInternationalCaseNumber;
            TotalInternationalRecoveriesNumber.Text = _TotalInternationalRecoveriesNumber;
            InternationalDeathNumber.Text = _TotalInternationalDeathNumber;

            // American Numbers
            TotalAmericanNumber.Text = _AmericanCaseNumber;
            AmericanRecoveriesNumber.Text = _AmericanRecoveriesNumber;
            AmericanDeathNumber.Text = _AmericanDeathNumber;

            // Create Dashboard Chart
            this.dashboardChart.Series["International"].Points.AddXY("Cases", _TotalInternationalCaseNumber);
            this.dashboardChart.Series["International"].Points.AddXY("Recoveries", _TotalInternationalRecoveriesNumber);
            this.dashboardChart.Series["International"].Points.AddXY("Deaths", _TotalInternationalDeathNumber);

            this.dashboardChart.Series["America"].Points.AddXY("Cases", _AmericanCaseNumber);
            this.dashboardChart.Series["America"].Points.AddXY("Recoveries", _AmericanRecoveriesNumber);
            this.dashboardChart.Series["America"].Points.AddXY("Deaths", _AmericanDeathNumber);

        }

        private string getInternationalTotalCases ()
        {
 
            string url = "https://www.worldometers.info/coronavirus/";
            var web = new HtmlAgilityPack.HtmlWeb();

            HtmlAgilityPack.HtmlDocument doc = new HtmlAgilityPack.HtmlDocument();
            doc = web.LoadFromBrowser(url);

            string cases = doc.DocumentNode.SelectNodes("//html//body//div[3]//div[2]//div[1]//div//div[4]//div//span")[0].InnerText;

            return cases;
            
        }

        private string getInternationalTotalRecoveries()
        {

            string url = "https://www.worldometers.info/coronavirus/";
            var web = new HtmlAgilityPack.HtmlWeb();

            HtmlAgilityPack.HtmlDocument doc = new HtmlAgilityPack.HtmlDocument();
            doc = web.LoadFromBrowser(url);

            string cases = doc.DocumentNode.SelectNodes("//html//body//div[3]//div[2]//div[1]//div//div[7]//div//span")[0].InnerText;

            return cases;

        }

        private string getInternationalTotalDeaths()
        {

            string url = "https://www.worldometers.info/coronavirus/";
            var web = new HtmlAgilityPack.HtmlWeb();

            HtmlAgilityPack.HtmlDocument doc = new HtmlAgilityPack.HtmlDocument();
            doc = web.LoadFromBrowser(url);

            string cases = doc.DocumentNode.SelectNodes("//html//body//div[3]//div[2]//div[1]//div//div[6]//div//span")[0].InnerText;

            return cases;

        }

        private string getAmericanTotalCases()
        {

            string url = "https://www.worldometers.info/coronavirus/#countries";
            var web = new HtmlAgilityPack.HtmlWeb();

            HtmlAgilityPack.HtmlDocument doc = new HtmlAgilityPack.HtmlDocument();
            doc = web.LoadFromBrowser(url);

            string cases = doc.DocumentNode.SelectNodes("//html//body//div[3]//div[3]//div/div[3]//div[1]//div//table//tbody[1]//tr[4]//td[2]")[0].InnerText;

            return cases;

        }

        private string getAmericanTotalDeaths()
        {

            string url = "https://www.worldometers.info/coronavirus/#countries";
            var web = new HtmlAgilityPack.HtmlWeb();

            HtmlAgilityPack.HtmlDocument doc = new HtmlAgilityPack.HtmlDocument();
            doc = web.LoadFromBrowser(url);

            string cases = doc.DocumentNode.SelectNodes("//html//body//div[3]//div[3]//div//div[3]//div[1]//div//table//tbody[1]//tr[4]//td[4]")[0].InnerText;

            return cases;

        }

        private string getAmericanTotalRecoveries()
        {

            string url = "https://www.worldometers.info/coronavirus/#countries";
            var web = new HtmlAgilityPack.HtmlWeb();

            HtmlAgilityPack.HtmlDocument doc = new HtmlAgilityPack.HtmlDocument();
            doc = web.LoadFromBrowser(url);

            string cases = doc.DocumentNode.SelectNodes("//html//body//div[3]//div[3]//div//div[3]//div[1]//div//table//tbody[1]//tr[4]//td[6]")[0].InnerText;

            return cases;

        }

    }
}
