using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using Windows.Data.Json;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media.Imaging;

namespace ShowMeAPicture
{
    public sealed partial class MainPage : Page
    {
        const string SubscriptionKey = "your key";
        const string UriBase = "https://api.cognitive.microsoft.com/bing/v7.0/images/search";

        public MainPage()
        {
            this.InitializeComponent();
        }

        private void OnKeyDownHandler(object sender, KeyRoutedEventArgs e)
        {
            // If the user presses Enter, read the search terms and use them to find an image.

            if (e.Key == Windows.System.VirtualKey.Enter &&
                    searchTermsTextBox.Text.Trim().Length > 0)
            {
                // Search for an image by using the Bing Image Search API,
                // supplying the search term entered in the XAML text box.
                string imageUrl = FindUrlOfImage(searchTermsTextBox.Text);

                // Display the first image found.
                foundObjectImage.Source = new BitmapImage(new Uri(imageUrl, UriKind.Absolute));

            }
        }

        struct SearchResult
        {
            public String jsonResult;
            public Dictionary<String, String> relevantHeaders;
        }

        private string FindUrlOfImage(string targetString)
        {
            // Call the method that does the search.
            SearchResult result = PerformBingImageSearch(targetString);

            // Process the JSON response from the Bing Image Search API and get the URL of the first image returned.
            JsonObject jsonObj = JsonObject.Parse(result.jsonResult);
            JsonArray results = jsonObj.GetNamedArray("value");
            if (results.Count > 0)
            {
                JsonObject first_result = results.GetObjectAt(0);
                String imageUrl = first_result.GetNamedString("contentUrl");
                return imageUrl;
            }
            else
                return "https://docs.microsoft.com/learn/windows/build-internet-connected-windows10-apps/media/imagenotfound.png";
        }

        static SearchResult PerformBingImageSearch(string searchTerms)
        {
            // Create the web-based query that talks to the Bing API.
            string uriQuery = UriBase + "?q=" + Uri.EscapeDataString(searchTerms);
            WebRequest request = WebRequest.Create(uriQuery);
            request.Headers["Ocp-Apim-Subscription-Key"] = SubscriptionKey;
            HttpWebResponse response = (HttpWebResponse)request.GetResponseAsync().Result;
            string json = new StreamReader(response.GetResponseStream()).ReadToEnd();

            // Create the result object for the return value.
            var searchResult = new SearchResult()
            {
                jsonResult = json,
                relevantHeaders = new Dictionary<String, String>()
            };

            // Extract the Bing HTTP headers.
            foreach (String header in response.Headers)
            {
                if (header.StartsWith("BingAPIs-") || header.StartsWith("X-MSEdge-"))
                    searchResult.relevantHeaders[header] = response.Headers[header];
            }

            return searchResult;
        }

    }
}