/*
* 文 件 名： DockUIPageWidget.h
* 作    者： DXB
* 版 本 号： 1.0
* 创建时间： 2018/07/25 13:16
* 文件描述： 
* 其他说明：
*/
#ifndef DockUIPageWidget_H
#define DockUIPageWidget_H

#include <QWidget>
#include "DockUIDefines.h"
#include "DockUIBase.h"

namespace DockUI
{
	class DockUIPageWidget : public QWidget, public DockUIBase
	{
		Q_OBJECT
	public:
		explicit DockUIPageWidget(QWidget *parent = nullptr);

	};
}

#endif // DockUIPageWidget_H
