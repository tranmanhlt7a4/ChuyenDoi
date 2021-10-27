#include <QApplication>
#include "CuaSoChinh.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    CuaSoChinh *cuaSo = new CuaSoChinh();
    cuaSo->show();

    return app.exec();
}
