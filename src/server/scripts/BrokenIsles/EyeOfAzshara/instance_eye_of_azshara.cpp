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

#include "GameObject.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "eye_of_azshara.h"

DoorData const doorData[] =
{
	{ GO_WATER_DOOR, DATA_KING_DEEPBEARD, DOOR_TYPE_ROOM },
{ 0, 0, DOOR_TYPE_ROOM }
};

class instance_eye_of_azshara : public InstanceMapScript
{
public:
	instance_eye_of_azshara() : InstanceMapScript(EoAScriptName, 1456)
	{}

	struct instance_eye_of_azshara_InstanceScript : public InstanceScript
	{
		instance_eye_of_azshara_InstanceScript(InstanceMap* map) : InstanceScript(map)
		{
			SetHeaders(DataHeader);
			SetBossNumber(EncounterCount);
			LoadDoorData(doorData);
			_parjeshGUID = ObjectGuid::Empty;
			_ladyHatecoilGUID = ObjectGuid::Empty;
			_ladyIntro = NOT_STARTED;
			_wrathIntro = NOT_STARTED;
			_ritualEvent = NOT_STARTED;
			_ritualistDeads = 0;
			_bossesDone = 0;
			_ritualists.clear();
			_serpentrixGUID = ObjectGuid::Empty;
			_kingDeepbeardGUID = ObjectGuid::Empty;
			_wrathOfAzsharaGUID = ObjectGuid::Empty;
		}

		void OnCreatureCreate(Creature* creature) override
		{
			if (!creature)
				return;

			switch (creature->GetEntry())
			{
			case BOSS_PARJESH:
				_parjeshGUID = creature->GetGUID();
				break;

			case BOSS_LADY_HATECOIL:
				_ladyHatecoilGUID = creature->GetGUID();
				break;

			case BOSS_SERPENTRIX:
				_serpentrixGUID = creature->GetGUID();
				break;

			case BOSS_KING_DEEPBEARD:
				_kingDeepbeardGUID = creature->GetGUID();
				break;

			case BOSS_WRATH_OF_AZSHARA:
				_wrathOfAzsharaGUID = creature->GetGUID();
				break;

			case NPC_RITUALIST_LESHA:
			case NPC_CHANNELER_VARISZ:
			case NPC_BINDER_ASHIOIS:
			case NPC_MYSTIC_SSAVEH:
				_ritualists.push_back(creature);
				break;

			default: break;
			}
		}

		void OnGameObjectCreate(GameObject* go) override
		{
			if (!go)
				return;

			switch (go->GetEntry())
			{
			case GO_WATER_DOOR:
				AddDoor(go, true);
				break;
			}
		}

		void OnGameObjectRemove(GameObject* go) override
		{
			if (!go)
				return;

			switch (go->GetEntry())
			{
			case GO_WATER_DOOR:
				AddDoor(go, false);
				break;
			}
		}

		bool SetBossState(uint32 id, EncounterState state) override
		{
			if (!InstanceScript::SetBossState(id, state))
				return false;

			if (state == DONE)
			{
				_bossesDone++;

				if (_bossesDone >= 4 && GetData(DATA_RITUAL_EVENT) != DONE)
				{
					SetData(DATA_RITUAL_EVENT, DONE);

					if (!_ritualists.empty())
					{
						for (auto & it : _ritualists)
						{
							if (it->IsAlive())
								it->AI()->DoAction(2); // ACTION_BOSSES_DEAD
						}
					}
				}
			}

			return true;
		}

		void OnUnitDeath(Unit* unit) override
		{
			if (!unit)
				return;

			switch (unit->GetEntry())
			{
			case NPC_HATECOIL_ARCANIST:
			{
				if (Creature* ladyHatecoil = instance->GetCreature(_ladyHatecoilGUID))
					ladyHatecoil->AI()->DoAction(2); // ACTION_REMOVE_SHIELD
				break;
			}

			case NPC_RITUALIST_LESHA:
			case NPC_CHANNELER_VARISZ:
			case NPC_BINDER_ASHIOIS:
			case NPC_MYSTIC_SSAVEH:
			{
				_ritualistDeads++;
				if (_ritualistDeads >= 4 && GetData(DATA_WRATH_INTRO) != DONE)
				{
					Creature* wrath = instance->GetCreature(_wrathOfAzsharaGUID);

					if (wrath)
						wrath->AI()->DoAction(1); // ACTION_RITUALIST_DEAD
				}

				break;
			}

			default: break;

			}
		}

		uint32 GetData(uint32 type) const override
		{
			switch (type)
			{
			case DATA_LADY_INTRO: return _ladyIntro;
			case DATA_WRATH_INTRO: return _wrathIntro;
			case DATA_RITUAL_EVENT: return _ritualEvent;

			default: break;
			}

			return 0;
		}

		void SetData(uint32 type, uint32 data) override
		{
			switch (type)
			{
			case DATA_LADY_INTRO:
				_ladyIntro = data;
				break;

			case DATA_WRATH_INTRO:
				_wrathIntro = data;
				break;

			case DATA_RITUAL_EVENT:
				_ritualEvent = data;
				break;

			default: break;
			}

			if (data == DONE)
				SaveToDB();
		}

		ObjectGuid GetGuidData(uint32 data) const override
		{
			switch (data)
			{
			case DATA_PARJESH: return _parjeshGUID;
			case DATA_LADY_HATECOIL: return _ladyHatecoilGUID;
			case DATA_SERPENTRIX: return _serpentrixGUID;
			case DATA_KING_DEEPBEARD: return _kingDeepbeardGUID;
			case DATA_WRATH_OF_AZSHARA: return _wrathOfAzsharaGUID;

			default: break;
			}

			return ObjectGuid::Empty;
		}

		void WriteSaveDataMore(std::ostringstream& data) override
		{
			data << _ladyIntro << ' ' << _wrathIntro << ' ' << _ritualistDeads <<
				' ' << _ritualEvent << ' ' << _bossesDone;
		}

		void ReadSaveDataMore(std::istringstream& data) override
		{
			data >> _ladyIntro;
			data >> _wrathIntro;
			data >> _ritualistDeads;
			data >> _ritualEvent;
			data >> _bossesDone;
		}

	private:
		ObjectGuid _parjeshGUID;
		ObjectGuid _ladyHatecoilGUID;
		ObjectGuid _serpentrixGUID;
		ObjectGuid _kingDeepbeardGUID;
		ObjectGuid _wrathOfAzsharaGUID;
		uint32 _ladyIntro;
		uint32 _wrathIntro;
		uint32 _ritualEvent;
		uint8 _ritualistDeads;
		uint8 _bossesDone;
		std::list<Creature*> _ritualists;
	};

	InstanceScript* GetInstanceScript(InstanceMap* map) const override
	{
		return new instance_eye_of_azshara_InstanceScript(map);
	}
};

void AddSC_instance_eye_of_azshara()
{
	new instance_eye_of_azshara();
}
