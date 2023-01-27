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

enum Texts
{
	SAY_AGGRO = 0,
	SAY_EYE_OF_NZOTH,
	SAY_CORRUPTORS_GAZE,
	SAY_ORGANS_OF_CORRUPTION,
	SAY_ORGAN_SLAIN,
	SAY_KILL,
	SAY_WIPE,
	SAY_DEATH
};

const Position organ_of_corruption_left = { -284.047f, 112.586f, -524.631f, 3.925f };
const Position organ_of_corruption_mid = { -294.877f, -1.449811f, -524.986f, 2.198f };
const Position organ_of_corruption_right = { -408.385f, 7.823f, -524.518f, 0.711f };

enum Spells
{
	SPELL_LIVING_CHAMBER = 315097,
	SPELL_EYE_OF_NZOTH = 309961, //every 25s on tank
	SPELL_CORRUPTORS_GAZE_CREATE_AT = 310321,
	SPELL_CORRUPTORS_GAZE_CREATE_PERIODIC_AURA_AT = 310320, //npc 159247
	SPELL_MORASS_OF_CORRUPTION_AT_DAMAGE = 310322,
	SPELL_CURSED_BLOOD = 311159,
	SPELL_CURSED_BLOOD_EPLOSION = 311160,
	SPELL_BERSERK = 317669,
	//Heroic
	SPELL_TOUCH_OF_THE_CORRUPTOR = 311401,
	SPELL_TOUCH_OF_THE_CORRUPTOR_MIND_CONTROL = 311367,
	//Mythic
	SPELL_ABSORBING_CHARGE = 318383,
	//Organ of Corruption
	SPELL_PUMPING_BLOOD_MISSILE = 310788, //triggers summon 159514
	//Blood of Nyalotha
	SPELL_RECURRING_NIGHTMARE_TRIGGER = 312485,
	SPELL_RECURRING_NIGHTMARE_DEBUFF = 312486,
	SPELL_HEMORRHAGE = 311143,
};

enum Events
{
	EVENT_ENERGY_GAIN = 1,
	EVENT_EYE_OF_NZOTH,
	EVENT_CORRUPTORS_GAZE,
	EVENT_SUMMON_ORGANS,
	EVENT_PREPARE_ORGANS,
	EVENT_CURSED_BLOOD,
	EVENT_TOUCH_OF_THE_CORRUPTOR,
	EVENT_CLOTTED_CORRUPTION,
	EVENT_ABSORBING_CHARGE,
	EVENT_BERSERK
};

//158328
struct ilgynoth_n : public BossAI
{
	ilgynoth_n(Creature* creature) : BossAI(creature, DATA_ILGYNOTH) 
	{
		SetCombatMovement(false);
		me->SetFlying(true);
	}

private:
	uint8 phase;
	uint8 organDied;

	void Reset() override
	{
		BossAI::Reset();
		me->SetPowerType(POWER_ENERGY);
		me->SetMaxPower(POWER_ENERGY, 100);
		me->SetPower(POWER_ENERGY, 0);
		me->AddAura(AURA_OVERRIDE_POWER_COLOR_PURPLE2);
		me->SetReactState(REACT_AGGRESSIVE);		
	}

	void EnterCombat(Unit* /*who*/ override)
	{
		_EnterCombat();
		Talk(SAY_AGGRO);
		this->phase = 1;
		this->organDied = 0;
		events.ScheduleEvent(EVENT_ENERGY_GAIN, 1s);
		events.ScheduleEvent(EVENT_EYE_OF_NZOTH, 5s);
		events.ScheduleEvent(EVENT_CORRUPTORS_GAZE, 12s);
		events.ScheduleEvent(EVENT_CURSED_BLOOD, 18s);
		if (IsHeroic() || IsMythic())
		//events.ScheduleEvent(EVENT_TOUCH_OF_THE_CORRUPTOR, 46s);
		events.ScheduleEvent(EVENT_BERSERK, 10min);
	}

	void JustSummoned(Creature* summon) override
	{
		if (summon->GetEntry() != NPC_ORGAN_OF_CORRUPTION)
			summon->AI()->DoZoneInCombat(nullptr);
	}

	void DamageTaken(Unit* done_by, uint32& damage) override
	{
		if (me->HealthBelowPct(2) && this->phase == 1)
		{
			this->phase = 2;
			events.Reset();
			me->SetReactState(REACT_PASSIVE);
			me->AddUnitState(UNIT_STAND_STATE_SUBMERGED);
			events.ScheduleEvent(EVENT_CLOTTED_CORRUPTION, 20s);			
			if (this->organDied == 0)
			{
				Talk(SAY_ORGANS_OF_CORRUPTION);
				events.ScheduleEvent(EVENT_SUMMON_ORGANS, 1s);
			}
			if (this->organDied > 0)
			{
				events.ScheduleEvent(EVENT_PREPARE_ORGANS, 1s);
			}
			if (this->organDied < 3)
			{
				me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
				me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
				me->SetHealth(me->GetMaxHealth());
			}
		}
	}

