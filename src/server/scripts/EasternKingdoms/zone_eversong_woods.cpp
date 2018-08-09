/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2011-2018 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2018 MaNGOS <https://getmangos.com/>
 * Copyright (C) 2006-2014 ScriptDev2 <https://github.com/scriptdev2/scriptdev2/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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
#include "Player.h"
#include "Unit.h"
#include "UnitAI.h"
#include "ObjectAccessor.h"
#include "Object.h"
#include "QuestDef.h"

enum UnexpectedResults
{
    // Quest
    QUEST_UNEXPECTED_RESULT         = 8488,

    // Creatures
    NPC_GHARZUL                     = 15958,
    NPC_ANGERSHADE                  = 15656
};

// 15402
struct npc_apprentice_mirveda : public ScriptedAI
{
    npc_apprentice_mirveda(Creature* creature) : ScriptedAI(creature) { }

    uint32 KillCount;
    ObjectGuid PlayerGUID;

    void Reset() override
    {
        KillCount = 0;
        PlayerGUID = ObjectGuid::Empty;
        summons.DespawnAll();
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_UNEXPECTED_RESULT)
        {
            PlayerGUID = player->GetGUID();

            me->SummonCreature(NPC_GHARZUL, 8745, -7134.32f, 35.22f, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
            me->SummonCreature(NPC_ANGERSHADE, 8745, -7134.32f, 35.22f, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
            me->SummonCreature(NPC_ANGERSHADE, 8745, -7134.32f, 35.22f, 0, TEMPSUMMON_CORPSE_DESPAWN, 4000);
        }
    }

    void EnterCombat(Unit* /*who*/) override { }

    void JustSummoned(Creature* summoned) override
    {
        summoned->AI()->AttackStart(me);
        summons.Summon(summoned);
    }

    void SummonedCreatureDespawn(Creature* summoned) override
    {
        summons.Despawn(summoned);

        if (++KillCount >= 3 && !PlayerGUID.IsEmpty())
            if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                player->CompleteQuest(QUEST_UNEXPECTED_RESULT);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (!PlayerGUID.IsEmpty())
            if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                player->FailQuest(QUEST_UNEXPECTED_RESULT);
    }
};

/*######
## npc_infused_crystal
######*/

enum InfusedCrystal
{
    // Quest
    QUEST_POWERING_OUR_DEFENSES     = 8490,

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
    {8303.5f,  -7201.96f, 139.577f},
    {8273.22f, -7241.82f, 139.382f},
    {8254.89f, -7222.12f, 139.603f},
    {8278.51f, -7242.13f, 139.162f},
    {8267.97f, -7239.17f, 139.517f}
};

// 16364
struct npc_infused_crystal : public ScriptedAI
{
    npc_infused_crystal(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
    }

    uint32 EndTimer;
    uint32 WaveTimer;
    bool Completed;
    bool Progress;
    ObjectGuid PlayerGUID;

    void Reset() override
    {
        EndTimer = 0;
        Completed = false;
        Progress = false;
        PlayerGUID = ObjectGuid::Empty;
        WaveTimer = 0;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!Progress && who->IsPlayer() && me->IsWithinDistInMap(who, 10.0f))
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

    void JustDied(Unit* /*killer*/) override
    {
        if (!PlayerGUID.IsEmpty() && !Completed)
            if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                player->FailQuest(QUEST_POWERING_OUR_DEFENSES);
    }

    void UpdateAI(uint32 diff) override
    {
        if (EndTimer < diff && Progress)
        {
            Talk(EMOTE);
            Completed = true;
            if (!PlayerGUID.IsEmpty())
                if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                    player->CompleteQuest(QUEST_POWERING_OUR_DEFENSES);

            me->DisappearAndDie();

        } else EndTimer -= diff;

        if (WaveTimer < diff && !Completed && Progress)
        {
            for (uint8 i = 0; i < 3; ++i)
            {
                uint32 randLocation = urand(0, 7);
                me->SummonCreature(NPC_ENRAGED_WRAITH, SpawnLocations[randLocation].x, SpawnLocations[randLocation].y, SpawnLocations[randLocation].z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
            }

            WaveTimer = 30000;
        } else WaveTimer -= diff;
    }
};

void AddSC_eversong_woods()
{
    RegisterCreatureAI(npc_apprentice_mirveda);
    RegisterCreatureAI(npc_infused_crystal);
}
