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
SDComment: Quest support: 8487, 8488, 8490
SDCategory: Eversong Woods
EndScriptData */

/* ContentData
npc_apprentice_mirveda
npc_infused_crystal
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Player.h"

enum UnexpectedResults
{
    // Quest
    QUEST_CORRUPTED_SOIL            = 8487,
    QUEST_UNEXPECTED_RESULT         = 8488,

    // Creatures
    NPC_GHARZUL                     = 15958, // Quest 8488
    NPC_ANGERSHADE                  = 15656, // Quest 8488

    // Factions
    FACTION_NORMAL                  = 1604,  // Quest 8488
    FACTION_COMBAT                  = 232,   // Quest 8488

    // Spells
    SPELL_TEST_SOIL                 = 29535, // Quest 8487
    SPELL_FIREBALL                  = 20811, // Quest 8488

    // Text
    SAY_TEST_SOIL                   = 0,     // Quest 8487

    // Events
    EVENT_TALK                      = 1,     // Quest 8487
    EVENT_ADD_QUEST_GIVER_FLAG      = 2,     // Quest 8487
    EVENT_SUMMON                    = 3,     // Quest 8488
    EVENT_FIREBALL                  = 4      // Quest 8488
};

class npc_apprentice_mirveda : public CreatureScript
{
public:
    npc_apprentice_mirveda() : CreatureScript("npc_apprentice_mirveda") { }

    struct npc_apprentice_mirvedaAI : public ScriptedAI
    {
        npc_apprentice_mirvedaAI(Creature* creature) : ScriptedAI(creature), Summons(me) { }

        uint32 KillCount;
        uint64 PlayerGUID;
        SummonList Summons;
        EventMap events;

        void Reset() override
        {
            SetCombatMovement(false);
            KillCount = 0;
            PlayerGUID = 0;
            Summons.DespawnAll();
        }

        void sQuestReward(Player* /*player*/, Quest const* quest, uint32 /*opt*/) override
        {
            if (quest->GetQuestId() == QUEST_CORRUPTED_SOIL)
            {
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                events.ScheduleEvent(EVENT_TALK, 2000);
            }
        }

        void sQuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_UNEXPECTED_RESULT)
            {
                me->setFaction(FACTION_COMBAT);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                events.ScheduleEvent(EVENT_SUMMON, 1000);
                PlayerGUID = player->GetGUID();
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_FIREBALL, 1000);
        }

        void JustSummoned(Creature* summoned) override
        {
            // This is the best I can do because AttackStart does nothing
            summoned->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
            // summoned->AI()->AttackStart(me);
            Summons.Summon(summoned);
        }

        void SummonedCreatureDies(Creature* summoned, Unit* /*who*/) override
        {
            Summons.Despawn(summoned);
            ++KillCount;
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->setFaction(FACTION_NORMAL);

            if (PlayerGUID)
                if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                    player->FailQuest(QUEST_UNEXPECTED_RESULT);
        }

        void UpdateAI(uint32 diff) override
        {
            if (KillCount >= 3 && PlayerGUID)
                if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                    if (player->GetQuestStatus(QUEST_UNEXPECTED_RESULT) == QUEST_STATUS_INCOMPLETE)
                    {
                        player->CompleteQuest(QUEST_UNEXPECTED_RESULT);
                        me->setFaction(FACTION_NORMAL);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TALK:
                        Talk(SAY_TEST_SOIL);
                        events.ScheduleEvent(EVENT_ADD_QUEST_GIVER_FLAG, 7000);
                        break;
                    case EVENT_ADD_QUEST_GIVER_FLAG:
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        break;
                    case EVENT_SUMMON:
                        me->SummonCreature(NPC_GHARZUL,    8749.505f, -7132.595f, 35.31983f, 3.816502f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 180000);
                        me->SummonCreature(NPC_ANGERSHADE, 8755.38f,  -7131.521f, 35.30957f, 3.816502f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 180000);
                        me->SummonCreature(NPC_ANGERSHADE, 8753.199f, -7125.975f, 35.31986f, 3.816502f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 180000);
                        break;
                    case EVENT_FIREBALL:
                        if (!UpdateVictim())
                            continue;
                        DoCastVictim(SPELL_FIREBALL, true);  // Not casting in combat
                        events.ScheduleEvent(EVENT_FIREBALL, 3000);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_apprentice_mirvedaAI(creature);
    }
};

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
    new npc_apprentice_mirveda();
    new npc_infused_crystal();
}
