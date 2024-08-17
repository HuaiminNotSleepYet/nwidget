#include "mainwindow.h"

#include "nwidget/checkbox.h"
#include "nwidget/frame.h"
#include "nwidget/gridlayout.h"
#include "nwidget/label.h"
#include "nwidget/spinbox.h"

class MainWindowRef : public nw::WidgetRefT<MainWindow>
{
public:
    using nw::WidgetRefT<MainWindow>::WidgetRefT;

    N_PROPERTY(units::length, length1, N_GETTER(length1), N_SETTER(setLength1), N_NOTIFY(length1Changed))
    N_PROPERTY(units::length, length2, N_GETTER(length2), N_SETTER(setLength2), N_NOTIFY(length2Changed))
};


static QString number(double val)
{
    return QString::number(val, 'g', 5);
}


MainWindow::MainWindow()
    : length1_(1, units::m)
    , length2_(1, units::m)
{
    using namespace units;

    static const QHash<length_unit, QString> lengthUnitNames = {
        {mm , "mm" },
        {cm , "cm" },
        {m  , "m"  },
        {km , "km" },
        {in , "in" },
        {ft , "ft" },
        {yd , "yd" },
        {mi , "mi" },
        {nmi, "nmi"},
    };

    static const QList<length_unit> lengthUnits = {mm, cm, m , km, in, ft, yd, mi, nmi};

    const int row_count = lengthUnits.size();

    setWindowTitle("Length Calculator");

    auto* group1 = new QButtonGroup(this);
    auto* group2 = new QButtonGroup(this);

    MainWindowRef window = this;

    nw::LabelRef label = new QLabel;

    nw::DoubleSpinBoxRef spinBox1 = new QDoubleSpinBox;
    nw::DoubleSpinBoxRef spinBox2 = new QDoubleSpinBox;

    setCentralWidget(nw::Widget(nw::GridLayout{
        nw::ForEach(lengthUnits,
        [=](int index, length_unit unit) -> nw::GridLayoutItem {
            nw::LabelRef label = new QLabel;
            label.text() = nw::call(number, window.length1().invoke(&length::convert_to, unit)
                                                            .invoke(&length::value));
            return {index, 0, nw::Label(label).alignment(Qt::AlignRight)};
        }),

        nw::ForEach(lengthUnits,
        [=](int index, length_unit unit) -> nw::GridLayoutItem {
            nw::CheckBoxRef box = new QCheckBox;
            box.checked() = window.length1().invoke(&length::unit) == unit;
            return {index, 1, nw::CheckBox(box, lengthUnitNames[unit])
                    .group(group1)
                    .onClicked([=](){
                        setLength1(length1().convert_to(unit));
                        spinBox1->setValue(length1().value());
                    })};
        }),

        {0, 2, Qt::AlignHCenter, nw::Label("/")},
        {1, 2, (int)lengthUnits.size(), 1, Qt::AlignHCenter, nw::Frame().frameStyle(QFrame::VLine).frameShadow(QFrame::Raised)},

        nw::ForEach(lengthUnits,
        [=](int index, length_unit unit) -> nw::GridLayoutItem {
            nw::LabelRef label = new QLabel;
            label.text() = nw::call(number, window.length2().invoke(&length::convert_to, unit)
                                                            .invoke(&length::value));
            return {index, 3, nw::Label(label).alignment(Qt::AlignRight)};
        }),

        nw::ForEach(lengthUnits,
        [=](int index, length_unit unit) -> nw::GridLayoutItem {
            nw::CheckBoxRef box = new QCheckBox;
            box.checked() = window.length2().invoke(&length::unit) == unit;
            return {index, 4, nw::CheckBox(box, lengthUnitNames[unit])
                    .group(group2)
                    .onClicked([=](){
                        setLength2(length2().convert_to(unit));
                        spinBox2->setValue(length2().value());
                    })};
        }),

        {0, 5, Qt::AlignHCenter, nw::Label("=")},
        {1, 5, (int)lengthUnits.size(), 1, Qt::AlignHCenter, nw::Frame().frameStyle(QFrame::VLine).frameShadow(QFrame::Raised)},

        {0, 6, nw::Label(label)},

        {row_count, 0, 1, 2, nw::DoubleSpinBox(spinBox1).value(1).decimals(3).minimum(0.001).maximum(std::numeric_limits<double>::max())},
        {row_count, 3, 1, 2, nw::DoubleSpinBox(spinBox2).value(1).decimals(3).minimum(0.001).maximum(std::numeric_limits<double>::max())},

    }
    .columnStretch(0, 1)
    .columnStretch(3, 1)
    .rowStretch(row_count + 1, 1)));

    label.text() = nw::call(number, window.length1() / window.length2());

    window.length1() = nw::constructor<units::length>(spinBox1.value(), window.length1().invoke(&length::unit));
    window.length2() = nw::constructor<units::length>(spinBox2.value(), window.length2().invoke(&length::unit));
}

units::length MainWindow::length1() const { return length1_; }
units::length MainWindow::length2() const { return length2_; }

void MainWindow::setLength1(units::length v) { length1_ = v; emit length1Changed(v); }
void MainWindow::setLength2(units::length v) { length2_ = v; emit length2Changed(v); }
