#ifndef GIMAGE_H
#define GIMAGE_H

#include <QLabel>
#include <QPoint>
#include <QMenu>
#include "QAction"
#include "QString"
#include "gattribute.h"
#include "ganimation.h"

class GImage : public QLabel
{
    Q_OBJECT

public:
    GImage(QWidget *parent);
    ~GImage();

    QString getInitJson();
    QString getAnimationJson();

    int getTop() const;
    void setTop(int value);

    int getLeft() const;
    void setLeft(int value);

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void contextMenuEvent(QContextMenuEvent *ev);

signals:
    void selected(QObject *obj);

private slots:
    void attrImage();
    void styleImage();
    void deleteImage();
    void animateImage();
    void srcImage();

private:
    QPoint offset;
    bool isSelect;
    bool isHide = false;

    int top;
    int left;

    QMenu *popMenu;
    GAttribute *attr;

    QString src;

    QList<QString> styleSheet;
    QList<GAnimation*> animationList;

    QAction *attrAction;
    QAction *styleAction;
    QAction *animateAction;
    QAction *deleteAction;
    QAction *srcAction;

};

#endif // GIMAGE_H
