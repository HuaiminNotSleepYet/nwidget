# nwidget

> 注意：该库当前尚不完善

用声明式语法创建 QWidget 程序界面

从命令式：
```cpp
auto* lineEdit = new QLineEdit;
lineEdit->setText("Hello");
auto* slider = new QSlider(Qt::Horizontal);
slider->setRange(0, 100);
slider->setValue(25);

auto* button0 = new QPushButton("Button 0");
auto* button1 = new QPushButton("Button 1");
auto* button2 = new QPushButton("Button 2");
button2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

auto* gridLayout = new QGridLayout;
gridLayout->addWidget(button0, 0, 0);
gridLayout->addWidget(button1, 1, 0);
gridLayout->addWidget(button2, 0, 1, 2, 1);

auto* formLayout = new QFormLayout;
formLayout->addRow("Line 0", lineEdit);
formLayout->addRow("Line 1", slider);
formLayout->addRow(gridLayout);
```

到声明式：
```cpp
QFormLayout* formLayout = FormLayout{
    {"Lable 0", LineEdit().text("Hello")},
    {"Lable 1", Slider(Qt::Horizontal).range(0, 100).value(25)},
    {GridLayout{
        {0, 0,       PushButton("Button 0")},
        {1, 0,       PushButton("Button 1")},
        {0, 1, 2, 1, PushButton("Button 2").sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding)
        },
    }}};
```

效果：

![](../img/nwidget.png)

同时，你依然可以使用命令式语法：

```cpp
auto* button = new QPushButton;
button->setText("Button");

QSlider* slider0 = nullptr;
QSlider* slider1 = nullptr;

QVBoxLayout* layout = VBoxLayout{
    button,
    Slider().bindTo(slider0),
    Slider().bindTo(slider1),
};

connect(slider0, &QSlider::valueChanged, slider1, &QSlider::setValue);
```

## 优点

- 直观
- 易于修改
- 易于维护
- 有趣

## 示例

- [NWidget Gallery](../../examples/gallery)：用 nwidget 编写的 [Widget Gallery](https://doc.qt.io/qt-6/qtwidgets-gallery-example.html)
