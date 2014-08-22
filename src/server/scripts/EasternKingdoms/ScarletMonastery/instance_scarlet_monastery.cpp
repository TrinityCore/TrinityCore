/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "scarlet_monastery.h"

DoorData const doorData[] =
{
    { GO_HIGH_INQUISITORS_DOOR, DATA_MOGRAINE_AND_WHITE_EVENT, DOOR_TYPE_ROOM, BOUNDARY_NONE },
    { 0,                        0,                             DOOR_TYPE_ROOM, BOUNDARY_NONE } // END
};

class instance_scarlet_monastery : public InstanceMapScript
{
    public:
        instance_scarlet_monastery() : InstanceMapScript("instance_scarlet_monastery", 189) { }

        struct instance_scarlet_monastery_InstanceMapScript : public InstanceScript
        {
            instance_scarlet_monastery_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                PumpkinShrineGUID      = 0;
                HorsemanGUID           = 0;
                HeadGUID               = 0;
                MograineGUID           = 0;
                WhitemaneGUID          = 0;
                VorrelGUID             = 0;

                HorsemanAdds.clear();
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_PUMPKIN_SHRINE:
                        PumpkinShrineGUID = go->GetGUID();
                        break;
                    case GO_HIGH_INQUISITORS_DOOR:
                        AddDoor(go, true);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_HIGH_INQUISITORS_DOOR:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_HORSEMAN:
                        HorsemanGUID = creature->GetGUID();
                        break;
                    case NPC_HEAD:
                        HeadGUID = creature->GetGUID();
                        break;
                    case NPC_PUMPKIN:
                        HorsemanAdds.insert(creature->GetGUID());
                        break;
                    case NPC_MOGRAINE:
                        MograineGUID = creature->GetGUID();
                        break;
                    case NPC_WHITEMANE:
                        WhitemaneGUID = creature->GetGUID();
                        break;
                    case NPC_VORREL:
                        VorrelGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void SetData(uint32 type, uint32 /*data*/) override
            {
                switch (type)
                {
                    case DATA_PUMPKIN_SHRINE:
                        HandleGameObject(PumpkinShrineGUID, false);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_HORSEMAN_EVENT:
                        if (state == DONE)
                        {
                            for (uint64 guid : HorsemanAdds)
                            {
                                Creature* add = instance->GetCreature(guid);
                                if (add && add->IsAlive())
                                    add->Kill(add);
                            }
                            HorsemanAdds.clear();
                            HandleGameObject(PumpkinShrineGUID, false);
                        }
                        break;
                    default:
                        break;
                }
                return true;
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_MOGRAINE:
                        return MograineGUID;
                    case DATA_WHITEMANE:
                        return WhitemaneGUID;
                    case DATA_VORREL:
                        return VorrelGUID;
                    default:
                        break;
                }
                return 0;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "S M " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* str) override
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'S' && dataHead2 == 'M')
                {
                    for (uint8 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;

                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            uint64 PumpkinShrineGUID;
            uint64 HorsemanGUID;
            uint64 HeadGUID;
            uint64 MograineGUID;
            uint64 WhitemaneGUID;
            uint64 VorrelGUID;

            std::set<uint64> HorsemanAdds;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_scarlet_monastery_InstanceMapScript(map);
        }
};

void AddSC_instance_scarlet_monastery()
{
    new instance_scarlet_monastery();
}
