/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ScriptMgr.h"
#include "AreaBoundary.h"
#include "Creature.h"
#include "forge_of_souls.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"

BossBoundaryData const boundaries =
{
    { DATA_BRONJAHM,          new CircleBoundary(Position(5297.3f, 2506.45f), 100.96)                                                             },
    { DATA_DEVOURER_OF_SOULS, new ParallelogramBoundary(Position(5663.56f, 2570.53f), Position(5724.39f, 2520.45f), Position(5570.36f, 2461.42f)) }
};

class instance_forge_of_souls : public InstanceMapScript
{
    public:
        instance_forge_of_souls() : InstanceMapScript(FoSScriptName, 632) { }

        struct instance_forge_of_souls_InstanceScript : public InstanceScript
        {
            instance_forge_of_souls_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadBossBoundaries(boundaries);

                teamInInstance = 0;
            }

            void OnPlayerEnter(Player* player) override
            {
                if (!teamInInstance)
                    teamInInstance = player->GetTeam();
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_BRONJAHM:
                        bronjahm = creature->GetGUID();
                        break;
                    case NPC_DEVOURER:
                        devourerOfSouls = creature->GetGUID();
                        break;
                }
            }

            uint32 GetCreatureEntry(ObjectGuid::LowType /*guidLow*/, CreatureData const* data) override
            {
                if (!teamInInstance)
                {
                    Map::PlayerList const& players = instance->GetPlayers();
                    if (!players.isEmpty())
                        if (Player* player = players.begin()->GetSource())
                            teamInInstance = player->GetTeam();
                }

                uint32 entry = data->id;
                switch (entry)
                {
                    case NPC_SYLVANAS_PART1:
                        return teamInInstance == ALLIANCE ? NPC_JAINA_PART1 : NPC_SYLVANAS_PART1;
                    case NPC_LORALEN:
                        return teamInInstance == ALLIANCE ? NPC_ELANDRA : NPC_LORALEN;
                    case NPC_KALIRA:
                        return teamInInstance == ALLIANCE ? NPC_KORELN : NPC_KALIRA;
                    default:
                        return entry;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_TEAM_IN_INSTANCE:
                        return teamInInstance;
                    default:
                        break;
                }

                return 0;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_BRONJAHM:
                        return bronjahm;
                    case DATA_DEVOURER_OF_SOULS:
                        return devourerOfSouls;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

        private:
            ObjectGuid bronjahm;
            ObjectGuid devourerOfSouls;

            uint32 teamInInstance;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_forge_of_souls_InstanceScript(map);
        }
};

void AddSC_instance_forge_of_souls()
{
    new instance_forge_of_souls();
}
