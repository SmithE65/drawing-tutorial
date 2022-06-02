#ifndef RENDERAREA_H
#define RENDERAREA_H

#include "parametricshape.h"

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    void setBackgroundColor(QColor color);
    QColor backgroundColor() const;

    void setShapeColor(QColor color);
    QColor shapeColor() const;

    void setScale(float scale);
    float scale() const;

    void setInterval(float interval);
    float interval() const;

    void setSteps(int steps);
    int steps() const;

    void setShape(ParametricShape shape);
    ParametricShape shape() const;

    enum ShapeType { Astroid, Cycloid, HuygensCycloid, HypoCycloid };

signals:


    // QWidget interface
public:
    QSize sizeHint() const Q_DECL_OVERRIDE;
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    void onShapeChanged();
    QPoint toPixel(QPointF pointF);
    QColor mBackgroundColor;
    QColor mShapeColor;
    ParametricShape mShape;
    DrawSettings mSettings;
};

#endif // RENDERAREA_H
