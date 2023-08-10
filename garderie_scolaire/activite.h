#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class Activite
{
public:
    Activite();
    Activite(int,QString,QString,QString,QString,QDate,float);
    int getId();
    QString getTitre();
    QString getDescription();
    QString getType();
    QString getLieu();
    float getPrix();
    QDate getDatte();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* afficher();

private:
    int id;
    QString titre,description,type,lieu;
    float prix;
    QDate datte;
};

#endif // ACTIVITE_H
