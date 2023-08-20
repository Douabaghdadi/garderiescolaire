#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class Reservation
{
public:
    Reservation();
    Reservation(int,int,int,QDateTime,QString);
    Reservation(int,int,QDateTime,QString);
    int getId();
    int getId_eleve();
    int getId_activite();
    QDateTime getDatee();
    QString getEtat();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    bool modifier_e(int);
    QSqlQueryModel* afficher();

private:
    int id,id_eleve,id_activite;
    QDateTime datee;
    QString etat;
};

#endif // RESERVATION_H
