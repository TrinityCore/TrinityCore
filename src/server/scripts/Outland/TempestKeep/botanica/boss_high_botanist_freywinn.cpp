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
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "the_botanica.h"

enum Texts
{
    SAY_AGGRO                  = 0,
    SAY_SLAY                   = 1,
    SAY_TREE                   = 2,
    SAY_DEATH                  = 3,
    SAY_OOC_RANDOM             = 4
};

enum Spells
{
    SPELL_TRANQUILITY          = 34550,
    SPELL_TREE_FORM            = 34551,
    SPELL_SUMMON_FRAYER        = 34557,
    SPELL_PLANT_WHITE          = 34759,
    SPELL_PLANT_GREEN          = 34761,
    SPELL_PLANT_BLUE           = 34762,
    SPELL_PLANT_RED            = 34763,
    SPELL_CANCEL_TRANQUILITY   = 34777
};

enum Events
{
    EVENT_PLANT_SEEDLING       = 1,
    EVENT_TREE_FORM,
    EVENT_TRANQUILITY
};

struct boss_high_botanist_freywinn : public BossAI
{
    boss_high_botanist_freywinn(Creature* creature) : BossAI(creature, DATA_HIGH_BOTANIST_FREYWINN), _frayersKilled(0) { }

    void Reset() override
    {
        _Reset();
        _frayersKilled = 0;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_PLANT_SEEDLING, 6s);
        events.ScheduleEvent(EVENT_TREE_FORM, 30s);
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

    // Do not despawn them
    void JustSummoned(Creature* summon) override
    {
        if (me->IsEngaged())
            DoZoneInCombat(summon);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        // Completely guessed, may be actually not used
        if (spellInfo->Id == SPELL_CANCEL_TRANQUILITY)
        {
            ++_frayersKilled;

            if (_frayersKilled >= 3)
            {
                _frayersKilled = 0;
                me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                me->RemoveAurasDueToSpell(SPELL_TREE_FORM);
            }
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
                case EVENT_PLANT_SEEDLING:
                    DoCastSelf(RAND(SPELL_PLANT_WHITE, SPELL_PLANT_GREEN, SPELL_PLANT_BLUE, SPELL_PLANT_RED));
                    events.Repeat(6s);
                    break;
                case EVENT_TREE_FORM:
                    // Reset counter in case not all frayers were killed and tree phase was ended, otherwise next time it will be enough to
                    // kill only 1 or 2 to stop phase. It's an edge case, quite possible it was not even supported
                    _frayersKilled = 0;
                    Talk(SAY_TREE);
                    DoCastSelf(SPELL_SUMMON_FRAYER);
                    DoCastSelf(SPELL_TREE_FORM);
                    events.Repeat(60s);
                    events.ScheduleEvent(EVENT_TRANQUILITY, 1s);
                    break;
                case EVENT_TRANQUILITY:
                    DoCastSelf(SPELL_TRANQUILITY);
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
    uint8 _frayersKilled;
};

void AddSC_boss_high_botanist_freywinn()
{
    RegisterBotanicaCreatureAI(boss_high_botanist_freywinn);
}
