## CPP flags for includes, defines, etc.
AM_CPPFLAGS = -I$(srcdir)

## Build world list daemon as standalone program
bin_PROGRAMS = genrevision
genrevision_SOURCES = \
    genrevision.cpp

## Link world daemon against the shared library
genrevision_LDADD = 
genrevision_LDFLAGS = -L$(libdir)

## Additional files to include when running 'make dist'
#  Include world daemon configuration
#EXTRA_DIST = 

## Additional files to install
