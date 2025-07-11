#pragma once
#include <QMainWindow>
#include "utils.h"
class CodeEditor : public QWidget
{
	Q_OBJECT

public:
	CodeEditor(QWidget *parent = nullptr);

	~CodeEditor();
};

