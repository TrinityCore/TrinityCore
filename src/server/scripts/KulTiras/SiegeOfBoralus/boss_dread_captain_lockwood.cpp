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
#include "siege_of_boralus.h"
#include "ScriptedGossip.h"

const Position lockwood_home_pos = { 620.0f, -245.0f, 12.58f, 1.0f };
const Position lockwood_withdraw_pos = { 662.0f, -245.0f, 11.06f, 3.25f };
const Position deckhand_door_pos = { 656.0f, -227.0f, 1100.0f, 4.78f };
const Position deckhand_2_pos = { 671.0f, -245.0f, 1100.0f, 3.23f };
const Position cannoneer_pos = { 671.0f, -242.0f, 1098.0f, 3.23f };

const Position summons_pos = { 641.0f, -244.0f, 12.0f, 3.30f };

enum Texts
{
	SAY_AGGRO = 0,
	SAY_GUT,
	SAY_CANNON,
	SAY_WITHDRAW,
	SAY_CLEAR,
	SAY_ADS,
	SAY_DEATH,
	SAY_WIPE,
};

enum Events
{
	EVENT_SHOOT = 1,
	EVENT_GUT_SHOT,
	EVENT_CLEAR_THE_DECK,
	EVENT_WITHDRAW,
	EVENT_DREAD_VOLLEY,
	EVENT_CANNON_BARRAGE,
	EVENT_EVASIVE,
	EVENT_RANGE
};

enum Spells
{
	EVASIVE = 272471,
	LOCKWOOD_SHOOT = 280389, // random every 2.5s
	GUT_SHOT = 273470, // random
	CLEAR_THE_DECK = 269029, //tank
	WITHDRAW = 268752, // at 100 energy

	DREAD_VOLLEY_CHANNEL = 268933,
	DREAD_VOLLEY_GROUND_MARK = 268940,
	DREAD_VOLLEY_MISSILE = 268944,

	UNSTABLE_ORDNACE_SUMMON = 268963,
	UNSTABLE_ORDNACE = 268995,
	UNSTABLE_ORDNACE_EXP = 269015,
};

//129208
struct boss_dread_captain_lockwood : public BossAI
{
	boss_dread_captain_lockwood(Creature* creature) : BossAI(creature, DATA_DREAD_CAPTAIN_LOCKWOOD) { }

	void Reset() override
	{
		BossAI::Reset();
		me->SetPowerType(POWER_COMBO_POINTS);
		me->SetPower(POWER_COMBO_POINTS, 0);
		me->ClearUnitState(UNIT_STATE_ROOT);
		me->NearTeleportTo(me->GetHomePosition());
		me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
		me->DespawnCreaturesInArea(NPC_ASHVANE_DECKHAND, 125.0f);
		me->DespawnCreaturesInArea(NPC_ASHAVANE_CANNONNEER, 125.0f);
		me->DespawnCreaturesInArea(NPC_CANNON_BARRAGE, 125.0f);
		Talk(SAY_WIPE);
		if (!me->HasAura(EVASIVE))
		{
			me->CastSpell(me, EVASIVE);
		}
	}

	void EnterCombat(Unit* u) override
	{
		_EnterCombat();
		Talk(SAY_AGGRO);
		events.ScheduleEvent(EVENT_RANGE, 500ms);
		events.ScheduleEvent(EVENT_SHOOT, 1s);
		events.ScheduleEvent(EVENT_GUT_SHOT, 3s);
		events.ScheduleEvent(EVENT_EVASIVE, 4s);
		events.ScheduleEvent(EVENT_CLEAR_THE_DECK, 6s);
		events.ScheduleEvent(EVENT_WITHDRAW, 30s);	
	}

	void JustDied(Unit* u) override
	{		
		_JustDied();
		Talk(SAY_DEATH);
		me->DespawnCreaturesInArea(NPC_ASHVANE_DECKHAND, 125.0f);
		me->DespawnCreaturesInArea(NPC_ASHAVANE_CANNONNEER, 125.0f);
		me->DespawnCreaturesInArea(NPC_CANNON_BARRAGE, 125.0f);
	}

	void ExecuteEvent(uint32 eventid) override
	{
		switch (eventid)
		{
		case EVENT_SHOOT:
			if (Unit* tar = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
			{
				DoCast(tar, LOCKWOOD_SHOOT);
			}
			events.Repeat(2500ms);
			break;

		case EVENT_EVASIVE:
			if (me->HasAura(EVASIVE))
			{
				DoCast(152511); // Withdraw jump
			}
			events.Repeat(17s);
			break;

		case EVENT_GUT_SHOT:
		{
			Talk(SAY_GUT);
			UnitList tarlist;
			SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 45.0f, true);
			for (Unit* tar : tarlist)
			DoCast(tar, GUT_SHOT, true);
			events.Repeat(15s);
			break;
		}

		case EVENT_CLEAR_THE_DECK:
			if (Unit* tar = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 30.0f, true))
			{
				DoCastAOE(CLEAR_THE_DECK, true);
			}
			events.Repeat(20s);
			break;

		case EVENT_CANNON_BARRAGE:
			if (me->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE))
			{
				Talk(SAY_CANNON);
                for (uint8 i = 0; i < 21; i++)
                {
                    me->SummonCreature(NPC_CANNON_BARRAGE, me->GetRandomPoint(lockwood_home_pos, 30.0f));
                }
				if (Creature* dread_cannon = me->FindNearestCreature(NPC_DREAD_CANNON, 100.0f, true))
				{
					dread_cannon->CastSpell(nullptr, DREAD_VOLLEY_CHANNEL);
					if (Creature* lockwoodbunny = me->FindNearestCreature(NPC_DREAD_CANNON_BUNNY, 100.0f, true))
					{
						lockwoodbunny->GetScheduler().Schedule(3000ms, [lockwoodbunny](TaskContext context)
						{
							std::list<Creature*> c_list;
							lockwoodbunny->GetCreatureListWithEntryInGrid(c_list, NPC_CANNON_BARRAGE, 250.0f);
							for (auto & controllers : c_list)
							lockwoodbunny->AI()->DoCast(controllers, DREAD_VOLLEY_MISSILE);
						});
					}
				}			
			}
			events.Repeat(15s);
			break;

