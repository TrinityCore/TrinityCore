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

enum Spells
{
	SPELL_CAUSTIC_COATING_PERIODIC_DAMAGE = 309704,
	SPELL_CAUSTIC_COATING_BUFF = 309707,
	SPELL_DEBILITATING_SPIT = 307358,
	SPELL_UMBRAL_ERUPTION_MISSILE = 307944,
	SPELL_CRASH_CAST = 307476,
	SPELL_CRASH_DAMAGE = 307471,
	SPELL_DISSOLVE_CAST = 307478,
	SPELL_DISSOLVE_DAMAGE = 307472,
	SPELL_FIXATE_TARGET	= 318078, //Living Miasma
	SPELL_SLURRY_OUTBURST = 307240, //Living Miasma
	SPELL_UMBRAL_MANTLE = 306448,
	SPELL_UMBRAL_BREATH_CAST = 312528,
	SPELL_UMBRAL_BREATH_STUN = 306928, 
	SPELL_EAT_ENTROPIC_CARCASS = 316031,
	SPELL_EAT_NOXIOUS_CARCASS = 316030,
	SPELL_ENTROPIC_MANTLE = 306934,
	SPELL_ENTROPIC_BREATH_INSTANT = 312530,
	SPELL_ENTROPIC_BREATH_MOD_HEALING_DONE = 306930,
	SPELL_ENTROPIC_BUILDUP_PERIODIC_DAMAGE = 308177,
	SPELL_ENTROPIC_BUILDUP_CREATE_AT = 308173,
	SPELL_NOXIOUS_MANTLE_PERIODIC = 306932,
	SPELL_NOXIOUS_MANTLE_APPLY_AT = 306931,
	SPELL_BUBBLING_OVERFLOW_AT_DAMAGE = 314736,
	SPELL_BUBBLING_OVERFLOW_APPLY_AT = 308025, //?
	SPELL_BUBBLING_OVERFLOW_MOD_DAMAGE_TAKEN = 308149,
	//314735?
	SPELL_BUBBLING_OVERFLOW_CREATE_AT = 315885,
	SPELL_BUBLING_OVERFLOW_MISSILE = 315888, // triggers spell + at above
	SPELL_BUBBLING_BREATH_CAST = 312529,
	SPELL_BUBBLING_BREATH_PERIODIC_DAMAGE = 306929,
	SPELL_FRENZY = 306942,
	//Heroic	
	//Mythic
	SPELL_HUNGRY_STACK = 312328,
	SPELL_UNCONTROLLABLY_RAVENOUS = 312329,
	SPELL_SLIMY_RESIDUE = 312332,
	SPELL_TASTY_MORSEL_MOD_SCALE = 312099,
	SPELL_TASTY_MORSEL_MISSILE = 312311,
	SPELL_TASTY_MORSEL_CREATE_AT = 312316,
};

enum Events
{
	EVENT_POWER_GAIN = 1,
	EVENT_DEBILATITING_SPIT,
	EVENT_UMBRAL_ERUPTION,
	EVENT_CRASH_DISSOLVE,
	EVENT_LIVING_MIASMA,
	EVENT_UMBRAL_MANTLE,
	EVENT_ENTROPIC_MANTLE,
	EVENT_ENTROPIC_BUILDUP,
	EVENT_ENTROPIC_BREAT,
	EVENT_NOXIOUS_MANTLE,
	EVENT_BUBBLING_BREATH,
	EVENT_FRENZY,
	EVENT_HUNGRY
};

//157231
struct boss_shadhar : public BossAI
{
	boss_shadhar(Creature* creature) : BossAI(creature, DATA_SHADHAR) { }

private:
	uint8 phase;

	void Reset() override
	{
		BossAI::Reset();
		me->SetPowerType(POWER_ENERGY);
		me->SetMaxPower(POWER_ENERGY, 100);
		me->SetPower(POWER_ENERGY, 0);
		me->AddAura(AURA_OVERRIDE_POWER_COLOR_PURPLE2);
		me->SetReactState(REACT_AGGRESSIVE);
	}

	void EnterCombat(Unit* u) override
	{
		_EnterCombat();
		this->phase = 1;
		events.ScheduleEvent(EVENT_POWER_GAIN, 1s);
		events.ScheduleEvent(EVENT_CRASH_DISSOLVE, 5s);
		events.ScheduleEvent(EVENT_UMBRAL_ERUPTION, 9500ms);
		events.ScheduleEvent(EVENT_DEBILATITING_SPIT, 10s);
		events.ScheduleEvent(EVENT_LIVING_MIASMA, 15s);
		events.ScheduleEvent(EVENT_UMBRAL_MANTLE, 20s);
		if (IsMythic())
			events.ScheduleEvent(EVENT_HUNGRY, 60s);
	}

