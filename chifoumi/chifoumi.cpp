/***************************************************************
 * Name:      chifoumiMain.h
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe m�tier (= mod�le) Chifoumi-v1
 **************************************************************/
#include "chifoumi.h"

#include <cstdlib>
#include <ctime>

    ///* ---- PARTIE MOD�LE ---------------------------

Chifoumi::Chifoumi():
    scoreMax(5),
    scoreJoueur(0),
    scoreMachine(0),
    coupJoueur(rien),
    coupMachine(rien)
{
    //ctor
    // partie mod�le
}

Chifoumi::~Chifoumi()
{
    //dtor
}

string Chifoumi::getNomJoueur()
{
    return nomJoueur;
}

        /// Getters

Chifoumi::UnCoup Chifoumi::getCoupJoueur() {
    return coupJoueur;
}

Chifoumi::UnCoup Chifoumi::getCoupMachine() {
    return coupMachine;
}

unsigned int Chifoumi::getScoreMax()
{
    return scoreMax;
}

unsigned int Chifoumi::getScoreJoueur() {
    return scoreJoueur;
}

unsigned int Chifoumi::getScoreMachine() {
    return scoreMachine;
}

unsigned int Chifoumi::getTempsRestant()
{
    return tempsRestant;
}

unsigned int Chifoumi::getDureePartie()
{
    return dureePartie;
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

         ///* M�thodes utilitaires du Mod�le

int randMinMax(int min, int max){
    /* pr�-condition : min<max ;
       Le nbre al�atoire est compris entre [min, max[ */
   return rand()%(max-min) + min;
}

Chifoumi::UnCoup Chifoumi::genererUnCoup()
{
    UnCoup valeurGeneree;   // valeur � retourner

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

void Chifoumi::setNomJoueur(string nom)
{
    nomJoueur = nom;
}

void Chifoumi::setDureePartie(int duree)
{
    dureePartie = duree;
}

void Chifoumi::setScoreMax(int max)
{
    scoreMax = max;
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

void Chifoumi::initTemps()
{
    tempsRestant = dureePartie;
}

void Chifoumi::decTemps()
{
    tempsRestant = tempsRestant-1;
}
