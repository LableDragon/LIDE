#include "LIDE.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LIDE window;
    window.show();
    return app.exec();
}
