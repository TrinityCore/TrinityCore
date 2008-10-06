# Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

## Process this file with automake to produce Makefile.in

## Build world list daemon as standalone program
bin_PROGRAMS = trinity-core

## Preprocessor flags
trinity_core_CPPFLAGS = \
$(MYSQL_INCLUDES) \
$(POSTGRE_INCLUDES) \
$(TRINI_INCLUDES) \
-I$(top_srcdir)/dep/include \
-I$(top_srcdir)/src/shared \
-I$(top_srcdir)/src/framework \
-I$(top_srcdir)/src/game \
-D_TRINITY_CORE_CONFIG='"$(sysconfdir)/trinitycore.conf"'

## Sources
trinity_core_SOURCES = \
$(srcdir)/CliRunnable.cpp \
$(srcdir)/CliRunnable.h \
$(srcdir)/Main.cpp \
$(srcdir)/Master.cpp \
$(srcdir)/Master.h \
$(srcdir)/RASocket.cpp \
$(srcdir)/RASocket.h \
$(srcdir)/WorldRunnable.cpp \
$(srcdir)/WorldRunnable.h

## Convenience libs to add
trinity_core_LDADD = \
$(top_builddir)/src/game/libgame.a \
$(top_builddir)/src/shared/libshared.a \
$(top_builddir)/src/shared/vmap/libvmaps.a \
$(top_builddir)/src/framework/libmangosframework.a \
$(top_builddir)/dep/src/sockets/libmangossockets.a \
$(top_builddir)/dep/src/zthread/libZThread.la \
$(top_builddir)/dep/src/g3dlite/libg3dlite.a

if USE_TSCRIPTS
trinity_core_LDADD += $(top_builddir)/src/bindings/scripts/libtrinityscript.la
else
trinity_core_LDADD += $(top_builddir)/src/bindings/interface/libtrinityscript.la
endif

## Linker flags
trinity_core_LDFLAGS = $(MYSQL_LIBS) $(POSTGRE_LIBS) $(ZLIB) $(COMPATLIB) $(SSLLIB) $(TRINI_LIBS) -export-dynamic

## Additional files to install
sysconf_DATA = \
	trinitycore.conf.dist

EXTRA_DIST =  \
        trinitycore.conf.dist

## Prevend overwrite of the config file, if its already installed
install-data-hook:
	@list='$(sysconf_DATA)'; for p in $$list; do \
      dest=`echo $$p | sed -e s/.dist//`; \
	  if test -f $(DESTDIR)$(sysconfdir)/$$dest; then \
        echo "$@ will not overwrite existing $(DESTDIR)$(sysconfdir)/$$dest"; \
      else \
	    echo " $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(sysconfdir)/$$dest"; \
	    $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(sysconfdir)/$$dest; \
	  fi; \
	done

