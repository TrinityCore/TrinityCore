/*
    http://uwow.biz
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

class instance_walling_caverns_pet : public InstanceMapScript
{
public:
    instance_walling_caverns_pet() : InstanceMapScript("instance_walling_caverns_pet", 1687) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_walling_caverns_pet_InstanceMapScript(map);
    }

    struct instance_walling_caverns_pet_InstanceMapScript : public InstanceScript
    {
        instance_walling_caverns_pet_InstanceMapScript(Map* map) : InstanceScript(map) {}
        
        std::list<ObjectGuid> gobs{};

        
        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case 266872:
                    gobs.push_back(go->GetGUID());
                    break;
            }
        }

        void onScenarionNextStep(uint32 newStep) override
        {
            gobs.sort([&](const ObjectGuid& guid1, const ObjectGuid& guid2)
            {
                GameObject* go1 = instance->GetGameObject(guid1);
                GameObject* go2 = instance->GetGameObject(guid2);
                if (!go1 || !go2)
                    return true; 

                return go1->GetDBTableGUIDLow() < go2->GetDBTableGUIDLow();
            });

            uint8 i = 0;
            for (const auto& guid : gobs)
            {
                if (i != 2 && i != 5)
                    if (GameObject* go = instance->GetGameObject(guid))
                        go->SetFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                ++i;
            }

            i = 0;
            switch (newStep)
            {
                case 2:
                    i = 0;
                    break;
                case 4:
                    i = 2;
                    break;
                case 5:
                    i = 3;
                    break;
                default:
                    return;
            }

            
            if (i >= gobs.size())
                return;

            auto itr = gobs.begin();
            std::advance(itr, i);
            if (GameObject* go = instance->GetGameObject(*itr))
                HandleGameObject(go->GetGUID(), true, go);
        }
        
        void Update(uint32 diff) override {}
    };
};

void AddSC_instance_walling_caverns_pet()
{
    new instance_walling_caverns_pet();
}
