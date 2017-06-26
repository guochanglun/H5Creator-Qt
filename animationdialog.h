#ifndef ANIMATIONDIALOG_H
#define ANIMATIONDIALOG_H

#include <QDialog>
#include "ganimation.h"
#include "gattribute.h"

namespace Ui {
class AnimationDialog;
}

class AnimationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnimationDialog(QWidget *parent = 0);
    explicit AnimationDialog(QList<GAnimation*> animationList, GAttribute *attr);
    ~AnimationDialog();

    void setAnimationList(QList<GAnimation*> animationList);
    QList<GAnimation*> getAnimationList();

private slots:

    void on_translate_clicked();

    void on_scale_clicked();

    void on_showhide_clicked();

    void on_rotate_clicked();

    void on_buttonBox_accepted();

private:
    Ui::AnimationDialog *ui;

    QList<GAnimation*> animationList;

    GAttribute *attr;

};

#endif // ANIMATIONDIALOG_H
