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
            account.MakeDeposit(100, DateTime.Now, "Deposit");
            account.MakeWithdrawal(355, DateTime.Now, "Withdraw");
            Console.WriteLine(account.GetAccountHistory());
            // Test for a negative balance.
            try
            {
                account.MakeWithdrawal(750, DateTime.Now, "Attempt to overdraw");
            }
            catch (InvalidOperationException e)
            {
                Console.WriteLine("Exception caught trying to overdraw");
                Console.WriteLine(e.ToString());
                return;
            }
        }
    }
}
