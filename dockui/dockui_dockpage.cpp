#include "dockui_dockpage.h"

DockUI::DockuiDockPage::DockuiDockPage(QWidget *parent)
    : DockUIBase(parent)
{

}

DockUI::DockWidgetType DockUI::DockuiDockPage::type()
{
    return DockUI::DockWidgetType::DockPage;
}

bool DockUI::DockuiDockPage::addChildPage(DockUIBase* child, DockUI::DockWidgetPos pos)
{
	return false;
}
