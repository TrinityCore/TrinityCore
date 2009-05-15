# Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
#
# Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

## Sub-directories to parse
SUBDIRS = Auth Config Database vmap

## CPP flags for includes, defines, etc.
AM_CPPFLAGS = $(TRINI_INCLUDES) -I$(top_builddir)/src/shared -I$(srcdir) -I$(srcdir)/../../dep/include -I$(srcdir)/../framework -I$(srcdir)/../shared -I$(srcdir)/../../dep/include/g3dlite  -DSYSCONFDIR=\"$(sysconfdir)/\"
## AM_CPPFLAGS += -I$(srcdir)/../game -I$(srcdir)/../realmd

## Build MaNGOS shared library and its parts as convenience library.
#  All libraries will be convenience libraries. Might be changed to shared
#  later.
noinst_LIBRARIES = libmangosshared.a

#  libmangosshared library will later be reused by ...
libmangosshared_a_SOURCES = \
	Base.cpp \
	Base.h \
	ByteBuffer.h \
	Common.cpp \
	Common.h \
	Errors.h \
	LockedQueue.h \
	Log.cpp \
	Log.h \
	MemoryLeaks.cpp \
	MemoryLeaks.h \
	ProgressBar.cpp \
	ProgressBar.h \
	Timer.h \
	Threading.cpp \
	Threading.h \
	Util.cpp \
	Util.h \
	WorldPacket.h \
	revision_nr.h \
	revision.h

# Get revision (git or svn)
# Get HG revision
REVISION_FILE = revision.h

BUILT_SOURCES = $(REVISION_FILE)
CLEANFILES = $(REVISION_FILE)

FORCE:

$(REVISION_FILE) : $(top_builddir)/src/tools/genrevision/genrevision FORCE
	$(top_builddir)/src/tools/genrevision/genrevision $(top_srcdir)
	cp $(top_builddir)/src/shared/revision.h $(top_srcdir)/src/shared

## Additional files to include when running 'make dist'
#  Disabled packet logger
EXTRA_DIST = \
	PacketLog.cpp \
	PacketLog.h

# System configuration
EXTRA_DIST += \
	SystemConfig.h

# System Win32 files
EXTRA_DIST += \
	ServiceWin32.cpp \
	ServiceWin32.h \
	WheatyExceptionReport.cpp \
	WheatyExceptionReport.h
