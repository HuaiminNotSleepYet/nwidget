#ifndef NWIDGET_H
#define NWIDGET_H

// Since QT is configurable, including all header files at once would reduce its versatility.
// Placing nwidget.h after QT header will automatically import the corresponding header files:
//
//   #include <QPushButton>
//   #include <QSlider>
//   #include ...
//   #include <nwidget/nwidget.h>

#include "object.h"

#ifdef QABSTRACTBUTTON_H
#include "abstractbutton.h"
#endif
#ifdef QABSTRACTITEMVIEW_H
#include "abstractitemview.h"
#endif
#ifdef QABSTRACTSCROLLAREA_H
#include "abstractscrollarea.h"
#endif
#ifdef QABSTRACTSLIDER_H
#include "abstractslider.h"
#endif
#ifdef QABSTRACTSPINBOX_H
#include "abstractspinbox.h"
#endif
#ifdef QACTION_H
#include "action.h"
#endif
#ifdef QBOXLAYOUT_H
#include "boxlayout.h"
#endif
#ifdef QCHECKBOX_H
#include "checkbox.h"
#endif
#ifdef QCOMBOBOX_H
#include "combobox.h"
#endif
#ifdef QCOMMANDLINKBUTTON_H
#include "commandlinkbutton.h"
#endif
#ifdef QDATETIMEEDIT_H
#include "datetimeedit.h"
#endif
#ifdef QDIAL_H
#include "dial.h"
#endif
#ifdef QDIALOGBUTTONBOX_H
#include "dialogbuttonbox.h"
#endif
#ifdef QFORMLAYOUT_H
#include "formlayout.h"
#endif
#ifdef QFRAME_H
#include "frame.h"
#endif
#ifdef QGRIDLAYOUT_H
#include "gridlayout.h"
#endif
#ifdef QGROUPBOX_H
#include "groupbox.h"
#endif
#ifdef QHEADERVIEW_H
#include "headerview.h"
#endif
#ifdef QLABEL_H
#include "label.h"
#endif
#ifdef QLAYOUT_H
#include "layout.h"
#endif
#ifdef QLINEEDIT_H
#include "lineedit.h"
#endif
#ifdef QLISTVIEW_H
#include "listview.h"
#endif
#ifdef QMENU_H
#include "menu.h"
#endif
#ifdef QMENUBAR_H
#include "menubar.h"
#endif
#ifdef QPLAINTEXTEDIT_H
#include "plaintextedit.h"
#endif
#ifdef QPROGRESSBAR_H
#include "progressbar.h"
#endif
#ifdef QPUSHBUTTON_H
#include "pushbutton.h"
#endif
#ifdef QRADIOBUTTON_H
#include "radiobutton.h"
#endif
#ifdef QSCROLLBAR_H
#include "scrollbar.h"
#endif
#ifdef QSLIDER_H
#include "slider.h"
#endif
#ifdef QSPINBOX_H
#include "spinbox.h"
#endif
#ifdef QSPLITTER_H
#include "splitter.h"
#endif
#ifdef QSTACKEDLAYOUT_H
#include "stackedlayout.h"
#endif
#ifdef QTABBAR_H
#include "tabbar.h"
#endif
#ifdef QTABLEVIEW_H
#include "tableview.h"
#endif
#ifdef QTABLEWIDGET_H
#include "tablewidget.h"
#endif
#ifdef QTABWIDGET_H
#include "tabwidget.h"
#endif
#ifdef QTEXTBROWSER_H
#include "textbrowser.h"
#endif
#ifdef QTEXTEDIT_H
#include "textedit.h"
#endif
#ifdef QTOOLBOX_H
#include "toolbox.h"
#endif
#ifdef QTOOLBUTTON_H
#include "toolbutton.h"
#endif
#ifdef QTREEVIEW_H
#include "treeview.h"
#endif
#ifdef QWIDGET_H
#include "widget.h"
#endif

#endif // NWIDGET_H
