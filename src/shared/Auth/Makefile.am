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
AM_CPPFLAGS = $(TRINI_INCLUDES) -I$(top_builddir)/src/shared -I$(srcdir) -I$(srcdir)/../../../dep/include -I$(srcdir)/../../framework -I$(srcdir)/../../shared -I$(srcdir)/../../../dep/include/g3dlite

## Build MaNGOS shared library and its parts as convenience library.
#  All libraries will be convenience libraries. Might be changed to shared
#  later.
noinst_LIBRARIES = libmangosauth.a

libmangosauth_a_SOURCES = \
	AuthCrypt.cpp \
	AuthCrypt.h \
	BigNumber.cpp \
	BigNumber.h \
	Hmac.cpp \
	Hmac.h \
	Sha1.cpp \
	Sha1.h \
	md5.c \
	md5.h
