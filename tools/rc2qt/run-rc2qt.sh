#!/bin/sh
cd $(git rev-parse --show-toplevel)

python tools/rc2qt/rc2qt.py \
	libs/famitracker/res/0CC-FamiTracker.rc \
	> libs/famitracker/cqtmfc_famitracker.cpp \
	# 2> libs/famitracker/rc2qt-errors.txt \
#}
