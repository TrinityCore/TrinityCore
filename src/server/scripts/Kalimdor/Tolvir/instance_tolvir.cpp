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
#include "tolvir.h"

class instance_tolvir : public InstanceMapScript
{
    public:
        instance_tolvir() : InstanceMapScript("instance_tolvir", 755) { }

        struct instance_tolvir_InstanceMapScript : public InstanceScript
        {
            instance_tolvir_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];

            // Creatures
            uint64 GeneralHusamGUID;
            uint64 HighProphetBarimGUID;
            uint64 LockmawGUID;
            uint64 AughGUID;
            uint64 SiamatGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);

                GeneralHusamGUID                = 0;
                HighProphetBarimGUID            = 0;
                LockmawGUID                     = 0;
                AughGUID                        = 0;
                SiamatGUID                      = 0;

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
                    case NPC_GENERAL_HUSAM:
                        GeneralHusamGUID = creature->GetGUID();
                        break;
                    case NPC_HIGH_PROPHET_BARIM:
                        HighProphetBarimGUID = creature->GetGUID();
                        break;
                    case NPC_LOCKMAW:
                        LockmawGUID = creature->GetGUID();
                        break;
                    case NPC_AUGH:
                        AughGUID = creature->GetGUID();
                        break
                    case NPC_SIAMAT:
                        SiamatGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_GENERAL_HUSAM:
                        return GeneralHusamGUID;
                    case BOSS_HIGH_PROPHET_BARIM:
                        return HighProphetBarimGUID;
                    case BOSS_LOCKMAW:
                        return LockmawGUID;
                    case BOSS_AUGH:
                        return AughGUID;
                    case BOSS_SIAMAT:
                        return SiamatGUID;
                }

                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_tolvir_InstanceMapScript(map);
        }
};

void AddSC_instance_tolvir()
{
    new instance_tolvir();
}
