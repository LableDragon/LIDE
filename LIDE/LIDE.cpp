#include "LIDE.h"

LIDE::LIDE(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    for (QToolBar* tb : this->findChildren<QToolBar*>()) {
        this->removeToolBar(tb);
        delete tb;
    };

    this->setWindowTitle("LIDE");

    buttonStyle = R"(
        QPushButton {
            background-color: #131a24;
            border: 1px solid #4f46e5;
            border-radius: 10px;
            padding: 15px;
            font-size: 18px;
            color: #f4f4f5;
            
        }
        QPushButton:hover {
            background-color: #17202b;
            border: 2px solid #6366f1;
        }
    )";


    applyDefaultTemplate(this);

    // ---
    QWidget* centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    mainLayout = new QVBoxLayout(centralWidget);
    textVLayout = new QVBoxLayout();
    textVLayout->addSpacing(100);

    greetLabel = new QLabel(
        "<span style='color: #ECECEC; font-size: 114px;'>"
        "<b>Hello, User!</b>"
        "</span>",
        this
    );

    greetLabel->setAlignment(Qt::AlignCenter);

    this->setAutoFillBackground(true);

    buttonPos = new QGridLayout(this);
    createBut = new QPushButton("Create", this);
    openBut = new QPushButton("Open", this);
    moduleBut = new QPushButton("Modules", this);
    settingBut = new QPushButton("Settings", this); 

    createBut->setProperty("windowId", "Options");

    // Реализация OpenButton не продумана. До готовой идеи не раскомментировать!!!
    //openBut->setProperty("windowId", "Files");

    moduleBut->setProperty("windowId", "Modules");
    settingBut->setProperty("windowId", "Settings");

    createBut->setStyleSheet(buttonStyle);
    openBut->setStyleSheet(buttonStyle);
    moduleBut->setStyleSheet(buttonStyle);
    settingBut->setStyleSheet(buttonStyle);

    buttonPos->addWidget(createBut, 0, 0);
    buttonPos->addWidget(moduleBut, 0, 1);
    buttonPos->addWidget(openBut, 1, 0);
    buttonPos->addWidget(settingBut, 1, 1);

    buttonPos->setRowStretch(0, 1);
    buttonPos->setRowStretch(1, 1);
    buttonPos->setColumnStretch(0, 1);
    buttonPos->setColumnStretch(1, 1);

    buttonPos->setSpacing(10);
    buttonPos->setContentsMargins(20, 20, 20, 20);

    mainLayout->addWidget(greetLabel);
    mainLayout->addStretch(1);
    mainLayout->addLayout(buttonPos);
    mainLayout->addStretch(1);

    connect(createBut, &QPushButton::clicked, this, [=]() {
        registerWindowsFactory("Options", []() -> QWidget* {
            return new SelectOption();
        });

        openWindowById("Options");

    });

    centralWidget->setLayout(mainLayout);

    this->resize(1200, 900);
}

LIDE::~LIDE()
{}

