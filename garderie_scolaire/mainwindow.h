#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "eleve.h"
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include "activite.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
Eleve etmp;
Activite atmp;
};

#endif // MAINWINDOW_H
