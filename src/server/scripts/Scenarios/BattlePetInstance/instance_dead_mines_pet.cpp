/*
    http://uwow.biz
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

class instance_dead_mines_per : public InstanceMapScript
{
public:
    instance_dead_mines_per() : InstanceMapScript("instance_dead_mines_per", 1688) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_dead_mines_per_InstanceMapScript(map);
    }

    struct instance_dead_mines_per_InstanceMapScript : public InstanceScript
    {
        instance_dead_mines_per_InstanceMapScript(Map* map) : InstanceScript(map) {}
        
        ObjectGuid first_step{}, third_step{};
        
        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case 17154:
                    go->SetFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    break;
                case 16399:
                    first_step = go->GetGUID();
                    break;
                case 16397:
                    third_step = go->GetGUID();
                    break;
            }
        }

        void onScenarionNextStep(uint32 newStep) override
        {
            
            ObjectGuid* guid = nullptr;
            switch (newStep)
            {
                case 1:
                    guid = &first_step;
                    break;
                case 3:
                    guid = &third_step;
                    break;
                default:
                    return;
            }

            if (!guid)
                return;
            
            if (GameObject* go = instance->GetGameObject(*guid))
                HandleGameObject(go->GetGUID(), true, go);
        }
        
        void Update(uint32 diff) override {}
    };
};

void AddSC_instance_dead_mines_per()
{
    new instance_dead_mines_per();
}
