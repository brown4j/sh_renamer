#include "QtApplShrenamer.h"

QtApplShrenamer::QtApplShrenamer(QWidget *parent) : QMainWindow(parent)
{

    QFileSystemModel* model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
      

}

void QtApplShrenamer::resizeEvent(QResizeEvent*)
{
}