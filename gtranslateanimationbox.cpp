#include "gtranslateanimationbox.h"
#include "QGroupBox"
#include "QVBoxLayout"
#include "QGridLayout"
#include "QPushButton"
#include "QLabel"
#include "const.h"
#include "QLineEdit"
#include "QValidator"
#include "QIntValidator"
#include "gattribute.h"
#include "QDebug"
#include "translateanimation.h"

GTranslateAnimationBox::GTranslateAnimationBox(QWidget *parent, GAttribute *attr, TranslateAnimation *animation): QGroupBox(parent)
{
    this->setObjectName("GTranslateAnimationBox");
    this->setTitle("Translate Animation");
    QVBoxLayout *layout = new QVBoxLayout();

    QIntValidator *validatorPercent = new QIntValidator(0, 100, this);
    QIntValidator *validatorTime = new QIntValidator(this);

    // add to text;
    QGridLayout *grid = new QGridLayout();

    QLabel *toTop = new QLabel("toTop(%)", this);
    this->toTopEdit = new QLineEdit(this);
    this->toTopEdit->setValidator(validatorPercent);
    grid->addWidget(toTop, 0, 0);
    grid->addWidget(toTopEdit, 0, 1);

    QLabel *toLeft = new QLabel("toLeft(%)", this);
    this->toLeftEdit = new QLineEdit(this);
    this->toLeftEdit->setValidator(validatorPercent);
    grid->addWidget(toLeft, 1, 0);
    grid->addWidget(toLeftEdit, 1, 1);

    QLabel *time = new QLabel("time(ms)", this);
    this->timeEdit = new QLineEdit(this);
    this->timeEdit->setValidator(validatorTime);
    grid->addWidget(time, 2, 0);
    grid->addWidget(timeEdit, 2, 1);

    QLabel *delay = new QLabel("delay(ms)", this);
    this->delayEdit = new QLineEdit(this);
    this->delayEdit->setValidator(validatorTime);
    grid->addWidget(delay, 3, 0);
    grid->addWidget(delayEdit, 3, 1);

    layout->addLayout(grid);

    // add delete button
    QPushButton *deleteButton = new QPushButton("delete", this);
    deleteButton->setStyleSheet("color: red");
    layout->addWidget(deleteButton);

    int maximumHeight = (toTop->height() + toTopEdit->height()) * 4 + deleteButton->height();
    this->setMaximumHeight(maximumHeight);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    // add delete connect
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteLater()));

    this->toTopEdit->setPlaceholderText(attr->getTop());
    this->toLeftEdit->setPlaceholderText(attr->getLeft());

    if(animation != NULL){
        toTopEdit->setText(animation->getToTop());
        toLeftEdit->setText(animation->getToLeft());
        timeEdit->setText(animation->getTime());
        delayEdit->setText(animation->getDelay());
    }

    this->setLayout(layout);
}

QLineEdit *GTranslateAnimationBox::getToTopEdit() const
{
    return toTopEdit;
}

QLineEdit *GTranslateAnimationBox::getToLeftEdit() const
{
    return toLeftEdit;
}

QLineEdit *GTranslateAnimationBox::getTimeEdit() const
{
    return timeEdit;
}

QLineEdit *GTranslateAnimationBox::getDelayEdit() const
{
    return delayEdit;
}
