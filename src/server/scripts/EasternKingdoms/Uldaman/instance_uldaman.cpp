/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: instance_uldaman
SD%Complete: 99
SDComment: Need some cosmetics updates when archeadas door are closing (Guardians Waypoints).
SDCategory: Uldaman
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "uldaman.h"

enum Spells
{
    SPELL_ARCHAEDAS_AWAKEN      = 10347,
    SPELL_AWAKEN_VAULT_WALKER   = 10258,
};

enum Events
{
    EVENT_SUB_BOSS_AGGRO        = 2228
};

class instance_uldaman : public InstanceMapScript
{
    public:
        instance_uldaman() : InstanceMapScript("instance_uldaman", 70) { }

        struct instance_uldaman_InstanceMapScript : public InstanceScript
        {
            instance_uldaman_InstanceMapScript(Map* map) : InstanceScript(map) { }

            void Initialize() OVERRIDE
            {
                memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

                archaedasGUID = 0;
                ironayaGUID = 0;
                whoWokeuiArchaedasGUID = 0;

                altarOfTheKeeperTempleDoor = 0;
                archaedasTempleDoor = 0;
                ancientVaultDoor = 0;

                ironayaSealDoor = 0;

                keystoneGUID = 0;

                ironayaSealDoorTimer = 27000; //animation time
                keystoneCheck = false;
            }

            bool IsEncounterInProgress() const OVERRIDE
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        return true;

                return false;
            }

            uint64 archaedasGUID;
            uint64 ironayaGUID;
            uint64 whoWokeuiArchaedasGUID;

            uint64 altarOfTheKeeperTempleDoor;
            uint64 archaedasTempleDoor;
            uint64 ancientVaultDoor;
            uint64 ironayaSealDoor;

            uint64 keystoneGUID;

            uint32 ironayaSealDoorTimer;
            bool keystoneCheck;

            std::vector<uint64> stoneKeepers;
            std::vector<uint64> altarOfTheKeeperCounts;
            std::vector<uint64> vaultWalkers;
            std::vector<uint64> earthenGuardians;
            std::vector<uint64> archaedasWallMinions;    // minions lined up around the wall

            uint32 m_auiEncounter[MAX_ENCOUNTER];
            std::string str_data;

            void OnGameObjectCreate(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_ALTAR_OF_THE_KEEPER_TEMPLE_DOOR:         // lock the door
                        altarOfTheKeeperTempleDoor = go->GetGUID();

                        if (m_auiEncounter[0] == DONE)
                           HandleGameObject(0, true, go);
                        break;

                    case GO_ARCHAEDAS_TEMPLE_DOOR:
                        archaedasTempleDoor = go->GetGUID();

                        if (m_auiEncounter[0] == DONE)
                            HandleGameObject(0, true, go);
                        break;

                    case GO_ANCIENT_VAULT_DOOR:
                        go->SetGoState(GO_STATE_READY);
                        go->SetUInt32Value(GAMEOBJECT_FLAGS, 33);
                        ancientVaultDoor = go->GetGUID();

                        if (m_auiEncounter[1] == DONE)
                            HandleGameObject(0, true, go);
                        break;

                    case GO_IRONAYA_SEAL_DOOR:
                        ironayaSealDoor = go->GetGUID();

                        if (m_auiEncounter[2] == DONE)
                            HandleGameObject(0, true, go);
                        break;

                    case GO_KEYSTONE:
                        keystoneGUID = go->GetGUID();

                        if (m_auiEncounter[2] == DONE)
                        {
                            HandleGameObject(0, true, go);
                            go->SetUInt32Value(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                        }
                        break;
                }
            }

            void SetFrozenState(Creature* creature)
            {
                creature->setFaction(35);
                creature->RemoveAllAuras();
                //creature->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_ANIMATION_FROZEN);
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            }

            void SetDoor(uint64 guid, bool open)
            {
                GameObject* go = instance->GetGameObject(guid);
                if (!go)
                    return;

                HandleGameObject(guid, open);
            }

