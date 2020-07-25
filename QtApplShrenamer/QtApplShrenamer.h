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
#include <QSplitter>
#include <QLineEdit>
#include <QStatusBar>
#include <QMenu>
#include <QStatusBar>

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
QT_END_NAMESPACE

class QtApplShrenamer : public QMainWindow
{
    Q_OBJECT

public:
    QtApplShrenamer(QWidget *parent = Q_NULLPTR);
    ~QtApplShrenamer();
    //void createStatusBar();

//protected:
//#ifndef QT_NO_CONTEXTMENU
//    void contextMenuEvent(QContextMenuEvent* event) override;
//#endif // QT_NO_CONTEXTMENU


//private:
//    QDir* qdir;
//    QDir* qdirCurrent;
//    QFileSystemModel* qfsModel;
//    //QFileSelector* qfCurrent;
//    QFile* qfCurrent;
//    QFileInfo* qfi;

private:
    QMenu* menuBarTop;
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

    QMenu* fileMenu;
    QAction* newAct;
    QAction* cutAct;
    QAction* copyAct;
    QAction* pasteAct;
    

private:
    
    void createActions();
    void createMenus();
    //void resizeEvent(QResizeEvent*);

private slots:
    void newFile();
    void cut();
    void copy();
    void paste();
//    void listViewLeft_ItemClicked(const QModelIndex index);
//    void pushButtonUpDir_clicked();
//    void elementsPathChanged();
//    void movePathUpper();

};

 