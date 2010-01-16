/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#include <cstdio>

#include "DebugCmdLogger.h"
#include <stdio.h>

using namespace G3D;

namespace VMAP
{

    bool CommandFileRW::appendCmd(const Command&
#ifdef _DEBUG
        pCommand
#endif
        )
    {
        #ifdef _DEBUG
        bool result = false;
        if(iWritingEnabled || pCommand.isCoreCmd())
        {
            FILE* f = fopen(iFileName.c_str(), "ab");
            if(f)
            {
                result = true;
                if(fwrite(&pCommand, sizeof(Command), 1, f) != 1) { result = false; }
                fclose(f);
            }
        }
        else
        {
            result = true;
        }
        return result;
        #else
        return true;
        #endif
    }

    //=========================================================

    bool CommandFileRW::appendCmds(const Array<Command>&
#ifdef _DEBUG
        pCmdArray
#endif
        )
    {
        #ifdef _DEBUG
        bool result = false;
        if(iWritingEnabled)
        {
            FILE* f;
            if(resetfile)
                f = fopen(iFileName.c_str(), "wb");
            else
                f = fopen(iFileName.c_str(), "ab");
            resetfile = false;

            if(f)
            {
                result = true;
                for (int i=0; i<pCmdArray.size(); ++i)
                {
                    if(fwrite(&pCmdArray[i], sizeof(Command), 1, f) != 1) { result = false; break; }
                }
                fclose(f);
            }
        }
        else
        {
            result = true;
        }
        return result;
        #else
        return true;
        #endif
    }

    //=========================================================

    bool CommandFileRW::getNewCommands(Array<Command>& pCmdArray)
    {
        bool result = false;
        FILE* f = fopen(iFileName.c_str(), "rb");
        if(f)
        {
            Command cmd;
            if(fseek(f, iLastPos, SEEK_SET) == 0) { result = true; }
            while(result)
            {
                if(fread(&cmd, sizeof(Command), 1, f) != 1)
                {
                    result = false;
                }
                iLastPos = ftell(f);
                if(cmd.getType() == STOP)
                {
                    break;
                }
                pCmdArray.append(cmd);
            }
            fclose(f);
        }
        if(result)
        {
            iCommandArray.append(pCmdArray);
        }
        return(result);
    }
    //========================================================
}

