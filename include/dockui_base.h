#ifndef DOCKUI_BASE_H
#define DOCKUI_BASE_H

#include "dockui_global.h"
#include "dockui_defines.h"
#include <QtCore>

namespace DockUI
{
    class DockUIBasePrivate;
    class DOCKUISHARED_EXPORT DockUIBase : public QWidget
    {
    public:
        DockUIBase();
        virtual ~DockUIBase();

    public:
        //类型
        virtual DockUI::DockWidgetType type() = 0;

        //id
        QString id();

        //名称
        QString name();
        void setName(const QString& name);

    private:
        DockUIBasePrivate* d_ptr;

    private:
       Q_DECLARE_PRIVATE(DockUIBase);
    };
}
#endif // DOCKUI_BASE_H
