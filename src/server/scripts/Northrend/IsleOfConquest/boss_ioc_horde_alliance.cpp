/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "BattlegroundIC.h"

enum BossSpells
{
    SPELL_BRUTAL_STRIKE       = 58460,
    SPELL_DAGGER_THROW        = 67280,
    SPELL_CRUSHING_LEAP       = 68506,
    SPELL_RAGE                = 66776
};

enum BossEvents
{
    EVENT_BRUTAL_STRIKE       = 1,
    EVENT_DAGGER_THROW        = 2,
    EVENT_CRUSHING_LEAP       = 3,
    EVENT_CHECK_RANGE         = 4
};

class boss_ioc_horde_alliance : public CreatureScript
{
public:
    boss_ioc_horde_alliance() : CreatureScript("boss_ioc_horde_alliance") { }

    struct boss_ioc_horde_allianceAI : public ScriptedAI
    {
        boss_ioc_horde_allianceAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _events.Reset();

            uint32 _npcGuard;
            if (me->GetEntry() == NPC_HIGH_COMMANDER_HALFORD_WYRMBANE)
                _npcGuard = NPC_SEVEN_TH_LEGION_INFANTRY;
            else
                _npcGuard = NPC_KOR_KRON_GUARD;

            std::list<Creature*> guardsList;
            me->GetCreatureListWithEntryInGrid(guardsList, _npcGuard, 100.0f);
            for (std::list<Creature*>::const_iterator itr = guardsList.begin(); itr != guardsList.end(); ++itr)
                (*itr)->Respawn();
        };

        void JustEngagedWith(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_BRUTAL_STRIKE, 5s);
            _events.ScheduleEvent(EVENT_DAGGER_THROW,  7 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_CHECK_RANGE,   1 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_CRUSHING_LEAP, 15s);
        }

        void SpellHit(Unit* caster, SpellInfo const* /*spell*/) override
        {
            if (caster->IsVehicle())
                Unit::Kill(me, caster);
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
                    case EVENT_BRUTAL_STRIKE:
                        DoCastVictim(SPELL_BRUTAL_STRIKE);
                        _events.ScheduleEvent(EVENT_BRUTAL_STRIKE, 5s);
                        break;
                    case EVENT_DAGGER_THROW:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                            DoCast(target, SPELL_DAGGER_THROW);
                        _events.ScheduleEvent(EVENT_DAGGER_THROW, 7s);
                        break;
                    case EVENT_CRUSHING_LEAP:
                        DoCastVictim(SPELL_CRUSHING_LEAP);
                        _events.ScheduleEvent(EVENT_CRUSHING_LEAP, 25s);
                        break;
                    case EVENT_CHECK_RANGE:
                        if (me->GetDistance(me->GetHomePosition()) > 25.0f)
                            DoCast(me, SPELL_RAGE);
                        else
                            me->RemoveAurasDueToSpell(SPELL_RAGE);
                        _events.ScheduleEvent(EVENT_CHECK_RANGE, 1s);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_ioc_horde_allianceAI(creature);
    }
};

void AddSC_boss_ioc_horde_alliance()
{
    new boss_ioc_horde_alliance();
}
