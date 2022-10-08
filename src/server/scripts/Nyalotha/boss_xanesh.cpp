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
	SAY_SOUL_FLAY,
	SAY_ABYSSAL_STRIKE,
	SAY_TORMENT,
	SAY_VOID_RITUAL,
	SAY_OBELISKS,
};

enum Spells
{
	SPELL_TORMENT_DAMAGE = 311383,
	SPELL_TORMENT_SUMMON_VEHICLE = 305907,
	SPELL_TORMENT_CREATE_AT = 305912,
	SPELL_TORMENT_SCREEN_EFFECT = 305916,
	SPELL_ANQUISH = 305794,
	SPELL_ABYSSAL_STRIKE = 311551,
	SPELL_SOUL_FLY_TRIGGER = 306319,
	SPELL_SOUL_FLY_DEBUFF = 306311,
	SPELL_SOUL_FLY_MISSILE = 306315, //157005
	SPELL_SOUL_FLY = 306228,
	SPELL_VOID_RITUAL = 312336,
	SPELL_VOID_RITUAL_DAMAGE = 313258,
	SPELL_VOID_SHIELD = 314035,
	SPELL_VOIDWOKEN = 312406,
	SPELL_REVILE = 309654,
	SPELL_DARK_COLLAPSE_DAMAGE = 306876,
	SPELL_DARK_ASCENSION = 313264,
	SPELL_FANATICISM = 314179,
	SPELL_VOID_TOUCHED_TRIGGER = 313198,
	SPELL_VOID_ORB_VISUAL = 311591, // void orb visual
	SPELL_GOAL_PORTAL_VISUAL = 312326, // goal portal visual
	//Heroic
	SPELL_DOOM = 314300,
	SPELL_OBELISK_AREA_DENIAL = 306493,
	SPELL_LARGE_OBELISK_AREA_DENIAL = 315494,
	SPELL_SUMMON_RITUAL_OBELISKS = 306495,
	SPELL_RITUAL_FIELD = 305575,
	SPELL_RITUAL_OBELISK_KNOCKBACK = 314297,
	SPELL_IMMINENT_DOOM = 314298,
	SPELL_IMMINENT_DOOM_SCREEN_EFFECT = 314299,
	//Mythic
	SPELL_TERROR_WAVE = 316211,
	SPELL_BERSERK = 306845,
};

enum Events
{
	EVENT_TORMENT = 1,
	EVENT_ABYSSAL_STRIKE,
	EVENT_SOUL_FLY,
	EVENT_VOID_RITUAL,
	EVENT_OBELISKS,
	EVENT_BERSERK
};

const Position goal_portal_spawn_one = { -559.329f, -342.082f, -251.202f, 1.0f };
const Position goal_portal_spawn_two = { -501.874f, -336.755f, -251.092f, 1.0f };
const Position goal_portal_spawn_three = { -496.966f, -378.767f, -251.133f, 1.0f };
const Position goal_portal_spawn_four = { -551.031f, -382.878f, -251.157f, 1.0f };
const Position void_orb_spawn = { -521.773f, -392.395f, -251.088f, 1.682f };
const Position azshara_pos = { -524.841f, -357.070f, -250.923f, 4.783f };

//156575
struct boss_xanesh : public BossAI
{
	boss_xanesh(Creature* creature) : BossAI(creature, DATA_XANESH) { }

	void Reset() override
	{
		BossAI::Reset();
		me->SetPowerType(POWER_ENERGY);
		me->SetMaxPower(POWER_ENERGY, 100);
		me->SetPower(POWER_ENERGY, 0);
	}

	void EnterCombat(Unit* /*who*/) override
	{
		Talk(SAY_AGGRO);
		_EnterCombat();
		if (IsHeroic() || IsMythic())
			events.ScheduleEvent(EVENT_OBELISKS, 5s);
		events.ScheduleEvent(EVENT_ABYSSAL_STRIKE, 10s);
		events.ScheduleEvent(EVENT_VOID_RITUAL, 18s);
		events.ScheduleEvent(EVENT_SOUL_FLY, 25s);
		events.ScheduleEvent(EVENT_TORMENT, 50s);
		events.ScheduleEvent(EVENT_BERSERK, 15min);
		if (Creature* azshara = me->FindNearestCreature(NPC_QUEEN_AZSHARA_XANESH, 100.0f, true))
			me->AddAura(SPELL_ANQUISH, azshara);
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_ABYSSAL_STRIKE:
			Talk(SAY_ABYSSAL_STRIKE);
			if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
				me->CastSpell(target, SPELL_ABYSSAL_STRIKE, false);
			events.Repeat(45s);
			break;

		case EVENT_SOUL_FLY:
			Talk(SAY_SOUL_FLAY);
			me->CastSpell(nullptr, SPELL_SOUL_FLY_TRIGGER, false);
			if (IsMythic())
			{
				UnitList tarlist;
				SelectTargetList(tarlist, 6, SELECT_TARGET_RANDOM, 100.0f);
				for (Unit* targets : tarlist)
				{
					me->CastSpell(targets, SPELL_SOUL_FLY_DEBUFF, true);
					me->CastSpell(targets->GetPosition(), SPELL_SOUL_FLY_MISSILE, true);
				}
			}
			else
			{
				UnitList tarlist;
				SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 100.0f);
				for (Unit* targets : tarlist)
				{
					me->CastSpell(targets, SPELL_SOUL_FLY_DEBUFF, true);
					me->CastSpell(targets->GetPosition(), SPELL_SOUL_FLY_MISSILE, true);
				}
			}
			events.Repeat(35s);
			break;

