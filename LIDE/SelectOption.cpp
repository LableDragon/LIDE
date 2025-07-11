#include "SelectOption.h"

SelectOption::SelectOption(QWidget* parent)
	: QWidget(parent)
{
	applyDefaultTemplate(this);
}

SelectOption::~SelectOption()
{
	qDebug("This object was delete");
}