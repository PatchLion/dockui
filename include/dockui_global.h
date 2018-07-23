#ifndef DOCKUI_GLOBAL_H
#define DOCKUI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DOCKUI_LIBRARY)
#  define DOCKUISHARED_EXPORT Q_DECL_EXPORT
#else
#  define DOCKUISHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DOCKUI_GLOBAL_H
