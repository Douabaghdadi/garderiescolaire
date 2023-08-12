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
if (nom.isEmpty() || prenom.isEmpty()|| classe.isEmpty() || d.isNull() || tel_parent.isEmpty()) {
    QMessageBox::information(this, tr("Entrer tous les champs demandés"),
        tr("Entrer tous les valeurs."));
    return;
}
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

void MainWindow::on_pushButton_4_clicked()
{
    int id=ui->id_A->text().toInt();
    QString titre=ui->titre->text();
    QString description=ui->description->toPlainText();
    QString lieu=ui->lieu->text();
    QDate d=ui->date_A->date();
    QString type=ui->type->currentText();
    float prix=ui->prix->text().toFloat();
    Activite a (id, titre, description, type, lieu, d, prix);
    if (titre.isEmpty() || description.isEmpty()|| lieu.isEmpty() || d.isNull() || type.isEmpty()) {
        QMessageBox::information(this, tr("Entrer tous les champs demandés"),
            tr("Entrer tous les valeurs."));
        return;
    }
    bool test=a.ajouter();
    if (test)
        {
    ui->tableView_2->setModel(atmp.afficher());
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

void MainWindow::on_pushButton_5_clicked()
{
    bool i;
            int id_del;
            id_del=ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0)).toInt();
            i=atmp.supprimer(id_del);
         if(i)
                    {
                        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                    QObject::tr("delete successful.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                        ui->tableView_2->setModel(atmp.afficher());

                    }
                    else
                       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                    QObject::tr("delete failed.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_6_clicked()
{
    int id_upt=ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0)).toInt();
    QString titre=ui->titre->text();
    QString description=ui->description->toPlainText();
    QString lieu=ui->lieu->text();
    QDate d=ui->date_A->date();
    QString type=ui->type->currentText();
    float prix=ui->prix->text().toFloat();

    Activite a(id_upt,titre, description, type, lieu, d, prix);



            bool test=a.modifier(id_upt);
            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("update successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_2->setModel(atmp.afficher());

            }
            else
               { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("update failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_pushButton_7_clicked()
{
    QString test=ui->search->text();
          if (test.isEmpty()) {
              QMessageBox::information(this, tr("Champ vide"),
                  tr("Entrer une valeur."));
              return;
          } else {
          ui->tableView->setModel(etmp.recherche(test));
          }
}

void MainWindow::on_pushButton_8_clicked()
{
    QString tst;
               if (ui->radioButtonA->isChecked()) tst="ASC";
               else if (ui->radioButtonD->isChecked()) tst="DESC";

               switch (ui->comboBox->currentIndex()) {
               case 0:
                   ui->tableView->setModel(etmp.Triparnom(tst));
                   break;
               case 1:
                   ui->tableView->setModel(etmp.TriClasse(tst));
                   break;
               case 2:
                   ui->tableView->setModel(etmp.TriMoyenne(tst));
                   break;
               }
}
