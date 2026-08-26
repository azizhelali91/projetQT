#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"
#include <QObject>


Connexion::Connexion()
{

}

bool Connexion::createconnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projetcnx");
    db.setUserName("SYSTEM");//projetcnx nom de l'utilisateur
    db.setPassword("azizboxesavate");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;
    return  test;
}

void Connexion::fermerConnexion()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.close();
}
