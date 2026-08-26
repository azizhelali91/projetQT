#include "mainwindow.h"
#include "qmessagebox.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //lors de l'execution ! ,  une seul fois ! ,
    ui->setupUi(this);

    //affichage
    ui->tableView_formateur->setModel(f.afficher());
    ui->tableView_cour->setModel(c.afficher());


    ui->embauche_formateur->setDate(QDate::currentDate());

    QIntValidator *intValidator = new QIntValidator(0, 100000000, this); // Only allows integers from 0 to 100000
    ui->id_formateur->setValidator(intValidator);
    ui->cin_formateur->setValidator(intValidator);
    ui->telephone_formateur->setValidator(intValidator);

    ui->id_cour->setValidator(intValidator);
    ui->prix_cour->setValidator(intValidator);


    QRegularExpression charRegex("[a-zA-Z]*");
    QRegularExpressionValidator* charValidator = new QRegularExpressionValidator(charRegex, this);
    ui->nom_formateur->setValidator(charValidator);
    ui->prenom_formateur->setValidator(charValidator);

    ui->nom_cour->setValidator(charValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_formateur_clicked()
{
//Etape1: récupération des donné d'apres ui !
    int id_formateur= ui->id_formateur->text().toInt();
    QString nom=ui->nom_formateur->text();
    QString prenom=ui->prenom_formateur->text();
    QString email=ui->email_formateur->text();
    QString cin=ui->cin_formateur->text();
    QString telephone=ui->telephone_formateur->text();
    QString specialite =ui->specialite_formateur->currentText();
    QDate embauche=ui->embauche_formateur->date();

//Etape2: controle de saisie


    if(f.idExists(id_formateur)==true)
    {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le id deja existe"), QMessageBox::Cancel);
        return;

    }

    // Create a QRegularExpression object for email validation
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");//aa@aa.aa
    // Check if the email is valid
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("L'adresse email est invalide"), QMessageBox::Cancel);
        return;
    }

    // Check if the telephone number has exactly 8 characters
    if (telephone.length() != 8) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le numéro de téléphone doit contenir 8 numéro"), QMessageBox::Cancel);
        return;
    }

    if (cin.length() != 8) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le cin doit contenir 8 numéro"), QMessageBox::Cancel);
        return;
    }


    if(nom==""||cin==""||prenom==""||email==""||telephone==""||id_formateur==0)
    {

        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Tu dois remplir tous les champs"), QMessageBox::Cancel);
        return;
    }

    if(QDate::currentDate()>embauche)    //19/08/2026 >15/08/2026
    {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Tu ne peut pas donner un date dans le passer"), QMessageBox::Cancel);
        return;
    }

//Etape3: appel du fonction ajout !

    formateurs f( id_formateur,
                nom,
                prenom,
                cin,
                email,
                telephone,
                specialite,
                embauche);

    bool  test= f.ajouter();

//Etape4:  affichage du message succés ou échoué

    if(test==true)
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                              QObject::tr("Ajout avec succées"), QMessageBox::Cancel);
        ui->tableView_formateur->setModel(f.afficher());

        ui->id_formateur->clear();
        ui->nom_formateur->clear();
        ui->prenom_formateur->clear();
        ui->email_formateur->clear();
        ui->cin_formateur->clear();
        ui->telephone_formateur->clear();
        ui->embauche_formateur->setDate(QDate::currentDate());


    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Ajout échoué"), QMessageBox::Cancel);
    }


}


void MainWindow::on_tableView_formateur_clicked(const QModelIndex &index)
{
    //etape1: numero du ligne ! clicked !
    QAbstractItemModel* model = ui->tableView_formateur->model();

    int row = index.row();
    //etape2:  table du format matrice , recuperation du donne
    QString id_formateur = model->data(model->index(row, 0)).toString();
    QString nom = model->data(model->index(row, 1)).toString();
    QString prenom = model->data(model->index(row, 2)).toString();
    QString cin = model->data(model->index(row, 3)).toString();
    QString email = model->data(model->index(row, 4)).toString();
    QString telephone = model->data(model->index(row, 5)).toString();
    QString specialite = model->data(model->index(row, 6)).toString();
    QDate embauche = model->data(model->index(row, 7)).toDate();

    //etape3: insertion dans ui  ( lineEdit , comboBox)

    ui->id_formateur->setText(id_formateur);
    ui->nom_formateur->setText(nom);
    ui->prenom_formateur->setText(prenom);
    ui->cin_formateur->setText(cin);
    ui->email_formateur->setText(email);
    ui->telephone_formateur->setText(telephone);
    ui->specialite_formateur->setCurrentText(specialite);
    ui->embauche_formateur->setDate(embauche);
}


