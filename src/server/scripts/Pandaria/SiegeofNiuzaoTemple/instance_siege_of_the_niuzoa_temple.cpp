/*
    Dungeon : Stormstout Brewery 85-87
    Instance General Script
*/

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "siege_of_the_niuzoa_temple.h"

class instance_siege_of_the_niuzoa_temple : public InstanceMapScript
{
public:
    instance_siege_of_the_niuzoa_temple() : InstanceMapScript("instance_siege_of_the_niuzoa_temple", 1011) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_siege_of_the_niuzoa_temple_InstanceMapScript(map);
    }

    struct instance_siege_of_the_niuzoa_temple_InstanceMapScript : public InstanceScript
    {
        uint64 jinbakGuid;
        uint64 vojakGuid;
        uint64 pavalakGuid;
        uint64 neronokGuid;

        instance_siege_of_the_niuzoa_temple_InstanceMapScript(Map* map) : InstanceScript(map)
        {}

        void Initialize()
        {
            jinbakGuid  = 0;
            vojakGuid   = 0;
            pavalakGuid = 0;
            neronokGuid = 0;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_JINBAK:
                    jinbakGuid = creature->GetGUID().GetEntry();
                    break;
                case NPC_VOJAK:
                    vojakGuid = creature->GetGUID().GetEntry();
                    break;
                case NPC_PAVALAK:
                    pavalakGuid = creature->GetGUID().GetEntry();
                    break;
                case NPC_NERONOK:
                    neronokGuid = creature->GetGUID().GetEntry();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
        }

        void SetData(uint32 type, uint32 data)
        {}

        uint32 GetData(uint32 type) const override
        {
            return 0;
        }

        uint64 GetData64(uint32 type) const override
        {
            switch (type)
            {
                case NPC_JINBAK:    return jinbakGuid;
                case NPC_VOJAK:     return vojakGuid;
                case NPC_PAVALAK:   return pavalakGuid;
                case NPC_NERONOK:   return neronokGuid;
            }

            return 0;
        }
    };

};

void AddSC_instance_siege_of_the_niuzoa_temple()
{
    new instance_siege_of_the_niuzoa_temple();
}
