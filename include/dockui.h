//*******************************************************
// 文 件 名： dockui.h
// 作    者： DXB
// 版 本 号： 1.0
// 创建时间： 2018/07/24 12:57
// 文件描述： 
// 其他说明：Dock主页面
//*******************************************************
#ifndef DOCKUI_H
#define DOCKUI_H

#include "dockui_global.h"
#include "dockui_defines.h"
#include "dockui_base.h"
#include <QWidget>

namespace DockUI {
    class DOCKUISHARED_EXPORT Dockui : public DockUIBase
    {
        Q_OBJECT
    public:
        Dockui(QWidget* parent = 0);

    public:
		//是否可以拖动
		virtual bool canDrag() const override { return false; }

		//添加Dock页, 返回Dock页的id
		bool addDockPage(QWidget* content, DockUI::DockWidgetPos pos);

	protected:
		//添加子窗体
		virtual bool addChildPage(DockUIBase* child, DockUI::DockWidgetPos pos) override;

		virtual QColor testBackgroundColor() { return QColor("red"); }
    public:
        //类型
        DockUI::DockWidgetType type() override;
    };
}

#endif // DOCKUI_H
