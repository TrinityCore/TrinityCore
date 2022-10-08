/*
* Copyright (C) 2021 ShadowCore
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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuraEffects.h"
#include "castle_nathria.h"

enum HungeringDestroyer
{   
    EVENT_GAIN_ENERGY = 1,
    SPELL_GROWING_HUNGER_BUFF = 332295,
    SPELL_OVERWHELM = 329774,
    SPELL_GLUTTONOUS_MIASMA = 329298, //every 24s
    SPELL_GLUTTONOUS_MIASMA_DAMAGE = 330590,
    SPELL_GLUTTONOUS_MIASMA_HEAL = 329314,
    SPELL_DESOLATE = 329455, // 20s on combat and then every mimute
    SPELL_VOLATILE_EJECTION_CAST = 334266, //every 30s
    SPELL_VOLATILE_EJECTION_DAMAGE_TAKEN_DEBUFF = 334228,
    SPELL_VOLATILE_EJECTION_MARK = 334064, //apply as aura, 3 targets, 4 mythic
    SPELL_VOLATILE_EJECTION_EXP_VISUAL = 334191,
    SPELL_EXPUNGE_CAST = 329758,
    SPELL_EXPUNGE_DAMAGE = 329742,
    SPELL_EXPUNGE_APPLY_AT = 329725,//20517
    SPELL_CONSUME = 334522,
    //Heroic
    SPELL_OBLITERATING_RIFT_CREATE_AT = 332375, //on expire from expunge target
    SPELL_OBLITERATING_RIFT_DAMAGE = 329835,
    //Mythic
    SPELL_ESSENCE_SAP = 334755,    
};

//164261
struct boss_hungering_destroyer : public BossAI
{
    boss_hungering_destroyer(Creature* creature) : BossAI(creature, DATA_HUNGERING_DESTROYER) { }

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        /*if (instance->GetBossState(DATA_HUNTSMAN_ALTIMOR) != DONE)
        BossAI::EnterEvadeMode();*/
        _EnterCombat();
        events.ScheduleEvent(EVENT_GAIN_ENERGY, 1s);
        events.ScheduleEvent(SPELL_GLUTTONOUS_MIASMA, 3s);
        events.ScheduleEvent(SPELL_OVERWHELM, 5s);
        events.ScheduleEvent(SPELL_VOLATILE_EJECTION_CAST, 10s);
        events.ScheduleEvent(SPELL_DESOLATE, 22s);
        events.ScheduleEvent(SPELL_CONSUME, 92s);        
    }

    void ExecuteEvent(uint32 eventId) override 
    { 
        if (me->GetPower(POWER_ENERGY) == 100)
        {
            me->SetPower(POWER_ENERGY, 0);
            me->CastSpell(nullptr, SPELL_CONSUME, false);
        }
        switch (eventId)
        {

        case EVENT_GAIN_ENERGY:
            me->ModifyPower(POWER_ENERGY, +1);
            events.Repeat(1s);
            break;

        case SPELL_OVERWHELM:
            DoCastVictim(SPELL_OVERWHELM, false);
            events.Repeat(20s);
            break;

        case SPELL_GLUTTONOUS_MIASMA:
        {
            UnitList targetList;
            SelectTargetList(targetList, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->AddAura(SPELL_GLUTTONOUS_MIASMA, targets);
            }
            events.Repeat(24s);
            break;
        }
        case SPELL_VOLATILE_EJECTION_CAST:
        {
            me->CastSpell(nullptr, SPELL_VOLATILE_EJECTION_CAST, false);
            events.Repeat(30s);
            break;
        }
        case SPELL_DESOLATE:
        {
            DoCastAOE(SPELL_DESOLATE, false);
            events.Repeat(60s);
            break;
        }
        }
    }

    void JustReachedHome() override
    { 
        _JustReachedHome();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        me->RemoveAllAreaTriggers();
        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*who*/) override 
    {
        summons.DespawnAll();
        me->RemoveAllAreaTriggers();
        _JustDied();
        std::list<GameObject*> goList;
    }
};

//329725
class aura_expunge : public AuraScript
{
    PrepareAuraScript(aura_expunge);

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {        
        if (GetTarget()->GetMap()->IsHeroic() || GetTarget()->GetMap()->IsMythic())
            GetTarget()->CastSpell(nullptr, SPELL_OBLITERATING_RIFT_CREATE_AT, true);
    }

    void Register() override
    {
       OnEffectRemove += AuraEffectRemoveFn(aura_expunge::HandleRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
    }
};

//329725
struct at_obliterating_rift : public AreaTriggerAI
{
    at_obliterating_rift(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        at->SetDuration(360000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;
        
         at->GetCaster()->CastSpell(unit, SPELL_OBLITERATING_RIFT_DAMAGE, true);
    }
};

//329298
class aura_gluttonous_miasma : public AuraScript
{
    PrepareAuraScript(aura_gluttonous_miasma);

    void OnTick(AuraEffect const* auraEff)
    {
        if (GetCaster() && GetTarget())
        {
            GetTarget()->CastSpell(nullptr, SPELL_GLUTTONOUS_MIASMA_DAMAGE, true);
            GetTarget()->CastSpell(nullptr, SPELL_GLUTTONOUS_MIASMA_HEAL, true);
        }

        if (GetTarget()->GetMap()->IsHeroic() || GetTarget()->GetMap()->IsMythic())
            GetTarget()->CastSpell(nullptr, SPELL_ESSENCE_SAP, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_gluttonous_miasma::OnTick, EFFECT_0, SPELL_AURA_MOD_HEALING_PCT);
    }
};

void AddSC_boss_hungering_destroyer()
{
    RegisterCreatureAI(boss_hungering_destroyer);
    RegisterAuraScript(aura_expunge);
    RegisterAreaTriggerAI(at_obliterating_rift);
    RegisterAuraScript(aura_gluttonous_miasma);
}
