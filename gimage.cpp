#include "gimage.h"
#include "QLabel"
#include "QMouseEvent"
#include "QCursor"
#include "QAction"
#include "QDebug"
#include "const.h"
#include "QPixmap"
#include "QTime"
#include "attrdialog.h"
#include "styledialog.h"
#include "translateanimation.h"
#include "gscaleanimation.h"
#include "animationdialog.h"
#include "gimagesrcdialog.h"

GImage::GImage(QWidget *parent):QLabel(parent)
{

    this->setObjectName("image" + QTime::currentTime().toString("hh_mm_ss_zzz"));
    this->isSelect = false;

    this->popMenu = new QMenu();
    this->attrAction = new QAction(this);
    this->styleAction = new QAction(this);
    this->deleteAction = new QAction(this);
    this->animateAction = new QAction(this);
    this->srcAction = new QAction(this);

    this->attrAction->setText(tr("attribute"));
    this->styleAction->setText(tr("style"));
    this->deleteAction->setText(tr("delete"));
    this->animateAction->setText(tr("animation"));
    this->srcAction->setText(tr("src"));

    this->popMenu->addAction(this->attrAction);
    this->popMenu->addAction(this->srcAction);
    this->popMenu->addAction(this->styleAction);
    this->popMenu->addAction(this->animateAction);
    this->popMenu->addAction(this->deleteAction);

    connect(this->attrAction, SIGNAL(triggered()), this, SLOT(attrImage()));
    connect(this->styleAction, SIGNAL(triggered()), this, SLOT(styleImage()));
    connect(this->deleteAction, SIGNAL(triggered()), this, SLOT(deleteImage()));
    connect(this->animateAction, SIGNAL(triggered()), this, SLOT(animateImage()));
    connect(this->srcAction, SIGNAL(triggered()), this, SLOT(srcImage()));

    QPixmap pixmap(":/img/defaultImage");
    this->setPixmap(pixmap.scaled(Const::PHONE_WIDTH, 250));
    this->resize(Const::PHONE_WIDTH, 250);
    this->setStyleSheet("margin: 2px; border: 1px dotted #123456;");

    this->attr = new GAttribute();
    int h = this->height() * 100 / Const::PHONE_HEIGHT;
    int w = this->width() * 100 / Const::PHONE_WIDTH;
    this->attr->setHeight(QString::number(h));
    this->attr->setWidth(QString::number(w));
    this->attr->setIsHide(this->isHide);
}

GImage::~GImage(){
    //    qDebug()<<"destroy";
}

QString GImage::getInitJson()
{
    QString style = "{";
    style += "\"type\":\"image\",";
    style += "\"id\":\"" + this->objectName() + "\",";
    style += "\"src\":\"res/" + this->src + "\",";
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

QString GImage::getAnimationJson()
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

void GImage::mousePressEvent(QMouseEvent *ev){
    emit this->selected(this);

    if(ev->button() == Qt::LeftButton){
        this->isSelect = true;
        this->setCursor(QCursor(Qt::OpenHandCursor));
        this->offset = ev->globalPos() - this->pos();
    }
}

void GImage::mouseMoveEvent(QMouseEvent *ev){
    if(this->isSelect){
        this->move(ev->globalPos() - this->offset);
        this->top =(this->y() - Const::PHONE_Y) * 100 / Const::PHONE_HEIGHT;
        this->left = (this->x() - Const::PHONE_X) * 100 / Const::PHONE_WIDTH;

        this->attr->setTop(QString::number(this->top));
        this->attr->setLeft(QString::number(this->left));
    }
}

void GImage::mouseReleaseEvent(QMouseEvent *ev){
    this->isSelect = false;
    this->setCursor(QCursor(Qt::ArrowCursor));
}

void GImage::contextMenuEvent(QContextMenuEvent *ev){
    this->popMenu->exec(QCursor::pos());
    ev->accept();
}

void GImage::attrImage(){
    qDebug()<<"attrImage";
    AttrDialog dialog(this->attr);
    if(dialog.exec() == QDialog::Accepted){
        GAttribute *attr0 = dialog.getAttr();
        int width = attr0->getWidth().toInt();
        int height = attr0->getHeight().toInt();
        bool hide = attr0->getIsHide();
        if(width != 0 && height != 0){
            this->attr->setWidth(attr0->getWidth());
            this->attr->setHeight(attr0->getHeight());
            this->attr->setTop(attr0->getTop());
            this->attr->setLeft(attr0->getLeft());
            this->attr->setIsHide(hide);

            this->isHide = hide;

            int w = this->attr->getWidth().toInt() * Const::PHONE_WIDTH / 100;
            int h = this->attr->getHeight().toInt() * Const::PHONE_HEIGHT / 100;

            int left = this->attr->getLeft().toInt() * Const::PHONE_WIDTH / 100 + Const::PHONE_X;
            int top = this->attr->getTop().toInt() * Const::PHONE_HEIGHT / 100 + Const::PHONE_Y;

            this->move(left, top);

            this->resize(w, h);
        }
    }
}

void GImage::styleImage(){
    StyleDialog dialog;
    dialog.setStyleList(this->styleSheet);
    if(dialog.exec() == QDialog::Accepted){
        this->styleSheet = dialog.getStyleList();
        this->setStyleSheet(dialog.getStylePlainText());
    }
}

void GImage::deleteImage(){
    Const::state->getCurrentPage().getElementMap()->remove(this->objectName());
    this->deleteLater();
}

void GImage::animateImage()
{
    AnimationDialog dialog(this->animationList, this->attr);
    if(dialog.exec() == QDialog::Accepted){
        this->animationList = dialog.getAnimationList();
    }
}

void GImage::srcImage()
{
    GImageSrcDialog dialog;
    if(dialog.exec() == QDialog::Accepted){
        this->src = dialog.getSrc();
        QPixmap pixmap(Const::APP_PATH + "/res/" + this->src);
        this->setPixmap(pixmap.scaled(this->width(), this->height()));
    }
}

int GImage::getLeft() const
{
    return left;
}

void GImage::setLeft(int value)
{
    left = value;
}

int GImage::getTop() const
{
    return top;
}

void GImage::setTop(int value)
{
    top = value;
}
