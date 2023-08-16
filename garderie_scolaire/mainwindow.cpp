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
