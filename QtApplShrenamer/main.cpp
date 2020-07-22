#include "QtApplShrenamer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtApplShrenamer w;

    QPushButton* button1 = new QPushButton("One");
    QPushButton* button2 = new QPushButton("Two");
    QPushButton* button3 = new QPushButton("Three");
    QPushButton* button4 = new QPushButton("Four");
    QPushButton* button5 = new QPushButton("Five");

    QVBoxLayout* qvboxLayout = new QVBoxLayout;

    qvboxLayout->addWidget(button1);
    qvboxLayout->addWidget(button2);
    qvboxLayout->addWidget(button3);
    qvboxLayout->addWidget(button4);
    qvboxLayout->addWidget(button5);

    w.setLayout(qvboxLayout);
    w.show();
    return a.exec();
}
