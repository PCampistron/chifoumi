#include "chifoumipresentation.h"
#include "chifoumivue.h"
#include <QDebug>

chifoumiPresentation::chifoumiPresentation(Chifoumi *m, QObject *parent)
    : QObject(parent),
      _modele(m),
      etat(etatInitial)
{

}

chifoumiPresentation::~chifoumiPresentation() {
    delete this;
}

Chifoumi *chifoumiPresentation::getModele()
{
    return _modele;
}

ChifoumiVue *chifoumiPresentation::getVue()
{
    return _vue;
}

void chifoumiPresentation::setModele(Chifoumi *m)
{
    _modele = m;
}

void chifoumiPresentation::setVue(ChifoumiVue *v)
{
    _vue = v;
}

void chifoumiPresentation::jouerSigne(char c)
{
    switch (c) {
        case 'c':
            _modele->setCoupJoueur(_modele->ciseau);
            break;
        case 'f':
            _modele->setCoupJoueur(_modele->papier);
            break;
        case 'p':
            _modele->setCoupJoueur(_modele->pierre);
            break;
    }
    _modele->majCoupMachine();

    _modele->majScores(_modele->determinerGagnant());

    _vue->majInterface(_modele->getCoupJoueur(), _modele->getCoupMachine(), _modele->getScoreJoueur(), _modele->getScoreMachine(), getEtat());

    qDebug() << _modele->getScoreJoueur();
}

chifoumiPresentation::etatJeu chifoumiPresentation::getEtat()
{
    return etat;
}

void chifoumiPresentation::setEtat(chifoumiPresentation::etatJeu etatVoulu)
{
    etat = etatVoulu;
}

void chifoumiPresentation::jouerCiseaux()
{
    emit(jouerSigne('c'));
}

void chifoumiPresentation::jouerFeuille()
{
    emit(jouerSigne('f'));
}

void chifoumiPresentation::jouerPierre()
{
    emit(jouerSigne('p'));
}

void chifoumiPresentation::initialiserPartie()
{
    qDebug() << "Initialisation de la partie";

    _modele->initCoups();
    _modele->initScores();

    setEtat(partieEnCours);

    _vue->majInterface(_modele->getCoupJoueur(), _modele->getCoupMachine(), _modele->getScoreJoueur(), _modele->getScoreMachine(), getEtat());
}

