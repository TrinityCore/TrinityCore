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
#include "Spell.h"
#include "nyalotha.h"

enum Texts
{
	SAY_AGGRO = 0,
	SAY_DRAW_VITA,
	SAY_SUMMON_VOID_HUNTER,
	SAY_SUMMON_CRACKLING_STALKER,
	SAY_PHASE_2,
	SAY_CHARGED_BONDS,
	SAY_GORGE,
	SAY_VOID_ERUPTION,
	SAY_DEATH
};

enum Spells
{
	SPELL_NULLYFYING_STRIKE = 306819,	
	SPELL_DRAW_VITA = 306090,
	SPELL_INEVITABLE_PULL = 306106,
	SPELL_UNCLAIMED_VITA = 313395,
	SPELL_DRAW_VOID = 306168,
	SPELL_UNCLAIMED_VOID = 313398,
	SPELL_VOID_EMPOWERED = 306733,
	SPELL_VITA_EMPOWERED = 306732,
	SPELL_OVERWHELMING_RAGE = 307673,
	SPELL_UNLEASHED_VOID = 306184,
	SPELL_INSTABILITY_EXPOSURE = 306279,
	SPELL_UNSTABLE_VITA_DAMAGE = 306257,
	SPELL_UNSTABLE_VITA_AURA = 306273,
	SPELL_UNSTABLE_VITA_AREA_KNOCKBACK = 316005,
	SPELL_UNSTABLE_VOID_MISSILE = 306603,
	SPELL_UNLEASHED_VITA_DAMAGE = 306115,	
	//Summon Spells
	SPELL_SUMMON_CRACKLING_STALKER = 306865,
	SPELL_SUMMON_NIGHT_TERROR = 314484,
	SPELL_SUMMON_VOID_HUNTER = 306866,
	//Void Hunter
	SPELL_VOID_COLLAPSE = 306881,
	SPELL_VOID_DEFILEMENT = 309777,
	//Crackling Stalker
	SPELL_CHAIN_LIGHTNING = 306874,
	//Phase 2
	SPELL_GORGE_ENERGY = 309985,
	SPELL_DECAYING_STRIKE = 313213,
	SPELL_DECAYING_WOUND = 313227,
	SPELL_LINGERING_ENERGIES = 309755,
	SPELL_RUIN = 309852,
	SPELL_VOID_ERUPTION = 310003,
	SPELL_VOID_ERUPTION_MISSILE = 310004,
	SPELL_CHARGED_BONDS = 310019,
	//Mythic
	SPELL_NIGHTMARE_EMPOWERED = 312996,
	SPELL_UNSTABLE_NIGHTMARE = 313077,
	SPELL_UNLEASHED_NIGHTMARE_MISSILE = 306654,
	SPELL_UNSTABLE_NIGHTMARE_DAMAGE = 313109,
	SPELL_UNSTABLE_NIGHTMARE_MISSILE = 313003,
	SPELL_DRAW_NIGHTMARE = 312750,
	SPELL_UNCLAIMED_NIGHTMARE = 313399,
	SPELL_DREAD_INFERNO_CREATE_AT = 315252,
	SPELL_DREAD_INFERNO_AT_DAMAGE = 315258,
};

enum Events
{
	EVENT_RADEN_ENERGY = 1,
	EVENT_NULLYFYING_STRIKE,
	EVENT_DRAW_VITA_VOID,
	EVENT_UNSTABLE_VOID,
	//Phase 2
	EVENT_DECAYING_STRIKE,
	EVENT_GORGE_ENERGY,
	EVENT_RUIN,
	EVENT_VOID_ERUPTION,
	EVENT_CHARGED_BONDS,
	//Adds
	EVENT_VOID_COLLAPSE,
	EVENT_CHAIN_LIGHTNING,
	EVENT_DREAD_INFERNO
};

const Position essence_of_void_spawn = { -342.462f, 247.273f, -211.817f, 4.952f };
const Position essence_of_vita_spawn = { -266.726f, 180.448f, -211.817f, 3.255f };
const Position essence_of_nightmare_spawn = { -358.802f, 156.894f, -211.818f, 0.859f };

//156866
struct boss_raden : public BossAI
{
	boss_raden(Creature* creature) : BossAI(creature, DATA_RADEN) { }

private:
	uint8 phase;
	uint8 unstableVoidBounce;

