#ifndef DOCKUI_DOCKPAGE_H
#define DOCKUI_DOCKPAGE_H

#include "dockui_global.h"
#include "dockui_defines.h"
#include "dockui_base.h"
#include <QWidget>

namespace DockUI
{
    class  DockuiDockPage : public QWidget, public DockUIBase
    {
        Q_OBJECT
    public:
        explicit DockuiDockPage(QWidget *parent = nullptr);

    public:
        //类型
        DockUI::DockWidgetType type();
    };
}

#endif // DOCKUI_DOCKPAGE_H
