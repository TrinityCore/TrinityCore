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
#include "InstanceScript.h"
#include "firelands.h"

DoorData const doorData[] =
{
    {GO_LORD_RHYOLITH_BRIDGE,    DATA_LORD_RHYOLITH,      DOOR_TYPE_ROOM},
    {GO_BETH_TILAC_DOOR,         DATA_BETH_TILAC,         DOOR_TYPE_ROOM},
    //{GO_BALEROC_FIREWALL,        DATA_BALEROC,            DOOR_TYPE_ROOM},
    {GO_MAJORDOMO_FIREWALL,      DATA_MAJORDOMO_STAGHELM, DOOR_TYPE_PASSAGE},
    {GO_RAGNAROS_DOOR,           DATA_RAGNAROS,           DOOR_TYPE_ROOM},
    {0,                          0,                       DOOR_TYPE_ROOM}, //END
}; //Baleroc door is special, it depends on the health status of the other bosses in the instance

class instance_firelands : public InstanceMapScript
{
    public:
        instance_firelands() : InstanceMapScript(FirelandsScriptName, 720) { }

        struct instance_firelands_InstanceScript : public InstanceScript
        {
            instance_firelands_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_SMOULDERING_HATCHLING:
                        // Cannot directly start attacking here as the creature is not yet on map
                        creature->m_Events.AddEvent(new DelayedAttackStartEvent(creature), creature->m_Events.CalculateTime(500));
                        break;
                    case NPC_BALEROC:
                        BalerocGUID = creature->GetGUID();
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_BALEROC:
                        return BalerocGUID;
                }

                return ObjectGuid::Empty;
            }

            private:
                ObjectGuid BalerocGUID;

        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_firelands_InstanceScript(map);
        }
};

void AddSC_instance_firelands()
{
    new instance_firelands();
}
