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

## TODO move vmaps in src dir instead of src/shared

## Sub-directories to parse
SUBDIRS = vmap

## Build MaNGOS shared library and its parts as convenience library.
#  All libraries will be convenience libraries. Might be changed to shared
#  later.
noinst_LIBRARIES = libshared.a

libshared_a_CPPFLAGS = \
$(MYSQL_INCLUDES) \
$(POSTGRE_INCLUDES) \
-I$(top_srcdir)/dep/include \
-I$(top_srcdir)/src/framework

#  libmangosshared library will later be reused by ...
libshared_a_SOURCES = \
$(srcdir)/Base.cpp \
$(srcdir)/Base.h \
$(srcdir)/ByteBuffer.h \
$(srcdir)/Common.cpp \
$(srcdir)/Common.h \
$(srcdir)/Errors.h \
$(srcdir)/Log.cpp \
$(srcdir)/Log.h \
$(srcdir)/Mthread.cpp \
$(srcdir)/Mthread.h \
$(srcdir)/ProgressBar.cpp \
$(srcdir)/ProgressBar.h \
$(srcdir)/Timer.h \
$(srcdir)/Util.cpp \
$(srcdir)/Util.h \
$(srcdir)/WorldPacket.h \
$(srcdir)/SystemConfig.h \
$(srcdir)../game/IRCConf.h \
$(srcdir)/Auth/AuthCrypt.cpp \
$(srcdir)/Auth/AuthCrypt.h \
$(srcdir)/Auth/BigNumber.cpp \
$(srcdir)/Auth/BigNumber.h \
$(srcdir)/Auth/Hmac.cpp \
$(srcdir)/Auth/Hmac.h \
$(srcdir)/Auth/Sha1.cpp \
$(srcdir)/Auth/Sha1.h \
$(srcdir)/Auth/md5.c \
$(srcdir)/Auth/md5.h \
$(srcdir)/Config/dotconfpp/dotconfpp.cpp \
$(srcdir)/Config/dotconfpp/dotconfpp.h \
$(srcdir)/Config/dotconfpp/mempool.cpp \
$(srcdir)/Config/dotconfpp/mempool.h \
$(srcdir)/Config/Config.cpp \
$(srcdir)/Config/Config.h \
$(srcdir)/Config/ConfigEnv.h \
$(srcdir)/Database/DBCStores.cpp \
$(srcdir)/Database/DBCStores.h \
$(srcdir)/Database/DBCStructure.h \
$(srcdir)/Database/DBCfmt.cpp \
$(srcdir)/Database/Database.cpp \
$(srcdir)/Database/Database.h \
$(srcdir)/Database/DatabaseEnv.h \
$(srcdir)/Database/DatabaseImpl.h \
$(srcdir)/Database/DatabaseMysql.cpp \
$(srcdir)/Database/DatabasePostgre.cpp \
$(srcdir)/Database/DatabaseMysql.h \
$(srcdir)/Database/DatabasePostgre.h \
$(srcdir)/Database/DatabaseSqlite.cpp \
$(srcdir)/Database/DatabaseSqlite.h \
$(srcdir)/Database/Field.cpp \
$(srcdir)/Database/Field.h \
$(srcdir)/Database/MySQLDelayThread.h \
$(srcdir)/Database/PGSQLDelayThread.h \
$(srcdir)/Database/QueryResult.h \
$(srcdir)/Database/QueryResultMysql.cpp \
$(srcdir)/Database/QueryResultMysql.h \
$(srcdir)/Database/QueryResultPostgre.cpp \
$(srcdir)/Database/QueryResultPostgre.h \
$(srcdir)/Database/QueryResultSqlite.cpp \
$(srcdir)/Database/QueryResultSqlite.h \
$(srcdir)/Database/SQLStorage.cpp \
$(srcdir)/Database/SQLStorage.h \
$(srcdir)/Database/SqlDelayThread.cpp \
$(srcdir)/Database/SqlDelayThread.h \
$(srcdir)/Database/SqlOperations.cpp \
$(srcdir)/Database/SqlOperations.h \
$(srcdir)/Database/dbcfile.cpp \
$(srcdir)/Database/dbcfile.h

## Additional files to include when running 'make dist'
#  Disabled packet logger
EXTRA_DIST = \
	PacketLog.cpp \
	PacketLog.h

# System Win32 files
EXTRA_DIST += \
	ServiceWin32.cpp \
	ServiceWin32.h \
	WheatyExceptionReport.cpp \
	WheatyExceptionReport.h


