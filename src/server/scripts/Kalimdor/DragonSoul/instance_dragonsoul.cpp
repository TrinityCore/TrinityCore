/*
 * Copyright (C) 2008-2013 DREAM WOW <http://www.dream-wow.com/>
 * Code by Troxx Rodrigo Alviña
 * 2013-2015
 *
 */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "Map.h"
#include "PoolMgr.h"
#include "AccountMgr.h"
#include "dragonsoul.h"
#include "Player.h"
#include "WorldPacket.h"
#include "WorldSession.h"


class instance_dragonsoul : public InstanceMapScript
{
	public:
		instance_dragonsoul() : InstanceMapScript(DragonSoulScriptName, 967) { }

		struct instance_dragonsoul_InstanceMapScript : public InstanceScript
		{
			instance_dragonsoul_InstanceMapScript(InstanceMap* map) : InstanceScript(map) 
			{
				SetBossNumber(MAX_ENCOUNTER);
				MorchokGUID				= 0;
				KochromGUID				= 0;
				ZonozzGUID 				= 0;
				YorsahjGUID 			= 0;
				HagaraGUID 				= 0;
				UltraxionGUID 			= 0;
				BlackhornGUID 			= 0;
				SpineGUID 				= 0;
				MadnessGUID 			= 0;
				TeamInInstance 			= 0;
			}

			void OnPlayerEnter(Player* player) OVERRIDE
			{
				if (!TeamInInstance)
					TeamInInstance = player->GetTeam();

			}

			void OnCreatureCreate(Creature* creature) OVERRIDE
			{
				if (!TeamInInstance)
				{
					Map::PlayerList const& Players = instance->GetPlayers();
					if (!Players.isEmpty())
						if (Player* player = Players.begin()->GetSource())
							TeamInInstance = player->GetTeam();
				}

				switch (creature->GetEntry())
				{
					case NPC_MORCHOK:
						MorchokGUID = creature->GetGUID();
						break;
					case NPC_KOHCROM:
						KochromGUID = creature->GetGUID();
						break;
					case NPC_ZONOZZ:
						ZonozzGUID = creature->GetGUID();
						break;
					case NPC_YORSAHJ:
						YorsahjGUID = creature->GetGUID();
						break;
					case NPC_HAGARA:
						HagaraGUID = creature->GetGUID();
						break;
					case NPC_ULTRAXION:
						UltraxionGUID = creature->GetGUID();
						break;
					case NPC_BLACKHORN:
						BlackhornGUID = creature->GetGUID();
						break;
					case NPC_SPINE:
						SpineGUID = creature->GetGUID();
						break;
					case NPC_MADNESS:
						MadnessGUID = creature->GetGUID();
						break;
				}
			}

			std::string GetSaveData()
			{
				OUT_SAVE_INST_DATA;
			
				std::ostringstream saveStream;
				saveStream << "H O " << GetBossSaveData();
			
				OUT_SAVE_INST_DATA_COMPLETE;
				return saveStream.str();
			}

			uint64 GetData64(uint32 data) const OVERRIDE
			{
				switch (data)
				{
					case BOSS_MORCHOK:
						return MorchokGUID;
					case NPC_KOHCROM:
						return KochromGUID;
					case BOSS_ZONOZZ:
						return ZonozzGUID;
					case BOSS_YORSAHJ:
						return YorsahjGUID;
					case BOSS_HAGARA:
						return HagaraGUID;
					case BOSS_ULTRAXION:
						return UltraxionGUID;
					case BOSS_BLACKHORN:
						return BlackhornGUID;
					case BOSS_SPINE:
						return SpineGUID;
					case BOSS_MADNESS:
						return MadnessGUID;

				}
			}

			void Load(const char* in)
			{
				if (!in)
				{
					OUT_LOAD_INST_DATA_FAIL;
					return;
				}

				OUT_LOAD_INST_DATA(in);

				char dataHead1, dataHead2;
				uint16 data0, data1;

				std::istringstream loadStream(in);
	            loadStream >> dataHead1 >> dataHead2;

	            if (dataHead1 == 'H' && dataHead2 == 'O')
	            {
	                for (uint32 i = 0; i < EncounterCount; ++i)
	                {
	                    uint32 tmpState;
	                    loadStream >> tmpState;
	                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
	                        tmpState = NOT_STARTED;
	                    SetBossState(i, EncounterState(tmpState));
	                }
	                uint32 tmp;
	                loadStream >> tmp;
	            }
	            else
	                OUT_LOAD_INST_DATA_FAIL;

	            OUT_LOAD_INST_DATA_COMPLETE;


			}

		protected:
			uint64 MorchokGUID;
			uint64 KochromGUID;
			uint64 ZonozzGUID;
			uint64 YorsahjGUID;
			uint64 HagaraGUID;
			uint64 UltraxionGUID;
			uint64 BlackhornGUID;
			uint64 SpineGUID;
			uint64 MadnessGUID;
			uint32 TeamInInstance;

        private:
        	EventMap _events;
		};

		InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
		{
			return new instance_dragonsoul_InstanceMapScript(map);
		}
};

void AddSC_instance_dragonsoul()
{
	new instance_dragonsoul();
}