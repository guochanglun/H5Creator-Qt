#include "ganimation.h"
#include "QDebug";
GAnimation::GAnimation()
{

}

void GAnimation::setType(const QString &value)
{
    type = value;
}

QString GAnimation::animationCmd(QString id) const
{
    return "";
}

QString GAnimation::getId() const
{
    return id;
}

void GAnimation::setId(const QString &value)
{
    id = value;
}

QString GAnimation::getTime() const
{
    return time;
}

void GAnimation::setTime(const QString &value)
{
    time = value;
}

QString GAnimation::getDelay() const
{
    return delay;
}

void GAnimation::setDelay(const QString &value)
{
    delay = value;
}

QString GAnimation::getType() const
{
    return type;
}
