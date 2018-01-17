AC_PREREQ(2.62)
AC_INIT([libini], [0.0.1], [leonhad@gmail.com], [https://github.com/leonhad/pdftools])
AM_INIT_AUTOMAKE([-Wall tar-ustar no-define nostdinc ])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER([config.h])

AC_CANONICAL_HOST

# Checks for programs.
AC_LANG([C++])
AC_PROG_CXX
AM_PROG_AR
# AC_PROG_LIBTOOL
AX_CXX_COMPILE_STDCXX([11], [noext], [mandatory])

LT_INIT([win32-dll])
# LT_INIT
# LT_LANG([C++])

# Checks for library functions.
# Checks for libraries.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
