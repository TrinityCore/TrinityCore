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
	SAY_KAZIR_SPAWN_ACIDIC = 0,
	SAY_KAZIR_HIVEMIND_CONTROL,
	SAY_KAZIR_SHADOWS,
	SAY_KAZIR_BLISTER,
	SAY_TEKRIS_FALL = 0,
	SAY_TEKRIS_GIVE,
	SAY_TEKRIS_HIVE_CONTROL,
	SAY_TEKRIS_ECHOING_VOID,
	SAY_TEKRIS_VOID,
	SAY_TEKRIS_KILL
};

enum Spells
{
	SPELL_HIVEMIND_ENERGY_MANAGEMENT = 313732,
	SPELL_TEKRIS_HIVEMIND_CONTROL = 307213,
	SPELL_TEKRIS_HIVEMIND_CONTROL_DAMAGE_REDUCTION = 315884,
	SPELL_KAZIR_HIVEMIND_CONTROL = 307201,
	SPELL_KAZIR_HIVEMIND_CONTROL_DAMAGE_REDUCTION = 315889,
	SPELL_SHADOW_VEIL = 307202,
	SPELL_VOID_INFUSION = 307334,//Any adds that spawn during Tek'ris's Hivemind Control will gain Void Infusion every second.
	SPELL_REGENERATION = 307227,
	SPELL_REGENERATION_HEAL = 306974,//Any adds spawned during Ka'zir's Hivemind Control gain Regeneration.
	SPELL_DARK_RECONSTRUCTION = 307569,
	SPELL_NULLIFICATION_BLAST = 307968,
	SPELL_NULLIFICATIOB_BLAST_DEBUFF = 313460,
	SPELL_ECHOING_VOID = 307232,
	SPELL_ECHOING_VOID_PULSE = 317022,
	SPELL_SPAWN_ACIDIC_AQUIR = 313441,
	SPELL_SPAWN_ACIDIC_AQUIR_SUMMON = 310340, //npc 159173
	SPELL_ACIDIC_AQUIR_VISUAL = 310343,
	SPELL_CORROSION = 313461,
	SPELL_MIND_NUMBING_NOVA = 313652,
	SPELL_MIND_NUMBING_TOXIN = 314593,
	//Aqir Darter
	SPELL_PSIONIC_RESONANCE = 307217,
	//Ravager
	SPELL_RAVAGE = 315311,
	//Heroic
	SPELL_DEVOURING_FRENZY_VISUAL = 310402,
	SPELL_DEVOURING_FRENZY_DAMAGE = 310403,
	SPELL_DEVOURING_FRENZY_MOD_DAMAGE = 313720,
	SPELL_ACIDIC_BLOOD_CREATE_AT = 313671, //despawn after 60s
	SPELL_ACIDIC_BLOOD_AT_DAMAGE = 307560,
	SPELL_ACCELERATED_EVOLUTION_MISSILE = 308227,
	SPELL_ACCELERATED_EVOLUTION = 307637,
	SPELL_VOLATILE_ERUPTION = 307582,
	//Mythic
	SPELL_ACID_POOL_AT_DAMAGE = 316049,
	SPELL_ENTROPIC_ECHO_MISSILE = 313689,
	SPELL_ENTROPIC_ECHO_DAMAGE = 313692,	
};

enum Events
{
	EVENT_POWER_GAIN = 1,
	EVENT_AQIR_DRONES,
	EVENT_AQIR_DARTERS,
	EVENT_NULLIFICATION_BLAST,
	EVENT_ECHOING_VOID,
	EVENT_SPAWN_ACIDIC_AQIR,
	EVENT_MIND_NUMBING_NOVA,
	//Heroic
	EVENT_DEVOURING_FRENZY,
	EVENT_ACCELERATED_EVOLUTION,
	EVENT_VOLATILE_ERUPTION,
	//Mythic
};

enum Actions
{
	ACTION_TEKRIS_CONTROL,
	ACTION_KAZIR_CONTROL
};

