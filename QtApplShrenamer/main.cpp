#include <QApplication>
#include "QtApplShrenamer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtApplShrenamer w;
    w.show();
    return a.exec();
}
