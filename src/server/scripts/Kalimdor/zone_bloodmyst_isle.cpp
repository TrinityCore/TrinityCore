/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Bloodmyst_Isle
SD%Complete: 80
SDComment: Quest support: 9670, 9756(gossip items text needed).
SDCategory: Bloodmyst Isle
EndScriptData */

/* ContentData
npc_webbed_creature
npc_captured_sunhawk_agent
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"

/*######
## npc_webbed_creature
######*/

//possible creatures to be spawned
uint32 const possibleSpawns[32] = {17322, 17661, 17496, 17522, 17340, 17352, 17333, 17524, 17654, 17348, 17339, 17345, 17359, 17353, 17336, 17550, 17330, 17701, 17321, 17680, 17325, 17320, 17683, 17342, 17715, 17334, 17341, 17338, 17337, 17346, 17344, 17327};

class npc_webbed_creature : public CreatureScript
{
public:
    npc_webbed_creature() : CreatureScript("npc_webbed_creature") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_webbed_creatureAI(creature);
    }

    struct npc_webbed_creatureAI : public ScriptedAI
    {
        npc_webbed_creatureAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() OVERRIDE {}

        void EnterCombat(Unit* /*who*/) OVERRIDE {}

        void JustDied(Unit* killer) OVERRIDE
        {
            uint32 spawnCreatureID = 0;

            switch (urand(0, 2))
            {
                case 0:
                    spawnCreatureID = 17681;
                    if (Player* player = killer->ToPlayer())
                        player->KilledMonsterCredit(spawnCreatureID, 0);
                    break;
                case 1:
                case 2:
                    spawnCreatureID = possibleSpawns[urand(0, 30)];
                    break;
            }

            if (spawnCreatureID)
                me->SummonCreature(spawnCreatureID, 0.0f, 0.0f, 0.0f, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
        }
    };

};

/*######
## npc_captured_sunhawk_agent
######*/

#define C_SUNHAWK_TRIGGER 17974

#define GOSSIP_HELLO_CSA     "[PH] "
#define GOSSIP_SELECT_CSA1   "[PH] "
#define GOSSIP_SELECT_CSA2   "[PH] "
#define GOSSIP_SELECT_CSA3   "[PH] "
#define GOSSIP_SELECT_CSA4   "[PH] "
#define GOSSIP_SELECT_CSA5   "[PH] "

class npc_captured_sunhawk_agent : public CreatureScript
{
public:
    npc_captured_sunhawk_agent() : CreatureScript("npc_captured_sunhawk_agent") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_CSA1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(9137, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_CSA2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                player->SEND_GOSSIP_MENU(9138, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_CSA3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                player->SEND_GOSSIP_MENU(9139, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_CSA4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                player->SEND_GOSSIP_MENU(9140, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_CSA5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                player->SEND_GOSSIP_MENU(9141, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                player->CLOSE_GOSSIP_MENU();
                player->TalkedToCreature(C_SUNHAWK_TRIGGER, creature->GetGUID());
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (player->HasAura(31609) && player->GetQuestStatus(9756) == QUEST_STATUS_INCOMPLETE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_CSA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(9136, creature->GetGUID());
        }
        else
            player->SEND_GOSSIP_MENU(9134, creature->GetGUID());

        return true;
    }

};

/*######
## Quest 9667: Saving Princess Stillpine
######*/

enum Stillpine
{
    QUEST_SAVING_PRINCESS_STILLPINE               = 9667,
    NPC_PRINCESS_STILLPINE                        = 17682,
    GO_PRINCESS_STILLPINES_CAGE                   = 181928,
    SPELL_OPENING_PRINCESS_STILLPINE_CREDIT       = 31003,
    SAY_DIRECTION                                 = 0
};

class go_princess_stillpines_cage : public GameObjectScript
{
public:
    go_princess_stillpines_cage() : GameObjectScript("go_princess_stillpines_cage") { }

    bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
    {
        go->SetGoState(GO_STATE_READY);
        if (Creature* stillpine = go->FindNearestCreature(NPC_PRINCESS_STILLPINE, 25, true))
        {
            stillpine->GetMotionMaster()->MovePoint(1, go->GetPositionX(), go->GetPositionY()-15, go->GetPositionZ());
            player->KilledMonsterCredit(NPC_PRINCESS_STILLPINE, stillpine->GetGUID());
        }
        return true;
    }
};

class npc_princess_stillpine : public CreatureScript
{
public:
    npc_princess_stillpine() : CreatureScript("npc_princess_stillpine") { }

    struct npc_princess_stillpineAI : public ScriptedAI
    {
        npc_princess_stillpineAI(Creature* creature) : ScriptedAI(creature) { }

        void MovementInform(uint32 type, uint32 id) OVERRIDE
        {
            if (type == POINT_MOTION_TYPE && id == 1)
            {
                Talk(SAY_DIRECTION);
                me->DespawnOrUnsummon();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_princess_stillpineAI(creature);
    }
};

void AddSC_bloodmyst_isle()
{
    new npc_webbed_creature();
    new npc_captured_sunhawk_agent();
    new npc_princess_stillpine();
    new go_princess_stillpines_cage();
}
