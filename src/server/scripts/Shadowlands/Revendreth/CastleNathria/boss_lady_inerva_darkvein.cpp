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

enum Spells
{
    EVENT_GAIN_ENERGY = 1,
    SPELL_LOOSE_ANIMA_PERIODIC_DAMAGE = 325184, //when player interact with container
    SPELL_CONTAINER_BREACH = 325225, //when container reach full energy
    SPELL_FOCUS_ANIMA_CREATE_AT = 331844, // 1409
    SPELL_EXPOSE_DESIRES = 325379,
    SPELL_EXPOSE_DESIRES_DAMAGE = 341621,
    SPELL_WARPED_DESIRES_DEBUFF = 325382,
    SPELL_EXPOSE_COGNITION = 341623,
    SPELL_SHARED_COGNITION = 325908,
    //Exposed
    SPELL_CHANGE_OF_HEART_TRIGGER = 340452,
    SPELL_BOTTLED_ANIMA_CAST = 339557,
    SPELL_BOTTLED_ANIMA = 342280,
    SPELL_BOTTLED_ANIMA_MISSILE = 339556,
    SPELL_BOTTLED_ANIMA_CREATE_AT = 329620, //24398
    SPELL_UNLEASHED_VOLATILY = 329618,
    SPELL_LINGERING_ANIMA_CREATE_AT = 325718, //24030
    SPELL_LINGERING_ANIMA_AT_DAMAGE = 325713,
    SPELL_LESSER_SINS_AND_SUFFERING = 342287,
    SPELL_ANIMA_WEB = 326139, //166766
    SPELL_SINS_OF_THE_PAST_DAMAGE = 326040,
    SPELL_INDEMNIFICATION_PERIODIC_DAMAGE = 331527,
    SPELL_SHARED_SUFFERING = 324983, // spellmisc 21630, missing data
    SPELL_GREATER_SINS_OF_SUFFERING = 342290,
    SPELL_LIGHTLY_CONCETRATED_ANIMA = 342320,
    SPELL_CONCENTRATED_ANIMA = 342321,
    SPELL_ROOTED_IN_ANIMA = 341746,
    EVENT_EXPOSED_COGNITION = 2,
    EVENT_EXPOSED_HEART,
    SPELL_CHANGE_OF_HEART_DAMAGE = 325384,
    EVENT_BOTTLED_ANIMA = 4,
    EVENT_LINGERING_ANIMA,
    EVENT_REPLICATING_ANIMA,
    SPELL_ANIMA_WEB_CREATE_AT = 339614, //21556, missing data
    SPELL_ANIMA_WEB_CREATE_AT_2 = 326094, //20155, missing data
    SPELL_ANIMA_WEB_AT_DAMAGE = 339612,
    EVENT_LIGHTLY_CONCETRATED_ANIMA = 7,
    EVENT_CONCENTRATED_ANIMA,
    EVENT_HIGHLY_CONCENTRATED_ANIMA,
    SPELL_CONCETRATED_ANIMA_PERIODIC_DAMAGE = 332664,
    SPELL_HIGHLY_CONCETRATED_ANIMA_CAST = 342322,
    SPELL_FRAGMENTS_OF_SHADOW_DAMAGE = 325596,
    SPELL_FRAGHMENTS_OF_SHADOW_CREATE_AT = 327125,
};

//165521
struct boss_lady_inerva_darkvein : public BossAI
{
    boss_lady_inerva_darkvein(Creature* creature) : BossAI(creature, DATA_LADY_INERVA_DARKVEIN) { }

private:
    float randAngle;
    float angleOne;
    float angleTwo;

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
        me->SetReactState(REACT_AGGRESSIVE);
       // me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(EVENT_GAIN_ENERGY, 1s);
        events.ScheduleEvent(SPELL_EXPOSE_DESIRES, 5s);
        events.ScheduleEvent(EVENT_EXPOSED_COGNITION, 14s);
        events.ScheduleEvent(EVENT_EXPOSED_HEART, 47s);
        events.ScheduleEvent(EVENT_BOTTLED_ANIMA, 35s);
        events.ScheduleEvent(SPELL_LESSER_SINS_AND_SUFFERING, 50s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->GetPowerPct(POWER_ENERGY) >= 100)
            me->SetPower(POWER_ENERGY, 0);

