lib_LTLIBRARIES = libini.la
libini_la_SOURCES = \
    fileinterface.cpp \
    groups.cpp \
    inifile.cpp \
    memoryfile.cpp \
    propertyfile.cpp

libini_ladir = $(includedir)/ini

libini_la_HEADERS = \
	ini.h \
	fileinterface.h \
    groups.h \
    inifile.h \
    key.h \
    memoryfile.h \
    propertyfile.h

libini_la_CXXFLAGS = $(AM_CXXFLAGS)
libini_la_CPPFLAGS = $(AM_CPPFLAGS)
libini_la_LDFLAGS = -no-undefined -version-info 0:0:0

nodist_libini_la_SOURCES = $(BUILT_SOURCES)
