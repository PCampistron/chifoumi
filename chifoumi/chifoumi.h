/***************************************************************
 * Name:      chifoumiMain.h
 * Author:    P.Dagorret ()
 * Created:   2021-05-10
 * Description : classe m�tier (= Mod�le) Chifoumi-v1
 **************************************************************/
#ifndef CHIFOUMI_H
#define CHIFOUMI_H
#include <iostream>


using namespace std;

class Chifoumi
{
    ///* ---- PARTIE MOD�LE ---------------------------

        ///* Une d�finition de type �num�r�
    public:
        enum UnCoup {pierre, papier, ciseau, rien};

        ///* M�thodes du Mod�le
    public:
        Chifoumi();
        virtual ~Chifoumi();

        // Getters
        string getNomJoueur();

        UnCoup getCoupJoueur();
            /* retourne le dernier coup jou� par le joueur */
        UnCoup getCoupMachine();
            /* retourne le dernier coup jou� par le joueur */
        unsigned int getScoreMax();
            /* retourne le score max � atteindre */
        unsigned int getScoreJoueur();
            /* retourne le score du joueur */
        unsigned int getScoreMachine();
            /* retourne le score de la machine */
        unsigned int getTempsRestant();
            /* retourne le temps restant */
        unsigned int getDureePartie();
        char determinerGagnant();
            /* d�termine le gagnant 'J' pour joueur, 'M' pour machine, 'N' pour match nul
               en fonction du dernier coup jou� par chacun d'eux */

         ///* M�thodes utilitaires du Mod�le
    private :
        UnCoup genererUnCoup();
    /* retourne une valeur al�atoire = pierre, papier ou ciseau.
       Utilis�e pour faire jouer la machine */

        // Setters
    public:
        void setNomJoueur(string);

        void setDureePartie(int);

        void setScoreMax(int);

        void setCoupJoueur(UnCoup p_coup);
            /* initialise l'attribut coupJoueur avec la valeur
               du param�tre p_coup */
        void setCoupMachine(UnCoup p_coup);
             /* initialise l'attribut coupmachine avec la valeur
               du param�tre p_coup */
        void setScoreJoueur(unsigned int p_score);
            /* initialise l'attribut scoreJoueur avec la valeur
               du param�tre p_score */
        void setScoreMachine(unsigned int p_score);
             /* initialise l'attribut coupMachine avec la valeur
               du param�tre p_score */

        // Autres modificateurs
         void majScores(char p_gagnant);
			/* Mise � jour des scores en fonction des r�gles de gestion actuelles :
				- 1 point pour le gagnant lorsqu'il y a un gagnant
				- 0 point en cas de match nul
			*/

        void majCoupMachine();

        void initScores();
            /* initialise � 0 les attributs scoreJoueur et scoreMachine
               NON indispensable */
        void initCoups();
            /* initialise � rien les attributs coupJoueur et coupMachine
               NON indispensable */
        void initTemps();
            /* Initialise le temps � la dur�e d'une partie */
        void decTemps();
            /* D�cr�mente le temps restant */


        ///* Attributs du Mod�le
     private:
        string nomJoueur = "Vous";           // Nom du joueur
        unsigned int dureePartie = 30;   // Dur�e d'une partie
        unsigned int tempsRestant;  // Temps de la partie restante
        unsigned int scoreMax;      // Score max � atteindre pour finir la partie
        unsigned int scoreJoueur;   // score actuel du joueur
        unsigned int scoreMachine;  // score actuel de la Machine
        UnCoup coupJoueur;          // dernier coup jou� par le joueur
        UnCoup coupMachine;         // dernier coup jou� par la machine
};

#endif // CHIFOUMI_H
