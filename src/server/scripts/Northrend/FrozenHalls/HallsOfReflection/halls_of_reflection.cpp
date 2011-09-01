/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "halls_of_reflection.h"

enum Yells
{
    SAY_JAINA_INTRO_1                             = -1668001,
    SAY_JAINA_INTRO_2                             = -1668002,
    SAY_JAINA_INTRO_3                             = -1668003,
    SAY_JAINA_INTRO_4                             = -1668004,
    SAY_UTHER_INTRO_A2_1                          = -1668005,
    SAY_JAINA_INTRO_5                             = -1668006,
    SAY_UTHER_INTRO_A2_2                          = -1668007,
    SAY_JAINA_INTRO_6                             = -1668008,
    SAY_UTHER_INTRO_A2_3                          = -1668009,
    SAY_JAINA_INTRO_7                             = -1668010,
    SAY_UTHER_INTRO_A2_4                          = -1668011,
    SAY_JAINA_INTRO_8                             = -1668012,
    SAY_UTHER_INTRO_A2_5                          = -1668013,
    SAY_JAINA_INTRO_9                             = -1668014,
    SAY_UTHER_INTRO_A2_6                          = -1668015,
    SAY_UTHER_INTRO_A2_7                          = -1668016,
    SAY_JAINA_INTRO_10                            = -1668017,
    SAY_UTHER_INTRO_A2_8                          = -1668018,
    SAY_JAINA_INTRO_11                            = -1668019,
    SAY_UTHER_INTRO_A2_9                          = -1668020,

    SAY_SYLVANAS_INTRO_1                          = -1668021,
    SAY_SYLVANAS_INTRO_2                          = -1668022,
    SAY_SYLVANAS_INTRO_3                          = -1668023,
    SAY_UTHER_INTRO_H2_1                          = -1668024,
    SAY_SYLVANAS_INTRO_4                          = -1668025,
    SAY_UTHER_INTRO_H2_2                          = -1668026,
    SAY_SYLVANAS_INTRO_5                          = -1668027,
    SAY_UTHER_INTRO_H2_3                          = -1668028,
    SAY_SYLVANAS_INTRO_6                          = -1668029,
    SAY_UTHER_INTRO_H2_4                          = -1668030,
    SAY_SYLVANAS_INTRO_7                          = -1668031,
    SAY_UTHER_INTRO_H2_5                          = -1668032,
    SAY_UTHER_INTRO_H2_6                          = -1668033,
    SAY_SYLVANAS_INTRO_8                          = -1668034,
    SAY_UTHER_INTRO_H2_7                          = -1668035,

    SAY_LK_INTRO_1                                = -1668036,
    SAY_LK_INTRO_2                                = -1668037,
    SAY_LK_INTRO_3                                = -1668038,
    SAY_FALRIC_INTRO_1                            = -1668039,
    SAY_MARWYN_INTRO_1                            = -1668040,
    SAY_FALRIC_INTRO_2                            = -1668041,

    SAY_JAINA_INTRO_END                           = -1668042,
    SAY_SYLVANAS_INTRO_END                        = -1668043,
};

enum Events
{
    EVENT_NONE,

    EVENT_START_INTRO,
    EVENT_SKIP_INTRO,

    EVENT_INTRO_A2_1,
    EVENT_INTRO_A2_2,
    EVENT_INTRO_A2_3,
    EVENT_INTRO_A2_4,
    EVENT_INTRO_A2_5,
    EVENT_INTRO_A2_6,
    EVENT_INTRO_A2_7,
    EVENT_INTRO_A2_8,
    EVENT_INTRO_A2_9,
    EVENT_INTRO_A2_10,
    EVENT_INTRO_A2_11,
    EVENT_INTRO_A2_12,
    EVENT_INTRO_A2_13,
    EVENT_INTRO_A2_14,
    EVENT_INTRO_A2_15,
    EVENT_INTRO_A2_16,
    EVENT_INTRO_A2_17,
    EVENT_INTRO_A2_18,
    EVENT_INTRO_A2_19,

    EVENT_INTRO_H2_1,
    EVENT_INTRO_H2_2,
    EVENT_INTRO_H2_3,
    EVENT_INTRO_H2_4,
    EVENT_INTRO_H2_5,
    EVENT_INTRO_H2_6,
    EVENT_INTRO_H2_7,
    EVENT_INTRO_H2_8,
    EVENT_INTRO_H2_9,
    EVENT_INTRO_H2_10,
    EVENT_INTRO_H2_11,
    EVENT_INTRO_H2_12,
    EVENT_INTRO_H2_13,
    EVENT_INTRO_H2_14,
    EVENT_INTRO_H2_15,

    EVENT_INTRO_LK_1,
    EVENT_INTRO_LK_2,
    EVENT_INTRO_LK_3,
    EVENT_INTRO_LK_4,
    EVENT_INTRO_LK_5,
    EVENT_INTRO_LK_6,
    EVENT_INTRO_LK_7,
    EVENT_INTRO_LK_8,
    EVENT_INTRO_LK_9,

    EVENT_INTRO_END,
};

enum Spells
{
    SPELL_EQUIP_FROSTMOURNE         = 72729,
    SPELL_FALRIC_MARWYN_SPAWN_AURA  = 72712,
    SPELL_UTHER_DESPAWN             = 70693,
    SPELL_FROSTMOURNE_HANDED        = 73220, // Most probably wrong, surely enough used in the ICC Encounter.
    SPELL_FROSTMOURNE_SPAWN_SOUND   = 70667,
};

enum Various
{
    ACTION_START_INTRO,
    ACTION_SKIP_INTRO,

    QUEST_DELIVRANCE_FROM_THE_PIT_A2              = 24710,
    QUEST_DELIVRANCE_FROM_THE_PIT_H2              = 24712,
    QUEST_WRATH_OF_THE_LICH_KING_A2               = 24500,
    QUEST_WRATH_OF_THE_LICH_KING_H2               = 24802,
};

const Position HallsofReflectionLocs[]=
{
    {5283.234863f, 1990.946777f, 707.695679f, 0.929097f},   // 2 Loralen Follows
    {5408.031250f, 2102.918213f, 707.695251f, 0.792756f},   // 9 Sylvanas Follows
    {5401.866699f, 2110.837402f, 707.695251f, 0.800610f},   // 10 Loralen follows
};

const Position SpawnPos              = {5262.540527f, 1949.693726f, 707.695007f, 0.808736f}; // Jaina/Sylvanas Beginning Position
const Position MoveThronePos         = {5306.952148f, 1998.499023f, 709.341431f, 1.277278f}; // Jaina/Sylvanas walks to throne
const Position UtherSpawnPos         = {5308.310059f, 2003.857178f, 709.341431f, 4.650315f};
const Position LichKingSpawnPos      = {5362.917480f, 2062.307129f, 707.695374f, 3.945812f};
const Position LichKingMoveThronePos = {5312.080566f, 2009.172119f, 709.341431f, 3.973301f}; // Lich King walks to throne
const Position LichKingMoveAwayPos   = {5400.069824f, 2102.7131689f, 707.69525f, 0.843803f}; // Lich King walks away
const Position FalricMovePos         = {5283.309f, 2031.173f, 709.319f, 5.472657f};
const Position MarwynMovePos         = {5335.585f, 1981.439f, 709.319f, 2.375833f};

