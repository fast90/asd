#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(asd, 1.0, fabian.m.stahl@posteo.de)
#AM_INIT_AUTOMAKE(asd,1.0)
AM_INIT_AUTOMAKE[foreign -Wall -Werror]

AC_CONFIG_SRCDIR([src/cleanup.h])
AC_CONFIG_HEADERS([config.h])
AC_PREFIX_DEFAULT(/usr)

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([bcm2835],[bcm2835_version],[HAVE_BCM=1] [TEST_LIBS="$TEST_LIBS -lbcm2835"],
			AC_MSG_ERROR([libbcm2835 is not installed.]))

# Checks for header files.
AC_CHECK_HEADERS([stdint.h stdlib.h string.h sys/param.h sys/socket.h syslog.h unistd.h bcm2835.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_PID_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_FORK
AC_CHECK_FUNCS([memset socket strstr])

AC_OUTPUT(Makefile src/Makefile man/Makefile scripts/Makefile)
