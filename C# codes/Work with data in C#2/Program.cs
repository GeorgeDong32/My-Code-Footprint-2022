/*Unit 2
string[] pallets = { "B14", "A11", "B12", "A13" };

Console.WriteLine("Sorted...");
Array.Sort(pallets);
foreach (var pallet in pallets)
{
    Console.WriteLine($"-- {pallet}");
}

Console.WriteLine("");
Console.WriteLine("Reversed...");
Array.Reverse(pallets);
foreach (var pallet in pallets)
{
    Console.WriteLine($"-- {pallet}");
}*/
/*Unit 3
string[] pallets = { "B14", "A11", "B12", "A13" };
Console.WriteLine("");

Array.Clear(pallets, 0, 2);
Console.WriteLine($"Clearing 2 ... count: {pallets.Length}");
foreach (var pallet in pallets)
{
    Console.WriteLine($"-- {pallet}");
}

Console.WriteLine("");
Array.Resize(ref pallets, 6);
Console.WriteLine($"Resizing 6 ... count: {pallets.Length}");

pallets[4] = "C01";
pallets[5] = "C02";

foreach (var pallet in pallets)
{
    Console.WriteLine($"-- {pallet}");
}

Console.WriteLine("");
Array.Resize(ref pallets, 3);
Console.WriteLine($"Resizing 3 ... count: {pallets.Length}");

foreach (var pallet in pallets)
{
    Console.WriteLine($"-- {pallet}");
}
*/
/*Unit 4
string value = "abc123";
char[] valueArray = value.ToCharArray();
Array.Reverse(valueArray);
// string result = new string(valueArray);
string result = String.Join(",", valueArray);
Console.WriteLine(result);
string[] items = result.Split(',');
foreach (string item in items)
{
    Console.WriteLine(item);
}*/
/*Fisrst Challenge*/
string pangram = "The quick brown fox jumps over the lazy dog";
string[] splitresult = pangram.Split(" ");
string[] result = new string[splitresult.Length];
int ctrl = 0;
foreach (var mids in splitresult)
{
    //Console.WriteLine(mids);
    char[] mid = mids.ToCharArray();
    Array.Reverse(mid);
    result[ctrl] = new String(mid);
    ctrl++;
}
pangram = "";
pangram = String.Join(" ", result);
Console.WriteLine(pangram);