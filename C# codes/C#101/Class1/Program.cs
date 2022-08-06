using System;

namespace Class1
{
    public enum SomeRootVegetable
    {
        HorseRadish,
        Radish,
        Turnip
    }
    public enum Seasons
    {
        None = 0,
        Summer = 1,
        Autumn = 2,
        Winter = 4,
        Spring = 8,
        All = Summer | Autumn | Winter | Spring
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            var turnip = SomeRootVegetable.Turnip;
            var spring = Seasons.Spring;
            var startingOnEquinox = Seasons.Spring | Seasons.Autumn;
            var theYear = Seasons.All;
        }
    }
}