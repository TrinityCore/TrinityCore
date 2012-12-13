/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "halls_of_reflection.h"
#include "Player.h"

enum Yells
{
    SAY_JAINA_INTRO_1                   = 0,
    SAY_JAINA_INTRO_2                   = 1,
    SAY_JAINA_INTRO_3                   = 2,
    SAY_JAINA_INTRO_4                   = 3,
    SAY_JAINA_INTRO_5                   = 4,
    SAY_JAINA_INTRO_6                   = 5,
    SAY_JAINA_INTRO_7                   = 6,
    SAY_JAINA_INTRO_8                   = 7,
    SAY_JAINA_INTRO_9                   = 8,
    SAY_JAINA_INTRO_10                  = 9,
    SAY_JAINA_INTRO_11                  = 10,
    SAY_JAINA_INTRO_END                 = 11,

    SAY_SYLVANAS_INTRO_1                = 0,
    SAY_SYLVANAS_INTRO_2                = 1,
    SAY_SYLVANAS_INTRO_3                = 2,
    SAY_SYLVANAS_INTRO_4                = 3,
    SAY_SYLVANAS_INTRO_5                = 4,
    SAY_SYLVANAS_INTRO_6                = 5,
    SAY_SYLVANAS_INTRO_7                = 6,
    SAY_SYLVANAS_INTRO_8                = 7,
    SAY_SYLVANAS_INTRO_END              = 8,

    SAY_UTHER_INTRO_A2_1                = 0,
    SAY_UTHER_INTRO_A2_2                = 1,
    SAY_UTHER_INTRO_A2_3                = 2,
    SAY_UTHER_INTRO_A2_4                = 3,
    SAY_UTHER_INTRO_A2_5                = 4,
    SAY_UTHER_INTRO_A2_6                = 5,
    SAY_UTHER_INTRO_A2_7                = 6,
    SAY_UTHER_INTRO_A2_8                = 7,
    SAY_UTHER_INTRO_A2_9                = 8,
    SAY_UTHER_INTRO_H2_1                = 9,
    SAY_UTHER_INTRO_H2_2                = 10,
    SAY_UTHER_INTRO_H2_3                = 11,
    SAY_UTHER_INTRO_H2_4                = 12,
    SAY_UTHER_INTRO_H2_5                = 13,
    SAY_UTHER_INTRO_H2_6                = 14,
    SAY_UTHER_INTRO_H2_7                = 15,

    SAY_LK_INTRO_1                      = 0,
    SAY_LK_INTRO_2                      = 1,
    SAY_LK_INTRO_3                      = 2,

    SAY_FALRIC_INTRO_1                  = 5,
    SAY_FALRIC_INTRO_2                  = 6,

