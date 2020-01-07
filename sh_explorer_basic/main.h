#include <QWidget>
#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	void MainWindow::createStatusBar();

private slots:
	//void newFile();
	//void open()

};