class npc_jaina_or_sylvanas_hor : public CreatureScript
{
private:
    bool m_isSylvana;

public:
    npc_jaina_or_sylvanas_hor(bool isSylvana, const char* name) : CreatureScript(name), m_isSylvana(isSylvana) { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();
                if (creature->AI())
                    creature->AI()->DoAction(ACTION_START_INTRO);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->CLOSE_GOSSIP_MENU();
                if (creature->AI())
                    creature->AI()->DoAction(ACTION_SKIP_INTRO);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                break;
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        QuestStatus status = player->GetQuestStatus(m_isSylvana ? QUEST_DELIVRANCE_FROM_THE_PIT_H2 : QUEST_DELIVRANCE_FROM_THE_PIT_A2);
        if (status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_REWARDED)
            player->ADD_GOSSIP_ITEM( 0, "Can you remove the sword?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        // once last quest is completed, she offers this shortcut of the starting event
        // Disable it since not implemented
        /*
        status = player->GetQuestStatus(m_isSylvana ? QUEST_WRATH_OF_THE_LICH_KING_H2 : QUEST_WRATH_OF_THE_LICH_KING_A2);
        if (status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_REWARDED)
            player->ADD_GOSSIP_ITEM( 0, "Dark Lady, I think I hear Arthas coming. Whatever you're going to do, do it quickly.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        */
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_jaina_or_sylvanas_horAI(creature);
    }

    // AI of Part1: handle the intro till start of gauntlet event.
    struct npc_jaina_or_sylvanas_horAI : public ScriptedAI
    {
        npc_jaina_or_sylvanas_horAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = me->GetInstanceScript();
        }

        InstanceScript* pInstance;
        uint64 UtherGUID;
        uint64 uiLichKing;

        EventMap events;

        void Reset()
        {
            events.Reset();

            UtherGUID = 0;
            uiLichKing = 0;

            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetVisible(true);
        }

        void DoAction(const int32 actionId)
        {
            switch (actionId)
            {
                case ACTION_START_INTRO:
                    events.ScheduleEvent(EVENT_START_INTRO, 0);
                    break;
                case ACTION_SKIP_INTRO:
                    events.ScheduleEvent(EVENT_SKIP_INTRO, 0);
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);
            switch (events.ExecuteEvent())
            {
                case EVENT_START_INTRO:
                    me->GetMotionMaster()->MovePoint(0, MoveThronePos);
                    // Begining of intro is differents between factions as the speech sequence and timers are differents.
                    events.ScheduleEvent((pInstance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE ? EVENT_INTRO_A2_1 : EVENT_INTRO_H2_1), 0);
                    break;
                // Alliance Intro Events
                case EVENT_INTRO_A2_1:
                    DoScriptText(SAY_JAINA_INTRO_3, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_2, 5000);
                    break;
                case EVENT_INTRO_A2_2:
                    DoScriptText(SAY_JAINA_INTRO_4, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_3, 10000);
                    break;
                case EVENT_INTRO_A2_3:
                    // TODO: she's doing some kind of spell casting emote
                    pInstance->HandleGameObject(pInstance->GetData64(DATA_FROSTMOURNE), true);
                    me->CastSpell(me, SPELL_FROSTMOURNE_SPAWN_SOUND, true);
                    events.ScheduleEvent(EVENT_INTRO_A2_4, 10000);
                    break;
                case EVENT_INTRO_A2_4:
                    // Spawn Uther
                    if (Creature* Uther = me->SummonCreature(NPC_UTHER, UtherSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        Uther->GetMotionMaster()->MoveIdle();
                        Uther->SetReactState(REACT_PASSIVE);
                        Uther->CastSpell(Uther, SPELL_FALRIC_MARWYN_SPAWN_AURA, true);
                        UtherGUID = Uther->GetGUID();
                    }
                    events.ScheduleEvent(EVENT_INTRO_A2_5, 2000);
                    break;
                case EVENT_INTRO_A2_5:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(SAY_UTHER_INTRO_A2_1, Uther);
                    events.ScheduleEvent(EVENT_INTRO_A2_6, 3000);
                    break;
                case EVENT_INTRO_A2_6:
                    DoScriptText(SAY_JAINA_INTRO_5, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_7, 6000);
                    break;
                case EVENT_INTRO_A2_7:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(SAY_UTHER_INTRO_A2_2, Uther);
                    events.ScheduleEvent(EVENT_INTRO_A2_8, 6500);
                    break;
                case EVENT_INTRO_A2_8:
                    DoScriptText(SAY_JAINA_INTRO_6, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_9, 2000);
                    break;
                case EVENT_INTRO_A2_9:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(SAY_UTHER_INTRO_A2_3, Uther);
                    events.ScheduleEvent(EVENT_INTRO_A2_10, 9000);
                    break;
                case EVENT_INTRO_A2_10:
                    DoScriptText(SAY_JAINA_INTRO_7, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_11, 5000);
                    break;
                case EVENT_INTRO_A2_11:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(SAY_UTHER_INTRO_A2_4, Uther);
                    events.ScheduleEvent(EVENT_INTRO_A2_12, 11000);
                    break;
                case EVENT_INTRO_A2_12:
                    DoScriptText(SAY_JAINA_INTRO_8, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_13, 4000);
                    break;
                case EVENT_INTRO_A2_13:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(SAY_UTHER_INTRO_A2_5, Uther);
                    events.ScheduleEvent(EVENT_INTRO_A2_14, 12500);
                    break;
                case EVENT_INTRO_A2_14:
                    DoScriptText(SAY_JAINA_INTRO_9, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_15, 10000);
                    break;
                case EVENT_INTRO_A2_15:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(SAY_UTHER_INTRO_A2_6, Uther);
                    events.ScheduleEvent(EVENT_INTRO_A2_16, 22000);
                    break;
                case EVENT_INTRO_A2_16:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(SAY_UTHER_INTRO_A2_7, Uther);
                    events.ScheduleEvent(EVENT_INTRO_A2_17, 4000);
                    break;
                case EVENT_INTRO_A2_17:
                    DoScriptText(SAY_JAINA_INTRO_10, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_18, 2000);
                    break;
                case EVENT_INTRO_A2_18:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                    {
                        Uther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                        DoScriptText(SAY_UTHER_INTRO_A2_8, Uther);
                    }
                    events.ScheduleEvent(EVENT_INTRO_A2_19, 11000);
                    break;
                case EVENT_INTRO_A2_19:
                    DoScriptText(SAY_JAINA_INTRO_11, me);
                    events.ScheduleEvent(EVENT_INTRO_LK_1, 2000);
                    break;
                // Horde Intro Events
                case EVENT_INTRO_H2_1:
                    DoScriptText(SAY_SYLVANAS_INTRO_1, me);
                    events.ScheduleEvent(EVENT_INTRO_H2_2, 8000);
                    break;
                case EVENT_INTRO_H2_2:
                    DoScriptText(SAY_SYLVANAS_INTRO_2, me);
                    events.ScheduleEvent(EVENT_INTRO_H2_3, 6000);
                    break;
                case EVENT_INTRO_H2_3:
                    DoScriptText(SAY_SYLVANAS_INTRO_3, me);
                    // TODO: she's doing some kind of spell casting emote
                    me->CastSpell(me, SPELL_FROSTMOURNE_SPAWN_SOUND, true);
                    events.ScheduleEvent(EVENT_INTRO_H2_4, 6000);
                    break;
                case EVENT_INTRO_H2_4:
                    // Spawn Uther
                    if (Creature* Uther = me->SummonCreature(NPC_UTHER, UtherSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        Uther->GetMotionMaster()->MoveIdle();
                        Uther->SetReactState(REACT_PASSIVE);
                        Uther->CastSpell(Uther, SPELL_FALRIC_MARWYN_SPAWN_AURA, true); // Same visual as Marwyn and Falric
                        UtherGUID = Uther->GetGUID();
                    }
                    events.ScheduleEvent(EVENT_INTRO_H2_5, 2000);
                    break;
                case EVENT_INTRO_H2_5:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(SAY_UTHER_INTRO_H2_1, Uther);
                    events.ScheduleEvent(EVENT_INTRO_H2_6, 11000);
                    break;
                case EVENT_INTRO_H2_6:
                    DoScriptText(SAY_SYLVANAS_INTRO_4, me);
                    events.ScheduleEvent(EVENT_INTRO_H2_7, 3000);
                    break;
                case EVENT_INTRO_H2_7:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(SAY_UTHER_INTRO_H2_2, Uther);
                    events.ScheduleEvent(EVENT_INTRO_H2_8, 6000);
                    break;
                case EVENT_INTRO_H2_8:
                    DoScriptText(SAY_SYLVANAS_INTRO_5, me);
                    events.ScheduleEvent(EVENT_INTRO_H2_9, 5000);
                    break;
                case EVENT_INTRO_H2_9:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(SAY_UTHER_INTRO_H2_3, Uther);
                    events.ScheduleEvent(EVENT_INTRO_H2_10, 19000);
                    break;
                case EVENT_INTRO_H2_10:
                    DoScriptText(SAY_SYLVANAS_INTRO_6, me);
                    events.ScheduleEvent(EVENT_INTRO_H2_11, 1500);
                    break;
                case EVENT_INTRO_H2_11:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(SAY_UTHER_INTRO_H2_4, Uther);
                    events.ScheduleEvent(EVENT_INTRO_H2_12, 19500);
                    break;
                case EVENT_INTRO_H2_12:
                    DoScriptText(SAY_SYLVANAS_INTRO_7, me);
                    events.ScheduleEvent(EVENT_INTRO_H2_13, 2000);
                    break;
                case EVENT_INTRO_H2_13:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                    {
                        Uther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                        DoScriptText(SAY_UTHER_INTRO_H2_5, Uther);
                    }
                    events.ScheduleEvent(EVENT_INTRO_H2_14, 12000);
                    break;
                case EVENT_INTRO_H2_14:
                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(SAY_UTHER_INTRO_H2_6, Uther);
                    events.ScheduleEvent(EVENT_INTRO_H2_15, 8000);
                    break;
                case EVENT_INTRO_H2_15:
                    DoScriptText(SAY_SYLVANAS_INTRO_8, me);
                    events.ScheduleEvent(EVENT_INTRO_LK_1, 2000);
                    break;
                // Remaining Intro Events common for both faction
                case EVENT_INTRO_LK_1:
                    // Spawn LK in front of door, and make him move to the sword.
                    if (Creature* pLichKing = me->SummonCreature(NPC_LICH_KING_EVENT, LichKingSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        pLichKing->GetMotionMaster()->MovePoint(0, LichKingMoveThronePos);
                        pLichKing->SetReactState(REACT_PASSIVE);
                        uiLichKing = pLichKing->GetGUID();
                    }

                    if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                        DoScriptText(pInstance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE ? SAY_UTHER_INTRO_A2_9 : SAY_UTHER_INTRO_H2_7, Uther);

                    events.ScheduleEvent(EVENT_INTRO_LK_2, 11000);
                    break;

                case EVENT_INTRO_LK_2:
                     if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                         DoScriptText(SAY_LK_INTRO_1, pLichKing);
                     events.ScheduleEvent(EVENT_INTRO_LK_3, 2000);
                     break;
                case EVENT_INTRO_LK_3:
                     if (Creature* Uther = me->GetCreature(*me, UtherGUID))
                     {
                         Uther->CastSpell(Uther, SPELL_UTHER_DESPAWN, true);
                         Uther->DespawnOrUnsummon(500);
                         UtherGUID = 0;
                     }
                     // He steps forward and removes the runeblade from the heap of skulls.
                     events.ScheduleEvent(EVENT_INTRO_LK_4, 4000);
                     break;
                case EVENT_INTRO_LK_4:
                    if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                    {
                        DoScriptText(SAY_LK_INTRO_2, pLichKing);
                        pLichKing->AI()->DoCast(SPELL_EQUIP_FROSTMOURNE);
                    }
                    events.ScheduleEvent(EVENT_INTRO_LK_5, 10000);
                    break;
                case EVENT_INTRO_LK_5:
                    // Make Falric and Marwyn visible. then go back to the door
                    if (Creature* pFalric = me->GetCreature(*me, pInstance->GetData64(DATA_FALRIC)))
                    {
                        pFalric->SetVisible(true);
                        pFalric->CastSpell(pFalric, SPELL_FALRIC_MARWYN_SPAWN_AURA, true);
                    }
                    if (Creature* pMarwyn = me->GetCreature(*me, pInstance->GetData64(DATA_MARWYN)))
                    {
                        pMarwyn->SetVisible(true);
                        pMarwyn->CastSpell(pMarwyn, SPELL_FALRIC_MARWYN_SPAWN_AURA, true);
                    }
                    if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                    {
                        pLichKing->GetMotionMaster()->MovePoint(0, LichKingSpawnPos);
                        DoScriptText(SAY_LK_INTRO_3, pLichKing);
                    }
                    events.ScheduleEvent(EVENT_INTRO_LK_6, 8000);
                    break;
                case EVENT_INTRO_LK_6:
                    if (Creature* pFalric = me->GetCreature(*me, pInstance->GetData64(DATA_FALRIC)))
                        DoScriptText(SAY_FALRIC_INTRO_1, pFalric);
                    events.ScheduleEvent(EVENT_INTRO_LK_7, 2000);
                    break;
                case EVENT_INTRO_LK_7:
                    if (Creature* pMarwyn = me->GetCreature(*me, pInstance->GetData64(DATA_MARWYN)))
                        DoScriptText(SAY_MARWYN_INTRO_1, pMarwyn);
                    events.ScheduleEvent(EVENT_INTRO_LK_8, 2000);
                    break;
                case EVENT_INTRO_LK_8:
                    if (Creature* pFalric = me->GetCreature(*me, pInstance->GetData64(DATA_FALRIC)))
                        DoScriptText(SAY_FALRIC_INTRO_2, pFalric);
                    events.ScheduleEvent(EVENT_INTRO_LK_9, 5000);
                    break;
                case EVENT_INTRO_LK_9:
                    if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        DoScriptText(SAY_JAINA_INTRO_END, me);
                    else
                        DoScriptText(SAY_SYLVANAS_INTRO_END, me);

                    me->GetMotionMaster()->MovePoint(0, LichKingSpawnPos);
                    // TODO: Loralen/Koreln shall run also
                    events.ScheduleEvent(EVENT_INTRO_END, 10000);
                    break;
                case EVENT_INTRO_END:
                    if (pInstance)
                        pInstance->SetData(DATA_WAVE_COUNT, SPECIAL);   // start first wave
                    // Loralen or Koreln should also disappearAndDie()
                    me->DisappearAndDie();
                    break;
                case EVENT_SKIP_INTRO:
                    // TODO: implement
                    if (Creature* pFalric = me->GetCreature(*me, pInstance->GetData64(DATA_FALRIC)))
                        pFalric->SetVisible(true);
                    if (Creature* pMarwyn = me->GetCreature(*me, pInstance->GetData64(DATA_MARWYN)))
                        pMarwyn->SetVisible(true);
                    me->GetMotionMaster()->MovePoint(0, LichKingSpawnPos);
                    // TODO: Loralen/Koreln shall run also
                    events.ScheduleEvent(EVENT_INTRO_END, 15000);
                    break;
            }
        }
    };

};

enum TrashSpells
{
    // Ghostly Priest
    SPELL_SHADOW_WORD_PAIN                        = 72318,
    SPELL_CIRCLE_OF_DESTRUCTION                   = 72320,
    SPELL_COWER_IN_FEAR                           = 72321,
    SPELL_DARK_MENDING                            = 72322,

    // Phantom Mage
    SPELL_FIREBALL                                = 72163,
    SPELL_FLAMESTRIKE                             = 72169,
    SPELL_FROSTBOLT                               = 72166,
    SPELL_CHAINS_OF_ICE                           = 72121,
    SPELL_HALLUCINATION                           = 72342,

    // Phantom Hallucination (same as phantom mage + HALLUCINATION_2 when dies)
    SPELL_HALLUCINATION_2                         = 72344,

    // Shadowy Mercenary
    SPELL_SHADOW_STEP                             = 72326,
    SPELL_DEADLY_POISON                           = 72329,
    SPELL_ENVENOMED_DAGGER_THROW                  = 72333,
    SPELL_KIDNEY_SHOT                             = 72335,

    // Spectral Footman
    SPELL_SPECTRAL_STRIKE                         = 72198,
    SPELL_SHIELD_BASH                             = 72194,
    SPELL_TORTURED_ENRAGE                         = 72203,

    // Tortured Rifleman
    SPELL_SHOOT                                   = 72208,
    SPELL_CURSED_ARROW                            = 72222,
    SPELL_FROST_TRAP                              = 72215,
    SPELL_ICE_SHOT                                = 72268,
};

enum TrashEvents
{
    EVENT_TRASH_NONE,

    // Ghostly Priest
    EVENT_SHADOW_WORD_PAIN,
    EVENT_CIRCLE_OF_DESTRUCTION,
    EVENT_COWER_IN_FEAR,
    EVENT_DARK_MENDING,

    // Phantom Mage
    EVENT_FIREBALL,
    EVENT_FLAMESTRIKE,
    EVENT_FROSTBOLT,
    EVENT_CHAINS_OF_ICE,
    EVENT_HALLUCINATION,

    // Shadowy Mercenary
    EVENT_SHADOW_STEP,
    EVENT_DEADLY_POISON,
    EVENT_ENVENOMED_DAGGER_THROW,
    EVENT_KIDNEY_SHOT,

    // Spectral Footman
    EVENT_SPECTRAL_STRIKE,
    EVENT_SHIELD_BASH,
    EVENT_TORTURED_ENRAGE,

    // Tortured Rifleman
    EVENT_SHOOT,
    EVENT_CURSED_ARROW,
    EVENT_FROST_TRAP,
    EVENT_ICE_SHOT,
};

class npc_ghostly_priest : public CreatureScript
{
    public:
        npc_ghostly_priest() : CreatureScript("npc_ghostly_priest") { }

        struct npc_ghostly_priestAI: public ScriptedAI
        {
            npc_ghostly_priestAI(Creature* c) : ScriptedAI(c)
            {
            }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000); // TODO: adjust timers
                events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000);
                events.ScheduleEvent(EVENT_COWER_IN_FEAR, 10000);
                events.ScheduleEvent(EVENT_DARK_MENDING, 20000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHADOW_WORD_PAIN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_SHADOW_WORD_PAIN);
                            events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000);
                            return;
                        case EVENT_CIRCLE_OF_DESTRUCTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_CIRCLE_OF_DESTRUCTION);
                            events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000);
                            return;
                        case EVENT_COWER_IN_FEAR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_COWER_IN_FEAR);
                            events.ScheduleEvent(EVENT_COWER_IN_FEAR, 10000);
                            return;
                        case EVENT_DARK_MENDING:
                            if (Unit* target = DoSelectLowestHpFriendly(40, DUNGEON_MODE(30000, 50000)))
                            {
                                DoCast(target, SPELL_DARK_MENDING);
                                events.ScheduleEvent(EVENT_DARK_MENDING, 20000);
                            }
                            else
                                events.ScheduleEvent(EVENT_DARK_MENDING, 5000);
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }
            
        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_ghostly_priestAI(creature);
        }
};

