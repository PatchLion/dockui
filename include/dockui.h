#ifndef DOCKUI_H
#define DOCKUI_H

#include "dockui_global.h"
#include "dockui_defines.h"
#include "dockui_base.h"
#include <QWidget>

namespace DockUI {
    class DOCKUISHARED_EXPORT Dockui : public QWidget, public DockUIBase
    {
        Q_OBJECT
    public:
        Dockui(QWidget* parent = 0);

    public:
        void addDockPage();
        void addTabPage(const QString& dock_widget_id);

    public:
        //类型
        DockUI::DockWidgetType type();
    };
}

#endif // DOCKUI_H
