AC_PREREQ(2.62)
AC_INIT([libini], [0.0.1], [leonhad@gmail.com], [https://github.com/leonhad/ini])
AM_INIT_AUTOMAKE([-Wall tar-ustar no-define nostdinc subdir-objects])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER([config.h])

DEBUG_CFLAGS="-O3 -DNDEBUG"
dnl This mechanism allows one to enable debug compilations...
AC_ARG_ENABLE(debug,
[  --enable-debug     enable debugging and disable optimization],
[  if test "$enable_debug" = "yes"; then
      DEBUG_CFLAGS="-fprofile-arcs  -fPIC -O0 -g3 -DDEBUG -fno-inline -fdiagnostics-show-option"

      dnl Coverage on clang
      AX_CHECK_COMPILE_FLAG([-ftest-coverage], [CXXFLAGS="$CXXFLAGS -ftest-coverage"])
      AX_CHECK_COMPILE_FLAG([-fprofile-instr-generate -fcoverage-mapping], [CXXFLAGS="$CXXFLAGS -fprofile-instr-generate -fcoverage-mapping"])
   fi
])
AM_CONDITIONAL(ENABLE_DEBUG, test "$enable_debug" = "yes")
CXXFLAGS="$DEBUG_CFLAGS $CXXFLAGS"

AC_CANONICAL_HOST

# Checks for programs.
AC_LANG([C++])
AC_PROG_CXX([clang++])
AX_CXX_COMPILE_STDCXX([11], [noext], [mandatory])

AC_PROG_INSTALL
AC_PROG_MAKE_SET
AM_PROG_AR
LT_INIT

AC_LIBTOOL_WIN32_DLL

# Checks for library functions.
# Checks for libraries.

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 test/Makefile])
AC_OUTPUT
