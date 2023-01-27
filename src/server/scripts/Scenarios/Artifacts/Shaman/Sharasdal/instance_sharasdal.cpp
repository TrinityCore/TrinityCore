/*
    http://uwow.biz
    Shaman: Sharasdal
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"


class instance_sharasdal : public InstanceMapScript
{
public:
    instance_sharasdal() : InstanceMapScript("instance_sharasdal", 1600) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_sharasdal_InstanceMapScript(map);
    }

    struct instance_sharasdal_InstanceMapScript : public InstanceScript
    {
        instance_sharasdal_InstanceMapScript(Map* map) : InstanceScript(map) {}
        
        WorldLocation loc_res_pla;  // for respawn

        WorldLocation* GetClosestGraveYard(float x, float y, float z) override
        // OnPlayerDeath
        {            
            // Init data
            loc_res_pla.Relocate(x, y, z);
            loc_res_pla.SetMapId(1600);
            
            return &loc_res_pla;
        }

        void OnUnitDeath(Unit* creature) override
        {            
            switch (creature->GetEntry())
            {
                case 102792:
                    if (Player* targ = creature->FindNearestPlayer(100.0f))
                    {
                        targ->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 49861);
                        targ->CreateConversation(1693);
                        targ->AddDelayedEvent(5000, [targ] () -> void
                        {
                            if (Creature* grash = targ->FindNearestCreature(105298, 70.0f, true))
                                grash->SetUInt32Value(UNIT_FIELD_NPC_FLAGS, 1); // госсип
                        });
                    }
                    break;
            }
        }
        
        void OnCreatureCreate(Creature* creature) override
        {
            if (creature->GetEntry() == 38821)
            {
                creature->SetFlag(UNIT_FIELD_FLAGS, 0);
                creature->SetVisible(true);
            }
        }
         
        void Update(uint32 diff) override {}
    };
};

void AddSC_instance_sharasdal()
{
    new instance_sharasdal();
}
