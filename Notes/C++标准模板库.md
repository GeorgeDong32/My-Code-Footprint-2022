# C++标准模板库

## STL

Standard Template Library

C++标准库的一部分，命名是历史遗存

在C++20中STL指

* 容器库（Containers library, Chap. 26）

* 迭代器库（Iterators library, Chap. 27）

* 算法库（Algorithms library, Chap. 28）

## 迭代器 Iterator

迭代器（*Iterator*）是用于遍历容器元素的指针对象的包装，用于访问修改增加删除容器元素

单向迭代器实现了以下运算符重载

* operator ++ ，==, != , * 等，例如：++ 表示取容器中的下一个元素

容器会提供一个或多个迭代器实现

* 例：

* vector 提供正向和反向的迭代器。

  通过成员函数 begin()，end() 返回正向迭代器对象实例。

  通过成员函数 rbegin()，rend() 返回反向迭代器对象实例 

  <img src="D:\OneDrive - dong32\Note\Typora\Pics\image-20220609225409596.png" alt="image-20220609225409596" style="zoom:50%;" />

## 容器

容器是存储其他对象的对象

### 分类

* 序列式
* 关联式
* 无序关联式
* 容器适配器

### 序列式容器

#### 类型

<img src="D:\OneDrive - dong32\Note\Typora\Pics\image-20220609231747524.png" alt="image-20220609231747524" style="zoom:60%;" />

#### 构造

<img src="D:\OneDrive - dong32\Note\Typora\Pics\image-20220609232018136.png" alt="image-20220609232018136" style="zoom:60%;" />

#### 访问

<img src="D:\OneDrive - dong32\Note\Typora\Pics\image-20220609232052901.png" alt="image-20220609232052901" style="zoom:60%;" />

#### 迭代器

<img src="D:\OneDrive - dong32\Note\Typora\Pics\image-20220609232209775.png" alt="image-20220609232209775" style="zoom:60%;" />

#### 插入

![image-20220610091611177](D:\OneDrive - dong32\Note\Typora\Pics\image-20220610091611177.png)

#### 删除

![image-20220610091703403](D:\OneDrive - dong32\Note\Typora\Pics\image-20220610091703403.png)

#### 比较

![image-20220610091749418](D:\OneDrive - dong32\Note\Typora\Pics\image-20220610091749418.png)

#### 容量

![image-20220610091843728](D:\OneDrive - dong32\Note\Typora\Pics\image-20220610091843728.png)

#### 赋值和交换

![image-20220610092046238](D:\OneDrive - dong32\Note\Typora\Pics\image-20220610092046238.png)

### 关联式容器

#### 类型

![image-20220609233152123](D:\OneDrive - dong32\Note\Typora\Pics\image-20220609233152123.png)

#### 使用

##### Map

 ###### 构造

![image-20220610092624174](D:\OneDrive - dong32\Note\Typora\Pics\image-20220610092624174.png)

###### 插入元素

![photo](D:\OneDrive - dong32\Note\Typora\Pics\image-20220610094412711.png)

###### 查找元素

![image-20220610094446096](D:\OneDrive - dong32\Note\Typora\Pics\image-20220610094446096.png)

###### 删除元素

![image-20220610094514070](D:\OneDrive - dong32\Note\Typora\Pics\image-20220610094514070.png)

##### multimap

* 不支持下标操作。

* insert操作每调用一次都会增加新的元素（multimap容器中，键相同的元素相邻存放）。

* 以键值为参数的erase操作删除该键所关联的所有元素，并返回被删除元素的数目。

* count操作返回指定键的出现次数。

* find操作返回的迭代器指向与被查找键相关联的第一个元素。

* 结合使用count和find操作依次访问multimap容器中与特定键关联的所有元素

##### set

与map相似

<details>
    <summary><b> 不支持的操作 </b></summary>
1. 没有定义mapped_type类型.<br> 
2. set容器定义的value_type类型不是pair类型，而是与key_type相同，指的都set中元素的类型. 
</details>

### 容器适配器

