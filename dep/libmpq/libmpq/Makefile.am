# minimum required automake 1.6
AUTOMAKE_OPTIONS		= 1.6

# library information and headers which should not be installed.
lib_LTLIBRARIES			= libmpq.la
noinst_HEADERS			= common.h explode.h extract.h huffman.h mpq-internal.h wave.h

# directory where the include files will be installed.
libmpq_includedir		= $(includedir)/libmpq

# header files to install.
libmpq_include_HEADERS		= mpq.h

libmpq_la_SOURCES		= $(GENERAL_SRCS)
libmpq_la_LDFLAGS		= -version-info @LIBMPQ_ABI@

GENERAL_SRCS =			\
	common.c		\
	huffman.c		\
	extract.c		\
	explode.c		\
	mpq.c			\
	wave.c
