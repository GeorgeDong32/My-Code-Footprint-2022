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

    private void MyBtn_Clicked(object sender, EventArgs e)
	{
		var rand = new Random();
		var colorint = rand.Next(0, 255);
		var color = Color.FromRgba(rand.Next(), rand.Next(0, 255), rand.Next(0, 255), 255);
		Console.WriteLine($"The int of color is{colorint}");
		MyBtn.TextColor = color;
        
    }
}

