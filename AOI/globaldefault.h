#pragma once
#include "qmetatype.h"

enum enumStatus {
	success = 0,
	running,
	stop,
	stop2,
	stop3,
	pause,
	_continue,
	abnormalBox_Load,
	abnormalBox_unLoad,
	abnormalPannel_Load,
	abnormalPannel_unLoad,
	abnormalBoxBase_Load,
	abnormalBoxBase_unLoad,
	lotNumber,
	nextLoop,
	lotOver

};

Q_DECLARE_METATYPE(enumStatus);