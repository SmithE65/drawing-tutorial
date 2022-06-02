#ifndef PARAMETRICSHAPE_H
#define PARAMETRICSHAPE_H


#include "drawsettings.h"

#include <QPointF>
#include <functional>

class ParametricShape
{
public:
    ParametricShape(std::function<QPointF(float)> compute, DrawSettings settings);
    QPointF Compute(float t) const;
    int stepCount() const;
    float intervalLength() const;
    float scale() const;

private:
    std::function<QPointF(float)> mCompute;
    DrawSettings mSettings;
};

#endif // PARAMETRICSHAPE_H
