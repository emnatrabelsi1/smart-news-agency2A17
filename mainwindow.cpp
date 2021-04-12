#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "article.h"
#include"qmessagebox.h"
#include "QPainter"
#include "QPdfWriter"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"
#include"qsqlquery.h"
#include "qobject.h"
#include "qsqlerror.h"
#include"QIntValidator"
#include"qcoreapplication.h"
#include"qdebug.h"
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPropertyAnimation * animation = new QPropertyAnimation(ui->animation, "geometry");
        animation->setDuration(10000);
        animation->setLoopCount(-1);
        animation->setStartValue(QRect(-20, -125, 371, 400));
        animation->setEndValue(QRect(1050, -125, 371, 400));
        animation->start();
    click = new QMediaPlayer();
            click->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/projetqt/Atelier_Connexion/click.wav"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
        click->play();
        qDebug()<<click ->errorString();
        int id_Article = ui->le_ID->text().toInt();
        QString libelle_Article= ui->le_libelle->text();
        QString description_Article=ui->la_description->text();
        int nbre_page=ui->le_nbredepage->text().toInt();
        int priorite=ui->la_priorite->text().toInt();
        QString format=ui->le_format->text();

      Article a(id_Article,libelle_Article,description_Article,nbre_page,priorite,format);
      bool test=a.ajouter();
      if(test)
    {

    QMessageBox::information(nullptr, QObject::tr("Ajouter un article"),
                      QObject::tr("article ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_article->setModel(g->afficher());

    }
      else

          QMessageBox::critical(nullptr, QObject::tr("Ajouter un article"),
                      QObject::tr("Erreur !\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      ui->tab_article->setModel(g->afficher());
    }

void MainWindow::on_modifier_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_Article = ui->le_ID_2->text().toInt();
    QString libelle_Article= ui->le_libelle_2->text();
    QString description_Article=ui->la_description_2->text();
    int nbre_page=ui->le_nbredepage_2->text().toInt();
    int priorite=ui->la_priorite_2->text().toInt();
    QString format=ui->le_format_2->text();


          Article j(id_Article,libelle_Article,description_Article,nbre_page,priorite,format);

             bool test =j.modifier();

             if(test)

             {
                 QMessageBox::information(nullptr, QObject::tr("Modifier un article"),
                             QObject::tr("article modifiée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_article->setModel(g->afficher());

             }

             else

             {
                 QMessageBox::critical(nullptr, QObject::tr("modifier un article"),
                             QObject::tr("Erreur !\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_article->setModel(g->afficher());

             }
}

void MainWindow::on_supprimer_clicked()
{

    click->play();
    qDebug()<<click ->errorString();
    int id_Article = ui->le_ID_2->text().toInt();

        bool test=g->supprimer(id_Article);
        if(test)
        {
            ui->tab_article->setModel(g->afficher());

            QMessageBox::information(nullptr, QObject::tr("Supprimer un article"),
                        QObject::tr("article supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un article"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_article->setModel(g->afficher());
    }





void MainWindow::on_pushButton_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->tab_article->setModel(g->afficher());
}

void MainWindow::on_gestion_article_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_return_2_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_trier_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    bool test = t->tri_libelle();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des articles"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_article->setModel(t->tri_libelle());}//refresh
           else
           {QMessageBox::critical(nullptr, QObject::tr("tri des articles"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_article->setModel(t->tri_libelle());}//refresh
}

void MainWindow::on_recherche_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    QString libelle_Article= ui->libelle_rechercher->text();
    ui->resultat->setModel(r->rechercher(libelle_Article));
    ui->tab_article->setModel(g->afficher());
}

void MainWindow::on_pdf_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
        QPdfWriter pdf("C:/Users/Asus/Desktop/qt_pdf/pdf_article");
                                  QPainter painter(&pdf);
                                 int i = 4000;
                                      painter.setPen(Qt::red);
                                      painter.setFont(QFont("Arial", 30));
                                      painter.drawText(2300,1200,"Liste Des Articles");
                                      painter.setPen(Qt::black);
                                      painter.setFont(QFont("Arial", 50));
                                      //painter.drawText(1100,2000,afficheDC);
                                      painter.drawRect(1500,200,7300,2600);
                                      painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Asus/Desktop/qt_pdf/pdf_article"));
                                      painter.drawRect(0,3000,9600,500);
                                      painter.setFont(QFont("Arial", 9));
                                      painter.drawText(300,3300,"id_Article");
                                      painter.drawText(1800,3300,"libelle_Article");
                                      painter.drawText(3300,3300,"description_Article");
                                      painter.drawText(4800,3300,"nbre_page");
                                      painter.drawText(6300,3300,"priorite");
                                      painter.drawText(7800,3300,"format");




                                      QSqlQuery query;
                                      query.prepare("select * from article");
                                      query.exec();
                                      while (query.next())
                                      {
                                          painter.drawText(300,i,query.value(0).toString());
                                          painter.drawText(1800,i,query.value(1).toString());
                                          painter.drawText(3300,i,query.value(2).toString());
                                          painter.drawText(4800,i,query.value(3).toString());
                                          painter.drawText(6300,i,query.value(4).toString());
                                          painter.drawText(7800,i,query.value(5).toString());




                                         i = i +500;
                                      }
                                      qDebug()<<"le pdf a ete cree";
                                      QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
    }

void MainWindow::on_tab_article_activated(const QModelIndex &index)
{


        click->play();
        qDebug()<<click ->errorString();
        QString val=ui->tab_article->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select * from article where id_Article='"+val+"'or libelle_Article='"+val+"'or description_Article='"+val+"'or nbre_page='"+val+"'or priorite='"+val+"' or format='"+val+"'");

        if(query.exec())
        {

         while(query.next())
        {
                ui->le_ID_2->setText(query.value(0).toString());
                ui->le_libelle_2->setText(query.value(1).toString());
                ui->la_description_2->setText(query.value(2).toString());
                ui->le_nbredepage_2->setText(query.value(3).toString());
                ui->la_priorite_2->setText(query.value(4).toString());
                ui->le_format_2->setText(query.value(5).toString());

    }

      }
        else {
            QMessageBox::critical(nullptr, QObject::tr("article"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
       }



void MainWindow::on_gestion_categorie_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pb_ajouter_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_Categorie = ui->le_ID_5->text().toInt();
    QString libelle_Categorie= ui->le_libelle_5->text();
    QString description_Categorie=ui->la_description_5->text();
    QString type_Categorie=ui->le_type_5->text();

  Categorie c(id_Categorie,libelle_Categorie,description_Categorie,type_Categorie);
  bool test=c.ajouter_c();
  if(test)
{

QMessageBox::information(nullptr, QObject::tr("Ajouter une categorie"),
                  QObject::tr("categorie ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_categorie->setModel(d->afficher_c());

}
  else

      QMessageBox::critical(nullptr, QObject::tr("Ajouter une categorie"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tab_categorie->setModel(d->afficher_c());
}

void MainWindow::on_pushButton_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->tab_categorie->setModel(d->afficher_c());
}

void MainWindow::on_modifier_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_Categorie = ui->le_ID_6->text().toInt();
    QString libelle_Categorie= ui->le_libelle_6->text();
    QString description_Categorie=ui->la_description_6->text();
    QString type_Categorie=ui->le_type_6->text();


          Categorie e(id_Categorie,libelle_Categorie,description_Categorie,type_Categorie);

             bool test =e.modifier_c();

             if(test)

             {
                 QMessageBox::information(nullptr, QObject::tr("Modifier une categorie"),
                             QObject::tr("categorie modifiée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tab_categorie->setModel(d->afficher_c());

             }

             else

             {
                 QMessageBox::critical(nullptr, QObject::tr("modifier une categorie"),
                             QObject::tr("Erreur !\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_categorie->setModel(d->afficher_c());

             }
}

void MainWindow::on_supprimer_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    int id_Categorie = ui->le_ID_6->text().toInt();

        bool test=d->supprimer_c(id_Categorie);
        if(test)
        {
            ui->tab_categorie->setModel(d->afficher_c());

            QMessageBox::information(nullptr, QObject::tr("Supprimer une categorie"),
                        QObject::tr("article supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une categorie"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_categorie->setModel(d->afficher_c());

}

void MainWindow::on_trier_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    bool test = f->tri_libelle_c();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des categories"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_categorie->setModel(f->tri_libelle_c());}//refresh
           else
           {QMessageBox::critical(nullptr, QObject::tr("tri des categories"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_categorie->setModel(f->tri_libelle_c());}//refresh
}

void MainWindow::on_pdf_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
        QPdfWriter pdf("C:/Users/Asus/Desktop/qt_pdf/pdf_categorie");
                                  QPainter painter(&pdf);
                                 int i = 4000;
                                      painter.setPen(Qt::red);
                                      painter.setFont(QFont("Arial", 30));
                                      painter.drawText(2300,1200,"Liste Des categories");
                                      painter.setPen(Qt::black);
                                      painter.setFont(QFont("Arial", 50));
                                      //painter.drawText(1100,2000,afficheDC);
                                      painter.drawRect(1500,200,7300,2600);
                                      painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Asus/Desktop/qt_pdf/pdf_article"));
                                      painter.drawRect(0,3000,9600,500);
                                      painter.setFont(QFont("Arial", 9));
                                      painter.drawText(300,3300,"id_Categorie");
                                      painter.drawText(2800,3300,"libelle_Categorie");
                                      painter.drawText(5300,3300,"description_Categorie");
                                      painter.drawText(7800,3300,"type_Categorie");





                                      QSqlQuery query;
                                      query.prepare("select * from categorie");
                                      query.exec();
                                      while (query.next())
                                      {
                                          painter.drawText(300,i,query.value(0).toString());
                                          painter.drawText(2800,i,query.value(1).toString());
                                          painter.drawText(5300,i,query.value(2).toString());
                                          painter.drawText(7800,i,query.value(3).toString());




                                         i = i +500;
                                      }
                                      qDebug()<<"le pdf a ete cree";
                                      QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
    }

void MainWindow::on_recherche_3_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    QString libelle_Categorie= ui->libelle_rechercher_3->text();
    int id_Categorie= ui->ID_rechercher->text().toInt();
    ui->resultat_3->setModel(h->rechercher_c(libelle_Categorie,id_Categorie));
    ui->tab_categorie->setModel(d->afficher_c());
}

void MainWindow::on_tab_categorie_activated(const QModelIndex &index)
{
    click->play();
    qDebug()<<click ->errorString();
    QString val=ui->tab_categorie->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from categorie where id_Categorie='"+val+"'or libelle_Categorie='"+val+"'or description_Categorie='"+val+"'or type_Categorie='"+val+"'");

    if(query.exec())
    {

     while(query.next())
    {
            ui->le_ID_6->setText(query.value(0).toString());
            ui->le_libelle_6->setText(query.value(1).toString());
            ui->la_description_6->setText(query.value(2).toString());
            ui->le_type_6->setText(query.value(3).toString());

}

  }
    else {
        QMessageBox::critical(nullptr, QObject::tr("categorie"),
                    QObject::tr("Erreur !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_return_4_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_trier2_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    bool test = t->tri_id();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des articles"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_article->setModel(t->tri_id());}//refresh
           else
           {QMessageBox::critical(nullptr, QObject::tr("tri des articles"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_article->setModel(t->tri_id());}//refresh
}

void MainWindow::on_trier2_2_clicked()
{
    click->play();
    qDebug()<<click ->errorString();
    bool test = f->tri_id_c();
           if (test){
               QMessageBox::information(nullptr, QObject::tr("tri des categories"),
                           QObject::tr("succée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_categorie->setModel(f->tri_id_c());}//refresh
           else
           {QMessageBox::critical(nullptr, QObject::tr("tri des categories"),
                           QObject::tr("Erreur !\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_categorie->setModel(f->tri_id_c());}//refresh
}
