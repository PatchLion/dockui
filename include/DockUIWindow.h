/*
* 文 件 名： DockUIWindow.h
* 作    者： DXB
* 版 本 号： 1.0
* 创建时间： 2018/07/25 11:39
* 文件描述： 主窗体
* 其他说明：
*/
#ifndef DockUIWindow_h
#define DockUIWindow_h

#include <QWidget>
#include "DockUIGlobal.h"
#include "DockUIDefines.h"

namespace DockUI {
	class DockUIWindowPrivate;
	class DOCKUISHARED_EXPORT DockUIWindow : public QWidget
    {
        Q_OBJECT
    public:
		explicit DockUIWindow(QWidget* parent = 0);
		~DockUIWindow();

    public:
		/*
		* 函数名称： addEmptyDock
		* 函数说明： 添加空白Dock页
		* 参数说明： int length: dock页的宽度或高度，由pos决定是宽度或高度, -1为自动控制
		* 参数说明： DockUI::PosType pos: 插入位置
		* 返 回 值： QString: 新dock页面的ID，为空则表示插入失败
		*/
		QString addEmptyDock(DockUI::PosType pos, int length=-1);


		/*
		* 函数名称： addEmptyDock
		* 函数说明： 向指定的Dock中增加空白子Dock
		* 参数说明： DockUI::PosType pos: 插入位置
		* 参数说明： const QString & parentid: 父dockID
		* 参数说明： int length: dock页的宽度或高度，由pos决定是宽度或高度, -1为自动控制
		* 返 回 值： QString: dock页面的ID，为空则表示插入失败
		*/
		QString addEmptyDock(DockUI::PosType pos, const QString& parentid, int length = -1);


		/*
		* 函数名称： addContentToDock
		* 函数说明： 为Dock页面增加窗体
		* 参数说明： const QString & dockid: 目标dock窗体ID
		* 参数说明： QWidget * content: 窗体
		* 返 回 值： bool: 是否成功
		*/
		bool addContentToDock(const QString& dockid, QWidget* content);
		
		/*
		* 函数名称： addDock
		* 函数说明： 添加Dock页
		* 参数说明： QWidget * content: 内容页
		* 参数说明： DockUI::PosType pos: 插入位置
		* 参数说明： DockUI::WidgetSizePolicy sp: dock窗体缩放策略
		* 返 回 值： QString: dock页面的ID，为空则表示插入失败
		*/
		QString addDock(QWidget* content, DockUI::PosType pos, DockUI::WidgetSizePolicy sp);
	private:
		DockUIWindowPrivate* d_ptr;
		Q_DECLARE_PRIVATE(DockUIWindow)
    };
}

#endif // DockUIWindow_h
