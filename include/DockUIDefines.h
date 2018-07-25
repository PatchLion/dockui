#ifndef dockui_defines_h__
#define dockui_defines_h__

namespace DockUI
{
	//窗口位置
	enum class PosType
	{
		Top,
		Left,
		Right,
		Bottom,
	};

	//窗口尺寸策略
	enum class WidgetSizePolicy
	{
		Fixed, //固定
		Extended, //扩展
	};
}

#endif // dockui_defines_h__
