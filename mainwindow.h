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

private:
    Ui::MainWindow *ui;

    formateurs f;
    COURS c;

};
#endif // MAINWINDOW_H
