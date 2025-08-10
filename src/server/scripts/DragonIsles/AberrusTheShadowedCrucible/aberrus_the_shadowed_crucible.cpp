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
#include "ConversationAI.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Unit.h"
#include "aberrus_the_shadowed_crucible.h"

enum AberrusEvents
{
    EVENT_SABELLIAN_MOVE = 1,
    EVENT_SABELLIAN_MOVE_HOME_POS,
    EVENT_KAZZARA_INTRO,
    EVENT_KAZZARA_INTRO_DONE
};

enum AberrusPaths
{
    PATH_SARKARETH                              = (202416 * 10) << 3,
    PATH_WINGLORD_DEZRAN                        = (202610 * 10) << 3,
    PATH_ZSKARN                                 = (202637 * 10) << 3
};

enum AberrusSpells
{
    SPELL_ABERRUS_ENTRANCE_RP_CONVERSATION_1    = 400785, // Sabellian and Wrathion
    SPELL_ABERRUS_ENTRANCE_RP_CONVERSATION_2    = 403340, // Sabellian and Sarkareth
};

enum AberrusMisc
{
    // Sabellian intro
    CONVO_ACTOR_IDX_SABELLIAN                   = 0,

    CONVO_SABELLIAN_INTRO_LINE_01               = 56690,
    CONVO_SABELLIAN_INTRO_LINE_02               = 56692,

    // Kazzara intro
    CONVO_ACTOR_IDX_WINGLORD_DEZRAN             = 0,
    CONVO_ACTOR_IDX_ZSKARN                      = 1,
    CONVO_ACTOR_IDX_SARKARETH                   = 2,

    CONVO_SARKARETH_LAST_LINE                   = 57821
};

Position const SabellianIntroConvoMovePosition = { 2250.6372f, 2482.3003f, 711.9592f };

// Id 26 - Areatrigger
struct at_aberrus_sabellian_conversation_intro : AreaTriggerAI
{
    at_aberrus_sabellian_conversation_intro(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        Creature* sabellian = unit->FindNearestCreature(NPC_SABELLIAN_AT_ABERRUS_ENTRANCE, 50.0f);

        if (!sabellian)
            return;

        sabellian->CastSpell(nullptr, SPELL_ABERRUS_ENTRANCE_RP_CONVERSATION_1);
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

        Creature* sabellian = unit->FindNearestCreature(NPC_SABELLIAN_AT_ABERRUS_ENTRANCE, 50.0f);

        if (!sabellian)
            return;

        sabellian->CastSpell(nullptr, SPELL_ABERRUS_ENTRANCE_RP_CONVERSATION_2);
        at->Remove();
    }
};

// 20800 - Conversation
class conversation_aberrus_sabellian_intro : public ConversationAI
{
public:
    conversation_aberrus_sabellian_intro(Conversation* conversation) : ConversationAI(conversation) { }

    void OnStart() override
    {
        if (Milliseconds const* sabellianMoveStartTime = conversation->GetLineStartTime(DEFAULT_LOCALE, CONVO_SABELLIAN_INTRO_LINE_01))
            _events.ScheduleEvent(EVENT_SABELLIAN_MOVE, *sabellianMoveStartTime);

        if (Milliseconds const* sabellianHomeMoveStartTime = conversation->GetLineStartTime(DEFAULT_LOCALE, CONVO_SABELLIAN_INTRO_LINE_02))
            _events.ScheduleEvent(EVENT_SABELLIAN_MOVE_HOME_POS, *sabellianHomeMoveStartTime + Seconds(2));
    }

    void OnUpdate(uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_SABELLIAN_MOVE:
            {
                Creature* sabellian = conversation->GetActorCreature(CONVO_ACTOR_IDX_SABELLIAN);
                if (!sabellian)
                    break;

                sabellian->SetWalk(true);
                sabellian->GetMotionMaster()->MovePoint(0, SabellianIntroConvoMovePosition);
                break;
            }
            case EVENT_SABELLIAN_MOVE_HOME_POS:
            {
                Creature* sabellian = conversation->GetActorCreature(CONVO_ACTOR_IDX_SABELLIAN);
                if (!sabellian)
                    break;

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
class conversation_aberrus_kazzara_intro : public ConversationAI
{
public:
    conversation_aberrus_kazzara_intro(Conversation* conversation) : ConversationAI(conversation) { }

    void OnStart() override
    {
        _events.ScheduleEvent(EVENT_KAZZARA_INTRO, conversation->GetLineEndTime(DEFAULT_LOCALE, CONVO_SARKARETH_LAST_LINE));
    }

    void OnUpdate(uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_KAZZARA_INTRO:
            {
                Creature* winglordDezran = conversation->GetActorCreature(CONVO_ACTOR_IDX_WINGLORD_DEZRAN);
                Creature* zskarn = conversation->GetActorCreature(CONVO_ACTOR_IDX_ZSKARN);
                Creature* sarkareth = conversation->GetActorCreature(CONVO_ACTOR_IDX_SARKARETH);

                if (!winglordDezran || !zskarn || !sarkareth)
                    return;

                sarkareth->GetMotionMaster()->MovePath(PATH_SARKARETH, false);
                sarkareth->DespawnOrUnsummon(45s);

                winglordDezran->GetMotionMaster()->MovePath(PATH_WINGLORD_DEZRAN, false);
                winglordDezran->DespawnOrUnsummon(45s);

                zskarn->GetMotionMaster()->MovePath(PATH_ZSKARN, false);
                zskarn->DespawnOrUnsummon(45s, Seconds::max()); // override respawn time to prevent instant respawn due to CREATURE_FLAG_EXTRA_DUNGEON_BOSS

                if (InstanceScript* instance = conversation->GetInstanceScript())
                {
                    instance->SetData(DATA_KAZZARA_INTRO_STATE, DONE);
                    if (Creature* kazzara = instance->GetCreature(DATA_KAZZARA_THE_HELLFORGED))
                        kazzara->AI()->DoAction(ACTION_START_KAZZARA_INTRO);
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

    RegisterConversationAI(conversation_aberrus_sabellian_intro);
    RegisterConversationAI(conversation_aberrus_kazzara_intro);
}
