/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "Database/SqlDelayThread.h"
#include "Database/SqlOperations.h"
#include "DatabaseEnv.h"

SqlDelayThread::SqlDelayThread(Database* db, const char* infoString) :m_running(true)
{

  m_dbEngine = new DatabaseType;
  ((DatabaseType*)m_dbEngine)->Initialize(infoString, false);

}

void SqlDelayThread::run()
{
    SqlOperation* s;
    #ifndef DO_POSTGRESQL
    mysql_thread_init();
    #endif

    while (m_running)
    {
      try
	{
	  s = m_sqlQueue.next();
	}
      catch(...)
	{continue;}
      if(!s)
	continue;
      s->Execute(m_dbEngine);
      delete s;
      
    }

    #ifndef DO_POSTGRESQL
    mysql_thread_end();
    #endif
}

void SqlDelayThread::Stop()
{
    m_running = false;
    m_sqlQueue.cancel();
}

