#ifndef STYLEDIALOG_H
#define STYLEDIALOG_H

#include <QDialog>

namespace Ui {
class StyleDialog;
}

class StyleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StyleDialog(QWidget *parent = 0);
    ~StyleDialog();

    void setStyleList(QList<QString> styleSheet);
    QList<QString> getStyleList();
    QString getStylePlainText();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::StyleDialog *ui;
    QList<QString> styleSheet;
};

#endif // STYLEDIALOG_H
