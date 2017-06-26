#ifndef GATTRIBUTE_H
#define GATTRIBUTE_H

#include "QString"

class GAttribute
{
public:
    GAttribute();

    QString getWidth() const;
    void setWidth(const QString &value);

    QString getHeight() const;
    void setHeight(const QString &value);

    bool getIsHide() const;
    void setIsHide(bool value);

    QString getTop() const;
    void setTop(const QString &value);

    QString getLeft() const;
    void setLeft(const QString &value);

private:
    QString width;
    QString height;
    bool isHide;

    QString top;
    QString left;
};

#endif // GATTRIBUTE_H
