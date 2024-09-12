# Document

- [Inclusion](#inclusion)
- [Layout Syntax](#layout-syntax)
  - [ForEach](#foreach)
- [Property Binding](#property-binding)
  - [xxxId](#xxxid)
  - [Property](#property)
  - [Property Binding](#property-binding)
  - [is\_observable\<T\>](#is_observablet)
  - [is\_same\_property\<A, B\>](#is_same_propertya-b)

## Inclusion

Include each control individually:

```cpp
#include <nwidget/pushbutton.h>
#include <nwidget/slider.h>
#include <nwidget/...>
```

Or use `nwidget.h` after QT header files:

```cpp
#include <QPushButton>
#include <QSlider>
#include <Q...>
#include <nwidget/nwidget.h>
```

## Layout Syntax

Use declarative syntax to arrange controls and set control properties through method chaining.

```cpp
auto* button1 = new QPushButton;
auto* button2 = new QPushButton;
button1.setText("Button");

QLayout* layout = nwidget::VBoxLayout{
    button1,                                // Use existing instance
    new QPushButton,
    nwidget::PushButton(),
    nwidget::PushButton(button2).text("Button"), // Set on existing instance
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

## Property Binding

nwidget uses syntax similar to [qml property binding](https://doc.qt.io/qt-6/qtqml-syntax-propertybinding.html).

You can create binding in declarative syntax:

```cpp
LabelId label = new QLabel;
LineEditId edit = new QLineEdit;

QLayout* layout = VBoxLayout{
    Label(label).text(edit.text()),
    LineEdit(edit)
};
```

or in code:

```cpp
nwidget::SliderId slider1 = new QSlider;
nwidget::SliderId slider2 = new QSlider;
nwidget::SliderId slider3 = new QSlider;

slider3.value() = slider1.value() + slider2.value();
```

### xxxId

To achieve a mechanism similar to QML's [id](https://doc.qt.io/qt-6/qtqml-syntax-objectattributes.html#the-id-attribute), nwidget provides the `xxxId` class. It is used to uniquely identify an object and get instance of [Property](#property).

To create a Id type for custom class, refer to `MainWindowId` in [length_calculator](../../examples/length_calculator/mainwindow.cpp).

### Property

`Property` is a template class representing a property of a QObject instance. It uses template parameters to record the property’s name, Getter, Setter, and change signal.

There are several ways to manipulate `Property`:

```cpp
// Set and get methods
auto textProp = label.text();
textProp.set("value1");
QString text = textProp.get();

// Assignment operator
auto valueProp = slider.value();
valueProp = 20;
valueProp += 10;

// Increment/Decrement
++valueProp;
```

### Property Binding

Similar to qml, binding is created by assigning an expression of `Property` to another. When a new value or binding is set for a `Property`, the old binding is removed.

The simplest binding is assigning one property to another:

```cpp
label.text() = lineEdit.text()
```

Binding expressions support most c++ operators:

```cpp
slider1.value() = slider2.value() / 2;

checkBox.checked() = slider.value() > 50;

checkBox.checked() = !((spinBox.value() > 25) && (slider.value() < 75));
```

In addition to properties, expressions can also be bind to a slots or lambda:

```cpp
(slider1.value() + slider2.value())
    .bindTo(slider3, &QSlider::setValue)
    .bindTo(slider3, [](int v){ qDebug() << v; });
```

> Note: Each binding would evaluates the expression once at update time,  for the code above, the expression will be evaluated 2 times when updated.

---

For some operators and C++ features, specific methods are required:

Ternary operator: `nwidget::cond`

```cpp
label.text() = nwidget::cond(slider.value() > 50, QString(">"), QString("<"));
```

Function calls: `nwidget::call`

```cpp
int add(int a, int b) { return a + b; }

slider1.value() = nwidget::call(add, slider2.value(), slider3.value())

slider1.value() = nwidget::call([](int a, int b){ return a + b; },
                           slider2.value(),
                           slider3.value())
```

Constructor calls: `nwidget::constructor<T>`

```cpp
dateTimeEdit.dateTime() = nwidget::constructor<QDateTime>(dateEdit.date(), timeEdit.time());
```

Member function calls: `invoke`

```cpp
spinBox.value() = lineEdit.text().invoke(&QString::length)
```

Cast: `nwidget::cast<T>`, `nwidget::static_cast_<T>`, `nwidget::reinterpret_cast_<T>`

```cpp
doubleSpinBox.value() = nwidget::cast<double>(spinBox.value());

doubleSpinBox.value() = nwidget::static_cast_<double>(spinBox.value());
```

nwidget also provides a string formatting method `nwidget::asprintf`, internally calling `QString::asprintf`:

```cpp
label.text() = nwidget::asprintf("%d, %d", slider1.value(), slider2.value());
```

You can use the same instance’s properties in expressions, but need to avoid loops and updating the value of an expression within the expression:

```cpp
button.iconSize()
= nwidget::constructor<QSize>(slider.value(),   // < Signal change here is subscribed
                         button.iconSize() // < Signal change here is ignored
                         .invoke(&QSize::height));
```

### is_observable\<T>

`nwidget::is_observable<T>` is a trait to check if a property/expr is observable:

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
