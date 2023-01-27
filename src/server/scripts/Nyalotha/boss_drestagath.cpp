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

};

enum Spells
{
	SPELL_ABERRANT_REGENERATION = 308373,
	SPELL_VOID_INFUSED_ICHOR_MISSILE = 310964,
	SPELL_VOID_INFUSED_ICHOR_CREATE_AT = 310968,
	SPELL_VOID_INFUSED_ICHOR_BUFF = 308377,
	SPELL_THROES_OF_AGONY = 308941,
	SPELL_DISMEMBERMENT = 308661,
	SPELL_VOLATILE_SEED = 310277,
	SPELL_VOLATILE_DETONATION = 310288,
	SPELL_VOID_GRIP = 313280,
	SPELL_VOID_GRIP_STUN,
	SPELL_ENTROPIC_CRASH = 310329,
	SPELL_VOID_GLARE_DAMAGE = 310406,
	SPELL_VOID_GLARE_DUMMY = 310396, //dummy trigger
	SPELL_VOID_GLARE_APPLY_AURA_AT = 310404, // visual
	SPELL_MUTTERING_INSANITY_PERIODIC = 310358,
	SPELL_MUTTERING_OF_INSANITY_SLOW = 310359,
	SPELL_UNLEASHED_INSANITY = 310361,
	//Tentacle of Drestagath
	SPELL_CRUSHING_SLAM = 310614,
	SPELL_ENTROPIC_CRASH_TENTACLE = 310348,
	SPELL_REALITY_TEAR_MISSILE = 274849, // not correct, because we have no at
	SPELL_REALITY_TEAR_CREATE_AT_TENTACLE = 315766,
	//Eye of Drestagath
	SPELL_MIND_FLAY = 310552,
	SPELL_ERRANT_BLAST = 308953,
	//SPELL_ERRANT_BLAST_MISSILE = 308957,
	SPELL_ERRANT_BLAST_MISSILE = 315401,
	SPELL_ERRANT_BLAST_CREATE_AT = 318901,
	//Maw of Drestagath
	SPELL_ACID_SPLASH_MISSILE = 310580,
	SPELL_SPINE_ERUPTION = 310078,
	SPELL_SPINE_ERUPTION_SMALL_MISSILE = 310079,
	SPELL_SPINE_ERUPTION_MED_MISSILE = 310080,
	SPELL_SPINE_ERUPTION_BIG_MISSILE = 310081,
	//Heroic
	SPELL_UMBRAL_AVERSION = 317001,
	SPELL_VOID_MIASMA_APPLY_AT = 310478,
	SPELL_VOID_MISMA_AT_DAMAGE = 310499,
	SPELL_MUTTERING_OF_BETRAYAL_TRIGGER= 310561,
	SPELL_MUTTERING_OF_BETRAYAL_AURA = 310563,
	SPELL_BETRAYED = 310567,
	//Mythic
	SPELL_BERSERK = 26662,
};

enum Events
{
	EVENT_DRESTAGATH_ENERGY = 1,
	EVENT_VOLATILE_SEED,
	EVENT_ENTROPIC_CRASH,
	EVENT_MUTTERINGS_OF_INSANITY,
	EVENT_VOID_GLARE,
	EVENT_BERSERK,
	EVENT_WAVE_ONE,
	EVENT_WAVE_TWO,
	EVENT_WAVE_THREE,
	EVENT_WAVE_FOUR,
	EVENT_WAVE_FIVE,
	//Adds
	EVENT_CRUSHING_SLAM,
	EVENT_MIND_FLAY,
	EVENT_ACID_SPLASH,
};

//157602
struct boss_drestagath : public BossAI
{
	boss_drestagath(Creature* creature) : BossAI(creature, DATA_DRESTAGATH) 
	{ 
		SetCombatMovement(false);
		me->SetFlying(true);
	}

