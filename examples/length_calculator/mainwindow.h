#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "units.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    units::length length1() const;
    units::length length2() const;

    void setLength1(units::length);
    void setLength2(units::length);

signals:
    void length1Changed(units::length);
    void length2Changed(units::length);

private:
    units::length length1_;
    units::length length2_;
};

#endif // MAINWINDOW_H
