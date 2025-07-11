#include "LIDE.h"
#include "CodeEditor.h"
#include <QFont>
#include <QFontDatabase>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int fontId = QFontDatabase::addApplicationFont(":/fonts/RobotoCondensed-Regular.ttf");
    if (fontId != -1) {
        QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
        qDebug() << "�������� �����:" << " " << family;
        QFont font(family, 11);
        QApplication::setFont(font);
    }
    else {
        qWarning("�� ������� ��������� ����� RobotoCondensed! ");
    }

    LIDE window;
    CodeEditor editorWindow;
    window.show();
    return app.exec();
}
