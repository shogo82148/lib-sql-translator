#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([sql translator c++ library], [0.01], [shogo82148@gmail.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src])

AM_INIT_AUTOMAKE([foreign])
AM_CONFIG_HEADER(config.h)

# Checks for programs.
m4_include([m4/ax_cxx_compile_stdcxx_11.m4])
AX_CXX_COMPILE_STDCXX_11
AC_LANG([C++])
AC_PROG_CXX
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 test/Makefile])
AC_OUTPUT
