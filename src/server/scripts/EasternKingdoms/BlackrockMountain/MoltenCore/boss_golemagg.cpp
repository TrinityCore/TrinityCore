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

#include "ScriptMgr.h"
#include "molten_core.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum GolemaggTexts
{
    EMOTE_LOW_HEALTH        = 0
};

enum GolemaggSpells
{
    // Golemagg
    SPELL_DOUBLE_ATTACK     = 18943,
    SPELL_GOLEMAGGS_TRUST   = 20556,
    SPELL_MAGMA_SPLASH      = 13879,

    SPELL_PYROBLAST         = 20228,
    SPELL_EARTHQUAKE        = 19798,

    // Core Rager
    SPELL_THRASH            = 12787,
    SPELL_MANGLE            = 19820,
    SPELL_FULL_HEAL         = 17683,
    SPELL_QUIET_SUICIDE     = 3617
};

enum GolemaggEvents
{
    EVENT_PYROBLAST         = 1,
    EVENT_EARTHQUAKE
};

enum GolemaggMisc
{
    NPC_CORE_RAGER          = 11672,
    ACTION_QUIET_SUICIDE    = 0
};

// 11988 - Golemagg the Incinerator
struct boss_golemagg : public BossAI
{
    boss_golemagg(Creature* creature) : BossAI(creature, BOSS_GOLEMAGG_THE_INCINERATOR), _isPerformingEarthquake(false) { }

    void Reset() override
    {
        _Reset();
        _isPerformingEarthquake = false;
        DoCastSelf(SPELL_DOUBLE_ATTACK);
        DoCastSelf(SPELL_GOLEMAGGS_TRUST);
        DoCastSelf(SPELL_MAGMA_SPLASH);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_PYROBLAST, 5s, 10s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_isPerformingEarthquake && me->HealthBelowPctDamaged(10, damage))
        {
            _isPerformingEarthquake = true;
            events.ScheduleEvent(EVENT_EARTHQUAKE, 3s);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        std::vector<Creature*> ragers;
        GetCreatureListWithEntryInGrid(ragers, me, NPC_CORE_RAGER, 250.0f);
        for (Creature* rager : ragers)
            rager->AI()->DoAction(ACTION_QUIET_SUICIDE);
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
                case EVENT_PYROBLAST:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_PYROBLAST);
                    events.Repeat(3s, 13s);
                    break;
                case EVENT_EARTHQUAKE:
                    DoCastSelf(SPELL_EARTHQUAKE);
                    events.Repeat(3s);
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
    bool _isPerformingEarthquake;
};

// 11672 - Core Rager
struct npc_core_rager : public ScriptedAI
{
    npc_core_rager(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _scheduler.CancelAll();
        DoCastSelf(SPELL_THRASH);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(5s, 15s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_MANGLE);
            task.Repeat(10s, 20s);
        });
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_QUIET_SUICIDE)
            DoCastSelf(SPELL_QUIET_SUICIDE, true);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_FULL_HEAL)
            Talk(EMOTE_LOW_HEALTH);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(50, damage))
        {
            _scheduler.Schedule(0s, [this](TaskContext /*task*/)
            {
                DoCastSelf(SPELL_FULL_HEAL);
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_boss_golemagg()
{
    RegisterMoltenCoreCreatureAI(boss_golemagg);
    RegisterMoltenCoreCreatureAI(npc_core_rager);
}
