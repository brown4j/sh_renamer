#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileSystemModel>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTreeView>
#include <QMessageBox>

#include "ui_QtApplShrenamer.h"

class QtApplShrenamer : public QMainWindow
{
    Q_OBJECT

public:
    QtApplShrenamer(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtApplShrenamerClass ui;

private slots:
    void UpDirectory();

};

 