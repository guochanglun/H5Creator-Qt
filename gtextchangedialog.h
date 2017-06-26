#ifndef GTEXTCHANGEDIALOG_H
#define GTEXTCHANGEDIALOG_H

#include <QDialog>
#include "QString"

namespace Ui {
class GTextChangeDialog;
}

class GTextChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GTextChangeDialog(QString text);
    ~GTextChangeDialog();

    QString getText();

private:
    Ui::GTextChangeDialog *ui;
};

#endif // GTEXTCHANGEDIALOG_H
