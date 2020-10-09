#include "tristam_catacombs.h"
#include "AreaBoundary.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"
#include "WorldStatePackets.h"

#include <iostream>

class instance_tristam_catacombs : public InstanceMapScript
{
    public:
        instance_tristam_catacombs() : InstanceMapScript(TCScriptName, 732) { }

        struct instance_tristam_catacombs_InstanceMapScript : public InstanceScript
        {
            instance_tristam_catacombs_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_NETRISTRASZA:
                        netristraszaGUID = creature->GetGUID();
                        break;
                    case NPC_ANTONN_GRAVE:
                        antonnGUID = creature->GetGUID();
                        break;
                    case NPC_ACOLYTE:
                        if (!creature->HasFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD))
                            acolytesGUID.push_back(creature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_NETRISTRASZA:
                        return netristraszaGUID;
                    case DATA_ANTONN_GRAVE:
                        return antonnGUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_NETRISTRASZA_ENTRANCE:
                        switch (state)
                        {
                            case NOT_STARTED:
                                break;
                            case IN_PROGRESS:
                                if (Creature* netristrasza = instance->GetCreature(netristraszaGUID))
                                    netristrasza->AI()->DoAction(ACTION_START_DUNGEON);
                                break;
                            case DONE:
                                break;
                            case FAIL:
                                if (Creature* netristrasza = instance->GetCreature(netristraszaGUID))
                                    netristrasza->DespawnOrUnsummon(10s);
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            void ProcessEvent(WorldObject* /*obj*/, uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_ANTONN_GRAVE:
                        if (Creature* antonn = instance->GetCreature(antonnGUID))
                        {
                            antonn->AI()->Talk(SAY_ANTONN_01);
                            for (auto guid : acolytesGUID)
                            {
                                if (Creature* acolyte = instance->GetCreature(guid))
                                {
                                    acolyte->SetFacingToObject(antonn);
                                    acolyte->CastSpell(antonn, SPELL_RITUAL_CANALISATION, true);
                                }
                            }
                        }
                        break;
                    default:
                        break;
                }
            }

            private:
            ObjectGuid netristraszaGUID;
            ObjectGuid antonnGUID;
            std::list<ObjectGuid> acolytesGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_tristam_catacombs_InstanceMapScript(map);
        }
};

void AddSC_instance_tristam_catacombs()
{
    new instance_tristam_catacombs();
}
