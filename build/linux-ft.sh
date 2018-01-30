#!/bin/bash

LIBDEPS="../deps/rtmidi/release/librtmidi \
     ../deps/qscintilla2/Qt4Qt5/libqscintilla2_qt5 \
     ../libs/famitracker/release/libfamitracker"

DEPLOYS="../apps/famitracker/release/famitracker"

TARGARGS="-verbose=0 -appimage"

if [ ! -f "./linuxdeployqt-continuous-x86_64.AppImage" ]; then
   wget -c "https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-continuous-x86_64.AppImage"
   chmod a+x linuxdeployqt*.AppImage
fi
unset QTDIR; unset QT_PLUGIN_PATH; unset LD_LIBRARY_PATH

for DEPLOY in ${DEPLOYS}
do
   DIST=$(basename $DEPLOY) 
   echo Deploying ${DIST}
   rm -rf ./dist
   mkdir -pv ./dist
   cp -v ${DEPLOY} ./dist/
   for f in ${LIBDEPS}
   do 
      sudo cp -v ${f}* /usr/lib/x86_64-linux-gnu/
   done
   if [ "$DEPLOY" == "../apps/ide/release/nesicide" ]; then
      make -C ../deps/cc65; make -C ../deps/cc65 install prefix=$PWD/dist/cc65
   fi
   cp -v ${DIST}.desktop ./dist
   cp -v ${DIST}.png ./dist
   ./linuxdeployqt-continuous-x86_64.AppImage ${DIST}.desktop ${TARGARGS}
done
ls -al ./dist/
