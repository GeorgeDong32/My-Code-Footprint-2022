# C# Notes(.NET)

> **Copyright (c) GeorgeDong32. All rights reserved.** 
>
> **Power by [Microsoft C# tutorials](https://docs.microsoft.com/zh-cn/dotnet/csharp/tour-of-csharp/tutorials) and [Microsoft Learn-C#](https://docs.microsoft.com/zh-cn/learn/paths/csharp-first-steps)** 
> 
> **[Learning List](https://docs.microsoft.com/zh-cn/users/georgedong-3686/collections/p7et6z8yx041q?section=activity)**

## 依赖项

.NET 附带许多核心库，可处理从文件管理到 HTTP 再到压缩文件各种任务。 此外还有一个巨大的第三方库生态系统。 可以使用 NuGet（.NET 包管理器）安装这些库并在应用程序中使用它们。.NET 及其生态系统经常使用“依赖项”一词。 包依赖项是第三方库。 它是一段用于完成某些操作的可重用代码，可以添加到你的应用程序。 应用程序依赖第三方库才能正常运行，因此称之为“依赖项”

## 日志和跟踪

用于对程序进行长期分析

日志输出可以使用 `System.Diagnostics.Debug` 或 `System.Diagnostics.Trace` 它们附加了对应的侦听器时写入日志

### 打印API区别

- `System.Console`
  - 始终启用，并始终写入控制台。
  - 适用于客户可能需要在发行版中看到的信息。
  - 由于这是最简单的方法，所以常常用于临时调试。 此调试代码通常不会签入到源代码管理中。
- `System.Diagnostics.Trace`
  - 仅在定义 `TRACE` 时启用。
  - 写入附加侦听器，默认情况下为 `DefaultTraceListener`。
  - 创建将在大多数生成中启用的日志时，请使用此 API。
- `System.Diagnostics.Debug`
  - 仅在定义 `DEBUG` 时才启用（处于调试模式时）。
  - 写入附加调试器。
  - 创建仅在调试生成中启用的日志时，请使用此 API。

### Debug

> **仅Debug模式下有效**

1. #### `Debug.Assert()`

   ````c#
   Debug.Assert(条件, 输出信息);
   //不满足条件时,调试器将终止程序,输出信息
   //满足条件时不会发生任何事
   ````

2. #### `Debug.WriteIf()`

   ````c#
   Debug.WriteIf(条件, 信息);
   //满足条件时调试控制台输出信息
   ````

#### 调试器

##### 前两个值

* 控制程序执行
* 观察程序状态

## 文件系统

.NET 包含用于使用文件系统的内置类型，可在 `System.IO` 命名空间找到这些类型。

现在，你将了解 `System.IO` 中的类型，使用 C# 来读取文件系统，以查找文件和目录。

### 文件目录操作

#### 环境一

````c#
📂 stores
    📄 sales.json
    📄 totals.txt
    📂 201
       📄 sales.json
       📄 salestotals.json
       📄 inventory.txt
    📂 202
````

#### `Directory.EnumerateDirectories()` 列出所有顶级目录

列出指定文件夹下的顶级目录, 不包含子文件夹

````c#
IEnumerable<string> listOfDirectories = Directory.EnumerateDirectories(文件夹路径);

foreach (var dir in listOfDirectories) {
    Console.WriteLine(dir);
}

// Outputs:
// stores/201
// stores/202
````

#### `Directory.EnumerateFiles` 列出目录中的文件

列出指定文件夹下的文件, 不包含子文件夹及其文件

````c#
IEnumerable<string> files = Directory.EnumerateFiles("stores");

foreach (var file in files)
{
    Console.WriteLine(file);
}

// Outputs:
// stores/totals.txt
// stores/sales.json
````

#### 列出目录和所有子目录中的所有内容

`Directory.EnumerateDirectories` 和 `Directory.EnumerateFiles` 函数都具有一个重载，该重载接受用于指定搜索模式文件和目录必须匹配的参数。

它们还具有另一个重载，该重载接受用于指示是否以递归方式遍历指定的文件夹及其所有子文件夹的参数。

````c#
// Find all *.txt files in the stores folder and its subfolders
IEnumerable<string> allFilesInAllFolders = Directory.EnumerateFiles("stores", "*.txt", SearchOption.AllDirectories);

foreach (var file in allFilesInAllFolders)
{
    Console.WriteLine(file);
}

// Outputs:
// stores/totals.txt
// stores/201/inventory.txt
````

#### `Directory.GetCurrentDirectory()`获取当前目录

返回文件夹路径字符串

### 路径

路径是频繁出现的一个主题，.NET 包含一个称为 `Path` 的类，专用于处理路径。

`Path` 类位于 .NET 的 `System.IO` 命名空间中，无需安装。

#### 路径字符

不同的操作系统使用不同的字符来分隔目录级别

.NET中使用 `Path.DirectorySeparatorChar`来帮助完成跨平台的文件路径输出

````c#
Console.WriteLine($"stores{Path.DirectorySeparatorChar}201");

// returns:
// stores\201 on Windows
//
// stores/201 on macOS
````

#### 联结路径

使用 `Path.Combine("A", "B")` 以获取 `A/B`的路径

#### 获取文件或路径信息

`Path` 类包含许多不同的方法，这些方法可执行各种操作。 可以分别使用 `DirectoryInfo` 或 `FileInfo` 类获取关于目录或文件的最完整信息。

````c#
string fileName = $"stores{Path.DirectorySeparatorChar}201{Path.DirectorySeparatorChar}sales{Path.DirectorySeparatorChar}sales.json";

FileInfo info = new FileInfo(fileName);

Console.WriteLine($"Full Name: {info.FullName}{Environment.NewLine}Directory: {info.Directory}{Environment.NewLine}Extension: {info.Extension}{Environment.NewLine}Create Date: {info.CreationTime}"); // And many more
````

### 创建目录和文件

#### `Directory.CreateDirectory()` 创建目录

````c#
Directory.CreateDirectory(Path.Combine(Directory.GetCurrentDirectory(),"stores","201","newDir"));
````

#### `File.WriteAllText()` 创建及写入文件
````c#
File.WriteAllText(路径, 待写入字符串);//覆盖写入,会抹掉之前文件的所有数据
````

### 读取和写入文件

#### `File.ReadAllText()` 读取文件
````c#
File.ReadAllText(文件路径);
//返回字符串
````

#### `File.AppendAllText()` 追加数据到文件
````c#
File.AppendAllText(路径, 待写入字符串);
* File.AppendAllText($"salesTotalDir{Path.DirectorySeparatorChar}totals.txt", $"{data.Total}{Environment.NewLine}");
```` 
> Environment.NewLine 将值放置于新的一行
