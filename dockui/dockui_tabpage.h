//*******************************************************
// 文 件 名： dockui_tabpage.h
// 作    者： DXB
// 版 本 号： 1.0
// 创建时间： 2018/07/24 12:58
// 文件描述： 
// 其他说明：tab页面
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
		//类型
		DockUI::DockWidgetType type();

	protected:
		//添加子窗体
		virtual bool addChildPage(DockUIBase* child, DockUI::DockWidgetPos pos) override;

		//
		virtual QColor testBackgroundColor() override { return QColor("red"); }
	};
}

#endif // DOCKUI_TABPAGE_H