void MainWindow::on_modifier_formateur_clicked()
{
    //Etape1: récupération des donné d'apres ui !
    int id_formateur= ui->id_formateur->text().toInt();
    QString nom=ui->nom_formateur->text();
    QString prenom=ui->prenom_formateur->text();
    QString email=ui->email_formateur->text();
    QString cin=ui->cin_formateur->text();
    QString telephone=ui->telephone_formateur->text();
    QString specialite =ui->specialite_formateur->currentText();
    QDate embauche=ui->embauche_formateur->date();

    //Etape2: controle de saisie


    if(f.idExists(id_formateur)==false)
    {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le id n'existe pas"), QMessageBox::Cancel);
        return;

    }

    // Create a QRegularExpression object for email validation
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");//aa@aa.aa
    // Check if the email is valid
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("L'adresse email est invalide"), QMessageBox::Cancel);
        return;
    }

    // Check if the telephone number has exactly 8 characters
    if (telephone.length() != 8) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le numéro de téléphone doit contenir 8 numéro"), QMessageBox::Cancel);
        return;
    }

    if (cin.length() != 8) {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le cin doit contenir 8 numéro"), QMessageBox::Cancel);
        return;
    }


    if(nom==""||cin==""||prenom==""||email==""||telephone==""||id_formateur==0)
    {

        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Tu dois remplir tous les champs"), QMessageBox::Cancel);
        return;
    }



    //Etape3: appel du fonction ajout !

    formateurs f( id_formateur,
                 nom,
                 prenom,
                 cin,
                 email,
                 telephone,
                 specialite,
                 embauche);

    bool  test= f.modifier();

    //Etape4:  affichage du message succés ou échoué

    if(test==true)
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Modification avec succées"), QMessageBox::Cancel);
        ui->tableView_formateur->setModel(f.afficher());

        ui->id_formateur->clear();
        ui->nom_formateur->clear();
        ui->prenom_formateur->clear();
        ui->email_formateur->clear();
        ui->cin_formateur->clear();
        ui->telephone_formateur->clear();
        ui->embauche_formateur->setDate(QDate::currentDate());


    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Modification échoué"), QMessageBox::Cancel);
    }

}


void MainWindow::on_supprimer_formateur_clicked()
{

    //récuperation d'apres ui
    int id_formateur= ui->id_formateur->text().toInt();

//controle de saisie
    if(f.idExists(id_formateur)==false)
    {
        QMessageBox::critical(nullptr, QObject::tr(""),
                              QObject::tr("Le id n'existe pas"), QMessageBox::Cancel);
        return;

    }
//action supprimer
    bool test= f.supprimer(id_formateur);
    //affichage du message
    if(test==true)
    {
        QMessageBox::information(nullptr, QObject::tr(""),
                                 QObject::tr("Suppression avec succées"), QMessageBox::Cancel);
        ui->tableView_formateur->setModel(f.afficher());

        ui->id_formateur->clear();
        ui->nom_formateur->clear();
        ui->prenom_formateur->clear();
        ui->email_formateur->clear();
        ui->cin_formateur->clear();
        ui->telephone_formateur->clear();
        ui->embauche_formateur->setDate(QDate::currentDate());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr(""),
                                 QObject::tr("Suppression échoué"), QMessageBox::Cancel);
    }
}


void MainWindow::on_tri_formateur_clicked()
{

    QString column=ui->choix_formateur->currentText();
    QString ordre=ui->ordre_formateur->currentText();
    ui->tableView_formateur->setModel(f.tri(column,ordre));
}


void MainWindow::on_recherche_formateur_clicked()
{
    QString text=ui->text_chercher_formateur->text();
    QString column=ui->choix_formateur->currentText();
    ui->tableView_formateur->setModel(f.chercher(column,text));

}

