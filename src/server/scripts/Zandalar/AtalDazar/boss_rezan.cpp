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
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "atal_dazar.h"

enum RezanSpells
{
    SPELL_TAIL_SELECTOR               = 255372,
    SPELL_TAIL_DAMAGE                 = 255373,
    SPELL_SERRATED_TEETH              = 255434,
    SPELL_DEVOUR                      = 255421,
    SPELL_TERRIFYING_VISAGE           = 255371,
    SPELL_REVERSE_CAST_RIDE_VEHICLE   = 258344,
    SPELL_PURSUIT                     = 257407,
    SPELL_RIDE_VEHICLE                = 46598,
    SPELL_PILE_OF_BONES_AT_SPAWN      = 256608,
    SPELL_PILE_OF_BONES_AT_SLOW       = 256606,
    SPELL_PILE_OF_BONES_TRIGGER_SPAWN = 256634,
    SPELL_PILE_OF_BONES_SLOW          = 257483,
    SPELL_BOSS_EMOTE_AT_TARGET        = 255600
};

enum RezanEvents
{
    EVENT_TERRIFYING_VISAGE = 1,
    EVENT_TAIL,
    EVENT_SERRATED_TEETH,
    EVENT_PURSUIT
};

enum RezanTexts
{
    SAY_REANIMATED_RAPTOR_WARNING  = 0,
    SAY_REANIMATED_RAPTOR_SUMMONER = 1,
    SAY_TERRIFYING_VISAGE          = 2,
    SAY_PURSUIT                    = 3
};

constexpr Position PilesOfBonesPosition[]
{
    { -814.344f, 2241.63f, 641.538f },
    { -868.391f, 2245.54f, 642.03f  },
    { -887.726f, 2242.22f, 642.04f  },
    { -846.66f,  2247.46f, 641.774f },
    { -902.443f, 2238.86f, 642.331f },
    { -829.602f, 2247.23f, 641.842f },
    { -793.8f,   2239.09f, 641.832f },
    { -859.222f, 2256.25f, 643.136f },
    { -871.375f, 2258.77f, 643.438f },
    { -804.901f, 2254.52f, 641.964f },
    { -884.057f, 2257.15f, 642.643f },
    { -818.212f, 2259.57f, 642.465f },
    { -830.214f, 2265.17f, 642.486f },
    { -897.104f, 2259.22f, 641.901f },
    { -874.649f, 2273.9f,  642.642f },
    { -809.342f, 2272.22f, 641.905f },
    { -821.203f, 2279.28f, 642.488f },
    { -893.123f, 2276.57f, 642.583f },
    { -848.333f, 2288.46f, 642.486f },
    { -797.328f, 2282.58f, 641.182f },
    { -900.995f, 2285.5f,  641.773f },
    { -804.385f, 2293.2f,  641.488f },
    { -895.255f, 2298.0f,  642.486f },
    { -880.141f, 2301.81f, 642.501f },
    { -826.514f, 2306.46f, 642.699f },
    { -871.58f,  2311.03f, 642.487f },
    { -803.264f, 2310.29f, 641.707f },
    { -817.41f,  2313.88f, 641.638f },
    { -889.821f, 2315.4f,  642.486f },
    { -834.929f, 2321.18f, 643.028f },
    { -861.599f, 2322.33f, 642.5f   },
    { -872.771f, 2324.00f, 642.77f  },
    { -825.752f, 2329.17f, 642.247f },
    { -810.163f, 2327.19f, 641.401f },
    { -884.835f, 2331.72f, 642.487f },
    { -843.49f,  2335.39f, 642.765f },
    { -895.611f, 2334.97f, 642.425f },
    { -874.451f, 2340.77f, 643.405f },
    { -817.785f, 2342.43f, 641.914f },
    { -861.078f, 2344.69f, 642.685f },
    { -838.155f, 2345.16f, 642.733f },
    { -869.793f, 2352.61f, 642.515f }
};

// 122963 - Rezan
struct boss_rezan : public BossAI
{
    boss_rezan(Creature* creature) : BossAI(creature, DATA_REZAN) { }

