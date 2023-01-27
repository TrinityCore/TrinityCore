/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "InstanceScript.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "nyalotha.h"

const Position middle_of_the_room_pos = { -1485.0f, 487.0f, -556.0f, 1.58f };
const Position mana_orb_pos = { -1463.0f, 481.0f, -556.0f, 3.19f };

enum Texts
{
	SAY_AGGRO = 0,
	SAY_INTRO,
	SAY_DARK_MANIFESTATION,
	SAY_OBSIDIAN_SKIN,
	SAY_STYGIAN_ANNIHILATION,
	SAY_KILL,
	SAY_DEVOUR_MAGIC,
	SAY_DEATH
};

enum Spells
{
	PERIODIC_ENERGY_GAIN = 299956,
	CONSUMING_SHADOWS = 308158, //every 15s
	CONSUMING_SHADOWS_DAMAGE = 308168,
	DEVOUR_MAGIC_CAST = 307805, //every 25s
	DEVOUR_MAGIC_DAMAGE = 307821,
	DEVOUR_MAGIC_MARK = 307806,
	DEVOUR_MAGIC_GIVE_POWER = 309498,
	DEVOURED_ABYSS_CREATE_AT = 307839,
	DEVOURED_ABYSS_AT_DAMAGE = 307586, //pacify, silence, screen effect
	DEVOURED_ABYSS_DAMAGE_9Y = 315291,
	DEVOURED_ABYSS_DRAIN_MANA = 309853, // drain mana, silence
	STYGIAN_ANNIHILATION_CAST = 308044, //every 40s
	STYGIAN_ANNIHILATION_DAMAGE = 307773,
	SHADOW_CLAWS = 310129, //leaving 24s debuff on tank
	SHADOW_WOUNDS_PERIODIC = 315882,
	DARK_AEGIS = 305675, //passive for add 156650
	DARK_OFFERING = 308872, //casted on boss, interrupted by entering to devoured abyss ats
	DARK_OFFERING_GIVE_POWER_MANA = 309514,
	DARK_MANIFESTATION_CREATE_AT = 312117, //no data?
	DARK_MANIFESTATION_CREAT_AT_PULL = 308904, //22237
    DARK_MANIFESTATION_DAMAGE = 308908,
    DARK_MANIFESTATION_SUMMON = 305625,
	DARK_MANIFESTATION_EXP = 308908,
	//PHASE 2
	OBSIDIAN_SKIN = 306005,
	OBSIDIAN_SKIN_DAMAGE = 306070,
	OBISIDAN_SKIN_DAMAGE_2 = 314907,
    OBSIDIAN_SHATTER_DAMAGE = 315098,
	OBSIDIAN_SKIN_VISUAL = 315198,
	OBSIDIAN_SHATTER_TRIGGER_CONSUME_MAGIC = 305722,
    OBSIDIAN_SKIN_LOSE_MANA_INSTEAD_OF_HP = 314803,
	FORBIDDEN_MANA_DEBUFF = 306301,
	FORBIDDEN_MANA_EXP = 306295,
	FORBIDDEN_MANA_MOD_HEALING_AND_MANA_REGEN = 310611,
    FORBIDDEN_MANA_GIVE_POWER_MAUT = 306296,
	//Heroic
	BLACK_WINGS = 305663,
	DRAIN_ESSENCE_PERIODIC = 314993,
	DRAIN_ESSENCE_EXP = 314995,
	//Mythic
	ANCIENT_CURSE = 315025,
	ANCIENT_CURSE_INSTAKILL = 315083,
    ANCIENT_CURSE_DAMAGE = 314390,
	ENRAGED = 310613
};

enum Events
{
	EVENT_CONSUMING_SHADOWS = 1,
	EVENT_DEVOUR_MAGIC,
	EVENT_STYGIAN_ANNIHILATION,
	EVENT_SHADOW_CLAWS,
    EVENT_DARK_MANIFESTATION,
	EVENT_OBSIDIAN_SKIN,
	EVENT_MANA_ORB,
	EVENT_BLACK_WINGS,
	EVENT_DRAIN_ESSENCE,
	EVENT_ANCIENT_CURSE,
	EVENT_ENRAGED,
    EVENT_DRAIN_MANA
};

