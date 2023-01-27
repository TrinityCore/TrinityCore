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

enum Shriekwing
{
    SPELL_BLOOD_SHROUD_CAST = 343995,
    SPELL_SANGUINE_ICHOR_CREATE_AT = 340299,//21611
    EVENT_GAIN_ENERGY = 1,
    SPELL_EARSPITTING_SHRIEK_CAST = 330711,
    SPELL_EARSPITTING_SHRIEK_PERIODIC = 330713,
    SPELL_SANGUINE_ICHOR_AT_DAMAGE = 340324,
    SPELL_ECHOLOCATION_MARK = 342077,
    SPELL_DESCENT = 342923,
    SPELL_DEADLY_DESCENT = 343021,
    SPELL_EXSANGUINATING_BITE = 328857,
    SPELL_EXSANGUINATED_DEBUFF = 328897,
    SPELL_BLIND_SWIPE_CAST = 343005,
    SPELL_WAVE_OF_BLOOD = 345397,
    SPELL_ECHOING_SONAR_CAST = 329362,
    SPELL_ECHOING_SONAR_CREATE_AT = 329002,
    SPELL_ECHOING_SONAR_DAMAGE = 343022,
    EVENT_PHASE_ONE = 2,
    SPELL_BERSERK = 343364,
    SPELL_HORRIFIED = 343024,
    //Heroic
    SPELL_ECHOING_SCREECH_CAST = 342864,
    SPELL_ECHOING_SCREECH_CREATE_AT = 342865, //21833
    //Mythic
    SPELL_BLOOD_LANTER_APPLY_AT = 344124, //21734
    SPELL_BLOOD_LANTERN_GRANT_BUTTON = 341684,
    SPELL_BLOOD_LANTERN_STUN = 341490,
    SPELL_BLOOD_LANTER_APPLY_AT_2 = 341690, //21754
    SPELL_BLODLIGHT_APPLY_AT = 343303, //21961
    SPELL_BLOODLIGHT_PERIODIC_DUMMY = 341489,
    SPELL_RAVENOUS_HORROR_MISSILE = 344762,
    EVENT_ECHOING_SONAR_SPAWN = 3,
    EVENT_ECHOING_SCREECH_SPAWN = 4,
    SPELL_BLOODLIGHT_PERIODIC_DAMAGE_TRIGGER = 344235,
};

const Position middle_pos = { -1864.986f, 6779.375f, 4319.209f };
const Position echoingSonarSpawnPos = { -1864.157f, 6790.122f, 4319.208f };
const Position echoingSonarSpawnPos2 = { -1864.138f, 6759.732f, 4319.208f };

