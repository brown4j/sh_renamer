#include "QtApplShrenamer.h"

QtApplShrenamer::QtApplShrenamer(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    qdir = new QDir;

    QFileSystemModel* model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
      
    ui.listViewLeft->setModel(model);
    ui.tableView->setModel(model);

    ui.lineEditCurrentPath->setText(qdir->path());
    

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
    //ui.lineEditCurrentPath->setText(qdir->currentPath());
}

void QtApplShrenamer::lineEdit_show()
{



}