AC_PREREQ([2.71])
AC_INIT([libini],[1.0.0],[leonhad@gmail.com],[https://github.com/leonhad/ini])
AM_INIT_AUTOMAKE([-Wall tar-ustar no-define nostdinc subdir-objects])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AC_USE_SYSTEM_EXTENSIONS

dnl This mechanism allows one to enable debug compilations...
AC_ARG_ENABLE(debug,
[  --enable-debug     enable debugging and disable optimization],
[  if test "$enable_debug" = "yes"; then
        AX_CHECK_COMPILE_FLAG([-fprofile-arcs], [CXXFLAGS="$CXXFLAGS -fprofile-arcs"])
        AX_CHECK_COMPILE_FLAG([-O0], [CXXFLAGS="$CXXFLAGS -O0"])
        AX_CHECK_COMPILE_FLAG([-g3], [CXXFLAGS="$CXXFLAGS -g3"])
        AX_CHECK_COMPILE_FLAG([-fdiagnostics-show-option],  [CXXFLAGS="$CXXFLAGS -fdiagnostics-show-option"])

        dnl Coverage on clang
        AX_CHECK_COMPILE_FLAG([-ftest-coverage], [CXXFLAGS="$CXXFLAGS -ftest-coverage"])
        AX_CHECK_COMPILE_FLAG([-fprofile-instr-generate -fcoverage-mapping], [CXXFLAGS="$CXXFLAGS -fprofile-instr-generate -fcoverage-mapping"])

        CXXFLAGS="$CXXFLAGS -DDEBUG"
   else
        AX_CHECK_COMPILE_FLAG([-O3], [CXXFLAGS="$CXXFLAGS -O3"])
        CXXFLAGS="$CXXFLAGS -O3 -DNDEBUG"
   fi
])
AM_CONDITIONAL(ENABLE_DEBUG, test "$enable_debug" = "yes")

AC_CANONICAL_HOST

dnl Checks for programs.
AC_LANG([C++])
AC_PROG_CXX([clang++])
AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])

AC_PROG_INSTALL
AC_PROG_MAKE_SET
AM_PROG_AR
LT_INIT([win32-dll])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
