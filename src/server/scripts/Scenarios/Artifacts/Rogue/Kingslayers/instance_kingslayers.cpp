/*
    http://uwow.biz
    Rogue: Kingslayers
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"


class instance_kingslayers : public InstanceMapScript
{
public:
    instance_kingslayers() : InstanceMapScript("instance_kingslayers", 1620) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_kingslayers_InstanceMapScript(map);
    }

    struct instance_kingslayers_InstanceMapScript : public InstanceScript
    {
        instance_kingslayers_InstanceMapScript(Map* map) : InstanceScript(map) {}
        
        WorldLocation loc_res_pla;  // for respawn

        WorldLocation* GetClosestGraveYard(float x, float y, float z) override
        // OnPlayerDeath
        {
            // Init data
            loc_res_pla.Relocate(x, y, z);
            loc_res_pla.SetMapId(1620);

            uint32 graveyardId = 5518;
            
            switch(getScenarionStep())
            {
                case 0:
                case 1:
                    graveyardId = 5518;
                    break;
                case 2:
                case 3:
                case 4:
                    graveyardId = 5528;
                    break;
                case 5:
                case 6:
                    graveyardId = 5529;
                    break;
                case 7:
                case 8:
                case 9:
                    graveyardId = 5530;
                    break;
            }

            if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
            {
                loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
                loc_res_pla.SetMapId(gy->MapID);
            }
            return &loc_res_pla;
        }
        
        void Update(uint32 diff) override {}
    };
};

void AddSC_instance_kingslayers()
{
    new instance_kingslayers();
}
