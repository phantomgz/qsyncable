#ifndef LIBQSYNCABLE_GLOBAL_H
#define LIBQSYNCABLE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBQSYNCABLE_LIBRARY)
#  define LIBQSYNCABLE_EXPORT Q_DECL_EXPORT
#else
#  define LIBQSYNCABLE_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBQSYNCABLE_GLOBAL_H
