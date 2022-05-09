/***************************************************************
 * Name:      chifoumiMain.h
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe métier (= modèle) Chifoumi-v1
 **************************************************************/
#include "chifoumi.h"

#include <cstdlib>
#include <ctime>


    ///* ---- PARTIE MODèLE ---------------------------

Chifoumi::Chifoumi():
    scoreJoueur(0),
    scoreMachine(0),
    coupJoueur(rien),
    coupMachine(rien)
{
    //ctor
    // partie modèle
}

Chifoumi::~Chifoumi()
{
    //dtor
}

        /// Getters

Chifoumi::UnCoup Chifoumi::getCoupJoueur() {
    return coupJoueur;
}

Chifoumi::UnCoup Chifoumi::getCoupMachine() {
    return coupMachine;
}

unsigned int Chifoumi::getScoreJoueur() {
    return scoreJoueur;
}

unsigned int Chifoumi::getScoreMachine() {
    return scoreMachine;
}

char Chifoumi::determinerGagnant()
{
    char gagnantARetourner;

    if(getCoupJoueur() == getCoupMachine())
    {
        gagnantARetourner = 'N';
    }

    // Victoires pierre

    if(getCoupJoueur() == pierre && getCoupMachine() == ciseau)
    {
        gagnantARetourner = 'J';
    }

    if(getCoupMachine() == pierre && getCoupJoueur() == ciseau)
    {
        gagnantARetourner = 'M';
    }

    // Victoires papier

    if(getCoupJoueur() == papier && getCoupMachine() == pierre)
    {
        gagnantARetourner = 'J';
    }

    if(getCoupMachine() == papier && getCoupJoueur() == pierre)
    {
        gagnantARetourner = 'M';
    }

    // Victoire ciseau

    if(getCoupJoueur() == ciseau && getCoupMachine() == papier)
    {
        gagnantARetourner = 'J';
    }

    if(getCoupMachine() == ciseau && getCoupJoueur() == papier)
    {
        gagnantARetourner = 'M';
    }

    return gagnantARetourner;
}

         ///* Méthodes utilitaires du Modèle

int randMinMax(int min, int max){
    /* pré-condition : min<max ;
       Le nbre aléatoire est compris entre [min, max[ */
   return rand()%(max-min) + min;
}

Chifoumi::UnCoup Chifoumi::genererUnCoup()
{
    UnCoup valeurGeneree;   // valeur à retourner

    switch (randMinMax(1,4)) {
        case 1:
        valeurGeneree = pierre;
        break;

        case 2:
        valeurGeneree = papier;
        break;

        case 3:
        valeurGeneree = ciseau;
        break;

        default:
        valeurGeneree = rien;
        break;
    }
    return valeurGeneree;
}

        /// Setters

void Chifoumi::setCoupJoueur(UnCoup p_coup) {
    coupJoueur = p_coup;
}

void Chifoumi::setCoupMachine(UnCoup p_coup) {
    coupMachine = p_coup;
}

void Chifoumi::setScoreJoueur(unsigned int p_score) {
    scoreJoueur = p_score;
}

void Chifoumi::setScoreMachine(unsigned int p_score) {
    scoreMachine = p_score;
}

void Chifoumi::majScores(char p_gagnant) {
    if(p_gagnant != 'N')
    {
        if(p_gagnant == 'J')
        {
            scoreJoueur += 1;
        }
        if(p_gagnant == 'M')
        {
            scoreMachine += 1;
        }
    }
}

void Chifoumi::majCoupMachine()
{
    coupMachine = genererUnCoup();
}

void Chifoumi::initScores() {
    scoreJoueur = 0;
    scoreMachine = 0;
}

void Chifoumi::initCoups() {
    coupJoueur = rien;
    coupMachine = rien;
}
