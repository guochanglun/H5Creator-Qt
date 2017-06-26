#ifndef GTRANSLATEANIMATIONBOX_H
#define GTRANSLATEANIMATIONBOX_H

#include "QWidget"
#include "QGroupBox"
#include "translateanimation.h"
#include "QVBoxLayout"
#include "QGridLayout"
#include "QPushButton"
#include "QLabel"
#include "const.h"
#include "QLineEdit"
#include "gattribute.h"
#include "translateanimation.h"

class GTranslateAnimationBox : public QGroupBox
{
public:
    GTranslateAnimationBox(QWidget *parent, GAttribute *attr, TranslateAnimation *animation = NULL);

    QLineEdit *getToTopEdit() const;

    QLineEdit *getToLeftEdit() const;

    QLineEdit *getTimeEdit() const;

    QLineEdit *getDelayEdit() const;

private:
    QLineEdit *toTopEdit;
    QLineEdit *toLeftEdit;
    QLineEdit *timeEdit;
    QLineEdit *delayEdit;
};

#endif // GTRANSLATEANIMATIONBOX_H
