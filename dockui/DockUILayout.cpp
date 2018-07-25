#include "DockUILayout.h"
#include "DockUIDockWidget.h"


DockUI::DockUILayout::DockUILayout(QWidget *parent)
    : QWidget(parent)
	//, m_layout(nullptr)
{
	
}


bool DockUI::DockUILayout::addDock(DockUI::DockUIDockWidget* dock, DockUI::PosType pos, DockUI::WidgetSizePolicy sp)
{
	if (dock && !m_layout)
	{
		switch (pos)
		{
		case DockUI::PosType::Top:
		case DockUI::PosType::Bottom:
		{
			newSpiltter(Qt::Vertical);
		}
		break;
		case DockUI::PosType::Left:
		case DockUI::PosType::Right:
		{
			newSpiltter(Qt::Horizontal);
		}
		break;
		}
	}

	switch (pos)
	{
	case DockUI::PosType::Top:
	{
		if (m_layout->orientation() != Qt::Vertical)
		{
			newSpiltter(Qt::Vertical);
		}

		m_layout->insertWidget(0, dock);
	}
	break;
	case DockUI::PosType::Bottom:
	{
		if (m_layout->orientation() != Qt::Vertical)
		{
			newSpiltter(Qt::Vertical);
		}

		m_layout->addWidget(dock);
	}
	break;
	case DockUI::PosType::Left:
	{
		if (m_layout->orientation() != Qt::Horizontal)
		{
			newSpiltter(Qt::Horizontal);
		}

		m_layout->insertWidget(0, dock);
	}
	break;
	case DockUI::PosType::Right:
	{
		if (m_layout->orientation() != Qt::Horizontal)
		{
			newSpiltter(Qt::Horizontal);
		}

		m_layout->addWidget(dock);
	}
	break;
	}

	refresh();

	return true;
}

bool DockUI::DockUILayout::addDockByExistDock(DockUI::DockUIDockWidget* dock, const QString& other_dock_id, DockUI::PosType pos, DockUI::WidgetSizePolicy sp)
{
	return "";
}

void DockUI::DockUILayout::resizeEvent(QResizeEvent *event)
{
	refresh();
}


void DockUI::DockUILayout::refresh()
{
	if (m_layout)
	{
		m_layout->setGeometry(0, 0, width(), height());
	}
}

bool DockUI::DockUILayout::newSpiltter(Qt::Orientation ori)
{
	QSplitter* new_splitter = new QSplitter(ori, this);
	if (m_layout) {
		m_layout->setParent(new_splitter);
		new_splitter->addWidget(m_layout);
	}
	m_layout = new_splitter;

	refresh();
	return true;
}

DockUI::DockUIDockWidget* DockUI::DockUILayout::dockWidget(const QString& other_dock_id)
{
	if (!isDockWidgetExisted(other_dock_id))
	{
		return nullptr;
	}
	return m_dockUIs[other_dock_id];
}

bool DockUI::DockUILayout::isDockWidgetExisted(const QString& other_dock_id)
{
	return m_dockUIs.end() != m_dockUIs.find(other_dock_id);
}

/*


void DockUI::DockUILayout::addUI(DockUIBase* ui, DockUI::PosType pos, DockUI::WidgetSizePolicy sp)
{
	if (!m_layout)
	{
		switch (pos)
		{
		case DockUI::PosType::Top:
		case DockUI::PosType::Bottom:
		{
			newSpiltter(Qt::Vertical);
		}
			break;
		case DockUI::PosType::Left:
		case DockUI::PosType::Right:
		{
			newSpiltter(Qt::Horizontal);
		}
			break;
		}
	}
	
	switch (pos)
	{
	case DockUI::PosType::Top:
	{
		if (m_layout->orientation() != Qt::Vertical)
		{
			newSpiltter(Qt::Vertical);
		}

		m_layout->insertWidget(0, ui);
	}
	break;
	case DockUI::PosType::Bottom:
	{
		if (m_layout->orientation() != Qt::Vertical)
		{
			newSpiltter(Qt::Vertical);
		}

		m_layout->addWidget(ui);
	}
		break;
	case DockUI::PosType::Left:
	{
		if (m_layout->orientation() != Qt::Horizontal)
		{
			newSpiltter(Qt::Horizontal);
		}

		m_layout->insertWidget(0, ui);
	}
	break;
	case DockUI::PosType::Right:
	{
		if (m_layout->orientation() != Qt::Horizontal)
		{
			newSpiltter(Qt::Horizontal);
		}

		m_layout->addWidget(ui);
	}
		break;
	}

	refresh();
}

void DockUI::DockUILayout::resizeEvent(QResizeEvent *event)
{
	refresh();
}

*/
