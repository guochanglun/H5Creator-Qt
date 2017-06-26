#include "gtextchangedialog.h"
#include "ui_gtextchangedialog.h"

GTextChangeDialog::GTextChangeDialog(QString text) :
    QDialog(0),
    ui(new Ui::GTextChangeDialog)
{
    ui->setupUi(this);
    ui->textEdit->setText(text);
}

GTextChangeDialog::~GTextChangeDialog()
{
    delete ui;
}

QString GTextChangeDialog::getText()
{
    return ui->textEdit->toPlainText();
}
