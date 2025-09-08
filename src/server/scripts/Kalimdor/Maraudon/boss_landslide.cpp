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
#include "maraudon.h"
#include "ScriptedCreature.h"

enum LandslideSpells
{
    SPELL_KNOCK_AWAY        = 18670,
    SPELL_TRAMPLE           = 5568,
    SPELL_LANDSLIDE         = 21808
};

// 12203 - Landslide
struct boss_landslide : public ScriptedAI
{
    boss_landslide(Creature* creature) : ScriptedAI(creature), _landslide(false) { }

    void Reset() override
    {
        _scheduler.CancelAll();
        _landslide = false;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_KNOCK_AWAY);
                task.Repeat(15s, 25s);
            })
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_TRAMPLE);
                task.Repeat(10s, 20s);
            });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_landslide && me->HealthBelowPctDamaged(50, damage))
        {
            _landslide = true;

            _scheduler.Schedule(0s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_LANDSLIDE);
                task.Repeat(30s, 40s);
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
    bool _landslide;
};

void AddSC_boss_landslide()
{
    RegisterMaraudonCreatureAI(boss_landslide);
}
