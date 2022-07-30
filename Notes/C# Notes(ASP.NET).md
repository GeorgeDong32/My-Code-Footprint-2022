# C# Notes(ASP.NET Core)
> **Copyright (c) GeorgeDong32. All rights reserved.** 
>
> **Power by [Microsoft C# tutorials](https://docs.microsoft.com/zh-cn/dotnet/csharp/tour-of-csharp/tutorials) and [Microsoft Learn-C#](https://docs.microsoft.com/zh-cn/learn/paths/csharp-first-steps)** 
> 
> **[Learning List](https://docs.microsoft.com/zh-cn/users/georgedong-3686/collections/p7et6z8yx041q?section=activity)**

## ASP.NET
ASP.NET 是一个Web框架, 可以用HTML, CSS, JavaScript 构建网站, Web应用和Web API

## ASP.NET Core
ASP.NET Core 是一个跨平台的高性能开源框架，用于生成启用云且连接 Internet 的新式应用. 即使用C#或JavaScript构建Web应用等

使用 ASP.NET Core，您可以：

* 生成 Web 应用和服务、物联网 (IoT) 应用和移动后端。
* 在 Windows、macOS 和 Linux 上使用喜爱的开发工具。
* 部署到云或本地。
* 在 .NET Core 上运行。

## ASP.NET Core 中的 REST
> **REST：用于使用 HTTP 生成 API 的常见模式**

表述性状态转移 (REST) 是一种用于生成 Web 服务的体系结构样式。 REST 请求是通过 HTTP 发出的。 它们使用 Web 浏览器用于检索网页和将数据发送到服务器的相同 HTTP 谓词。 谓词如下：

- `GET`：从 Web 服务检索数据。
- `POST`：在 Web 服务上创建新的数据项。
- `PUT`：更新 Web 服务上的数据项。
- `PATCH`：通过描述有关如何修改项的一组说明，更新 Web 服务上的数据项。 本模块中的示例应用程序不使用此谓词。
- `DELETE`：删除 Web 服务上的数据项。

遵循 REST 的 Web 服务 API 称为 RESTful API。 它们通过以下方法进行定义：

- 一个基 URI。
- HTTP 方法，如 `GET`、`POST`、`PUT`、`PATCH` 或 `DELETE`。
- 数据的媒体类型，例如 JavaScript 对象表示法 (JSON) 或 XML。

## Web API

### 创建项目

1. 创建项目文件夹
2. 在终端中输入 `dotnet new webapi -f net6.0` 
3. 终端中输入 `dotnet run` 启动运行
4. 在终端中输入 `Ctrl + c` 结束运行
5. 在终端中输入 `dotnet dev-certs https --trust` , 以信任生成的 `localhost` , 使API 可以被公开识别

### 使用.NET HTTP REPL进行请求

1. 安装.NET HTTP REPL

   打开新终端: VS Code --> 终端 --> 新建终端

   运行下列代码

   ````.NET CLI
   dotnet tool install -g Microsoft.dotnet-httprepl
   ````

2. 在新终端中运行
	````.NET CLI
   httprepl https://localhost:{PORT}
   ````
   
   命令将把.NET HTTP REPL 连接到 local host 上
   
3. 新终端中运行

   ````.NET CLI
   ls
   ````

   终端将列出连接的终结点的所有可用的API
   
   输出如下
   
   ````.NET CLI
   https://localhost:{PORT}/> ls
   .                 []
   WeatherForecast   [GET] 
   ````

4. 运行以下命令以转到 `WeatherForecast` 终结点：

   ````.NET CLI
   https://localhost:{PORT}/> cd WeatherForecast
   //输出如下
   /WeatherForecast    [GET]
   ````

5. 使用以下命令在 `HttpRepl` 中发出 `GET` 请求：

   ````.NET CLI
   get
   ````

   命令请求类似于转到浏览器中的终结点

   ````.NET CLI
   //输出
   HTTP/1.1 200 OK
   Content-Type: application/json; charset=utf-8
   Date: Fri, 02 Apr 2021 17:31:43 GMT
   Server: Kestrel
   Transfer-Encoding: chunked
   [
     {
       "date": 4/3/2021 10:31:44 AM,
       "temperatureC": 13,
       "temperatureF": 55,
       "summary": "Sweltering"
     },
     {
       "date": 4/4/2021 10:31:44 AM,
       "temperatureC": -13,
       "temperatureF": 9,
       "summary": "Warm"
     },
     // ..
   ]
   ````

6. 使用以下命令结束当前的 `HttpRepl` 会话：

   ````.NET CLI
   exit
   ````

7. 使用 `help` 命令获取命令列表

   ````.NET CLI
   help
   ````

   输出

   <details>
       <summary> 输出如下 </summary>
       <p>Setup Commands:</p>
       <p>Use these commands to configure the tool for your API server</p>
       <p>connect        Configures the directory structure and base address of the api server</p>
       <p>set header     Sets or clears a header for all requests. e.g. `set header content-type application/json`</p>
   <p>HTTP Commands:</p>
   <p>Use these commands to execute requests against your application</p>
   <p>GET            get - Issues a GET request</p>
   <p>POST           post - Issues a POST request</p>
   <p>PUT            put - Issues a PUT request</p>
   <p>DELETE         delete - Issues a DELETE request</p>
   <p>PATCH          patch - Issues a PATCH request</p>
   <p>HEAD           head - Issues a HEAD request</p>
   <p>OPTIONS        options - Issues a OPTIONS request</p>
   <p>Navigation Commands:</p>
   <p>The REPL allows you to navigate your URL space and focus on specific APIs that you are working on</p>
   <p>ls             Show all endpoints for the current path</p>
   <p>cd             Append the given directory to the currently selected path, or move up a path when using `cd ..`</p>
   <p>Shell Commands:</p>
   <p>Use these commands to interact with the REPL shell</p>
   <p>clear          Removes all text from the shell</p>
   <p>echo [on/off]  Turns request echoing on or off, show the request that was made when using request commands</p>
   <p>exit           Exit the shell</p>
   <p>REPL Customization Commands:</p>
   <p>Use these commands to customize the REPL behavior</p>
   <p>pref [get/set] Allows viewing or changing preferences, e.g. 'pref set editor.command.default 'C:\\Program Files\\Microsoft VS Code\\Code.exe'`</p>
   <p>run            Runs the script at the given path. A script is a set of commands that can be typed with one command per line</p>
   <p>ui             Displays the Swagger UI page, if available, in the default browser</p>
   <p>Use `help <COMMAND>` for more detail on an individual command. e.g. `help get`</p>
   <p>For detailed tool info, see https://aka.ms/http-repl-doc</p>
   </details>

### ASP.NET Core Web API 控制器

#### 控制器基类 `ControllerBase`

控制器是一个公共类，具有一个或多个称为“操作”的公共方法。 按照惯例，控制器放在项目根目录的 Controllers 目录中。 操作通过路由被公开为 HTTP 终结点.

#### 控制器类属性

有两个重要属性应用到了 `WeatherForecastController`，如以下代码所示：

```c#
[ApiController]
[Route("[controller]")]
public class WeatherForecastController : ControllerBase
```

`[ApiController]` 启用[固定行为](https://docs.microsoft.com/zh-CN/aspnet/core/web-api/#apicontroller-attribute)，使生成 Web API 更加容易。 一些行为包括[参数源推理](https://docs.microsoft.com/zh-CN/aspnet/core/web-api/#binding-source-parameter-inference)、[将属性路由作为一项要求](https://docs.microsoft.com/zh-CN/aspnet/core/web-api/#attribute-routing-requirement)以及[模型验证错误处理增强功能](https://docs.microsoft.com/zh-CN/aspnet/core/web-api/#automatic-http-400-responses)。

`[Route]` 定义路由模式 `[controller]`。 `[controller]` 令牌将替换为控制器的名称（不区分大小写，无 Controller 后缀）。 此控制器处理对 `https://localhost:{PORT}/weatherforecast` 的请求。

### 添加数据存储

#### 创建模型

1. 新建 `Models` 文件夹, 该文件夹是Web API 使用的模型-视图-控制器体系结构中的一种结构约定

   终端中输入命令

   ````终端
   mkdir Models
   ````

2. 向文件夹中添加 `{Model Name}.cs` ({Model Name}替换为模型所需名称)

   在 `{Model Name}.cs` 中添加模型定义

   ````c#
   namespace 项目名.Models;
   
   public class 模型名
   {
       //模型内容
       public int Id { get; set; }
       public string? Name { get; set; }
       public bool IsGlutenFree { get; set; }
   }
   ````

#### 添加数据服务

1. 新建 `Services` 文件夹

2. 文件夹中创建 `{ServiceName}.cs` 文件

3. 在 `ServiceName.cs` 中添加数据服务定义

   <details>
     <summary>定义样例</summary>
     <code data-enlighter-language="c#" class="EnlighterJSRAW"></code><code data-enlighter-language="c#" class="EnlighterJSRAW">
       <p>using 项目名.Models;</p>
       <p>namespace 项目名.Services;</p>
       <p>public static class PizzaService</p>
       <p>{
       static List<Pizza> Pizzas { get; }
       static int nextId = 3;
       static PizzaService()
      {
           Pizzas = new List<Pizza>
           {
                   new Pizza { Id = 1, Name = "Classic Italian", IsGlutenFree = false },
               new Pizza { Id = 2, Name = "Veggie", IsGlutenFree = true }
           };
       }
       public static List<Pizza> GetAll() => Pizzas;
       public static Pizza? Get(int id) => Pizzas.FirstOrDefault(p => p.Id == id);
       public static void Add(Pizza pizza)
       {
           pizza.Id = nextId++;
           Pizzas.Add(pizza);
       }
       public static void Delete(int id)
       {
           var pizza = Get(id);
           if(pizza is null)
               return;
           Pizzas.Remove(pizza);
       }
       public static void Update(Pizza pizza)
       {
           var index = Pizzas.FindIndex(p => p.Id == pizza.Id);
           if(index == -1)
               return;
           Pizzas[index] = pizza;
       }
       }</p>
     </code><code data-enlighter-language="c#" class="EnlighterJSRAW"></code>
   </details>

   ````c#
   using 项目名.Models;
   
   namespace 项目名.Services;
   
   public static class PizzaService
   {
       static List<Pizza> Pizzas { get; }
       static int nextId = 3;
       static PizzaService()
       {
           Pizzas = new List<Pizza>
           {
               new Pizza { Id = 1, Name = "Classic Italian", IsGlutenFree = false },
               new Pizza { Id = 2, Name = "Veggie", IsGlutenFree = true }
           };
       }
   
       public static List<Pizza> GetAll() => Pizzas;
   
       public static Pizza? Get(int id) => Pizzas.FirstOrDefault(p => p.Id == id);
   
       public static void Add(Pizza pizza)
       {
           pizza.Id = nextId++;
           Pizzas.Add(pizza);
       }
   
       public static void Delete(int id)
       {
           var pizza = Get(id);
           if(pizza is null)
               return;
   
           Pizzas.Remove(pizza);
       }
   
       public static void Update(Pizza pizza)
       {
           var index = Pizzas.FindIndex(p => p.Id == pizza.Id);
           if(index == -1)
               return;
   
           Pizzas[index] = pizza;
       }
   }
   ````

### 添加控制器

#### 创建控制器

1. 在 `Controllers` 目录下创建 `{DataName}Controller.cs` 文件

2. 在文件中添加以下代码以创建控制器

   ````c#
   using ContosoPizza.Models; //使用数据模型
   using ContosoPizza.Services;  //使用数据服务
   using Microsoft.AspNetCore.Mvc;  //使用ASP.NET Core框架
   
   namespace ContosoPizza.Controllers;
   
   [ApiController]
   [Route("[controller]")]
   public class PizzaController : ControllerBase
   {
       public PizzaController(){}
       //以下为待完善部分
       // GET all action
       // GET by Id action
       // POST action
       // PUT action
       // DELETE action
   }
   ````

#### 为控制器提供方法(函数实现)

##### REST谓词 / CRUD操作

| HTTP 操作谓词 | CRUD 操作 | ASP.NET Core 属性 |
| :------------ | :-------- | :---------------- |
| `GET`         | 读取      | `[HttpGet]`       |
| `POST`        | 创建      | `[HttpPost]`      |
| `PUT`         | 更新      | `[HttpPut]`       |
| `DELETE`      | 删除      | `[HttpDelete]`    |

##### GET

````c#
[HttpGet]//头
public ActionResult<List<Pizza>> GetAll() =>
    PizzaService.GetAll();//请求数据服务
````

##### 有输入参数的GET

````c#
[HttpGet("{id}")]
public ActionResult<Pizza> Get(int id)
{
    var pizza = PizzaService.Get(id);

    if(pizza == null)
        return NotFound();

    return pizza;
}
````

##### POST

```csharp
[HttpPost]
public IActionResult Create(Pizza pizza)
{            
    PizzaService.Add(pizza);
    return CreatedAtAction(nameof(Create), new { id = pizza.Id }, pizza);
}
```

###### 操作结果

| ASP.NET Core 操作结果 | HTTP 状态代码 | 说明                                                         |
| :-------------------- | :------------ | :----------------------------------------------------------- |
| `CreatedAtAction`     | 201           | 已将披萨添加到内存中缓存。 该披萨包含在由 `accept` HTTP 请求标头中所定义的媒体类型（默认情况下为 JSON）的响应正文中。 |
| `BadRequest` 为隐式   | 400           | 请求正文的 `pizza` 对象无效。                                |

##### PUT

```csharp
[HttpPut("{id}")]
public IActionResult Update(int id, Pizza pizza)
{
    if (id != pizza.Id)
        return BadRequest();
           
    var existingPizza = PizzaService.Get(id);
    if(existingPizza is null)
        return NotFound();
   
    PizzaService.Update(pizza);           
   
    return NoContent();
}
```

###### 操作结果

| ASP.NET Core 操作结果 | HTTP 状态代码 | 说明                                       |
| :-------------------- | :------------ | :----------------------------------------- |
| `NoContent`           | 204           | 已在内存中缓存中更新了披萨。               |
| `BadRequest`          | 400           | 请求正文的 `Id` 值与路由的 `id` 值不匹配。 |
| `BadRequest` 为隐式   | 400           | 请求正文的 `Pizza` 对象无效。              |

##### DELETE

```csharp
[HttpDelete("{id}")]
public IActionResult Delete(int id)
{
    var pizza = PizzaService.Get(id);
   
    if (pizza is null)
        return NotFound();
       
    PizzaService.Delete(id);
   
    return NoContent();
}
```

###### 操作结果

| ASP.NET Core 操作结果 | HTTP 状态代码 | 说明                                               |
| :-------------------- | :------------ | :------------------------------------------------- |
| `NoContent`           | 204           | 已从内存中缓存中删除了披萨。                       |
| `NotFound`            | 404           | 内存中缓存中不存在与所提供的 `id` 参数匹配的披萨。 |
