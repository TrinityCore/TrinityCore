/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
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
    { GO_FIRE_BARRIER,     DATA_FELMYST,  DOOR_TYPE_PASSAGE },
    { GO_MURUS_GATE_1,     DATA_MURU,     DOOR_TYPE_ROOM },
    { GO_MURUS_GATE_2,     DATA_MURU,     DOOR_TYPE_PASSAGE },
    { GO_BOSS_COLLISION_1, DATA_KALECGOS, DOOR_TYPE_ROOM },
    { GO_BOSS_COLLISION_2, DATA_KALECGOS, DOOR_TYPE_ROOM },
    { GO_FORCE_FIELD,      DATA_KALECGOS, DOOR_TYPE_ROOM },
    { 0,                   0,             DOOR_TYPE_ROOM } // END
};

class instance_sunwell_plateau : public InstanceMapScript
{
    public:
        instance_sunwell_plateau() : InstanceMapScript(SunwellPlateauScriptName, 580) { }

        struct instance_sunwell_plateau_InstanceMapScript : public InstanceScript
        {
            instance_sunwell_plateau_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

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
                        if (player && !player->HasAura(45839))
                            return player;
                    }
                }
                else
                    TC_LOG_DEBUG("scripts", "Instance Sunwell Plateau: GetPlayerInMap, but PlayerList is empty!");

                return NULL;
            }

            void OnCreatureCreate(Creature* creature) override
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

            void OnGameObjectCreate(GameObject* go) override
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

            void OnGameObjectRemove(GameObject* go) override
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

            ObjectGuid GetGuidData(uint32 id) const override
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
                        return target ? target->GetGUID() : ObjectGuid::Empty;
                    }
                    default:
                        break;
                }
                return ObjectGuid::Empty;
            }

        protected:
            ObjectGuid KalecgosDragonGUID;
            ObjectGuid KalecgosHumanGUID;
            ObjectGuid SathrovarrGUID;
            ObjectGuid BrutallusGUID;
            ObjectGuid MadrigosaGUID;
            ObjectGuid FelmystGUID;
            ObjectGuid AlythessGUID;
            ObjectGuid SacrolashGUID;
            ObjectGuid MuruGUID;
            ObjectGuid KilJaedenGUID;
            ObjectGuid KilJaedenControllerGUID;
            ObjectGuid AnveenaGUID;
            ObjectGuid KalecgosKjGUID;
            uint32 SpectralPlayers;

            uint32 SpectralRealmTimer;
            GuidVector SpectralRealmList;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_sunwell_plateau_InstanceMapScript(map);
        }
};

void AddSC_instance_sunwell_plateau()
{
    new instance_sunwell_plateau();
}
