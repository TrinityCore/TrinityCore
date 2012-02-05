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
#include "halls_of_origination.h"

class instance_halls_of_origination : public InstanceMapScript
{
    public:
        instance_halls_of_origination() : InstanceMapScript("instance_halls_of_origination", 644) { }

        struct instance_halls_of_origination_InstanceMapScript : public InstanceScript
        {
            instance_halls_of_origination_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];

            // Creatures
            uint64 TempleGuardianAnhuurGUID;
            uint64 EarthragerPtahGUID;
            uint64 AnraphetGUID;
            uint64 IsisetGUID;
            uint64 AmmunaeGUID;
            uint64 SeteshGUID;
            uint64 RajhGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);

                TempleGuardianAnhuurGUID        = 0;
                EarthragerPtahGUID              = 0;
                AnraphetGUID                    = 0;
                IsisetGUID                      = 0;
                AmmunaeGUID                     = 0;
                SeteshGUID                      = 0;
                RajhGUID                        = 0;

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
                    case NPC_TEMPLE_GUARDIAN_ANHUUR:
                        TempleGuardianAnhuurGUID = creature->GetGUID();
                        break;
                    case NPC_EARTHRAGER_PTAH:
                        EarthragerPtahGUID = creature->GetGUID();
                        break;
                    case NPC_ANRAPHET:
                        AnraphetGUID = creature->GetGUID();
                        break;
                    case NPC_ISISET:
                        IsisetGUID = creature->GetGUID();
                        break;
                    case NPC_AMMUNAE:
                        AmmunaeGUID = creature->GetGUID();
                        break;
                    case NPC_SETESH:
                        SeteshGUID = creature->GetGUID();
                        break;
                    case NPC_RAJH:
                        RajhGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_TEMPLE_GUARDIAN_ANHUUR:
                        return TempleGuardianAnhuurGUID;
                    case BOSS_EARTHRAGER_PTAH:
                        return EarthragerPtahGUID;
                    case BOSS_ANRAPHET:
                        return AnraphetGUID;
                    case BOSS_ISISET:
                        return IsisetGUID;
                    case BOSS_AMMUNAE:
                        return AmmunaeGUID;
                    case BOSS_SETESH:
                        return SeteshGUID;
                    case BOSS_RAJH:
                        return RajhGUID;
                }

                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_halls_of_origination_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_origination()
{
    new instance_halls_of_origination();
}
