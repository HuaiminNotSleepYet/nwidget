# 文档

-[引入](#引入)
- [布局语法](#布局语法)
  - [ForEach](#foreach)
- [属性绑定](#属性绑定)
  - [xxxId](#xxxid)
  - [Property](#property)
  - [属性绑定](#属性绑定)
  - [is\_observable\<T\>](#is_observablet)
  - [is\_same\_property\<A, B\>](#is_same_propertya-b)

## 引入

单独引入每个控件：

```cpp
#include <nwidget/pushbutton.h>
#include <nwidget/slider.h>
#include <nwidget/...>
```

或在 QT 头文件之后使用 `nwidget.h` ：

```cpp
#include <QPushButton>
#include <QSlider>
#include <Q...>
#include <nwidget/nwidget.h>
```

## 布局语法

使用声明式语法排列控件，通过链式调用设置控件属性：

```cpp
auto* button1 = new QPushButton;
auto* button2 = new QPushButton;
button1.setText("Button");

QLayout* layout = nwidget::VBoxLayout{
    button1,                                // 使用已有实例
    new QPushButton,
    nwidget::PushButton(),
    nwidget::PushButton(button2).text("Button"), // 在已有实例上设置
};
```

### ForEach

```cpp
std::vector<int> nums = {1, 2, 3, 4, 5};

QLayout* layout = nwidget::VBoxLayout{
    nwidget::Label("Label"),
    nwidget::ForEach(nums, [](int index, int value) -> nwidget::BoxLayoutItem {
        return new QPushButton(QString::number(value));
    })
};
```

![](../img/foreach_example.png)

## 属性绑定

nwidget 引入了 qml 的 [属性绑定](https://doc.qt.io/qt-6/qtqml-syntax-propertybinding.html) 机制，并使用类似的语法

你可以在在声明式语法中创建绑定：

```cpp
LabelId label = new QLabel;
LineEditId edit = new QLineEdit;

QLayout* layout = VBoxLayout{
    Label(label).text(edit.text()),
    LineEdit(edit)
};
```

或直接在代码中创建：

```cpp
nwidget::SliderId slider1 = new QSlider;
nwidget::SliderId slider2 = new QSlider;
nwidget::SliderId slider3 = new QSlider;

slider3.value() = slider1.value() + slider2.value();
```

### xxxId

为了实现类似 qml 的 [id](https://doc.qt.io/qt-6/qtqml-syntax-objectattributes.html#the-id-attribute) 机制，nwidget 添加了 `xxxId` 类型，它用于唯一标识一个对象和获取 [Property](#property) 实例

要为自定义类创建对应的 Id 类型，请参考 [length_calculator](../../examples/length_calculator/mainwindow.cpp) 中的 `MainWindowId`

### Property

`Property` 是一个模板类，代表 QObject 实例的一个属性。它使用模板参数记录属性的名称、Getter、Setter、变更信号

有多种方法可以操作 `Property`：

```cpp
// set 和 get 方法
auto textProp = label.text();
textProp.set("value1");
QString text = textProp.get();

// 赋值运算符
auto valueProp = slider.value();
valueProp = 20;
valueProp += 10;

// 自增/自减
++valueProp;
```

### 属性绑定

与 qml 类似，当你将一个 `Property` 的表达式赋给一个 `Property` 时便可创建绑定。当为 `Property` 设置新值或新绑定时，旧绑定被删除

最简单的绑定便是将一个属性赋给另一属性：

```cpp
label.text() = lineEdit.text()
```

绑定表达式支持大部分 c++ 运算符：

```cpp
slider1.value() = slider2.value() / 2;

checkBox.checked() = slider.value() > 50;

checkBox.checked() = !((spinBox.value() > 25) && (slider.value() < 75));
```

除了绑定到属性，表达式还可以绑定到槽或lambda：

```cpp
(slider1.value() + slider2.value())
    .bindTo(slider3, &QSlider::setValue)
    .bindTo(slider3, [](int v){ qDebug() << v; });
```

> 注意：每个绑定都会单独计算表达式的值，对于以上代码，表达式将在更新后被计算两次

---

若要在表达式中使用一些特殊运算符和 c++ 功能，请使用专门方法：

三目运算符：`nwidget::cond`

```cpp
label.text() = nwidget::cond(slider.value() > 50, QString(">"), QString("<"));
```

函数调用：`nwidget::call`

```cpp
int add(int a, int b) { return a + b; }

slider1.value() = nwidget::call(add, slider2.value(), slider3.value())

slider1.value() = nwidget::call([](int a, int b){ return a + b; },
                           slider2.value(),
                           slider3.value())
```

构造函数调用：`nwidget::constructor<T>`

```cpp
dateTimeEdit.dateTime() = nwidget::constructor<QDateTime>(dateEdit.date(), timeEdit.time());
```

成员函数调用：`invoke`

```cpp
spinBox.value() = lineEdit.text().invoke(&QString::length)
```

类型转换：`nwidget::cast<T>`、`nwidget::static_cast_<T>`、`nwidget::reinterpret_cast_<T>`

```cpp
doubleSpinBox.value() = nwidget::cast<double>(spinBox.value());

doubleSpinBox.value() = nwidget::static_cast_<double>(spinBox.value());
```

nwidget 也提供了字符串格式化方法 `nwidget::asprintf`，其内部调用 `QString::asprintf`：

```cpp
label.text() = nwidget::asprintf("%d, %d", sldier1.value(), sldier2.value());
```

你可以在表达式中使用相同实例的相同属性，但应避免循环和在表达式中更新表达式的值：

```cpp
button.iconSize()
= nwidget::constructor<QSize>(slider.value(),   // < 此处变更信号被订阅
                         button.iconSize() // < 此处变更信号被忽略
                         .invoke(&QSize::height));
```

### is_observable\<T>

`nwidget::is_observable<T>` 可用于判断一个属性/表达式是否可观察：

```cpp
auto expr1 = slider.value() + 10;
nwidget::is_observable_v<decltype(slider.value())>; // true
nwidget::is_observable_v<decltype(expr1)>; // true

auto expr2 = slider.maximum() + 10;
nwidget::is_observable_v<decltype(slider.maximum())>; // false
nwidget::is_observable_v<decltype(expr2)>; // false
```

### is_same_property<A, B>

```cpp
using prop1 = decltype(slider1.value());
using prop2 = decltype(slider2.value());
using prop3 = decltype(slider1.maximum());

nwidget::is_same_property_v<prop1, prop2>; // true
nwidget::is_same_property_v<prop1, prop3>; // false

```
