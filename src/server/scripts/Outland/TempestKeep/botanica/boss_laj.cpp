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
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "ScriptedCreature.h"
#include "the_botanica.h"

enum LajTexts
{
    EMOTE_SUMMON               = 0
};

enum LajSpells
{
    SPELL_ALLERGIC_REACTION    = 34697,
    SPELL_TELEPORT_SELF        = 34673,
    SPELL_THRASH               = 3391,     // No aura here

    SPELL_SUMMON_LASHER_1      = 34681,
    SPELL_SUMMON_FLAYER_1      = 34682,
    SPELL_SUMMON_LASHER_2      = 34684,
    SPELL_SUMMON_FLAYER_2      = 34685,

    SPELL_TRANSFORM_ARCANE     = 34703,
    SPELL_TRANSFORM_FIRE       = 34704,
    SPELL_TRANSFORM_FROST      = 34705,
    SPELL_TRANSFORM_NATURE     = 34707,
    SPELL_TRANSFORM_SHADOW     = 34710
};

enum LajEvents
{
    EVENT_SEQUENCE_1             = 1,
    EVENT_SEQUENCE_2,
    EVENT_SEQUENCE_3,
    EVENT_ALLERGIC_REACTION,
    EVENT_TRANSFORM,
    EVENT_THRASH
};

// 17980 - Laj
struct boss_laj : public BossAI
{
    boss_laj(Creature* creature) : BossAI(creature, DATA_LAJ), _lastTransformSpell(0), _isFirstTransform(true) { }

    void Reset() override
    {
        _Reset();
        _lastTransformSpell = 0;
        _isFirstTransform = true;

        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_SEQUENCE_1, 15s, 25s);
        events.ScheduleEvent(EVENT_ALLERGIC_REACTION, 10s, 20s);
        events.ScheduleEvent(EVENT_TRANSFORM, 20s, 30s);
        events.ScheduleEvent(EVENT_THRASH, 0s, 10s);
    }

    void JustSummoned(Creature* summon) override
    {
        // Not entirely correct, they aggro on their own in a weird way and in general behave weirdly
        if (me->IsEngaged())
            DoZoneInCombat(summon);
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
                // Teleport sequence
                case EVENT_SEQUENCE_1:
                    DoCastSelf(SPELL_TELEPORT_SELF);
                    me->SetReactState(REACT_PASSIVE);
                    events.Repeat(25s, 40s);
                    events.ScheduleEvent(EVENT_SEQUENCE_2, 2s);
                    break;
                case EVENT_SEQUENCE_2:
                    Talk(EMOTE_SUMMON);
                    events.ScheduleEvent(EVENT_SEQUENCE_3, 1s);
                    break;
                case EVENT_SEQUENCE_3:
                    DoCastSelf(RAND(SPELL_SUMMON_LASHER_1, SPELL_SUMMON_FLAYER_1));
                    DoCastSelf(RAND(SPELL_SUMMON_LASHER_2, SPELL_SUMMON_FLAYER_2));
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;

                // Abilities
                case EVENT_ALLERGIC_REACTION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 8.f))
                        DoCast(target, SPELL_ALLERGIC_REACTION);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_TRANSFORM:
                {
                    std::vector<uint32> transformSpells = { SPELL_TRANSFORM_ARCANE, SPELL_TRANSFORM_FIRE, SPELL_TRANSFORM_FROST, SPELL_TRANSFORM_NATURE, SPELL_TRANSFORM_SHADOW };

                    if (_isFirstTransform)
                    {
                        std::erase(transformSpells, SPELL_TRANSFORM_SHADOW);
                        _isFirstTransform = false;
                    }

                    if (_lastTransformSpell)
                    {
                        std::erase(transformSpells, _lastTransformSpell);
                        me->RemoveAurasDueToSpell(_lastTransformSpell);
                    }

                    uint32 selectedSpell = Trinity::Containers::SelectRandomContainerElement(transformSpells);

                    _lastTransformSpell = selectedSpell;

                    DoCastSelf(selectedSpell);
                    events.Repeat(25s, 45s);
                    break;
                }
                case EVENT_THRASH:
                    DoCastSelf(SPELL_THRASH);
                    events.Repeat(15s, 20s);
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
    uint32 _lastTransformSpell;
    bool _isFirstTransform;
};

void AddSC_boss_laj()
{
    RegisterBotanicaCreatureAI(boss_laj);
}
