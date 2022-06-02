#include "parametricshapes.h"

ParametricShape ParametricShapes::Astroid()
{
    return ParametricShape(astroidCompute, DrawSettings{256,2 * M_PI,40});
}

ParametricShape ParametricShapes::Cycloid()
{
    return ParametricShape(cycloid, DrawSettings{128,6 * M_PI,4});
}

ParametricShape ParametricShapes::Huygens()
{
    return ParametricShape(huygens, DrawSettings{256,4 * M_PI,4});
}

ParametricShape ParametricShapes::HypoCycloid()
{
    return ParametricShape(hypoCycloid, DrawSettings{256,2 * M_PI,15});
}

QPointF ParametricShapes::astroidCompute(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF(x,y);
}

QPointF ParametricShapes::cycloid(float t)
{
    float x = 1.5 * (1 - cos(t));
    float y = 1.5 * (t - sin(t));
    return QPointF(x,y);
}

QPointF ParametricShapes::huygens(float t)
{
    float x = 4 * (3 * cos(t) - cos(3 * t));
    float y = 4 * (3 * sin(t) - sin(3 * t));
    return QPointF(x,y);
}

QPointF ParametricShapes::hypoCycloid(float t)
{
    float x = 1.5 * (2 * cos(t) + cos(2 * t));
    float y = 1.5 * (2 * sin(t) - sin(2 * t));
    return QPointF(x,y);
}
