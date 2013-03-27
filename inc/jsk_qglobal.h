#ifndef JSK_QGLOBAL_H
#define JSK_QGLOBAL_H

#include <QtCore/qglobal.h>

#if defined(JSK_LIBRARY)
#  define JSK_EXPORT Q_DECL_EXPORT
#else
#  define JSK_EXPORT Q_DECL_IMPORT
#endif

#endif // JSK_QGLOBAL_H
