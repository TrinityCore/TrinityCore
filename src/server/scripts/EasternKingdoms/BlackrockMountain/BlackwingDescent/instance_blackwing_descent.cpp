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
#include "blackwing_descent.h"

class instance_blackwing_descent : public InstanceMapScript
{
    public:
        instance_blackwing_descent() : InstanceMapScript("instance_blackwing_descent", 669) { }

        struct instance_blackwing_descent_InstanceMapScript : public InstanceScript
        {
            instance_blackwing_descent_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];

            // Creatures
            uint64 MagmawGUID;
            uint64 OmnotronDefenseSystemGUIDs[4];
            uint64 MaloriakGUID;
            uint64 AtramedesGUID;
            uint64 ChimaeronGUID;
            uint64 NefarianGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);

                MagmawGUID                      = 0;
                memset(OmnotronDefenseSystemGUIDs, 0, sizeof(OmnotronDefenseSystemGUIDs));
                MaloriakGUID                    = 0;
                AtramedesGUID                   = 0;
                ChimaeronGUID                   = 0;
                NefarianGUID                    = 0;

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
                    case NPC_MAGMAW:
                        MagmawGUID = creature->GetGUID();
                        break;
                    case NPC_ARCANOTRON:
                        OmnotronDefenseSystemGUIDs[0] = creature->GetGUID();
                        break;
                    case NPC_ELECTRON:
                        OmnotronDefenseSystemGUIDs[1] = creature->GetGUID();
                        break;
                    case NPC_MAGMATRON:
                        OmnotronDefenseSystemGUIDs[2] = creature->GetGUID();
                        break;
                    case NPC_TOXITRON:
                        OmnotronDefenseSystemGUIDs[3] = creature->GetGUID();
                        break;
                    case NPC_MALORIAK:
                        MaloriakGUID = creature->GetGUID();
                        break;
                    case NPC_ATRAMEDES:
                        AtramedesGUID = creature->GetGUID();
                        break;
                    case NPC_CHIMAERON:
                        ChimaeronGUID = creature->GetGUID();
                        break;
                    case NPC_NEFARIAN:
                        NefarianGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_MAGMAW:
                        return MagmawGUID;
                    case BOSS_ARCANOTRON:
                        return OmnotronDefenseSystemGUIDs[0];
                    case BOSS_ELECTRON:
                        return OmnotronDefenseSystemGUIDs[1];
                    case BOSS_MAGMATRON:
                        return OmnotronDefenseSystemGUIDs[2];
                    case BOSS_TOXITRON:
                        return OmnotronDefenseSystemGUIDs[3];
                    case BOSS_MALORIAK:
                        return MaloriakGUID;
                    case BOSS_ATRAMEDES:
                        return AtramedesGUID;
                    case BOSS_CHIMAERON:
                        return ChimaeronGUID;
                    case BOSS_NEFARIAN:
                        return NefarianGUID;
                }

                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_blackwing_descent_InstanceMapScript(map);
        }
};

void AddSC_instance_blackwing_descent()
{
    new instance_blackwing_descent();
}
