#ifndef ATTRDIALOG_H
#define ATTRDIALOG_H

#include <QDialog>
#include "gattribute.h"

namespace Ui {
class AttrDialog;
}

class AttrDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AttrDialog(QWidget *parent = 0);
    AttrDialog(GAttribute *attr);
    ~AttrDialog();

    GAttribute *getAttr() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AttrDialog *ui;

    GAttribute *attr;
};

#endif // ATTRDIALOG_H
