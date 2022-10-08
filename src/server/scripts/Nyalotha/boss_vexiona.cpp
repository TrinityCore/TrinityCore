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
	SAY_DESPAIR,
};

enum Spells
{
	SPELL_DESPAIR = 307359,
	SPELL_SHATTERED_RESOLVE = 307371,
	SPELL_TWILIGHT_BREATH = 307020,
	SPELL_TWILIGHT_BREATH_DAMAGE = 307297,
	SPELL_ANNIHILATION = 307403,
	SPELL_ANNIHILATION_DAMAGE = 307421,
	SPELL_GIFT_OF_THE_VOID = 306981, // gives button to player
	SPELL_GIFT_OF_THE_VOID_DAMAGE = 306982,
	SPELL_VOID_CORRUPTION_PERIODIC_TRIGGER = 307019,
	SPELL_VOID_CORRUUPTION_DAMAGE = 313283,
	SPELL_DARK_GATEWAY_VISUAL = 313668,
	SPELL_DARK_GATEWAY_DAMAGE = 307057,
	SPELL_FANATICAL_ASCENSION = 307729,
	SPELL_VOID_BOLT = 307177,
	SPELL_ENCROACHING_SHADOWS_PERIODIC_TRIGGER = 307314,
	SPELL_ENCROACHING_SHADOWS_DAMAGE = 307317,
	SPELL_ENCROACHING_SHADOWS_CREATE_AT = 307318,
	SPELL_SHADOWY_RESIDUE_AT_DAMAGE = 307343,
	//Phase 2
	SPELL_DECIMATION_DAMAGE = 315769,
	SPELL_TWILIGHT_DECIMATOR_DAMAGE = 307218,
	SPELL_TWILIGHT_DECIMATOR_CREATE_AT = 307212,
	SPELL_TWILIGHT_DECIMATOR_CREATE_AT_SECOND = 310225,
	SPELL_TWILIGHT_DECIMATOR_CREATE_AT_THIRD = 310237,
	SPELL_TWILIGHT_DECIMATOR_CREATE_AT_FOUR = 310238,
	//Phase 3
	SPELL_TERRYFYING_PRESENCE = 307284,
	SPELL_HEART_OF_DARKNESS = 307639,
	SPELL_HEART_OF_DARKNESS_FEAR = 307645,
	SPELL_DESTRUCTIVE_RAGE = 317157,
	SPELL_DESOLATION_MISSILE = 310324,
	SPELL_DESOLATION_SLOW = 310323,
	SPELL_DESOLATION_DAMAGE = 310325,
	SPELL_BERSERK = 306845,
};

enum Events
{
	EVENT_GAIN_ENERGY_VEXIONA = 1,
	EVENT_ASCENDANT,
	EVENT_DESPAIR,
	EVENT_TWILIGHT_BREATH,
	EVENT_ANNIHILATION,
	EVENT_GATEWAY,
	EVENT_CULTIST_GAIN_ENERGY,
	EVENT_VOID_BOLT,
	EVENT_ENCROACHING_SHADOWS,
	//Phase 2
	EVENT_TWILIGHT_DECIMATOR,
	//Phase 3
	EVENT_HEART_OF_DARKNESS,
	EVENT_DESOLATION,
	EVENT_BERSERK
};

enum Points
{
	POINT_ONE = 1,
	POINT_TWO,
	POINT_THREE,
};

//157354
struct boss_vexiona : public BossAI
{
	boss_vexiona(Creature* creature) : BossAI(creature, DATA_VEXIONA) { }

private:
	uint8 phase;
	bool isInHome;
	uint8 twilightDecimator;
	uint8 desolationTargets;

	void Reset() override
	{
		BossAI::Reset();
		this->phase = 0;
		this->twilightDecimator = 0;
		this->desolationTargets = 0;
		me->SetPowerType(POWER_ENERGY);
		me->SetMaxPower(POWER_ENERGY, 100);
		me->SetPower(POWER_ENERGY, 0);
		me->AddAura(AURA_OVERRIDE_POWER_COLOR_PURPLE);	
		/*if (instance->GetBossState(DATA_SKITRA) != DONE)
			StartFlight();*/
	}	

