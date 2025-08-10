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

#include "scarlet_monastery.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum AzshirTheSleeplessSpells
{
    SPELL_CALL_OF_THE_GRAVE = 17831,
    SPELL_TERRIFY = 7399,
    SPELL_SOUL_SIPHON = 7290
};

enum AzshirTheSleeplessEvents
{
    EVENT_CALL_OF_GRAVE = 1,
    EVENT_TERRIFY,
    EVENT_SOUL_SIPHON
};

struct boss_azshir_the_sleepless : public BossAI
{
    boss_azshir_the_sleepless(Creature* creature) : BossAI(creature, DATA_AZSHIR)
    {
        _siphon = false;
    }

    void Reset() override
    {
        _Reset();
        _siphon = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_CALL_OF_GRAVE, 30s);
        events.ScheduleEvent(EVENT_TERRIFY, 20s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_siphon && me->HealthBelowPctDamaged(50, damage))
        {
            DoCastVictim(SPELL_SOUL_SIPHON);
            events.ScheduleEvent(EVENT_SOUL_SIPHON, 20s);
            _siphon = true;
        }
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
                case EVENT_CALL_OF_GRAVE:
                    DoCastVictim(SPELL_CALL_OF_THE_GRAVE);
                    events.Repeat(30s);
                    break;
                case EVENT_TERRIFY:
                    DoCastVictim(SPELL_TERRIFY);
                    events.Repeat(20s);
                    break;
                case EVENT_SOUL_SIPHON:
                    DoCastVictim(SPELL_SOUL_SIPHON);
                    events.Repeat(20s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    bool _siphon;
};

void AddSC_boss_azshir_the_sleepless()
{
    RegisterScarletMonasteryCreatureAI(boss_azshir_the_sleepless);
}
