#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

char all_list[] = 
{
'@', '#', '!', '$', '%', '^', '&', '*', '(', ')',
'-', '_', '+','=', '[', ']', '{', '}', '\\', '|', '\'', '\"', ';', ':',
',', '.', '<', '>', '/', '?', '`', '~', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

char ln_list[] = 
{
'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

char letter_list[] =
{
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

int randomNum(int start, int end)
{
    //srand(time(0));
    int random_value = 0; int return_value = 0;
    random_value = rand();
    return_value = (rand() % (end - start + 1)) + start;
    return return_value;
}

string randomPW(int len, int mode)  //random failed
{
    string re_password;
    for (int i = 0; i < len; i++)
    {
        int random_num = 0;
        switch (mode)
        {
            case 1:
                random_num = randomNum(0, 93);
                re_password += all_list[random_num];
                break;
            case 2:
                random_num = randomNum(0, 61);
                re_password += ln_list[random_num];
                break;
            case 3:
                random_num = randomNum(0, 51);
                re_password += letter_list[random_num];
                break;
        }
    }
    return re_password;
}

int main() 
{
    int time = 0;
    cin >> time;
    string test;
    for(int i = 0; i < time; i++)
    {
        test = randomPW(15, 1);
        cout << "The mode1 password is " << test << endl;
        test = randomPW(15, 2);
        cout << "The mode2 password is " << test << endl;
        test = randomPW(15, 3);
        cout << "The mode3 password is " << test << endl;
    }
    return 0;
}