class npc_phantom_mage : public CreatureScript
{
    public:
        npc_phantom_mage() : CreatureScript("npc_phantom_mage") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_phantom_mageAI(creature);
        }

        struct npc_phantom_mageAI: public ScriptedAI
        {
            npc_phantom_mageAI(Creature* c) : ScriptedAI(c) { }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_FIREBALL, 3000); // TODO: adjust timers
                events.ScheduleEvent(EVENT_FLAMESTRIKE, 6000);
                events.ScheduleEvent(EVENT_FROSTBOLT, 9000);
                events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 12000);
                events.ScheduleEvent(EVENT_HALLUCINATION, 40000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIREBALL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_FIREBALL);
                            events.ScheduleEvent(EVENT_FIREBALL, 15000);
                            return;
                        case EVENT_FLAMESTRIKE:
                            DoCast(SPELL_FLAMESTRIKE);
                            events.ScheduleEvent(EVENT_FLAMESTRIKE, 15000);
                            return;
                        case EVENT_FROSTBOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_FROSTBOLT);
                            events.ScheduleEvent(EVENT_FROSTBOLT, 15000);
                            return;
                        case EVENT_CHAINS_OF_ICE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_CHAINS_OF_ICE);
                            events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 15000);
                            return;
                        case EVENT_HALLUCINATION:
                            DoCast(SPELL_HALLUCINATION);
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };
};