		case EVENT_VOID_RITUAL:
			Talk(SAY_VOID_RITUAL);
			me->CastSpell(nullptr, SPELL_VOID_RITUAL, false);
			events.Repeat(80s);
			break;

		case EVENT_TORMENT:
		{
			Talk(SAY_TORMENT);
			std::list<Creature*> tormentVehicles;
			me->GetCreatureListWithEntryInGrid(tormentVehicles, NPC_TORMENT_VEHICLE, 100.0f);
			for (auto& controllers : tormentVehicles)
			{
				controllers->CastSpell(nullptr, SPELL_TORMENT_DAMAGE, false);
			}
			events.Repeat(30s);
			break;
		}

		case EVENT_OBELISKS:
		{
			me->DespawnCreaturesInArea(NPC_RITUAL_OBELISK, 125.0f);
			me->DespawnCreaturesInArea(NPC_LARGE_RITUAL_OBELISK, 125.0f);
			Talk(SAY_OBELISKS);
			me->CastSpell(nullptr, SPELL_SUMMON_RITUAL_OBELISKS, false);
			if (Creature* azshara = me->FindNearestCreature(NPC_QUEEN_AZSHARA_XANESH, 100.0f, true))
			{		
				for (uint8 i = 0; i < 8; i++)
				{
					azshara->SummonCreature(NPC_RITUAL_OBELISK, azshara->GetRandomNearPosition(25.0f), TEMPSUMMON_MANUAL_DESPAWN);
				}
			}
			events.Repeat(65s);
			break;
		}

		case EVENT_BERSERK:
			me->CastSpell(nullptr, SPELL_BERSERK, true);
			break;
		}
	}

	void ChooseGoalPortal()
	{
		me->DespawnCreaturesInArea(NPC_GOAL_PORTAL, 125.0f);
		uint32 ChoosePortal = urand(0, 3);
		switch (ChoosePortal)
		{
		case 0:			
			me->SummonCreature(NPC_GOAL_PORTAL, goal_portal_spawn_one, TEMPSUMMON_MANUAL_DESPAWN);
			break;

		case 1:
			me->SummonCreature(NPC_GOAL_PORTAL, goal_portal_spawn_two, TEMPSUMMON_MANUAL_DESPAWN);
			break;

		case 2:
			me->SummonCreature(NPC_GOAL_PORTAL, goal_portal_spawn_three, TEMPSUMMON_MANUAL_DESPAWN);
			break;

		case 3:
			me->SummonCreature(NPC_GOAL_PORTAL, goal_portal_spawn_four, TEMPSUMMON_MANUAL_DESPAWN);
			break;
		}
	}

	void OnSpellFinished(SpellInfo const* spellInfo) override
	{
		switch (spellInfo->Id)
		{
		case SPELL_VOID_RITUAL:
		{
			me->SummonCreature(NPC_VOID_ORB, void_orb_spawn, TEMPSUMMON_MANUAL_DESPAWN);
			ChooseGoalPortal();
			break;
		}

		}
	}

	void CleanupEncounter(InstanceScript* instance, Creature* me)
	{
		_JustReachedHome();
		me->DespawnCreaturesInArea(NPC_FLAYED_SOUL, 125.0f);
		me->DespawnCreaturesInArea(NPC_RITUAL_OBELISK, 125.0f);
		me->DespawnCreaturesInArea(NPC_LARGE_RITUAL_OBELISK, 125.0f);
		me->DespawnCreaturesInArea(NPC_AWAKENED_TERROR, 125.0f);
		me->DespawnCreaturesInArea(NPC_FLAYED_SOUL, 125.0f);
		me->DespawnCreaturesInArea(NPC_TORMENT_VEHICLE, 125.0f);
		me->DespawnCreaturesInArea(NPC_VOID_ORB, 125.0f);
		me->DespawnCreaturesInArea(NPC_GOAL_PORTAL, 125.0f);
		me->RemoveAllAreaTriggers();
		if (Creature* azshara = me->FindNearestCreature(NPC_QUEEN_AZSHARA_XANESH, 100.0f, true))
			azshara->RemoveAura(SPELL_ANQUISH);
	}

	void EnterEvadeMode(EvadeReason /*why*/) override
	{
		CleanupEncounter(instance, me);
		_DespawnAtEvade();
	}

	void JustDied(Unit* /*attacker*/) override
	{
		_JustDied();
		instance->DoModifyPlayerCurrencies(CURRENCY_ECHOES_OF_NYALOTHA, 12);
	}
};

