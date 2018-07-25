#include "DockUIWindow.h"
#include "DockUILayout.h"

DockUI::DockUIWindow::DockUIWindow(QWidget* parent)
    : QWidget(parent)
{
}


DockUI::DockUIWindow::~DockUIWindow()
{

}

QString DockUI::DockUIWindow::addEmptyDock(DockUI::PosType pos, int length/*=-1*/)
{
	return "";
}

bool DockUI::DockUIWindow::addContentToDock(const QString& dockid, QWidget* content)
{
	return false;
}

QString DockUI::DockUIWindow::addDock(QWidget* content, DockUI::PosType pos, DockUI::WidgetSizePolicy sp)
{
	return "";
}

QString DockUI::DockUIWindow::addEmptyDock(DockUI::PosType pos, const QString& parentid, int length /*= -1*/)
{
	return "";
}

