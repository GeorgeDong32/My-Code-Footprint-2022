/*Func<int, int> square = x => x * x;
Console.WriteLine(square(5));
// Output:
// 25

System.Linq.Expressions.Expression<Func<int, int>> e = x => x * x;
Console.WriteLine(e);
// Output:
// x => (x * x)
//空括号表示没有入参
Action line = () => Console.WriteLine();
//只有一个参数可以省略括号
Func<double, double> cube = (x) => x * x * x;
Console.WriteLine(cube(3));

Func<int, int, int> constant = (_, _) => 42;
Console.WriteLine(constant(0, 0));*/