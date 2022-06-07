#include "database.h"
#include "QDebug"

database::database()
{

}

bool database::openDataBase()
{
    mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    mydb.setDatabaseName(DATABASE_NAME);

    if (mydb.open())
    {
        return true;
    }
    else return false;
}

void database::closeDataBase()
{
    mydb.close();
}

bool database::verifJoueurBD(QString username, QString mdp)
{
    bool bdOk;
    bool verifOk = false;

    bdOk = openDataBase();

    if(!bdOk)
    {
        qDebug() << "Erreur dans l'ouverture de la table." << Qt::endl;
    }
    else
    {
        QSqlQuery query;

        if(!query.exec("SELECT * FROM Joueur"))
        {
            qDebug() << "Erreur lors de la recherche" << Qt::endl;
        }

        for(unsigned int i = 0 ; query.next() ; i++)
        {
            if(username == query.value(0).toString() && mdp == query.value(1).toString())
            {
                verifOk = true;
            }
        }
    }

    closeDataBase();

    return verifOk;
}

bool database::insererScore(QString username, int scoreJoueur, int scoreMachine)
{
    bool bdOk;
    bool inserOk = false;

    bdOk = openDataBase();

    if(!bdOk)
    {
        qDebug() << "Erreur dans l'ouverture de la table." << Qt::endl;
    }
    else
    {
        QSqlQuery query;

        QString queryTxt = "INSERT INTO Scores (username, scoreJoueur, scoreMachine) VALUES ('";

        queryTxt.append(username);

        queryTxt.append("',");

        queryTxt.append(QString::number(scoreJoueur));

        queryTxt.append(",");

        queryTxt.append(QString::number(scoreMachine));

        queryTxt.append(");");

        qDebug() << queryTxt;

        if(!query.exec(queryTxt))
        {
            qDebug() << "Erreur lors de l'insertion" << Qt::endl;
        }
        else
        {
            inserOk = true;
        }
    }
    qDebug() << inserOk;

    closeDataBase();

    return inserOk;
}
