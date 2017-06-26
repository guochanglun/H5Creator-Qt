#ifndef PAGE_H
#define PAGE_H

#include "QList"
#include "QMap"
#include "QString"

class Page
{
public:
    Page();

    QString getJson() const;
    QMap<QString, QObject *> *getElementMap() const;

    QString getBgImage() const;
    void setBgImage(const QString value);

    QString getBgColor() const;
    void setBgColor(const QString value);

private:
    QMap<QString, QObject*> *elementMap;
    QList<QString> *styleList;

    QString bgImage;
    QString bgColor;
};

#endif // PAGE_H
