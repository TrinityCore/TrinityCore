/*
    http://uwow.biz
    Monk Specialization: Brewmaster
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"


class instance_temple_of_the_jade_serpent : public InstanceMapScript
{
public:
    instance_temple_of_the_jade_serpent() : InstanceMapScript("instance_temple_of_the_jade_serpent", 1625) {}

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_temple_of_the_jade_serpent_InstanceMapScript(map);
    }

    struct instance_temple_of_the_jade_serpent_InstanceMapScript : public InstanceScript
    {
        instance_temple_of_the_jade_serpent_InstanceMapScript(Map* map) : InstanceScript(map) {}

        uint8 diedCounter;
        ObjectGuid YulonGUID;

        void Initialize() override
        {
            YulonGUID.Clear();
            diedCounter = 0;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case 109391:
                    YulonGUID = creature->GetGUID();
                    break;
            }
        }

        void CreatureDies(Creature* creature, Unit* /*killer*/) override
        {
            switch (creature->GetEntry())
            {
                case 110471:
                case 109933:
                case 109511:
                case 109438:
                    diedCounter++;
                    if (diedCounter == 32)
                    {
                        if (Creature* Yulon = instance->GetCreature(YulonGUID))
                            Yulon->AI()->SetData(2, 2);
                    }
                    break;
            }
        }
        
        void onScenarionNextStep(uint32 newStep) override {}
    };
};

void AddSC_instance_temple_of_the_jade_serpent()
{
    new instance_temple_of_the_jade_serpent();
}
