#include "QtApplShrenamer.h"

QtApplShrenamer::QtApplShrenamer(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    qdir = new QDir;
    qfsModel = new QFileSystemModel;
    qfsModel->setRootPath(QDir::currentPath());

    elementsPathChanged();

// connect functions
    connect(ui.pushButtonUpDir, SIGNAL(clicked()), this, SLOT(movePathUpper()));
    //connect(ui.pushButtonUpDir, SIGNAL(clicked()), this, SLOT(elementsPathChanged()));
    connect(ui.pushButtonLeftDir, SIGNAL(clicked()) , this, SLOT(pushButtonUpDir_clicked()));

}

void QtApplShrenamer::pushButtonUpDir_clicked()
{
    //ui.setupUi(this);
    //QMessageBox msgBox;
    //msgBox.setText("The document has been modified.");
    //msgBox.exec();

}

void QtApplShrenamer::elementsPathChanged()
{
    //QMessageBox::information(this, "Current Path", QDir::currentPath());
    //QMessageBox::information(this, "Current Path", qdir->path());
    ui.lineEditCurrentPath->setText(qdir->path());
    
    qfsModel->setRootPath(qdir->path());

    //ui.listViewLeft->setModel(qfsModel);
    //ui.listViewLeft->setRootIndex(qfsModel->index(QDir::currentPath()));
    ui.listViewLeft->setModel(qfsModel);
    ui.listViewLeft->setRootIndex(qfsModel->index(qdir->path()));
    //ui.tableView->setModel(qfsModel);
}

void QtApplShrenamer::movePathUpper() {
    qdir->cdUp();
    elementsPathChanged();

}