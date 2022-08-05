using System;
using Classes;

namespace MySuperBank
{
    internal class Program
    {
        static void Main(string[] args)
        {
            BankAccount account = new BankAccount("Test");
            Console.WriteLine($"Account {account.Number} is created for {account.Owner} with {account.Balance} dollar(s).");
        }
    }
}
