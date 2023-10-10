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

/* ScriptData
SDName: instance_uldaman
SD%Complete: 80%
SDComment: Need some cosmetics updates when archeadas door are closing (Guardians Waypoints).
SDCategory: Uldaman
EndScriptData */

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
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

static constexpr DungeonEncounterData Encounters[] =
{
    { BOSS_REVELOSH, { { 547 } } },
    { BOSS_THE_LOST_DWARVES, { { 548 } } },
    { BOSS_IRONAYA, { { 549 } } },
    { BOSS_ANCIENT_STONE_KEEPER, { { 551 } } },
    { BOSS_GALGANN_FIREHAMMER, { { 552 } } },
    { BOSS_GRIMLOK, { { 553 } } },
    { BOSS_ARCHAEDAS, { { 554 } } },
    { BOSS_OBSIDIAN_SENTINEL, { { 1887 } } },
};

const Position IronayaPoint = { -231.228f, 246.6135f, -49.01617f, 0.0f };

class instance_uldaman : public InstanceMapScript
{
    public:
        instance_uldaman() : InstanceMapScript(UldamanScriptName, 70) { }

        struct instance_uldaman_InstanceMapScript : public InstanceScript
        {
            instance_uldaman_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(MAX_ENCOUNTER);
                LoadDungeonEncounterData(Encounters);

                ironayaActive = false;
                altarDoorsDone = false;
                ironayaSealDoorTimer = 27000; //animation time
                keystoneCheck = false;
            }

            ObjectGuid archaedasGUID;
            ObjectGuid ironayaGUID;
            bool ironayaActive;

            ObjectGuid whoWokeuiArchaedasGUID;

            ObjectGuid altarOfTheKeeperTempleDoor;
            bool altarDoorsDone;

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

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_ALTAR_OF_THE_KEEPER_TEMPLE_DOOR:         // lock the door
                        altarOfTheKeeperTempleDoor = go->GetGUID();

                        if (altarDoorsDone)
                           HandleGameObject(ObjectGuid::Empty, true, go);
                        break;

                    case GO_ARCHAEDAS_TEMPLE_DOOR:
                        archaedasTempleDoor = go->GetGUID();

                        if (altarDoorsDone)
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        break;

                    case GO_ANCIENT_VAULT_DOOR:
                        go->SetGoState(GO_STATE_READY);
                        go->ReplaceAllFlags(GO_FLAG_IN_USE | GO_FLAG_NODESPAWN);
                        ancientVaultDoor = go->GetGUID();

                        if (GetBossState(BOSS_ARCHAEDAS) == DONE)
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        break;

                    case GO_IRONAYA_SEAL_DOOR:
                        ironayaSealDoor = go->GetGUID();

                        if (ironayaActive)
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        break;

                    case GO_KEYSTONE:
                        keystoneGUID = go->GetGUID();

                        if (ironayaActive)
                        {
                            HandleGameObject(ObjectGuid::Empty, true, go);
                            go->SetFlag(GO_FLAG_INTERACT_COND);
                        }
                        break;
                }
            }

            void SetFrozenState(Creature* creature)
            {
                creature->SetFaction(FACTION_FRIENDLY);
                creature->RemoveAllAuras();
                creature->SetUninteractible(true);
                creature->SetControlled(true, UNIT_STATE_ROOT);
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

                go->SetFlag(GO_FLAG_INTERACT_COND);
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
                        target->SetControlled(false, UNIT_STATE_ROOT);
                        target->SetFaction(FACTION_MONSTER);
                        target->SetUninteractible(false);
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
                    if (!target || !target->IsAlive() || target->GetFaction() == FACTION_MONSTER)
                        continue;
                    target->SetControlled(false, UNIT_STATE_ROOT);
                    target->SetUninteractible(false);
                    target->SetFaction(FACTION_MONSTER);
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
                    if (!target || target->isDead() || target->GetFaction() != FACTION_MONSTER)
                        continue;
                    target->DespawnOrUnsummon();
                }

                // Vault Walkers
                for (GuidVector::const_iterator i = vaultWalkers.begin(); i != vaultWalkers.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (!target || target->isDead() || target->GetFaction() != FACTION_MONSTER)
                        continue;
                    target->DespawnOrUnsummon();
                }

                // Earthen Guardians
                for (GuidVector::const_iterator i = earthenGuardians.begin(); i != earthenGuardians.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (!target || target->isDead() || target->GetFaction() != FACTION_MONSTER)
                        continue;
                    target->DespawnOrUnsummon();
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
                    archaedas->SetFaction(FACTION_TITAN);
                    archaedas->SetUninteractible(false);
                    whoWokeuiArchaedasGUID = target;
                }
            }

            void ActivateIronaya()
            {
                Creature* ironaya = instance->GetCreature(ironayaGUID);
                if (!ironaya)
                    return;

                ironaya->SetFaction(FACTION_TITAN);
                ironaya->SetControlled(false, UNIT_STATE_ROOT);
                ironaya->SetUninteractible(false);

                ironaya->GetMotionMaster()->Clear();
                ironaya->GetMotionMaster()->MovePoint(0, IronayaPoint);
                ironaya->SetHomePosition(IronayaPoint);

                ironaya->AI()->Talk(SAY_AGGRO);
                ironayaActive = true;
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

                    keystoneCheck = false;
                }
                else
                    ironayaSealDoorTimer -= diff;
            }

            bool SetBossState(uint32 id, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(id, state))
                    return false;

                switch (id)
                {
                    case BOSS_ARCHAEDAS:
                        if (state == DONE) //archeadas defeat
                        {
                            SetDoor(archaedasTempleDoor, true); //re open enter door
                            SetDoor(ancientVaultDoor, true);
                        }
                        break;
                }

                return true;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_ALTAR_DOORS:
                        altarDoorsDone = data == DONE;
                        if (data == DONE)
                            SetDoor(altarOfTheKeeperTempleDoor, true);
                        break;

                    case DATA_IRONAYA_DOOR:
                        SetBossState(2, EncounterState(data));
                        break;

                    case DATA_STONE_KEEPERS:
                        ActivateStoneKeepers();
                        break;

                    case DATA_MINIONS:
                        switch (data)
                        {
                            case NOT_STARTED:
                                if (altarDoorsDone) //if players opened the doors
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

                        if (!ironayaActive)
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

            void OnUnitDeath(Unit* unit) override
            {
                switch (unit->GetEntry())
                {
                    case NPC_REVELOSH: SetBossState(BOSS_REVELOSH, DONE); break;
                    //case ?: SetBossState(BOSS_THE_LOST_DWARVES, DONE); break;
                    case NPC_ANCIENT_STONE_KEEPER: SetBossState(BOSS_ANCIENT_STONE_KEEPER, DONE); break;
                    case NPC_GALGANN_FIREHAMMER: SetBossState(BOSS_GALGANN_FIREHAMMER, DONE); break;
                    case NPC_GRIMLOK: SetBossState(BOSS_GRIMLOK, DONE); break;
                    case NPC_OBSIDIAN_SENTINEL: SetBossState(BOSS_OBSIDIAN_SENTINEL, DONE); break;
                    default: break;
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

            void ProcessEvent(WorldObject* /*gameObject*/, uint32 eventId, WorldObject* /*invoker*/) override
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
