#ifndef GSTAGEDIALOG_H
#define GSTAGEDIALOG_H

#include <QDialog>
#include "QString"

namespace Ui {
class GStageDialog;
}

class GStageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GStageDialog(bool isAutoPlay);
    ~GStageDialog();

    bool getIsMusicAutoPlay() const;
    void setIsMusicAutoPlay(bool value);

    QString getBgm() const;
    void setBgm(const QString &value);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::GStageDialog *ui;

    bool isMusicAutoPlay;
    QString bgm;
};

#endif // GSTAGEDIALOG_H
