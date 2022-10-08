/*
* Copyright 2021 ShadowCore
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
#include "spires_of_ascension.h"

enum Devos
{
    SPELL_LOST_CONFIDENCE_PERIODIC_DAMAGE = 322818, // on any remove trigger lingering doubt
    SPELL_LINGERING_DOUBT_CREATE_AT = 322816,
    SPELL_LINGERING_DOUBT_AT_DAMAGE = 322817,
    SPELL_ARCHONS_BASTION_MISSILE = 335809,
    SPELL_ARCHONS_BASTION_CREATE_AT= 335806,
    //
    SPELL_RUN_THROUGH = 323943,
    SPELL_ABYSSAL_DETONATION_DAMAGE = 334625,
    //Phase 2
};

//162061
struct boss_devos : public BossAI
{
    boss_devos(Creature* creature) : BossAI(creature, DATA_DEVOS) { }

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
        me->CanFly();
        me->SetFlying(true);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(0);
        events.ScheduleEvent(SPELL_LOST_CONFIDENCE_PERIODIC_DAMAGE, 5s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_LOST_CONFIDENCE_PERIODIC_DAMAGE:
            UnitList targetList;
            SelectTargetList(targetList, 2, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->CastSpell(targets, SPELL_LOST_CONFIDENCE_PERIODIC_DAMAGE, false);
            }
            break;
            events.Repeat(18s, 20s);
        }
    }
};

//23641
struct at_lingering_doubt : public AreaTriggerAI
{
    at_lingering_doubt(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (!target->HasAura(SPELL_LINGERING_DOUBT_AT_DAMAGE))
            at->GetCaster()->AddAura(SPELL_LINGERING_DOUBT_AT_DAMAGE, target);
    }

    void OnUnitExit(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->HasAura(SPELL_LINGERING_DOUBT_AT_DAMAGE))
            target->RemoveAura(SPELL_LINGERING_DOUBT_AT_DAMAGE);
    }
};

void AddSC_boss_devos()
{
    RegisterCreatureAI(boss_devos);
    RegisterAreaTriggerAI(at_lingering_doubt);
}