	void JustSummoned(Creature* summon) override
	{
		if (summon->GetEntry() == NPC_LIVING_MIASMA)
		{
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
			if (Unit* fixateTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
			{				
				summon->SetWalk(true);
				summon->GetSpeed(MOVE_WALK);
				summon->CastSpell(fixateTarget, SPELL_FIXATE_TARGET, true);
				summon->AddThreat(fixateTarget, 1000.0f, SpellSchoolMask::SPELL_SCHOOL_MASK_NORMAL);
			}
		}
	}

	void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)  override
	{
		if (summon->GetEntry() == NPC_LIVING_MIASMA)
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon);
	}

	void EnterEvadeMode(EvadeReason /*why*/) override
	{
		_JustReachedHome();
		_DespawnAtEvade();		
		CleanEncounter(instance, me);
	}

	void CleanEncounter(InstanceScript* instance, Creature* me)
	{
		me->DespawnCreaturesInArea(NPC_LIVING_MIASMA, 125.0f);
		me->DespawnCreaturesInArea(NPC_ENTROPIC_BUILDUP, 125.0f);
		me->RemoveAllAreaTriggers();
	}

	void DamageTaken(Unit* done_by, uint32& damage) override
	{
		if (me->HealthBelowPct(67) && this->phase == 1)
		{
			this->phase = 2;
			events.Reset();
			events.ScheduleEvent(EVENT_POWER_GAIN, 1s);
			me->CastSpell(nullptr, SPELL_EAT_ENTROPIC_CARCASS, false);
			me->RemoveAura(AURA_OVERRIDE_POWER_COLOR_PURPLE2);
			me->AddAura(AURA_OVERRIDE_POWER_COLOR_ENTROPIC);
			events.ScheduleEvent(EVENT_CRASH_DISSOLVE, 5s);
			events.ScheduleEvent(EVENT_UMBRAL_ERUPTION, 9500ms);
			events.ScheduleEvent(EVENT_DEBILATITING_SPIT, 10s);
			events.ScheduleEvent(EVENT_LIVING_MIASMA, 15s);
			events.ScheduleEvent(EVENT_ENTROPIC_MANTLE, 20s);
		}
		if (me->HealthBelowPct(34) && this->phase == 2)
		{
			this->phase = 3;
			events.Reset();
			events.ScheduleEvent(EVENT_POWER_GAIN, 1s);
			me->CastSpell(nullptr, SPELL_EAT_NOXIOUS_CARCASS, false);
			me->RemoveAura(AURA_OVERRIDE_POWER_COLOR_ENTROPIC);
			me->AddAura(AURA_OVERRIDE_POWER_COLOR_GREEN);
			events.ScheduleEvent(EVENT_NOXIOUS_MANTLE, 4s);
			events.ScheduleEvent(EVENT_CRASH_DISSOLVE, 5s);
			events.ScheduleEvent(EVENT_UMBRAL_ERUPTION, 9500ms);
			events.ScheduleEvent(EVENT_DEBILATITING_SPIT, 10s);
			events.ScheduleEvent(EVENT_LIVING_MIASMA, 15s);
			me->AddAura(SPELL_FRENZY);
		}
	}

	void MoveInLineOfSight(Unit* unit) override
	{
		//Caustic damage when players enter to water
		if (unit->IsPlayer() && me->IsInCombat() && !unit->HasAura(SPELL_CAUSTIC_COATING_PERIODIC_DAMAGE) && unit->IsInWater())
			me->AddAura(SPELL_CAUSTIC_COATING_PERIODIC_DAMAGE, unit);

		if (unit->IsPlayer() && unit->HasAura(SPELL_CAUSTIC_COATING_PERIODIC_DAMAGE) && unit->IsInWater())
			unit->RemoveAura(SPELL_CAUSTIC_COATING_PERIODIC_DAMAGE);
	}

	void SpellHitTarget(Unit* target, SpellInfo const* spell) override
	{
		switch (spell->Id)
		{
		case SPELL_UMBRAL_BREATH_CAST:
			me->AddAura(SPELL_UMBRAL_BREATH_STUN, target);
			break;
		case SPELL_ENTROPIC_BREATH_INSTANT:
			me->AddAura(SPELL_ENTROPIC_BREATH_MOD_HEALING_DONE, target);
			break;
		case SPELL_BUBBLING_BREATH_CAST:
			me->AddAura(SPELL_BUBBLING_BREATH_PERIODIC_DAMAGE, target);
			break;
		}
	}

	void ExecuteEvent(uint32 eventId) override
	{
		//Caustic buff when boss enter to water
		if (me->IsInWater())
			if (!me->HasAura(SPELL_CAUSTIC_COATING_BUFF))
				me->AddAura(SPELL_CAUSTIC_COATING_BUFF);

		if (IsMythic())
		{
			if (Aura* hungry = me->GetAura(SPELL_HUNGRY_STACK))
			{
				if (hungry->GetStackAmount() == 10)
				{
					me->RemoveAurasDueToSpell(SPELL_HUNGRY_STACK);
					me->AddAura(SPELL_UNCONTROLLABLY_RAVENOUS);
				}
			}
		}
		//Handle breaths depends on energy and phase
		if (me->GetPower(POWER_ENERGY) == 100 && this->phase == 1)
		{
			me->ModifyPower(POWER_ENERGY, -100);
			if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
			{
				me->SetFacingToObject(target, true);
				me->CastSpell(target, SPELL_UMBRAL_BREATH_CAST, false);
			}
		}
		if (me->GetPower(POWER_ENERGY) == 100 && this->phase == 2)
		{
			me->ModifyPower(POWER_ENERGY, -100);
			if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
			{
				me->SetFacingToObject(target, true);
				me->CastSpell(target, SPELL_ENTROPIC_BREATH_INSTANT, false);
			}
		}
		if (me->GetPower(POWER_ENERGY) == 100 && this->phase == 3)
		{
			me->ModifyPower(POWER_ENERGY, -100);
			if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
			{
				me->SetFacingToObject(target, true);
				me->CastSpell(target, SPELL_BUBBLING_BREATH_CAST, false);
			}
		}
		switch (eventId)
		{
		case EVENT_POWER_GAIN:
		{
			me->ModifyPower(POWER_ENERGY, +7);
			events.Repeat(2s);
			break;
		}
		case EVENT_DEBILATITING_SPIT:
		{
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
			{
				me->CastSpell(target, SPELL_DEBILITATING_SPIT, true);
				if (Aura* spit = target->GetAura(SPELL_DEBILITATING_SPIT))	
					spit->SetStackAmount(4);
			}
			events.Repeat(35s);
			break;
		}
		case EVENT_UMBRAL_ERUPTION:
		{
			for (uint8 i = 0; i < 15; i++)
			{
				me->CastSpell(me->GetRandomNearPosition(20.0f), SPELL_UMBRAL_ERUPTION_MISSILE, true);
			}			
			events.Repeat(20s);
			break;
		}
		case EVENT_CRASH_DISSOLVE:
		{
			//TODO: Random casts
			if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
			{
				me->CastSpell(target, SPELL_CRASH_CAST, false);
				AddTimedDelayedOperation(2600, [this, target]() -> void
				{
					me->CastSpell(target, SPELL_CRASH_DAMAGE, true);
				});
				AddTimedDelayedOperation(3000, [this, target]() -> void
				{
					me->CastSpell(target, SPELL_DISSOLVE_CAST, false);
				});
				AddTimedDelayedOperation(5500, [this, target]() -> void
				{
					me->CastSpell(target, SPELL_DISSOLVE_DAMAGE, true);
				});
			}
			events.Repeat(30s, 35s);
			break;
		}
		case EVENT_LIVING_MIASMA:
		{
			me->SummonCreature(NPC_LIVING_MIASMA, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
			events.Repeat(30s);
			break;
		}
		case EVENT_UMBRAL_MANTLE:
		{
			std::list<Player*> pl_li;
			me->GetPlayerListInGrid(pl_li, 100.0f);
			for (auto& targets : pl_li)
			{
				me->CastSpell(targets, SPELL_UMBRAL_MANTLE, true);
			}
			events.Repeat(20s);
			break;
		}
		case EVENT_ENTROPIC_MANTLE:
		{
			std::list<Player*> pl_li;
			me->GetPlayerListInGrid(pl_li, 100.0f);
			for (auto& targets : pl_li)
			{
				me->CastSpell(targets, SPELL_ENTROPIC_MANTLE, true);
			}
			events.ScheduleEvent(EVENT_ENTROPIC_BUILDUP, 3s);
			events.Repeat(20s);
			break;
		}
		case EVENT_NOXIOUS_MANTLE:
		{
			std::list<Player*> pl_li;
			me->GetPlayerListInGrid(pl_li, 100.0f);
			for (auto& targets : pl_li)
			{
				me->AddAura(SPELL_NOXIOUS_MANTLE_PERIODIC, targets);
			}
			break;
		}
		case EVENT_ENTROPIC_BUILDUP:
		{
			for (uint8 i = 0; i < 3; i++)
			{
				me->CastSpell(me->GetRandomNearPosition(20.0f), SPELL_ENTROPIC_BUILDUP_CREATE_AT, true);
			}
			break;
		}
		case EVENT_HUNGRY:
		{
			me->AddAura(SPELL_HUNGRY_STACK);
			if (Aura* hungryStack = me->GetAura(SPELL_HUNGRY_STACK))
				hungryStack->ModStackAmount(+1);
			break;
			events.Repeat(60s);
		}
		}
	}

	void JustDied(Unit* /*attacker*/) override
	{
		_JustDied();
		CleanEncounter(instance, me);
		instance->DoModifyPlayerCurrencies(CURRENCY_ECHOES_OF_NYALOTHA, 11);
	}
};

