#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
int id=ui->id->text().toInt();
QString nom=ui->nom->text();
QString prenom=ui->prenom->text();
QString classe=ui->classe->text();
QString tel_parent=ui->tel_parent->text();
QDate d=ui->date->date();
QString pension=ui->pension->currentText();
float moyenne=ui->moyenne->text().toFloat();
Eleve e(id,nom,prenom,classe,pension,tel_parent,d,moyenne);
bool test=e.ajouter();
if (test)
    {
ui->tableView->setModel(etmp.afficher());
        QMessageBox :: information (nullptr, QObject ::tr("OK"),
                     QObject ::tr("Ajout effectué\n"
                                  "click cancel to exit"),
                QMessageBox:: Cancel);

}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("try again.\n"
                                         "click cancel to exit."),QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    bool i;
            int id_del;
            id_del=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
            i=etmp.supprimer(id_del);
         if(i)
                    {
                        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                    QObject::tr("delete successful.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                        ui->tableView->setModel(etmp.afficher());

                    }
                    else
                       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                    QObject::tr("delete failed.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_pushButton_3_clicked()
{
    int id_upt=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString classe=ui->classe->text();
    QString tel_parent=ui->tel_parent->text();
    QDate d=ui->date->date();
    QString pension=ui->pension->currentText();
    float moyenne=ui->moyenne->text().toFloat();
    Eleve e(id_upt,nom,prenom,classe,pension,tel_parent,d,moyenne);



            bool test=e.modifier(id_upt);
            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("update successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView->setModel(etmp.afficher());

            }
            else
               { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("update failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel); }
}
