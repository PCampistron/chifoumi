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

    return verifOk;
}
