#ifndef GSCALEANIMATIONBOX_H
#define GSCALEANIMATIONBOX_H

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
#include "gscaleanimation.h"

class GScaleAnimationBox : public QGroupBox
{
public:
    GScaleAnimationBox(QWidget *parent, GAttribute *attr, GScaleAnimation *animation = NULL);

    QLineEdit *getToWidthEdit() const;

    QLineEdit *getToHeightEdit() const;

    QLineEdit *getTimeEdit() const;

    QLineEdit *getDelayEdit() const;

private:
    QLineEdit *toWidthEdit;
    QLineEdit *toHeightEdit;
    QLineEdit *timeEdit;
    QLineEdit *delayEdit;
};

#endif // GSCALEANIMATIONBOX_H
