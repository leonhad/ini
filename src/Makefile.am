lib_LTLIBRARIES = libini.la
libini_la_SOURCES = \
    Section.cpp \
    Ini.cpp

libini_ladir = $(includedir)/ini

libini_la_HEADERS = \
	Ini.h \
    Section.h \
	Key.h

libini_la_CXXFLAGS = $(AM_CXXFLAGS)
libini_la_CPPFLAGS = $(AM_CPPFLAGS)
libini_la_LDFLAGS = -no-undefined -version-info 1:0:0

nodist_libini_la_SOURCES = $(BUILT_SOURCES)
