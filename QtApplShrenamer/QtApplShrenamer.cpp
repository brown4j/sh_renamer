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
    ui.tableViewRight->setModel(qfsModel);
    ui.tableViewRight->setRootIndex(qfsModel->index(qdir->path()));
    
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
    //QMessageBox::information(this, "Current Path", qdirCurrent->path());
    //QMessageBox::information(this, "Current Path", filesizeCalculator(qfi->size()));

    ui.statusBarBottom->showMessage(qdirCurrent->path() + " (" + filesizeCalculator(qfi->size()) + ")");
}

void QtApplShrenamer::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

QString QtApplShrenamer::filesizeCalculator(qint64 qi)
{
    QString qsunit = "B";

    if (qi > 1024*1024) {
        qi /= (1024 * 1024);
        qsunit = "MB";
    }
    else if (qi > 1024) {
        qi /= 1024;
        qsunit = "KB";
    }

    return QString::number(qi) + qsunit;
}