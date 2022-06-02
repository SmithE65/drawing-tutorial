#include "renderarea.h"

#include <QPaintEvent>
#include <QPainter>
#include <QColor>

#include "drawsettings.h"
#include "parametricshapes.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent},
      mBackgroundColor(QColorConstants::Blue),
      mShapeColor(QColorConstants::White),
      mShape(ParametricShapes::Astroid()),
      mSettings(mShape.stepCount(), mShape.intervalLength(), mShape.scale())
{
    onShapeChanged();
}

void RenderArea::setBackgroundColor(QColor color)
{
    mBackgroundColor = color;
}

QColor RenderArea::backgroundColor() const
{
    return mBackgroundColor;
}

void RenderArea::setShapeColor(QColor color)
{
    mShapeColor = color;
}

QColor RenderArea::shapeColor() const
{
    return mShapeColor;
}

void RenderArea::setScale(float scale)
{
    mSettings.setScale(scale);
}

float RenderArea::scale() const
{
    return mSettings.scale();
}

void RenderArea::setInterval(float interval)
{
    mSettings.setIntervalLength(interval);
}

float RenderArea::interval() const
{
    return mSettings.intervalLength();
}

void RenderArea::setSteps(int steps)
{
    mSettings.setStepCount(steps);
}

int RenderArea::steps() const
{
    return mSettings.stepCount();
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
    onShapeChanged();
}

ParametricShape RenderArea::shape() const
{
    return mShape;
}

QPoint RenderArea::toPixel(QPointF pointF)
{
    auto center = this->rect().center();
    QPoint pixel;
    pixel.setX(pointF.x() * mSettings.scale() + center.x());
    pixel.setY(pointF.y() * mSettings.scale() + center.y());
    return pixel;
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);
    painter.drawRect(this->rect());

    auto interval = mSettings.intervalLength();
    auto stepCount = mSettings.stepCount();
    auto step = interval / stepCount;
    auto prev = toPixel(mShape.Compute(0));

    for (float t = step; t < interval; t += step)
    {
        auto pixel = toPixel(mShape.Compute(t));
        painter.drawLine(pixel, prev);
        prev = pixel;
    }

    painter.drawLine(toPixel(mShape.Compute(interval)), prev);
}

void RenderArea::onShapeChanged()
{
    mSettings = DrawSettings{mShape.stepCount(), mShape.intervalLength(), mShape.scale()};
}
