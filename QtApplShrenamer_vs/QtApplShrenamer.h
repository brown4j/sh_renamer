#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileSystemModel>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTreeView>

#include "ui_QtApplShrenamer.h"

class QtApplShrenamer : public QMainWindow
{
    Q_OBJECT
        q
public:
    QtApplShrenamer(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtApplShrenamerClass ui;
    void resizeEvent(QResizeEvent*);

};
