#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>
#include <QDateTime>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Equipement
{
public:
    Equipement();
    Equipement(int,QString,QString,QString,QDateTime,float);
    int getid_Equipement();
    void setid_Equipement(int);
    QString getlibelle();
    void getlibelle(QString);
    QString getdescription();
    void setdescription(QString);
    QString getmarque();
    void setmarque(QString);
    QDateTime getdate_acqui();
    void setdate_acqui(QDateTime);
    float getprix();
    void setprix(float);
    bool ajouter_Equipement();
    QSqlQueryModel * afficher_Equipement();
    bool supprimer_Equipement(int);



private:
    int id_Equipement;
    QString libelle;
    QString description;
    QString marque;
    QDateTime date_acqui;
    float prix;
    class ordinateurs;

};

#endif // EQUIPEMENT_H
