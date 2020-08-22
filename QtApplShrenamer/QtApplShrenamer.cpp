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

    // upper horizon box configuration
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
    
    // bottom horizon box configuration
    hboxLayoutBottom = new QHBoxLayout();
    listviewLeft = new QListView(this);
    listviewLeft->setSelectionMode(QAbstractItemView::ExtendedSelection);
    listviewLeft->setDragEnabled(true);
    listviewLeft->setAcceptDrops(true);
    listviewLeft->setDropIndicatorShown(true);

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
    
    // resizing window
    QSize availableSize = qApp->desktop()->availableGeometry().size();
    int width = availableSize.width() * 0.5;
    int height = availableSize.height() * 0.7;
    QSize newSize(width, height);
    setGeometry( 
        QStyle::alignedRect( 
            Qt::LeftToRight, Qt::AlignCenter, newSize, 
            qApp->desktop()->availableGeometry()  )
    );

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

    /* connect functions */
    connect(btnUpperPath, SIGNAL(clicked()), this, SLOT(movePathUpper()));
    connect(btnPreviousPath, SIGNAL(clicked()), this, SLOT(pushButtonUpDir_clicked()));
    connect(listviewLeft, SIGNAL(clicked(const QModelIndex)), this, SLOT(listviewLeft_ItemClicked(QModelIndex)));

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

void QtApplShrenamer::listviewLeft_ItemClicked(const QModelIndex index) {
    QString qst = index.data().toString();
    //qfCurrent->select(qst);
    //qfCurrent->open()
    qdirCurrent->setPath(qst);

    qfi->setFile(qst);

    //QMessageBox::information(this, "Current Path", filesizeCalculator(qfi->size()));

    statusBar()->showMessage(qdirCurrent->path() + " (" + filesizeCalculator(qfi->size()) + ")");
}



QString QtApplShrenamer::filesizeCalculator(qint64 qi)
{
    QString qsunit = "B";

    if (qi > 1024 * 1024) {
        qi /= (1024 * 1024);
        qsunit = "MB";
    }
    else if (qi > 1024) {
        qi /= 1024;
        qsunit = "KB";
    }

    return QString::number(qi) + qsunit;
}