check_LTLIBRARIES = libgtest.la
libgtest_la_SOURCES = ../googletest/googletest/src/gtest-all.cc
libgtest_la_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest

libgtest_la_LDFLAGS = 

TESTS = gtest

check_PROGRAMS = gtest

gtest_SOURCES = gtest.cpp \
    keytest.cpp

gtest_LDADD = libgtest.la

gtest_LDFLAGS = 

gtest_CPPFLAGS = -I.. -I../src -I../src \
    -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest

MOSTLYCLEANFILES = \
    *.gcda *.gcno *.gcov
