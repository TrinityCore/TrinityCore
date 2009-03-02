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

## CPP flags for includes, defines, etc.
AM_CPPFLAGS = $(TRINI_INCLUDES) -I$(srcdir)

## Build MaNGOS framework library as convenience library.
#  libMaNGOSScript shared library will later be reused by world server daemon.
noinst_LIBRARIES = libmangosframework.a
libmangosframework_a_SOURCES = \
	Policies/ObjectLifeTime.cpp \
	Utilities/EventProcessor.cpp

## Additional files to include when running 'make dist'
#  Source and header files for the Framework.
EXTRA_DIST = \
	Dynamic/FactoryHolder.h \
	Dynamic/ObjectRegistry.h \
	GameSystem/Grid.h \
	GameSystem/GridLoader.h \
	GameSystem/GridRefManager.h \
	GameSystem/GridReference.h \
	GameSystem/NGrid.h \
	GameSystem/TypeContainer.h \
	GameSystem/TypeContainerFunctions.h \
	GameSystem/TypeContainerFunctionsPtr.h \
	GameSystem/TypeContainerVisitor.h \
	Network/SocketDefines.h \
	Platform/CompilerDefs.h \
	Platform/Define.h \
	Policies/CreationPolicy.h \
	Policies/ObjectLifeTime.h \
	Policies/Singleton.h \
	Policies/SingletonImp.h \
	Policies/ThreadingModel.h \
	Utilities/CountedReference/Reference.h \
	Utilities/CountedReference/ReferenceHolder.h \
	Utilities/CountedReference/ReferenceImpl.h \
	Utilities/LinkedReference/RefManager.h \
	Utilities/LinkedReference/Reference.h \
	Utilities/ByteConverter.h \
	Utilities/Callback.h \
	Utilities/EventProcessor.h \
	Utilities/UnorderedMap.h \
	Utilities/LinkedList.h \
	Utilities/TypeList.h
