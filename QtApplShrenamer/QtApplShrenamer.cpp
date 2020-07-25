#include "QtApplShrenamer.h"

QtApplShrenamer::QtApplShrenamer(QWidget* parent) : QMainWindow(parent) 
{
    //QFileSystemModel* model = new QFileSystemModel;
    //model->setRootPath(QDir::currentPath());
    const QSize btnPathCtrlSize = QSize(30, 20);

    //menuBarTop = new QMenu();
    //menuBarTop->addMenu(tr("&File")); 
    //menuBarTop->addAction(newAct);
    //menuBarTop->addAction(openAct);

    statusBar()->showMessage(tr("Ready"));

    qwidgetTop = new QWidget();
    setCentralWidget(qwidgetTop);

    hboxLayoutTop = new QHBoxLayout();
    btnPreviousPath = new QPushButton(QString::fromWCharArray(L"\u2190"), this);
    btnPreviousPath->setFixedSize(btnPathCtrlSize);
    btnUpperPath = new QPushButton(QString::fromWCharArray(L"\u2191"), this);
    btnUpperPath->setFixedSize(btnPathCtrlSize);
    // UTF-8 code from https://cloford.com/resources/charcodes/utf-8_arrows.htm
    editCurrentPath = new QLineEdit();
    btnLoadPath = new QPushButton("...", this);
    btnLoadPath->setFixedSize(btnPathCtrlSize);
    hboxLayoutTop->addWidget(btnPreviousPath);
    hboxLayoutTop->addWidget(btnUpperPath);
    hboxLayoutTop->addWidget(editCurrentPath);
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

    createActions();
    createMenus();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

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

//#ifndef QT_NO_CONTEXTMENU
//void QtApplShrenamer::contextMenuEvent(QContextMenuEvent* event)
//{
//    QMenu menu(this);
//    menu.addAction(cutAct);
//    menu.addAction(copyAct);
//    menu.addAction(pasteAct);
//    menu.exec(event->globalPos());
//}
//#endif // QT_NO_CONTEXTMENU


void QtApplShrenamer::createActions()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &QtApplShrenamer::newFile);

    cutAct = new QAction(tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
        "clipboard"));
    connect(cutAct, &QAction::triggered, this, &QtApplShrenamer::cut);

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
        "clipboard"));
    connect(copyAct, &QAction::triggered, this, &QtApplShrenamer::copy);

    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
        "selection"));
    connect(pasteAct, &QAction::triggered, this, &QtApplShrenamer::paste);
    //! [4]
     
}

void QtApplShrenamer::createMenus()
{
    //! [9] //! [10]
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(copyAct);
    //! [9] 
}

QtApplShrenamer::~QtApplShrenamer()
{
}

void QtApplShrenamer::copy()
{
    editCurrentPath->setText(tr("Invoked <b>Edit|Copy</b>"));
}