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
#include "TaskScheduler.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Map.h"

enum JainaTexts
{
	SAY_OUTRO_1 = 0,
	SAY_OUTRO_2 = 1
};

enum Misc
{
	ENCOUNTER_ID = 2100,
};

enum Events
{
	EVENT_ERADICATION = 1,
	EVENT_PUTRID_WATERS,
	EVENT_CHECK_PLAYERS,
};

enum Spells
{
	TERROR_FROM_BELOW_SCREEN_EFFECT = 279897,
	ERADICATION_MISSILE = 269456,
	PUTRID_WATERS = 275014,
	PUTRID_WATERS_EXP = 275051,
	BLAST_SS = 269416,
	BLAST_MISSILE = 269420,
};

//128652
struct boss_viqgoth : public BossAI
{
	boss_viqgoth(Creature* creature) : BossAI(creature, DATA_VIQGOTH) { }

	void Reset() override
	{
		BossAI::Reset();		
		me->SetReactState(REACT_PASSIVE);
		me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);		
		me->SetSwim(true);
		this->encountered = 0;
	}

	void EnterEvadeMode(EvadeReason why) override
	{
		if (me->getThreatManager().isThreatListEmpty() && this->encountered == 1 && me->HealthAbovePct(1) && instance->GetBossState(DATA_VIQGOTH == IN_PROGRESS))
		{
			if (Creature* viqgoth = me->FindNearestCreature(NPC_VIQGOTH, 100.0f, true))
			{
				viqgoth->GetScheduler().Schedule(1s, [viqgoth] (TaskContext context)
				{
					viqgoth->AI()->JustReachedHome();
					viqgoth->ForcedDespawn(1, 5s);
					std::list<Creature*> c_list;
					viqgoth->GetCreatureListWithEntryInGrid(c_list, NPC_DEMOLISHING_TERROR, 250.0f);
					viqgoth->GetCreatureListWithEntryInGrid(c_list, NPC_GRIPPING_TERROR, 250.0f);
					for (auto & creatures : c_list)
					{						
						creatures->AI()->EnterEvadeMode();
					}					
				});					
				std::list<Creature*> c_list;
				viqgoth->GetCreatureListWithEntryInGrid(c_list, NPC_DEMOLISHING_TERROR, 250.0f);
				viqgoth->GetCreatureListWithEntryInGrid(c_list, NPC_GRIPPING_TERROR, 250.0f);
				for (auto & creatures : c_list)
				instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, creatures);
				this->encountered = 0;
			}
		}		
	}

	void EnterCombat(Unit* u) override
	{
		_EnterCombat();
		//events.ScheduleEvent(EVENT_ERADICATION, 3s);
		events.ScheduleEvent(EVENT_PUTRID_WATERS, 6s);
		instance->SetBossState(DATA_VIQGOTH, IN_PROGRESS);
		this->encountered = 1;
	}

	void ExecuteEvent(uint32 eventid) override
	{
		switch (eventid)
		{
		case EVENT_ERADICATION:		
		{
			std::list<Player*> p_list;
			me->GetPlayerListInGrid(p_list, 250.0f);
			for (auto & players : p_list)
			me->AI()->DoCast(players, ERADICATION_MISSILE);
		}
		events.Repeat(15s);		
		break;

		case EVENT_PUTRID_WATERS:
		{
			std::list<Player*> p_list;
			me->GetPlayerListInGrid(p_list, 150.0f);
			for (auto & players : p_list)
			me->AI()->DoCast(players, PUTRID_WATERS);
		}
		events.Repeat(20s);
		break;

		default:
			break;
		}
	}

	void JustDied(Unit* u) override
	{	
		_JustDied();
	};

private:
	uint8 encountered;
};

enum DemolishingEvents
{
	EVENT_SLAM = 1,
	EVENT_HULLCRACKER
};

enum DemolishingSpells
{
	SLAM = 269266,
	HULLCRACKER = 270590
};

//137614
struct npc_demolishing_terror : public ScriptedAI
{
	npc_demolishing_terror(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		events.ScheduleEvent(EVENT_HULLCRACKER, 1s);
	}

	void EnterCombat(Unit* u) override
	{
		instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
		events.ScheduleEvent(EVENT_SLAM, 1s);

		if (Creature* viqgoth = me->FindNearestCreature(NPC_VIQGOTH, 100.0f, true))
		{
			if (viqgoth->IsAlive())
			{
				if (viqgoth->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE) && !viqgoth->IsInCombat())
				{
					viqgoth->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
					viqgoth->AI()->DoZoneInCombat(nullptr, 250.0f);
				}
				if (Creature* gripping_terror = me->FindNearestCreature(NPC_GRIPPING_TERROR, 100.0f, true))
				{
					if (gripping_terror->GetDistance(me) > 45.0f && gripping_terror->GetDistance(me) < 50.0f)
					{
						instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, gripping_terror);
					}					
				}
			}
		}
	}

	void ExecuteEvent(uint32 eventid) override
	{
		switch (eventid)
		{
		case EVENT_SLAM:
			if (Unit* tar = SelectTarget(SELECT_TARGET_RANDOM, 0, 35.0f, true))
			{
				DoCastAOE(SLAM, false);
			}
			events.Repeat(15s);	
			break;

		case EVENT_HULLCRACKER:
			if (me->IsInCombat())
			{
				DoCast(HULLCRACKER);
			}
			events.Repeat(17s);
			break;	

		default:
			break;
		}
	}

	void JustDied(Unit* u) override
	{		
		instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
	}
};