	void EnterEvadeMode(EvadeReason /*why*/) override
	{
		Talk(SAY_WIPE);
		_JustReachedHome();
		_DespawnAtEvade();
		CleanEncounter(instance, me);
	}

	void CleanEncounter(InstanceScript* instance, Creature* me)
	{
		me->DespawnCreaturesInArea(NPC_ORGAN_OF_CORRUPTION, 125.0f);
		me->DespawnCreaturesInArea(NPC_BLOOD_OF_NYALOTHA, 125.0f);
		me->DespawnCreaturesInArea(NPC_CLOTTED_CORRUPTION, 125.0f);
		me->RemoveAllAreaTriggers();
	}

	void KilledUnit(Unit* victim) override
	{
		if (victim->IsPlayer())
			if (roll_chance_f(15))
				Talk(SAY_KILL);
	}

	void SpellHit(Unit* unit, const SpellInfo* spellInfo)
	{
		if (spellInfo->Id == SPELL_EYE_OF_NZOTH)
		{
			me->RemoveAura(SPELL_EYE_OF_NZOTH);
			uint64 GetHit = 59147.63f;
			me->SetHealth(me->GetHealth() + GetHit);
		}
	}

	void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
	{
		if (spellInfo->Id == SPELL_EYE_OF_NZOTH)
		{
			switch (target->GetEntry())
			{
			case NPC_BLOOD_OF_NYALOTHA:
			case NPC_ORGAN_OF_CORRUPTION:
			case NPC_CLOTTED_CORRUPTION:
				target->RemoveAura(SPELL_EYE_OF_NZOTH);
				break;
			}
		}
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_ENERGY_GAIN:
			me->ModifyPower(POWER_ENERGY, +1);
			if (me->GetPower(POWER_ENERGY) != 100)
				events.Repeat(1s);
			break;

		case EVENT_EYE_OF_NZOTH:
			Talk(SAY_EYE_OF_NZOTH);
			if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
			{
				if (Player* player = target->ToPlayer())
				{	
					me->SetFacingToObject(player, true);
					me->CastSpell(player, SPELL_EYE_OF_NZOTH, false);
				}
			}
			events.Repeat(25s);
			break;

		case EVENT_CORRUPTORS_GAZE:
			Talk(SAY_CORRUPTORS_GAZE);;
			events.Repeat(35s);
			break;

		case EVENT_SUMMON_ORGANS:			
			me->SummonCreature(NPC_ORGAN_OF_CORRUPTION, organ_of_corruption_left, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_ORGAN_OF_CORRUPTION, organ_of_corruption_mid, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_ORGAN_OF_CORRUPTION, organ_of_corruption_right, TEMPSUMMON_MANUAL_DESPAWN);			
			break;

		case EVENT_PREPARE_ORGANS:
		{
			std::list<Creature*> organsList;
			me->GetCreatureListWithEntryInGrid(organsList, NPC_ORGAN_OF_CORRUPTION, 1500.0f);
			for (auto& organs : organsList)
			{
				organs->SetPower(POWER_ENERGY, 100);
				organs->CastSpell(me->GetRandomNearPosition(40.0f), SPELL_PUMPING_BLOOD_MISSILE, false);
			}
			break;
		}

		case EVENT_TOUCH_OF_THE_CORRUPTOR:
		{
			UnitList tarlist;
			SelectTargetList(tarlist, 2, SELECT_TARGET_RANDOM, 150.0f);
			for (Unit* targets : tarlist)
			{
				me->CastSpell(nullptr, SPELL_TOUCH_OF_THE_CORRUPTOR, false);
				me->GetScheduler().Schedule(3100ms, [this, targets](TaskContext context)
				{
					me->CastSpell(nullptr, SPELL_TOUCH_OF_THE_CORRUPTOR_MIND_CONTROL, true);
				});
			}
			events.Repeat(45s);
			break;
		}

		case EVENT_CURSED_BLOOD:
			if (IsMythic())
			{
				UnitList tarlist;
				SelectTargetList(tarlist, 7, SELECT_TARGET_RANDOM, 150.0f);
				for (Unit* targets : tarlist)
				{
					me->AddAura(SPELL_CURSED_BLOOD, targets);
				}
			}
			else
			{
				UnitList tarlist;
				SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 150.0f);
				for (Unit* targets : tarlist)
				{
					me->AddAura(SPELL_CURSED_BLOOD, targets);
				}
			}
			events.Repeat(18s);
			break;

		case EVENT_CLOTTED_CORRUPTION:
			for (uint8 i = 0; i < 3; i++)
			{
				me->SummonCreature(NPC_CLOTTED_CORRUPTION, me->GetRandomNearPosition(50.0f), TEMPSUMMON_MANUAL_DESPAWN);
			}
			break;

