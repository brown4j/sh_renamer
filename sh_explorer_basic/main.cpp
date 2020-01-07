#include "main.h"
#include <QDebug>
#include <QApplication>
#include <QMainWindow>
#include <QStringListModel>
#include <QSplitter>
#include <QFileSystemModel>
#include <QListView>
#include <QVBoxLayout>
#include <QStatusBar>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QMainWindow MainWindow;
	MainWindow.show();

	return a.exec();
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	//resize(800, 600);

	QSplitter *splitter = new QSplitter(this);
	QFileSystemModel *model = new QFileSystemModel;
	model->setRootPath(QDir::currentPath());

	QListView *list_left = new QListView(splitter);
	list_left->setModel(model);
	list_left->setRootIndex(model->index(QDir::currentPath()));

	QListView *list_right = new QListView(splitter);
	list_right->setModel(model);
	list_right->setRootIndex(model->index(QDir::currentPath()));
	
	QVBoxLayout *layout = new QVBoxLayout();
	layout->addWidget(splitter);
	setLayout(layout);

	QStatusBar *statusbar = new QStatusBar();
	statusbar->showMessage(tr("Ready"));


}

void MainWindow::createStatusBar()
{
	statusBar()->showMessage(tr("Ready"));
}

MainWindow::~MainWindow() {

}