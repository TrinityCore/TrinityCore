/*
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: MaNGOS <http://getmangos.com/>
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

#include "config.h"
#include "ScriptMgr.h"
#include "GossipDef.h"
#include "GameObject.h"
#include "Player.h"
#include "Map.h"
#include "ObjectMgr.h"

//uint8 loglevel = 0;
int nrscripts;
Script *m_scripts[MAX_SCRIPTS];
InstanceDataScript* m_instance_scripts[MAX_INSTANCE_SCRIPTS];
int num_inst_scripts;

// -- Scripts to be added --
extern void AddSC_default();
// -------------------

TRINITY_DLL_EXPORT
void ScriptsFree()
{                                                           // Free resources before library unload
    for(int i=0;i<nrscripts;i++)
        delete m_scripts[i];

    for(int i=0;i<num_inst_scripts;i++)
        delete m_instance_scripts[i];

    nrscripts = 0;
    num_inst_scripts = 0;
}

TRINITY_DLL_EXPORT
void ScriptsInit()
{
    nrscripts = 0;
    num_inst_scripts = 0;
    for(int i=0;i<MAX_SCRIPTS;i++)
    {
         m_scripts[i]=NULL;
         m_instance_scripts[i]=NULL;
    }

    // -- Inicialize the Scripts to be Added --
    AddSC_default();
    // ----------------------------------------

}

Script* GetScriptByName(std::string Name)
{
    if(Name.empty())
        return NULL;
    for(int i=0;i<MAX_SCRIPTS;i++)
    {
        if( m_scripts[i] && m_scripts[i]->Name == Name )
            return m_scripts[i];
    }
    return NULL;
}

//********************************
//*** Functions to be Exported ***

TRINITY_DLL_EXPORT
char const* ScriptsVersion()
{
    return "Default Trinity scripting library";
}
TRINITY_DLL_EXPORT
bool GossipHello ( Player * player, Creature *_Creature )
{
    Script *tmpscript = m_scripts[_Creature->GetScriptId()];
    if (!tmpscript || !tmpscript->pGossipHello) return false;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pGossipHello(player,_Creature);
}

TRINITY_DLL_EXPORT
bool GossipSelect( Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    debug_log("TSCR: Gossip selection, sender: %d, action: %d",sender, action);

    Script *tmpscript = m_scripts[_Creature->GetScriptId()];
    if (!tmpscript || !tmpscript->pGossipSelect) return false;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pGossipSelect(player,_Creature,sender,action);
}

TRINITY_DLL_EXPORT
bool GossipSelectWithCode( Player *player, Creature *_Creature, uint32 sender, uint32 action, const char* sCode )
{
    debug_log("TSCR: Gossip selection with code, sender: %d, action: %d",sender, action);

    Script *tmpscript = m_scripts[_Creature->GetScriptId()];
    if (!tmpscript || !tmpscript->pGossipSelectWithCode) return false;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pGossipSelectWithCode(player,_Creature,sender,action,sCode);
}

TRINITY_DLL_EXPORT
bool QuestAccept( Player *player, Creature *_Creature, Quest const *_Quest )
{
    Script *tmpscript = m_scripts[_Creature->GetScriptId()];
    if (!tmpscript || !tmpscript->pQuestAccept) return false;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pQuestAccept(player,_Creature,_Quest);
}

TRINITY_DLL_EXPORT
bool QuestSelect( Player *player, Creature *_Creature, Quest const *_Quest )
{
    Script *tmpscript = m_scripts[_Creature->GetScriptId()];
    if (!tmpscript || !tmpscript->pQuestSelect) return false;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pQuestSelect(player,_Creature,_Quest);
}

TRINITY_DLL_EXPORT
bool QuestComplete( Player *player, Creature *_Creature, Quest const *_Quest )
{
    Script *tmpscript = m_scripts[_Creature->GetScriptId()];
    if (!tmpscript || !tmpscript->pQuestComplete) return false;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pQuestComplete(player,_Creature,_Quest);
}

TRINITY_DLL_EXPORT
bool ChooseReward( Player *player, Creature *_Creature, Quest const *_Quest, uint32 opt )
{
    Script *tmpscript = m_scripts[_Creature->GetScriptId()];
    if (!tmpscript || !tmpscript->pChooseReward) return false;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pChooseReward(player,_Creature,_Quest,opt);
}

TRINITY_DLL_EXPORT
uint32 NPCDialogStatus( Player *player, Creature *_Creature )
{
    Script *tmpscript = m_scripts[_Creature->GetScriptId()];
    if (!tmpscript || !tmpscript->pNPCDialogStatus) return 100;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pNPCDialogStatus(player,_Creature);
}

TRINITY_DLL_EXPORT
uint32 GODialogStatus( Player *player, GameObject *_GO )
{
    Script *tmpscript = m_scripts[_GO->GetGOInfo()->ScriptId];
    if (!tmpscript || !tmpscript->pGODialogStatus) return 100;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pGODialogStatus(player,_GO);
}

TRINITY_DLL_EXPORT
bool ItemHello( Player *player, Item *_Item, Quest const *_Quest )
{
    Script *tmpscript = m_scripts[_Item->GetProto()->ScriptId];
    if (!tmpscript || !tmpscript->pItemHello) return false;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pItemHello(player,_Item,_Quest);
}

TRINITY_DLL_EXPORT
bool ItemQuestAccept( Player *player, Item *_Item, Quest const *_Quest )
{
    Script *tmpscript = m_scripts[_Item->GetProto()->ScriptId];
    if (!tmpscript || !tmpscript->pItemQuestAccept) return false;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pItemQuestAccept(player,_Item,_Quest);
}

TRINITY_DLL_EXPORT
bool GOHello( Player *player, GameObject *_GO )
{
    Script *tmpscript = m_scripts[_GO->GetGOInfo()->ScriptId];
    if (!tmpscript || !tmpscript->pGOHello) return false;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOHello(player,_GO);
}

TRINITY_DLL_EXPORT
bool GOQuestAccept( Player *player, GameObject *_GO, Quest const *_Quest )
{
    Script *tmpscript = m_scripts[_GO->GetGOInfo()->ScriptId];
    if (!tmpscript || !tmpscript->pGOQuestAccept) return false;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOQuestAccept(player,_GO,_Quest);
}

TRINITY_DLL_EXPORT
bool GOChooseReward( Player *player, GameObject *_GO, Quest const *_Quest, uint32 opt )
{
    Script *tmpscript = m_scripts[_GO->GetGOInfo()->ScriptId];
    if (!tmpscript || !tmpscript->pGOChooseReward) return false;

    player->PlayerTalkClass->ClearMenus();
    return tmpscript->pGOChooseReward(player,_GO,_Quest,opt);
}

TRINITY_DLL_EXPORT
bool AreaTrigger( Player *player, AreaTriggerEntry * atEntry)
{
    Script *tmpscript = m_scripts[GetAreaTriggerScriptId(atEntry->id)];
    if (!tmpscript || !tmpscript->pAreaTrigger) return false;

    return tmpscript->pAreaTrigger(player, atEntry);
}

TRINITY_DLL_EXPORT
CreatureAI* GetAI(Creature *_Creature)
{
    Script *tmpscript = m_scripts[_Creature->GetScriptId()];
    if (!tmpscript || !tmpscript->GetAI) return NULL;

    return tmpscript->GetAI(_Creature);
}

TRINITY_DLL_EXPORT
bool ItemUse( Player *player, Item* _Item, SpellCastTargets const& targets)
{
    Script *tmpscript = m_scripts[_Item->GetProto()->ScriptId];
    if (!tmpscript || !tmpscript->pItemUse) return false;

    return tmpscript->pItemUse(player,_Item,targets);
}

TRINITY_DLL_EXPORT
bool ReceiveEmote( Player *player, Creature *_Creature, uint32 emote )
{
    Script *tmpscript = m_scripts[_Creature->GetScriptId()];
    if (!tmpscript || !tmpscript->pReceiveEmote) return false;

    return tmpscript->pReceiveEmote(player, _Creature, emote);
}

/*TRINITY_DLL_EXPORT
InstanceData* CreateInstanceData(Map *map)
{
    if (!map->IsDungeon()) return NULL;

    Script *tmpscript = m_scripts[((InstanceMap*)map)->GetScriptId()];
    if (!tmpscript || !tmpscript->GetInstanceData) return NULL;

    return tmpscript->GetInstanceData(map);
}

void ScriptedAI::UpdateAI(const uint32)
{
    //Check if we have a current target
    if( m_creature->isAlive() && m_creature->SelectHostilTarget() && m_creature->getVictim())
    {
        //If we are within range melee the target
        if( m_creature->IsWithinDistInMap(m_creature->getVictim(), ATTACK_DISTANCE))
        {
            if( m_creature->isAttackReady() )
            {
                m_creature->AttackerStateUpdate(m_creature->getVictim());
                m_creature->resetAttackTimer();
            }
        }
    }
}

void ScriptedAI::EnterEvadeMode()
{
    if( m_creature->isAlive() )
        DoGoHome();
}

void ScriptedAI::DoStartAttack(Unit* victim)
{
    if( m_creature->Attack(victim, true) )
        m_creature->GetMotionMaster()->MoveChase(victim);
}

void ScriptedAI::DoStopAttack()
{
    if( m_creature->getVictim() != NULL )
    {
        m_creature->AttackStop();
    }
}

void ScriptedAI::DoGoHome()
{
    if( !m_creature->getVictim() && m_creature->isAlive() )
        m_creature->GetMotionMaster()->MoveTargetedHome();
}
*/

