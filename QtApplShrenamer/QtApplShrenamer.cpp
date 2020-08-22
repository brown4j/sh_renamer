#include <QtWidgets>

#include "QtApplShrenamer.h"

QtApplShrenamer::QtApplShrenamer()
{
    /* visual design start */


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
    
    /* visual design end */

    
    /* directory structure start */
    qdir = new QDir;
    qdir->setPath(QDir::currentPath());

    //qfCurrent = new QFileSelector;
    qfCurrent = new QFile;
    qdirCurrent = new QDir;
    qfi = new QFileInfo;

    qfsModel = new QFileSystemModel;
    qfsModel->setRootPath(QDir::currentPath());

    elementsPathChanged();
    /* directory structure end */
    
    
    
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

void QtApplShrenamer::elementsPathChanged()
{
    editCurrentPath->setText(qdir->path());
    qfsModel->setRootPath(qdir->path());

    listviewLeft->setModel(qfsModel);
    listviewLeft->setRootIndex(qfsModel->index(qdir->path()));
    tableviewRight->setModel(qfsModel);
    tableviewRight->setRootIndex(qfsModel->index(qdir->path()));

}

void QtApplShrenamer::movePathUpper() {
    qdir->cdUp();
    elementsPathChanged();

}

void QtApplShrenamer::newFile()
{
    editCurrentPath->setText(tr("Invoked <b>File|New</b>"));
}

void QtApplShrenamer::about()
{
    editCurrentPath->setText(tr("Invoked <b>Help|About</b>"));
    //QMessageBox::about(this, tr("About Menu"),
    //    tr("The <b>Menu</b> example shows how to create "
    //        "menu-bar menus and context menus."));
}

void QtApplShrenamer::aboutQt()
{
    editCurrentPath->setText(tr("Invoked <b>Help|About Qt</b>"));
}

void QtApplShrenamer::createActions()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &QtApplShrenamer::newFile);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &QtApplShrenamer::about);

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(aboutQtAct, &QAction::triggered, this, &QtApplShrenamer::aboutQt);
}

void QtApplShrenamer::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    //! [9]
    //! [11]
    fileMenu->addSeparator();
    //! [11]
    fileMenu->addAction(exitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
    //! [9] 
}
