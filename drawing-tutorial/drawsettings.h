#ifndef DRAWSETTINGS_H
#define DRAWSETTINGS_H

class DrawSettings
{
public:
    DrawSettings(int stepCount, float intervalLength, float scale);
    int stepCount() const;
    float intervalLength() const;
    float scale() const;
private:
    int mStepCount;
    float mIntervalLength;
    float mScale;
};

#endif // DRAWSETTINGS_H
