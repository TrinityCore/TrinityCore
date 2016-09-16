 /*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
SDName: Silverpine_Forest
SD%Complete: 100
SDComment: Quest support: 435, 452
SDCategory: Silverpine Forest
EndScriptData */

/* ContentData
npc_deathstalker_erland
pyrewood_ambush
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Player.h"

/*######
## npc_deathstalker_erland
######*/

enum Erland
{
    SAY_QUESTACCEPT     = 0,
    SAY_START           = 1,
    SAY_AGGRO           = 2,
    SAY_PROGRESS        = 3,
    SAY_LAST            = 4,

    SAY_RANE            = 0,
    SAY_RANE_ANSWER     = 5,
    SAY_MOVE_QUINN      = 6,

    SAY_QUINN           = 7,
    SAY_QUINN_ANSWER    = 0,
    SAY_BYE             = 8,

    QUEST_ESCORTING     = 435,
    NPC_RANE            = 1950,
    NPC_QUINN           = 1951
};

class npc_deathstalker_erland : public CreatureScript
{
public:
    npc_deathstalker_erland() : CreatureScript("npc_deathstalker_erland") { }

    struct npc_deathstalker_erlandAI : public npc_escortAI
    {
        npc_deathstalker_erlandAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 1:
                    Talk(SAY_START, player);
                    break;
                case 10:
                    Talk(SAY_PROGRESS);
                    break;
                case 13:
                    Talk(SAY_LAST, player);
                    player->GroupEventHappens(QUEST_ESCORTING, me);
                    break;
                case 15:
                    if (Creature* rane = me->FindNearestCreature(NPC_RANE, 20.0f))
                        rane->AI()->Talk(SAY_RANE);
                    break;
                case 16:
                    Talk(SAY_RANE_ANSWER);
                    break;
                case 17:
                    Talk(SAY_MOVE_QUINN);
                    break;
                case 24:
                    Talk(SAY_QUINN);
                    break;
                case 25:
                    if (Creature* quinn = me->FindNearestCreature(NPC_QUINN, 20.0f))
                        quinn->AI()->Talk(SAY_QUINN_ANSWER);
                    break;
                case 26:
                    Talk(SAY_BYE);
                    break;
            }
        }

        void Reset() override { }

        void EnterCombat(Unit* who) override
        {
            Talk(SAY_AGGRO, who);
        }
    };

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_ESCORTING)
        {
            creature->AI()->Talk(SAY_QUESTACCEPT, player);

            if (npc_escortAI* pEscortAI = CAST_AI(npc_deathstalker_erland::npc_deathstalker_erlandAI, creature->AI()))
                pEscortAI->Start(true, false, player->GetGUID());
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_deathstalker_erlandAI(creature);
    }
};

/*######
## pyrewood_ambush
#######*/

enum PyrewoodAmbush
{
    SAY_PREPARE_TO_AMBUSH = 0,
    SAY_A_BLOW_TO_ARUGAL  = 1,
    FACTION_ENEMY         = 168,
    QUEST_PYREWOOD_AMBUSH = 452,
    COUNCILMAN_SMITHERS   = 2060,
    COUNCILMAN_THATCHER   = 2061,
    COUNCILMAN_HENDRICKS  = 2062,
    COUNCILMAN_WILHELM    = 2063,
    COUNCILMAN_HARTIN     = 2064,
    COUNCILMAN_COOPER     = 2065,
    COUNCILMAN_HIGARTH    = 2066,
    COUNCILMAN_BRUNSWICK  = 2067,
    LORD_MAYOR_MORRISON   = 2068
};

static float PyrewoodSpawnPoints[3][4] =
{
    //pos_x   pos_y     pos_z    orien
    //outside
    /*
    {-400.85f, 1513.64f, 18.67f, 0},
    {-397.32f, 1514.12f, 18.67f, 0},
    {-397.44f, 1511.09f, 18.67f, 0},
    */
    //door
    {-396.17f, 1505.86f, 19.77f, 0},
    {-396.91f, 1505.77f, 19.77f, 0},
    {-397.94f, 1504.74f, 19.77f, 0},
};

