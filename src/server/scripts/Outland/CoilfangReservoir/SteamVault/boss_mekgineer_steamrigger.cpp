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

/* Timers requires update */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "steam_vault.h"

enum SteamriggerTexts
{
    SAY_MECHANICS               = 0,
    SAY_AGGRO                   = 1,
    SAY_SLAY                    = 2,
    SAY_DEATH                   = 3
};

enum SteamriggerSpells
{
    SPELL_SUPER_SHRINK_RAY      = 31485,
    SPELL_SAW_BLADE             = 31486,
    SPELL_ELECTRIFIED_NET       = 35107,

    SPELL_SUMMON_GNOME_1        = 31528,
    SPELL_SUMMON_GNOME_2        = 31529,
    SPELL_SUMMON_GNOME_3        = 31530,
    SPELL_SUMMON_GNOMES         = 31531,

    SPELL_DISPEL_MAGIC          = 17201,
    SPELL_REPAIR                = 31532
};

enum SteamriggerEvents
{
    EVENT_SHRINK                = 1,
    EVENT_SAW_BLADE,
    EVENT_ELECTRIFIED_NET,
    EVENT_SUMMON,
    EVENT_SUMMON_H
};

enum SteamriggerMisc
{
    POINT_REPAIR                = 1
};

enum SteamriggerPhases : uint8
{
    PHASE_NONE                  = 0,
    PHASE_HEALTH_75,
    PHASE_HEALTH_50,
    PHASE_HEALTH_25
};

// 17796 - Mekgineer Steamrigger
struct boss_mekgineer_steamrigger : public BossAI
{
    boss_mekgineer_steamrigger(Creature* creature) : BossAI(creature, DATA_MEKGINEER_STEAMRIGGER), _phase(PHASE_NONE) { }

    void Reset() override
    {
        _Reset();
        _phase = PHASE_NONE;
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_SHRINK, 20s);
        events.ScheduleEvent(EVENT_SAW_BLADE, 5s, 20s);
        events.ScheduleEvent(EVENT_ELECTRIFIED_NET, 20s, 30s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_SUMMON_H, 15s, 20s);
    }

    // Do not despawn mechanics
    void JustSummoned(Creature* /*summon*/) override { }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase < PHASE_HEALTH_75 && !IsHeroic() && me->HealthBelowPctDamaged(75, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SUMMON, 0s);
        }
        if (_phase < PHASE_HEALTH_50 && !IsHeroic() && me->HealthBelowPctDamaged(50, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SUMMON, 0s);
        }
        if (_phase < PHASE_HEALTH_25 && !IsHeroic() && me->HealthBelowPctDamaged(25, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SUMMON, 0s);
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
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
                case EVENT_SHRINK:
                    DoCastSelf(SPELL_SUPER_SHRINK_RAY);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_SAW_BLADE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1))
                        DoCast(target, SPELL_SAW_BLADE);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_ELECTRIFIED_NET:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_ELECTRIFIED_NET);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_SUMMON:
                    Talk(SAY_MECHANICS);
                    DoCastSelf(SPELL_SUMMON_GNOMES);
                    break;
                case EVENT_SUMMON_H:
                    DoCastSelf(RAND(SPELL_SUMMON_GNOME_1, SPELL_SUMMON_GNOME_2, SPELL_SUMMON_GNOME_3));
                    events.Repeat(20s);
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
    uint8 _phase;
};

// 17951 - Steamrigger Mechanic
struct npc_steamrigger_mechanic : public ScriptedAI
{
    npc_steamrigger_mechanic(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void IsSummonedBy(WorldObject* ownerWO) override
    {
        me->SetReactState(REACT_DEFENSIVE);

        Creature* owner = ownerWO->ToCreature();
        if (!owner)
            return;

        float x, y, z;
        owner->GetContactPoint(me, x, y, z);
        me->GetMotionMaster()->MovePoint(POINT_REPAIR, x, y, z);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_REPAIR)
            DoCastSelf(SPELL_REPAIR);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(5s, 10s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_DISPEL_MAGIC);
            task.Repeat(5s, 10s);
        });

        _scheduler.Schedule(5s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_REPAIR);
            task.Repeat(5s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 31531 - Summon Gnomes
class spell_mekgineer_steamrigger_summon_gnomes : public AuraScript
{
    PrepareAuraScript(spell_mekgineer_steamrigger_summon_gnomes);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_GNOME_1, SPELL_SUMMON_GNOME_2, SPELL_SUMMON_GNOME_3 });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_SUMMON_GNOME_1, true);
        target->CastSpell(target, SPELL_SUMMON_GNOME_2, true);
        target->CastSpell(target, SPELL_SUMMON_GNOME_3, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_mekgineer_steamrigger_summon_gnomes::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_mekgineer_steamrigger()
{
    RegisterSteamVaultCreatureAI(boss_mekgineer_steamrigger);
    RegisterSteamVaultCreatureAI(npc_steamrigger_mechanic);
    RegisterSpellScript(spell_mekgineer_steamrigger_summon_gnomes);
}
