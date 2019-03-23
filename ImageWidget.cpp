#include "ImageWidget.h"
#include <QDebug>
#include <QPainter>
#include <QScrollBar>

ImageWidget::ImageWidget(QWidget *parent)
	: QWidget(parent)
{

}

void ImageWidget::setScrollBar(QScrollBar *hsb, QScrollBar *vsb)
{
	hsb_ = hsb;
	vsb_ = vsb;
	updateScrollBar();
}

QScrollBar *ImageWidget::hScrollBar() const
{
	return hsb_;
}

QScrollBar *ImageWidget::vScrollBar() const
{
	return vsb_;
}

void ImageWidget::updateScrollBar()
{
	QScrollBar *hsb;
	QScrollBar *vsb;
	hsb = hScrollBar();
	vsb = vScrollBar();
	if (hsb) {
		hsb->setRange(0, image_.width());
		hsb->setPageStep(width());
	}
	if (vsb) {
		vsb->setRange(0, image_.height());
		vsb->setPageStep(height());
	}
}

QPoint ImageWidget::scrollPos() const
{
	QScrollBar *hsb = hScrollBar();
	QScrollBar *vsb = vScrollBar();
	return QPoint(hsb ? hsb->value() : 0, vsb ? vsb->value() : 0);
}

void ImageWidget::scrollTo(int x, int y)
{
	QScrollBar *hsb;
	QScrollBar *vsb;
	hsb = hScrollBar();
	vsb = vScrollBar();
	if (hsb) hsb->setValue(x);
	if (vsb) vsb->setValue(y);
	update();
}

void ImageWidget::paintEvent(QPaintEvent *event)
{
	QPoint pos = scrollPos();
	QPainter pr(this);
	pr.drawImage(width() / 2 - pos.x(), height() / 2 - pos.y(), image_);
}

void ImageWidget::resizeEvent(QResizeEvent *event)
{
	updateScrollBar();
}

void ImageWidget::setImage(QImage const &image0, QImage const &image1)
{
	image0_ = image0;
	image1_ = image1;

	image_ = image0;
	updateScrollBar();
	scrollTo(image0_.width() / 2, image0_.height() / 2);
	update();
}