//307358
class aura_debilatiting_spit : public AuraScript
{
	PrepareAuraScript(aura_debilatiting_spit);

	void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
	{
		Unit* target = GetTarget();
		Unit* caster = GetCaster();
		if (!caster || !target)
			return;

		if (Unit* caster = GetTarget())
		{
			std::list<Player*> jumpTargets_li;
			caster->GetPlayerListInGrid(jumpTargets_li, 25.0f);
			for (auto& targets : jumpTargets_li)
			{
				if (!targets->GetAura(SPELL_DEBILITATING_SPIT))
				{
					GetCaster()->CastSpell(targets, SPELL_DEBILITATING_SPIT, true);
					if (Aura* spit = targets->GetAura(SPELL_DEBILITATING_SPIT))
						spit->SetStackAmount(2);
				}
			}
		}
	}

	void Register() override
	{
		OnEffectRemove += AuraEffectRemoveFn(aura_debilatiting_spit::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
	}
};

//500600
struct npc_entropic_buildup : public ScriptedAI
{
	npc_entropic_buildup(Creature* c) : ScriptedAI(c) 
	{
		me->SetReactState(REACT_PASSIVE);
	}

private:
	uint8 Timer;

	void Reset() override
	{
		ScriptedAI::Reset();
		me->SetHover(true);
		me->SetHoverHeight(1.0f);
		me->SetDisplayId(93188, 1.0f);
		/*AddTimedDelayedOperation(15000, [this]() -> void
		{
			//TODO
		});*/
		this->Timer = 0;
	}

