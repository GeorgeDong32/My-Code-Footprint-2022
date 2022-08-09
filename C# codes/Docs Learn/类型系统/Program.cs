//Interface
Car car1 = new Car();
Car car2 = new Car();
car1.Make = "German";
car1.Model = "BMW";
car1.Year = "2022";
car2.Make = "Italy";
car2.Model = "Ferrari";
car2.Year = "1998";
Console.WriteLine(car1 == car2);
interface IEquatable<T>
{
    bool Equals(T obj);
}
public class Car : IEquatable<Car>
{
    public string? Make { get; set; }
    public string? Model { get; set; }
    public string? Year { get; set; }

    // Implementation of IEquatable<T> interface
    public bool Equals(Car? car)
    {
        return (this.Make, this.Model, this.Year) ==
            (car?.Make, car?.Model, car?.Year);
    }
}