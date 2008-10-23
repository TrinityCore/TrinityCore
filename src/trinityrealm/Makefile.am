# Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
#
# Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

## Process this file with automake to produce Makefile.in

## Build realm list daemon as standalone program
bin_PROGRAMS = trinity-realm

## Preprocessor flags
trinity_realm_CPPFLAGS = \
$(MYSQL_INCLUDES) \
$(POSTGRE_INCLUDES) \
$(TRINI_INCLUDES) \
-I$(top_srcdir)/dep/include \
-I$(top_srcdir)/src/framework \
-I$(top_srcdir)/src/shared \
-D_TRINITY_REALM_CONFIG='"$(sysconfdir)/trinityrealm.conf"'

## Sources
trinity_realm_SOURCES = \
$(srcdir)/AuthCodes.h \
$(srcdir)/AuthSocket.cpp \
$(srcdir)/AuthSocket.h \
$(srcdir)/Main.cpp \
$(srcdir)/RealmList.cpp \
$(srcdir)/RealmList.h

## Convenience libs to add
trinity_realm_LDADD =  \
$(top_builddir)/src/shared/libshared.a \
$(top_builddir)/src/framework/libmangosframework.a \
$(top_builddir)/dep/src/sockets/libmangossockets.a \
$(top_builddir)/dep/src/zthread/libZThread.la

## Linker flags
trinity_realm_LDFLAGS = $(MYSQL_LIBS) $(POSTGRE_LIBS) $(ZLIB) $(COMPATLIB) $(SSLLIB) $(TRINI_LIBS)

## Additional files to install
sysconf_DATA = \
	trinityrealm.conf.dist

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

## Additional files to include when running 'make dist'
EXTRA_DIST =  trinityrealm.conf.dist


