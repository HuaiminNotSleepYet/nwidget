#include "mainwindow.h"

#include "nwidget/boxlayout.h"
#include "nwidget/datetimeedit.h"
#include "nwidget/formlayout.h"
#include "nwidget/gridlayout.h"
#include "nwidget/groupbox.h"
#include "nwidget/label.h"
#include "nwidget/lineedit.h"
#include "nwidget/slider.h"

MainWindow::MainWindow()
{
    setWindowTitle("nwidget");

    using namespace nw;

    LabelId label_0_0 = new QLabel;
    LineEditId lineEdit_0_0 = new QLineEdit;

    LabelId label_0_1 = new QLabel;
    SliderId slider_0_1 = new QSlider(Qt::Horizontal);

    SliderId slider_1_0_0 = new QSlider(Qt::Horizontal);
    SliderId slider_1_0_1 = new QSlider(Qt::Horizontal);
    SliderId slider_1_0_2 = new QSlider(Qt::Horizontal);
    SliderId slider_1_0_3 = new QSlider(Qt::Horizontal);

    DateEditId dateEdit_1_1_0 = new QDateEdit;
    DateEditId dateEdit_1_1_1 = new QDateEdit;
    LabelId label_1_1 = new QLabel;

    LabelId label_2_0 = new QLabel;
    SliderId slider_2_0 = new QSlider(Qt::Horizontal);

    DateTimeEditId dateTimeEdit_2_1 = new QDateTimeEdit;
    DateEditId dateEdit_2_1 = new QDateEdit;
    TimeEditId timeEdit_2_1 = new QTimeEdit;

    setCentralWidget(Widget(GridLayout{
        {0, 0, GroupBox("Binding", VBoxLayout{
            Label("label.text = lineEdit.text"),
            Label(label_0_0)
                .alignment(Qt::AlignHCenter)
                .text(lineEdit_0_0.text()), // create binding as a builder property
            LineEdit(lineEdit_0_0).text("hello"),
            BoxLayoutItem::Stretch,
        })},

        {0, 1, GroupBox("Call", VBoxLayout{
            Label("label.text = asprintf(\"%02d\", slider.value)"),
            Label(label_0_1)
                .alignment(Qt::AlignHCenter)
                .text(nw::asprintf("%02d", slider_0_1.value())), // use nw::call to replace function call
            Slider(slider_0_1).value(32),
            BoxLayoutItem::Stretch,
        })},

        {1, 0, GroupBox("Expression", VBoxLayout{
            Label("slider2.value = slider0.value\nslider3.value = slider0.value + slider1.value\n"),
            HBoxLayout{
                Slider(slider_1_0_0).range(0, 50).value(16),
                Slider(slider_1_0_1).range(0, 50).value(28),
            },
            Slider(slider_1_0_2),
            Slider(slider_1_0_3),
            BoxLayoutItem::Stretch,
        })},

        {1, 1, GroupBox("Invoke", VBoxLayout{
            Label("label.text = dateEdit0.date.daysTo(dateEdit1.date)"),
            FormLayout{
               {"" , DateEdit(dateEdit_1_1_0)},
               {"-", DateEdit(dateEdit_1_1_1)},
               {"=", Label(label_1_1)},
            },
            BoxLayoutItem::Stretch,
        })},

        {2, 0, GroupBox("Conditional", VBoxLayout{
            Label("label.text = slider.value > 50 ? \">\" : \"<\" "),
            Label(label_2_0).alignment(Qt::AlignHCenter),
            Slider(slider_2_0).range(0, 100).value(72),
            BoxLayoutItem::Stretch,
        })},


        {2, 1, GroupBox("Constructor", VBoxLayout{
            Label("dateTimeEdit.dateTime = QDateTime(dateEdit.date, timeEdit.time)"),
            DateTimeEdit(dateTimeEdit_2_1).readOnly(true),
            HBoxLayout{
              DateEdit(dateEdit_2_1),
              TimeEdit(timeEdit_2_1),
            },
        })},
    }.rowStretch(3, 1)));

    // or create binding in code.

    slider_1_0_2.value() = slider_1_0_0.value();
    slider_1_0_3.value() = slider_1_0_0.value() + slider_1_0_1.value();

    label_1_1.text() = nw::asprintf("%d", dateEdit_1_1_0.date().invoke(&QDate::daysTo, dateEdit_1_1_1.date()));

    label_2_0.text() = nw::cond(slider_2_0.value() > 50, QString(">"), QString("<"));

    dateTimeEdit_2_1.dateTime() = nw::constructor<QDateTime>(dateEdit_2_1.date(), timeEdit_2_1.time());
}
