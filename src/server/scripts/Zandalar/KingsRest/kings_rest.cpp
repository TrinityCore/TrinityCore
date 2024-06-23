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
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Unit.h"
#include "kings_rest.h"

enum KingsRestData
{
    // Creature
    NPC_SHADOW_OF_ZUL               = 137020,

    // Creature text
    SAY_ANIMATED_GUARDIAN_ENGAGE    = 0,

    // DisplayIDs
    DISPLAY_INVISIBLE_ZUL           = 11686,

    // Spell Visuals
    SPELL_VISUAL_ZUL_OPEN_GOB       = 77330,

    // Conversation
    CONV_ZUL_KINGS_REST_INTRO       = 7690,

    // Spells
    SPELL_ZUL_SHADOWFORM            = 269058,
    SPELL_SUPPRESSION_SLAM_SELECTOR = 270002,
    SPELL_SUPPRESSION_SLAM_DAMAGE   = 270003,
    SPELL_RELEASED_INHIBITORS       = 270016
};

constexpr Position ShadowOfZulIntroSpawnPosition = { -944.9617f, 2646.5268f, 832.8684f, 4.716575f };

// 67 - KingsRest - Trigger Intro Event with Shadow of Zul
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

enum AnimatedGuardianEvent
{
    EVENT_SUPPRESSION_SLAM = 1
};

// 133935 - Animated Guardian
struct npc_kings_rest_animated_guardian : public ScriptedAI
{
    npc_kings_rest_animated_guardian(Creature* creature) : ScriptedAI(creature), _suppressionSlamCasts(0), _releasedInhibitors(false) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_ANIMATED_GUARDIAN_ENGAGE);
        _events.ScheduleEvent(EVENT_SUPPRESSION_SLAM, 12s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_releasedInhibitors && me->HealthBelowPctDamaged(50, damage))
        {
            _releasedInhibitors = true;
            _events.DelayEvents(1200ms);
            DoCast(SPELL_RELEASED_INHIBITORS);
        }
    }

    void Reset() override
    {
        _events.Reset();
        _suppressionSlamCasts = 0;
        _releasedInhibitors = false;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SUPPRESSION_SLAM:
                    DoCast(SPELL_SUPPRESSION_SLAM_SELECTOR);
                    _suppressionSlamCasts++;
                    _events.ScheduleEvent(EVENT_SUPPRESSION_SLAM, _suppressionSlamCasts % 2 == 0 ? 12s : 13300ms);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    int32 _suppressionSlamCasts;
    bool _releasedInhibitors;
};

// 270002 - Suppression Slam
class spell_kings_rest_suppression_slam : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUPPRESSION_SLAM_DAMAGE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        // @TODO: visual is a bit off - requires SPELL_ATTR12_UNK11 impl
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SUPPRESSION_SLAM_DAMAGE, false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kings_rest_suppression_slam::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 269935 - Bound by Shadow
class spell_kings_rest_bound_by_shadow : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        GetTarget()->KillSelf();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_kings_rest_bound_by_shadow::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

// 276031 - Pit of Despair
class spell_kings_rest_pit_of_despair : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetCaster()->KillSelf();
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectRemoveFn(spell_kings_rest_pit_of_despair::OnApply, EFFECT_0, SPELL_AURA_MOD_FEAR, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_kings_rest()
{
    // Creature
    RegisterKingsRestCreatureAI(npc_kings_rest_animated_guardian);

    // Areatrigger
    RegisterAreaTriggerAI(at_kings_rest_trigger_intro_event_with_zul);

    // Conversation
    new conversation_kings_rest_intro();

    // Spells
    RegisterSpellScript(spell_kings_rest_suppression_slam);
    RegisterSpellScript(spell_kings_rest_bound_by_shadow);
    RegisterSpellScript(spell_kings_rest_pit_of_despair);
}