enum Actions
{
	ACTION_OBSIDIAN_SKIN = 1,
};

//156523
struct boss_maut : public BossAI
{
	boss_maut(Creature* creature) : BossAI(creature, DATA_MAUT) { }

private:
	uint8 phase;

	void Reset() override
	{	
		BossAI::Reset();
		me->SetPowerType(POWER_ENERGY);
		me->SetPower(POWER_ENERGY, 0);
		me->DespawnCreaturesInArea(NPC_DARK_MANIFESTATION, 125.0f);
        me->DespawnCreaturesInArea(500506, 125.0f);
        me->SetReactState(REACT_DEFENSIVE);
        intro = false;
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_ENTROPIC);
	}

	void EnterCombat(Unit* u) override
	{
        me->RemoveAura(OBSIDIAN_SKIN_VISUAL);
		_EnterCombat();
		Talk(SAY_AGGRO);
		DoCast(PERIODIC_ENERGY_GAIN);
        this->phase = 1;
		events.ScheduleEvent(EVENT_SHADOW_CLAWS, 5s);
		events.ScheduleEvent(EVENT_DEVOUR_MAGIC, 10s);
		events.ScheduleEvent(EVENT_CONSUMING_SHADOWS, 13s);
        events.ScheduleEvent(EVENT_STYGIAN_ANNIHILATION, 30s);
        events.ScheduleEvent(EVENT_DARK_MANIFESTATION, 40s);
		events.ScheduleEvent(EVENT_ENRAGED, 10min);
		if (IsHeroic() || IsMythic())
		{
			events.ScheduleEvent(EVENT_BLACK_WINGS, 7s);
			events.ScheduleEvent(EVENT_DRAIN_ESSENCE, 14s);
			events.ScheduleEvent(EVENT_ANCIENT_CURSE, 12s);
		}
	}

	void KilledUnit(Unit* victim) override
	{
		if (victim->IsPlayer())
			if (roll_chance_f(15))
				Talk(SAY_KILL);
	}

	void OnSpellFinished(SpellInfo const* spellInfo) override
	{
		if (spellInfo->Id == SHADOW_CLAWS)
		{
			if (Unit* tar = SelectTarget(SELECT_TARGET_NEAREST, 0, 30.0f, true))
			{
				me->AddAura(SHADOW_WOUNDS_PERIODIC, tar);				
			}
		}
		if (spellInfo->Id == STYGIAN_ANNIHILATION_CAST)
		{			
            std::list<Player*> p_li;
            me->GetPlayerListInGrid(p_li, 500.0f);
            for (auto& players : p_li)
            {
                me->CastSpell(players, STYGIAN_ANNIHILATION_DAMAGE);
            }
		}
		if (spellInfo->Id == DEVOUR_MAGIC_CAST)
		{
			if (IsMythic())
			{
				UnitList tarlist;
				SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 500.0f, true);
				for (Unit* tar : tarlist)
				me->CastSpell(tar, DEVOUR_MAGIC_MARK);
			}
			else
			{
				UnitList tarlist;
				SelectTargetList(tarlist, 2, SELECT_TARGET_RANDOM, 500.0f, true);
				for (Unit* tar : tarlist)
				me->CastSpell(tar, DEVOUR_MAGIC_MARK);
			}
		}
	}

	void JustSummoned(Creature* summon) override
	{
		switch (summon->GetEntry())
		{
		case NPC_DARK_MANIFESTATION:
             //instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
			 summon->SetNativeDisplayId(93869, 2.5f);
			 summon->AddAura(DARK_AEGIS);
             summon->AI()->EnterCombat(nullptr);
			 summon->AI()->DoZoneInCombat();
			 break;
		}
	}

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        _DespawnAtEvade();
        me->RemoveAllAreaTriggers();
        me->DespawnCreaturesInArea(NPC_DARK_MANIFESTATION, 125.0f);
        me->DespawnCreaturesInArea(500506, 125.0f);
    }

	void JustReachedHome() override
	{
		_JustReachedHome();		
		me->SetPower(POWER_ENERGY, 0);
	}

	void MovementInform(uint32 type, uint32 point) override
	{
		if (type != POINT_MOTION_TYPE)
			return;

		if (point == 1 && this->phase == 1)
        {
            this->phase = 2;
            if (this->phase)
            {
                me->AI()->DoAction(ACTION_OBSIDIAN_SKIN);
            }			
        }
	}

	void DoAction(int32 param)
	{
		switch (param)
		{
		case ACTION_OBSIDIAN_SKIN:             
			 Talk(SAY_OBSIDIAN_SKIN);
			 events.Reset();
			 me->SetFacingTo(1.62f);
			 me->AddUnitState(UNIT_STATE_ROOT);
			 me->AddAura(OBSIDIAN_SKIN_VISUAL);
			 me->AddAura(OBSIDIAN_SKIN);
             me->CastCustomSpell(OBSIDIAN_SKIN_LOSE_MANA_INSTEAD_OF_HP, SPELLVALUE_BASE_POINT0, 10398, me, true);
             me->CastSpell(me, OBSIDIAN_SHATTER_TRIGGER_CONSUME_MAGIC, true);
             events.ScheduleEvent(EVENT_MANA_ORB, 1s);
             me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
             events.ScheduleEvent(EVENT_DRAIN_MANA, 1500ms);
			 break;
		}
	}

    void DamageTaken(Unit* done_by, uint32& damage) override
    {
        if (me->HasAura(OBSIDIAN_SKIN_LOSE_MANA_INSTEAD_OF_HP))
        {
			if (me->GetPower(POWER_ENERGY) != 0 && this->phase == 2)
				me->ModifyPower(POWER_ENERGY, -1);

            if (me->GetPower(POWER_ENERGY) == 0 && this->phase == 2)
            {               
				me->SetReactState(REACT_AGGRESSIVE);
                this->phase = 1;                
                me->RemoveAura(OBSIDIAN_SHATTER_TRIGGER_CONSUME_MAGIC);
                me->RemoveUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
                me->RemoveAura(OBSIDIAN_SKIN);
                me->RemoveAura(OBSIDIAN_SKIN_LOSE_MANA_INSTEAD_OF_HP);
                me->RemoveAura(OBSIDIAN_SKIN_VISUAL);
                DoCast(PERIODIC_ENERGY_GAIN);
                me->ClearUnitState(UNIT_STATE_ROOT);
				events.Reset();
				me->GetMotionMaster()->Clear(true);
				me->GetMotionMaster()->MoveChase(me->GetVictim());
                events.ScheduleEvent(EVENT_SHADOW_CLAWS, 5s);
                events.ScheduleEvent(EVENT_DEVOUR_MAGIC, 10s);
                events.ScheduleEvent(EVENT_CONSUMING_SHADOWS, 13s);
                events.ScheduleEvent(EVENT_STYGIAN_ANNIHILATION, 30s);
                events.ScheduleEvent(EVENT_DARK_MANIFESTATION, 40s);
                events.ScheduleEvent(EVENT_ENRAGED, 10min);
                if (IsHeroic() || IsMythic())
                {
                    events.ScheduleEvent(EVENT_BLACK_WINGS, 7s);
                    events.ScheduleEvent(EVENT_DRAIN_ESSENCE, 14s);
                    events.ScheduleEvent(EVENT_ANCIENT_CURSE, 12s);
                }
            }
        }
    }

	void ExecuteEvent(uint32 eventId) override
	{
		if (me->GetPower(POWER_ENERGY) == 100)
		{
			me->CastStop();
			events.Reset();
			me->RemoveAura(PERIODIC_ENERGY_GAIN);
			events.ScheduleEvent(EVENT_OBSIDIAN_SKIN, 500ms);		
		}
		switch (eventId)
		{
		case EVENT_CONSUMING_SHADOWS:
		{
			UnitList tarlist;
			SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 500.0f, true);
			for (Unit* tar : tarlist)
			DoCast(tar, CONSUMING_SHADOWS);
			events.Repeat(15s);
			break;
		}
		case EVENT_SHADOW_CLAWS:
		{
			DoCastVictim(SHADOW_CLAWS);
			events.Repeat(20s);
			break;
		}
		case EVENT_DEVOUR_MAGIC:
		{
			Talk(SAY_DEVOUR_MAGIC);
			DoCast(DEVOUR_MAGIC_CAST);
			events.Repeat(25s);
			break;
		}
		case EVENT_STYGIAN_ANNIHILATION:
		{
			Talk(SAY_STYGIAN_ANNIHILATION);
			me->StopMoving();
			DoCastAOE(STYGIAN_ANNIHILATION_CAST);			
			events.Repeat(30s);
			break;
		}
        case EVENT_DARK_MANIFESTATION:
        {
            me->CastSpell(me, DARK_MANIFESTATION_CREAT_AT_PULL);            
            events.Repeat(40s);
            break;
        }
		case EVENT_OBSIDIAN_SKIN:
		{
			me->SetReactState(REACT_PASSIVE);
			me->SetWalk(false);
			me->GetMotionMaster()->Clear(true);
			me->GetMotionMaster()->MovePoint(1, middle_of_the_room_pos, false);
			break;
		}	
		case EVENT_BLACK_WINGS:
		{
			if (Unit* tar = SelectTarget(SELECT_TARGET_NEAREST, 0, 40.0f, true))
			{		
				me->SetFacingToObject(tar, true);
				DoCast(tar, BLACK_WINGS);
			}
			events.Repeat(23s);
			break;
		}
		case EVENT_DRAIN_ESSENCE:
		{
			UnitList tarlist;
			SelectTargetList(tarlist, 2, SELECT_TARGET_RANDOM, 500.0f, true);
			for (Unit* tar : tarlist)
			{
				DoCast(tar, DRAIN_ESSENCE_PERIODIC);
			}
			break;
		}
		case EVENT_ANCIENT_CURSE:
		{
			UnitList tarlist;
			SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 500.0f, true);
			for (Unit* tar : tarlist)
			{
				DoCast(tar, ANCIENT_CURSE);
			}
			break;
		}
		case EVENT_ENRAGED:
		{
			me->AddAura(ENRAGED);
			break;
		}
		case EVENT_MANA_ORB:
		{
			me->SummonCreature(500506, mana_orb_pos, TEMPSUMMON_MANUAL_DESPAWN);
			events.Repeat(15s);
			break;
		}
        case EVENT_DRAIN_MANA:
        {
			me->ModifyPower(POWER_ENERGY, -1);
            break;
        }

		}
	}

	void JustDied(Unit* /*attacker*/) override
	{
		_JustDied();
		instance->DoModifyPlayerCurrencies(CURRENCY_ECHOES_OF_NYALOTHA, 15);
	}