	void Reset() override
	{
		BossAI::Reset();
		me->SetPowerType(POWER_ENERGY);
		me->SetMaxPower(POWER_ENERGY, 100);
		me->SetPower(POWER_ENERGY, 0);
		me->AddAura(AURA_OVERRIDE_POWER_COLOR_ENTROPIC);
	}

	void EnterCombat(Unit* /*who*/) override
	{
		Talk(SAY_AGGRO);
		_EnterCombat();
		events.ScheduleEvent(EVENT_RADEN_ENERGY, 100ms);
		events.ScheduleEvent(EVENT_DRAW_VITA_VOID, 5s);
		events.ScheduleEvent(EVENT_NULLYFYING_STRIKE, 21s);
		this->phase = 1;
		this->unstableVoidBounce = 0;
	}

	void DamageTaken(Unit* attacker, uint32& damage) override
	{
		if (this->phase = 1 && me->HealthBelowPct(40))
		{
			Talk(SAY_PHASE_2);
			events.Reset();
			this->phase = 2;
			me->SetPower(POWER_ENERGY, 0);
			events.ScheduleEvent(EVENT_RADEN_ENERGY, 100ms);
			events.ScheduleEvent(EVENT_GORGE_ENERGY, 1s);
			events.ScheduleEvent(EVENT_VOID_ERUPTION, 20s);
			events.ScheduleEvent(EVENT_DECAYING_STRIKE, 21s);
			events.ScheduleEvent(EVENT_CHARGED_BONDS, 10s);
			events.ScheduleEvent(EVENT_RUIN, 25s);			
		}
	}

