#ifndef TIANCHI_QGLOBAL_H
#define TIANCHI_QGLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TIANCHI_LIBRARY)
#  define TIANCHI_EXPORT Q_DECL_EXPORT
#else
#  define TIANCHI_EXPORT Q_DECL_IMPORT
#endif

#endif // TIANCHI_QGLOBAL_H
