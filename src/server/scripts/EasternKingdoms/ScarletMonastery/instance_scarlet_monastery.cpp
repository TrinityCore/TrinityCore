/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "scarlet_monastery.h"

DoorData const doorData[] =
{
    { GO_HIGH_INQUISITORS_DOOR, DATA_MOGRAINE_AND_WHITE_EVENT, DOOR_TYPE_ROOM },
    { 0,                        0,                             DOOR_TYPE_ROOM } // END
};

class instance_scarlet_monastery : public InstanceMapScript
{
    public:
        instance_scarlet_monastery() : InstanceMapScript(SMScriptName, 189) { }

        struct instance_scarlet_monastery_InstanceMapScript : public InstanceScript
        {
            instance_scarlet_monastery_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

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
                            for (ObjectGuid guid : HorsemanAdds)
                            {
                                Creature* add = instance->GetCreature(guid);
                                if (add && add->IsAlive())
                                    add->KillSelf();
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

            ObjectGuid GetGuidData(uint32 type) const override
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
                return ObjectGuid::Empty;
            }

        protected:
            ObjectGuid PumpkinShrineGUID;
            ObjectGuid HorsemanGUID;
            ObjectGuid HeadGUID;
            ObjectGuid MograineGUID;
            ObjectGuid WhitemaneGUID;
            ObjectGuid VorrelGUID;

            GuidSet HorsemanAdds;
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