        switch (eventId)
        {
        case EVENT_GAIN_ENERGY:
            me->ModifyPower(POWER_ENERGY, urand(+5, +15));
            events.Repeat(1s);
            break;

       /* case SPELL_EXPOSE_DESIRES:
            me->CastSpell(nullptr, SPELL_EXPOSE_DESIRES, true);
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_EXPOSE_DESIRES_DAMAGE, false);
                me->AddAura(SPELL_WARPED_DESIRES_DEBUFF, target);
            }
            events.Repeat(19s);
            break;
            
        case EVENT_EXPOSED_COGNITION:
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_EXPOSE_DESIRES_DAMAGE, false);
                me->AddAura(SPELL_WARPED_DESIRES_DEBUFF, target);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    me->AddAura(SPELL_SHARED_COGNITION, target);

                events.ScheduleEvent(EVENT_LINGERING_ANIMA, 1s);
                events.ScheduleEvent(SPELL_LIGHTLY_CONCETRATED_ANIMA, 2s);
            }
            events.Repeat(33s);
            break;
            
        case EVENT_EXPOSED_HEART:
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                if (!target->HasAura(SPELL_WARPED_DESIRES_DEBUFF))
                    me->AddAura(SPELL_CHANGE_OF_HEART_TRIGGER, target);

            events.ScheduleEvent(EVENT_REPLICATING_ANIMA, 1s);
            events.ScheduleEvent(EVENT_HIGHLY_CONCENTRATED_ANIMA, 2s);

            events.Repeat(66s);
            break;
            */
        case EVENT_BOTTLED_ANIMA:
            me->CastSpell(nullptr, SPELL_BOTTLED_ANIMA_CAST, false);
            {
                std::list<Player*> bottledAnimaPosList;
                me->GetPlayerListInGrid(bottledAnimaPosList, 100.0f);
                for (Player* bottledAnimaRandomPos : bottledAnimaPosList)
                {
                    bottledAnimaRandomPos->GetRandomNearPosition(5.0f);
                    me->CastSpell(bottledAnimaRandomPos, SPELL_BOTTLED_ANIMA_CREATE_AT, true);
                }
            }
            events.Repeat(35s);
            break;

        case EVENT_LINGERING_ANIMA:
        {
            std::list<Player*> bottledAnimaPosList;
            me->GetPlayerListInGrid(bottledAnimaPosList, 100.0f);
            for (Player* bottledAnimaRandomPos : bottledAnimaPosList)
            {
                bottledAnimaRandomPos->GetRandomNearPosition(5.0f);
                me->CastSpell(bottledAnimaRandomPos, SPELL_BOTTLED_ANIMA_CREATE_AT, true);
                me->CastSpell(bottledAnimaRandomPos, SPELL_LINGERING_ANIMA_CREATE_AT, true);
            }
            break;
        }

        case EVENT_REPLICATING_ANIMA:
        {
            std::list<Player*> bottledAnimaPosList;
            me->GetPlayerListInGrid(bottledAnimaPosList, 100.0f);
            for (Player* bottledAnimaRandomPos : bottledAnimaPosList)
            {
                bottledAnimaRandomPos->GetRandomNearPosition(5.0f);
                me->CastSpell(bottledAnimaRandomPos, SPELL_BOTTLED_ANIMA_CREATE_AT, true);
            }
            break;
        }

        case SPELL_LESSER_SINS_AND_SUFFERING:
        {
            me->SummonCreature(NPC_SINS_OF_THE_PAST, -1612.527f, 6983.473f, 4291.221f, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_SINS_OF_THE_PAST, -1601.090f, 6972.282f, 4291.222f, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_SINS_OF_THE_PAST, -1601.068f, 6995.120f, 4291.221f, TEMPSUMMON_MANUAL_DESPAWN);
            UnitList targetList;
            SelectTargetList(targetList, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->CastSpell(targets, SPELL_SHARED_SUFFERING, true);
            }
            events.Repeat(50s);
            break;
        }

        case SPELL_LIGHTLY_CONCETRATED_ANIMA:
            me->CastSpell(nullptr, SPELL_LIGHTLY_CONCETRATED_ANIMA, false);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_CONCETRATED_ANIMA_PERIODIC_DAMAGE, true);
                me->AddAura(SPELL_ROOTED_IN_ANIMA, target);
                if (IsHeroic() || IsMythic())
                    DoCastRandom(SPELL_CONCETRATED_ANIMA_PERIODIC_DAMAGE, 100.0f, true);
            }
            break;

        case EVENT_HIGHLY_CONCENTRATED_ANIMA:
            me->CastSpell(nullptr, SPELL_HIGHLY_CONCETRATED_ANIMA_CAST, false);
            std::list<Player*> concetratedAnimaTargetList;
            me->GetPlayerListInGrid(concetratedAnimaTargetList, 100.0f);
            for (Player* concetratedTargets : concetratedAnimaTargetList)
            {
                if (concetratedTargets->HasAura(SPELL_CONCENTRATED_ANIMA))
                {
                    this->randAngle = (float(rand()) / float((RAND_MAX)) * 6.28);
                    for (uint8 i = 0; i < 15; i++)
                    {
                        Position castPosOne = me->GetPositionWithDistInOrientation(8.0f, ((((180 / 14.0f) * i) * M_PI / 180) + this->randAngle));
                        me->CastSpell(castPosOne, SPELL_FRAGHMENTS_OF_SHADOW_CREATE_AT, true);
                        this->angleOne = ((((180 / 14.0f) * i) * M_PI / 180) + this->randAngle);
                        //atOne->SetFacingTo(this->angleOne, true);
                        Position castPosTwo = me->GetPositionWithDistInOrientation(8.0f, (((((180 / 14.0f) * i) * M_PI / 180) * -1) + this->randAngle));  
                        me->CastSpell(castPosTwo, SPELL_FRAGHMENTS_OF_SHADOW_CREATE_AT, true);
                        this->angleTwo = (((((180 / 14.0f) * i) * M_PI / 180) * -1) + this->randAngle);
                        //atTwo->SetFacingTo(this->angleTwo, true);
                    }
                }
            }
            break;
        }
    }

    void JustSummoned(Creature* summon) override
    {        
        switch (summon->GetEntry())
        {
        case NPC_SINS_OF_THE_PAST:
            summon->AddAura(SPELL_ANIMA_WEB);
            summon->GetScheduler().Schedule(45s, [this](TaskContext /*context*/)
            {
                if (me)
                {
                    if (Creature* darkvein = me->FindNearestCreature(NPC_LADY_INERVA_DARKVEIN, 100.0f, true))
                    {
                        std::list<Player*> indemnificationList;
                        me->GetPlayerListInGrid(indemnificationList, 100.0f);
                        for (Player* targets : indemnificationList)
                        {
                            if (!targets->HasAura(SPELL_INDEMNIFICATION_PERIODIC_DAMAGE))
                                darkvein->AddAura(SPELL_INDEMNIFICATION_PERIODIC_DAMAGE, targets);
                        }
                    }                    
                }
            });
            break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    { 
        _JustReachedHome();
        me->RemoveAllAreaTriggers();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*victim*/) override
    {        
        _JustDied();
        me->RemoveAllAreaTriggers();
    }
};

//340452
class aura_change_of_heart : public AuraScript
{
    PrepareAuraScript(aura_change_of_heart);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetCaster() || GetTarget())
            return;

        GetCaster()->CastSpell(GetTarget()->GetPosition(), SPELL_CHANGE_OF_HEART_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_change_of_heart::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//24398
struct at_bottled_anima : public AreaTriggerAI
{
    at_bottled_anima(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        if (at->GetCaster())
            at->GetCaster()->CastSpell(at->GetPosition(), SPELL_BOTTLED_ANIMA_MISSILE, true);
    }
};

//24030
struct at_lingering_anima : public AreaTriggerAI
{
    at_lingering_anima(AreaTrigger* at) : AreaTriggerAI(at) { at->SetDuration(MINUTE * 60); }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (at->GetCaster() && !target->HasAura(SPELL_LINGERING_ANIMA_AT_DAMAGE))
            at->GetCaster()->CastSpell(target, SPELL_LINGERING_ANIMA_AT_DAMAGE, true);
    }

    void OnUnitExit(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->HasAura(SPELL_LINGERING_ANIMA_AT_DAMAGE))
            target->RemoveAura(SPELL_LINGERING_ANIMA_AT_DAMAGE);
    }
};

