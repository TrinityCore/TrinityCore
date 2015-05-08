/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
SD%Complete: 80%
SDComment: Need some cosmetics updates when archeadas door are closing (Guardians Waypoints).
SDCategory: Uldaman
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "uldaman.h"

enum Spells
{
    SPELL_ARCHAEDAS_AWAKEN      = 10347,
    SPELL_AWAKEN_VAULT_WALKER   = 10258,
    SPELL_FREEZE_ANIM           = 16245,
    SPELL_MINION_FREEZE_ANIM    = 10255
};

enum Events
{
    EVENT_SUB_BOSS_AGGRO        = 2228
};

enum IronayaTalk
{
    SAY_AGGRO = 0
};

const Position IronayaPoint = { -231.228f, 246.6135f, -49.01617f, 0.0f };

class instance_uldaman : public InstanceMapScript
{
    public:
        instance_uldaman() : InstanceMapScript("instance_uldaman", 70) { }

        struct instance_uldaman_InstanceMapScript : public InstanceScript
        {
            instance_uldaman_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

                ironayaSealDoorTimer = 27000; //animation time
                keystoneCheck = false;
            }

            bool IsEncounterInProgress() const override
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        return true;

                return false;
            }

            ObjectGuid archaedasGUID;
            ObjectGuid ironayaGUID;
            ObjectGuid whoWokeuiArchaedasGUID;

            ObjectGuid altarOfTheKeeperTempleDoor;
            ObjectGuid archaedasTempleDoor;
            ObjectGuid ancientVaultDoor;
            ObjectGuid ironayaSealDoor;

            ObjectGuid keystoneGUID;

            uint32 ironayaSealDoorTimer;
            bool keystoneCheck;

            GuidVector stoneKeepers;
            GuidVector altarOfTheKeeperCounts;
            GuidVector vaultWalkers;
            GuidVector earthenGuardians;
            GuidVector archaedasWallMinions;    // minions lined up around the wall

            uint32 m_auiEncounter[MAX_ENCOUNTER];
            std::string str_data;

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_ALTAR_OF_THE_KEEPER_TEMPLE_DOOR:         // lock the door
                        altarOfTheKeeperTempleDoor = go->GetGUID();

                        if (m_auiEncounter[0] == DONE)
                           HandleGameObject(ObjectGuid::Empty, true, go);
                        break;

                    case GO_ARCHAEDAS_TEMPLE_DOOR:
                        archaedasTempleDoor = go->GetGUID();

                        if (m_auiEncounter[0] == DONE)
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        break;

                    case GO_ANCIENT_VAULT_DOOR:
                        go->SetGoState(GO_STATE_READY);
                        go->SetUInt32Value(GAMEOBJECT_FLAGS, 33);
                        ancientVaultDoor = go->GetGUID();

                        if (m_auiEncounter[1] == DONE)
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        break;

                    case GO_IRONAYA_SEAL_DOOR:
                        ironayaSealDoor = go->GetGUID();

                        if (m_auiEncounter[2] == DONE)
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        break;

                    case GO_KEYSTONE:
                        keystoneGUID = go->GetGUID();

                        if (m_auiEncounter[2] == DONE)
                        {
                            HandleGameObject(ObjectGuid::Empty, true, go);
                            go->SetUInt32Value(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                        }
                        break;
                }
            }

            void SetFrozenState(Creature* creature)
            {
                creature->setFaction(35);
                creature->RemoveAllAuras();
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                creature->AddAura(SPELL_MINION_FREEZE_ANIM, creature);
            }

            void SetDoor(ObjectGuid guid, bool open)
            {
                GameObject* go = instance->GetGameObject(guid);
                if (!go)
                    return;

                HandleGameObject(guid, open);
            }

            void BlockGO(ObjectGuid guid)
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
                    for (GuidVector::const_iterator i = stoneKeepers.begin(); i != stoneKeepers.end(); ++i)
                    {
                        Creature* target = instance->GetCreature(*i);
                        if (!target || !target->IsAlive())
                            continue;
                        target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                        target->setFaction(14);
                        target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        target->RemoveAura(SPELL_MINION_FREEZE_ANIM);

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

                for (GuidVector::const_iterator i = archaedasWallMinions.begin(); i != archaedasWallMinions.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (!target || !target->IsAlive() || target->getFaction() == 14)
                        continue;
                    target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    target->setFaction(14);
                    target->RemoveAura(SPELL_MINION_FREEZE_ANIM);
                    archaedas->CastSpell(target, SPELL_AWAKEN_VAULT_WALKER, true);
                    target->CastSpell(target, SPELL_ARCHAEDAS_AWAKEN, true);

                    return;        // only want the first one we find
                }
            }

            // used when Archaedas dies.  All active minions must be despawned.
            void DeActivateMinions()
            {
                // first despawn any aggroed wall minions
                for (GuidVector::const_iterator i = archaedasWallMinions.begin(); i != archaedasWallMinions.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (!target || target->isDead() || target->getFaction() != 14)
                        continue;
                    target->setDeathState(JUST_DIED);
                    target->RemoveCorpse();
                }

                // Vault Walkers
                for (GuidVector::const_iterator i = vaultWalkers.begin(); i != vaultWalkers.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (!target || target->isDead() || target->getFaction() != 14)
                        continue;
                    target->setDeathState(JUST_DIED);
                    target->RemoveCorpse();
                }

                // Earthen Guardians
                for (GuidVector::const_iterator i = earthenGuardians.begin(); i != earthenGuardians.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (!target || target->isDead() || target->getFaction() != 14)
                        continue;
                    target->setDeathState(JUST_DIED);
                    target->RemoveCorpse();
                }
            }

            void ActivateArchaedas(ObjectGuid target)
            {
                Creature* archaedas = instance->GetCreature(archaedasGUID);
                if (!archaedas)
                    return;

                if (ObjectAccessor::GetUnit(*archaedas, target))
                {
                    archaedas->RemoveAura(SPELL_FREEZE_ANIM);
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

                ironaya->GetMotionMaster()->Clear();
                ironaya->GetMotionMaster()->MovePoint(0, IronayaPoint);
                ironaya->SetHomePosition(IronayaPoint);

                ironaya->AI()->Talk(SAY_AGGRO);
            }

            void RespawnMinions()
            {
                // first respawn any aggroed wall minions
                for (GuidVector::const_iterator i = archaedasWallMinions.begin(); i != archaedasWallMinions.end(); ++i)
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
                for (GuidVector::const_iterator i = vaultWalkers.begin(); i != vaultWalkers.end(); ++i)
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
                for (GuidVector::const_iterator i = earthenGuardians.begin(); i != earthenGuardians.end(); ++i)
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
            void Update(uint32 diff) override
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

            void SetData(uint32 type, uint32 data) override
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

            void SetGuidData(uint32 type, ObjectGuid data) override
            {
                // Archaedas
                if (type == 0)
                {
                    ActivateArchaedas (data);
                    SetDoor(archaedasTempleDoor, false); //close when event is started
                }
            }

            std::string GetSaveData() override
            {
                return str_data;
            }

            void Load(const char* in) override
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

            void OnCreatureCreate(Creature* creature) override
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

            ObjectGuid GetGuidData(uint32 identifier) const override
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

                return ObjectGuid::Empty;
            } // end GetGuidData

            void ProcessEvent(WorldObject* /*gameObject*/, uint32 eventId) override
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

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_uldaman_InstanceMapScript(map);
        }
};

void AddSC_instance_uldaman()
{
    new instance_uldaman();
}
