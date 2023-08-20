#include "reservation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSystemTrayIcon>


Reservation::Reservation()
{

    id=0;
    id_eleve=0;
    id_activite=0;
    etat="";

}

Reservation::Reservation(int id,int id_eleve,int id_activite,QDateTime datee,QString etat)
{
    this->id=id;
    this->id_eleve=id_eleve;
    this->id_activite=id_activite;
    this->datee=datee;
    this->etat=etat;

}
Reservation::Reservation(int id_eleve,int id_activite,QDateTime datee,QString etat)
{

    this->id_eleve=id_eleve;
    this->id_activite=id_activite;
    this->datee=datee;
    this->etat=etat;

}


int Reservation::getId()
{
    return id;
}

int Reservation::getId_eleve()
{
    return id_eleve;
}

int Reservation::getId_activite()
{
    return id_activite;
}

QDateTime Reservation::getDatee()
{
    return datee;
}

QString Reservation::getEtat()
{
    return etat;
}

bool Reservation::ajouter()
{
    QSqlQuery query;
    QString id_eleve_s= QString::number(id_eleve);
     QString id_act_s= QString::number(id_activite);
          query.prepare("INSERT INTO Reservation (id_eleve,id_activite,datte,etat) "
                        "VALUES (:id_eleve, :id_activite, :datte, :etat)");

          query.bindValue(":id_eleve", id_eleve_s);
          query.bindValue(":id_activite", id_act_s);
          query.bindValue(":datte", datee);
          query.bindValue(":etat", etat);
          return query.exec();
}


QSqlQueryModel* Reservation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM Reservation");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_eleve"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_activite"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("datee"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
    return model;
}

bool Reservation::supprimer(int id)
    {
        QSqlQuery query;
        QString id_string=QString::number(id);
        query.prepare("delete from Reservation where id=:id");
        query.bindValue(":id",id);
        return query.exec();
    }

bool Reservation::modifier(int id)
{
    QSqlQuery query;
    //QString res=QString::number(id);
    query.prepare("UPDATE Reservation SET id_eleve=:id_eleve,id_activite=:id_activite,datee=:datee,etat=:etat, WHERE id=:id");
    query.bindValue(":id_eleve",id_eleve);
    query.bindValue(":id_activite",id_activite);
    query.bindValue(":datee",datee);
    query.bindValue(":etat",etat);
    query.bindValue(":id",id);

    return query.exec();
}
bool Reservation::modifier_e(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("UPDATE Reservation SET etat='approuvée' WHERE id=:id");

    query.bindValue(":id",res);

    return query.exec();
}
