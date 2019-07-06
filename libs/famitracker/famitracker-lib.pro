#-------------------------------------------------
#
# Project created by QtCreator 2013-02-05T19:20:22
#
#-------------------------------------------------

TARGET = famitracker
TEMPLATE = lib

QT += core \
      gui

QT += widgets

# `CONFIG += c++17` was added in Qt 5.12. I'm on 5.9.
win32-msvc* {
    # Compiling on MSVC is untested.
    QMAKE_CXXFLAGS += /std:c++latest
}
else {
    QMAKE_CXXFLAGS += -std=c++17
}

macx {
  QMAKE_CFLAGS += -mmacosx-version-min=10.7
  QMAKE_LFLAGS += -mmacosx-version-min=10.7
}

QMAKE_CFLAGS += -w
QMAKE_CXXFLAGS += -w

TOP = ../..

macx {
    QMAKE_MAC_SDK = macosx10.14
}

CONFIG += warn_off

CONFIG(release, debug|release) {
   DESTDIR = release
} else {
   DESTDIR = debug
   #DEFINES += _DEBUG
}

OBJECTS_DIR = $$DESTDIR
MOC_DIR = $$DESTDIR
RCC_DIR = $$DESTDIR
UI_DIR = $$DESTDIR

win32 {
   DEPENDENCYROOTPATH = $$TOP/deps
   DEPENDENCYPATH = $$DEPENDENCYROOTPATH/Windows
}
mac {
   DEPENDENCYROOTPATH = $$TOP/deps
   DEPENDENCYPATH = $$DEPENDENCYROOTPATH/osx
}
unix:!mac {
   DEPENDENCYROOTPATH = $$TOP/deps
   DEPENDENCYPATH = $$DEPENDENCYROOTPATH/linux
}

DEFINES -= UNICODE
DEFINES += NOMINMAX NULL=0

INCLUDEPATH += \
   . \
   Source \
   $$TOP/common

# Boost is (thankfully) a generic dependency.
BOOST_CXXFLAGS=-I$$DEPENDENCYROOTPATH/boost_1_64_0

win32 {
#    contains(QT_ARCH, i386) {
#        arch = x86
#    } else {
#        arch = x64
#    }
   arch = x86

   SDL_CXXFLAGS = -I$$DEPENDENCYPATH/SDL
   SDL_LIBS =  -L$$DEPENDENCYPATH/SDL/$$arch -lsdl
}

mac {
   SDL_CXXFLAGS = -I$$DEPENDENCYPATH/SDL.framework/Headers
   SDL_LIBS = -F$$DEPENDENCYPATH -framework SDL

   WINE_CXXFLAGS = -I $$DEPENDENCYROOTPATH/wine/include -DWINE_UNICODE_NATIVE -I $$DEPENDENCYPATH -I $$DEPENDENCYPATH/stdafxhack

   QMAKE_POST_LINK += install_name_tool -change librtmidi.1.dylib \
       @executable_path/../Frameworks/librtmidi.1.dylib \
       $$DESTDIR/libfamitracker.dylib $$escape_expand(\n\t)
}

unix:!mac {
    SDL_CXXFLAGS = $$system(sdl-config --cflags)
    SDL_LIBS = $$system(sdl-config --libs)

    WINE_CXXFLAGS = -I $$DEPENDENCYROOTPATH/wine/include -DUSE_WS_PREFIX -DWINE_UNICODE_NATIVE

   PREFIX = $$(PREFIX)
   isEmpty (PREFIX) {
      PREFIX = /usr/local
   }

   isEmpty (BINDIR) {
                BINDIR=$$PREFIX/bin
   }

   target.path = $$BINDIR
   INSTALLS += target
}

RTMIDI_CXXFLAGS = -I$$DEPENDENCYROOTPATH/rtmidi
RTMIDI_LIBS = -L$$DEPENDENCYROOTPATH/rtmidi/$$DESTDIR -lrtmidi

