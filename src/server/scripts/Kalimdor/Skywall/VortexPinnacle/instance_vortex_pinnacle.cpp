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
#include "vortex_pinnacle.h"

class instance_vortex_pinnacle : public InstanceMapScript
{
    public:
        instance_vortex_pinnacle() : InstanceMapScript("instance_vortex_pinnacle", 657) { }

        struct instance_vortex_pinnacle_InstanceMapScript : public InstanceScript
        {
            instance_vortex_pinnacle_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];

            // Creatures
            uint64 GrandVizierErtanGUID;
            uint64 AltairusGUID;
            uint64 AsaadGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);

                GrandVizierErtanGUID            = 0;
                AltairusGUID                    = 0;
                AsaadGUID                       = 0;

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
                    case NPC_GRAND_VIZIER_ERTAN:
                        GrandVizierErtanGUID = creature->GetGUID();
                        break;
                    case NPC_ALTAIRUS:
                        AltairusGUID = creature->GetGUID();
                        break;
                    case NPC_ASAAD:
                        AsaadGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_GRAND_VIZIER_ERTAN:
                        return GrandVizierErtanGUID;
                    case BOSS_ALTAIRUS:
                        return AltairusGUID;
                    case BOSS_ASAAD:
                        return AsaadGUID;
                }

                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_vortex_pinnacle_InstanceMapScript(map);
        }
};

void AddSC_instance_vortex_pinnacle()
{
    new instance_vortex_pinnacle();
}