class npc_phantom_hallucination : public CreatureScript
{
public:
    npc_phantom_hallucination() : CreatureScript("npc_phantom_hallucination") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_phantom_hallucinationAI(creature);
    }

    struct npc_phantom_hallucinationAI : public npc_phantom_mage::npc_phantom_mageAI
    {
        npc_phantom_hallucinationAI(Creature* c) : npc_phantom_mage::npc_phantom_mageAI(c)
        {
        }

        void JustDied(Unit* /*who*/)
        {
            DoCast(SPELL_HALLUCINATION_2);
        }
    };

};

class npc_shadowy_mercenary : public CreatureScript
{
    public:
        npc_shadowy_mercenary() : CreatureScript("npc_shadowy_mercenary") { }

        struct npc_shadowy_mercenaryAI: public ScriptedAI
        {
            npc_shadowy_mercenaryAI(Creature* c) : ScriptedAI(c) { }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_SHADOW_STEP, 8000); // TODO: adjust timers
                events.ScheduleEvent(EVENT_DEADLY_POISON, 5000);
                events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
                events.ScheduleEvent(EVENT_KIDNEY_SHOT, 12000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHADOW_STEP:
                            DoCast(SPELL_SHADOW_STEP);
                            events.ScheduleEvent(EVENT_SHADOW_STEP, 8000);
                            return;
                        case EVENT_DEADLY_POISON:
                            if (Unit* victim = me->getVictim())
                                DoCast(victim, SPELL_DEADLY_POISON);
                            events.ScheduleEvent(EVENT_DEADLY_POISON, 10000);
                            return;
                        case EVENT_ENVENOMED_DAGGER_THROW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_ENVENOMED_DAGGER_THROW);
                            events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
                            return;
                        case EVENT_KIDNEY_SHOT:
                            if (Unit* victim = me->getVictim())
                                DoCast(victim, SPELL_KIDNEY_SHOT);
                            events.ScheduleEvent(EVENT_KIDNEY_SHOT, 10000);
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_shadowy_mercenaryAI(creature);
        }
};

class npc_spectral_footman : public CreatureScript
{
    public:
        npc_spectral_footman() : CreatureScript("npc_spectral_footman") { }

