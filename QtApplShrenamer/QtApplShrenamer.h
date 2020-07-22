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

private:
    //QVBoxLayout* qvboxLayout;


private:
    void resizeEvent(QResizeEvent*);

};
