/*
* Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

/*
Name:     Black_Temple
Complete: 100%
Comment:  Spirit of Olum: Player Teleporter to Seer Kanai Teleport after defeating Naj'entus and Supremus.
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "black_temple.h"
#include "Player.h"

enum Spells
{
	// Spirit of Olum
	SPELL_TELEPORT = 41566,
	SPELL_TELEPORT_2 = 41570,
	// Wrathbone Flayer
	SPELL_CLEAVE = 15496,
	SPELL_IGNORED = 39544,
	SPELL_SUMMON_CHANNEL = 40094
};

enum Creatures
{
	NPC_BLOOD_MAGE = 22945,
	NPC_DEATHSHAPER = 22882
};

enum Events
{
	// Wrathbone Flayer
	EVENT_GET_CHANNELERS = 1,
	EVENT_SET_CHANNELERS = 2,
	EVENT_CLEAVE = 3,
	EVENT_IGNORED = 4,
};

// ########################################################
// Spirit of Olum
// ########################################################
#define OZ_GOSSIP1          "Take me to the other Deathsworn, Olum."
#define OZ_GOSSIP2          "I'm ready.  Take me to the Chamber of Command."

class npc_spirit_of_olum : public CreatureScript
{
public:
	npc_spirit_of_olum() : CreatureScript("npc_spirit_of_olum") { }

	bool OnGossipHello(Player* player, Creature* creature) override
	{
		if (InstanceScript* instance = creature->GetInstanceScript())
		{
			if (instance->GetBossState(DATA_SUPREMUS) == DONE)
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, OZ_GOSSIP1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
			if (instance->GetBossState(DATA_ILLIDARI_COUNCIL) == DONE)
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, OZ_GOSSIP2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
			if (instance->GetBossState(DATA_SUPREMUS) == DONE || instance->GetBossState(DATA_ILLIDARI_COUNCIL) == DONE)
				player->SEND_GOSSIP_MENU(11081, creature->GetGUID());
			else
				player->SEND_GOSSIP_MENU(11082, creature->GetGUID());
		}
		return true;
	}

	

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
	{
		switch (action)
		{
		case GOSSIP_ACTION_INFO_DEF:
			player->CLOSE_GOSSIP_MENU();
			player->InterruptNonMeleeSpells(false);
			player->CastSpell(player, SPELL_TELEPORT, false);
			break;
		case GOSSIP_ACTION_INFO_DEF +1:
			player->CLOSE_GOSSIP_MENU();
			player->InterruptNonMeleeSpells(false);
			player->CastSpell(player, SPELL_TELEPORT_2, false);
			break;
		}
		return true;
	}
};

// ########################################################
// Spirit of Udalo
// ########################################################
#define UD_GOSSIP1          "I'm ready.  Take me to the Chamber of Command."

class npc_Spirit_of_Udalo : public CreatureScript
{
public:
	npc_Spirit_of_Udalo() : CreatureScript("npc_Spirit_of_Udalo") { }

	bool OnGossipHello(Player* player, Creature* creature) override
	{
		if (InstanceScript* instance = creature->GetInstanceScript())
		{
			if (instance->GetBossState(DATA_ILLIDARI_COUNCIL) == DONE)
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, UD_GOSSIP1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
				player->SEND_GOSSIP_MENU(11077, creature->GetGUID());
			}
			else
				player->SEND_GOSSIP_MENU(11078, creature->GetGUID());
		}
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
	{
		switch (action)
		{
		case GOSSIP_ACTION_INFO_DEF:
			player->CLOSE_GOSSIP_MENU();
			player->InterruptNonMeleeSpells(false);
			player->CastSpell(player, SPELL_TELEPORT_2, false);
			break;
		}
		return true;
	}
};

void AddSc_npc_Spirit_of_Udalo()
{
new npc_Spirit_of_Udalo();
}

// ########################################################
// Wrathbone Flayer
// ########################################################

class npc_wrathbone_flayer : public CreatureScript
{
public:
	npc_wrathbone_flayer() : CreatureScript("npc_wrathbone_flayer") { }

	struct npc_wrathbone_flayerAI : public ScriptedAI
	{
		npc_wrathbone_flayerAI(Creature* creature) : ScriptedAI(creature)
		{
			Initialize();
			_instance = creature->GetInstanceScript();
		}

		void Initialize()
		{
			_enteredCombat = false;
		}

		void Reset() override
		{
			_events.ScheduleEvent(EVENT_GET_CHANNELERS, 3000);
			Initialize();
			_bloodmageList.clear();
			_deathshaperList.clear();
		}

		void JustDied(Unit* /*killer*/) override { }

		void EnterCombat(Unit* /*who*/) override
		{
			_events.ScheduleEvent(EVENT_CLEAVE, 5000);
			_events.ScheduleEvent(EVENT_IGNORED, 7000);
			_enteredCombat = true;
		}

		void UpdateAI(uint32 diff) override
		{

			if (!_enteredCombat)
			{
				_events.Update(diff);

				while (uint32 eventId = _events.ExecuteEvent())
				{
					switch (eventId)
					{
					case EVENT_GET_CHANNELERS:
					{
												 std::list<Creature*> BloodMageList;
												 me->GetCreatureListWithEntryInGrid(BloodMageList, NPC_BLOOD_MAGE, 15.0f);

												 if (!BloodMageList.empty())
												 for (std::list<Creature*>::const_iterator itr = BloodMageList.begin(); itr != BloodMageList.end(); ++itr)
												 {
													 _bloodmageList.push_back((*itr)->GetGUID());
													 if ((*itr)->isDead())
														 (*itr)->Respawn();
												 }

												 std::list<Creature*> DeathShaperList;
												 me->GetCreatureListWithEntryInGrid(DeathShaperList, NPC_DEATHSHAPER, 15.0f);

												 if (!DeathShaperList.empty())
												 for (std::list<Creature*>::const_iterator itr = DeathShaperList.begin(); itr != DeathShaperList.end(); ++itr)
												 {
													 _deathshaperList.push_back((*itr)->GetGUID());
													 if ((*itr)->isDead())
														 (*itr)->Respawn();
												 }

												 _events.ScheduleEvent(EVENT_SET_CHANNELERS, 3000);

												 break;
					}
					case EVENT_SET_CHANNELERS:
					{
												 for (ObjectGuid guid : _bloodmageList)
												 if (Creature* bloodmage = ObjectAccessor::GetCreature(*me, guid))
													 bloodmage->CastSpell((Unit*)NULL, SPELL_SUMMON_CHANNEL);

												 for (ObjectGuid guid : _deathshaperList)
												 if (Creature* deathshaper = ObjectAccessor::GetCreature(*me, guid))
													 deathshaper->CastSpell((Unit*)NULL, SPELL_SUMMON_CHANNEL);

												 _events.ScheduleEvent(EVENT_SET_CHANNELERS, 12000);

												 break;
					}
					default:
						break;
					}
				}
			}

			if (!UpdateVictim())
				return;

			_events.Update(diff);

			while (uint32 eventId = _events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_CLEAVE:
					DoCastVictim(SPELL_CLEAVE);
					_events.ScheduleEvent(EVENT_CLEAVE, urand(1000, 2000));
					break;
				case EVENT_IGNORED:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
						DoCast(target, SPELL_IGNORED);
					_events.ScheduleEvent(EVENT_IGNORED, 10000);
					break;
				default:
					break;
				}
			}
			DoMeleeAttackIfReady();
		}

	private:
		InstanceScript* _instance;
		EventMap _events;
		GuidList _bloodmageList;
		GuidList _deathshaperList;
		bool _enteredCombat;
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return GetInstanceAI<npc_wrathbone_flayerAI>(creature);
	}
};

void AddSC_black_temple()
{
	new npc_spirit_of_olum();
	new npc_wrathbone_flayer();
	new npc_Spirit_of_Udalo();
}
