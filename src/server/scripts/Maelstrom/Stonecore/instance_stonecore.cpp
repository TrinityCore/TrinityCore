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
#include "stonecore.h"

class instance_stonecore : public InstanceMapScript
{
    public:
        instance_stonecore() : InstanceMapScript("instance_stonecore", 725) { }

        struct instance_stonecore_InstanceMapScript : public InstanceScript
        {
            instance_stonecore_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];

            // Creatures
            uint64 CorborusGUID;
            uint64 SlabhideGUID;
            uint64 OzrukGUID;
            uint64 HighPriestessAzilGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);

                CorborusGUID                    = 0;
                SlabhideGUID                    = 0;
                OzrukGUID                       = 0;
                HighPriestessAzilGUID           = 0;

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
                    case NPC_CORBORUS:
                        CorborusGUID = creature->GetGUID();
                        break;
                    case NPC_SLABHIDE:
                        SlabhideGUID = creature->GetGUID();
                        break;
                    case NPC_OZRUK:
                        OzrukGUID = creature->GetGUID();
                        break;
                    case NPC_HIGH_PRIESTESS_AZIL:
                        HighPriestessAzilGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_CORBORUS:
                        return CorborusGUID;
                    case BOSS_SLABHIDE:
                        return SlabhideGUID;
                    case BOSS_OZRUK:
                        return OzrukGUID;
                    case BOSS_HIGH_PRIESTESS_AZIL:
                        return HighPriestessAzilGUID;
                }

                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_stonecore_InstanceMapScript(map);
        }
};

void AddSC_instance_stonecore()
{
    new instance_stonecore();
}
