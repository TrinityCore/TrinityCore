/*
* Copyright 2023 AzgathCore
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
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "de_other_side.h"

enum Spells
{
    SPELL_MASTER_OF_DEATH_CHANNEL = 325258,
    SPELL_MASTER_OF_DEATH_DAMAGE = 334913,
    SPELL_SHATTER_REALITY = 326171,
    SPELL_BWONSAMDI_FURY = 327891, //periodic Dummy
    SPELL_BWONSAMDI_FEWOR = 327893,
    SPELL_DEATH_GATE_APPLY_AT = 324698,
    SPELL_CAPTIVE_LOA = 334810,
    SPELL_COALESCING = 334970,
    SPELL_CRUSH = 334961,
    SPELL_CRUSHED_SOUL_PERIODIC = 327649,
    SPELL_SOULCRASHER = 327646,
};

//166608
struct boss_muehzala : public BossAI
{
    boss_muehzala(Creature* c) : BossAI(c, DATA_MUEHZALA)
    {
        SetCombatMovement(false);
        me->CanFly();
    }

    void Reset() override
    {
        BossAI::Reset();
        if (instance->GetBossState(DATA_HAKKAR_THE_SOULFLAYER) != DONE && instance->GetBossState(DATA_THE_MANASTORMS) != DONE && instance->GetBossState(DATA_DEALER_XYEXA) != DONE)
            me->SetVisible(false);
        else
            me->SetVisible(true);
    }

    void EnterCombat(Unit* /*who*/)
    {
        events.ScheduleEvent(SPELL_SOULCRASHER, 6s);
        events.ScheduleEvent(SPELL_MASTER_OF_DEATH_CHANNEL, 15s);        
        events.ScheduleEvent(SPELL_SHATTER_REALITY, 30s);
    }

    void OnSpellFinished(SpellInfo const* /*spellInfo*/) { }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_SOULCRASHER:
            events.Repeat(9s);
            break;

        case SPELL_MASTER_OF_DEATH_CHANNEL:
            me->CastSpell(nullptr, SPELL_MASTER_OF_DEATH_CHANNEL, false);
            events.Repeat(30s);
            break;

        case SPELL_SHATTER_REALITY:
            //Portals and tele locs
            me->CastSpell(nullptr, SPELL_SHATTER_REALITY, false);
            events.Repeat(40s);
            break;
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        me->RemoveAllAreaTriggers();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->RemoveAllAreaTriggers();
        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        me->RemoveAllAreaTriggers();
    }
};

//23903
struct at_death_gate : public AreaTriggerAI
{
    at_death_gate(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;
    }
};

void AddSC_boss_muehzala()
{
    RegisterCreatureAI(boss_muehzala);
    RegisterAreaTriggerAI(at_death_gate);
}
