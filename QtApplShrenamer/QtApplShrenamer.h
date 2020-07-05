#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileSystemModel>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTreeView>
#include <QMessageBox>
#include <QStatusBar>

#include "ui_QtApplShrenamer.h"

class QtApplShrenamer : public QMainWindow
{
    Q_OBJECT

public:
    QtApplShrenamer(QWidget *parent = Q_NULLPTR);
    void createStatusBar();

private:
    QDir* qdir;
    QFileSystemModel* qfsModel;


private:
    Ui::QtApplShrenamerClass ui;

private slots:
    void pushButtonUpDir_clicked();
    void elementsPathChanged();
    void movePathUpper();
    void listViewLeft_ItemClicked(const QModelIndex index);

};

 