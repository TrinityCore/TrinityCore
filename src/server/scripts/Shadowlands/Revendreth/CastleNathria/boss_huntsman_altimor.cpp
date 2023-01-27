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

enum HuntsmanAltimor
{
    SPELL_SPREADSHOT = 334404,
    SPELL_SINSEEKER = 335114, // every 45s, 3 targets
    SPELL_SINSEEKER_PERIODIC_DAMAGE = 335304,
    SPELL_SINSEEKER_INIT_DAMAGE = 335116,
    SPELL_SINSEEKER_CONVERSATION = 335488,
    SPELL_HUNTSMAN_BLOOD = 334504,

    //Margore 165067
    SPELL_JAGGED_CLAWS = 334971, // 10s, 20s, tank
    SPELL_VICIOUS_LUNGE_CIRCLE = 334939,
    SPELL_VICIOUS_LUNGE_MARK = 334945,
    SPELL_VICIOUS_LUNGE_CHARGE = 266947, // there is instakill

    //Bargast 169457
    SPELL_RIP_SOUL = 334797,
    SPELL_DEVOUR_SOUL = 334884,
    SPELL_SHADES_OF_BARGAST = 334757,
    SPELL_DEATHLY_ROAR = 334708,
    SPELL_DESTABILIZE = 334695,

    //Hecutis 169458
    SPELL_CRUSHING_STONE = 334860,
    SPELL_PETRIFYING_HOWL = 334852,
    SPELL_PETRIFYING_HOWL_CREATE_AT = 334889, //21100
    SPELL_STONE_SHARDS_AT_DAMAGE = 334893,
    SPELL_CHARGE = 343259,

    //Heroic
    SPELL_VICIOUS_WOUND = 334960,
    SPELL_RIPPED_SOUL_AOE = 339638,
    //Mythic
    SPELL_SHATTER_SHOT_DAMAGE = 338593,
};

//165066
struct boss_huntsman_altimor : public BossAI
{
    boss_huntsman_altimor(Creature* creature) : BossAI(creature, DATA_HUNTSMAN_ALTIMOR) { }