const Position middle_of_the_room = { -290.083f, 227.152f, -294.551f, 2.512f };

//157253,157254
struct boss_hivemind : public BossAI
{
	boss_hivemind(Creature* creature) : BossAI(creature, DATA_HIVEMIND) { }

private:
	uint8 hivemindControlTekris;
	uint8 hivemindControlKazir;
	bool darkReconstruction;

	void Reset() override
	{
		switch (me->GetEntry())
		{
		case NPC_KAZIR:
			BossAI::Reset();
			me->SetPowerType(POWER_ENERGY);
			me->SetMaxPower(POWER_ENERGY, 100);
			me->SetPower(POWER_ENERGY, 0);
			me->AddAura(AURA_OVERRIDE_POWER_COLOR_ORANGE);
			me->NearTeleportTo(me->GetHomePosition());
			if (Creature* tekris = me->FindNearestCreature(NPC_TEKRIS, 100.0f, false))
				if (tekris->isDead())
					tekris->ForcedDespawn();
			break;

		case NPC_TEKRIS:
			BossAI::Reset();
			me->SetPowerType(POWER_ENERGY);
			me->SetMaxPower(POWER_ENERGY, 100);
			me->SetPower(POWER_ENERGY, 0);
			me->AddAura(AURA_OVERRIDE_POWER_COLOR_ORANGE);
			me->NearTeleportTo(me->GetHomePosition());
			if (Creature* kazir = me->FindNearestCreature(NPC_TEKRIS, 100.0f, false))
				if (kazir->isDead())
					kazir->ForcedDespawn();
			break;
		}
	}

	void MoveInLineOfSight(Unit* unit) override
	{
		switch (me->GetEntry())
		{
		case NPC_TEKRIS:
			if (unit->GetEntry() == NPC_KAZIR && unit->GetDistance2d(me) <= 20.0f && me->IsInCombat())
			{
				if (!unit->HasAura(SPELL_SHADOW_VEIL))
					unit->AddAura(SPELL_SHADOW_VEIL);

				if (!me->HasAura(SPELL_SHADOW_VEIL))
					me->AddAura(SPELL_SHADOW_VEIL);
			}
			if (unit->GetEntry() == NPC_KAZIR && unit->GetDistance2d(me) > 20.0f && me->IsInCombat())
			{
				if (unit->HasAura(SPELL_SHADOW_VEIL))
					unit->RemoveAura(SPELL_SHADOW_VEIL);

				if (me->HasAura(SPELL_SHADOW_VEIL))
					me->RemoveAura(SPELL_SHADOW_VEIL);
			}
			break;
		}
	}

	void EnterCombat(Unit* /*who*/) override
	{
		switch (me->GetEntry())
		{
		case NPC_KAZIR:
			_EnterCombat();
			events.ScheduleEvent(EVENT_POWER_GAIN, 1s);
			darkReconstruction = false;
			events.ScheduleEvent(EVENT_SPAWN_ACIDIC_AQIR, 45s);
			events.ScheduleEvent(EVENT_MIND_NUMBING_NOVA, 8s, 12s);
			events.ScheduleEvent(EVENT_VOLATILE_ERUPTION, 87s);
			if (Creature* tekris = me->FindNearestCreature(NPC_TEKRIS, 100.0f, true))
				if (!tekris->IsInCombat())
					tekris->AI()->DoZoneInCombat(nullptr);
			break;

		case NPC_TEKRIS:
			_EnterCombat();
			events.ScheduleEvent(EVENT_POWER_GAIN, 1s);
			me->GetScheduler().Schedule(3s, [this](TaskContext /*context*/)
			{
				me->AI()->DoAction(ACTION_TEKRIS_CONTROL);
			});
			darkReconstruction = false;
			events.ScheduleEvent(EVENT_AQIR_DRONES, 10s);
			events.ScheduleEvent(EVENT_AQIR_DARTERS, 20s);
			events.ScheduleEvent(EVENT_ECHOING_VOID, 26s);
			events.ScheduleEvent(EVENT_NULLIFICATION_BLAST, 30s);
			if (IsHeroic() || IsMythic())
				events.ScheduleEvent(EVENT_ACCELERATED_EVOLUTION, 15s);
			if (Creature* kazir = me->FindNearestCreature(NPC_KAZIR, 100.0f, true))
				if (!kazir->IsInCombat())
					kazir->AI()->DoZoneInCombat(nullptr);
			break;
		}
	}

