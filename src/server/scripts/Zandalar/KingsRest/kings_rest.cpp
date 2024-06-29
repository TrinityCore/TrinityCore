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
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Map.h"
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
    NPC_SHADOW_OF_ZUL                   = 137020,

    // Creature text
    SAY_ANIMATED_GUARDIAN_ENGAGE        = 0,
    SAY_ZUL_PRE_BOSS_EVENT_SPAWN        = 0,

    // DisplayIDs
    DISPLAY_INVISIBLE_ZUL               = 11686,

    // Spell Visuals
    SPELL_VISUAL_ZUL_OPEN_GOB           = 77330,

    // Conversation
    CONV_ZUL_KINGS_REST_INTRO           = 7690,

    // Spawngroups
    SPAWN_GROUP_PRE_FIRST_BOSS          = 1255,

    // Spells
    SPELL_ZUL_SHADOWFORM                = 269058,
    SPELL_ZUL_TRASH_EVENT_STATE         = 269905,
    SPELL_ZUL_DESPAWN_COSMETIC_TRASH    = 270692,
    SPELL_ZUL_SUMMON_VISUAL             = 269619,
    SPELL_ZUL_SUMMON_VISUAL_CHANNEL     = 269623,
    SPELL_SUPPRESSION_SLAM_SELECTOR     = 270002,
    SPELL_SUPPRESSION_SLAM_DAMAGE       = 270003,
    SPELL_RELEASED_INHIBITORS           = 270016,
    SPELL_GUST_SLASH                    = 269931,
    SPELL_GUST_SLASH_DAMAGE             = 269932,
    SPELL_DEATHLY_CHILL                 = 269973,
    SPELL_SHADOW_BOLT_VOLLEY            = 269972,
    SPELL_ANCESTRAL_FURY                = 269976,
    SPELL_VIGILANT_DEFENSE              = 269928,
    SPELL_MINION_OF_ZUL_FIXATE          = 269936,
    SPELL_BOUND_BY_SHADOW               = 269935
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

constexpr Position ShadowOfZulSerpentBossEventSpawnPosition = { -1066.0365f, 2643.302f, 819.37024f, 5.028946f };

// 288466 - Serpentine Seal
struct go_kings_rest_serpentine_seal : public GameObjectAI
{
    go_kings_rest_serpentine_seal(GameObject* go) : GameObjectAI(go) { }

