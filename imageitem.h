#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QImage>
#include <QPainter>
#include <QPixmap>
#include <QQuickItem>
#include <QQuickPaintedItem>

class ImageItem : public QQuickPaintedItem {
  Q_OBJECT
public:
  ImageItem();
  virtual void paint(QPainter *painter) override;
  Q_INVOKABLE void setScale(const float s);

protected:
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;

signals:

private:
  QImage m_img;
  int m_angle;
  float m_scale;
};

#endif // IMAGEITEM_H
