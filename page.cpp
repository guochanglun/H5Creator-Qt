#include "page.h"
#include "QMap"
#include "QList"
#include "gimage.h"
#include "QDebug"
#include "glabel.h"

Page::Page()
{
    this->elementMap = new QMap<QString, QObject*>();
    this->styleList = new QList<QString>();
}

QString Page::getJson() const
{
    QList<QString> keys = this->elementMap->keys();
    QList<QObject*> values = this->elementMap->values();

    QString json = "{";

    // init
    json += "\"init\":[";
    for(int i = 0; i<keys.size(); i++){
        QString objectName = keys.at(i);
        if(objectName.contains("image")){
            GImage *image = static_cast<GImage*>(values.at(i));
            json += image->getInitJson() + ",";
        }else if(objectName.contains("text")){
            GLabel *label = static_cast<GLabel*>(values.at(i));
            json += label->getInitJson() + ",";
        }
    }
    json += "],";

    // animation
    json += "\"animation\":[";

    for(int i = 0; i<keys.size(); i++){
        QString objectName = keys.at(i);
        if(objectName.contains("image")){
            GImage *image = static_cast<GImage*>(values.at(i));
            json += image->getAnimationJson();
        }else if(objectName.contains("text")){
            GLabel *label = static_cast<GLabel*>(values.at(i));
            json += label->getAnimationJson();
        }
    }

    if(keys.size() != 0){
        json = json.left(json.size() - 1) + "]";
    }else {
        json += "]";
    }

    json += "}";

    return json;
}

QMap<QString, QObject *> *Page::getElementMap() const
{
    return elementMap;
}

QString Page::getBgImage() const
{
    return bgImage;
}

void Page::setBgImage(const QString value)
{
    qDebug()<<value;
    this->bgImage = QString(value);
}

QString Page::getBgColor() const
{
    return bgColor;
}

void Page::setBgColor(const QString value)
{
    bgColor = value;
}
