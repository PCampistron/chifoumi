#include "chifoumivue.h"
#include "chifoumi.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChifoumiVue w;
    Chifoumi *c = new Chifoumi();

    w.setModele(c);

    w.show();
    return a.exec();
}