	const Position flight_pos_one = { -372.505f, -50.668f, -191.482f, 6.282f };
	const Position flight_pos_two = { -388.901f, 114.360f, -188.599f, 1.034f };
	const Position flight_pos_three = { -721.146f, -13.310f, -156.645f, 4.833f };

	void StartFlight()
	{
		me->SetWalk(false);
		me->SetFlying(true);
		me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
		me->GetMotionMaster()->Clear(true);
		me->GetSpeed(MOVE_FLIGHT);
		me->UpdateSpeed(MOVE_FLIGHT);
		me->GetMotionMaster()->MovePoint(POINT_ONE, flight_pos_one, true);
		isInHome = false;
	}

	void MovementInform(uint32 type, uint32 flightPoint) override
	{
		if (type != POINT_MOTION_TYPE)
			return;

		switch (flightPoint)
		{
		case POINT_ONE:
			me->GetMotionMaster()->MovePoint(POINT_TWO, flight_pos_two, true);
			break;

		case POINT_TWO:
			me->GetMotionMaster()->MovePoint(POINT_THREE, flight_pos_three, true);
			break;

		case POINT_THREE:
			me->GetMotionMaster()->MoveTargetedHome();
			break;
		}
	}

	void JustReachedHome() override
	{
		if (instance->GetBossState(DATA_SKITRA) != DONE)
		{
			me->GetMotionMaster()->Clear();
			StartFlight();
		}
		else
		{
			me->GetMotionMaster()->Clear();
			me->SetFlying(false);
			me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
			me->GetSpeed(MOVE_WALK);
			me->UpdateSpeed(MOVE_WALK);
			instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GIFT_OF_THE_VOID_DAMAGE);
		}
	}

	void CleanupEncounter(InstanceScript* instance, Creature* me)
	{
		_JustReachedHome();
		me->DespawnCreaturesInArea(NPC_ASCENDANT, 125.0f);
		me->DespawnCreaturesInArea(NPC_GIFT_OF_THE_VOID, 125.0f);
		me->DespawnCreaturesInArea(NPC_FANATICAL_CULTIST, 125.0f);
		me->DespawnCreaturesInArea(NPC_SPELLBOUND_RITUALIST, 125.0f);
		me->DespawnCreaturesInArea(NPC_DARK_GATEWAY, 125.0f);
		me->DespawnCreaturesInArea(NPC_SINISTER_SOULCARVER, 125.0f);
		me->DespawnCreaturesInArea(NPC_IRON_WILLED_ENFORCER, 125.0f);
		me->RemoveAllAreaTriggers();
		instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HEART_OF_DARKNESS_FEAR);
	}

	void EnterCombat(Unit* /*who*/) override
	{
		Talk(SAY_AGGRO);
		_EnterCombat();
		events.ScheduleEvent(EVENT_GAIN_ENERGY_VEXIONA, 100ms);
		events.ScheduleEvent(EVENT_ASCENDANT, 1s);
		events.ScheduleEvent(EVENT_ENCROACHING_SHADOWS, 13s);
		events.ScheduleEvent(EVENT_DESPAIR, 15s);
		events.ScheduleEvent(EVENT_TWILIGHT_BREATH, 18s);
		events.ScheduleEvent(EVENT_GATEWAY, 32s);
		events.ScheduleEvent(EVENT_BERSERK, 12min);
		this->phase = 1;
	}

	void DamageTaken(Unit* attacker, uint32& damage) override
	{
		if (this->phase = 1 && this->twilightDecimator == 3)
		{
			//events.Reset();
			this->phase = 2;
			twilightDecimator = 0;
		}
		if (me->HealthBelowPct(40))
		{
			//events.Reset();
			this->phase = 3;
		}
	}

	void UpdateAI(uint32 diff) override
	{
		if (instance->GetBossState(DATA_SKITRA) == DONE && !isInHome)
		{
			isInHome = true;
			me->NearTeleportTo(me->GetHomePosition());
		}

		if (!UpdateVictim())
			return;

		events.Update(diff);

		while (uint32 eventId = events.ExecuteEvent())
		{
			if (me->GetPower(POWER_ENERGY) == 100)
			{
				me->SetPower(POWER_ENERGY, 0);
				me->CastSpell(nullptr, SPELL_HEART_OF_DARKNESS, false);
			}

			switch (eventId)
			{
			case EVENT_GAIN_ENERGY_VEXIONA:
				me->ModifyPower(POWER_ENERGY, +1);
				events.Repeat(1s);
				break;

			case EVENT_ASCENDANT:
				me->SummonCreature(NPC_ASCENDANT, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
				break;

			case EVENT_DESPAIR:
				Talk(SAY_DESPAIR);		
				if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
					me->CastSpell(target, SPELL_DESPAIR, true);
				events.Repeat(30s);
				break;

			case EVENT_TWILIGHT_BREATH:
				if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 50.0f, true))
					me->CastSpell(target, SPELL_TWILIGHT_BREATH, false);
				events.Repeat(18s);
				break;

			case EVENT_GATEWAY:
				me->SummonCreature(NPC_DARK_GATEWAY, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
				break;

			case EVENT_ENCROACHING_SHADOWS:	
			{
				UnitList tarlist;
				SelectTargetList(tarlist, 6, SELECT_TARGET_RANDOM, 100.0f);
				for (Unit* targets : tarlist)
				{
					me->CastSpell(targets, SPELL_ENCROACHING_SHADOWS_PERIODIC_TRIGGER, true);
				}
				events.Repeat(35s);
				break;
			}

			case EVENT_TWILIGHT_DECIMATOR:
				twilightDecimator++;
				me->SetReactState(REACT_PASSIVE);
				me->SetHover(true);
				me->SetHoverHeight(30.0f);
				me->GetMotionMaster()->MovePoint(4, me->GetRandomNearPosition(60.0f), true);
				break;

			case EVENT_DESOLATION:
				if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
					me->CastSpell(target, SPELL_DESOLATION_MISSILE, false);
				events.Repeat(25s);
				break;

			case EVENT_BERSERK:
				me->CastSpell(nullptr, SPELL_BERSERK, true);
				break;
		}
		DoMeleeAttackIfReady();
		}
	}

	void SpellHitTarget(Unit* target, const SpellInfo* spellInfo) override
	{
		switch (spellInfo->Id)
		{
		case SPELL_DESOLATION_DAMAGE:
			desolationTargets++;
			if (this->desolationTargets >= 3)
			{
				me->CastSpell(nullptr, SPELL_DESTRUCTIVE_RAGE, true);
				desolationTargets = 0;
			}
			break;
		}
	}

	void OnSpellFinished(SpellInfo const* spellInfo) override
	{
		switch (spellInfo->Id)
		{
		case SPELL_HEART_OF_DARKNESS:
			std::list<Player*> playerList;
			me->GetPlayerListInGrid(playerList, 100.0f);
			for (auto& targets : playerList)
			{
				if (!targets->SelectNearestPlayer(6.0f))
					targets->AddAura(SPELL_HEART_OF_DARKNESS_FEAR);
			}
			break;
		}
	}

	void EnterEvadeMode(EvadeReason /*why*/) override
	{
		CleanupEncounter(instance, me);
		_DespawnAtEvade();
	}

	void JustDied(Unit* /*attacker*/) override
	{
		_JustDied();
		CleanupEncounter(instance, me);
		instance->DoModifyPlayerCurrencies(CURRENCY_ECHOES_OF_NYALOTHA, 13);
	}
};

