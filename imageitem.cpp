#include "imageitem.h"
#include <QDebug>
#include <QImage>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QPointF>
#include <QRectF>

ImageItem::ImageItem() : m_angle(30), m_scale(1.0) {
  setAcceptedMouseButtons(Qt::AllButtons);
  setAcceptHoverEvents(true);
  setFlag(ItemAcceptsInputMethod, true);
  QImage img("/home/eton/Pictures/duck.jpeg");
  qDebug() << img.size();
  img = img.scaledToWidth(200, Qt::SmoothTransformation);
  m_img = img;
}

void ImageItem::setScale(const float s) {
  m_scale = s;
  update();
}

void ImageItem::paint(QPainter *painter) {
  QPointF viewCenter(width() / 2, height() / 2);
  QPointF imgPt(0, 0);
  // painter->drawImage(imgPt,m_img);
  qDebug() << "scale=" << m_scale;
  QPixmap imap;
  imap.convertFromImage(m_img);

  QPointF imgCen(m_img.width() / 2.f, m_img.width() / 2.f);
  painter->save();
  // painter->rotate(m_angle, boundingRect().center());
  painter->translate(viewCenter);
  painter->rotate(m_angle);
  painter->translate(-viewCenter);
  float newEdge = m_scale * width();
  float xOffset = viewCenter.x() - newEdge / 2;
  painter->drawPixmap(xOffset, xOffset, imap.scaledToHeight(newEdge));
  // painter->drawImage(xOffset, xOffset, m_img.scaledToHeight(newEdge));
  painter->restore();

  QPen pen(QColor(0, 255, 9), 3);
  painter->setPen(pen);
  painter->drawRect(boundingRect());
  painter->drawPoint(viewCenter);
}

void ImageItem::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    m_scale -= 0.1;
  } else {
    m_scale += 0.1;
  }
  if (m_scale < 0.3) {
    m_scale = 1.0;
  }
  if (m_scale > 1.5) {
    m_scale = 1.0;
  }
  update();
}
void ImageItem::mouseMoveEvent(QMouseEvent *event) { qDebug() << "move"; }

void ImageItem::mouseReleaseEvent(QMouseEvent *event) {
  // qDebug() << "release";
}

void ImageItem::wheelEvent(QWheelEvent *event) {
  // qDebug() << "wheelEvent:" << event->pixelDelta();
  if (event->pixelDelta().y() > 0) {
    m_angle += 5;
  } else {
    m_angle -= 5;
  }
  update();
}