            void BlockGO(uint64 guid)
            {
                GameObject* go = instance->GetGameObject(guid);
                if (!go)
                    return;

                go->SetUInt32Value(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
            }

            void ActivateStoneKeepers()
            {
                if (GetData(DATA_ALTAR_DOORS) != DONE)
                {
                    for (std::vector<uint64>::const_iterator i = stoneKeepers.begin(); i != stoneKeepers.end(); ++i)
                    {
                        Creature* target = instance->GetCreature(*i);
                        if (!target || !target->IsAlive())
                            continue;
                        target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                        target->setFaction(14);
                        target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        return;        // only want the first one we find
                    }
                    // if we get this far than all four are dead so open the door
                    SetData(DATA_ALTAR_DOORS, DONE);
                    SetDoor(archaedasTempleDoor, true); //open next the door too
                }
            }

            void ActivateWallMinions()
            {
                Creature* archaedas = instance->GetCreature(archaedasGUID);
                if (!archaedas)
                    return;

                for (std::vector<uint64>::const_iterator i = archaedasWallMinions.begin(); i != archaedasWallMinions.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (!target || !target->IsAlive() || target->getFaction() == 14)
                        continue;
                    archaedas->CastSpell(target, SPELL_AWAKEN_VAULT_WALKER, true);
                    target->CastSpell(target, SPELL_ARCHAEDAS_AWAKEN, true);
                    target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    target->setFaction(14);
                    return;        // only want the first one we find
                }
            }

            // used when Archaedas dies.  All active minions must be despawned.
            void DeActivateMinions()
            {
                // first despawn any aggroed wall minions
                for (std::vector<uint64>::const_iterator i = archaedasWallMinions.begin(); i != archaedasWallMinions.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (!target || target->isDead() || target->getFaction() != 14)
                        continue;
                    target->setDeathState(JUST_DIED);
                    target->RemoveCorpse();
                }

                // Vault Walkers
                for (std::vector<uint64>::const_iterator i = vaultWalkers.begin(); i != vaultWalkers.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (!target || target->isDead() || target->getFaction() != 14)
                        continue;
                    target->setDeathState(JUST_DIED);
                    target->RemoveCorpse();
                }

                // Earthen Guardians
                for (std::vector<uint64>::const_iterator i = earthenGuardians.begin(); i != earthenGuardians.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (!target || target->isDead() || target->getFaction() != 14)
                        continue;
                    target->setDeathState(JUST_DIED);
                    target->RemoveCorpse();
                }
            }

            void ActivateArchaedas(uint64 target)
            {
                Creature* archaedas = instance->GetCreature(archaedasGUID);
                if (!archaedas)
                    return;

                if (Unit::GetUnit(*archaedas, target))
                {
                    archaedas->CastSpell(archaedas, SPELL_ARCHAEDAS_AWAKEN, false);
                    whoWokeuiArchaedasGUID = target;
                }
            }

            void ActivateIronaya()
            {
                Creature* ironaya = instance->GetCreature(ironayaGUID);
                if (!ironaya)
                    return;

                ironaya->setFaction(415);
                ironaya->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                ironaya->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void RespawnMinions()
            {
                // first respawn any aggroed wall minions
                for (std::vector<uint64>::const_iterator i = archaedasWallMinions.begin(); i != archaedasWallMinions.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (target && target->isDead())
                    {
                        target->Respawn();
                        target->GetMotionMaster()->MoveTargetedHome();
                        SetFrozenState(target);
                    }
                }

                // Vault Walkers
                for (std::vector<uint64>::const_iterator i = vaultWalkers.begin(); i != vaultWalkers.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (target && target->isDead())
                    {
                        target->Respawn();
                        target->GetMotionMaster()->MoveTargetedHome();
                        SetFrozenState(target);
                    }
                }

                // Earthen Guardians
                for (std::vector<uint64>::const_iterator i = earthenGuardians.begin(); i != earthenGuardians.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (target && target->isDead())
                    {
                        target->Respawn();
                        target->GetMotionMaster()->MoveTargetedHome();
                        SetFrozenState(target);
                    }
                }
            }
            void Update(uint32 diff) OVERRIDE
            {
                if (!keystoneCheck)
                    return;

                if (ironayaSealDoorTimer <= diff)
                {
                    ActivateIronaya();

                    SetDoor(ironayaSealDoor, true);
                    BlockGO(keystoneGUID);

                    SetData(DATA_IRONAYA_DOOR, DONE); //save state
                    keystoneCheck = false;
                }
                else
                    ironayaSealDoorTimer -= diff;
            }

            void SetData(uint32 type, uint32 data) OVERRIDE
            {
                switch (type)
                {
                    case DATA_ALTAR_DOORS:
                        m_auiEncounter[0] = data;
                        if (data == DONE)
                            SetDoor(altarOfTheKeeperTempleDoor, true);
                        break;

                    case DATA_ANCIENT_DOOR:
                        m_auiEncounter[1] = data;
                        if (data == DONE) //archeadas defeat
                        {
                            SetDoor(archaedasTempleDoor, true); //re open enter door
                            SetDoor(ancientVaultDoor, true);
                        }
                        break;

                    case DATA_IRONAYA_DOOR:
                        m_auiEncounter[2] = data;
                        break;

                    case DATA_STONE_KEEPERS:
                        ActivateStoneKeepers();
                        break;

                    case DATA_MINIONS:
                        switch (data)
                        {
                            case NOT_STARTED:
                                if (m_auiEncounter[0] == DONE) //if players opened the doors
                                    SetDoor(archaedasTempleDoor, true);

                                RespawnMinions();
                                break;

                            case IN_PROGRESS:
                                ActivateWallMinions();
                                break;

                            case SPECIAL:
                                DeActivateMinions();
                                break;
                        }
                        break;

                    case DATA_IRONAYA_SEAL:
                        keystoneCheck = true;
                        break;
                }

                if (data == DONE)
                {
                    OUT_SAVE_INST_DATA;

                    std::ostringstream saveStream;
                    saveStream << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' ' << m_auiEncounter[2];

                    str_data = saveStream.str();

                    SaveToDB();
                    OUT_SAVE_INST_DATA_COMPLETE;
                }
            }

            void SetData64(uint32 type, uint64 data) OVERRIDE
            {
                // Archaedas
                if (type == 0)
                {
                    ActivateArchaedas (data);
                    SetDoor(archaedasTempleDoor, false); //close when event is started
                }
            }

            std::string GetSaveData() OVERRIDE
            {
                return str_data;
            }

            void Load(const char* in) OVERRIDE
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(in);

                std::istringstream loadStream(in);
                loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2];

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;
                }

