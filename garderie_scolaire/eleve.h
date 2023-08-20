#ifndef ELEVE_H
#define ELEVE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
#include<vector>
class Eleve
{
public:
    Eleve();
    Eleve(int,QString,QString,QString,QString,QString,QDate,float);
    Eleve(QString,QString,QString,QString,QString,QDate,float);
    int getId();
    QString getNom();
    QString getPrenom();
    QString getClasse();
    QString getPension();
    QString getTel();
    QDate getDate();
    float getMoyenne();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* afficher();
     QSqlQueryModel * recherche(QString tst);
     QSqlQueryModel * Triparnom(QString tst);
    QSqlQueryModel * TriMoyenne(QString tst);
    QSqlQueryModel * TriClasse(QString tst);


private:
    int id;
    QString nom,prenom,classe,pension,tel_parent;
    QDate ddn;
    float moyenne;
};

#endif // ELEVE_H
