#pragma once

#include <QtWidgets/QMainWindow>
#include <QPalette>
#include "ui_LIDE.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>

class LIDE : public QMainWindow
{
    Q_OBJECT

public:
    LIDE(QWidget *parent = nullptr);
    ~LIDE();

private:
    Ui::LIDEClass ui;

    // Переменные
    QPalette pal;
    
    QVBoxLayout* textVLayout;

    QVBoxLayout* vert1;
    QVBoxLayout* vert2;
    QLabel* greetLabel;
};

