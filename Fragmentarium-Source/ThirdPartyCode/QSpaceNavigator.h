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
	struct Motion {
		float x;
		float y;
		float z;
		float rx;
		float ry;
		float rz;
	Motion(float x, float y, float z, float rx, float ry, float rz) : x(x),y(y),z(z),rx(rx),ry(ry),rz(rz){};
	};

signals:
	void motion(Motion m);
	void buttonPressed(int bnum);
	void buttonReleased(int bnum);

private slots:
	void poll();

protected:
	spnav_event sev;
	QSocketNotifier *spaceSock;
};
