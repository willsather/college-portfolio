using System;
using System.Net;
using Newtonsoft.Json.Linq;

namespace COVID_Dashboard
{
    public class Statistics
    {
        private Data _minnesotaData;
        private Data _americanData;

        public Statistics()
        {
            this._americanData = new Data();
            this._minnesotaData = new Data();

            this.LoadData();
        }

        public Data AmericanSet => this._americanData;
        public Data MinnesotaSet => this._minnesotaData;

        public void LoadData()
        {
            using (var wc = new WebClient())
            {
                ServicePointManager.Expect100Continue = true;
                ServicePointManager.SecurityProtocol = (SecurityProtocolType)(0xc0 | 0x300 | 0xc00);

                try
                {
                    var usaJson = wc.DownloadString("https://api.covidtracking.com/v1/us/current.json");

                    // United States of America Parsing
                    var usaJsonObject = JArray.Parse(usaJson);
                    
                    this._americanData.Cases = (int)usaJsonObject[0]["positive"];
                    this._americanData.Recoveries = (int)usaJsonObject[0]["recovered"];
                    this._americanData.Deaths = (int)usaJsonObject[0]["death"];

                    // Minnesota Parsing
                    var mnJson = wc.DownloadString("https://api.covidtracking.com/v1/states/mn/current.json");

                    // HACK: fix external JSON issues to make an array
                    var finalString = "[" + mnJson + "]";

                    var mnJsonObject = JArray.Parse(finalString);
                    this._minnesotaData.Cases = (int)mnJsonObject[0]["positive"];
                    this._minnesotaData.Recoveries = (int)mnJsonObject[0]["recovered"];
                    this._minnesotaData.Deaths = (int)mnJsonObject[0]["death"];

                }
                catch (Exception ex)
                {
                    Console.WriteLine("______________________________\n");
                    Console.WriteLine("Failed to download JSON string\n");
                    Console.WriteLine("______________________________\n");
                    Console.WriteLine(ex);
                }
            }
        }
    }
    public struct Data
    {
        /// <summary>
        /// How many total COVID-19 cases exist
        /// </summary>
        public int Cases { get; set; }

        /// <summary>
        /// How many people have recovered
        /// </summary>
        public int Recoveries { get; set; }

        /// <summary>
        /// How many people have died from COVID-19
        /// </summary>
        public int Deaths { get; set; }
    }
}