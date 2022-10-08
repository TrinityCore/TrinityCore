/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016-2019 MagicStorm
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

#include "trial_of_valor.h"

enum Spells
{
    SPELL_DANCING_BLADE         = 228003,
    SPELL_HORN_OF_VALOR         = 228012,
};

enum Events
{
    EVENT_DANCING_BLADE         = 1,  // every 20 seconds
    EVENT_HORN_OF_VALOR,                // every 35 seconds
};

enum Says
{
    SAY_HORN  = 0,
    SAY_DEFEAT = 1,
};

class boss_hymdall_tov : public CreatureScript
{
public:

    boss_hymdall_tov() : CreatureScript("boss_hymdall_tov") { }

    struct boss_hymdall_tovAI : public BossAI
    {
        boss_hymdall_tovAI(Creature* creature) : BossAI(creature, DATA_HYMDALL)
        {
            me->SetCanFly(false);

            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));

            instance->SetBossState(DATA_HYMDALL, NOT_STARTED);
        }

        Creature* hyrja = nullptr;
        Creature* odyn = nullptr;
        bool defeat;

        void Reset() override
        {
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));

            hyrja = nullptr;
            odyn = nullptr;

            defeat = false;

            me->SetFaction(14);

            _Reset();
            if (instance)
                instance->SetBossState(DATA_HYMDALL, FAIL);

            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

            me->setActive(true);
            DoZoneInCombat();

            events.ScheduleEvent(EVENT_DANCING_BLADE, 20 * IN_MILLISECONDS); // 22
            events.ScheduleEvent(EVENT_HORN_OF_VALOR, 75 * IN_MILLISECONDS);
            instance->SetBossState(DATA_HYMDALL, IN_PROGRESS);

            hyrja = me->FindNearestCreature(BOSS_HYRJA, 500.0f);
            odyn = me->FindNearestCreature(BOSS_ODYN, 500.0f);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustDied();
                instance->SetBossState(DATA_HYMDALL, DONE);
            }

            me->SetHealth(me->GetMaxHealth());
            me->SetFaction(35);
            me->GetMotionMaster()->MoveTargetedHome();

            //Talk(SAY_DIED);
        }

        void KilledUnit(Unit* victim) override
        {
            //if (victim->GetTypeId() == TYPEID_PLAYER)
            //    Talk(SAY_KILL);
        }

        void JustReachedHome() override
        {
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustReachedHome();
                instance->SetBossState(DATA_HYMDALL, FAIL);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->GetHealthPct() <= 25 && !(me->FindCurrentSpellBySpellId(SPELL_REVIVIFY)))
            {
                me->CastStop();
                me->CastSpell(me, SPELL_REVIVIFY, false);
            }

            if (hyrja && hyrja->GetHealthPct() <= 25 && !(hyrja->FindCurrentSpellBySpellId(SPELL_REVIVIFY))
                && me->GetHealthPct() <= 25 && !(me->FindCurrentSpellBySpellId(SPELL_REVIVIFY)) && !defeat)
            {
                Talk(SAY_DEFEAT);
                defeat = true;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DANCING_BLADE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            me->CastSpell(target, SPELL_DANCING_BLADE, false);
                        events.ScheduleEvent(EVENT_DANCING_BLADE, 20 * IN_MILLISECONDS);
                        break;
                    case EVENT_HORN_OF_VALOR:
                        Talk(SAY_HORN);
                        DoCast(SPELL_HORN_OF_VALOR);
                        events.ScheduleEvent(EVENT_HORN_OF_VALOR, 75 * IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfValorAI<boss_hymdall_tovAI>(creature);
    }
};

// 228006 Dancing Blade
class at_hymdall_dancing_blade : public AreaTriggerEntityScript
{
public:
    at_hymdall_dancing_blade() : AreaTriggerEntityScript("at_hymdall_dancing_blade") { }

    struct at_hymdall_dancing_bladeAI : AreaTriggerAI
    {
        at_hymdall_dancing_bladeAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        uint32 checkTimer = 500;

        enum Spells
        {
            DancingBladeDOT = 228007,
        };

        // Called on each AreaTrigger update
        void OnUpdate(uint32 diff)
        {
            if (checkTimer <= diff)
            {
                GuidUnorderedSet const& insideTargets = at->GetInsideUnits();

                for (ObjectGuid insideTargetGuid : insideTargets)
                    if (Unit* insideTarget = ObjectAccessor::GetUnit(*at->GetCaster(), insideTargetGuid))
                        if (insideTarget->IsPlayer() && !insideTarget->HasAura(Spells::DancingBladeDOT))
                            at->GetCaster()->AddAura(Spells::DancingBladeDOT, insideTarget);
                checkTimer = 500;
            }
            else
                checkTimer -= diff;
        }

        // Called when an unit exit the AreaTrigger, or when the AreaTrigger is removed
        void OnUnitExit(Unit* unit) override
        {
            if (unit->IsPlayer() && unit->HasAura(Spells::DancingBladeDOT))
                unit->RemoveAurasDueToSpell(Spells::DancingBladeDOT);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_hymdall_dancing_bladeAI(areatrigger);
    }
};

void AddSC_boss_hymdall_tov()
{
    new boss_hymdall_tov();
    new at_hymdall_dancing_blade();
}