        struct npc_spectral_footmanAI: public ScriptedAI
        {
            npc_spectral_footmanAI(Creature* c) : ScriptedAI(c) { }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000); // TODO: adjust timers
                events.ScheduleEvent(EVENT_SHIELD_BASH, 10000);
                events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPECTRAL_STRIKE:
                            if (Unit* victim = me->getVictim())
                                DoCast(victim, SPELL_SPECTRAL_STRIKE);
                            events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000);
                            return;
                        case EVENT_SHIELD_BASH:
                            if (Unit* victim = me->getVictim())
                                DoCast(victim, SPELL_SHIELD_BASH);
                            events.ScheduleEvent(EVENT_SHIELD_BASH, 5000);
                            return;
                        case EVENT_TORTURED_ENRAGE:
                            DoCast(SPELL_TORTURED_ENRAGE);
                            events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000);
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_spectral_footmanAI(creature);
        }
};

class npc_tortured_rifleman : public CreatureScript
{
    public:
        npc_tortured_rifleman() : CreatureScript("npc_tortured_rifleman") { }

        struct npc_tortured_riflemanAI  : public ScriptedAI
        {
            npc_tortured_riflemanAI(Creature* c) : ScriptedAI(c) { }

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_SHOOT, 2000); // TODO: adjust timers
                events.ScheduleEvent(EVENT_CURSED_ARROW, 10000);
                events.ScheduleEvent(EVENT_FROST_TRAP, 1000);
                events.ScheduleEvent(EVENT_ICE_SHOT, 15000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHOOT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_SHOOT);
                            events.ScheduleEvent(EVENT_SHOOT, 2000);
                            return;
                        case EVENT_CURSED_ARROW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_CURSED_ARROW);
                            events.ScheduleEvent(EVENT_CURSED_ARROW, 10000);
                            return;
                        case EVENT_FROST_TRAP:
                            DoCast(SPELL_FROST_TRAP);
                            events.ScheduleEvent(EVENT_FROST_TRAP, 30000);
                            return;
                        case EVENT_ICE_SHOT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_ICE_SHOT);
                            events.ScheduleEvent(EVENT_ICE_SHOT, 15000);
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_tortured_riflemanAI(creature);
        }
};

// Script Frostsworn General and his summons

enum Sayings
{
    // Pre escape
    SAY_LICH_KING_AGGRO_A              = -1594477,
    SAY_LICH_KING_AGGRO_H              = -1594478,
    SAY_JAINA_AGGRO                    = -1594479,
    SAY_SYLVANA_AGGRO                  = -1594480,

    // Escape
    SAY_JAINA_WALL_01                  = -1594487,
    SAY_SYLVANA_WALL_01                = -1594488,
    SAY_JAINA_WALL_02                  = -1594489,
    SAY_SYLVANA_WALL_02                = -1594490,
    SAY_LICH_KING_WALL_02              = -1594491,
    SAY_LICH_KING_WALL_03              = -1594492,
    SAY_LICH_KING_WALL_04              = -1594493,
    SAY_JAINA_WALL_03                  = -1594494,
    SAY_JAINA_WALL_04                  = -1594495,
    SAY_SYLVANA_WALL_03                = -1594496,
    SAY_SYLVANA_WALL_04                = -1594497,
    SAY_JAINA_ESCAPE_01                = -1594498,
    SAY_JAINA_ESCAPE_02                = -1594499,
    SAY_SYLVANA_ESCAPE_01              = -1594500,
    SAY_SYLVANA_ESCAPE_02              = -1594501,
    SAY_JAINA_TRAP                     = -1594502,
    SAY_SYLVANA_TRAP                   = -1594503,
    SAY_MATHEAS_JAINA                  = -1594505,
    SAY_JAINA_FIRE                     = -1594526,
    SAY_SYLVANA_FIRE                   = -1594522,
    SAY_SYLVANA_FINAL_1                = -1594523,
    SAY_SYLVANA_FINAL_2                = -1594521,
    SAY_JAINA_FINAL_1                  = -1594527,
    SAY_JAINA_FINAL_2                  = -1594524,
    SAY_JAINA_FINAL_3                  = -1594525,
    SAY_LICH_KING_END_01               = -1594506,
    SAY_LICH_KING_END_02               = -1594507,
    SAY_LICH_KING_END_03               = -1594508,
};

enum EndingSpells
{
    SPELL_WINTER                       = 69780,
    SPELL_FURY_OF_FROSTMOURNE          = 70063,
    SPELL_ICE_PRISON_VISUAL            = 69708,
    SPELL_DARK_ARROW                   = 70194,
    SPELL_ICE_BARRIER                  = 69787,
    SPELL_DESTROY_ICE_WALL_01          = 69784, // Jaina
    SPELL_DESTROY_ICE_WALL_03          = 70225, // Sylvannas - 
    SPELL_SYLVANA_JUMP                 = 68339,
    SPELL_SYLVANA_STEP                 = 69087,
    SPELL_FIRE_CANNON                  = 67461,

    FACTION                            = 2076,
};

const Position CannonSpawns[4] = 
{
    {5230.00f, 1658.75f, 802.22f, 0.00f},
    {5245.74f, 1644.44f, 802.35f, 0.00f},
    {5260.64f, 1636.07f, 802.16f, 0.00f},
    {5275.90f, 1633.22f, 802.25f, 0.00f},
};

