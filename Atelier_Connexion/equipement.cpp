#include "equipement.h"

Equipement::Equipement()
{
    id_Equipement=0;
    libelle="";
    marque="";
    prix=0;
    description="";
}


Equipement::Equipement(int id,QString libelle,QString marque,QString description,QDateTime date,float prix)
{this->id_Equipement=id;
        this->libelle=libelle;
        this->marque=marque;
        this->date_acqui=date;
        this->description=description;
    this->prix=prix;}

int Equipement::getid_Equipement(){return id_Equipement;}
void Equipement::setid_Equipement(int id){this->id_Equipement=id;}
QString Equipement::getlibelle(){return libelle;}
void Equipement::getlibelle(QString libelle){this->libelle=libelle;}
QString Equipement::getdescription(){return description;}
void Equipement::setdescription(QString description){this->description=description;}
QString Equipement::getmarque(){return marque;}
void Equipement::setmarque(QString marque){this->marque=marque;}
QDateTime Equipement::getdate_acqui(){return date_acqui;}
void Equipement::setdate_acqui(QDateTime date){this->date_acqui=date;}
float Equipement::getprix(){return prix;}
void Equipement::setprix(float prix){this->prix=prix;}

bool Equipement::ajouter_Equipement()
{
    QSqlQuery query;
    QString res=QString::number(id_Equipement);

    query.prepare("insert into equipements (id_equipement,libelle, marque,description,date_acqui,prix) " "values(:id_equipement,:libelle,: marque,:description,:date_acqui,:prix)");

    query.bindValue(":id_Equipement",res);
    query.bindValue(":libelle",libelle);
    query.bindValue(":description",description);
    query.bindValue("marque",marque);
    query.bindValue("date_acqui",date_acqui);
    query.bindValue("prix",prix);
    return query.exec();
}

QSqlQueryModel * afficher_Equipement();
bool supprimer_Equipement(int);
