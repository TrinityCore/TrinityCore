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
#include "GameObject.h"
#include "InstanceScript.h"
#include "TemporarySummon.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Unit.h"
#include "kings_rest.h"

enum KingsRestData
{
    // Creature
    NPC_SHADOW_OF_ZUL           = 137020,

    // DisplayIDs
    DISPLAY_INVISIBLE_ZUL       = 11686,

    // Spell Visuals
    SPELL_VISUAL_ZUL_OPEN_GOB   = 77330,

    // Conversation
    CONV_ZUL_KINGS_REST_INTRO   = 7690,

    // Spells
    SPELL_ZUL_SHADOWFORM        = 269058
};

constexpr Position ShadowOfZulIntroSpawnPosition = { -944.9617f, 2646.5268f, 832.8684f, 4.716575f };

// XX - KingsRest - Trigger Intro Event with Shadow of Zul
struct at_kings_rest_trigger_intro_event_with_zul : AreaTriggerAI
{
    at_kings_rest_trigger_intro_event_with_zul(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Conversation::CreateConversation(CONV_ZUL_KINGS_REST_INTRO, unit, unit->GetPosition(), unit->GetGUID());
        at->Remove();
    }
};

// 7690 - Shadow of Zul - KingsRest Intro
class conversation_kings_rest_intro : public ConversationScript
{
public:
    conversation_kings_rest_intro() : ConversationScript("conversation_kings_rest_intro") { }

    enum KingsRestIntroConversationData
    {
        CONVO_ACTOR_INTRO_ZUL   = 64206,

        CONVO_LINE_INTRO_DOOR   = 17526
    };

    enum KingsRestIntroEventData
    {
        EVENT_ZUL_OPEN_INTRO_DOOR   = 1,
        EVENT_ZUL_INTRO_DESPAWN,
    };

    void OnConversationCreate(Conversation* conversation, Unit* /*creator*/) override
    {
        TempSummon* shadowOfZul = conversation->SummonCreature(NPC_SHADOW_OF_ZUL, ShadowOfZulIntroSpawnPosition, TEMPSUMMON_MANUAL_DESPAWN);
        if (!shadowOfZul)
            return;

        conversation->AddActor(CONVO_ACTOR_INTRO_ZUL, 0, shadowOfZul->GetGUID());
        conversation->Start();
    }

    void OnConversationStart(Conversation* conversation) override
    {
        _events.ScheduleEvent(EVENT_ZUL_OPEN_INTRO_DOOR, conversation->GetLineEndTime(DEFAULT_LOCALE, CONVO_LINE_INTRO_DOOR));
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_ZUL_OPEN_INTRO_DOOR:
            {
                Creature* shadowOfZul = conversation->GetActorCreature(0);
                if (!shadowOfZul)
                    break;

                shadowOfZul->RemoveAurasDueToSpell(SPELL_ZUL_SHADOWFORM);
                _events.ScheduleEvent(EVENT_ZUL_INTRO_DESPAWN, 1s);

                if (InstanceScript* instance = conversation->GetInstanceScript())
                {
                    if (GameObject* gate = instance->GetGameObject(DATA_KINGS_REST_INTRO_DOOR))
                    {
                        gate->SetGoState(GO_STATE_ACTIVE);
                        gate->SetSpellVisualId(SPELL_VISUAL_ZUL_OPEN_GOB);
                    }
                }
                break;
            }
            case EVENT_ZUL_INTRO_DESPAWN:
            {
                Creature* shadowOfZul = conversation->GetActorCreature(0);
                if (!shadowOfZul)
                    break;

                shadowOfZul->SetDisplayId(DISPLAY_INVISIBLE_ZUL);
                shadowOfZul->DespawnOrUnsummon(1s);
                break;
            }
            default:
                break;
        }
    }

private:
    EventMap _events;
};

void AddSC_kings_rest()
{
    // Areatrigger
    RegisterAreaTriggerAI(at_kings_rest_trigger_intro_event_with_zul);

    // Conversation
    new conversation_kings_rest_intro();
}
