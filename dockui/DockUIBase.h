//*******************************************************
// 文 件 名： dockui_base.h
// 作    者： DXB
// 版 本 号： 1.0
// 创建时间： 2018/07/24 12:56
// 文件描述： 
// 其他说明：Dock和Page共有信息基类
//*******************************************************
#ifndef DOCKUI_BASE_H
#define DOCKUI_BASE_H

#include <QtCore>

namespace DockUI
{
    class DockUIBase 
	{
    public:
		DockUIBase() : m_uuid(QUuid::createUuid().toString()) {}
		virtual ~DockUIBase() {}

    public:
        //id
		QString id() const { return m_uuid; }

        //名称
		QString name() const { return m_name; }
		void setName(const QString& name) { m_name = name; }

    private:
		QString m_uuid;
		QString m_name;
    };

}
#endif // DOCKUI_BASE_H
