#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "eleve.h"
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QtCharts>
#include "activite.h"
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>
#include"reservation.h"


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



    void on_pushButton_8_clicked();



    void on_trier_A_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_search_textChanged(const QString &arg1);

    void on_search_A_textChanged(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::MainWindow *ui;
Eleve etmp;
Activite atmp;
Reservation rtmp;
};

#endif // MAINWINDOW_H
