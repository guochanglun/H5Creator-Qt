#ifndef GLABEL_H
#define GLABEL_H

#include <QLabel>
#include <QPoint>
#include <QMenu>
#include <QAction>
#include "gattribute.h"
#include "ganimation.h"

class GLabel : public QLabel
{
    Q_OBJECT

public:
    GLabel(QWidget *parent);

    QString getInitJson();
    QString getAnimationJson();

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void contextMenuEvent(QContextMenuEvent *ev);

private slots:
    void deleteText();
    void attrText();
    void animateText();
    void styleText();
    void changeText();

private:
    QPoint offset;
    bool isSelect;
    bool isHide = false;

    int top;
    int left;

    QMenu *popMenu;
    GAttribute *attr;

    QList<QString> styleSheet;
    QList<GAnimation*> animationList;

    QAction *changeAction;
    QAction *attrAction;
    QAction *styleAction;
    QAction *animateAction;
    QAction *deleteAction;
    QAction *srcAction;
};

#endif // GLABEL_H
