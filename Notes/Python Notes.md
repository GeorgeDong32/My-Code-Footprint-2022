# Python Notes

## Python简介

Python 是一种解释型语言，该语言无需进行编译，因此缩短了编辑-测试-调试周期。 为了运行 Python 应用，你需要运行时环境/解释器来执行代码。

大多数运行时环境都支持两种方式执行 Python 代码：

- **交互模式**：在这种模式下，键入的每个命令都会被立即翻译并执行，并且每次按 Enter 时都会看到结果。 交互模式是默认模式，除非将文件名传递到解释器。
- **脚本模式**：在脚本模式下，可以将一组 Python 语句放入扩展名为 .py 的文本文件。 然后运行 `python` 解释器并将其指向该文件。 程序逐行执行并显示输出。 没有编译步骤，如下图所示：
- ![Diagram showing the execution of a .py file through the Python interpreter.](D:\OneDrive - dong32\Note\Typora\Pics\2-python-steps.png)

## 环境配置和项目管理

### Jupyter Notebook

> Jupyter Notebook是基于网页的用于交互计算的应用程序。其可被应用于全过程计算：开发、文档编写、运行代码和展示结果。——[Jupyter Notebook官方介绍](https://jupyter-notebook.readthedocs.io/en/stable/notebook.html)

简而言之，Jupyter Notebook是以网页的形式打开，可以在网页页面中**直接编写代码**和**运行代码**，代码的**运行结果**也会直接在代码块下显示的程序。如在编程过程中需要编写说明文档，可在同一个页面中直接编写，便于作及时的说明和解释。

#### VS Code 配置 Jupyter

##### 环境

推荐安装较低版本的Python，测试`3.9.10`版本可用

下载链接 `(https://www.python.org/downloads/release/python-3910/)`

##### 安装 ipykernel

国内网络访问pip容易出现丢包断连,推荐使用清华大学镜像源安装

安装命令

````
pip install ipykernel --user -i https://pypi.tuna.tsinghua.edu.cn/simple
````

> 若安装有多个版本Python记得切换到对应版本之后再用命令

### pip （**Python 包管理工具**）

#### pip install(包安装)

```python
pip install {packagename}  #安装包
```
后缀
```python
--user # 仅为当前用户安装
-i {source adress} # 从非官方地址安装
# 加速镜像源 清华镜像
https://pypi.tuna.tsinghua.edu.cn/simple
=={version} #安装指定版本
>={version} #安装不低于指定版本
```

#### 其他

```python
pip uninstall {packagename} # 卸载指定包
pip --help # 帮助列表
pip list # 查看包列表
pip freeze # 查看依赖项列表
pip freeze > requirement.txt # 将依赖项写入列表
pip install -r requirements.txt # 从依赖列表中配置环境
```

### 虚拟环境

虚拟环境中的改变不会影响系统中的任何其他部分,相对安全

#### 创建

```powershell
python -m venv env
```

#### 激活

```powershell
{venvname}\Scripts\Activate.ps1
```

> 若出现==在此系统上禁止运行脚本== 的报错, 管理员启动Powershell运行**set-executionpolicy remotesigned**命令

#### 退激活

```powershell
deactivate
```

### Python 项目管理

#### 依赖列表 `requirements.txt`

## 基础知识

### 判断结构

#### `if`

```python
if {条件}:
    # 执行语句块,无需大括号,但要缩进
    print(...)
print(...) # 无缩进默认是正常语句,始终执行
```

#### `else`

```python
if {条件}:
    #if 语句块
else:
    #else 语句块
```

#### `elif`

`else if` 的缩写, 用法与 C/C++ 中的 `else if` 相同

```python
if {条件}:
    #if 语句块
elif {条件}:
    #elif 语句块
```

#### `and` 和 `or` 运算符

相当于 C/C++ 中的 `&&` 和 `||` 运算符

```python
#and & or
## and
if sub-expression1 and sub-expression2:
    #执行语句块
## or
if sub-expression1 or sub-expression2:
    #执行语句块
```

### 循环结构

#### `while`

```python
while condition:
    # code here //需要缩进以提示代码块
```

#### `for`

```python
for 迭代器 in list:
    # 语句块 //需要缩进以提示代码块
```



### 字符串

允许使用单引号`'` , 双引号 `"` , 三引号来`'''` 引起python字符串但不应引起歧义

#### 性质

1. 不可变性

   > 字符串赋值后不可更改

#### 方法

* `.title()` 将字符串转化为标题格式
* `.split()` 将字符串按空格拆分

* `.find()` 查找单词所在位置, 不存在则返回 -1

* `.count()` 计数单词出现次数

* `.lower()` , `.upper()` 转换大小写

* 检查信息

  * `.isnumeric()` 检查字符串是否为数字

  * `.isdecimal()` 检查是否为小数

  * `.startwith()` , `.endwith()` 检查是否开头结尾是对应字符

  * `in` 

    ```python
    if tar in str # 若 tar 在 str 中,返回true
    ```

* 文本转化

  * `.replace()` 两个参数, 前参为待替换字符, 后参为替换后字符

* 合并字符串

  * `.join()`

    ```python
    moon_facts = ["The Moon is drifting away from the Earth.", "On average, the Moon is moving about 4cm every year"]
    '\n'.join(moon_facts) # 表示用'\n'连接数组的字符串
    ```

#### 字符串格式

##### 百分号格式

```python
info = 'George'
print("Hi! %s" %  info) #输出为 Hi! George
```

```python
print("""Both sides of the %s get the same amount of sunlight,
but only one side is seen from %s because
the %s rotates around its own axis when it orbits %s.""" % ("Moon", "Earth", "Moon", "Earth"))
# 输出
Both sides of the Moon get the same amount of sunlight,
but only one side is seen from Earth because
the Moon rotates around its own axis when it orbits Earth.
```

##### `.format()`方法

```python
print("""You are lighter on the {0}, because on the {0} 
	you would weigh about {1} of your weight on Earth""".format("Moon", mass_percentage))
# 输出
You are lighter on the Moon, because on the Moon you would weigh about 1/6 of your weight on Earth
```

#### `f-string`

> 要求Python >= 3.6

##### 字符串内嵌

```python
print(f"On the Moon, you would weigh about {mass_percentage} of your weight on Earth")
# 输出
On the Moon, you would weigh about 1/6 of your weight on Earth
```

##### 表示小数

```python
>>> round(100/6, 1)
# 输出
16.7
```

### 数学运算

#### 加法

与C/C++一致

#### 减法

与C/C++一致

#### 乘法

与C/C++一致

#### 除法

与C/C++一致

`//` 向下取整的除法

### 数字

#### 类型转换

可以从字符串转换成数字

#### 绝对值

`abs(value)` 函数返回绝对值

#### 舍入

`round()` 函数, 执行5舍6入

#### 数学库 `math`

```python
from math import ceil, floor

round_up = ceil(12.5)
print(round_up)

round_down = floor(12.5)
print(round_down)
```

### 类

#### 创建类

```python
class Car:
```

#### 创建类对象

```python
car = Car()
```

#### 构造函数 `__init__()`

```python
class Elevator:
    def __init__(self, starting_floor):
        self.make = "The elevator company"
        self.floor = starting_floor
```

self 指向当前创造对象的实例, 非self的参数都会视作是临时变量, 函数结束后销毁

#### 数据封装&访问级别

python使用特征前缀来完成数据隐藏，通过添加下划线 `_` 来指示访问级别

##### 受保护的 `_{valuename}`

与C/C++中的 `protected` 类似, 依然允许修改数据

##### 专用 `__valuename`

与C/C++中的 `private` 类似, 直接修改数据会产生 `AttributeError` 

但可以使用以下方式修改数据

```python
class Square:
    def __init__(self):
          self.__height = 2
          self.__width = 2
	def set_side(self, new_side):
          self.__height = new_side
          self.__width = new_side

square = Square()
square.__height = 3 # 产生 AttributeError 错误
square._Square__height = 3 # 允许的修改方式
```

#### 取/赋值函数(Getter/Setter)

用于读取和赋值的方法, 可以利用Setter作为缓冲保护, 防止设置错误值

### 列表`list`

储存值的集合, 可以使用 `[]` 访问元素, 使用负值反向索引

#### 获取长度

```python
int lenoflist = len(targetlist) # len函数
```

#### 添加值

```python
targetlist.append(value) # append函数
```

#### 删除值

```python
targetlist.pop() # pop函数,删除最后一个list元素
```

#### 获取最大/小值

```python
min(targetlist)
max(targetlist)
```

#### 获取指定范围内的所有项

```python
new_list = list[0:2] # 获取0,1两项
```

#### 连接列表

```python
new_list = list1 + list2
```

#### 排序

```python
list.sort() # 正向排序
list.sort(reverse=True) # 反向排序
```

### 字典

相当于一个容器，可以储存更多的值, 其存储的的信息可以使用迭代器访问

> 结构是一组键, 键包含唯一的名称和为一对应的值

```python
planet = {
    'name': 'Earth', # 键
    'moons': 1 # 键
}
```

#### 获取值

##### `get()` 方法

```python
print(planet.get('name'))
# Displays Earth
```

若无结果, 返回 `None` 

##### `[]` 检索

```python
# planet['name'] is identical to using planet.get('name')
print(planet['name'])
# Displays Earth
```

若无结果返回 `KeyError` 

#### 修改值

##### `update()` 方法

```python
# Using update 可以执行多个替换
planet.update({
    'name': 'Jupiter',
    'moons': 79
})
```

##### `[]` 索引更新

```python
# Using square brackets 只能单个替换
planet['name'] = 'Jupiter'
planet['moons'] = 79
```

#### 增加和删除值

##### 增加

```python
planet['orbital period'] = 4333 #直接使用索引更新
```

##### 删除

```python
planet.pop('orbital period') # 输入参数为键名
```

#### 嵌套字典

可以在字典中嵌套加入新的字典

```python
# Add address
planet['diameter (km)'] = {
    'polar': 133709,
    'equatorial': 142984
}

# planet dictionary now contains: {
#   name: 'Jupiter'
#   moons: 79
#   diameter (km): {
#      polar: 133709
#      equatorial: 142984
#   }
# }
```

#### 所有键/值的获取

```python
rainfall = {
    'october': 3.5,
    'november': 4.2,
    'december': 2.1
}
# 键的获取
for key in rainfall.keys():
    print(f'{key}: {rainfall[key]}cm')
# 值的获取
for value in rainfall.value():
    totalrf += value
```

### 函数

* 创建函数

  ```python
  def functionname(参数列表)
  	# 函数语句
  ```

* 调用函数

  ```python
  functionname(参数列表)
  ```

#### 参数

* 必需参数(定义参数)

  ```python
  def function(必须参数1, 必须参数2)
  ```

* 可选参数(关键字参数)

  ```python
  def function(value=0)
  ```

  > 需要赋予默认值

* 可变参数 `*args`

  ```python
  def function(*args): # 可以传入任意数量的参数
      print(args)
  ```

* 可变关键字参数 `**kwargs`

  ```python
  def variable_length(**kwargs):
      print(kwargs)
  ```

> 混合使用定义参数和关键字参数时, 要先定义定义参数, 后关键字参数

### Python异常

#### 处理异常

使用 `try()` 和 `except()` 处理异常

```python
try:
    # 语句块
except {错误名}:
    #语句块
```



## Python 构建应用

### Python REPL(交互式解释器)

```控制台
// 控制台
python
//输出
Python 3.9.10 (tags/v3.9.10:f2f3f53, Jan 17 2022, 15:14:21) [MSC v.1929 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license" for more information.
```

```python REPL
# 多行代码以 ';\' 分割和指示, 最后一行无需指示
first_number = int(input('Type the first number: ')) ;\
second_number = int(input('Type the second number: ')) ;\
print("The sum is: ", first_number + second_number)
```

### 使用Python进行测试

主要使用 `unittest` 进行编写和测试

#### 断言和断言方法

- `self.assertTrue(value)`：确保 `value` 为 true。
- `self.assertFalse(value)`：确保 `value` 为 false。
- `self.assertNotEqual(a, b)`：检查 `a` 和 `b` 是否不相等。

* `self.assertEqual(a, b)` ：检查 `a` 和 `b` 是否相等。

* ......

断言方法属于类 `unittest.TestCase` 
