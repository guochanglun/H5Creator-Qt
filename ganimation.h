#ifndef GANIMATION_H
#define GANIMATION_H

#include "QString"

class GAnimation
{
public:
    GAnimation();

    QString getId() const;
    void setId(const QString &value);

    QString getTime() const;
    void setTime(const QString &value);

    QString getDelay() const;
    void setDelay(const QString &value);

    QString getType() const;
    void setType(const QString &value);

    QString animationCmd(QString id) const;
private:
    QString id;
    QString time;
    QString delay;
    QString type;
};

#endif // GANIMATION_H
