#include "activite.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSystemTrayIcon>


Activite::Activite()
{
    id=0;
    titre="";
    description="";
    type="";
    lieu="";
    prix=0;
}

Activite::Activite(int id,QString titre,QString description,QString type,QString lieu,QDate datte,float prix)
{
    this->id=id;
    this->titre=titre;
    this->description=description;
    this->type=type;
    this->lieu=lieu;
    this->datte=datte;
    this->prix=prix;

}

int Activite::getId()
{
    return id;
}

QString Activite::getTitre()
{
    return titre;
}

QString Activite::getDescription()
{
    return description;
}

QString Activite::getType()
{
    return type;
}

QString Activite::getLieu()
{
    return lieu;
}

QDate Activite::getDatte()
{
    return datte;
}

float Activite::getPrix()
{
    return prix;
}

bool Activite::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    QString prix_string= QString::number(prix);
          query.prepare("INSERT INTO Activite (id,titre,description,type,lieu,datte,prix) "
                        "VALUES (:id, :titre, :description, :type, :lieu, :datte, :prix)");
          query.bindValue(":id",id_string);
          query.bindValue(":titre", titre);
          query.bindValue(":description", description);
          query.bindValue(":type", type);
          query.bindValue(":lieu", lieu);
          query.bindValue(":datte",datte);
          query.bindValue(":prix",prix_string);
          return query.exec();
}

QSqlQueryModel* Activite::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM Activite");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieu"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("datte"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

bool Activite::supprimer(int id)
    {
        QSqlQuery query;
        QString id_string=QString::number(id);
        query.prepare("delete from Activite where id=:id");
        query.bindValue(":id",id);
        return query.exec();
    }

bool Activite::modifier(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
     QString prix_string= QString::number(prix);
    query.prepare("UPDATE Activite SET titre=:titre,description=:description,type=:type,lieu=:lieu,datte=:datte,prix=:prix WHERE id=:id");
    query.bindValue(":titre",titre);
    query.bindValue(":description",description);
    query.bindValue(":type",type);
    query.bindValue(":lieu",lieu);
    query.bindValue(":datte",datte);
    query.bindValue(":prix",prix_string);
    query.bindValue(":id",res);

    return query.exec();
}

QSqlQueryModel * Activite::recherche(QString tst)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Activite WHERE ( titre LIKE '%"+tst+"%' OR type LIKE '%"+tst+"%' OR lieu LIKE '%"+tst+"%' ) ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datte"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix"));
return model;
}

QSqlQueryModel * Activite::Tripartitre(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Activite ORDER BY titre  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datte"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

QSqlQueryModel * Activite::TriDate(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Activite ORDER BY datte  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datte"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

QSqlQueryModel * Activite::TriPrix(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Activite ORDER BY prix  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datte"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix"));

    return model;
}



