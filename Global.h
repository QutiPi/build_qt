#pragma once

#include <QtCore/qglobal.h>

#if defined(QUTIPI_CPP)
#  define QUTIPICPPSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QUTIPICPPSHARED_EXPORT Q_DECL_IMPORT
#endif
