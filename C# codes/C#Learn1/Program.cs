string[] values = { "12.3", "45", "ABC", "11", "DEF" };
string charre = "";
decimal sum = 0; decimal mid = 0;
foreach (var val in values)
{
    if (decimal.TryParse(val, out mid))
    {
        sum += mid;
    }
    else
    {
        charre += val;
    }
}

Console.WriteLine($"Message: {charre}");
Console.WriteLine($"Total: {sum}");