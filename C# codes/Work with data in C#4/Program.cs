/*Unit 2*/
/*string message = "Find what is (inside the parentheses)";

int openingPosition = message.IndexOf('(');
int closingPosition = message.IndexOf(')');

openingPosition += 1;

int length = closingPosition - openingPosition;
Console.WriteLine(message.Substring(openingPosition, length));

string message = "(What if) I have [different symbols] but every {open symbol} needs a [matching closing symbol]?";

// The IndexOfAny() helper method requires a char array of characters. 
// We want to look for:
char[] openSymbols = { '[', '{', '(' };

// We'll use a slightly different technique for iterating through the 
// characters in the string. This time, we'll use the closing position
// of the previous iteration as the starting index for the next open
// symbol. So, we need to initialize the closingPosition variable
// to zero:
int closingPosition = 0;

while (true)
{
    int openingPosition = message.IndexOfAny(openSymbols, closingPosition);
    if (openingPosition == -1) break;
    string currentSymbol = message.Substring(openingPosition, 1);

    // Now we must find the matching closing symbol
    char matchingSymbol = ' ';
    switch (currentSymbol)
    {
        case "[":
            matchingSymbol = ']';
            break;
        case "{":
            matchingSymbol = '}';
            break;
        case "(":
            matchingSymbol = ')';
            break;
    }

    // To find the closingPosition, we use an overload of the IndexOf method to specify 
    // that our search for the matchingSymbol should start at the openingPosition in the string. 
    openingPosition += 1;
    closingPosition = message.IndexOf(matchingSymbol, openingPosition);

    // Finally, use the techniques we've already learned to display the sub-string:
    int length = closingPosition - openingPosition;
    Console.WriteLine(message.Substring(openingPosition, length));
}*/
/*Unit 3*/
string data = "12345John Smith          5000  3  ";
string updatedData = data.Remove(5, 20);
Console.WriteLine(updatedData);