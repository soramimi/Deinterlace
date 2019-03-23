#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>

class QScrollBar;

class ImageWidget : public QWidget {
	Q_OBJECT
private:
	QScrollBar *hsb_ = nullptr;
	QScrollBar *vsb_ = nullptr;
	QImage image0_;
	QImage image1_;
	QImage image_;
	void updateScrollBar();
protected:
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent *event);
public:
	explicit ImageWidget(QWidget *parent = nullptr);
	void setScrollBar(QScrollBar *hsb, QScrollBar *vsb);
	QScrollBar *hScrollBar() const;
	QScrollBar *vScrollBar() const;
	void setImage(const QImage &image0, const QImage &image1);
	void scrollTo(int x, int y);
	QPoint scrollPos() const;

	// QWidget interface
protected:
};

#endif // IMAGEWIDGET_H
