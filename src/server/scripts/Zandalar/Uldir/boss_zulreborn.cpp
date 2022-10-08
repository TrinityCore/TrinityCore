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
#include "ScriptMgr.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"
#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "MotionMaster.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Object.h"
#include "GameObjectData.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "uldir.h"

enum Spells
{
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_SHADOW_BARRAGE = 273359,
    SPELL_DARK_REVELATION_TRIGGER = 273365,
    SPELL_DARK_REVELATION_EXPLOSION = 273438,
    SPELL_DARK_REVELATION_SUMMON_MINION_OF_ZUL = 271967,
    SPELL_CALL_OF_BLOOD = 273889,
    SPELL_CALL_OF_BLOOD_MISSILE_SUMMON_CRAWG = 273893,
    SPELL_CALL_OF_BLOOD_MISSILE_SUMMON_CASTER_ADD = 274099,
    SPELL_CALL_OF_BLOOD_MISSILE_SUMMON_MELEE_ADD = 274122,
    //Phase 2
    SPELL_LOCUS_OF_CORRUPTION = 274168,
    SPELL_CORRUPTED_BLOOD_AURA = 274195,
    SPELL_RUPTURING_BLOOD_AURA = 274358,
    SPELL_RUPTURED_BLOOD_CREATE_AT = 274363,
    SPELL_DEATHWISH = 274271,
    SPELL_DEATHWISH_EXPLOSION = 275991,
    SPELL_DEATHWISH_JUMP = 274274,
    SPELL_POOL_OF_DARKNESS = 273361, //npc 139171
    SPELL_POOL_OF_DARKNESS_VISUAL_FORMING = 273360,
    SPELL_ERUPTING_DARKNESS_DAMAGE = 273363,
    SPELL_ABSORBED_DARKNESS_AURA = 274387,
    SPELL_BERSERK = 26662,
    //Minions
    SPELL_BLOODY_CLEAVE = 273316,
    SPELL_THRUMMING_PULSE = 273288,
    SPELL_BLOODSHARD = 273350,
    SPELL_CONGEAL_BLOOD = 273451, //npc 139195
    SPELL_DRIPPING_BLOOD = 274396,
    SPELL_ICHOR_TRANSFUSION = 273556,
    SPELL_HUNGERING_MAW_HEAL = 273255,
    SPELL_BLOOD_RECALL = 276659,
    SPELL_DECAYING_FLESH = 276434,
};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_CALL_OF_BLOOD,
    SAY_DARK_REVELATION,
    SAY_LOCUS,
    SAY_DEATHWISH,
    SAY_KILL,
    SAY_DEATH
};

enum Events
{
    EVENT_SHADOW_BARRAGE,
    EVENT_DARK_REVELATION,
    EVENT_CALL_OF_BLOOD,    
    EVENT_LOCUS_OF_CORRUPTION,
    EVENT_DEATHWISH,
    EVENT_RUPTURING_BLOOD,
    EVENT_POOL_OF_DARKNESS
};

//138967
struct boss_zul : public BossAI
{
    boss_zul(Creature* creature) : BossAI(creature, DATA_ZUL) { }

private:
    bool spawn;
    uint8 phase;

