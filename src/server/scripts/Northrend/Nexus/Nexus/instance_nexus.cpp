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
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "nexus.h"
#include "Player.h"

class instance_nexus : public InstanceMapScript
{
    public:
        instance_nexus() : InstanceMapScript(NexusScriptName, 576) { }

        struct instance_nexus_InstanceMapScript : public InstanceScript
        {
            instance_nexus_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                _teamInInstance = 0;
            }

            void OnPlayerEnter(Player* player) override
            {
                if (!_teamInInstance)
                    _teamInInstance = player->GetTeam();
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_ANOMALUS:
                        AnomalusGUID = creature->GetGUID();
                        break;
                    case NPC_KERISTRASZA:
                        KeristraszaGUID = creature->GetGUID();
                        break;
                    case NPC_ALLIANCE_BERSERKER:
                    case NPC_ALLIANCE_RANGER:
                    case NPC_ALLIANCE_CLERIC:
                    case NPC_ALLIANCE_COMMANDER:
                    case NPC_COMMANDER_STOUTBEARD:
                        if (ServerAllowsTwoSideGroups())
                            creature->SetFaction(FACTION_MONSTER_2);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetCreatureEntry(ObjectGuid::LowType /*guidLow*/, CreatureData const* data) override
            {
                if (!_teamInInstance)
                {
                    Map::PlayerList const& players = instance->GetPlayers();
                    if (!players.isEmpty())
                        if (Player* player = players.begin()->GetSource())
                            _teamInInstance = player->GetTeam();
                }

                uint32 entry = data->id;
                switch (entry)
                {
                    case NPC_ALLIANCE_BERSERKER:
                        return _teamInInstance == ALLIANCE ? NPC_HORDE_BERSERKER : NPC_ALLIANCE_BERSERKER;
                    case NPC_ALLIANCE_RANGER:
                        return _teamInInstance == ALLIANCE ? NPC_HORDE_RANGER : NPC_ALLIANCE_RANGER;
                    case NPC_ALLIANCE_CLERIC:
                        return _teamInInstance == ALLIANCE ? NPC_HORDE_CLERIC : NPC_ALLIANCE_CLERIC;
                    case NPC_ALLIANCE_COMMANDER:
                        return _teamInInstance == ALLIANCE ? NPC_HORDE_COMMANDER : NPC_ALLIANCE_COMMANDER;
                    case NPC_COMMANDER_STOUTBEARD:
                        return _teamInInstance == ALLIANCE ? NPC_COMMANDER_KOLURG : NPC_COMMANDER_STOUTBEARD;
                    default:
                        return entry;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_ANOMALUS_CONTAINMENT_SPHERE:
                        AnomalusContainmentSphere = go->GetGUID();
                        if (GetBossState(DATA_ANOMALUS) == DONE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_ORMOROKS_CONTAINMENT_SPHERE:
                        OrmoroksContainmentSphere = go->GetGUID();
                        if (GetBossState(DATA_ORMOROK) == DONE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_TELESTRAS_CONTAINMENT_SPHERE:
                        TelestrasContainmentSphere = go->GetGUID();
                        if (GetBossState(DATA_MAGUS_TELESTRA) == DONE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_MAGUS_TELESTRA:
                        if (state == DONE)
                        {
                            if (GameObject* sphere = instance->GetGameObject(TelestrasContainmentSphere))
                                sphere->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        break;
                    case DATA_ANOMALUS:
                        if (state == DONE)
                        {
                            if (GameObject* sphere = instance->GetGameObject(AnomalusContainmentSphere))
                                sphere->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        break;
                    case DATA_ORMOROK:
                        if (state == DONE)
                        {
                            if (GameObject* sphere = instance->GetGameObject(OrmoroksContainmentSphere))
                                sphere->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ANOMALUS:
                        return AnomalusGUID;
                    case DATA_KERISTRASZA:
                        return KeristraszaGUID;
                    case ANOMALUS_CONTAINMENT_SPHERE:
                        return AnomalusContainmentSphere;
                    case ORMOROKS_CONTAINMENT_SPHERE:
                        return OrmoroksContainmentSphere;
                    case TELESTRAS_CONTAINMENT_SPHERE:
                        return TelestrasContainmentSphere;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

        private:
            ObjectGuid AnomalusGUID;
            ObjectGuid KeristraszaGUID;
            ObjectGuid AnomalusContainmentSphere;
            ObjectGuid OrmoroksContainmentSphere;
            ObjectGuid TelestrasContainmentSphere;
            uint32 _teamInInstance;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_nexus_InstanceMapScript(map);
        }
};

void AddSC_instance_nexus()
{
    new instance_nexus();
}