	void MoveInLineOfSight(Unit* unit) override
	{
		if (unit->IsPlayer() && unit->GetDistance2d(me) <= 10.0f)
		{
			//Apply periodic damage, when player stand in it
			if (unit->IsPlayer() && unit->GetDistance2d(me) <= 5.0f && !unit->HasAura(SPELL_ENTROPIC_BUILDUP_PERIODIC_DAMAGE))
			{
				me->AddAura(SPELL_ENTROPIC_BUILDUP_PERIODIC_DAMAGE, unit);
			}
			if (unit->IsPlayer() && unit->GetDistance2d(me) > 5.0f && unit->HasAura(SPELL_ENTROPIC_BUILDUP_PERIODIC_DAMAGE))
				unit->RemoveAura(SPELL_ENTROPIC_BUILDUP_PERIODIC_DAMAGE);
		}
	}
};

//157229
struct npc_living_miasma : public ScriptedAI
{
	npc_living_miasma(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
	}

	void MoveInLineOfSight(Unit* unit) override
	{
		if (unit->IsPlayer() && unit->GetDistance2d(me) <= 5.0f && unit->HasAura(SPELL_FIXATE_TARGET))
		{
			me->CastSpell(unit, SPELL_SLURRY_OUTBURST, true);
			unit->RemoveAura(SPELL_FIXATE_TARGET);
		}
	}
};

//40018, 308173
struct at_entropic_buildup : public AreaTriggerAI
{
	at_entropic_buildup(AreaTrigger* at) : AreaTriggerAI(at) { }

private:
	bool soaked;

	void OnCreate() override
	{
		soaked = false;
		at->SetDuration(15000);
	}

	void OnUnitEnter(Unit* unit) override
	{
		if (unit->IsPlayer() && !unit->HasAura(SPELL_ENTROPIC_BUILDUP_PERIODIC_DAMAGE))
		{
			at->GetCaster()->AddAura(SPELL_ENTROPIC_BUILDUP_PERIODIC_DAMAGE, unit);
			soaked = true;
		}
	}

	void OnUnitExit(Unit* unit) override
	{
		if (unit->HasAura(SPELL_ENTROPIC_BUILDUP_PERIODIC_DAMAGE))
			unit->RemoveAura(SPELL_ENTROPIC_BUILDUP_PERIODIC_DAMAGE);
	}
};

void AddSC_shadhar()
{
	RegisterCreatureAI(boss_shadhar);
	RegisterAuraScript(aura_debilatiting_spit);
	RegisterCreatureAI(npc_entropic_buildup);
	RegisterCreatureAI(npc_living_miasma);
	RegisterAreaTriggerAI(at_entropic_buildup);
};
