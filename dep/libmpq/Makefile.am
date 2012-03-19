# minimum required automake 1.6
AUTOMAKE_OPTIONS		= 1.6

# any directories which should be built and installed.
SUBDIRS				= libmpq bindings doc

# the directories which are part of the distribution.
DIST_SUBDIRS			= $(SUBDIRS)

# libmpq runtime configuration script.
bin_SCRIPTS			= libmpq-config

# pkg-config installation directory.
pkgconfigdir			= $(libdir)/pkgconfig
pkgconfig_DATA			= libmpq.pc

# extra stuff.
EXTRA_DIST =			\
	AUTHORS			\
	COPYING			\
	FAQ			\
	INSTALL			\
	NEWS			\
	README			\
	THANKS			\
	TODO
