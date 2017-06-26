#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glabel.h"
#include "gimage.h"
#include "QPixmap"
#include "QDebug"
#include "QResizeEvent"
#include "const.h"
#include "page.h"
#include "state.h"
#include "QIcon"
#include "QDir"
#include "QFile"
#include "QMessageBox"
#include "QFileDialog"
#include "QSizePolicy"
#include "gresourcedialog.h"
#include "gpageoption.h"
#include "gstagedialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // init button
    QPixmap imgPixmap(":/icon/1201772");
    ui->btnAddImg->setIcon(QIcon(imgPixmap));
    ui->btnAddImg->setIconSize(ui->btnAddImg->size());

    QPixmap textPixmap(":/icon/1203030");
    ui->btnAddText->setIcon(QIcon(textPixmap));
    ui->btnAddText->setIconSize(ui->btnAddText->size());

    Const::PHONE_X = ui->phone->x();
    Const::PHONE_Y = ui->phone->y();

    Page page;
    Const::state->getPageList()->append(page);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *ev)
{
    int width = ui->frame->width();
    int height = ui->frame->height();
    int phoneWidth = ui->phone->width();
    int phoneHeight = ui->phone->height();
    ui->phone->setGeometry((width - phoneWidth) / 2, (height - phoneHeight) / 2, phoneWidth, phoneHeight);

    Const::PHONE_X = ui->phone->x();
    Const::PHONE_Y = ui->phone->y();

    Const::state->refreshAllPages();
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::displayInfo(QObject *obj){
    qDebug()<<obj;
}

void MainWindow::on_btnAddImg_clicked()
{
    // add Image
    GImage *image = new GImage(ui->frame);
    image->show();
    Const::state->getCurrentPage().getElementMap()->insert(image->objectName(), image);
}

void MainWindow::on_btnAddText_clicked()
{
    // add text
    GLabel *label = new GLabel(ui->frame);
    label->show();

    Const::state->getCurrentPage().getElementMap()->insert(label->objectName(), label);
}

void MainWindow::on_outputAction_triggered()
{
    QFile file(Const::APP_PATH + "/js/data.js");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream in(&file);
        in<<Const::state->jsonData();;
        file.close();
    }
}

void MainWindow::on_actionNewPage_triggered()
{
    this->hidePage(Const::state->getCurrentPage());

    Page page;
    Const::state->appendPage(page);
}

void MainWindow::showPage(Page page){
    QList<QObject*> objects = page.getElementMap()->values();
    for(int i = 0, size = objects.size(); i < size; i++){
        static_cast<QWidget*>(objects.at(i))->show();
    }
}

void MainWindow::hidePage(Page page){
    QList<QObject*> objects = page.getElementMap()->values();
    for(int i = 0, size = objects.size(); i < size; i++){
        static_cast<QWidget*>(objects.at(i))->hide();;
    }
}

bool MainWindow::copyResource(QString sourceDir, QString toDir, bool coverFileIfExist)
{
   toDir.replace("\\","/");
   if (sourceDir == toDir){
       return true;
   }
   if (!QFile::exists(sourceDir)){
       return false;
   }
   QDir *createfile = new QDir;
   bool exist = createfile->exists(toDir);
   if (exist){
       if(coverFileIfExist){
           createfile->remove(toDir);
       }
   }//end if

   if(!QFile::copy(sourceDir, toDir))
   {
       return false;
   }
   return true;
}

bool MainWindow::copyApp(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    if(!targetDir.exists()){    /**< 如果目标目录不存在，则进行创建 */
        if(!targetDir.mkdir(targetDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){    /**< 当为目录时，递归的进行copy */
            if(!this->copyApp(fileInfo.filePath(),
                targetDir.filePath(fileInfo.fileName()),
                coverFileIfExist))
                return false;
        }
        else{            /**< 当允许覆盖操作时，将旧文件进行删除操作 */
            if(coverFileIfExist && targetDir.exists(fileInfo.fileName())){
                targetDir.remove(fileInfo.fileName());
            }

            /// 进行文件copy
            if(!QFile::copy(fileInfo.filePath(),
                targetDir.filePath(fileInfo.fileName()))){
                    return false;
            }
        }
    }
    return true;
}

bool MainWindow::newApp()
{
    if(Const::APP_PATH.size() == 0){
        QString dirName = QFileDialog::getExistingDirectory(this, "新建工程");
        if(dirName.size() != 0){
            Const::APP_PATH = dirName;
            if(!this->copyApp("/home/gcl/桌面/H5Creator", dirName, true)){
                QMessageBox::warning(this, "错误", "创建工程出错");
                return false;
            }
        }
    }
    return true;
}

void MainWindow::on_actionPrePave_triggered()
{
    if(Const::state->hasPre()){
        this->hidePage(Const::state->getCurrentPage());
        Const::state->goPrePage();
        this->showPage(Const::state->getCurrentPage());
    }
}

void MainWindow::on_actionNextPage_triggered()
{
    if(Const::state->hasNext()){
        this->hidePage(Const::state->getCurrentPage());
        Const::state->goNextPage();
        this->showPage(Const::state->getCurrentPage());
    }
}

void MainWindow::on_actionDeletePage_triggered()
{
    this->hidePage(Const::state->getCurrentPage());
    Const::state->deletePage();
    this->showPage(Const::state->getCurrentPage());
}

void MainWindow::on_actionOptions_triggered()
{
//    GPageOption *option = new GPageOption(this);
//    option->exec();

//    Page page = Const::state->getCurrentPage();
//    page.setBgImage(option->getBgImage());
//    page.setBgColor(option->getBgColor());

//    QString image = page.getBgImage();

//    QPixmap bgImage(Const::APP_PATH + "/res/" + image);
//    ui->phone->setPixmap(bgImage.scaled(Const::PHONE_WIDTH, Const::PHONE_HEIGHT));


    if(!this->newApp()) return;
    GStageDialog dialog(Const::state->getIsMusicAutoPlay());
    if(dialog.exec() == QDialog::Accepted){
        Const::state->setBgm(dialog.getBgm());
        Const::state->setIsMusicAutoPlay(dialog.getIsMusicAutoPlay());
    }
}

void MainWindow::on_actionAddResources_triggered()
{
    if(!this->newApp()) return;

    GResourceDialog *resource = new GResourceDialog(this);
    resource->exec();
}

void MainWindow::on_actionRun_triggered()
{
}
