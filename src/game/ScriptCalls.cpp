/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#ifndef WIN32
#include <dlfcn.h>
#endif

#include "Platform/Define.h"
#include "ScriptCalls.h"
#include "World.h"

ScriptsSet Script=NULL;

void UnloadScriptingModule()
{
    if(Script)
    {
        //todo: some check if some func from script library is called right now
        Script->ScriptsFree();
        TRINITY_CLOSE_LIBRARY(Script->hScriptsLib);
        delete Script;
        Script = NULL;
    }
}

bool LoadScriptingModule(char const* libName)
{
    ScriptsSet testScript=new _ScriptSet;

    std::string name = strlen(libName) ? libName : TRINITY_SCRIPT_NAME;
    name += TRINITY_SCRIPT_EXT;

    testScript->hScriptsLib=TRINITY_LOAD_LIBRARY(name.c_str());

    if(!testScript->hScriptsLib )
    {
        printf("Error loading Scripts Library %s !\n",name.c_str());
        delete testScript;
        return false;
    }

    if(   !(testScript->ScriptsInit         =(scriptCallScriptsInit         )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"ScriptsInit"         ))
        ||!(testScript->ScriptsFree         =(scriptCallScriptsFree         )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"ScriptsFree"         ))
        ||!(testScript->ScriptsVersion      =(scriptCallScriptsVersion      )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"ScriptsVersion"      ))
        ||!(testScript->GossipHello         =(scriptCallGossipHello         )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"GossipHello"         ))
        ||!(testScript->GOChooseReward      =(scriptCallGOChooseReward      )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"GOChooseReward"      ))
        ||!(testScript->QuestAccept         =(scriptCallQuestAccept         )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"QuestAccept"         ))
        ||!(testScript->GossipSelect        =(scriptCallGossipSelect        )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"GossipSelect"        ))
        ||!(testScript->GossipSelectWithCode=(scriptCallGossipSelectWithCode)TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"GossipSelectWithCode"))
        ||!(testScript->GOSelect            =(scriptCallGOSelect            )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"GOSelect"            ))
        ||!(testScript->GOSelectWithCode    =(scriptCallGOSelectWithCode    )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"GOSelectWithCode"    ))
        ||!(testScript->QuestSelect         =(scriptCallQuestSelect         )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"QuestSelect"         ))
        ||!(testScript->QuestComplete       =(scriptCallQuestComplete       )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"QuestComplete"       ))
        ||!(testScript->NPCDialogStatus     =(scriptCallNPCDialogStatus     )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"NPCDialogStatus"     ))
        ||!(testScript->GODialogStatus      =(scriptCallGODialogStatus      )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"GODialogStatus"     ))
        ||!(testScript->ChooseReward        =(scriptCallChooseReward        )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"ChooseReward"        ))
        ||!(testScript->ItemHello           =(scriptCallItemHello           )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"ItemHello"           ))
        ||!(testScript->GOHello             =(scriptCallGOHello             )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"GOHello"             ))
        ||!(testScript->scriptAreaTrigger   =(scriptCallAreaTrigger         )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"AreaTrigger"         ))
        ||!(testScript->ItemQuestAccept     =(scriptCallItemQuestAccept     )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"ItemQuestAccept"     ))
        ||!(testScript->GOQuestAccept       =(scriptCallGOQuestAccept       )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"GOQuestAccept"       ))
        ||!(testScript->ItemUse             =(scriptCallItemUse             )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"ItemUse"             ))
        ||!(testScript->EffectDummyGameObj  =(scriptCallEffectDummyGameObj  )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"EffectDummyGameObj"  ))
        ||!(testScript->EffectDummyCreature =(scriptCallEffectDummyCreature )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"EffectDummyCreature" ))
        ||!(testScript->EffectDummyItem     =(scriptCallEffectDummyItem     )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"EffectDummyItem"     ))
        ||!(testScript->GetAI               =(scriptCallGetAI               )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"GetAI"               ))
        ||!(testScript->CreateInstanceData  =(scriptCallCreateInstanceData  )TRINITY_GET_PROC_ADDR(testScript->hScriptsLib,"CreateInstanceData"  ))
        )
    {
        printf("Error loading Scripts Library %s !\n Library missing required functions.",name.c_str());
        TRINITY_CLOSE_LIBRARY(testScript->hScriptsLib);
        delete testScript;
        return false;
    }

    sLog.outString();
    sLog.outString( ">>> Scripts Library %s was successfully loaded.\n", name.c_str() );

    //heh we are still there :P we have a valid library
    //we reload script
    UnloadScriptingModule();

    Script=testScript;
    Script->ScriptsInit();

    sWorld.SetScriptsVersion(Script->ScriptsVersion());

    return true;
}