//156579
struct npc_queen_azshara_xanesh : public ScriptedAI
{
	npc_queen_azshara_xanesh(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->AddUnitState(UNIT_STATE_STUNNED);
		me->CastSpell(nullptr, SPELL_LARGE_OBELISK_AREA_DENIAL, true);
		me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
	}
};

//156840
struct npc_torment_vehicle : public ScriptedAI
{
	npc_torment_vehicle(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
	}
};

//157126,162098
struct npc_ritual_obelisk : public ScriptedAI
{
	npc_ritual_obelisk(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->SetReactState(REACT_PASSIVE);
		me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
		switch (me->GetEntry())
		{
		case NPC_RITUAL_OBELISK:
			me->CastSpell(nullptr, SPELL_OBELISK_AREA_DENIAL, true);
			break;

		case NPC_LARGE_RITUAL_OBELISK:
			me->CastSpell(nullptr, SPELL_LARGE_OBELISK_AREA_DENIAL, true);
			break;
		}
	}

	void MoveInLineOfSight(Unit* unit) override
	{
		 switch (me->GetEntry())
		 {
		 case NPC_RITUAL_OBELISK:
			 if (unit->IsPlayer() && me->GetDistance2d(unit) <= 4.9f && !unit->HasAura(SPELL_RITUAL_FIELD))
				 me->AddAura(SPELL_RITUAL_FIELD, unit);

			 if (unit->IsPlayer() && me->GetDistance2d(unit) > 4.9f && unit->HasAura(SPELL_RITUAL_FIELD))
				 unit->RemoveAura(SPELL_RITUAL_FIELD);
			 break;

		 case NPC_LARGE_RITUAL_OBELISK:
			 if (unit->IsPlayer() && me->GetDistance2d(unit) <= 8.3f && !unit->HasAura(SPELL_RITUAL_FIELD))
				 me->AddAura(SPELL_RITUAL_FIELD, unit);

			 if (unit->IsPlayer() && me->GetDistance2d(unit) > 8.3f && unit->HasAura(SPELL_RITUAL_FIELD))
				 unit->RemoveAura(SPELL_RITUAL_FIELD);
			 break;
		 }
	}
};

//500523
struct npc_void_orb : public ScriptedAI
{
	npc_void_orb(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
		me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
		me->SetDisplayId(93977, 1.5f);
		me->SetWalk(true);
		me->GetSpeed(MOVE_WALK);		
	}

	void IsSummonedBy(Unit* summoner) override
	{
		if (me->GetMapId() == MAP_NYALOTHA)
			me->GetMotionMaster()->MovePoint(1, azshara_pos, true);
	}

	void OnSpellClick(Unit* clicker, bool& /*result*/) override
	{
		if (Player* player = clicker->ToPlayer())
		{
			if (clicker->HasAura(SPELL_VOIDWOKEN))
			{
				me->StopMoving();		
				me->GetMotionMaster()->Clear(true);
				me->GetMotionMaster()->MoveFollow(clicker, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
				if (IsHeroic() || IsMythic())
				{
					me->AddAura(SPELL_IMMINENT_DOOM, clicker);
					if (Aura* imminentDoom = clicker->GetAura(SPELL_IMMINENT_DOOM))
						if (imminentDoom->GetStackAmount() == 5)
							clicker->CastSpell(nullptr, SPELL_DOOM, true);
				}
			}
		}
	}

	void MoveInLineOfSight(Unit* unit) override
	{
		if (unit->GetEntry() == NPC_QUEEN_AZSHARA_XANESH || unit->GetEntry() == NPC_RITUAL_OBELISK || unit->GetEntry() == NPC_LARGE_RITUAL_OBELISK)
		{
			if (unit->GetDistance2d(me) <= 5.0f)
			{
				me->CastSpell(nullptr, SPELL_DARK_COLLAPSE_DAMAGE, true);
				me->DespawnOrUnsummon();
			}
		}
		else if (unit->GetEntry() == NPC_GOAL_PORTAL)
		{
			if (unit->GetDistance2d(me) <= 5.0f)
				me->DespawnOrUnsummon();
		}
	}
};

//500524
struct npc_goal_portal : public ScriptedAI
{
	npc_goal_portal(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
		me->CastSpell(nullptr, SPELL_GOAL_PORTAL_VISUAL, true);
	}
};

//157005
struct npc_flayed_soul : public ScriptedAI
{
	npc_flayed_soul(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		DoZoneInCombat(nullptr);		
	}

	void EnterCombat(Unit* /*who*/) override
	{
		me->CastSpell(nullptr, SPELL_SOUL_FLY, false);
	}
};

void AddSC_xanesh()
{
	RegisterCreatureAI(boss_xanesh);
	RegisterCreatureAI(npc_queen_azshara_xanesh);
	RegisterCreatureAI(npc_torment_vehicle);
	RegisterCreatureAI(npc_ritual_obelisk);
	RegisterCreatureAI(npc_void_orb);
	RegisterCreatureAI(npc_goal_portal);
	RegisterCreatureAI(npc_flayed_soul);
};
