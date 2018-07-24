//*******************************************************
// 文 件 名： dockui_base.h
// 作    者： DXB
// 版 本 号： 1.0
// 创建时间： 2018/07/24 12:56
// 文件描述： 
// 其他说明：Dock页基类
//*******************************************************
#ifndef DOCKUI_BASE_H
#define DOCKUI_BASE_H

#include <QtCore>
#include <QtWidgets>
#include "dockui_global.h"
#include "dockui_defines.h"

namespace DockUI
{
    class DockUIBasePrivate;
	class DockGuider;
    class DOCKUISHARED_EXPORT DockUIBase : public QWidget
    {
    public:
        DockUIBase(QWidget* parent = nullptr);
        virtual ~DockUIBase();

    public:
        //类型
        virtual DockUI::DockWidgetType type() = 0;

        //id
        QString id();

        //名称
        QString name();
        void setName(const QString& name);

		//是否可以拖动
		virtual bool canDrag() const { return true; }

	protected:
		//指示器
		DockGuider* guider();

		//添加子窗体
		virtual bool addChildPage(QWidget* child, DockUI::DockWidgetPos pos) = 0;

		//
		virtual void resizeEvent(QResizeEvent *event) override;
		virtual void mousePressEvent(QMouseEvent *event) override;
		virtual void paintEvent(QPaintEvent *event) override;

		virtual QColor testBackgroundColor() { return QColor("transparent"); }

    private:
        DockUIBasePrivate* d_ptr;

    private:
       Q_DECLARE_PRIVATE(DockUIBase)
    };
}
#endif // DOCKUI_BASE_H
