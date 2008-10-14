# Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
#
# Thanks to the original authors: MaNGOS <http://www.mangosproject.org/>
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

noinst_LIBRARIES = libvmaps.a

## Preprocessor flags
libvmaps_a_CPPFLAGS = \
$(TRINI_INCLUDES) \
-I$(top_srcdir)/dep/include \
-I$(top_srcdir)/dep/include/g3dlite

libvmaps_a_SOURCES = \
$(srcdir)/AABSPTree.h \
$(srcdir)/BaseModel.cpp \
$(srcdir)/BaseModel.h \
$(srcdir)/CoordModelMapping.cpp \
$(srcdir)/CoordModelMapping.h \
$(srcdir)/DebugCmdLogger.cpp \
$(srcdir)/DebugCmdLogger.h \
$(srcdir)/IVMapManager.h \
$(srcdir)/ManagedModelContainer.cpp \
$(srcdir)/ManagedModelContainer.h \
$(srcdir)/ModelContainer.cpp \
$(srcdir)/ModelContainer.h \
$(srcdir)/NodeValueAccess.h \
$(srcdir)/ShortBox.h \
$(srcdir)/ShortVector.h \
$(srcdir)/SubModel.cpp \
$(srcdir)/SubModel.h \
$(srcdir)/TileAssembler.cpp \
$(srcdir)/TileAssembler.h \
$(srcdir)/TreeNode.cpp \
$(srcdir)/TreeNode.h \
$(srcdir)/VMapDefinitions.h \
$(srcdir)/VMapFactory.cpp \
$(srcdir)/VMapFactory.h \
$(srcdir)/VMapManager.cpp \
$(srcdir)/VMapManager.h \
$(srcdir)/VMapTools.h


