/*
    http://uwow.biz
    Rogue: Devourer
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"


class instance_devourer : public InstanceMapScript
{
public:
    instance_devourer() : InstanceMapScript("instance_devourer", 1607) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_devourer_InstanceMapScript(map);
    }

    struct instance_devourer_InstanceMapScript : public InstanceScript
    {
        instance_devourer_InstanceMapScript(Map* map) : InstanceScript(map) {}
        
        WorldLocation loc_res_pla;  // for respawn
        std::list<Creature*> trashGUIDconteiner;
        uint32 outrotimer;
        
        void Initialize() override
        {
            trashGUIDconteiner.clear();
            outrotimer = 2000;
        }
        
        void OnCreatureCreate(Creature* creature) override
        {
            if (creature->GetEntry() == 98308 || creature->GetEntry() == 98307 || creature->GetEntry() == 54638)
                trashGUIDconteiner.push_back(creature);
        }
        
        void OnCreatureRemove(Creature* creature) override
        {
            if (creature->GetEntry() == 98308 || creature->GetEntry() == 98307 || creature->GetEntry() == 54638)
                trashGUIDconteiner.remove(creature);
        }
        
        
        WorldLocation* GetClosestGraveYard(float x, float y, float z) override
        // OnPlayerDeath
        {
            // Init data
            loc_res_pla.Relocate(x, y, z);
            loc_res_pla.SetMapId(1607);

            uint32 graveyardId = 5467;
            
            switch(getScenarionStep())
            {
                case 1:
                case 2:
                    graveyardId = 5468;
                    break;
                case 3:
                case 4:
                    graveyardId = 5469;
                    break;
                case 5:
                case 6:
                    graveyardId = 5470;
                    break;
            }

            if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
            {
                loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
                loc_res_pla.SetMapId(gy->MapID);
            }
            return &loc_res_pla;
        }
        
        void Update(uint32 diff) override
        {
            if (getScenarionStep() == 7)
                if (outrotimer <= diff)
                {
                    if (!trashGUIDconteiner.empty())
                        for (auto trash : trashGUIDconteiner)
                        {
                            if (trash && urand(0, 1) == 1)
                                trash->CastSpell(trash, (trash->GetEntry() == 98308 ? 209814 : 209813));
                        }
                    outrotimer = 2000;
                }
                else outrotimer -= diff;
        }
    };
};

void AddSC_instance_devourer()
{
    new instance_devourer();
}
