#include "utils.h"
// 
static QMap<QString, QWidget*> windows;
static QMap<QString, std::function<QWidget* ()>> factories;

// ������� ������������ ����� ������� (������� �������� ���� �� id). ������� �������� id ���������� � ������ � �����������. ����� � ����� �� id ����������� �������� ������
void registerWindowsFactory(const QString& id, std::function<QWidget* ()> factory) {
	factories[id] = factory;
}

// ������� ��������� ���� �� id. windows ������ �������� ����.
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