#include "QtApplShrenamer.h"

QtApplShrenamer::QtApplShrenamer(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    qdir = new QDir;
    qfsModel = new QFileSystemModel;
    qfsModel->setRootPath(QDir::currentPath());

// connect functions
    connect(ui.pushButtonUpDir, SIGNAL(clicked()), this, SLOT(pushButtonUpDir_clicked()));
}

void QtApplShrenamer::pushButtonUpDir_clicked()
{
    //ui.setupUi(this);
    //QMessageBox msgBox;
    //msgBox.setText("The document has been modified.");
    //msgBox.exec();

    QMessageBox::information(this, "Current Path", qdir->path());

    qdir->cdUp();
    lineEdit_show();
}

void QtApplShrenamer::lineEdit_show()
{
    ui.setupUi(this);

    ui.lineEditCurrentPath->setText(qdir->currentPath());

    ui.listViewLeft->setModel(qfsModel);
    ui.tableView->setModel(qfsModel);
}