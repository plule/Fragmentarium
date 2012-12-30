#include "QSpaceNavigator.h"

QSpaceNavigator::QSpaceNavigator() {
	if(spnav_open() != -1) {
		spaceSock = new QSocketNotifier(spnav_fd(),QSocketNotifier::Read, this);
		connect(spaceSock, SIGNAL(activated(int)), this, SLOT(poll()));
	}
}

QSpaceNavigator::~QSpaceNavigator() {
	spnav_close();
	delete spaceSock;
}

void QSpaceNavigator::poll() {
	spnav_poll_event(&sev);
	if(sev.type == SPNAV_EVENT_MOTION) {
		emit motion(Motion(sev.motion.x,sev.motion.y,sev.motion.z,sev.motion.rx,sev.motion.ry,sev.motion.rz));
	} else { /* SPNAV_EVENT_BUTTON */
		if (sev.button.press)
			emit buttonPressed(sev.button.bnum);
		else
			emit buttonReleased(sev.button.bnum);
	}
}
