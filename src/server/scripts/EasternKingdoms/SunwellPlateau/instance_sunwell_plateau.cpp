/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "Player.h"
#include "sunwell_plateau.h"

/* Sunwell Plateau:
0 - Kalecgos and Sathrovarr
1 - Brutallus
2 - Felmyst
3 - Eredar Twins (Alythess and Sacrolash)
4 - M'uru
5 - Kil'Jaeden
*/

DoorData const doorData[] =
{
    { GO_FIRE_BARRIER,     DATA_FELMYST,  DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GO_MURUS_GATE_1,     DATA_MURU,     DOOR_TYPE_ROOM,    BOUNDARY_NONE },
    { GO_MURUS_GATE_2,     DATA_MURU,     DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GO_BOSS_COLLISION_1, DATA_KALECGOS, DOOR_TYPE_ROOM,    BOUNDARY_NONE },
    { GO_BOSS_COLLISION_2, DATA_KALECGOS, DOOR_TYPE_ROOM,    BOUNDARY_NONE },
    { GO_FORCE_FIELD,      DATA_KALECGOS, DOOR_TYPE_ROOM,    BOUNDARY_NONE },
    { 0,                   0,             DOOR_TYPE_ROOM,    BOUNDARY_NONE } // END
};

class instance_sunwell_plateau : public InstanceMapScript
{
    public:
        instance_sunwell_plateau() : InstanceMapScript(SunwellPlateauScriptName, 580) { }

        struct instance_sunwell_plateau_InstanceMapScript : public InstanceScript
        {
            instance_sunwell_plateau_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                KalecgosDragonGUID          = 0;
                KalecgosHumanGUID           = 0;
                SathrovarrGUID              = 0;
                BrutallusGUID               = 0;
                MadrigosaGUID               = 0;
                FelmystGUID                 = 0;
                AlythessGUID                = 0;
                SacrolashGUID               = 0;
                MuruGUID                    = 0;
                KilJaedenGUID               = 0;
                KilJaedenControllerGUID     = 0;
                AnveenaGUID                 = 0;
                KalecgosKjGUID              = 0;
                SpectralPlayers             = 0;

                SpectralRealmTimer          = 5000;
            }

            Player const* GetPlayerInMap() const
            {
                Map::PlayerList const& players = instance->GetPlayers();

                if (!players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* player = itr->GetSource();
                        if (player && !player->HasAura(45839, 0))
                            return player;
                    }
                }
                else
                    TC_LOG_DEBUG("scripts", "Instance Sunwell Plateau: GetPlayerInMap, but PlayerList is empty!");

                return NULL;
            }

            void OnCreatureCreate(Creature* creature) OVERRIDE
            {
                switch (creature->GetEntry())
                {
                    case NPC_KALECGOS:
                        KalecgosDragonGUID = creature->GetGUID();
                        break;
                    case NPC_KALEC:
                        KalecgosHumanGUID = creature->GetGUID();
                        break;
                    case NPC_SATHROVARR:
                        SathrovarrGUID = creature->GetGUID();
                        break;
                    case NPC_BRUTALLUS:
                        BrutallusGUID = creature->GetGUID();
                        break;
                    case NPC_MADRIGOSA:
                        MadrigosaGUID = creature->GetGUID();
                        break;
                    case NPC_FELMYST:
                        FelmystGUID = creature->GetGUID();
                        break;
                    case NPC_GRAND_WARLOCK_ALYTHESS:
                        AlythessGUID = creature->GetGUID();
                        break;
                    case NPC_LADY_SACROLASH:
                        SacrolashGUID = creature->GetGUID();
                        break;
                    case NPC_MURU:
                        MuruGUID = creature->GetGUID();
                        break;
                    case NPC_KILJAEDEN:
                        KilJaedenGUID = creature->GetGUID();
                        break;
                    case NPC_KILJAEDEN_CONTROLLER:
                        KilJaedenControllerGUID = creature->GetGUID();
                        break;
                    case NPC_ANVEENA:
                        AnveenaGUID = creature->GetGUID();
                        break;
                    case NPC_KALECGOS_KJ:
                        KalecgosKjGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_FORCE_FIELD:
                    case GO_BOSS_COLLISION_1:
                    case GO_BOSS_COLLISION_2:
                    case GO_FIRE_BARRIER:
                    case GO_MURUS_GATE_1:
                    case GO_MURUS_GATE_2:
                        AddDoor(go, true);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_FIRE_BARRIER:
                    case GO_MURUS_GATE_1:
                    case GO_MURUS_GATE_2:
                    case GO_BOSS_COLLISION_1:
                    case GO_BOSS_COLLISION_2:
                    case GO_FORCE_FIELD:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 id) const OVERRIDE
            {
                switch (id)
                {
                    case DATA_KALECGOS_DRAGON:
                        return KalecgosDragonGUID;
                    case DATA_KALECGOS_HUMAN:
                        return KalecgosHumanGUID;
                    case DATA_SATHROVARR:
                        return SathrovarrGUID;
                    case DATA_BRUTALLUS:
                        return BrutallusGUID;
                    case DATA_MADRIGOSA:
                        return MadrigosaGUID;
                    case DATA_FELMYST:
                        return FelmystGUID;
                    case DATA_ALYTHESS:
                        return AlythessGUID;
                    case DATA_SACROLASH:
                        return SacrolashGUID;
                    case DATA_MURU:
                        return MuruGUID;
                    case DATA_KILJAEDEN:
                        return KilJaedenGUID;
                    case DATA_KILJAEDEN_CONTROLLER:
                        return KilJaedenControllerGUID;
                    case DATA_ANVEENA:
                        return AnveenaGUID;
                    case DATA_KALECGOS_KJ:
                        return KalecgosKjGUID;
                    case DATA_PLAYER_GUID:
                    {
                        Player const* target = GetPlayerInMap();
                        return target ? target->GetGUID() : 0;
                    }
                    default:
                        break;
                }
                return 0;
            }

            std::string GetSaveData() OVERRIDE
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "S P " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* str) OVERRIDE
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'S' && dataHead2 == 'P')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

            protected:
                uint64 KalecgosDragonGUID;
                uint64 KalecgosHumanGUID;
                uint64 SathrovarrGUID;
                uint64 BrutallusGUID;
                uint64 MadrigosaGUID;
                uint64 FelmystGUID;
                uint64 AlythessGUID;
                uint64 SacrolashGUID;
                uint64 MuruGUID;
                uint64 KilJaedenGUID;
                uint64 KilJaedenControllerGUID;
                uint64 AnveenaGUID;
                uint64 KalecgosKjGUID;
                uint32 SpectralPlayers;

                uint32 SpectralRealmTimer;
                std::vector<uint64> SpectralRealmList;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_sunwell_plateau_InstanceMapScript(map);
        }
};

void AddSC_instance_sunwell_plateau()
{
    new instance_sunwell_plateau();
}