//307359 
class aura_despair : public AuraScript
{
	PrepareAuraScript(aura_despair);

	void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
	{
		Unit* target = GetTarget();
		Unit* caster = GetCaster();
		if (!caster || !target)
			return;

		if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
			caster->CastSpell(target, SPELL_SHATTERED_RESOLVE, true);
	}

	void Register() override
	{
		OnEffectRemove += AuraEffectRemoveFn(aura_despair::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
	}
};

//162719
struct npc_void_ascendant : public ScriptedAI
{
	npc_void_ascendant(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		if (instance)
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
		me->SetPowerType(POWER_ENERGY);
		me->SetMaxPower(POWER_ENERGY, 100);
		me->SetPower(POWER_ENERGY, 0);
		me->AddAura(AURA_OVERRIDE_POWER_COLOR_PURPLE);
	}

	void IsSummonedBy(Unit* summoner) override
	{
		if (summoner->IsInCombat())
			DoZoneInCombat(nullptr);
	}

	void EnterCombat(Unit* /*who*/) override
	{
		events.ScheduleEvent(EVENT_ANNIHILATION, 3s);
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_ANNIHILATION:
			if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
				me->CastSpell(target, SPELL_ANNIHILATION, false);
			events.Repeat(20s);
			break;
		}
	}

