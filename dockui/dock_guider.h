//*******************************************************
// 文 件 名： dock_guider.h
// 作    者： DXB
// 版 本 号： 1.0
// 创建时间： 2018/07/24 12:57
// 文件描述： 
// 其他说明：dock拖动位置指示器
//*******************************************************
#ifndef dock_guider_H
#define dock_guider_H

#include <QWidget>
#include <QMap>

namespace DockUI
{
    class DockGuider : public QWidget
    {
        Q_OBJECT
   
	public:
		//指示器模式
		enum GuiderMode 
		{
			NoGuider, //不显示指示器
			MainGuider,				//主指示器，MainPage使用
			CenterFullGuider,  //中间的指示器，显示所有的
			CenterSimpleGuider, //中间的指示器，显示简单的
		};

		//指示器按钮显示
		enum GuiderButton
		{
			NoButton = 0x00000,
			MainLeftButton = 0x00001 << 0,     //MainPage的左边按钮
			MainRightButton = 0x00001 << 1,  //MainPage的右边按钮
			MainTopButton = 0x00001 << 2,  //MainPage的顶部按钮
			MainBottomButton = 0x00001 << 3,  //MainPage的底部按钮
			LeftButton = 0x00001 << 4,  //左边按钮
			RightButton = 0x00001 << 5, //右边按钮
			TopButton = 0x00001 << 6, //顶部按钮
			BottomButton = 0x00001 << 7, //底部按钮
			SplitLeftButton = 0x00001 << 8,//分割左边按钮
			SplitTopButton = 0x00001 << 9,//分割顶部按钮
			SplitRightButton = 0x00001 << 10,//分割右边按钮
			SplitBottomButton = 0x00001 << 11,//分割底部按钮
			CenterButton = 0x00001 << 12,//中间按钮

			//所有按钮
			AllButtons = (MainLeftButton | MainRightButton | MainTopButton | MainBottomButton | LeftButton | RightButton | TopButton | BottomButton | SplitLeftButton | SplitTopButton | SplitRightButton | SplitBottomButton | CenterButton),
		};

		Q_DECLARE_FLAGS(GuiderButtons, GuiderButton)
	private:
		typedef QMap<GuiderButton, QRect> ButtonRects;
		
	public:
        DockGuider(QWidget* parent = nullptr);
        ~DockGuider();

	public:
		//绘制模式
		GuiderMode drawMode() const { return m_drawMode; }
		void setDrawMode(GuiderMode val);

		//设置需要绘制的按钮
		GuiderButtons drawButtons() const { return m_drawButtons; }
		void setDrawButtons(GuiderButtons val);
		void setButtonVisible(GuiderButton button, bool visible);

    protected:
        void paintEvent(QPaintEvent* event);
		void resizeEvent(QResizeEvent *event);
		void mouseMoveEvent(QMouseEvent *event);

		//更新按钮的Rect
		void updateButtonRects();

	private:
		GuiderMode m_drawMode;   //绘制模式
		GuiderButtons m_drawButtons; //需要绘制的按钮
		ButtonRects m_buttonRect;
		GuiderButton m_hoverButton; //
    };
}
#endif
