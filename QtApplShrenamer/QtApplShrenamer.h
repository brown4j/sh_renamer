#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileSystemModel>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSplitter>
#include <QLineEdit>

class QPushButton;

class QtApplShrenamer : public QMainWindow
{
    Q_OBJECT

public:
    QtApplShrenamer(QWidget *parent = Q_NULLPTR);
    //void createStatusBar();

//private:
//    QDir* qdir;
//    QDir* qdirCurrent;
//    QFileSystemModel* qfsModel;
//    //QFileSelector* qfCurrent;
//    QFile* qfCurrent;
//    QFileInfo* qfi;

private:
    QWidget* qwidgetTop;
    QVBoxLayout* vboxLayoutTop;

    QHBoxLayout* hboxLayoutTop;
    QPushButton* btnPreviousPath;
    QPushButton* btnUpperPath;
    QLineEdit* editCurrentPath;
    QPushButton* btnLoadPath;

    QHBoxLayout* hboxLayoutBottom;
    QListView* listviewLeft;
    QTableView* tableviewRight;
    

private:
    //void resizeEvent(QResizeEvent*);

//private slots:
//    void listViewLeft_ItemClicked(const QModelIndex index);
//    void pushButtonUpDir_clicked();
//    void elementsPathChanged();
//    void movePathUpper();
    
};

 