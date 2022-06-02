#include "drawsettings.h"

DrawSettings::DrawSettings(int stepCount, float intervalLength, float scale) :
    mStepCount(stepCount), mIntervalLength(intervalLength), mScale(scale)
{

}

void DrawSettings::setStepCount(int steps)
{
    mStepCount = steps;
}

int DrawSettings::stepCount() const
{
    return mStepCount;
}

void DrawSettings::setIntervalLength(float interval)
{
    mIntervalLength = interval;
}

float DrawSettings::intervalLength() const
{
    return mIntervalLength;
}

void DrawSettings::setScale(float scale)
{
    mScale = scale;
}

float DrawSettings::scale() const
{
    return mScale;
}
