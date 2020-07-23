#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileSystemModel>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTreeView>
#include <QVBoxLayout>
#include <QPushButton>

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
    //QVBoxLayout* qvboxLayout;


private:
    void resizeEvent(QResizeEvent*);

private slots:
    void listViewLeft_ItemClicked(const QModelIndex index);
    void pushButtonUpDir_clicked();
    void elementsPathChanged();
    void movePathUpper();
    
};

 