    void Reset() override
    {
        BossAI::Reset();
        //me->SetReactState(REACT_PASSIVE);
        //me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        //me->SetVisible(false);
        spawn = false;
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);
        CleanEncounter(instance, me);
        me->CanFly();
        me->SetFlying(true);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(SAY_AGGRO);
        this->phase = 1;
        events.ScheduleEvent(EVENT_SHADOW_BARRAGE, 3s);
        events.ScheduleEvent(EVENT_CALL_OF_BLOOD, 15s);
        events.ScheduleEvent(EVENT_DARK_REVELATION, 29s);        
        if (IsHeroic() || (IsMythic()))
            events.ScheduleEvent(EVENT_POOL_OF_DARKNESS, 20s);
        DoCastSelf(SPELL_PERIODIC_ENERGY_GAIN);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPct(41) && this->phase == 1)
        {
            this->phase = 2;
            events.Reset();
            events.ScheduleEvent(EVENT_LOCUS_OF_CORRUPTION, 3s);
            events.ScheduleEvent(EVENT_SHADOW_BARRAGE, 6s);
            events.ScheduleEvent(EVENT_DARK_REVELATION, 10s);
            events.ScheduleEvent(EVENT_CALL_OF_BLOOD, 25s);
            events.ScheduleEvent(EVENT_DEATHWISH, 30s);
            events.ScheduleEvent(EVENT_RUPTURING_BLOOD, 35s);
            events.ScheduleEvent(EVENT_POOL_OF_DARKNESS, 40s);
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            if (roll_chance_f(15))
                Talk(SAY_KILL);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_SHADOW_BARRAGE:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                me->CastSpell(target, SPELL_SHADOW_BARRAGE, false);
            events.Repeat(2s);
            break;
        }
        case EVENT_DARK_REVELATION:
        {
            Talk(SAY_DARK_REVELATION);
            UnitList u_li;
            if (IsHeroic() || (IsMythic()))
            {
                SelectTargetList(u_li, 2, SELECT_TARGET_RANDOM, 150.0f, true);
                for (Unit* targets : u_li)
                {
                    me->AddAura(SPELL_DARK_REVELATION_TRIGGER, targets);
                }
            }
            else
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                    me->AddAura(SPELL_DARK_REVELATION_TRIGGER, target);
            }
            events.Repeat(20s);
            break;
        }            
        case EVENT_CALL_OF_BLOOD:
        {
            Talk(SAY_CALL_OF_BLOOD);
            me->CastSpell(nullptr, SPELL_CALL_OF_BLOOD, false);
            me->CastSpell(me->GetRandomNearPosition(30.0f), SPELL_CALL_OF_BLOOD_MISSILE_SUMMON_MELEE_ADD, true);
            me->CastSpell(me->GetRandomNearPosition(30.0f), SPELL_CALL_OF_BLOOD_MISSILE_SUMMON_CASTER_ADD, true);
            for (uint8 i = 0; i < 6; i++)
            {
                me->CastSpell(me->GetRandomNearPosition(25.0f), SPELL_CALL_OF_BLOOD_MISSILE_SUMMON_CRAWG, true);
            }
            events.Repeat(30s);
            break;
        }
        case EVENT_LOCUS_OF_CORRUPTION:
        {
            Talk(SAY_LOCUS);
            me->CastSpell(nullptr, SPELL_LOCUS_OF_CORRUPTION, false);
            AddTimedDelayedOperation(3100, [this]() -> void
            {
                std::list<Player*> pl_li;
                me->GetPlayerListInGrid(pl_li, 100.0f);
                for (auto& targets : pl_li)
                {
                    me->AddAura(SPELL_CORRUPTED_BLOOD_AURA, targets);
                    int8 setCorruptedStacks = me->GetPower(POWER_ENERGY) / 5;
                    if (Aura* corruptedBlood = targets->GetAura(SPELL_CORRUPTED_BLOOD_AURA))
                        corruptedBlood->SetStackAmount(setCorruptedStacks);
                }
            });
            break;
        }
        case EVENT_RUPTURING_BLOOD:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                me->AddAura(SPELL_RUPTURING_BLOOD_AURA, target);
                AddTimedDelayedOperation(20100, [this, target]() -> void
                {
                    me->CastSpell(target, SPELL_RUPTURED_BLOOD_CREATE_AT, true);//applies corrupted blood on enter
                });
            }
            events.Repeat(15s);
            break;
        }
        case EVENT_DEATHWISH:
        {
            Talk(SAY_DEATHWISH);
            UnitList u_li;
            SelectTargetList(u_li, 2, SELECT_TARGET_RANDOM, 150.0f, true);
            for (Unit* targets : u_li)
            {
                me->CastSpell(targets, SPELL_DEATHWISH, true);
            }
            events.Repeat(45s);
            break;
        }
        case EVENT_POOL_OF_DARKNESS:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {                
                me->CastSpell(target, SPELL_POOL_OF_DARKNESS, true);
            }
            events.Repeat(50s);
            break;
        }
        } 
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        _DespawnAtEvade();
        CleanEncounter(instance, me);
        me->RemoveAllAreaTriggers();
    }

    void CleanEncounter(InstanceScript* instance, Creature* zul)
    {
        me->DespawnCreaturesInArea(NPC_POOL_OF_DARKNESS, 125.0f);
        me->DespawnCreaturesInArea(NPC_CRAWG, 125.0f);
        me->DespawnCreaturesInArea(NPC_NAZMANI_BLOODHEXER, 125.0f);
        me->DespawnCreaturesInArea(NPC_NAZMANI_CRUSHER, 125.0f);
        me->DespawnCreaturesInArea(NPC_NAZMANI_BLOODWEAVER, 125.0f);
        me->DespawnCreaturesInArea(NPC_NAZMANI_VEINSPLITTER, 125.0f);
        me->DespawnCreaturesInArea(NPC_NAZMANI_DOMINATOR, 125.0f);
        me->DespawnCreaturesInArea(NPC_MINION_OF_ZUL_ULDIR, 125.0f);
        me->DespawnCreaturesInArea(NPC_ANIMATED_ICHOR, 125.0f);
        me->RemoveAllAreaTriggers();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        CleanEncounter(instance, me);
        if (auto* titanConsole = me->FindNearestGameObject(GO_TITAN_CONSOLE_ZUL, 100.0f))
            titanConsole->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
        CleanEncounter(instance, me);
        if (Creature* mythrax = me->FindNearestCreature(NPC_MYTHRAX, 100.0f, true))
        {
            mythrax->SetVisible(true);
        }
    }
};

