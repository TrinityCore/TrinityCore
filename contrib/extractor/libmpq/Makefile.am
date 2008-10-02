# The input Makefile for the main mpq-tools

lib_LTLIBRARIES		= libmpq.la
noinst_HEADERS		= explode.h huffman.h wave.h common.h

# The directory where the include files will be installed.
libmpq_includedir	= $(includedir)/libmpq

# Which header files to install.
libmpq_include_HEADERS	= mpq.h

libmpq_la_SOURCES	= $(GENERAL_SRCS)
libmpq_la_LDFLAGS	= -release $(LIBMPQ_VERSION)
libmpq_la_LIBADD	= @Z_LIBS@

GENERAL_SRCS =			\
	common.c		\
	huffman.c		\
	extract.c		\
	explode.c		\
	mpq.c			\
	parser.c		\
	wave.c
