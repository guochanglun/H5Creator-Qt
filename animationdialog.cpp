#include "animationdialog.h"
#include "ui_animationdialog.h"
#include "QGroupBox"
#include "gtranslateanimationbox.h"
#include "ganimation.h"
#include "translateanimation.h"
#include "gscaleanimation.h"
#include "gscaleanimationbox.h"
#include "gattribute.h"
#include "const.h"
#include "QDebug"

AnimationDialog::AnimationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimationDialog)
{
    ui->setupUi(this);
}

AnimationDialog::AnimationDialog(QList<GAnimation*> animationList, GAttribute *attr) :
    QDialog(0),
    ui(new Ui::AnimationDialog)
{
    ui->setupUi(this);

    this->attr = attr;

    for(GAnimation *animation: animationList){
        if(animation->getType() == "translate"){
            TranslateAnimation *animation0 = static_cast<TranslateAnimation*>(animation);
            GTranslateAnimationBox *box = new GTranslateAnimationBox(this, attr, animation0);
            ui->scrollAreaWidgetContents->layout()->addWidget(box);
        }else if(animation->getType() == "scale"){
            GScaleAnimation *animation0 = static_cast<GScaleAnimation*>(animation);
            GScaleAnimationBox *box = new GScaleAnimationBox(this, attr, animation0);
            ui->scrollAreaWidgetContents->layout()->addWidget(box);
        }
    }
}

AnimationDialog::~AnimationDialog()
{
    delete ui;
}

void AnimationDialog::setAnimationList(QList<GAnimation *> animationList)
{
    this->animationList = animationList;
}

QList<GAnimation *> AnimationDialog::getAnimationList()
{
    return this->animationList;
}

void AnimationDialog::on_translate_clicked()
{
    GTranslateAnimationBox *box = new GTranslateAnimationBox(this, this->attr);
    ui->scrollAreaWidgetContents->layout()->addWidget(box);
}

void AnimationDialog::on_scale_clicked()
{
    GScaleAnimationBox *box = new GScaleAnimationBox(this, this->attr);
    ui->scrollAreaWidgetContents->layout()->addWidget(box);
}

void AnimationDialog::on_showhide_clicked()
{

}

void AnimationDialog::on_rotate_clicked()
{

}

void AnimationDialog::on_buttonBox_accepted()
{
    for(QObject *obj: ui->scrollAreaWidgetContents->children()){

        if(obj->objectName() == "GTranslateAnimationBox"){
            TranslateAnimation *animation = new TranslateAnimation();
            GTranslateAnimationBox *box = static_cast<GTranslateAnimationBox*>(obj);
            animation->setType("translate");
            animation->setId("");

            animation->setTime(box->getTimeEdit()->text());
            animation->setToLeft(box->getToLeftEdit()->text());
            animation->setToTop(box->getToTopEdit()->text());
            animation->setDelay(box->getDelayEdit()->text());
            this->animationList.append(animation);
        }else if(obj->objectName() == "GScaleAnimationBox"){
            GScaleAnimation *animation = new GScaleAnimation();
            GScaleAnimationBox *box = static_cast<GScaleAnimationBox*>(obj);
            animation->setType("scale");
            animation->setId("");

            animation->setTime(box->getTimeEdit()->text());
            animation->setToHeight(box->getToHeightEdit()->text());
            animation->setToWidth(box->getToWidthEdit()->text());
            animation->setDelay(box->getDelayEdit()->text());
            this->animationList.append(animation);
        }
    }
}