                OUT_LOAD_INST_DATA_COMPLETE;
            }

            void OnCreatureCreate(Creature* creature) OVERRIDE
            {
                switch (creature->GetEntry())
                {
                    case 4857:    // Stone Keeper
                        SetFrozenState (creature);
                        stoneKeepers.push_back(creature->GetGUID());
                        break;

                    case 7309:    // Earthen Custodian
                        archaedasWallMinions.push_back(creature->GetGUID());
                        break;

                    case 7077:    // Earthen Hallshaper
                        archaedasWallMinions.push_back(creature->GetGUID());
                        break;

                    case 7076:    // Earthen Guardian
                        earthenGuardians.push_back(creature->GetGUID());
                        break;

                    case 7228:    // Ironaya
                        ironayaGUID = creature->GetGUID();

                        if (m_auiEncounter[2] != DONE)
                            SetFrozenState (creature);
                        break;

                    case 10120:    // Vault Walker
                        vaultWalkers.push_back(creature->GetGUID());
                        break;

                    case 2748:    // Archaedas
                        archaedasGUID = creature->GetGUID();
                        break;

                }
            }

            uint64 GetData64(uint32 identifier) const OVERRIDE
            {
                switch (identifier)
                {
                    case 0:
                        return whoWokeuiArchaedasGUID;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        return vaultWalkers.at(identifier - 1);
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                        return earthenGuardians.at(identifier - 5);
                    default:
                        break;
                }

                return 0;
            } // end GetData64

            void ProcessEvent(WorldObject* /*gameObject*/, uint32 eventId) OVERRIDE
            {
                switch (eventId)
                {
                    case EVENT_SUB_BOSS_AGGRO:
                        SetData(DATA_STONE_KEEPERS, IN_PROGRESS); // activate the Stone Keepers
                        break;
                    default:
                        break;
                }
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_uldaman_InstanceMapScript(map);
        }
};

void AddSC_instance_uldaman()
{
    new instance_uldaman();
}
