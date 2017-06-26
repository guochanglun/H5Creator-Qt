#include "gattribute.h"

GAttribute::GAttribute()
{

}

QString GAttribute::getWidth() const
{
    return width;
}

void GAttribute::setWidth(const QString &value)
{
    width = value;
}

QString GAttribute::getHeight() const
{
    return height;
}

void GAttribute::setHeight(const QString &value)
{
    height = value;
}

bool GAttribute::getIsHide() const
{
    return isHide;
}

void GAttribute::setIsHide(bool value)
{
    isHide = value;
}

QString GAttribute::getTop() const
{
    return top;
}

void GAttribute::setTop(const QString &value)
{
    top = value;
}

QString GAttribute::getLeft() const
{
    return left;
}

void GAttribute::setLeft(const QString &value)
{
    left = value;
}
