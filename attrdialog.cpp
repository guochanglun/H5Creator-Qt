#include "attrdialog.h"
#include "ui_attrdialog.h"
#include "gattribute.h"
#include "QLineEdit"
#include "QIntValidator"

AttrDialog::AttrDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AttrDialog)
{
    ui->setupUi(this);
}

AttrDialog::AttrDialog(GAttribute *attr) :
    QDialog(0),
    ui(new Ui::AttrDialog)
{
    ui->setupUi(this);

    QIntValidator *validator = new QIntValidator(-100, 100, this);
    ui->topEdit->setValidator(validator);
    ui->leftEdit->setValidator(validator);
    ui->widthEdit->setValidator(validator);
    ui->heightEdit->setValidator(validator);

    ui->topEdit->setText(attr->getTop());
    ui->leftEdit->setText(attr->getLeft());
    ui->widthEdit->setText(attr->getWidth());
    ui->heightEdit->setText(attr->getHeight());
    if(attr->getIsHide()){
        ui->showhide->setCurrentIndex(1);
    }else{
        ui->showhide->setCurrentIndex(0);
    }
}

AttrDialog::~AttrDialog()
{
    delete ui;
}

void AttrDialog::on_buttonBox_accepted()
{
    this->attr = new GAttribute();
    attr->setHeight(ui->heightEdit->text());
    attr->setWidth(ui->widthEdit->text());
    attr->setTop(ui->topEdit->text());
    attr->setLeft(ui->leftEdit->text());

    if(ui->showhide->currentIndex() == 0){
        attr->setIsHide(false);
    }else{
        attr->setIsHide(true);
    }
}

GAttribute *AttrDialog::getAttr() const
{
    return attr;
}
