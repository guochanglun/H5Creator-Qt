#include "gpageoption.h"
#include "ui_gpageoption.h"
#include "gresourcedialog.h"
#include "const.h"
#include "QDebug"

GPageOption::GPageOption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GPageOption)
{
    ui->setupUi(this);
    GResourceDialog dialog(this);
    ui->bgiBox->addItems(dialog.getResources());
}

GPageOption::~GPageOption()
{
    delete ui;
}

QString GPageOption::getBgImage()
{
    return ui->bgiBox->currentText();
}

QString GPageOption::getBgColor()
{
    return ui->colorEdit->text();
}

void GPageOption::on_buttonBox_accepted()
{
//    Const::state->getCurrentPage().setBgColor(ui->colorEdit->text());
//    Const::state->getCurrentPage().setBgImage(ui->bgiBox->currentText());
}
