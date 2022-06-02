#ifndef DRAWSETTINGS_H
#define DRAWSETTINGS_H

class DrawSettings
{
public:
    DrawSettings(int stepCount, float intervalLength, float scale);

    void setStepCount(int steps);
    int stepCount() const;

    void setIntervalLength(float interval);
    float intervalLength() const;

    void setScale(float scale);
    float scale() const;
private:
    int mStepCount;
    float mIntervalLength;
    float mScale;
};

#endif // DRAWSETTINGS_H
