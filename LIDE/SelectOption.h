#pragma once
#include <QWidget>
#include "utils.h"
class SelectOption :public QWidget
{
	Q_OBJECT

public:
	SelectOption(QWidget *parent = nullptr);

	~SelectOption();
};

