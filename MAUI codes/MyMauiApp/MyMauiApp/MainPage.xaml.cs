using System;
namespace MyMauiApp;

public partial class MainPage : ContentPage
{
    public MainPage()
    {
        InitializeComponent();
    }

    void LoginButton_Clicked(object sender, EventArgs e)
    {
        this.DisplayAlert("Login Process:", "Please confirm your account:" + Account, "Yes", "No");
    }
}