//273365
class aura_dark_revelation : public AuraScript
{
    PrepareAuraScript(aura_dark_revelation);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            Unit* target = GetTarget();
            target->CastSpell(nullptr, SPELL_DARK_REVELATION_EXPLOSION, true);
            for (uint8 i = 0; i < 3; i++)
            {
                caster->CastSpell(target, SPELL_DARK_REVELATION_SUMMON_MINION_OF_ZUL, true);
            }
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_dark_revelation::OnRemove, EFFECT_0, SPELL_EFFECT_SUMMON_STABLED_PET, AURA_EFFECT_HANDLE_REAL);
    }
};

const Position jump_of_cliff_pos = { 280.195f, -304.824f, 624.548f, 5.06f };

//274271
class aura_deathwish : public AuraScript
{
    PrepareAuraScript(aura_deathwish);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (caster->GetEntry() == NPC_ZUL)
            {                
                GetTarget()->GetMotionMaster()->MovePoint(1, jump_of_cliff_pos, true);
            }
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(aura_deathwish::OnApply, EFFECT_0, SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED, AURA_EFFECT_HANDLE_REAL);
    }
};

enum Generic
{
    EVENT_BLOODY_CLEAVE = 1,
    EVENT_THRUMMING_PULSE,
    EVENT_BLOODSHARD,
    EVENT_CONGEAL_BLOOD,
    EVENT_HUNGERING_MAW_HEAL
};

//139059,139057,139051,138493
struct npc_generic_zul_minion : public ScriptedAI
{
    npc_generic_zul_minion(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        if (IsMythic())
        {
            me->AddAura(SPELL_BLOOD_RECALL);
            //me->AddAura(SPELL_DECAYING_FLESH);
        }
        if (Creature* zul = me->FindNearestCreature(NPC_ZUL, 100.0f, true))
            if (zul->IsInCombat())
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                me->AI()->DoZoneInCombat(nullptr);
            }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_NAZMANI_CRUSHER:
            me->SetPowerType(POWER_ENERGY);
            me->SetPower(POWER_ENERGY, 0);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);
            DoCastSelf(SPELL_PERIODIC_ENERGY_GAIN);
            events.ScheduleEvent(EVENT_BLOODY_CLEAVE, 3s);
            break;
        case NPC_NAZMANI_BLOODHEXER:
            me->SetPowerType(POWER_ENERGY);
            me->SetPower(POWER_ENERGY, 0);
            me->SetMaxPower(POWER_ENERGY, 100);
            DoCastSelf(SPELL_PERIODIC_ENERGY_GAIN);
            events.ScheduleEvent(EVENT_BLOODSHARD, 3s);
            break;
        case NPC_CRAWG:
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_BLOODY_CLEAVE:
            DoCastVictim(SPELL_BLOODY_CLEAVE, false);
            events.Repeat(15s, 18s);
            break;

        case EVENT_BLOODSHARD:
            DoCastRandom(SPELL_BLOODSHARD, false);
            events.Repeat(2s);
            break;
        }
        if (me->GetPower(POWER_ENERGY) == 100 && me->GetEntry() == NPC_NAZMANI_CRUSHER)
        {
            me->ModifyPower(POWER_ENERGY, -100);
            me->CastSpell(nullptr, SPELL_THRUMMING_PULSE, true);
        }
        if (me->GetPower(POWER_ENERGY) == 100 && me->GetEntry() == NPC_NAZMANI_BLOODHEXER)
        {
            me->ModifyPower(POWER_ENERGY, -100);
            me->SummonCreature(NPC_ANIMATED_ICHOR, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (instance)
        {
            if (!me->HasAura(SPELL_DECAYING_FLESH))
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            else
            {
                me->Respawn(true);
                me->SetHealth(me->GetMaxHealth() / 70);
            }
        }
    }
};