class npc_jaina_and_sylvana_hor_part2 : public CreatureScript
    {
    public:
        npc_jaina_and_sylvana_hor_part2() : CreatureScript("npc_jaina_and_sylvana_hor_part2") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            InstanceScript* instance = (InstanceScript*)creature->GetInstanceScript();

            if (!instance)
                return false;

            if (instance->GetData(DATA_LICHKING_EVENT) == DONE)
                return false;

            player->CLOSE_GOSSIP_MENU();
            creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);
            creature->setActive(true);

            if (instance)
            {
                instance->SetData64(DATA_ESCAPE_LEADER, creature->GetGUID());
                instance->SetData(DATA_LICHKING_EVENT, IN_PROGRESS);
            }

            return true;
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_jaina_and_sylvana_hor_part2AI(creature);
        }

        struct npc_jaina_and_sylvana_hor_part2AI : public npc_escortAI
        {
            npc_jaina_and_sylvana_hor_part2AI(Creature *creature) : npc_escortAI(creature)
            {
                instance = (InstanceScript*)creature->GetInstanceScript();
                Reset();
            }

            InstanceScript* instance;

            uint32 EncounterTime;
            uint32 CastTimer;
            uint32 StepTimer;
            uint32 Step;
            int32 HoldTimer;
            uint32 Count;
            bool Fight;
            bool Event;
            bool PreFight;
            bool WallCast;
            uint64 m_uiLichKingGUID;
            uint64 m_uiLiderGUID;
            uint64 IceWallGUID;
            uint64 WallTargetGUID;
            uint64 uiCaptain;
            Creature* pLichKing;
            uint32 m_chestID;
            EventMap events;

            void Reset()
            {
                if (!instance)
                    return;

                if (instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS)
                    return;

                Step = 0;
                StepTimer = 500;
                Fight = true;
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                WallTargetGUID = 0;

                if (me->GetEntry() == NPC_JAINA_PART2 || me->GetEntry() == NPC_SYLVANAS_PART2)
                {
                    me->CastSpell(me, SPELL_ICE_BARRIER, false);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);
                }
                if (instance->GetData(DATA_LICHKING_EVENT) == DONE)
                    me->SetVisible(false);

            }

            void AttackStart(Unit* who)
            {
                if (!who)
                    return;

                if (me->GetEntry() != NPC_JAINA_PART2 && me->GetEntry() != NPC_SYLVANAS_PART2)
                    return;

                if (instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS || Fight != true)
                    return;

                npc_escortAI::AttackStart(who);

            }

            void JustDied(Unit* /*killer*/)
            {
                if (!instance)
                    return;
                instance->SetData(DATA_LICHKING_EVENT, FAIL);
            }

            void WaypointReached(uint32 i)
            {
                switch (i)
                {
                    case 3:
                        instance->SetData(DATA_ICE_WALL_1, IN_PROGRESS);
                        if (GameObject* wall = instance->instance->GetGameObject(instance->GetData64(GO_ICE_WALL_1)))
                        {
                            wall->SetGoState(GO_STATE_READY);
                            IceWallGUID = wall->GetGUID();
                        }
                        break;
                    case 4:
                        if (me->GetEntry() == NPC_JAINA_PART2)
                            DoScriptText(SAY_JAINA_WALL_01, me);
                        if (me->GetEntry() == NPC_SYLVANAS_PART2)
                            DoScriptText(SAY_SYLVANA_WALL_01, me);
                        CastTimer = 1000;
                        HoldTimer = 30000;
                        SetEscortPaused(true);
                        if (Creature *WallTarget = me->SummonCreature(NPC_ICE_WALL_TARGET,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                        {
                            WallTargetGUID = WallTarget->GetGUID();
                            WallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            me->CastSpell(WallTarget, SPELL_DESTROY_ICE_WALL_01, false);
                        }
                        WallCast = true;
                        break;
                    case 6:
                        instance->SetData(DATA_ICE_WALL_2, IN_PROGRESS);
                        if (Creature* WallTarget = instance->instance->GetCreature(WallTargetGUID))
                        {
                            if (WallTarget->isAlive())
                            {
                                WallTarget->ForcedDespawn();
                                WallTargetGUID = 0;
                            }
                        }
                        break;
                    case 8:
                        if (me->GetEntry() == NPC_JAINA_PART2)
                            DoScriptText(SAY_JAINA_WALL_02, me);
                        if (me->GetEntry() == NPC_SYLVANAS_PART2)
                            DoScriptText(SAY_SYLVANA_WALL_02, me);
                        CastTimer = 1000;
                        HoldTimer = 30000;
                        SetEscortPaused(true);
                        if (Creature *WallTarget = me->SummonCreature(NPC_ICE_WALL_TARGET,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                        {
                            WallTargetGUID = WallTarget->GetGUID();
                            WallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            if (me->GetEntry() == NPC_JAINA_PART2 || me->GetEntry() == NPC_SYLVANAS_PART2)
                                me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                        }
                        WallCast = true;
                        break;
                    case 9:
                        if (me->GetEntry() == NPC_JAINA_PART2)
                            DoScriptText(SAY_JAINA_ESCAPE_01, me);
                        if (me->GetEntry() == NPC_SYLVANAS_PART2)
                            DoScriptText(SAY_SYLVANA_ESCAPE_01, me);
                        break;
                    case 11:
                        instance->SetData(DATA_ICE_WALL_3, IN_PROGRESS);
                        if (Creature* WallTarget = instance->instance->GetCreature(WallTargetGUID))
                        {
                            if (WallTarget->isAlive())
                            {
                                WallTarget->ForcedDespawn();
                                WallTargetGUID = 0;
                            }
                        }
                        break;
                    case 12:
                        if (me->GetEntry() == NPC_JAINA_PART2)
                            DoScriptText(SAY_JAINA_WALL_03, me);
                        if (me->GetEntry() == NPC_SYLVANAS_PART2)
                            DoScriptText(SAY_SYLVANA_WALL_03, me);
                        CastTimer = 1000;
                        HoldTimer = 30000;
                        SetEscortPaused(true);
                        if (Creature *WallTarget = me->SummonCreature(NPC_ICE_WALL_TARGET,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                        {
                            WallTargetGUID = WallTarget->GetGUID();
                            WallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            if (me->GetEntry() == NPC_JAINA_PART2 || me->GetEntry() == NPC_SYLVANAS_PART2)
                                me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                        }
                        WallCast = true;
                        break;
                    case 13:
                        if (me->GetEntry() == NPC_JAINA_PART2)
                            DoScriptText(SAY_JAINA_ESCAPE_02, me);
                        if (me->GetEntry() == NPC_SYLVANAS_PART2)
                            DoScriptText(SAY_SYLVANA_ESCAPE_02, me);
                        break;
                    case 15:
                        instance->SetData(DATA_ICE_WALL_4, IN_PROGRESS);
                        if (Creature* WallTarget = instance->instance->GetCreature(WallTargetGUID))
                        {
                            if (WallTarget->isAlive())
                            {
                                WallTarget->ForcedDespawn();
                                WallTargetGUID = 0;
                            }
                        }
                        break;
                    case 16:
                        if (me->GetEntry() == NPC_JAINA_PART2)
                            DoScriptText(SAY_JAINA_WALL_04, me);
                        if (me->GetEntry() == NPC_SYLVANAS_PART2)
                            DoScriptText(SAY_SYLVANA_WALL_04, me);
                        CastTimer = 1000;
                        HoldTimer = 30000;
                        SetEscortPaused(true);
                        if (Creature *WallTarget = me->SummonCreature(NPC_ICE_WALL_TARGET,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                        {
                            WallTargetGUID = WallTarget->GetGUID();
                            WallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            if (me->GetEntry() == NPC_JAINA_PART2 || me->GetEntry() == NPC_SYLVANAS_PART2)
                                me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                        }
                        WallCast = true;
                        break;
                    case 19:
                        if (me->GetEntry() == NPC_JAINA_PART2)
                            DoScriptText(SAY_JAINA_TRAP, me);
                        if (me->GetEntry() == NPC_SYLVANAS_PART2)
                            DoScriptText(SAY_SYLVANA_TRAP, me);
                        break;
                    case 20:
                        if (Creature* WallTarget = instance->instance->GetCreature(WallTargetGUID))
                        {
                            if (WallTarget->isAlive())
                            {
                                WallTarget->ForcedDespawn();
                                WallTargetGUID = 0;
                            }
                        }
                        SetEscortPaused(true);
                        if (me->GetEntry() == NPC_JAINA_PART2)
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);
                        if (me->GetEntry() == NPC_SYLVANAS_PART2)
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                        break;
                }
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!who || !instance)
                    return;

                if (who->GetTypeId() != TYPEID_PLAYER)
                    return;

                Player* player = who->ToPlayer();

                if ((player->GetTeam() == ALLIANCE && me->GetEntry() == NPC_SYLVANAS_PART2)
                    || (player->GetTeam() == HORDE && me->GetEntry() == NPC_JAINA_PART2))
                    return;

                if (me->IsWithinDistInMap(who, 50.0f)
                    && instance->GetData(DATA_FROSWORN_EVENT) == DONE
                    && instance->GetData(DATA_PHASE) == 3)
                {
                    Event = true;
                    instance->SetData(DATA_PHASE, 4);
                }
            }

            void DamageTaken(Unit* who, uint32 &damage)
            {
                if (!instance)
                    return;

                if (instance->GetData(DATA_LICHKING_EVENT) != IN_PROGRESS)
                {
                    damage = 0;
                    return;
                }

                if (instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS && WallCast == true)
                {
                    HoldTimer = HoldTimer + 100;
                    return;
                }
            }

            void JumpNextStep(uint32 Time)
            {
                StepTimer = Time;
                Step++;
            }

            void Intro()
            {
                switch (Step)
                {
                    case 0:
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        m_uiLichKingGUID = instance->GetData64(DATA_LICHKING);
                        EncounterTime = 0;                    
                        pLichKing = instance->instance->GetCreature(m_uiLichKingGUID);
                        me->SetUInt64Value(UNIT_FIELD_TARGET, pLichKing->GetGUID());
                        JumpNextStep(100);
                        break;
                    case 1:
                        HoRQuestComplete(me->GetEntry());
                        if (pLichKing)
                        {
                            if (me->GetEntry() == NPC_JAINA_PART2)
                                DoScriptText(SAY_LICH_KING_AGGRO_A, pLichKing);
                            if (me->GetEntry() == NPC_SYLVANAS_PART2)
                                DoScriptText(SAY_LICH_KING_AGGRO_H, pLichKing);
                            pLichKing->AI()->AttackStart(me);
                            me->AI()->AttackStart(pLichKing);
                        }
                        JumpNextStep(3000);
                        break;
                    case 2:
                	    if (me->GetEntry() == NPC_JAINA_PART2 || me->GetEntry() == NPC_SYLVANAS_PART2)
                        {
                            Fight = false;
                            if (pLichKing)
                                me->GetMotionMaster()->MovePoint(0, (me->GetPositionX()-5)+rand()%10, (me->GetPositionY()-5)+rand()%10, me->GetPositionZ());
                            JumpNextStep(3000);
                        }
                        else
                            JumpNextStep(100);
                        break;
                    case 3:
                	    if (me->GetEntry() == NPC_JAINA_PART2 || me->GetEntry() == NPC_SYLVANAS_PART2)
                            Fight = true;
                        JumpNextStep(100);
                        break;
                    case 4:
                	    if (me->GetEntry() == NPC_JAINA_PART2 || me->GetEntry() == NPC_SYLVANAS_PART2)
                        {
                            if (pLichKing)
                                me->CastSpell(pLichKing, SPELL_SYLVANA_STEP, false);
                            JumpNextStep(3000);
                        }
                        else
                            JumpNextStep(100);
                        break;
                    case 5:
                	    if (me->GetEntry() == NPC_JAINA_PART2 || me->GetEntry() == NPC_SYLVANAS_PART2)
                        {
                            Fight = false;
                            if (pLichKing)
                                me->GetMotionMaster()->MovePoint(0, (me->GetPositionX()-5)+rand()%10, (me->GetPositionY()-5)+rand()%10, me->GetPositionZ());
                            JumpNextStep(3000);
                        }
                        else
                            JumpNextStep(12000);
                        break;
                    case 6:
                        Fight = true;

                        if (pLichKing)
                        {
                    	    if (me->GetEntry() == NPC_JAINA_PART2 || me->GetEntry() == NPC_SYLVANAS_PART2)
                                DoCast(SPELL_SYLVANA_JUMP);
                            DoCast(pLichKing, me->GetEntry() == NPC_JAINA_PART2 ? SPELL_ICE_PRISON_VISUAL : SPELL_DARK_ARROW, false);
                            pLichKing->AttackStop();
                        }
                        JumpNextStep(1480);
                        break;
                    case 7:
                        me->RemoveAllAuras();

                        if (pLichKing && !pLichKing->HasAura(SPELL_ICE_PRISON_VISUAL))
                            pLichKing->AddAura(me->GetEntry() == NPC_JAINA_PART2 ? SPELL_ICE_PRISON_VISUAL : SPELL_DARK_ARROW, pLichKing);

                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                        me->AttackStop();

                        if (me->GetEntry() == NPC_JAINA_PART2)
                        {
                            me->RemoveAurasDueToSpell(SPELL_ICE_BARRIER);
                            DoScriptText(SAY_JAINA_AGGRO, me);
                        }

                        if (me->GetEntry() == NPC_SYLVANAS_PART2)
                            DoScriptText(SAY_SYLVANA_AGGRO, me);

                        JumpNextStep(3000);
                        break;
                    case 8:
                        me->GetMotionMaster()->MovePoint(0, 5577.187f, 2236.003f, 733.012f);
                        if (pLichKing && !pLichKing->HasAura(SPELL_ICE_PRISON_VISUAL))
                        {
                            pLichKing->AddAura(me->GetEntry() == NPC_JAINA_PART2 ? SPELL_ICE_PRISON_VISUAL : SPELL_DARK_ARROW, pLichKing);
                            me->SetUInt64Value(UNIT_FIELD_TARGET, pLichKing->GetGUID());
                        }
                        JumpNextStep(10000);
                        break;
                    case 9:
                        if (pLichKing && (!pLichKing->HasAura(SPELL_ICE_PRISON_VISUAL) || !pLichKing->HasAura(SPELL_DARK_ARROW)))
                        {
                            pLichKing->AddAura(me->GetEntry() == NPC_JAINA_PART2 ? SPELL_ICE_PRISON_VISUAL : SPELL_DARK_ARROW, pLichKing);
                            me->SetUInt64Value(UNIT_FIELD_TARGET, pLichKing->GetGUID());
                        }
                        me->RemoveAllAuras();
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        Count = 1;
                        JumpNextStep(100);
                        break;
                }
            }

            void Outro()
            {
                switch (Step)
                {
                    case 10:
                        JumpNextStep(10000);
                        break;
                    case 11:
                        if (GameObject* pGunship = instance->instance->GetGameObject(instance->GetData64(me->GetEntry() == NPC_JAINA_PART2 ? GO_SKYBREAKER : GO_ORGRIM_HAMMER)))
                            pGunship->SetPhaseMask(1, true);
                    
                        if (Creature* pCaptain = me->SummonCreature(me->GetEntry() == NPC_JAINA_PART2 ? NPC_BARTLETT : NPC_KORM, 5251.17f, 1610.2f, 795.812f, 2.07997f))
                        {
                            DoScriptText(me->GetEntry() == NPC_JAINA_PART2 ? SAY_JAINA_FIRE : SAY_SYLVANA_FIRE, pCaptain);
                            uiCaptain = pCaptain->GetGUID();
                        }
                        if (GameObject* pCave = instance->instance->GetGameObject(instance->GetData64(GO_CAVE)))
                        {
                            Creature *pCaveTarget = me->SummonCreature(NPC_ICE_WALL_TARGET, pCave->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000);
                            pCaveTarget->SetFloatValue(OBJECT_FIELD_SCALE_X, 4);

                            for (int8 i = 0; i < 4; i++)
                            {
                                if (Creature* pCannoner = me->SummonCreature(NPC_ICE_WALL_TARGET, CannonSpawns[i],TEMPSUMMON_MANUAL_DESPAWN,720000))
                                {
                                    pCannoner->setFaction(me->getFaction());
                                    pCannoner->CastSpell(pCaveTarget, SPELL_FIRE_CANNON, true);
                                }

                            }
                        }
                        JumpNextStep(6000);
                        break;
                    case 12:
                        if (GameObject* pCave = instance->instance->GetGameObject(instance->GetData64(GO_CAVE)))
                            pCave->SetGoState(GO_STATE_READY);
                        me->RemoveAllAuras();

                        if (pLichKing)
                            pLichKing->DespawnOrUnsummon();

                        HoRQuestComplete(38211);
                        JumpNextStep(10000);
                        break;
                    case 13:
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                        instance->SetData(DATA_LICHKING_EVENT, DONE);
                        if (Creature* pCaptain = me->GetCreature(*me, uiCaptain))
                            DoScriptText(me->GetEntry() == NPC_JAINA_PART2 ? SAY_JAINA_FINAL_1 : SAY_SYLVANA_FINAL_1, pCaptain);
                        me->SummonGameObject(me->GetEntry() == NPC_JAINA_PART2 ? GO_STAIRS_SKYBREAKER : GO_STAIRS_ORGRIM_HAMMER, 5247.45f, 1627.72f, 784.302f, 5.88208f, 0, 0, 0.199211f, -0.979957f, 1*DAY);
                        JumpNextStep(10000);
                        break;
                    case 14:
                        DoScriptText(me->GetEntry() == NPC_JAINA_PART2 ? SAY_JAINA_FINAL_2 : SAY_SYLVANA_FINAL_2, me);
                        JumpNextStep(20000);
                        break;
                    case 15:
					    DoScriptText(me->GetEntry() == NPC_JAINA_PART2 ? SAY_JAINA_FINAL_3:-0, me);
                        JumpNextStep(5000);
                        break;
                    case 16:
                        me->SetOrientation(0.68f);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        JumpNextStep(5000);
                        if (instance)
                        {
                            if (IsHeroic())
            	            {
                                //instance->DoCompleteAchievement(ACHIEV_HOR_H);
                                //if (EncounterTime <= MAX_ENCOUNTER_TIME)
                                //instance->DoCompleteAchievement(ACHIEV_NOT_RETREATING);
                            }
                            //instance->DoCompleteAchievement(ACHIEV_HOR);

                        }
                        break;
                }
            }

            void HoRQuestComplete(uint32 killCredit)
            {
                if (instance)
                {
                    Map::PlayerList const &PlayerList = instance->instance->GetPlayers();
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        i->getSource()->KilledMonsterCredit(killCredit, 0);
                }
            }

            void UpdateEscortAI(const uint32 diff)
            {
                if (!instance || !Event)
                    return;

                DoMeleeAttackIfReady();

                if (instance->GetData(DATA_PHASE) == 4 && instance->GetData(DATA_LICHKING_EVENT) != IN_PROGRESS)
                {
                    if (StepTimer < diff)
                        Intro();
                    else
                        StepTimer -= diff;
			        EncounterTime += diff;
                }

                if (instance->GetData(DATA_LICHKING_EVENT) == SPECIAL
                    && instance->GetData(DATA_PHASE) != 6)       //End Cinematic
                {
                    instance->SetData(DATA_PHASE, 6);
                    Step = 10;
                }

                if (instance->GetData(DATA_PHASE) == 6)
                {
                    if (StepTimer < diff)
                        Outro();
                    else
                        StepTimer -= diff;
                    return;
                }

                if (WallCast == true && CastTimer < diff)
                {
            	    if (me->GetEntry() == NPC_JAINA_PART2 || me->GetEntry() == NPC_SYLVANAS_PART2)
                    {
                       if (Creature* WallTarget = instance->instance->GetCreature(WallTargetGUID))
                            me->CastSpell(WallTarget, SPELL_DESTROY_ICE_WALL_03, false);
                        CastTimer = 1000;
                    }
                }
                else
                    CastTimer -= diff;

                if (WallCast == true && HoldTimer < 10000 && (instance->GetData(DATA_SUMMONS) == 0 || !me->isInCombat()))
                {
                    WallCast = false;
                    me->InterruptNonMeleeSpells(false);
                    SetEscortPaused(false);
                    if (GameObject* Gate = instance->instance->GetGameObject(IceWallGUID))
                        Gate->SetGoState(GO_STATE_ACTIVE);
                    ++Count;
                    switch (Count)
                    {
                        case 2:
                            if (GameObject* Gate = instance->instance->GetGameObject(instance->GetData64(GO_ICE_WALL_2)))
                            {
                                Gate->SetGoState(GO_STATE_READY);
                                if (pLichKing && pLichKing->isAlive())
                                    DoScriptText(SAY_LICH_KING_WALL_02, pLichKing);
                                IceWallGUID = Gate->GetGUID();
                            }
                            break;
                        case 3:
                            if (GameObject* Gate = instance->instance->GetGameObject(instance->GetData64(GO_ICE_WALL_3)))
                            {
                                Gate->SetGoState(GO_STATE_READY);
                                if (pLichKing && pLichKing->isAlive())
                                    DoScriptText(SAY_LICH_KING_WALL_03, pLichKing);
                                IceWallGUID = Gate->GetGUID();
                            }
                            break;
                        case 4:
                            if (GameObject* Gate = instance->instance->GetGameObject(instance->GetData64(GO_ICE_WALL_4)))
                            {
                                Gate->SetGoState(GO_STATE_READY);
                                if (pLichKing && pLichKing->isAlive())
                                    DoScriptText(SAY_LICH_KING_WALL_04, pLichKing);
                                IceWallGUID = Gate->GetGUID();
                            }
                            break;
                        case 5:
                            if (pLichKing && pLichKing->isAlive())
                            {
                                pLichKing->RemoveAurasDueToSpell(SPELL_WINTER);
                                pLichKing->SetSpeed(MOVE_WALK, 2.5f, true);
                                Step = 0;
                            }
                            break;
                    }
                }
                else
                {
                    HoldTimer -= diff;
                    if (HoldTimer <= 0)
                        HoldTimer = 0;
                }

                return;
            }
        };
};

class at_hor_waves_restarter : public AreaTriggerScript
{
    public:
        at_hor_waves_restarter() : AreaTriggerScript("at_hor_waves_restarter") {}

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/)
        {
            InstanceScript* pInstance = player->GetInstanceScript();

            if (player->isGameMaster())
                return true;

            if (pInstance->GetData(DATA_WAVE_COUNT) == SPECIAL)
                return true;

            if (pInstance->GetData(DATA_MARWYN_EVENT) != DONE)
            {
                pInstance->SetData(DATA_WAVE_COUNT, SPECIAL);

                if (Creature* pFalric = player->GetCreature(*player, pInstance->GetData64(DATA_FALRIC)))
                {
                    pFalric->CastSpell(pFalric, SPELL_FALRIC_MARWYN_SPAWN_AURA, true);
                    pFalric->SetVisible(true);
                }
                if (Creature* pMarwyn = player->GetCreature(*player, pInstance->GetData64(DATA_MARWYN)))
                {
                    pMarwyn->CastSpell(pMarwyn, SPELL_FALRIC_MARWYN_SPAWN_AURA, true);
                    pMarwyn->SetVisible(true);
                }
            }
            return true;
        }
};
/*
class npc_queldelar : public CreatureScript
{
public:
    npc_queldelar() : CreatureScript("npc_queldelar") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_queldelarAI(creature);
    }
    struct npc_queldelarAI  : public ScriptedAI
    {
        npc_queldelarAI(Creature *c) : ScriptedAI(c)
        {
        }
        void MoveInLineOfSight(Unit* who)
        {
            if (!who)
                return;
            if (me->IsWithinDistInMap(who, 20) && who->HasAura(SPELL_QUELDELAR_AURA))
            {
                me->SummonCreature(NPC_QUELDELAR, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                me->DisappearAndDie();
            }
        }
    };
};*/

class spell_hor_equip_frostmourne : public SpellScriptLoader
{
    public:
        spell_hor_equip_frostmourne() : SpellScriptLoader("spell_hor_equip_frostmourne") { }

        class spell_hor_equip_frostmourne_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hor_equip_frostmourne_AuraScript);

            void Remove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    caster->CastSpell(caster, SPELL_EQUIP_FROSTMOURNE, true);

                    if (InstanceScript* instance = caster->GetInstanceScript())
                    {
                        instance->GetData64(
                    }
                }
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_hor_equip_frostmourne_AuraScript::Remove, EFFECT_0, SPELL_EFFECT_APPLY_AURA, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_hor_equip_frostmourne_AuraScript();
        }
};

void AddSC_halls_of_reflection()
{
    new npc_jaina_or_sylvanas_hor(true, "npc_sylvanas_hor_part1");
    new npc_jaina_or_sylvanas_hor(false, "npc_jaina_hor_part1");
    new npc_ghostly_priest();
    new npc_phantom_mage();
    new npc_phantom_hallucination();
    new npc_shadowy_mercenary();
    new npc_spectral_footman();
    new npc_tortured_rifleman();
}
