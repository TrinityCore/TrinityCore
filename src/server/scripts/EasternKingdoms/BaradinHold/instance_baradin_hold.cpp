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
#include "baradin_hold.h"

class instance_baradin_hold : public InstanceMapScript
{
    public:
        instance_baradin_hold() : InstanceMapScript("instance_baradin_hold", 757) { }

        struct instance_baradin_hold_InstanceMapScript : public InstanceScript
        {
            instance_baradin_hold_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];

            // Creatures
            uint64 ArgalothGUID;
            uint64 OccutharGUID;
            uint64 AlizabalGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);

                ArgalothGUID                    = 0;
                OccutharGUID                    = 0;
                AlizabalGUID                    = 0;

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
                    case NPC_ARGALOTH:
                        ArgalothGUID = creature->GetGUID();
                        break;
                    case NPC_OCCUTHAR:
                        OccutharGUID = creature->GetGUID();
                        break;
                    case NPC_ALIZABAL:
                        AlizabalGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_ARGALOTH:
                        return ArgalothGUID;
                    case BOSS_OCCUTHAR:
                        return OccutharGUID;
                    case BOSS_ALIZABAL:
                        return AlizabalGUID;
                }

                return 0;
            }
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
