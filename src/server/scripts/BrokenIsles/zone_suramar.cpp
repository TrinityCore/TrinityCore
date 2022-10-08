/*
* Copyright (C) 2021 BfaCore Reforged
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "Player.h"
#include "QuestPackets.h"
#include "ScenePackets.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "SpellAuras.h"
#include "LFGMgr.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "InstanceScript.h"
#include "CriteriaHandler.h"
#include "SceneMgr.h"
#include "Creature.h"
#include "GameObject.h"
#include "PhasingHandler.h"
#include "Log.h"
#include "Object.h"

enum SPELLS
{
    QUEST_MASQUERADE = 42079,
    QUEST_A_Way_Back_In = 40401,
    LEARN_MASQUERADE = 211086,
    SPELL_MASQUERADE = 211135,
};

class Player_Spell_Masquerade : public PlayerScript
{

public:
    Player_Spell_Masquerade() : PlayerScript("Player_Spell_Masquerade") { }

    void OnLogin(Player* player, bool /*firstLogin*/)
    {
        UseSpellMasquerade(player, player->GetAreaId(), true);
    }

    void OnPlayerUpdateAreaAlternate(Player* player, uint32 newArea, uint32 /*oldArea*/)
    {
        UseSpellMasquerade(player, newArea, false);
    }

    void UseSpellMasquerade(Player* player, uint32 area, bool trigger)
    {
        switch (area)
        {
        case 8149:
        case 8148:
        case 8150:
        case 7963:
        case 8351:
        case 8352:
        case 8353:
        case 8355:
        case 8378:
        case 8379:
        case 8380:
        case 8381:
        case 8386:
        case 8385:
        case 8384:
        case 8383:
        case 8382:
        case 8395:
        case 8397:
        case 8398:
        case 8431:
        case 8436:
        case 8441:
        case 8434:
        case 8345:
        case 8461:
        case 8487:
        case 8496:
            if (!player->HasAura(LEARN_MASQUERADE))
                return;
            if (player->GetQuestStatus(QUEST_MASQUERADE) != QUEST_STATUS_REWARDED)
                return;
            if (trigger)
                player->RemoveAurasDueToSpell(SPELL_MASQUERADE);
            if (!player->HasAura(SPELL_MASQUERADE))
                player->CastSpell(player, SPELL_MASQUERADE, true);
            player->GetQuestObjectiveCriteriaMgr();
            return;
            break;
        default:
            return;
            break;
        }
    }
};

enum
{
    ///Quest
    MAKE_YOUR_MARK = 42792,
    The_Gondolier = 41878,
};

struct npc_cyrille_107350 : public ScriptedAI
{
    npc_cyrille_107350(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        if (player->HasQuest(MAKE_YOUR_MARK))
        {
            if (gossipListId == 0)
            {
                player->KilledMonsterCredit(107350);
                CloseGossipMenuFor(player);
                Talk(0);
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (player->HasQuest(MAKE_YOUR_MARK))
                    me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
        }
    }
};

struct npc_lorin_107349 : public ScriptedAI
{
    npc_lorin_107349(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        if (player->HasQuest(MAKE_YOUR_MARK))
        {
            if (gossipListId == 0)
            {
                player->KilledMonsterCredit(107349);
                CloseGossipMenuFor(player);
                Talk(0);
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (player->HasQuest(MAKE_YOUR_MARK))
                    me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
        }
    }
};

struct npc_sylessa_107348 : public ScriptedAI
{
    npc_sylessa_107348(Creature* creature) : ScriptedAI(creature) { me->SetAIAnimKitId(0); }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        if (player->HasQuest(MAKE_YOUR_MARK))
        {
            if (gossipListId == 0)
            {
                player->KilledMonsterCredit(107348);
                CloseGossipMenuFor(player);
                Talk(0);
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (player->HasQuest(MAKE_YOUR_MARK))
                    me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
        }
    }
};

// quest 41878
struct npc_gondolier_107225 : public ScriptedAI
{
    npc_gondolier_107225(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        if (player->HasQuest(The_Gondolier))
        {
            if (gossipListId == 0)
            {
                player->KilledMonsterCredit(107225);
                CloseGossipMenuFor(player);
                Talk(0);
            }
        }
    }
};

// quest 42487
class npc_thallyssra_97140 : public CreatureScript
{
public:
    npc_thallyssra_97140() : CreatureScript("npc_thallyssra_97140") { }
    struct npc_thallyssra_97140AI : public ScriptedAI
    {
        npc_thallyssra_97140AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(42487) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 12.0f))
                    {
                        player->KilledMonsterCredit(97140);
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_thallyssra_97140AI(creature);
    }
};

// quest 40010
class npc_zoneexplorer_113893 : public CreatureScript
{
public:
    npc_zoneexplorer_113893() : CreatureScript("npc_zoneexplorer_113893") { }
    struct npc_zoneexplorer_113893AI : public ScriptedAI
    {
        npc_zoneexplorer_113893AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(40010) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 12.0f))
                    {
                        player->KilledMonsterCredit(113893);
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_zoneexplorer_113893AI(creature);
    }
};

class npc_zoneexplorer_113894 : public CreatureScript
{
public:
    npc_zoneexplorer_113894() : CreatureScript("npc_zoneexplorer_113894") { }
    struct npc_zoneexplorer_113894AI : public ScriptedAI
    {
        npc_zoneexplorer_113894AI(Creature* creature) : ScriptedAI(creature) { }
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(40010) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->IsInDist(me, 2.0f))
                    {
                        player->KilledMonsterCredit(113894);
                    }
                }
            }
        }
    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_zoneexplorer_113894AI(creature);
    }
};

// 102600
class npc_gossip_102600 : public CreatureScript
{
public:
    npc_gossip_102600() : CreatureScript("npc_gossip_102600") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(40010) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(102600);
        }
        return true;
    }
};

struct npc_astoril : public ScriptedAI
{
    npc_astoril(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        if (player->HasQuest(QUEST_A_Way_Back_In))
        {
            if (gossipListId == 0)
            {
                player->KilledMonsterCredit(100226);
                CloseGossipMenuFor(player);
            }
        }
    }
};

//fly spell 215595,

void AddSC_suramar()
{
    new Player_Spell_Masquerade();
    RegisterCreatureAI(npc_cyrille_107350);
    RegisterCreatureAI(npc_astoril);
    RegisterCreatureAI(npc_lorin_107349);
    RegisterCreatureAI(npc_sylessa_107348);
    RegisterCreatureAI(npc_gondolier_107225);
    new npc_thallyssra_97140();
    new npc_zoneexplorer_113893();
    new npc_zoneexplorer_113894();
    new npc_gossip_102600();
}
