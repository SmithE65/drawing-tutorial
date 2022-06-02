#include "renderarea.h"

#include <QPaintEvent>
#include <QPainter>
#include <QColor>

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent},
      mBackgroundColor(QColorConstants::Blue),
      mShapeColor(QColorConstants::White),
      mShape(Astroid)
{
    onShapeChanged();
}

void RenderArea::setBackgroundColor(QColor color)
{
    mBackgroundColor = color;
}

QSize RenderArea::sizeHint() const
{
    return QSize(400,200);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100,100);
}

void RenderArea::setShape(ShapeType shape)
{
    mShape = shape;
    onShapeChanged();
}

RenderArea::ShapeType RenderArea::shape() const
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
    auto step = mIntervalLength / mStepCount;

    for (float t = 0; t < mIntervalLength; t += step)
    {
        auto point = compute(t);
        QPoint pixel;
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());
        painter.drawPoint(pixel);
    }
}

void RenderArea::onShapeChanged()
{
    switch (mShape) {
    case Astroid:
        mScale = 40;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;
    case Cycloid:
        mScale = 4;
        mIntervalLength = 6 * M_PI;
        mStepCount = 128;
        break;
    case HuygensCycloid:
        mScale = 4;
        mIntervalLength = 4 * M_PI;
        mStepCount = 256;
        break;
    case HypoCycloid:
        mScale = 15;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;
        break;
    default:
        break;
    }
}

QPointF RenderArea::compute(float t)
{
    switch (mShape) {
    case Astroid:
        return computeAstroid(t);
        break;
    case Cycloid:
        return computeCycloid(t);
        break;
    case HuygensCycloid:
        return computeHuygens(t);
        break;
    case HypoCycloid:
        return computeHypoCycloid(t);
        break;
    default:
        return QPointF(0,0);
        break;
    }
}

QPointF RenderArea::computeAstroid(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF(x,y);
}

QPointF RenderArea::computeCycloid(float t)
{
    float x = 1.5 * (1 - cos(t));
    float y = 1.5 * (t - sin(t));
    return QPointF(x,y);
}

QPointF RenderArea::computeHuygens(float t)
{
    float x = 4 * (3 * cos(t) - cos(3 * t));
    float y = 4 * (3 * sin(t) - sin(3 * t));
    return QPointF(x,y);
}

QPointF RenderArea::computeHypoCycloid(float t)
{
    float x = 1.5 * (2 * cos(t) + cos(2 * t));
    float y = 1.5 * (2 * sin(t) - sin(2 * t));
    return QPointF(x,y);
}