	void JustDied(Unit* /*killer*/) override
	{
		if (instance)
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
		me->SummonCreature(NPC_GIFT_OF_THE_VOID, me->GetRandomNearPosition(5.0f), TEMPSUMMON_MANUAL_DESPAWN);
	}
};

//157422
struct npc_gift_of_the_void : public ScriptedAI
{
	npc_gift_of_the_void(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
	}

	void OnSpellClick(Unit* clicker, bool& /*result*/) override
	{
		if (Player* player = clicker->ToPlayer())
		{
			me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
			player->AddAura(SPELL_GIFT_OF_THE_VOID);
			if (player->HasAura(SPELL_VOID_CORRUPTION_PERIODIC_TRIGGER))
				if (Aura* voidCorruption = player->GetAura(SPELL_VOID_CORRUPTION_PERIODIC_TRIGGER))
				{
					voidCorruption->SetStackAmount(0);
					me->DespawnOrUnsummon();
				}
		}
	}
};

//161148
struct npc_dark_gateway : public ScriptedAI
{
	npc_dark_gateway(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->SetReactState(REACT_PASSIVE);
		me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
		me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
		me->CastSpell(nullptr, SPELL_DARK_GATEWAY_VISUAL, true);
		me->CastSpell(nullptr, SPELL_DARK_GATEWAY_DAMAGE, true);
		uint32 cultists = urand(0, 1);
		switch (cultists)
		{
		case 0:
			for (uint8 i = 0; i < 3; i++)
			{
				me->SummonCreature(NPC_FANATICAL_CULTIST, me->GetRandomNearPosition(5.0f), TEMPSUMMON_MANUAL_DESPAWN);
			}
			//Soulcarvers
			if (IsHeroic() || IsMythic())
				me->SummonCreature(NPC_SINISTER_SOULCARVER, me->GetRandomNearPosition(5.0f), TEMPSUMMON_MANUAL_DESPAWN);
			//Enforcers
			if (IsMythic())
				me->SummonCreature(NPC_IRON_WILLED_ENFORCER, me->GetRandomNearPosition(5.0f), TEMPSUMMON_MANUAL_DESPAWN);
			break;

		case 1:
			me->SummonCreature(NPC_SPELLBOUND_RITUALIST, me->GetRandomNearPosition(5.0f), TEMPSUMMON_MANUAL_DESPAWN);
			//Soulcarvers
			if (IsHeroic() || IsMythic())
				me->SummonCreature(NPC_SINISTER_SOULCARVER, me->GetRandomNearPosition(5.0f), TEMPSUMMON_MANUAL_DESPAWN);
			//Enforcers
			if (IsMythic())
				me->SummonCreature(NPC_IRON_WILLED_ENFORCER, me->GetRandomNearPosition(5.0f), TEMPSUMMON_MANUAL_DESPAWN);
			break;
		}
		me->DespawnOrUnsummon(5s);
	}

