/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
    {1877.51f, 850.104f, 44.6599f, 4.7822f },     // WP 1
    {1918.37f, 853.437f, 47.1624f, 4.12294f},     // WP 2
    {1936.07f, 803.198f, 53.3749f, 3.12414f},     // WP 3
    {1927.61f, 758.436f, 51.4533f, 2.20891f},     // WP 4
    {1890.64f, 753.471f, 48.7224f, 1.71042f},     // WP 5
    {1908.31f, 809.657f, 38.7037f, 3.08701f}      // WP 6
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
    CYANIGOSA_BLUE_AURA                           = 47759,
};

ObjectData const creatureData[] =
{
    { NPC_XEVOZZ,    DATA_XEVOZZ    },
    { NPC_LAVANTHOR, DATA_LAVANTHOR },
    { NPC_ICHORON,   DATA_ICHORON   },
    { NPC_ZURAMAT,   DATA_ZURAMAT   },
    { NPC_EREKEM,    DATA_EREKEM    },
    { NPC_MORAGG,    DATA_MORAGG    },
    { NPC_CYANIGOSA, DATA_CYANIGOSA },
    { NPC_SINCLARI,  DATA_SINCLARI  },
    { 0,             0              } // END
};

ObjectData const gameObjectData[] =
{
    { GO_EREKEM_GUARD_1_DOOR, DATA_EREKEM_LEFT_GUARD_CELL  },
    { GO_EREKEM_GUARD_2_DOOR, DATA_EREKEM_RIGHT_GUARD_CELL },
    { GO_EREKEM_DOOR,         DATA_EREKEM_CELL             },
    { GO_ZURAMAT_DOOR,        DATA_ZURAMAT_CELL            },
    { GO_LAVANTHOR_DOOR,      DATA_LAVANTHOR_CELL          },
    { GO_MORAGG_DOOR,         DATA_MORAGG_CELL             },
    { GO_ICHORON_DOOR,        DATA_ICHORON_CELL            },
    { GO_XEVOZZ_DOOR,         DATA_XEVOZZ_CELL             },
    { GO_MAIN_DOOR,           DATA_MAIN_DOOR               },
    { 0,                      0                            } // END
};

class instance_violet_hold : public InstanceMapScript
{
public:
    instance_violet_hold() : InstanceMapScript("instance_violet_hold", 608) { }

    struct instance_violet_hold_InstanceMapScript : public InstanceScript
    {
        instance_violet_hold_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, gameObjectData);

            uiRemoveNpc = 0;

            uiDoorIntegrity = 100;

            uiWaveCount = 0;
            uiLocation = urand(0, 5);
            uiFirstBoss = 0;
            uiSecondBoss = 0;
            uiCountErekemGuards = 0;
            uiCountActivationCrystals = 0;
            uiCyanigosaEventPhase = 1;

            uiActivationTimer = 5000;
            uiDoorSpellTimer = 2000;
            uiCyanigosaEventTimer = 3 * IN_MILLISECONDS;