    bool OnGossipHello(Player* /*player*/) override
    {
        me->UseDoorOrButton();
        _scheduler.Schedule(3s, [this](TaskContext)
        {
            if (TempSummon* zul = me->SummonCreature(NPC_SHADOW_OF_ZUL, ShadowOfZulSerpentBossEventSpawnPosition))
                zul->SetScriptStringId("SerpentBossEvent");
        });
        return true;
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 137020 - Shadow of Zul
struct npc_kings_rest_shadow_of_zul : public ScriptedAI
{
    npc_kings_rest_shadow_of_zul(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        if (me->HasStringId("SerpentBossEvent"))
            TriggerSerpentBossEvent();
    }

    void TriggerSerpentBossEvent()
    {
        Seconds delay = 1s;

        _scheduler.Schedule(delay, [this](TaskContext)
        {
            Talk(SAY_ZUL_PRE_BOSS_EVENT_SPAWN);
            me->CastSpell(nullptr, SPELL_ZUL_TRASH_EVENT_STATE, false);
            me->CastSpell(nullptr, SPELL_ZUL_DESPAWN_COSMETIC_TRASH, false);
            if (InstanceScript* instance = me->GetInstanceScript())
            {
                if (GameObject* pool = instance->GetGameObject(DATA_KINGS_REST_LIQUID_POOL))
                    pool->SetGoState(GO_STATE_ACTIVE);
            }
        });

        delay += 9s;

        _scheduler.Schedule(delay, [this](TaskContext)
        {
            std::vector<WorldObject*> spawnedCreatures;
            me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_PRE_FIRST_BOSS, false, false, &spawnedCreatures);
            for (WorldObject* obj : spawnedCreatures)
            {
                Creature* creature = obj->ToCreature();
                if (!creature)
                    continue;

                me->CastSpell(creature, SPELL_ZUL_SUMMON_VISUAL_CHANNEL, false);
            }
        });

        delay += 5s;

        _scheduler.Schedule(delay, [this](TaskContext)
        {
            me->RemoveAurasDueToSpell(SPELL_ZUL_SHADOWFORM);
        });

        delay += 1s;

        _scheduler.Schedule(delay, [this](TaskContext)
        {
            me->SetDisplayId(DISPLAY_INVISIBLE_ZUL);
            me->DespawnOrUnsummon(1s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

struct npc_kings_rest_temple_basic : public ScriptedAI
{
    npc_kings_rest_temple_basic(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->CastSpell(me, SPELL_ZUL_SUMMON_VISUAL, false);
    }
};

enum ShadowBorneWarriorEvent
{
    EVENT_GUST_SLASH    = 1
};

// 134157 - Shadow-Borne Warrior
struct npc_kings_rest_shadow_borne_warrior : public npc_kings_rest_temple_basic
{
    npc_kings_rest_shadow_borne_warrior(Creature* creature) : npc_kings_rest_temple_basic(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_GUST_SLASH, 17s);
    }

    void Reset() override
    {
        _events.Reset();
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
                case EVENT_GUST_SLASH:
                    DoCast(SPELL_GUST_SLASH);
                    _events.ScheduleEvent(EVENT_GUST_SLASH, 17s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

enum ShadowBorneWitchDoctorEvent
{
    EVENT_DEATHLY_CHILL         = 1,
    EVENT_SHADOW_BOLT_VOLLEY
};

// 134174 - Shadow-Borne Witch Doctor
struct npc_kings_rest_shadow_borne_witch_doctor : public npc_kings_rest_temple_basic
{
    npc_kings_rest_shadow_borne_witch_doctor(Creature* creature) : npc_kings_rest_temple_basic(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_DEATHLY_CHILL, 5s);
        _events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 17s);
    }

    void Reset() override
    {
        _events.Reset();
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
                case EVENT_DEATHLY_CHILL:
                    DoCastVictim(SPELL_DEATHLY_CHILL);
                    _events.ScheduleEvent(EVENT_DEATHLY_CHILL, 2s + 500ms);
                    break;
                case EVENT_SHADOW_BOLT_VOLLEY:
                    DoCast(SPELL_SHADOW_BOLT_VOLLEY);
                    _events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 16s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    EventMap _events;
};

enum ShadowBorneChampionEvent
{
    EVENT_ANCESTRAL_FURY    = 1,
    EVENT_VIGILANT_DEFENSE
};

// 134158 - Shadow-Borne Champion
struct npc_kings_rest_shadow_borne_champion : public npc_kings_rest_temple_basic
{
    npc_kings_rest_shadow_borne_champion(Creature* creature) : npc_kings_rest_temple_basic(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_ANCESTRAL_FURY, 35s);
        _events.ScheduleEvent(EVENT_VIGILANT_DEFENSE, 21s);
    }

    void Reset() override
    {
        _events.Reset();
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
                case EVENT_ANCESTRAL_FURY:
                    DoCast(SPELL_ANCESTRAL_FURY);
                    _events.ScheduleEvent(EVENT_ANCESTRAL_FURY, 30s);
                    break;
                case EVENT_VIGILANT_DEFENSE:
                    DoCast(SPELL_VIGILANT_DEFENSE);
                    _events.ScheduleEvent(EVENT_VIGILANT_DEFENSE, 21s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    EventMap _events;
};

// 133943 - Minion of Zul
struct npc_kings_rest_minion_of_zul : public npc_kings_rest_temple_basic
{
    npc_kings_rest_minion_of_zul(Creature* creature) : npc_kings_rest_temple_basic(creature) { }

    void JustAppeared() override
    {
        if (me->HasStringId("TempleEvent"))
            npc_kings_rest_temple_basic::JustAppeared();

        DoCast(SPELL_BOUND_BY_SHADOW);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCast(SPELL_MINION_OF_ZUL_FIXATE);
    }
};

// 17933 - Gust Slash - Areatrigger
struct at_kings_rest_gust_slash : AreaTriggerAI
{
    at_kings_rest_gust_slash(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(nullptr, SPELL_GUST_SLASH_DAMAGE, true);
    }
};

void AddSC_kings_rest()
{
    // Creature
    RegisterKingsRestCreatureAI(npc_kings_rest_animated_guardian);
    RegisterKingsRestCreatureAI(npc_kings_rest_shadow_of_zul);
    RegisterKingsRestCreatureAI(npc_kings_rest_shadow_borne_warrior);
    RegisterKingsRestCreatureAI(npc_kings_rest_shadow_borne_witch_doctor);
    RegisterKingsRestCreatureAI(npc_kings_rest_shadow_borne_champion);
    RegisterKingsRestCreatureAI(npc_kings_rest_minion_of_zul);

    // GameObject
    RegisterGameObjectAI(go_kings_rest_serpentine_seal);

    // Areatrigger
    RegisterAreaTriggerAI(at_kings_rest_trigger_intro_event_with_zul);
    RegisterAreaTriggerAI(at_kings_rest_gust_slash);

    // Conversation
    new conversation_kings_rest_intro();

    // Spells
    RegisterSpellScript(spell_kings_rest_suppression_slam);
    RegisterSpellScript(spell_kings_rest_bound_by_shadow);
    RegisterSpellScript(spell_kings_rest_pit_of_despair);
}
