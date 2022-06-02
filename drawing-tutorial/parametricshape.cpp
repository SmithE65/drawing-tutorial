#include "parametricshape.h"

ParametricShape::ParametricShape(std::function<QPointF(float)> compute, DrawSettings settings) :
    mCompute(compute), mSettings(settings)
{

}

QPointF ParametricShape::Compute(float t) const
{
    return mCompute(t);
}

int ParametricShape::stepCount() const
{
    return mSettings.stepCount();
}

float ParametricShape::intervalLength() const
{
    return mSettings.intervalLength();
}

float ParametricShape::scale() const
{
    return mSettings.scale();
}
