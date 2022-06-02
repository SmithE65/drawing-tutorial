#ifndef RENDERAREA_H
#define RENDERAREA_H

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

    void setShape(ShapeType shape);
    ShapeType shape() const;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    void onShapeChanged();
    QPointF compute(float t);
    QPointF computeAstroid(float t);
    QPointF computeCycloid(float t);
    QPointF computeHuygens(float t);
    QPointF computeHypoCycloid(float t);

    int mStepCount;
    float mIntervalLength;
    float mScale;
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;
};

#endif // RENDERAREA_H
