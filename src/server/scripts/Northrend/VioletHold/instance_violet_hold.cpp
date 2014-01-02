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
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "violet_hold.h"
#include "Player.h"
#include "TemporarySummon.h"

/* Violet Hold encounters:
0 - First boss
1 - Second boss
2 - Cyanigosa*/

/* Violet hold bosses:
1 - Moragg
2 - Erekem
3 - Ichoron
4 - Lavanthor
5 - Xevozz
6 - Zuramat
7 - Cyanigosa */

enum AzureSaboteurSpells
{
    SABOTEUR_SHIELD_DISRUPTION                      = 58291,
    SABOTEUR_SHIELD_EFFECT                          = 45775
};

enum CrystalSpells
{
    SPELL_ARCANE_LIGHTNING                          = 57930
};

Position const PortalLocation[] =
{
    { 1877.51f, 850.104f, 44.6599f, 4.78220f },     // WP 1
    { 1918.37f, 853.437f, 47.1624f, 4.12294f },     // WP 2
    { 1936.07f, 803.198f, 53.3749f, 3.12414f },     // WP 3
    { 1927.61f, 758.436f, 51.4533f, 2.20891f },     // WP 4
    { 1890.64f, 753.471f, 48.7224f, 1.71042f },     // WP 5
    { 1908.31f, 809.657f, 38.7037f, 3.08701f }      // WP 6
};

Position const ArcaneSphere    = {1887.060059f, 806.151001f, 61.321602f, 0.0f};
Position const BossStartMove1  = {1894.684448f, 739.390503f, 47.668003f, 0.0f};
Position const BossStartMove2  = {1875.173950f, 860.832703f, 43.333565f, 0.0f};
Position const BossStartMove21 = {1858.854614f, 855.071411f, 43.333565f, 0.0f};
Position const BossStartMove22 = {1891.926636f, 863.388977f, 43.333565f, 0.0f};
Position const BossStartMove3  = {1916.138062f, 778.152222f, 35.772308f, 0.0f};
Position const BossStartMove4  = {1853.618286f, 758.557617f, 38.657505f, 0.0f};
Position const BossStartMove5  = {1906.683960f, 842.348022f, 38.637459f, 0.0f};
Position const BossStartMove6  = {1928.207031f, 852.864441f, 47.200813f, 0.0f};

Position const CyanigosasSpawnLocation = {1930.281250f, 804.407715f, 52.410946f, 3.139621f};
Position const MiddleRoomLocation = {1892.291260f, 805.696838f, 38.438862f, 3.139621f};
Position const MiddleRoomPortalSaboLocation = {1896.622925f, 804.854126f, 38.504772f, 3.139621f};

// Cyanigosa's prefight event data
enum Yells
{
    CYANIGOSA_SAY_SPAWN                           = 0
};

enum Spells
{
    CYANIGOSA_SPELL_TRANSFORM                     = 58668,
    CYANIGOSA_BLUE_AURA                           = 47759
};

