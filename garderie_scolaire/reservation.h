#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class Reservation
{
public:
    Reservation();
    Reservation(int,int,int,QDate,QString);
    int getId();
    int getId_eleve();
    int getId_activite();
    QDate getDatee();
    QString getEtat();
    bool ajouter();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* afficher();

private:
    int id,id_eleve,id_activite;
    QDate datee;
    QString etat;
};

#endif // RESERVATION_H
