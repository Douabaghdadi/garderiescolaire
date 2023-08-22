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

QString nom=ui->nom->text();
QString prenom=ui->prenom->text();
QString classe=ui->classe->text();
QString tel_parent=ui->tel_parent->text();
QDate d=ui->date->date();
QString pension=ui->pension->currentText();
float moyenne=ui->moyenne->text().toFloat();

QRegularExpression letterRegex("^[a-zA-Z]+$");
QRegularExpression numberRegex("^[0-9]+$");
if(!nom.contains(letterRegex))
{
    QMessageBox::information(this, tr("Erreur saisie"),
        tr("Le nom doit contenir que des lettres ."));
    return;
}

if(!prenom.contains(letterRegex))
{
    QMessageBox::information(this, tr("Erreur saisie"),
        tr("Le prenom doit contenir que des lettres ."));
    return;
}
if(!ui->moyenne->text().contains(numberRegex))
{
    QMessageBox::information(this, tr("Erreur saisie"),
        tr("La moyenne doit contenir que des chiffres ."));
    return;
}
if(!tel_parent.contains(numberRegex) || !(tel_parent.length()==8))
{
    QMessageBox::information(this, tr("Erreur saisie"),
        tr("Le num tel doit contenir que des chiffres et de longeur 8 ."));
    return;}
