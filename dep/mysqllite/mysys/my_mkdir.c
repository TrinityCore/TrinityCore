/* Copyright (C) 2000 MySQL AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#include "mysys_priv.h"
#include "mysys_err.h"
#include <sys/types.h>
#include <sys/stat.h>
#ifdef __WIN__
#include <direct.h>
#endif

int my_mkdir(const char *dir, int Flags, myf MyFlags)
{
  DBUG_ENTER("my_dir");
  DBUG_PRINT("enter",("dir: %s",dir));

#if  defined(__WIN__)
  if (mkdir((char*) dir))
#else
  if (mkdir((char*) dir, Flags & my_umask_dir))
#endif
  {
    my_errno=errno;
    DBUG_PRINT("error",("error %d when creating direcory %s",my_errno,dir));
    if (MyFlags & (MY_FFNF | MY_FAE | MY_WME))
      my_error(EE_CANT_MKDIR,  MYF(ME_BELL+ME_WAITTANG), dir, my_errno);
    DBUG_RETURN(-1);
  }
  DBUG_RETURN(0);
}