	void Reset() override
	{
		BossAI::Reset();
		me->SetPowerType(POWER_ENERGY);
		me->SetMaxPower(POWER_ENERGY, 100);
		me->SetPower(POWER_ENERGY, 0);
		me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);
		me->CastSpell(nullptr, SPELL_ABERRANT_REGENERATION, true);
		if (IsMythic())
		{
			me->SummonCreature(NPC_EYE_OF_DRESTAGATH, -530.989f, 213.483f, -484.662f, 4.833f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_EYE_OF_DRESTAGATH, -505.739f, 214.786f, -484.683f, 4.766f, TEMPSUMMON_MANUAL_DESPAWN);
		}
		else
			me->SummonCreature(NPC_EYE_OF_DRESTAGATH, -530.989f, 213.483f, -484.662f, 4.833f, TEMPSUMMON_MANUAL_DESPAWN);
	}

	void EnterCombat(Unit* /*who*/) override
	{
		_EnterCombat();
		events.ScheduleEvent(EVENT_DRESTAGATH_ENERGY, 100ms);
		events.ScheduleEvent(EVENT_VOLATILE_SEED, 3s);
		events.ScheduleEvent(EVENT_ENTROPIC_CRASH, 15s);
		events.ScheduleEvent(EVENT_MUTTERINGS_OF_INSANITY, 30s);
		events.ScheduleEvent(EVENT_VOID_GLARE, 45s);
		events.ScheduleEvent(EVENT_WAVE_ONE, 17s);
		events.ScheduleEvent(EVENT_WAVE_TWO, 110s);
		events.ScheduleEvent(EVENT_WAVE_THREE, 200s);
		events.ScheduleEvent(EVENT_WAVE_FOUR, 290s);
		events.ScheduleEvent(EVENT_WAVE_FIVE, 380s);
		std::list<Creature*> eyeList;
		me->GetCreatureListWithEntryInGrid(eyeList, NPC_EYE_OF_DRESTAGATH, 125.0f);
		for (auto& eyes : eyeList)
		{
			eyes->AI()->DoZoneInCombat(nullptr);
		}
		if (IsMythic())
			events.ScheduleEvent(EVENT_BERSERK, 10min);
	}

	void JustSummoned(Creature* summon) override
	{
		summon->AI()->DoZoneInCombat(nullptr);
	}

	void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
	{
		switch (summon->GetEntry())
		{
		case NPC_TENTACLE_OF_DRESTAGATH:
		case NPC_EYE_OF_DRESTAGATH:
		case NPC_MAW_OF_DRESTAGATH:
			if (Creature* drestagath = me->FindNearestCreature(NPC_DRESTAGATH, 125.0f, true))
				drestagath->AddAura(SPELL_DISMEMBERMENT);
			if (IsMythic())
			{
				std::list<Creature*> agonyList;
				me->GetCreatureListWithEntryInGrid(agonyList, NPC_TENTACLE_OF_DRESTAGATH, 125.0f);
				me->GetCreatureListWithEntryInGrid(agonyList, NPC_EYE_OF_DRESTAGATH, 125.0f);
				me->GetCreatureListWithEntryInGrid(agonyList, NPC_MAW_OF_DRESTAGATH, 125.0f);
				for (auto& agonyCreatures : agonyList)
				{
					switch (agonyCreatures->GetEntry())
					{
					case NPC_TENTACLE_OF_DRESTAGATH:
						agonyCreatures->AI()->DoCastRandom(SPELL_REALITY_TEAR_MISSILE, 100.0f, true);
						break;
					case NPC_EYE_OF_DRESTAGATH:
					{
						std::list<Player*> playerList;
						me->GetPlayerListInGrid(playerList, 100.0f);
						for (auto& targets : playerList)
						{
							agonyCreatures->CastSpell(targets->GetPositionX() + 10.0f, SPELL_ERRANT_BLAST_MISSILE, true);
							agonyCreatures->CastSpell(targets->GetPositionX() + 10.0f, SPELL_ERRANT_BLAST_CREATE_AT, true);
						}
						break;
					}
					case NPC_MAW_OF_DRESTAGATH:
						uint32 spineEruptions = urand(1, 3);
						uint32 spellId = 0;
						switch (spineEruptions)
						{
						case 1:
							spellId = SPELL_SPINE_ERUPTION_SMALL_MISSILE;
							agonyCreatures->AI()->DoCastSelf(spellId, true);
							break;
						case 2:
							spellId = SPELL_SPINE_ERUPTION_MED_MISSILE;
							agonyCreatures->AI()->DoCastSelf(spellId, true);
							break;
						case 3:
							break;
							spellId = SPELL_SPINE_ERUPTION_BIG_MISSILE;
							agonyCreatures->AI()->DoCastSelf(spellId, true);
						}
						break;
					}
				}
			}
		}
	}

	void ExecuteEvent(uint32 eventId) override
	{
		if (me->GetPower(POWER_ENERGY) == 100)
		{
			me->SetPower(POWER_ENERGY, 0);
			me->AddAura(SPELL_THROES_OF_AGONY);
			std::list<Creature*> agonyList;
			me->GetCreatureListWithEntryInGrid(agonyList, NPC_TENTACLE_OF_DRESTAGATH, 125.0f);
			me->GetCreatureListWithEntryInGrid(agonyList, NPC_EYE_OF_DRESTAGATH, 125.0f);
			me->GetCreatureListWithEntryInGrid(agonyList, NPC_MAW_OF_DRESTAGATH, 125.0f);
			for (auto& agonyCreatures : agonyList)
			{
				switch (agonyCreatures->GetEntry())
				{
				case NPC_TENTACLE_OF_DRESTAGATH:
					agonyCreatures->AI()->DoCastRandom(SPELL_REALITY_TEAR_MISSILE, 100.0f, true);
					break;
				case NPC_EYE_OF_DRESTAGATH:
				{
					std::list<Player*> playerList;
					me->GetPlayerListInGrid(playerList, 100.0f);
					for (auto& targets : playerList)
					{
						agonyCreatures->CastSpell(targets->GetPositionX() + 10.0f, SPELL_ERRANT_BLAST_MISSILE, true);
						agonyCreatures->CastSpell(targets->GetPositionX() + 10.0f, SPELL_ERRANT_BLAST_CREATE_AT, true);
					}
					break;
				}
				case NPC_MAW_OF_DRESTAGATH:
					uint32 spineEruptions = urand(1, 3);
					uint32 spellId = 0;
					switch (spineEruptions)
					{
					case 1:
						spellId = SPELL_SPINE_ERUPTION_SMALL_MISSILE;
						agonyCreatures->AI()->DoCastSelf(spellId, true);
						break;
					case 2:
						spellId = SPELL_SPINE_ERUPTION_MED_MISSILE;
						agonyCreatures->AI()->DoCastSelf(spellId, true);
						break;
					case 3:
						break;
						spellId = SPELL_SPINE_ERUPTION_BIG_MISSILE;
						agonyCreatures->AI()->DoCastSelf(spellId, true);
					}
					break;
				}
			}
		}
		switch (eventId)
		{
		case EVENT_DRESTAGATH_ENERGY:
			me->ModifyPower(POWER_ENERGY, +1);
			events.Repeat(1s);
			break;

		case EVENT_VOLATILE_SEED:
			if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
				me->CastSpell(target, SPELL_VOLATILE_SEED, false);
			events.Repeat(18s);
			break;

		case EVENT_ENTROPIC_CRASH:
			me->CastSpell(SPELL_ENTROPIC_CRASH, false);
			events.Repeat(30s);
			break;

		case EVENT_VOID_GLARE:
		{
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
			{
				me->SetFacingToObject(target, true);
				me->CastSpell(nullptr, SPELL_VOID_GLARE_DUMMY, false);
				me->AddAura(SPELL_VOID_GLARE_DAMAGE, target);
			}
			std::list<Creature*> eyeList;
			me->GetCreatureListWithEntryInGrid(eyeList, NPC_EYE_OF_DRESTAGATH, 150.0f);
			for (auto& eyes : eyeList)
			{				
				if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
				{
					eyes->CastSpell(nullptr, SPELL_VOID_GLARE_DUMMY, false);
					eyes->AddAura(SPELL_VOID_GLARE_DAMAGE, target);
				}				
			}
			events.Repeat(55s);
			break;
		}

		case EVENT_WAVE_ONE:
			me->SummonCreature(NPC_EYE_OF_DRESTAGATH, -537.979f, 249.764f, -484.515f, 4.476f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_TENTACLE_OF_DRESTAGATH, -539.835f, 230.644f, -484.739f, 5.117f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_TENTACLE_OF_DRESTAGATH, -488.273f, 242.526f, -484.631f, 5.026f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_TENTACLE_OF_DRESTAGATH, -475.170f, 183.860f, -484.911f, 1.679f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_MAW_OF_DRESTAGATH, -551.022f, 183.074f, -484.938f, 1.690f, TEMPSUMMON_MANUAL_DESPAWN);
			break;

		case EVENT_WAVE_TWO:
			me->SummonCreature(NPC_MAW_OF_DRESTAGATH, -517.787f, 193.074f, -484.684f, 1.568f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_MAW_OF_DRESTAGATH, -494.643f, 206.261f, -484.450f, 1.745f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_MAW_OF_DRESTAGATH, -527.579f, 265.148f, -484.951f, 4.722f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_EYE_OF_DRESTAGATH, -503.748f, 181.565f, -484.576f, 1.681f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_TENTACLE_OF_DRESTAGATH, -528.391f, 173.251f, -484.553f, 1.426f, TEMPSUMMON_MANUAL_DESPAWN);
			break;

		case EVENT_WAVE_THREE:
			me->SummonCreature(NPC_EYE_OF_DRESTAGATH, -540.627f, 230.830f, -484.735f, 4.825f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_EYE_OF_DRESTAGATH, -550.973f, 188.269f, -484.962f, 0.532f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_EYE_OF_DRESTAGATH, -506.552f, 181.430f, -484.615f, 1.868f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_TENTACLE_OF_DRESTAGATH, -479.870f, 227.161f, -484.547f, 3.375f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_MAW_OF_DRESTAGATH, -546.596f, 171.310f, -484.794f, 0.199f, TEMPSUMMON_MANUAL_DESPAWN);
			break;

		case EVENT_WAVE_FOUR:
			me->SummonCreature(NPC_MAW_OF_DRESTAGATH, -558.856f, 239.233f, -484.629f, 5.773f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_MAW_OF_DRESTAGATH, -500.945f, 212.461f, -484.682f, 2.643f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_EYE_OF_DRESTAGATH, -503.177f, 185.026f, -484.567f, 1.650f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_EYE_OF_DRESTAGATH, -544.403f, 225.410f, -484.636f, 5.732f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_TENTACLE_OF_DRESTAGATH, -561.334f, 181.176f, -484.936f, 0.561f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_TENTACLE_OF_DRESTAGATH, -518.446f, 275.674f, -484.946f, 4.590f, TEMPSUMMON_MANUAL_DESPAWN);
			break;

		case EVENT_WAVE_FIVE:
			me->SummonCreature(NPC_MAW_OF_DRESTAGATH, -473.772f, 179.005f, -484.926f, 1.344f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_MAW_OF_DRESTAGATH, -563.086f, 202.996f, -484.894f, 0.023f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_EYE_OF_DRESTAGATH, -568.914f, 188.183f, -484.989f, 0.420f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_EYE_OF_DRESTAGATH, -492.998f, 233.653f, -484.702f, 3.734f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_TENTACLE_OF_DRESTAGATH, -493.332f, 221.747f, -484.632f, 3.760f, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_TENTACLE_OF_DRESTAGATH, -515.428f, 196.642f, -484.751f, 1.094f, TEMPSUMMON_MANUAL_DESPAWN);
			break;

		case EVENT_BERSERK:
			me->CastSpell(nullptr, SPELL_BERSERK, true);
			break;
		}
	}

	void EnterEvadeMode(EvadeReason /*why*/) override
	{
		CleanupEncounter(instance, me);
		_DespawnAtEvade();
	}

	void JustDied(Unit* unit) override
	{
		_JustDied();
		CleanupEncounter(instance, me);
		instance->DoModifyPlayerCurrencies(CURRENCY_ECHOES_OF_NYALOTHA, 16);
	}

	void CleanupEncounter(InstanceScript* instance, Creature* me)
	{
		_JustReachedHome();
		me->DespawnCreaturesInArea(NPC_EYE_OF_DRESTAGATH, 125.0f);
		me->DespawnCreaturesInArea(NPC_TENTACLE_OF_DRESTAGATH, 125.0f);
		me->DespawnCreaturesInArea(NPC_MAW_OF_DRESTAGATH, 125.0f);
		me->RemoveAllAreaTriggers();
	}
};

