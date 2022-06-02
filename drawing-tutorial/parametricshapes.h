#ifndef PARAMETRICSHAPES_H
#define PARAMETRICSHAPES_H


#include "parametricshape.h"

class ParametricShapes
{
public:
    ParametricShapes() = delete;

    static ParametricShape Astroid();
    static ParametricShape Cycloid();
    static ParametricShape Huygens();
    static ParametricShape HypoCycloid();

private:
    static QPointF astroidCompute(float t);
    static QPointF cycloid(float t);
    static QPointF huygens(float t);
    static QPointF hypoCycloid(float t);
};

#endif // PARAMETRICSHAPES_H
