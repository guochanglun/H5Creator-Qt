#ifndef TRANSLATEANIMATION_H
#define TRANSLATEANIMATION_H

#include "ganimation.h"

class TranslateAnimation: public GAnimation
{
public:
    TranslateAnimation();

    QString getToTop() const;
    void setToTop(const QString &value);

    QString getToLeft() const;
    void setToLeft(const QString &value);

    QString animationCmd(QString id) const;
private:
    QString toTop;
    QString toLeft;
};

#endif // TRANSLATEANIMATION_H
