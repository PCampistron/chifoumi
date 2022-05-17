#include "chifoumivue.h"
#include "chifoumi.h"
#include "chifoumipresentation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChifoumiVue w;
    Chifoumi *c = new Chifoumi();
    chifoumiPresentation *p = new chifoumiPresentation(c);

    p->setVue(&w);

    w.nvlleConnexion(p);

    w.show();
    return a.exec();
}
