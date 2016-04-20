
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "iron_docks.h"

class instance_iron_docks : public InstanceMapScript
{
    public:
        instance_iron_docks() : InstanceMapScript(IronDocksScriptName, 1195) { }

        struct instance_iron_docks_InstanceScript : public InstanceScript
        {
            instance_iron_docks_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case BOSS_SKULLOC:
                    case BOSS_KORAMAR:
                    case BOSS_ZOGGOSH:
                        creature->setActive(true); // tempoary hackfix to make him visible from far need packet research to find more about him
                        break;
                    default:
                        break;
                }
            }
        protected:
        };


        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_iron_docks_InstanceScript(map);
        }
};

void AddSC_instance_iron_docks()
{
    new instance_iron_docks();
}
