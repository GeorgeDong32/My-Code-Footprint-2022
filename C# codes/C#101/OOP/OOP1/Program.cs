using System;
using Classes;

namespace MySuperBank
{
    internal class Program
    {
        static void Main(string[] args)
        {
            BankAccount account = new BankAccount("Test",400);
            Console.WriteLine($"Account {account.Number} is created for {account.Owner} with {account.Balance} dollar(s).");
            account.MakeWithdrawal(500, DateTime.Now, "Rent payment");
            Console.WriteLine(account.Balance);
            account.MakeDeposit(100, DateTime.Now, "Friend paid me back");
            Console.WriteLine(account.Balance);
        }
    }
}
