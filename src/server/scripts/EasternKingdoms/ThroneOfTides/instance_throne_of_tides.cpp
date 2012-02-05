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
#include "throne_of_tides.h"

class instance_throne_of_tides : public InstanceMapScript
{
    public:
        instance_throne_of_tides() : InstanceMapScript("instance_throne_of_tides", 643) { }

        struct instance_throne_of_tides_InstanceMapScript : public InstanceScript
        {
            instance_throne_of_tides_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint32 Encounter[MAX_ENCOUNTER];

            // Creatures
            uint64 NazjarGUID;
            uint64 CommanderUlthokGUID;
            uint64 ErunakStonespeakerGUID;
            uint64 OzumatGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);

                NazjarGUID                      = 0;
                CommanderUlthokGUID             = 0;
                ErunakStonespeakerGUID          = 0;
                OzumatGUID                      = 0;

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
                    case NPC_NAZJAR:
                        NazjarGUID = creature->GetGUID();
                        break;
                    case NPC_COMMANDER_ULTHOK:
                        CommanderUlthokGUID = creature->GetGUID();
                        break;
                    case NPC_ERUNAK_STONESPEAKER:
                        ErunakStonespeakerGUID = creature->GetGUID();
                        break;
                    case NPC_OZUMAT:
                        OzumatGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_NAZJAR:
                        return NazjarGUID;
                    case BOSS_COMMANDER_ULTHOK:
                        return CommanderUlthokGUID;
                    case BOSS_ERUNAK_STONESPEAKER:
                        return ErunakStonespeakerGUID;
                    case BOSS_OZUMAT:
                        return OzumatGUID;
                }

                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_throne_of_tides_InstanceMapScript(map);
        }
};

void AddSC_instance_throne_of_tides()
{
    new instance_throne_of_tides();
}
