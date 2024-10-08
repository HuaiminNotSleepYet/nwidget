# nwidget

nwidget 是一个 `仅头文件` 库，为QWidget 提供了 `声明式语法` 和 `属性绑定` 的拓展

[文档](Document.md)

## 功能

### 声明式语法

![](../img/nwidget.png)

命令式：
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

声明式：
```cpp
namespace nw = nwidget;

QLayout* layout = nw::FormLayout{
    {"Lable 0", nw::LineEdit().text("Hello")},
    {"Lable 1", nw::Slider(Qt::Horizontal).range(0, 100).value(25)},
    {GridLayout{
        {0, 0,       nw::PushButton("Button 0")},
        {1, 0,       nw::PushButton("Button 1")},
        {0, 1, 2, 1, nw::PushButton("Button 2").sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding)
        },
    }}};
```

### 属性绑定

![](../img/binding.gif)

```cpp
namespace nw = nwidget;

nw::LabelId  label   = new QLabel;
nw::SliderId slider1 = new QSlider;
nw::SliderId slider2 = new QSlider;

QLayout* layout = nw::VBoxLayout{
    nw::Label(label)
        .text(nw::asprintf("%d", slider1.value() + slider2.value())), // 创建绑定
    nw::Slider(slider1).orientation(Qt::Horizontal),
    nw::Slider(slider2).orientation(Qt::Horizontal),
};

// 绑定也可通过以下方式创建
label.text() = nw::asprintf("%d", slider1.value() + slider2.value());

nw::asprintf("%d", slider1.value() + slider2.value())
    .bindTo(label, &QLabel::setText);

nw::asprintf("%d", slider1.value() + slider2.value())
    .bindTo(label, [label](const QString& s) {label.text() = s;});

```

## 优点

- 直观
- 易于修改
- 易于维护
- 有趣

## 安装

```shell
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX:PATH=/installation/path
cmake --build . --config Release --target install
```

```cmake
find_package(nwidget CONFIG REQUIRED)
target_link_libraries(main PRIVATE nwidget::nwidget)
```

## 示例

[NWidget Gallery](../../examples/gallery)：用 nwidget 编写的 [Widget Gallery](https://doc.qt.io/qt-6/qtwidgets-gallery-example.html)

![](../img/nwidget_gallery.png)

[Binding Example](../../examples/binding_example)：属性绑定示例

![](../img/binding_example.gif)

[Length Calculator](../../examples/length_caculator)：长度单位计算器

![](../img/length_calculator.gif)

## 特别感谢

- [@QuadnucYard](https://github.com/QuadnucYard) 在 C++ 方面的指导
- [@Niwik](https://github.com/niwik-dev) 对属性绑定机制的建议
