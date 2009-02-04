# Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
#
# Thanks to the original authors: MaNGOS <http://getmangos.com/>
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

## Sub-directories to parse

## Build MaNGOS script library as shared library.
#  libmangosscript shared library will later be reused by world server daemon.
lib_LTLIBRARIES = libtrinityscript.la

libtrinityscript_la_CPPFLAGS = \
$(MYSQL_INCLUDES) \
$(POSTGRE_INCLUDES) \
$(TRINI_INCLUDES) \
-I$(top_srcdir)/dep/include \
-I$(top_srcdir)/src/shared \
-I$(top_srcdir)/src/framework \
-I$(top_srcdir)/src/game

libtrinityscript_la_SOURCES = \
$(srcdir)/ScriptMgr.cpp \
$(srcdir)/ScriptMgr.h \
$(srcdir)/config.h \
$(srcdir)/system.cpp \
$(srcdir)/Scripts/sc_default.cpp \
$(srcdir)/Scripts/sc_defines.cpp \
$(srcdir)/Scripts/sc_defines.h

## libtool settings
#  API versioning
libtrinityscript_la_LIBFLAGS = -version-info 0:0:0
libtrinityscript_la_LIBADD = $(MYSQL_LIBS) $(POSTGRE_LIBS)

## Additional files to include when running 'make dist'
#  Scripts defaults.
EXTRA_DIST = \
        Readme.txt


