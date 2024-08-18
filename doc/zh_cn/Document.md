# 文档

- [布局语法](#布局语法)
  - [概述](#概述)
  - [ForEach](#foreach)
- [属性绑定](#属性绑定)
  - [概述](#概述-1)
  - [xxxRef](#xxxref)
  - [Property](#property)
  - [成员函数](#成员函数)
  - [特殊 c++ 功能](#特殊-c-功能)

## 布局语法

### 概述

使用声明式语法排列控件，通过链式调用设置控件属性

```cpp
auto* button1 = new QPushButton;
auto* button2 = new QPushButton;- [文档](#文档)
button1.setText("Button");

QLayout* layout = nw::VBoxLayout{
    button1,                                // 使用已有对象
    new QPushButton,
    nw::PushButton(),
    nw::PushButton(button2).text("Button"), // 在已有对象上设置
};
```

### ForEach

```cpp
std::vector<int> nums = {1, 2, 3, 4, 5};

QLayout* layout = nw::VBoxLayout{
    nw::Label("Label"),
    nw::ForEach(nums, [](int index, int value) -> nw::BoxLayoutItem {
        return new QPushButton(QString::number(value));
    })
};
```

![](../img/foreach_example.png)

## 属性绑定

### 概述

nwidget 使用类似 [qml 属性绑定](https://doc.qt.io/qt-6/qtqml-syntax-propertybinding.html) 的语法

```cpp
nw::SliderRef slider1;
nw::SliderRef slider2;
nw::SliderRef slider3;

QLayout* layout = nw::VBoxLayout{
    nw::Slider(slider1, Qt::Horizontal),
    nw::Slider(slider2, Qt::Horizontal),
    nw::Slider(slider3, Qt::Horizontal),
};

slider3.value() = slider1.value() + slider2.value();
```

你可以在表达式中使用相同实例的相同属性，但应避免循环和在表达式中更新表达式的值

```cpp
button.iconSize()
= nw::constructor<QSize>(slider.value(), button.iconSize().invoke(&QSize::height));
//                       ^               ^ 此处变更信号被忽略
//                       此处变更信号被订阅
```

### xxxRef

`xxxRef` 是一个辅助类，功能如下：
1. 唯一标识一个对象，类似 qml 中的 [id](https://doc.qt.io/qt-6/qtqml-syntax-objectattributes.html#the-id-attribute)，因此它不可以被设置为新值
2. 返回表示 QObject 属性的 `Property` 对象实例

> xxxRef 这个名字不能明确表示它的功能，我希望将来找到更好的代替

> 要为你的类创建对应的 Ref 对象，请参考 [length_calculator](../../examples/length_calculator)：

### Property

`Property` 代表 QObject 对象的一个属性，记录该属性的名称、Getter、Setter、变更信号等信息

```cpp
nw::LabelRef label = new QLabel;

QString name = decltype(label.text())::Info::name(); // "text"

label.text() = "hello";
QString text = label.text();
```

> `Binding` 对象会自动连接绑定表达式中 Property 对象对应 QObject 的 `destroyed` 信号

### 成员函数

使用 `invoke` 表示成员函数调用：

```cpp
nw::LineEditRef edit1;
nw::LineEditRef edit2;
nw::LabelRef label;

// ...

label.text() = (edit1.text() + ' ' + edit2.text()).invoke(&QString::toLower);
```

`invoke` 方法可携带参数:

```cpp
label.text() = lineEdit.text().invoke(&QString::last, 5);
```

### 特殊 c++ 功能

一些 c++ 功能无法直接在绑定表达式中使用，为此 nwidget 提供了以下方法：

|                            | 功能             | 备注       |
| -------------------------- | ---------------- | ---------- |
| `nw::call`                 | 函数调用         | 可携带参数 |
| `nw::constructor<T>`       | 构造函数调用     | 可携带参数 |
| `nw::cast`                 | 强制类型转换     |            |
| `nw::static_cast_<T>`      | static_cast      |            |
| `nw::reinterpret_cast_<T>` | reinterpret_cast |            |

和一个辅助方法 `nw::asprintf`