//164406
struct boss_shriekwing : public BossAI
{
    boss_shriekwing(Creature* creature) : BossAI(creature, DATA_SHRIEKWING) { }

private:
    uint8 earSpitting;
    uint8 echoingSonar;

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
       // me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(EVENT_GAIN_ENERGY, 1s);
        events.ScheduleEvent(SPELL_EXSANGUINATING_BITE, 5s);
        events.ScheduleEvent(SPELL_ECHOLOCATION_MARK, 13s);
        events.ScheduleEvent(SPELL_BLIND_SWIPE_CAST, 19s);
        events.ScheduleEvent(SPELL_WAVE_OF_BLOOD, 12s);
        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_ECHOING_SCREECH_SPAWN, 23s);
        this->earSpitting = 0;
        this->echoingSonar = 0;
        if (IsMythic())
            me->SummonCreature(NPC_BLOOD_LANTERN, me->GetRandomNearPosition(25.0f), TEMPSUMMON_MANUAL_DESPAWN);
    }

    void ExecuteEvent(uint32 eventId) override 
    { 
        if (me->GetPower(POWER_ENERGY) == 100)
        {            
            if (AreaTrigger* at = me->GetAreaTrigger(SPELL_ECHOING_SONAR_CREATE_AT))
                at->Remove();
            me->NearTeleportTo(middle_pos, false);
            me->SetPower(POWER_ENERGY, 0);
            events.Reset();
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->CastSpell(nullptr, SPELL_BLOOD_SHROUD_CAST, false);
            events.ScheduleEvent(EVENT_ECHOING_SONAR_SPAWN, 1s);
            events.ScheduleEvent(SPELL_EARSPITTING_SHRIEK_CAST, 3s);
            events.ScheduleEvent(EVENT_PHASE_ONE, 40s);
        }
        switch (eventId)
        {
        case EVENT_PHASE_ONE:
            me->SetReactState(REACT_AGGRESSIVE);
            events.Reset();
            events.ScheduleEvent(EVENT_GAIN_ENERGY, 1s);
            events.ScheduleEvent(SPELL_EXSANGUINATING_BITE, 5s);
            events.ScheduleEvent(SPELL_ECHOLOCATION_MARK, 8s);
            events.ScheduleEvent(SPELL_BLIND_SWIPE_CAST, 13s);
            events.ScheduleEvent(SPELL_WAVE_OF_BLOOD, 18s);
            break;

        case EVENT_GAIN_ENERGY:
            me->ModifyPower(POWER_ENERGY, + 1);
            events.Repeat(1s);
            break;

        case SPELL_ECHOLOCATION_MARK:
        {
            UnitList targetList;
            SelectTargetList(targetList, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->CastSpell(targets, SPELL_ECHOLOCATION_MARK, true);
                targets->GetScheduler().Schedule(8s, [this, targets](TaskContext /*context*/)
                {
                    if (!targets)
                        return;

                    me->CastSpell(targets, SPELL_DESCENT, true);
                    me->CastSpell(targets, SPELL_SANGUINE_ICHOR_CREATE_AT, true);
                });
            }
            events.Repeat(25s);
            break;
        }

        /* case SPELL_EXSANGUINATING_BITE:
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 30.0f))
            {
                me->CastSpell(target, SPELL_EXSANGUINATING_BITE, false);
                me->AddAura(SPELL_EXSANGUINATED_DEBUFF, target);
                if (Aura* exsanguinated = target->GetAura(SPELL_EXSANGUINATED_DEBUFF))
                {
                    exsanguinated->SetStackAmount(10);
                    target->GetScheduler().Schedule(1500ms, [this, target, exsanguinated](TaskContext context)
                    {
                        if (!target || !me)
                            return;
                            
                        if (Aura* exsanguinated = target->GetAura(SPELL_EXSANGUINATED_DEBUFF))
                            if (exsanguinated->GetStackAmount() > 1)
                                exsanguinated->SetStackAmount(exsanguinated->GetStackAmount() - 1);

                        if (exsanguinated->GetStackAmount() == 1)
                            target->RemoveAura(SPELL_EXSANGUINATED_DEBUFF);

                        if (exsanguinated->GetStackAmount() > 1)
                            context.Repeat(1500ms);
                    });
                }
            }
            events.Repeat(20s);
            break;
            */
        case SPELL_BLIND_SWIPE_CAST:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f))
            {
                me->SetFacingToObject(target, true);
                me->CastSpell(target, SPELL_BLIND_SWIPE_CAST, false);
            }
            events.Repeat(30s);
            break;

        case SPELL_WAVE_OF_BLOOD:
        {
            UnitList targetList;
            SelectTargetList(targetList, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
                me->CastSpell(targets, SPELL_WAVE_OF_BLOOD, false);
            events.Repeat(36s);
            break;
        }

        case SPELL_EARSPITTING_SHRIEK_CAST:
            earSpitting++;
            if (earSpitting != 3)
            {
                std::list<Player*> playerList;
                me->GetPlayerListInGrid(playerList, 100.0f);
                for (auto& targets : playerList)
                {
                    me->CastSpell(targets, SPELL_EARSPITTING_SHRIEK_PERIODIC, true);
                    if (targets->IsWithinLOSInMap(me))
                        me->CastSpell(targets, SPELL_SANGUINE_ICHOR_CREATE_AT, true);
                }
            }
            break;

        case EVENT_ECHOING_SONAR_SPAWN:  
            if (AreaTrigger* at = me->GetAreaTrigger(SPELL_ECHOING_SONAR_CREATE_AT))
                at->Remove();

            me->CastSpell(nullptr, SPELL_ECHOING_SONAR_CAST, false);
            for (uint8 i = 0; i < 12; i++)
            {
                me->CastSpell(echoingSonarSpawnPos, SPELL_ECHOING_SONAR_CREATE_AT, true);
            }
            for (uint8 i = 0; i < 12; i++)
            {
                me->CastSpell(echoingSonarSpawnPos2, SPELL_ECHOING_SONAR_CREATE_AT, true);
            }
            break;

        case EVENT_ECHOING_SCREECH_SPAWN:
            if (AreaTrigger* at = me->GetAreaTrigger(SPELL_ECHOING_SCREECH_CREATE_AT))
                at->Remove();

            me->CastSpell(nullptr, SPELL_ECHOING_SCREECH_CAST, false);
            for (uint8 i = 0; i < 10; i++)
            {
                me->CastSpell(nullptr, SPELL_ECHOING_SCREECH_CREATE_AT, true);
            }
            break;
        }
    }

    void JustSummoned(Creature* summon) override
    { 
        if (summon->GetEntry() == NPC_BLOOD_LANTERN)
        {
            summon->SetObjectScale(2.0f);
            summon->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);            
            summon->AddAura(SPELL_BLOOD_LANTER_APPLY_AT_2);
        }
    }

    void JustReachedHome() override
    { 
        _JustReachedHome();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnCreaturesInArea(NPC_BLOOD_LANTERN, 100.0f);
        me->RemoveAllAreaTriggers();       
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*who*/) override 
    { 
        me->DespawnCreaturesInArea(NPC_BLOOD_LANTERN, 100.0f);
        me->RemoveAllAreaTriggers();
        _JustDied();
    }
};

