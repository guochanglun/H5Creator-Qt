#ifndef GPAGEOPTION_H
#define GPAGEOPTION_H

#include <QDialog>
#include "QString"

namespace Ui {
class GPageOption;
}

class GPageOption : public QDialog
{
    Q_OBJECT

public:
    explicit GPageOption(QWidget *parent = 0);
    ~GPageOption();

    QString getBgImage();
    QString getBgColor();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::GPageOption *ui;

};

#endif // GPAGEOPTION_H