	void ExecuteEvent(uint32 eventId) override
	{
		if (Aura* unclaimedVita = me->GetAura(SPELL_UNCLAIMED_VITA))
		{
			if (unclaimedVita->GetStackAmount() == 2)
			{				
				if (!me->HasAura(SPELL_OVERWHELMING_RAGE))
					me->CastSpell(nullptr, SPELL_OVERWHELMING_RAGE, true);
				unclaimedVita->SetStackAmount(0);
			}
		}
		if (Aura* unclaimedVoid = me->GetAura(SPELL_UNCLAIMED_VOID))
		{
			if (unclaimedVoid->GetStackAmount() == 2)
			{
				if (!me->HasAura(SPELL_OVERWHELMING_RAGE))
					me->CastSpell(nullptr, SPELL_OVERWHELMING_RAGE, true);
				unclaimedVoid->SetStackAmount(0);
			}
		}
		if (Aura* unclaimedNightmare = me->GetAura(SPELL_UNCLAIMED_NIGHTMARE))
		{
			if (unclaimedNightmare->GetStackAmount() == 2)
			{
				if (!me->HasAura(SPELL_OVERWHELMING_RAGE))
					me->CastSpell(nullptr, SPELL_OVERWHELMING_RAGE, true);
				unclaimedNightmare->SetStackAmount(0);
			}
		}
		switch (eventId)
		{
		case EVENT_RADEN_ENERGY:
			me->ModifyPower(POWER_ENERGY, +5);
			events.Repeat(1s);
			break;
		
		case EVENT_NULLYFYING_STRIKE:
			if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
				me->CastSpell(target, SPELL_NULLYFYING_STRIKE, false);
			events.Repeat(20s);
			break;

		case EVENT_DRAW_VITA_VOID:
			Talk(SAY_DRAW_VITA);
			me->SummonCreature(NPC_ESSENCE_OF_VITA, essence_of_vita_spawn, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_ESSENCE_OF_VOID, essence_of_void_spawn, TEMPSUMMON_MANUAL_DESPAWN);
			if (IsMythic())
				me->SummonCreature(NPC_ESSENCE_OF_NIGHTMARE, essence_of_nightmare_spawn, TEMPSUMMON_MANUAL_DESPAWN);
			events.Repeat(60s);
			break;

		case EVENT_DECAYING_STRIKE:
			if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
			{
				me->CastSpell(target, SPELL_DECAYING_STRIKE, false);
				me->AddAura(SPELL_DECAYING_WOUND, target);
			}
			events.Repeat(21s);
			break;

		case EVENT_GORGE_ENERGY:
			Talk(SAY_GORGE);
			me->CastSpell(nullptr, SPELL_GORGE_ENERGY, false);
			events.Repeat(30s);
			break;

		case EVENT_RUIN:
			me->AddAura(SPELL_RUIN);
			break;

		case EVENT_VOID_ERUPTION:
			Talk(SAY_VOID_ERUPTION);
			if (IsMythic())
			{
				UnitList tarlist;
				SelectTargetList(tarlist, 6, SELECT_TARGET_RANDOM, 100.0f);
				for (Unit* targets : tarlist)
				{					
					me->CastSpell(targets->GetPosition(), SPELL_VOID_ERUPTION_MISSILE, true);
				}
			}
			else
			{
				UnitList tarlist;
				SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 100.0f);
				for (Unit* targets : tarlist)
				{					
					me->CastSpell(targets->GetPosition(), SPELL_VOID_ERUPTION_MISSILE, true);
				}
			}	
			events.Repeat(20s);
			break;

		case EVENT_CHARGED_BONDS:
			Talk(SAY_CHARGED_BONDS);
			if (IsMythic())
			{
				UnitList tarlist;
				SelectTargetList(tarlist, 4, SELECT_TARGET_RANDOM, 100.0f);
				for (Unit* targets : tarlist)
				{					
					me->CastSpell(targets->GetPosition(), SPELL_CHARGED_BONDS, true);
				}
			}
			if (IsHeroic())
			{
				UnitList tarlist;
				SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 100.0f);
				for (Unit* targets : tarlist)
				{
					me->CastSpell(targets->GetPosition(), SPELL_CHARGED_BONDS, true);
				}
			}
			else
			{
				UnitList tarlist;
				SelectTargetList(tarlist, 2, SELECT_TARGET_RANDOM, 100.0f);
				for (Unit* targets : tarlist)
				{
					me->CastSpell(targets->GetPosition(), SPELL_CHARGED_BONDS, true);
				}
			}
			events.Repeat(10s);
			break;
		}
	}

	/*void OnSpellFinished(SpellInfo const* spellInfo) override
	{
	}*/

	void SpellHitTarget(Unit* target, const SpellInfo* spellInfo) override
	{
		switch (spellInfo->Id)
		{
		case SPELL_UNSTABLE_VOID_MISSILE:
			if (unstableVoidBounce != 5)
			{
				if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
					me->CastSpell(target, SPELL_UNSTABLE_VOID_MISSILE, true);
			}		
			if (unstableVoidBounce == 5)
				unstableVoidBounce = 0;

			unstableVoidBounce++;
			break;
		}
	}

	void SpellHitDest(SpellDestination const* dest, SpellInfo const* spellInfo)
	{		
		switch (spellInfo->Id)
		{
		case SPELL_UNSTABLE_VOID_MISSILE:			
			break;
		}
	}

	void CleanupEncounter(InstanceScript* instance, Creature* me)
	{
		_JustReachedHome();
		me->DespawnCreaturesInArea(NPC_ESSENCE_OF_VITA, 125.0f);
		me->DespawnCreaturesInArea(NPC_ESSENCE_OF_VOID, 125.0f);
		me->DespawnCreaturesInArea(NPC_VOID_HUNTER, 125.0f);
		me->DespawnCreaturesInArea(NPC_CRACKLING_STALKER, 125.0f);
		me->DespawnCreaturesInArea(NPC_ESSENCE_OF_NIGHTMARE, 125.0f);
		me->DespawnCreaturesInArea(NPC_NIGHT_TERROR, 125.0f);
		me->DespawnCreaturesInArea(NPC_CRACKLING_STALKER, 125.0f);
		me->RemoveAllAreaTriggers();
	}

	void EnterEvadeMode(EvadeReason /*why*/) override
	{
		CleanupEncounter(instance, me);
		_DespawnAtEvade();
	}

	void JustDied(Unit* /*attacker*/) override
	{		
		Talk(SAY_DEATH);
		_JustDied();
		CleanupEncounter(instance, me);
		instance->DoModifyPlayerCurrencies(CURRENCY_ECHOES_OF_NYALOTHA, 19);
	}
};

//156884,156980,160663
struct npc_essence_raden : public ScriptedAI
{
	npc_essence_raden(Creature* c) : ScriptedAI(c)
	{ 
		me->SetHover(true);
	}

