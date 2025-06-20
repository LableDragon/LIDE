#include "LIDE.h"

LIDE::LIDE(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Задний фон
    pal.setColor(QPalette::Window, QColor("#11171f"));

    // ---
    QWidget* centralWidget = new QWidget(this);
    textVLayout = new QVBoxLayout(centralWidget);
    textVLayout->addSpacing(100);

    greetLabel = new QLabel(
        "<span style='color: #ECECEC; font-size: 114px;'>"
        "<b>Hello, User!</b>"
        "</span>",
        this
    );

    greetLabel->setAlignment(Qt::AlignCenter);

    textVLayout->addWidget(greetLabel);
    centralWidget->setLayout(textVLayout);
    textVLayout->addStretch(1);

    this->setAutoFillBackground(true);
    this->setPalette(pal);

    this->resize(1200, 900);

    setCentralWidget(centralWidget);
}

LIDE::~LIDE()
{}

