///*
//Dungeon : Stormstout Brewery 85-87
//Instance General Script
//*/
//
//#include "ScriptMgr.h"
//#include "InstanceScript.h"
//#include "siege_of_the_niuzoa_temple.h"
//
//class instance_siege_of_the_niuzoa_temple : public InstanceMapScript
//{
//public:
//	instance_siege_of_the_niuzoa_temple() : InstanceMapScript("instance_siege_of_the_niuzoa_temple", 1011) { }
//
//	InstanceScript* GetInstanceScript(InstanceMap* map) const
//	{
//		return new instance_siege_of_the_niuzoa_temple_InstanceMapScript(map);
//	}
//
//	struct instance_siege_of_the_niuzoa_temple_InstanceMapScript : public InstanceScript
//	{
//		uint64 jinbakGuid;
//		uint64 vojakGuid;
//		uint64 pavalakGuid;
//		uint64 neronokGuid;
//
//		instance_siege_of_the_niuzoa_temple_InstanceMapScript(Map* map) : InstanceScript(map)
//		{}
//
//		void Initialize()
//		{
//			jinbakGuid = 0;
//			vojakGuid = 0;
//			pavalakGuid = 0;
//			neronokGuid = 0;
//		}
//
//		void OnCreatureCreate(Creature* creature)
//		{
//			switch (creature->GetEntry())
//			{
//			case NPC_JINBAK:
//				jinbakGuid = creature->GetGUID();
//				break;
//			case NPC_VOJAK:
//				vojakGuid = creature->GetGUID();
//				break;
//			case NPC_PAVALAK:
//				pavalakGuid = creature->GetGUID();
//				break;
//			case NPC_NERONOK:
//				neronokGuid = creature->GetGUID();
//				break;
//			}
//		}
//
//		void OnGameObjectCreate(GameObject* go)
//		{
//		}
//
//		void SetData(uint32 type, uint32 data)
//		{}
//
//		uint32 GetData(uint32 type)
//		{
//			return 0;
//		}
//
//		uint64 GetData64(uint32 id) const
//		{
//			switch (id)
//			{
//			case DATA_JINBAK:    return jinbakGuid;
//			case DATA_VOJAK:     return vojakGuid;
//			case DATA_PAVALAK:   return pavalakGuid;
//			case DATA_NERONOK:   return neronokGuid;
//			}
//
//			return 0;
//		}
//	};
//
//};
//
//void AddSC_instance_siege_of_the_niuzoa_temple()
//{
//	new instance_siege_of_the_niuzoa_temple();
//}
