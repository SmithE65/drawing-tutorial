#include "renderarea.h"

#include "parametricshapes.h"
#include <QPaintEvent>
#include <QPainter>
#include <QColor>

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent},
      mBackgroundColor(QColorConstants::Blue),
      mShapeColor(QColorConstants::White),
      mShape(ParametricShapes::Astroid())
{

}

void RenderArea::setBackgroundColor(QColor color)
{
    mBackgroundColor = color;
}

QSize RenderArea::sizeHint() const
{
    return QSize(400,400);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(400,400);
}

void RenderArea::setShape(ParametricShape shape)
{
    mShape = shape;
}

ParametricShape RenderArea::shape() const
{
    return mShape;
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);
    painter.drawRect(this->rect());

    auto center = this->rect().center();
    auto interval = mShape.intervalLength();
    auto stepCount = mShape.stepCount();
    auto scale = mShape.scale();
    auto step = interval / stepCount;

    for (float t = 0; t < interval; t += step)
    {
        auto point = mShape.Compute(t);
        QPoint pixel;
        pixel.setX(point.x() * scale + center.x());
        pixel.setY(point.y() * scale + center.y());
        painter.drawPoint(pixel);
    }
}
