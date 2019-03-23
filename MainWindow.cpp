#include "Deinterlace.h"
#include "ImageWidget.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QElapsedTimer>
#include <QThread>
#include <stdint.h>
#include <memory>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->widget->setScrollBar(ui->horizontalScrollBar, ui->verticalScrollBar);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::load(QString const &path)
{
	QImage image;
	image.load(path);
	int w = image.width();
	int h = image.height();
	if (w > 0 && h > 2) {
		QElapsedTimer t;
		t.start();

		Deinterlace di;
		auto pair = di.filter(image);

		qDebug() << t.elapsed();
		ui->widget->setImage(pair.first, pair.second);
	}
}

void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
	QPoint pos = ui->widget->scrollPos();
	ui->widget->scrollTo(value, pos.y());
}

void MainWindow::on_verticalScrollBar_valueChanged(int value)
{
	QPoint pos = ui->widget->scrollPos();
	ui->widget->scrollTo(pos.x(), value);
}


void MainWindow::on_action_file_open_triggered()
{
	QString path = QFileDialog::getOpenFileName(this, tr("Open file"), path_);
	if (QFileInfo(path).isFile()) {
		path_ = path;
		load(path);
	}
}
