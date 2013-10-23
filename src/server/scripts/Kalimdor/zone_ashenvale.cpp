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
SDName: Ashenvale
SD%Complete: 70
SDComment: Quest support: 6544, 6482
SDCategory: Ashenvale Forest
EndScriptData */

/* ContentData
npc_torek
npc_ruul_snowhoof
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Player.h"

/*####
# npc_torek
####*/

enum TorekSays
{
    SAY_READY                  = 0,
    SAY_MOVE                   = 1,
    SAY_PREPARE                = 2,
    SAY_WIN                    = 3,
    SAY_END                    = 4,
};

enum TorekSpells
{
    SPELL_REND                  = 11977,
    SPELL_THUNDERCLAP           = 8078,
};

enum TorekMisc
{
    QUEST_TOREK_ASSULT          = 6544,

    ENTRY_SPLINTERTREE_RAIDER   = 12859,
    ENTRY_DURIEL                = 12860,
    ENTRY_SILVERWING_SENTINEL   = 12896,
    ENTRY_SILVERWING_WARRIOR    = 12897,
};

class npc_torek : public CreatureScript
{
    public:

        npc_torek() : CreatureScript("npc_torek")
        {
        }

        struct npc_torekAI : public npc_escortAI
        {
            npc_torekAI(Creature* creature) : npc_escortAI(creature) { }

            uint32 Rend_Timer;
            uint32 Thunderclap_Timer;
            bool Completed;

