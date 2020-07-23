#pragma once

#include <QtWidgets>
#include <QFileSystemModel>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTreeView>
#include <QListView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSplitter>
#include <QLineEdit>

class QPushButton;

class QtApplShrenamer : public QWidget
{
    Q_OBJECT

public:
    QtApplShrenamer(QWidget *parent = Q_NULLPTR);

private:
    QPushButton * button1;
    QPushButton* button2;
    QPushButton* button3;
    QPushButton* button4;
    QHBoxLayout* layouth;
    QVBoxLayout* layout;
    //QLabel* printName;

    //QLineEdit* nameEdit;

    //QVBoxLayout* layoutVbox1;
    //QHBoxLayout* layoutHbox1;
    //QHBoxLayout* layoutHbox2;
    ////QSplitter* layoutSplitter;
    //QPushButton* buttonUpDir;
    //QPushButton* buttonSearchDir;
    //QLineEdit* lineeditCurrentPath;

private:
    //void resizeEvent(QResizeEvent*);

};
