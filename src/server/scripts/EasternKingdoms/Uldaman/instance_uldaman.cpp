/* Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
 SDName: Instance_Uldaman
 SD%Complete: 60
 SDComment:
 SDCategory: Uldaman
 EndScriptData
 */

#include "scriptPCH.h"
#include "uldaman.h"

struct instance_uldaman : public ScriptedInstance
{
    instance_uldaman(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };

    uint32 m_auiEncounter[ULDAMAN_MAX_ENCOUNTER];
    std::string strInstData;

    uint64 uiArchaedasGUID;
    uint64 uiAltarOfArchaedas;
    uint64 uiIronayaGUID;
    uint64 uiWhoWokeIronayaGUID;
    uint64 uiAltarOfTheKeeper;
    uint64 uiAltarOfTheKeeperTempleDoor;
    uint64 uiAncientVaultDoor;
    uint64 uiIronayaSealDoor;
    uint64 uiKeystoneGUID;
    uint64 uiArchaedasTempleDoor;
    uint32 uiIronayaSealDoorTimer;
    bool bKeystoneCheck;

    std::vector<uint64> vStoneKeeper;
    std::vector<uint64> vAltarOfTheKeeperCount;
    std::vector<uint64> vVaultWarder;
    std::vector<uint64> vVaultWarderFurniture;
    std::vector<uint64> vEarthenGuardian;
    std::vector<uint64> vArchaedasWallMinions; //Minions lined up around the wall

