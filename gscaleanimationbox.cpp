#include "gscaleanimationbox.h"
#include "QGroupBox"
#include "QVBoxLayout"
#include "QGridLayout"
#include "QPushButton"
#include "QLabel"
#include "const.h"
#include "QLineEdit"
#include "QIntValidator"
#include "gattribute.h"
#include "gscaleanimation.h"

GScaleAnimationBox::GScaleAnimationBox(QWidget *parent, GAttribute *attr, GScaleAnimation *animation): QGroupBox(parent)
{
    this->setObjectName("GScaleAnimationBox");
    this->setTitle("Scale Animation");
    QVBoxLayout *layout = new QVBoxLayout();

    QIntValidator *validator = new QIntValidator();

    // add to text;
    QGridLayout *grid = new QGridLayout();

    QLabel *toWidth = new QLabel("toWidth(%)", this);
    this->toWidthEdit = new QLineEdit(this);
    this->toWidthEdit->setValidator(validator);
    grid->addWidget(toWidth, 0, 0);
    grid->addWidget(toWidthEdit, 0, 1);

    QLabel *toHeight = new QLabel("toHeight(%)", this);
    this->toHeightEdit = new QLineEdit(this);
    this->toHeightEdit->setValidator(validator);
    grid->addWidget(toHeight, 1, 0);
    grid->addWidget(toHeightEdit, 1, 1);

    QLabel *time = new QLabel("time(ms)", this);
    this->timeEdit = new QLineEdit(this);
    this->timeEdit->setValidator(validator);
    grid->addWidget(time, 2, 0);
    grid->addWidget(timeEdit, 2, 1);

    QLabel *delay = new QLabel("delay(ms)", this);
    this->delayEdit = new QLineEdit(this);
    this->delayEdit->setValidator(validator);
    grid->addWidget(delay, 3, 0);
    grid->addWidget(delayEdit, 3, 1);

    this->toHeightEdit->setPlaceholderText(attr->getHeight());
    this->toWidthEdit->setPlaceholderText(attr->getWidth());

    layout->addLayout(grid);

    // add delete button
    QPushButton *deleteButton = new QPushButton("delete", this);
    deleteButton->setStyleSheet("color: red");
    layout->addWidget(deleteButton);

    int maximumHeight = (toHeight->height() + toHeightEdit->height()) * 4 + deleteButton->height();
    this->setMaximumHeight(maximumHeight);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    // add delete connect
    connect(deleteButton, &QPushButton::clicked, this, &GScaleAnimationBox::deleteLater);

    if(animation != NULL){
        toWidthEdit->setText(animation->getToWidth());
        toHeightEdit->setText(animation->getToHeight());
        timeEdit->setText(animation->getTime());
        delayEdit->setText(animation->getDelay());
    }

    this->setLayout(layout);
}

QLineEdit *GScaleAnimationBox::getToWidthEdit() const
{
    return toWidthEdit;
}

QLineEdit *GScaleAnimationBox::getToHeightEdit() const
{
    return toHeightEdit;
}

QLineEdit *GScaleAnimationBox::getTimeEdit() const
{
    return timeEdit;
}

QLineEdit *GScaleAnimationBox::getDelayEdit() const
{
    return delayEdit;
}
