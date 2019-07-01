#include "cqtmfc.h"
#include "cqtmfc_famitracker.h"
#include "resource.h"

#include "stdafx.h"

#include "FamiTrackerDoc.h"


void qtMfcInitMenuResource_IDR_MAINFRAME(CMenu* parent)
{
	QAction* menuAction;

	// IDR_MAINFRAME MENU
	// BEGIN
	QList<CMenu*> subMenuTree;
	CMenu* subMenu;


	// POPUP "&File"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&File");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&File");

	// BEGIN
   // MENUITEM "&New\tCtrl+N", ID_FILE_NEW
	subMenu->AppendMenu(MF_STRING,ID_FILE_NEW,"&New\tCtrl+N");

   // MENUITEM "&Open...\tCtrl+O", ID_FILE_OPEN
	subMenu->AppendMenu(MF_STRING,ID_FILE_OPEN,"&Open...\tCtrl+O");

   // MENUITEM "&Save\tCtrl+S", ID_FILE_SAVE
	subMenu->AppendMenu(MF_STRING,ID_FILE_SAVE,"&Save\tCtrl+S");

   // MENUITEM "Save &As...", ID_FILE_SAVE_AS
	subMenu->AppendMenu(MF_STRING,ID_FILE_SAVE_AS,"Save &As...");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Create NS&F...\tCtrl+E", ID_FILE_CREATE_NSF
	subMenu->AppendMenu(MF_STRING,ID_FILE_CREATE_NSF,"Create NS&F...\tCtrl+E");

   // MENUITEM "Create WA&V...", ID_FILE_CREATEWAV
	subMenu->AppendMenu(MF_STRING,ID_FILE_CREATEWAV,"Create WA&V...");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Import Text...", ID_FILE_IMPORTTEXT
	subMenu->AppendMenu(MF_STRING,ID_FILE_IMPORTTEXT,"&Import Text...");

   // MENUITEM "&Export Text...", ID_FILE_EXPORTTEXT
	subMenu->AppendMenu(MF_STRING,ID_FILE_EXPORTTEXT,"&Export Text...");

   // MENUITEM "Export Ro&ws...", ID_FILE_EXPORTROWS
	subMenu->AppendMenu(MF_STRING,ID_FILE_EXPORTROWS,"Export Ro&ws...");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Configuration...", ID_FILE_GENERALSETTINGS
	subMenu->AppendMenu(MF_STRING,ID_FILE_GENERALSETTINGS,"&Configuration...");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);


	// POPUP "&Recent Files"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Recent Files");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Recent Files");

	// BEGIN
   // MENUITEM "&Clear", ID_RECENTFILES_CLEAR
	subMenu->AppendMenu(MF_STRING,ID_RECENTFILES_CLEAR,"&Clear");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "(File)", ID_FILE_MRU_FILE1
	subMenu->AppendMenu(MF_STRING,ID_FILE_MRU_FILE1,"(File)");

   // END
	subMenu = subMenuTree.takeLast();

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "E&xit\tAlt+F4", ID_APP_EXIT
	subMenu->AppendMenu(MF_STRING,ID_APP_EXIT,"E&xit\tAlt+F4");

   // END
	subMenu = subMenuTree.takeLast();


	// POPUP "&Edit"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Edit");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Edit");

	// BEGIN
   // MENUITEM "&Undo\tCtrl+Z", ID_EDIT_UNDO
	subMenu->AppendMenu(MF_STRING,ID_EDIT_UNDO,"&Undo\tCtrl+Z");

   // MENUITEM "&Redo\tCtrl+Y", ID_EDIT_REDO
	subMenu->AppendMenu(MF_STRING,ID_EDIT_REDO,"&Redo\tCtrl+Y");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Cu&t\tCtrl+X", ID_EDIT_CUT
	subMenu->AppendMenu(MF_STRING,ID_EDIT_CUT,"Cu&t\tCtrl+X");

   // MENUITEM "&Copy\tCtrl+C", ID_EDIT_COPY
	subMenu->AppendMenu(MF_STRING,ID_EDIT_COPY,"&Copy\tCtrl+C");

   // MENUITEM "&Paste\tCtrl+V", ID_EDIT_PASTE
	subMenu->AppendMenu(MF_STRING,ID_EDIT_PASTE,"&Paste\tCtrl+V");


	// POPUP "Paste Specia&l"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Paste Specia&l");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Paste Specia&l");

	// BEGIN
   // MENUITEM "&Mix", ID_EDIT_PASTEMIX
	subMenu->AppendMenu(MF_STRING,ID_EDIT_PASTEMIX,"&Mix");

   // MENUITEM "&Overwrite", ID_EDIT_PASTEOVERWRITE
	subMenu->AppendMenu(MF_STRING,ID_EDIT_PASTEOVERWRITE,"&Overwrite");

   // MENUITEM "&Insert", ID_EDIT_PASTEINSERT
	subMenu->AppendMenu(MF_STRING,ID_EDIT_PASTEINSERT,"&Insert");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Cursor", ID_PASTESPECIAL_CURSOR
	subMenu->AppendMenu(MF_CHECKED|MF_STRING,ID_PASTESPECIAL_CURSOR,"&Cursor");

   // MENUITEM "&Selection", ID_PASTESPECIAL_SELECTION
	subMenu->AppendMenu(MF_STRING,ID_PASTESPECIAL_SELECTION,"&Selection");

   // MENUITEM "&Fill", ID_PASTESPECIAL_FILL
	subMenu->AppendMenu(MF_STRING,ID_PASTESPECIAL_FILL,"&Fill");

   // END
	subMenu = subMenuTree.takeLast();

   // MENUITEM "&Delete\tDel", ID_EDIT_DELETE
	subMenu->AppendMenu(MF_STRING,ID_EDIT_DELETE,"&Delete\tDel");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);


	// POPUP "Copy &As"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Copy &As");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Copy &As");

	// BEGIN
   // MENUITEM "&Volume Sequence", ID_COPYAS_VOLUMESEQUENCE
	subMenu->AppendMenu(MF_STRING,ID_COPYAS_VOLUMESEQUENCE,"&Volume Sequence");

   // MENUITEM "&Plain Text", ID_COPYAS_TEXT
	subMenu->AppendMenu(MF_STRING,ID_COPYAS_TEXT,"&Plain Text");

   // MENUITEM "PPMCK &MML Data", ID_COPYAS_PPMCK
	subMenu->AppendMenu(MF_STRING,ID_COPYAS_PPMCK,"PPMCK &MML Data");

   // END
	subMenu = subMenuTree.takeLast();

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);


	// POPUP "&Select"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Select");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Select");

	// BEGIN
   // MENUITEM "&All\tCtrl+A", ID_EDIT_SELECTALL
	subMenu->AppendMenu(MF_STRING,ID_EDIT_SELECTALL,"&All\tCtrl+A");

   // MENUITEM "&None", ID_SELECT_NONE
	subMenu->AppendMenu(MF_STRING,ID_SELECT_NONE,"&None");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Row", ID_SELECT_ROW
	subMenu->AppendMenu(MF_STRING,ID_SELECT_ROW,"&Row");

   // MENUITEM "&Column", ID_SELECT_COLUMN
	subMenu->AppendMenu(MF_STRING,ID_SELECT_COLUMN,"&Column");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Pattern", ID_SELECT_PATTERN
	subMenu->AppendMenu(MF_STRING,ID_SELECT_PATTERN,"&Pattern");

   // MENUITEM "&Frame", ID_SELECT_FRAME
	subMenu->AppendMenu(MF_STRING,ID_SELECT_FRAME,"&Frame");

   // MENUITEM "C&hannel", ID_SELECT_CHANNEL
	subMenu->AppendMenu(MF_STRING,ID_SELECT_CHANNEL,"C&hannel");

   // MENUITEM "&Track", ID_SELECT_TRACK
	subMenu->AppendMenu(MF_STRING,ID_SELECT_TRACK,"&Track");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "In &Other Editor", ID_SELECT_OTHER
	subMenu->AppendMenu(MF_STRING,ID_SELECT_OTHER,"In &Other Editor");

   // END
	subMenu = subMenuTree.takeLast();

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);


	// POPUP "&Find / Replace"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Find / Replace");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Find / Replace");

	// BEGIN
   // MENUITEM "&Toggle Tab", ID_EDIT_FIND_TOGGLE
	subMenu->AppendMenu(MF_STRING,ID_EDIT_FIND_TOGGLE,"&Toggle Tab");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Find &Next", ID_FIND_NEXT
	subMenu->AppendMenu(MF_STRING,ID_FIND_NEXT,"Find &Next");

   // MENUITEM "Find &Previous", ID_FIND_PREVIOUS
	subMenu->AppendMenu(MF_STRING,ID_FIND_PREVIOUS,"Find &Previous");

   // END
	subMenu = subMenuTree.takeLast();

   // MENUITEM "&Go To...", ID_EDIT_GOTO
	subMenu->AppendMenu(MF_STRING,ID_EDIT_GOTO,"&Go To...");


	// POPUP "&Bookmarks"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Bookmarks");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Bookmarks");

	// BEGIN
   // MENUITEM "&Toggle Bookmark", ID_BOOKMARKS_TOGGLE
	subMenu->AppendMenu(MF_STRING,ID_BOOKMARKS_TOGGLE,"&Toggle Bookmark");

   // MENUITEM "&Next Bookmark", ID_BOOKMARKS_NEXT
	subMenu->AppendMenu(MF_STRING,ID_BOOKMARKS_NEXT,"&Next Bookmark");

   // MENUITEM "&Previous Bookmark", ID_BOOKMARKS_PREVIOUS
	subMenu->AppendMenu(MF_STRING,ID_BOOKMARKS_PREVIOUS,"&Previous Bookmark");

   // END
	subMenu = subMenuTree.takeLast();

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Instrument Mask", ID_EDIT_INSTRUMENTMASK
	subMenu->AppendMenu(MF_STRING,ID_EDIT_INSTRUMENTMASK,"&Instrument Mask");

   // MENUITEM "&Volume Mask", ID_EDIT_VOLUMEMASK
	subMenu->AppendMenu(MF_CHECKED|MF_STRING,ID_EDIT_VOLUMEMASK,"&Volume Mask");

   // MENUITEM "Split Keyboard...", ID_EDIT_SPLITKEYBOARD
	subMenu->AppendMenu(MF_STRING,ID_EDIT_SPLITKEYBOARD,"Split Keyboard...");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Enable &MIDI", ID_EDIT_ENABLEMIDI
	subMenu->AppendMenu(MF_STRING,ID_EDIT_ENABLEMIDI,"Enable &MIDI");

   // END
	subMenu = subMenuTree.takeLast();


	// POPUP "&Pattern"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Pattern");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Pattern");

	// BEGIN
   // MENUITEM "&Interpolate", ID_EDIT_INTERPOLATE
	subMenu->AppendMenu(MF_STRING,ID_EDIT_INTERPOLATE,"&Interpolate");

   // MENUITEM "&Reverse", ID_EDIT_REVERSE
	subMenu->AppendMenu(MF_STRING,ID_EDIT_REVERSE,"&Reverse");

   // MENUITEM "R&eplace Instrument", ID_EDIT_REPLACEINSTRUMENT
	subMenu->AppendMenu(MF_STRING,ID_EDIT_REPLACEINSTRUMENT,"R&eplace Instrument");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "E&xpand", ID_EDIT_EXPANDPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_EDIT_EXPANDPATTERNS,"E&xpand");

   // MENUITEM "S&hrink", ID_EDIT_SHRINKPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_EDIT_SHRINKPATTERNS,"S&hrink");

   // MENUITEM "&Stretch...", ID_EDIT_STRETCHPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_EDIT_STRETCHPATTERNS,"&Stretch...");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);


	// POPUP "&Transpose"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Transpose");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Transpose");

	// BEGIN
   // MENUITEM "&Decrease Note", ID_TRANSPOSE_DECREASENOTE
	subMenu->AppendMenu(MF_STRING,ID_TRANSPOSE_DECREASENOTE,"&Decrease Note");

   // MENUITEM "&Increase Note", ID_TRANSPOSE_INCREASENOTE
	subMenu->AppendMenu(MF_STRING,ID_TRANSPOSE_INCREASENOTE,"&Increase Note");

   // MENUITEM "D&ecrease Octave", ID_TRANSPOSE_DECREASEOCTAVE
	subMenu->AppendMenu(MF_STRING,ID_TRANSPOSE_DECREASEOCTAVE,"D&ecrease Octave");

   // MENUITEM "I&ncrease Octave", ID_TRANSPOSE_INCREASEOCTAVE
	subMenu->AppendMenu(MF_STRING,ID_TRANSPOSE_INCREASEOCTAVE,"I&ncrease Octave");

   // END
	subMenu = subMenuTree.takeLast();

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "S&wap Channels...", ID_EDIT_SWAPCHANNELS
	subMenu->AppendMenu(MF_STRING,ID_EDIT_SWAPCHANNELS,"S&wap Channels...");

   // END
	subMenu = subMenuTree.takeLast();


	// POPUP "&Song"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Song");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Song");

	// BEGIN
   // MENUITEM "&Insert Frame", ID_MODULE_INSERTFRAME
	subMenu->AppendMenu(MF_STRING,ID_MODULE_INSERTFRAME,"&Insert Frame");

   // MENUITEM "&Remove Frame", ID_MODULE_REMOVEFRAME
	subMenu->AppendMenu(MF_STRING,ID_MODULE_REMOVEFRAME,"&Remove Frame");

   // MENUITEM "&Duplicate Frame", ID_MODULE_DUPLICATEFRAME
	subMenu->AppendMenu(MF_STRING,ID_MODULE_DUPLICATEFRAME,"&Duplicate Frame");

   // MENUITEM "Move Frame &Up", ID_MODULE_MOVEFRAMEUP
	subMenu->AppendMenu(MF_STRING,ID_MODULE_MOVEFRAMEUP,"Move Frame &Up");

   // MENUITEM "Move Frame Do&wn", ID_MODULE_MOVEFRAMEDOWN
	subMenu->AppendMenu(MF_STRING,ID_MODULE_MOVEFRAMEDOWN,"Move Frame Do&wn");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Clone Patterns", ID_MODULE_DUPLICATECURRENTPATTERN
	subMenu->AppendMenu(MF_STRING,ID_MODULE_DUPLICATECURRENTPATTERN,"&Clone Patterns");

   // MENUITEM "Clone &Frame", ID_MODULE_DUPLICATEFRAMEPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_MODULE_DUPLICATEFRAMEPATTERNS,"Clone &Frame");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "C&lear Patterns", ID_EDIT_CLEARPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_EDIT_CLEARPATTERNS,"C&lear Patterns");

   // MENUITEM "&Merge Duplicated Patterns", ID_CLEANUP_MERGEDUPLICATEDPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_CLEANUP_MERGEDUPLICATEDPATTERNS,"&Merge Duplicated Patterns");

   // MENUITEM "Populate Uni&que Patterns", ID_CLEANUP_POPULATEUNIQUEPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_CLEANUP_POPULATEUNIQUEPATTERNS,"Populate Uni&que Patterns");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Transpose Song...", ID_TRANSPOSE_CUSTOM
	subMenu->AppendMenu(MF_STRING,ID_TRANSPOSE_CUSTOM,"&Transpose Song...");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Estimate Song Length", ID_MODULE_ESTIMATESONGLENGTH
	subMenu->AppendMenu(MF_STRING,ID_MODULE_ESTIMATESONGLENGTH,"&Estimate Song Length");

   // END
	subMenu = subMenuTree.takeLast();


	// POPUP "&Module"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Module");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Module");

	// BEGIN
   // MENUITEM "&Module Properties...\tCtrl+P", ID_MODULE_MODULEPROPERTIES
	subMenu->AppendMenu(MF_STRING,ID_MODULE_MODULEPROPERTIES,"&Module Properties...\tCtrl+P");

   // MENUITEM "&Comments...", ID_MODULE_COMMENTS
	subMenu->AppendMenu(MF_STRING,ID_MODULE_COMMENTS,"&Comments...");


	// POPUP "&Region"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Region");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Region");

	// BEGIN
   // MENUITEM "&NTSC", ID_TRACKER_NTSC
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_NTSC,"&NTSC");

   // MENUITEM "&PAL", ID_TRACKER_PAL
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_PAL,"&PAL");

   // END
	subMenu = subMenuTree.takeLast();


	// POPUP "&Engine Speed"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Engine Speed");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Engine Speed");

	// BEGIN
   // MENUITEM "&Default", ID_SPEED_DEFAULT
	subMenu->AppendMenu(MF_STRING,ID_SPEED_DEFAULT,"&Default");

   // MENUITEM "&Custom...", ID_SPEED_CUSTOM
	subMenu->AppendMenu(MF_STRING,ID_SPEED_CUSTOM,"&Custom...");

   // END
	subMenu = subMenuTree.takeLast();

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Detune Settings...", ID_MODULE_DETUNE
	subMenu->AppendMenu(MF_STRING,ID_MODULE_DETUNE,"&Detune Settings...");

   // MENUITEM "&Groove Settings", ID_MODULE_GROOVE
	subMenu->AppendMenu(MF_STRING,ID_MODULE_GROOVE,"&Groove Settings");

   // MENUITEM "&Bookmark Manager", ID_MODULE_BOOKMARK
	subMenu->AppendMenu(MF_STRING,ID_MODULE_BOOKMARK,"&Bookmark Manager");

   // MENUITEM "C&hannels", ID_MODULE_CHANNELS
	subMenu->AppendMenu(MF_STRING,ID_MODULE_CHANNELS,"C&hannels");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);


	// POPUP "Clean&up"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Clean&up");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Clean&up");

	// BEGIN
   // MENUITEM "Remove Unused &Instruments", ID_CLEANUP_REMOVEUNUSEDINSTRUMENTS
	subMenu->AppendMenu(MF_STRING,ID_CLEANUP_REMOVEUNUSEDINSTRUMENTS,"Remove Unused &Instruments");

   // MENUITEM "Remove Unused &DPCM Samples", ID_CLEANUP_REMOVEUNUSEDDPCMSAMPLES
	subMenu->AppendMenu(MF_STRING,ID_CLEANUP_REMOVEUNUSEDDPCMSAMPLES,"Remove Unused &DPCM Samples");

   // MENUITEM "Remove Unused &Patterns", ID_CLEANUP_REMOVEUNUSEDPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_CLEANUP_REMOVEUNUSEDPATTERNS,"Remove Unused &Patterns");

   // END
	subMenu = subMenuTree.takeLast();

   // END
	subMenu = subMenuTree.takeLast();


	// POPUP "&Instrument"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Instrument");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Instrument");

	// BEGIN
   // MENUITEM "&New Instrument", ID_INSTRUMENT_NEW
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_NEW,"&New Instrument");

   // MENUITEM "&Remove Instrument", ID_INSTRUMENT_REMOVE
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_REMOVE,"&Remove Instrument");

   // MENUITEM "&Clone Instrument", ID_INSTRUMENT_CLONE
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_CLONE,"&Clone Instrument");

   // MENUITEM "&Deep Clone Instrument", ID_INSTRUMENT_DEEPCLONE
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_DEEPCLONE,"&Deep Clone Instrument");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Load from File...", ID_INSTRUMENT_LOAD
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_LOAD,"&Load from File...");

   // MENUITEM "&Save to File...", ID_INSTRUMENT_SAVE
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_SAVE,"&Save to File...");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Edit\tCtrl+I", ID_INSTRUMENT_EDIT
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_EDIT,"&Edit\tCtrl+I");

   // END
	subMenu = subMenuTree.takeLast();


	// POPUP "T&racker"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"T&racker");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"T&racker");

	// BEGIN
   // MENUITEM "&Play", ID_TRACKER_PLAY
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_PLAY,"&Play");

   // MENUITEM "Play P&attern", ID_TRACKER_PLAYPATTERN
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_PLAYPATTERN,"Play P&attern");

   // MENUITEM "Play &from Start", ID_TRACKER_PLAY_START
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_PLAY_START,"Play &from Start");

   // MENUITEM "Play from C&ursor", ID_TRACKER_PLAY_CURSOR
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_PLAY_CURSOR,"Play from C&ursor");

   // MENUITEM "Play from &Marker", ID_TRACKER_PLAY_MARKER
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_PLAY_MARKER,"Play from &Marker");

   // MENUITEM "&Stop", ID_TRACKER_STOP
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_STOP,"&Stop");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Toggle &Edit Mode", ID_TRACKER_EDIT
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_EDIT,"Toggle &Edit Mode");

   // MENUITEM "Set Ro&w Marker", ID_TRACKER_SET_MARKER
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_SET_MARKER,"Set Ro&w Marker");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Toggle Channel", ID_TRACKER_TOGGLECHANNEL
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_TOGGLECHANNEL,"&Toggle Channel");

   // MENUITEM "S&olo Channel", ID_TRACKER_SOLOCHANNEL
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_SOLOCHANNEL,"S&olo Channel");

   // MENUITEM "To&ggle Chip", ID_TRACKER_TOGGLECHIP
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_TOGGLECHIP,"To&ggle Chip");

   // MENUITEM "So&lo Chip", ID_TRACKER_SOLOCHIP
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_SOLOCHIP,"So&lo Chip");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Switch To Track &Instrument", ID_TRACKER_SWITCHTOTRACKINSTRUMENT
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_SWITCHTOTRACKINSTRUMENT,"Switch To Track &Instrument");

   // MENUITEM "&Record To Instrument", ID_TRACKER_RECORDTOINST
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_RECORDTOINST,"&Record To Instrument");

   // MENUITEM "Re&corder Settings...", ID_TRACKER_RECORDERSETTINGS
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_RECORDERSETTINGS,"Re&corder Settings...");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Kill Sound\tF12", ID_TRACKER_KILLSOUND
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_KILLSOUND,"&Kill Sound\tF12");

   // END
	subMenu = subMenuTree.takeLast();


	// POPUP "&View"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&View");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&View");

	// BEGIN
   // MENUITEM "&Toolbar", ID_VIEW_TOOLBAR
	subMenu->AppendMenu(MF_STRING,ID_VIEW_TOOLBAR,"&Toolbar");

   // MENUITEM "&Status Bar", ID_VIEW_STATUS_BAR
	subMenu->AppendMenu(MF_STRING,ID_VIEW_STATUS_BAR,"&Status Bar");

   // MENUITEM "&Control Panel", ID_VIEW_CONTROLPANEL
	subMenu->AppendMenu(MF_STRING,ID_VIEW_CONTROLPANEL,"&Control Panel");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Follow Mode", IDC_FOLLOW_TOGGLE
	subMenu->AppendMenu(MF_CHECKED|MF_STRING,IDC_FOLLOW_TOGGLE,"&Follow Mode");

   // MENUITEM "Co&mpact View", IDC_COMPACT_TOGGLE
	subMenu->AppendMenu(MF_STRING,IDC_COMPACT_TOGGLE,"Co&mpact View");


	// POPUP "Meter &Decay Rate"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Meter &Decay Rate");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Meter &Decay Rate");

	// BEGIN
   // MENUITEM "&Slow", ID_DECAY_SLOW
	subMenu->AppendMenu(MF_STRING,ID_DECAY_SLOW,"&Slow");

   // MENUITEM "&Fast", ID_DECAY_FAST
	subMenu->AppendMenu(MF_STRING,ID_DECAY_FAST,"&Fast");

   // END
	subMenu = subMenuTree.takeLast();

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Average &BPM", ID_VIEW_AVERAGEBPM
	subMenu->AppendMenu(MF_STRING,ID_VIEW_AVERAGEBPM,"Average &BPM");

   // MENUITEM "&Register State", ID_TRACKER_DISPLAYREGISTERSTATE
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_DISPLAYREGISTERSTATE,"&Register State");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);


	// POPUP "Frame Editor &Position"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Frame Editor &Position");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Frame Editor &Position");

	// BEGIN
   // MENUITEM "&Top", ID_FRAMEEDITOR_TOP
	subMenu->AppendMenu(MF_CHECKED|MF_STRING,ID_FRAMEEDITOR_TOP,"&Top");

   // MENUITEM "&Left", ID_FRAMEEDITOR_LEFT
	subMenu->AppendMenu(MF_STRING,ID_FRAMEEDITOR_LEFT,"&Left");

   // END
	subMenu = subMenuTree.takeLast();

   // END
	subMenu = subMenuTree.takeLast();


	// POPUP "&Help"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Help");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Help");

	// BEGIN
   // MENUITEM "&Help Topics\tF1", ID_HELP_FINDER
	subMenu->AppendMenu(MF_STRING,ID_HELP_FINDER,"&Help Topics\tF1");

   // MENUITEM "&Effect Table", ID_HELP_EFFECTTABLE
	subMenu->AppendMenu(MF_STRING,ID_HELP_EFFECTTABLE,"&Effect Table");

   // MENUITEM "&FAQ", ID_HELP_FAQ
	subMenu->AppendMenu(MF_STRING,ID_HELP_FAQ,"&FAQ");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Performance", ID_HELP_PERFORMANCE
	subMenu->AppendMenu(MF_STRING,ID_HELP_PERFORMANCE,"&Performance");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&About j0CC-FamiTracker...", ID_APP_ABOUT
	subMenu->AppendMenu(MF_STRING,ID_APP_ABOUT,"&About j0CC-FamiTracker...");

   // END
	subMenu = subMenuTree.takeLast();

   // END
}


void qtMfcInitMenuResource_IDR_PATTERN_POPUP(CMenu* parent)
{
	QAction* menuAction;

	// IDR_PATTERN_POPUP MENU
	// BEGIN
	QList<CMenu*> subMenuTree;
	CMenu* subMenu;


	// POPUP "Popup"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Popup");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Popup");

	// BEGIN
   // MENUITEM "&Undo\tCtrl+Z", ID_EDIT_UNDO
	subMenu->AppendMenu(MF_STRING,ID_EDIT_UNDO,"&Undo\tCtrl+Z");

   // MENUITEM "&Redo\tCtrl+Y", ID_EDIT_REDO
	subMenu->AppendMenu(MF_STRING,ID_EDIT_REDO,"&Redo\tCtrl+Y");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Cu&t\tCtrl+X", ID_EDIT_CUT
	subMenu->AppendMenu(MF_STRING,ID_EDIT_CUT,"Cu&t\tCtrl+X");

   // MENUITEM "&Copy\tCtrl+C", ID_EDIT_COPY
	subMenu->AppendMenu(MF_STRING,ID_EDIT_COPY,"&Copy\tCtrl+C");

   // MENUITEM "&Paste\tCtrl+V", ID_EDIT_PASTE
	subMenu->AppendMenu(MF_STRING,ID_EDIT_PASTE,"&Paste\tCtrl+V");

   // MENUITEM "&Delete\tDel", ID_EDIT_DELETE
	subMenu->AppendMenu(MF_STRING,ID_EDIT_DELETE,"&Delete\tDel");

   // MENUITEM "Select &All\tCtrl+A", ID_EDIT_SELECTALL
	subMenu->AppendMenu(MF_STRING,ID_EDIT_SELECTALL,"Select &All\tCtrl+A");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);


	// POPUP "Patter&n"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Patter&n");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Patter&n");

	// BEGIN
   // MENUITEM "&Interpolate", ID_EDIT_INTERPOLATE
	subMenu->AppendMenu(MF_STRING,ID_EDIT_INTERPOLATE,"&Interpolate");

   // MENUITEM "&Reverse", ID_EDIT_REVERSE
	subMenu->AppendMenu(MF_STRING,ID_EDIT_REVERSE,"&Reverse");

   // MENUITEM "R&eplace Instrument", ID_EDIT_REPLACEINSTRUMENT
	subMenu->AppendMenu(MF_STRING,ID_EDIT_REPLACEINSTRUMENT,"R&eplace Instrument");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "E&xpand", ID_EDIT_EXPANDPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_EDIT_EXPANDPATTERNS,"E&xpand");

   // MENUITEM "S&hrink", ID_EDIT_SHRINKPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_EDIT_SHRINKPATTERNS,"S&hrink");

   // MENUITEM "&Stretch...", ID_EDIT_STRETCHPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_EDIT_STRETCHPATTERNS,"&Stretch...");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);


	// POPUP "&Transpose"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Transpose");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Transpose");

	// BEGIN
   // MENUITEM "&Decrease Note", ID_TRANSPOSE_DECREASENOTE
	subMenu->AppendMenu(MF_STRING,ID_TRANSPOSE_DECREASENOTE,"&Decrease Note");

   // MENUITEM "&Increase Note", ID_TRANSPOSE_INCREASENOTE
	subMenu->AppendMenu(MF_STRING,ID_TRANSPOSE_INCREASENOTE,"&Increase Note");

   // MENUITEM "D&ecrease Octave", ID_TRANSPOSE_DECREASEOCTAVE
	subMenu->AppendMenu(MF_STRING,ID_TRANSPOSE_DECREASEOCTAVE,"D&ecrease Octave");

   // MENUITEM "I&ncrease Octave", ID_TRANSPOSE_INCREASEOCTAVE
	subMenu->AppendMenu(MF_STRING,ID_TRANSPOSE_INCREASEOCTAVE,"I&ncrease Octave");

   // END
	subMenu = subMenuTree.takeLast();

   // END
	subMenu = subMenuTree.takeLast();

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Pic&k Up Row", ID_POPUP_PICKUPROW
	subMenu->AppendMenu(MF_STRING,ID_POPUP_PICKUPROW,"Pic&k Up Row");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "T&oggle Channel", ID_TRACKER_TOGGLECHANNEL
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_TOGGLECHANNEL,"T&oggle Channel");

   // MENUITEM "&Solo Channel", ID_TRACKER_SOLOCHANNEL
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_SOLOCHANNEL,"&Solo Channel");

   // MENUITEM "To&ggle Chip", ID_TRACKER_TOGGLECHIP
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_TOGGLECHIP,"To&ggle Chip");

   // MENUITEM "So&lo Chip", ID_TRACKER_SOLOCHIP
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_SOLOCHIP,"So&lo Chip");

   // END
	subMenu = subMenuTree.takeLast();

   // END
}


void qtMfcInitMenuResource_IDR_FRAME_POPUP(CMenu* parent)
{
	QAction* menuAction;

	// IDR_FRAME_POPUP MENU
	// BEGIN
	QList<CMenu*> subMenuTree;
	CMenu* subMenu;


	// POPUP "Frame"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Frame");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Frame");

	// BEGIN
   // MENUITEM "&Insert Frame", ID_MODULE_INSERTFRAME
	subMenu->AppendMenu(MF_STRING,ID_MODULE_INSERTFRAME,"&Insert Frame");

   // MENUITEM "&Remove Frame", ID_MODULE_REMOVEFRAME
	subMenu->AppendMenu(MF_STRING,ID_MODULE_REMOVEFRAME,"&Remove Frame");

   // MENUITEM "Duplicate &Frame", ID_MODULE_DUPLICATEFRAME
	subMenu->AppendMenu(MF_STRING,ID_MODULE_DUPLICATEFRAME,"Duplicate &Frame");

   // MENUITEM "Clone Pattern", ID_MODULE_DUPLICATECURRENTPATTERN
	subMenu->AppendMenu(MF_STRING,ID_MODULE_DUPLICATECURRENTPATTERN,"Clone Pattern");

   // MENUITEM "D&uplicate Patterns", ID_MODULE_DUPLICATEFRAMEPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_MODULE_DUPLICATEFRAMEPATTERNS,"D&uplicate Patterns");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Move &Up", ID_MODULE_MOVEFRAMEUP
	subMenu->AppendMenu(MF_STRING,ID_MODULE_MOVEFRAMEUP,"Move &Up");

   // MENUITEM "Move &Down", ID_MODULE_MOVEFRAMEDOWN
	subMenu->AppendMenu(MF_STRING,ID_MODULE_MOVEFRAMEDOWN,"Move &Down");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Cu&t\tCtrl+X", ID_FRAME_CUT
	subMenu->AppendMenu(MF_STRING,ID_FRAME_CUT,"Cu&t\tCtrl+X");

   // MENUITEM "&Copy\tCtrl+C", ID_FRAME_COPY
	subMenu->AppendMenu(MF_STRING,ID_FRAME_COPY,"&Copy\tCtrl+C");

   // MENUITEM "&Paste\tCtrl+V", ID_FRAME_PASTE
	subMenu->AppendMenu(MF_STRING,ID_FRAME_PASTE,"&Paste\tCtrl+V");

   // MENUITEM "Paste && &Overwrite", ID_FRAME_PASTEOVERWRITE
	subMenu->AppendMenu(MF_STRING,ID_FRAME_PASTEOVERWRITE,"Paste && &Overwrite");

   // MENUITEM "Paste && Duplicate", ID_FRAME_PASTENEWPATTERNS
	subMenu->AppendMenu(MF_STRING,ID_FRAME_PASTENEWPATTERNS,"Paste && Duplicate");

   // MENUITEM "Delete\tDel", ID_FRAME_DELETE
	subMenu->AppendMenu(MF_STRING,ID_FRAME_DELETE,"Delete\tDel");

   // END
	subMenu = subMenuTree.takeLast();

   // END
}


void qtMfcInitMenuResource_IDR_INSTRUMENT_POPUP(CMenu* parent)
{
	QAction* menuAction;

	// IDR_INSTRUMENT_POPUP MENU
	// BEGIN
	QList<CMenu*> subMenuTree;
	CMenu* subMenu;


	// POPUP "Instrument"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Instrument");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Instrument");

	// BEGIN
   // MENUITEM "Add", ID_INSTRUMENT_NEW
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_NEW,"Add");

   // MENUITEM "Remove", ID_INSTRUMENT_REMOVE
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_REMOVE,"Remove");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Load from file...", ID_INSTRUMENT_LOAD
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_LOAD,"&Load from file...");

   // MENUITEM "&Save to file...", ID_INSTRUMENT_SAVE
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_SAVE,"&Save to file...");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Clone instrument", ID_INSTRUMENT_CLONE
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_CLONE,"Clone instrument");

   // MENUITEM "Deep clone instrument", ID_INSTRUMENT_DEEPCLONE
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_DEEPCLONE,"Deep clone instrument");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Edit", ID_INSTRUMENT_EDIT
	subMenu->AppendMenu(MF_STRING,ID_INSTRUMENT_EDIT,"Edit");

   // END
	subMenu = subMenuTree.takeLast();

   // END
}


void qtMfcInitMenuResource_IDR_SAMPLES_POPUP(CMenu* parent)
{
	QAction* menuAction;

	// IDR_SAMPLES_POPUP MENU
	// BEGIN
	QList<CMenu*> subMenuTree;
	CMenu* subMenu;


	// POPUP "Popup"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Popup");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Popup");

	// BEGIN
   // MENUITEM "Preview", IDC_PREVIEW
	subMenu->AppendMenu(MF_STRING,IDC_PREVIEW,"Preview");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Edit", IDC_EDIT
	subMenu->AppendMenu(MF_STRING,IDC_EDIT,"Edit");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Unload", IDC_UNLOAD
	subMenu->AppendMenu(MF_STRING,IDC_UNLOAD,"Unload");

   // MENUITEM "Save", IDC_SAVE
	subMenu->AppendMenu(MF_STRING,IDC_SAVE,"Save");

   // MENUITEM "Load", IDC_LOAD
	subMenu->AppendMenu(MF_STRING,IDC_LOAD,"Load");

   // MENUITEM "Import", IDC_IMPORT
	subMenu->AppendMenu(MF_STRING,IDC_IMPORT,"Import");

   // END
	subMenu = subMenuTree.takeLast();

   // END
}


void qtMfcInitMenuResource_IDR_SAMPLE_WND_POPUP(CMenu* parent)
{
	QAction* menuAction;

	// IDR_SAMPLE_WND_POPUP MENU
	// BEGIN
	QList<CMenu*> subMenuTree;
	CMenu* subMenu;


	// POPUP "Popup"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Popup");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Popup");

	// BEGIN
   // MENUITEM "Sample scope", ID_POPUP_SAMPLESCOPE1
	subMenu->AppendMenu(MF_STRING,ID_POPUP_SAMPLESCOPE1,"Sample scope");

   // MENUITEM "Sample scope (blur)", ID_POPUP_SAMPLESCOPE2
	subMenu->AppendMenu(MF_STRING,ID_POPUP_SAMPLESCOPE2,"Sample scope (blur)");

   // MENUITEM "Spectrum analyzer", ID_POPUP_SPECTRUMANALYZER
	subMenu->AppendMenu(MF_STRING,ID_POPUP_SPECTRUMANALYZER,"Spectrum analyzer");

   // MENUITEM "Spectrum analyzer (fine)", ID_POPUP_SPECTRUMANALYZER2
	subMenu->AppendMenu(MF_STRING,ID_POPUP_SPECTRUMANALYZER2,"Spectrum analyzer (fine)");

   // MENUITEM "Logo", ID_POPUP_NOTHING
	subMenu->AppendMenu(MF_STRING,ID_POPUP_NOTHING,"Logo");

   // END
	subMenu = subMenuTree.takeLast();

   // END
}


void qtMfcInitMenuResource_IDR_PATTERN_HEADER_POPUP(CMenu* parent)
{
	QAction* menuAction;

	// IDR_PATTERN_HEADER_POPUP MENU
	// BEGIN
	QList<CMenu*> subMenuTree;
	CMenu* subMenu;


	// POPUP "Popup"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Popup");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Popup");

	// BEGIN
   // MENUITEM "&Toggle Channel", ID_TRACKER_TOGGLECHANNEL
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_TOGGLECHANNEL,"&Toggle Channel");

   // MENUITEM "&Solo Channel", ID_TRACKER_SOLOCHANNEL
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_SOLOCHANNEL,"&Solo Channel");

   // MENUITEM "To&ggle Chip", ID_TRACKER_TOGGLECHIP
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_TOGGLECHIP,"To&ggle Chip");

   // MENUITEM "So&lo Chip", ID_TRACKER_SOLOCHIP
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_SOLOCHIP,"So&lo Chip");

   // MENUITEM "&Unmute All Channels", ID_POPUP_UNMUTEALLCHANNELS
	subMenu->AppendMenu(MF_STRING,ID_POPUP_UNMUTEALLCHANNELS,"&Unmute All Channels");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);


	// POPUP "&Meter Decay Rate"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Meter Decay Rate");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"&Meter Decay Rate");

	// BEGIN
   // MENUITEM "&Slow", ID_DECAY_SLOW
	subMenu->AppendMenu(MF_STRING,ID_DECAY_SLOW,"&Slow");

   // MENUITEM "&Fast", ID_DECAY_FAST
	subMenu->AppendMenu(MF_STRING,ID_DECAY_FAST,"&Fast");

   // END
	subMenu = subMenuTree.takeLast();

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "&Record to Instrument", ID_TRACKER_RECORDTOINST
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_RECORDTOINST,"&Record to Instrument");

   // MENUITEM "R&ecorder Settings...", ID_TRACKER_RECORDERSETTINGS
	subMenu->AppendMenu(MF_STRING,ID_TRACKER_RECORDERSETTINGS,"R&ecorder Settings...");

   // END
	subMenu = subMenuTree.takeLast();

   // END
}


void qtMfcInitMenuResource_IDR_SAMPLE_EDITOR_POPUP(CMenu* parent)
{
	QAction* menuAction;

	// IDR_SAMPLE_EDITOR_POPUP MENU
	// BEGIN
	QList<CMenu*> subMenuTree;
	CMenu* subMenu;


	// POPUP "Popup"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Popup");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Popup");

	// BEGIN
   // MENUITEM "Play\tP", IDC_PLAY
	subMenu->AppendMenu(MF_STRING,IDC_PLAY,"Play\tP");

   // MENUITEM SEPARATOR
	subMenu->AppendMenu(MF_SEPARATOR);

   // MENUITEM "Delete\tDel", IDC_DELETE
	subMenu->AppendMenu(MF_STRING,IDC_DELETE,"Delete\tDel");

   // MENUITEM "Tilt", IDC_TILT
	subMenu->AppendMenu(MF_STRING,IDC_TILT,"Tilt");

   // END
	subMenu = subMenuTree.takeLast();

   // END
}


void qtMfcInitMenuResource_IDR_SEQUENCE_POPUP(CMenu* parent)
{
	QAction* menuAction;

	// IDR_SEQUENCE_POPUP MENU
	// BEGIN
	QList<CMenu*> subMenuTree;
	CMenu* subMenu;


	// POPUP "Popup"
	subMenu = new CMenu;
	subMenuTree.append(subMenu);
	QObject::connect(subMenu->toQMenu(),SIGNAL(aboutToShow()),subMenu,SLOT(menu_aboutToShow()));
	if ( subMenuTree.count() == 1 )
		parent->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Popup");
	else
		subMenuTree.at(subMenuTree.count()-2)->AppendMenu(MF_POPUP|MF_STRING,(UINT_PTR)subMenu->m_hMenu,"Popup");

	// BEGIN
   // MENUITEM "&Clone sequence", ID_CLONE_SEQUENCE
	subMenu->AppendMenu(MF_STRING,ID_CLONE_SEQUENCE,"&Clone sequence");

   // END
	subMenu = subMenuTree.takeLast();

   // END
}


void qtMfcInitMenuResource(UINT menuID,CMenu* parent)
{
	switch ( menuID )
	{
      case IDR_MAINFRAME:
			qtMfcInitMenuResource_IDR_MAINFRAME(parent);
			break;

      case IDR_PATTERN_POPUP:
			qtMfcInitMenuResource_IDR_PATTERN_POPUP(parent);
			break;

      case IDR_FRAME_POPUP:
			qtMfcInitMenuResource_IDR_FRAME_POPUP(parent);
			break;

      case IDR_INSTRUMENT_POPUP:
			qtMfcInitMenuResource_IDR_INSTRUMENT_POPUP(parent);
			break;

      case IDR_SAMPLES_POPUP:
			qtMfcInitMenuResource_IDR_SAMPLES_POPUP(parent);
			break;

      case IDR_SAMPLE_WND_POPUP:
			qtMfcInitMenuResource_IDR_SAMPLE_WND_POPUP(parent);
			break;

      case IDR_PATTERN_HEADER_POPUP:
			qtMfcInitMenuResource_IDR_PATTERN_HEADER_POPUP(parent);
			break;

      case IDR_SAMPLE_EDITOR_POPUP:
			qtMfcInitMenuResource_IDR_SAMPLE_EDITOR_POPUP(parent);
			break;

      case IDR_SEQUENCE_POPUP:
			qtMfcInitMenuResource_IDR_SEQUENCE_POPUP(parent);
			break;

   }

	// Fixup shortcuts
	int menu = 0;
	CMenu* subMenu = parent->GetSubMenu(menu);
	while ( subMenu )
	{
		foreach ( QAction* action, subMenu->toQMenu()->actions() )
		{
			if ( action->text().contains("\t") )
			{
				action->setShortcut(QKeySequence(action->text().split("\t").at(1)));
			}
		}
		menu++;
		subMenu = parent->GetSubMenu(menu);
	}
}


void qtMfcInitStringResources()
{
	qtMfcStringResources.clear();


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(IDR_MAINFRAME,"j0CC-FamiTracker\n\nj0CC-FamiTracker\nj0CC-FamiTracker modules (*.0cc;*.ftm)\n.0cc\n0CCFamiTracker.Document\n0CCFamiTracker.Document");
   qtMfcStringResources.insert(IDS_FRAME_DROP_MOVE,"Drop selection to move frames");
   qtMfcStringResources.insert(IDS_DPCM_IMPORT_QUALITY_FORMAT,"Quality: %1");
   qtMfcStringResources.insert(IDS_CLIPBOARD_ERROR,"Could not register clipboard format");
   qtMfcStringResources.insert(IDS_FILE_OPEN_ERROR,"Could not open the file!");
   qtMfcStringResources.insert(IDS_CLEAR_RECENTS,"Do you want to clear all recent files?");
   qtMfcStringResources.insert(IDS_INST_LIMIT,"You cannot add more instruments");
   qtMfcStringResources.insert(IDS_CLIPBOARD_OPEN_ERROR,"Cannot open clipboard.");
   qtMfcStringResources.insert(IDS_CLIPBOARD_NOT_AVALIABLE,"Clipboard data is not available.");
   qtMfcStringResources.insert(ID_TRACKER_PLAY_START,"Play module from start\nPlay from Start");
   qtMfcStringResources.insert(IDS_INSTRUMENT_FILE_FAIL,"Instrument file was not vaild");
   qtMfcStringResources.insert(IDS_CLIPPING_MESSAGE,"Warning: Audio is clipping, decrease mixing levels!");
   qtMfcStringResources.insert(IDS_FILTER_FTI,"FamiTracker Instrument (*.fti)");
   qtMfcStringResources.insert(IDS_SAVE_FILE_ERROR,"Could not save file: %1");
   qtMfcStringResources.insert(IDS_START_ERROR,"Program could not start properly, default settings has been restored. Please restart the program.");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(IDS_SEL_REPEATED_ROW,"Error: Current selection contains the same row in multiple frames.");
   qtMfcStringResources.insert(IDS_SEL_NONTERMINAL_SKIP,"Error: Current selection spans over truncated rows, consider enabling \"Show skipped rows\".");
   qtMfcStringResources.insert(IDS_SEL_TERMINAL_SKIP,"Error: Current selection may truncate other rows, consider enabling \"Show skipped rows\".");
   qtMfcStringResources.insert(IDS_PASTE_REPEATED_ROW,"Warning: Clip data may overwrite itself during pasting. Do you want to apply the paste operation?");
   qtMfcStringResources.insert(IDS_PASTE_NONTERMINAL,"Warning: Clip data may alter frame lengths during pasting. Do you want to apply the paste operation?");
   qtMfcStringResources.insert(IDS_DISABLE_SAVE,"Saving to external files is disabled in this build of j0CC-FamiTracker.");
   qtMfcStringResources.insert(IDS_BOOKMARK_EMPTY,"The current track does not contain any bookmarks.");
   qtMfcStringResources.insert(IDS_POPULATE_PATTERNS,"Do you want to copy a unique pattern for all frames? There is no undo for this command.");
   qtMfcStringResources.insert(IDS_BOOKMARK_FORMAT,"Moved to bookmark %1. (Highlight: %2, %3)");
   qtMfcStringResources.insert(IDS_DUMP_NOT_SUPPORTED,"This channel does not support logging output to create a new instrument.");
   qtMfcStringResources.insert(IDS_SEQUENCE_LIMIT,"You cannot add more instrument sequences");
   qtMfcStringResources.insert(IDS_FIND_NONE,"Could not find the search query in the current search area.");
   qtMfcStringResources.insert(IDS_FINDRESULT_COUNT,"%1 %2 found.");
   qtMfcStringResources.insert(IDS_IMPORT_SEQUENCE_COUNT,"Could not import all sequences, out of sequence slots!");
   qtMfcStringResources.insert(ID_FIND_NEXT,"Find the next result of the search query\nFind Next");
   qtMfcStringResources.insert(IDS_ABOUT_TOOLTIP_BUG,"Report bugs at http://hertzdevil.info/bug/main_page.php");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(AFX_IDS_APP_TITLE,"0CC-FamiTracker");
   qtMfcStringResources.insert(AFX_IDS_IDLEMESSAGE,"For Help, press F1");
   qtMfcStringResources.insert(AFX_IDS_HELPMODEMESSAGE,"Select an object on which to get Help");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_INDICATOR_EXT,"EXT");
   qtMfcStringResources.insert(ID_INDICATOR_CAPS,"CAP");
   qtMfcStringResources.insert(ID_INDICATOR_NUM,"NUM");
   qtMfcStringResources.insert(ID_INDICATOR_SCRL,"SCRL");
   qtMfcStringResources.insert(ID_INDICATOR_OVR,"OVR");
   qtMfcStringResources.insert(ID_INDICATOR_REC,"REC");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_FILE_NEW,"Create a new document\nNew");
   qtMfcStringResources.insert(ID_FILE_OPEN,"Open an existing document\nOpen");
   qtMfcStringResources.insert(ID_FILE_CLOSE,"Close the active document\nClose");
   qtMfcStringResources.insert(ID_FILE_SAVE,"Save the active document\nSave");
   qtMfcStringResources.insert(ID_FILE_SAVE_AS,"Save the active document with a new name\nSave As");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_APP_ABOUT,"Display program information, version number and copyright\nAbout");
   qtMfcStringResources.insert(ID_APP_EXIT,"Quit the application; prompt to save documents\nExit");
   qtMfcStringResources.insert(ID_HELP_INDEX,"Open Help\nHelp Topics");
   qtMfcStringResources.insert(ID_HELP_FINDER,"List Help topics\nHelp Topics");
   qtMfcStringResources.insert(ID_HELP_USING,"Display instructions about how to use help\nHelp");
   qtMfcStringResources.insert(ID_CONTEXT_HELP,"Display help for clicked on buttons, menus and windows\nHelp");
   qtMfcStringResources.insert(ID_HELP,"Display help for current task or command\nHelp");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_FILE_MRU_FILE1,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE2,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE3,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE4,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE5,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE6,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE7,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE8,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE9,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE10,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE11,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE12,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE13,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE14,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE15,"Open this document");
   qtMfcStringResources.insert(ID_FILE_MRU_FILE16,"Open this document");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_NEXT_PANE,"Switch to the next window pane\nNext Pane");
   qtMfcStringResources.insert(ID_PREV_PANE,"Switch back to the previous window pane\nPrevious Pane");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_WINDOW_SPLIT,"Split the active window into panes\nSplit");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_EDIT_CLEAR,"Erase the selection\nErase");
   qtMfcStringResources.insert(ID_EDIT_CLEAR_ALL,"Erase everything\nErase All");
   qtMfcStringResources.insert(ID_EDIT_COPY,"Copy the selection and put it on the Clipboard\nCopy");
   qtMfcStringResources.insert(ID_EDIT_CUT,"Cut the selection and put it on the Clipboard\nCut");
   qtMfcStringResources.insert(ID_EDIT_FIND,"Find the specified text\nFind");
   qtMfcStringResources.insert(ID_EDIT_PASTE,"Insert Clipboard contents\nPaste");
   qtMfcStringResources.insert(ID_EDIT_REPEAT,"Repeat the last action\nRepeat");
   qtMfcStringResources.insert(ID_EDIT_REPLACE,"Replace specific text with different text\nReplace");
   qtMfcStringResources.insert(ID_EDIT_SELECT_ALL,"Select the entire document\nSelect All");
   qtMfcStringResources.insert(ID_EDIT_UNDO,"Undo the last action\nUndo");
   qtMfcStringResources.insert(ID_EDIT_REDO,"Redo the previously undone action\nRedo");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_VIEW_TOOLBAR,"Show or hide the toolbar\nToggle Toolbar");
   qtMfcStringResources.insert(ID_VIEW_STATUS_BAR,"Show or hide the status bar\nToggle Status Bar");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(AFX_IDS_SCSIZE,"Change the window size");
   qtMfcStringResources.insert(AFX_IDS_SCMOVE,"Change the window position");
   qtMfcStringResources.insert(AFX_IDS_SCMINIMIZE,"Reduce the window to an icon");
   qtMfcStringResources.insert(AFX_IDS_SCMAXIMIZE,"Enlarge the window to full size");
   qtMfcStringResources.insert(AFX_IDS_SCNEXTWINDOW,"Switch to the next document window");
   qtMfcStringResources.insert(AFX_IDS_SCPREVWINDOW,"Switch to the previous document window");
   qtMfcStringResources.insert(AFX_IDS_SCCLOSE,"Close the active window and prompts to save the documents");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(AFX_IDS_SCRESTORE,"Restore the window to normal size");
   qtMfcStringResources.insert(AFX_IDS_SCTASKLIST,"Activate Task List");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_TRACKER_PLAY,"Play module\nPlay");
   qtMfcStringResources.insert(ID_TRACKER_PLAYPATTERN,"Play and loop current pattern\nPlay Pattern");
   qtMfcStringResources.insert(ID_TRACKER_STOP,"Stop playing\nStop");
   qtMfcStringResources.insert(ID_TRACKER_EDIT,"Enable / disable edit mode\nToggle Edit Mode");
   qtMfcStringResources.insert(ID_TRACKER_KILLSOUND,"Promptly stop all channels\nKill Sound");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_EDIT_DELETE,"Delete selection, or note if there is no selection\nDelete");
   qtMfcStringResources.insert(ID_TRACKER_NTSC,"Switch to NTSC emulation\nNTSC");
   qtMfcStringResources.insert(ID_TRACKER_PAL,"Switch to PAL emulation\nPAL");
   qtMfcStringResources.insert(ID_SPEED_CUSTOM,"Set the playback rate manually\nCustom");
   qtMfcStringResources.insert(ID_HELP_PERFORMANCE,"Display application performance\nPerformance");
   qtMfcStringResources.insert(ID_EDIT_PASTEOVERWRITE,"Pasted notes will overwrite existing notes\nPaste Overwrite");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_FILE_CREATE_NSF,"Bring up the create NSF dialog\nCreate NSF");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_TRANSPOSE_INCREASENOTE,"Increase selected note/notes by one step\nIncrease Note");
   qtMfcStringResources.insert(ID_TRANSPOSE_DECREASENOTE,"Decrease selected note/notes by one step\nDecrease Note");
   qtMfcStringResources.insert(ID_TRANSPOSE_INCREASEOCTAVE,"Increase selected octave/octaves by one step\nIncrease Octave");
   qtMfcStringResources.insert(ID_TRANSPOSE_DECREASEOCTAVE,"Decrease selected octave/octaves by one step\nDecrease Octave");
   qtMfcStringResources.insert(ID_EDIT_SELECTALL,"Select pattern or all patterns\nSelect All");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_FILE_GENERALSETTINGS,"Open j0CC-FamiTracker settings\nConfiguration");
   qtMfcStringResources.insert(ID_EDIT_ENABLEMIDI,"Temporarly enable / disable commands from the MIDI device\nEnable MIDI");
   qtMfcStringResources.insert(ID_TRACKER_PLAYROW,"Play a single row\nPlay Current Row");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_SPEED_DEFAULT,"Choose default playback rate corresponding to selected video standard\nDefault");
   qtMfcStringResources.insert(ID_MODULE_MODULEPROPERTIES,"Open the module properties window\nModule Properties");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(IDS_TYPE_INST_NUM,"Instrument number: %1");
   qtMfcStringResources.insert(IDS_INVALID_INST_NUM,"Invalid instrument number!");
   qtMfcStringResources.insert(IDS_EXPORT_SAMPLES_FILE,"\"%1\" already exists in the same directory as the music data file. Are you sure you want to overwrite it?");
   qtMfcStringResources.insert(IDS_MODULE_ERROR_NONE,"This build is not allowed to bypass validation of loaded modules.");
   qtMfcStringResources.insert(IDS_FIND_EDIT_DISABLED,"Replace will not work unless Edit Mode is enabled.");
   qtMfcStringResources.insert(IDS_FILE_LOAD_ERROR,"Couldn't load file properly. Make sure you have the latest version of j0CC-FamiTracker.");
   qtMfcStringResources.insert(IDS_CONFIG_WINDOW,"FamiTracker configuration");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_EDIT_PASTEMIX,"Pasted notes will mix with blank fields in destination\nPaste Mix");
   qtMfcStringResources.insert(ID_MODULE_MOVEFRAMEDOWN,"Move selected frame one step down\nMove Frame Down");
   qtMfcStringResources.insert(ID_MODULE_MOVEFRAMEUP,"Move selected frame one step up\nMove Frame Up");
   qtMfcStringResources.insert(ID_MODULE_SAVEINSTRUMENT,"Save instrument to file\nSave Instrument");
   qtMfcStringResources.insert(ID_MODULE_LOADINSTRUMENT,"Load instrument from file\nLoad Instrument");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_MODULE_ADDINSTRUMENT,"Add a new instrument to the module\nAdd Instrument");
   qtMfcStringResources.insert(ID_MODULE_REMOVEINSTRUMENT,"Remove instrument from module\nRemove Instrument");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_NEXT_SONG,"Select next song\nNext song");
   qtMfcStringResources.insert(ID_PREV_SONG,"Select previous song\nPrevious song");
   qtMfcStringResources.insert(ID_EDIT_INSTRUMENTMASK,"Disable writing to the instrument column while entering a note\nInstrument Mask");
   qtMfcStringResources.insert(ID_TRACKER_SWITCHTOTRACKINSTRUMENT,"Switch to channel instruments when playing\nSwitch to Track Instrument");
   qtMfcStringResources.insert(ID_FILE_CREATEWAV,"Save the file as a WAV-file\nCreate WAV");
   qtMfcStringResources.insert(ID_VIEW_CONTROLPANEL,"Show or hide the control panel\nToggle Control Panel");
   qtMfcStringResources.insert(ID_EDIT_CLEARPATTERNS,"Reset all patterns and frames\nClear Patterns");
   qtMfcStringResources.insert(ID_EDIT_INTERPOLATE,"Interpolate a selection between two values\nInterpolate");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_TRACKER_SOLOCHANNEL,"Mute / unmute all but the selected channel\nSolo Channel");
   qtMfcStringResources.insert(ID_TRACKER_TOGGLECHANNEL,"Mute / unmute selected channel\nToggle Channel");
   qtMfcStringResources.insert(ID_MODULE_EDITINSTRUMENT,"Open instrument editor\nEdit instrument");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(IDS_INFO_TITLE,"(title)");
   qtMfcStringResources.insert(IDS_INFO_AUTHOR,"(author)");
   qtMfcStringResources.insert(IDS_OUT_OF_SLOTS,"Out of sample slots");
   qtMfcStringResources.insert(IDS_OUT_OF_SAMPLEMEM_FORMAT,"Couldn't load sample, out of sample memory (max %1 kB is avaliable)");
   qtMfcStringResources.insert(IDS_DPCM_IMPORT_GAIN_FORMAT,"Gain: %1 dB");
   qtMfcStringResources.insert(IDS_OPEN_FILE_ERROR,"Could not open file: %1");
   qtMfcStringResources.insert(IDS_INFO_COPYRIGHT,"(copyright)");
   qtMfcStringResources.insert(IDS_IMPORT_FAILED,"Import module failed");
   qtMfcStringResources.insert(IDS_IMPORT_INSTRUMENT_COUNT,"Could not import all instruments, out of instrument slots!");
   qtMfcStringResources.insert(IDS_IMPORT_SAMPLE_SLOTS,"Could not import all samples, out of sample slots!");
   qtMfcStringResources.insert(IDS_DPCM_IMPORT_TITLE_FORMAT,"PCM Import (%1)");
   qtMfcStringResources.insert(IDS_DPCM_IMPORT_WAVE_FORMAT,"%1 Hz, %2 bits, %3");
   qtMfcStringResources.insert(IDS_DPCM_IMPORT_TARGET_FORMAT,"Target sample rate: %1 Hz");
   qtMfcStringResources.insert(IDS_PERFORMANCE_FRAMERATE_FORMAT,"Frame rate: %1 Hz");
   qtMfcStringResources.insert(IDS_PERFORMANCE_UNDERRUN_FORMAT,"Underruns: %1");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_MODULE_DUPLICATEFRAME,"Insert a copy of current frame\nDuplicate Frame");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_EDIT_REVERSE,"Reverse a selection\nReverse");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_INSTRUMENT_REMOVE,"Remove instrument from module\nRemove Instrument");
   qtMfcStringResources.insert(ID_INSTRUMENT_EDIT,"Open instrument edtor\nEdit Instrument");
   qtMfcStringResources.insert(ID_INSTRUMENT_CLONE,"Create a copy of selected instrument\nClone Instrument");
   qtMfcStringResources.insert(ID_FRAME_COPY,"Copy the selection and put it on the Clipboard\nCopy");
   qtMfcStringResources.insert(ID_FRAME_PASTE,"Insert Clipboard contents\nPaste");
   qtMfcStringResources.insert(ID_EDIT_REPLACEINSTRUMENT,"Replace all instruments in a selection with the selected instrument\nReplace Instrument");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_CLEANUP_REMOVEUNUSEDPATTERNS,"Remove all unused patterns\nRemove Unused Patterns");
   qtMfcStringResources.insert(ID_HELP_EFFECTTABLE,"Open help window with effect table\nEffect Table");
   qtMfcStringResources.insert(ID_CLEANUP_REMOVEUNUSEDINSTRUMENTS,"Remove all unused instruments\nRemove Unused Instruments");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_MODULE_REMOVEFRAME,"Remove selected frame\nRemove Frame");
   qtMfcStringResources.insert(ID_MODULE_COMMENTS,"Open module comments dialog\nComments");
   qtMfcStringResources.insert(ID_MODULE_INSERTFRAME,"Insert a new frame\nInsert Frame");
   qtMfcStringResources.insert(ID_INSTRUMENT_NEW,"Add a new instrument to the module\nAdd Instrument");
   qtMfcStringResources.insert(ID_INSTRUMENT_LOAD,"Load instrument from file\nLoad Instrument");
   qtMfcStringResources.insert(ID_INSTRUMENT_SAVE,"Save instrument to file\nSave Instrument");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(IDS_SAVE_ERROR,"Couldn't save file, check that it isn't write protected or shared with other applications and enough disk space is available.");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_MODULE_DUPLICATEFRAMEPATTERNS,"Insert a copy of current frame including all patterns\nDuplicate Patterns");
   qtMfcStringResources.insert(ID_EDIT_EXPANDPATTERNS,"Expand selected pattern by 2x\nExpand");
   qtMfcStringResources.insert(ID_EDIT_SHRINKPATTERNS,"Shrink selected pattern by 2x\nShrink");
   qtMfcStringResources.insert(ID_FRAMEEDITOR_TOP,"Move the frame editor to the top of the window (default)\nTop");
   qtMfcStringResources.insert(ID_FRAMEEDITOR_LEFT,"Move the frame editor to the left of the window\nLeft");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_DECAY_SLOW,"[Channel Headers] Volume meters slowly decrease over time\nSlow Decay Rate");
   qtMfcStringResources.insert(ID_DECAY_FAST,"[Channel Headers] Volume meters reflect instant channel amplitude\nFast Decay Rate");
   qtMfcStringResources.insert(ID_INSTRUMENT_DEEPCLONE,"Create a copy of selected instrument including all sequences\nDeep Clone Instrument");
   qtMfcStringResources.insert(ID_EDIT_FIND_TOGGLE,"Bring up the find / replace tab\nToggle Find / Replace Tab");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_TRACKER_PLAY_CURSOR,"Play pattern from cursor\nPlay from Cursor");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(IDS_CLEARPATTERN,"Do you want to reset all patterns and frames? There is no undo for this command.");
   qtMfcStringResources.insert(IDS_CLIPBOARD_COPY_ERROR,"An error occured while trying to copy data to the clipboard.");
   qtMfcStringResources.insert(IDS_CLIPBOARD_PASTE_ERROR,"An error occured while trying to paste data from the clipboard.");
   qtMfcStringResources.insert(IDS_DPCM_SPACE_FORMAT,"Space used %1 kB, left %2 kB (%3 kB available)");
   qtMfcStringResources.insert(IDS_INSTRUMENT_EDITOR_TITLE,"Instrument editor - %1");
   qtMfcStringResources.insert(IDS_INST_VERSION_UNSUPPORTED,"File version not supported!");
   qtMfcStringResources.insert(IDS_FILE_SAVED,"File saved (%1 bytes)");
   qtMfcStringResources.insert(IDS_MIDI_ERR_INPUT,"MIDI Error: Could not open MIDI input device!");
   qtMfcStringResources.insert(IDS_MIDI_ERR_OUTPUT,"MIDI Error: Could not open MIDI output device!");
   qtMfcStringResources.insert(IDS_NEW_SOUND_CONFIG,"New sound configuration has been loaded");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(IDS_REMOVE_INSTRUMENTS,"Do you want to remove all unused instruments? There is no undo for this command.");
   qtMfcStringResources.insert(IDS_REMOVE_PATTERNS,"Do you want to remove all unused patterns? There is no undo for this command.");
   qtMfcStringResources.insert(IDS_SONG_DELETE,"Do you want to delete the selected songs? There is no undo for this command.");
   qtMfcStringResources.insert(IDS_SOUND_FAIL,"It appears the current sound settings aren't working, change settings and try again.");
   qtMfcStringResources.insert(IDS_UNDERRUN_MESSAGE,"Warning: Audio buffer underrun, increase the audio buffer size!");
   qtMfcStringResources.insert(IDS_WELCOME_VER_FORMAT,"Welcome to j0CC-FamiTracker %1, press F1 for help");
   qtMfcStringResources.insert(IDS_DPCM_IMPORT_INVALID_WAVEFILE,"Cannot load this sample, file is invalid or incompatible. (Only uncompressed PCM is supported.)");
   qtMfcStringResources.insert(IDS_INST_FILE_ERROR,"Could not load instrument file! Check that you have the most recent version of j0CC-FamiTracker.");
   qtMfcStringResources.insert(IDS_NEW_2A03_INSTRUMENT,"New 2A03 instrument");
   qtMfcStringResources.insert(IDS_NEW_VRC6_INSTRUMENT,"New VRC6 instrument");
   qtMfcStringResources.insert(IDS_NEW_VRC7_INSTRUMENT,"New VRC7 instrument");
   qtMfcStringResources.insert(IDS_NEW_FDS_INSTRUMENT,"New FDS instrument");
   qtMfcStringResources.insert(IDS_NEW_N163_INSTRUMENT,"New Namco instrument");
   qtMfcStringResources.insert(IDS_NEW_S5B_INSTRUMENT,"New Sunsoft instrument");
   qtMfcStringResources.insert(IDS_FRAME_DROP_COPY_NEW,"Drop selection to copy frames to new pattern numbers");
   qtMfcStringResources.insert(IDS_FRAME_DROP_COPY,"Drop selection to copy frames");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_INDICATOR_CHIP,"No expansion chip");
   qtMfcStringResources.insert(ID_INDICATOR_INSTRUMENT,"Instrument: %1");
   qtMfcStringResources.insert(ID_INDICATOR_OCTAVE,"Octave: %1");
   qtMfcStringResources.insert(ID_INDICATOR_RATE,"000 Hz");
   qtMfcStringResources.insert(ID_INDICATOR_TEMPO,"000.00 BPM");
   qtMfcStringResources.insert(ID_INDICATOR_TIME,"00:00:00 ");
   qtMfcStringResources.insert(ID_INDICATOR_POS,"00 / 00    ");
   qtMfcStringResources.insert(ID_INDICATOR_DPCM_SEGMENT,"Segment: %1, length: %2");
   qtMfcStringResources.insert(ID_INDICATOR_DPCM_SIZE,"Size: %1 bytes");
   qtMfcStringResources.insert(ID_INDICATOR_DPCM_ENDPOS,"Delta end pos: %1");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_MODULE_DETUNE,"Open the detune settings dialog\nDetune Settings");
   qtMfcStringResources.insert(ID_MODULE_GROOVE,"Open the groove settings dialog\nGroove Settings");
   qtMfcStringResources.insert(ID_FILE_EXPORTROWS,"Dumps pattern data to comma-separated values\nExport Rows");
   qtMfcStringResources.insert(ID_MODULE_DUPLICATECURRENTPATTERN,"Duplicate the current pattern or all patterns selected in the frame editor\nClone Pattern");
   qtMfcStringResources.insert(ID_CLEANUP_REMOVEUNUSEDDPCMSAMPLES,"Remove all unised DPCM samples\nRemove Unused DPCM Samples");
   qtMfcStringResources.insert(ID_EDIT_PASTEINSERT,"Pasted notes will be inserted above the destination\nPaste Insert");
   qtMfcStringResources.insert(ID_PASTESPECIAL_CURSOR,"Paste operations occur at the cursor\nCursor");
   qtMfcStringResources.insert(ID_PASTESPECIAL_SELECTION,"Paste operations occur at the start of selection\nSelection");
   qtMfcStringResources.insert(ID_PASTESPECIAL_FILL,"Paste operations loop throughout the current selection\nFill");
   qtMfcStringResources.insert(ID_CLEANUP_POPULATEUNIQUEPATTERNS,"Copy a unique pattern for each frame\nPopulate Unique Patterns");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_HELP_FAQ,"Open help window with the FAQ\nFAQ");
   qtMfcStringResources.insert(ID_TRACKER_DISPLAYREGISTERSTATE,"Display channel register values and tuning information\nDisplay Register State");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(IDS_WAVE_PROGRESS_FILE_FORMAT,"Saving to: %1");
   qtMfcStringResources.insert(IDS_WAVE_PROGRESS_FRAME_FORMAT,"Frame: %1 (%2 done)");
   qtMfcStringResources.insert(IDS_WAVE_PROGRESS_TIME_FORMAT,"Time: %1 (%2 done)");
   qtMfcStringResources.insert(IDS_WAVE_PROGRESS_ELAPSED_FORMAT,"Elapsed time: %1");
   qtMfcStringResources.insert(IDS_DSOUND_ERROR,"DirectX: DirectSound error!");
   qtMfcStringResources.insert(IDS_DSOUND_BUFFER_ERROR,"DirectX: DirectSound error: Could not create buffer!");
   qtMfcStringResources.insert(IDS_EDIT_MODE,"Changed to edit mode");
   qtMfcStringResources.insert(IDS_NORMAL_MODE,"Changed to normal mode");
   qtMfcStringResources.insert(IDS_MIDI_MESSAGE_ON_FORMAT,"MIDI message: Note on (note = %1, octave = %2, velocity = %3)");
   qtMfcStringResources.insert(IDS_MIDI_MESSAGE_OFF,"MIDI message: Note off");
   qtMfcStringResources.insert(IDS_WAVE_PROGRESS_ROW_FORMAT,"Row: %1 (%2 done)");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(IDS_LOADING_FILE,"Loading file...");
   qtMfcStringResources.insert(IDS_FILTER_DMC,"Delta modulated samples (*.dmc)");
   qtMfcStringResources.insert(IDS_FILTER_WAV,"Waveform Audio File Format (*.wav)");
   qtMfcStringResources.insert(IDS_FILTER_TXT,"Text files (*.txt)");
   qtMfcStringResources.insert(IDS_DPCM_EDIT_INFO_FORMAT,"Wave end: %1, Size: %2 bytes ");
   qtMfcStringResources.insert(IDS_WAVE_EXPORT_DONE,"Done");
   qtMfcStringResources.insert(IDS_WAVE_EXPORT_FINISHED,"finished");
   qtMfcStringResources.insert(IDS_ABOUT_TOOLTIP_MAIL,"Send mail to nicetas.c@gmail.com");
   qtMfcStringResources.insert(IDS_ABOUT_TOOLTIP_WEB,"Go to http://hertzdevil.info/programs/");
   qtMfcStringResources.insert(IDS_ABOUT_VERSION_FORMAT,"j0CC-FamiTracker version %1");
   qtMfcStringResources.insert(IDS_PROPERTIES_CHANNELS,"Channels:");
   qtMfcStringResources.insert(IDS_LOADING_DONE,"File loaded");
   qtMfcStringResources.insert(IDS_DPCM_IMPORT_SIZE_FORMAT,"Converted size: %1 bytes");
   qtMfcStringResources.insert(IDS_INSTRUMENT_FOLDER,"Choose a folder where you have instrument files");
   qtMfcStringResources.insert(IDS_IMPORT_GROOVE_SLOTS,"Could not import all grooves, out of groove slots!");
   qtMfcStringResources.insert(IDS_REMOVE_SAMPLES,"Do you want to remove all unused DPCM samples and DPCM assignments? There is no undo for this command.");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_FILE_IMPORTTEXT,"Imports module text files\nImport Text");
   qtMfcStringResources.insert(ID_FILE_EXPORTTEXT,"Exports module as a text file\nExport Text");
   qtMfcStringResources.insert(ID_CLEANUP_MERGEDUPLICATEDPATTERNS,"Combine copies of duplicated patterns\nMerge Duplicated Patterns");
   qtMfcStringResources.insert(ID_EDIT_VOLUMEMASK,"Disable writing to the volume column while entering a note\nVolume Mark");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(IDS_KRAID,"Do you want to carry out this operation? There is no undo for this command.");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_EDIT_STRETCHPATTERNS,"Stretch the current selection\nStretch");
   qtMfcStringResources.insert(IDC_COMPACT_TOGGLE,"Hide all columns except the note column");
   qtMfcStringResources.insert(ID_SELECT_NONE,"Clear the current selection\nDeselect");
   qtMfcStringResources.insert(ID_SELECT_ROW,"Select the current row\nSelect Row");
   qtMfcStringResources.insert(ID_SELECT_PATTERN,"Select the current patterm\nSelect Pattern");
   qtMfcStringResources.insert(ID_SELECT_FRAME,"Select the current frame\nSelect Frame");
   qtMfcStringResources.insert(ID_SELECT_CHANNEL,"Select the current channel\nSelect Channel");
   qtMfcStringResources.insert(ID_SELECT_TRACK,"Select the entire track\nSelect Track");
   qtMfcStringResources.insert(ID_SELECT_COLUMN,"Select the entire column in the current pattern\nSelect Column");
   qtMfcStringResources.insert(ID_COPYAS_TEXT,"Copy the current selection as pretty-printed text\nCopy As Text");
   qtMfcStringResources.insert(ID_COPYAS_VOLUMESEQUENCE,"Copy the volume sequence in the first selected channel\nCopy As Volume Sequence");
   qtMfcStringResources.insert(ID_COPYAS_PPMCK,"Copy the current selection as a PPMCK-compatible MML data\nCopy As PPMCK Data");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_FRAME_CUT,"Cut the selection and put it on the Clipboard\nCut");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_POPUP_PICKUPROW,"Select current row's instrument\nPick Up Row");
   qtMfcStringResources.insert(ID_POPUP_UNMUTEALLCHANNELS,"Unmute all channel\nUnmute all channels");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(IDC_FOLLOW_TOGGLE,"Make the cursor follow the currently played row");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_EDIT_GOTO,"Go to the specified position in the current track\nGo To");
   qtMfcStringResources.insert(ID_MODULE_BOOKMARK,"Open the bookmark settings dialog\nBookmark Manager");
   qtMfcStringResources.insert(ID_BOOKMARKS_TOGGLE,"Create or delete a bookmark on the current row\nToggle Bookmark");
   qtMfcStringResources.insert(ID_BOOKMARKS_PREVIOUS,"Navigate to the previous bookmark\nPrevious Bookmark");
   qtMfcStringResources.insert(ID_BOOKMARKS_NEXT,"Navigate to the next bookmark\nNext Bookmark");
   qtMfcStringResources.insert(ID_EDIT_SWAPCHANNELS,"Exchange the position of two channels\nSwap Channels");
   qtMfcStringResources.insert(ID_TRACKER_RECORDTOINST,"Create a new instrument by logging output from current channel\nRecord to Instrument");
   qtMfcStringResources.insert(ID_TRACKER_RECORDERSETTINGS,"Open the instrument recorder settings dialog\nRecorder Settings");
   qtMfcStringResources.insert(ID_TRANSPOSE_CUSTOM,"Transpose song by custom amount\nTranspose Song");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(ID_TRACKER_TOGGLECHIP,"Mute / unmute selected sound chip\nToggle Chip");
   qtMfcStringResources.insert(ID_TRACKER_SOLOCHIP,"Mute / unmute all but the selected sound chip\nSolo Chip");
   qtMfcStringResources.insert(ID_MODULE_LINEARPITCH,"Enable linear pitch bends\nLinear Pitch Mode");
   qtMfcStringResources.insert(ID_RECENTFILES_CLEAR,"Clear the recent file list\nClear Recent File List");
   qtMfcStringResources.insert(ID_EDIT_SPLITKEYBOARD,"Open the split keyboard settings dialog\nSplit Keyboard");
   qtMfcStringResources.insert(ID_VIEW_AVERAGEBPM,"[Status Bar] Display average BPM value instead of instant BPM value\nDisplay Average BPM");
   qtMfcStringResources.insert(ID_TRACKER_PLAY_MARKER,"Play pattern from row marker\nPlay from Marker");
   qtMfcStringResources.insert(ID_TRACKER_SET_MARKER,"Set a row marker for playback\nSet Row Marker");
   qtMfcStringResources.insert(ID_SELECT_OTHER,"Restore the current selection in the inactive editor window\nSelect in Other Editor");
   // END


	// STRINGTABLE
	// BEGIN
   qtMfcStringResources.insert(IDS_FIND_BEGIN,"Begin");
   qtMfcStringResources.insert(IDS_FIND_END,"(End)");
   // END


	// AFX resources
	qtMfcStringResources.insert(AFX_IDS_ALLFILTER,"All files|");
	qtMfcStringResources.insert(AFX_IDS_OPENFILE,"Open");
	qtMfcStringResources.insert(AFX_IDS_SAVEFILE,"Save As");
	qtMfcStringResources.insert(AFX_IDS_SAVEFILECOPY,"Save As");
	qtMfcStringResources.insert(AFX_IDS_UNTITLED,"Untitled");
	qtMfcStringResources.insert(AFX_IDP_ASK_TO_SAVE,"Save changes to %s?");
	qtMfcStringResources.insert(AFX_IDP_FAILED_TO_CREATE_DOC,"Failed to create empty document.");
}


// IDR_MAINFRAME ACCELERATORS
ACCEL ACCEL_IDR_MAINFRAME[] =
{
	// BEGIN
   // 'C', ID_EDIT_COPY, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'C', ID_EDIT_COPY },

   // VK_INSERT, ID_EDIT_COPY, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, VK_INSERT, ID_EDIT_COPY },

   // 'X', ID_EDIT_CUT, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'X', ID_EDIT_CUT },

   // 'V', ID_EDIT_PASTE, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'V', ID_EDIT_PASTE },

   // VK_INSERT, ID_EDIT_PASTE, FVIRTKEY|FSHIFT|FNOINVERT
	{ FVIRTKEY|FSHIFT|FNOINVERT, VK_INSERT, ID_EDIT_PASTE },

   // 'Y', ID_EDIT_REDO, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'Y', ID_EDIT_REDO },

   // VK_BACK, ID_EDIT_UNDO, FVIRTKEY|FALT|FNOINVERT
	{ FVIRTKEY|FALT|FNOINVERT, VK_BACK, ID_EDIT_UNDO },

   // 'Z', ID_EDIT_UNDO, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'Z', ID_EDIT_UNDO },

   // VK_F4, ID_FILE_CLOSE, FVIRTKEY|FALT|FNOINVERT
	{ FVIRTKEY|FALT|FNOINVERT, VK_F4, ID_FILE_CLOSE },

   // 'E', ID_FILE_CREATE_NSF, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'E', ID_FILE_CREATE_NSF },

   // 'N', ID_FILE_NEW, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'N', ID_FILE_NEW },

   // 'O', ID_FILE_OPEN, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'O', ID_FILE_OPEN },

   // 'S', ID_FILE_SAVE, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'S', ID_FILE_SAVE },

   // VK_F1, ID_HELP, FVIRTKEY|FNOINVERT
	{ FVIRTKEY|FNOINVERT, VK_F1, ID_HELP },

   // 'K', ID_KRAID1, FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL
	{ FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL, 'K', ID_KRAID1 },

   // 'R', ID_KRAID2, FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL
	{ FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL, 'R', ID_KRAID2 },

   // 'A', ID_KRAID3, FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL
	{ FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL, 'A', ID_KRAID3 },

   // 'I', ID_KRAID4, FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL
	{ FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL, 'I', ID_KRAID4 },

   // 'D', ID_KRAID5, FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL
	{ FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL, 'D', ID_KRAID5 },

   // 'P', ID_MODULE_MODULEPROPERTIES, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'P', ID_MODULE_MODULEPROPERTIES },

   // 'M', ID_TOGGLE_MULTIPLEXER, FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL
	{ FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL, 'M', ID_TOGGLE_MULTIPLEXER },

   // 'S', ID_TOGGLE_SPEED, FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL
	{ FVIRTKEY|FSHIFT|FNOINVERT|FCONTROL, 'S', ID_TOGGLE_SPEED },

   // VK_F12, ID_TRACKER_KILLSOUND, FVIRTKEY|FNOINVERT
	{ FVIRTKEY|FNOINVERT, VK_F12, ID_TRACKER_KILLSOUND },

   // END
	{ 0, 0, 0 },
};


// IDR_FRAMEWND ACCELERATORS
ACCEL ACCEL_IDR_FRAMEWND[] =
{
	// BEGIN
   // 'C', ID_EDIT_COPY, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'C', ID_EDIT_COPY },

   // VK_DELETE, ID_EDIT_DELETE, FVIRTKEY|FNOINVERT
	{ FVIRTKEY|FNOINVERT, VK_DELETE, ID_EDIT_DELETE },

   // 'V', ID_EDIT_PASTE, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'V', ID_EDIT_PASTE },

   // 'Y', ID_EDIT_REDO, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'Y', ID_EDIT_REDO },

   // 'Z', ID_EDIT_UNDO, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'Z', ID_EDIT_UNDO },

   // VK_DOWN, ID_MODULE_MOVEFRAMEDOWN, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, VK_DOWN, ID_MODULE_MOVEFRAMEDOWN },

   // VK_UP, ID_MODULE_MOVEFRAMEUP, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, VK_UP, ID_MODULE_MOVEFRAMEUP },

   // 'X', ID_EDIT_CUT, FVIRTKEY|FNOINVERT|FCONTROL
	{ FVIRTKEY|FNOINVERT|FCONTROL, 'X', ID_EDIT_CUT },

   // END
	{ 0, 0, 0 },
};


ACCEL* qtMfcAcceleratorResource(UINT id)
{
	switch ( id )
	{
      case IDR_MAINFRAME:
			return ACCEL_IDR_MAINFRAME;
			break;

      case IDR_FRAMEWND:
			return ACCEL_IDR_FRAMEWND;
			break;

   }
	return NULL;
}


void qtMfcInitBitmapResources()
{
	qtMfcBitmapResources.clear();

   // IDR_MAINFRAME BITMAP ":/resources/"MainToolbar-16.bmp"
	qtMfcBitmapResources.insert(IDR_MAINFRAME,new CBitmap(":/resources/"MainToolbar-16.bmp"));

   // IDR_INSTRUMENT_TOOLBAR BITMAP ":/resources/"InstrumentToolbar-16.bmp"
	qtMfcBitmapResources.insert(IDR_INSTRUMENT_TOOLBAR,new CBitmap(":/resources/"InstrumentToolbar-16.bmp"));

   // IDB_KEY_BLACK BITMAP ":/resources/"key_black_unpressed.bmp"
	qtMfcBitmapResources.insert(IDB_KEY_BLACK,new CBitmap(":/resources/"key_black_unpressed.bmp"));

   // IDB_KEY_BLACK_MARK BITMAP ":/resources/"key_black_pressed.bmp"
	qtMfcBitmapResources.insert(IDB_KEY_BLACK_MARK,new CBitmap(":/resources/"key_black_pressed.bmp"));

   // IDB_KEY_WHITE BITMAP ":/resources/"key_white_unpressed.bmp"
	qtMfcBitmapResources.insert(IDB_KEY_WHITE,new CBitmap(":/resources/"key_white_unpressed.bmp"));

   // IDB_KEY_WHITE_MARK BITMAP ":/resources/"key_white_pressed.bmp"
	qtMfcBitmapResources.insert(IDB_KEY_WHITE_MARK,new CBitmap(":/resources/"key_white_pressed.bmp"));

   // IDB_TOOLBAR_256 BITMAP ":/resources/"MainToolbar-256.bmp"
	qtMfcBitmapResources.insert(IDB_TOOLBAR_256,new CBitmap(":/resources/"MainToolbar-256.bmp"));

   // IDB_TOOLBAR_INST_256 BITMAP ":/resources/"InstrumentToolbar-256.bmp"
	qtMfcBitmapResources.insert(IDB_TOOLBAR_INST_256,new CBitmap(":/resources/"InstrumentToolbar-256.bmp"));

   // IDB_ABOUT BITMAP ":/resources/"About.bmp"
	qtMfcBitmapResources.insert(IDB_ABOUT,new CBitmap(":/resources/"About.bmp"));

}


void qtInitIconResources()
{
	qtIconNames.clear();
	qtIconResources.clear();

	// Icon with lowest ID value placed first to ensure application icon
	// remains consistent on all systems.

   // IDR_MAINFRAME ICON ":/resources/"Application.ico"
	qtIconNames.insert(IDR_MAINFRAME,":/resources/"Application.ico");

   // IDI_INST_2A03 ICON ":/resources/"Inst_2A03.ico"
	qtIconNames.insert(IDI_INST_2A03,":/resources/"Inst_2A03.ico");

   // IDI_INST_VRC6 ICON ":/resources/"Inst_VRC6.ico"
	qtIconNames.insert(IDI_INST_VRC6,":/resources/"Inst_VRC6.ico");

   // IDI_INST_VRC7 ICON ":/resources/"Inst_VRC7.ico"
	qtIconNames.insert(IDI_INST_VRC7,":/resources/"Inst_VRC7.ico");

   // IDR_FamiTrackerTYPE ICON ":/resources/"Document.ico"
	qtIconNames.insert(IDR_FamiTrackerTYPE,":/resources/"Document.ico");

   // IDI_INST_N163 ICON ":/resources/"Inst_N163.ico"
	qtIconNames.insert(IDI_INST_N163,":/resources/"Inst_N163.ico");

   // IDI_INST_FDS ICON ":/resources/"Inst_FDS.ico"
	qtIconNames.insert(IDI_INST_FDS,":/resources/"Inst_FDS.ico");

   // IDI_INST_S5B ICON ":/resources/"Inst_S5B.ico"
	qtIconNames.insert(IDI_INST_S5B,":/resources/"Inst_S5B.ico");

   // IDI_INST_2A07 ICON ":/resources/"Inst_2A07.ico"
	qtIconNames.insert(IDI_INST_2A07,":/resources/"Inst_2A07.ico");

   // IDI_LEFT ICON ":/resources/"LeftArrow.ico"
	qtIconNames.insert(IDI_LEFT,":/resources/"LeftArrow.ico");

   // IDI_RIGHT ICON ":/resources/"RightArrow.ico"
	qtIconNames.insert(IDI_RIGHT,":/resources/"RightArrow.ico");

}


void qtMfcInitDialogResource_IDD_ABOUTBOX(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_ABOUTBOX DIALOGEX 0, 0, 285, 334
	CRect rect(CPoint(0,0),CSize(285,334));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "About j0CC-FamiTracker"
	parent->SetWindowText("About j0CC-FamiTracker");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|DS_CENTER|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // CONTROL "", IDC_HEAD, "Static", WS_VISIBLE|WS_BORDER|SS_OWNERDRAW, 0, 0, 287, 49
	CStatic* mfc0 = new CStatic(parent);
	CRect r0(CPoint(0, 0), CSize(287, 49));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_OWNERDRAW, r0, parent, IDC_HEAD);
	mfcToQtWidget->insert(IDC_HEAD, mfc0);

   // CONTROL "", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, 0, 49, 287, 1
	CStatic* mfc1 = new CStatic(parent);
	CRect r1(CPoint(0, 49), CSize(287, 1));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, r1, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc1);

   // LTEXT "j0CC-FamiTracker",IDC_ABOUT1,54,58,219,11
	CStatic* mfc3 = new CStatic(parent);
	CRect r3(CPoint(54,58),CSize(219,11));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("j0CC-FamiTracker"),WS_VISIBLE|WS_BORDER|SS_NOPREFIX,r3,parent,IDC_ABOUT1);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "jimbo1qaz's Mod of 0CC-FamiTracker",IDC_ABOUT2,54,76,167,11
	CStatic* mfc4 = new CStatic(parent);
	CRect r4(CPoint(54,76),CSize(167,11));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("jimbo1qaz's Mod of 0CC-FamiTracker"),WS_VISIBLE|WS_BORDER|SS_NOPREFIX,r4,parent,IDC_ABOUT2);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Copyright (C) 2005 - 2015 jsr, 2014 - 2016 HertzDevil",IDC_ABOUT3,54,92,215,11
	CStatic* mfc5 = new CStatic(parent);
	CRect r5(CPoint(54,92),CSize(215,11));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Copyright (C) 2005 - 2015 jsr, 2014 - 2016 HertzDevil"),WS_VISIBLE|WS_BORDER,r5,parent,IDC_ABOUT3);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "E-mail:",IDC_STATIC,54,107,24,10
	CStatic* mfc6 = new CStatic(parent);
	CRect r6(CPoint(54,107),CSize(24,10));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("E-mail:"),WS_VISIBLE|WS_BORDER,r6,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "nicetas.c@gmail.com",IDC_MAIL,84,107,70,10
	CStatic* mfc7 = new CStatic(parent);
	CRect r7(CPoint(84,107),CSize(70,10));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("nicetas.c@gmail.com"),WS_VISIBLE|WS_BORDER|SS_NOTIFY,r7,parent,IDC_MAIL);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Web:",IDC_STATIC,54,117,24,9
	CStatic* mfc8 = new CStatic(parent);
	CRect r8(CPoint(54,117),CSize(24,9));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Web:"),WS_VISIBLE|WS_BORDER,r8,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "http://hertzdevil.info/programs/",IDC_WEBPAGE,84,117,154,9
	CStatic* mfc9 = new CStatic(parent);
	CRect r9(CPoint(84,117),CSize(154,9));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("http://hertzdevil.info/programs/"),WS_VISIBLE|WS_BORDER|SS_NOTIFY,r9,parent,IDC_WEBPAGE);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "http://hertzdevil.info/bug/main_page.php",IDC_BUG,84,127,154,9
	CStatic* mfc10 = new CStatic(parent);
	CRect r10(CPoint(84,127),CSize(154,9));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("http://hertzdevil.info/bug/main_page.php"),WS_VISIBLE|WS_BORDER|SS_NOTIFY,r10,parent,IDC_BUG);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "All comments and feedback are welcome\nGreets to everyone who has helped spread information about this mod or contributed with bug reports and suggestions!",IDC_STATIC,54,142,224,26
	CStatic* mfc11 = new CStatic(parent);
	CRect r11(CPoint(54,142),CSize(224,26));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T("All comments and feedback are welcome\nGreets to everyone who has helped spread information about this mod or contributed with bug reports and suggestions!"),WS_VISIBLE|WS_BORDER,r11,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "This software is licensed under the GNU General Public License.\nSource is available on Github.",IDC_STATIC,54,173,224,17
	CStatic* mfc12 = new CStatic(parent);
	CRect r12(CPoint(54,173),CSize(224,17));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T("This software is licensed under the GNU General Public License.\nSource is available on Github."),WS_VISIBLE|WS_BORDER,r12,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Contributions:",IDC_STATIC,54,196,224,9
	CStatic* mfc13 = new CStatic(parent);
	CRect r13(CPoint(54,196),CSize(224,9));
	parent->MapDialogRect(&r13);
	mfc13->Create(_T("Contributions:"),WS_VISIBLE|WS_BORDER,r13,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, 54, 207, 215, 1
	CStatic* mfc14 = new CStatic(parent);
	CRect r14(CPoint(54, 207), CSize(215, 1));
	parent->MapDialogRect(&r14);
	mfc14->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, r14, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc14);

   // EDITTEXT IDC_ABOUT_CONTRIB,54,210,225,51,WS_VISIBLE|ES_MULTILINE|ES_READONLY
	CEdit* mfc15 = new CEdit(parent);
	CRect r15(CPoint(54,210),CSize(225,51));
	parent->MapDialogRect(&r15);
	mfc15->Create(WS_VISIBLE|ES_MULTILINE|ES_READONLY,r15,parent,IDC_ABOUT_CONTRIB);
	mfcToQtWidget->insert(IDC_ABOUT_CONTRIB,mfc15);

   // LTEXT "Libraries:",IDC_STATIC,54,264,224,8
	CStatic* mfc16 = new CStatic(parent);
	CRect r16(CPoint(54,264),CSize(224,8));
	parent->MapDialogRect(&r16);
	mfc16->Create(_T("Libraries:"),WS_VISIBLE|WS_BORDER,r16,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, 54, 274, 215, 1
	CStatic* mfc17 = new CStatic(parent);
	CRect r17(CPoint(54, 274), CSize(215, 1));
	parent->MapDialogRect(&r17);
	mfc17->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, r17, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc17);

   // EDITTEXT IDC_ABOUT_LIB,54,277,225,49,WS_VISIBLE|ES_MULTILINE|ES_READONLY
	CEdit* mfc18 = new CEdit(parent);
	CRect r18(CPoint(54,277),CSize(225,49));
	parent->MapDialogRect(&r18);
	mfc18->Create(WS_VISIBLE|ES_MULTILINE|ES_READONLY,r18,parent,IDC_ABOUT_LIB);
	mfcToQtWidget->insert(IDC_ABOUT_LIB,mfc18);

   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER|WS_GROUP,7,105,39,16
	CButton* mfc19 = new CButton(parent);
	CRect r19(CPoint(7,105),CSize(39,16));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER|WS_GROUP,r19,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc19);

   // END
}


void qtMfcInitDialogResource_IDD_MAINFRAME(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_MAINFRAME DIALOGEX 0, 0, 405, 126
	CRect rect(CPoint(0,0),CSize(405,126));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());




   // BEGIN
   // GROUPBOX "Song settings",IDC_STATIC,7,5,78,71
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,5),CSize(78,71));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Song settings"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Edit settings",IDC_STATIC,7,78,78,43
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7,78),CSize(78,43));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Edit settings"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER|0,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Song information",IDC_STATIC,91,5,124,61
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(91,5),CSize(124,61));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Song information"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Songs",IDC_STATIC,91,94,124,27
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(91,94),CSize(124,27));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Songs"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r3,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_SPEED,43,15,38,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY|ES_NUMBER
	CEdit* mfc5 = new CEdit(parent);
	CRect r5(CPoint(43,15),CSize(38,12));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY|ES_NUMBER,r5,parent,IDC_SPEED);
	mfcToQtWidget->insert(IDC_SPEED,mfc5);

   // CONTROL "", IDC_SPEED_SPIN, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 81, 15, 11, 13
	CSpinButtonCtrl* mfc6 = new CSpinButtonCtrl(parent);
	CRect r6(CPoint(81, 15), CSize(11, 13));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r6, parent, IDC_SPEED_SPIN);
	mfcToQtWidget->insert(IDC_SPEED_SPIN, mfc6);

   // EDITTEXT IDC_TEMPO,43,29,38,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY
	CEdit* mfc7 = new CEdit(parent);
	CRect r7(CPoint(43,29),CSize(38,12));
	parent->MapDialogRect(&r7);
	mfc7->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY,r7,parent,IDC_TEMPO);
	mfcToQtWidget->insert(IDC_TEMPO,mfc7);

   // CONTROL "", IDC_TEMPO_SPIN, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 81, 28, 11, 13
	CSpinButtonCtrl* mfc8 = new CSpinButtonCtrl(parent);
	CRect r8(CPoint(81, 28), CSize(11, 13));
	parent->MapDialogRect(&r8);
	mfc8->Create(WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r8, parent, IDC_TEMPO_SPIN);
	mfcToQtWidget->insert(IDC_TEMPO_SPIN, mfc8);

   // LTEXT "Rows",IDC_STATIC,13,45,29,10
	CStatic* mfc9 = new CStatic(parent);
	CRect r9(CPoint(13,45),CSize(29,10));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("Rows"),WS_VISIBLE|WS_BORDER,r9,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_ROWS,43,43,38,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY|ES_WANTRETURN
	CEdit* mfc10 = new CEdit(parent);
	CRect r10(CPoint(43,43),CSize(38,12));
	parent->MapDialogRect(&r10);
	mfc10->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY|ES_WANTRETURN,r10,parent,IDC_ROWS);
	mfcToQtWidget->insert(IDC_ROWS,mfc10);

   // CONTROL "", IDC_ROWS_SPIN, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 81, 43, 11, 13
	CSpinButtonCtrl* mfc11 = new CSpinButtonCtrl(parent);
	CRect r11(CPoint(81, 43), CSize(11, 13));
	parent->MapDialogRect(&r11);
	mfc11->Create(WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r11, parent, IDC_ROWS_SPIN);
	mfcToQtWidget->insert(IDC_ROWS_SPIN, mfc11);

   // LTEXT "Frames",IDC_STATIC,13,59,29,10
	CStatic* mfc12 = new CStatic(parent);
	CRect r12(CPoint(13,59),CSize(29,10));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T("Frames"),WS_VISIBLE|WS_BORDER,r12,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_FRAMES,43,57,38,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY
	CEdit* mfc13 = new CEdit(parent);
	CRect r13(CPoint(43,57),CSize(38,12));
	parent->MapDialogRect(&r13);
	mfc13->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY,r13,parent,IDC_FRAMES);
	mfcToQtWidget->insert(IDC_FRAMES,mfc13);

   // CONTROL "", IDC_FRAME_SPIN, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 81, 58, 11, 13
	CSpinButtonCtrl* mfc14 = new CSpinButtonCtrl(parent);
	CRect r14(CPoint(81, 58), CSize(11, 13));
	parent->MapDialogRect(&r14);
	mfc14->Create(WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r14, parent, IDC_FRAME_SPIN);
	mfcToQtWidget->insert(IDC_FRAME_SPIN, mfc14);

   // LTEXT "Step",IDC_STATIC,13,91,29,10
	CStatic* mfc16 = new CStatic(parent);
	CRect r16(CPoint(13,91),CSize(29,10));
	parent->MapDialogRect(&r16);
	mfc16->Create(_T("Step"),WS_VISIBLE|WS_BORDER|0,r16,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_KEYSTEP,43,90,38,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY
	CEdit* mfc17 = new CEdit(parent);
	CRect r17(CPoint(43,90),CSize(38,12));
	parent->MapDialogRect(&r17);
	mfc17->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY,r17,parent,IDC_KEYSTEP);
	mfcToQtWidget->insert(IDC_KEYSTEP,mfc17);

   // CONTROL "", IDC_KEYSTEP_SPIN, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 81, 88, 11, 13
	CSpinButtonCtrl* mfc18 = new CSpinButtonCtrl(parent);
	CRect r18(CPoint(81, 88), CSize(11, 13));
	parent->MapDialogRect(&r18);
	mfc18->Create(WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r18, parent, IDC_KEYSTEP_SPIN);
	mfcToQtWidget->insert(IDC_KEYSTEP_SPIN, mfc18);

   // CONTROL "Key repetition", IDC_KEYREPEAT, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 13, 105, 68, 9
	CButton* mfc19 = new CButton(parent);
	CRect r19(CPoint(13, 105), CSize(68, 9));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("Key repetition"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r19, parent, IDC_KEYREPEAT);
	mfcToQtWidget->insert(IDC_KEYREPEAT, mfc19);

   // EDITTEXT IDC_SONG_NAME,97,18,111,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc21 = new CEdit(parent);
	CRect r21(CPoint(97,18),CSize(111,12));
	parent->MapDialogRect(&r21);
	mfc21->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r21,parent,IDC_SONG_NAME);
	mfcToQtWidget->insert(IDC_SONG_NAME,mfc21);

   // EDITTEXT IDC_SONG_ARTIST,97,33,111,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc22 = new CEdit(parent);
	CRect r22(CPoint(97,33),CSize(111,12));
	parent->MapDialogRect(&r22);
	mfc22->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r22,parent,IDC_SONG_ARTIST);
	mfcToQtWidget->insert(IDC_SONG_ARTIST,mfc22);

   // EDITTEXT IDC_SONG_COPYRIGHT,97,49,111,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc23 = new CEdit(parent);
	CRect r23(CPoint(97,49),CSize(111,12));
	parent->MapDialogRect(&r23);
	mfc23->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r23,parent,IDC_SONG_COPYRIGHT);
	mfcToQtWidget->insert(IDC_SONG_COPYRIGHT,mfc23);

   // COMBOBOX IDC_SUBTUNE,97,104,112,85,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc25 = new CComboBox(parent);
	CRect r25(CPoint(97,104),CSize(112,85));
	parent->MapDialogRect(&r25);
	mfc25->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r25,parent,IDC_SUBTUNE);
	mfcToQtWidget->insert(IDC_SUBTUNE,mfc25);

   // CONTROL "", IDC_INSTRUMENTS, "SysListView32", WS_VISIBLE|WS_BORDER|LVS_LIST|LVS_SINGLESEL|LVS_SHOWSELALWAYS|LVS_EDITLABELS|LVS_ALIGNLEFT|LVS_NOCOLUMNHEADER|LVS_NOSORTHEADER|WS_BORDER|WS_TABSTOP, 221, 5, 178, 97
	CListCtrl* mfc26 = new CListCtrl(parent);
	CRect r26(CPoint(221, 5), CSize(178, 97));
	parent->MapDialogRect(&r26);
	mfc26->Create(WS_VISIBLE|WS_BORDER|LVS_LIST|LVS_SINGLESEL|LVS_SHOWSELALWAYS|LVS_EDITLABELS|LVS_ALIGNLEFT|LVS_NOCOLUMNHEADER|LVS_NOSORTHEADER|WS_BORDER|WS_TABSTOP, r26, parent, IDC_INSTRUMENTS);
	mfcToQtWidget->insert(IDC_INSTRUMENTS, mfc26);

   // EDITTEXT IDC_INSTNAME,351,108,48,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc27 = new CEdit(parent);
	CRect r27(CPoint(351,108),CSize(48,12));
	parent->MapDialogRect(&r27);
	mfc27->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r27,parent,IDC_INSTNAME);
	mfcToQtWidget->insert(IDC_INSTNAME,mfc27);

   // PUSHBUTTON "Speed",IDC_BUTTON_GROOVE,12,14,30,13,WS_VISIBLE|WS_BORDER
	CButton* mfc28 = new CButton(parent);
	CRect r28(CPoint(12,14),CSize(30,13));
	parent->MapDialogRect(&r28);
	mfc28->Create(_T("Speed"),WS_VISIBLE|WS_BORDER,r28,parent,IDC_BUTTON_GROOVE);
	mfcToQtWidget->insert(IDC_BUTTON_GROOVE,mfc28);

   // PUSHBUTTON "Tempo",IDC_BUTTON_FIXTEMPO,12,28,30,13,WS_VISIBLE|WS_BORDER
	CButton* mfc29 = new CButton(parent);
	CRect r29(CPoint(12,28),CSize(30,13));
	parent->MapDialogRect(&r29);
	mfc29->Create(_T("Tempo"),WS_VISIBLE|WS_BORDER,r29,parent,IDC_BUTTON_FIXTEMPO);
	mfcToQtWidget->insert(IDC_BUTTON_FIXTEMPO,mfc29);

   // CONTROL "", IDC_MAINFRAME_VISUALIZER, "Static", WS_BORDER|SS_BLACKFRAME, 91, 69, 124, 25
	CStatic* mfc30 = new CStatic(parent);
	CRect r30(CPoint(91, 69), CSize(124, 25));
	parent->MapDialogRect(&r30);
	mfc30->Create(_T(""), WS_BORDER|SS_BLACKFRAME, r30, parent, IDC_MAINFRAME_VISUALIZER);
	mfcToQtWidget->insert(IDC_MAINFRAME_VISUALIZER, mfc30);

   // CONTROL "", IDC_MAINFRAME_INST_TOOLBAR, "Static", WS_BORDER|SS_BLACKFRAME, 221, 106, 124, 16
	CStatic* mfc31 = new CStatic(parent);
	CRect r31(CPoint(221, 106), CSize(124, 16));
	parent->MapDialogRect(&r31);
	mfc31->Create(_T(""), WS_BORDER|SS_BLACKFRAME, r31, parent, IDC_MAINFRAME_INST_TOOLBAR);
	mfcToQtWidget->insert(IDC_MAINFRAME_INST_TOOLBAR, mfc31);

   // END
}


void qtMfcInitDialogResource_IDD_PCMIMPORT(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_PCMIMPORT DIALOGEX 0, 0, 211, 144
	CRect rect(CPoint(0,0),CSize(211,144));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "PCM import"
	parent->SetWindowText("PCM import");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Quality: 0",IDC_QUALITY_FRM,7,7,136,36
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(136,36));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Quality: 0"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_QUALITY_FRM);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Gain: +0dB",IDC_VOLUME_FRM,7,47,136,35
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7,47),CSize(136,35));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Gain: +0dB"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_VOLUME_FRM);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "File info",IDC_STATIC,7,86,136,51
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(7,86),CSize(136,51));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("File info"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Low",IDC_STATIC,15,21,15,10
	CStatic* mfc4 = new CStatic(parent);
	CRect r4(CPoint(15,21),CSize(15,10));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Low"),WS_VISIBLE|WS_BORDER,r4,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_QUALITY, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 30, 19, 90, 15
	CSliderCtrl* mfc5 = new CSliderCtrl(parent);
	CRect r5(CPoint(30, 19), CSize(90, 15));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r5, parent, IDC_QUALITY);
	mfcToQtWidget->insert(IDC_QUALITY, mfc5);

   // LTEXT "High",IDC_STATIC,123,21,16,10
	CStatic* mfc6 = new CStatic(parent);
	CRect r6(CPoint(123,21),CSize(16,10));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("High"),WS_VISIBLE|WS_BORDER,r6,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Low",IDC_STATIC,15,61,15,10
	CStatic* mfc8 = new CStatic(parent);
	CRect r8(CPoint(15,61),CSize(15,10));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Low"),WS_VISIBLE|WS_BORDER,r8,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_VOLUME, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 30, 59, 90, 15
	CSliderCtrl* mfc9 = new CSliderCtrl(parent);
	CRect r9(CPoint(30, 59), CSize(90, 15));
	parent->MapDialogRect(&r9);
	mfc9->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r9, parent, IDC_VOLUME);
	mfcToQtWidget->insert(IDC_VOLUME, mfc9);

   // LTEXT "High",IDC_STATIC,123,61,16,10
	CStatic* mfc10 = new CStatic(parent);
	CRect r10(CPoint(123,61),CSize(16,10));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("High"),WS_VISIBLE|WS_BORDER,r10,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Static",IDC_SAMPLE_RATE,15,99,118,8
	CStatic* mfc12 = new CStatic(parent);
	CRect r12(CPoint(15,99),CSize(118,8));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T("Static"),WS_VISIBLE|WS_BORDER,r12,parent,IDC_SAMPLE_RATE);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Static",IDC_RESAMPLING,15,110,118,8
	CStatic* mfc13 = new CStatic(parent);
	CRect r13(CPoint(15,110),CSize(118,8));
	parent->MapDialogRect(&r13);
	mfc13->Create(_T("Static"),WS_VISIBLE|WS_BORDER,r13,parent,IDC_RESAMPLING);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // PUSHBUTTON "Preview",IDC_PREVIEW,154,7,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc14 = new CButton(parent);
	CRect r14(CPoint(154,7),CSize(50,14));
	parent->MapDialogRect(&r14);
	mfc14->Create(_T("Preview"),WS_VISIBLE|WS_BORDER,r14,parent,IDC_PREVIEW);
	mfcToQtWidget->insert(IDC_PREVIEW,mfc14);

   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,154,24,50,14
	CButton* mfc15 = new CButton(parent);
	CRect r15(CPoint(154,24),CSize(50,14));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r15,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc15);

   // PUSHBUTTON "Cancel",IDCANCEL,154,41,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc16 = new CButton(parent);
	CRect r16(CPoint(154,41),CSize(50,14));
	parent->MapDialogRect(&r16);
	mfc16->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r16,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc16);

   // LTEXT "Static",IDC_SAMPLESIZE,15,121,118,8
	CStatic* mfc17 = new CStatic(parent);
	CRect r17(CPoint(15,121),CSize(118,8));
	parent->MapDialogRect(&r17);
	mfc17->Create(_T("Static"),WS_VISIBLE|WS_BORDER,r17,parent,IDC_SAMPLESIZE);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // END
}


void qtMfcInitDialogResource_IDD_INSTRUMENT_INTERNAL(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_INSTRUMENT_INTERNAL DIALOGEX 0, 0, 372, 172
	CRect rect(CPoint(0,0),CSize(372,172));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());




   // BEGIN
   // GROUPBOX "Sequence editor",IDC_STATIC,120,7,245,158
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(120,7),CSize(245,158));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Sequence editor"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Instrument settings",IDC_STATIC,7,7,107,158
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7,7),CSize(107,158));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Instrument settings"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER|0,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_INSTSETTINGS, "SysListView32", WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|LVS_NOSORTHEADER|WS_BORDER|WS_TABSTOP, 12, 18, 96, 107
	CListCtrl* mfc2 = new CListCtrl(parent);
	CRect r2(CPoint(12, 18), CSize(96, 107));
	parent->MapDialogRect(&r2);
	mfc2->Create(WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|LVS_NOSORTHEADER|WS_BORDER|WS_TABSTOP, r2, parent, IDC_INSTSETTINGS);
	mfcToQtWidget->insert(IDC_INSTSETTINGS, mfc2);

   // PUSHBUTTON "Select next empty slot",IDC_FREE_SEQ,12,129,96,15,WS_VISIBLE|WS_BORDER
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(12,129),CSize(96,15));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Select next empty slot"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_FREE_SEQ);
	mfcToQtWidget->insert(IDC_FREE_SEQ,mfc3);

   // CONTROL "Sequence #", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_LEFTNOWORDWRAP|SS_CENTERIMAGE|WS_GROUP, 12, 148, 53, 10
	CStatic* mfc4 = new CStatic(parent);
	CRect r4(CPoint(12, 148), CSize(53, 10));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Sequence #"), WS_VISIBLE|WS_BORDER|SS_LEFTNOWORDWRAP|SS_CENTERIMAGE|WS_GROUP, r4, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc4);

   // EDITTEXT IDC_SEQ_INDEX,69,147,39,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc5 = new CEdit(parent);
	CRect r5(CPoint(69,147),CSize(39,12));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r5,parent,IDC_SEQ_INDEX);
	mfcToQtWidget->insert(IDC_SEQ_INDEX,mfc5);

   // CONTROL "", IDC_SEQUENCE_SPIN, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 66, 153, 11, 9
	CSpinButtonCtrl* mfc6 = new CSpinButtonCtrl(parent);
	CRect r6(CPoint(66, 153), CSize(11, 9));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r6, parent, IDC_SEQUENCE_SPIN);
	mfcToQtWidget->insert(IDC_SEQUENCE_SPIN, mfc6);

   // EDITTEXT IDC_SEQUENCE_STRING,126,147,232,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc7 = new CEdit(parent);
	CRect r7(CPoint(126,147),CSize(232,12));
	parent->MapDialogRect(&r7);
	mfc7->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r7,parent,IDC_SEQUENCE_STRING);
	mfcToQtWidget->insert(IDC_SEQUENCE_STRING,mfc7);

   // CONTROL "", IDC_INST_SEQUENCE_GRAPH, "Static", WS_BORDER|SS_BLACKFRAME, 126, 18, 232, 124
	CStatic* mfc10 = new CStatic(parent);
	CRect r10(CPoint(126, 18), CSize(232, 124));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T(""), WS_BORDER|SS_BLACKFRAME, r10, parent, IDC_INST_SEQUENCE_GRAPH);
	mfcToQtWidget->insert(IDC_INST_SEQUENCE_GRAPH, mfc10);

   // END
}


void qtMfcInitDialogResource_IDD_INSTRUMENT_DPCM(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_INSTRUMENT_DPCM DIALOGEX 0, 0, 372, 174
	CRect rect(CPoint(0,0),CSize(372,174));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());




   // BEGIN
   // GROUPBOX "Assigned samples",IDC_STATIC,7,7,179,160
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(179,160));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Assigned samples"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Loaded samples",IDC_STATIC,192,7,173,160
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(192,7),CSize(173,160));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Loaded samples"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_TABLE, "SysListView32", WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|LVS_NOSORTHEADER|WS_BORDER|WS_TABSTOP, 15, 19, 117, 125
	CListCtrl* mfc3 = new CListCtrl(parent);
	CRect r3(CPoint(15, 19), CSize(117, 125));
	parent->MapDialogRect(&r3);
	mfc3->Create(WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|LVS_NOSORTHEADER|WS_BORDER|WS_TABSTOP, r3, parent, IDC_TABLE);
	mfcToQtWidget->insert(IDC_TABLE, mfc3);

   // COMBOBOX IDC_SAMPLES,15,148,117,125,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|CBS_SORT|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc4 = new CComboBox(parent);
	CRect r4(CPoint(15,148),CSize(117,125));
	parent->MapDialogRect(&r4);
	mfc4->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|CBS_SORT|WS_VSCROLL|WS_TABSTOP,r4,parent,IDC_SAMPLES);
	mfcToQtWidget->insert(IDC_SAMPLES,mfc4);

   // LTEXT "Pitch",IDC_STATIC,138,19,30,8
	CStatic* mfc5 = new CStatic(parent);
	CRect r5(CPoint(138,19),CSize(30,8));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Pitch"),WS_VISIBLE|WS_BORDER,r5,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_PITCH,138,29,42,53,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc6 = new CComboBox(parent);
	CRect r6(CPoint(138,29),CSize(42,53));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r6,parent,IDC_PITCH);
	mfcToQtWidget->insert(IDC_PITCH,mfc6);

   // CONTROL "Loop", IDC_LOOP, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 138, 46, 42, 9
	CButton* mfc7 = new CButton(parent);
	CRect r7(CPoint(138, 46), CSize(42, 9));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("Loop"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r7, parent, IDC_LOOP);
	mfcToQtWidget->insert(IDC_LOOP, mfc7);

   // EDITTEXT IDC_DELTA_COUNTER,138,72,42,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc8 = new CEdit(parent);
	CRect r8(CPoint(138,72),CSize(42,14));
	parent->MapDialogRect(&r8);
	mfc8->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r8,parent,IDC_DELTA_COUNTER);
	mfcToQtWidget->insert(IDC_DELTA_COUNTER,mfc8);

   // CONTROL "", IDC_DELTA_SPIN, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 170, 72, 11, 14
	CSpinButtonCtrl* mfc9 = new CSpinButtonCtrl(parent);
	CRect r9(CPoint(170, 72), CSize(11, 14));
	parent->MapDialogRect(&r9);
	mfc9->Create(WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r9, parent, IDC_DELTA_SPIN);
	mfcToQtWidget->insert(IDC_DELTA_SPIN, mfc9);

   // PUSHBUTTON "",IDC_ADD,138,130,42,14,WS_VISIBLE|WS_BORDER|BS_ICON
	CButton* mfc10 = new CButton(parent);
	CRect r10(CPoint(138,130),CSize(42,14));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T(""),WS_VISIBLE|WS_BORDER|BS_ICON,r10,parent,IDC_ADD);
	mfcToQtWidget->insert(IDC_ADD,mfc10);

   // PUSHBUTTON "",IDC_REMOVE,138,148,42,14,WS_VISIBLE|WS_BORDER|BS_ICON
	CButton* mfc11 = new CButton(parent);
	CRect r11(CPoint(138,148),CSize(42,14));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T(""),WS_VISIBLE|WS_BORDER|BS_ICON,r11,parent,IDC_REMOVE);
	mfcToQtWidget->insert(IDC_REMOVE,mfc11);

   // CONTROL "", IDC_SAMPLE_LIST, "SysListView32", WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|LVS_NOSORTHEADER|WS_BORDER|WS_TABSTOP, 198, 19, 108, 125
	CListCtrl* mfc13 = new CListCtrl(parent);
	CRect r13(CPoint(198, 19), CSize(108, 125));
	parent->MapDialogRect(&r13);
	mfc13->Create(WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|LVS_NOSORTHEADER|WS_BORDER|WS_TABSTOP, r13, parent, IDC_SAMPLE_LIST);
	mfcToQtWidget->insert(IDC_SAMPLE_LIST, mfc13);

   // LTEXT "Space used 16 / 16 kb",IDC_SPACE,198,151,166,9
	CStatic* mfc14 = new CStatic(parent);
	CRect r14(CPoint(198,151),CSize(166,9));
	parent->MapDialogRect(&r14);
	mfc14->Create(_T("Space used 16 / 16 kb"),WS_VISIBLE|WS_BORDER,r14,parent,IDC_SPACE);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // DEFPUSHBUTTON "Load",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,312,19,47,14
	CButton* mfc15 = new CButton(parent);
	CRect r15(CPoint(312,19),CSize(47,14));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("Load"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r15,parent,IDC_LOAD);
	mfcToQtWidget->insert(IDC_LOAD,mfc15);

   // PUSHBUTTON "Unload",IDC_UNLOAD,312,35,47,14,WS_VISIBLE|WS_BORDER
	CButton* mfc16 = new CButton(parent);
	CRect r16(CPoint(312,35),CSize(47,14));
	parent->MapDialogRect(&r16);
	mfc16->Create(_T("Unload"),WS_VISIBLE|WS_BORDER,r16,parent,IDC_UNLOAD);
	mfcToQtWidget->insert(IDC_UNLOAD,mfc16);

   // PUSHBUTTON "Save",IDC_SAVE,312,51,47,14,WS_VISIBLE|WS_BORDER
	CButton* mfc17 = new CButton(parent);
	CRect r17(CPoint(312,51),CSize(47,14));
	parent->MapDialogRect(&r17);
	mfc17->Create(_T("Save"),WS_VISIBLE|WS_BORDER,r17,parent,IDC_SAVE);
	mfcToQtWidget->insert(IDC_SAVE,mfc17);

   // PUSHBUTTON "Import",IDC_IMPORT,312,67,47,14,WS_VISIBLE|WS_BORDER
	CButton* mfc18 = new CButton(parent);
	CRect r18(CPoint(312,67),CSize(47,14));
	parent->MapDialogRect(&r18);
	mfc18->Create(_T("Import"),WS_VISIBLE|WS_BORDER,r18,parent,IDC_IMPORT);
	mfcToQtWidget->insert(IDC_IMPORT,mfc18);

   // PUSHBUTTON "Edit",IDC_EDIT,312,83,47,14,WS_VISIBLE|WS_BORDER
	CButton* mfc19 = new CButton(parent);
	CRect r19(CPoint(312,83),CSize(47,14));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("Edit"),WS_VISIBLE|WS_BORDER,r19,parent,IDC_EDIT);
	mfcToQtWidget->insert(IDC_EDIT,mfc19);

   // PUSHBUTTON "Preview",IDC_PREVIEW,312,99,47,14,WS_VISIBLE|WS_BORDER
	CButton* mfc20 = new CButton(parent);
	CRect r20(CPoint(312,99),CSize(47,14));
	parent->MapDialogRect(&r20);
	mfc20->Create(_T("Preview"),WS_VISIBLE|WS_BORDER,r20,parent,IDC_PREVIEW);
	mfcToQtWidget->insert(IDC_PREVIEW,mfc20);

   // LTEXT "D-counter",IDC_STATIC,138,61,33,8
	CStatic* mfc21 = new CStatic(parent);
	CRect r21(CPoint(138,61),CSize(33,8));
	parent->MapDialogRect(&r21);
	mfc21->Create(_T("D-counter"),WS_VISIBLE|WS_BORDER,r21,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // END
}


void qtMfcInitDialogResource_IDD_INSTRUMENT(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_INSTRUMENT DIALOGEX 0, 0, 389, 242
	CRect rect(CPoint(0,0),CSize(389,242));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Instrument editor"
	parent->SetWindowText("Instrument editor");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|DS_CENTER|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // CONTROL "", IDC_INST_TAB, "SysTabControl32", WS_VISIBLE|WS_BORDER|0x0, 7, 7, 375, 185
	CTabCtrl* mfc0 = new CTabCtrl(parent);
	CRect r0(CPoint(7, 7), CSize(375, 185));
	parent->MapDialogRect(&r0);
	mfc0->Create(WS_VISIBLE|WS_BORDER|0x0, r0, parent, IDC_INST_TAB);
	mfcToQtWidget->insert(IDC_INST_TAB, mfc0);

   // CONTROL "", IDC_KEYBOARD, "Static", WS_VISIBLE|WS_BORDER|SS_OWNERDRAW|SS_REALSIZEIMAGE|SS_SUNKEN, 7, 198, 375, 37
	CStatic* mfc1 = new CStatic(parent);
	CRect r1(CPoint(7, 198), CSize(375, 37));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_OWNERDRAW|SS_REALSIZEIMAGE|SS_SUNKEN, r1, parent, IDC_KEYBOARD);
	mfcToQtWidget->insert(IDC_KEYBOARD, mfc1);

   // END
}


void qtMfcInitDialogResource_IDD_CONFIG_APPEARANCE(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_CONFIG_APPEARANCE DIALOGEX 0, 0, 280, 167
	CRect rect(CPoint(0,0),CSize(280,167));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Appearance"
	parent->SetWindowText("Appearance");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Color schemes",IDC_STATIC,6,7,166,39
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(6,7),CSize(166,39));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Color schemes"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Colors",IDC_STATIC,6,54,166,65
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(6,54),CSize(166,65));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Colors"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Pattern font and size",IDC_STATIC,6,126,166,34
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(6,126),CSize(166,34));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Pattern font and size"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Preview",IDC_STATIC,178,7,94,132
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(178,7),CSize(94,132));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Preview"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r3,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_SCHEME,12,22,153,126,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc5 = new CComboBox(parent);
	CRect r5(CPoint(12,22),CSize(153,126));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r5,parent,IDC_SCHEME);
	mfcToQtWidget->insert(IDC_SCHEME,mfc5);

   // LTEXT "Item",IDC_STATIC,12,68,16,8
	CStatic* mfc7 = new CStatic(parent);
	CRect r7(CPoint(12,68),CSize(16,8));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("Item"),WS_VISIBLE|WS_BORDER,r7,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_COL_ITEM,31,66,134,172,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc8 = new CComboBox(parent);
	CRect r8(CPoint(31,66),CSize(134,172));
	parent->MapDialogRect(&r8);
	mfc8->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r8,parent,IDC_COL_ITEM);
	mfcToQtWidget->insert(IDC_COL_ITEM,mfc8);

   // CONTROL "", IDC_COL_PREVIEW, "Static", WS_VISIBLE|WS_BORDER|SS_OWNERDRAW, 12, 85, 89, 15
	CStatic* mfc9 = new CStatic(parent);
	CRect r9(CPoint(12, 85), CSize(89, 15));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_OWNERDRAW, r9, parent, IDC_COL_PREVIEW);
	mfcToQtWidget->insert(IDC_COL_PREVIEW, mfc9);

   // PUSHBUTTON "&Pick color",IDC_PICK_COL,111,85,54,15,WS_VISIBLE|WS_BORDER
	CButton* mfc10 = new CButton(parent);
	CRect r10(CPoint(111,85),CSize(54,15));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("&Pick color"),WS_VISIBLE|WS_BORDER,r10,parent,IDC_PICK_COL);
	mfcToQtWidget->insert(IDC_PICK_COL,mfc10);

   // CONTROL "Pattern colors", IDC_PATTERNCOLORS, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 12, 105, 58, 9
	CButton* mfc11 = new CButton(parent);
	CRect r11(CPoint(12, 105), CSize(58, 9));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T("Pattern colors"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r11, parent, IDC_PATTERNCOLORS);
	mfcToQtWidget->insert(IDC_PATTERNCOLORS, mfc11);

   // CONTROL "Display flats", IDC_DISPLAYFLATS, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 83, 105, 58, 9
	CButton* mfc12 = new CButton(parent);
	CRect r12(CPoint(83, 105), CSize(58, 9));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T("Display flats"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r12, parent, IDC_DISPLAYFLATS);
	mfcToQtWidget->insert(IDC_DISPLAYFLATS, mfc12);

   // COMBOBOX IDC_FONT_PERCENT,12,139,31,12,WS_VISIBLE|WS_BORDER|CBS_DROPDOWN|CBS_AUTOHSCROLL|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc14 = new CComboBox(parent);
	CRect r14(CPoint(12,139),CSize(31,12));
	parent->MapDialogRect(&r14);
	mfc14->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWN|CBS_AUTOHSCROLL|WS_VSCROLL|WS_TABSTOP,r14,parent,IDC_FONT_PERCENT);
	mfcToQtWidget->insert(IDC_FONT_PERCENT,mfc14);

   // LTEXT "%",IDC_STATIC,45,141,8,8
	CStatic* mfc15 = new CStatic(parent);
	CRect r15(CPoint(45,141),CSize(8,8));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("%"),WS_VISIBLE|WS_BORDER,r15,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_FONT,54,139,81,12,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|CBS_SORT|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc16 = new CComboBox(parent);
	CRect r16(CPoint(54,139),CSize(81,12));
	parent->MapDialogRect(&r16);
	mfc16->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|CBS_SORT|WS_VSCROLL|WS_TABSTOP,r16,parent,IDC_FONT);
	mfcToQtWidget->insert(IDC_FONT,mfc16);

   // COMBOBOX IDC_FONT_SIZE,138,139,27,12,WS_VISIBLE|WS_BORDER|CBS_DROPDOWN|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc17 = new CComboBox(parent);
	CRect r17(CPoint(138,139),CSize(27,12));
	parent->MapDialogRect(&r17);
	mfc17->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWN|WS_VSCROLL|WS_TABSTOP,r17,parent,IDC_FONT_SIZE);
	mfcToQtWidget->insert(IDC_FONT_SIZE,mfc17);

   // CONTROL "", IDC_PREVIEW, "Static", WS_VISIBLE|WS_BORDER|SS_OWNERDRAW, 185, 19, 79, 111
	CStatic* mfc19 = new CStatic(parent);
	CRect r19(CPoint(185, 19), CSize(79, 111));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_OWNERDRAW, r19, parent, IDC_PREVIEW);
	mfcToQtWidget->insert(IDC_PREVIEW, mfc19);

   // PUSHBUTTON "&Save",IDC_BUTTON_APPEARANCE_SAVE,178,145,43,15,WS_VISIBLE|WS_BORDER
	CButton* mfc20 = new CButton(parent);
	CRect r20(CPoint(178,145),CSize(43,15));
	parent->MapDialogRect(&r20);
	mfc20->Create(_T("&Save"),WS_VISIBLE|WS_BORDER,r20,parent,IDC_BUTTON_APPEARANCE_SAVE);
	mfcToQtWidget->insert(IDC_BUTTON_APPEARANCE_SAVE,mfc20);

   // PUSHBUTTON "&Load",IDC_BUTTON_APPEARANCE_LOAD,229,145,43,15,WS_VISIBLE|WS_BORDER
	CButton* mfc21 = new CButton(parent);
	CRect r21(CPoint(229,145),CSize(43,15));
	parent->MapDialogRect(&r21);
	mfc21->Create(_T("&Load"),WS_VISIBLE|WS_BORDER,r21,parent,IDC_BUTTON_APPEARANCE_LOAD);
	mfcToQtWidget->insert(IDC_BUTTON_APPEARANCE_LOAD,mfc21);

   // END
}


void qtMfcInitDialogResource_IDD_CONFIG_GENERAL(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_CONFIG_GENERAL DIALOGEX 0, 0, 280, 167
	CRect rect(CPoint(0,0),CSize(280,167));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "General"
	parent->SetWindowText("General");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "General settings",IDC_STATIC,7,7,163,153
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(163,153));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("General settings"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Edit settings",IDC_STATIC,177,7,96,61
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(177,7),CSize(96,61));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Edit settings"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Keys",IDC_STATIC,177,72,96,88
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(177,72),CSize(96,88));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Keys"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_CONFIG_LIST, "SysListView32", WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SINGLESEL|LVS_ALIGNLEFT|LVS_NOCOLUMNHEADER|LVS_NOSORTHEADER|WS_BORDER|WS_TABSTOP, 15, 19, 147, 109
	CListCtrl* mfc4 = new CListCtrl(parent);
	CRect r4(CPoint(15, 19), CSize(147, 109));
	parent->MapDialogRect(&r4);
	mfc4->Create(WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SINGLESEL|LVS_ALIGNLEFT|LVS_NOCOLUMNHEADER|LVS_NOSORTHEADER|WS_BORDER|WS_TABSTOP, r4, parent, IDC_CONFIG_LIST);
	mfcToQtWidget->insert(IDC_CONFIG_LIST, mfc4);

   // LTEXT "Page Down jump:",IDC_STATIC,184,20,58,9
	CStatic* mfc6 = new CStatic(parent);
	CRect r6(CPoint(184,20),CSize(58,9));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Page Down jump:"),WS_VISIBLE|WS_BORDER,r6,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_PAGELENGTH,240,19,27,12,WS_VISIBLE|WS_BORDER|CBS_DROPDOWN|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc7 = new CComboBox(parent);
	CRect r7(CPoint(240,19),CSize(27,12));
	parent->MapDialogRect(&r7);
	mfc7->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWN|WS_VSCROLL|WS_TABSTOP,r7,parent,IDC_PAGELENGTH);
	mfcToQtWidget->insert(IDC_PAGELENGTH,mfc7);


	mfc7->AddString(_T("2"));
	

	mfc7->AddString(_T("4"));
	

	mfc7->AddString(_T("8"));
	

	mfc7->AddString(_T("16"));
	
   // LTEXT "Pattern edit style:",IDC_STATIC,184,35,59,8
	CStatic* mfc8 = new CStatic(parent);
	CRect r8(CPoint(184,35),CSize(59,8));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Pattern edit style:"),WS_VISIBLE|WS_BORDER,r8,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_COMBO_STYLE,184,48,83,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc9 = new CComboBox(parent);
	CRect r9(CPoint(184,48),CSize(83,30));
	parent->MapDialogRect(&r9);
	mfc9->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r9,parent,IDC_COMBO_STYLE);
	mfcToQtWidget->insert(IDC_COMBO_STYLE,mfc9);


	mfc9->AddString(_T("FastTracker 2"));
	

	mfc9->AddString(_T("ModPlug Tracker"));
	

	mfc9->AddString(_T("Impulse Tracker"));
	
   // LTEXT "Note cut",IDC_STATIC,184,87,41,11
	CStatic* mfc11 = new CStatic(parent);
	CRect r11(CPoint(184,87),CSize(41,11));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T("Note cut"),WS_VISIBLE|WS_BORDER,r11,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_KEY_NOTE_CUT,230,84,36,13,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY
	CEdit* mfc12 = new CEdit(parent);
	CRect r12(CPoint(230,84),CSize(36,13));
	parent->MapDialogRect(&r12);
	mfc12->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY,r12,parent,IDC_KEY_NOTE_CUT);
	mfcToQtWidget->insert(IDC_KEY_NOTE_CUT,mfc12);

   // LTEXT "Clear field",IDC_STATIC,184,101,41,11
	CStatic* mfc13 = new CStatic(parent);
	CRect r13(CPoint(184,101),CSize(41,11));
	parent->MapDialogRect(&r13);
	mfc13->Create(_T("Clear field"),WS_VISIBLE|WS_BORDER,r13,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_KEY_CLEAR,230,98,36,13,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY
	CEdit* mfc14 = new CEdit(parent);
	CRect r14(CPoint(230,98),CSize(36,13));
	parent->MapDialogRect(&r14);
	mfc14->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY,r14,parent,IDC_KEY_CLEAR);
	mfcToQtWidget->insert(IDC_KEY_CLEAR,mfc14);

   // LTEXT "Repeat",IDC_STATIC,184,115,41,11
	CStatic* mfc15 = new CStatic(parent);
	CRect r15(CPoint(184,115),CSize(41,11));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("Repeat"),WS_VISIBLE|WS_BORDER,r15,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_KEY_REPEAT,230,112,36,13,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY
	CEdit* mfc16 = new CEdit(parent);
	CRect r16(CPoint(230,112),CSize(36,13));
	parent->MapDialogRect(&r16);
	mfc16->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY,r16,parent,IDC_KEY_REPEAT);
	mfcToQtWidget->insert(IDC_KEY_REPEAT,mfc16);

   // LTEXT "Note release",IDC_STATIC,184,129,41,11
	CStatic* mfc17 = new CStatic(parent);
	CRect r17(CPoint(184,129),CSize(41,11));
	parent->MapDialogRect(&r17);
	mfc17->Create(_T("Note release"),WS_VISIBLE|WS_BORDER,r17,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_KEY_NOTE_RELEASE,230,126,36,13,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY
	CEdit* mfc18 = new CEdit(parent);
	CRect r18(CPoint(230,126),CSize(36,13));
	parent->MapDialogRect(&r18);
	mfc18->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY,r18,parent,IDC_KEY_NOTE_RELEASE);
	mfcToQtWidget->insert(IDC_KEY_NOTE_RELEASE,mfc18);

   // LTEXT "Echo buffer",IDC_STATIC,184,143,41,11
	CStatic* mfc19 = new CStatic(parent);
	CRect r19(CPoint(184,143),CSize(41,11));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("Echo buffer"),WS_VISIBLE|WS_BORDER,r19,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_KEY_ECHO_BUFFER,230,140,36,13,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY
	CEdit* mfc20 = new CEdit(parent);
	CRect r20(CPoint(230,140),CSize(36,13));
	parent->MapDialogRect(&r20);
	mfc20->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY,r20,parent,IDC_KEY_ECHO_BUFFER);
	mfcToQtWidget->insert(IDC_KEY_ECHO_BUFFER,mfc20);

   // EDITTEXT IDC_EDIT_CONFIG_DESC,13,130,152,25,WS_VISIBLE|ES_MULTILINE|ES_READONLY
	CEdit* mfc21 = new CEdit(parent);
	CRect r21(CPoint(13,130),CSize(152,25));
	parent->MapDialogRect(&r21);
	mfc21->Create(WS_VISIBLE|ES_MULTILINE|ES_READONLY,r21,parent,IDC_EDIT_CONFIG_DESC);
	mfcToQtWidget->insert(IDC_EDIT_CONFIG_DESC,mfc21);

   // END
}


void qtMfcInitDialogResource_IDD_CONFIG_MIDI(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_CONFIG_MIDI DIALOGEX 0, 0, 280, 167
	CRect rect(CPoint(0,0),CSize(280,167));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "MIDI"
	parent->SetWindowText("MIDI");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Input Device",IDC_STATIC,7,7,266,35
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(266,35));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Input Device"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Output Device",IDC_STATIC,7,48,266,35
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7,48),CSize(266,35));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Output Device"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Options",IDC_STATIC,7,89,266,71
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(7,89),CSize(266,71));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Options"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_INDEVICES,13,20,253,50,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc4 = new CComboBox(parent);
	CRect r4(CPoint(13,20),CSize(253,50));
	parent->MapDialogRect(&r4);
	mfc4->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r4,parent,IDC_INDEVICES);
	mfcToQtWidget->insert(IDC_INDEVICES,mfc4);

   // COMBOBOX IDC_OUTDEVICES,13,61,253,50,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc6 = new CComboBox(parent);
	CRect r6(CPoint(13,61),CSize(253,50));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r6,parent,IDC_OUTDEVICES);
	mfcToQtWidget->insert(IDC_OUTDEVICES,mfc6);

   // CONTROL "Receive sync ticks", IDC_MASTER_SYNC, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 13, 102, 173, 10
	CButton* mfc7 = new CButton(parent);
	CRect r7(CPoint(13, 102), CSize(173, 10));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("Receive sync ticks"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r7, parent, IDC_MASTER_SYNC);
	mfcToQtWidget->insert(IDC_MASTER_SYNC, mfc7);

   // CONTROL "Skip key releases", IDC_KEY_RELEASE, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 13, 112, 173, 10
	CButton* mfc8 = new CButton(parent);
	CRect r8(CPoint(13, 112), CSize(173, 10));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Skip key releases"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r8, parent, IDC_KEY_RELEASE);
	mfcToQtWidget->insert(IDC_KEY_RELEASE, mfc8);

   // CONTROL "Map MIDI channels to NES channels", IDC_CHANMAP, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 13, 122, 173, 10
	CButton* mfc9 = new CButton(parent);
	CRect r9(CPoint(13, 122), CSize(173, 10));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("Map MIDI channels to NES channels"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r9, parent, IDC_CHANMAP);
	mfcToQtWidget->insert(IDC_CHANMAP, mfc9);

   // CONTROL "Record velocities", IDC_VELOCITY, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 13, 132, 173, 10
	CButton* mfc10 = new CButton(parent);
	CRect r10(CPoint(13, 132), CSize(173, 10));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("Record velocities"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r10, parent, IDC_VELOCITY);
	mfcToQtWidget->insert(IDC_VELOCITY, mfc10);

   // CONTROL "Auto arpeggiate chords", IDC_ARPEGGIATE, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 13, 142, 173, 10
	CButton* mfc11 = new CButton(parent);
	CRect r11(CPoint(13, 142), CSize(173, 10));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T("Auto arpeggiate chords"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r11, parent, IDC_ARPEGGIATE);
	mfcToQtWidget->insert(IDC_ARPEGGIATE, mfc11);

   // END
}


void qtMfcInitDialogResource_IDD_CONFIG_SOUND(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_CONFIG_SOUND DIALOGEX 0, 0, 280, 167
	CRect rect(CPoint(0,0),CSize(280,167));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Sound"
	parent->SetWindowText("Sound");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Device",IDC_STATIC,7,7,266,35
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(266,35));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Device"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Sample rate",IDC_STATIC,7,48,113,33
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7,48),CSize(113,33));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Sample rate"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Sample size",IDC_STATIC,7,90,113,33
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(7,90),CSize(113,33));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Sample size"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Buffer length",IDC_STATIC,7,129,113,31
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(7,129),CSize(113,31));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Buffer length"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r3,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Bass filtering",IDC_STATIC,126,48,147,33
	CButton* mfc4 = new CButton(parent);
	CRect r4(CPoint(126,48),CSize(147,33));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Bass filtering"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r4,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Treble filtering",IDC_STATIC,126,86,147,43
	CButton* mfc5 = new CButton(parent);
	CRect r5(CPoint(126,86),CSize(147,43));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Treble filtering"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r5,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Volume",IDC_STATIC,126,133,147,27
	CButton* mfc6 = new CButton(parent);
	CRect r6(CPoint(126,133),CSize(147,27));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Volume"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r6,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_DEVICES,13,20,253,12,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc8 = new CComboBox(parent);
	CRect r8(CPoint(13,20),CSize(253,12));
	parent->MapDialogRect(&r8);
	mfc8->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r8,parent,IDC_DEVICES);
	mfcToQtWidget->insert(IDC_DEVICES,mfc8);

   // COMBOBOX IDC_SAMPLE_RATE,13,61,101,62,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|CBS_SORT|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc10 = new CComboBox(parent);
	CRect r10(CPoint(13,61),CSize(101,62));
	parent->MapDialogRect(&r10);
	mfc10->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|CBS_SORT|WS_VSCROLL|WS_TABSTOP,r10,parent,IDC_SAMPLE_RATE);
	mfcToQtWidget->insert(IDC_SAMPLE_RATE,mfc10);


	mfc10->AddString(_T("11 025 Hz"));
	

	mfc10->AddString(_T("22 050 Hz"));
	

	mfc10->AddString(_T("44 100 Hz"));
	

	mfc10->AddString(_T("48 000 Hz"));
	

	mfc10->AddString(_T("96 000 Hz"));
	
   // COMBOBOX IDC_SAMPLE_SIZE,13,102,101,62,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|CBS_SORT|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc12 = new CComboBox(parent);
	CRect r12(CPoint(13,102),CSize(101,62));
	parent->MapDialogRect(&r12);
	mfc12->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|CBS_SORT|WS_VSCROLL|WS_TABSTOP,r12,parent,IDC_SAMPLE_SIZE);
	mfcToQtWidget->insert(IDC_SAMPLE_SIZE,mfc12);


	mfc12->AddString(_T("16 bit"));
	

	mfc12->AddString(_T("8 bit"));
	
   // CONTROL "", IDC_BUF_LENGTH, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_BOTH|TBS_NOTICKS|WS_TABSTOP, 13, 141, 69, 12
	CSliderCtrl* mfc14 = new CSliderCtrl(parent);
	CRect r14(CPoint(13, 141), CSize(69, 12));
	parent->MapDialogRect(&r14);
	mfc14->Create(WS_VISIBLE|WS_BORDER|TBS_BOTH|TBS_NOTICKS|WS_TABSTOP, r14, parent, IDC_BUF_LENGTH);
	mfcToQtWidget->insert(IDC_BUF_LENGTH, mfc14);

   // CTEXT "20 ms",IDC_BUF_LEN,83,142,31,11
	CStatic* mfc15 = new CStatic(parent);
	CRect r15(CPoint(83,142),CSize(31,11));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("20 ms"),WS_VISIBLE|WS_BORDER,r15,parent,IDC_BUF_LEN);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Frequency",IDC_STATIC,132,63,36,11
	CStatic* mfc17 = new CStatic(parent);
	CRect r17(CPoint(132,63),CSize(36,11));
	parent->MapDialogRect(&r17);
	mfc17->Create(_T("Frequency"),WS_VISIBLE|WS_BORDER,r17,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_BASS_FREQ, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_BOTH|TBS_NOTICKS|WS_TABSTOP, 174, 63, 55, 12
	CSliderCtrl* mfc18 = new CSliderCtrl(parent);
	CRect r18(CPoint(174, 63), CSize(55, 12));
	parent->MapDialogRect(&r18);
	mfc18->Create(WS_VISIBLE|WS_BORDER|TBS_BOTH|TBS_NOTICKS|WS_TABSTOP, r18, parent, IDC_BASS_FREQ);
	mfcToQtWidget->insert(IDC_BASS_FREQ, mfc18);

   // CTEXT "16 Hz",IDC_BASS_FREQ_T,234,64,32,10
	CStatic* mfc19 = new CStatic(parent);
	CRect r19(CPoint(234,64),CSize(32,10));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("16 Hz"),WS_VISIBLE|WS_BORDER,r19,parent,IDC_BASS_FREQ_T);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Damping",IDC_STATIC,132,99,36,10
	CStatic* mfc21 = new CStatic(parent);
	CRect r21(CPoint(132,99),CSize(36,10));
	parent->MapDialogRect(&r21);
	mfc21->Create(_T("Damping"),WS_VISIBLE|WS_BORDER,r21,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_TREBLE_DAMP, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_BOTH|TBS_NOTICKS|WS_TABSTOP, 174, 99, 55, 12
	CSliderCtrl* mfc22 = new CSliderCtrl(parent);
	CRect r22(CPoint(174, 99), CSize(55, 12));
	parent->MapDialogRect(&r22);
	mfc22->Create(WS_VISIBLE|WS_BORDER|TBS_BOTH|TBS_NOTICKS|WS_TABSTOP, r22, parent, IDC_TREBLE_DAMP);
	mfcToQtWidget->insert(IDC_TREBLE_DAMP, mfc22);

   // CTEXT "-24 dB",IDC_TREBLE_DAMP_T,234,99,32,9
	CStatic* mfc23 = new CStatic(parent);
	CRect r23(CPoint(234,99),CSize(32,9));
	parent->MapDialogRect(&r23);
	mfc23->Create(_T("-24 dB"),WS_VISIBLE|WS_BORDER,r23,parent,IDC_TREBLE_DAMP_T);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Frequency",IDC_STATIC,132,112,36,10
	CStatic* mfc24 = new CStatic(parent);
	CRect r24(CPoint(132,112),CSize(36,10));
	parent->MapDialogRect(&r24);
	mfc24->Create(_T("Frequency"),WS_VISIBLE|WS_BORDER,r24,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_TREBLE_FREQ, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_BOTH|TBS_NOTICKS|WS_TABSTOP, 174, 112, 55, 12
	CSliderCtrl* mfc25 = new CSliderCtrl(parent);
	CRect r25(CPoint(174, 112), CSize(55, 12));
	parent->MapDialogRect(&r25);
	mfc25->Create(WS_VISIBLE|WS_BORDER|TBS_BOTH|TBS_NOTICKS|WS_TABSTOP, r25, parent, IDC_TREBLE_FREQ);
	mfcToQtWidget->insert(IDC_TREBLE_FREQ, mfc25);

   // CTEXT "12000 Hz",IDC_TREBLE_FREQ_T,234,110,32,11
	CStatic* mfc26 = new CStatic(parent);
	CRect r26(CPoint(234,110),CSize(32,11));
	parent->MapDialogRect(&r26);
	mfc26->Create(_T("12000 Hz"),WS_VISIBLE|WS_BORDER,r26,parent,IDC_TREBLE_FREQ_T);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_VOLUME, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_BOTH|TBS_NOTICKS|WS_TABSTOP, 132, 144, 96, 12
	CSliderCtrl* mfc28 = new CSliderCtrl(parent);
	CRect r28(CPoint(132, 144), CSize(96, 12));
	parent->MapDialogRect(&r28);
	mfc28->Create(WS_VISIBLE|WS_BORDER|TBS_BOTH|TBS_NOTICKS|WS_TABSTOP, r28, parent, IDC_VOLUME);
	mfcToQtWidget->insert(IDC_VOLUME, mfc28);

   // CTEXT "100 %",IDC_VOLUME_T,234,144,31,8
	CStatic* mfc29 = new CStatic(parent);
	CRect r29(CPoint(234,144),CSize(31,8));
	parent->MapDialogRect(&r29);
	mfc29->Create(_T("100 %"),WS_VISIBLE|WS_BORDER,r29,parent,IDC_VOLUME_T);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // END
}


void qtMfcInitDialogResource_IDD_CONFIG_SHORTCUTS(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_CONFIG_SHORTCUTS DIALOGEX 0, 0, 280, 167
	CRect rect(CPoint(0,0),CSize(280,167));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Shortcuts"
	parent->SetWindowText("Shortcuts");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // CONTROL "", IDC_SHORTCUTS, "SysListView32", WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|WS_BORDER|WS_TABSTOP, 7, 7, 266, 136
	CListCtrl* mfc0 = new CListCtrl(parent);
	CRect r0(CPoint(7, 7), CSize(266, 136));
	parent->MapDialogRect(&r0);
	mfc0->Create(WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|WS_BORDER|WS_TABSTOP, r0, parent, IDC_SHORTCUTS);
	mfcToQtWidget->insert(IDC_SHORTCUTS, mfc0);

   // LTEXT "Keys:",IDC_STATIC,7,149,23,12
	CStatic* mfc1 = new CStatic(parent);
	CRect r1(CPoint(7,149),CSize(23,12));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Keys:"),WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_KEY,36,147,144,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY
	CEdit* mfc2 = new CEdit(parent);
	CRect r2(CPoint(36,147),CSize(144,14));
	parent->MapDialogRect(&r2);
	mfc2->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY,r2,parent,IDC_KEY);
	mfcToQtWidget->insert(IDC_KEY,mfc2);

   // PUSHBUTTON "Clear",IDC_CLEAR,186,147,36,14,WS_VISIBLE|WS_BORDER
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(186,147),CSize(36,14));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Clear"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_CLEAR);
	mfcToQtWidget->insert(IDC_CLEAR,mfc3);

   // PUSHBUTTON "Default",IDC_DEFAULT,228,147,45,14,WS_VISIBLE|WS_BORDER
	CButton* mfc4 = new CButton(parent);
	CRect r4(CPoint(228,147),CSize(45,14));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Default"),WS_VISIBLE|WS_BORDER,r4,parent,IDC_DEFAULT);
	mfcToQtWidget->insert(IDC_DEFAULT,mfc4);

   // END
}


void qtMfcInitDialogResource_IDD_OCTAVE(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_OCTAVE DIALOGEX 0, 0, 322, 12
	CRect rect(CPoint(0,0),CSize(322,12));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());




   // BEGIN
   // CONTROL "Octave", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_LEFTNOWORDWRAP|WS_GROUP, 4, 2, 24, 8
	CStatic* mfc0 = new CStatic(parent);
	CRect r0(CPoint(4, 2), CSize(24, 8));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Octave"), WS_VISIBLE|WS_BORDER|SS_LEFTNOWORDWRAP|WS_GROUP, r0, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc0);

   // COMBOBOX IDC_OCTAVE,31,0,25,74,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|CBS_SORT|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc1 = new CComboBox(parent);
	CRect r1(CPoint(31,0),CSize(25,74));
	parent->MapDialogRect(&r1);
	mfc1->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|CBS_SORT|WS_VSCROLL|WS_TABSTOP,r1,parent,IDC_OCTAVE);
	mfcToQtWidget->insert(IDC_OCTAVE,mfc1);


	mfc1->AddString(_T("0"));
	

	mfc1->AddString(_T("1"));
	

	mfc1->AddString(_T("2"));
	

	mfc1->AddString(_T("3"));
	

	mfc1->AddString(_T("4"));
	

	mfc1->AddString(_T("5"));
	

	mfc1->AddString(_T("6"));
	

	mfc1->AddString(_T("7"));
	
   // CONTROL "Follow-mode", IDC_FOLLOW, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, 60, 0, 52, 13
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(60, 0), CSize(52, 13));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Follow-mode"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, r2, parent, IDC_FOLLOW);
	mfcToQtWidget->insert(IDC_FOLLOW, mfc2);

   // CONTROL "Compact view", IDC_CHECK_COMPACT, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, 115, 0, 52, 13
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(115, 0), CSize(52, 13));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Compact view"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, r3, parent, IDC_CHECK_COMPACT);
	mfcToQtWidget->insert(IDC_CHECK_COMPACT, mfc3);

   // CONTROL "Row highlight, 1st", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_LEFTNOWORDWRAP|WS_GROUP, 173, 2, 58, 8
	CStatic* mfc4 = new CStatic(parent);
	CRect r4(CPoint(173, 2), CSize(58, 8));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Row highlight, 1st"), WS_VISIBLE|WS_BORDER|SS_LEFTNOWORDWRAP|WS_GROUP, r4, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc4);

   // EDITTEXT IDC_HIGHLIGHT1,235,0,27,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY|ES_NUMBER
	CEdit* mfc5 = new CEdit(parent);
	CRect r5(CPoint(235,0),CSize(27,12));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY|ES_NUMBER,r5,parent,IDC_HIGHLIGHT1);
	mfcToQtWidget->insert(IDC_HIGHLIGHT1,mfc5);

   // CONTROL "", IDC_HIGHLIGHTSPIN1, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 257, 2, 11, 6
	CSpinButtonCtrl* mfc6 = new CSpinButtonCtrl(parent);
	CRect r6(CPoint(257, 2), CSize(11, 6));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r6, parent, IDC_HIGHLIGHTSPIN1);
	mfcToQtWidget->insert(IDC_HIGHLIGHTSPIN1, mfc6);

   // CONTROL "2nd", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_LEFTNOWORDWRAP|WS_GROUP, 269, 2, 13, 8
	CStatic* mfc7 = new CStatic(parent);
	CRect r7(CPoint(269, 2), CSize(13, 8));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("2nd"), WS_VISIBLE|WS_BORDER|SS_LEFTNOWORDWRAP|WS_GROUP, r7, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc7);

   // EDITTEXT IDC_HIGHLIGHT2,285,0,27,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY|ES_NUMBER
	CEdit* mfc8 = new CEdit(parent);
	CRect r8(CPoint(285,0),CSize(27,12));
	parent->MapDialogRect(&r8);
	mfc8->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_READONLY|ES_NUMBER,r8,parent,IDC_HIGHLIGHT2);
	mfcToQtWidget->insert(IDC_HIGHLIGHT2,mfc8);

   // CONTROL "", IDC_HIGHLIGHTSPIN2, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 307, 2, 11, 6
	CSpinButtonCtrl* mfc9 = new CSpinButtonCtrl(parent);
	CRect r9(CPoint(307, 2), CSize(11, 6));
	parent->MapDialogRect(&r9);
	mfc9->Create(WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r9, parent, IDC_HIGHLIGHTSPIN2);
	mfcToQtWidget->insert(IDC_HIGHLIGHTSPIN2, mfc9);

   // END
}


void qtMfcInitDialogResource_IDD_EXPORT(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_EXPORT DIALOGEX 0, 0, 247, 283
	CRect rect(CPoint(0,0),CSize(247,283));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Export file"
	parent->SetWindowText("Export file");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "NSF file options",IDC_STATIC,7,7,173,75
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(173,75));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("NSF file options"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Progress",IDC_STATIC,7,120,233,156
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7,120),CSize(233,156));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Progress"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Type of file",IDC_STATIC,7,87,233,29
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(7,87),CSize(233,29));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Type of file"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // DEFPUSHBUTTON "&Export",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,187,7,53,14
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(187,7),CSize(53,14));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("&Export"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r3,parent,IDC_EXPORT);
	mfcToQtWidget->insert(IDC_EXPORT,mfc3);

   // PUSHBUTTON "&Close",IDC_CLOSE,187,23,53,14,WS_VISIBLE|WS_BORDER
	CButton* mfc4 = new CButton(parent);
	CRect r4(CPoint(187,23),CSize(53,14));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("&Close"),WS_VISIBLE|WS_BORDER,r4,parent,IDC_CLOSE);
	mfcToQtWidget->insert(IDC_CLOSE,mfc4);

   // EDITTEXT IDC_NAME,60,18,114,13,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc5 = new CEdit(parent);
	CRect r5(CPoint(60,18),CSize(114,13));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r5,parent,IDC_NAME);
	mfcToQtWidget->insert(IDC_NAME,mfc5);

   // EDITTEXT IDC_ARTIST,60,33,114,13,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc6 = new CEdit(parent);
	CRect r6(CPoint(60,33),CSize(114,13));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r6,parent,IDC_ARTIST);
	mfcToQtWidget->insert(IDC_ARTIST,mfc6);

   // EDITTEXT IDC_COPYRIGHT,60,49,114,13,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc7 = new CEdit(parent);
	CRect r7(CPoint(60,49),CSize(114,13));
	parent->MapDialogRect(&r7);
	mfc7->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r7,parent,IDC_COPYRIGHT);
	mfcToQtWidget->insert(IDC_COPYRIGHT,mfc7);

   // CONTROL "NTSC", IDC_NTSC, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, 16, 67, 33, 10
	CButton* mfc8 = new CButton(parent);
	CRect r8(CPoint(16, 67), CSize(33, 10));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("NTSC"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, r8, parent, IDC_NTSC);
	mfcToQtWidget->insert(IDC_NTSC, mfc8);

   // CONTROL "PAL", IDC_PAL, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, 54, 67, 28, 10
	CButton* mfc9 = new CButton(parent);
	CRect r9(CPoint(54, 67), CSize(28, 10));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("PAL"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, r9, parent, IDC_PAL);
	mfcToQtWidget->insert(IDC_PAL, mfc9);

   // CONTROL "Dual", IDC_DUAL, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, 88, 67, 30, 10
	CButton* mfc10 = new CButton(parent);
	CRect r10(CPoint(88, 67), CSize(30, 10));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("Dual"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, r10, parent, IDC_DUAL);
	mfcToQtWidget->insert(IDC_DUAL, mfc10);

   // COMBOBOX IDC_TYPE,16,97,218,100,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc11 = new CComboBox(parent);
	CRect r11(CPoint(16,97),CSize(218,100));
	parent->MapDialogRect(&r11);
	mfc11->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r11,parent,IDC_TYPE);
	mfcToQtWidget->insert(IDC_TYPE,mfc11);

   // LTEXT "Name",IDC_STATIC,16,20,38,11
	CStatic* mfc13 = new CStatic(parent);
	CRect r13(CPoint(16,20),CSize(38,11));
	parent->MapDialogRect(&r13);
	mfc13->Create(_T("Name"),WS_VISIBLE|WS_BORDER,r13,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Artist",IDC_STATIC,16,35,38,11
	CStatic* mfc14 = new CStatic(parent);
	CRect r14(CPoint(16,35),CSize(38,11));
	parent->MapDialogRect(&r14);
	mfc14->Create(_T("Artist"),WS_VISIBLE|WS_BORDER,r14,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Copyright",IDC_STATIC,16,51,38,11
	CStatic* mfc15 = new CStatic(parent);
	CRect r15(CPoint(16,51),CSize(38,11));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("Copyright"),WS_VISIBLE|WS_BORDER,r15,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_OUTPUT,16,132,218,139,WS_VISIBLE|ES_MULTILINE|ES_AUTOHSCROLL|ES_READONLY|WS_VSCROLL
	CEdit* mfc17 = new CEdit(parent);
	CRect r17(CPoint(16,132),CSize(218,139));
	parent->MapDialogRect(&r17);
	mfc17->Create(WS_VISIBLE|ES_MULTILINE|ES_AUTOHSCROLL|ES_READONLY|WS_VSCROLL,r17,parent,IDC_OUTPUT);
	mfcToQtWidget->insert(IDC_OUTPUT,mfc17);

   // PUSHBUTTON "&Play",IDC_PLAY,187,68,53,14,WS_BORDER
	CButton* mfc19 = new CButton(parent);
	CRect r19(CPoint(187,68),CSize(53,14));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("&Play"),WS_BORDER,r19,parent,IDC_PLAY);
	mfcToQtWidget->insert(IDC_PLAY,mfc19);

   // END
}


void qtMfcInitDialogResource_IDD_INSTRUMENT_VRC7(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_INSTRUMENT_VRC7 DIALOGEX 0, 0, 372, 172
	CRect rect(CPoint(0,0),CSize(372,172));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());




   // BEGIN
   // GROUPBOX "Patch",IDC_STATIC,7,7,310,30
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(310,30));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Patch"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Modulator settings",IDC_STATIC,7,42,153,123
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7,42),CSize(153,123));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Modulator settings"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Carrier settings",IDC_STATIC,166,42,152,123
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(166,42),CSize(152,123));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Carrier settings"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_PATCH,15,18,295,128,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc4 = new CComboBox(parent);
	CRect r4(CPoint(15,18),CSize(295,128));
	parent->MapDialogRect(&r4);
	mfc4->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r4,parent,IDC_PATCH);
	mfcToQtWidget->insert(IDC_PATCH,mfc4);

   // PUSHBUTTON "Copy",IDC_COPY,322,7,43,14,WS_VISIBLE|WS_BORDER
	CButton* mfc5 = new CButton(parent);
	CRect r5(CPoint(322,7),CSize(43,14));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Copy"),WS_VISIBLE|WS_BORDER,r5,parent,IDC_COPY);
	mfcToQtWidget->insert(IDC_COPY,mfc5);

   // PUSHBUTTON "Paste",IDC_PASTE,322,23,43,14,WS_VISIBLE|WS_BORDER
	CButton* mfc6 = new CButton(parent);
	CRect r6(CPoint(322,23),CSize(43,14));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Paste"),WS_VISIBLE|WS_BORDER,r6,parent,IDC_PASTE);
	mfcToQtWidget->insert(IDC_PASTE,mfc6);

   // CONTROL "Amplitude modulation", IDC_M_AM, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 14, 54, 84, 10
	CButton* mfc8 = new CButton(parent);
	CRect r8(CPoint(14, 54), CSize(84, 10));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Amplitude modulation"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r8, parent, IDC_M_AM);
	mfcToQtWidget->insert(IDC_M_AM, mfc8);

   // CONTROL "Vibrato", IDC_M_VIB, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 109, 54, 39, 10
	CButton* mfc9 = new CButton(parent);
	CRect r9(CPoint(109, 54), CSize(39, 10));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("Vibrato"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r9, parent, IDC_M_VIB);
	mfcToQtWidget->insert(IDC_M_VIB, mfc9);

   // CONTROL "Sustained", IDC_M_EG, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 14, 70, 47, 10
	CButton* mfc10 = new CButton(parent);
	CRect r10(CPoint(14, 70), CSize(47, 10));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("Sustained"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r10, parent, IDC_M_EG);
	mfcToQtWidget->insert(IDC_M_EG, mfc10);

   // CONTROL "Key scaling", IDC_M_KSR2, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 14, 86, 51, 10
	CButton* mfc11 = new CButton(parent);
	CRect r11(CPoint(14, 86), CSize(51, 10));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T("Key scaling"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r11, parent, IDC_M_KSR2);
	mfcToQtWidget->insert(IDC_M_KSR2, mfc11);

   // CONTROL "Wave rectification", IDC_M_DM, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 74, 70, 74, 10
	CButton* mfc12 = new CButton(parent);
	CRect r12(CPoint(74, 70), CSize(74, 10));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T("Wave rectification"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r12, parent, IDC_M_DM);
	mfcToQtWidget->insert(IDC_M_DM, mfc12);

   // LTEXT "Level",IDC_STATIC,69,87,18,8
	CStatic* mfc13 = new CStatic(parent);
	CRect r13(CPoint(69,87),CSize(18,8));
	parent->MapDialogRect(&r13);
	mfc13->Create(_T("Level"),WS_VISIBLE|WS_BORDER,r13,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_M_KSL, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 90, 86, 58, 11
	CSliderCtrl* mfc14 = new CSliderCtrl(parent);
	CRect r14(CPoint(90, 86), CSize(58, 11));
	parent->MapDialogRect(&r14);
	mfc14->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r14, parent, IDC_M_KSL);
	mfcToQtWidget->insert(IDC_M_KSL, mfc14);

   // LTEXT "Mult. factor",IDC_STATIC,14,108,38,8
	CStatic* mfc15 = new CStatic(parent);
	CRect r15(CPoint(14,108),CSize(38,8));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("Mult. factor"),WS_VISIBLE|WS_BORDER,r15,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_M_MUL, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 51, 107, 105, 11
	CSliderCtrl* mfc16 = new CSliderCtrl(parent);
	CRect r16(CPoint(51, 107), CSize(105, 11));
	parent->MapDialogRect(&r16);
	mfc16->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r16, parent, IDC_M_MUL);
	mfcToQtWidget->insert(IDC_M_MUL, mfc16);

   // LTEXT "Attack",IDC_STATIC,14,127,22,8
	CStatic* mfc17 = new CStatic(parent);
	CRect r17(CPoint(14,127),CSize(22,8));
	parent->MapDialogRect(&r17);
	mfc17->Create(_T("Attack"),WS_VISIBLE|WS_BORDER,r17,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_M_AR, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 40, 126, 42, 11
	CSliderCtrl* mfc18 = new CSliderCtrl(parent);
	CRect r18(CPoint(40, 126), CSize(42, 11));
	parent->MapDialogRect(&r18);
	mfc18->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r18, parent, IDC_M_AR);
	mfcToQtWidget->insert(IDC_M_AR, mfc18);

   // LTEXT "Decay",IDC_STATIC,87,127,21,8
	CStatic* mfc19 = new CStatic(parent);
	CRect r19(CPoint(87,127),CSize(21,8));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("Decay"),WS_VISIBLE|WS_BORDER,r19,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_M_DR, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 114, 126, 42, 11
	CSliderCtrl* mfc20 = new CSliderCtrl(parent);
	CRect r20(CPoint(114, 126), CSize(42, 11));
	parent->MapDialogRect(&r20);
	mfc20->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r20, parent, IDC_M_DR);
	mfcToQtWidget->insert(IDC_M_DR, mfc20);

   // LTEXT "Sustain",IDC_STATIC,14,144,24,8
	CStatic* mfc21 = new CStatic(parent);
	CRect r21(CPoint(14,144),CSize(24,8));
	parent->MapDialogRect(&r21);
	mfc21->Create(_T("Sustain"),WS_VISIBLE|WS_BORDER,r21,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_M_SL, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 39, 143, 42, 11
	CSliderCtrl* mfc22 = new CSliderCtrl(parent);
	CRect r22(CPoint(39, 143), CSize(42, 11));
	parent->MapDialogRect(&r22);
	mfc22->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r22, parent, IDC_M_SL);
	mfcToQtWidget->insert(IDC_M_SL, mfc22);

   // LTEXT "Release",IDC_STATIC,85,144,26,8
	CStatic* mfc23 = new CStatic(parent);
	CRect r23(CPoint(85,144),CSize(26,8));
	parent->MapDialogRect(&r23);
	mfc23->Create(_T("Release"),WS_VISIBLE|WS_BORDER,r23,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_M_RR, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 114, 143, 42, 11
	CSliderCtrl* mfc24 = new CSliderCtrl(parent);
	CRect r24(CPoint(114, 143), CSize(42, 11));
	parent->MapDialogRect(&r24);
	mfc24->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r24, parent, IDC_M_RR);
	mfcToQtWidget->insert(IDC_M_RR, mfc24);

   // CONTROL "Amplitude modulation", IDC_C_AM, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 171, 54, 84, 10
	CButton* mfc26 = new CButton(parent);
	CRect r26(CPoint(171, 54), CSize(84, 10));
	parent->MapDialogRect(&r26);
	mfc26->Create(_T("Amplitude modulation"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r26, parent, IDC_C_AM);
	mfcToQtWidget->insert(IDC_C_AM, mfc26);

   // CONTROL "Vibrato", IDC_C_VIB, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 267, 54, 39, 10
	CButton* mfc27 = new CButton(parent);
	CRect r27(CPoint(267, 54), CSize(39, 10));
	parent->MapDialogRect(&r27);
	mfc27->Create(_T("Vibrato"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r27, parent, IDC_C_VIB);
	mfcToQtWidget->insert(IDC_C_VIB, mfc27);

   // CONTROL "Sustained", IDC_C_EG, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 171, 70, 47, 10
	CButton* mfc28 = new CButton(parent);
	CRect r28(CPoint(171, 70), CSize(47, 10));
	parent->MapDialogRect(&r28);
	mfc28->Create(_T("Sustained"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r28, parent, IDC_C_EG);
	mfcToQtWidget->insert(IDC_C_EG, mfc28);

   // CONTROL "Key scaling", IDC_C_KSR, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 171, 86, 51, 10
	CButton* mfc29 = new CButton(parent);
	CRect r29(CPoint(171, 86), CSize(51, 10));
	parent->MapDialogRect(&r29);
	mfc29->Create(_T("Key scaling"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r29, parent, IDC_C_KSR);
	mfcToQtWidget->insert(IDC_C_KSR, mfc29);

   // CONTROL "Wave rectification", IDC_C_DM, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 232, 70, 74, 10
	CButton* mfc30 = new CButton(parent);
	CRect r30(CPoint(232, 70), CSize(74, 10));
	parent->MapDialogRect(&r30);
	mfc30->Create(_T("Wave rectification"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r30, parent, IDC_C_DM);
	mfcToQtWidget->insert(IDC_C_DM, mfc30);

   // LTEXT "Level",IDC_STATIC,226,87,18,8
	CStatic* mfc31 = new CStatic(parent);
	CRect r31(CPoint(226,87),CSize(18,8));
	parent->MapDialogRect(&r31);
	mfc31->Create(_T("Level"),WS_VISIBLE|WS_BORDER,r31,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_C_KSL, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 247, 86, 59, 11
	CSliderCtrl* mfc32 = new CSliderCtrl(parent);
	CRect r32(CPoint(247, 86), CSize(59, 11));
	parent->MapDialogRect(&r32);
	mfc32->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r32, parent, IDC_C_KSL);
	mfcToQtWidget->insert(IDC_C_KSL, mfc32);

   // LTEXT "Mult. factor",IDC_STATIC,171,108,38,8
	CStatic* mfc33 = new CStatic(parent);
	CRect r33(CPoint(171,108),CSize(38,8));
	parent->MapDialogRect(&r33);
	mfc33->Create(_T("Mult. factor"),WS_VISIBLE|WS_BORDER,r33,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_C_MUL, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 208, 107, 106, 11
	CSliderCtrl* mfc34 = new CSliderCtrl(parent);
	CRect r34(CPoint(208, 107), CSize(106, 11));
	parent->MapDialogRect(&r34);
	mfc34->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r34, parent, IDC_C_MUL);
	mfcToQtWidget->insert(IDC_C_MUL, mfc34);

   // LTEXT "Attack",IDC_STATIC,171,127,22,8
	CStatic* mfc35 = new CStatic(parent);
	CRect r35(CPoint(171,127),CSize(22,8));
	parent->MapDialogRect(&r35);
	mfc35->Create(_T("Attack"),WS_VISIBLE|WS_BORDER,r35,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_C_AR, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 199, 126, 42, 11
	CSliderCtrl* mfc36 = new CSliderCtrl(parent);
	CRect r36(CPoint(199, 126), CSize(42, 11));
	parent->MapDialogRect(&r36);
	mfc36->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r36, parent, IDC_C_AR);
	mfcToQtWidget->insert(IDC_C_AR, mfc36);

   // LTEXT "Decay",IDC_STATIC,247,127,21,8
	CStatic* mfc37 = new CStatic(parent);
	CRect r37(CPoint(247,127),CSize(21,8));
	parent->MapDialogRect(&r37);
	mfc37->Create(_T("Decay"),WS_VISIBLE|WS_BORDER,r37,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_C_DR, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 271, 126, 43, 11
	CSliderCtrl* mfc38 = new CSliderCtrl(parent);
	CRect r38(CPoint(271, 126), CSize(43, 11));
	parent->MapDialogRect(&r38);
	mfc38->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r38, parent, IDC_C_DR);
	mfcToQtWidget->insert(IDC_C_DR, mfc38);

   // LTEXT "Sustain",IDC_STATIC,171,144,24,8
	CStatic* mfc39 = new CStatic(parent);
	CRect r39(CPoint(171,144),CSize(24,8));
	parent->MapDialogRect(&r39);
	mfc39->Create(_T("Sustain"),WS_VISIBLE|WS_BORDER,r39,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_C_SL, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 199, 143, 42, 11
	CSliderCtrl* mfc40 = new CSliderCtrl(parent);
	CRect r40(CPoint(199, 143), CSize(42, 11));
	parent->MapDialogRect(&r40);
	mfc40->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r40, parent, IDC_C_SL);
	mfcToQtWidget->insert(IDC_C_SL, mfc40);

   // LTEXT "Release",IDC_STATIC,245,144,26,8
	CStatic* mfc41 = new CStatic(parent);
	CRect r41(CPoint(245,144),CSize(26,8));
	parent->MapDialogRect(&r41);
	mfc41->Create(_T("Release"),WS_VISIBLE|WS_BORDER,r41,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_C_RR, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 271, 143, 43, 11
	CSliderCtrl* mfc42 = new CSliderCtrl(parent);
	CRect r42(CPoint(271, 143), CSize(43, 11));
	parent->MapDialogRect(&r42);
	mfc42->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r42, parent, IDC_C_RR);
	mfcToQtWidget->insert(IDC_C_RR, mfc42);

   // CTEXT "Modulator\nlevel",IDC_STATIC,322,42,36,17
	CStatic* mfc43 = new CStatic(parent);
	CRect r43(CPoint(322,42),CSize(36,17));
	parent->MapDialogRect(&r43);
	mfc43->Create(_T("Modulator\nlevel"),WS_VISIBLE|WS_BORDER,r43,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_TL, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_VERT|TBS_BOTH|TBS_NOTICKS|WS_TABSTOP, 329, 59, 16, 53
	CSliderCtrl* mfc44 = new CSliderCtrl(parent);
	CRect r44(CPoint(329, 59), CSize(16, 53));
	parent->MapDialogRect(&r44);
	mfc44->Create(WS_VISIBLE|WS_BORDER|TBS_VERT|TBS_BOTH|TBS_NOTICKS|WS_TABSTOP, r44, parent, IDC_TL);
	mfcToQtWidget->insert(IDC_TL, mfc44);

   // CTEXT "Feedback",IDC_STATIC,322,112,36,9
	CStatic* mfc45 = new CStatic(parent);
	CRect r45(CPoint(322,112),CSize(36,9));
	parent->MapDialogRect(&r45);
	mfc45->Create(_T("Feedback"),WS_VISIBLE|WS_BORDER,r45,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_FB, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, 325, 124, 25, 41
	CSliderCtrl* mfc46 = new CSliderCtrl(parent);
	CRect r46(CPoint(325, 124), CSize(25, 41));
	parent->MapDialogRect(&r46);
	mfc46->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, r46, parent, IDC_FB);
	mfcToQtWidget->insert(IDC_FB, mfc46);

   // END
}


void qtMfcInitDialogResource_IDD_CREATEWAV(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_CREATEWAV DIALOGEX 0, 0, 151, 208
	CRect rect(CPoint(0,0),CSize(151,208));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Create wave file"
	parent->SetWindowText("Create wave file");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Song length",IDC_STATIC,7,7,137,47
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(137,47));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Song length"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Channels",IDC_STATIC,7,96,137,87
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7,96),CSize(137,87));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Channels"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Song",IDC_STATIC,7,60,137,30
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(7,60),CSize(137,30));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Song"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // DEFPUSHBUTTON "Begin",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,37,187,52,14
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(37,187),CSize(52,14));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Begin"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r3,parent,IDC_BEGIN);
	mfcToQtWidget->insert(IDC_BEGIN,mfc3);

   // PUSHBUTTON "Cancel",IDCANCEL,92,187,52,14,WS_VISIBLE|WS_BORDER
	CButton* mfc4 = new CButton(parent);
	CRect r4(CPoint(92,187),CSize(52,14));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r4,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc4);

   // CONTROL "Play the song", IDC_RADIO_LOOP, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, 14, 20, 55, 10
	CButton* mfc6 = new CButton(parent);
	CRect r6(CPoint(14, 20), CSize(55, 10));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Play the song"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, r6, parent, IDC_RADIO_LOOP);
	mfcToQtWidget->insert(IDC_RADIO_LOOP, mfc6);

   // CONTROL "Play for", IDC_RADIO_TIME, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, 14, 38, 37, 10
	CButton* mfc7 = new CButton(parent);
	CRect r7(CPoint(14, 38), CSize(37, 10));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("Play for"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, r7, parent, IDC_RADIO_TIME);
	mfcToQtWidget->insert(IDC_RADIO_TIME, mfc7);

   // EDITTEXT IDC_TIMES,73,19,36,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc8 = new CEdit(parent);
	CRect r8(CPoint(73,19),CSize(36,12));
	parent->MapDialogRect(&r8);
	mfc8->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r8,parent,IDC_TIMES);
	mfcToQtWidget->insert(IDC_TIMES,mfc8);

   // CONTROL "", IDC_SPIN_LOOP, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 105, 17, 11, 17
	CSpinButtonCtrl* mfc9 = new CSpinButtonCtrl(parent);
	CRect r9(CPoint(105, 17), CSize(11, 17));
	parent->MapDialogRect(&r9);
	mfc9->Create(WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r9, parent, IDC_SPIN_LOOP);
	mfcToQtWidget->insert(IDC_SPIN_LOOP, mfc9);

   // LTEXT "time(s)",IDC_STATIC,115,20,21,10
	CStatic* mfc10 = new CStatic(parent);
	CRect r10(CPoint(115,20),CSize(21,10));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("time(s)"),WS_VISIBLE|WS_BORDER|SS_CENTERIMAGE,r10,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_SECONDS,53,37,44,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc11 = new CEdit(parent);
	CRect r11(CPoint(53,37),CSize(44,12));
	parent->MapDialogRect(&r11);
	mfc11->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r11,parent,IDC_SECONDS);
	mfcToQtWidget->insert(IDC_SECONDS,mfc11);

   // CONTROL "", IDC_SPIN_TIME, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 93, 36, 11, 14
	CSpinButtonCtrl* mfc12 = new CSpinButtonCtrl(parent);
	CRect r12(CPoint(93, 36), CSize(11, 14));
	parent->MapDialogRect(&r12);
	mfc12->Create(WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r12, parent, IDC_SPIN_TIME);
	mfcToQtWidget->insert(IDC_SPIN_TIME, mfc12);

   // LTEXT "mm:ss",IDC_STATIC,106,38,21,10
	CStatic* mfc13 = new CStatic(parent);
	CRect r13(CPoint(106,38),CSize(21,10));
	parent->MapDialogRect(&r13);
	mfc13->Create(_T("mm:ss"),WS_VISIBLE|WS_BORDER|SS_CENTERIMAGE,r13,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LISTBOX IDC_CHANNELS,14,107,124,70,WS_VISIBLE|WS_BORDER|LBS_OWNERDRAWFIXED|LBS_HASSTRINGS|LBS_NOINTEGRALHEIGHT|WS_VSCROLL|WS_TABSTOP
	CListBox* mfc15 = new CListBox(parent);
	CRect r15(CPoint(14,107),CSize(124,70));
	parent->MapDialogRect(&r15);
	mfc15->Create(WS_VISIBLE|WS_BORDER|LBS_OWNERDRAWFIXED|LBS_HASSTRINGS|LBS_NOINTEGRALHEIGHT|WS_VSCROLL|WS_TABSTOP,r15,parent,IDC_CHANNELS);
	mfcToQtWidget->insert(IDC_CHANNELS,mfc15);

   // COMBOBOX IDC_TRACKS,14,72,124,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|CBS_SORT|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc17 = new CComboBox(parent);
	CRect r17(CPoint(14,72),CSize(124,30));
	parent->MapDialogRect(&r17);
	mfc17->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|CBS_SORT|WS_VSCROLL|WS_TABSTOP,r17,parent,IDC_TRACKS);
	mfcToQtWidget->insert(IDC_TRACKS,mfc17);

   // END
}


void qtMfcInitDialogResource_IDD_MAINBAR(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_MAINBAR DIALOGEX 0, 0, 143, 128
	CRect rect(CPoint(0,0),CSize(143,128));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());




   // BEGIN
   // END
}


void qtMfcInitDialogResource_IDD_INSTRUMENT_FDS(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_INSTRUMENT_FDS DIALOGEX 0, 0, 372, 172
	CRect rect(CPoint(0,0),CSize(372,172));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());




   // BEGIN
   // GROUPBOX "Wave editor",IDC_STATIC,7,7,228,111
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(228,111));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Wave editor"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Frequency modulation",IDC_STATIC,240,7,124,79
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(240,7),CSize(124,79));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Frequency modulation"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // PUSHBUTTON "Sine",IDC_PRESET_SINE,14,101,41,12,WS_VISIBLE|WS_BORDER
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(14,101),CSize(41,12));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Sine"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_PRESET_SINE);
	mfcToQtWidget->insert(IDC_PRESET_SINE,mfc3);

   // PUSHBUTTON "Triangle",IDC_PRESET_TRIANGLE,57,101,41,12,WS_VISIBLE|WS_BORDER
	CButton* mfc4 = new CButton(parent);
	CRect r4(CPoint(57,101),CSize(41,12));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Triangle"),WS_VISIBLE|WS_BORDER,r4,parent,IDC_PRESET_TRIANGLE);
	mfcToQtWidget->insert(IDC_PRESET_TRIANGLE,mfc4);

   // PUSHBUTTON "Sawtooth",IDC_PRESET_SAWTOOTH,100,101,41,12,WS_VISIBLE|WS_BORDER
	CButton* mfc5 = new CButton(parent);
	CRect r5(CPoint(100,101),CSize(41,12));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Sawtooth"),WS_VISIBLE|WS_BORDER,r5,parent,IDC_PRESET_SAWTOOTH);
	mfcToQtWidget->insert(IDC_PRESET_SAWTOOTH,mfc5);

   // LTEXT "Modulation rate",IDC_STATIC,246,24,51,8
	CStatic* mfc6 = new CStatic(parent);
	CRect r6(CPoint(246,24),CSize(51,8));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Modulation rate"),WS_VISIBLE|WS_BORDER,r6,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_MOD_RATE,318,22,37,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc7 = new CEdit(parent);
	CRect r7(CPoint(318,22),CSize(37,14));
	parent->MapDialogRect(&r7);
	mfc7->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r7,parent,IDC_MOD_RATE);
	mfcToQtWidget->insert(IDC_MOD_RATE,mfc7);

   // CONTROL "", IDC_MOD_RATE_SPIN, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS|UDS_NOTHOUSANDS, 344, 25, 11, 14
	CSpinButtonCtrl* mfc8 = new CSpinButtonCtrl(parent);
	CRect r8(CPoint(344, 25), CSize(11, 14));
	parent->MapDialogRect(&r8);
	mfc8->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS|UDS_NOTHOUSANDS, r8, parent, IDC_MOD_RATE_SPIN);
	mfcToQtWidget->insert(IDC_MOD_RATE_SPIN, mfc8);

   // LTEXT "Modulation depth",IDC_STATIC,246,46,56,8
	CStatic* mfc9 = new CStatic(parent);
	CRect r9(CPoint(246,46),CSize(56,8));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("Modulation depth"),WS_VISIBLE|WS_BORDER,r9,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_MOD_DEPTH,318,43,37,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc10 = new CEdit(parent);
	CRect r10(CPoint(318,43),CSize(37,14));
	parent->MapDialogRect(&r10);
	mfc10->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r10,parent,IDC_MOD_DEPTH);
	mfcToQtWidget->insert(IDC_MOD_DEPTH,mfc10);

   // CONTROL "", IDC_MOD_DEPTH_SPIN, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 344, 43, 11, 14
	CSpinButtonCtrl* mfc11 = new CSpinButtonCtrl(parent);
	CRect r11(CPoint(344, 43), CSize(11, 14));
	parent->MapDialogRect(&r11);
	mfc11->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r11, parent, IDC_MOD_DEPTH_SPIN);
	mfcToQtWidget->insert(IDC_MOD_DEPTH_SPIN, mfc11);

   // LTEXT "Modulation delay",IDC_STATIC,246,68,55,8
	CStatic* mfc12 = new CStatic(parent);
	CRect r12(CPoint(246,68),CSize(55,8));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T("Modulation delay"),WS_VISIBLE|WS_BORDER,r12,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_MOD_DELAY,318,65,37,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc13 = new CEdit(parent);
	CRect r13(CPoint(318,65),CSize(37,14));
	parent->MapDialogRect(&r13);
	mfc13->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r13,parent,IDC_MOD_DELAY);
	mfcToQtWidget->insert(IDC_MOD_DELAY,mfc13);

   // CONTROL "", IDC_MOD_DELAY_SPIN, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 344, 63, 11, 14
	CSpinButtonCtrl* mfc14 = new CSpinButtonCtrl(parent);
	CRect r14(CPoint(344, 63), CSize(11, 14));
	parent->MapDialogRect(&r14);
	mfc14->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r14, parent, IDC_MOD_DELAY_SPIN);
	mfcToQtWidget->insert(IDC_MOD_DELAY_SPIN, mfc14);

   // PUSHBUTTON "Flat",IDC_MOD_PRESET_FLAT,318,131,46,12,WS_VISIBLE|WS_BORDER
	CButton* mfc15 = new CButton(parent);
	CRect r15(CPoint(318,131),CSize(46,12));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("Flat"),WS_VISIBLE|WS_BORDER,r15,parent,IDC_MOD_PRESET_FLAT);
	mfcToQtWidget->insert(IDC_MOD_PRESET_FLAT,mfc15);

   // PUSHBUTTON "Sine",IDC_MOD_PRESET_SINE,318,148,46,12,WS_VISIBLE|WS_BORDER
	CButton* mfc16 = new CButton(parent);
	CRect r16(CPoint(318,148),CSize(46,12));
	parent->MapDialogRect(&r16);
	mfc16->Create(_T("Sine"),WS_VISIBLE|WS_BORDER,r16,parent,IDC_MOD_PRESET_SINE);
	mfcToQtWidget->insert(IDC_MOD_PRESET_SINE,mfc16);

   // PUSHBUTTON "Copy wave",IDC_COPY_WAVE,240,90,59,14,WS_VISIBLE|WS_BORDER
	CButton* mfc18 = new CButton(parent);
	CRect r18(CPoint(240,90),CSize(59,14));
	parent->MapDialogRect(&r18);
	mfc18->Create(_T("Copy wave"),WS_VISIBLE|WS_BORDER,r18,parent,IDC_COPY_WAVE);
	mfcToQtWidget->insert(IDC_COPY_WAVE,mfc18);

   // PUSHBUTTON "Paste wave",IDC_PASTE_WAVE,240,104,59,14,WS_VISIBLE|WS_BORDER
	CButton* mfc19 = new CButton(parent);
	CRect r19(CPoint(240,104),CSize(59,14));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("Paste wave"),WS_VISIBLE|WS_BORDER,r19,parent,IDC_PASTE_WAVE);
	mfcToQtWidget->insert(IDC_PASTE_WAVE,mfc19);

   // PUSHBUTTON "Copy table",IDC_COPY_TABLE,305,90,59,14,WS_VISIBLE|WS_BORDER
	CButton* mfc20 = new CButton(parent);
	CRect r20(CPoint(305,90),CSize(59,14));
	parent->MapDialogRect(&r20);
	mfc20->Create(_T("Copy table"),WS_VISIBLE|WS_BORDER,r20,parent,IDC_COPY_TABLE);
	mfcToQtWidget->insert(IDC_COPY_TABLE,mfc20);

   // PUSHBUTTON "Paste table",IDC_PASTE_TABLE,305,104,59,14,WS_VISIBLE|WS_BORDER
	CButton* mfc21 = new CButton(parent);
	CRect r21(CPoint(305,104),CSize(59,14));
	parent->MapDialogRect(&r21);
	mfc21->Create(_T("Paste table"),WS_VISIBLE|WS_BORDER,r21,parent,IDC_PASTE_TABLE);
	mfcToQtWidget->insert(IDC_PASTE_TABLE,mfc21);

   // PUSHBUTTON "50% pulse",IDC_PRESET_PULSE_50,143,101,41,12,WS_VISIBLE|WS_BORDER
	CButton* mfc22 = new CButton(parent);
	CRect r22(CPoint(143,101),CSize(41,12));
	parent->MapDialogRect(&r22);
	mfc22->Create(_T("50% pulse"),WS_VISIBLE|WS_BORDER,r22,parent,IDC_PRESET_PULSE_50);
	mfcToQtWidget->insert(IDC_PRESET_PULSE_50,mfc22);

   // PUSHBUTTON "25% pulse",IDC_PRESET_PULSE_25,186,101,41,12,WS_VISIBLE|WS_BORDER
	CButton* mfc23 = new CButton(parent);
	CRect r23(CPoint(186,101),CSize(41,12));
	parent->MapDialogRect(&r23);
	mfc23->Create(_T("25% pulse"),WS_VISIBLE|WS_BORDER,r23,parent,IDC_PRESET_PULSE_25);
	mfcToQtWidget->insert(IDC_PRESET_PULSE_25,mfc23);

   // END
}


void qtMfcInitDialogResource_IDD_FRAMECONTROLS(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_FRAMECONTROLS DIALOGEX 0, 0, 107, 12
	CRect rect(CPoint(0,0),CSize(107,12));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());


   // STYLE DS_SETFONT|DS_FIXEDSYS|DS_CONTROL|WS_CHILD|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::WindowSystemMenuHint);


   // BEGIN
   // PUSHBUTTON "+",IDC_FRAME_INC,0,0,17,12,WS_VISIBLE|WS_BORDER
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(0,0),CSize(17,12));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("+"),WS_VISIBLE|WS_BORDER,r0,parent,IDC_FRAME_INC);
	mfcToQtWidget->insert(IDC_FRAME_INC,mfc0);

   // PUSHBUTTON "-",IDC_FRAME_DEC,23,0,17,12,WS_VISIBLE|WS_BORDER
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(23,0),CSize(17,12));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("-"),WS_VISIBLE|WS_BORDER,r1,parent,IDC_FRAME_DEC);
	mfcToQtWidget->insert(IDC_FRAME_DEC,mfc1);

   // CONTROL "Change all", IDC_CHANGE_ALL, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 51, 2, 56, 10
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(51, 2), CSize(56, 10));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Change all"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r2, parent, IDC_CHANGE_ALL);
	mfcToQtWidget->insert(IDC_CHANGE_ALL, mfc2);

   // END
}


void qtMfcInitDialogResource_IDD_INSTRUMENT_FDS_ENVELOPE(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_INSTRUMENT_FDS_ENVELOPE DIALOGEX 0, 0, 372, 172
	CRect rect(CPoint(0,0),CSize(372,172));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());




   // BEGIN
   // EDITTEXT IDC_SEQUENCE_STRING,75,151,290,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc0 = new CEdit(parent);
	CRect r0(CPoint(75,151),CSize(290,14));
	parent->MapDialogRect(&r0);
	mfc0->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r0,parent,IDC_SEQUENCE_STRING);
	mfcToQtWidget->insert(IDC_SEQUENCE_STRING,mfc0);

   // COMBOBOX IDC_TYPE,8,151,63,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc1 = new CComboBox(parent);
	CRect r1(CPoint(8,151),CSize(63,30));
	parent->MapDialogRect(&r1);
	mfc1->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r1,parent,IDC_TYPE);
	mfcToQtWidget->insert(IDC_TYPE,mfc1);


	mfc1->AddString(_T("Volume"));
	

	mfc1->AddString(_T("Arpeggio"));
	

	mfc1->AddString(_T("Pitch"));
	
   // END
}


void qtMfcInitDialogResource_IDD_CHANNELS(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_CHANNELS DIALOGEX 0, 0, 303, 236
	CRect rect(CPoint(0,0),CSize(303,236));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Channels"
	parent->SetWindowText("Channels");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Available channels",IDC_STATIC,7,7,138,197
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(138,197));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Available channels"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Added channels",IDC_STATIC,151,7,145,197
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(151,7),CSize(145,197));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Added channels"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,194,215,50,14
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(194,215),CSize(50,14));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r2,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc2);

   // PUSHBUTTON "Cancel",IDCANCEL,246,215,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(246,215),CSize(50,14));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r3,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc3);

   // PUSHBUTTON "Move up",IDC_MOVE_UP,7,215,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc4 = new CButton(parent);
	CRect r4(CPoint(7,215),CSize(50,14));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Move up"),WS_VISIBLE|WS_BORDER,r4,parent,IDC_MOVE_UP);
	mfcToQtWidget->insert(IDC_MOVE_UP,mfc4);

   // PUSHBUTTON "Move down",IDC_MOVE_DOWN,62,215,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc5 = new CButton(parent);
	CRect r5(CPoint(62,215),CSize(50,14));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Move down"),WS_VISIBLE|WS_BORDER,r5,parent,IDC_MOVE_DOWN);
	mfcToQtWidget->insert(IDC_MOVE_DOWN,mfc5);

   // CONTROL "", IDC_ADDED_LIST, "SysListView32", WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|LVS_NOCOLUMNHEADER|WS_BORDER|WS_TABSTOP, 159, 17, 129, 181
	CListCtrl* mfc6 = new CListCtrl(parent);
	CRect r6(CPoint(159, 17), CSize(129, 181));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|LVS_NOCOLUMNHEADER|WS_BORDER|WS_TABSTOP, r6, parent, IDC_ADDED_LIST);
	mfcToQtWidget->insert(IDC_ADDED_LIST, mfc6);

   // CONTROL "", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, 7, 209, 289, 1
	CStatic* mfc7 = new CStatic(parent);
	CRect r7(CPoint(7, 209), CSize(289, 1));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, r7, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc7);

   // CONTROL "", IDC_AVAILABLE_TREE, "SysTreeView32", WS_VISIBLE|WS_BORDER|TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT|WS_BORDER|WS_HSCROLL|WS_TABSTOP, 14, 17, 122, 181
	CTreeCtrl* mfc10 = new CTreeCtrl(parent);
	CRect r10(CPoint(14, 17), CSize(122, 181));
	parent->MapDialogRect(&r10);
	mfc10->Create(WS_VISIBLE|WS_BORDER|TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT|WS_BORDER|WS_HSCROLL|WS_TABSTOP, r10, parent, IDC_AVAILABLE_TREE);
	mfcToQtWidget->insert(IDC_AVAILABLE_TREE, mfc10);

   // END
}


void qtMfcInitDialogResource_IDD_HEADER(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_HEADER DIALOGEX 0, 0, 530, 21
	CRect rect(CPoint(0,0),CSize(530,21));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());


   // STYLE DS_SETFONT|DS_FIXEDSYS|WS_CHILD|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::WindowSystemMenuHint);


   // BEGIN
   // END
}


void qtMfcInitDialogResource_IDD_COMMENTS(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_COMMENTS DIALOGEX 0, 0, 358, 230
	CRect rect(CPoint(0,0),CSize(358,230));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Module comments"
	parent->SetWindowText("Module comments");

   // STYLE DS_SETFONT|DS_FIXEDSYS|WS_MINIMIZEBOX|WS_MAXIMIZEBOX|WS_POPUP|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::WindowMinimizeButtonHint|Qt::WindowMaximizeButtonHint|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // PUSHBUTTON "Cancel",IDCANCEL,304,211,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(304,211),CSize(50,14));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r0,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc0);

   // EDITTEXT IDC_COMMENTS,0,0,358,206,WS_VISIBLE|WS_BORDER|ES_MULTILINE|ES_AUTOVSCROLL|ES_AUTOHSCROLL|ES_WANTRETURN|WS_VSCROLL|WS_HSCROLL
	CEdit* mfc1 = new CEdit(parent);
	CRect r1(CPoint(0,0),CSize(358,206));
	parent->MapDialogRect(&r1);
	mfc1->Create(WS_VISIBLE|WS_BORDER|ES_MULTILINE|ES_AUTOVSCROLL|ES_AUTOHSCROLL|ES_WANTRETURN|WS_VSCROLL|WS_HSCROLL,r1,parent,IDC_COMMENTS);
	mfcToQtWidget->insert(IDC_COMMENTS,mfc1);

   // CONTROL "Show when loading file", IDC_SHOWONOPEN, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 5, 215, 89, 10
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(5, 215), CSize(89, 10));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Show when loading file"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r2, parent, IDC_SHOWONOPEN);
	mfcToQtWidget->insert(IDC_SHOWONOPEN, mfc2);

   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,248,211,50,14
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(248,211),CSize(50,14));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r3,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc3);

   // END
}


void qtMfcInitDialogResource_IDD_CONFIG_MIXER(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_CONFIG_MIXER DIALOGEX 0, 0, 280, 167
	CRect rect(CPoint(0,0),CSize(280,167));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Mixer"
	parent->SetWindowText("Mixer");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // CONTROL "", IDC_SLIDER_APU1, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, 7, 34, 26, 110
	CSliderCtrl* mfc0 = new CSliderCtrl(parent);
	CRect r0(CPoint(7, 34), CSize(26, 110));
	parent->MapDialogRect(&r0);
	mfc0->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, r0, parent, IDC_SLIDER_APU1);
	mfcToQtWidget->insert(IDC_SLIDER_APU1, mfc0);

   // CTEXT "APU1",IDC_STATIC,7,26,26,8
	CStatic* mfc1 = new CStatic(parent);
	CRect r1(CPoint(7,26),CSize(26,8));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("APU1"),WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SLIDER_APU2, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, 41, 34, 26, 110
	CSliderCtrl* mfc2 = new CSliderCtrl(parent);
	CRect r2(CPoint(41, 34), CSize(26, 110));
	parent->MapDialogRect(&r2);
	mfc2->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, r2, parent, IDC_SLIDER_APU2);
	mfcToQtWidget->insert(IDC_SLIDER_APU2, mfc2);

   // CTEXT "APU2",IDC_STATIC,41,26,26,8
	CStatic* mfc3 = new CStatic(parent);
	CRect r3(CPoint(41,26),CSize(26,8));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("APU2"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SLIDER_VRC6, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, 75, 34, 26, 110
	CSliderCtrl* mfc4 = new CSliderCtrl(parent);
	CRect r4(CPoint(75, 34), CSize(26, 110));
	parent->MapDialogRect(&r4);
	mfc4->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, r4, parent, IDC_SLIDER_VRC6);
	mfcToQtWidget->insert(IDC_SLIDER_VRC6, mfc4);

   // CTEXT "VRC6",IDC_STATIC,75,26,26,8
	CStatic* mfc5 = new CStatic(parent);
	CRect r5(CPoint(75,26),CSize(26,8));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("VRC6"),WS_VISIBLE|WS_BORDER,r5,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SLIDER_VRC7, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, 109, 34, 26, 110
	CSliderCtrl* mfc6 = new CSliderCtrl(parent);
	CRect r6(CPoint(109, 34), CSize(26, 110));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, r6, parent, IDC_SLIDER_VRC7);
	mfcToQtWidget->insert(IDC_SLIDER_VRC7, mfc6);

   // CTEXT "VRC7",IDC_STATIC,109,26,26,8
	CStatic* mfc7 = new CStatic(parent);
	CRect r7(CPoint(109,26),CSize(26,8));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("VRC7"),WS_VISIBLE|WS_BORDER,r7,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SLIDER_MMC5, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, 143, 34, 26, 110
	CSliderCtrl* mfc8 = new CSliderCtrl(parent);
	CRect r8(CPoint(143, 34), CSize(26, 110));
	parent->MapDialogRect(&r8);
	mfc8->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, r8, parent, IDC_SLIDER_MMC5);
	mfcToQtWidget->insert(IDC_SLIDER_MMC5, mfc8);

   // CTEXT "MMC5",IDC_STATIC,143,26,26,8
	CStatic* mfc9 = new CStatic(parent);
	CRect r9(CPoint(143,26),CSize(26,8));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("MMC5"),WS_VISIBLE|WS_BORDER,r9,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SLIDER_FDS, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, 177, 34, 26, 110
	CSliderCtrl* mfc10 = new CSliderCtrl(parent);
	CRect r10(CPoint(177, 34), CSize(26, 110));
	parent->MapDialogRect(&r10);
	mfc10->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, r10, parent, IDC_SLIDER_FDS);
	mfcToQtWidget->insert(IDC_SLIDER_FDS, mfc10);

   // CTEXT "FDS",IDC_STATIC,177,26,26,8
	CStatic* mfc11 = new CStatic(parent);
	CRect r11(CPoint(177,26),CSize(26,8));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T("FDS"),WS_VISIBLE|WS_BORDER,r11,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SLIDER_N163, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, 211, 34, 26, 110
	CSliderCtrl* mfc12 = new CSliderCtrl(parent);
	CRect r12(CPoint(211, 34), CSize(26, 110));
	parent->MapDialogRect(&r12);
	mfc12->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, r12, parent, IDC_SLIDER_N163);
	mfcToQtWidget->insert(IDC_SLIDER_N163, mfc12);

   // CTEXT "N163",IDC_STATIC,211,26,26,8
	CStatic* mfc13 = new CStatic(parent);
	CRect r13(CPoint(211,26),CSize(26,8));
	parent->MapDialogRect(&r13);
	mfc13->Create(_T("N163"),WS_VISIBLE|WS_BORDER,r13,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SLIDER_S5B, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, 245, 34, 26, 110
	CSliderCtrl* mfc14 = new CSliderCtrl(parent);
	CRect r14(CPoint(245, 34), CSize(26, 110));
	parent->MapDialogRect(&r14);
	mfc14->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, r14, parent, IDC_SLIDER_S5B);
	mfcToQtWidget->insert(IDC_SLIDER_S5B, mfc14);

   // CTEXT "S5B",IDC_STATIC,245,26,26,8
	CStatic* mfc15 = new CStatic(parent);
	CRect r15(CPoint(245,26),CSize(26,8));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("S5B"),WS_VISIBLE|WS_BORDER,r15,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "0.0dB",IDC_LEVEL_APU1,7,149,30,8
	CStatic* mfc16 = new CStatic(parent);
	CRect r16(CPoint(7,149),CSize(30,8));
	parent->MapDialogRect(&r16);
	mfc16->Create(_T("0.0dB"),WS_VISIBLE|WS_BORDER,r16,parent,IDC_LEVEL_APU1);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "0.0dB",IDC_LEVEL_APU2,40,149,30,8
	CStatic* mfc17 = new CStatic(parent);
	CRect r17(CPoint(40,149),CSize(30,8));
	parent->MapDialogRect(&r17);
	mfc17->Create(_T("0.0dB"),WS_VISIBLE|WS_BORDER,r17,parent,IDC_LEVEL_APU2);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "0.0dB",IDC_LEVEL_VRC6,73,149,30,8
	CStatic* mfc18 = new CStatic(parent);
	CRect r18(CPoint(73,149),CSize(30,8));
	parent->MapDialogRect(&r18);
	mfc18->Create(_T("0.0dB"),WS_VISIBLE|WS_BORDER,r18,parent,IDC_LEVEL_VRC6);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "0.0dB",IDC_LEVEL_VRC7,108,149,30,8
	CStatic* mfc19 = new CStatic(parent);
	CRect r19(CPoint(108,149),CSize(30,8));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("0.0dB"),WS_VISIBLE|WS_BORDER,r19,parent,IDC_LEVEL_VRC7);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "0.0dB",IDC_LEVEL_MMC5,142,149,30,8
	CStatic* mfc20 = new CStatic(parent);
	CRect r20(CPoint(142,149),CSize(30,8));
	parent->MapDialogRect(&r20);
	mfc20->Create(_T("0.0dB"),WS_VISIBLE|WS_BORDER,r20,parent,IDC_LEVEL_MMC5);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "0.0dB",IDC_LEVEL_FDS,176,149,30,8
	CStatic* mfc21 = new CStatic(parent);
	CRect r21(CPoint(176,149),CSize(30,8));
	parent->MapDialogRect(&r21);
	mfc21->Create(_T("0.0dB"),WS_VISIBLE|WS_BORDER,r21,parent,IDC_LEVEL_FDS);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "0.0dB",IDC_LEVEL_N163,209,149,30,8
	CStatic* mfc22 = new CStatic(parent);
	CRect r22(CPoint(209,149),CSize(30,8));
	parent->MapDialogRect(&r22);
	mfc22->Create(_T("0.0dB"),WS_VISIBLE|WS_BORDER,r22,parent,IDC_LEVEL_N163);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "0.0dB",IDC_LEVEL_S5B,243,149,30,8
	CStatic* mfc23 = new CStatic(parent);
	CRect r23(CPoint(243,149),CSize(30,8));
	parent->MapDialogRect(&r23);
	mfc23->Create(_T("0.0dB"),WS_VISIBLE|WS_BORDER,r23,parent,IDC_LEVEL_S5B);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Hardware mixing levels",IDC_STATIC,7,7,74,8
	CStatic* mfc24 = new CStatic(parent);
	CRect r24(CPoint(7,7),CSize(74,8));
	parent->MapDialogRect(&r24);
	mfc24->Create(_T("Hardware mixing levels"),WS_VISIBLE|WS_BORDER,r24,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // PUSHBUTTON "Reset",IDC_BUTTON_MIXER_RESET,223,7,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc25 = new CButton(parent);
	CRect r25(CPoint(223,7),CSize(50,14));
	parent->MapDialogRect(&r25);
	mfc25->Create(_T("Reset"),WS_VISIBLE|WS_BORDER,r25,parent,IDC_BUTTON_MIXER_RESET);
	mfcToQtWidget->insert(IDC_BUTTON_MIXER_RESET,mfc25);

   // END
}


void qtMfcInitDialogResource_IDD_INSTRUMENT_N163_WAVE(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_INSTRUMENT_N163_WAVE DIALOGEX 0, 0, 372, 172
	CRect rect(CPoint(0,0),CSize(372,172));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());


   // STYLE DS_SETFONT|DS_FIXEDSYS|WS_CHILD|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Wave editor",IDC_STATIC,7,7,228,116
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(228,116));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Wave editor"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Loaded waves",IDC_STATIC,242,7,123,159
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(242,7),CSize(123,159));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Loaded waves"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // PUSHBUTTON "Sine",IDC_PRESET_SINE,14,104,41,14,WS_VISIBLE|WS_BORDER
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(14,104),CSize(41,14));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Sine"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_PRESET_SINE);
	mfcToQtWidget->insert(IDC_PRESET_SINE,mfc3);

   // PUSHBUTTON "Triangle",IDC_PRESET_TRIANGLE,57,104,41,14,WS_VISIBLE|WS_BORDER
	CButton* mfc4 = new CButton(parent);
	CRect r4(CPoint(57,104),CSize(41,14));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Triangle"),WS_VISIBLE|WS_BORDER,r4,parent,IDC_PRESET_TRIANGLE);
	mfcToQtWidget->insert(IDC_PRESET_TRIANGLE,mfc4);

   // PUSHBUTTON "Sawtooth",IDC_PRESET_SAWTOOTH,100,104,41,14,WS_VISIBLE|WS_BORDER
	CButton* mfc5 = new CButton(parent);
	CRect r5(CPoint(100,104),CSize(41,14));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Sawtooth"),WS_VISIBLE|WS_BORDER,r5,parent,IDC_PRESET_SAWTOOTH);
	mfcToQtWidget->insert(IDC_PRESET_SAWTOOTH,mfc5);

   // PUSHBUTTON "50% pulse",IDC_PRESET_PULSE_50,143,104,41,14,WS_VISIBLE|WS_BORDER
	CButton* mfc6 = new CButton(parent);
	CRect r6(CPoint(143,104),CSize(41,14));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("50% pulse"),WS_VISIBLE|WS_BORDER,r6,parent,IDC_PRESET_PULSE_50);
	mfcToQtWidget->insert(IDC_PRESET_PULSE_50,mfc6);

   // PUSHBUTTON "25% pulse",IDC_PRESET_PULSE_25,186,104,41,14,WS_VISIBLE|WS_BORDER
	CButton* mfc7 = new CButton(parent);
	CRect r7(CPoint(186,104),CSize(41,14));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("25% pulse"),WS_VISIBLE|WS_BORDER,r7,parent,IDC_PRESET_PULSE_25);
	mfcToQtWidget->insert(IDC_PRESET_PULSE_25,mfc7);

   // EDITTEXT IDC_MML,7,129,228,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc8 = new CEdit(parent);
	CRect r8(CPoint(7,129),CSize(228,14));
	parent->MapDialogRect(&r8);
	mfc8->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r8,parent,IDC_MML);
	mfcToQtWidget->insert(IDC_MML,mfc8);

   // LTEXT "Wave size:",IDC_STATIC,8,152,36,8
	CStatic* mfc9 = new CStatic(parent);
	CRect r9(CPoint(8,152),CSize(36,8));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("Wave size:"),WS_VISIBLE|WS_BORDER,r9,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_WAVE_SIZE,46,149,36,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc10 = new CComboBox(parent);
	CRect r10(CPoint(46,149),CSize(36,30));
	parent->MapDialogRect(&r10);
	mfc10->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r10,parent,IDC_WAVE_SIZE);
	mfcToQtWidget->insert(IDC_WAVE_SIZE,mfc10);

   // LTEXT "Wave position:",IDC_STATIC,94,152,49,8
	CStatic* mfc11 = new CStatic(parent);
	CRect r11(CPoint(94,152),CSize(49,8));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T("Wave position:"),WS_VISIBLE|WS_BORDER,r11,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_WAVE_POS,145,150,36,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWN|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc12 = new CComboBox(parent);
	CRect r12(CPoint(145,150),CSize(36,30));
	parent->MapDialogRect(&r12);
	mfc12->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWN|WS_VSCROLL|WS_TABSTOP,r12,parent,IDC_WAVE_POS);
	mfcToQtWidget->insert(IDC_WAVE_POS,mfc12);

   // CONTROL "", IDC_N163_WAVES, "SysListView32", WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|LVS_NOSORTHEADER|WS_BORDER|WS_TABSTOP, 250, 20, 107, 118
	CListCtrl* mfc14 = new CListCtrl(parent);
	CRect r14(CPoint(250, 20), CSize(107, 118));
	parent->MapDialogRect(&r14);
	mfc14->Create(WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|LVS_NOSORTHEADER|WS_BORDER|WS_TABSTOP, r14, parent, IDC_N163_WAVES);
	mfcToQtWidget->insert(IDC_N163_WAVES, mfc14);

   // PUSHBUTTON "Add",IDC_N163_ADD,248,144,27,14,WS_VISIBLE|WS_BORDER
	CButton* mfc15 = new CButton(parent);
	CRect r15(CPoint(248,144),CSize(27,14));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("Add"),WS_VISIBLE|WS_BORDER,r15,parent,IDC_N163_ADD);
	mfcToQtWidget->insert(IDC_N163_ADD,mfc15);

   // PUSHBUTTON "Delete",IDC_N163_DELETE,276,144,27,14,WS_VISIBLE|WS_BORDER
	CButton* mfc16 = new CButton(parent);
	CRect r16(CPoint(276,144),CSize(27,14));
	parent->MapDialogRect(&r16);
	mfc16->Create(_T("Delete"),WS_VISIBLE|WS_BORDER,r16,parent,IDC_N163_DELETE);
	mfcToQtWidget->insert(IDC_N163_DELETE,mfc16);

   // PUSHBUTTON "Copy",IDC_COPY,304,144,27,14,WS_VISIBLE|WS_BORDER
	CButton* mfc17 = new CButton(parent);
	CRect r17(CPoint(304,144),CSize(27,14));
	parent->MapDialogRect(&r17);
	mfc17->Create(_T("Copy"),WS_VISIBLE|WS_BORDER,r17,parent,IDC_COPY);
	mfcToQtWidget->insert(IDC_COPY,mfc17);

   // PUSHBUTTON "Paste",IDC_PASTE,332,144,27,14,WS_VISIBLE|WS_BORDER
	CButton* mfc18 = new CButton(parent);
	CRect r18(CPoint(332,144),CSize(27,14));
	parent->MapDialogRect(&r18);
	mfc18->Create(_T("Paste"),WS_VISIBLE|WS_BORDER,r18,parent,IDC_PASTE);
	mfcToQtWidget->insert(IDC_PASTE,mfc18);

   // END
}


void qtMfcInitDialogResource_IDD_IMPORT(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_IMPORT DIALOGEX 0, 0, 161, 231
	CRect rect(CPoint(0,0),CSize(161,231));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Import options"
	parent->SetWindowText("Import options");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Tracks",IDC_STATIC,7,7,147,137
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(147,137));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Tracks"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Options",IDC_STATIC,7,148,147,49
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7,148),CSize(147,49));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Options"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,51,210,50,14
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(51,210),CSize(50,14));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r2,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc2);

   // PUSHBUTTON "Cancel",IDCANCEL,104,210,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(104,210),CSize(50,14));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r3,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc3);

   // CONTROL "Include instruments", IDC_INSTRUMENTS, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 14, 160, 116, 10
	CButton* mfc5 = new CButton(parent);
	CRect r5(CPoint(14, 160), CSize(116, 10));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Include instruments"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r5, parent, IDC_INSTRUMENTS);
	mfcToQtWidget->insert(IDC_INSTRUMENTS, mfc5);

   // CONTROL "Overwrite detune table", IDC_IMPORT_DETUNE, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 14, 182, 116, 10
	CButton* mfc6 = new CButton(parent);
	CRect r6(CPoint(14, 182), CSize(116, 10));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Overwrite detune table"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r6, parent, IDC_IMPORT_DETUNE);
	mfcToQtWidget->insert(IDC_IMPORT_DETUNE, mfc6);

   // CONTROL "", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, 7, 203, 147, 1
	CStatic* mfc7 = new CStatic(parent);
	CRect r7(CPoint(7, 203), CSize(147, 1));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, r7, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc7);

   // LISTBOX IDC_TRACKS,14,18,133,120,WS_VISIBLE|WS_BORDER|LBS_OWNERDRAWFIXED|LBS_HASSTRINGS|LBS_NOINTEGRALHEIGHT|WS_VSCROLL|WS_TABSTOP
	CListBox* mfc9 = new CListBox(parent);
	CRect r9(CPoint(14,18),CSize(133,120));
	parent->MapDialogRect(&r9);
	mfc9->Create(WS_VISIBLE|WS_BORDER|LBS_OWNERDRAWFIXED|LBS_HASSTRINGS|LBS_NOINTEGRALHEIGHT|WS_VSCROLL|WS_TABSTOP,r9,parent,IDC_TRACKS);
	mfcToQtWidget->insert(IDC_TRACKS,mfc9);

   // CONTROL "Include grooves", IDC_IMPORT_GROOVE, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 14, 171, 116, 10
	CButton* mfc10 = new CButton(parent);
	CRect r10(CPoint(14, 171), CSize(116, 10));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("Include grooves"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r10, parent, IDC_IMPORT_GROOVE);
	mfcToQtWidget->insert(IDC_IMPORT_GROOVE, mfc10);

   // END
}


void qtMfcInitDialogResource_IDD_PERFORMANCE(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_PERFORMANCE DIALOGEX 0, 0, 177, 95
	CRect rect(CPoint(0,0),CSize(177,95));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Performance"
	parent->SetWindowText("Performance");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|DS_CENTER|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "CPU usage",IDC_STATIC,7,7,68,53
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(68,53));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("CPU usage"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Other",IDC_STATIC,81,7,88,26
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(81,7),CSize(88,26));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Other"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Audio",IDC_STATIC,81,34,88,26
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(81,34),CSize(88,26));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Audio"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // DEFPUSHBUTTON "Close",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,58,74,60,14
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(58,74),CSize(60,14));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Close"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r3,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc3);

   // CTEXT "--%",IDC_CPU,43,30,29,10
	CStatic* mfc5 = new CStatic(parent);
	CRect r5(CPoint(43,30),CSize(29,10));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("--%"),WS_VISIBLE|WS_BORDER,r5,parent,IDC_CPU);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_CPU_BAR, "msctls_progress32", WS_VISIBLE|WS_BORDER|PBS_SMOOTH|PBS_VERTICAL|WS_BORDER, 18, 19, 18, 34
	CProgressCtrl* mfc6 = new CProgressCtrl(parent);
	CRect r6(CPoint(18, 19), CSize(18, 34));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|PBS_SMOOTH|PBS_VERTICAL|WS_BORDER, r6, parent, IDC_CPU_BAR);
	mfcToQtWidget->insert(IDC_CPU_BAR, mfc6);

   // LTEXT "Frame rate: 0 Hz",IDC_FRAMERATE,89,18,72,8
	CStatic* mfc7 = new CStatic(parent);
	CRect r7(CPoint(89,18),CSize(72,8));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("Frame rate: 0 Hz"),WS_VISIBLE|WS_BORDER,r7,parent,IDC_FRAMERATE);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Underruns: 0",IDC_UNDERRUN,89,45,66,8
	CStatic* mfc8 = new CStatic(parent);
	CRect r8(CPoint(89,45),CSize(66,8));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Underruns: 0"),WS_VISIBLE|WS_BORDER,r8,parent,IDC_UNDERRUN);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, 7, 67, 162, 1
	CStatic* mfc9 = new CStatic(parent);
	CRect r9(CPoint(7, 67), CSize(162, 1));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, r9, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc9);

   // END
}


void qtMfcInitDialogResource_IDD_SPEED(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_SPEED DIALOGEX 0, 0, 196, 44
	CRect rect(CPoint(0,0),CSize(196,44));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Custom speed"
	parent->SetWindowText("Custom speed");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,139,7,50,14
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(139,7),CSize(50,14));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r0,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc0);

   // PUSHBUTTON "Cancel",IDCANCEL,139,23,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(139,23),CSize(50,14));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r1,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc1);

   // CONTROL "", IDC_SPEED_SLD, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|WS_TABSTOP, 7, 7, 101, 16
	CSliderCtrl* mfc2 = new CSliderCtrl(parent);
	CRect r2(CPoint(7, 7), CSize(101, 16));
	parent->MapDialogRect(&r2);
	mfc2->Create(WS_VISIBLE|WS_BORDER|WS_TABSTOP, r2, parent, IDC_SPEED_SLD);
	mfcToQtWidget->insert(IDC_SPEED_SLD, mfc2);

   // LTEXT "60 Hz",IDC_SPEED,112,11,26,12
	CStatic* mfc3 = new CStatic(parent);
	CRect r3(CPoint(112,11),CSize(26,12));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("60 Hz"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_SPEED);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // END
}


void qtMfcInitDialogResource_IDD_PROPERTIES(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_PROPERTIES DIALOGEX 0, 0, 213, 333
	CRect rect(CPoint(0,0),CSize(213,333));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Module properties"
	parent->SetWindowText("Module properties");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Expansion sound",IDC_STATIC,7,156,199,43
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,156),CSize(199,43));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Expansion sound"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Vibrato",IDC_STATIC,7,202,199,31
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7,202),CSize(199,31));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Vibrato"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Pitch mode",IDC_STATIC,7,235,199,31
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(7,235),CSize(199,31));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Pitch mode"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Song editor",IDC_STATIC,7,7,199,147
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(7,7),CSize(199,147));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Song editor"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r3,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "N163 level offset",IDC_STATIC,7,268,199,40
	CButton* mfc4 = new CButton(parent);
	CRect r4(CPoint(7,268),CSize(199,40));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("N163 level offset"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r4,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SONGLIST, "SysListView32", WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|LVS_NOCOLUMNHEADER|WS_BORDER|WS_TABSTOP, 14, 18, 120, 114
	CListCtrl* mfc5 = new CListCtrl(parent);
	CRect r5(CPoint(14, 18), CSize(120, 114));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SHOWSELALWAYS|LVS_ALIGNLEFT|LVS_NOCOLUMNHEADER|WS_BORDER|WS_TABSTOP, r5, parent, IDC_SONGLIST);
	mfcToQtWidget->insert(IDC_SONGLIST, mfc5);

   // PUSHBUTTON "Add",IDC_SONG_ADD,138,17,60,14,WS_VISIBLE|WS_BORDER
	CButton* mfc6 = new CButton(parent);
	CRect r6(CPoint(138,17),CSize(60,14));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Add"),WS_VISIBLE|WS_BORDER,r6,parent,IDC_SONG_ADD);
	mfcToQtWidget->insert(IDC_SONG_ADD,mfc6);

   // PUSHBUTTON "Insert",IDC_SONG_INSERT,138,33,60,14,WS_VISIBLE|WS_BORDER
	CButton* mfc7 = new CButton(parent);
	CRect r7(CPoint(138,33),CSize(60,14));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("Insert"),WS_VISIBLE|WS_BORDER,r7,parent,IDC_SONG_INSERT);
	mfcToQtWidget->insert(IDC_SONG_INSERT,mfc7);

   // PUSHBUTTON "Remove",IDC_SONG_REMOVE,138,49,60,14,WS_VISIBLE|WS_BORDER
	CButton* mfc8 = new CButton(parent);
	CRect r8(CPoint(138,49),CSize(60,14));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Remove"),WS_VISIBLE|WS_BORDER,r8,parent,IDC_SONG_REMOVE);
	mfcToQtWidget->insert(IDC_SONG_REMOVE,mfc8);

   // PUSHBUTTON "Move up",IDC_SONG_UP,138,65,60,14,WS_VISIBLE|WS_BORDER
	CButton* mfc9 = new CButton(parent);
	CRect r9(CPoint(138,65),CSize(60,14));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("Move up"),WS_VISIBLE|WS_BORDER,r9,parent,IDC_SONG_UP);
	mfcToQtWidget->insert(IDC_SONG_UP,mfc9);

   // PUSHBUTTON "Move down",IDC_SONG_DOWN,138,81,60,14,WS_VISIBLE|WS_BORDER
	CButton* mfc10 = new CButton(parent);
	CRect r10(CPoint(138,81),CSize(60,14));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("Move down"),WS_VISIBLE|WS_BORDER,r10,parent,IDC_SONG_DOWN);
	mfcToQtWidget->insert(IDC_SONG_DOWN,mfc10);

   // PUSHBUTTON "Import file",IDC_SONG_IMPORT,138,97,60,14,WS_VISIBLE|WS_BORDER
	CButton* mfc11 = new CButton(parent);
	CRect r11(CPoint(138,97),CSize(60,14));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T("Import file"),WS_VISIBLE|WS_BORDER,r11,parent,IDC_SONG_IMPORT);
	mfcToQtWidget->insert(IDC_SONG_IMPORT,mfc11);

   // LTEXT " Title",IDC_STATIC,14,135,17,12
	CStatic* mfc12 = new CStatic(parent);
	CRect r12(CPoint(14,135),CSize(17,12));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T(" Title"),WS_VISIBLE|WS_BORDER|SS_CENTERIMAGE,r12,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_SONGNAME,34,135,100,12,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc13 = new CEdit(parent);
	CRect r13(CPoint(34,135),CSize(100,12));
	parent->MapDialogRect(&r13);
	mfc13->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r13,parent,IDC_SONGNAME);
	mfcToQtWidget->insert(IDC_SONGNAME,mfc13);

   // CONTROL "VRC6", IDC_EXPANSION_VRC6, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 14, 168, 33, 10
	CButton* mfc15 = new CButton(parent);
	CRect r15(CPoint(14, 168), CSize(33, 10));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("VRC6"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r15, parent, IDC_EXPANSION_VRC6);
	mfcToQtWidget->insert(IDC_EXPANSION_VRC6, mfc15);

   // CONTROL "MMC5", IDC_EXPANSION_MMC5, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 59, 168, 35, 10
	CButton* mfc16 = new CButton(parent);
	CRect r16(CPoint(59, 168), CSize(35, 10));
	parent->MapDialogRect(&r16);
	mfc16->Create(_T("MMC5"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r16, parent, IDC_EXPANSION_MMC5);
	mfcToQtWidget->insert(IDC_EXPANSION_MMC5, mfc16);

   // CONTROL "N163", IDC_EXPANSION_N163, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 106, 168, 33, 10
	CButton* mfc17 = new CButton(parent);
	CRect r17(CPoint(106, 168), CSize(33, 10));
	parent->MapDialogRect(&r17);
	mfc17->Create(_T("N163"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r17, parent, IDC_EXPANSION_N163);
	mfcToQtWidget->insert(IDC_EXPANSION_N163, mfc17);

   // CONTROL "FDS", IDC_EXPANSION_FDS, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 14, 182, 29, 10
	CButton* mfc18 = new CButton(parent);
	CRect r18(CPoint(14, 182), CSize(29, 10));
	parent->MapDialogRect(&r18);
	mfc18->Create(_T("FDS"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r18, parent, IDC_EXPANSION_FDS);
	mfcToQtWidget->insert(IDC_EXPANSION_FDS, mfc18);

   // CONTROL "VRC7", IDC_EXPANSION_VRC7, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 59, 182, 33, 10
	CButton* mfc19 = new CButton(parent);
	CRect r19(CPoint(59, 182), CSize(33, 10));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("VRC7"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r19, parent, IDC_EXPANSION_VRC7);
	mfcToQtWidget->insert(IDC_EXPANSION_VRC7, mfc19);

   // CONTROL "S5B", IDC_EXPANSION_S5B, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 106, 182, 24, 10
	CButton* mfc20 = new CButton(parent);
	CRect r20(CPoint(106, 182), CSize(24, 10));
	parent->MapDialogRect(&r20);
	mfc20->Create(_T("S5B"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r20, parent, IDC_EXPANSION_S5B);
	mfcToQtWidget->insert(IDC_EXPANSION_S5B, mfc20);

   // LTEXT "Channels: 1",IDC_CHANNELS_NR,150,168,51,8
	CStatic* mfc21 = new CStatic(parent);
	CRect r21(CPoint(150,168),CSize(51,8));
	parent->MapDialogRect(&r21);
	mfc21->Create(_T("Channels: 1"),WS_VISIBLE|WS_BORDER|WS_DISABLED,r21,parent,IDC_CHANNELS_NR);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_CHANNELS, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_DISABLED|WS_TABSTOP, 145, 180, 51, 13
	CSliderCtrl* mfc22 = new CSliderCtrl(parent);
	CRect r22(CPoint(145, 180), CSize(51, 13));
	parent->MapDialogRect(&r22);
	mfc22->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_DISABLED|WS_TABSTOP, r22, parent, IDC_CHANNELS);
	mfcToQtWidget->insert(IDC_CHANNELS, mfc22);

   // COMBOBOX IDC_VIBRATO,14,213,184,61,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc24 = new CComboBox(parent);
	CRect r24(CPoint(14,213),CSize(184,61));
	parent->MapDialogRect(&r24);
	mfc24->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r24,parent,IDC_VIBRATO);
	mfcToQtWidget->insert(IDC_VIBRATO,mfc24);


	mfc24->AddString(_T("New style (bend up & down)"));
	

	mfc24->AddString(_T("Old style (bend up)"));
	
   // COMBOBOX IDC_COMBO_LINEARPITCH,14,246,184,61,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc26 = new CComboBox(parent);
	CRect r26(CPoint(14,246),CSize(184,61));
	parent->MapDialogRect(&r26);
	mfc26->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r26,parent,IDC_COMBO_LINEARPITCH);
	mfcToQtWidget->insert(IDC_COMBO_LINEARPITCH,mfc26);


	mfc26->AddString(_T("Linear period / frequency (register pitch bends)"));
	

	mfc26->AddString(_T("Linear pitch (uniform pitch bends)"));
	
   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,95,312,53,14
	CButton* mfc27 = new CButton(parent);
	CRect r27(CPoint(95,312),CSize(53,14));
	parent->MapDialogRect(&r27);
	mfc27->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r27,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc27);

   // PUSHBUTTON "Cancel",IDCANCEL,153,312,53,14,WS_VISIBLE|WS_BORDER
	CButton* mfc28 = new CButton(parent);
	CRect r28(CPoint(153,312),CSize(53,14));
	parent->MapDialogRect(&r28);
	mfc28->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r28,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc28);

   // CONTROL "", IDC_N163_OFFSET_SLIDER, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_BOTH|WS_DISABLED|WS_TABSTOP, 9, 278, 146, 24
	CSliderCtrl* mfc31 = new CSliderCtrl(parent);
	CRect r31(CPoint(9, 278), CSize(146, 24));
	parent->MapDialogRect(&r31);
	mfc31->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_BOTH|WS_DISABLED|WS_TABSTOP, r31, parent, IDC_N163_OFFSET_SLIDER);
	mfcToQtWidget->insert(IDC_N163_OFFSET_SLIDER, mfc31);

   // EDITTEXT IDC_N163_OFFSET_EDIT,156,285,31,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|WS_DISABLED
	CEdit* mfc32 = new CEdit(parent);
	CRect r32(CPoint(156,285),CSize(31,14));
	parent->MapDialogRect(&r32);
	mfc32->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|WS_DISABLED,r32,parent,IDC_N163_OFFSET_EDIT);
	mfcToQtWidget->insert(IDC_N163_OFFSET_EDIT,mfc32);

   // RTEXT "dB",IDC_N163_OFFSET_DB,190,287,8,8
	CStatic* mfc33 = new CStatic(parent);
	CRect r33(CPoint(190,287),CSize(8,8));
	parent->MapDialogRect(&r33);
	mfc33->Create(_T("dB"),WS_VISIBLE|WS_BORDER|WS_DISABLED,r33,parent,IDC_N163_OFFSET_DB);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // END
}


void qtMfcInitDialogResource_IDD_WAVE_PROGRESS(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_WAVE_PROGRESS DIALOGEX 0, 0, 220, 111
	CRect rect(CPoint(0,0),CSize(220,111));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Creating WAV..."
	parent->SetWindowText("Creating WAV...");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|DS_CENTER|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // PUSHBUTTON "Cancel",IDC_CANCEL,84,90,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(84,90),CSize(50,14));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r0,parent,IDC_CANCEL);
	mfcToQtWidget->insert(IDC_CANCEL,mfc0);

   // CONTROL "", IDC_PROGRESS_BAR, "msctls_progress32", WS_VISIBLE|WS_BORDER|WS_BORDER, 7, 65, 206, 12
	CProgressCtrl* mfc1 = new CProgressCtrl(parent);
	CRect r1(CPoint(7, 65), CSize(206, 12));
	parent->MapDialogRect(&r1);
	mfc1->Create(WS_VISIBLE|WS_BORDER|WS_BORDER, r1, parent, IDC_PROGRESS_BAR);
	mfcToQtWidget->insert(IDC_PROGRESS_BAR, mfc1);

   // CTEXT "Progress",IDC_PROGRESS_LBL,7,37,206,11
	CStatic* mfc2 = new CStatic(parent);
	CRect r2(CPoint(7,37),CSize(206,11));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Progress"),WS_VISIBLE|WS_BORDER,r2,parent,IDC_PROGRESS_LBL);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_ETCHEDFRAME, 7, 83, 206, 1
	CStatic* mfc3 = new CStatic(parent);
	CRect r3(CPoint(7, 83), CSize(206, 1));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_ETCHEDFRAME, r3, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc3);

   // CTEXT "File",IDC_PROGRESS_FILE,7,7,206,20
	CStatic* mfc4 = new CStatic(parent);
	CRect r4(CPoint(7,7),CSize(206,20));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("File"),WS_VISIBLE|WS_BORDER|SS_CENTERIMAGE,r4,parent,IDC_PROGRESS_FILE);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_ETCHEDFRAME, 7, 29, 206, 1
	CStatic* mfc5 = new CStatic(parent);
	CRect r5(CPoint(7, 29), CSize(206, 1));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_ETCHEDFRAME, r5, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc5);

   // CTEXT "Progress",IDC_TIME,7,49,206,11
	CStatic* mfc6 = new CStatic(parent);
	CRect r6(CPoint(7,49),CSize(206,11));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Progress"),WS_VISIBLE|WS_BORDER,r6,parent,IDC_TIME);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // END
}


void qtMfcInitDialogResource_IDD_SAMPLE_EDITOR(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_SAMPLE_EDITOR DIALOGEX 0, 0, 481, 261
	CRect rect(CPoint(0,0),CSize(481,261));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "DPCM sample editor"
	parent->SetWindowText("DPCM sample editor");

   // STYLE DS_SETFONT|DS_FIXEDSYS|WS_MAXIMIZEBOX|WS_POPUP|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::WindowMaximizeButtonHint|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,424,213,50,14
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(424,213),CSize(50,14));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r0,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc0);

   // PUSHBUTTON "Cancel",IDCANCEL,424,230,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(424,230),CSize(50,14));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r1,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc1);

   // CONTROL "", IDC_SAMPLE, "Static", WS_VISIBLE|WS_BORDER|SS_WHITERECT|SS_NOTIFY|SS_SUNKEN, 2, 2, 476, 204
	CStatic* mfc2 = new CStatic(parent);
	CRect r2(CPoint(2, 2), CSize(476, 204));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_WHITERECT|SS_NOTIFY|SS_SUNKEN, r2, parent, IDC_SAMPLE);
	mfcToQtWidget->insert(IDC_SAMPLE, mfc2);

   // PUSHBUTTON "Play",IDC_PLAY,7,212,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(7,212),CSize(50,14));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Play"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_PLAY);
	mfcToQtWidget->insert(IDC_PLAY,mfc3);

   // PUSHBUTTON "Delete",IDC_DELETE,64,212,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc4 = new CButton(parent);
	CRect r4(CPoint(64,212),CSize(50,14));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Delete"),WS_VISIBLE|WS_BORDER,r4,parent,IDC_DELETE);
	mfcToQtWidget->insert(IDC_DELETE,mfc4);

   // CONTROL "", IDC_PITCH, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 45, 232, 130, 12
	CSliderCtrl* mfc5 = new CSliderCtrl(parent);
	CRect r5(CPoint(45, 232), CSize(130, 12));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r5, parent, IDC_PITCH);
	mfcToQtWidget->insert(IDC_PITCH, mfc5);

   // PUSHBUTTON "Tilt",IDC_TILT,121,212,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc6 = new CButton(parent);
	CRect r6(CPoint(121,212),CSize(50,14));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Tilt"),WS_VISIBLE|WS_BORDER,r6,parent,IDC_TILT);
	mfcToQtWidget->insert(IDC_TILT,mfc6);

   // LTEXT "Pitch (15)",IDC_STATIC_PITCH,8,233,34,11
	CStatic* mfc7 = new CStatic(parent);
	CRect r7(CPoint(8,233),CSize(34,11));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("Pitch (15)"),WS_VISIBLE|WS_BORDER,r7,parent,IDC_STATIC_PITCH);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "Center wave", IDC_DELTASTART, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 179, 232, 57, 10
	CButton* mfc8 = new CButton(parent);
	CRect r8(CPoint(179, 232), CSize(57, 10));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Center wave"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r8, parent, IDC_DELTASTART);
	mfcToQtWidget->insert(IDC_DELTASTART, mfc8);

   // CONTROL "", IDC_ZOOM, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 240, 213, 181, 12
	CSliderCtrl* mfc9 = new CSliderCtrl(parent);
	CRect r9(CPoint(240, 213), CSize(181, 12));
	parent->MapDialogRect(&r9);
	mfc9->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r9, parent, IDC_ZOOM);
	mfcToQtWidget->insert(IDC_ZOOM, mfc9);

   // LTEXT "Zoom (1.00x)",IDC_STATIC_DPCM_ZOOM,185,214,54,8
	CStatic* mfc10 = new CStatic(parent);
	CRect r10(CPoint(185,214),CSize(54,8));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("Zoom (1.00x)"),WS_VISIBLE|WS_BORDER,r10,parent,IDC_STATIC_DPCM_ZOOM);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // END
}


void qtMfcInitDialogResource_IDD_DETUNE(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_DETUNE DIALOGEX 0, 0, 293, 272
	CRect rect(CPoint(0,0),CSize(293,272));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Detune Settings"
	parent->SetWindowText("Detune Settings");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Detune editor",IDC_STATIC,7,7,220,103
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(220,103));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Detune editor"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Global tuning",IDC_STATIC,7,114,220,73
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7,114),CSize(220,73));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Global tuning"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Info panel",IDC_STATIC,7,191,220,74
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(7,191),CSize(220,74));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Info panel"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // RTEXT "Octave:",IDC_STATIC,16,21,27,8
	CStatic* mfc4 = new CStatic(parent);
	CRect r4(CPoint(16,21),CSize(27,8));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Octave:"),WS_VISIBLE|WS_BORDER,r4,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SLIDER_OCTAVE, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 44, 19, 132, 15
	CSliderCtrl* mfc5 = new CSliderCtrl(parent);
	CRect r5(CPoint(44, 19), CSize(132, 15));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r5, parent, IDC_SLIDER_OCTAVE);
	mfcToQtWidget->insert(IDC_SLIDER_OCTAVE, mfc5);

   // EDITTEXT IDC_EDIT_OCTAVE,180,18,38,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc6 = new CEdit(parent);
	CRect r6(CPoint(180,18),CSize(38,14));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r6,parent,IDC_EDIT_OCTAVE);
	mfcToQtWidget->insert(IDC_EDIT_OCTAVE,mfc6);

   // CONTROL "", IDC_SPIN_OCTAVE, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 207, 18, 11, 14
	CSpinButtonCtrl* mfc7 = new CSpinButtonCtrl(parent);
	CRect r7(CPoint(207, 18), CSize(11, 14));
	parent->MapDialogRect(&r7);
	mfc7->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r7, parent, IDC_SPIN_OCTAVE);
	mfcToQtWidget->insert(IDC_SPIN_OCTAVE, mfc7);

   // RTEXT "Note:",IDC_STATIC,24,41,19,8
	CStatic* mfc8 = new CStatic(parent);
	CRect r8(CPoint(24,41),CSize(19,8));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Note:"),WS_VISIBLE|WS_BORDER,r8,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SLIDER_NOTE, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 43, 39, 132, 15
	CSliderCtrl* mfc9 = new CSliderCtrl(parent);
	CRect r9(CPoint(43, 39), CSize(132, 15));
	parent->MapDialogRect(&r9);
	mfc9->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r9, parent, IDC_SLIDER_NOTE);
	mfcToQtWidget->insert(IDC_SLIDER_NOTE, mfc9);

   // EDITTEXT IDC_EDIT_NOTE,180,37,38,14,WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL
	CEdit* mfc10 = new CEdit(parent);
	CRect r10(CPoint(180,37),CSize(38,14));
	parent->MapDialogRect(&r10);
	mfc10->Create(WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL,r10,parent,IDC_EDIT_NOTE);
	mfcToQtWidget->insert(IDC_EDIT_NOTE,mfc10);

   // CONTROL "", IDC_SPIN_NOTE, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 207, 37, 11, 14
	CSpinButtonCtrl* mfc11 = new CSpinButtonCtrl(parent);
	CRect r11(CPoint(207, 37), CSize(11, 14));
	parent->MapDialogRect(&r11);
	mfc11->Create(WS_VISIBLE|WS_BORDER|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r11, parent, IDC_SPIN_NOTE);
	mfcToQtWidget->insert(IDC_SPIN_NOTE, mfc11);

   // RTEXT "Offset:",IDC_STATIC,19,61,24,8
	CStatic* mfc12 = new CStatic(parent);
	CRect r12(CPoint(19,61),CSize(24,8));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T("Offset:"),WS_VISIBLE|WS_BORDER,r12,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SLIDER_OFFSET, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 43, 59, 132, 15
	CSliderCtrl* mfc13 = new CSliderCtrl(parent);
	CRect r13(CPoint(43, 59), CSize(132, 15));
	parent->MapDialogRect(&r13);
	mfc13->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r13, parent, IDC_SLIDER_OFFSET);
	mfcToQtWidget->insert(IDC_SLIDER_OFFSET, mfc13);

   // EDITTEXT IDC_EDIT_OFFSET,180,57,38,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc14 = new CEdit(parent);
	CRect r14(CPoint(180,57),CSize(38,14));
	parent->MapDialogRect(&r14);
	mfc14->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r14,parent,IDC_EDIT_OFFSET);
	mfcToQtWidget->insert(IDC_EDIT_OFFSET,mfc14);

   // CONTROL "", IDC_SPIN_OFFSET, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 207, 57, 11, 14
	CSpinButtonCtrl* mfc15 = new CSpinButtonCtrl(parent);
	CRect r15(CPoint(207, 57), CSize(11, 14));
	parent->MapDialogRect(&r15);
	mfc15->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r15, parent, IDC_SPIN_OFFSET);
	mfcToQtWidget->insert(IDC_SPIN_OFFSET, mfc15);

   // RTEXT "Table:",IDC_STATIC,21,80,21,8
	CStatic* mfc16 = new CStatic(parent);
	CRect r16(CPoint(21,80),CSize(21,8));
	parent->MapDialogRect(&r16);
	mfc16->Create(_T("Table:"),WS_VISIBLE|WS_BORDER,r16,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "2A03/Default", IDC_RADIO_NTSC, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON|WS_GROUP, 46, 80, 59, 10
	CButton* mfc17 = new CButton(parent);
	CRect r17(CPoint(46, 80), CSize(59, 10));
	parent->MapDialogRect(&r17);
	mfc17->Create(_T("2A03/Default"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON|WS_GROUP, r17, parent, IDC_RADIO_NTSC);
	mfcToQtWidget->insert(IDC_RADIO_NTSC, mfc17);

   // CONTROL "2A07", IDC_RADIO_PAL, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, 108, 80, 33, 10
	CButton* mfc18 = new CButton(parent);
	CRect r18(CPoint(108, 80), CSize(33, 10));
	parent->MapDialogRect(&r18);
	mfc18->Create(_T("2A07"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, r18, parent, IDC_RADIO_PAL);
	mfcToQtWidget->insert(IDC_RADIO_PAL, mfc18);

   // CONTROL "VRC6 Sawtooth", IDC_RADIO_VRC6, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, 145, 80, 66, 10
	CButton* mfc19 = new CButton(parent);
	CRect r19(CPoint(145, 80), CSize(66, 10));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("VRC6 Sawtooth"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, r19, parent, IDC_RADIO_VRC6);
	mfcToQtWidget->insert(IDC_RADIO_VRC6, mfc19);

   // CONTROL "VRC7", IDC_RADIO_VRC7, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, 46, 93, 33, 10
	CButton* mfc20 = new CButton(parent);
	CRect r20(CPoint(46, 93), CSize(33, 10));
	parent->MapDialogRect(&r20);
	mfc20->Create(_T("VRC7"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, r20, parent, IDC_RADIO_VRC7);
	mfcToQtWidget->insert(IDC_RADIO_VRC7, mfc20);

   // CONTROL "FDS", IDC_RADIO_FDS, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, 108, 93, 33, 10
	CButton* mfc21 = new CButton(parent);
	CRect r21(CPoint(108, 93), CSize(33, 10));
	parent->MapDialogRect(&r21);
	mfc21->Create(_T("FDS"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, r21, parent, IDC_RADIO_FDS);
	mfcToQtWidget->insert(IDC_RADIO_FDS, mfc21);

   // CONTROL "N163", IDC_RADIO_N163, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, 145, 93, 33, 10
	CButton* mfc22 = new CButton(parent);
	CRect r22(CPoint(145, 93), CSize(33, 10));
	parent->MapDialogRect(&r22);
	mfc22->Create(_T("N163"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, r22, parent, IDC_RADIO_N163);
	mfcToQtWidget->insert(IDC_RADIO_N163, mfc22);

   // CONTROL "Enable", IDC_CHECK_ENABLE, "Button", WS_BORDER|BS_AUTOCHECKBOX|WS_DISABLED|WS_TABSTOP, 181, 93, 34, 10
	CButton* mfc23 = new CButton(parent);
	CRect r23(CPoint(181, 93), CSize(34, 10));
	parent->MapDialogRect(&r23);
	mfc23->Create(_T("Enable"), WS_BORDER|BS_AUTOCHECKBOX|WS_DISABLED|WS_TABSTOP, r23, parent, IDC_CHECK_ENABLE);
	mfcToQtWidget->insert(IDC_CHECK_ENABLE, mfc23);

   // LTEXT "Semitone: +0",IDC_STATIC_DETUNE_SEMITONE,15,129,52,8
	CStatic* mfc25 = new CStatic(parent);
	CRect r25(CPoint(15,129),CSize(52,8));
	parent->MapDialogRect(&r25);
	mfc25->Create(_T("Semitone: +0"),WS_VISIBLE|WS_BORDER,r25,parent,IDC_STATIC_DETUNE_SEMITONE);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SLIDER_DETUNE_SEMITONE, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 72, 126, 150, 15
	CSliderCtrl* mfc26 = new CSliderCtrl(parent);
	CRect r26(CPoint(72, 126), CSize(150, 15));
	parent->MapDialogRect(&r26);
	mfc26->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r26, parent, IDC_SLIDER_DETUNE_SEMITONE);
	mfcToQtWidget->insert(IDC_SLIDER_DETUNE_SEMITONE, mfc26);

   // LTEXT "Cent: +0",IDC_STATIC_DETUNE_CENT,15,147,52,8
	CStatic* mfc27 = new CStatic(parent);
	CRect r27(CPoint(15,147),CSize(52,8));
	parent->MapDialogRect(&r27);
	mfc27->Create(_T("Cent: +0"),WS_VISIBLE|WS_BORDER,r27,parent,IDC_STATIC_DETUNE_CENT);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "", IDC_SLIDER_DETUNE_CENT, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, 72, 144, 150, 15
	CSliderCtrl* mfc28 = new CSliderCtrl(parent);
	CRect r28(CPoint(72, 144), CSize(150, 15));
	parent->MapDialogRect(&r28);
	mfc28->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|WS_TABSTOP, r28, parent, IDC_SLIDER_DETUNE_CENT);
	mfcToQtWidget->insert(IDC_SLIDER_DETUNE_CENT, mfc28);

   // LTEXT "Modules saved in this build of j0CC-FamiTracker will erase the tuning information for official 0.5.0 beta.",IDC_STATIC,15,163,201,18
	CStatic* mfc29 = new CStatic(parent);
	CRect r29(CPoint(15,163),CSize(201,18));
	parent->MapDialogRect(&r29);
	mfc29->Create(_T("Modules saved in this build of j0CC-FamiTracker will erase the tuning information for official 0.5.0 beta."),WS_VISIBLE|WS_BORDER,r29,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // PUSHBUTTON "Reset",IDC_BUTTON_RESET,236,10,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc30 = new CButton(parent);
	CRect r30(CPoint(236,10),CSize(50,14));
	parent->MapDialogRect(&r30);
	mfc30->Create(_T("Reset"),WS_VISIBLE|WS_BORDER,r30,parent,IDC_BUTTON_RESET);
	mfcToQtWidget->insert(IDC_BUTTON_RESET,mfc30);

   // PUSHBUTTON "Import",IDC_BUTTON_IMPORT,236,27,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc31 = new CButton(parent);
	CRect r31(CPoint(236,27),CSize(50,14));
	parent->MapDialogRect(&r31);
	mfc31->Create(_T("Import"),WS_VISIBLE|WS_BORDER,r31,parent,IDC_BUTTON_IMPORT);
	mfcToQtWidget->insert(IDC_BUTTON_IMPORT,mfc31);

   // PUSHBUTTON "Export",IDC_BUTTON_EXPORT,236,44,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc32 = new CButton(parent);
	CRect r32(CPoint(236,44),CSize(50,14));
	parent->MapDialogRect(&r32);
	mfc32->Create(_T("Export"),WS_VISIBLE|WS_BORDER,r32,parent,IDC_BUTTON_EXPORT);
	mfcToQtWidget->insert(IDC_BUTTON_EXPORT,mfc32);

   // PUSHBUTTON "OK",IDOK,235,233,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc33 = new CButton(parent);
	CRect r33(CPoint(235,233),CSize(50,14));
	parent->MapDialogRect(&r33);
	mfc33->Create(_T("OK"),WS_VISIBLE|WS_BORDER,r33,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc33);

   // PUSHBUTTON "Cancel",IDCANCEL,235,251,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc34 = new CButton(parent);
	CRect r34(CPoint(235,251),CSize(50,14));
	parent->MapDialogRect(&r34);
	mfc34->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r34,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc34);

   // RTEXT "\nOld register\nNew register\nOld frequency\nNew frequency\nBase frequency\nCent detune",IDC_STATIC,13,202,50,55
	CStatic* mfc36 = new CStatic(parent);
	CRect r36(CPoint(13,202),CSize(50,55));
	parent->MapDialogRect(&r36);
	mfc36->Create(_T("\nOld register\nNew register\nOld frequency\nNew frequency\nBase frequency\nCent detune"),WS_VISIBLE|WS_BORDER,r36,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "NTSC\n0\n0\n0\n0\n0\n0",IDC_DETUNE_INFO_NTSC,66,202,26,55
	CStatic* mfc37 = new CStatic(parent);
	CRect r37(CPoint(66,202),CSize(26,55));
	parent->MapDialogRect(&r37);
	mfc37->Create(_T("NTSC\n0\n0\n0\n0\n0\n0"),WS_VISIBLE|WS_BORDER,r37,parent,IDC_DETUNE_INFO_NTSC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "PAL\n0\n0\n0\n0\n0\n0",IDC_DETUNE_INFO_PAL,94,202,24,55
	CStatic* mfc38 = new CStatic(parent);
	CRect r38(CPoint(94,202),CSize(24,55));
	parent->MapDialogRect(&r38);
	mfc38->Create(_T("PAL\n0\n0\n0\n0\n0\n0"),WS_VISIBLE|WS_BORDER,r38,parent,IDC_DETUNE_INFO_PAL);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "Saw\n0\n0\n0\n0\n0\n0",IDC_DETUNE_INFO_SAW,120,202,24,55
	CStatic* mfc39 = new CStatic(parent);
	CRect r39(CPoint(120,202),CSize(24,55));
	parent->MapDialogRect(&r39);
	mfc39->Create(_T("Saw\n0\n0\n0\n0\n0\n0"),WS_VISIBLE|WS_BORDER,r39,parent,IDC_DETUNE_INFO_SAW);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "VRC7\n0\n0\n0\n0\n0\n0",IDC_DETUNE_INFO_VRC7,146,202,24,55
	CStatic* mfc40 = new CStatic(parent);
	CRect r40(CPoint(146,202),CSize(24,55));
	parent->MapDialogRect(&r40);
	mfc40->Create(_T("VRC7\n0\n0\n0\n0\n0\n0"),WS_VISIBLE|WS_BORDER,r40,parent,IDC_DETUNE_INFO_VRC7);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "FDS\n0\n0\n0\n0\n0\n0",IDC_DETUNE_INFO_FDS,172,202,24,55
	CStatic* mfc41 = new CStatic(parent);
	CRect r41(CPoint(172,202),CSize(24,55));
	parent->MapDialogRect(&r41);
	mfc41->Create(_T("FDS\n0\n0\n0\n0\n0\n0"),WS_VISIBLE|WS_BORDER,r41,parent,IDC_DETUNE_INFO_FDS);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CTEXT "N163\n0\n0\n0\n0\n0\n0",IDC_DETUNE_INFO_N163,198,202,24,55
	CStatic* mfc42 = new CStatic(parent);
	CRect r42(CPoint(198,202),CSize(24,55));
	parent->MapDialogRect(&r42);
	mfc42->Create(_T("N163\n0\n0\n0\n0\n0\n0"),WS_VISIBLE|WS_BORDER,r42,parent,IDC_DETUNE_INFO_N163);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // END
}


void qtMfcInitDialogResource_IDD_GROOVE(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_GROOVE DIALOGEX 0, 0, 289, 160
	CRect rect(CPoint(0,0),CSize(289,160));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Groove Settings"
	parent->SetWindowText("Groove Settings");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Groove list",IDC_STATIC,7,7,101,119
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(101,119));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Groove list"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Groove editor",IDC_STATIC,116,7,166,119
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(116,7),CSize(166,119));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Groove editor"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LISTBOX IDC_LIST_GROOVE_TABLE,15,18,44,100,WS_VISIBLE|WS_BORDER|LBS_SORT|LBS_NOINTEGRALHEIGHT|WS_VSCROLL|WS_TABSTOP
	CListBox* mfc3 = new CListBox(parent);
	CRect r3(CPoint(15,18),CSize(44,100));
	parent->MapDialogRect(&r3);
	mfc3->Create(WS_VISIBLE|WS_BORDER|LBS_SORT|LBS_NOINTEGRALHEIGHT|WS_VSCROLL|WS_TABSTOP,r3,parent,IDC_LIST_GROOVE_TABLE);
	mfcToQtWidget->insert(IDC_LIST_GROOVE_TABLE,mfc3);

   // PUSHBUTTON "Up",IDC_BUTTON_GROOVEL_UP,66,18,35,14,WS_VISIBLE|WS_BORDER
	CButton* mfc4 = new CButton(parent);
	CRect r4(CPoint(66,18),CSize(35,14));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Up"),WS_VISIBLE|WS_BORDER,r4,parent,IDC_BUTTON_GROOVEL_UP);
	mfcToQtWidget->insert(IDC_BUTTON_GROOVEL_UP,mfc4);

   // PUSHBUTTON "Down",IDC_BUTTON_GROOVEL_DOWN,66,36,35,14,WS_VISIBLE|WS_BORDER
	CButton* mfc5 = new CButton(parent);
	CRect r5(CPoint(66,36),CSize(35,14));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Down"),WS_VISIBLE|WS_BORDER,r5,parent,IDC_BUTTON_GROOVEL_DOWN);
	mfcToQtWidget->insert(IDC_BUTTON_GROOVEL_DOWN,mfc5);

   // PUSHBUTTON "Clear",IDC_BUTTON_GROOVEL_CLEAR,66,54,35,14,WS_VISIBLE|WS_BORDER
	CButton* mfc6 = new CButton(parent);
	CRect r6(CPoint(66,54),CSize(35,14));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Clear"),WS_VISIBLE|WS_BORDER,r6,parent,IDC_BUTTON_GROOVEL_CLEAR);
	mfcToQtWidget->insert(IDC_BUTTON_GROOVEL_CLEAR,mfc6);

   // PUSHBUTTON "Clear all",IDC_BUTTON_GROOVEL_CLEARALL,66,72,35,14,WS_VISIBLE|WS_BORDER
	CButton* mfc7 = new CButton(parent);
	CRect r7(CPoint(66,72),CSize(35,14));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("Clear all"),WS_VISIBLE|WS_BORDER,r7,parent,IDC_BUTTON_GROOVEL_CLEARALL);
	mfcToQtWidget->insert(IDC_BUTTON_GROOVEL_CLEARALL,mfc7);

   // LTEXT "Total size:\n1 / 256 bytes",IDC_STATIC_GROOVE_TOTAL,65,94,37,24
	CStatic* mfc8 = new CStatic(parent);
	CRect r8(CPoint(65,94),CSize(37,24));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Total size:\n1 / 256 bytes"),WS_VISIBLE|WS_BORDER,r8,parent,IDC_STATIC_GROOVE_TOTAL);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LISTBOX IDC_LIST_GROOVE_EDITOR,124,18,44,82,WS_VISIBLE|WS_BORDER|LBS_SORT|LBS_NOINTEGRALHEIGHT|WS_VSCROLL|WS_TABSTOP
	CListBox* mfc10 = new CListBox(parent);
	CRect r10(CPoint(124,18),CSize(44,82));
	parent->MapDialogRect(&r10);
	mfc10->Create(WS_VISIBLE|WS_BORDER|LBS_SORT|LBS_NOINTEGRALHEIGHT|WS_VSCROLL|WS_TABSTOP,r10,parent,IDC_LIST_GROOVE_EDITOR);
	mfcToQtWidget->insert(IDC_LIST_GROOVE_EDITOR,mfc10);

   // PUSHBUTTON "Move up",IDC_BUTTON_GROOVE_UP,175,18,46,14,WS_VISIBLE|WS_BORDER
	CButton* mfc11 = new CButton(parent);
	CRect r11(CPoint(175,18),CSize(46,14));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T("Move up"),WS_VISIBLE|WS_BORDER,r11,parent,IDC_BUTTON_GROOVE_UP);
	mfcToQtWidget->insert(IDC_BUTTON_GROOVE_UP,mfc11);

   // PUSHBUTTON "Move down",IDC_BUTTON_GROOVE_DOWN,175,36,46,14,WS_VISIBLE|WS_BORDER
	CButton* mfc12 = new CButton(parent);
	CRect r12(CPoint(175,36),CSize(46,14));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T("Move down"),WS_VISIBLE|WS_BORDER,r12,parent,IDC_BUTTON_GROOVE_DOWN);
	mfcToQtWidget->insert(IDC_BUTTON_GROOVE_DOWN,mfc12);

   // PUSHBUTTON "Expand",IDC_BUTTON_GROOVE_EXPAND,227,18,46,14,WS_VISIBLE|WS_BORDER
	CButton* mfc13 = new CButton(parent);
	CRect r13(CPoint(227,18),CSize(46,14));
	parent->MapDialogRect(&r13);
	mfc13->Create(_T("Expand"),WS_VISIBLE|WS_BORDER,r13,parent,IDC_BUTTON_GROOVE_EXPAND);
	mfcToQtWidget->insert(IDC_BUTTON_GROOVE_EXPAND,mfc13);

   // PUSHBUTTON "Shrink",IDC_BUTTON_GROOVE_SHRINK,227,36,46,14,WS_VISIBLE|WS_BORDER
	CButton* mfc14 = new CButton(parent);
	CRect r14(CPoint(227,36),CSize(46,14));
	parent->MapDialogRect(&r14);
	mfc14->Create(_T("Shrink"),WS_VISIBLE|WS_BORDER,r14,parent,IDC_BUTTON_GROOVE_SHRINK);
	mfcToQtWidget->insert(IDC_BUTTON_GROOVE_SHRINK,mfc14);

   // PUSHBUTTON "Generate",IDC_BUTTON_GROOVE_GENERATE,175,54,46,14,WS_VISIBLE|WS_BORDER
	CButton* mfc15 = new CButton(parent);
	CRect r15(CPoint(175,54),CSize(46,14));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("Generate"),WS_VISIBLE|WS_BORDER,r15,parent,IDC_BUTTON_GROOVE_GENERATE);
	mfcToQtWidget->insert(IDC_BUTTON_GROOVE_GENERATE,mfc15);

   // EDITTEXT IDC_EDIT_GROOVE_NUM,228,54,17,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc16 = new CEdit(parent);
	CRect r16(CPoint(228,54),CSize(17,14));
	parent->MapDialogRect(&r16);
	mfc16->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r16,parent,IDC_EDIT_GROOVE_NUM);
	mfcToQtWidget->insert(IDC_EDIT_GROOVE_NUM,mfc16);

   // LTEXT " /",IDC_STATIC,247,56,8,8
	CStatic* mfc17 = new CStatic(parent);
	CRect r17(CPoint(247,56),CSize(8,8));
	parent->MapDialogRect(&r17);
	mfc17->Create(_T(" /"),WS_VISIBLE|WS_BORDER,r17,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_EDIT_GROOVE_DENOM,255,54,17,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc18 = new CEdit(parent);
	CRect r18(CPoint(255,54),CSize(17,14));
	parent->MapDialogRect(&r18);
	mfc18->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r18,parent,IDC_EDIT_GROOVE_DENOM);
	mfcToQtWidget->insert(IDC_EDIT_GROOVE_DENOM,mfc18);

   // PUSHBUTTON "Pad",IDC_BUTTON_GROOVE_PAD,175,72,46,14,WS_VISIBLE|WS_BORDER
	CButton* mfc19 = new CButton(parent);
	CRect r19(CPoint(175,72),CSize(46,14));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("Pad"),WS_VISIBLE|WS_BORDER,r19,parent,IDC_BUTTON_GROOVE_PAD);
	mfcToQtWidget->insert(IDC_BUTTON_GROOVE_PAD,mfc19);

   // EDITTEXT IDC_EDIT_GROOVE_PAD,228,72,45,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc20 = new CEdit(parent);
	CRect r20(CPoint(228,72),CSize(45,14));
	parent->MapDialogRect(&r20);
	mfc20->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r20,parent,IDC_EDIT_GROOVE_PAD);
	mfcToQtWidget->insert(IDC_EDIT_GROOVE_PAD,mfc20);

   // CONTROL "", IDC_SPIN_PAD, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 264, 72, 10, 14
	CSpinButtonCtrl* mfc21 = new CSpinButtonCtrl(parent);
	CRect r21(CPoint(264, 72), CSize(10, 14));
	parent->MapDialogRect(&r21);
	mfc21->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r21, parent, IDC_SPIN_PAD);
	mfcToQtWidget->insert(IDC_SPIN_PAD, mfc21);

   // LTEXT "Speed: 6.000",IDC_STATIC_GROOVE_AVERAGE,176,91,46,8
	CStatic* mfc22 = new CStatic(parent);
	CRect r22(CPoint(176,91),CSize(46,8));
	parent->MapDialogRect(&r22);
	mfc22->Create(_T("Speed: 6.000"),WS_VISIBLE|WS_BORDER,r22,parent,IDC_STATIC_GROOVE_AVERAGE);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Size: 0 bytes",IDC_STATIC_GROOVE_SIZE,228,91,45,8
	CStatic* mfc23 = new CStatic(parent);
	CRect r23(CPoint(228,91),CSize(45,8));
	parent->MapDialogRect(&r23);
	mfc23->Create(_T("Size: 0 bytes"),WS_VISIBLE|WS_BORDER,r23,parent,IDC_STATIC_GROOVE_SIZE);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // PUSHBUTTON "Copy Fxx",IDC_BUTTON_GROOVE_COPY,123,105,45,14,WS_VISIBLE|WS_BORDER
	CButton* mfc24 = new CButton(parent);
	CRect r24(CPoint(123,105),CSize(45,14));
	parent->MapDialogRect(&r24);
	mfc24->Create(_T("Copy Fxx"),WS_VISIBLE|WS_BORDER,r24,parent,IDC_BUTTON_GROOVE_COPY);
	mfcToQtWidget->insert(IDC_BUTTON_GROOVE_COPY,mfc24);

   // EDITTEXT IDC_EDIT_GROOVE_FIELD,176,105,97,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc25 = new CEdit(parent);
	CRect r25(CPoint(176,105),CSize(97,14));
	parent->MapDialogRect(&r25);
	mfc25->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r25,parent,IDC_EDIT_GROOVE_FIELD);
	mfcToQtWidget->insert(IDC_EDIT_GROOVE_FIELD,mfc25);

   // CONTROL "", IDC_STATIC, "Static", WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, 7, 132, 275, 1
	CStatic* mfc26 = new CStatic(parent);
	CRect r26(CPoint(7, 132), CSize(275, 1));
	parent->MapDialogRect(&r26);
	mfc26->Create(_T(""), WS_VISIBLE|WS_BORDER|SS_ETCHEDHORZ, r26, parent, IDC_STATIC);
	mfcToQtWidget->insert(IDC_STATIC, mfc26);

   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,124,139,50,14
	CButton* mfc27 = new CButton(parent);
	CRect r27(CPoint(124,139),CSize(50,14));
	parent->MapDialogRect(&r27);
	mfc27->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r27,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc27);

   // PUSHBUTTON "Cancel",IDCANCEL,178,139,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc28 = new CButton(parent);
	CRect r28(CPoint(178,139),CSize(50,14));
	parent->MapDialogRect(&r28);
	mfc28->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r28,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc28);

   // PUSHBUTTON "Apply",IDAPPLY,232,139,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc29 = new CButton(parent);
	CRect r29(CPoint(232,139),CSize(50,14));
	parent->MapDialogRect(&r29);
	mfc29->Create(_T("Apply"),WS_VISIBLE|WS_BORDER,r29,parent,IDAPPLY);
	mfcToQtWidget->insert(IDAPPLY,mfc29);

   // END
}


void qtMfcInitDialogResource_IDD_FIND(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_FIND DIALOGEX 0, 0, 142, 264
	CRect rect(CPoint(0,0),CSize(142,264));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());




   // BEGIN
   // GROUPBOX "Find / Replace",IDC_STATIC,8,9,126,121
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(8,9),CSize(126,121));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Find / Replace"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Search Options",IDC_STATIC,8,133,126,67
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(8,133),CSize(126,67));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Search Options"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Find what:",IDC_STATIC,15,21,34,8
	CStatic* mfc3 = new CStatic(parent);
	CRect r3(CPoint(15,21),CSize(34,8));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Find what:"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "Note", IDC_CHECK_FIND_NOTE, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, 15, 34, 24, 10
	CButton* mfc4 = new CButton(parent);
	CRect r4(CPoint(15, 34), CSize(24, 10));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Note"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, r4, parent, IDC_CHECK_FIND_NOTE);
	mfcToQtWidget->insert(IDC_CHECK_FIND_NOTE, mfc4);

   // EDITTEXT IDC_EDIT_FIND_NOTE,15,47,24,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|WS_DISABLED
	CEdit* mfc5 = new CEdit(parent);
	CRect r5(CPoint(15,47),CSize(24,14));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|WS_DISABLED,r5,parent,IDC_EDIT_FIND_NOTE);
	mfcToQtWidget->insert(IDC_EDIT_FIND_NOTE,mfc5);

   // EDITTEXT IDC_EDIT_FIND_NOTE2,15,64,24,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|WS_DISABLED
	CEdit* mfc6 = new CEdit(parent);
	CRect r6(CPoint(15,64),CSize(24,14));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|WS_DISABLED,r6,parent,IDC_EDIT_FIND_NOTE2);
	mfcToQtWidget->insert(IDC_EDIT_FIND_NOTE2,mfc6);

   // CONTROL "Inst", IDC_CHECK_FIND_INST, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, 44, 34, 24, 10
	CButton* mfc7 = new CButton(parent);
	CRect r7(CPoint(44, 34), CSize(24, 10));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("Inst"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, r7, parent, IDC_CHECK_FIND_INST);
	mfcToQtWidget->insert(IDC_CHECK_FIND_INST, mfc7);

   // EDITTEXT IDC_EDIT_FIND_INST,44,47,24,14,WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED
	CEdit* mfc8 = new CEdit(parent);
	CRect r8(CPoint(44,47),CSize(24,14));
	parent->MapDialogRect(&r8);
	mfc8->Create(WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED,r8,parent,IDC_EDIT_FIND_INST);
	mfcToQtWidget->insert(IDC_EDIT_FIND_INST,mfc8);

   // EDITTEXT IDC_EDIT_FIND_INST2,44,64,24,14,WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED
	CEdit* mfc9 = new CEdit(parent);
	CRect r9(CPoint(44,64),CSize(24,14));
	parent->MapDialogRect(&r9);
	mfc9->Create(WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED,r9,parent,IDC_EDIT_FIND_INST2);
	mfcToQtWidget->insert(IDC_EDIT_FIND_INST2,mfc9);

   // CONTROL "Vol", IDC_CHECK_FIND_VOL, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, 73, 34, 24, 10
	CButton* mfc10 = new CButton(parent);
	CRect r10(CPoint(73, 34), CSize(24, 10));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("Vol"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, r10, parent, IDC_CHECK_FIND_VOL);
	mfcToQtWidget->insert(IDC_CHECK_FIND_VOL, mfc10);

   // EDITTEXT IDC_EDIT_FIND_VOL,73,47,24,14,WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED
	CEdit* mfc11 = new CEdit(parent);
	CRect r11(CPoint(73,47),CSize(24,14));
	parent->MapDialogRect(&r11);
	mfc11->Create(WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED,r11,parent,IDC_EDIT_FIND_VOL);
	mfcToQtWidget->insert(IDC_EDIT_FIND_VOL,mfc11);

   // EDITTEXT IDC_EDIT_FIND_VOL2,73,64,24,14,WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED
	CEdit* mfc12 = new CEdit(parent);
	CRect r12(CPoint(73,64),CSize(24,14));
	parent->MapDialogRect(&r12);
	mfc12->Create(WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED,r12,parent,IDC_EDIT_FIND_VOL2);
	mfcToQtWidget->insert(IDC_EDIT_FIND_VOL2,mfc12);

   // CONTROL "FX", IDC_CHECK_FIND_EFF, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, 102, 34, 24, 10
	CButton* mfc13 = new CButton(parent);
	CRect r13(CPoint(102, 34), CSize(24, 10));
	parent->MapDialogRect(&r13);
	mfc13->Create(_T("FX"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, r13, parent, IDC_CHECK_FIND_EFF);
	mfcToQtWidget->insert(IDC_CHECK_FIND_EFF, mfc13);

   // EDITTEXT IDC_EDIT_FIND_EFF,102,47,24,14,WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED
	CEdit* mfc14 = new CEdit(parent);
	CRect r14(CPoint(102,47),CSize(24,14));
	parent->MapDialogRect(&r14);
	mfc14->Create(WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED,r14,parent,IDC_EDIT_FIND_EFF);
	mfcToQtWidget->insert(IDC_EDIT_FIND_EFF,mfc14);

   // LTEXT "Replace with:",IDC_STATIC,15,83,43,8
	CStatic* mfc15 = new CStatic(parent);
	CRect r15(CPoint(15,83),CSize(43,8));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("Replace with:"),WS_VISIBLE|WS_BORDER,r15,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "Note", IDC_CHECK_REPLACE_NOTE, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, 15, 96, 24, 10
	CButton* mfc16 = new CButton(parent);
	CRect r16(CPoint(15, 96), CSize(24, 10));
	parent->MapDialogRect(&r16);
	mfc16->Create(_T("Note"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, r16, parent, IDC_CHECK_REPLACE_NOTE);
	mfcToQtWidget->insert(IDC_CHECK_REPLACE_NOTE, mfc16);

   // EDITTEXT IDC_EDIT_REPLACE_NOTE,15,109,24,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|WS_DISABLED
	CEdit* mfc17 = new CEdit(parent);
	CRect r17(CPoint(15,109),CSize(24,14));
	parent->MapDialogRect(&r17);
	mfc17->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|WS_DISABLED,r17,parent,IDC_EDIT_REPLACE_NOTE);
	mfcToQtWidget->insert(IDC_EDIT_REPLACE_NOTE,mfc17);

   // CONTROL "Inst", IDC_CHECK_REPLACE_INST, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, 44, 96, 24, 10
	CButton* mfc18 = new CButton(parent);
	CRect r18(CPoint(44, 96), CSize(24, 10));
	parent->MapDialogRect(&r18);
	mfc18->Create(_T("Inst"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, r18, parent, IDC_CHECK_REPLACE_INST);
	mfcToQtWidget->insert(IDC_CHECK_REPLACE_INST, mfc18);

   // EDITTEXT IDC_EDIT_REPLACE_INST,44,109,24,14,WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED
	CEdit* mfc19 = new CEdit(parent);
	CRect r19(CPoint(44,109),CSize(24,14));
	parent->MapDialogRect(&r19);
	mfc19->Create(WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED,r19,parent,IDC_EDIT_REPLACE_INST);
	mfcToQtWidget->insert(IDC_EDIT_REPLACE_INST,mfc19);

   // CONTROL "Vol", IDC_CHECK_REPLACE_VOL, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, 73, 96, 24, 10
	CButton* mfc20 = new CButton(parent);
	CRect r20(CPoint(73, 96), CSize(24, 10));
	parent->MapDialogRect(&r20);
	mfc20->Create(_T("Vol"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, r20, parent, IDC_CHECK_REPLACE_VOL);
	mfcToQtWidget->insert(IDC_CHECK_REPLACE_VOL, mfc20);

   // EDITTEXT IDC_EDIT_REPLACE_VOL,73,109,24,14,WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED
	CEdit* mfc21 = new CEdit(parent);
	CRect r21(CPoint(73,109),CSize(24,14));
	parent->MapDialogRect(&r21);
	mfc21->Create(WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED,r21,parent,IDC_EDIT_REPLACE_VOL);
	mfcToQtWidget->insert(IDC_EDIT_REPLACE_VOL,mfc21);

   // CONTROL "FX", IDC_CHECK_REPLACE_EFF, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, 102, 96, 24, 10
	CButton* mfc22 = new CButton(parent);
	CRect r22(CPoint(102, 96), CSize(24, 10));
	parent->MapDialogRect(&r22);
	mfc22->Create(_T("FX"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|BS_PUSHLIKE|WS_TABSTOP, r22, parent, IDC_CHECK_REPLACE_EFF);
	mfcToQtWidget->insert(IDC_CHECK_REPLACE_EFF, mfc22);

   // EDITTEXT IDC_EDIT_REPLACE_EFF,102,109,24,14,WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED
	CEdit* mfc23 = new CEdit(parent);
	CRect r23(CPoint(102,109),CSize(24,14));
	parent->MapDialogRect(&r23);
	mfc23->Create(WS_VISIBLE|WS_BORDER|ES_UPPERCASE|ES_AUTOHSCROLL|WS_DISABLED,r23,parent,IDC_EDIT_REPLACE_EFF);
	mfcToQtWidget->insert(IDC_EDIT_REPLACE_EFF,mfc23);

   // LTEXT "Look in:",IDC_STATIC,15,147,26,8
	CStatic* mfc25 = new CStatic(parent);
	CRect r25(CPoint(15,147),CSize(26,8));
	parent->MapDialogRect(&r25);
	mfc25->Create(_T("Look in:"),WS_VISIBLE|WS_BORDER,r25,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_COMBO_FIND_IN,43,145,44,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc26 = new CComboBox(parent);
	CRect r26(CPoint(43,145),CSize(44,30));
	parent->MapDialogRect(&r26);
	mfc26->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r26,parent,IDC_COMBO_FIND_IN);
	mfcToQtWidget->insert(IDC_COMBO_FIND_IN,mfc26);


	mfc26->AddString(_T("Track"));
	

	mfc26->AddString(_T("Channel"));
	

	mfc26->AddString(_T("Frame"));
	

	mfc26->AddString(_T("Pattern"));
	

	mfc26->AddString(_T("Selection"));
	
   // COMBOBOX IDC_COMBO_EFFCOLUMN,95,145,31,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc27 = new CComboBox(parent);
	CRect r27(CPoint(95,145),CSize(31,30));
	parent->MapDialogRect(&r27);
	mfc27->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r27,parent,IDC_COMBO_EFFCOLUMN);
	mfcToQtWidget->insert(IDC_COMBO_EFFCOLUMN,mfc27);


	mfc27->AddString(_T("fx1"));
	

	mfc27->AddString(_T("fx2"));
	

	mfc27->AddString(_T("fx3"));
	

	mfc27->AddString(_T("fx4"));
	

	mfc27->AddString(_T("All"));
	
   // CONTROL "Vertical-first searching", IDC_CHECK_VERTICAL_SEARCH, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 15, 162, 98, 10
	CButton* mfc28 = new CButton(parent);
	CRect r28(CPoint(15, 162), CSize(98, 10));
	parent->MapDialogRect(&r28);
	mfc28->Create(_T("Vertical-first searching"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r28, parent, IDC_CHECK_VERTICAL_SEARCH);
	mfcToQtWidget->insert(IDC_CHECK_VERTICAL_SEARCH, mfc28);

   // CONTROL "Remove original data", IDC_CHECK_FIND_REMOVE, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 15, 173, 98, 10
	CButton* mfc29 = new CButton(parent);
	CRect r29(CPoint(15, 173), CSize(98, 10));
	parent->MapDialogRect(&r29);
	mfc29->Create(_T("Remove original data"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r29, parent, IDC_CHECK_FIND_REMOVE);
	mfcToQtWidget->insert(IDC_CHECK_FIND_REMOVE, mfc29);

   // CONTROL "Negate search", IDC_CHECK_FIND_NEGATE, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 15, 184, 98, 10
	CButton* mfc30 = new CButton(parent);
	CRect r30(CPoint(15, 184), CSize(98, 10));
	parent->MapDialogRect(&r30);
	mfc30->Create(_T("Negate search"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r30, parent, IDC_CHECK_FIND_NEGATE);
	mfcToQtWidget->insert(IDC_CHECK_FIND_NEGATE, mfc30);

   // PUSHBUTTON "Find Next",IDC_BUTTON_FIND_NEXT,8,206,54,14,WS_VISIBLE|WS_BORDER|WS_GROUP
	CButton* mfc31 = new CButton(parent);
	CRect r31(CPoint(8,206),CSize(54,14));
	parent->MapDialogRect(&r31);
	mfc31->Create(_T("Find Next"),WS_VISIBLE|WS_BORDER|WS_GROUP,r31,parent,IDC_BUTTON_FIND_NEXT);
	mfcToQtWidget->insert(IDC_BUTTON_FIND_NEXT,mfc31);

   // PUSHBUTTON "Find Previous",IDC_BUTTON_FIND_PREVIOUS,8,224,54,14,WS_VISIBLE|WS_BORDER
	CButton* mfc32 = new CButton(parent);
	CRect r32(CPoint(8,224),CSize(54,14));
	parent->MapDialogRect(&r32);
	mfc32->Create(_T("Find Previous"),WS_VISIBLE|WS_BORDER,r32,parent,IDC_BUTTON_FIND_PREVIOUS);
	mfcToQtWidget->insert(IDC_BUTTON_FIND_PREVIOUS,mfc32);

   // PUSHBUTTON "Find All",IDC_BUTTON_FIND_ALL,8,242,54,14,WS_VISIBLE|WS_BORDER
	CButton* mfc33 = new CButton(parent);
	CRect r33(CPoint(8,242),CSize(54,14));
	parent->MapDialogRect(&r33);
	mfc33->Create(_T("Find All"),WS_VISIBLE|WS_BORDER,r33,parent,IDC_BUTTON_FIND_ALL);
	mfcToQtWidget->insert(IDC_BUTTON_FIND_ALL,mfc33);

   // PUSHBUTTON "Replace Next",IDC_BUTTON_REPLACE,69,206,65,14,WS_VISIBLE|WS_BORDER
	CButton* mfc34 = new CButton(parent);
	CRect r34(CPoint(69,206),CSize(65,14));
	parent->MapDialogRect(&r34);
	mfc34->Create(_T("Replace Next"),WS_VISIBLE|WS_BORDER,r34,parent,IDC_BUTTON_REPLACE);
	mfcToQtWidget->insert(IDC_BUTTON_REPLACE,mfc34);

   // PUSHBUTTON "Replace Previous",IDC_BUTTON_REPLACE_PREVIOUS,69,224,65,14,WS_VISIBLE|WS_BORDER
	CButton* mfc35 = new CButton(parent);
	CRect r35(CPoint(69,224),CSize(65,14));
	parent->MapDialogRect(&r35);
	mfc35->Create(_T("Replace Previous"),WS_VISIBLE|WS_BORDER,r35,parent,IDC_BUTTON_REPLACE_PREVIOUS);
	mfcToQtWidget->insert(IDC_BUTTON_REPLACE_PREVIOUS,mfc35);

   // PUSHBUTTON "Replace All",IDC_BUTTON_FIND_REPLACEALL,69,242,65,14,WS_VISIBLE|WS_BORDER
	CButton* mfc36 = new CButton(parent);
	CRect r36(CPoint(69,242),CSize(65,14));
	parent->MapDialogRect(&r36);
	mfc36->Create(_T("Replace All"),WS_VISIBLE|WS_BORDER,r36,parent,IDC_BUTTON_FIND_REPLACEALL);
	mfcToQtWidget->insert(IDC_BUTTON_FIND_REPLACEALL,mfc36);

   // END
}


void qtMfcInitDialogResource_IDD_STRETCH(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_STRETCH DIALOGEX 0, 0, 294, 42
	CRect rect(CPoint(0,0),CSize(294,42));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Stretch selection"
	parent->SetWindowText("Stretch selection");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // LTEXT "Stretch map:",IDC_STATIC,6,9,42,8
	CStatic* mfc0 = new CStatic(parent);
	CRect r0(CPoint(6,9),CSize(42,8));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Stretch map:"),WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_EDIT_STRETCH_MAP,51,7,98,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc1 = new CEdit(parent);
	CRect r1(CPoint(51,7),CSize(98,14));
	parent->MapDialogRect(&r1);
	mfc1->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r1,parent,IDC_EDIT_STRETCH_MAP);
	mfcToQtWidget->insert(IDC_EDIT_STRETCH_MAP,mfc1);

   // LTEXT "Test: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15",IDC_STRETCH_TEST,6,26,143,8
	CStatic* mfc2 = new CStatic(parent);
	CRect r2(CPoint(6,26),CSize(143,8));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Test: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15"),WS_VISIBLE|WS_BORDER,r2,parent,IDC_STRETCH_TEST);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // PUSHBUTTON "Expand",IDC_BUTTON_STRETCH_EXPAND,156,7,39,14,WS_VISIBLE|WS_BORDER
	CButton* mfc3 = new CButton(parent);
	CRect r3(CPoint(156,7),CSize(39,14));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Expand"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_BUTTON_STRETCH_EXPAND);
	mfcToQtWidget->insert(IDC_BUTTON_STRETCH_EXPAND,mfc3);

   // PUSHBUTTON "Shrink",IDC_BUTTON_STRETCH_SHRINK,156,23,39,14,WS_VISIBLE|WS_BORDER
	CButton* mfc4 = new CButton(parent);
	CRect r4(CPoint(156,23),CSize(39,14));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Shrink"),WS_VISIBLE|WS_BORDER,r4,parent,IDC_BUTTON_STRETCH_SHRINK);
	mfcToQtWidget->insert(IDC_BUTTON_STRETCH_SHRINK,mfc4);

   // PUSHBUTTON "Reset",IDC_BUTTON_STRETCH_RESET,202,7,39,14,WS_VISIBLE|WS_BORDER
	CButton* mfc5 = new CButton(parent);
	CRect r5(CPoint(202,7),CSize(39,14));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Reset"),WS_VISIBLE|WS_BORDER,r5,parent,IDC_BUTTON_STRETCH_RESET);
	mfcToQtWidget->insert(IDC_BUTTON_STRETCH_RESET,mfc5);

   // PUSHBUTTON "Invert",IDC_BUTTON_STRETCH_INVERT,202,23,39,14,WS_VISIBLE|WS_BORDER
	CButton* mfc6 = new CButton(parent);
	CRect r6(CPoint(202,23),CSize(39,14));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Invert"),WS_VISIBLE|WS_BORDER,r6,parent,IDC_BUTTON_STRETCH_INVERT);
	mfcToQtWidget->insert(IDC_BUTTON_STRETCH_INVERT,mfc6);

   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,248,7,39,14
	CButton* mfc7 = new CButton(parent);
	CRect r7(CPoint(248,7),CSize(39,14));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r7,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc7);

   // PUSHBUTTON "Cancel",IDCANCEL,248,23,39,14,WS_VISIBLE|WS_BORDER
	CButton* mfc8 = new CButton(parent);
	CRect r8(CPoint(248,23),CSize(39,14));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r8,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc8);

   // END
}


void qtMfcInitDialogResource_IDD_BOOKMARKS(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_BOOKMARKS DIALOGEX 0, 0, 325, 162
	CRect rect(CPoint(0,0),CSize(325,162));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Bookmark Manager"
	parent->SetWindowText("Bookmark Manager");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Bookmark Editor",IDC_STATIC,7,5,117,150
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,5),CSize(117,150));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Bookmark Editor"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Bookmark List",IDC_STATIC,132,5,186,150
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(132,5),CSize(186,150));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Bookmark List"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Name:",IDC_STATIC,16,19,22,8
	CStatic* mfc3 = new CStatic(parent);
	CRect r3(CPoint(16,19),CSize(22,8));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Name:"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_EDIT_BOOKMARK_NAME,40,17,77,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL
	CEdit* mfc4 = new CEdit(parent);
	CRect r4(CPoint(40,17),CSize(77,14));
	parent->MapDialogRect(&r4);
	mfc4->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,r4,parent,IDC_EDIT_BOOKMARK_NAME);
	mfcToQtWidget->insert(IDC_EDIT_BOOKMARK_NAME,mfc4);

   // LTEXT "Frame:",IDC_STATIC,14,37,24,8
	CStatic* mfc5 = new CStatic(parent);
	CRect r5(CPoint(14,37),CSize(24,8));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Frame:"),WS_VISIBLE|WS_BORDER,r5,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_EDIT_BOOKMARK_FRAME,40,35,77,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc6 = new CEdit(parent);
	CRect r6(CPoint(40,35),CSize(77,14));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r6,parent,IDC_EDIT_BOOKMARK_FRAME);
	mfcToQtWidget->insert(IDC_EDIT_BOOKMARK_FRAME,mfc6);

   // CONTROL "", IDC_SPIN_BOOKMARK_FRAME, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 106, 35, 11, 14
	CSpinButtonCtrl* mfc7 = new CSpinButtonCtrl(parent);
	CRect r7(CPoint(106, 35), CSize(11, 14));
	parent->MapDialogRect(&r7);
	mfc7->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r7, parent, IDC_SPIN_BOOKMARK_FRAME);
	mfcToQtWidget->insert(IDC_SPIN_BOOKMARK_FRAME, mfc7);

   // LTEXT "Row:",IDC_STATIC,20,55,18,8
	CStatic* mfc8 = new CStatic(parent);
	CRect r8(CPoint(20,55),CSize(18,8));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Row:"),WS_VISIBLE|WS_BORDER,r8,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_EDIT_BOOKMARK_ROW,40,53,77,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc9 = new CEdit(parent);
	CRect r9(CPoint(40,53),CSize(77,14));
	parent->MapDialogRect(&r9);
	mfc9->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r9,parent,IDC_EDIT_BOOKMARK_ROW);
	mfcToQtWidget->insert(IDC_EDIT_BOOKMARK_ROW,mfc9);

   // CONTROL "", IDC_SPIN_BOOKMARK_ROW, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 106, 52, 11, 14
	CSpinButtonCtrl* mfc10 = new CSpinButtonCtrl(parent);
	CRect r10(CPoint(106, 52), CSize(11, 14));
	parent->MapDialogRect(&r10);
	mfc10->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r10, parent, IDC_SPIN_BOOKMARK_ROW);
	mfcToQtWidget->insert(IDC_SPIN_BOOKMARK_ROW, mfc10);

   // LTEXT "Highlight Settings",IDC_STATIC,14,70,56,8
	CStatic* mfc11 = new CStatic(parent);
	CRect r11(CPoint(14,70),CSize(56,8));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T("Highlight Settings"),WS_VISIBLE|WS_BORDER,r11,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "1st:", IDC_CHECK_BOOKMARK_HIGH1, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 12, 84, 25, 10
	CButton* mfc12 = new CButton(parent);
	CRect r12(CPoint(12, 84), CSize(25, 10));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T("1st:"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r12, parent, IDC_CHECK_BOOKMARK_HIGH1);
	mfcToQtWidget->insert(IDC_CHECK_BOOKMARK_HIGH1, mfc12);

   // EDITTEXT IDC_EDIT_BOOKMARK_HIGH1,40,83,77,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER|WS_DISABLED
	CEdit* mfc13 = new CEdit(parent);
	CRect r13(CPoint(40,83),CSize(77,14));
	parent->MapDialogRect(&r13);
	mfc13->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER|WS_DISABLED,r13,parent,IDC_EDIT_BOOKMARK_HIGH1);
	mfcToQtWidget->insert(IDC_EDIT_BOOKMARK_HIGH1,mfc13);

   // CONTROL "", IDC_SPIN_BOOKMARK_HIGH1, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 106, 83, 11, 14
	CSpinButtonCtrl* mfc14 = new CSpinButtonCtrl(parent);
	CRect r14(CPoint(106, 83), CSize(11, 14));
	parent->MapDialogRect(&r14);
	mfc14->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r14, parent, IDC_SPIN_BOOKMARK_HIGH1);
	mfcToQtWidget->insert(IDC_SPIN_BOOKMARK_HIGH1, mfc14);

   // CONTROL "2nd:", IDC_CHECK_BOOKMARK_HIGH2, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 12, 102, 25, 10
	CButton* mfc15 = new CButton(parent);
	CRect r15(CPoint(12, 102), CSize(25, 10));
	parent->MapDialogRect(&r15);
	mfc15->Create(_T("2nd:"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r15, parent, IDC_CHECK_BOOKMARK_HIGH2);
	mfcToQtWidget->insert(IDC_CHECK_BOOKMARK_HIGH2, mfc15);

   // EDITTEXT IDC_EDIT_BOOKMARK_HIGH2,40,101,77,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER|WS_DISABLED
	CEdit* mfc16 = new CEdit(parent);
	CRect r16(CPoint(40,101),CSize(77,14));
	parent->MapDialogRect(&r16);
	mfc16->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER|WS_DISABLED,r16,parent,IDC_EDIT_BOOKMARK_HIGH2);
	mfcToQtWidget->insert(IDC_EDIT_BOOKMARK_HIGH2,mfc16);

   // CONTROL "", IDC_SPIN_BOOKMARK_HIGH2, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 106, 101, 11, 14
	CSpinButtonCtrl* mfc17 = new CSpinButtonCtrl(parent);
	CRect r17(CPoint(106, 101), CSize(11, 14));
	parent->MapDialogRect(&r17);
	mfc17->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r17, parent, IDC_SPIN_BOOKMARK_HIGH2);
	mfcToQtWidget->insert(IDC_SPIN_BOOKMARK_HIGH2, mfc17);

   // CONTROL "Apply to all following frames", IDC_CHECK_BOOKMARK_PERSIST, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 12, 120, 105, 10
	CButton* mfc18 = new CButton(parent);
	CRect r18(CPoint(12, 120), CSize(105, 10));
	parent->MapDialogRect(&r18);
	mfc18->Create(_T("Apply to all following frames"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r18, parent, IDC_CHECK_BOOKMARK_PERSIST);
	mfcToQtWidget->insert(IDC_CHECK_BOOKMARK_PERSIST, mfc18);

   // PUSHBUTTON "Create New",IDC_BUTTON_BOOKMARK_ADD,14,135,48,14,WS_VISIBLE|WS_BORDER
	CButton* mfc19 = new CButton(parent);
	CRect r19(CPoint(14,135),CSize(48,14));
	parent->MapDialogRect(&r19);
	mfc19->Create(_T("Create New"),WS_VISIBLE|WS_BORDER,r19,parent,IDC_BUTTON_BOOKMARK_ADD);
	mfcToQtWidget->insert(IDC_BUTTON_BOOKMARK_ADD,mfc19);

   // LISTBOX IDC_LIST_BOOKMARKS,140,18,115,130,WS_VISIBLE|WS_BORDER|LBS_NOINTEGRALHEIGHT|WS_VSCROLL|WS_TABSTOP
	CListBox* mfc21 = new CListBox(parent);
	CRect r21(CPoint(140,18),CSize(115,130));
	parent->MapDialogRect(&r21);
	mfc21->Create(WS_VISIBLE|WS_BORDER|LBS_NOINTEGRALHEIGHT|WS_VSCROLL|WS_TABSTOP,r21,parent,IDC_LIST_BOOKMARKS);
	mfcToQtWidget->insert(IDC_LIST_BOOKMARKS,mfc21);

   // PUSHBUTTON "Move Up",IDC_BUTTON_BOOKMARK_MOVEUP,262,17,48,14,WS_VISIBLE|WS_BORDER
	CButton* mfc22 = new CButton(parent);
	CRect r22(CPoint(262,17),CSize(48,14));
	parent->MapDialogRect(&r22);
	mfc22->Create(_T("Move Up"),WS_VISIBLE|WS_BORDER,r22,parent,IDC_BUTTON_BOOKMARK_MOVEUP);
	mfcToQtWidget->insert(IDC_BUTTON_BOOKMARK_MOVEUP,mfc22);

   // PUSHBUTTON "Move Down",IDC_BUTTON_BOOKMARK_MOVEDOWN,262,35,48,14,WS_VISIBLE|WS_BORDER
	CButton* mfc23 = new CButton(parent);
	CRect r23(CPoint(262,35),CSize(48,14));
	parent->MapDialogRect(&r23);
	mfc23->Create(_T("Move Down"),WS_VISIBLE|WS_BORDER,r23,parent,IDC_BUTTON_BOOKMARK_MOVEDOWN);
	mfcToQtWidget->insert(IDC_BUTTON_BOOKMARK_MOVEDOWN,mfc23);

   // PUSHBUTTON "Remove",IDC_BUTTON_BOOKMARK_REMOVE,262,53,48,14,WS_VISIBLE|WS_BORDER
	CButton* mfc24 = new CButton(parent);
	CRect r24(CPoint(262,53),CSize(48,14));
	parent->MapDialogRect(&r24);
	mfc24->Create(_T("Remove"),WS_VISIBLE|WS_BORDER,r24,parent,IDC_BUTTON_BOOKMARK_REMOVE);
	mfcToQtWidget->insert(IDC_BUTTON_BOOKMARK_REMOVE,mfc24);

   // PUSHBUTTON "Clear All",IDC_BUTTON_BOOKMARK_CLEARALL,262,71,48,14,WS_VISIBLE|WS_BORDER
	CButton* mfc25 = new CButton(parent);
	CRect r25(CPoint(262,71),CSize(48,14));
	parent->MapDialogRect(&r25);
	mfc25->Create(_T("Clear All"),WS_VISIBLE|WS_BORDER,r25,parent,IDC_BUTTON_BOOKMARK_CLEARALL);
	mfcToQtWidget->insert(IDC_BUTTON_BOOKMARK_CLEARALL,mfc25);

   // LTEXT "Sort by:",IDC_STATIC,263,103,27,8
	CStatic* mfc26 = new CStatic(parent);
	CRect r26(CPoint(263,103),CSize(27,8));
	parent->MapDialogRect(&r26);
	mfc26->Create(_T("Sort by:"),WS_VISIBLE|WS_BORDER,r26,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // PUSHBUTTON "Position",IDC_BUTTON_BOOKMARK_SORTP,262,116,48,14,WS_VISIBLE|WS_BORDER
	CButton* mfc27 = new CButton(parent);
	CRect r27(CPoint(262,116),CSize(48,14));
	parent->MapDialogRect(&r27);
	mfc27->Create(_T("Position"),WS_VISIBLE|WS_BORDER,r27,parent,IDC_BUTTON_BOOKMARK_SORTP);
	mfcToQtWidget->insert(IDC_BUTTON_BOOKMARK_SORTP,mfc27);

   // PUSHBUTTON "Name",IDC_BUTTON_BOOKMARK_SORTN,262,134,48,14,WS_VISIBLE|WS_BORDER
	CButton* mfc28 = new CButton(parent);
	CRect r28(CPoint(262,134),CSize(48,14));
	parent->MapDialogRect(&r28);
	mfc28->Create(_T("Name"),WS_VISIBLE|WS_BORDER,r28,parent,IDC_BUTTON_BOOKMARK_SORTN);
	mfcToQtWidget->insert(IDC_BUTTON_BOOKMARK_SORTN,mfc28);

   // PUSHBUTTON "Update",IDC_BUTTON_BOOKMARK_UPDATE,70,135,48,14,WS_VISIBLE|WS_BORDER
	CButton* mfc29 = new CButton(parent);
	CRect r29(CPoint(70,135),CSize(48,14));
	parent->MapDialogRect(&r29);
	mfc29->Create(_T("Update"),WS_VISIBLE|WS_BORDER,r29,parent,IDC_BUTTON_BOOKMARK_UPDATE);
	mfcToQtWidget->insert(IDC_BUTTON_BOOKMARK_UPDATE,mfc29);

   // END
}


void qtMfcInitDialogResource_IDD_GOTO(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_GOTO DIALOGEX 0, 0, 159, 60
	CRect rect(CPoint(0,0),CSize(159,60));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Go To"
	parent->SetWindowText("Go To");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // LTEXT "Frame:",IDC_STATIC,9,6,24,8
	CStatic* mfc0 = new CStatic(parent);
	CRect r0(CPoint(9,6),CSize(24,8));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Frame:"),WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Row:",IDC_STATIC,45,6,18,8
	CStatic* mfc1 = new CStatic(parent);
	CRect r1(CPoint(45,6),CSize(18,8));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Row:"),WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Chip:",IDC_STATIC,81,6,18,8
	CStatic* mfc2 = new CStatic(parent);
	CRect r2(CPoint(81,6),CSize(18,8));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Chip:"),WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Channel:",IDC_STATIC,124,6,30,8
	CStatic* mfc3 = new CStatic(parent);
	CRect r3(CPoint(124,6),CSize(30,8));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Channel:"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_EDIT_GOTO_FRAME,8,19,28,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc4 = new CEdit(parent);
	CRect r4(CPoint(8,19),CSize(28,14));
	parent->MapDialogRect(&r4);
	mfc4->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r4,parent,IDC_EDIT_GOTO_FRAME);
	mfcToQtWidget->insert(IDC_EDIT_GOTO_FRAME,mfc4);

   // EDITTEXT IDC_EDIT_GOTO_ROW,44,19,28,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc5 = new CEdit(parent);
	CRect r5(CPoint(44,19),CSize(28,14));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r5,parent,IDC_EDIT_GOTO_ROW);
	mfcToQtWidget->insert(IDC_EDIT_GOTO_ROW,mfc5);

   // COMBOBOX IDC_COMBO_GOTO_CHIP,80,19,35,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc6 = new CComboBox(parent);
	CRect r6(CPoint(80,19),CSize(35,30));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r6,parent,IDC_COMBO_GOTO_CHIP);
	mfcToQtWidget->insert(IDC_COMBO_GOTO_CHIP,mfc6);

   // EDITTEXT IDC_EDIT_GOTO_CHANNEL,123,19,28,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc7 = new CEdit(parent);
	CRect r7(CPoint(123,19),CSize(28,14));
	parent->MapDialogRect(&r7);
	mfc7->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r7,parent,IDC_EDIT_GOTO_CHANNEL);
	mfcToQtWidget->insert(IDC_EDIT_GOTO_CHANNEL,mfc7);

   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,48,39,50,14
	CButton* mfc8 = new CButton(parent);
	CRect r8(CPoint(48,39),CSize(50,14));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r8,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc8);

   // PUSHBUTTON "Cancel",IDCANCEL,102,39,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc9 = new CButton(parent);
	CRect r9(CPoint(102,39),CSize(50,14));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r9,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc9);

   // END
}


void qtMfcInitDialogResource_IDD_SWAP(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_SWAP DIALOGEX 0, 0, 87, 112
	CRect rect(CPoint(0,0),CSize(87,112));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Swap Channels"
	parent->SetWindowText("Swap Channels");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,7,91,31,14
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,91),CSize(31,14));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r0,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc0);

   // PUSHBUTTON "Cancel",IDCANCEL,49,91,31,14,WS_VISIBLE|WS_BORDER
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(49,91),CSize(31,14));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r1,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc1);

   // LTEXT "Chip:",IDC_STATIC,9,6,18,8
	CStatic* mfc2 = new CStatic(parent);
	CRect r2(CPoint(9,6),CSize(18,8));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Chip:"),WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Channel:",IDC_STATIC,49,6,30,8
	CStatic* mfc3 = new CStatic(parent);
	CRect r3(CPoint(49,6),CSize(30,8));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Channel:"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Warning: Resets undo after swapping!",IDC_STATIC,7,70,73,17
	CStatic* mfc4 = new CStatic(parent);
	CRect r4(CPoint(7,70),CSize(73,17));
	parent->MapDialogRect(&r4);
	mfc4->Create(_T("Warning: Resets undo after swapping!"),WS_VISIBLE|WS_BORDER,r4,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_COMBO_SWAP_CHIP1,7,19,34,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc5 = new CComboBox(parent);
	CRect r5(CPoint(7,19),CSize(34,30));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r5,parent,IDC_COMBO_SWAP_CHIP1);
	mfcToQtWidget->insert(IDC_COMBO_SWAP_CHIP1,mfc5);

   // COMBOBOX IDC_COMBO_SWAP_CHIP2,7,38,34,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc6 = new CComboBox(parent);
	CRect r6(CPoint(7,38),CSize(34,30));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r6,parent,IDC_COMBO_SWAP_CHIP2);
	mfcToQtWidget->insert(IDC_COMBO_SWAP_CHIP2,mfc6);

   // EDITTEXT IDC_EDIT_SWAP_CHAN1,49,19,28,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc7 = new CEdit(parent);
	CRect r7(CPoint(49,19),CSize(28,14));
	parent->MapDialogRect(&r7);
	mfc7->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r7,parent,IDC_EDIT_SWAP_CHAN1);
	mfcToQtWidget->insert(IDC_EDIT_SWAP_CHAN1,mfc7);

   // EDITTEXT IDC_EDIT_SWAP_CHAN2,49,38,28,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc8 = new CEdit(parent);
	CRect r8(CPoint(49,38),CSize(28,14));
	parent->MapDialogRect(&r8);
	mfc8->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r8,parent,IDC_EDIT_SWAP_CHAN2);
	mfcToQtWidget->insert(IDC_EDIT_SWAP_CHAN2,mfc8);

   // CONTROL "Apply to all tracks", IDC_CHECK_SWAP_ALL, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 7, 57, 73, 10
	CButton* mfc9 = new CButton(parent);
	CRect r9(CPoint(7, 57), CSize(73, 10));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("Apply to all tracks"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r9, parent, IDC_CHECK_SWAP_ALL);
	mfcToQtWidget->insert(IDC_CHECK_SWAP_ALL, mfc9);

   // END
}


void qtMfcInitDialogResource_IDD_RECORD_SETTINGS(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_RECORD_SETTINGS DIALOGEX 0, 0, 167, 105
	CRect rect(CPoint(0,0),CSize(167,105));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Recorder Settings"
	parent->SetWindowText("Recorder Settings");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Instrument recorder parameters",IDC_STATIC,7,7,153,73
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(153,73));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Instrument recorder parameters"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Sequence length:",IDC_STATIC,17,23,57,8
	CStatic* mfc2 = new CStatic(parent);
	CRect r2(CPoint(17,23),CSize(57,8));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Sequence length:"),WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_EDIT_RECORDER_INTERVAL,110,21,40,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc3 = new CEdit(parent);
	CRect r3(CPoint(110,21),CSize(40,14));
	parent->MapDialogRect(&r3);
	mfc3->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r3,parent,IDC_EDIT_RECORDER_INTERVAL);
	mfcToQtWidget->insert(IDC_EDIT_RECORDER_INTERVAL,mfc3);

   // CONTROL "", IDC_SPIN_RECORDER_INTERVAL, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 139, 21, 11, 14
	CSpinButtonCtrl* mfc4 = new CSpinButtonCtrl(parent);
	CRect r4(CPoint(139, 21), CSize(11, 14));
	parent->MapDialogRect(&r4);
	mfc4->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r4, parent, IDC_SPIN_RECORDER_INTERVAL);
	mfcToQtWidget->insert(IDC_SPIN_RECORDER_INTERVAL, mfc4);

   // LTEXT "Maximum instrument count:",IDC_STATIC,17,43,89,8
	CStatic* mfc5 = new CStatic(parent);
	CRect r5(CPoint(17,43),CSize(89,8));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Maximum instrument count:"),WS_VISIBLE|WS_BORDER,r5,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_EDIT_RECORDER_COUNT,110,41,40,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc6 = new CEdit(parent);
	CRect r6(CPoint(110,41),CSize(40,14));
	parent->MapDialogRect(&r6);
	mfc6->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r6,parent,IDC_EDIT_RECORDER_COUNT);
	mfcToQtWidget->insert(IDC_EDIT_RECORDER_COUNT,mfc6);

   // CONTROL "", IDC_SPIN_RECORDER_COUNT, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 139, 41, 11, 14
	CSpinButtonCtrl* mfc7 = new CSpinButtonCtrl(parent);
	CRect r7(CPoint(139, 41), CSize(11, 14));
	parent->MapDialogRect(&r7);
	mfc7->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r7, parent, IDC_SPIN_RECORDER_COUNT);
	mfcToQtWidget->insert(IDC_SPIN_RECORDER_COUNT, mfc7);

   // CONTROL "Re-initialize settings upon stopping", IDC_CHECK_RECORDER_RESET, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 17, 62, 127, 10
	CButton* mfc8 = new CButton(parent);
	CRect r8(CPoint(17, 62), CSize(127, 10));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Re-initialize settings upon stopping"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r8, parent, IDC_CHECK_RECORDER_RESET);
	mfcToQtWidget->insert(IDC_CHECK_RECORDER_RESET, mfc8);

   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,53,85,50,14
	CButton* mfc9 = new CButton(parent);
	CRect r9(CPoint(53,85),CSize(50,14));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r9,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc9);

   // PUSHBUTTON "Cancel",IDCANCEL,111,85,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc10 = new CButton(parent);
	CRect r10(CPoint(111,85),CSize(50,14));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r10,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc10);

   // END
}


void qtMfcInitDialogResource_IDD_CONFIG_VERSION(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_CONFIG_VERSION DIALOGEX 0, 0, 280, 167
	CRect rect(CPoint(0,0),CSize(280,167));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Version"
	parent->SetWindowText("Version");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "FamiTracker Version",IDC_STATIC,7,7,266,35
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(266,35));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("FamiTracker Version"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Compatibility Settings",IDC_STATIC,7,46,148,50
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7,46),CSize(148,50));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Compatibility Settings"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // GROUPBOX "Module Error Level",IDC_STATIC,7,100,148,60
	CButton* mfc2 = new CButton(parent);
	CRect r2(CPoint(7,100),CSize(148,60));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Module Error Level"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_COMBO_VERSION_SELECT,13,20,253,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc4 = new CComboBox(parent);
	CRect r4(CPoint(13,20),CSize(253,30));
	parent->MapDialogRect(&r4);
	mfc4->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r4,parent,IDC_COMBO_VERSION_SELECT);
	mfcToQtWidget->insert(IDC_COMBO_VERSION_SELECT,mfc4);

   // CONTROL "Disallow future features while loading", IDC_CHECK_VERSION_LOAD, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 16, 58, 135, 10
	CButton* mfc6 = new CButton(parent);
	CRect r6(CPoint(16, 58), CSize(135, 10));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Disallow future features while loading"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r6, parent, IDC_CHECK_VERSION_LOAD);
	mfcToQtWidget->insert(IDC_CHECK_VERSION_LOAD, mfc6);

   // CONTROL "Disable future features in tracker", IDC_CHECK_VERSION_EDIT, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 16, 69, 122, 10
	CButton* mfc7 = new CButton(parent);
	CRect r7(CPoint(16, 69), CSize(122, 10));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("Disable future features in tracker"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r7, parent, IDC_CHECK_VERSION_EDIT);
	mfcToQtWidget->insert(IDC_CHECK_VERSION_EDIT, mfc7);

   // CONTROL "Save in target FTM format version", IDC_CHECK_VERSION_SAVE, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 16, 80, 125, 10
	CButton* mfc8 = new CButton(parent);
	CRect r8(CPoint(16, 80), CSize(125, 10));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Save in target FTM format version"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r8, parent, IDC_CHECK_VERSION_SAVE);
	mfcToQtWidget->insert(IDC_CHECK_VERSION_SAVE, mfc8);

   // CONTROL "", IDC_SLIDER_VERSION_ERRORLEVEL, "msctls_trackbar32", WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, 12, 108, 26, 48
	CSliderCtrl* mfc10 = new CSliderCtrl(parent);
	CRect r10(CPoint(12, 108), CSize(26, 48));
	parent->MapDialogRect(&r10);
	mfc10->Create(WS_VISIBLE|WS_BORDER|TBS_AUTOTICKS|TBS_VERT|TBS_BOTH|WS_TABSTOP, r10, parent, IDC_SLIDER_VERSION_ERRORLEVEL);
	mfcToQtWidget->insert(IDC_SLIDER_VERSION_ERRORLEVEL, mfc10);

   // LTEXT "Description",IDC_STATIC_VERSION_ERROR,45,112,98,41
	CStatic* mfc11 = new CStatic(parent);
	CRect r11(CPoint(45,112),CSize(98,41));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T("Description"),WS_VISIBLE|WS_BORDER,r11,parent,IDC_STATIC_VERSION_ERROR);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Technical information about the current version setting goes here.",IDC_STATIC,183,88,72,42
	CStatic* mfc12 = new CStatic(parent);
	CRect r12(CPoint(183,88),CSize(72,42));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T("Technical information about the current version setting goes here."),WS_VISIBLE|WS_BORDER,r12,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // END
}


void qtMfcInitDialogResource_IDD_TRANSPOSE(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_TRANSPOSE DIALOGEX 0, 0, 217, 226
	CRect rect(CPoint(0,0),CSize(217,226));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Transpose"
	parent->SetWindowText("Transpose");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Transpose",IDC_STATIC,7,7,203,193
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,7),CSize(203,193));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Transpose"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Semitones:",IDC_STATIC,16,20,36,8
	CStatic* mfc2 = new CStatic(parent);
	CRect r2(CPoint(16,20),CSize(36,8));
	parent->MapDialogRect(&r2);
	mfc2->Create(_T("Semitones:"),WS_VISIBLE|WS_BORDER,r2,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // EDITTEXT IDC_EDIT_TRSP_SEMITONE,56,18,40,14,WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER
	CEdit* mfc3 = new CEdit(parent);
	CRect r3(CPoint(56,18),CSize(40,14));
	parent->MapDialogRect(&r3);
	mfc3->Create(WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|ES_NUMBER,r3,parent,IDC_EDIT_TRSP_SEMITONE);
	mfcToQtWidget->insert(IDC_EDIT_TRSP_SEMITONE,mfc3);

   // CONTROL "", IDC_SPIN_TRSP_SEMITONE, "msctls_updown32", WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, 85, 18, 11, 14
	CSpinButtonCtrl* mfc4 = new CSpinButtonCtrl(parent);
	CRect r4(CPoint(85, 18), CSize(11, 14));
	parent->MapDialogRect(&r4);
	mfc4->Create(WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|UDS_ALIGNRIGHT|UDS_AUTOBUDDY|UDS_ARROWKEYS, r4, parent, IDC_SPIN_TRSP_SEMITONE);
	mfcToQtWidget->insert(IDC_SPIN_TRSP_SEMITONE, mfc4);

   // CONTROL "Raise", IDC_RADIO_SEMITONE_INC, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON|WS_GROUP, 103, 20, 33, 10
	CButton* mfc5 = new CButton(parent);
	CRect r5(CPoint(103, 20), CSize(33, 10));
	parent->MapDialogRect(&r5);
	mfc5->Create(_T("Raise"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON|WS_GROUP, r5, parent, IDC_RADIO_SEMITONE_INC);
	mfcToQtWidget->insert(IDC_RADIO_SEMITONE_INC, mfc5);

   // CONTROL "Lower", IDC_RADIO_SEMITONE_DEC, "Button", WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, 138, 20, 32, 10
	CButton* mfc6 = new CButton(parent);
	CRect r6(CPoint(138, 20), CSize(32, 10));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Lower"), WS_VISIBLE|WS_BORDER|BS_AUTORADIOBUTTON, r6, parent, IDC_RADIO_SEMITONE_DEC);
	mfcToQtWidget->insert(IDC_RADIO_SEMITONE_DEC, mfc6);

   // LTEXT "Exclude these instruments:",IDC_STATIC,15,52,88,8
	CStatic* mfc7 = new CStatic(parent);
	CRect r7(CPoint(15,52),CSize(88,8));
	parent->MapDialogRect(&r7);
	mfc7->Create(_T("Exclude these instruments:"),WS_VISIBLE|WS_BORDER,r7,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // LTEXT "Warning: Resets undo history!",IDC_STATIC,15,185,99,8
	CStatic* mfc8 = new CStatic(parent);
	CRect r8(CPoint(15,185),CSize(99,8));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Warning: Resets undo history!"),WS_VISIBLE|WS_BORDER,r8,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,106,205,50,14
	CButton* mfc9 = new CButton(parent);
	CRect r9(CPoint(106,205),CSize(50,14));
	parent->MapDialogRect(&r9);
	mfc9->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r9,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc9);

   // PUSHBUTTON "Cancel",IDCANCEL,160,205,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc10 = new CButton(parent);
	CRect r10(CPoint(160,205),CSize(50,14));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r10,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc10);

   // CONTROL "Transpose all tracks", IDC_CHECK_TRSP_ALL, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 15, 36, 79, 10
	CButton* mfc11 = new CButton(parent);
	CRect r11(CPoint(15, 36), CSize(79, 10));
	parent->MapDialogRect(&r11);
	mfc11->Create(_T("Transpose all tracks"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r11, parent, IDC_CHECK_TRSP_ALL);
	mfcToQtWidget->insert(IDC_CHECK_TRSP_ALL, mfc11);

   // PUSHBUTTON "Reverse",IDC_BUTTON_TRSP_REVERSE,47,166,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc12 = new CButton(parent);
	CRect r12(CPoint(47,166),CSize(50,14));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T("Reverse"),WS_VISIBLE|WS_BORDER,r12,parent,IDC_BUTTON_TRSP_REVERSE);
	mfcToQtWidget->insert(IDC_BUTTON_TRSP_REVERSE,mfc12);

   // PUSHBUTTON "Clear All",IDC_BUTTON_TRSP_CLEAR,120,166,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc13 = new CButton(parent);
	CRect r13(CPoint(120,166),CSize(50,14));
	parent->MapDialogRect(&r13);
	mfc13->Create(_T("Clear All"),WS_VISIBLE|WS_BORDER,r13,parent,IDC_BUTTON_TRSP_CLEAR);
	mfcToQtWidget->insert(IDC_BUTTON_TRSP_CLEAR,mfc13);

   // END
}


void qtMfcInitDialogResource_IDD_FINDRESULTS(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_FINDRESULTS DIALOGEX 0, 0, 331, 192
	CRect rect(CPoint(0,0),CSize(331,192));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Find Results"
	parent->SetWindowText("Find Results");

   // STYLE DS_SETFONT|DS_FIXEDSYS|DS_CENTER|WS_POPUP|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // CONTROL "", IDC_LIST_FINDRESULTS, "SysListView32", WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_ALIGNLEFT|WS_BORDER|WS_TABSTOP, 7, 7, 317, 163
	CListCtrl* mfc0 = new CListCtrl(parent);
	CRect r0(CPoint(7, 7), CSize(317, 163));
	parent->MapDialogRect(&r0);
	mfc0->Create(WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_ALIGNLEFT|WS_BORDER|WS_TABSTOP, r0, parent, IDC_LIST_FINDRESULTS);
	mfcToQtWidget->insert(IDC_LIST_FINDRESULTS, mfc0);

   // LTEXT "0 results found.",IDC_STATIC_FINDRESULT_COUNT,7,176,78,8
	CStatic* mfc1 = new CStatic(parent);
	CRect r1(CPoint(7,176),CSize(78,8));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("0 results found."),WS_VISIBLE|WS_BORDER,r1,parent,IDC_STATIC_FINDRESULT_COUNT);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // END
}


void qtMfcInitDialogResource_IDD_SPLIT_KEYBOARD(CDialog* parent)
{
	QHash<int,CWnd*>* mfcToQtWidget = parent->mfcToQtWidgetMap();

	// IDD_SPLIT_KEYBOARD DIALOGEX 0, 0, 135, 133
	CRect rect(CPoint(0,0),CSize(135,133));
	parent->MapDialogRect(&rect);
	parent->setFixedSize(rect.Width(),rect.Height());

   // CAPTION "Split Keyboard Settings"
	parent->SetWindowText("Split Keyboard Settings");

   // STYLE DS_SETFONT|DS_MODALFRAME|DS_FIXEDSYS|WS_POPUP|WS_CAPTION|WS_SYSMENU
	parent->toQWidget()->setWindowFlags(parent->toQWidget()->windowFlags()|Qt::Popup|Qt::WindowTitleHint|Qt::WindowSystemMenuHint);


   // BEGIN
   // GROUPBOX "Split keyboard options",IDC_STATIC,7,20,121,87
	CButton* mfc0 = new CButton(parent);
	CRect r0(CPoint(7,20),CSize(121,87));
	parent->MapDialogRect(&r0);
	mfc0->Create(_T("Split keyboard options"),BS_GROUPBOX|WS_VISIBLE|WS_BORDER,r0,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // CONTROL "Enable split keyboard", IDC_CHECK_SPLIT_ENABLE, "Button", WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, 7, 7, 84, 10
	CButton* mfc1 = new CButton(parent);
	CRect r1(CPoint(7, 7), CSize(84, 10));
	parent->MapDialogRect(&r1);
	mfc1->Create(_T("Enable split keyboard"), WS_VISIBLE|WS_BORDER|BS_AUTOCHECKBOX|WS_TABSTOP, r1, parent, IDC_CHECK_SPLIT_ENABLE);
	mfcToQtWidget->insert(IDC_CHECK_SPLIT_ENABLE, mfc1);

   // RTEXT "Split point:",IDC_STATIC,16,35,35,8
	CStatic* mfc3 = new CStatic(parent);
	CRect r3(CPoint(16,35),CSize(35,8));
	parent->MapDialogRect(&r3);
	mfc3->Create(_T("Split point:"),WS_VISIBLE|WS_BORDER,r3,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_COMBO_SPLIT_NOTE,55,33,37,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc4 = new CComboBox(parent);
	CRect r4(CPoint(55,33),CSize(37,30));
	parent->MapDialogRect(&r4);
	mfc4->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r4,parent,IDC_COMBO_SPLIT_NOTE);
	mfcToQtWidget->insert(IDC_COMBO_SPLIT_NOTE,mfc4);

   // COMBOBOX IDC_COMBO_SPLIT_OCTAVE,99,33,21,15,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc5 = new CComboBox(parent);
	CRect r5(CPoint(99,33),CSize(21,15));
	parent->MapDialogRect(&r5);
	mfc5->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r5,parent,IDC_COMBO_SPLIT_OCTAVE);
	mfcToQtWidget->insert(IDC_COMBO_SPLIT_OCTAVE,mfc5);

   // RTEXT "Channel:",IDC_STATIC,21,53,30,8
	CStatic* mfc6 = new CStatic(parent);
	CRect r6(CPoint(21,53),CSize(30,8));
	parent->MapDialogRect(&r6);
	mfc6->Create(_T("Channel:"),WS_VISIBLE|WS_BORDER,r6,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_COMBO_SPLIT_CHAN,55,51,65,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc7 = new CComboBox(parent);
	CRect r7(CPoint(55,51),CSize(65,30));
	parent->MapDialogRect(&r7);
	mfc7->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r7,parent,IDC_COMBO_SPLIT_CHAN);
	mfcToQtWidget->insert(IDC_COMBO_SPLIT_CHAN,mfc7);

   // RTEXT "Instrument:",IDC_STATIC,12,71,39,8
	CStatic* mfc8 = new CStatic(parent);
	CRect r8(CPoint(12,71),CSize(39,8));
	parent->MapDialogRect(&r8);
	mfc8->Create(_T("Instrument:"),WS_VISIBLE|WS_BORDER,r8,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_COMBO_SPLIT_INST,55,69,65,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc9 = new CComboBox(parent);
	CRect r9(CPoint(55,69),CSize(65,30));
	parent->MapDialogRect(&r9);
	mfc9->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r9,parent,IDC_COMBO_SPLIT_INST);
	mfcToQtWidget->insert(IDC_COMBO_SPLIT_INST,mfc9);

   // RTEXT "Transpose:",IDC_STATIC,14,89,37,8
	CStatic* mfc10 = new CStatic(parent);
	CRect r10(CPoint(14,89),CSize(37,8));
	parent->MapDialogRect(&r10);
	mfc10->Create(_T("Transpose:"),WS_VISIBLE|WS_BORDER,r10,parent,IDC_STATIC);
	// IDC_STATIC do not get added to MFC-to-Qt map.

   // COMBOBOX IDC_COMBO_SPLIT_TRSP,55,87,65,30,WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP
	CComboBox* mfc11 = new CComboBox(parent);
	CRect r11(CPoint(55,87),CSize(65,30));
	parent->MapDialogRect(&r11);
	mfc11->Create(WS_VISIBLE|WS_BORDER|CBS_DROPDOWNLIST|WS_VSCROLL|WS_TABSTOP,r11,parent,IDC_COMBO_SPLIT_TRSP);
	mfcToQtWidget->insert(IDC_COMBO_SPLIT_TRSP,mfc11);

   // DEFPUSHBUTTON "OK",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,13,112,50,14
	CButton* mfc12 = new CButton(parent);
	CRect r12(CPoint(13,112),CSize(50,14));
	parent->MapDialogRect(&r12);
	mfc12->Create(_T("OK"),BS_DEFPUSHBUTTON|WS_VISIBLE|WS_BORDER,r12,parent,IDOK);
	mfcToQtWidget->insert(IDOK,mfc12);

   // PUSHBUTTON "Cancel",IDCANCEL,71,112,50,14,WS_VISIBLE|WS_BORDER
	CButton* mfc13 = new CButton(parent);
	CRect r13(CPoint(71,112),CSize(50,14));
	parent->MapDialogRect(&r13);
	mfc13->Create(_T("Cancel"),WS_VISIBLE|WS_BORDER,r13,parent,IDCANCEL);
	mfcToQtWidget->insert(IDCANCEL,mfc13);

   // END
}


void qtMfcInitDialogResource(UINT dlgID,CDialog* parent)
{
	switch ( dlgID )
	{
      case IDD_ABOUTBOX:
			qtMfcInitDialogResource_IDD_ABOUTBOX(parent);
			break;

      case IDD_MAINFRAME:
			qtMfcInitDialogResource_IDD_MAINFRAME(parent);
			break;

      case IDD_PCMIMPORT:
			qtMfcInitDialogResource_IDD_PCMIMPORT(parent);
			break;

      case IDD_INSTRUMENT_INTERNAL:
			qtMfcInitDialogResource_IDD_INSTRUMENT_INTERNAL(parent);
			break;

      case IDD_INSTRUMENT_DPCM:
			qtMfcInitDialogResource_IDD_INSTRUMENT_DPCM(parent);
			break;

      case IDD_INSTRUMENT:
			qtMfcInitDialogResource_IDD_INSTRUMENT(parent);
			break;

      case IDD_CONFIG_APPEARANCE:
			qtMfcInitDialogResource_IDD_CONFIG_APPEARANCE(parent);
			break;

      case IDD_CONFIG_GENERAL:
			qtMfcInitDialogResource_IDD_CONFIG_GENERAL(parent);
			break;

      case IDD_CONFIG_MIDI:
			qtMfcInitDialogResource_IDD_CONFIG_MIDI(parent);
			break;

      case IDD_CONFIG_SOUND:
			qtMfcInitDialogResource_IDD_CONFIG_SOUND(parent);
			break;

      case IDD_CONFIG_SHORTCUTS:
			qtMfcInitDialogResource_IDD_CONFIG_SHORTCUTS(parent);
			break;

      case IDD_OCTAVE:
			qtMfcInitDialogResource_IDD_OCTAVE(parent);
			break;

      case IDD_EXPORT:
			qtMfcInitDialogResource_IDD_EXPORT(parent);
			break;

      case IDD_INSTRUMENT_VRC7:
			qtMfcInitDialogResource_IDD_INSTRUMENT_VRC7(parent);
			break;

      case IDD_CREATEWAV:
			qtMfcInitDialogResource_IDD_CREATEWAV(parent);
			break;

      case IDD_MAINBAR:
			qtMfcInitDialogResource_IDD_MAINBAR(parent);
			break;

      case IDD_INSTRUMENT_FDS:
			qtMfcInitDialogResource_IDD_INSTRUMENT_FDS(parent);
			break;

      case IDD_FRAMECONTROLS:
			qtMfcInitDialogResource_IDD_FRAMECONTROLS(parent);
			break;

      case IDD_INSTRUMENT_FDS_ENVELOPE:
			qtMfcInitDialogResource_IDD_INSTRUMENT_FDS_ENVELOPE(parent);
			break;

      case IDD_CHANNELS:
			qtMfcInitDialogResource_IDD_CHANNELS(parent);
			break;

      case IDD_HEADER:
			qtMfcInitDialogResource_IDD_HEADER(parent);
			break;

      case IDD_COMMENTS:
			qtMfcInitDialogResource_IDD_COMMENTS(parent);
			break;

      case IDD_CONFIG_MIXER:
			qtMfcInitDialogResource_IDD_CONFIG_MIXER(parent);
			break;

      case IDD_INSTRUMENT_N163_WAVE:
			qtMfcInitDialogResource_IDD_INSTRUMENT_N163_WAVE(parent);
			break;

      case IDD_IMPORT:
			qtMfcInitDialogResource_IDD_IMPORT(parent);
			break;

      case IDD_PERFORMANCE:
			qtMfcInitDialogResource_IDD_PERFORMANCE(parent);
			break;

      case IDD_SPEED:
			qtMfcInitDialogResource_IDD_SPEED(parent);
			break;

      case IDD_PROPERTIES:
			qtMfcInitDialogResource_IDD_PROPERTIES(parent);
			break;

      case IDD_WAVE_PROGRESS:
			qtMfcInitDialogResource_IDD_WAVE_PROGRESS(parent);
			break;

      case IDD_SAMPLE_EDITOR:
			qtMfcInitDialogResource_IDD_SAMPLE_EDITOR(parent);
			break;

      case IDD_DETUNE:
			qtMfcInitDialogResource_IDD_DETUNE(parent);
			break;

      case IDD_GROOVE:
			qtMfcInitDialogResource_IDD_GROOVE(parent);
			break;

      case IDD_FIND:
			qtMfcInitDialogResource_IDD_FIND(parent);
			break;

      case IDD_STRETCH:
			qtMfcInitDialogResource_IDD_STRETCH(parent);
			break;

      case IDD_BOOKMARKS:
			qtMfcInitDialogResource_IDD_BOOKMARKS(parent);
			break;

      case IDD_GOTO:
			qtMfcInitDialogResource_IDD_GOTO(parent);
			break;

      case IDD_SWAP:
			qtMfcInitDialogResource_IDD_SWAP(parent);
			break;

      case IDD_RECORD_SETTINGS:
			qtMfcInitDialogResource_IDD_RECORD_SETTINGS(parent);
			break;

      case IDD_CONFIG_VERSION:
			qtMfcInitDialogResource_IDD_CONFIG_VERSION(parent);
			break;

      case IDD_TRANSPOSE:
			qtMfcInitDialogResource_IDD_TRANSPOSE(parent);
			break;

      case IDD_FINDRESULTS:
			qtMfcInitDialogResource_IDD_FINDRESULTS(parent);
			break;

      case IDD_SPLIT_KEYBOARD:
			qtMfcInitDialogResource_IDD_SPLIT_KEYBOARD(parent);
			break;


	case 0:
		// CP: Allow blank dialogs.
		break;
	default:
		qFatal("dialog resource not implemented...");
	}
}


void qtMfcInitToolBarResource_IDR_MAINFRAME(UINT dlgID,CToolBar* parent)
{
	QImage toolBarImage = qtMfcBitmapResource(IDR_MAINFRAME)->toQPixmap()->toImage();
	QToolBar* toolBar = dynamic_cast<QToolBar*>(parent->toQWidget());
	QPixmap toolBarActionPixmap;
	QAction* toolBarAction;
	QRgb pixel00;
	int x,y;

	toolBarImage = toolBarImage.convertToFormat(QImage::Format_ARGB32);
	pixel00 = toolBarImage.pixel(0,0);
	for ( y = 0; y < toolBarImage.height(); y++ )
	{
		for ( x = 0; x < toolBarImage.width(); x++ )
		{
			if ( toolBarImage.pixel(x,y) == pixel00 )
			{
				toolBarImage.setPixel(x,y,qRgba(0,0,0,0));
			}
		}
	}

	// IDR_MAINFRAME TOOLBAR 16, 15
		toolBar->setIconSize(QSize(16,15));
	// BEGIN
   // BUTTON ID_FILE_NEW
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(0*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_FILE_NEW);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_FILE_OPEN
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(1*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_FILE_OPEN);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_FILE_SAVE
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(2*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_FILE_SAVE);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // SEPARATOR
	toolBar->addSeparator();

   // BUTTON ID_EDIT_CUT
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(3*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_EDIT_CUT);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_EDIT_COPY
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(4*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_EDIT_COPY);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_EDIT_PASTE
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(5*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_EDIT_PASTE);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // SEPARATOR
	toolBar->addSeparator();

   // BUTTON ID_APP_ABOUT
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(6*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_APP_ABOUT);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_CONTEXT_HELP
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(7*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_CONTEXT_HELP);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // SEPARATOR
	toolBar->addSeparator();

   // BUTTON ID_MODULE_INSERTFRAME
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(8*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_MODULE_INSERTFRAME);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_MODULE_REMOVEFRAME
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(9*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_MODULE_REMOVEFRAME);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_MODULE_MOVEFRAMEDOWN
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(10*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_MODULE_MOVEFRAMEDOWN);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_MODULE_MOVEFRAMEUP
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(11*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_MODULE_MOVEFRAMEUP);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_MODULE_DUPLICATEFRAME
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(12*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_MODULE_DUPLICATEFRAME);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // SEPARATOR
	toolBar->addSeparator();

   // BUTTON ID_MODULE_MODULEPROPERTIES
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(13*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_MODULE_MODULEPROPERTIES);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // SEPARATOR
	toolBar->addSeparator();

   // BUTTON ID_TRACKER_PLAY
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(14*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_TRACKER_PLAY);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_TRACKER_PLAYPATTERN
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(15*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_TRACKER_PLAYPATTERN);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_TRACKER_STOP
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(16*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_TRACKER_STOP);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_TRACKER_EDIT
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(17*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_TRACKER_EDIT);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // SEPARATOR
	toolBar->addSeparator();

   // BUTTON ID_PREV_SONG
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(18*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_PREV_SONG);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_NEXT_SONG
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(19*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_NEXT_SONG);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // SEPARATOR
	toolBar->addSeparator();

   // BUTTON ID_FILE_GENERALSETTINGS
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(20*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_FILE_GENERALSETTINGS);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // SEPARATOR
	toolBar->addSeparator();

   // BUTTON ID_FILE_CREATE_NSF
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(21*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_FILE_CREATE_NSF);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // END

	for ( x = 0; x < toolBar->actions().count(); x++ )
	{
		CString toolTipCString = qtMfcStringResource(toolBar->actions().at(x)->data().toInt());
		QString toolTip = toolTipCString;
		if ( toolTip.indexOf('\n') >= 0 )
		{
			toolBar->actions().value(x)->setToolTip(toolTip.right(toolTip.length()-toolTip.indexOf('\n')-1));
		}
	}
}


void qtMfcInitToolBarResource_IDR_INSTRUMENT_TOOLBAR(UINT dlgID,CToolBar* parent)
{
	QImage toolBarImage = qtMfcBitmapResource(IDR_INSTRUMENT_TOOLBAR)->toQPixmap()->toImage();
	QToolBar* toolBar = dynamic_cast<QToolBar*>(parent->toQWidget());
	QPixmap toolBarActionPixmap;
	QAction* toolBarAction;
	QRgb pixel00;
	int x,y;

	toolBarImage = toolBarImage.convertToFormat(QImage::Format_ARGB32);
	pixel00 = toolBarImage.pixel(0,0);
	for ( y = 0; y < toolBarImage.height(); y++ )
	{
		for ( x = 0; x < toolBarImage.width(); x++ )
		{
			if ( toolBarImage.pixel(x,y) == pixel00 )
			{
				toolBarImage.setPixel(x,y,qRgba(0,0,0,0));
			}
		}
	}

	// IDR_INSTRUMENT_TOOLBAR TOOLBAR 16, 15
		toolBar->setIconSize(QSize(16,15));
	// BEGIN
   // BUTTON ID_INSTRUMENT_NEW
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(0*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_INSTRUMENT_NEW);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_INSTRUMENT_REMOVE
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(1*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_INSTRUMENT_REMOVE);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_INSTRUMENT_CLONE
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(2*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_INSTRUMENT_CLONE);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // SEPARATOR
	toolBar->addSeparator();

   // BUTTON ID_INSTRUMENT_LOAD
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(3*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_INSTRUMENT_LOAD);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // BUTTON ID_INSTRUMENT_SAVE
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(4*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_INSTRUMENT_SAVE);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // SEPARATOR
	toolBar->addSeparator();

   // BUTTON ID_INSTRUMENT_EDIT
	toolBarAction = new QAction(parent);
	toolBarActionPixmap = QPixmap::fromImage(toolBarImage.copy(5*16,0,16,15));
	toolBarAction->setIcon(QIcon(toolBarActionPixmap));
	toolBarAction->setData(ID_INSTRUMENT_EDIT);
	QObject::connect(toolBarAction,SIGNAL(triggered()),parent,SLOT(toolBarAction_triggered()));
	toolBar->addAction(toolBarAction);

   // END

	for ( x = 0; x < toolBar->actions().count(); x++ )
	{
		CString toolTipCString = qtMfcStringResource(toolBar->actions().at(x)->data().toInt());
		QString toolTip = toolTipCString;
		if ( toolTip.indexOf('\n') >= 0 )
		{
			toolBar->actions().value(x)->setToolTip(toolTip.right(toolTip.length()-toolTip.indexOf('\n')-1));
		}
	}
}


void qtMfcInitToolBarResource(UINT dlgID,CToolBar* parent)
{
	switch ( dlgID )
	{
   case IDR_MAINFRAME:
		qtMfcInitToolBarResource_IDR_MAINFRAME(dlgID,parent);
		break;

   case IDR_INSTRUMENT_TOOLBAR:
		qtMfcInitToolBarResource_IDR_INSTRUMENT_TOOLBAR(dlgID,parent);
		break;

   }
}


void qtMfcInit(QMainWindow* parent)
{
	// Hook Qt to this MFC app...
	AfxGetApp()->qtMainWindow = parent;
	AfxGetApp()->moveToThread(QApplication::instance()->thread());

	qtMfcInitStringResources();
	qtMfcInitBitmapResources();
	qtInitIconResources();
}

