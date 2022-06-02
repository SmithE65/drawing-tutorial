#include "drawsettings.h"

DrawSettings::DrawSettings(int stepCount, float intervalLength, float scale) :
    mStepCount(stepCount), mIntervalLength(intervalLength), mScale(scale)
{

}

int DrawSettings::stepCount() const
{
    return mStepCount;
}

float DrawSettings::intervalLength() const
{
    return mIntervalLength;
}

float DrawSettings::scale() const
{
    return mScale;
}
