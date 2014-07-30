/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDName: Eversong_Woods
SD%Complete: 95
SDComment: Quest support: 8490
SDCategory: Eversong Woods
EndScriptData */

/* ContentData
npc_infused_crystal
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Player.h"


/*######
## npc_infused_crystal
######*/

enum InfusedCrystal
{
    // Quest
    QUEST_POWERING_OUR_DEFENSES     = 8490,

    // Quest Credit
    QUEST_POD_CREDIT = 16364,

    // Says
    EMOTE                           = 0,

    // Creatures
    NPC_ENRAGED_WRAITH              = 17086
};

struct Location
{
    float x, y, z;
};

static Location SpawnLocations[] =
{
    {8270.68f, -7188.53f, 139.619f},
    {8284.27f, -7187.78f, 139.603f},
    {8297.43f, -7193.53f, 139.603f},
    {8303.5f, -7201.96f, 139.577f},
    {8273.22f, -7241.82f, 139.382f},
    {8254.89f, -7222.12f, 139.603f},
    {8278.51f, -7242.13f, 139.162f},
    {8267.97f, -7239.17f, 139.517f}
};

class npc_infused_crystal : public CreatureScript
{
public:
    npc_infused_crystal() : CreatureScript("npc_infused_crystal") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_infused_crystalAI(creature);
    }

    struct npc_infused_crystalAI : public ScriptedAI
    {
        npc_infused_crystalAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
        }

        uint32 EndTimer;
        uint32 WaveTimer;
        bool Completed;
        bool Progress;
        uint64 PlayerGUID;

        void Reset() override
        {
            EndTimer = 0;
            Completed = false;
            Progress = false;
            PlayerGUID = 0;
            WaveTimer = 0;
        }

        void MoveInLineOfSight(Unit* who) override

        {
            if (!Progress && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 10.0f))
            {
                if (who->ToPlayer()->GetQuestStatus(QUEST_POWERING_OUR_DEFENSES) == QUEST_STATUS_INCOMPLETE)
                {
                    PlayerGUID = who->GetGUID();
                    WaveTimer = 1000;
                    EndTimer = 60000;
                    Progress = true;
                }
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->AI()->AttackStart(me);
        }

        void UpdateAI(uint32 diff) override
        {
            if (EndTimer < diff && Progress)
            {
                Completed = true;
                if (PlayerGUID)
                    if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                    {
                        Talk(EMOTE, player);
                        player->KilledMonsterCredit(QUEST_POD_CREDIT);
                    }
                me->RemoveCorpse();
            } else EndTimer -= diff;

            if (WaveTimer < diff && !Completed && Progress)
            {
                uint32 ran1 = rand32() % 8;
                uint32 ran2 = rand32() % 8;
                uint32 ran3 = rand32() % 8;
                me->SummonCreature(NPC_ENRAGED_WRAITH, SpawnLocations[ran1].x, SpawnLocations[ran1].y, SpawnLocations[ran1].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
                me->SummonCreature(NPC_ENRAGED_WRAITH, SpawnLocations[ran2].x, SpawnLocations[ran2].y, SpawnLocations[ran2].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
                me->SummonCreature(NPC_ENRAGED_WRAITH, SpawnLocations[ran3].x, SpawnLocations[ran3].y, SpawnLocations[ran3].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
                WaveTimer = 30000;
            } else WaveTimer -= diff;
        }
    };
};

void AddSC_eversong_woods()
{
    new npc_infused_crystal();
}
