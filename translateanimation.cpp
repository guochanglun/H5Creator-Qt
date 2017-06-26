#include "translateanimation.h"
#include "QDebug"

TranslateAnimation::TranslateAnimation()
{

}

QString TranslateAnimation::getToTop() const
{
    return toTop;
}

void TranslateAnimation::setToTop(const QString &value)
{
    toTop = value;
}

QString TranslateAnimation::getToLeft() const
{
    return toLeft;
}

void TranslateAnimation::setToLeft(const QString &value)
{
    toLeft = value;
}

QString TranslateAnimation::animationCmd(QString id) const
{
    return QString("{\"type\": \"translate\",") +
            + "\"id\": \"" + id + "\","
            + "\"toTop\": \"" + this->getToTop() + "%\","
            + "\"toLeft\": \"" + this->getToLeft() + "%\","
            + "\"time\": " + this->getTime() + ","
            + "\"dalay\": " + this->getDelay() + ","
            + "\"isUse\": false}";
}
