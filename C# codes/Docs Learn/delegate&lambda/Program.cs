Func<int, int> square = x => x * x;
Console.WriteLine(square(5));
// Output:
// 25

System.Linq.Expressions.Expression<Func<int, int>> e = x => x * x;
Console.WriteLine(e);
// Output:
// x => (x * x)