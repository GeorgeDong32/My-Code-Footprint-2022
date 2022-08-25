namespace MauiApp1;

public partial class MainPage : ContentPage
{
	int count = 0;

	public MainPage()
	{
		InitializeComponent();
	}

	private void OnCounterClicked(object sender, EventArgs e)
	{
		count++;

		if (count == 1)
		{
			CounterBtn.Text = $"Clicked {count} time";
			//MyCounter.Text = $"Clicked {count} time";
        }

		else
		{ 
			CounterBtn.Text = $"Clicked {count} times"; 
			//MyCounter.Text = $"Clicked {count} times";
        }

		SemanticScreenReader.Announce(CounterBtn.Text);
		//SemanticScreenReader.Announce(MyCounter.Text);
	}

    private byte[] GetRandomBytes(int n)
    {
        //  Fill an array of bytes of length "n" with random numbers.
        var rand = new Random();
        var randomBytes = new byte[n];
        rand.NextBytes(randomBytes);
		return randomBytes;
    }

    private void MyBtn_Clicked(object sender, EventArgs e)
	{
		var rgb = GetRandomBytes(3);
		var color = Color.FromRgba(Convert.ToInt32(rgb[0]), Convert.ToInt32(rgb[1]), Convert.ToInt32(rgb[2]), 255);
        MyBtn.BackgroundColor = color;
		MyBtn.Text = "Clicked";
    }
}

