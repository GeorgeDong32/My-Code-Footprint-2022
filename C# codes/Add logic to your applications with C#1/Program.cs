/*Unit 2
Console.WriteLine("a" == "a");
Console.WriteLine("a" == "A");
Console.WriteLine(1 == 2);

string myValue = "a";
Console.WriteLine(myValue == "a");*/
/*Challenge*/
Random coin = new Random();
int result = coin.Next(0, 2);
if (result == 1)
{
    Console.WriteLine("heads");
}
else
{
    Console.WriteLine("tails");
}
//
//Random coin = new Random();
Console.WriteLine((coin.Next(0, 2) == 0) ? "heads" : "tails");