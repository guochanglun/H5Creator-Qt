#ifndef GIMAGESRCDIALOG_H
#define GIMAGESRCDIALOG_H

#include <QDialog>
#include "QString"

namespace Ui {
class GImageSrcDialog;
}

class GImageSrcDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GImageSrcDialog(QWidget *parent = 0);
    ~GImageSrcDialog();

    QString getSrc();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::GImageSrcDialog *ui;

    QString src;
};

#endif // GIMAGESRCDIALOG_H
