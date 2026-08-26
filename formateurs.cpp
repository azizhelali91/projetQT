#include "formateurs.h"
#include "qsqlquery.h"

// Constructeur par défaut
formateurs::formateurs()
{
    id_formateur = 0;
}

// Constructeur avec paramètres
formateurs::formateurs(int id_formateur,
                       QString nom,
                       QString prenom,
                       QString cin,
                       QString email,
                       QString telephone,
                       QString specialite,
                       QDate date_embauche)
{
    this->id_formateur = id_formateur;
    this->nom = nom;
    this->prenom = prenom;
    this->cin = cin;
    this->email = email;
    this->telephone = telephone;
    this->specialite = specialite;
    this->date_embauche = date_embauche;

}

// ==================== SETTERS ====================

void formateurs::setIdFormateur(int id)
{
    id_formateur = id;
}

void formateurs::setNom(QString nom)
{
    this->nom = nom;
}

void formateurs::setPrenom(QString prenom)
{
    this->prenom = prenom;
}

void formateurs::setCin(QString cin)
{
    this->cin = cin;
}

void formateurs::setEmail(QString email)
{
    this->email = email;
}

void formateurs::setTelephone(QString telephone)
{
    this->telephone = telephone;
}

void formateurs::setSpecialite(QString specialite)
{
    this->specialite = specialite;
}

void formateurs::setDateEmbauche(QDate date_embauche)
{
    this->date_embauche = date_embauche;
}



// ==================== GETTERS ====================

int formateurs::getIdFormateur()
{
    return id_formateur;
}

QString formateurs::getNom()
{
    return nom;
}

QString formateurs::getPrenom()
{
    return prenom;
}

QString formateurs::getCin()
{
    return cin;
}

QString formateurs::getEmail()
{
    return email;
}

QString formateurs::getTelephone()
{
    return telephone;
}

QString formateurs::getSpecialite()
{
    return specialite;
}

QDate formateurs::getDateEmbauche()
{
    return date_embauche;
}




//CRUD
bool formateurs::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO FORMATEURS (ID_FORMATEUR,NOM,PRENOM,CIN,EMAIL,TELEPHONE,SPECIALITE,DATE_EMBAUCHE)"
                  " VALUES (:id,:nom,:prenom,:cin,:email,:telephone,:specialite,:date_embauche) ");
    query.bindValue(":id",id_formateur);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
      query.bindValue(":cin",cin);
      query.bindValue(":email",email);
       query.bindValue(":telephone",telephone);
       query.bindValue(":specialite",specialite);
        query.bindValue(":date_embauche",date_embauche);


        bool test=query.exec();
       if(test==true)
            return true;
       else
           return false;


}
bool formateurs::modifier()
{

    {
        QSqlQuery query;
        query.prepare("UPDATE  FORMATEURS SET NOM=:nom,PRENOM=:prenom,CIN=:cin,EMAIL=:email,TELEPHONE=:telephone,SPECIALITE=:specialite,DATE_EMBAUCHE=:date_embauche"
                      " WHERE ID_FORMATEUR=:id"    );
        query.bindValue(":id",id_formateur);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":cin",cin);
        query.bindValue(":email",email);
        query.bindValue(":telephone",telephone);
        query.bindValue(":specialite",specialite);
        query.bindValue(":date_embauche",date_embauche);


        bool test=query.exec();
        if(test==true)
            return true;
        else
            return false;


    }
}
bool formateurs::supprimer(int id)
{
    QSqlQuery query;


    query.prepare("DELETE FROM FORMATEURS WHERE ID_FORMATEUR =:id");
    query.bindValue(":id",id);

    bool test=query.exec();
    if(test==true)
        return true;
    else
        return false;
}
QSqlQueryModel* formateurs::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FORMATEURS");
    return model;

}


bool formateurs::idExists(int id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FORMATEURS WHERE ID_FORMATEUR = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0; //true
    }

    return false;
}


QSqlQueryModel* formateurs::chercher(QString column, QString text)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FORMATEURS WHERE " + column + " LIKE '%" + text + "%'"); // NOM   LIKE  '%az%'  = az
    return model;
}

QSqlQueryModel* formateurs::tri(QString column, QString choix)//(SELECT * FROM FORMATEURS ORDER BY  nom ASC)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FORMATEURS ORDER BY " + column + " " + choix);
    return model;
}