    void JustAppeared() override
    {
        for (Position const& spawnPoint : PilesOfBonesPosition)
        {
            me->CastSpell(spawnPoint, SPELL_PILE_OF_BONES_AT_SPAWN, true);
            me->CastSpell(spawnPoint, SPELL_PILE_OF_BONES_AT_SLOW, true);
        }
    }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (apply && who->ToPlayer())
            DoCast(who, SPELL_DEVOUR, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();

        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        events.ScheduleEvent(EVENT_TERRIFYING_VISAGE, 12200ms);
        events.ScheduleEvent(EVENT_TAIL, 6100ms);
        events.ScheduleEvent(EVENT_SERRATED_TEETH, 8500ms);
        events.ScheduleEvent(EVENT_PURSUIT, 21900ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_TERRIFYING_VISAGE:
            {
                DoCastSelf(SPELL_TERRIFYING_VISAGE);
                Talk(SAY_TERRIFYING_VISAGE);
                events.Repeat(35500ms);
                break;
            }
            case EVENT_TAIL:
            {
                DoCastSelf(SPELL_TAIL_SELECTOR);
                events.Repeat(15800ms, 18200ms);
                break;
            }
            case EVENT_SERRATED_TEETH:
            {
                DoCastVictim(SPELL_SERRATED_TEETH);
                events.Repeat(34100ms);
                break;
            }
            case EVENT_PURSUIT:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                {
                    DoCast(target, SPELL_BOSS_EMOTE_AT_TARGET, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
                    DoCast(target, SPELL_PURSUIT);
                }
                events.Repeat(35200ms);
                break;
            }
            default:
                break;
        }
    }
};

// 255372 - Tail
class spell_rezan_tail_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TAIL_DAMAGE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_TAIL_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rezan_tail_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 255421 - Devour
class spell_rezan_devour : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RIDE_VEHICLE });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->RemoveAura(SPELL_RIDE_VEHICLE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_rezan_devour::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 257407 - Pursuit
class spell_rezan_pursuit : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_REVERSE_CAST_RIDE_VEHICLE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_REVERSE_CAST_RIDE_VEHICLE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_rezan_pursuit::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 255600 - Boss Emote Passed Points 0 @ Target
class spell_rezan_boss_emote_at_target : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Creature* casterCreature = GetCaster()->ToCreature())
            casterCreature->AI()->Talk(SAY_PURSUIT, GetHitUnit());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rezan_boss_emote_at_target::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 255371 - Terrifying Visage
class spell_rezan_terrifying_visage : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* target) -> bool
        {
            return !GetCaster()->IsWithinLOSInMap(target);
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rezan_terrifying_visage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 256608 - Pile of Bones
struct at_rezan_pile_of_bones_spawn_raptor : AreaTriggerAI
{
    at_rezan_pile_of_bones_spawn_raptor(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        Creature* rezan = at->GetInstanceScript()->GetCreature(DATA_REZAN);
        if (!rezan || !rezan->IsInCombat())
            return;

        if (!unit->IsPlayer() || (unit == rezan && !rezan->GetMap()->IsHeroicOrHigher()))
            return;

        rezan->CastSpell(at->GetPosition(), SPELL_PILE_OF_BONES_TRIGGER_SPAWN, true);
        rezan->AI()->Talk(SAY_REANIMATED_RAPTOR_WARNING);
        rezan->AI()->Talk(SAY_REANIMATED_RAPTOR_SUMMONER, unit);
        at->Remove();
    }
};

// 256606 - Pile of Bones
struct at_rezan_pile_of_bones_slow : AreaTriggerAI
{
    at_rezan_pile_of_bones_slow(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        Creature* rezan = at->GetInstanceScript()->GetCreature(DATA_REZAN);
        if (!rezan || !rezan->IsInCombat())
            return;

        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_PILE_OF_BONES_SLOW, true);
        at->Remove();
    }
};

void AddSC_boss_rezan()
{
    RegisterAtalDazarCreatureAI(boss_rezan);

    RegisterSpellScript(spell_rezan_tail_selector);
    RegisterSpellScript(spell_rezan_devour);
    RegisterSpellScript(spell_rezan_pursuit);
    RegisterSpellScript(spell_rezan_boss_emote_at_target);
    RegisterSpellScript(spell_rezan_terrifying_visage);

    RegisterAreaTriggerAI(at_rezan_pile_of_bones_spawn_raptor);
    RegisterAreaTriggerAI(at_rezan_pile_of_bones_slow);
}