//137123
struct npc_cannon_viq : public ScriptedAI
{
	npc_cannon_viq(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{		

	}

	void sGossipHello(Player* player)
	{	
		CloseGossipMenuFor(player);
		//me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
		if (Creature* viqgoth = me->FindNearestCreature(NPC_VIQGOTH, 100.0f, true))
		{
			if (viqgoth->IsAlive() && viqgoth->IsInCombat())
			{				
				me->CastSpell(viqgoth, BLAST_SS, true);
				me->CastSpell(viqgoth, BLAST_MISSILE, true);
				float viqGothPct = (float)(this->cannon_count * 33) / 100;
				uint64 viqGothHealth = (viqgoth->GetMaxHealth() - (viqgoth->GetMaxHealth() * viqGothPct));
				viqgoth->SetHealth(viqGothHealth);
				//player->Kill(me);
				this->cannon_count++;
			}

			if (this->cannon_count == 3)
			{				
				events.CancelEvent(EVENT_PUTRID_WATERS);
				if (Creature* viqgoth = me->FindNearestCreature(NPC_VIQGOTH, 100.0f, true))
				{					
					if (viqgoth->IsAlive())
					{	
						viqgoth->AI()->JustDied(nullptr);
						events.CancelEvent(EVENT_PUTRID_WATERS);
						events.CancelEvent(EVENT_ERADICATION);
						viqgoth->SetReactState(REACT_PASSIVE);
						instance->SetBossState(DATA_VIQGOTH, DONE);	
						instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, viqgoth);
						viqgoth->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
						viqgoth->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
						viqgoth->RemoveAllAuras();
						viqgoth->SetCanTransitionBetweenSwimAndFly(true);
						viqgoth->SetSwim(true);
						viqgoth->SetSpeedRate(MOVE_SWIM, 1.5f);
						viqgoth->UpdateSpeed(MOVE_SWIM);
						viqgoth->GetMotionMaster()->MovePoint(1, 84.71f, -268.0f, -3.48f, true);				
						viqgoth->DespawnCreaturesInArea(NPC_DEMOLISHING_TERROR);
						viqgoth->DespawnCreaturesInArea(NPC_GRIPPING_TERROR);
						viqgoth->DespawnCreaturesInArea(NPC_CANNON_VIQ_ENCOUNTER);						
						instance->SendBossKillCredit(ENCOUNTER_ID);
						viqgoth->DespawnOrUnsummon(20s);
						std::list<Player*> p_li;
						viqgoth->GetPlayerListInGrid(p_li, 500.0f);
						for (auto & players : p_li)
						{
							players->KilledMonsterCredit(viqgoth->GetEntry());
						}						
						if (Creature* jaina = me->FindNearestCreature(NPC_JAINA_SOB_ALI_OUTRO_ALI, 100.0f, true))
						{
							jaina->SetVisible(true);
							if (jaina->IsAlive())
							{
								jaina->GetScheduler().Schedule(3s, [jaina] (TaskContext context)
								{
									jaina->AI()->Talk(SAY_OUTRO_1);
								});
								
								jaina->GetScheduler().Schedule(9s, [jaina] (TaskContext context)
								{
									jaina->AI()->Talk(SAY_OUTRO_2);
								});

								jaina->GetScheduler().Schedule(10s, [jaina] (TaskContext context)
								{								
									jaina->SummonGameObject(GO_TREASURE_RICH_FLOTSAM, 226.745f, -180.668f, 0.607619f, 0.0166253f, QuaternionData(), false);
								});

								if (IsMythic() && instance->IsChallengeModeStarted())
								{
									jaina->SummonGameObject(GO_CHALLENGERS_CACHE_BORALUS, 230.170f, -181.269f, 0.581000f, 3.05467f, QuaternionData(), false);								
								}
							}
						}
					}
				}
			}
		}
	}

private:
	uint16 cannon_count;
};

//142486
struct npc_jaina_sob_outro_ali : public ScriptedAI
{
	npc_jaina_sob_outro_ali(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
		me->SetVisible(false);
	}

	void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
	{
		if (player->GetTeam() != HORDE)
		{			
			CloseGossipMenuFor(player);
			player->TeleportTo(1643, 1080.0f, -623.0f, 17.55f, 1.67f);
		}
		else
		{
			CloseGossipMenuFor(player);
			player->TeleportTo(1643, -313.0f, -1571.0f, 0.75f, 0.7f);
		}
	}

	void UpdateAI(uint32 diff)
	{
		scheduler.Update(diff);
	}

private:
	TaskScheduler scheduler;
};

void AddSC_boss_viqgoth()
{
	RegisterCreatureAI(boss_viqgoth);
	RegisterCreatureAI(npc_demolishing_terror);
	RegisterCreatureAI(npc_cannon_viq);
	RegisterCreatureAI(npc_jaina_sob_outro_ali);
}
