#include "gimagesrcdialog.h"
#include "ui_gimagesrcdialog.h"
#include "QDir"
#include "QStringList"
#include "QFileInfoList"
#include "QFileInfo"
#include "const.h"
#include "QStringListModel"

GImageSrcDialog::GImageSrcDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GImageSrcDialog)
{
    ui->setupUi(this);
    QDir *res = new QDir(Const::APP_PATH + "/res");
    QFileInfoList infos = res->entryInfoList();

    QStringList fileList;

    for(int i = 0, size = infos.size(); i < size; i++){
        QString name = infos.at(i).fileName();
        if(name.size() < 3) continue;
        fileList<<infos.at(i).fileName();
    }

    QStringListModel *model = new QStringListModel(fileList);
    ui->comboBox->setModel(model);
}

GImageSrcDialog::~GImageSrcDialog()
{
    delete ui;
}

QString GImageSrcDialog::getSrc()
{
    return this->src;
}

void GImageSrcDialog::on_buttonBox_accepted()
{
   this->src = ui->comboBox->currentText();
}
