/*
* 文 件 名： DockUIDockWidget.h
* 作    者： DXB
* 版 本 号： 1.0
* 创建时间： 2018/07/25 13:19
* 文件描述： dock窗体
* 其他说明：
*/
#ifndef DOCKUI_DOCKWIDGET_H
#define DOCKUI_DOCKWIDGET_H

#include <QWidget>
#include "DockUIGlobal.h"
#include "DockUIDefines.h"
#include "DockUIBase.h"

namespace DockUI
{
    class  DockUIDockWidget : public QWidget, public DockUIBase
    {
        Q_OBJECT
    public:
        explicit DockUIDockWidget(QWidget *parent = nullptr);

	public:
		/*
		* 函数名称： setShowTitle
		* 函数说明： 设置是否显示Title
		* 参数说明： bool show
		* 返 回 值： void
		*/
		void setShowTitle(bool show);

		/*
		* 函数名称： addContent
		* 函数说明： 添加窗体
		* 参数说明： QWidget * content: 窗体
		* 返 回 值： void
		*/
		void addContent(QWidget* content);

		/*
		* 函数名称： removeContent
		* 函数说明： 移除窗体
		* 参数说明： QWidget * content: 窗体
		* 返 回 值： void
		*/
		void removeContent(QWidget* content);
    };


	typedef QMap<QString, DockUIDockWidget*> MapDockWidgets;
}

#endif // DOCKUI_DOCKWIDGET_H
