/*
* �� �� ���� DockUIPageWidget.h
* ��    �ߣ� DXB
* �� �� �ţ� 1.0
* ����ʱ�䣺 2018/07/25 13:16
* �ļ������� 
* ����˵����
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
