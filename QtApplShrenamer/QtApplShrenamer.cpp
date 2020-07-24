#include "QtApplShrenamer.h"

QtApplShrenamer::QtApplShrenamer(QWidget* parent) : QMainWindow(parent) 
{
    //QFileSystemModel* model = new QFileSystemModel;
    //model->setRootPath(QDir::currentPath());

    qwidgetTop = new QWidget();

    hboxLayoutTop = new QHBoxLayout();
    btnPreviousPath = new QPushButton("ก็", this);
    btnUpperPath = new QPushButton("ก่", this);
    btnLoadPath = new QPushButton("...", this);
    hboxLayoutTop->addWidget(btnPreviousPath);
    hboxLayoutTop->addWidget(btnUpperPath);
    hboxLayoutTop->addWidget(btnLoadPath);
    
    hboxLayoutBottom = new QHBoxLayout();
    listviewLeft = new QListView(this);
    tableviewRight = new QTableView(this);
    hboxLayoutBottom->addWidget(listviewLeft);
    hboxLayoutBottom->addWidget(tableviewRight);

    vboxLayoutTop = new QVBoxLayout();
    vboxLayoutTop->addLayout(hboxLayoutTop);
    vboxLayoutTop->addLayout(hboxLayoutBottom);

    //setLayout(vboxLayoutTop);
    qwidgetTop->setLayout(vboxLayoutTop);
    //centralWidget()->setLayout(qwidgetTop);
    //this->setLayout(vboxLayoutTop);
    this->setCentralWidget(qwidgetTop);
    //button1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //   layout->setSpacing(3);
    //   layout->addStretch(1);
    //layout->addWidget(button2);
    //layout->addWidget(button1);
    //layout->addStretch(1);

    //layouth->addSpacing(15);
    //layouth->addWidget(button3);
    //layouth->addLayout(layout);
     
    //QVBoxLayout* layoutVbox1 = new QVBoxLayout();

    //QHBoxLayout* layoutHbox1 = new QHBoxLayout();
    //QPushButton* buttonUpDir = new QPushButton("1");
    //layoutHbox1->addWidget(buttonUpDir);

    ////buttonSearchDir = new QPushButton("O");
    //
    //QHBoxLayout* layoutHbox2 = new QHBoxLayout();
    //QLineEdit* lineeditCurrentPath = new QLineEdit("");
    //layoutHbox2->addWidget(lineeditCurrentPath);

    //layoutVbox1->addLayout(layoutHbox1);
    //layoutVbox1->addLayout(layoutHbox2);


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