/*
 * Copyright 2021 BfaCore
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
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "uldir.h"

enum Spells
{
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_TERRIBLE_THRASH_DAMAGE = 262277,
    SPELL_ROTTING_REGURGITATION = 262292,
    SPELL_SHOCKWAVE_STOMP = 262288,
    SPELL_MALODOROUS_MIASMA_AURA = 262313,
    SPELL_FETID_FRENZY = 262378,
    SPELL_CONSUME_CORRUPTION = 262370,
    SPELL_ENTICING_ESSENCE = 262364,
    SPELL_TRASH_CHUTE_AT = 274470,
    SPELL_PUTRID_PAROXYSM = 262314,
    SPELL_BERSERK = 26662,
};

enum Events
{
    EVENT_TERRIBLE_THRASH = 1,
    EVENT_MALODOROUS_MIASMA,
    EVENT_WASTE_DISPOSAL_UNITS,
    EVENT_ROTTING_REGURGITATION,
    EVENT_SHOCKWAVE_STOMP,
    EVENT_GET_CORRUPTION,
    EVENT_BERSERK
};

enum Texts
{
    SAY_ROTTING_REGURGITATION,
    SAY_WASTE_DISPOSAL_UNITS,
};

enum Actions
{
    ACTION_GET_CORRUPTION = 1,
};

const Position corruption_corpuscle_spawn_pos = { 290.625f, -622.588f, 694.882f, 3.13f };
const Position corruption_corpuscle_spawn_pos2 = { 216.449f, -623.721f, 694.882f, 3.13f };
const Position corruption_corpuscle_spawn_pos3 = { 234.059f, -719.541f, 694.882f, 3.13f };
const Position corruption_corpuscle_spawn_pos4 = { 278.369f, -719.677f, 694.799f, 2.917f };

//133298
struct boss_fetid_devourer : public BossAI
{
    boss_fetid_devourer(Creature* creature) : BossAI(creature, DATA_DEVOURER) { }

    void Reset() override
    {
        BossAI::Reset();
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        me->RemoveAllAreaTriggers();
        me->DespawnCreaturesInArea(NPC_CORRUPTION_CORPUSCLE, 125.0f);
        me->RemoveUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);
        IsLock = true;
    }

    void EnterCombat(Unit* u) override
    {
        _EnterCombat();
        DoCastSelf(SPELL_PERIODIC_ENERGY_GAIN);
        events.ScheduleEvent(EVENT_TERRIBLE_THRASH, 4s);
        events.ScheduleEvent(EVENT_MALODOROUS_MIASMA, 8s);
        events.ScheduleEvent(EVENT_WASTE_DISPOSAL_UNITS, 16s);
        events.ScheduleEvent(EVENT_GET_CORRUPTION, 21s);
        events.ScheduleEvent(EVENT_BERSERK, 330s);
        if (IsHeroic() || (IsMythic()))
        {
            events.ScheduleEvent(EVENT_SHOCKWAVE_STOMP, 12s);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        _DespawnAtEvade();
        me->RemoveAllAreaTriggers();
        me->DespawnCreaturesInArea(NPC_CORRUPTION_CORPUSCLE, 125.0f);
    }

    void JustDied(Unit* u) override
    {
        _JustDied();
        me->RemoveAllAreaTriggers();
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {

        case NPC_CORRUPTION_CORPUSCLE:
            //instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
            summon->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            summon->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
            summon->CastSpell(nullptr, SPELL_ENTICING_ESSENCE, false);
            eaten = false;
            break;
        }
    }

    void DamageTaken(Unit* done_by, uint32& /*damage*/) override
    {
        if (me->HealthBelowPct(51) && IsLock)
        {
            IsLock = false;
            me->CastSpell(nullptr, SPELL_FETID_FRENZY, true);
        }
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->GetEntry() == NPC_DEVOURER)
        {
            if (Creature* corruption = me->FindNearestCreature(NPC_CORRUPTION_CORPUSCLE, 20.0f, true && !eaten))
            {
                if (me->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE))                
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);

                me->SetReactState(REACT_AGGRESSIVE);
            
                eaten = true;
                corruption->CastSpell(me, SPELL_CONSUME_CORRUPTION, false);
                me->GetMotionMaster()->Clear();
                events.ScheduleEvent(EVENT_TERRIBLE_THRASH, 4s);
                events.ScheduleEvent(EVENT_MALODOROUS_MIASMA, 8s);
                events.ScheduleEvent(EVENT_WASTE_DISPOSAL_UNITS, 16s);
                events.ScheduleEvent(EVENT_GET_CORRUPTION, 21s);
                if (IsHeroic() || (IsMythic()))
                {
                    events.ScheduleEvent(EVENT_SHOCKWAVE_STOMP, 12s);
                }
            }
        }
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
        case ACTION_GET_CORRUPTION:
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->GetPower(POWER_ENERGY) == 100)
        {
            if (Unit* breathTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->SetFacingToObject(breathTarget, true);
                me->CastSpell(breathTarget, SPELL_ROTTING_REGURGITATION, false);
                me->SetPower(POWER_ENERGY, 0);
            }
        }

        switch (eventId)
        {
        case EVENT_TERRIBLE_THRASH:
        {
            if (Unit* tank = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                if (tank = SelectTarget(SELECT_TARGET_NEAREST, 0, 25.0f, true))
                {
                    me->CastSpell(tank, SPELL_TERRIBLE_THRASH_DAMAGE, false);
                }
            }
            events.Repeat(4s);
            break;
        }
        case EVENT_MALODOROUS_MIASMA:
        {
            UnitList tarlist;
            SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 500.0f, true);
            for (Unit* targets : tarlist)
            {
                me->AddAura(SPELL_MALODOROUS_MIASMA_AURA, targets);
                targets->GetScheduler().Schedule(19s, [this, targets] (TaskContext context)
                {
                    me->AddAura(SPELL_PUTRID_PAROXYSM, targets);
                });
            }
            events.Repeat(20s);
            break;
        }
        case EVENT_WASTE_DISPOSAL_UNITS:
        {
            uint32 Position = urand(0, 0);
            switch (Position)
            {
            case 0:
                me->SummonCreature(NPC_CORRUPTION_CORPUSCLE, corruption_corpuscle_spawn_pos);                
                break;

            case 1:
                me->SummonCreature(NPC_CORRUPTION_CORPUSCLE, corruption_corpuscle_spawn_pos2);
                break;

            case 2:
                me->SummonCreature(NPC_CORRUPTION_CORPUSCLE, corruption_corpuscle_spawn_pos3);
                break;

            case 3:
                me->SummonCreature(NPC_CORRUPTION_CORPUSCLE, corruption_corpuscle_spawn_pos4);
                break;
            }

            me->AI()->DoAction(ACTION_GET_CORRUPTION);

            events.Repeat(30s);
            break;
        }
        case EVENT_SHOCKWAVE_STOMP:
        {
            DoCastAOE(SPELL_SHOCKWAVE_STOMP);
            events.Repeat(25s);
            break;
        }
        case EVENT_GET_CORRUPTION:
        {
            events.CancelEvent(EVENT_TERRIBLE_THRASH);
            events.CancelEvent(EVENT_MALODOROUS_MIASMA);
            events.CancelEvent(EVENT_WASTE_DISPOSAL_UNITS);
            if (IsHeroic() || (IsMythic()))
            {
                events.CancelEvent(EVENT_SHOCKWAVE_STOMP);
            }
            if (Unit* corruption = instance->GetCreature(NPC_CORRUPTION_CORPUSCLE))
            {               
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);                
                me->SetFacingToObject(corruption, true);
                me->GetMotionMaster()->MovePoint(1, corruption_corpuscle_spawn_pos, true);
            }
            events.Repeat(35s);
            break;
        }
        case EVENT_BERSERK:
        {
            me->AddAura(SPELL_BERSERK);
            break;
        }

        }
    }

    private:
    bool eaten;
};

//133492
struct npc_corruption_corpuscle : public ScriptedAI
{
    npc_corruption_corpuscle(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }
};

void AddSC_boss_fetid_devourer()
{
    RegisterCreatureAI(boss_fetid_devourer);
    RegisterCreatureAI(npc_corruption_corpuscle);
}