	void DoAction(int32 action) override
	{
		switch (action)
		{
		case ACTION_TEKRIS_CONTROL:
			Talk(SAY_TEKRIS_HIVE_CONTROL);
			me->CastSpell(nullptr, SPELL_TEKRIS_HIVEMIND_CONTROL, false);
			this->hivemindControlKazir = 0;
			this->hivemindControlTekris = 1;
			me->GetScheduler().Schedule(70s, [this](TaskContext /*context*/)
			{
				me->RemoveAura(SPELL_HIVEMIND_ENERGY_MANAGEMENT);
				me->RemoveAura(SPELL_TEKRIS_HIVEMIND_CONTROL);
				me->AI()->DoAction(ACTION_KAZIR_CONTROL);
			});
			break;

		case ACTION_KAZIR_CONTROL:
			Talk(SAY_KAZIR_HIVEMIND_CONTROL);
			me->CastSpell(nullptr, SPELL_KAZIR_HIVEMIND_CONTROL, false);
			this->hivemindControlKazir = 1;
			this->hivemindControlTekris = 0;
			me->GetScheduler().Schedule(70s, [this](TaskContext /*context*/)
			{
				me->RemoveAura(SPELL_HIVEMIND_ENERGY_MANAGEMENT);
				me->RemoveAura(SPELL_KAZIR_HIVEMIND_CONTROL);
				me->AI()->DoAction(ACTION_TEKRIS_CONTROL);
			});
			break;
		}
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_POWER_GAIN:
			me->ModifyPower(POWER_ENERGY, +1);
			if (me->GetPower(POWER_ENERGY) != 100)
				events.Repeat(1s);
			break;

		case EVENT_AQIR_DRONES:
			for (uint8 i = 0; i < 15; i++)
			{
				me->SummonCreature(NPC_AQIR_DRONE, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
			}
			break;

		case EVENT_AQIR_DARTERS:
			for (uint8 i = 0; i < 3; i++)
			{
				me->SummonCreature(NPC_AQIR_DARTER, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
			}
			break;

		case EVENT_NULLIFICATION_BLAST:
			if (Unit* tank = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
			{
				me->SetFacingToObject(tank, true);
				me->CastSpell(tank, SPELL_NULLIFICATION_BLAST, false);
			}
			events.Repeat(30s);
			break;

		case EVENT_ECHOING_VOID:
		{
			me->CastSpell(nullptr, SPELL_ECHOING_VOID, false);
			std::list<Player*> playerList;
			me->GetPlayerListInGrid(playerList, 100.0f);
			for (auto& targets : playerList)
			{
				me->CastSpell(targets, SPELL_ECHOING_VOID_PULSE, true);
				if (IsMythic())
				{
					me->GetScheduler().Schedule(4s, [this, targets](TaskContext /*context*/)
					{
						me->CastSpell(targets, SPELL_ENTROPIC_ECHO_MISSILE, true);
					});
				}
			}
			events.Repeat(40s);
			break;
		}

		case EVENT_SPAWN_ACIDIC_AQIR:
			for (uint8 i = 0; i < 10; i++)
			{
				Position positions = me->GetRandomNearPosition(60.0f);	
				me->CastSpell(positions, SPELL_SPAWN_ACIDIC_AQUIR_SUMMON, false);
			}
			events.Repeat(60s);
			break;

		case EVENT_MIND_NUMBING_NOVA:
			me->CastSpell(nullptr, SPELL_MIND_NUMBING_NOVA, false);
			events.Repeat(8s, 12s);
			break;

		case EVENT_ACCELERATED_EVOLUTION:
			if (Creature* aqirDrone = me->FindNearestCreature(NPC_AQIR_DRONE, 100.0f, true))
			{
				me->CastSpell(aqirDrone, SPELL_ACCELERATED_EVOLUTION_MISSILE, false);
				if (instance)
					instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, aqirDrone);
			}
			events.Repeat(65s);
			break;

		case EVENT_VOLATILE_ERUPTION:
			if (this->hivemindControlKazir == 1)
			{
				if (Creature* aqirDrone = me->FindNearestCreature(NPC_AQIR_DRONE, 100.0f, true))
					aqirDrone->CastSpell(nullptr, SPELL_VOLATILE_ERUPTION, false);
			}
			break;
		}
	}

	void OnSpellFinished(SpellInfo const* spellInfo) override
	{
		switch (spellInfo->Id)
		{
		case SPELL_MIND_NUMBING_NOVA:
			if (me->GetEntry() == NPC_KAZIR)
			{
				std::list<Player*> playerList;
				me->GetPlayerListInGrid(playerList, 100.0f);
				for (auto& targets : playerList)
				{
					me->CastSpell(targets, SPELL_MIND_NUMBING_TOXIN, true);
				}
			}
			break;

		case SPELL_TEKRIS_HIVEMIND_CONTROL:
		case SPELL_KAZIR_HIVEMIND_CONTROL:
			if (IsHeroic() || IsMythic())
				me->CastSpell(middle_of_the_room, SPELL_DEVOURING_FRENZY_VISUAL, true);
			break;
		}
	}

	void JustSummoned(Creature* summon) override
	{
		switch (summon->GetEntry())
		{
		case NPC_AQIR_DRONE:
		case NPC_AQIR_DARTER:
		case NPC_AQIR_RAVAGER:
			summon->AI()->DoZoneInCombat(nullptr);
			if (this->hivemindControlTekris = 1)
				summon->AddAura(SPELL_VOID_INFUSION);
			if (this->hivemindControlKazir = 1)
				summon->AddAura(SPELL_REGENERATION);
			break;
		}
	}

	void DamageTaken(Unit* done_by, uint32& damage) override
	{
		switch (me->GetEntry())
		{
		case NPC_KAZIR:
			if (me->GetHealthPct() == 1.0f)
			{
				me->RemoveAllAurasExceptType(SPELL_AURA_PREVENT_INTERRUPT);
				me->CastSpell(nullptr, SPELL_DARK_RECONSTRUCTION, false);
				me->GetScheduler().Schedule(10000ms, [this, done_by](TaskContext /*context*/)
				{
					if (Creature* tekris = me->FindNearestCreature(NPC_TEKRIS, 100.0f, true))
						if (tekris->isDead())
							done_by->Kill(me);
				});
			}
			break;

		case NPC_TEKRIS:
			if (me->GetHealthPct() == 1.0f)
			{			
				me->RemoveAllAurasExceptType(SPELL_AURA_PREVENT_INTERRUPT);
				me->CastSpell(nullptr, SPELL_DARK_RECONSTRUCTION, false);
				me->GetScheduler().Schedule(10000ms, [this, done_by](TaskContext /*context*/)
				{
					if (Creature* kazir = me->FindNearestCreature(NPC_KAZIR, 100.0f, true))
						if (kazir->isDead())
							done_by->Kill(me);
				});
			}
			break;
		}
	}

	void EnterEvadeMode(EvadeReason /*why*/) override
	{
		switch (me->GetEntry())
		{
		case NPC_KAZIR:		
			CleanEncounter(instance, me);
			break;

		case NPC_TEKRIS:
			CleanEncounter(instance, me);
			break;
		}
		_JustReachedHome();
		_DespawnAtEvade();
	}

	void CleanEncounter(InstanceScript* instance, Creature* me)
	{
		me->DespawnCreaturesInArea(NPC_AQIR_DRONE, 125.0f);
		me->DespawnCreaturesInArea(NPC_AQIR_DARTER, 125.0f);
		me->DespawnCreaturesInArea(NPC_AQIR_RAVAGER, 125.0f);
		me->RemoveAllAreaTriggers();
	}

	void JustDied(Unit* /*killer*/) override
	{
		switch (me->GetEntry())
		{
		case NPC_KAZIR:
			_JustDied();
			break;

		case NPC_TEKRIS:
			_JustDied();
			break;
		}
	}
};

//159173
struct npc_acidic_aqir : public ScriptedAI
{
	npc_acidic_aqir(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->SetReactState(REACT_PASSIVE);
		me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
		me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
		me->SetNativeDisplayId(16925, 1.0f);
		me->CastSpell(nullptr, SPELL_ACIDIC_AQUIR_VISUAL, true);
		me->SetWalk(false);
		me->GetSpeed(MOVE_RUN);
		me->GetMotionMaster()->MoveForward(me, 60.0f);
		me->DespawnOrUnsummon(10s);
	}

