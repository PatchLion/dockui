#include "Dockui.h"


DockUI::Dockui::Dockui(QWidget* parent)
    : QWidget(parent)
{
}

DockUI::DockWidgetType DockUI::Dockui::type()
 {
    return DockWidgetType::MainPage;
}
