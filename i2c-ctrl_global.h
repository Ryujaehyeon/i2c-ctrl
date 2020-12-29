#ifndef I2CCTRL_GLOBAL_H
#define I2CCTRL_GLOBAL_H

#include <QtCore/qglobal.h>


#if defined(I2CCTRL_LIBRARY)
#  define I2CCTRLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define I2CCTRLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // I2CCTRL_GLOBAL_H
