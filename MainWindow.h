#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ImageWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT
private:
	Ui::MainWindow *ui;
	QString path_;
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	void load(const QString &path);
private slots:
	void on_horizontalScrollBar_valueChanged(int value);
	void on_verticalScrollBar_valueChanged(int value);
	void on_action_file_open_triggered();
};

#endif // MAINWINDOW_H
