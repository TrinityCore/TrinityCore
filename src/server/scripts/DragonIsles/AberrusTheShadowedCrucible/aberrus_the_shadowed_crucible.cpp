/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Conversation.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "aberrus_the_shadowed_crucible.h"

enum AberrusMisc
{
    CONVERSATION_SABELLIAN_INTRO      = 20800, // Sabellian and Wrathion
    CONVERSATION_SARKARETH_INTRO      = 20970, // Sabellian and Sarkareth
    CONVERSATION_KAZZARA_SUMMON_INTRO = 20985, // Winglord Dezran, Sarkareth and Zskarn

    // Sabellian intro
    CONVO_ACTOR_IDX_SABELLIAN         = 0,

    CONVO_SABELLIAN_INTRO_LINE_01     = 56690,
    CONVO_SABELLIAN_INTRO_LINE_02     = 56692,

    // Kazzara intro
    CONVO_ACTOR_IDX_WINGLORD_DEZRAN   = 0,
    CONVO_ACTOR_IDX_ZSKARN            = 1,
    CONVO_ACTOR_IDX_SARKARETH         = 2,

    CONVO_SARKARETH_LAST_LINE         = 57821
};

enum AberrusEvents
{
    EVENT_SABELLIAN_MOVE = 1,
    EVENT_SABELLIAN_MOVE_HOME_POS,
    EVENT_KAZZARA_INTRO,
    EVENT_KAZZARA_INTRO_DONE
};

Position const SabellianConvoPosition  = { 2250.6372f, 2482.3003f, 711.9592f };

Position const SarkarethMovePos[7] =
{
    { 2500.0615f, 2482.264f, 708.7047f },
    { 2511.0615f, 2482.014f, 701.9547f },
    { 2519.8115f, 2485.014f, 700.4547f },
    { 2526.8115f, 2492.264f, 700.4547f },
    { 2535.8115f, 2515.014f, 700.4547f },
    { 2540.0615f, 2529.014f, 700.4547f },
    { 2544.5642f, 2552.007f, 699.9161f }
};

Position const WinglordDezranMovePos[7] =
{
    { 2494.0542f, 2487.5217f, 708.2893f },
    { 2500.8042f, 2487.5217f, 708.5393f },
    { 2512.8042f, 2490.0217f, 700.5393f },
    { 2517.5542f, 2493.2717f, 700.2893f },
    { 2520.8042f, 2500.0217f, 700.2893f },
    { 2531.5542f, 2529.7717f, 700.2893f },
    { 2535.716f, 2551.6182f, 699.9161f }
};

Position const ZskarnMovePos[6] =
{
    { 2500.9102f, 2474.3933f, 708.5393f },
    { 2512.4102f, 2473.3933f, 701.0393f },
    { 2522.9102f, 2476.1433f, 700.2893f },
    { 2534.1602f, 2487.6433f, 700.2893f },
    { 2545.9102f, 2511.8933f, 700.2893f },
    { 2555.8586f, 2552.1042f, 699.9161f }
};

// Id 26 - Areatrigger
struct at_aberrus_sabellian_conversation_intro : AreaTriggerAI
{
    at_aberrus_sabellian_conversation_intro(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        Conversation::CreateConversation(CONVERSATION_SABELLIAN_INTRO, unit, unit->GetPosition(), ObjectGuid::Empty, nullptr, true);
        at->Remove();
    }
};

// Id 27 - Areatrigger
struct at_aberrus_sarkareth_conversation_intro : AreaTriggerAI
{
    at_aberrus_sarkareth_conversation_intro(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        Conversation::CreateConversation(CONVERSATION_SARKARETH_INTRO, unit, unit->GetPosition(), ObjectGuid::Empty, nullptr, true);
        at->Remove();
    }
};

// Id 28 - Areatrigger
struct at_aberrus_kazzara_summon_conversation_intro : AreaTriggerAI
{
    at_aberrus_kazzara_summon_conversation_intro(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        Conversation::CreateConversation(CONVERSATION_KAZZARA_SUMMON_INTRO, unit, unit->GetPosition(), ObjectGuid::Empty, nullptr, true);
        at->Remove();
    }
};

// 20800 - Conversation
class conversation_aberrus_sabellian_intro : public ConversationScript
{
    public:
        conversation_aberrus_sabellian_intro() : ConversationScript("conversation_aberrus_sabellian_intro") { }

