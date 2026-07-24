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

/*
 * Combat timers requires to be revisited
 * Everything requires sniff verification, especially Water Globule
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "ScriptedCreature.h"
#include "serpent_shrine.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum MorogrimTexts
{
    SAY_AGGRO                       = 0,
    SAY_SUMMON                      = 1,
    SAY_SUMMON_BUBL                 = 2,
    SAY_SLAY                        = 3,
    SAY_DEATH                       = 4,
    EMOTE_WATERY_GRAVE              = 5,
    EMOTE_EARTHQUAKE                = 6,
    EMOTE_WATER_GLOBULES            = 7
};

enum MorogrimSpells
{
    // Passive
    SPELL_DOUBLE_ATTACK             = 18943,

    // Combat
    SPELL_TIDAL_WAVE                = 37730,
    SPELL_EARTHQUAKE                = 37764,
    SPELL_WATERY_GRAVE              = 38028,
    SPELL_SUMMON_WATER_GLOBULES     = 37866,

    SPELL_SUMMON_MURLOC_A1          = 37766,
    SPELL_SUMMON_MURLOC_A2          = 37923,
    SPELL_SUMMON_MURLOC_A3          = 37925,
    SPELL_SUMMON_MURLOC_A4          = 37926,
    SPELL_SUMMON_MURLOC_A5          = 37927,
    SPELL_SUMMON_MURLOC_A6          = 39813,
    SPELL_SUMMON_MURLOC_A7          = 39814,
    SPELL_SUMMON_MURLOC_A8          = 39815,
    SPELL_SUMMON_MURLOC_A9          = 39816,
    SPELL_SUMMON_MURLOC_A10         = 39817,

    SPELL_SUMMON_MURLOC_B1          = 37772,
    SPELL_SUMMON_MURLOC_B2          = 37928,
    SPELL_SUMMON_MURLOC_B3          = 37929,
    SPELL_SUMMON_MURLOC_B4          = 37931,
    SPELL_SUMMON_MURLOC_B5          = 37932,
    SPELL_SUMMON_MURLOC_B6          = 39818,
    SPELL_SUMMON_MURLOC_B7          = 39819,
    SPELL_SUMMON_MURLOC_B8          = 39820,
    SPELL_SUMMON_MURLOC_B9          = 39821,
    SPELL_SUMMON_MURLOC_B10         = 39822,

    // Water Globule
    SPELL_WATER_GLOBULE_EXPLODE     = 37871,
    SPELL_WATER_GLOBULE_NEW_TARGET  = 39848,

    // Scripts
    SPELL_WATERY_GRAVE_TELEPORT_1   = 37850,
    SPELL_WATERY_GRAVE_TELEPORT_2   = 38023,
    SPELL_WATERY_GRAVE_TELEPORT_3   = 38024,
    SPELL_WATERY_GRAVE_TELEPORT_4   = 38025,

    SPELL_SUMMON_WATER_GLOBULE_1    = 37854,
    SPELL_SUMMON_WATER_GLOBULE_2    = 37858,
    SPELL_SUMMON_WATER_GLOBULE_3    = 37860,
    SPELL_SUMMON_WATER_GLOBULE_4    = 37861
};

enum MorogrimEvents
{
    EVENT_TIDAL_WAVE                = 1,
    EVENT_EARTHQUAKE,
    EVENT_WATERY_GRAVE,
    EVENT_SUMMON_WATER_GLOBULES
};

static constexpr std::array<uint32, 6> SummonMurlocsNorthSpells =
{
    SPELL_SUMMON_MURLOC_A1,
    SPELL_SUMMON_MURLOC_A3,
    SPELL_SUMMON_MURLOC_A5,
    SPELL_SUMMON_MURLOC_A7,
    SPELL_SUMMON_MURLOC_A9,
    SPELL_SUMMON_MURLOC_A10
};

static constexpr std::array<uint32, 6> SummonMurlocsSouthSpells =
{
    SPELL_SUMMON_MURLOC_B2,
    SPELL_SUMMON_MURLOC_B4,
    SPELL_SUMMON_MURLOC_B6,
    SPELL_SUMMON_MURLOC_B8,
    SPELL_SUMMON_MURLOC_B9,
    SPELL_SUMMON_MURLOC_B10
};

static constexpr std::array<uint32, 4> WateryGraveTeleportSpells =
{
    SPELL_WATERY_GRAVE_TELEPORT_1,
    SPELL_WATERY_GRAVE_TELEPORT_2,
    SPELL_WATERY_GRAVE_TELEPORT_3,
    SPELL_WATERY_GRAVE_TELEPORT_4
};

static constexpr std::array<uint32, 4> SummonWaterGlobulesSpells =
{
    SPELL_SUMMON_WATER_GLOBULE_1,
    SPELL_SUMMON_WATER_GLOBULE_2,
    SPELL_SUMMON_WATER_GLOBULE_3,
    SPELL_SUMMON_WATER_GLOBULE_4
};

// 21213 - Morogrim Tidewalker
struct boss_morogrim_tidewalker : public BossAI
{
    boss_morogrim_tidewalker(Creature* creature) : BossAI(creature, BOSS_MOROGRIM_TIDEWALKER), _isSecondPhaseStarted(false) { }

    void Reset() override
    {
        _Reset();

        _isSecondPhaseStarted = false;

        DoCastSelf(SPELL_DOUBLE_ATTACK);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_TIDAL_WAVE, 10s, 15s);
        events.ScheduleEvent(EVENT_EARTHQUAKE, 35s, 45s);
        events.ScheduleEvent(EVENT_WATERY_GRAVE, 20s, 25s);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_EARTHQUAKE:
                Talk(EMOTE_EARTHQUAKE);
                Talk(SAY_SUMMON);

                for (uint32 spell : SummonMurlocsNorthSpells)
                    DoCastSelf(spell, true);

                for (uint32 spell : SummonMurlocsSouthSpells)
                    DoCastSelf(spell, true);

                break;
            case SPELL_WATERY_GRAVE:
                Talk(EMOTE_WATERY_GRAVE);
                break;
            case SPELL_SUMMON_WATER_GLOBULES:
                Talk(EMOTE_WATER_GLOBULES);
                Talk(SAY_SUMMON_BUBL);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_isSecondPhaseStarted && me->HealthBelowPctDamaged(25, damage))
        {
            _isSecondPhaseStarted = true;
            events.ScheduleEvent(EVENT_SUMMON_WATER_GLOBULES, 0s);
            events.CancelEvent(EVENT_WATERY_GRAVE);
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        DoCastSelf(SPELL_DOUBLE_ATTACK);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void UpdateAI(uint32 diff) override
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
                case EVENT_TIDAL_WAVE:
                    DoCastSelf(SPELL_TIDAL_WAVE, TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD);
                    events.Repeat(20s, 25s);
                    break;
                case EVENT_EARTHQUAKE:
                    DoCastSelf(SPELL_EARTHQUAKE, TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD);
                    events.Repeat(50s, 60s);
                    break;
                case EVENT_WATERY_GRAVE:
                    DoCastSelf(SPELL_WATERY_GRAVE, TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD);
                    events.Repeat(30s, 35s);
                    break;
                case EVENT_SUMMON_WATER_GLOBULES:
                    DoCastSelf(SPELL_SUMMON_WATER_GLOBULES);
                    events.Repeat(40s, 50s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _isSecondPhaseStarted;
};

// 21913 - Water Globule
struct npc_water_globule : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void JustAppeared() override
    {
        DoZoneInCombat();

        _scheduler
            .Schedule(0s, [this](TaskContext task)
            {
                ResetThreatList();
                DoCastSelf(SPELL_WATER_GLOBULE_NEW_TARGET, { SPELLVALUE_MAX_TARGETS, 1 });
                task.Repeat(7s, 10s);
            })
            .Schedule(0s, [this](TaskContext task)
            {
                if (me->IsWithinDistInMap(me->GetVictim(), 5.0f))
                    DoCastVictim(SPELL_WATER_GLOBULE_EXPLODE);
                task.Repeat(1200ms);
            });
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_WATER_GLOBULE_NEW_TARGET:
                if (Unit* unit = target->ToUnit())
                    AddThreat(unit, 3000000.0f);
                break;
            case SPELL_WATER_GLOBULE_EXPLODE:
                me->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 38028 - Watery Grave
class spell_morogrim_tidewalker_watery_grave : public SpellScript
{
    PrepareSpellScript(spell_morogrim_tidewalker_watery_grave);

public:
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(WateryGraveTeleportSpells);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetCaster()->GetVictim());
        Trinity::Containers::RandomResize(targets, 4);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), WateryGraveTeleportSpells[std::min(_targetCount, WateryGraveTeleportSpells.size() - 1)], true);
        _targetCount++;
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_morogrim_tidewalker_watery_grave::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_morogrim_tidewalker_watery_grave::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    std::size_t _targetCount = 0;
};

// 37866 - Summon Water Globules
class spell_morogrim_tidewalker_summon_water_globules : public SpellScript
{
    PrepareSpellScript(spell_morogrim_tidewalker_summon_water_globules);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SummonWaterGlobulesSpells);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        for (uint32 spell : SummonWaterGlobulesSpells)
            caster->CastSpell(caster, spell, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_morogrim_tidewalker_summon_water_globules::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_morogrim_tidewalker()
{
    RegisterSerpentshrineCavernCreatureAI(boss_morogrim_tidewalker);
    RegisterSerpentshrineCavernCreatureAI(npc_water_globule);
    RegisterSpellScript(spell_morogrim_tidewalker_watery_grave);
    RegisterSpellScript(spell_morogrim_tidewalker_summon_water_globules);
}
