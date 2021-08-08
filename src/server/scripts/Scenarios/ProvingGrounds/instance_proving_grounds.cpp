
#include "proving_grounds.h"

class instance_proving_grounds : public InstanceMapScript
{
public:
    instance_proving_grounds() : InstanceMapScript("instance_proving_grounds", 1148) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_proving_grounds_InstanceMapScript(map);
    }

    struct instance_proving_grounds_InstanceMapScript : public InstanceScript
    {
        instance_proving_grounds_InstanceMapScript(Map* map) : InstanceScript(map)
        { }

        void Initialize() override
        {
        }

        void OnPlayerEnter(Player* player) override
        {
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case 0:
                default:
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case 0:
                default:
                    return ObjectGuid::Empty;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case 0:
                default:
                    return 0;
            }
        }
    };
};

void AddSC_instance_proving_grounds()
{
    new instance_proving_grounds();
}
