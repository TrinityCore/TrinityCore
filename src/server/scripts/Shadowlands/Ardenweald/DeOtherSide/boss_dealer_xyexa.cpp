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
#include "de_other_side.h"

enum Spells
{
    SPELL_DISPLACEMENT_TRAP = 319619,
    SPELL_DISPLACEMENT_TRAP_CREATE_AT = 319636, //23341, 19347
    SPELL_DISPLACEMENT_TRAP_DAMAGE = 320834,
    SPELL_DISPLACEMENT_TRAP_MISSILE = 319627,
    SPELL_DISPLACEMENT_TRAP_MAIN = 334199,
    SPELL_LOCALIZED_EXPOSIVE_CONTRIVANCE_MARK = 321948,
    SPELL_LOCALIZED_EXPLOSIVE_CONTRIVANCE_PERIODIC = 342961,
    SPELL_EXPLOSIVE_CONTRIVANCE_CAST = 320230,
    SPELL_EXPLOSIVE_CONTRIVANCE_PERIODIC = 320232,
    SPELL_LOCALIZED_EXPLOSIVE_CONTRIVANCE_CREATE_VISUAL_AT = 342962,
};

//164450
struct boss_dealer_xyexa : public BossAI
{
    boss_dealer_xyexa(Creature* c) : BossAI(c, DATA_DEALER_XYEXA) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(SPELL_DISPLACEMENT_TRAP, 3s);
        events.ScheduleEvent(SPELL_LOCALIZED_EXPOSIVE_CONTRIVANCE_MARK, 5s);
        events.ScheduleEvent(SPELL_EXPLOSIVE_CONTRIVANCE_PERIODIC, 10s);
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SPELL_DISPLACEMENT_TRAP:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, 100.0f);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), SPELL_DISPLACEMENT_TRAP_MISSILE, true);
            }
            break;
        }
    
        case SPELL_EXPLOSIVE_CONTRIVANCE_CAST:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_LOCALIZED_EXPOSIVE_CONTRIVANCE_MARK, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_LOCALIZED_EXPLOSIVE_CONTRIVANCE_CREATE_VISUAL_AT, true);
                    at->Remove();
                }
            }
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, 100.0f);
            for (Player* targets : targetList)
            {
                if (targets->GetPositionZ() < -45.0f && !targets->HasAura(SPELL_EXPLOSIVE_CONTRIVANCE_PERIODIC))
                    me->CastSpell(targets, SPELL_EXPLOSIVE_CONTRIVANCE_PERIODIC, true);
            }
            break;
        }
        }    
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_DISPLACEMENT_TRAP:
            me->CastSpell(nullptr, SPELL_DISPLACEMENT_TRAP, true);
            events.Repeat(20s, 25s); 
            break;

        case SPELL_LOCALIZED_EXPOSIVE_CONTRIVANCE_MARK:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0F, true))
            {
                me->CastSpell(target, SPELL_LOCALIZED_EXPOSIVE_CONTRIVANCE_MARK, true);
                me->AddAura(SPELL_LOCALIZED_EXPLOSIVE_CONTRIVANCE_PERIODIC, target);
            }
            events.Repeat(30s);
            break;

        case SPELL_EXPLOSIVE_CONTRIVANCE_PERIODIC:
            me->CastSpell(nullptr, SPELL_EXPLOSIVE_CONTRIVANCE_CAST, false);
            events.Repeat(29s);
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
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        me->RemoveAllAreaTriggers();
    }
};

//319636, 23341
struct at_displacement_trap : public AreaTriggerAI
{
    at_displacement_trap(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!at->GetCaster() || !target->IsPlayer())
            return;

        at->GetCaster()->CastSpell(target, SPELL_DISPLACEMENT_TRAP_DAMAGE, true);
        at->GetCaster()->CastSpell(target, SPELL_DISPLACEMENT_TRAP_MAIN, true);
        target->UpdatePosition(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ() + 30, target->GetOrientation());
	}
};

//321948, 19864
struct at_localized_explosive_contrivance : public AreaTriggerAI
{
    at_localized_explosive_contrivance(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnRemove() override
    {
        std::list<AreaTrigger*> atList;
        at->GetCaster()->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_LOCALIZED_EXPOSIVE_CONTRIVANCE_MARK, 100.0f);
        for (AreaTrigger* at : atList)
        {
            if (at->GetPositionZ() < -45.0f)
            {
                at->GetCaster()->CastSpell(at->GetPosition(), SPELL_LOCALIZED_EXPLOSIVE_CONTRIVANCE_CREATE_VISUAL_AT, true);
                at->Remove();
            }
        }
    }
};

//320230
class spell_explosive_contrivance : public SpellScript
{
    PrepareSpellScript(spell_explosive_contrivance);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (GetHitUnit()->GetPositionZ() < -45.0f)
            targets.remove(GetHitUnit());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_explosive_contrivance::FilterTargets, EFFECT_0, TARGET_DEST_CASTER);
    }
};

void AddSC_boss_dealer_xyexa()
{
    RegisterCreatureAI(boss_dealer_xyexa);
    RegisterAreaTriggerAI(at_displacement_trap);
    RegisterAreaTriggerAI(at_localized_explosive_contrivance);
    RegisterSpellScript(spell_explosive_contrivance);
}