#include "gstagedialog.h"
#include "ui_gstagedialog.h"
#include "QDir"
#include "const.h"
#include "QFileInfo"
#include "QStringListModel"

GStageDialog::GStageDialog(bool isAutoplay) :
    QDialog(0),
    ui(new Ui::GStageDialog)
{
    ui->setupUi(this);
    ui->autoplay->setChecked(isAutoplay);

    QDir *res = new QDir(Const::APP_PATH + "/res");
    QFileInfoList infos = res->entryInfoList();

    QStringList fileList;

    for(int i = 0, size = infos.size(); i < size; i++){
        QString name = infos.at(i).fileName();
        if(name.size() < 3) continue;
        fileList<<infos.at(i).fileName();
    }

    QStringListModel *model = new QStringListModel(fileList);
    ui->bgmBox->setModel(model);
}

GStageDialog::~GStageDialog()
{
    delete ui;
}

void GStageDialog::on_buttonBox_accepted()
{
    this->bgm = ui->bgmBox->currentText();
    this->isMusicAutoPlay = ui->autoplay->isChecked();
}

QString GStageDialog::getBgm() const
{
    return bgm;
}

void GStageDialog::setBgm(const QString &value)
{
    bgm = value;
}

bool GStageDialog::getIsMusicAutoPlay() const
{
    return isMusicAutoPlay;
}

void GStageDialog::setIsMusicAutoPlay(bool value)
{
    isMusicAutoPlay = value;
}
