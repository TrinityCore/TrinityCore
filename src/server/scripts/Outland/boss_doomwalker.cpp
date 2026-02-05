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

#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Texts
{
    SAY_AGGRO       = 0,
    SAY_EARTHQUAKE  = 1,
    SAY_OVERRUN     = 2,
    SAY_SLAY        = 3,
    SAY_DEATH       = 4
};

enum Spells
{
    SPELL_EARTHQUAKE        = 32686,
    SPELL_SUNDER_ARMOR      = 33661,
    SPELL_CHAIN_LIGHTNING   = 33665,
    SPELL_SUMMON_OVERRUN_TARGET = 32632, // Serverside
    SPELL_OVERRUN           = 32636,
    SPELL_ENRAGE            = 33653,
    SPELL_MARK_DEATH        = 37128,
    SPELL_AURA_DEATH        = 37131,
    SPELL_KNOCKDOWN         = 13360
};

enum Events
{
    EVENT_ENRAGE    = 1,
    EVENT_ARMOR     = 2,
    EVENT_CHAIN     = 3,
    EVENT_QUAKE     = 4,
    EVENT_OVERRUN   = 5
};

enum DoomwalkerMisc
{
    POINT_OVERRUN         = 0,
    NPC_OVERRUN_TARGET    = 18665
};

struct boss_doomwalker : public ScriptedAI
{
    boss_doomwalker(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _inEnrage = false;
    }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_ENRAGE, 0s);
        _events.ScheduleEvent(EVENT_ARMOR, 5s, 13s);
        _events.ScheduleEvent(EVENT_CHAIN, 10s, 30s);
        _events.ScheduleEvent(EVENT_QUAKE, 25s, 35s);
        _events.ScheduleEvent(EVENT_OVERRUN, 30s, 45s);
        Initialize();
    }

    void KilledUnit(Unit* victim) override
    {
        victim->CastSpell(victim, SPELL_MARK_DEATH, true);

        if (urand(0, 4))
            return;

        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who && who->GetTypeId() == TYPEID_PLAYER && me->IsValidAttackTarget(who))
            if (who->HasAura(SPELL_MARK_DEATH))
                who->CastSpell(who, SPELL_AURA_DEATH, true);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_OVERRUN)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveAurasDueToSpell(SPELL_OVERRUN);

            if (Creature* overrunTarget = me->FindNearestCreature(NPC_OVERRUN_TARGET, 500.0f))
                overrunTarget->DespawnOrUnsummon();
        }
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
                case EVENT_ENRAGE:
                    if (!HealthAbovePct(20))
                    {
                        DoCast(me, SPELL_ENRAGE);
                        _events.ScheduleEvent(EVENT_ENRAGE, 6s);
                        _inEnrage = true;
                    }
                    break;
                case EVENT_OVERRUN:
                    DoCastSelf(SPELL_SUMMON_OVERRUN_TARGET);
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_OVERRUN);
                    DoCastVictim(SPELL_OVERRUN);
                    _events.ScheduleEvent(EVENT_OVERRUN, 25s, 40s);
                    break;
                case EVENT_QUAKE:
                    Talk(SAY_EARTHQUAKE);

                    //remove enrage before casting earthquake because enrage + earthquake = 16000dmg over 8sec and all dead
                    if (_inEnrage)
                        me->RemoveAurasDueToSpell(SPELL_ENRAGE);

                    DoCast(me, SPELL_EARTHQUAKE);
                    _events.ScheduleEvent(EVENT_QUAKE, 30s, 55s);
                    break;
                case EVENT_CHAIN:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                        DoCast(target, SPELL_CHAIN_LIGHTNING);
                    _events.ScheduleEvent(EVENT_CHAIN, 7s, 27s);
                    break;
                case EVENT_ARMOR:
                    DoCastVictim(SPELL_SUNDER_ARMOR);
                    _events.ScheduleEvent(EVENT_ARMOR, 10s, 25s);
                    break;
                default:
                    break;
            }
        }
    }

    private:
        EventMap _events;
        bool _inEnrage;
};

// 32686 - Earthquake
// 326405 - Earthquake
class spell_doomwalker_earthquake : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_KNOCKDOWN });
    }

    void HandleKnockdown(AuraEffect const* /*aurEff*/) const
    {
        if (roll_chance_i(50))
            GetTarget()->CastSpell(GetTarget(), SPELL_KNOCKDOWN, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_doomwalker_earthquake::HandleKnockdown, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 32636 - Overrun
class spell_doomwalker_overrun : public SpellScript
{
    void StartMovement() const
    {
        if (Creature* overrunTarget = GetCaster()->FindNearestCreature(NPC_OVERRUN_TARGET, 500.0f))
            GetCaster()->GetMotionMaster()->MovePoint(0, overrunTarget->GetPosition(), true, {}, {}, MovementWalkRunSpeedSelectionMode::ForceRun);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_doomwalker_overrun::StartMovement);
    }
};

// 32637 - Overrun
class spell_doomwalker_overrun_damage : public SpellScript
{
    void StartNextCast(SpellEffIndex /*effIndex*/) const
    {
        if (GetCaster()->HasAura(SPELL_OVERRUN))
            GetCaster()->CastSpell(nullptr, GetSpellInfo()->Id, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_IGNORE_SET_FACING,
                .TriggeringSpell = GetSpell()
            });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_doomwalker_overrun_damage::StartNextCast, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_doomwalker()
{
    RegisterCreatureAI(boss_doomwalker);
    RegisterSpellScript(spell_doomwalker_earthquake);
    RegisterSpellScript(spell_doomwalker_overrun);
    RegisterSpellScript(spell_doomwalker_overrun_damage);
}
