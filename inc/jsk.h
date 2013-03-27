#ifndef JSK_INC_H
#define JSK_INC_H

#include <QtCore/qglobal.h>

#if defined(JSK_LIBRARY)
#  define JSK_EXPORT Q_DECL_EXPORT
#else
#  define JSK_EXPORT Q_DECL_IMPORT
#endif

#include "jsk_Utils.h"

#endif // JSK_INC_H
