#include "dockui_dockpage.h"

DockUI::DockuiDockPage::DockuiDockPage(QWidget *parent)
    : QWidget(parent)
{

}

DockUI::DockWidgetType DockUI::DockuiDockPage::type()
{
    return DockUI::DockWidgetType::DockPage;
}
