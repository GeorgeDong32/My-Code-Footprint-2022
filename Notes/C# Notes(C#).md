# C# Notes(C#)

> **Copyright (c) GeorgeDong32. All rights reserved.** 
>
> **Power by [Microsoft C# tutorials](https://docs.microsoft.com/zh-cn/dotnet/csharp/tour-of-csharp/tutorials) and [Microsoft Learn-C#](https://docs.microsoft.com/zh-cn/learn/paths/csharp-first-steps)** 

## 控制台应用（console）

### 控制台输入输出

调用`Console`类进行输入输出

````c#
Console.Write();  //输出到控制台,结尾不换行,要求至少有一个参数
Console.WriteLine();  //输出到控制台,结尾换行,无参数则输出一个空行
Console.Read();  //读取输入流的下一个字符,无字符返回-1
Console.ReadKey();  //读取输入的按键,返回用户按键的Unicode
Console.ReadKey(Boolean intercept);  //读取输入的按键,intercept控制是否在控制台中显示按下的键,返回ConsoleKeyInfo对象
Console.ReadLine();  //读取输入流的下一行,无数入则为NULL
````

## C#中的数

### 整型数`int`

与C/C++中int相同

数值范围：-2147483648~214783647

### 双精度类型`double`

与C/C++中double相同

### 十进制类型`decimal`

`decimal` 类型的范围较小，但精度高于 `double`

````c#
double a = 1.0;
double b = 3.0;
Console.WriteLine(a / b);

decimal c = 1.0M;
decimal d = 3.0M;
Console.WriteLine(c / d);

//输出结果
0.333333333333333
0.3333333333333333333333333333
````

==M用于指示常数以十进制类型使用,否则默认为double类型==

## C#中的字符串

* 允许使用`+`来叠加字符串

* 允许使用转义符`\` , `\n` , `\t (Tab)` 等进行操作

* 新增==字符串内插==属性

  ````c#
  Console.WriteLine($"Hello {name}");  //通过$符号标识字符串内插
  ````

* 裁剪字符串空格`Trim`方法

  ````c#
  string greeting = "      Hello World!       ";
  Console.WriteLine($"[{greeting}]");  //不做裁剪
  
  string trimmedGreeting = greeting.TrimStart();  //裁剪前面空格
  Console.WriteLine($"[{trimmedGreeting}]");
  
  trimmedGreeting = greeting.TrimEnd();  //裁剪末尾空格
  Console.WriteLine($"[{trimmedGreeting}]");
  
  trimmedGreeting = greeting.Trim();  //裁剪所有空格
  Console.WriteLine($"[{trimmedGreeting}]");
  ````

* 字符串删除 `Remove()` 方法

  ````C#
  string data = "12345John Smith          5000  3  ";
  string updatedData = data.Remove(5, 20);
  Console.WriteLine(updatedData);
  //输出
  //123455000  3  
  ````

  ````c#
  string.Remove(int 起始位置, int 结束位置);
  ````

  

* 替换字符串`Replace`方法

  ````c#
  string sayHello = "Hello World!";
  sayHello = sayHello.Replace("Hello", "Greetings");  //将sayHello中的制定字符替换为第二个串
  ````

* 字符串转换大小写

  ````c#
  Console.WriteLine(sayHello.ToUpper());  //转换为大写
  Console.WriteLine(sayHello.ToLower());  //转换为小写
  ````

* 字符串搜索`Contains`方法

  ````c#
  string songLyrics = "You say goodbye, and I say hello";
  Console.WriteLine(songLyrics.Contains("goodbye"));  //查找是否含有子串,返回bool值
  Console.WriteLine(songLyrics.StartsWith(start));  //查找字符串是否以start串开头
  Console.WriteLine(songLyrics.EndsWith(end));  //查找字符串是否以end串开头
  ````

* 逐字字符串文本

  保留所有空格和字符,无需转义符,也保留原有格式(多行)

  ````c#
  Console.WriteLine(@"   c:\source\repos   
        (this is where your code goes)");
  //输出
  c:\source\repos   
        (this is where your code goes)
  ````


### 字符串格式设置

#### 复合格式设置 `string.Format()`

````c#
string first = "Hello";
string second = "World";
string result = string.Format("{0} {1}!", first, second);
Console.WriteLine(result);
//输出
//Hello World!
````

* 函数参数

  模板字符串, 传入参数

* 参数对应关系

  `{0} 自动对应传入参数的第一个, {1} 自动对应第二个` 

#### 设置货币格式

使用 `{valuename}:C` 来设置数字输出时以货币格式输出, 输出为系统语言对应的货币单位

#### 设置小数点后位数

使用 `{valuename}:N{位数}` 来设置数字输出时的小数位数

#### 设置百分号格式

使用 `{valuename}:P{位数}` 来设置数字输出为百分位时的位数

#### 长度控制(添加空格)

````c#
string input = "Pad this";
Console.WriteLine(input.PadLeft(12));
Console.WriteLine(input.PadRight(12));
Console.WriteLine(input.PadLeft(12, '-'));
Console.WriteLine(input.PadRight(12, '-'));
````

````输出
//输出
    Pad this
Pad this    
----Pad this
Pad this----
````

### 字符串内数据操作

#### 识别字符位置 `.IndexOf()`

````c#
string message = "Find what is (inside the parentheses)";

int openingPosition = message.IndexOf('(');
//返回目标字符的下标
````

#### 获取子字符串 `.Substring()` 

````c#
string message = "Find what is (inside the parentheses)";
string newmessage = message.Substring(int 操作位置, int 子字符串长度);
````

##### 避免magic值

如获取html格式时的分隔符 `<div>` 可以使用 `Indexof("<div>")` 同时对索引进行偏移

但若分隔符变化或者是内部字符顺序变化(误写为 `<dvi>` )将导致错误, 无法捕获

可以将分隔符变为常量如下操作

````c#
string message = "What is the value <span>between the tags</span>?";

const string openSpan = "<span>";
const string closeSpan = "</span>";

int openingPosition = message.IndexOf(openSpan);
int closingPosition = message.IndexOf(closeSpan);

openingPosition += openSpan.Length;
int length = closingPosition - openingPosition;
Console.WriteLine(message.Substring(openingPosition, length));
//替换分隔符不会导致意料外的错误
````

##### 实现多次匹配

````c#
string message = "(What if) there are (more than) one (set of parentheses)?";
while (true)
{
    int openingPosition = message.IndexOf('(');
    if (openingPosition == -1) break;

    openingPosition += 1;
    int closingPosition = message.IndexOf(')');
    int length = closingPosition - openingPosition;
    Console.WriteLine(message.Substring(openingPosition, length));

    // Note how we use the overload of Substring to return only the remaining 
    // unprocessed message:
    message = message.Substring(closingPosition + 1);//更新字符串,去掉第一对括号及其内容
}
````

````输出
//输出
What if
more than
set of parentheses
````

##### 实现多分隔符匹配

````c#
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
}
````

使用 `IndexOfAny()` 进行多值匹配

## 类型转换

### 隐式转换&强制类型转换

与 C/C++ 一致

### 显式转换

#### 数字 --> 字符串

`ToString()`函数, 返回字符串类型

#### 字符串 --> 数字

`Parse()` 函数, 返回数字

#### 使用`Convert ` 类进行数据转换

* ````c#
  Convert.ToInt32(value); //返回int类型值,小数按四舍五入取整
  ````

* ......

#### `TryParse()` 方法

> 用于处理字符串转化为数字时字符串不完全有数字构成的情况

````c#
数字类型.TryParse(value, out result); //result 为out参数, 实现函数输出转化结果
//函数返回bool值表示是否成功转换
````



## C#的分支和循环

即`if` `else` `for` `while`等循环和判断语句，与C/C++中相同

### foreach循环

用于集合或列表的遍历

* 语法

  ````c#
  foreach(数据类型 变量名 in 数(据)组名)
  {
      //执行语句块
  }
  ````


## 代码规范

### 变量名称规则

- 变量名可包含字母数字字符和下划线字符。 不允许使用特殊字符（如英镑 `#`、短划线 `-` 或美元符号 `$`）。
- 变量名称必须以字母或下划线开头，不能以数字开头。 开发者将下划线用于特殊目的，因此现在请勿使用。
- 变量名不能是 C# 关键字。 例如，不允许使用以下变量名称声明：`float float;` 或 `string string;`。
- 变量名称区分大小写，这意味着 `string MyValue;` 和 `string myValue;` 是两个不同的变量。

### 注释

- 使用代码注释为自己添加有意义的备注，注明代码可解决的问题。
- 不应使用解释 C# 或 .NET 类库如何工作的代码注释
- 暂时尝试替代解决方法时，请使用代码注释，直至你已准备提交新的代码解决方案，此时可以删除旧代码

## 数据结构

### 数组

属于 `Array` 类, 有排序, 清空, 扩容等方法

#### 排序

具有正向排序方法 `Array.Sort(目标数组)` 和反转顺序方法 `Array.Reverse(目标数组)`

#### 清除和调整大小

清除方法 `Array.Clear(目标数组, 起始位置, 结束位置)` . 清除后元素值为 `null`

调整大小方法 `Array.Resize(ref 目标数组, 调整后大小)`，可以调大调小，调大是添加 `null` 元素到末尾，调小是从后往前删除元素直到符合要求

#### 拆分和合并

* 拆分 `Split()` 方法

  ````c#
  string result = "3,2,1,c,b,a";
  string[] items = result.Split(',');
  //输出
  //3 2 1 c b a
  ````

  

* 合并串联 `Join()` 方法

  ````c#
  string result = String.Join(",", valueArray);
  //输出
  //3,2,1,c,b,a
  ````


### `List<T>`列表

* `Add`方法
* `Remove`方法
* index`[]`
* `Count` 列表长
* `Sort` 排序方法(按数字大小或字典序排序)

## 委托

可以用于替代函数名进行函数调用

* 实际应用:

  开发游戏有多角色可选, 每个角色有三个技能但互不相同, 使用委托可以在选择时将技能按钮映射给不同技能而不用更改代码块

  或是预留接口方便模块化开发

````c#
delegate /*返回参数类型*/ MyDelegate (参数列表); //委托声明
MyDelegate = MyAdd; //委托赋值,即选定委托所指向的函数(可变更)
//要求: 返回类型相同,参数列表相同
````

## 命名空间

### 命名空间

命名空间影响类，命名空间可消除具有相同名称的两个类的歧义

命名空间不影响方法，命名空间可消除具有相同名称的两个方法的歧义

