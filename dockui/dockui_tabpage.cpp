#include "dockui_tabpage.h"

DockUI::DockuiTabPage::DockuiTabPage(QWidget *parent)
	: DockUIBase(parent)
{

}

DockUI::DockWidgetType DockUI::DockuiTabPage::type()
{
	return DockUI::DockWidgetType::TabPage;
}

bool DockUI::DockuiTabPage::addChildPage(DockUIBase* child, DockUI::DockWidgetPos pos)
{
	return false;
}