    SAY_MARWYN_INTRO_1                  = 4
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

enum eEnum
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

class npc_jaina_or_sylvanas_hor : public CreatureScript
{
private:
    bool m_isSylvana;

public:
    npc_jaina_or_sylvanas_hor(bool isSylvana, const char* name) : CreatureScript(name), m_isSylvana(isSylvana) { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
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
        status = player->GetQuestStatus(m_isSylvana ? QUEST_WRATH_OF_THE_LICH_KING_H2 : QUEST_WRATH_OF_THE_LICH_KING_A2);
        if (status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_REWARDED)
            player->ADD_GOSSIP_ITEM( 0, "Dark Lady, I think I hear Arthas coming. Whatever you're going to do, do it quickly.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

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
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        uint64 utherGUID;
        uint64 lichkingGUID;

        EventMap events;

        void Reset()
        {
            events.Reset();

            utherGUID = 0;
            lichkingGUID = 0;

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
                    // Begining of intro is differents between fActions as the speech sequence and timers are differents.
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        events.ScheduleEvent(EVENT_INTRO_A2_1, 0);
                    else
                        events.ScheduleEvent(EVENT_INTRO_H2_1, 0);
                    break;

            // A2 Intro Events
                case EVENT_INTRO_A2_1:
                    Talk(SAY_JAINA_INTRO_3);
                    events.ScheduleEvent(EVENT_INTRO_A2_2, 5000);
                    break;
                case EVENT_INTRO_A2_2:
                    Talk(SAY_JAINA_INTRO_4);
                    events.ScheduleEvent(EVENT_INTRO_A2_3, 10000);
                    break;
                case EVENT_INTRO_A2_3:
                    // TODO: she's doing some kind of spell casting emote
                    instance->HandleGameObject(instance->GetData64(DATA_FROSTMOURNE), true);
                    events.ScheduleEvent(EVENT_INTRO_A2_4, 10000);
                    break;
                case EVENT_INTRO_A2_4:
                    // spawn UTHER during speach 2
                    if (Creature* uther = me->SummonCreature(NPC_UTHER, UtherSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        uther->GetMotionMaster()->MoveIdle();
                        uther->SetReactState(REACT_PASSIVE); // be sure he will not aggro arthas
                        utherGUID = uther->GetGUID();
                    }
                    events.ScheduleEvent(EVENT_INTRO_A2_5, 2000);
                    break;
                case EVENT_INTRO_A2_5:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_1);
                    events.ScheduleEvent(EVENT_INTRO_A2_6, 3000);
                    break;
                case EVENT_INTRO_A2_6:
                    Talk(SAY_JAINA_INTRO_5);
                    events.ScheduleEvent(EVENT_INTRO_A2_7, 6000);
                    break;
                case EVENT_INTRO_A2_7:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_2);
                    events.ScheduleEvent(EVENT_INTRO_A2_8, 6500);
                    break;
                case EVENT_INTRO_A2_8:
                    Talk(SAY_JAINA_INTRO_6);
                    events.ScheduleEvent(EVENT_INTRO_A2_9, 2000);
                    break;
                case EVENT_INTRO_A2_9:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_3);
                    events.ScheduleEvent(EVENT_INTRO_A2_10, 9000);
                    break;
                case EVENT_INTRO_A2_10:
                    Talk(SAY_JAINA_INTRO_7);
                    events.ScheduleEvent(EVENT_INTRO_A2_11, 5000);
                    break;
                case EVENT_INTRO_A2_11:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_4);
                    events.ScheduleEvent(EVENT_INTRO_A2_12, 11000);
                    break;
                case EVENT_INTRO_A2_12:
                    Talk(SAY_JAINA_INTRO_8);
                    events.ScheduleEvent(EVENT_INTRO_A2_13, 4000);
                    break;
                case EVENT_INTRO_A2_13:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_5);
                    events.ScheduleEvent(EVENT_INTRO_A2_14, 12500);
                    break;
                case EVENT_INTRO_A2_14:
                    Talk(SAY_JAINA_INTRO_9);
                    events.ScheduleEvent(EVENT_INTRO_A2_15, 10000);
                    break;
                case EVENT_INTRO_A2_15:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_6);
                    events.ScheduleEvent(EVENT_INTRO_A2_16, 22000);
                    break;
                case EVENT_INTRO_A2_16:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_7);
                    events.ScheduleEvent(EVENT_INTRO_A2_17, 4000);
                    break;
                case EVENT_INTRO_A2_17:
                    Talk(SAY_JAINA_INTRO_10);
                    events.ScheduleEvent(EVENT_INTRO_A2_18, 2000);
                    break;
                case EVENT_INTRO_A2_18:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                    {
                        uther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_8);
                    }
                    events.ScheduleEvent(EVENT_INTRO_A2_19, 11000);
                    break;
                case EVENT_INTRO_A2_19:
                    Talk(SAY_JAINA_INTRO_11);
                    events.ScheduleEvent(EVENT_INTRO_LK_1, 2000);
                    break;

            // H2 Intro Events
                case EVENT_INTRO_H2_1:
                    Talk(SAY_SYLVANAS_INTRO_1);
                    events.ScheduleEvent(EVENT_INTRO_H2_2, 8000);
                    break;
                case EVENT_INTRO_H2_2:
                    Talk(SAY_SYLVANAS_INTRO_2);
                    events.ScheduleEvent(EVENT_INTRO_H2_3, 6000);
                    break;
                case EVENT_INTRO_H2_3:
                    Talk(SAY_SYLVANAS_INTRO_3);
                    // TODO: she's doing some kind of spell casting emote
                    events.ScheduleEvent(EVENT_INTRO_H2_4, 6000);
                    break;
                case EVENT_INTRO_H2_4:
                    // spawn UTHER during speach 2
                    if (Creature* uther = me->SummonCreature(NPC_UTHER, UtherSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        uther->GetMotionMaster()->MoveIdle();
                        uther->SetReactState(REACT_PASSIVE); // be sure he will not aggro arthas
                        utherGUID = uther->GetGUID();
                    }
                    events.ScheduleEvent(EVENT_INTRO_H2_5, 2000);
                    break;
                case EVENT_INTRO_H2_5:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_1);
                    events.ScheduleEvent(EVENT_INTRO_H2_6, 11000);
                    break;
                case EVENT_INTRO_H2_6:
                    Talk(SAY_SYLVANAS_INTRO_4);
                    events.ScheduleEvent(EVENT_INTRO_H2_7, 3000);
                    break;
                case EVENT_INTRO_H2_7:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_2);
                    events.ScheduleEvent(EVENT_INTRO_H2_8, 6000);
                    break;
                case EVENT_INTRO_H2_8:
                    Talk(SAY_SYLVANAS_INTRO_5);
                    events.ScheduleEvent(EVENT_INTRO_H2_9, 5000);
                    break;
                case EVENT_INTRO_H2_9:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_3);
                    events.ScheduleEvent(EVENT_INTRO_H2_10, 19000);
                    break;
                case EVENT_INTRO_H2_10:
                    Talk(SAY_SYLVANAS_INTRO_6);
                    events.ScheduleEvent(EVENT_INTRO_H2_11, 1500);
                    break;
                case EVENT_INTRO_H2_11:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_4);
                    events.ScheduleEvent(EVENT_INTRO_H2_12, 19500);
                    break;
                case EVENT_INTRO_H2_12:
                    Talk(SAY_SYLVANAS_INTRO_7);
                    events.ScheduleEvent(EVENT_INTRO_H2_13, 2000);
                    break;
                case EVENT_INTRO_H2_13:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                    {
                        uther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_5);
                    }
                    events.ScheduleEvent(EVENT_INTRO_H2_14, 12000);
                    break;
                case EVENT_INTRO_H2_14:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_6);
                    events.ScheduleEvent(EVENT_INTRO_H2_15, 8000);
                    break;
                case EVENT_INTRO_H2_15:
                    Talk(SAY_SYLVANAS_INTRO_8);
                    events.ScheduleEvent(EVENT_INTRO_LK_1, 2000);
                    break;

            // Remaining Intro Events common for both faction
                case EVENT_INTRO_LK_1:
                    // Spawn LK in front of door, and make him move to the sword.
                    if (Creature* lichking = me->SummonCreature(NPC_LICH_KING_EVENT, LichKingSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        lichking->GetMotionMaster()->MovePoint(0, LichKingMoveThronePos);
                        lichking->SetReactState(REACT_PASSIVE);
                        lichkingGUID = lichking->GetGUID();
                    }

                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                    {
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            uther->AI()->Talk(SAY_UTHER_INTRO_A2_9);
                        else
                            uther->AI()->Talk(SAY_UTHER_INTRO_H2_7);
                    }

                    events.ScheduleEvent(EVENT_INTRO_LK_2, 11000);
                    break;

                case EVENT_INTRO_LK_2:
                     if (Creature* lichking = me->GetCreature(*me, lichkingGUID))
                         lichking->AI()->Talk(SAY_LK_INTRO_1);
                     events.ScheduleEvent(EVENT_INTRO_LK_3, 2000);
                     break;

                case EVENT_INTRO_LK_3:
                     // The Lich King banishes Uther to the abyss.
                     if (Creature* uther = me->GetCreature(*me, utherGUID))
                     {
                         uther->DisappearAndDie();
                         utherGUID = 0;
                     }

                     // He steps forward and removes the runeblade from the heap of skulls.

                     events.ScheduleEvent(EVENT_INTRO_LK_4, 4000);
                     break;

                case EVENT_INTRO_LK_4:
                      if (Creature* lichking = me->GetCreature(*me, lichkingGUID))
                          lichking->AI()->Talk(SAY_LK_INTRO_2);
                    events.ScheduleEvent(EVENT_INTRO_LK_5, 10000);
                    break;

                case EVENT_INTRO_LK_5:
                    // summon Falric and Marwyn. then go back to the door
                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        pFalric->SetVisible(true);
                    if (Creature* pMarwyn = me->GetCreature(*me, instance->GetData64(DATA_MARWYN)))
                        pMarwyn->SetVisible(true);

                    if (Creature* lichking = me->GetCreature(*me, lichkingGUID))
                    {
                        lichking->GetMotionMaster()->MovePoint(0, LichKingSpawnPos);
                        lichking->AI()->Talk(SAY_LK_INTRO_3);
                    }

                    events.ScheduleEvent(EVENT_INTRO_LK_6, 8000);
                    break;

                case EVENT_INTRO_LK_6:
                    if (Creature* falric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        falric->AI()->Talk(SAY_FALRIC_INTRO_1);

                    events.ScheduleEvent(EVENT_INTRO_LK_7, 2000);
                    break;

                case EVENT_INTRO_LK_7:
                    if (Creature* marwyn = me->GetCreature(*me, instance->GetData64(DATA_MARWYN)))
                        marwyn->AI()->Talk(SAY_MARWYN_INTRO_1);

                    events.ScheduleEvent(EVENT_INTRO_LK_8, 2000);
                    break;

                case EVENT_INTRO_LK_8:
                    if (Creature* falric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        falric->AI()->Talk(SAY_FALRIC_INTRO_2);

                    events.ScheduleEvent(EVENT_INTRO_LK_9, 5000);
                    break;

                case EVENT_INTRO_LK_9:
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        Talk(SAY_JAINA_INTRO_END);
                    else
                        Talk(SAY_SYLVANAS_INTRO_END);

                    me->GetMotionMaster()->MovePoint(0, LichKingSpawnPos);
                    // TODO: Loralen/Koreln shall run also
                    events.ScheduleEvent(EVENT_INTRO_END, 10000);
                    break;

                case EVENT_INTRO_END:
                    if (instance)
                        instance->SetData(DATA_WAVE_COUNT, SPECIAL);   // start first wave

                    // Loralen or Koreln disappearAndDie()
                    me->DisappearAndDie();
                    break;

                case EVENT_SKIP_INTRO:
                    // TODO: implement

                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        pFalric->SetVisible(true);
                    if (Creature* pMarwyn = me->GetCreature(*me, instance->GetData64(DATA_MARWYN)))
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

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ghostly_priestAI(creature);
    }

    struct npc_ghostly_priestAI: public ScriptedAI
    {
        npc_ghostly_priestAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

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

            if (me->HasUnitState(UNIT_STATE_CASTING))
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
                        // find an ally with missing HP
                        if (Unit* target = DoSelectLowestHpFriendly(40, DUNGEON_MODE(30000, 50000)))
                        {
                            DoCast(target, SPELL_DARK_MENDING);
                            events.ScheduleEvent(EVENT_DARK_MENDING, 20000);
                        }
                        else
                        {
                            // no friendly unit with missing hp. re-check in just 5 sec.
                            events.ScheduleEvent(EVENT_DARK_MENDING, 5000);
                        }
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

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
        npc_phantom_mageAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

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

            if (me->HasUnitState(UNIT_STATE_CASTING))
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
        npc_phantom_hallucinationAI(Creature* creature) : npc_phantom_mage::npc_phantom_mageAI(creature)
        {
        }

        void JustDied(Unit* /*killer*/)
        {
            DoCast(SPELL_HALLUCINATION_2);
        }
    };

};

class npc_shadowy_mercenary : public CreatureScript
{
public:
    npc_shadowy_mercenary() : CreatureScript("npc_shadowy_mercenary") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_shadowy_mercenaryAI(creature);
    }

    struct npc_shadowy_mercenaryAI: public ScriptedAI
    {
        npc_shadowy_mercenaryAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

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

            if (me->HasUnitState(UNIT_STATE_CASTING))
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
                        DoCast(me->getVictim(), SPELL_DEADLY_POISON);
                        events.ScheduleEvent(EVENT_DEADLY_POISON, 10000);
                        return;
                    case EVENT_ENVENOMED_DAGGER_THROW:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_ENVENOMED_DAGGER_THROW);
                        events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
                        return;
                    case EVENT_KIDNEY_SHOT:
                        DoCast(me->getVictim(), SPELL_KIDNEY_SHOT);
                        events.ScheduleEvent(EVENT_KIDNEY_SHOT, 10000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_spectral_footman : public CreatureScript
{
public:
    npc_spectral_footman() : CreatureScript("npc_spectral_footman") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_spectral_footmanAI(creature);
    }

    struct npc_spectral_footmanAI: public ScriptedAI
    {
        npc_spectral_footmanAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

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

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPECTRAL_STRIKE:
                        DoCast(me->getVictim(), SPELL_SPECTRAL_STRIKE);
                        events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000);
                        return;
                    case EVENT_SHIELD_BASH:
                        DoCast(me->getVictim(), SPELL_SHIELD_BASH);
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
    };

};

class npc_tortured_rifleman : public CreatureScript
{
public:
    npc_tortured_rifleman() : CreatureScript("npc_tortured_rifleman") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_tortured_riflemanAI(creature);
    }

    struct npc_tortured_riflemanAI  : public ScriptedAI
    {
        npc_tortured_riflemanAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

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

            if (me->HasUnitState(UNIT_STATE_CASTING))
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
    };

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
