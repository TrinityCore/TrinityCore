/*
    http://uwow.biz
    Invasion Stormheim
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScenarioMgr.h"
#include "Scenario.h"

class instance_invasion_stormheim : public InstanceMapScript
{
public:
    instance_invasion_stormheim() : InstanceMapScript("instance_invasion_stormheim", 1707) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_invasion_stormheim_InstanceMapScript(map);
    }

    struct instance_invasion_stormheim_InstanceMapScript : public InstanceScript
    {
        instance_invasion_stormheim_InstanceMapScript(Map* map) : InstanceScript(map) {}
        
        WorldLocation loc_res_pla;  // for respawn

        WorldLocation* GetClosestGraveYard(float x, float y, float z) override
        // OnPlayerDeath
        {            
            // Init data
            loc_res_pla.Relocate(x, y, z);
            loc_res_pla.SetMapId(1707);
            
            uint32 graveyardId = 5913;
            if (getScenarionStep() >= 2)
                graveyardId = 5911;

            if (WorldSafeLocsEntry const* gy = sWorldSafeLocsStore.LookupEntry(graveyardId))
            {
                loc_res_pla.Relocate(gy->Loc.X, gy->Loc.Y, gy->Loc.Z);
                loc_res_pla.SetMapId(gy->MapID);
            }
            
            return &loc_res_pla;
        }   
        
        void OnPlayerEnter(Player* player) override
        {
            if (!player)
                return;

            if (player->GetQuestStatus(46110) != QUEST_STATUS_INCOMPLETE)
            {
                player->AddDelayedEvent(2000, [player]() -> void
                {
                    player->TeleportTo(1220, -834.95f, 4277.59f, 746.25f, 1.0f);
                });
                return;
            }

            player->AddDelayedEvent(5000, [player] () -> void
            {
                player->CreateConversation(4527);
            });
        }

        void OnUnitDeath(Unit* creature) override
        {
            switch(creature->GetEntry())
            {
                case 119016:
                case 118838:
                case 118915:
                case 118808:
                case 118800:
                case 118807:
                    updateCriteriaForPlayers(56622);
                    updateCriteriaForPlayers(56826);
                    updateCriteriaForPlayers(56606);
                    break;
            }
        }
        
        
        void updateCriteriaForPlayers(int32 objective)
        {
            Map::PlayerList const &PlList = instance->GetPlayers();

            if (PlList.isEmpty())
                return;
            
            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                if (Player* player = i->getSource())
                {
                    if (objective > 0)
                        player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, objective);
                    else
                        player->CreateConversation(abs(objective));
                    break;
                }
        }
        
        void onScenarionNextStep(uint32 newStep) override
        {
            switch(newStep)
            {
                case 1:
                    updateCriteriaForPlayers(-4528);
                    break;
                case 2:
                    updateCriteriaForPlayers(-4529);
                    break;
                case 4:
                    updateCriteriaForPlayers(-4533);
                    break;
                case 5:
                    updateCriteriaForPlayers(-4530);
                    break;
            }
        }
        
    };
};

void AddSC_instance_invasion_stormheim()
{
    new instance_invasion_stormheim();
}