        void OnConversationStart(Conversation* conversation) override
        {
            if (Milliseconds const* sabellianMoveStartTime = conversation->GetLineStartTime(DEFAULT_LOCALE, CONVO_SABELLIAN_INTRO_LINE_01))
                _events.ScheduleEvent(EVENT_SABELLIAN_MOVE, *sabellianMoveStartTime);

            if (Milliseconds const* sabellianHomeMoveStartTime = conversation->GetLineStartTime(DEFAULT_LOCALE, CONVO_SABELLIAN_INTRO_LINE_02))
                _events.ScheduleEvent(EVENT_SABELLIAN_MOVE_HOME_POS, *sabellianHomeMoveStartTime + Seconds(2));
        }

        void OnConversationUpdate(Conversation* conversation, uint32 diff) override
        {
            _events.Update(diff);

            switch (_events.ExecuteEvent())
            {
                case EVENT_SABELLIAN_MOVE:
                {
                    Unit* sabellian = conversation->GetActorUnit(CONVO_ACTOR_IDX_SABELLIAN);

                    sabellian->SetWalk(true);
                    sabellian->GetMotionMaster()->MovePoint(0, SabellianConvoPosition);
                    break;
                }
                case EVENT_SABELLIAN_MOVE_HOME_POS:
                {
                    Unit* sabellian = conversation->GetActorUnit(CONVO_ACTOR_IDX_SABELLIAN);

                    sabellian->SetWalk(true);
                    sabellian->GetMotionMaster()->MovePoint(0, sabellian->ToCreature()->GetHomePosition(), false, sabellian->ToCreature()->GetHomePosition().GetOrientation());
                    break;
                }
                default:
                    break;
            }
        }

private:
    EventMap _events;
};

// 20985 - Conversation
class conversation_aberrus_kazzara_intro : public ConversationScript
{
    public:
        conversation_aberrus_kazzara_intro() : ConversationScript("conversation_aberrus_kazzara_intro") { }

        void OnConversationStart(Conversation* conversation) override
        {
            _events.ScheduleEvent(EVENT_KAZZARA_INTRO, conversation->GetLineEndTime(DEFAULT_LOCALE, CONVO_SARKARETH_LAST_LINE));
        }

        void OnConversationUpdate(Conversation* conversation, uint32 diff) override
        {
            _events.Update(diff);

            switch (_events.ExecuteEvent())
            {
                case EVENT_KAZZARA_INTRO:
                {
                    Unit* winglordDezran = conversation->GetActorUnit(CONVO_ACTOR_IDX_WINGLORD_DEZRAN);
                    Unit* zskarn = conversation->GetActorUnit(CONVO_ACTOR_IDX_ZSKARN);
                    Unit* sarkareth = conversation->GetActorUnit(CONVO_ACTOR_IDX_SARKARETH);

                    if (Creature* kazzara = conversation->GetInstanceScript()->GetCreature(DATA_KAZZARA_THE_HELLFORGED))
                        kazzara->AI()->DoAction(ACTION_START_INTRO);

                    for (uint8 i = 0; i < 7; i++)
                    {
                        sarkareth->SetWalk(true);
                        sarkareth->GetMotionMaster()->MovePoint(0, SarkarethMovePos[i], true);
                        sarkareth->ToCreature()->DespawnOrUnsummon(45s);

                        winglordDezran->SetWalk(true);
                        winglordDezran->GetMotionMaster()->MovePoint(0, WinglordDezranMovePos[i], true);
                        winglordDezran->ToCreature()->DespawnOrUnsummon(45s);
                    }

                    for (uint8 i = 0; i < 6; i++)
                    {
                        zskarn->SetWalk(true);
                        zskarn->GetMotionMaster()->MovePoint(0, ZskarnMovePos[i], true);
                        zskarn->ToCreature()->DespawnOrUnsummon(45s, Seconds::max()); // override respawn time due to CREATURE_FLAG_EXTRA_DUNGEON_BOSS
                    }
                    break;
                }
                default:
                    break;
            }
        }

private:
    EventMap _events;
};

void AddSC_aberrus_the_shadowed_crucible()
{
    RegisterAreaTriggerAI(at_aberrus_sabellian_conversation_intro);
    RegisterAreaTriggerAI(at_aberrus_sarkareth_conversation_intro);
    RegisterAreaTriggerAI(at_aberrus_kazzara_summon_conversation_intro);

    new conversation_aberrus_sabellian_intro();
    new conversation_aberrus_kazzara_intro();
}