//166766, npc sins of the past, SPELL_SINS_OF_THE_PAST_DAMAGE

//332664
class aura_concentrated_anima : public AuraScript
{
    PrepareAuraScript(aura_concentrated_anima);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget())
            return;

        GetTarget()->SummonCreature(NPC_HARNESSED_SPECTER, GetTarget()->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_concentrated_anima::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

//327125
struct at_fragments_of_shadow : public AreaTriggerAI
{
    at_fragments_of_shadow(AreaTrigger* at) : AreaTriggerAI(at) { at->SetDuration(MINUTE * 60); }

    void OnInitialize() override
    {
        if (!at->GetCaster())
            return;

        Position casterPos = at->GetCaster()->GetPosition();
        at->MovePosition(casterPos, 30.0f, 0.0f);
      //  at->SetDestination(casterPos, 3000);
    }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        at->GetCaster()->CastSpell(target, SPELL_FRAGMENTS_OF_SHADOW_DAMAGE, true);
    }
};

void AddSC_boss_lady_inerva_darkvein()
{
    RegisterCreatureAI(boss_lady_inerva_darkvein);
    RegisterAuraScript(aura_change_of_heart);
    RegisterAreaTriggerAI(at_bottled_anima);
    RegisterAreaTriggerAI(at_lingering_anima);
    RegisterAuraScript(aura_concentrated_anima);
    RegisterAreaTriggerAI(at_fragments_of_shadow);
}
