#include "QtApplShrenamer.h"

QtApplShrenamer::QtApplShrenamer(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    qdir = new QDir;
    qdir->setPath(QDir::currentPath());

    //QMessageBox::information(this, "Current Path", qdir->path());

    qfsModel = new QFileSystemModel;
    qfsModel->setRootPath(QDir::currentPath());

    elementsPathChanged();

// connect functions
    connect(ui.pushButtonUpDir, SIGNAL(clicked()), this, SLOT(movePathUpper()));
    connect(ui.pushButtonLeftDir, SIGNAL(clicked()) , this, SLOT(pushButtonUpDir_clicked()));

}

void QtApplShrenamer::pushButtonUpDir_clicked()
{
    //msgBox.setText("The document has been modified.");

}

void QtApplShrenamer::elementsPathChanged()
{
    //QMessageBox::information(this, "Current Path", QDir::currentPath());
    ui.lineEditCurrentPath->setText(qdir->path());
    qfsModel->setRootPath(qdir->path());

    ui.listViewLeft->setModel(qfsModel);
    ui.listViewLeft->setRootIndex(qfsModel->index(qdir->path()));
}

void QtApplShrenamer::movePathUpper() {
    qdir->cdUp();
    elementsPathChanged();

}