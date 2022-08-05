using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MySuperBank
{
    internal class Program
    {
        static void Main(string[] args)
        {
            BankAccount account = new BankAccount("Test", 10000);
            Console.WriteLine($"Account {account.Number} is created for {account.Owner} with {account.Balance} dollar(s).");
        }
    }
}
