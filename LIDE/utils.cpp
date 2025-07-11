#include "utils.h"
// 
static QMap<QString, QWidget*> windows;
static QMap<QString, std::function<QWidget* ()>> factories;

// Функция регистрирует новую фабрику (функция создания окна по id). Функция получает id приложения и лямбду с параметрами. Далее в карту по id добавляется значение лямбды
void registerWindowsFactory(const QString& id, std::function<QWidget* ()> factory) {
	factories[id] = factory;
}

// Функция открывает окно по id. windows хранит открытые окна.
void openWindowById(const QString& id, QWidget* parent) {
	if (windows.contains(id)) {
		QWidget* w = windows[id];
		w->raise();
		w->activateWindow();
		return;
	}

	if (!factories.contains(id)) {
		return;
	}

	QWidget* w = factories[id]();
	windows[id] = w;

	w->setAttribute(Qt::WA_DeleteOnClose);
	w->setWindowFlags(Qt::Window);
	w->resize(900, 900);
	w->show();

	QObject::connect(w, &QObject::destroyed, [id]() {
		windows.remove(id);
		});

}