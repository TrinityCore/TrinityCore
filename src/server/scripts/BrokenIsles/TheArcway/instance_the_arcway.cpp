#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "the_arcway.h"

class instance_the_arcway : public InstanceMapScript
{
public:
    instance_the_arcway() : InstanceMapScript(ArcwayScriptName, ArcwayMapId) { }

    struct instance_the_arcway_InstanceMapScript : public InstanceScript
    {
    public:
        instance_the_arcway_InstanceMapScript(InstanceMap *map) : InstanceScript(map)
        {
            SetHeaders(ArcwayDataHeaders);
            SetBossNumber(EncounterCount);
        }

        void OnCreatureCreate(Creature *creature)
        {
            switch (creature->GetEntry())
            {
            case NPC_CORSTILAX:
                corstilaxGUID = creature->GetGUID();
                break;
            }
        }
    
    protected:
        ObjectGuid corstilaxGUID;
    };

    InstanceScript *GetInstanceScript(InstanceMap *map) const override
    {
        return new instance_the_arcway_InstanceMapScript(map);
    }
};

void AddSC_instance_the_arcway()
{
    new instance_the_arcway();
}
