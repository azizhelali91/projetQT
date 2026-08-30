#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "formateurs.h"
#include "cours.h"
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_ajouter_formateur_clicked();

    void on_tableView_formateur_clicked(const QModelIndex &index);

    void on_modifier_formateur_clicked();

    void on_supprimer_formateur_clicked();

    void on_tri_formateur_clicked();

    void on_recherche_formateur_clicked();

    void on_refresh_formateur_clicked();

    void remplir_comboBox_formateur();

    void on_ajouter_cour_clicked();

    void on_tableView_cour_clicked(const QModelIndex &index);

    void on_modifier_cour_clicked();

    void on_supprimer_cour_clicked();

    void on_tri_cour_clicked();

    void on_refresh_cour_clicked();

    void on_recherche_cour_clicked();

    void on_pdf_cour_clicked();

    void on_pdf_formateur_clicked();

    void on_stat_formateur_clicked();

    void on_statistique_cour_clicked();

private:
    Ui::MainWindow *ui;

    formateurs f;
    COURS c;

};
#endif // MAINWINDOW_H