	void Reset() override
	{
		switch (me->GetEntry())
		{
		case NPC_ESSENCE_OF_VITA:
			me->SetReactState(REACT_PASSIVE);
			me->SetWalk(true);
			me->SetSpeed(MOVE_WALK, 0.5);
			me->AddAura(SPELL_INEVITABLE_PULL);
			break;

		case NPC_ESSENCE_OF_VOID:
			me->SetReactState(REACT_PASSIVE);
			me->SetWalk(true);
			me->SetSpeed(MOVE_WALK, 0.5);
			me->AddAura(SPELL_INEVITABLE_PULL);
			break;

		case NPC_ESSENCE_OF_NIGHTMARE:
			me->SetReactState(REACT_PASSIVE);
			me->SetWalk(true);
			me->SetSpeed(MOVE_WALK, 0.5);
			me->AddAura(SPELL_INEVITABLE_PULL);
			break;
		}
	}

	void IsSummonedBy(Unit* summoner) override
	{
		switch (me->GetEntry())
		{
		case NPC_ESSENCE_OF_VITA:
			me->CastSpell(summoner, SPELL_DRAW_VITA, false);
			me->GetMotionMaster()->MoveFollow(summoner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
			break;

		case NPC_ESSENCE_OF_VOID:
			me->CastSpell(summoner, SPELL_DRAW_VOID, false);
			me->GetMotionMaster()->MoveFollow(summoner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
			break;

		case NPC_ESSENCE_OF_NIGHTMARE:
			me->CastSpell(summoner, SPELL_DRAW_NIGHTMARE, false);
			me->GetMotionMaster()->MoveFollow(summoner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
			break;
		}
	}

	void JustDied(Unit* unit) override
	{
		switch (me->GetEntry())
		{
		case NPC_ESSENCE_OF_VITA:
			if (Creature* raden = me->FindNearestCreature(NPC_RADEN, 100.0f, true))
				raden->AddAura(SPELL_UNCLAIMED_VITA);
			me->DespawnOrUnsummon();
			break;

		case NPC_ESSENCE_OF_VOID:
			if (Creature* raden = me->FindNearestCreature(NPC_RADEN, 100.0f, true))
				raden->AddAura(SPELL_UNCLAIMED_VOID);
			me->DespawnOrUnsummon();
			break;

		case NPC_ESSENCE_OF_NIGHTMARE:
			if (Creature* raden = me->FindNearestCreature(NPC_RADEN, 100.0f, true))
				raden->AddAura(SPELL_UNCLAIMED_NIGHTMARE);
			me->DespawnOrUnsummon();
			break;
		}
	}

	void UpdateAI(uint32 diff) override
	{
		switch (me->GetEntry())
		{
		case NPC_ESSENCE_OF_VITA:			
			if (Creature* raden = me->FindNearestCreature(NPC_RADEN, 10.0f, true))
			{
				if (me->GetDistance2d(raden) <= 10.0f)
				{
					//Vita Empowered				
					me->AddAura(SPELL_VITA_EMPOWERED, raden);
					raden->CastSpell(nullptr, SPELL_UNLEASHED_VITA_DAMAGE, true);
					raden->GetScheduler().Schedule(5s, [this, raden](TaskContext context)
					{
						if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
						{
							if (target->IsWithinMeleeRange(raden))
								raden->CastSpell(target, SPELL_UNSTABLE_VITA_AREA_KNOCKBACK, true);

							raden->CastSpell(target, SPELL_UNSTABLE_VITA_AURA, true);
						}
						raden->SummonCreature(NPC_CRACKLING_STALKER, essence_of_vita_spawn, TEMPSUMMON_MANUAL_DESPAWN);
						//raden->CastSpell(essence_of_vita_spawn, SPELL_SUMMON_CRACKLING_STALKER, false);
					});
					me->DespawnOrUnsummon();
				}
			}
			break;

		case NPC_ESSENCE_OF_VOID:
			if (Creature* raden = me->FindNearestCreature(NPC_RADEN, 10.0f, true))
			{
				if (me->GetDistance2d(raden) <= 10.0f)
				{
					//Void Empowered
					me->AddAura(SPELL_VOID_EMPOWERED, raden);
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
					{
						if (target->IsWithinMeleeRange(raden))
							raden->CastSpell(target, SPELL_UNSTABLE_VITA_AREA_KNOCKBACK, true);

						raden->CastSpell(target, SPELL_UNSTABLE_VITA_AURA, true);
					}
					AddTimedDelayedOperation(6000, [raden]()
					{
						raden->SummonCreature(NPC_CRACKLING_STALKER, essence_of_void_spawn, TEMPSUMMON_MANUAL_DESPAWN);
					});
					me->DespawnOrUnsummon();
				}
			}
			break;

		case NPC_ESSENCE_OF_NIGHTMARE:
			if (Creature* raden = me->FindNearestCreature(NPC_RADEN, 10.0f, true))
			{
				if (me->GetDistance2d(raden) <= 10.0f)
				{
					//Nightmare Empowered
					me->AddAura(SPELL_NIGHTMARE_EMPOWERED, raden);;
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
					{
						raden->CastSpell(target, SPELL_UNSTABLE_NIGHTMARE_MISSILE, true);
					}
					me->DespawnOrUnsummon();
				}
			}
			break;
		}
	}
};

//157366, 157365
struct npc_void_hunter_crackling_stalker : public ScriptedAI
{
	npc_void_hunter_crackling_stalker(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		switch (me->GetEntry())
		{
		case NPC_VOID_HUNTER:
			if (instance)
				instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
			break;

		case NPC_CRACKLING_STALKER:
			if (instance)
				instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
			break;
		}
	}

	void IsSummonedBy(Unit* summoner)
	{
		if (summoner->IsInCombat())
			me->AI()->DoZoneInCombat(nullptr);
	}

	void EnterCombat(Unit* who) override
	{
		switch (me->GetEntry())
		{
		case NPC_VOID_HUNTER:
			events.ScheduleEvent(EVENT_VOID_COLLAPSE, 3s);
			break;

		case NPC_CRACKLING_STALKER:
			events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 3s);
			break;
		}
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_VOID_COLLAPSE:
			DoCastAOE(SPELL_VOID_COLLAPSE, false);
			events.Repeat(15s);
			break;

		case EVENT_CHAIN_LIGHTNING:
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
				me->CastSpell(target, SPELL_CHAIN_LIGHTNING, false);
			events.Repeat(15s);
			break;
		}
	}

	void JustDied(Unit* unit) override
	{
		switch (me->GetEntry())
		{
		case NPC_VOID_HUNTER:
			if (instance)
				instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
			break;

		case NPC_CRACKLING_STALKER:
			if (instance)
				instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
			break;
		}
	}
};

//306273 
class aura_unstable_vita : public AuraScript
{
	PrepareAuraScript(aura_unstable_vita);

