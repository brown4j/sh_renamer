#pragma once

#include <QMainWindow>

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
    QtApplShrenamer();
    //void createStatusBar();

//protected:
//#ifndef QT_NO_CONTEXTMENU
//    void contextMenuEvent(QContextMenuEvent* event) override;
//#endif // QT_NO_CONTEXTMENU


private slots:
    void newFile();
    void about();
    void aboutQt();

    void elementsPathChanged();
    void movePathUpper();
    void listviewLeft_ItemClicked(const QModelIndex);


private:
    void createActions();
    void createMenus();
    QString filesizeCalculator(qint64 qi);

private:
    QDir* qdir;
    QDir* qdirCurrent;
    QFileSystemModel* qfsModel;
    //QFileSelector* qfCurrent;
    QFile* qfCurrent;
    QFileInfo* qfi;

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
    QMenu* helpMenu;
    QAction* newAct;
    QAction* exitAct;
    QAction* aboutAct;
    QAction* aboutQtAct;

    
    //void resizeEvent(QResizeEvent*);

//    void listViewLeft_ItemClicked(const QModelIndex index);
//    void pushButtonUpDir_clicked();
//    void elementsPathChanged();
//    void movePathUpper();

};

 