            void WaypointReached(uint32 waypointId) OVERRIDE
            {
                if (Player* player = GetPlayerForEscort())
                {
                    switch (waypointId)
                    {
                        case 1:
                            Talk(SAY_MOVE, player->GetGUID());
                            break;
                        case 8:
                            Talk(SAY_PREPARE, player->GetGUID());
                            break;
                        case 19:
                            /// @todo verify location and creatures amount.
                            me->SummonCreature(ENTRY_DURIEL, 1776.73f, -2049.06f, 109.83f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                            me->SummonCreature(ENTRY_SILVERWING_SENTINEL, 1774.64f, -2049.41f, 109.83f, 1.40f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                            me->SummonCreature(ENTRY_SILVERWING_WARRIOR, 1778.73f, -2049.50f, 109.83f, 1.67f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                            break;
                        case 20:
                            Talk(SAY_WIN, player->GetGUID());
                            Completed = true;
                            player->GroupEventHappens(QUEST_TOREK_ASSULT, me);
                            break;
                        case 21:
                            Talk(SAY_END, player->GetGUID());
                            break;
                    }
                }
            }

            void Reset() OVERRIDE
            {
                Rend_Timer = 5000;
                Thunderclap_Timer = 8000;
                Completed = false;
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
            }

            void JustSummoned(Creature* summoned) OVERRIDE
            {
                summoned->AI()->AttackStart(me);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                npc_escortAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                if (Rend_Timer <= diff)
                {
                    DoCastVictim(SPELL_REND);
                    Rend_Timer = 20000;
                } else Rend_Timer -= diff;

                if (Thunderclap_Timer <= diff)
                {
                    DoCast(me, SPELL_THUNDERCLAP);
                    Thunderclap_Timer = 30000;
                } else Thunderclap_Timer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_torekAI(creature);
        }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
        {
            if (quest->GetQuestId() == QUEST_TOREK_ASSULT)
            {
                /// @todo find companions, make them follow Torek, at any time (possibly done by core/database in future?)
                creature->AI()->Talk(SAY_READY, player->GetGUID());
                creature->setFaction(113);

                if (npc_escortAI* pEscortAI = CAST_AI(npc_torekAI, creature->AI()))
                    pEscortAI->Start(true, true, player->GetGUID());
            }

            return true;
        }
};

/*####
# npc_ruul_snowhoof
####*/

enum RuulSnowhoof
{
    NPC_THISTLEFUR_URSA         = 3921,
    NPC_THISTLEFUR_TOTEMIC      = 3922,
    NPC_THISTLEFUR_PATHFINDER   = 3926,

    QUEST_FREEDOM_TO_RUUL       = 6482,

    GO_CAGE                     = 178147
};

Position const RuulSnowhoofSummonsCoord[6] =
{
    {3449.218018f, -587.825073f, 174.978867f, 4.714445f},
    {3446.384521f, -587.830872f, 175.186279f, 4.714445f},
    {3444.218994f, -587.835327f, 175.380600f, 4.714445f},
    {3508.344482f, -492.024261f, 186.929031f, 4.145029f},
    {3506.265625f, -490.531006f, 186.740128f, 4.239277f},
    {3503.682373f, -489.393799f, 186.629684f, 4.349232f}
};

class npc_ruul_snowhoof : public CreatureScript
{
    public:
        npc_ruul_snowhoof() : CreatureScript("npc_ruul_snowhoof") { }

        struct npc_ruul_snowhoofAI : public npc_escortAI
        {
            npc_ruul_snowhoofAI(Creature* creature) : npc_escortAI(creature) { }

            void WaypointReached(uint32 waypointId) OVERRIDE
            {
                Player* player = GetPlayerForEscort();
                if (!player)
                    return;

                switch (waypointId)
                {
                    case 0:
                        me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                        if (GameObject* Cage = me->FindNearestGameObject(GO_CAGE, 20))
                            Cage->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case 13:
                        me->SummonCreature(NPC_THISTLEFUR_TOTEMIC, RuulSnowhoofSummonsCoord[0], TEMPSUMMON_DEAD_DESPAWN, 60000);
                        me->SummonCreature(NPC_THISTLEFUR_URSA, RuulSnowhoofSummonsCoord[1], TEMPSUMMON_DEAD_DESPAWN, 60000);
                        me->SummonCreature(NPC_THISTLEFUR_PATHFINDER, RuulSnowhoofSummonsCoord[2], TEMPSUMMON_DEAD_DESPAWN, 60000);
                        break;
                    case 19:
                        me->SummonCreature(NPC_THISTLEFUR_TOTEMIC, RuulSnowhoofSummonsCoord[3], TEMPSUMMON_DEAD_DESPAWN, 60000);
                        me->SummonCreature(NPC_THISTLEFUR_URSA, RuulSnowhoofSummonsCoord[4], TEMPSUMMON_DEAD_DESPAWN, 60000);
                        me->SummonCreature(NPC_THISTLEFUR_PATHFINDER, RuulSnowhoofSummonsCoord[5], TEMPSUMMON_DEAD_DESPAWN, 60000);
                        break;
                    case 21:
                        player->GroupEventHappens(QUEST_FREEDOM_TO_RUUL, me);
                        break;
                }
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE {}

            void Reset() OVERRIDE
            {
                if (GameObject* Cage = me->FindNearestGameObject(GO_CAGE, 20))
                    Cage->SetGoState(GO_STATE_READY);
            }

            void JustSummoned(Creature* summoned) OVERRIDE
            {
                summoned->AI()->AttackStart(me);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                npc_escortAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_ruul_snowhoofAI(creature);
        }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
        {
            if (quest->GetQuestId() == QUEST_FREEDOM_TO_RUUL)
            {
                creature->setFaction(113);

                if (npc_escortAI* pEscortAI = CAST_AI(npc_ruul_snowhoofAI, (creature->AI())))
                    pEscortAI->Start(true, false, player->GetGUID());
            }

            return true;
        }
};

enum Muglash
{
    SAY_MUG_START1          = 0,
    SAY_MUG_START2          = 1,
    SAY_MUG_BRAZIER         = 2,
    SAY_MUG_BRAZIER_WAIT    = 3,
    SAY_MUG_ON_GUARD        = 4,
    SAY_MUG_REST            = 5,
    SAY_MUG_DONE            = 6,
    SAY_MUG_GRATITUDE       = 7,
    SAY_MUG_PATROL          = 8,
    SAY_MUG_RETURN          = 9,

    QUEST_VORSHA            = 6641,

    GO_NAGA_BRAZIER         = 178247,

    NPC_WRATH_RIDER         = 3713,
    NPC_WRATH_SORCERESS     = 3717,
    NPC_WRATH_RAZORTAIL     = 3712,

    NPC_WRATH_PRIESTESS     = 3944,
    NPC_WRATH_MYRMIDON      = 3711,
    NPC_WRATH_SEAWITCH      = 3715,

    NPC_VORSHA              = 12940,
    NPC_MUGLASH             = 12717
};

Position const FirstNagaCoord[3] =
{
    {3603.504150f, 1122.631104f, 1.635f, 0.0f},         // rider
    {3589.293945f, 1148.664063f, 5.565f, 0.0f},         // sorceress
    {3609.925537f, 1168.759521f, -1.168f, 0.0f}         // razortail
};

Position const SecondNagaCoord[3] =
{
    {3609.925537f, 1168.759521f, -1.168f, 0.0f},        // witch
    {3645.652100f, 1139.425415f, 1.322f, 0.0f},         // priest
    {3583.602051f, 1128.405762f, 2.347f, 0.0f}          // myrmidon
};

Position const VorshaCoord = {3633.056885f, 1172.924072f, -5.388f, 0.0f};

class npc_muglash : public CreatureScript
{
    public:
        npc_muglash() : CreatureScript("npc_muglash") { }

        struct npc_muglashAI : public npc_escortAI
        {
            npc_muglashAI(Creature* creature) : npc_escortAI(creature) { }

            uint8 WaveId;
            uint32 EventTimer;
            bool IsBrazierExtinguished;

            void JustSummoned(Creature* summoned) OVERRIDE
            {
                summoned->AI()->AttackStart(me);
            }

            void WaypointReached(uint32 waypointId) OVERRIDE
            {
                if (Player* player = GetPlayerForEscort())
                {
                    switch (waypointId)
                    {
                        case 0:
                            Talk(SAY_MUG_START2, player->GetGUID());
                            break;
                        case 24:
                            Talk(SAY_MUG_BRAZIER, player->GetGUID());

                            if (GameObject* go = GetClosestGameObjectWithEntry(me, GO_NAGA_BRAZIER, INTERACTION_DISTANCE*2))
                            {
                                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                                SetEscortPaused(true);
                            }
                            break;
                        case 25:
                            Talk(SAY_MUG_GRATITUDE);
                            player->GroupEventHappens(QUEST_VORSHA, me);
                            break;
                        case 26:
                            Talk(SAY_MUG_PATROL);
                            break;
                        case 27:
                            Talk(SAY_MUG_RETURN);
                            break;
                    }
                }
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                if (Player* player = GetPlayerForEscort())
                    if (HasEscortState(STATE_ESCORT_PAUSED))
                    {
                        if (urand(0, 1))
                            Talk(SAY_MUG_ON_GUARD, player->GetGUID());
                        return;
                    }
            }

            void Reset() OVERRIDE
            {
                EventTimer = 10000;
                WaveId = 0;
                IsBrazierExtinguished = false;
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                if (HasEscortState(STATE_ESCORT_ESCORTING))
                    if (Player* player = GetPlayerForEscort())
                        player->FailQuest(QUEST_VORSHA);
            }

            void DoWaveSummon()
            {
                switch (WaveId)
                {
                    case 1:
                        me->SummonCreature(NPC_WRATH_RIDER,     FirstNagaCoord[0], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        me->SummonCreature(NPC_WRATH_SORCERESS, FirstNagaCoord[1], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        me->SummonCreature(NPC_WRATH_RAZORTAIL, FirstNagaCoord[2], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        break;
                    case 2:
                        me->SummonCreature(NPC_WRATH_PRIESTESS, SecondNagaCoord[0], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        me->SummonCreature(NPC_WRATH_MYRMIDON,  SecondNagaCoord[1], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        me->SummonCreature(NPC_WRATH_SEAWITCH,  SecondNagaCoord[2], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        break;
                    case 3:
                        me->SummonCreature(NPC_VORSHA, VorshaCoord, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        break;
                    case 4:
                        SetEscortPaused(false);
                        Talk(SAY_MUG_DONE);
                        break;
                }
            }

            void UpdateAI(uint32 uiDiff) OVERRIDE
            {
                npc_escortAI::UpdateAI(uiDiff);

                if (!me->GetVictim())
                {
                    if (HasEscortState(STATE_ESCORT_PAUSED) && IsBrazierExtinguished)
                    {
                        if (EventTimer < uiDiff)
                        {
                            ++WaveId;
                            DoWaveSummon();
                            EventTimer = 10000;
                        }
                        else
                            EventTimer -= uiDiff;
                    }
                    return;
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_muglashAI(creature);
        }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
        {
            if (quest->GetQuestId() == QUEST_VORSHA)
            {
                if (npc_muglashAI* pEscortAI = CAST_AI(npc_muglashAI, creature->AI()))
                {
                    creature->AI()->Talk(SAY_MUG_START1);
                    creature->setFaction(113);

                    pEscortAI->Start(true, false, player->GetGUID());
                }
            }
            return true;
        }
};

class go_naga_brazier : public GameObjectScript
{
    public:
        go_naga_brazier() : GameObjectScript("go_naga_brazier") { }

        bool OnGossipHello(Player* /*player*/, GameObject* go) OVERRIDE
        {
            if (Creature* creature = GetClosestCreatureWithEntry(go, NPC_MUGLASH, INTERACTION_DISTANCE*2))
            {
                if (npc_muglash::npc_muglashAI* pEscortAI = CAST_AI(npc_muglash::npc_muglashAI, creature->AI()))
                {
                    creature->AI()->Talk(SAY_MUG_BRAZIER_WAIT);

                    pEscortAI->IsBrazierExtinguished = true;
                    return false;
                }
            }

            return true;
        }
};

void AddSC_ashenvale()
{
    new npc_torek();
    new npc_ruul_snowhoof();
    new npc_muglash();
    new go_naga_brazier();
}