if (nom.isEmpty() || prenom.isEmpty()|| classe.isEmpty() || d.isNull() || tel_parent.isEmpty()) {
    QMessageBox::information(this, tr("Entrer tous les champs demandés"),
        tr("Entrer tous les valeurs."));
    return;
}
Eleve e(nom,prenom,classe,pension,tel_parent,d,moyenne);
bool test=e.ajouter();
if (test)
    {
ui->tableView->setModel(etmp.afficher());
        QMessageBox :: information (nullptr, QObject ::tr("OK"),
                     QObject ::tr("Ajout effectué\n"
                                  "click cancel to exit"),
                QMessageBox:: Cancel);
        std::string apiKey = "d2c5ddf4";
               std::string apiSecret = "bM0Z88a9OHbE9hDA";
               std::string fromNumber = "Vonage";
               std::string toNumber = ui->tel_parent->text().toStdString();
               std::string message = "Succes";

               SMS sms(apiKey, apiSecret, fromNumber);
               if (sms.sendSMS(toNumber, message)) {
                   printf("SMS sent successfully\n");
               }
               else {
                   printf("Failed to send SMS\n");
               }

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

    QString titre=ui->titre->text();
    QString description=ui->description->toPlainText();
    QString lieu=ui->lieu->text();
    QDate d=ui->date_A->date();
    QString type=ui->type->currentText();
    float prix=ui->prix->text().toFloat();
    QRegularExpression letterRegex("^[a-zA-Z]+$");
    QRegularExpression numberRegex("^[0-9]+$");
    if(!titre.contains(letterRegex))
    {
        QMessageBox::information(this, tr("Erreur saisie"),
            tr("Le titre doit contenir que des lettres ."));
        return;
    }
    if(!ui->prix->text().contains(numberRegex))
    {
        QMessageBox::information(this, tr("Erreur saisie"),
            tr("Le prix doit contenir que des chiffres ."));
        return;
    }
    Activite a ( titre, description, type, lieu, d, prix);
    if (titre.isEmpty() || description.isEmpty()|| lieu.isEmpty() || d.isNull() || type.isEmpty()) {
        QMessageBox::information(this, tr("Entrer tous les champs demandés"),
            tr("Entrer tous les valeurs."));
        return;
    }
    bool test=a.ajouter();
    if (test)
        {
    ui->tableView_2->setModel(atmp.afficher());
    ui->tableView_4->setModel(atmp.afficher());
            QMessageBox :: information (nullptr, QObject ::tr("OK"),
                         QObject ::tr("Ajout effectué\n"
                                      "click cancel to exit"),
                    QMessageBox:: Cancel);
            QSqlQueryModel *model=new QSqlQueryModel();
                        model = atmp.afficher();
                        int id = model->data(model->index(model->rowCount()-1,0)).toInt();
            test=a.ajouter_mod(id,"ajout",QDateTime::currentDateTime());
            ui->tableView_3->setModel(atmp.afficher_mod());


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
                        ui->tableView_4->setModel(atmp.afficher());
                        i=atmp.ajouter_mod(id_del,"Suppression",QDateTime::currentDateTime());
                        ui->tableView_3->setModel(atmp.afficher_mod());

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
                ui->tableView_4->setModel(atmp.afficher());
                 test=a.ajouter_mod(id_upt,"modification",QDateTime::currentDateTime());
                 ui->tableView_3->setModel(atmp.afficher_mod());


            }
            else
               { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("update failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel); }
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







void MainWindow::on_trier_A_clicked()
{
    QString tst;
               if (ui->radioButton_A->isChecked()) tst="ASC";
               else if (ui->radioButton_D->isChecked()) tst="DESC";

               switch (ui->comboBox_A->currentIndex()) {
               case 0:
                   ui->tableView_2->setModel(atmp.Tripartitre(tst));
                   break;
               case 1:
                   ui->tableView_2->setModel(atmp.TriDate(tst));
                   break;
               case 2:
                   ui->tableView_2->setModel(atmp.TriPrix(tst));
                   break;
               }
}

void MainWindow::on_pushButton_9_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT moyenne FROM eleve WHERE  moyenne>15 ");
           float counta=model->rowCount();
           model->setQuery("SELECT moyenne FROM eleve WHERE  moyenne<15 AND moyenne>10 ");
           float countc=model->rowCount();
           model->setQuery("SELECT moyenne FROM eleve WHERE  moyenne<10 ");
           float countp=model->rowCount();

           float total=counta+countp+countc;

                   QPieSeries *series = new QPieSeries();
                   series->append("Supérieur à 15",counta);
                   series->append("entre 15 et 10",countc);
                   series->append("inférieur à 10",countp);

                   if (counta!=0)
                   {QPieSlice *slice = series->slices().at(0);
                       slice->setLabel("Supérieur à 15 "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                       slice->setLabelVisible();
                       slice->setPen(QPen(Qt::black));}
                   if ( countc!=0)
                   {
                       // Add label, explode and define brush for 2nd slice
                       QPieSlice *slice1 = series->slices().at(1);
                       //slice1->setExploded();
                       slice1->setLabel("entre 15 et 10 "+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                       slice1->setLabelVisible();
                       slice1->setBrush(QColor(Qt::cyan));
                   }
                   if ( countp!=0)
                   {
                       // Add label, explode and define brush for 2nd slice
                       QPieSlice *slice1 = series->slices().at(2);
                       //slice1->setExploded();
                       slice1->setLabel("inférieur à 10 "+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                       slice1->setLabelVisible();
                       slice1->setBrush(QColor(Qt::red));
                   }


                   // Create the chart widget
                   QChart *chart = new QChart();
                   // Add data to chart with title and hide legend
                   chart->addSeries(series);
                   chart->setTitle("Totale eleves "+ QString::number(total));

                   // Used to display the chart
                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1000,500);


                   chart->legend()->hide();
                   chartView->show();
}

void MainWindow::on_pushButton_10_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT type FROM activite WHERE  type='Sport' ");
           float counta=model->rowCount();
           model->setQuery("SSELECT type FROM activite WHERE  type='Intellectuelle'");
           float countc=model->rowCount();
           model->setQuery("SELECT type FROM activite WHERE  type='Artistique'");
           float countp=model->rowCount();

           float total=counta+countp+countc;

                   QPieSeries *series = new QPieSeries();
                   series->append("Sport",counta);
                   series->append("Intellectuelle",countc);
                   series->append("Artistique",countp);

                   if (counta!=0)
                   {QPieSlice *slice = series->slices().at(0);
                       slice->setLabel("Sport "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                       slice->setLabelVisible();
                       slice->setPen(QPen(Qt::black));}
                   if ( countc!=0)
                   {
                       // Add label, explode and define brush for 2nd slice
                       QPieSlice *slice1 = series->slices().at(1);
                       //slice1->setExploded();
                       slice1->setLabel("Intellectuelle"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                       slice1->setLabelVisible();
                       slice1->setBrush(QColor(Qt::cyan));
                   }
                   if ( countp!=0)
                   {
                       // Add label, explode and define brush for 2nd slice
                       QPieSlice *slice1 = series->slices().at(2);
                       //slice1->setExploded();
                       slice1->setLabel("Artistique"+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                       slice1->setLabelVisible();
                       slice1->setBrush(QColor(Qt::red));
                   }


                   // Create the chart widget
                   QChart *chart = new QChart();
                   // Add data to chart with title and hide legend
                   chart->addSeries(series);
                   chart->setTitle("Totale Activités "+ QString::number(total));

                   // Used to display the chart
                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1000,500);


                   chart->legend()->hide();
                   chartView->show();
}

void MainWindow::on_search_textChanged(const QString &arg1)
{
    ui->tableView->setModel(etmp.recherche(arg1));
}

void MainWindow::on_search_A_textChanged(const QString &arg1)
{
    ui->tableView_2->setModel(atmp.recherche(arg1));
}

void MainWindow::on_pushButton_7_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);

                            const int rowCount = ui->tableView->model()->rowCount();
                            const int columnCount = ui->tableView->model()->columnCount();
                            QString TT = QDate::currentDate().toString("dd/MM/yyyy");
                            out <<"<html>\n"
                                  "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                << "<title>Liste eléves<title>\n "
                                << "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<h1 style=\"text-align: center;\"><strong>Liste eléves"+TT+"</strong></h1>"
                                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                  "</br> </br>";

                            out << "<thead><tr bgcolor=#d6e5ff>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tableView->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";


                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tableView->isColumnHidden(column)) {
                                        QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                    }
                                }
                                out << "</tr>\n";
                            }
                            out <<  "</table>\n"
                                "</body>\n"
                                "</html>\n";

                            QTextDocument *document = new QTextDocument();
                            document->setHtml(strStream);

                            QPrinter printer;

                            QPrintDialog *test = new QPrintDialog(&printer, NULL);
                            if (test->exec() == QDialog::Accepted) {
                                document->print(&printer);
                            }

                            delete document;
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int id_modif;
        id_modif=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
    ui->nom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),1)).toString());
    ui->prenom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),2)).toString());
    ui->date->setDate(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),3)).toDate());
    ui->classe->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString());
    ui->pension->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),5)).toString());
    ui->tel_parent->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),6)).toString());
    ui->moyenne->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),7)).toString());






}

