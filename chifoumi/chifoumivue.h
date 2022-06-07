#ifndef CHIFOUMIVUE_H
#define CHIFOUMIVUE_H

#include <QMainWindow>
#include <chifoumi.h>
#include "chifoumipresentation.h"
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class ChifoumiVue; }
QT_END_NAMESPACE

class ChifoumiVue : public QMainWindow
{
    Q_OBJECT

public:
    enum Joueur {humain, machine};
    ChifoumiVue(QWidget *parent = nullptr);
    ~ChifoumiVue();
    void nvlleConnexion(QObject *c);
    void supprConnexion(QObject *c);
    void changerCouleurNom(Joueur);
    void majInterface(Chifoumi::UnCoup, Chifoumi::UnCoup, string, int, int, int, int, chifoumiPresentation::etatJeu);

signals:
    void premiereMajInterface();

private:
    Ui::ChifoumiVue *ui;
    Chifoumi *_modele;
};
#endif // CHIFOUMIVUE_H
