#ifndef GSCALEANIMATION_H
#define GSCALEANIMATION_H

#include "ganimation.h"

class GScaleAnimation : public GAnimation
{
public:
    GScaleAnimation();

    QString getToWidth() const;
    void setToWidth(const QString &value);

    QString getToHeight() const;
    void setToHeight(const QString &value);

    QString animationCmd(QString id);

private:
    QString toWidth;
    QString toHeight;
};

#endif // GSCALEANIMATION_H
