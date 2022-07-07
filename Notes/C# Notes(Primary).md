# C# Notes(primary)

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

## 字符串

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

### `List<T>`列表

* `Add`方法
* `Remove`方法
* index`[]`
* `Count` 列表长
* `Sort` 排序方法(按数字大小或字典序排序)
