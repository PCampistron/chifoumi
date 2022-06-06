#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>

#define DATABASE_NAME "BD_Campistron_Lakartxela"
#define CONNECT_TYPE "QODBC"

class database
{
public:
    database();
    bool openDataBase();
    void closeDataBase();
    bool verifJoueurBD(QString, QString);

private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
