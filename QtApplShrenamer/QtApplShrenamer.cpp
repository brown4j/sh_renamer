#include "QtApplShrenamer.h"

QtApplShrenamer::QtApplShrenamer(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    qdir = new QDir;
    qdir->setPath(QDir::currentPath());

    //qfCurrent = new QFileSelector;
    qfCurrent = new QFile;
    qdirCurrent = new QDir;
    qfi = new QFileInfo;
    
    //QMessageBox::information(this, "Current Path", qdir->path());

    qfsModel = new QFileSystemModel;
    qfsModel->setRootPath(QDir::currentPath());

    elementsPathChanged();

// connect functions
    connect(ui.pushButtonUpDir, SIGNAL(clicked()), this, SLOT(movePathUpper()));
    connect(ui.pushButtonLeftDir, SIGNAL(clicked()), this, SLOT(pushButtonUpDir_clicked()));
    connect(ui.listViewLeft, SIGNAL(clicked(const QModelIndex)), this, SLOT(listViewLeft_ItemClicked(QModelIndex)));

}

void QtApplShrenamer::pushButtonUpDir_clicked()
{

}

void QtApplShrenamer::elementsPathChanged()
{
    ui.lineEditCurrentPath->setText(qdir->path());
    qfsModel->setRootPath(qdir->path());

    ui.listViewLeft->setModel(qfsModel);
    ui.listViewLeft->setRootIndex(qfsModel->index(qdir->path()));
}

void QtApplShrenamer::movePathUpper() {
    qdir->cdUp();
    elementsPathChanged();

}
void QtApplShrenamer::listViewLeft_ItemClicked(const QModelIndex index) {
    QString qst = index.data().toString();
    //qfCurrent->select(qst);
    //qfCurrent->open()
    qdirCurrent->setPath(qst);

    qfi->setFile(qst);




    //const QMetaObject* mObject = qfCurrent->metaObject();
    //mObject->
    QMessageBox::information(this, "Current Path", qdirCurrent->path());
    QString sA = QString::number(qfi->size());

    QMessageBox::information(this, "Current Path", sA );

}


void QtApplShrenamer::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}