DoorData const doorData[] =
{
    { GO_MAIN_DOOR, DATA_CYANIGOSA, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { 0,            0,              DOOR_TYPE_ROOM,    BOUNDARY_NONE } // END
};

class instance_violet_hold : public InstanceMapScript
{
    public:
        instance_violet_hold() : InstanceMapScript("instance_violet_hold", 608) { }

        struct instance_violet_hold_InstanceMapScript : public InstanceScript
        {
            instance_violet_hold_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                MoraggGUID                    = 0;
                ErekemGUID                    = 0;
                IchoronGUID                   = 0;
                LavanthorGUID                 = 0;
                XevozzGUID                    = 0;
                ZuramatGUID                   = 0;
                CyanigosaGUID                 = 0;
                SinclariGUID                  = 0;

                MoraggCellGUID                = 0;
                ErekemCellGUID                = 0;
                IchoronCellGUID               = 0;
                LavanthorCellGUID             = 0;
                XevozzCellGUID                = 0;
                ZuramatCellGUID               = 0;
                MainDoorGUID                  = 0;

                uiTeleportationPortal         = 0;
                uiSaboteurPortal              = 0;
                trashMobs.clear();
                uiRemoveNpc                   = 0;
                uiDoorIntegrity               = 100;
                uiWaveCount                   = 0;
                uiLocation                    = urand(0, 5);
                uiFirstBoss                   = 0;
                uiSecondBoss                  = 0;
                uiCountErekemGuards           = 0;
                uiCountActivationCrystals     = 0;
                uiCyanigosaEventPhase         = 1;

                uiActivationTimer             = 5000;
                uiDoorSpellTimer              = 2000;
                uiCyanigosaEventTimer         = 3000;

                bActive = false;
                bCrystalActivated = false;
                defenseless = true;
                uiMainEventPhase = NOT_STARTED;

                memset(ErekemGuardGUIDs, 0, 2 * sizeof(uint64));
            }

            void OnCreatureCreate(Creature* creature) OVERRIDE
            {
                switch (creature->GetEntry())
                {
                    case NPC_XEVOZZ:
                        XevozzGUID = creature->GetGUID();
                        break;
                    case NPC_LAVANTHOR:
                        LavanthorGUID = creature->GetGUID();
                        break;
                    case NPC_ICHORON:
                        IchoronGUID = creature->GetGUID();
                        break;
                    case NPC_ZURAMAT:
                        ZuramatGUID = creature->GetGUID();
                        break;
                    case NPC_EREKEM:
                        ErekemGUID = creature->GetGUID();
                        break;
                    case NPC_EREKEM_GUARD:
                        if (uiCountErekemGuards < 2)
                        {
                            ErekemGuardGUIDs[uiCountErekemGuards++] = creature->GetGUID();
                            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                        }
                        break;
                    case NPC_MORAGG:
                        MoraggGUID = creature->GetGUID();
                        break;
                    case NPC_CYANIGOSA:
                        CyanigosaGUID = creature->GetGUID();
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                        break;
                    case NPC_SINCLARI:
                        SinclariGUID = creature->GetGUID();
                        break;
                }

                if (creature->GetGUID() == uiFirstBoss || creature->GetGUID() == uiSecondBoss)
                {
                    creature->AllLootRemovedFromCorpse();
                    creature->RemoveLootMode(1);
                }
            }

            void OnGameObjectCreate(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_EREKEM_GUARD_1_DOOR:
                        ErekemLeftGuardCellGUID = go->GetGUID();
                        break;
                    case GO_EREKEM_GUARD_2_DOOR:
                        ErekemRightGuardCellGUID = go->GetGUID();
                        break;
                    case GO_EREKEM_DOOR:
                        ErekemCellGUID = go->GetGUID();
                        break;
                    case GO_ZURAMAT_DOOR:
                        ZuramatCellGUID = go->GetGUID();
                        break;
                    case GO_LAVANTHOR_DOOR:
                        LavanthorCellGUID = go->GetGUID();
                        break;
                    case GO_MORAGG_DOOR:
                        MoraggCellGUID = go->GetGUID();
                        break;
                    case GO_ICHORON_DOOR:
                        IchoronCellGUID = go->GetGUID();
                        break;
                    case GO_XEVOZZ_DOOR:
                        XevozzCellGUID = go->GetGUID();
                        break;
                    case GO_MAIN_DOOR:
                        MainDoorGUID = go->GetGUID();
                        break;
                    case GO_ACTIVATION_CRYSTAL:
                        if (uiCountActivationCrystals < 4)
                            uiActivationCrystal[uiCountActivationCrystals++] = go->GetGUID();
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) OVERRIDE
            {
                switch (type)
                {
                    case DATA_WAVE_COUNT:
                        uiWaveCount = data;
                        bActive = true;
                        break;
                    case DATA_REMOVE_NPC:
                        uiRemoveNpc = data;
                        break;
                    case DATA_PORTAL_LOCATION:
                        uiLocation = (uint8)data;
                        break;
                    case DATA_DOOR_INTEGRITY:
                        uiDoorIntegrity = data;
                        defenseless = false;
                        DoUpdateWorldState(WORLD_STATE_VH_PRISON_STATE, uiDoorIntegrity);
                        break;
                    case DATA_NPC_PRESENCE_AT_DOOR_ADD:
                        NpcAtDoorCastingList.push_back(data);
                        break;
                    case DATA_NPC_PRESENCE_AT_DOOR_REMOVE:
                        if (!NpcAtDoorCastingList.empty())
                            NpcAtDoorCastingList.pop_back();
                        break;
                    case DATA_MAIN_DOOR:
                        if (GameObject* MainDoor = instance->GetGameObject(MainDoorGUID))
                        {
                            switch (data)
                            {
                                case GO_STATE_ACTIVE:
                                    MainDoor->SetGoState(GO_STATE_ACTIVE);
                                    break;
                                case GO_STATE_READY:
                                    MainDoor->SetGoState(GO_STATE_READY);
                                    break;
                                case GO_STATE_ACTIVE_ALTERNATIVE:
                                    MainDoor->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                                    break;
                            }
                        }
                        break;
                    case DATA_START_BOSS_ENCOUNTER:
                        switch (uiWaveCount)
                        {
                            case 6:
                                StartBossEncounter(uiFirstBoss);
                                break;
                            case 12:
                                StartBossEncounter(uiSecondBoss);
                                break;
                        }
                        break;
                    case DATA_ACTIVATE_CRYSTAL:
                        ActivateCrystal();
                        break;
                    case DATA_MAIN_EVENT_PHASE:
                        uiMainEventPhase = data;
                        if (data == IN_PROGRESS) // Start event
                        {
                            if (GameObject* mainDoor = instance->GetGameObject(MainDoorGUID))
                                mainDoor->SetGoState(GO_STATE_READY);
                            uiWaveCount = 1;
                            bActive = true;
                            for (int i = 0; i < 4; ++i)
                                if (GameObject* crystal = instance->GetGameObject(uiActivationCrystal[i]))
                                    crystal->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            uiRemoveNpc = 0; // might not have been reset after a wipe on a boss.
                        }
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) OVERRIDE
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_1ST_BOSS_EVENT:
                        UpdateEncounterState(ENCOUNTER_CREDIT_KILL_CREATURE, NPC_EREKEM, NULL);
                        break;
                    case DATA_2ND_BOSS_EVENT:
                        UpdateEncounterState(ENCOUNTER_CREDIT_KILL_CREATURE, NPC_MORAGG, NULL);
                        break;
                    case DATA_CYANIGOSA:
                        uiMainEventPhase = DONE;
                        break;     
                }
                return true;
            }

            void SetData64(uint32 type, uint64 data) OVERRIDE
            {
                switch (type)
                {
                    case DATA_ADD_TRASH_MOB:
                        trashMobs.insert(data);
                        break;
                    case DATA_DEL_TRASH_MOB:
                        trashMobs.erase(data);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const OVERRIDE
            {
                switch (type)
                {
                    case DATA_WAVE_COUNT:
                        return uiWaveCount;
                    case DATA_REMOVE_NPC:
                        return uiRemoveNpc;
                    case DATA_PORTAL_LOCATION:
                        return uiLocation;
                    case DATA_DOOR_INTEGRITY:
                        return uiDoorIntegrity;
                    case DATA_NPC_PRESENCE_AT_DOOR:
                        return NpcAtDoorCastingList.size();
                    case DATA_FIRST_BOSS: 
                        return uiFirstBoss;
                    case DATA_SECOND_BOSS:
                        return uiSecondBoss;
                    case DATA_MAIN_EVENT_PHASE:
                        return uiMainEventPhase;
                    case DATA_DEFENSELESS:
                        return defenseless ? 1 : 0;
                    default:
                        break;
                }

                return 0;
            }

            uint64 GetData64(uint32 type) const OVERRIDE
            {
                switch (type)
                {
                    case DATA_MORAGG:
                        return MoraggGUID;
                    case DATA_EREKEM:
                        return ErekemGUID;
                    case DATA_EREKEM_GUARD_1:
                        return ErekemGuardGUIDs[0];
                    case DATA_EREKEM_GUARD_2:
                        return ErekemGuardGUIDs[1];
                    case DATA_ICHORON:
                        return IchoronGUID;
                    case DATA_LAVANTHOR:
                        return LavanthorGUID;
                    case DATA_XEVOZZ:
                        return XevozzGUID;
                    case DATA_ZURAMAT:
                        return ZuramatGUID;
                    case DATA_CYANIGOSA:
                        return CyanigosaGUID;
                    case DATA_MORAGG_CELL:
                        return MoraggCellGUID;
                    case DATA_EREKEM_CELL:
                        return ErekemCellGUID;
                    case DATA_EREKEM_RIGHT_GUARD_CELL:
                        return ErekemRightGuardCellGUID;
                    case DATA_EREKEM_LEFT_GUARD_CELL:
                        return ErekemLeftGuardCellGUID;
                    case DATA_ICHORON_CELL:
                        return IchoronCellGUID;
                    case DATA_LAVANTHOR_CELL:
                        return LavanthorCellGUID;
                    case DATA_XEVOZZ_CELL:
                        return XevozzCellGUID;
                    case DATA_ZURAMAT_CELL:
                        return ZuramatCellGUID;
                    case DATA_MAIN_DOOR:
                        return MainDoorGUID;
                    case DATA_SINCLARI:
                        return SinclariGUID;
                    case DATA_TELEPORTATION_PORTAL:
                        return uiTeleportationPortal;
                    case DATA_SABOTEUR_PORTAL:
                        return uiSaboteurPortal;
                    default:
                        break;
                }
                return 0;
            }

            void SpawnPortal()
            {
                SetData(DATA_PORTAL_LOCATION, (GetData(DATA_PORTAL_LOCATION) + urand(1, 5))%6);
                if (Creature* pSinclari = instance->GetCreature(SinclariGUID))
                    if (Creature* portal = pSinclari->SummonCreature(NPC_TELEPORTATION_PORTAL, PortalLocation[GetData(DATA_PORTAL_LOCATION)], TEMPSUMMON_CORPSE_DESPAWN))
                        uiTeleportationPortal = portal->GetGUID();
            }

            void StartBossEncounter(uint8 uiBoss, bool bForceRespawn = true)
            {
                Creature* pBoss = NULL;

                switch (uiBoss)
                {
                    case BOSS_MORAGG:
                        HandleGameObject(MoraggCellGUID, bForceRespawn);
                        pBoss = instance->GetCreature(MoraggGUID);
                        if (pBoss)
                            pBoss->GetMotionMaster()->MovePoint(0, BossStartMove1);
                        break;
                    case BOSS_EREKEM:
                        HandleGameObject(ErekemCellGUID, bForceRespawn);
                        HandleGameObject(ErekemRightGuardCellGUID, bForceRespawn);
                        HandleGameObject(ErekemLeftGuardCellGUID, bForceRespawn);

                        pBoss = instance->GetCreature(ErekemGUID);

                        if (pBoss)
                            pBoss->GetMotionMaster()->MovePoint(0, BossStartMove2);

                        if (Creature* pGuard1 = instance->GetCreature(ErekemGuardGUIDs[0]))
                        {
                            if (bForceRespawn)
                                pGuard1->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                            else
                                pGuard1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                            pGuard1->GetMotionMaster()->MovePoint(0, BossStartMove21);
                        }

                        if (Creature* pGuard2 = instance->GetCreature(ErekemGuardGUIDs[1]))
                        {
                            if (bForceRespawn)
                                pGuard2->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                            else
                                pGuard2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                            pGuard2->GetMotionMaster()->MovePoint(0, BossStartMove22);
                        }
                        break;
                    case BOSS_ICHORON:
                        HandleGameObject(IchoronCellGUID, bForceRespawn);
                        pBoss = instance->GetCreature(IchoronGUID);
                        if (pBoss)
                            pBoss->GetMotionMaster()->MovePoint(0, BossStartMove3);
                        break;
                    case BOSS_LAVANTHOR:
                        HandleGameObject(LavanthorCellGUID, bForceRespawn);
                        pBoss = instance->GetCreature(LavanthorGUID);
                        if (pBoss)
                            pBoss->GetMotionMaster()->MovePoint(0, BossStartMove4);
                        break;
                    case BOSS_XEVOZZ:
                        HandleGameObject(XevozzCellGUID, bForceRespawn);
                        pBoss = instance->GetCreature(XevozzGUID);
                        if (pBoss)
                            pBoss->GetMotionMaster()->MovePoint(0, BossStartMove5);
                        break;
                    case BOSS_ZURAMAT:
                        HandleGameObject(ZuramatCellGUID, bForceRespawn);
                        pBoss = instance->GetCreature(ZuramatGUID);
                        if (pBoss)
                            pBoss->GetMotionMaster()->MovePoint(0, BossStartMove6);
                        break;
                }

                // generic boss state changes
                if (pBoss)
                {
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                    pBoss->SetReactState(REACT_AGGRESSIVE);

                    if (!bForceRespawn)
                    {
                        if (pBoss->isDead())
                        {
                            // respawn but avoid to be looted again
                            pBoss->Respawn();
                            pBoss->RemoveLootMode(1);
                        }
                        pBoss->GetMotionMaster()->MovePoint(1, pBoss->GetHomePosition());
                        pBoss->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                        uiWaveCount = 0;
                    }
                }
            }

            void AddWave()
            {
                DoUpdateWorldState(WORLD_STATE_VH, 1);
                DoUpdateWorldState(WORLD_STATE_VH_WAVE_COUNT, uiWaveCount);

                switch (uiWaveCount)
                {
                    case 6:
                        if (uiFirstBoss == 0)
                            uiFirstBoss = urand(1, 6);
                        if (Creature* pSinclari = instance->GetCreature(SinclariGUID))
                        {
                            if (Creature* pPortal = pSinclari->SummonCreature(NPC_TELEPORTATION_PORTAL, MiddleRoomPortalSaboLocation, TEMPSUMMON_CORPSE_DESPAWN))
                                uiSaboteurPortal = pPortal->GetGUID();
                            if (Creature* pAzureSaboteur = pSinclari->SummonCreature(NPC_SABOTEOUR, MiddleRoomLocation, TEMPSUMMON_DEAD_DESPAWN))
                                pAzureSaboteur->CastSpell(pAzureSaboteur, SABOTEUR_SHIELD_EFFECT, false);
                        }
                        break;
                    case 12:
                        if (uiSecondBoss == 0)
                            do
                            {
                                uiSecondBoss = urand(1, 6);
                            } while (uiSecondBoss == uiFirstBoss);
                        if (Creature* pSinclari = instance->GetCreature(SinclariGUID))
                        {
                            if (Creature* pPortal = pSinclari->SummonCreature(NPC_TELEPORTATION_PORTAL, MiddleRoomPortalSaboLocation, TEMPSUMMON_CORPSE_DESPAWN))
                                uiSaboteurPortal = pPortal->GetGUID();
                            if (Creature* pAzureSaboteur = pSinclari->SummonCreature(NPC_SABOTEOUR, MiddleRoomLocation, TEMPSUMMON_DEAD_DESPAWN))
                                pAzureSaboteur->CastSpell(pAzureSaboteur, SABOTEUR_SHIELD_EFFECT, false);
                        }
                        break;
                    case 18:
                    {
                        if (Creature* pSinclari = instance->GetCreature(SinclariGUID))
                            pSinclari->SummonCreature(NPC_CYANIGOSA, CyanigosasSpawnLocation, TEMPSUMMON_DEAD_DESPAWN);
                        break;
                    }
                    case 1:
                    {
                        if (GameObject* pMainDoor = instance->GetGameObject(MainDoorGUID))
                            pMainDoor->SetGoState(GO_STATE_READY);
                        DoUpdateWorldState(WORLD_STATE_VH_PRISON_STATE, 100);
                        // no break
                    }
                    default:
                        SpawnPortal();
                        break;
                }
            }

            std::string GetSaveData() OVERRIDE
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "V H " << GetBossSaveData();

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

                if (dataHead1 == 'V' && dataHead2 == 'H')
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

            bool CheckWipe()
            {
                Map::PlayerList const &players = instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* player = itr->GetSource();
                    if (player->IsGameMaster())
                        continue;

                    if (player->IsAlive())
                        return false;
                }

                return true;
            }

            void ResetInstance()
            {
                SetData(DATA_REMOVE_NPC, 1);
                StartBossEncounter(uiFirstBoss, false);
                StartBossEncounter(uiSecondBoss, false);
                uiDoorIntegrity = 100;
                uiWaveCount = 0;

                DoUpdateWorldState(WORLD_STATE_VH, 1);
                DoUpdateWorldState(WORLD_STATE_VH_WAVE_COUNT, uiWaveCount);
                DoUpdateWorldState(WORLD_STATE_VH_PRISON_STATE, 100);

                SetData(DATA_MAIN_DOOR, GO_STATE_ACTIVE);
                SetData(DATA_WAVE_COUNT, 0);
                uiMainEventPhase = NOT_STARTED;

                for (int i = 0; i < 4; ++i)
                    if (GameObject* crystal = instance->GetGameObject(uiActivationCrystal[i]))
                        crystal->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                if (Creature* pSinclari = instance->GetCreature(SinclariGUID))
                {
                    pSinclari->SetVisible(true);

                    std::list<Creature*> GuardList;
                    pSinclari->GetCreatureListWithEntryInGrid(GuardList, NPC_VIOLET_HOLD_GUARD, 40.0f);
                    if (!GuardList.empty())
                    {
                        for (std::list<Creature*>::const_iterator itr = GuardList.begin(); itr != GuardList.end(); ++itr)
                        {
                            if (Creature* pGuard = *itr)
                            {
                                pGuard->SetVisible(true);
                                pGuard->SetReactState(REACT_AGGRESSIVE);
                                pGuard->GetMotionMaster()->MovePoint(1, pGuard->GetHomePosition());
                            }
                        }
                    }
                    pSinclari->GetMotionMaster()->MovePoint(1, pSinclari->GetHomePosition());
                    pSinclari->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }

                for (std::set<uint64>::const_iterator itr = trashMobs.begin(); itr != trashMobs.end(); ++itr)
                {
                    Creature* creature = instance->GetCreature(*itr);
                    if (creature && creature->IsAlive())
                        creature->DespawnOrUnsummon();
                }

                trashMobs.clear();
            }

            void Update(uint32 diff) OVERRIDE
            {
                if (!instance->HavePlayers())
                    return;

                // portals should spawn if other portal is dead and doors are closed
                if (bActive && uiMainEventPhase == IN_PROGRESS)
                {
                    if (uiActivationTimer < diff)
                    {
                        AddWave();
                        bActive = false;
                        // 1 minute waiting time after each boss fight
                        uiActivationTimer = (uiWaveCount == 6 || uiWaveCount == 12) ? 60000 : 5000;
                    } else uiActivationTimer -= diff;
                }

                // if main event is in progress and players have wiped then reset instance
                if (uiMainEventPhase == IN_PROGRESS && CheckWipe())
                    ResetInstance();

                // Cyanigosa is spawned but not tranformed, prefight event
                Creature* pCyanigosa = instance->GetCreature(CyanigosaGUID);
                if (pCyanigosa && !pCyanigosa->HasAura(CYANIGOSA_SPELL_TRANSFORM))
                {
                    if (uiCyanigosaEventTimer <= diff)
                    {
                        switch (uiCyanigosaEventPhase)
                        {
                            case 1:
                                pCyanigosa->CastSpell(pCyanigosa, CYANIGOSA_BLUE_AURA, false);
                                pCyanigosa->AI()->Talk(CYANIGOSA_SAY_SPAWN);
                                uiCyanigosaEventTimer = 7*IN_MILLISECONDS;
                                ++uiCyanigosaEventPhase;
                                break;
                            case 2:
                                pCyanigosa->GetMotionMaster()->MoveJump(MiddleRoomLocation.GetPositionX(), MiddleRoomLocation.GetPositionY(), MiddleRoomLocation.GetPositionZ(), 10.0f, 20.0f);
                                pCyanigosa->CastSpell(pCyanigosa, CYANIGOSA_BLUE_AURA, false);
                                uiCyanigosaEventTimer = 7*IN_MILLISECONDS;
                                ++uiCyanigosaEventPhase;
                                break;
                            case 3:
                                pCyanigosa->RemoveAurasDueToSpell(CYANIGOSA_BLUE_AURA);
                                pCyanigosa->CastSpell(pCyanigosa, CYANIGOSA_SPELL_TRANSFORM, 0);
                                pCyanigosa->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                                pCyanigosa->SetReactState(REACT_AGGRESSIVE);
                                uiCyanigosaEventTimer = 2*IN_MILLISECONDS;
                                ++uiCyanigosaEventPhase;
                                break;
                            case 4:
                                uiCyanigosaEventPhase = 0;
                                break;
                        }
                    } else uiCyanigosaEventTimer -= diff;
                }

                // if there are NPCs in front of the prison door, which are casting the door seal spell and doors are active
                if (GetData(DATA_NPC_PRESENCE_AT_DOOR) && uiMainEventPhase == IN_PROGRESS)
                {
                    // if door integrity is > 0 then decrase it's integrity state
                    if (GetData(DATA_DOOR_INTEGRITY))
                    {
                        if (uiDoorSpellTimer < diff)
                        {
                            SetData(DATA_DOOR_INTEGRITY, GetData(DATA_DOOR_INTEGRITY)-1);
                            uiDoorSpellTimer = 2000;
                        } else uiDoorSpellTimer -= diff;
                    }
                    // else set door state to active (means door will open and group have failed to sustain mob invasion on the door)
                    else
                    {
                        SetData(DATA_MAIN_DOOR, GO_STATE_ACTIVE);
                        uiMainEventPhase = FAIL;
                        ResetInstance();
                    }
                }
            }

            void ActivateCrystal()
            {
                // just to make things easier we'll get the gameobject from the map
                GameObject* invoker = instance->GetGameObject(uiActivationCrystal[0]);
                if (!invoker)
                    return;

                SpellInfo const* spellInfoLightning = sSpellMgr->GetSpellInfo(SPELL_ARCANE_LIGHTNING);
                if (!spellInfoLightning)
                    return;

                // the orb
                TempSummon* trigger = invoker->SummonCreature(NPC_DEFENSE_SYSTEM, ArcaneSphere, TEMPSUMMON_MANUAL_DESPAWN, 0);
                if (!trigger)
                    return;

                // visuals
                trigger->CastSpell(trigger, spellInfoLightning, true, 0, 0, trigger->GetGUID());

                // Kill all mobs registered with SetData64(ADD_TRASH_MOB)
                for (std::set<uint64>::const_iterator itr = trashMobs.begin(); itr != trashMobs.end(); ++itr)
                {
                    Creature* creature = instance->GetCreature(*itr);
                    if (creature && creature->IsAlive())
                        trigger->Kill(creature);
                }

                defenseless = false;
            }

            void ProcessEvent(WorldObject* /*go*/, uint32 uiEventId)
            {
                switch (uiEventId)
                {
                    case EVENT_ACTIVATE_CRYSTAL:
                        bCrystalActivated = true; // Activation by player's will throw event signal
                        ActivateCrystal();
                        break;
                }
            }

            protected:
                uint64 MoraggGUID;
                uint64 ErekemGUID;
                uint64 ErekemGuardGUIDs[2];
                uint64 IchoronGUID;
                uint64 LavanthorGUID;
                uint64 XevozzGUID;
                uint64 ZuramatGUID;
                uint64 CyanigosaGUID;
                uint64 SinclariGUID;

                uint64 MoraggCellGUID;
                uint64 ErekemCellGUID;
                uint64 ErekemLeftGuardCellGUID;
                uint64 ErekemRightGuardCellGUID;
                uint64 IchoronCellGUID;
                uint64 LavanthorCellGUID;
                uint64 XevozzCellGUID;
                uint64 ZuramatCellGUID;
                uint64 MainDoorGUID;

                uint64 uiTeleportationPortal;
                uint64 uiSaboteurPortal;

                uint64 uiActivationCrystal[4];
                uint32 uiActivationTimer;
                uint32 uiCyanigosaEventTimer;
                uint32 uiDoorSpellTimer;

                std::set<uint64> trashMobs; // to kill with crystal

                uint8 uiWaveCount;
                uint8 uiLocation;
                uint8 uiFirstBoss;
                uint8 uiSecondBoss;
                uint8 uiRemoveNpc;

                uint8 uiDoorIntegrity;
                uint8 uiCountErekemGuards;
                uint8 uiCountActivationCrystals;
                uint8 uiCyanigosaEventPhase;
                uint8 uiMainEventPhase; // SPECIAL: pre event animations, IN_PROGRESS: event itself

                bool bActive;
                bool bCrystalActivated;
                bool defenseless;

                std::list<uint8> NpcAtDoorCastingList;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_violet_hold_InstanceMapScript(map);
        }
};

void AddSC_instance_violet_hold()
{
    new instance_violet_hold();
}
