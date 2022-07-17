//First Challenge
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

//Second Challenge
int value1 = 12;
decimal value2 = 6.2m;
float value3 = 4.3f;

int result1 = Convert.ToInt32(value1 / value2);
Console.WriteLine($"Divide value1 by value2, display the result as an int: {result1}");

decimal result2 = Convert.ToDecimal(value2 / (decimal)value3);
Console.WriteLine($"Divide value2 by value3, display the result as a decimal: {result2}");

float result3 = (float)value3 / value1;
Console.WriteLine($"Divide value3 by value1, display the result as a float: {result3}");