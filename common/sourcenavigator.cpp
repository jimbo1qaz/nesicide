#include "sourcenavigator.h"
#include "ui_sourcenavigator.h"

#include "main.h"

#include "ccc65interface.h"

SourceNavigator::SourceNavigator(QTabWidget* pTarget,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SourceNavigator)
{
    ui->setupUi(this);

    ui->files->setEnabled(false);
    ui->symbols->setEnabled(false);

    QObject::connect(compiler,SIGNAL(compileDone(bool)),this,SLOT(compiler_compileDone(bool)));
    QObject::connect(emulator,SIGNAL(cartridgeLoaded()),this,SLOT(emulator_cartridgeLoaded()));
    QObject::connect(emulator,SIGNAL(emulatorPaused(bool)),this,SLOT(emulator_emulatorPaused(bool)));
    QObject::connect(emulator,SIGNAL(emulatorReset()),this,SLOT(emulator_emulatorPaused()));
    QObject::connect(breakpointWatcher,SIGNAL(breakpointHit()),this,SLOT(emulator_emulatorPaused()));

    m_pTarget = pTarget;
}

SourceNavigator::~SourceNavigator()
{
    delete ui;
}

void SourceNavigator::shutdown()
{
   ui->files->clear();
   ui->symbols->clear();
   ui->files->setEnabled(false);
   ui->symbols->setEnabled(false);
}

void SourceNavigator::updateFiles(bool doIt)
{
   ui->files->clear();
   ui->symbols->clear();

   if ( doIt )
   {
      QStringList files = CCC65Interface::getSourceFiles();
      ui->files->addItems(files);
      if ( files.count() )
      {
         updateSymbolsForFile(files.at(0));
      }
   }
   else
   {
      ui->files->clear();
      ui->symbols->clear();
   }

   ui->files->setEnabled(doIt);
   ui->symbols->setEnabled(doIt);
}

void SourceNavigator::updateSymbolsForFile(QString file)
{
   QStringList   symbols;

   blockSignals(true);
   ui->symbols->clear();

   symbols = CCC65Interface::getSymbolsForSourceFile(file);
   ui->symbols->addItems(symbols);

   blockSignals(false);
}

void SourceNavigator::emulator_cartridgeLoaded()
{
   blockSignals(true);
   updateFiles(true);
   blockSignals(false);
}

void SourceNavigator::emulator_emulatorPaused(bool show)
{
   IProjectTreeViewItemIterator iter(nesicideProject->getProject()->getSources());
   CSourceItem* pSource;
   QString file;
   int   linenumber;
   unsigned int addr;
   unsigned int absAddr;
   bool found = false;

   if ( show )
   {
      blockSignals(true);
      addr = nesGetCPUProgramCounterOfLastSync();
      absAddr = nesGetAbsoluteAddressFromAddress(addr);
      file = CCC65Interface::getSourceFileFromAbsoluteAddress(addr,absAddr);
      if ( !file.isEmpty() )
      {
         linenumber = CCC65Interface::getSourceLineFromAbsoluteAddress(addr,absAddr);
         ui->files->setCurrentIndex(ui->files->findText(file));
         on_files_activated(file);

         while ( iter.current() )
         {
            pSource = dynamic_cast<CSourceItem*>(iter.current());
            if ( pSource &&
                 (pSource->path() == file) )
            {
               pSource->editor()->selectLine(linenumber);
               found = true;
            }
            else if ( pSource && pSource->editor() )
            {
               pSource->editor()->selectLine(-1);
            }
            iter.next();
         }

         // Now search through open files that are not part of the project.
         for ( int tab = 0; tab < m_pTarget->count(); tab++ )
         {
            CodeEditorForm* editor = dynamic_cast<CodeEditorForm*>(m_pTarget->widget(tab));
            if ( editor &&
                 (editor->fileName() == file) )
            {
               editor->selectLine(linenumber);
            }
            else if ( editor )
            {
               editor->selectLine(-1);
            }
         }
      }
      blockSignals(false);
   }
}

void SourceNavigator::compiler_compileDone(bool bOk)
{
   blockSignals(true);
   updateFiles(bOk);
   blockSignals(false);
}

void SourceNavigator::projectTreeView_openItem(IProjectTreeViewItem* item)
{
   CProjectBase* pItem = dynamic_cast<CProjectBase*>(item);

   if ( pItem )
   {
      blockSignals(true);

      ui->files->setCurrentIndex(ui->files->findText(pItem->path()));
      ui->symbols->clear();

      updateSymbolsForFile(pItem->path());

      blockSignals(false);
   }
}

void SourceNavigator::on_files_activated(QString file)
{
   IProjectTreeViewItemIterator iter(nesicideProject->getProject()->getSources());
   CSourceItem* pSource;
   bool found = false;

   while ( iter.current() )
   {
      pSource = dynamic_cast<CSourceItem*>(iter.current());
      if ( pSource )
      {
         if ( pSource->path() == file )
         {
            pSource->openItemEvent(m_pTarget);
            updateSymbolsForFile(file);
            emit fileNavigator_fileChanged(ui->files->currentText());
            found = true;
            break;
         }
      }
      iter.next();
   }

   if ( !found )
   {
      // If we got here the file is not part of the project...lets open it anyway,
      // if it's not already open.
      int foundIdx = -1;
      for ( int tab = 0; tab < m_pTarget->count(); tab++ )
      {
         CodeEditorForm* editor = dynamic_cast<CodeEditorForm*>(m_pTarget->widget(tab));
         if ( editor &&
              editor->fileName() == file )
         {
            found = true;
            foundIdx = tab;
            emit fileNavigator_fileChanged(ui->files->currentText());
            break;
         }
      }
      if ( !found )
      {
         QDir dir(QDir::currentPath());
         QString fileName = dir.toNativeSeparators(dir.filePath(file));
         QFile fileIn(fileName);

         if ( fileIn.exists() && fileIn.open(QIODevice::ReadOnly|QIODevice::Text) )
         {
            CodeEditorForm* editor = new CodeEditorForm(file,QString(fileIn.readAll()));

            fileIn.close();

            m_pTarget->addTab(editor, file);
            m_pTarget->setCurrentWidget(editor);

            emit fileNavigator_fileChanged(ui->files->currentText());
         }
         else
         {
            QMessageBox::information(0,"Locate Source","I am unable to find:\n\n"+file+"\n\nThis typically occurs if the project output files (*.nes, *.dbg) are moved away from the folder containing their parent project file (*.nesproject).");
         }
      }
      else
      {
         m_pTarget->setCurrentIndex(foundIdx);
         emit fileNavigator_fileChanged(ui->files->currentText());
      }
   }
}

void SourceNavigator::on_symbols_activated(QString symbol)
{
#if 0
   IProjectTreeViewItemIterator iter(nesicideProject->getProject()->getSources());
   CSourceItem* pSource;
   int          linenumber = pasm_get_symbol_linenum_by_name(symbol.toAscii().constData());

   while ( iter.current() )
   {
      pSource = dynamic_cast<CSourceItem*>(iter.current());
      if ( pSource &&
           (pSource->path() == ui->files->currentText()) )
      {
         pSource->openItemEvent(m_pTarget);
         pSource->editor()->selectLine(linenumber);
         emit fileNavigator_symbolChanged(ui->symbols->currentText(),ui->symbols->currentText(),linenumber);
         break;
      }
      iter.next();
   }
#endif
}