	void JustSummoned(Creature* summon) override
	{
		switch (summon->GetEntry())
		{
		case NPC_ASCENDANT:
		case NPC_FANATICAL_CULTIST:
		case NPC_SPELLBOUND_RITUALIST:
		case NPC_SINISTER_SOULCARVER:
		case NPC_IRON_WILLED_ENFORCER:
			summon->AI()->DoZoneInCombat(nullptr);
			break;
		}
	}
};

//162715, 162716
struct npc_fanatic : public ScriptedAI
{
	npc_fanatic(Creature* c) : ScriptedAI(c) { }

	void EnterCombat(Unit* /*who*/) override
	{
		switch (me->GetEntry())
		{
		case NPC_FANATICAL_CULTIST:
			me->SetPowerType(POWER_ENERGY);
			me->SetMaxPower(POWER_ENERGY, 100);
			me->SetPower(POWER_ENERGY, 0);
			break;

		case NPC_SPELLBOUND_RITUALIST:
			events.ScheduleEvent(EVENT_VOID_BOLT, 3s);
			break;
		}
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_CULTIST_GAIN_ENERGY:
			me->ModifyPower(POWER_ENERGY, +1);
			if (me->GetPower(POWER_ENERGY) == 100)
				me->CastSpell(nullptr, SPELL_FANATICAL_ASCENSION, false);
			break;

		case EVENT_VOID_BOLT:
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
				me->CastSpell(target, SPELL_VOID_BOLT, false);
			events.Repeat(3s, 3500ms);
			break;
		}
	}
};

//307314
class aura_encroaching_shadows : public AuraScript
{
	PrepareAuraScript(aura_encroaching_shadows);

	void OnTick(AuraEffect const* /*aurEff*/)
	{
		if (Unit* target = GetTarget())
			if (Unit* caster = GetCaster())
				caster->CastSpell(target, SPELL_ENCROACHING_SHADOWS_DAMAGE, true);
	}

	void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
	{
		Unit* target = GetTarget();
		Unit* caster = GetCaster();
		if (!caster || !target)
			return;

		if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
			caster->CastSpell(target, SPELL_ENCROACHING_SHADOWS_CREATE_AT, true);
	}

	void Register() override
	{
		OnEffectPeriodic += AuraEffectPeriodicFn(aura_encroaching_shadows::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
		OnEffectRemove += AuraEffectRemoveFn(aura_encroaching_shadows::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
	}
};

class terryfying_presence : public PlayerScript
{
public:
	terryfying_presence() : PlayerScript("terryfying_presence") { }

private:
	uint32 checkTimer = 1000;

	void OnUpdate(Player* player, uint32 diff) override
	{
		if (player->GetAreaId() != 12877)
			return;

		if (checkTimer == 1000)
		{
			if (Creature* vexiona = player->FindNearestCreature(NPC_VEXIONA, 100.0f, true))
			{
				if (vexiona->IsInCombat())
				{
					if (!player->SelectNearestPlayer(6.0f))
						vexiona->CastSpell(player, SPELL_TERRYFYING_PRESENCE, true);
					else
					{
						if (player->HasAura(SPELL_TERRYFYING_PRESENCE))
							player->RemoveAura(SPELL_TERRYFYING_PRESENCE);
					}
				}
			}
		}
	}
};

void AddSC_vexiona()
{
	RegisterCreatureAI(boss_vexiona);
	RegisterAuraScript(aura_despair);
	RegisterCreatureAI(npc_void_ascendant);
	RegisterCreatureAI(npc_gift_of_the_void);
	RegisterCreatureAI(npc_dark_gateway);
	RegisterCreatureAI(npc_fanatic);
	RegisterAuraScript(aura_encroaching_shadows);
	RegisterPlayerScript(terryfying_presence);
};
