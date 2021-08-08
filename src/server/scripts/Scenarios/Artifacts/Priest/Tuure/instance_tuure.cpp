/*
    http://uwow.biz
    Priest: Tuure
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"


class instance_tuure : public InstanceMapScript
{
public:
    instance_tuure() : InstanceMapScript("instance_tuure", 1489) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_tuure_InstanceMapScript(map);
    }

    struct instance_tuure_InstanceMapScript : public InstanceScript
    {
        instance_tuure_InstanceMapScript(Map* map) : InstanceScript(map) {}
        
        WorldLocation loc_res_pla;  // for respawn

        WorldLocation* GetClosestGraveYard(float x, float y, float z) override
        // OnPlayerDeath
        {            
            // Init data
            loc_res_pla.Relocate(x, y, z);
            loc_res_pla.SetMapId(1489);
            
            return &loc_res_pla;
        }

        void OnUnitDeath(Unit* creature) override
        {            
            switch (creature->GetEntry())
            {
                case 106221:
                    if (Creature* targ = creature->FindNearestCreature(106134, 100.0f, true))
                        targ->AI()->DoAction(1);
                    break;
            }
        }
         
        void Update(uint32 diff) override {}
    };
};

void AddSC_instance_tuure()
{
    new instance_tuure();
}
