/*Unit 2
Console.WriteLine("a" == "a");
Console.WriteLine("a" == "A");
Console.WriteLine(1 == 2);

string myValue = "a";
Console.WriteLine(myValue == "a");*/
/*Challenge 1
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
Console.WriteLine((coin.Next(0, 2) == 0) ? "heads" : "tails");*/
/*Challenge 2*/
string permission = "Admin|Manager";
int level = 55;
if (permission.Contains("Admin"))
{
    Console.WriteLine((level > 55) ? "Welcome, Super Admin user." : "Welcome, Admin user.");
}
else if (permission.Contains("Manager"))
{
    Console.WriteLine((level >= 20) ? "Contact an Admin for access." : "You do not have sufficient privileges.");
}
else
{
    Console.WriteLine("You do not have sufficient privileges.");
}