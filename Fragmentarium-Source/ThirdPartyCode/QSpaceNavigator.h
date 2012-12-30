#pragma once

/**
 * Provides a QT-friendly interface to
 * spacenav driver
 */

#include <QObject>
#include <QSocketNotifier>
#include <spnav.h>

class QSpaceNavigator : public QObject
{
	Q_OBJECT

public:
	QSpaceNavigator();
	virtual ~QSpaceNavigator();

signals:
	void motion(float x, float y, float z, float rx, float ry, float rz);
	void buttonPressed(int bnum);
	void buttonReleased(int bnum);

private slots:
	void poll();

protected:
	spnav_event sev;
	QSocketNotifier *spaceSock;
};
