#ifndef CHIFOUMIPRESENTATION_H
#define CHIFOUMIPRESENTATION_H

#include <QObject>
#include "chifoumi.h"

class ChifoumiVue;

class chifoumiPresentation : public QObject
{
    Q_OBJECT
public:
    enum etatJeu {etatInitial, partieEnCours};
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
    void jouerCiseaux();
    void jouerFeuille();
    void jouerPierre();
    void initialiserPartie();
    void demanderPremiereMajInterface();
    void aProposDe();

private:
    bool etatBouton;
    Chifoumi *_modele;
    ChifoumiVue *_vue;
    etatJeu etat;
};

#endif // CHIFOUMIPRESENTATION_H
