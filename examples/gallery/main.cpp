#include "nwidgetgallery.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    NWidgetGallery w;
    w.show();
    return a.exec();
}