void MainWindow::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    int id_modif;
        id_modif=ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0)).toInt();
    ui->titre->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),1)).toString());
    ui->description->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),2)).toString());
    ui->date_A->setDate(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),5)).toDate());
    ui->lieu->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),4)).toString());
    ui->type->setCurrentText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),3)).toString());
    ui->prix->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),6)).toString());

}

void MainWindow::on_pushButton_11_clicked()
{
    int id_eleve=ui->id_eleve_r->text().toInt();
    int id_act=ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->currentIndex().row(),0)).toInt();
    Reservation r(id_eleve,id_act,QDateTime::currentDateTime(),"non approuvée");
    bool test=r.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("Reservation successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tableView_5->setModel(rtmp.afficher());



    }
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("Reservation failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->tableView_4->setModel(atmp.afficher());
}

void MainWindow::on_pushButton_13_clicked()
{
    int id_r=ui->tableView_5->model()->data(ui->tableView_5->model()->index(ui->tableView_5->currentIndex().row(),0)).toInt();
    bool test=rtmp.modifier_e(id_r);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("Approuvée successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tableView_5->setModel(rtmp.afficher());



    }
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("Approuvée failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }
}



void MainWindow::on_pushButton_14_clicked()
{
    bool i;
            int id_del;
            id_del=ui->tableView_5->model()->data(ui->tableView_5->model()->index(ui->tableView_5->currentIndex().row(),0)).toInt();
            i=rtmp.supprimer(id_del);
         if(i)
                    {
                        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                    QObject::tr("delete successful.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

                        ui->tableView_5->setModel(rtmp.afficher());

                    }
                    else
                       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                    QObject::tr("delete failed.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_15_clicked()
{
    QString strStream;
                            QTextStream out(&strStream);

                            const int rowCount = ui->tableView_2->model()->rowCount();
                            const int columnCount = ui->tableView_2->model()->columnCount();
                            QString TT = QDate::currentDate().toString("dd/MM/yyyy");
                            out <<"<html>\n"
                                  "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                << "<title>Liste des activités<title>\n "
                                << "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<h1 style=\"text-align: center;\"><strong>Liste des activités"+TT+"</strong></h1>"
                                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                  "</br> </br>";

                            out << "<thead><tr bgcolor=#d6e5ff>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tableView_2->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";


                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tableView_2->isColumnHidden(column)) {
                                        QString data =ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                    }
                                }
                                out << "</tr>\n";
                            }
                            out <<  "</table>\n"
                                "</body>\n"
                                "</html>\n";

                            QTextDocument *document = new QTextDocument();
                            document->setHtml(strStream);

                            QPrinter printer;

                            QPrintDialog *test = new QPrintDialog(&printer, NULL);
                            if (test->exec() == QDialog::Accepted) {
                                document->print(&printer);
                            }

                            delete document;
}
