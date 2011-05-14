#ifndef NAMETABLEVISUALIZERDOCKWIDGET_H
#define NAMETABLEVISUALIZERDOCKWIDGET_H

#include "cnametablepreviewrenderer.h"

#include <QDockWidget>

namespace Ui {
   class NameTableVisualizerDockWidget;
}

class NameTableVisualizerDockWidget : public QDockWidget
{
   Q_OBJECT

public:
   explicit NameTableVisualizerDockWidget(QWidget *parent = 0);
   ~NameTableVisualizerDockWidget();

protected:
   void showEvent(QShowEvent* event);
   void hideEvent(QHideEvent* event);
   void changeEvent(QEvent* e);
   void resizeEvent(QResizeEvent* event);
   CNameTablePreviewRenderer* renderer;
   void updateScrollbars();

public slots:
   void renderData();

private slots:
   void on_showVisible_toggled(bool checked);
   void on_verticalScrollBar_valueChanged(int value);
   void on_horizontalScrollBar_valueChanged(int value);
   void on_zoomSlider_valueChanged(int value);
   
private:
   Ui::NameTableVisualizerDockWidget *ui;
   char* imgData;
};

#endif // NAMETABLEVISUALIZERDOCKWIDGET_H