QMAKE_CXXFLAGS += $$SDL_CXXFLAGS $$BOOST_CXXFLAGS $$RTMIDI_CXXFLAGS $$WINE_CXXFLAGS
QMAKE_CFLAGS += $$SDL_CXXFLAGS $$BOOST_CXXFLAGS $$RTMIDI_CXXFLAGS $$WINE_CXXFLAGS
LIBS += $$SDL_LIBS $$RTMIDI_LIBS

INCLUDEPATH += Source/APU

SOURCES += \
    cqtmfc_famitracker.cpp \
    $$TOP/common/cqtmfc.cpp \
    Source/AboutDlg.cpp \
    Source/Accelerator.cpp \
    Source/Action.cpp \
    Source/APU/2A03.cpp \
    Source/APU/APU.CPP \
    Source/APU/DPCM.CPP \
    Source/APU/emu2413.c \
    Source/APU/FDS.CPP \
    Source/APU/FDSSound.cpp \
    Source/APU/Mixer.cpp \
    Source/APU/MMC5.CPP \
    Source/APU/N163.CPP \
    Source/APU/Noise.cpp \
    Source/APU/S5B.cpp \
    Source/APU/SoundChip.cpp \
    Source/APU/Square.cpp \
    Source/APU/Triangle.cpp \
    Source/APU/VRC6.CPP \
    Source/APU/VRC7.cpp \
    Source/Blip_Buffer/Blip_Buffer.cpp \
    Source/Bookmark.cpp \
    Source/BookmarkCollection.cpp \
    Source/BookmarkDlg.cpp \
    Source/BookmarkManager.cpp \
    Source/ChannelFactory.cpp \
    Source/ChannelHandler.cpp \
    Source/ChannelMap.cpp \
    Source/Channels2A03.cpp \
    Source/ChannelsDlg.cpp \
    Source/ChannelsFDS.cpp \
    Source/ChannelsMMC5.cpp \
    Source/ChannelsN163.cpp \
    Source/ChannelsS5B.cpp \
    Source/ChannelState.cpp \
    Source/ChannelsVRC6.cpp \
    Source/ChannelsVRC7.cpp \
    Source/Chunk.cpp \
    Source/ChunkRenderBinary.cpp \
    Source/ChunkRenderText.cpp \
    Source/Clipboard.cpp \
    Source/CommandLineExport.cpp \
    Source/CommentsDlg.cpp \
    Source/Compiler.cpp \
    Source/CompoundAction.cpp \
    Source/ConfigAppearance.cpp \
    Source/ConfigGeneral.cpp \
    Source/ConfigMIDI.cpp \
    Source/ConfigMixer.cpp \
    Source/ConfigShortcuts.cpp \
    Source/ConfigSound.cpp \
    Source/ConfigVersion.cpp \
    Source/ConfigWindow.cpp \
    Source/ControlPanelDlg.cpp \
    Source/CreateWaveDlg.cpp \
    Source/CustomControls.cpp \
    Source/CustomExporter.cpp \
    Source/CustomExporter_C_Interface.cpp \
    Source/CustomExporters.cpp \
    Source/DetuneDlg.cpp \
    Source/DetuneTable.cpp \
    Source/DialogReBar.cpp \
    Source/DirectSound.cpp \
    Source/DocumentFile.cpp \
    Source/DocumentWrapper.cpp \
    Source/DPI.cpp \
    Source/DSample.cpp \
    Source/DSampleManager.cpp \
    Source/Exception.cpp \
    Source/ExportDialog.cpp \
    Source/FamiTracker.cpp \
    Source/FamiTrackerDoc.cpp \
    Source/FamiTrackerTypes.cpp \
    Source/FamiTrackerView.cpp \
    Source/FindDlg.cpp \
    Source/FrameAction.cpp \
    Source/FrameEditor.cpp \
    Source/FrameEditorTypes.cpp \
    Source/GotoDlg.cpp \
    Source/GraphEditor.cpp \
    Source/Graphics.cpp \
    Source/Groove.cpp \
    Source/GrooveDlg.cpp \
    Source/HistoryFileDlg.cpp \
    Source/InstHandlerDPCM.cpp \
    Source/InstHandlerVRC7.cpp \
    Source/Instrument.cpp \
    Source/Instrument2A03.cpp \
    Source/InstrumentEditDlg.cpp \
    Source/InstrumentEditorDPCM.cpp \
    Source/InstrumentEditorFDS.cpp \
    Source/InstrumentEditorFDSEnvelope.cpp \
    Source/InstrumentEditorN163Wave.cpp \
    Source/InstrumentEditorSeq.cpp \
    Source/InstrumentEditorVRC7.cpp \
    Source/InstrumentEditPanel.cpp \
    Source/InstrumentFactory.cpp \
    Source/InstrumentFDS.cpp \
    Source/InstrumentFileTree.cpp \
    Source/InstrumentListCtrl.cpp \
    Source/InstrumentManager.cpp \
    Source/InstrumentN163.cpp \
    Source/InstrumentRecorder.cpp \
    Source/InstrumentS5B.cpp \
    Source/InstrumentVRC6.cpp \
    Source/InstrumentVRC7.cpp \
    Source/MainFrm.cpp \
    Source/MIDI.cpp \
    Source/ModSequenceEditor.cpp \
    Source/ModuleException.cpp \
    Source/ModuleImportDlg.cpp \
    Source/ModulePropertiesDlg.cpp \
    Source/NoNotifyEdit.cpp \
    Source/NoteQueue.cpp \
    Source/OldSequence.cpp \
    Source/PatternAction.cpp \
    Source/PatternCompiler.cpp \
    Source/PatternComponent.cpp \
    Source/PatternData.cpp \
    Source/PatternEditor.cpp \
    Source/PatternEditorTypes.cpp \
    Source/PatternNote.cpp \
    Source/PCMImport.cpp \
    Source/PerformanceDlg.cpp \
    Source/RecordSettingsDlg.cpp \
    Source/RegisterState.cpp \
    Source/resampler/resample.cpp \
    Source/resampler/resample.inl \
    Source/resampler/sinc.cpp \
    Source/SampleEditorDlg.cpp \
    Source/SampleEditorView.cpp \
    Source/SeqInstHandler.cpp \
    Source/SeqInstHandler2A03Pulse.cpp \
    Source/SeqInstHandlerFDS.cpp \
    Source/SeqInstHandlerN163.cpp \
    Source/SeqInstHandlerS5B.cpp \
    Source/SeqInstHandlerSawtooth.cpp \
    Source/SeqInstrument.cpp \
    Source/Sequence.cpp \
    Source/SequenceCollection.cpp \
    Source/SequenceEditor.cpp \
    Source/SequenceManager.cpp \
    Source/SequenceParser.cpp \
    Source/SequenceSetting.cpp \
    Source/Settings.cpp \
    Source/SimpleFile.cpp \
    Source/SizeEditor.cpp \
    Source/SoundGen.cpp \
    Source/SpeedDlg.cpp \
    Source/SplitKeyboardDlg.cpp \
    Source/stdafx.cpp \
    Source/StretchDlg.cpp \
    Source/SwapDlg.cpp \
    Source/TextExporter.cpp \
    Source/TrackerChannel.cpp \
    Source/TransposeDlg.cpp \
    Source/utils/ftmath.cpp \
    Source/VisualizerBase.cpp \
    Source/VisualizerScope.cpp \
    Source/VisualizerSpectrum.cpp \
    Source/VisualizerStatic.cpp \
    Source/VisualizerWnd.cpp \
    Source/WaveEditor.cpp \
    Source/WaveFile.cpp \
    Source/WaveformGenerator.cpp \
    Source/WavegenBuiltin.cpp \
    Source/WavProgressDlg.cpp \

