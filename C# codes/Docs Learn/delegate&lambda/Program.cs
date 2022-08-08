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
public partial class Form1 : Form
{
    public Form1()
    {
        InitializeComponent();
        button1.Click += button1_Click;
    }

    private async void button1_Click(object sender, EventArgs e)
    {
        await ExampleMethodAsync();
        textBox1.Text += "\r\nControl returned to Click event handler.\n";
    }

    private async Task ExampleMethodAsync()
    {
        // The following line simulates a task-returning asynchronous process.
        await Task.Delay(1000);
    }
}