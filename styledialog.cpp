#include "styledialog.h"
#include "ui_styledialog.h"
#include "QDebug"

StyleDialog::StyleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StyleDialog)
{
    ui->setupUi(this);
}

StyleDialog::~StyleDialog()
{
    delete ui;
}

void StyleDialog::setStyleList(QList<QString> styleSheet)
{
    ui->textEdit->clear();
    QString style = "";
    foreach (QString s, styleSheet) {
        style += s + "\n";
    }
    ui->textEdit->setPlainText(style);
}


QList<QString> StyleDialog::getStyleList()
{
    return this->styleSheet;
}

QString StyleDialog::getStylePlainText()
{
    return ui->textEdit->toPlainText();
}

void StyleDialog::on_buttonBox_accepted()
{
    QString plainText = ui->textEdit->toPlainText();
    this->styleSheet = plainText.split("\n");
    qDebug()<<styleSheet;
}
