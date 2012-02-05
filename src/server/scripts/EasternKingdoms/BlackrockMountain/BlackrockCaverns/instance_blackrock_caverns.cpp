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
#include "blackrock_caverns.h"

class instance_blackrock_caverns : public InstanceMapScript
{
    public:
        instance_blackrock_caverns() : InstanceMapScript("instance_blackrock_caverns", 645) { }

        struct instance_blackrock_caverns_InstanceMapScript : public InstanceScript
        {
            instance_blackrock_caverns_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];

            // Creatures
            uint64 RomoggBonecrusherGUID;
            uint64 CorlaGUID;
            uint64 KarshSteelbenderGUID;
            uint64 BeautyGUID;
            uint64 AscendantLordObsidiusGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);

                RomoggBonecrusherGUID           = 0;
                CorlaGUID                       = 0;
                KarshSteelbenderGUID            = 0;
                BeautyGUID                      = 0;
                AscendantLordObsidiusGUID       = 0;

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
                    case NPC_ROMOGG_BONECRUSHER:
                        RomoggBonecrusherGUID = creature->GetGUID();
                        break;
                    case NPC_CORLA_HERALD_OF_TWILIGHT:
                        CorlaGUID = creature->GetGUID();
                        break;
                    case NPC_KARSH_STEELBENDER:
                        KarshSteelbenderGUID = creature->GetGUID();
                        break;
                    case NPC_BEAUTY:
                        BeautyGUID = creature->GetGUID();
                        break;
                    case NPC_ASCENDANT_LORD_OBSIDIUS:
                        AscendantLordObsidiusGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_ROMOGG_BONECRUSHER:
                        return RomoggBonecrusherGUID;
                    case BOSS_CORLA_HERALD_OF_TWILIGHT:
                        return CorlaGUID;
                    case BOSS_KARSH_STEELBENDER:
                        return KarshSteelbenderGUID;
                    case BOSS_BEAUTY:
                        return BeautyGUID;
                    case BOSS_ASCENDANT_LORD_OBSIDIUS:
                        return AscendantLordObsidiusGUID;
                }

                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_blackrock_caverns_InstanceMapScript(map);
        }
};

void AddSC_instance_blackrock_caverns()
{
    new instance_blackrock_caverns();
}
