/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "throne_of_four_winds.h"

class instance_throne_of_four_winds : public InstanceMapScript
{
    public:
        instance_throne_of_four_winds() : InstanceMapScript("instance_throne_of_four_winds", 754) { }

        struct instance_throne_of_four_winds_InstanceMapScript : public InstanceScript
        {
            instance_throne_of_four_winds_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];

            // Creatures
            uint64 ConclaveOfWindGUIDs[3];
            uint64 AlAkirGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);

                memset(ConclaveOfWindGUIDs, 0, sizeof(ConclaveOfWindGUIDs));
                AlAkirGUID                      = 0;

                memset(Encounter, 0, sizeof(Encounter));
            }

            bool IsEncounterInProgress() const
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (Encounter[i] == IN_PROGRESS)
                        return true;

                return false;
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_ANSHAL:
                        ConclaveOfWindGUIDs[0] = creature->GetGUID();
                        break;
                    case NPC_NEZIR:
                        ConclaveOfWindGUIDs[1] = creature->GetGUID();
                        break;
                    case NPC_ROHASH:
                        ConclaveOfWindGUIDs[2] = creature->GetGUID();
                        break;
                    case NPC_ALAKIR:
                        AlAkirGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_ANSHAL:
                        return ConclaveOfWindGUIDs[0];
                    case BOSS_NEZIR:
                        return ConclaveOfWindGUIDs[1];
                    case BOSS_ROHASH:
                        return ConclaveOfWindGUIDs[2];
                    case BOSS_ALAKIR:
                        return AlAkirGUID;
                }

                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_throne_of_four_winds_InstanceMapScript(map);
        }
};

void AddSC_instance_throne_of_four_winds()
{
    new instance_throne_of_four_winds();
}
