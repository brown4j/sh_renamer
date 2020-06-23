#include "QtApplShrenamer.h"

QtApplShrenamer::QtApplShrenamer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QFileSystemModel* model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
      
    ui.listViewLeft->setModel(model);
    ui.tableView->setModel(model);

    //ui.lineEditCurrentPath->setText(QDir::currentPath());

}

void QtApplShrenamer::resizeEvent(QResizeEvent*)
{
    ui.verticalLayoutWidget->setFixedSize(this->width(), this->height());
}