	void MoveInLineOfSight(Unit* unit) override
	{
		if (unit->IsPlayer() && me->GetDistance2d(unit) <= 5.0f && !unit->HasAura(SPELL_CORROSION))
			me->GetOwner()->AddAura(SPELL_CORROSION, unit);
	}
};

enum Hivemind
{
	SPELL_FIXATE = 308360,
	SPELL_MINDLESS = 313129,
	EVENT_FIXATE = 1,
	EVENT_PSIONIC_RESONANCE,
	EVENT_RAVAGE
};

//160599 ravager, 157255 drone, darter 157256
struct npc_hivemind : public ScriptedAI
{
	npc_hivemind(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		switch (me->GetEntry())
		{
		case NPC_AQIR_DRONE:
			ScriptedAI::Reset();
			break;

		case NPC_AQIR_DARTER:
		{
			ScriptedAI::Reset();
			Position position = me->GetRandomNearPosition(30.0f);			
			me->GetMotionMaster()->MoveJump(position, 25.0f, 25.0f, 0, true);
			break;
		}

		case NPC_AQIR_RAVAGER:
			ScriptedAI::Reset();
			break;
		}
	}

	void EnterCombat(Unit* /*who*/) override
	{
		switch (me->GetEntry())
		{
		case NPC_AQIR_DRONE:
			me->CastSpell(nullptr, SPELL_MINDLESS, true);
			events.ScheduleEvent(EVENT_FIXATE, 1s);
			break;

		case NPC_AQIR_DARTER:
			events.ScheduleEvent(EVENT_PSIONIC_RESONANCE, 3s);
			break;

		case NPC_AQIR_RAVAGER:
			events.ScheduleEvent(EVENT_RAVAGE, 3s);
			break;
		}
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_FIXATE:
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
			{
				me->AddThreat(target, 1000.0f, SpellSchoolMask::SPELL_SCHOOL_MASK_NORMAL);
				me->CastSpell(target, SPELL_FIXATE, true);				
			}
			break;

		case EVENT_PSIONIC_RESONANCE:
			me->CastSpell(nullptr, SPELL_PSIONIC_RESONANCE, false);
			events.Repeat(15s);
			break;

		case EVENT_RAVAGE:
			if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
				me->CastSpell(target, SPELL_RAVAGE, false);
			events.Repeat(18s);
			break;
		}
	}

	void JustDied(Unit* /*killer*/) override
	{
		if (me->GetEntry() == NPC_AQIR_RAVAGER)
			if (instance)
				instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
	}
};

void AddSC_hivemind()
{
	RegisterCreatureAI(boss_hivemind);
	RegisterCreatureAI(npc_acidic_aqir);
	RegisterCreatureAI(npc_hivemind);
};
