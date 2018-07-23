#include "dockui_base.h"
#include <QtCore>

namespace DockUI
{
    class  DockUIBasePrivate
    {
    public:
        DockUIBasePrivate()
            : uuid(QUuid::createUuid().toString())
            , content(nullptr){}

        QString uuid;
        QString name;
    };

    DockUIBase::DockUIBase()
        : d_ptr(new DockUIBasePrivate)
    { }

    DockUIBase::~DockUIBase()
    {
        Q_D(DockUIBase);
        if(d)
        {
            delete d;
        }
    }

    QString DockUIBase::id() 
    {
        Q_D(DockUIBase);
        Q_ASSERT(d);
        return d->uuid;
    }

    QString DockUIBase::name()
    {
        Q_D(DockUIBase);
        Q_ASSERT(d);
        return d->name;
    }

    void DockUIBase::setName(const QString &name)
    {
        Q_D(DockUIBase);
        Q_ASSERT(d);
        d->name = name;
    }
}
