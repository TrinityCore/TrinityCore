/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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
#include "baradin_hold.h"

DoorData const doorData[] =
{
    { GO_ARGALOTH_DOOR,  DATA_ARGALOTH, DOOR_TYPE_ROOM },
    { GO_OCCUTHAR_DOOR,  DATA_OCCUTHAR, DOOR_TYPE_ROOM },
    { GO_ALIZABAL_DOOR,  DATA_ALIZABAL, DOOR_TYPE_ROOM },
    { 0,                 0,             DOOR_TYPE_ROOM }  // END
};

class instance_baradin_hold: public InstanceMapScript
{
    public:
        instance_baradin_hold() : InstanceMapScript(BHScriptName, 757) { }

        struct instance_baradin_hold_InstanceMapScript: public InstanceScript
        {
            instance_baradin_hold_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch(creature->GetEntry())
                {
                    case BOSS_ARGALOTH:
                        ArgalothGUID = creature->GetGUID();
                        break;
                    case BOSS_OCCUTHAR:
                        OccutharGUID = creature->GetGUID();
                        break;
                    case BOSS_ALIZABAL:
                        AlizabalGUID = creature->GetGUID();
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch(go->GetEntry())
                {
                    case GO_ARGALOTH_DOOR:
                    case GO_OCCUTHAR_DOOR:
                    case GO_ALIZABAL_DOOR:
                        AddDoor(go, true);
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 data) const override
            {
                switch (data)
                {
                    case DATA_ARGALOTH:
                        return ArgalothGUID;
                    case DATA_OCCUTHAR:
                        return OccutharGUID;
                    case DATA_ALIZABAL:
                        return AlizabalGUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch(go->GetEntry())
                {
                    case GO_ARGALOTH_DOOR:
                    case GO_OCCUTHAR_DOOR:
                    case GO_ALIZABAL_DOOR:
                        AddDoor(go, false);
                        break;
                }
            }

        protected:
            ObjectGuid ArgalothGUID;
            ObjectGuid OccutharGUID;
            ObjectGuid AlizabalGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_baradin_hold_InstanceMapScript(map);
        }
};

void AddSC_instance_baradin_hold()
{
    new instance_baradin_hold();
}