		case EVENT_WITHDRAW:
			Talk(SAY_WITHDRAW);
			DoCastSelf(WITHDRAW, true);
			me->AttackStop();
			me->CastStop();
			me->SetReactState(REACT_PASSIVE);
			me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
			me->NearTeleportTo(662.0f, -245.0f, 11.06f, 3.25f, false);
			me->AddUnitState(UNIT_STATE_ROOT);
			events.CancelEvent(EVENT_GUT_SHOT);			
			events.CancelEvent(EVENT_WITHDRAW);
			events.CancelEvent(EVENT_SHOOT);
			//Temp option because of line of sight
			Talk(SAY_ADS);
			me->SummonCreature(NPC_ASHAVANE_CANNONNEER, summons_pos, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_ASHVANE_DECKHAND, summons_pos, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_ASHVANE_DECKHAND, summons_pos, TEMPSUMMON_MANUAL_DESPAWN);
			events.ScheduleEvent(EVENT_CANNON_BARRAGE, 3s);
			break;

		default:
			break;
		}
	}

	void JustSummoned(Creature* summon) override
	{
		switch (summon->GetEntry())
		{
		case NPC_ASHVANE_DECKHAND:
		case NPC_ASHAVANE_CANNONNEER:
			 instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
			 summon->AI()->DoZoneInCombat();
			 //summon->GetMotionMaster()->MoveJump(623.0f, -243.0f, 12.55f, 3.58f, 30.0f, 30.0f, 0, true);
			 break;

		case NPC_CANNON_BARRAGE:
			 summon->CastSpell(summon, DREAD_VOLLEY_GROUND_MARK);
			 break;

		default:
			break;
		}
	}

	void SummonedCreatureDies(Creature* summon, Unit* killer) override
	{
		switch (summon->GetEntry())
		{
		case NPC_ASHVANE_DECKHAND:
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon);			
			break;

		case NPC_ASHAVANE_CANNONNEER:
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon);
			summon->CastSpell(nullptr, UNSTABLE_ORDNACE_SUMMON);
			if (Creature* lockwood = me->FindNearestCreature(NPC_DREAD_CAPTAIN_LOCKWOOD, 100.0f, true))
			{
				if (lockwood->IsAlive())
				{
					lockwood->AI()->Talk(SAY_CLEAR);
					lockwood->NearTeleportTo(me->GetHomePosition());
					lockwood->ClearUnitState(UNIT_STATE_ROOT);					
					lockwood->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
					me->SetReactState(REACT_AGGRESSIVE);
					events.ScheduleEvent(EVENT_SHOOT, 1s);
					events.ScheduleEvent(EVENT_GUT_SHOT, 3s);
					events.ScheduleEvent(EVENT_CLEAR_THE_DECK, 6s);
					events.ScheduleEvent(EVENT_WITHDRAW, 30s);
				}
			}
			break;

		default:
			break;
		}
	}
	private:	
};

//143618
struct npc_unstable_ordnace : public ScriptedAI
{
	npc_unstable_ordnace(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();		
	}

	void sGossipHello(Player* player) 
	{ 
		me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
		CloseGossipMenuFor(player);
		player->CastSpell(player, UNSTABLE_ORDNACE);
		me->DespawnOrUnsummon();
	}
};

//139277
struct npc_dread_cannon : public ScriptedAI
{
	npc_dread_cannon(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
	}

	void OnSuccessfulSpellCast(SpellInfo const* spell)
	{
		switch (spell->Id)
		{
		case DREAD_VOLLEY_CHANNEL:
			 break;

		default:
			break;
		}
	}

	void UpdateAI(uint32 diff)
	{
		scheduler.Update(diff);
	}

private:
	TaskScheduler scheduler;
};

//500500
struct npc_dread_cannon_bunny : public ScriptedAI
{
	npc_dread_cannon_bunny(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->SetReactState(REACT_PASSIVE);
		me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
		me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
		me->SetDisplayId(16925, 1.0f);
	}

	void DamageTaken(Unit* done_by, uint32& damage) override
	{
		damage = 0;
		if (me->HealthBelowPct(99))
		{
			me->SetFullHealth();
		}
	}

	void UpdateAI(uint32 diff)
	{
		scheduler.Update(diff);
	}

private:
	TaskScheduler scheduler;
};

void AddSC_boss_dread_captain_lockwood()
{
	RegisterCreatureAI(boss_dread_captain_lockwood);
	RegisterCreatureAI(npc_unstable_ordnace);
	RegisterCreatureAI(npc_dread_cannon);
	RegisterCreatureAI(npc_dread_cannon_bunny);
}
