#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileSystemModel>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTreeView>

class QtApplShrenamer : public QMainWindow
{
    Q_OBJECT

public:
    QtApplShrenamer(QWidget *parent = Q_NULLPTR);

private:
    void resizeEvent(QResizeEvent*);

};
