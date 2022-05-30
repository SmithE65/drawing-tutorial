#include "renderarea.h"

#include <QPaintEvent>
#include <QPainter>
#include <QColor>

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent},
      mBackgroundColor(QColorConstants::Blue),
      mShapeColor(QColorConstants::White)
{

}

QSize RenderArea::sizeHint() const
{
    return QSize(400,200);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100,100);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawRect(this->rect());
    painter.drawLine(this->rect().topLeft(), this->rect().bottomRight());
}