class pyrewood_ambush : public CreatureScript
{
public:
    pyrewood_ambush() : CreatureScript("pyrewood_ambush") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest *quest) override
    {
        if (quest->GetQuestId() == QUEST_PYREWOOD_AMBUSH && !ENSURE_AI(pyrewood_ambush::pyrewood_ambushAI, creature->AI())->QuestInProgress)
        {
            ENSURE_AI(pyrewood_ambush::pyrewood_ambushAI, creature->AI())->QuestInProgress = true;
            ENSURE_AI(pyrewood_ambush::pyrewood_ambushAI, creature->AI())->Phase = 0;
            ENSURE_AI(pyrewood_ambush::pyrewood_ambushAI, creature->AI())->KillCount = 0;
            ENSURE_AI(pyrewood_ambush::pyrewood_ambushAI, creature->AI())->PlayerGUID = player->GetGUID();
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new pyrewood_ambushAI(creature);
    }

    struct pyrewood_ambushAI : public ScriptedAI
    {
        pyrewood_ambushAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            Initialize();
            WaitTimer = 6 * IN_MILLISECONDS;
            QuestInProgress = false;
        }

        void Initialize()
        {
            Phase = 0;
            KillCount = 0;
            PlayerGUID.Clear();
        }

        uint32 Phase;
        int8 KillCount;
        uint32 WaitTimer;
        ObjectGuid PlayerGUID;
        SummonList Summons;

        bool QuestInProgress;

        void Reset() override
        {
            WaitTimer = 6 * IN_MILLISECONDS;

            if (!QuestInProgress) //fix reset values (see UpdateVictim)
            {
                Initialize();
                Summons.DespawnAll();
            }
        }

        void EnterCombat(Unit* /*who*/) override { }

        void JustSummoned(Creature* summoned) override
        {
            Summons.Summon(summoned);
            ++KillCount;
        }

        void SummonedCreatureDespawn(Creature* summoned) override
        {
            Summons.Despawn(summoned);
            --KillCount;
        }

        void SummonCreatureWithRandomTarget(uint32 creatureId, int position)
        {
            if (Creature* summoned = me->SummonCreature(creatureId, PyrewoodSpawnPoints[position][0], PyrewoodSpawnPoints[position][1], PyrewoodSpawnPoints[position][2], PyrewoodSpawnPoints[position][3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000))
            {
                Unit* target = NULL;
                if (PlayerGUID)
                    if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                        if (player->IsAlive() && RAND(0, 1))
                            target = player;

                if (!target)
                    target = me;

                summoned->setFaction(FACTION_ENEMY);
                summoned->AddThreat(target, 32.0f);
                summoned->AI()->AttackStart(target);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (PlayerGUID)
                if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                    if (player->GetQuestStatus(QUEST_PYREWOOD_AMBUSH) == QUEST_STATUS_INCOMPLETE)
                        player->FailQuest(QUEST_PYREWOOD_AMBUSH);
        }

        void UpdateAI(uint32 diff) override
        {
            //TC_LOG_INFO("scripts", "DEBUG: p(%i) k(%i) d(%u) W(%i)", Phase, KillCount, diff, WaitTimer);

            if (!QuestInProgress)
                return;

            if (KillCount && Phase < 6)
            {
                if (!UpdateVictim()) //reset() on target Despawn...
                    return;

                DoMeleeAttackIfReady();
                return;
            }

            switch (Phase)
            {
                case 0:
                    if (WaitTimer == 6 * IN_MILLISECONDS)
                        if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                            Talk(SAY_PREPARE_TO_AMBUSH, player);

                    if (WaitTimer <= diff)
                    {
                        WaitTimer -= diff;
                        return;
                    }
                    break;
                case 1:
                    SummonCreatureWithRandomTarget(COUNCILMAN_SMITHERS, 1);
                    break;
                case 2:
                    SummonCreatureWithRandomTarget(COUNCILMAN_THATCHER, 2);
                    SummonCreatureWithRandomTarget(COUNCILMAN_HENDRICKS, 0);
                    break;
                case 3:
                    SummonCreatureWithRandomTarget(COUNCILMAN_WILHELM, 1);
                    SummonCreatureWithRandomTarget(COUNCILMAN_HARTIN, 2);
                    SummonCreatureWithRandomTarget(COUNCILMAN_COOPER, 0);
                    break;
                case 4:
                    SummonCreatureWithRandomTarget(COUNCILMAN_HIGARTH, 1);
                    SummonCreatureWithRandomTarget(COUNCILMAN_BRUNSWICK, 0);
                    SummonCreatureWithRandomTarget(LORD_MAYOR_MORRISON, 2);
                    break;
                case 5: //end
                    if (PlayerGUID)
                    {
                        if (Player* player = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                        {
                            Talk(SAY_A_BLOW_TO_ARUGAL);
                            player->GroupEventHappens(QUEST_PYREWOOD_AMBUSH, me);
                        }
                    }
                    QuestInProgress = false;
                    Reset();
                    break;
            }
            ++Phase; //prepare next phase
        }
    };
};

/*######
## AddSC
######*/

void AddSC_silverpine_forest()
{
    new npc_deathstalker_erland();
    new pyrewood_ambush();
}
