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

    enum ShapeType { Astroid, Cycloid, HuygensCycloid, HypoCycloid };

signals:


    // QWidget interface
public:
    QSize sizeHint() const Q_DECL_OVERRIDE;
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;

    void setShape(ParametricShape shape);
    ParametricShape shape() const;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    void onShapeChanged();
    QColor mBackgroundColor;
    QColor mShapeColor;
    ParametricShape mShape;
};

#endif // RENDERAREA_H
