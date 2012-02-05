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
#include "bastion_of_twilight.h"

class instance_bastion_of_twilight : public InstanceMapScript
{
    public:
        instance_bastion_of_twilight() : InstanceMapScript("instance_bastion_of_twilight", 671) { }

        struct instance_bastion_of_twilight_InstanceMapScript : public InstanceScript
        {
            instance_bastion_of_twilight_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];

            // Creatures
            uint64 HalfusWyrmbreakerGUID;
            uint64 DoubleDragonGUIDs[2];
            uint64 AscendantCouncilGUIDs[5];
            uint64 ChogallGUID;
            uint64 SinestraGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);

                HalfusWyrmbreakerGUID           = 0;
                memset(DoubleDragonGUIDs, 0, sizeof(DoubleDragonGUIDs));
                memset(AscendantCouncilGUIDs, 0, sizeof(AscendantCouncilGUIDs));
                ChogallGUID                     = 0;
                SinestraGUID                    = 0;

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
                    case NPC_HALFUS_WYRMBREAKER:
                        HalfusWyrmbreakerGUID = creature->GetGUID();
                        break;
                    case NPC_VALIONA:
                        DoubleDragonGUIDs[0] = creature->GetGUID();
                        break;
                    case NPC_THERALION:
                        DoubleDragonGUIDs[1] = creature->GetGUID();
                        break;
                    case NPC_FELUDIUS:
                        AscendantCouncilGUIDs[0] = creature->GetGUID();
                        break;
                    case NPC_IGNACIOUS:
                        AscendantCouncilGUIDs[1] = creature->GetGUID();
                        break;
                    case NPC_ARION:
                        AscendantCouncilGUIDs[2] = creature->GetGUID();
                        break;
                    case NPC_TERRASTRA:
                        AscendantCouncilGUIDs[3] = creature->GetGUID();
                        break;
                    case NPC_ELEMENTIUM_MONSTROSITY:
                        AscendantCouncilGUIDs[4] = creature->GetGUID();
                        break;
                    case NPC_CHOGALL:
                        ChogallGUID = creature->GetGUID();
                        break;
                    case NPC_SINESTRA:
                        SinestraGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_HALFUS_WYRMBREAKER:
                        return HalfusWyrmbreakerGUID;
                    case BOSS_VALIONA:
                        return DoubleDragonGUIDs[0];
                    case BOSS_THERALION:
                        return DoubleDragonGUIDs[1];
                    case BOSS_FELUDIUS:
                        return AscendantCouncilGUIDs[0];
                    case BOSS_IGNACIOUS:
                        return AscendantCouncilGUIDs[1];
                    case BOSS_ARION:
                        return AscendantCouncilGUIDs[2];
                    case BOSS_TERRASTRA:
                        return AscendantCouncilGUIDs[3];
                    case BOSS_ELEMENTIUM_MONSTROSITY:
                        return AscendantCouncilGUIDs[4];
                    case BOSS_CHOGALL:
                        return ChogallGUID;
                    case BOSS_SINESTRA:
                        return SinestraGUID;
                }

                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_bastion_of_twilight_InstanceMapScript(map);
        }
};

void AddSC_instance_bastion_of_twilight()
{
    new instance_bastion_of_twilight();
}
