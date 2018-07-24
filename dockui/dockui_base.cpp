#include "dockui_base.h"
#include <QtCore>
#include <QtWidgets>
#include "dock_guider.h"

namespace DockUI
{
    class  DockUIBasePrivate
    {
    public:
        DockUIBasePrivate()
            : uuid(QUuid::createUuid().toString())
			, guider(nullptr)
			, spliter(nullptr)
		{}

        QString uuid;
        QString name;
		DockGuider* guider;
		QSplitter* spliter;
    };

    DockUIBase::DockUIBase(QWidget* parent)
        : QWidget(parent)
		, d_ptr(new DockUIBasePrivate)
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

	void DockUIBase::setContent(QWidget *cont)
	{
		Q_D(DockUIBase);
		Q_ASSERT(d);
		d->spliter = cont;
		cont->setParent(this);
	}

	QWidget* DockUIBase::content()
	{
		Q_D(DockUIBase);
		Q_ASSERT(d);
		return d->spliter;
	}

	DockUI::DockGuider* DockUIBase::guider()
	{
		Q_D(DockUIBase);
		Q_ASSERT(d);

		if (!d->guider)
		{
			d->guider = new DockGuider(this);
		}
		return d->guider;
	}

	bool DockUIBase::addChildPage(DockUIBase* child, DockUI::DockWidgetPos pos)
	{
		return false;
	}

	void DockUIBase::resizeEvent(QResizeEvent *event)
	{
		QWidget::resizeEvent(event);
		if (guider())
		{
			guider()->setGeometry(0, 0, width(), height());
		}

		if (content())
		{
			content()->setGeometry(0, 0, width(), height());
		}
	}

	void DockUIBase::mousePressEvent(QMouseEvent *event)
	{

	}

	void DockUIBase::paintEvent(QPaintEvent *event)
	{
		QPainter painter(this);
		painter.setPen(testBackgroundColor());
		painter.setBrush(testBackgroundColor());
		painter.drawRect(rect());
	}

}