//139171
struct npc_pool_of_darkness : public ScriptedAI
{
    npc_pool_of_darkness(Creature* creature) : ScriptedAI(creature) {
        me->SetReactState(REACT_PASSIVE);
    }

private:
    TaskScheduler scheduler;

    void Reset() override
    {
        ScriptedAI::Reset();
        me->CastSpell(nullptr, SPELL_POOL_OF_DARKNESS_VISUAL_FORMING, false);
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && me->GetDistance2d(unit) > 5.0f)
        {
            if (unit->HasAura(SPELL_ABSORBED_DARKNESS_AURA))
                unit->RemoveAura(SPELL_ABSORBED_DARKNESS_AURA);
            me->GetScheduler().Schedule(100s, [this](TaskContext context)
            {
                me->CastSpell(nullptr, SPELL_ERUPTING_DARKNESS_DAMAGE, true);
                context.Repeat(2s);
            });
        }
        if (unit->IsPlayer() && me->GetDistance2d(unit) < 5.0f)
        {
            if (!unit->HasAura(SPELL_ABSORBED_DARKNESS_AURA))
                me->AddAura(SPELL_ABSORBED_DARKNESS_AURA, unit);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }
};

//287416 - Trapdoor
struct go_zul_trapdoor : public GameObjectAI
{
    go_zul_trapdoor(GameObject* go) : GameObjectAI(go) { }

    void Reset() override
    {
        go->GetScheduler().CancelAll();
        go->GetScheduler().Schedule(1s, [this](TaskContext context)
        {
            if (InstanceScript* instance = go->GetInstanceScript())
            {
                if (instance->GetBossState(DATA_TALOC == DONE) && instance->GetBossState(DATA_MOTHER == DONE) && instance->GetBossState(DATA_DEVOURER == DONE) && instance->GetBossState(DATA_VECTIS == DONE) && instance->GetBossState(DATA_ZEKVOZ == DONE)) /*&& instance->GetBossState(DATA_ZUL == DONE)*/
                    go->SetGoState(GO_STATE_ACTIVE);
                else
                    context.Repeat(15s);
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

//139195
struct npc_animated_ichor : public ScriptedAI
{
    npc_animated_ichor(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

private:
    TaskScheduler scheduler;
    bool transfer;

    void Reset() override
    {
        ScriptedAI::Reset();
        me->AddAura(SPELL_DRIPPING_BLOOD);
        me->SetWalk(true);
        transfer = false;
        if (Creature* zul = me->FindNearestCreature(NPC_ZUL, 100.0f, true))
        {
            me->GetMotionMaster()->Clear();
            me->GetSpeed(MOVE_WALK);
            me->GetMotionMaster()->MoveChase(zul, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        }
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->GetEntry() == NPC_ZUL)
        {
            if (Creature* zul = me->FindNearestCreature(NPC_ZUL, 100.0f, true))
            {
                if (me->GetDistance2d(zul) <= 5.0f && !transfer)
                {
                    transfer = true;
                    me->CastSpell(zul, SPELL_ICHOR_TRANSFUSION, true);
                    uint64 transfer = me->GetMaxHealth();
                    zul->SetHealth(zul->GetHealth() + transfer);
                    me->KillSelf();
                }
            }
        }
    }
};

//276434
class aura_decaying_flesh : public AuraScript
{
    PrepareAuraScript(aura_decaying_flesh);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_decaying_flesh::OnRemove, EFFECT_1, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_zul()
{
    RegisterCreatureAI(boss_zul);
    RegisterAuraScript(aura_dark_revelation);
    RegisterAuraScript(aura_deathwish);
    RegisterCreatureAI(npc_generic_zul_minion);
    RegisterCreatureAI(npc_pool_of_darkness);
    RegisterGameObjectAI(go_zul_trapdoor);
    RegisterCreatureAI(npc_animated_ichor);
    RegisterAuraScript(aura_decaying_flesh);
}
