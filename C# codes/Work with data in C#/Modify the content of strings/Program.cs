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
/*Unit 3
string data = "12345John Smith          5000  3  ";
string updatedData = data.Remove(5, 20);
Console.WriteLine(updatedData);*/
/*Challenge*/
const string input = "<div><h2>Widgets &trade;</h2><span>5000</span></div>";

string quantity = "";
string output = "";

const string ospan = "<span>";
const string cspan = "</span>";
const string odiv = "<div>";
const string cdiv = "</div>";
int ospanp = input.IndexOf(ospan);
int cspanp = input.IndexOf(cspan);
int odivp = input.IndexOf(odiv);
int cdivp = input.IndexOf(cdiv);
ospanp += ospan.Length;
int l1 = cspanp - ospanp;
odivp += odiv.Length;
int l2 = cdivp - odivp;
quantity = input.Substring(ospanp, l1);
output = input.Substring(odivp, l2);

Console.WriteLine(quantity);
Console.WriteLine(output);