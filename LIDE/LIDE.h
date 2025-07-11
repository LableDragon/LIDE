#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LIDE.h"
#include "utils.h"
#include "CodeEditor.h"
#include "SelectOption.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QFile>
#include <QString>
#include <QTimer>

class LIDE : public QMainWindow
{
    Q_OBJECT

public:
    LIDE(QWidget *parent = nullptr);

    ~LIDE();

private:
    Ui::LIDEClass ui;

    // Переменные
    
    QVBoxLayout* mainLayout;
    QVBoxLayout* textVLayout;

    QString buttonStyle;

    QVBoxLayout* vert1;
    QVBoxLayout* vert2;
    QLabel* greetLabel;

    QGridLayout* buttonPos;
    QPushButton* createBut, *openBut, *moduleBut, *settingBut;


};

