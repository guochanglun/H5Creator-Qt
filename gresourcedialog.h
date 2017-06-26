#ifndef GRESOURCEDIALOG_H
#define GRESOURCEDIALOG_H

#include <QDialog>
#include "QString"
#include "QStringList"

namespace Ui {
class GResourceDialog;
}

class GResourceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GResourceDialog(QWidget *parent = 0);
    ~GResourceDialog();

    QStringList getResources();

private slots:
    void on_btnAddImage_clicked();

    void on_btnAddMusic_clicked();

private:
    Ui::GResourceDialog *ui;

    bool copyResource(QString sourceFile);

    void refreshResources();
};

#endif // GRESOURCEDIALOG_H