//157612
struct npc_eye_of_drestagath : public ScriptedAI
{
	npc_eye_of_drestagath(Creature* c) : ScriptedAI(c) 
	{ 
		SetCombatMovement(false);
	}

	void Reset() override
	{
		ScriptedAI::Reset();
		me->SetPowerType(POWER_ENERGY);
		me->SetMaxPower(POWER_ENERGY, 100);
		me->SetPower(POWER_ENERGY, 0);
		me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);
	}

	void EnterCombat(Unit* /*who*/) override
	{
		if (instance)
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
		events.ScheduleEvent(EVENT_MIND_FLAY, 3s);
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_MIND_FLAY:
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
				me->CastSpell(target, SPELL_MIND_FLAY, false);
			events.Repeat(6s);
			break;
		}
	}

	void JustDied(Unit* /*killer*/) override
	{
		if (instance)
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
	}
};

//157614
struct npc_tentacle_of_drestagath : public ScriptedAI
{
	npc_tentacle_of_drestagath(Creature* c) : ScriptedAI(c)
	{
		SetCombatMovement(false);
	}

	void Reset() override
	{
		ScriptedAI::Reset();
		me->SetPowerType(POWER_ENERGY);
		me->SetMaxPower(POWER_ENERGY, 100);
		me->SetPower(POWER_ENERGY, 0);
		me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);
		if (IsHeroic() || IsMythic())
			me->AddAura(SPELL_VOID_MIASMA_APPLY_AT);
	}

	void MoveInLineOfSight(Unit* unit) override
	{
		if (!IsHeroic() || !IsMythic())
			return;

		if (!unit->IsPlayer())
			return;

		if (unit->GetDistance2d(me) <= 10.0f && !unit->HasAura(SPELL_VOID_MISMA_AT_DAMAGE))
			me->AddAura(SPELL_VOID_MISMA_AT_DAMAGE, unit);

		if (unit->GetDistance2d(me) > 10.0f && unit->HasAura(SPELL_VOID_MISMA_AT_DAMAGE))
			unit->RemoveAura(SPELL_VOID_MISMA_AT_DAMAGE);
	}

	void EnterCombat(Unit* /*who*/) override
	{
		if (instance)
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
		events.ScheduleEvent(EVENT_CRUSHING_SLAM, 3s);
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_CRUSHING_SLAM:
			if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 5.0f, true))
				me->CastSpell(target, SPELL_CRUSHING_SLAM, false);
			events.Repeat(15s);
			break;
		}
	}

	void JustDied(Unit* /*killer*/) override
	{
		if (instance)
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
	}
};

