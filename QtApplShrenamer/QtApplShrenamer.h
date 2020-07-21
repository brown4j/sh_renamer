#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileSystemModel>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTreeView>
#include <QMessageBox>
#include <QStatusBar>

//#include <QFileSelector>

#include "ui_QtApplShrenamer.h"

class QtApplShrenamer : public QMainWindow
{
    Q_OBJECT

public:
    QtApplShrenamer(QWidget *parent = Q_NULLPTR);
    void createStatusBar();

private:
    QDir* qdir;
    QDir* qdirCurrent;
    QFileSystemModel* qfsModel;
    //QFileSelector* qfCurrent;
    QFile* qfCurrent;
    QFileInfo* qfi;

private:
    Ui::QtApplShrenamerClass ui;
    QString filesizeCalculator(qint64 qi);

private slots:
    void listViewLeft_ItemClicked(const QModelIndex index);
    void pushButtonUpDir_clicked();
    void elementsPathChanged();
    void movePathUpper();
    
};

 