#include <QPalette>
#include <QMap>
#include <QWidget>
#include <QObject>
#include <QDebug>

#ifndef UTILS_H
#define UTILS_H

void registerWindowsFactory(const QString& id, std::function<QWidget*()> factory);
void openWindowById(const QString& id, QWidget* parent = nullptr);

inline void applyDefaultTemplate(QWidget *widget) {
	QPalette pal;
	pal.setColor(QPalette::Window, QColor("#1e1e2f"));
	widget->setPalette(pal);
}



#endif // UTILS_H