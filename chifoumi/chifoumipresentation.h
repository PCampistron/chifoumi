#ifndef CHIFOUMIPRESENTATION_H
#define CHIFOUMIPRESENTATION_H

#include <QObject>
#include <QTimer>
#include "configpartie.h"
#include "connexion.h"
#include "chifoumi.h"
#include "database.h"

class ChifoumiVue;

class chifoumiPresentation : public QObject
{
    Q_OBJECT
public:
    enum etatJeu {etatInitial, partieEnCours, pause};
    explicit chifoumiPresentation(Chifoumi *m, QObject *parent = nullptr);
    virtual ~chifoumiPresentation();
    Chifoumi* getModele();
    ChifoumiVue* getVue();
    void setModele(Chifoumi *m);
    void setVue(ChifoumiVue *v);
    void jouerSigne(char c);
    etatJeu getEtat();
    void setEtat(etatJeu);
    void testGagnant();

public slots:
    void demanderConnexion();
    void configurerPartie();
    void actionPause();
    void jouerCiseaux();
    void jouerFeuille();
    void jouerPierre();
    void initialiserPartie();
    void demanderPremiereMajInterface();
    void aProposDe();
    void tic();

private:
    QString username;
    QString mdp;
    bool connexionValide = false;
    database *db;
    QTimer *timer;
    const unsigned int intervalleTimer = 1000;
    bool etatBouton;
    Chifoumi *_modele;
    ChifoumiVue *_vue;
    etatJeu etat;
};

#endif // CHIFOUMIPRESENTATION_H
