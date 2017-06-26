#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "page.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *e);
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    void showPage(Page page);
    void hidePage(Page page);

    bool copyResource(QString sourceDir ,QString toDir, bool coverFileIfExist);
    bool copyApp(const QString &fromDir, const QString &toDir, bool coverFileIfExist);

    bool newApp();
private slots:
    void on_actionDeletePage_triggered();
    void on_actionNextPage_triggered();
    void on_actionPrePave_triggered();
    void on_actionNewPage_triggered();
    void displayInfo(QObject *obj);
    void on_btnAddImg_clicked();
    void on_btnAddText_clicked();
    void on_outputAction_triggered();
    void on_actionOptions_triggered();
    void on_actionAddResources_triggered();
    void on_actionRun_triggered();
};

#endif // MAINWINDOW_H
