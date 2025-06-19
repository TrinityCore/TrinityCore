/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "arcatraz.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"

DoorData const doorData[] =
{
    { GO_CONTAINMENT_CORE_SECURITY_FIELD_ALPHA, DATA_SOCCOTHRATES,  DOOR_TYPE_PASSAGE },
    { GO_CONTAINMENT_CORE_SECURITY_FIELD_BETA,  DATA_DALLIAH,       DOOR_TYPE_PASSAGE },
    { 0,                                        0,                  DOOR_TYPE_ROOM } // END
};

ObjectData const creatureData[] =
{
    { NPC_MELLICHAR,              DATA_MELLICHAR        },
    { 0,                          0                     } // END
};

ObjectData const gameObjectData[] =
{
    { GO_STASIS_POD_ALPHA,        DATA_STASIS_POD_ALPHA },
    { GO_STASIS_POD_BETA,         DATA_STASIS_POD_BETA  },
    { GO_STASIS_POD_DELTA,        DATA_STASIS_POD_DELTA },
    { GO_STASIS_POD_GAMMA,        DATA_STASIS_POD_GAMMA },
    { GO_STASIS_POD_OMEGA,        DATA_STASIS_POD_OMEGA },
    { GO_WARDENS_SHIELD,          DATA_WARDENS_SHIELD   },
    { 0,                          0                     } //END
};

class instance_arcatraz : public InstanceMapScript
{
    public:
        instance_arcatraz() : InstanceMapScript(ArcatrazScriptName, 552) { }

        struct instance_arcatraz_InstanceMapScript : public InstanceScript
        {
            instance_arcatraz_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);

                ConversationState = NOT_STARTED;

                memset(StasisPodStates, NOT_STARTED, 5 * sizeof(uint8));
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_DALLIAH:
                        DalliahGUID = creature->GetGUID();
                        break;
                    case NPC_SOCCOTHRATES:
                        SoccothratesGUID = creature->GetGUID();
                        break;
                    case NPC_MILLHOUSE:
                        MillhouseGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_WARDEN_1:
                    case DATA_WARDEN_2:
                    case DATA_WARDEN_3:
                    case DATA_WARDEN_4:
                    case DATA_WARDEN_5:
                        StasisPodStates[type - DATA_WARDEN_1] = uint8(data);
                        break;
                    case DATA_CONVERSATION:
                        ConversationState = uint8(data);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_WARDEN_1:
                    case DATA_WARDEN_2:
                    case DATA_WARDEN_3:
                    case DATA_WARDEN_4:
                    case DATA_WARDEN_5:
                        return StasisPodStates[type - DATA_WARDEN_1];
                    case DATA_CONVERSATION:
                        return ConversationState;
                    default:
                        break;
                }
                return 0;
            }

            ObjectGuid GetGuidData(uint32 data) const override
            {
                switch (data)
                {
                    case DATA_DALLIAH:
                        return DalliahGUID;
                    case DATA_SOCCOTHRATES:
                        return SoccothratesGUID;
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
                    case DATA_HARBINGER_SKYRISS:
                        if (state == NOT_STARTED || state == FAIL)
                        {
                            SetData(DATA_WARDEN_1, NOT_STARTED);
                            SetData(DATA_WARDEN_2, NOT_STARTED);
                            SetData(DATA_WARDEN_3, NOT_STARTED);
                            SetData(DATA_WARDEN_4, NOT_STARTED);
                            SetData(DATA_WARDEN_5, NOT_STARTED);
                        }
                        if (state == DONE)
                        {
                            if (!instance->IsHeroic())
                                break;

                            if (Creature* millhouse = instance->GetCreature(MillhouseGUID))
                                if (millhouse->IsAlive())
                                    DoCastSpellOnPlayers(SPELL_QID_10886);
                        }
                        if (state == FAIL)
                        {
                            if (Creature* mellichar = GetCreature(DATA_MELLICHAR))
                                mellichar->AI()->DoAction(ACTION_RESET_PRISON);
                        }
                        break;
                    default:
                        break;
                }
                return true;
            }

        protected:
            ObjectGuid DalliahGUID;
            ObjectGuid SoccothratesGUID;
            ObjectGuid MillhouseGUID;

            uint8 ConversationState;
            uint8 StasisPodStates[5];
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_arcatraz_InstanceMapScript(map);
        }
};

void AddSC_instance_arcatraz()
{
    new instance_arcatraz();
}
