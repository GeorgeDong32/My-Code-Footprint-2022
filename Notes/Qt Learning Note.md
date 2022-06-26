# Qt Learning Note:
## 窗口:
.show();手动显示窗口
.setWindowTitle("Title name"); 设置窗口标题
.resize(width, heigth);设置窗口大小
.setFixedSize(width, heigth);设置用户不可更改的窗口大小
## 按钮：
### 1.先引用 `<QPushButton>`
### 2.创建按钮对象
QPushButton* "名字" = new QPushButton ("按钮显示的文字", 父类(一般为this));
或QPushButton* "名字" = new QPushButton; 再name.setparent(&parent);
为了前后按钮不重叠,可用""name->move(x,y);移动按钮
按钮大小同样可以用.resize(宽,高)设定.
## 对象树（概念）
### QT中对象的组织形式
对象树：QT创建对象时会要求传入另一个对象指针，即父对象（不是父类），构建为一棵对象树，同时父对象中会有一个children列表。析构父对象时，其子对象也会析构。
## 坐标系
QT的坐标原点在左上角
## 信号和槽
优点：松散耦合
信号发出方与接收方没有关联，通过关系连接
代码实操
函数：connect（信号发出方，发送信号类型signals，信号的接收者，处理的槽函数Slots）
实例：
connect（mybutton，&QPushButton::clicked， this，&myWidget::close ）;
connect
### 信号signals：
clicked点击
pressed按下
released松开
### 槽slots：
showMaxmized 最大化
showMinimized 最小化
showNormal 还原
close 结束进程
lower 降低图层优先级
### 自定义的信号和槽
#### 信号：
写在类中的signals: 后，返回类型为void，只需声明无需实现。
触发信号：emit 对象.函数
#### 槽：
写在public slots: 后或直接写在 public: 中，视版本而定。返回类型为void，需声明和实现。
#### 信号和槽的重载
重载后多个函数公用一个地址，要新建函数指针指向对应重载
* 例
Teacher类中有重载：hungry(); hungry(QString foodrequest);
指向后者的指针应被定义为：
void(Teacher:: *teacher_hungry_s)(QString) = &Teacher::hungry;

即：
返回类型（作用域 + *指针名）（函数参数类型） =  &重载的函数
调用connect时直接传入指针即可
* *补充
QString 在QDebug 输出时会附带引号，去除方法为将QString转为char*，具体操作为QString.toUtf8.data();

#### 信号可以连接信号，用Connect连接两者即可。