            bActive = false;
            bWiped = false;
            bIsDoorSpellCast = false;
            bCrystalActivated = false;
            defenseless = true;
            uiMainEventPhase = NOT_STARTED;
            zuramatDead = false;
        }

        ObjectGuid uiErekemGuard[2];

        ObjectGuid uiTeleportationPortal;
        ObjectGuid uiSaboteurPortal;

        ObjectGuid uiActivationCrystal[4];

        uint32 uiActivationTimer;
        uint32 uiCyanigosaEventTimer;
        uint32 uiDoorSpellTimer;

        GuidSet trashMobs; // to kill with crystal

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
        bool bWiped;
        bool bIsDoorSpellCast;
        bool bCrystalActivated;
        bool defenseless;
        bool zuramatDead;

        std::list<uint8> NpcAtDoorCastingList;

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case NPC_EREKEM_GUARD:
                    if (uiCountErekemGuards < 2)
                    {
                        uiErekemGuard[uiCountErekemGuards++] = creature->GetGUID();
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE);
                    }
                    break;
                case NPC_CYANIGOSA:
                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE);
                    break;
                default:
                    break;
                case NPC_VOID_SENTRY:
                    if (zuramatDead)
                    {
                        creature->DespawnOrUnsummon();
                        zuramatDead = false;
                    }
                    break;
            }

            if (creature->GetGUID() == uiFirstBoss || creature->GetGUID() == uiSecondBoss)
            {
                creature->AllLootRemovedFromCorpse();
                creature->RemoveLootMode(1);
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
                case GO_ACTIVATION_CRYSTAL:
                    if (uiCountActivationCrystals < 4)
                        uiActivationCrystal[uiCountActivationCrystals++] = go->GetGUID();
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
                case DATA_1ST_BOSS_EVENT:
                    if (state == DONE)
                        UpdateEncounterState(ENCOUNTER_CREDIT_KILL_CREATURE, NPC_EREKEM, nullptr);
                    break;
                case DATA_2ND_BOSS_EVENT:
                    if (state == DONE)
                        UpdateEncounterState(ENCOUNTER_CREDIT_KILL_CREATURE, NPC_MORAGG, nullptr);
                    break;
                case DATA_CYANIGOSA:
                    if (state == DONE)
                    {
                        uiMainEventPhase = DONE;
                        if (GameObject* mainDoor = GetGameObject(DATA_MAIN_DOOR))
                            mainDoor->SetGoState(GO_STATE_ACTIVE);
                    }
                    break;
                default:
                    break;
            }

            return true;
        }

        void SetData(uint32 type, uint32 data) override
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
                    if (GameObject* mainDoor = GetGameObject(type))
                        mainDoor->SetGoState(GOState(data));
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
                        if (GameObject* mainDoor = GetGameObject(DATA_MAIN_DOOR))
                            mainDoor->SetGoState(GO_STATE_READY);
                        uiWaveCount = 1;
                        bActive = true;
                        for (int i = 0; i < 4; ++i)
                            if (GameObject* crystal = instance->GetGameObject(uiActivationCrystal[i]))
                                crystal->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        uiRemoveNpc = 0; // might not have been reset after a wipe on a boss.
                    }
                    break;
                case DATA_ZURAMAT:
                    zuramatDead = true;
                    break;
            }
        }

        void SetGuidData(uint32 type, ObjectGuid data) override
        {
            switch (type)
            {
                case DATA_ADD_TRASH_MOB:
                    trashMobs.insert(data);
                    break;
                case DATA_DEL_TRASH_MOB:
                    trashMobs.erase(data);
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_WAVE_COUNT:               return uiWaveCount;
                case DATA_REMOVE_NPC:               return uiRemoveNpc;
                case DATA_PORTAL_LOCATION:          return uiLocation;
                case DATA_DOOR_INTEGRITY:           return uiDoorIntegrity;
                case DATA_NPC_PRESENCE_AT_DOOR:     return NpcAtDoorCastingList.size();
                case DATA_FIRST_BOSS:               return uiFirstBoss;
                case DATA_SECOND_BOSS:              return uiSecondBoss;
                case DATA_MAIN_EVENT_PHASE:         return uiMainEventPhase;
                case DATA_DEFENSELESS:              return defenseless ? 1 : 0;
            }

            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_EREKEM_GUARD_1:           return uiErekemGuard[0];
                case DATA_EREKEM_GUARD_2:           return uiErekemGuard[1];
                case DATA_TELEPORTATION_PORTAL:     return uiTeleportationPortal;
                case DATA_SABOTEUR_PORTAL:          return uiSaboteurPortal;
            }

            return InstanceScript::GetGuidData(type);
        }

        void SpawnPortal()
        {
            SetData(DATA_PORTAL_LOCATION, (GetData(DATA_PORTAL_LOCATION) + urand(1, 5))%6);
            if (Creature* sinclari = GetCreature(DATA_SINCLARI))
                if (Creature* portal = sinclari->SummonCreature(NPC_TELEPORTATION_PORTAL, PortalLocation[GetData(DATA_PORTAL_LOCATION)], TEMPSUMMON_CORPSE_DESPAWN))
                    uiTeleportationPortal = portal->GetGUID();
        }

        void StartBossEncounter(uint8 uiBoss, bool bForceRespawn = true)
        {
            Creature* boss = nullptr;

            switch (uiBoss)
            {
                case BOSS_MORAGG:
                    HandleGameObject(GetObjectGuid(DATA_MORAGG_CELL), bForceRespawn);
                    boss = GetCreature(DATA_MORAGG);
                    if (boss)
                        boss->GetMotionMaster()->MovePoint(0, BossStartMove1);
                    break;
                case BOSS_EREKEM:
                    HandleGameObject(GetObjectGuid(DATA_EREKEM_CELL), bForceRespawn);
                    HandleGameObject(GetObjectGuid(DATA_EREKEM_LEFT_GUARD_CELL), bForceRespawn);
                    HandleGameObject(GetObjectGuid(DATA_EREKEM_RIGHT_GUARD_CELL), bForceRespawn);

                    boss = GetCreature(DATA_EREKEM);
                    if (boss)
                        boss->GetMotionMaster()->MovePoint(0, BossStartMove2);

                    if (Creature* pGuard1 = instance->GetCreature(uiErekemGuard[0]))
                    {
                        if (bForceRespawn)
                        {
                            pGuard1->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE);
                            pGuard1->GetMotionMaster()->MovePoint(0, BossStartMove21);
                        }
                        else
                            pGuard1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                    }

                    if (Creature* pGuard2 = instance->GetCreature(uiErekemGuard[1]))
                    {
                        if (bForceRespawn)
                        {
                            pGuard2->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                            pGuard2->GetMotionMaster()->MovePoint(0, BossStartMove22);
                        }
                        else
                            pGuard2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                    }
                    break;
                case BOSS_ICHORON:
                    HandleGameObject(GetObjectGuid(DATA_ICHORON_CELL), bForceRespawn);
                    boss = GetCreature(DATA_ICHORON);
                    if (boss)
                        boss->GetMotionMaster()->MovePoint(0, BossStartMove3);
                    break;
                case BOSS_LAVANTHOR:
                    HandleGameObject(GetObjectGuid(DATA_LAVANTHOR_CELL), bForceRespawn);
                    boss = GetCreature(DATA_LAVANTHOR);
                    if (boss)
                        boss->GetMotionMaster()->MovePoint(0, BossStartMove4);
                    break;
                case BOSS_XEVOZZ:
                    HandleGameObject(GetObjectGuid(DATA_XEVOZZ_CELL), bForceRespawn);
                    boss = GetCreature(DATA_XEVOZZ);
                    if (boss)
                        boss->GetMotionMaster()->MovePoint(0, BossStartMove5);
                    break;
                case BOSS_ZURAMAT:
                    HandleGameObject(GetObjectGuid(DATA_ZURAMAT_CELL), bForceRespawn);
                    boss = GetCreature(DATA_ZURAMAT);
                    if (boss)
                        boss->GetMotionMaster()->MovePoint(0, BossStartMove6);
                    break;
            }

            // generic boss state changes
            if (boss)
            {
                boss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                boss->SetReactState(REACT_AGGRESSIVE);

                if (!bForceRespawn)
                {
                    if (boss->isDead())
                    {
                        // respawn but avoid to be looted again
                        boss->Respawn();
                        boss->RemoveLootMode(1);
                    }
                    else
                        boss->GetMotionMaster()->MoveTargetedHome();

                    boss->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
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
                    if (Creature* sinclari = GetCreature(DATA_SINCLARI))
                    {
                        if (Creature* portal = sinclari->SummonCreature(NPC_TELEPORTATION_PORTAL, MiddleRoomPortalSaboLocation, TEMPSUMMON_CORPSE_DESPAWN))
                            uiSaboteurPortal = portal->GetGUID();
                        if (Creature* azureSaboteur = sinclari->SummonCreature(NPC_SABOTEOUR, MiddleRoomLocation, TEMPSUMMON_DEAD_DESPAWN))
                            azureSaboteur->CastSpell(azureSaboteur, SABOTEUR_SHIELD_EFFECT, false);
                    }
                    break;
                case 12:
                    if (uiSecondBoss == 0)
                        do
                        {
                            uiSecondBoss = urand(1, 6);
                        } while (uiSecondBoss == uiFirstBoss);
                    if (Creature* sinclari = GetCreature(DATA_SINCLARI))
                    {
                        if (Creature* pPortal = sinclari->SummonCreature(NPC_TELEPORTATION_PORTAL, MiddleRoomPortalSaboLocation, TEMPSUMMON_CORPSE_DESPAWN))
                            uiSaboteurPortal = pPortal->GetGUID();
                        if (Creature* pAzureSaboteur = sinclari->SummonCreature(NPC_SABOTEOUR, MiddleRoomLocation, TEMPSUMMON_DEAD_DESPAWN))
                            pAzureSaboteur->CastSpell(pAzureSaboteur, SABOTEUR_SHIELD_EFFECT, false);
                    }
                    break;
                case 18:
                    if (Creature* sinclari = GetCreature(DATA_SINCLARI))
                        sinclari->SummonCreature(NPC_CYANIGOSA, CyanigosasSpawnLocation, TEMPSUMMON_DEAD_DESPAWN);
                    break;
                case 1:
                {
                    if (GameObject* mainDoor = GetGameObject(DATA_MAIN_DOOR))
                        mainDoor->SetGoState(GO_STATE_READY);
                    DoUpdateWorldState(WORLD_STATE_VH_PRISON_STATE, 100);
                    // no break
                }
                default:
                    SpawnPortal();
                    break;
            }
        }

        void WriteSaveDataMore(std::ostringstream& data) override
        {
            data << uiFirstBoss << ' ' << uiSecondBoss;
        }

        void ReadSaveDataMore(std::istringstream& data) override
        {
            data >> uiFirstBoss;
            data >> uiSecondBoss;
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

            zuramatDead = false;
            return true;
        }

        void Update(uint32 diff) override
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
            {
                SetData(DATA_REMOVE_NPC, 1);
                StartBossEncounter(uiFirstBoss, false);
                StartBossEncounter(uiSecondBoss, false);

                SetData(DATA_MAIN_DOOR, GO_STATE_ACTIVE);
                SetData(DATA_WAVE_COUNT, 0);
                uiMainEventPhase = NOT_STARTED;
                uiActivationTimer = 5000;

                for (int i = 0; i < 4; ++i)
                    if (GameObject* crystal = instance->GetGameObject(uiActivationCrystal[i]))
                        crystal->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                if (Creature* sinclari = GetCreature(DATA_SINCLARI))
                {
                    sinclari->SetVisible(true);

                    std::list<Creature*> GuardList;
                    sinclari->GetCreatureListWithEntryInGrid(GuardList, NPC_VIOLET_HOLD_GUARD, 40.0f);
                    if (!GuardList.empty())
                    {
                        for (Creature* guard : GuardList)
                        {
                            guard->SetVisible(true);
                            guard->SetReactState(REACT_AGGRESSIVE);
                            guard->GetMotionMaster()->MovePoint(1, guard->GetHomePosition());
                        }
                    }
                    sinclari->GetMotionMaster()->MovePoint(1, sinclari->GetHomePosition());
                    sinclari->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }
            }

            // Cyanigosa is spawned but not tranformed, prefight event
            Creature* cyanigosa = GetCreature(DATA_CYANIGOSA);
            if (cyanigosa && !cyanigosa->HasAura(CYANIGOSA_SPELL_TRANSFORM))
            {
                if (uiCyanigosaEventTimer <= diff)
                {
                    switch (uiCyanigosaEventPhase)
                    {
                        case 1:
                            cyanigosa->CastSpell(cyanigosa, CYANIGOSA_BLUE_AURA, false);
                            cyanigosa->AI()->Talk(CYANIGOSA_SAY_SPAWN);
                            uiCyanigosaEventTimer = 7*IN_MILLISECONDS;
                            ++uiCyanigosaEventPhase;
                            break;
                        case 2:
                            cyanigosa->GetMotionMaster()->MoveJump(MiddleRoomLocation.GetPositionX(), MiddleRoomLocation.GetPositionY(), MiddleRoomLocation.GetPositionZ(), 10.0f, 20.0f);
                            cyanigosa->CastSpell(cyanigosa, CYANIGOSA_BLUE_AURA, false);
                            uiCyanigosaEventTimer = 7*IN_MILLISECONDS;
                            ++uiCyanigosaEventPhase;
                            break;
                        case 3:
                            cyanigosa->RemoveAurasDueToSpell(CYANIGOSA_BLUE_AURA);
                            cyanigosa->CastSpell(cyanigosa, CYANIGOSA_SPELL_TRANSFORM, 0);
                            cyanigosa->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_NON_ATTACKABLE);
                            cyanigosa->SetReactState(REACT_AGGRESSIVE);
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
                        uiDoorSpellTimer =2000;
                    } else uiDoorSpellTimer -= diff;
                }
                // else set door state to active (means door will open and group have failed to sustain mob invasion on the door)
                else
                {
                    SetData(DATA_MAIN_DOOR, GO_STATE_ACTIVE);
                    uiMainEventPhase = FAIL;
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

            // Kill all mobs registered with SetGuidData(ADD_TRASH_MOB)
            for (GuidSet::const_iterator itr = trashMobs.begin(); itr != trashMobs.end();)
            {
                Creature* creature = instance->GetCreature(*itr);
                // Increment the iterator before killing the creature because the kill will remove itr from trashMobs
                ++itr;
                if (creature && creature->IsAlive())
                    trigger->Kill(creature);
            }
        }

        void ProcessEvent(WorldObject* /*go*/, uint32 uiEventId) override
        {
            switch (uiEventId)
            {
                case EVENT_ACTIVATE_CRYSTAL:
                    bCrystalActivated = true; // Activation by player's will throw event signal
                    ActivateCrystal();
                    break;
            }
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_violet_hold_InstanceMapScript(map);
    }
};

void AddSC_instance_violet_hold()
{
    new instance_violet_hold();
}
