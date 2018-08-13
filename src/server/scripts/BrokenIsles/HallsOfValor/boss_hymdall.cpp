/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "ScriptMgr.h"
#include "halls_of_valor.h"

enum hymdallSpells
{
    SPELL_DANCING_BLADE         = 193235,
    SPELL_BLOODLETTING_SWEEP    = 193083,
    SPELL_HORN_VALOR            = 191284,
    SPELL_STATIC_FIELD          = 193260,
    SPELL_STORM_BREATH_AT       = 188404,

    NPC_DANCING_BLADE           = 97960,
};

enum hymdallEvents
{
    EVENT_DANCING_BLADE = 1,
    EVENT_BLOODLETTING_SWEEP,
    EVENT_HORN_VALOR,
    EVENT_DRAKES,
};

enum hymdallSays
{
    SAY_COMBAT      = 0,
    SAY_DRAKES      = 1,
    SAY_HORN        = 2,
    SAY_WEEKNESS    = 3,
    SAY_DIED        = 6,
};

const Position stormDrakeSpawn[8] =
{
    { 3566.13f,     601.736f,   633.8553f,  1.54f },
    { 3503.17f,     592.90f,    633.8553f,  1.54f },
    { 3534.452f,    601.7507f,  633.8553f,  1.54f },
    { 3566.29f,     601.7507f,  633.8553f,  1.54f },
    { 3566.13f,     389.755f,   634.02f,    1.54f },
    { 3503.208f,    465.04f,    633.8553f,  1.54f },
    { 3534.452f,    460.33f,    633.8553f,  1.54f },
    { 3566.29f,     460.33f,    633.8553f,  1.54f },
};

const Position stormDrakeEnd[8] =
{
    { 3566.13f,     389.755f,   634.02f,    1.54f },
    { 3503.208f,    465.04f,    633.8553f,  1.54f },
    { 3534.452f,    460.33f,    633.8553f,  1.54f },
    { 3566.29f,     460.33f,    633.8553f,  1.54f },
    { 3566.13f,     601.736f,   633.8553f,  1.54f },
    { 3503.17f,     592.90f,    633.8553f,  1.54f },
    { 3534.452f,    601.7507f,  633.8553f,  1.54f },
    { 3566.29f,     601.7507f,  633.8553f,  1.54f },
};

// 98542
struct boss_hymdall : public BossAI
{
    boss_hymdall(Creature* creature) : BossAI(creature, DATA_HYMDALL) { }

    std::list<Creature*> creatureList;
    uint32 spawn;
    ObjectGuid drakeGUID;
    bool selectedPosition;

    void Reset() override
    {
        _Reset();

        spawn = 0;

        drakeGUID = ObjectGuid::Empty;
        selectedPosition = false;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();

        events.ScheduleEvent(EVENT_DANCING_BLADE, 16 * IN_MILLISECONDS); // 22
        events.ScheduleEvent(EVENT_BLOODLETTING_SWEEP, 24 * IN_MILLISECONDS);
        events.ScheduleEvent(EVENT_HORN_VALOR, 15 * IN_MILLISECONDS);
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);

        if (summon->GetEntry() == NPC_DANCING_BLADE)
        {
            summon->setFaction(me->getFaction());
            summon->SetReactState(REACT_PASSIVE);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (uint64(damage) > me->GetHealth())
        {
            _JustDied();

            me->SetHealth(me->GetMaxHealth());
            me->setFaction(35);
            me->GetMotionMaster()->MoveTargetedHome();

            if (GameObject* go = instance->GetGameObject(GOB_HYMDALLS_CACHE))
                go->GetPhaseShift().AddPhase(169, PhaseFlags::None, nullptr);
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
                case EVENT_DANCING_BLADE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(target, SPELL_DANCING_BLADE, false);

                    events.ScheduleEvent(EVENT_DANCING_BLADE, 18 * IN_MILLISECONDS);
                    break;
                case EVENT_BLOODLETTING_SWEEP:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(target, SPELL_BLOODLETTING_SWEEP, false);

                    Talk(SAY_WEEKNESS);

                    events.ScheduleEvent(EVENT_BLOODLETTING_SWEEP, 24 * IN_MILLISECONDS);
                    break;
                case EVENT_HORN_VALOR:
                    me->CastSpell(me, SPELL_HORN_VALOR, true);

                    Talk(SAY_DRAKES);
                    Talk(SAY_HORN);

                    GetCreatureListWithEntryInGrid(creatureList, me, NPC_STATIC_FIELD, 100.0f);
                    for (Creature* staticField : creatureList)
                        staticField->CastSpell(staticField, SPELL_STATIC_FIELD, false);

                    spawn = urand(0, 7);

                    if (Creature* drake = me->SummonCreature(97788, stormDrakeSpawn[spawn], TEMPSUMMON_TIMED_DESPAWN, 20000))
                    {
                        if (Creature* rider = me->SummonCreature(94968, stormDrakeSpawn[spawn], TEMPSUMMON_TIMED_DESPAWN, 20000))
                            rider->CastSpell(drake, 46598, true);

                        drakeGUID = drake->GetGUID();
                        drake->SetCanFly(true);
                        drake->SetWalk(false);
                    }

                    events.ScheduleEvent(EVENT_DRAKES, 5 * IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_HORN_VALOR, 32 * IN_MILLISECONDS);
                    break;

                case EVENT_DRAKES:

                    if (Creature* drake = ObjectAccessor::GetCreature(*me, drakeGUID))
                    {
                        drake->CastSpell(drake, SPELL_STORM_BREATH_AT, true);
                        drake->GetMotionMaster()->MovePoint(0, stormDrakeEnd[spawn]);
                        spawn = 0;
                        drakeGUID = ObjectGuid::Empty;
                    }

                    break;

                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

// 9677
struct areatrigger_storm_breath : AreaTriggerAI
{
    areatrigger_storm_breath(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            if (!unit->HasAura(SPELL_STATIC_FIELD) && caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_STATIC_FIELD, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_STATIC_FIELD);
    }
};

// SpellId 193214
// 9700
struct areatrigger_dancing_blade : AreaTriggerAI
{
    areatrigger_dancing_blade(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    enum Spells
    {
        SPELL_DANCING_BLADE_DAMAGE  = 193234
    };

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_DANCING_BLADE_DAMAGE, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_DANCING_BLADE_DAMAGE);
    }
};

void AddSC_boss_hymdall()
{
    RegisterCreatureAI(boss_hymdall);
    RegisterAreaTriggerAI(areatrigger_storm_breath);
    RegisterAreaTriggerAI(areatrigger_dancing_blade);
}
