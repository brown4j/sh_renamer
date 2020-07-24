#include "QtApplShrenamer.h"

QtApplShrenamer::QtApplShrenamer(QWidget *parent) : QWidget(parent)
{
    //QFileSystemModel* model = new QFileSystemModel;
    //model->setRootPath(QDir::currentPath());

    QWidget* qwidgetTop = new QWidget();

    layout = new QVBoxLayout();
    layouth = new QHBoxLayout(this);

    button1 = new QPushButton("Button1", this);
    button2 = new QPushButton("Button2", this);
    button3 = new QPushButton("Button3", this);
    button4 = new QPushButton("Button4", this);

    //button1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

       layout->setSpacing(3);
       layout->addStretch(1);
    layout->addWidget(button2);
    layout->addWidget(button1);
    layout->addStretch(1);

    layouth->addSpacing(15);
    layouth->addWidget(button3);
    layouth->addLayout(layout);
    setLayout(layouth);
     
    //QVBoxLayout* layoutVbox1 = new QVBoxLayout();

    //QHBoxLayout* layoutHbox1 = new QHBoxLayout();
    //QPushButton* buttonUpDir = new QPushButton("1");
    //layoutHbox1->addWidget(buttonUpDir);

    ////buttonSearchDir = new QPushButton("O");
    ////layoutHbox1->addWidget(buttonSearchDir);
    //
    //QHBoxLayout* layoutHbox2 = new QHBoxLayout();
    //QLineEdit* lineeditCurrentPath = new QLineEdit("");
    //layoutHbox2->addWidget(lineeditCurrentPath);

    //layoutVbox1->addLayout(layoutHbox1);
    //layoutVbox1->addLayout(layoutHbox2);

    ////setLayout(layoutVbox1);
    //centralWidget()->setLayout(layoutHbox1);

    //layoutSplitter = new QSplitter(this);
    //QFileSystemModel* model = new QFileSystemModel;
    //model->setRootPath(QDir::currentPath());
    //QTreeView* tree = new QTreeView(layoutSplitter);
    //tree->setModel(model);
    //tree->setRootIndex(model->index(QDir::currentPath()));
    //QListView* list = new QListView(layoutSplitter);
    //list->setModel(model);
    //list->setRootIndex(model->index(QDir::currentPath()));
    //QVBoxLayout* layout = new QVBoxLayout();
    //
    //layout->addWidget(layoutSplitter);
    

    //layoutSplitter->setSizes(sizes);

}
//
//void QtApplShrenamer::resizeEvent(QResizeEvent*)
//{
//    //layoutVbox1->setFixedSize(this->width(), this->height());
//    
//}