HEADERS += \
    cqtmfc_famitracker.h \
    $$TOP/common/afxmsg_.h \
    $$TOP/common/cqtmfc.h \
    $$TOP/common/WinUser.h \
    name.h \
    res/resource.h \
    Source/AboutDlg.h \
    Source/Accelerator.h \
    Source/Action.h \
    Source/APU/2413tone.h \
    Source/APU/2A03.h \
    Source/APU/2A03Chan.h \
    Source/APU/APU.h \
    Source/APU/Channel.h \
    Source/APU/DPCM.h \
    Source/APU/emu2413.h \
    Source/APU/FDS.H \
    Source/APU/FDSSound.h \
    Source/APU/Mixer.h \
    Source/APU/MMC5.H \
    Source/APU/N163.H \
    Source/APU/Noise.h \
    Source/APU/S5B.h \
    Source/APU/SoundChip.h \
    Source/APU/Square.h \
    Source/APU/Triangle.h \
    Source/APU/Types.h \
    Source/APU/VRC6.H \
    Source/APU/VRC7.h \
    Source/APU/vrc7tone.h \
    Source/array_view.h \
    Source/Blip_Buffer/Blip_Buffer.h \
    Source/Bookmark.h \
    Source/BookmarkCollection.h \
    Source/BookmarkDlg.h \
    Source/BookmarkManager.h \
    Source/ChannelFactory.h \
    Source/ChannelHandler.h \
    Source/ChannelHandlerInterface.h \
    Source/ChannelMap.h \
    Source/Channels2A03.h \
    Source/ChannelsDlg.h \
    Source/ChannelsFDS.h \
    Source/ChannelsMMC5.h \
    Source/ChannelsN163.h \
    Source/ChannelsS5B.h \
    Source/ChannelState.h \
    Source/ChannelsVRC6.h \
    Source/ChannelsVRC7.h \
    Source/Chunk.h \
    Source/ChunkRenderBinary.h \
    Source/ChunkRenderText.h \
    Source/Clipboard.h \
    Source/ColorScheme.h \
    Source/CommandLineExport.h \
    Source/CommentsDlg.h \
    Source/Common.h \
    Source/Compiler.h \
    Source/CompoundAction.h \
    Source/ConfigAppearance.h \
    Source/ConfigGeneral.h \
    Source/ConfigMIDI.h \
    Source/ConfigMixer.h \
    Source/ConfigShortcuts.h \
    Source/ConfigSound.h \
    Source/ConfigVersion.h \
    Source/ConfigWindow.h \
    Source/ControlPanelDlg.h \
    Source/CreateWaveDlg.h \
    Source/CustomControls.h \
    Source/CustomExporter.h \
    Source/CustomExporter_C_Interface.h \
    Source/CustomExporterInterfaces.h \
    Source/CustomExporters.h \
    Source/DetuneDlg.h \
    Source/DetuneTable.h \
    Source/DialogReBar.h \
    Source/DirectSound.h \
    Source/DocumentFile.h \
    Source/DocumentWrapper.h \
    Source/DPI.h \
    Source/Driver.h \
    Source/drivers/drv_2a03.h \
    Source/drivers/drv_all.h \
    Source/drivers/drv_fds.h \
    Source/drivers/drv_mmc5.h \
    Source/drivers/drv_n163.h \
    Source/drivers/drv_s5b.h \
    Source/drivers/drv_vrc6.h \
    Source/drivers/drv_vrc7.h \
    Source/DSample.h \
    Source/DSampleManager.h \
    Source/Exception.h \
    Source/ExportDialog.h \
    Source/Factory.h \
    Source/FamiTracker.h \
    Source/FamiTrackerDoc.h \
    Source/FamiTrackerTypes.h \
    Source/FamiTrackerView.h \
    Source/FamiTrackerViewMessage.h \
    Source/FFT/FftBuffer.h \
    Source/FFT/FftComplex.hpp \
    Source/FindDlg.h \
    Source/FrameAction.h \
    Source/FrameEditor.h \
    Source/FrameEditorTypes.h \
    Source/FTMComponentInterface.h \
    Source/GotoDlg.h \
    Source/GraphEditor.h \
    Source/Graphics.h \
    Source/Groove.h \
    Source/GrooveDlg.h \
    Source/HistoryFileDlg.h \
    Source/InstHandler.h \
    Source/InstHandlerDPCM.h \
    Source/InstHandlerVRC7.h \
    Source/Instrument.h \
    Source/Instrument2A03.h \
    Source/InstrumentEditDlg.h \
    Source/InstrumentEditorDPCM.h \
    Source/InstrumentEditorFDS.h \
    Source/InstrumentEditorFDSEnvelope.h \
    Source/InstrumentEditorN163Wave.h \
    Source/InstrumentEditorSeq.h \
    Source/InstrumentEditorVRC7.h \
    Source/InstrumentEditPanel.h \
    Source/InstrumentFactory.h \
    Source/InstrumentFDS.h \
    Source/InstrumentFileTree.h \
    Source/InstrumentManager.h \
    Source/InstrumentManagerInterface.h \
    Source/InstrumentN163.h \
    Source/InstrumentRecorder.h \
    Source/InstrumentS5B.h \
    Source/InstrumentVRC6.h \
    Source/InstrumentVRC7.h \
    Source/IntRange.h \
    Source/json/json.hpp \
    Source/MainFrm.h \
    Source/MIDI.h \
    Source/ModSequenceEditor.h \
    Source/ModuleException.h \
    Source/ModuleImportDlg.h \
    Source/ModulePropertiesDlg.h \
    Source/NoNotifyEdit.h \
    Source/NoteQueue.h \
    Source/NumConv.h \
    Source/OldSequence.h \
    Source/PatternAction.h \
    Source/PatternCompiler.h \
    Source/PatternComponent.h \
    Source/PatternData.h \
    Source/PatternEditor.h \
    Source/PatternEditorTypes.h \
    Source/PatternNote.h \
    Source/PCMImport.h \
    Source/PerformanceDlg.h \
    Source/RecordSettingsDlg.h \
    Source/RegisterState.h \
    Source/resampler/resample.hpp \
    Source/resampler/sinc.hpp \
    Source/SampleEditorDlg.h \
    Source/SampleEditorView.h \
    Source/SeqInstHandler.h \
    Source/SeqInstHandler2A03Pulse.h \
    Source/SeqInstHandlerFDS.h \
    Source/SeqInstHandlerN163.h \
    Source/SeqInstHandlerS5B.h \
    Source/SeqInstHandlerSawtooth.h \
    Source/SeqInstrument.h \
    Source/Sequence.h \
    Source/SequenceCollection.h \
    Source/SequenceEditor.h \
    Source/SequenceEditorMessage.h \
    Source/SequenceManager.h \
    Source/SequenceParser.h \
    Source/SequenceSetting.h \
    Source/Settings.h \
    Source/SimpleFile.h \
    Source/SizeEditor.h \
    Source/SoundGen.h \
    Source/SpeedDlg.h \
    Source/SplitKeyboardDlg.h \
    Source/stdafx.h \
    Source/str_conv/str_conv.hpp \
    Source/str_conv/utf8_conv.hpp \
    Source/StretchDlg.h \
    Source/SwapDlg.h \
    Source/TextExporter.h \
    Source/to_sv.h \
    Source/TrackerChannel.h \
    Source/TransposeDlg.h \
    Source/utils/ftmath.h \
    Source/utils/input.h \
    Source/VisualizerBase.h \
    Source/VisualizerScope.h \
    Source/VisualizerSpectrum.h \
    Source/VisualizerStatic.h \
    Source/VisualizerWnd.h \
    Source/WaveEditor.h \
    Source/WaveFile.h \
    Source/WaveformGenerator.h \
    Source/WavegenBuiltin.h \
    Source/WavProgressDlg.h \
    Source/WinSDK/VersionHelpers.h \
    Source/WinSDK/winapifamily.h \
    version.h \

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEABB3021
    TARGET.CAPABILITY =
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = famitracker.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

win32 {
   contains(QMAKE_CC, cl) {
      # Visual Studio
      QMAKE_CXXFLAGS += "-Zc:strictStrings-"
      QMAKE_CXXFLAGS -= "-Zc:strictStrings"
   }
   #message($$QMAKE_CXXFLAGS)
   #message($$QMAKE_CXXFLAGS_DEBUG)
}

include($$TOP/common/export_symbols.pri)

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

OTHER_FILES += \
    famitracker-lib.pro

FORMS +=

RESOURCES += \
    $$TOP/common/resource.qrc