//157613
struct npc_maw_of_drestagath : public ScriptedAI
{
	npc_maw_of_drestagath(Creature* c) : ScriptedAI(c)
	{
		SetCombatMovement(false);
	}

	void Reset() override
	{
		ScriptedAI::Reset();
		me->SetPowerType(POWER_ENERGY);
		me->SetMaxPower(POWER_ENERGY, 100);
		me->SetPower(POWER_ENERGY, 0);
		me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);
		if (IsHeroic() || IsMythic())
			me->AddAura(SPELL_MUTTERING_OF_BETRAYAL_TRIGGER);
	}

	void MoveInLineOfSight(Unit* unit) override
	{
		if (me->HasAura(SPELL_MUTTERING_OF_BETRAYAL_TRIGGER && unit->IsPlayer() && unit->GetDistance2d(me) <= 10.0f))
		{
			if (Aura* muttering = unit->GetAura(SPELL_MUTTERING_OF_BETRAYAL_AURA))
			{
				if (muttering->GetStackAmount() < 4)
					me->AddAura(SPELL_MUTTERING_OF_BETRAYAL_AURA, unit);
				if (muttering->GetStackAmount() == 4)
				{
					unit->RemoveAurasDueToSpell(SPELL_MUTTERING_OF_BETRAYAL_AURA);
					me->AddAura(SPELL_BETRAYED, unit);
				}
			}
		}
	}

	void EnterCombat(Unit* /*who*/) override
	{
		if (instance)
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
		events.ScheduleEvent(EVENT_ACID_SPLASH, 3s);
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_ACID_SPLASH:
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
				me->CastSpell(target, SPELL_ACID_SPLASH_MISSILE, false);
			events.Repeat(3500ms, 4000ms);
			break;
		}
	}

	void JustDied(Unit* /*killer*/) override
	{
		if (instance)
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
	}
};