//340299
struct at_sanguine_ichor : public AreaTriggerAI
{
    at_sanguine_ichor(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        at->SetDuration(360000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        if (!unit->HasAura(SPELL_SANGUINE_ICHOR_AT_DAMAGE))
            at->GetCaster()->CastSpell(unit, SPELL_SANGUINE_ICHOR_AT_DAMAGE, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        if (unit->HasAura(SPELL_SANGUINE_ICHOR_AT_DAMAGE))
            unit->RemoveAura(SPELL_SANGUINE_ICHOR_AT_DAMAGE);
    }
};

//343995
class spell_blood_shroud : public SpellScript
{
    PrepareSpellScript(spell_blood_shroud);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetHitUnit()->IsWithinLOS(GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ()))
            targets.remove(GetHitUnit());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_blood_shroud::FilterTargets, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

//329002
struct at_echoing_sonar : public AreaTriggerAI
{
    at_echoing_sonar(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        at->SetDuration(30000);
        //at->SetPeriodicProcTimer(1000);
    }

    void OnInitialize() override
    {
        //VALIDATE_CASTER();
        Position GetRandomPos = at->GetRandomNearPosition(urand(20,30));
        at->MovePositionToFirstCollision(GetRandomPos, urand(30,45), 0.0f);
        //at->SetDestination(GetRandomPos, 3000);
    }

    void OnDestinationReached()
    {
        Position randomPos = at->GetCaster()->GetRandomNearPosition(urand(20,30));
        at->MovePositionToFirstCollision(randomPos, urand(30,45), 0.0f);
        //at->SetDestination(randomPos, 3000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        at->GetCaster()->Kill(unit, true);
    }
};

//342865, 21833
struct at_echoing_screech : public AreaTriggerAI
{
    at_echoing_screech(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        at->SetDuration(15000);
       // at->SetPeriodicProcTimer(1000);
    }

    void OnInitialize() override
    {
        //VALIDATE_CASTER();
        Position randomPos = at->GetCaster()->GetRandomNearPosition(urand(10,15));
        at->MovePositionToFirstCollision(randomPos, urand(20,30), 0.0f);
        //at->SetDestination(randomPos, 3000);
    }

    void OnDestinationReached()
    {
        Position randomPos = at->GetCaster()->GetRandomNearPosition(urand(10,15));
        at->MovePositionToFirstCollision(randomPos, urand(20,30), 0.0f);
       // at->SetDestination(randomPos, 3000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        at->GetCaster()->AddAura(SPELL_HORRIFIED, unit);
        Position deadlyDescent = unit->GetPosition();
        unit->GetScheduler().Schedule(5s, [this, unit](TaskContext /*context*/)
        {
            if (!unit)
                return;

            at->GetCaster()->CastSpell(unit, SPELL_DEADLY_DESCENT, true);
        });
    }
};

//341690, 21833
struct at_blood_lantern : public AreaTriggerAI
{
    at_blood_lantern(AreaTrigger* at) : AreaTriggerAI(at) { }

private:
    bool hasOwner;

    void OnCreate() override
    {
        hasOwner = false;
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        if (hasOwner)
            return;

        if (!unit->HasAura(SPELL_BLOOD_LANTERN_GRANT_BUTTON))
        {           
            unit->CastSpell(nullptr, SPELL_BLOOD_LANTERN_GRANT_BUTTON, true);
            hasOwner = true;
            at->GetCaster()->AddAura(SPELL_BLOODLIGHT_PERIODIC_DAMAGE_TRIGGER, unit);
        }
    }
};

void AddSC_boss_shriekwing()
{
    RegisterCreatureAI(boss_shriekwing);
    RegisterAreaTriggerAI(at_sanguine_ichor);
    RegisterSpellScript(spell_blood_shroud);
    RegisterAreaTriggerAI(at_echoing_sonar);
    RegisterAreaTriggerAI(at_echoing_screech);
    RegisterAreaTriggerAI(at_blood_lantern);
}