		case EVENT_BERSERK:
			me->CastSpell(nullptr, SPELL_BERSERK, true);
			break;
		}
	}

	void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)  override
	{
		if (summon->GetEntry() == NPC_ORGAN_OF_CORRUPTION)
		{
			organDied++;
			events.Reset();			
			me->ClearUnitState(UNIT_STAND_STATE_SUBMERGED);
			me->SetReactState(REACT_AGGRESSIVE);
			me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
			me->RemoveUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
			events.ScheduleEvent(EVENT_CURSED_BLOOD, 3s);
			events.ScheduleEvent(EVENT_EYE_OF_NZOTH, 5s);
			events.ScheduleEvent(EVENT_CORRUPTORS_GAZE, 12s);
			events.ScheduleEvent(EVENT_CURSED_BLOOD, 18s);
			//if (IsHeroic() || IsMythic())
				//events.ScheduleEvent(EVENT_TOUCH_OF_THE_CORRUPTOR, 46s);
		}
	}

	void JustDied(Unit* /*killer*/ override)
	{
		_JustDied();
		instance->DoModifyPlayerCurrencies(CURRENCY_ECHOES_OF_NYALOTHA, 16);
		CleanEncounter(instance, me);
	}
};

//158343
struct npc_organ_of_corruption : public ScriptedAI
{
	npc_organ_of_corruption(Creature* c) : ScriptedAI(c) {
		SetCombatMovement(false);
		me->SetReactState(REACT_PASSIVE);
	}

	void Reset() override
	{
		ScriptedAI::Reset();
		me->SetPowerType(POWER_ENERGY);
		me->SetMaxPower(POWER_ENERGY, 100);
		me->SetPower(POWER_ENERGY, 100);
		me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);		
	}

	void IsSummonedBy(Unit* summoner) override
	{
		if (instance)
		{
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
			me->CastSpell(nullptr, SPELL_PUMPING_BLOOD_MISSILE, false);
		}
	}

	void JustDied(Unit* /*killer*/) override
	{
		if (Creature* ilgynoth = me->FindNearestCreature(NPC_ILGYNOTH, 150.0f, true))
		{
			ilgynoth->AI()->Talk(SAY_ORGAN_SLAIN);
			std::list<Creature*> organsList;
			ilgynoth->GetCreatureListWithEntryInGrid(organsList, 150.0f);
			for (auto& organs : organsList)
			{
				if (organs->IsAlive())
				{
					organs->SetHealth(organs->GetMaxHealth());
					organs->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
				}
			}
		}
		if (instance)
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
	}
};

//159514
struct npc_blood_of_nyalotha : public ScriptedAI
{
	npc_blood_of_nyalotha(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->AddAura(SPELL_RECURRING_NIGHTMARE_TRIGGER);
		me->SetWalk(true);
		me->GetSpeed(MOVE_WALK);
		if (instance)
		{
			me->AI()->DoZoneInCombat(nullptr);
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
				me->AddThreat(target, 1000.0f);
		}
	}

	void SpellHit(Unit* unit, const SpellInfo* spellInfo) 
	{ 
		if (spellInfo->Id == SPELL_ABSORBING_CHARGE)
			unit->KillSelf();
	}

	void JustDied(Unit* /*killer*/) override
	{
		me->CastSpell(nullptr, SPELL_HEMORRHAGE, true);
	}
};

//311159
class aura_cursed_blood : public AuraScript
{
	PrepareAuraScript(aura_cursed_blood);

	void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
	{
		Unit* target = GetTarget();
		Unit* caster = GetCaster();
		if (!caster || !target)
			return;

		caster->CastSpell(target, SPELL_CURSED_BLOOD_EPLOSION, true);
	}

	void Register() override
	{
		OnEffectRemove += AuraEffectRemoveFn(aura_cursed_blood::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
	}
};

//163678
struct npc_clotted_corruption : public ScriptedAI
{
	npc_clotted_corruption(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
	}

	void EnterCombat(Unit* /*killer*/) override
	{
		events.ScheduleEvent(EVENT_ABSORBING_CHARGE, 3s);
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_ABSORBING_CHARGE:
			if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 150.0f, true))
				me->CastSpell(target, SPELL_ABSORBING_CHARGE, false);
		}
	}
};

//311367
class aura_touch_of_the_corruptor : public AuraScript
{
	PrepareAuraScript(aura_touch_of_the_corruptor);

	void PeriodicTick(AuraEffect const* /*aurEff*/)
	{
		Unit* target = GetTarget();
		Unit* caster = GetCaster();
		if (!caster || !target)
			return;

		if (target->HealthBelowPct(31) && target->HasAura(311367))
			target->RemoveAura(311367);
	}

	void Register() override
	{
		OnEffectPeriodic += AuraEffectPeriodicFn(aura_touch_of_the_corruptor::PeriodicTick, EFFECT_4, SPELL_AURA_PERIODIC_DUMMY);
	}
};

void AddSC_ilgynoth_n()
{
	RegisterCreatureAI(ilgynoth_n);
	RegisterCreatureAI(npc_organ_of_corruption);
	RegisterCreatureAI(npc_blood_of_nyalotha);
	RegisterAuraScript(aura_cursed_blood);
	RegisterCreatureAI(npc_clotted_corruption);
	RegisterAuraScript(aura_touch_of_the_corruptor);
};
