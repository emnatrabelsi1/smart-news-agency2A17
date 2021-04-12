#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "article.h"
#include "categorie.h"
#include "connection.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void on_pb_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_pushButton_clicked();

    void on_gestion_article_clicked();

    void on_return_2_clicked();

    void on_trier_clicked();

    void on_recherche_clicked();

    void on_pdf_clicked();

    void on_tab_article_activated(const QModelIndex &index);

    void on_gestion_categorie_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pushButton_3_clicked();

    void on_modifier_3_clicked();

    void on_supprimer_3_clicked();

    void on_trier_3_clicked();

    void on_pdf_3_clicked();

    void on_recherche_3_clicked();

    void on_tab_categorie_activated(const QModelIndex &index);

    void on_return_4_clicked();

    void on_trier2_clicked();

    void on_trier2_2_clicked();

private:
    Ui::MainWindow *ui;
    Article *g ;
    Article *r ;
    Article *t ;
    Article *j ;
    Categorie *d;
    Categorie *e;
    Categorie *f;
    Categorie *h;
    QMediaPlayer *click;
};
#endif // MAINWINDOW_H