	void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
	{
		Unit* target = GetTarget();
		Unit* caster = GetCaster();
		if (!caster || !target)
			return;

		if (caster->GetEntry() == NPC_RADEN)
		{
			if (Aura* thisAura = target->GetAura(SPELL_UNSTABLE_VITA_AURA))
				thisAura->SetStackAmount(5);
		}
		if (caster->IsPlayer())
		{
			if (Aura* thisAura = target->GetAura(SPELL_UNSTABLE_VITA_AURA))
				thisAura->SetStackAmount(-1);
		}
	}

	void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
	{
		Unit* target = GetTarget();
		Unit* caster = GetCaster();
		if (!caster || !target)
			return;

		if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
		{
			if (Player* player = target->SelectNearestPlayer(100.0f))
			{
				caster->CastSpell(target, SPELL_UNSTABLE_VITA_DAMAGE, true);
				caster->CastSpell(target, SPELL_UNSTABLE_VITA_AURA, true);
			}
		}
	}

	void Register() override
	{
		OnEffectApply += AuraEffectApplyFn(aura_unstable_vita::OnApply, EFFECT_1, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
		OnEffectRemove += AuraEffectRemoveFn(aura_unstable_vita::OnRemove, EFFECT_1, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
	}
};

//310019 
class aura_charged_bonds : public AuraScript
{
	PrepareAuraScript(aura_charged_bonds);

	void OnTick(AuraEffect const* /*aurEff*/)
	{
		if (Unit* target = GetTarget())
		{
			if (Player* player = target->SelectNearestPlayer(45.0f))
			{
				if (target->HasAura(SPELL_CHARGED_BONDS) && target->GetDistance2d(player) > 40.0f)
				{
					target->RemoveAura(SPELL_CHARGED_BONDS);
					player->RemoveAura(SPELL_CHARGED_BONDS);
				}
			}
		}
	}

	void Register() override
	{
		OnEffectPeriodic += AuraEffectPeriodicFn(aura_charged_bonds::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
	}
};

void AddSC_raden()
{
	RegisterCreatureAI(boss_raden);
	RegisterCreatureAI(npc_essence_raden);
	RegisterCreatureAI(npc_void_hunter_crackling_stalker);
	RegisterAuraScript(aura_unstable_vita);
	RegisterAuraScript(aura_charged_bonds);
};