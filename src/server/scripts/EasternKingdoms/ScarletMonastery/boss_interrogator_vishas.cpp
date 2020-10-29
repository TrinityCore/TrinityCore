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
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "scarlet_monastery.h"
#include "ScriptedCreature.h"

enum Says
{
    SAY_AGGRO               = 0,
    SAY_HEALTH_BELOW_75     = 1,
    SAY_HEALTH_BELOW_25     = 2,
    SAY_KILL                = 3
};

enum Spells
{
    SPELL_SHADOW_WORD_PAIN  = 14032
};

enum Events
{
    EVENT_SHADOW_WORD_PAIN  = 1
};

struct boss_interrogator_vishas : public BossAI
{
    boss_interrogator_vishas(Creature* creature) : BossAI(creature, DATA_INTERROGATOR_VISHAS), _textCount(0) { }

    void Reset() override
    {
        _textCount = 0;
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 6s, 8s);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(75, damage) && _textCount == 0)
        {
            Talk(SAY_HEALTH_BELOW_75);
            ++_textCount;
        }

        if (me->HealthBelowPctDamaged(25, damage) && _textCount == 1)
        {
            Talk(SAY_HEALTH_BELOW_25);
            ++_textCount;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHADOW_WORD_PAIN:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.f, true, true, -SPELL_SHADOW_WORD_PAIN))
                        DoCast(target, SPELL_SHADOW_WORD_PAIN);
                    events.Repeat(7s, 11s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    uint8 _textCount;
};

void AddSC_boss_interrogator_vishas()
{
    RegisterScarletMonasteryCreatureAI(boss_interrogator_vishas);
}
