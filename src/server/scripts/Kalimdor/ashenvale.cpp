/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

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
            npc_torekAI(Creature* creature) : npc_escortAI(creature) {}

            uint32 Rend_Timer;
            uint32 Thunderclap_Timer;
            bool Completed;

            void WaypointReached(uint32 i)
            {
                Player* player = GetPlayerForEscort();

                if (!player)
                    return;

                switch (i)
                {
                case 1:
                    Talk(SAY_MOVE, player->GetGUID());
                    break;
                case 8:
                    Talk(SAY_PREPARE, player->GetGUID());
                    break;
                case 19:
                    //TODO: verify location and creatures amount.
                    me->SummonCreature(ENTRY_DURIEL, 1776.73f, -2049.06f, 109.83f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(ENTRY_SILVERWING_SENTINEL, 1774.64f, -2049.41f, 109.83f, 1.40f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(ENTRY_SILVERWING_WARRIOR, 1778.73f, -2049.50f, 109.83f, 1.67f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 20:
                    DoScriptText(SAY_WIN, me, player);
                    Completed = true;
                    if (player)
                        player->GroupEventHappens(QUEST_TOREK_ASSULT, me);
                    break;
                case 21:
                    Talk(SAY_END, player->GetGUID());
                    break;
                }
            }

            void Reset()
            {
                Rend_Timer = 5000;
                Thunderclap_Timer = 8000;
                Completed = false;
            }

            void EnterCombat(Unit* /*who*/)
            {
            }

            void JustSummoned(Creature* summoned)
            {
                summoned->AI()->AttackStart(me);
            }

            void UpdateAI(const uint32 diff)
            {
                npc_escortAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                if (Rend_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_REND);
                    Rend_Timer = 20000;
                } else Rend_Timer -= diff;

                if (Thunderclap_Timer <= diff)
                {
                    DoCast(me, SPELL_THUNDERCLAP);
                    Thunderclap_Timer = 30000;
                } else Thunderclap_Timer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_torekAI(creature);
        }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
        {
            if (quest->GetQuestId() == QUEST_TOREK_ASSULT)
            {
                //TODO: find companions, make them follow Torek, at any time (possibly done by core/database in future?)
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

#define QUEST_FREEDOM_TO_RUUL    6482
#define GO_CAGE                  178147

class npc_ruul_snowhoof : public CreatureScript
{
    public:

        npc_ruul_snowhoof()
            : CreatureScript("npc_ruul_snowhoof")
        {
        }

        struct npc_ruul_snowhoofAI : public npc_escortAI
        {
            npc_ruul_snowhoofAI(Creature* c) : npc_escortAI(c) {}

            void WaypointReached(uint32 i)
            {
                Player* player = GetPlayerForEscort();

                if (!player)
                    return;

                switch (i)
                {
                case 0:    {
                        me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                        GameObject* Cage = me->FindNearestGameObject(GO_CAGE, 20);
                        if (Cage)
                            Cage->SetGoState(GO_STATE_ACTIVE);
                        break;}
                case 13:
                        me->SummonCreature(3922, 3449.218018f, -587.825073f, 174.978867f, 4.714445f, TEMPSUMMON_DEAD_DESPAWN, 60000);
                        me->SummonCreature(3921, 3446.384521f, -587.830872f, 175.186279f, 4.714445f, TEMPSUMMON_DEAD_DESPAWN, 60000);
                        me->SummonCreature(3926, 3444.218994f, -587.835327f, 175.380600f, 4.714445f, TEMPSUMMON_DEAD_DESPAWN, 60000);
                        break;
                case 19:
                        me->SummonCreature(3922, 3508.344482f, -492.024261f, 186.929031f, 4.145029f, TEMPSUMMON_DEAD_DESPAWN, 60000);
                        me->SummonCreature(3921, 3506.265625f, -490.531006f, 186.740128f, 4.239277f, TEMPSUMMON_DEAD_DESPAWN, 60000);
                        me->SummonCreature(3926, 3503.682373f, -489.393799f, 186.629684f, 4.349232f, TEMPSUMMON_DEAD_DESPAWN, 60000);
                        break;

                case 21:{
                        if (player)
                            player->GroupEventHappens(QUEST_FREEDOM_TO_RUUL, me);

                        break;  }
                }
            }

            void EnterCombat(Unit* /*who*/) {}

            void Reset()
            {
                GameObject* Cage = me->FindNearestGameObject(GO_CAGE, 20);
                if (Cage)
                    Cage->SetGoState(GO_STATE_READY);
            }

            void JustSummoned(Creature* summoned)
            {
                summoned->AI()->AttackStart(me);
            }

            void UpdateAI(const uint32 diff)
            {
                npc_escortAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_ruul_snowhoofAI(creature);
        }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
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

enum eEnums
{
    SAY_MUG_START1          = -1800054,
    SAY_MUG_START2          = -1800055,
    SAY_MUG_BRAZIER         = -1800056,
    SAY_MUG_BRAZIER_WAIT    = -1800057,
    SAY_MUG_ON_GUARD        = -1800058,
    SAY_MUG_REST            = -1800059,
    SAY_MUG_DONE            = -1800060,
    SAY_MUG_GRATITUDE       = -1800061,
    SAY_MUG_PATROL          = -1800062,
    SAY_MUG_RETURN          = -1800063,

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

static float m_afFirstNagaCoord[3][3]=
{
    {3603.504150f, 1122.631104f, 1.635f},                      // rider
    {3589.293945f, 1148.664063f, 5.565f},                      // sorceress
    {3609.925537f, 1168.759521f, -1.168f}                      // razortail
};

static float m_afSecondNagaCoord[3][3]=
{
    {3609.925537f, 1168.759521f, -1.168f},                     // witch
    {3645.652100f, 1139.425415f, 1.322f},                      // priest
    {3583.602051f, 1128.405762f, 2.347f}                       // myrmidon
};

static float m_fVorshaCoord[]={3633.056885f, 1172.924072f, -5.388f};

class npc_muglash : public CreatureScript
{
    public:
        npc_muglash() : CreatureScript("npc_muglash") { }

        struct npc_muglashAI : public npc_escortAI
        {
            npc_muglashAI(Creature* creature) : npc_escortAI(creature) { }

            uint32 m_uiWaveId;
            uint32 m_uiEventTimer;
            bool m_bIsBrazierExtinguished;

            void JustSummoned(Creature* summoned)
            {
                summoned->AI()->AttackStart(me);
            }

            void WaypointReached(uint32 i)
            {
                Player* player = GetPlayerForEscort();

                switch (i)
                {
                    case 0:
                        if (player)
                            DoScriptText(SAY_MUG_START2, me, player);
                        break;
                    case 24:
                        if (player)
                            DoScriptText(SAY_MUG_BRAZIER, me, player);

                        if (GameObject* go = GetClosestGameObjectWithEntry(me, GO_NAGA_BRAZIER, INTERACTION_DISTANCE*2))
                        {
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            SetEscortPaused(true);
                        }
                        break;
                    case 25:
                        DoScriptText(SAY_MUG_GRATITUDE, me);

                        if (player)
                            player->GroupEventHappens(QUEST_VORSHA, me);
                        break;
                    case 26:
                        DoScriptText(SAY_MUG_PATROL, me);
                        break;
                    case 27:
                        DoScriptText(SAY_MUG_RETURN, me);
                        break;
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (Player* player = GetPlayerForEscort())
                    if (HasEscortState(STATE_ESCORT_PAUSED))
                    {
                        if (urand(0, 1))
                            DoScriptText(SAY_MUG_ON_GUARD, me, player);
                        return;
                    }
            }

            void Reset()
            {
                m_uiEventTimer = 10000;
                m_uiWaveId = 0;
                m_bIsBrazierExtinguished = false;
            }

            void JustDied(Unit* /*killer*/)
            {
                Player* player = GetPlayerForEscort();
                if (HasEscortState(STATE_ESCORT_ESCORTING))
                {
                    if (player)
                    {
                        player->FailQuest(QUEST_VORSHA);
                    }
                }
            }

            void DoWaveSummon()
            {
                switch (m_uiWaveId)
                {
                    case 1:
                        me->SummonCreature(NPC_WRATH_RIDER,     m_afFirstNagaCoord[0][0], m_afFirstNagaCoord[0][1], m_afFirstNagaCoord[0][2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        me->SummonCreature(NPC_WRATH_SORCERESS, m_afFirstNagaCoord[1][0], m_afFirstNagaCoord[1][1], m_afFirstNagaCoord[1][2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        me->SummonCreature(NPC_WRATH_RAZORTAIL, m_afFirstNagaCoord[2][0], m_afFirstNagaCoord[2][1], m_afFirstNagaCoord[2][2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        break;
                    case 2:
                        me->SummonCreature(NPC_WRATH_PRIESTESS, m_afSecondNagaCoord[0][0], m_afSecondNagaCoord[0][1], m_afSecondNagaCoord[0][2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        me->SummonCreature(NPC_WRATH_MYRMIDON,  m_afSecondNagaCoord[1][0], m_afSecondNagaCoord[1][1], m_afSecondNagaCoord[1][2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        me->SummonCreature(NPC_WRATH_SEAWITCH,  m_afSecondNagaCoord[2][0], m_afSecondNagaCoord[2][1], m_afSecondNagaCoord[2][2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        break;
                    case 3:
                        me->SummonCreature(NPC_VORSHA, m_fVorshaCoord[0], m_fVorshaCoord[1], m_fVorshaCoord[2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                        break;
                    case 4:
                        SetEscortPaused(false);
                        DoScriptText(SAY_MUG_DONE, me);
                        break;
                }
            }

            void UpdateAI(const uint32 uiDiff)
            {
                npc_escortAI::UpdateAI(uiDiff);

                if (!me->getVictim())
                {
                    if (HasEscortState(STATE_ESCORT_PAUSED) && m_bIsBrazierExtinguished)
                    {
                        if (m_uiEventTimer < uiDiff)
                        {
                            ++m_uiWaveId;
                            DoWaveSummon();
                            m_uiEventTimer = 10000;
                        }
                        else
                            m_uiEventTimer -= uiDiff;
                    }
                    return;
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_muglashAI(creature);
        }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
        {
            if (quest->GetQuestId() == QUEST_VORSHA)
            {
                if (npc_muglashAI* pEscortAI = CAST_AI(npc_muglashAI, creature->AI()))
                {
                    DoScriptText(SAY_MUG_START1, creature);
                    creature->setFaction(113);

                    pEscortAI->Start(true, true, player->GetGUID());
                }
            }
            return true;
        }
};

class go_naga_brazier : public GameObjectScript
{
    public:

        go_naga_brazier()
            : GameObjectScript("go_naga_brazier")
        {
        }

        bool OnGossipHello(Player* /*player*/, GameObject* go)
        {
            if (Creature* creature = GetClosestCreatureWithEntry(go, NPC_MUGLASH, INTERACTION_DISTANCE*2))
            {
                if (npc_muglash::npc_muglashAI* pEscortAI = CAST_AI(npc_muglash::npc_muglashAI, creature->AI()))
                {
                    DoScriptText(SAY_MUG_BRAZIER_WAIT, creature);

                    pEscortAI->m_bIsBrazierExtinguished = true;
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
