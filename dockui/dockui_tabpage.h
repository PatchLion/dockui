//*******************************************************
// �� �� ���� dockui_tabpage.h
// ��    �ߣ� DXB
// �� �� �ţ� 1.0
// ����ʱ�䣺 2018/07/24 12:58
// �ļ������� 
// ����˵����tabҳ��
//*******************************************************
#ifndef DOCKUI_TABPAGE_H
#define DOCKUI_TABPAGE_H

#include <QWidget>
#include "dockui_global.h"
#include "dockui_defines.h"
#include "dockui_base.h"

namespace DockUI
{
	class DockuiTabPage : public DockUIBase
	{
		Q_OBJECT
	public:
		explicit DockuiTabPage(QWidget *parent = nullptr);

	public:
		//����
		DockUI::DockWidgetType type();

	protected:
		//����Ӵ���
		virtual bool addChildPage(DockUIBase* child, DockUI::DockWidgetPos pos) override;

		//
		virtual QColor testBackgroundColor() override { return QColor("red"); }
	};
}

#endif // DOCKUI_TABPAGE_H