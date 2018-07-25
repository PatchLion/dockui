/*
* 文 件 名： DockUILayout.h
* 作    者： DXB
* 版 本 号： 1.0
* 创建时间： 2018/07/25 12:42
* 文件描述： 布局管理
* 其他说明：
*/
#ifndef DOCKUI_LAYOUT_H
#define DOCKUI_LAYOUT_H

#include <QtWidgets>
#include "DockUIDefines.h"
#include "DockUIDockWidget.h"

namespace DockUI
{
	class DockUIGuider;
    class DockUILayout : public QWidget
    {
        Q_OBJECT
    public:
        explicit DockUILayout(QWidget *parent = nullptr);

	public:
		/*
		* 函数名称： addDock
		* 函数说明： 增加dock(基于主页面)
		* 参数说明： DockUIBase * dock: dock窗体
		* 参数说明： DockUI::PosType pos: 放入的位置
		* 参数说明： DockUI::WidgetSizePolicy sp: 尺寸策略
		* 返 回 值： bool: 成功与否
		*/
		bool addDock(DockUI::DockUIDockWidget* dock, DockUI::PosType pos, DockUI::WidgetSizePolicy sp);

		/*
		* 函数名称： addDockByExistDock
		* 函数说明： 增加dock
		* 参数说明： DockUIBase * dock: dock窗体
		* 参数说明： DockUI::PosType pos: 放入的位置
		* 参数说明： DockUI::WidgetSizePolicy sp: 尺寸策略
		* 返 回 值： bool: 成功与否
		*/
		bool addDockByExistDock(DockUI::DockUIDockWidget* dock, const QString& other_dock_id, DockUI::PosType pos, DockUI::WidgetSizePolicy sp);

	protected:
		void resizeEvent(QResizeEvent *event);

	private:
		void refresh();
		bool newSpiltter(Qt::Orientation ori);

		DockUI::DockUIDockWidget* dockWidget(const QString& other_dock_id);
		bool isDockWidgetExisted(const QString& other_dock_id);

	private:
		QSplitter* m_layout;
		MapDockWidgets m_dockUIs; //layout下的所有dock窗体
		DockUIGuider* m_guider; //
    };
}

#endif // DOCKUI_LAYOUT_H