//310358 
class aura_mutterings_of_insanity : public AuraScript
{
	PrepareAuraScript(aura_mutterings_of_insanity);

	void OnTick(AuraEffect const* /*aurEff*/)
	{
		if (Unit* target = GetTarget())
		{
			if (GetTarget()->HasAura(SPELL_MUTTERING_OF_INSANITY_SLOW))
				GetCaster()->CastSpell(target, SPELL_MUTTERING_OF_INSANITY_SLOW, true);
		}
	}

	void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
	{
		Unit* target = GetTarget();
		Unit* caster = GetCaster();
		if (!caster || !target)
			return;

		if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
			caster->CastSpell(target, SPELL_UNLEASHED_INSANITY, true);
	}

	void Register() override
	{
		OnEffectPeriodic += AuraEffectPeriodicFn(aura_mutterings_of_insanity::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
		OnEffectRemove += AuraEffectRemoveFn(aura_mutterings_of_insanity::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
	}
};

//310277 
class aura_volatile_seed : public AuraScript
{
	PrepareAuraScript(aura_volatile_seed);

	void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
	{
		Unit* target = GetTarget();
		Unit* caster = GetCaster();
		if (!caster || !target)
			return;

		if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
			caster->CastSpell(target, SPELL_VOLATILE_DETONATION, true);
	}

	void Register() override
	{
		OnEffectRemove += AuraEffectRemoveFn(aura_volatile_seed::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
	}
};

void AddSC_drestagath()
{
	RegisterCreatureAI(boss_drestagath);
	RegisterCreatureAI(npc_eye_of_drestagath);
	RegisterCreatureAI(npc_tentacle_of_drestagath);
	RegisterCreatureAI(npc_maw_of_drestagath);
	RegisterAuraScript(aura_mutterings_of_insanity);
	RegisterAuraScript(aura_volatile_seed);
};
