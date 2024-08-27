# Document

- [Layout Syntax](#layout-syntax)
  - [ForEach](#foreach)
- [Property Binding](#property-binding)
  - [xxxId](#xxxid)
  - [Property](#property)
  - [Property Binding](#property-binding-1)
  - [Binding Object](#binding-object)

## Layout Syntax

Use declarative syntax to arrange controls and set control properties through method chaining.

```cpp
auto* button1 = new QPushButton;
auto* button2 = new QPushButton;
button1.setText("Button");

QLayout* layout = nw::VBoxLayout{
    button1,                                // Use existing instance
    new QPushButton,
    nw::PushButton(),
    nw::PushButton(button2).text("Button"), // Set on existing instance
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

## Property Binding

nwidget uses syntax similar to [qml property binding](https://doc.qt.io/qt-6/qtqml-syntax-propertybinding.html).

```cpp
nw::SliderId slider1;
nw::SliderId slider2;
nw::SliderId slider3;

QLayout* layout = nw::VBoxLayout{
    nw::Slider(slider1, Qt::Horizontal),
    nw::Slider(slider2, Qt::Horizontal),
    nw::Slider(slider3, Qt::Horizontal),
};

slider3.value() = slider1.value() + slider2.value();
```

### xxxId

To achieve a mechanism similar to QML's [id](https://doc.qt.io/qt-6/qtqml-syntax-objectattributes.html#the-id-attribute), nwidget provides the `xxxId` class. It is used to uniquely identify an object and get instance of [Property](#property).

To create a Id type for custom class, refer to `MainWindowId` in [length_calculator](../../examples/length_calculator/mainwindow.cpp).

### Property

`Property` is a template class representing a property of a QObject instance. It uses template parameters to record the property’s name, Getter, Setter, and change signal:

```cpp
template<typename Object_,
         typename Type_,
         typename Getter_,
         typename Setter_,
         typename Notify_>
struct PropertyInfo
{
    using Object = Object_;
    using Type   = Type_;
    using Getter = Getter_;
    using Setter = Setter_;
    using Notify = Notify_;
};

template<typename PropertyInfo>
class Property
{
public:
    using Info = PropertyInfo;
    // ...
}
```

Usually you don't need to create `Property` directly, but use the `N_ID_PROPERTY` macro to declare it.

For the property without Getter/Setter/Notify, use `N_NO_GETTER`/`N_NO_SETTER`/`N_NO_NOTIFY` instend.

```cpp
class xxxId : public ObjectIdT<xxx>
{
public:
    N_ID_PROPERTY(int, propA, N_GETTER(propA), N_SETTER(setPropA), N_NOTIFY(propAChanged))
    N_ID_PROPERTY(int, propB, N_GETTER(propB), N_NO_SETTER       , N_NO_NOTIFY           )
}
```

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

For some operators and C++ features, specific methods are required:

Ternary operator: `nw::cond`

```cpp
label.text() = nw::cond(slider.value() > 50, QString(">"), QString("<"));
```

Function calls: `nw::call`

```cpp
int add(int a, int b) { return a + b; }

slider1.value() = nw::call(add, slider2.value(), slider3.value())

slider1.value() = nw::call([](int a, int b){ return a + b; },
                           slider2.value(),
                           slider3.value())
```

Constructor calls: `nw::constructor<T>`

```cpp
dateTimeEdit.dateTime() = nw::constructor<QDateTime>(dateEdit.date(), timeEdit.time());
```

Member function calls: `invoke`

```cpp
spinBox.value() = lineEdit.text().invoke(&QString::length)
```

Cast: `nw::cast<T>`, `nw::static_cast_<T>`, `nw::reinterpret_cast_<T>`

```cpp
doubleSpinBox.value() = nw::cast<double>(spinBox.value());

doubleSpinBox.value() = nw::static_cast_<double>(spinBox.value());
```

nwidget also provides a string formatting method `nw::asprintf`, internally calling `QString::asprintf`:

```cpp
label.text() = nw::asprintf("%d, %d", slider1.value(), slider2.value());
```

You can use the same instance’s properties in expressions, but need to avoid loops and updating the value of an expression within the expression:

```cpp
button.iconSize()
= nw::constructor<QSize>(slider.value(),   // < Signal change here is subscribed
                         button.iconSize() // < Signal change here is ignored
                         .invoke(&QSize::height));
```

### Binding Object

When creating a binding, you can get a `Binding` instance:

```cpp
Binding* bind = label.text() = lineEdit.text();
```

> If there are no observable values in the binding expression, `nullptr` is returned.

`Binding` has an `update` signal triggered when the binding expression is recalculated.

`Binding` automatically connects to the `destroyed` signal of the `QObject` corresponding to `Property` in the binding expression, so you don’t need to manage its lifecycle.