private:
    bool intro;
};

enum Mana
{
    SPELL_FORBIDDEN_BUFF_FROM_AT = 306293,// 21916    
};

//500506
struct npc_mana_orb : public ScriptedAI
{
	npc_mana_orb(Creature* c) : ScriptedAI(c)
    {
        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
    }

	void Reset() override
	{
		ScriptedAI::Reset(); 
	}

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && unit->GetDistance(me) <= 3.0f && !unit->HasAura(FORBIDDEN_MANA_DEBUFF) && !soaked)
        {
            soaked = true;
            unit->AddAura(SPELL_FORBIDDEN_BUFF_FROM_AT, unit);
            me->DespawnOrUnsummon();
        }
        else if (unit->IsCreature() && unit->GetEntry() == NPC_MAUT && !give_power_mana)
        {
            give_power_mana = true;
            unit->CastSpell(nullptr, FORBIDDEN_MANA_GIVE_POWER_MAUT, true);
            me->DespawnOrUnsummon();
        }
    }

	void IsSummonedBy(Unit* unit) override
	{        
        me->SetReactState(REACT_PASSIVE);
		if (Creature* maut = me->FindNearestCreature(NPC_MAUT, 500.0f, true))
		{
			me->SetWalk(false);
			me->GetMotionMaster()->MoveFollow(maut, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
		}
	}

private:
    bool soaked;
    bool give_power_mana;
};

