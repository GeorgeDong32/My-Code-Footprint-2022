using System;

namespace MySuperBank
{
    public class BankAccount
    {
        public string Number { get; set; }
        public string Owner { get; set; }
        public decimal Balance { get; set; }
        private static int accountNumberSeed = 11111111;
        public BankAccount(string owner, decimal balance)
        {
            Number = accountNumberSeed.ToString();
            Owner = owner;
            Balance = balance;
            accountNumberSeed++;
        }
    
        public void MakeDeposit(decimal amount, DateTime date, string note)
        {

        }
        public void MakeWithdrawal(decimal amount, DateTime date, string note)
        {

        }
    }
}
