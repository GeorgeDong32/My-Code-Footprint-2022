/*Example
Random random = new Random();
int current = random.Next(1, 11);

do
{
    current = random.Next(1, 11);

    if (current >= 8) continue;

    Console.WriteLine(current);
} while (current != 7);*/
/*Challenge*/
Random attack = new Random();
int Hero_HP = 10; int Monster_HP = 10;
do
{
    int Hero_at = attack.Next(1, 10);
    Monster_HP -= Hero_at;
    Console.WriteLine($"Monster was damaged and lost {Hero_at} health and now has {Monster_HP} health.");
    if (Monster_HP <= 0)
        break;
    int Monster_at = attack.Next(1, 10);
    Hero_HP -= Monster_at;
    Console.WriteLine($"Hero was damaged and lost {Monster_at} health and now has {Hero_HP} health.");
} while (Hero_HP > 0 && Monster_HP > 0);

Console.WriteLine((Hero_HP > 0) ? "Hero Wins!" : "Monster Wins!");