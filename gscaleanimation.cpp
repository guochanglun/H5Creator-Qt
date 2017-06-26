#include "gscaleanimation.h"

GScaleAnimation::GScaleAnimation()
{

}

QString GScaleAnimation::getToWidth() const
{
    return toWidth;
}

void GScaleAnimation::setToWidth(const QString &value)
{
    toWidth = value;
}

QString GScaleAnimation::getToHeight() const
{
    return toHeight;
}

void GScaleAnimation::setToHeight(const QString &value)
{
    toHeight = value;
}

QString GScaleAnimation::animationCmd(QString id)
{
    return QString("{\"type\": \"scale\",")
            + "\"id\": \"" + id + "\","
            + "\"toWidth\": \"" + this->getToWidth() + "%\","
            + "\"toheight\": \"" + this->getToHeight() + "%\","
            + "\"time\": " + this->getTime() + ","
            + "\"dalay\": " + this->getDelay() + ","
            + "\"isUse\": false}";
}