    void Reset() override
    {
        BossAI::Reset();
        me->SetReactState(REACT_AGGRESSIVE);
        me->SummonCreature(NPC_MARGORE, -1651.586f, 6700.420f, 4279.040f, TEMPSUMMON_MANUAL_DESPAWN);
        me->AddAura(SPELL_HUNTSMAN_BLOOD);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        /*if (instance->GetBossState(DATA_SHRIEKWING) != DONE)
            BossAI::EnterEvadeMode();*/

        _EnterCombat();
        Talk(0);
        events.ScheduleEvent(SPELL_SPREADSHOT, 6s);
        events.ScheduleEvent(SPELL_VICIOUS_LUNGE_CIRCLE, 17s);
        events.ScheduleEvent(SPELL_SINSEEKER, 27s);
        if (Creature* margore = me->FindNearestCreature(NPC_MARGORE, 100.0f, true))
            margore->AI()->DoZoneInCombat();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        switch (summon->GetEntry())
        {
        case NPC_MARGORE:
            summon->SetFacingTo(3.233f, true);
            summon->AddAura(SPELL_HUNTSMAN_BLOOD);
            break;

        case NPC_BARGAST:
            summon->AddAura(SPELL_HUNTSMAN_BLOOD);
            summon->AI()->DoZoneInCombat();
            break;

        case NPC_HECUTIS:
            summon->AddAura(SPELL_HUNTSMAN_BLOOD);
            summon->AI()->DoZoneInCombat();
            break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
        case NPC_MARGORE:
            if (Creature* altimor = me->FindNearestCreature(NPC_HUNTSMAN_ALTIMOR, 100.0f, true))
                altimor->AI()->Talk(3);
            me->SummonCreature(NPC_BARGAST, -1652.252f, 6682.398f, 4279.040f, TEMPSUMMON_MANUAL_DESPAWN);
            break;

        case NPC_BARGAST:
            me->SummonCreature(NPC_HECUTIS, -1651.693f, 6717.287f, 4279.040f, TEMPSUMMON_MANUAL_DESPAWN);
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override 
    { 
        switch (eventId)
        {
        case SPELL_SPREADSHOT:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->SetFacingToObject(target);
                me->CastSpell(target, SPELL_SPREADSHOT, false);
            }
            events.Repeat(20s);
            break;

        case SPELL_SINSEEKER:
            UnitList targetList;
            SelectTargetList(targetList, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->CastSpell(nullptr, SPELL_SINSEEKER, false);
                me->GetScheduler().Schedule(100ms, [this, targets](TaskContext context)
                {
                    if (!targets)
                        return;

                    me->CastSpell(targets, SPELL_SINSEEKER_INIT_DAMAGE, true);
                    me->CastSpell(targets, SPELL_SINSEEKER_PERIODIC_DAMAGE, true);
                });
            }
            events.Repeat(45s);
            break;
        }
    }

    void JustReachedHome() override
    { 
        _JustReachedHome();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        me->DespawnCreaturesInArea(NPC_SHADE_OF_BARGAST, 100.0f);
        me->RemoveAllAreaTriggers();
        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*who*/) override 
    {
        summons.DespawnAll();
        me->DespawnCreaturesInArea(NPC_SHADE_OF_BARGAST, 100.0f);
        me->RemoveAllAreaTriggers();
        _JustDied();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override { }
    void MovementInform(uint32 type, uint32 point) override { }
};

//165067,169457,169458
struct npc_altimor_pet : public ScriptedAI
{
    npc_altimor_pet(Creature* c) : ScriptedAI(c) { }

    void EnterCombat(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_MARGORE:
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(SPELL_JAGGED_CLAWS, 5s);
            events.ScheduleEvent(SPELL_VICIOUS_LUNGE_CIRCLE, 10s);
            break;

        case NPC_BARGAST:
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(SPELL_RIP_SOUL, 5s);
            events.ScheduleEvent(SPELL_SHADES_OF_BARGAST, 10s);
            break;

        case NPC_HECUTIS:
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(SPELL_CRUSHING_STONE, 5s);
            events.ScheduleEvent(SPELL_PETRIFYING_HOWL, 10s);
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override 
    {
        switch (eventId)
        {
        case SPELL_JAGGED_CLAWS:
            DoCastVictim(SPELL_JAGGED_CLAWS, false);
            events.Repeat(10s, 20s);
            break;

        case SPELL_VICIOUS_LUNGE_CIRCLE:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                if (Creature* altimor = me->FindNearestCreature(NPC_HUNTSMAN_ALTIMOR, 100.0f, true))
                    altimor->AI()->Talk(2);
                me->SetFacingToObject(target);
                me->CastSpell(target, SPELL_VICIOUS_LUNGE_CIRCLE, true);
                me->AddAura(SPELL_VICIOUS_LUNGE_MARK, target);
                me->GetScheduler().Schedule(6100ms, [this, target](TaskContext context)
                {
                    if (!target)
                        return;

                    me->CastSpell(target, SPELL_CHARGE, true);

                });
            }
            events.Repeat(30s, 35s);
            break;

        case SPELL_RIP_SOUL:
            if (Creature* altimor = me->FindNearestCreature(NPC_HUNTSMAN_ALTIMOR, 100.0f, true))
                altimor->AI()->Talk(4);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                me->SummonCreature(NPC_RIPPED_SOUL, target->GetPosition(), TEMPSUMMON_TIMED_DESPAWN);
            events.Repeat(10s, 20s);
            break;

        case SPELL_SHADES_OF_BARGAST:
            if (!IsHeroic() || !IsMythic())
                me->CastSpell(me->GetRandomNearPosition(15), SPELL_SHADES_OF_BARGAST, false);
            else
            {
                for (uint8 i = 0; i < 2; i++)
                {
                    me->CastSpell(me->GetRandomNearPosition(15), SPELL_SHADES_OF_BARGAST, false);
                }
            }
            events.Repeat(30s, 35s);
            break;

        case SPELL_CRUSHING_STONE:
            me->AddAura(SPELL_CRUSHING_STONE);
            events.Repeat(2s);
            break;

        case SPELL_PETRIFYING_HOWL:
        {
            DoCastAOE(SPELL_PETRIFYING_HOWL, false);
            UnitList targetList;
            SelectTargetList(targetList, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->AddAura(SPELL_PETRIFYING_HOWL, targets);
                me->GetScheduler().Schedule(8s, [this, targets](TaskContext context)
                {
                    if (!targets)
                        return;

                    targets->CastSpell(targets->GetPosition(), SPELL_PETRIFYING_HOWL_CREATE_AT, true);
                });
            }
            events.Repeat(30s, 35s);
            break;
        }
        }
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override 
    { 
        switch (spellInfo->Id)
        {
        case SPELL_PETRIFYING_HOWL:
            break;
        }
    }
};

//334889
struct at_stone_shards : public AreaTriggerAI
{
    at_stone_shards(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        at->SetDuration(360000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        if (!unit->HasAura(SPELL_STONE_SHARDS_AT_DAMAGE))
            at->GetCaster()->CastSpell(unit, SPELL_STONE_SHARDS_AT_DAMAGE);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        if (unit->HasAura(SPELL_STONE_SHARDS_AT_DAMAGE))
            unit->RemoveAura(SPELL_STONE_SHARDS_AT_DAMAGE);
    }
};

//171557
struct npc_shade_of_bargast : public ScriptedAI
{
    npc_shade_of_bargast(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        if (me->GetMap()->IsRaid())
            me->AI()->DoZoneInCombat();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(SPELL_DEATHLY_ROAR, 3s);
    }

    void ExecuteEvent(uint32 eventId) override 
    {
        switch (eventId)
        {
        case SPELL_DEATHLY_ROAR:
            DoCastAOE(SPELL_DEATHLY_ROAR, false);
            events.Repeat(20s, 25s);
            break;
        }
    }
};

//334939
class spell_vicious_lunge_damage : public SpellScript
{
    PrepareSpellScript(spell_vicious_lunge_damage);

private:
    uint32 targetCount;

    bool Load() override
    {
        targetCount = 0;
        return true;
    }

    void GetTargetCount(std::list<WorldObject*>& targets)
    {
        targetCount = targets.size();
    }

    void HandleOnHit()
    {
        int32 splitDamage = GetHitDamage() / targetCount;
        SetHitDamage(splitDamage);
        if (GetCaster()->GetMap()->IsHeroic() || GetCaster()->GetMap()->IsMythic())
            GetCaster()->CastSpell(GetHitUnit(), SPELL_VICIOUS_WOUND, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_vicious_lunge_damage::GetTargetCount, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnHit += SpellHitFn(spell_vicious_lunge_damage::HandleOnHit);
    }
};

//171577
struct npc_ripped_soul : public ScriptedAI
{
    npc_ripped_soul(Creature* c) : ScriptedAI(c) { }

    void IsSummonedBy(Unit* summoner) override
    {
        if (Creature* altimor = me->FindNearestCreature(NPC_HUNTSMAN_ALTIMOR, 100.0f, true))
        {
            if (IsHeroic() || IsMythic())
                me->CastSpell(nullptr, SPELL_RIPPED_SOUL_AOE, true);
            me->DealDamage(me, me->GetMaxHealth() / 2);
            me->SetWalk(true);
            me->GetMotionMaster()->MoveFollow(altimor, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        }
    }

    void MoveInLineOfSight(Unit* target) override
    {
        if (target->IsPlayer())
            return;

        if (target->GetEntry() != NPC_HUNTSMAN_ALTIMOR)
            return;

        if (target->GetEntry() == NPC_HUNTSMAN_ALTIMOR && me->GetDistance(target) <= 5.0f)
            if (Creature* altimor = me->FindNearestCreature(NPC_HUNTSMAN_ALTIMOR, 100.0f, true))
                if (!altimor->HasAura(SPELL_DEVOUR_SOUL))
                {
                    me->AddAura(SPELL_DEVOUR_SOUL, altimor);
                    me->DespawnOrUnsummon();
                }
    }
};

void AddSC_boss_huntsman_altimor()
{
    RegisterCreatureAI(boss_huntsman_altimor);
    RegisterCreatureAI(npc_altimor_pet);
    RegisterAreaTriggerAI(at_stone_shards);
    RegisterCreatureAI(npc_shade_of_bargast);
    RegisterSpellScript(spell_vicious_lunge_damage);
    RegisterCreatureAI(npc_ripped_soul);
}