//308158 - Consuming Shadows
class aura_consuming_shadows : public AuraScript
{
	PrepareAuraScript(aura_consuming_shadows);

	void HandlePeriodic(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
	{
		if (Unit* caster = GetCaster())
		{
			GetCaster()->CastSpell(GetTarget(), CONSUMING_SHADOWS_DAMAGE, true);
		}
	}

	void Register() override
	{
		OnEffectRemove += AuraEffectRemoveFn(aura_consuming_shadows::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
	}
};

//307806 - Devour Magic
class aura_devour_magic : public AuraScript
{
	PrepareAuraScript(aura_devour_magic);

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
	{
        if (Unit* caster = GetTarget())
        {
            caster->CastSpell(GetTarget(), DEVOUR_MAGIC_DAMAGE, true);
            caster->CastSpell(GetTarget(), DEVOURED_ABYSS_CREATE_AT, true);
		}
	}

	void Register() override
	{
		OnEffectRemove += AuraEffectRemoveFn(aura_devour_magic::HandleRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
	}
};

//314993 - Drain Essence
class aura_drain_essence : public AuraScript
{
	PrepareAuraScript(aura_drain_essence);

	void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
	{
		if (Unit* caster = GetCaster())
		{
            caster->CastSpell(GetTarget(), DRAIN_ESSENCE_EXP, true);
		}
	}

	void Register() override
	{
		OnEffectRemove += AuraEffectRemoveFn(aura_drain_essence::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
	}
};

//315025 - Ancient Curse
class aura_ancient_curse : public AuraScript
{
	PrepareAuraScript(aura_ancient_curse);

	void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
	{
		if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
		{
            Unit* target = GetTarget();
			if (Unit* caster = GetCaster())
			{                
                target->CastSpell(nullptr, ANCIENT_CURSE_DAMAGE, true);
                target->CastSpell(nullptr, ANCIENT_CURSE_INSTAKILL, true);
			}
		}		
	}

	void Register() override
	{
		OnEffectRemove += AuraEffectRemoveFn(aura_ancient_curse::HandleRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
	}
};

//306301 - Forbidden Mana Debuff
class aura_forbidden_mana : public AuraScript
{
	PrepareAuraScript(aura_forbidden_mana);

	void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
	{
		if (Unit* caster = GetCaster())
		{
            caster->CastSpell(GetTarget(), FORBIDDEN_MANA_EXP, true);
            caster->CastSpell(nullptr, FORBIDDEN_MANA_MOD_HEALING_AND_MANA_REGEN, true);
		}
	}

	void Register() override
	{
		OnEffectRemove += AuraEffectRemoveFn(aura_forbidden_mana::HandleRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
	}
};

//22078
struct at_maut_devoured_abyss : public AreaTriggerAI
{
    at_maut_devoured_abyss(AreaTrigger* at) : AreaTriggerAI(at) {}

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer())
        {
            unit->CastSpell(unit, DEVOURED_ABYSS_DAMAGE_9Y, true);
            unit->AddAura(DEVOURED_ABYSS_DRAIN_MANA);

            if (unit->HasAura(ANCIENT_CURSE))
            {
                unit->RemoveAura(ANCIENT_CURSE);
            }
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(DEVOURED_ABYSS_DRAIN_MANA);
    }
};

//22237
struct at_maut_dark_manifestation_pull : public AreaTriggerAI
{
    at_maut_dark_manifestation_pull(AreaTrigger* at) : AreaTriggerAI(at) {}

    void OnCreate() override
    {
        at->SetDuration(6000);
    }

    void OnRemove() override
    {
        at->GetCaster()->CastSpell(at->GetPosition(), DARK_MANIFESTATION_SUMMON, true);
        at->GetCaster()->CastSpell(at->GetPosition(), DARK_MANIFESTATION_DAMAGE, true);
    }
};

//21916
struct at_maut_mana_orb : public AreaTriggerAI
{
    at_maut_mana_orb(AreaTrigger* at) : AreaTriggerAI(at) {}
};

void AddSC_maut()
{
	RegisterCreatureAI(boss_maut);
	RegisterAuraScript(aura_consuming_shadows);
	RegisterAuraScript(aura_devour_magic);
	RegisterAuraScript(aura_drain_essence);
	RegisterAuraScript(aura_ancient_curse);
	RegisterCreatureAI(npc_mana_orb);
	RegisterAuraScript(aura_forbidden_mana);
    RegisterAreaTriggerAI(at_maut_devoured_abyss);
    RegisterAreaTriggerAI(at_maut_dark_manifestation_pull);
    RegisterAreaTriggerAI(at_maut_mana_orb);
}
