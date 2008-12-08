
#include "precompiled.h"
#include "def_scarlet_monastery.h"
#include "sc_creature.h"

#define ENTRY_PUMPKIN_SHRINE	186267
#define ENTRY_HORSEMAN			23682
#define ENTRY_HEAD				23775
#define ENTRY_PUMPKIN			23694

struct TRINITY_DLL_DECL instance_scarlet_monastery : public ScriptedInstance
{
    instance_scarlet_monastery(Map *Map) : ScriptedInstance(Map) {Initialize();};

    uint64 PumpkinShrineGUID;
	uint64 HorsemanGUID;
	uint64 HeadGUID;
	std::set<uint64> HorsemanAdds;

    void Initialize()
    {
        PumpkinShrineGUID  = 0;
		HorsemanGUID = 0;
		HeadGUID = 0;
		HorsemanAdds.clear();
    }

    void OnObjectCreate(GameObject *go)
    {
        switch(go->GetEntry())
        {
            case ENTRY_PUMPKIN_SHRINE:
				PumpkinShrineGUID = go->GetGUID();break;
        }
    }

	void OnCreatureCreate(Creature *creature, uint32 creature_entry)
    {
        switch(creature_entry)
        {
            case ENTRY_HORSEMAN:	HorsemanGUID = creature->GetGUID(); break;
            case ENTRY_HEAD:		HeadGUID = creature->GetGUID(); break;
			case ENTRY_PUMPKIN:		HorsemanAdds.insert(creature->GetGUID());break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
		switch(type)
        {
		case GAMEOBJECT_PUMPKIN_SHRINE:
			{
			GameObject *Shrine = instance->GetGameObjectInMap(PumpkinShrineGUID);
			if(Shrine)
				Shrine->SetUInt32Value(GAMEOBJECT_STATE,1);
			}break;
		case DATA_HORSEMAN_EVENT:
			if (data == DONE)
			{				
				for(std::set<uint64>::iterator itr = HorsemanAdds.begin(); itr != HorsemanAdds.end(); ++itr)
				{
					Creature* add = instance->GetCreatureInMap(*itr);
					if(add && add->isAlive())
						add->DealDamage(add, add->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
				}
				HorsemanAdds.clear();
				GameObject *Shrine = instance->GetGameObjectInMap(PumpkinShrineGUID);
				if(Shrine)
					Shrine->SetUInt32Value(GAMEOBJECT_STATE,1);
			}
			break;
        }
    }

/*	uint64 GetData64(uint32 type)
	{
        switch(type)
        {
            case GAMEOBJECT_PUMPKIN_SHRINE:	return PumpkinShrineGUID;
			case DATA_HORSEMAN:				return HorsemanGUID;
			case DATA_HEAD:					return HeadGUID;
        }
		return 0; 
	}*/
};

InstanceData* GetInstanceData_instance_scarlet_monastery(Map* map)
{
    return new instance_scarlet_monastery(map);
}

void AddSC_instance_scarlet_monastery()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_scarlet_monastery";
    newscript->GetInstanceData = &GetInstanceData_instance_scarlet_monastery;
    newscript->RegisterSelf();
}
