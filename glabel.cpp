#include "glabel.h"
#include "QLabel"
#include "QTime"
#include "QDebug"
#include "const.h"
#include "QMouseEvent"
#include "gattribute.h"
#include "attrdialog.h"
#include "styledialog.h"
#include "QSizePolicy"
#include "animationdialog.h"
#include "gscaleanimation.h"
#include "gtextchangedialog.h"
#include "translateanimation.h"

GLabel::GLabel(QWidget *parent):QLabel(parent)
{
    this->setObjectName("text" + QTime::currentTime().toString("hh_mm_ss_zzz"));
    this->isSelect = false;

    this->popMenu = new QMenu();
    this->attrAction = new QAction(this);
    this->styleAction = new QAction(this);
    this->deleteAction = new QAction(this);
    this->animateAction = new QAction(this);
    this->changeAction = new QAction(this);

    this->attrAction->setText(tr("attribute"));
    this->styleAction->setText(tr("style"));
    this->deleteAction->setText(tr("delete"));
    this->animateAction->setText(tr("animation"));
    this->changeAction->setText("text");

    this->popMenu->addAction(this->attrAction);
    this->popMenu->addAction(this->changeAction);
    this->popMenu->addAction(this->styleAction);
    this->popMenu->addAction(this->animateAction);
    this->popMenu->addAction(this->deleteAction);

    connect(this->deleteAction, SIGNAL(triggered()), this, SLOT(deleteText()));
    connect(this->attrAction, SIGNAL(triggered()), this, SLOT(attrText()));
    connect(this->styleAction, SIGNAL(triggered()), this, SLOT(styleText()));
    connect(this->animateAction, SIGNAL(triggered()), this, SLOT(animateText()));
    connect(this->changeAction, SIGNAL(triggered()), this, SLOT(changeText()));

    this->setText("Haha, text");
    this->setStyleSheet("border: 1px dotted #666666; padding: 5px");
    this->adjustSize();
//    this->setWordWrap(true);

    this->attr = new GAttribute();
    int h = this->height() * 100 / Const::PHONE_HEIGHT;
    int w = this->width() * 100 / Const::PHONE_WIDTH;
    this->attr->setHeight(QString::number(h));
    this->attr->setWidth(QString::number(w));
    this->attr->setIsHide(this->isHide);
}

QString GLabel::getInitJson()
{
    QString style = "{";
    style += "\"type\":\"text\",";
    style += "\"id\":\"" + this->objectName() + "\",";
    style += "\"text\":\"" + this->text() + "\",";
    style += "\"style\": {";
    foreach (QString style, this->styleSheet) {
        QStringList lists = style.split(":");
        if(lists.size() != 2){
            continue;
        }
        style += "\""+ lists.at(0) +"\": \"" + lists.at(1) + "\",";
    }
    style += "\"position\":\"absolute\",";
    style += "\"top\":\"" + this->attr->getTop() + "%\",";
    style += "\"left\":\"" + this->attr->getLeft() + "%\",";
    style += "\"width\":\"" + this->attr->getWidth() + "%\",";
    style += "\"height\":\"" + this->attr->getHeight() + "%\"";
    style += "}}";

    return style;
}

QString GLabel::getAnimationJson()
{
    if(this->animationList.size() == 0) return "";

    QString animationStr = "";
    foreach (GAnimation* animation, this->animationList) {
        if(animation->getType() == "translate"){
            animationStr += static_cast<TranslateAnimation*>(animation)->animationCmd(this->objectName()) + ",";
        }else if(animation->getType() == "scale"){
            animationStr += static_cast<GScaleAnimation*>(animation)->animationCmd(this->objectName()) + ",";
        }
    }
    return animationStr;
}

void GLabel::mousePressEvent(QMouseEvent *ev){
    if(ev->button() == Qt::LeftButton){
        this->isSelect = true;
        this->offset = ev->globalPos() - this->pos();
    }
}

void GLabel::mouseMoveEvent(QMouseEvent *ev){
    if(this->isSelect){
        this->setCursor(QCursor(Qt::OpenHandCursor));
        this->move(ev->globalPos() - this->offset);

        this->top =(this->y() - Const::PHONE_Y) * 100 / Const::PHONE_HEIGHT;
        this->left = (this->x() - Const::PHONE_X) * 100 / Const::PHONE_WIDTH;

        this->attr->setTop(QString::number(this->top));
        this->attr->setLeft(QString::number(this->left));
    }
}

void GLabel::mouseReleaseEvent(QMouseEvent *ev){
    this->isSelect = false;
    this->setCursor(QCursor(Qt::ArrowCursor));
}

void GLabel::contextMenuEvent(QContextMenuEvent *ev){
    this->popMenu->exec(QCursor::pos());
    ev->accept();
}

void GLabel::deleteText(){
    Const::state->getCurrentPage().getElementMap()->remove(this->objectName());
    this->deleteLater();
}

void GLabel::attrText()
{
    AttrDialog dialog(this->attr);
    if(dialog.exec() == QDialog::Accepted){
        GAttribute *attr0 = dialog.getAttr();
        int width = attr0->getWidth().toInt();
        int height = attr0->getHeight().toInt();
        bool hide = attr0->getIsHide();

        this->isHide = hide;
        this->attr->setIsHide(this->isHide);

        if(width != 0 && height != 0){
            this->attr->setWidth(attr0->getWidth());
            this->attr->setHeight(attr0->getHeight());
            this->attr->setTop(attr0->getTop());
            this->attr->setLeft(attr0->getLeft());

            int w = this->attr->getWidth().toInt() * Const::PHONE_WIDTH / 100;
            int h = this->attr->getHeight().toInt() * Const::PHONE_HEIGHT / 100;

            int left = this->attr->getLeft().toInt() * Const::PHONE_WIDTH / 100 + Const::PHONE_X;
            int top = this->attr->getTop().toInt() * Const::PHONE_HEIGHT / 100 + Const::PHONE_Y;
            this->move(left, top);

            this->resize(w, h);
        }
    }
}

void GLabel::animateText()
{
    AnimationDialog dialog(this->animationList, this->attr);
    if(dialog.exec() == QDialog::Accepted){
        this->animationList = dialog.getAnimationList();
    }
}

void GLabel::styleText()
{
    StyleDialog dialog;
    dialog.setStyleList(this->styleSheet);
    if(dialog.exec() == QDialog::Accepted){
        this->styleSheet = dialog.getStyleList();
        //this->setStyleSheet(dialog.getStylePlainText());
    }
}

void GLabel::changeText()
{
    GTextChangeDialog dialog(this->text());
    if(dialog.exec() == QDialog::Accepted){
        if(dialog.getText().trimmed().size() != 0){
            this->setText(dialog.getText());
            this->adjustSize();

            // 重置宽高
            int h = this->height() * 100 / Const::PHONE_HEIGHT;
            int w = this->width() * 100 / Const::PHONE_WIDTH;
            this->attr->setHeight(QString::number(h));
            this->attr->setWidth(QString::number(w));
        }
    }
}
