#include "Dockui.h"
#include "dock_guider.h"

DockUI::Dockui::Dockui(QWidget* parent)
    : DockUIBase(parent)
{
	guider()->setDrawMode(DockGuider::GuiderMode::MainGuider);
	guider()->setDrawButtons(DockGuider::GuiderButtons(DockGuider::GuiderButton::MainLeftButton 
		| DockGuider::GuiderButton::MainTopButton
		| DockGuider::GuiderButton::MainRightButton
		| DockGuider::GuiderButton::MainBottomButton));
}

bool DockUI::Dockui::addDockPage(QWidget* content, DockUI::DockWidgetPos pos)
{

}

bool DockUI::Dockui::addChildPage(DockUIBase* child, DockUI::DockWidgetPos pos)
{
	return false;
}
DockUI::DockWidgetType DockUI::Dockui::type()
 {
    return DockWidgetType::MainPage;
}
