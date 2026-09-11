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
#include "ScriptedEscortAI.h"
#include "ScriptMgr.h"

enum HerodSays
{
    SAY_AGGRO = 0,
    SAY_WHIRLWIND = 1,
    SAY_ENRAGE = 2,
    SAY_KILL = 3,
    EMOTE_ENRAGE = 4
};

enum HerodSpells
{
    SPELL_RUSHINGCHARGE = 8260,
    SPELL_CLEAVE = 15496,
    SPELL_WHIRLWIND = 8989,
    SPELL_FRENZY = 8269
};

enum HerodEvents
{
    EVENT_CLEAVE = 1,
    EVENT_WHIRLWIND
};

enum HerodSummonGroups
{
    SUMMON_GROUP_HEROD_TRAINEE = 0
};

struct boss_herod : public BossAI
{
    boss_herod(Creature* creature) : BossAI(creature, DATA_HEROD)
    {
        _enrage = false;
    }

    void Reset() override
    {
        _enrage = false;
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);
        DoCast(me, SPELL_RUSHINGCHARGE);
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_CLEAVE, 12s);
        events.ScheduleEvent(EVENT_WHIRLWIND, 1min);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        me->SummonCreatureGroup(SUMMON_GROUP_HEROD_TRAINEE);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_enrage && me->HealthBelowPctDamaged(30, damage))
        {
            Talk(EMOTE_ENRAGE);
            Talk(SAY_ENRAGE);
            DoCastSelf(SPELL_FRENZY);
            _enrage = true;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_CLEAVE:
                DoCastVictim(SPELL_CLEAVE);
                events.Repeat(12s);
                break;
            case EVENT_WHIRLWIND:
                Talk(SAY_WHIRLWIND);
                DoCastVictim(SPELL_WHIRLWIND);
                events.Repeat(30s);
                break;
            default:
                break;
        }
    }

private:
    bool _enrage;
};

void AddSC_boss_herod()
{
    RegisterScarletMonasteryCreatureAI(boss_herod);
}
