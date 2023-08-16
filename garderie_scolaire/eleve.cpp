#include "eleve.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSystemTrayIcon>

Eleve::Eleve()
{
id=0;
nom="";
prenom="";
classe="";
pension="";
tel_parent="";
moyenne=0;
}

Eleve::Eleve(int id,QString nom,QString prenom,QString classe,QString pension,QString Tel,QDate D,float Moyenne)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->classe=classe;
    this->pension=pension;
    this->tel_parent=Tel;
    this->ddn=D;
    this->moyenne=Moyenne;
}

int Eleve::getId()
{
    return id;
}

QString Eleve::getNom()
{
    return nom;
}

QString Eleve::getPrenom()
{
    return prenom;
}

QString Eleve::getClasse()
{
    return classe;
}

QString Eleve::getPension()
{
    return pension;
}

QString Eleve::getTel()
{
    return tel_parent;
}

float Eleve::getMoyenne()
{
    return moyenne;
}

QDate Eleve::getDate()
{
    return ddn;
}

bool Eleve::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    QString m_string= QString::number(moyenne);
          query.prepare("INSERT INTO Eleve (id,nom,prenom,ddn,classe,pension,tel_parent,moyenne) "
                        "VALUES (:id, :nom, :prenom, :ddn, :classe, :pension, :tel_parent, :moyenne)");
          query.bindValue(":id",id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":ddn", ddn);
          query.bindValue(":classe", classe);
          query.bindValue(":pension",pension);
          query.bindValue(":tel_parent",tel_parent);
          query.bindValue(":moyenne",m_string);
          return query.exec();
}

QSqlQueryModel* Eleve::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM Eleve");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("ddn"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("pension"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel_parent"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("moyenne"));
    return model;
}

bool Eleve::supprimer(int id)
    {
        QSqlQuery query;
        QString id_string=QString::number(id);
        query.prepare("delete from Eleve where id=:id");
        query.bindValue(":id",id);
        return query.exec();
    }

bool Eleve::modifier(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString m_string= QString::number(moyenne);
    query.prepare("UPDATE ELeve SET nom=:nom,prenom=:prenom,ddn=:ddn,classe=:classe,pension=:pension,tel_parent=:tel_parent,moyenne=:moyenne WHERE id=:id");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":ddn",ddn);
    query.bindValue(":classe",classe);
    query.bindValue(":pension",pension);
    query.bindValue(":tel_parent",tel_parent);
    query.bindValue(":moyenne",m_string);
    query.bindValue(":id",res);

    return query.exec();
}

QSqlQueryModel * Eleve::recherche(QString tst)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve WHERE ( nom LIKE '%"+tst+"%' OR prenom LIKE '%"+tst+"%' OR classe LIKE '%"+tst+"%' ) ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ddn"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pension"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel_parent"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("moyenne"));
return model;
}

QSqlQueryModel * Eleve::Triparnom(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve ORDER BY nom  "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ddn"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pension"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel_parent"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("moyenne"));
    return model;
}

QSqlQueryModel * Eleve::TriClasse(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve ORDER BY classe "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ddn"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pension"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel_parent"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("moyenne"));

    return model;
}
QSqlQueryModel * Eleve::TriMoyenne(QString tst)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM eleve ORDER BY moyenne "+tst);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ddn"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("pension"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("tel_parent"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("moyenne"));

    return model;
}