    void Initialize() override
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        uiArchaedasGUID = 0;
        uiAltarOfArchaedas = 0;
        uiIronayaGUID = 0;
        uiWhoWokeIronayaGUID = 0;
        uiAltarOfTheKeeper = 0;
        uiAltarOfTheKeeperTempleDoor = 0;
        uiArchaedasTempleDoor = 0;
        uiAncientVaultDoor = 0;
        uiIronayaSealDoor = 0;
        uiKeystoneGUID = 0;
        uiIronayaSealDoorTimer = 27000; //animation time
        bKeystoneCheck = false;
        vVaultWarder.reserve(2);
        vVaultWarderFurniture.reserve(2);
        vEarthenGuardian.reserve(6);
    }
        struct instance_uldaman_InstanceMapScript : public InstanceScript
        {
            instance_uldaman_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(MAX_ENCOUNTER);

                ironayaSealDoorTimer = 27000; //animation time
                keystoneCheck = false;
            }

    bool IsEncounterInProgress() const override
    {
        for (uint32 i : m_auiEncounter)
        {
            if (i == IN_PROGRESS)
            {
                return true;
            }
        }

        return false;
    }

            ObjectGuid archaedasGUID;
            ObjectGuid ironayaGUID;
            ObjectGuid whoWokeuiArchaedasGUID;

    void OnCreatureCreate(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_STONE_KEEPER:
                vStoneKeeper.push_back(pCreature->GetGUID());
                if (m_auiEncounter[ULDAMAN_ENCOUNTER_STONE_KEEPERS] != DONE)
                    RespawnMinion(pCreature->GetGUID());
                break;
            case NPC_EARTHEN_CUSTODIAN:
                vArchaedasWallMinions.push_back(pCreature->GetGUID());
                if (m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] != DONE)
                    RespawnMinion(pCreature->GetGUID());
                break;
            case NPC_EARTHEN_HALLSHAPER:
                vArchaedasWallMinions.push_back(pCreature->GetGUID());
                if (m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] != DONE)
                    RespawnMinion(pCreature->GetGUID());
                break;
            case NPC_EARTHEN_GUARDIAN:
                vEarthenGuardian.push_back(pCreature->GetGUID());
                if (m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] != DONE)
                    RespawnMinion(pCreature->GetGUID());
                break;
            case NPC_IRONAYA:
                uiIronayaGUID = pCreature->GetGUID();
                if (m_auiEncounter[ULDAMAN_ENCOUNTER_IRONAYA_DOOR] != DONE)
                {
                    SetFrozenState(pCreature);
                }
                break;
            case NPC_VAULT_WARDER:
                // Only take the ones inside Archaedas room
                if (pCreature->IsWithinDist2d(104, 272, 35.0f))
                {
                    vVaultWarder.push_back(pCreature->GetGUID());
                    if (m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] != DONE)
                        RespawnMinion(pCreature->GetGUID());
                }
                else
                    vVaultWarderFurniture.push_back(pCreature->GetGUID());
                break;
            case NPC_ARCHAEDAS:
                uiArchaedasGUID = pCreature->GetGUID();
                break;
        }
    }
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

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_ALTAR_OF_THE_KEEPER_TEMPLE_DOOR:         // lock the door
                        altarOfTheKeeperTempleDoor = go->GetGUID();

                        if (GetBossState(0) == DONE)
                           HandleGameObject(ObjectGuid::Empty, true, go);
                        break;

    void OnObjectCreate(GameObject* pGo) override
    {
        //sLog.outError("%s %u",pGo->GetNameForLocaleIdx(0),pGo->GetEntry());
        switch (pGo->GetEntry())
        {
            case GO_ALTAR_ARCHAEDAS:
                uiAltarOfArchaedas = pGo->GetGUID();
                break;
            case GO_ALTAR_KEEPERS:
                uiAltarOfTheKeeper = pGo->GetGUID();
                break;
            case GO_ALTAR_OF_THE_KEEPER_TEMPLE_DOOR:
                uiAltarOfTheKeeperTempleDoor = pGo->GetGUID();
                if (m_auiEncounter[ULDAMAN_ENCOUNTER_STONE_KEEPERS] == DONE)
                    pGo->UseDoorOrButton(0, false);
                break;
            case GO_ARCHAEDAS_TEMPLE_DOOR:
                uiArchaedasTempleDoor = pGo->GetGUID();
                if (m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] == DONE)
                    pGo->UseDoorOrButton(0, false);
                break;
            case GO_ANCIENT_VAULT_DOOR:
                pGo->SetGoState(GO_STATE_READY);
                pGo->SetUInt32Value(GAMEOBJECT_FLAGS, 33);
                uiAncientVaultDoor = pGo->GetGUID();
                if (m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] == DONE)
                    pGo->UseDoorOrButton(0, false);
                break;
            case GO_IRONAYA_SEAL_DOOR:
                uiIronayaSealDoor = pGo->GetGUID();
                if (m_auiEncounter[ULDAMAN_ENCOUNTER_IRONAYA_DOOR] == DONE)
                    pGo->UseDoorOrButton(0, false);
                break;
            case GO_KEYSTONE:
                uiKeystoneGUID = pGo->GetGUID();
                if (m_auiEncounter[ULDAMAN_ENCOUNTER_IRONAYA_DOOR] == DONE)
                    pGo->SetUInt32Value(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                break;
        }
    }
                    case GO_ARCHAEDAS_TEMPLE_DOOR:
                        archaedasTempleDoor = go->GetGUID();

                        if (GetBossState(0) == DONE)
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        break;

                    case GO_ANCIENT_VAULT_DOOR:
                        go->SetGoState(GO_STATE_READY);
                        go->ReplaceAllFlags(GO_FLAG_IN_USE | GO_FLAG_NODESPAWN);
                        ancientVaultDoor = go->GetGUID();

                        if (GetBossState(1) == DONE)
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        break;

                    case GO_IRONAYA_SEAL_DOOR:
                        ironayaSealDoor = go->GetGUID();

                        if (GetBossState(2) == DONE)
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        break;

                    case GO_KEYSTONE:
                        keystoneGUID = go->GetGUID();

                        if (GetBossState(2) == DONE)
                        {
                            HandleGameObject(ObjectGuid::Empty, true, go);
                            go->SetFlag(GO_FLAG_INTERACT_COND);
                        }
                        break;
                }
            }

    void SetFrozenState(Creature* creature)
    {
        creature->SetFactionTemplateId(FACTION_STONED);
        creature->RemoveAllAuras();
        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        if (!creature->HasAura(SPELL_STONED))
        {
            creature->CastSpell(creature, SPELL_STONED, false);
        }
    }
            void SetFrozenState(Creature* creature)
            {
                creature->SetFaction(FACTION_FRIENDLY);
                creature->RemoveAllAuras();
                creature->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                creature->SetControlled(true, UNIT_STATE_ROOT);
                creature->AddAura(SPELL_MINION_FREEZE_ANIM, creature);
            }

    void SetUnFrozenState(Creature* creature)
    {
        creature->SetFactionTemplateId(FACTION_AWAKE);
        if (creature->HasAura(SPELL_STONED))
        {
            creature->RemoveAurasDueToSpell(SPELL_STONED);
        }
        creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        //creature->ClearUnitState(UNIT_STAT_ROOT | UNIT_STAT_PENDING_ROOT);
        //creature->RemoveFlag(UNIT_FIELD_FLAGS,
    //                    UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
    }

    void RespawnMinion(uint64 guid)
    {
        Creature* target = instance->GetCreature(guid);
        if (!target || (target->IsAlive() && target->GetFactionTemplateId() == FACTION_STONED))
            return;
        if (target->IsAlive())
        {
            target->SetDeathState(JUST_DIED);
            target->RemoveCorpse();
        }
        target->Respawn();
        target->SetFactionTemplateId(FACTION_STONED);
    }

    void DespawnMinion(uint64 guid)
    {
        Creature* target = instance->GetCreature(guid);
        if (!target || target->IsDead())
            return;
        target->SetDeathState(JUST_DIED);
        target->RemoveCorpse();
    }
                go->SetFlag(GO_FLAG_INTERACT_COND);
            }

    void SetData64(uint32 type, uint64 data) override
    {
        // Ironaya's waker
        if (type == 0)
        {
            uiWhoWokeIronayaGUID = data;
        }
        // Unfreeze this creature
        else if (type == 1)
        {
            if (Creature* target = GetMap()->GetCreature(data))
            {
                SetUnFrozenState(target);
            }
        }
        // Freeze this creature
        else if (type == 2)
        {
            if (Creature* target = GetMap()->GetCreature(data))
            {
                SetFrozenState(target);
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
                        target->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                        target->RemoveAura(SPELL_MINION_FREEZE_ANIM);

                        return;        // only want the first one we find
                    }
                    // if we get this far than all four are dead so open the door
                    SetData(DATA_ALTAR_DOORS, DONE);
                    SetDoor(archaedasTempleDoor, true); //open next the door too
                }
            }
        }
    }

    uint64 GetData64(uint32 uiData) override
    {
        if (uiData == 0) return uiWhoWokeIronayaGUID;
        if (uiData == 1) return vVaultWarder[0]; // VaultWarder1
        if (uiData == 2) return vVaultWarder[1]; // VaultWarder2
        if (uiData == 5) return vEarthenGuardian[0];
        if (uiData == 6) return vEarthenGuardian[1];
        if (uiData == 7) return vEarthenGuardian[2];
        if (uiData == 8) return vEarthenGuardian[3];
        if (uiData == 9) return vEarthenGuardian[4];
        if (uiData == 10) return vEarthenGuardian[5];
        if (uiData == 11) return uiArchaedasGUID;
        if (uiData == 12) return vVaultWarderFurniture[0];
        if (uiData == 13) return vVaultWarderFurniture[1];

        return 0;
    }
                for (GuidVector::const_iterator i = archaedasWallMinions.begin(); i != archaedasWallMinions.end(); ++i)
                {
                    Creature* target = instance->GetCreature(*i);
                    if (!target || !target->IsAlive() || target->GetFaction() == FACTION_MONSTER)
                        continue;
                    target->SetControlled(false, UNIT_STATE_ROOT);
                    target->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    target->SetFaction(FACTION_MONSTER);
                    target->RemoveAura(SPELL_MINION_FREEZE_ANIM);
                    archaedas->CastSpell(target, SPELL_AWAKEN_VAULT_WALKER, true);
                    target->CastSpell(target, SPELL_ARCHAEDAS_AWAKEN, true);

    void SetData(uint32 uiType, uint32 uiData) override
    {
        switch (uiType)
        {
            case ULDAMAN_ENCOUNTER_IRONAYA_DOOR:
                if (uiData == DONE)
                {
                    bKeystoneCheck = true;
                    m_auiEncounter[ULDAMAN_ENCOUNTER_IRONAYA_DOOR] = uiData;
                }
                break;
            case DATA_KEEPERS_ALTAR :
                if (uiData == IN_PROGRESS)
                {
                    if(GameObject* pGo = instance->GetGameObject(uiAltarOfTheKeeper))
                        pGo->SetGoState(GO_STATE_ACTIVE);
                }
                else if (uiData == NOT_STARTED)
                {
                    if(GameObject* pGo = instance->GetGameObject(uiAltarOfTheKeeper))
                        pGo->SetGoState(GO_STATE_READY);
                }
                break;
            case ULDAMAN_ENCOUNTER_STONE_KEEPERS:
                switch (uiData)
                {
                    case DONE:
                        m_auiEncounter[ULDAMAN_ENCOUNTER_STONE_KEEPERS] = uiData;
                        DoOpenDoor(uiAltarOfTheKeeperTempleDoor);
                        break;
                    case IN_PROGRESS:
                    {
                        m_auiEncounter[ULDAMAN_ENCOUNTER_STONE_KEEPERS] = uiData;
                        /** Check the list of Stone Keeper created at instance creation */
                        Creature* target = nullptr;
                        bool encounterDone = true;
                        for (const auto& guid : vStoneKeeper)
                        {
                            Creature* current = instance->GetCreature(guid);
                    Creature* target = instance->GetCreature(*i);
                    if (!target || target->isDead() || target->GetFaction() != FACTION_MONSTER)
                        continue;
                    target->DespawnOrUnsummon();
                }

                            /* Do nothing if one is already alive and awaken */
                            if (current && current->IsAlive() && current->GetFactionTemplateId() == FACTION_AWAKE)
                            {
                                target = nullptr;
                                encounterDone = false;
                                break;
                            }
                            /* Save a creature that can be awaken for later */
                            if (!target && current && current->IsAlive() && current->GetFactionTemplateId() != FACTION_AWAKE)
                            {
                                target = current;
                            }
                        }
                        if (target)
                        {
                            encounterDone = false;
                            /** Creature become alive */
                            SetUnFrozenState(target);
                            if (Unit* victim = target->SelectNearestTarget(80.0f))
                            {
                                target->AI()->AttackStart(victim);
                            }
                            else
                            {
                                SetData(ULDAMAN_ENCOUNTER_STONE_KEEPERS, FAIL);
                            }
                        }
                        if (encounterDone)
                            SetData(ULDAMAN_ENCOUNTER_STONE_KEEPERS, DONE); //Open the doors
                        break;
                    }
                    case FAIL:
                        m_auiEncounter[ULDAMAN_ENCOUNTER_STONE_KEEPERS] = uiData;
                        for (const auto& guid : vStoneKeeper)
                        {
                            Creature* target = instance->GetCreature(guid);
                            if (!target)
                            {
                                continue;
                            }
                            if (target->IsDead())
                            {
                                target->Respawn();
                                SetFrozenState(target);
                            }
                            else if (target->GetFactionTemplateId() == FACTION_AWAKE)
                            {
                                target->SetDeathState(JUST_DIED);
                                target->RemoveCorpse();
                                target->Respawn();
                                SetFrozenState(target);
                            }
                        }
                        break;
                    default:
                        m_auiEncounter[ULDAMAN_ENCOUNTER_STONE_KEEPERS] = uiData;
                        break;
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
                    archaedas->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
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
                ironaya->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);

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
                break;
            case DATA_ANCIENT_DOOR:
                if (uiData == DONE) //archeadas defeat
                {
                    DoOpenDoor(uiArchaedasTempleDoor); //re open entrance
                    DoOpenDoor(uiAncientVaultDoor);
                }
                else if (uiData == FAIL)
                {
                    DoOpenDoor(uiArchaedasTempleDoor);
                    if (GameObject* pGo = GetGameObject(uiArchaedasTempleDoor))
                        pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
                }
                else if (uiData == IN_PROGRESS)
                {
                    DoResetDoor(uiArchaedasTempleDoor); //reset the door
                    if (GameObject* pGo = GetGameObject(uiArchaedasTempleDoor))
                        pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
                }
                break;
            case DATA_ARCHAEDAS_ALTAR :
                if (uiData == IN_PROGRESS)
                {
                    if(GameObject* pGo = instance->GetGameObject(uiAltarOfArchaedas))
                    {
                        pGo->SetGoState(GO_STATE_ACTIVE);
                    }
                }
                else if (uiData == NOT_STARTED)
                {
                    if(GameObject* pGo = instance->GetGameObject(uiAltarOfArchaedas))
                    {
                        pGo->SetGoState(GO_STATE_READY);
                    }
                }
                break;
            case ULDAMAN_ENCOUNTER_ARCHAEDAS:
            {
                Creature* archaedas = instance->GetCreature(uiArchaedasGUID);
                switch (uiData)
                {
                    case IN_PROGRESS: // Event is started
                    {
                        if (m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] != IN_PROGRESS)
                        {
                            if (m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] != DONE)
                                SetData(DATA_ANCIENT_DOOR, IN_PROGRESS);
                            if (archaedas)
                            {
                                if (archaedas->IsAlive() && archaedas->GetFactionTemplateId() != FACTION_AWAKE)
                                {
                                    archaedas->CastSpell(archaedas, SPELL_ARCHAEDAS_AWAKEN, false);
                                    SetUnFrozenState(archaedas);
                                }
                            }
                        }
                        else if (archaedas) // Wake a wall minion
                        {
                            for (const auto& i : vArchaedasWallMinions)
                            {
                                Creature* target = instance->GetCreature(i);
                                if (!target || !target->IsAlive() || target->GetFactionTemplateId() == FACTION_AWAKE)
                                {
                                    continue;
                                }
                                archaedas->CastSpell(target, SPELL_AWAKEN_EARTHEN_DWARF, false);
                                target->SetFactionTemplateId(FACTION_AWAKE);
                                break; // only want the first one we find
                            }
                        }
                        m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] = uiData;
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
                        SetBossState(0, EncounterState(data));
                        if (data == DONE)
                            SetDoor(altarOfTheKeeperTempleDoor, true);
                        break;
                    }
                    case NOT_STARTED: // Archaedas reaches his spawn point
                        // respawn any aggroed wall minions
                        for (const auto& i : vArchaedasWallMinions)
                            RespawnMinion(i);
                        // Vault Warders
                        for (const auto& i : vVaultWarder)
                            RespawnMinion(i);
                        // Earthen Guardians
                        for (const auto& i : vEarthenGuardian)
                            RespawnMinion(i);
                        // Furniture
                        for (const auto& i : vVaultWarderFurniture)

                    case DATA_ANCIENT_DOOR:
                        SetBossState(1, EncounterState(data));
                        if (data == DONE) //archeadas defeat
                        {
                            Creature* target = instance->GetCreature(i);
                            if (target && target->IsDespawned())
                                target->Respawn();
                        }
                        if (archaedas)
                            SetFrozenState(archaedas);
                        m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] = uiData;
                        break;

                    case DATA_IRONAYA_DOOR:
                        SetBossState(2, EncounterState(data));
                        break;
                    case FAIL: // Archaedas resets and moves towards his spawn point
                        m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] = uiData;
                        SetData(DATA_ANCIENT_DOOR, FAIL); // open the temple door
                        break;
                    case DONE: // Archaedas is dead
                        m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] = uiData;
                        // remove anything that isn't dead
                        // Wall minions
                        for (const auto& i : vArchaedasWallMinions)
                            DespawnMinion(i);
                        // Vault Warders
                        for (const auto& i : vVaultWarder)
                            DespawnMinion(i);
                        // Earthen Guardians
                        for (const auto& i : vEarthenGuardian)
                            DespawnMinion(i);
                        // Furniture
                        for (const auto& i : vVaultWarderFurniture)
                        {
                            Creature* target = instance->GetCreature(i);
                            if (target && target->IsDespawned())
                                target->Respawn();
                        }
                        // Open the Vault door
                        SetData(DATA_ANCIENT_DOOR, DONE);
                        // Summon Ancient Treasure
                        instance->SummonGameObject(GO_ANCIENT_TREASURE, 153.39f, 289.091f, -52.2262f, 2.68781f,
                                0, 0, 0.97437f, 0.224951f, -1, 0);
                        break;
                    default:
                        m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS] = uiData;
                        break;
                }
            }
        }

        if (uiType < ULDAMAN_MAX_ENCOUNTER && uiData == DONE)
        {
            OUT_SAVE_INST_DATA;
            std::ostringstream saveStream;
            saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2];
            strInstData = saveStream.str();
            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }
                            case NOT_STARTED:
                                if (GetBossState(0) == DONE) //if players opened the doors
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

    char const* Save() override
    {
        return strInstData.c_str();
    }

    void Load(char const* chrIn) override
    {
        if (!chrIn)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(chrIn);
        std::istringstream loadStream(chrIn);
        loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2];
        for (uint32 & i : m_auiEncounter)
            if (i != DONE)
                i = NOT_STARTED;
        OUT_LOAD_INST_DATA_COMPLETE;
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

    uint32 GetData(uint32 uiType) override
    {
        if (uiType == ULDAMAN_ENCOUNTER_IRONAYA_DOOR) return m_auiEncounter[ULDAMAN_ENCOUNTER_IRONAYA_DOOR];
        if (uiType == ULDAMAN_ENCOUNTER_STONE_KEEPERS) return m_auiEncounter[ULDAMAN_ENCOUNTER_STONE_KEEPERS];
        if (uiType == ULDAMAN_ENCOUNTER_ARCHAEDAS) return m_auiEncounter[ULDAMAN_ENCOUNTER_ARCHAEDAS];
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

                        if (GetBossState(2) != DONE)
                            SetFrozenState (creature);
                        break;

                    case 10120:    // Vault Walker
                        vaultWalkers.push_back(creature->GetGUID());
                        break;

                    case 2748:    // Archaedas
                        archaedasGUID = creature->GetGUID();
                        break;

        return 0;
    }

    void Update(uint32 uiDiff) override
    {
        if (!bKeystoneCheck)
        {
            return;
        }
        if (uiIronayaSealDoorTimer <= uiDiff)
        {
            Creature* ironaya = instance->GetCreature(uiIronayaGUID);
            if (!ironaya)
                return;
            SetUnFrozenState(ironaya);
            DoOpenDoor(uiIronayaSealDoor);
            bKeystoneCheck = false;
        }
        else
        {
            uiIronayaSealDoorTimer -= uiDiff;
        }
    }
};
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

InstanceData* GetInstanceData_instance_uldaman(Map* pMap)
{
    return new instance_uldaman(pMap);
}

void AddSC_instance_uldaman()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "instance_uldaman";
    pNewScript->GetInstanceData = &GetInstanceData_instance_uldaman;
    pNewScript->RegisterSelf();
}
