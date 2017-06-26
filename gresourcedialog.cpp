#include "gresourcedialog.h"
#include "ui_gresourcedialog.h"
#include "QPixmap"
#include "QIcon"
#include "QFileDialog"
#include "QFile"
#include "QDir"
#include "QFileInfoList"
#include "QFileInfo"
#include "QDebug"
#include "const.h"
#include "QString"
#include "QStringListModel"

GResourceDialog::GResourceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GResourceDialog)
{
    ui->setupUi(this);

    QPixmap addImage(":/icon/add_image");
    ui->btnAddImage->setIcon(QIcon(addImage));
    ui->btnAddImage->setIconSize(ui->btnAddImage->size());

    QPixmap addMusic(":/icon/add_music");
    ui->btnAddMusic->setIcon(QIcon(addMusic));
    ui->btnAddMusic->setIconSize(ui->btnAddMusic->size());

    this->refreshResources();
}

GResourceDialog::~GResourceDialog()
{
    delete ui;
}

QStringList GResourceDialog::getResources()
{
    QDir *res = new QDir(Const::APP_PATH + "/res");
    QFileInfoList infos = res->entryInfoList();

    QStringList fileList;

    for(int i = 0, size = infos.size(); i < size; i++){
        QString name = infos.at(i).fileName();
        if(name.size() < 3) continue;
        fileList<<infos.at(i).fileName();
    }

    return fileList;
}

void GResourceDialog::on_btnAddImage_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this, "选择要添加的图片");
    qDebug()<<Const::APP_PATH;
    for(int i = 0, size = files.size(); i < size; i++){
        this->copyResource(files.at(i));
    }

    this->refreshResources();
}

void GResourceDialog::on_btnAddMusic_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this, "选择要添加的音乐");
    for(int i = 0, size = files.size(); i < size; i++){
        this->copyResource(files.at(i));
    }
    this->refreshResources();
}

bool GResourceDialog::copyResource(QString sourceFile)
{
    QStringList l = sourceFile.split("/");
    QFile::copy(sourceFile, Const::APP_PATH + "/res/" + l.at(l.size() - 1));
}

void GResourceDialog::refreshResources(){
    QStringListModel *model = new QStringListModel(this->getResources());
    ui->resourceList->setModel(model);
}
