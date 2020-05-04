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

 /*
 This placeholder for the instance is needed for dungeon finding to be able
 to give credit after the boss defined in lastEncounterDungeon is killed.
 Without it, the party doing random dungeon won't get satchel of spoils and
 gets instead the deserter debuff.
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Map.h"
#include "GameObject.h"
#include "Pet.h"
#include "SpellHistory.h"
#include "GridNotifiers.h"
#include "MapReference.h"

 // Bosses (East)
 // 0 - Pusillin
 // 1 - Lethtendris
 // 2 - Hydrospawn
 // 3 - Zevrim Thornhoof
 // 4 - Alzzin the Wildshaper

 // West
 // 5 - Tendris Warpwood
 // 6 - Magister Kalendris
 // 7 - Tsu'zee
 // 8 - Illyanna Ravenoak
 // 9 - Immol'thar
 // 10 - Prince Tortheldrin

 // North
 // 11 - Guard Mol'dar
 // 12 - Stomper Kreeg
 // 13 - Guard Fengus
 // 14 - Guard Slip'kik
 // 15 - Captain Kromcrush
 // 16 - King Gordok

uint8 const EncounterCount = 17;

#ifndef GOSSIP_MENU_IRONBARK_THE_REDEEMED
#define GOSSIP_MENU_IRONBARK_THE_REDEEMED 5602
#endif

// EJ scripts
enum DIRE_MAUL_NPC
{
    NPC_ZEVRIM_THORNHOOF = 11490,
    NPC_OLD_IRONBARK = 11491,
    NPC_IRONBARK_THE_REDEEMED = 14241,
    NPC_WANDERING_EYE_OF_KILROGG = 14386,
    NPC_NETHERWALKER = 14389,
    NPC_TENDRIS_WARPWOOD = 11489,
    NPC_PETRIFIED_TREANT = 11458,
    NPC_IRONBARK_PROTECTOR = 11459,
    NPC_PETRIFIED_GUARDIAN = 14303,
    NPC_HIGHBORNE_SUMMONER = 11466,
    NPC_PRINCE_TORTHELDRIN = 11486,
    NPC_IMMOLTHAR = 11496,
    NPC_ARCANE_ABERRATION = 11480,
    NPC_MANA_REMNANT = 11483,
    NPC_ILLYANNA_RAVENOAK = 11488,
    NPC_FERRA = 14308,
    NPC_ANCIENT_EQUINE_SPIRIT = 14566,
};

enum DIRE_MAUL_GAMEOBJECT
{
    GAMEOBJECT_CONSERVATORY_DOOR = 176907,
    GAMEOBJECT_THE_PRINCE_CHEST = 179545,
    GAMEOBJECT_DOODAD_DIRE_MAULCRYSTAL_GENERATOR_01 = 177259,
    GAMEOBJECT_DOODAD_DIRE_MAULCRYSTAL_GENERATOR_02 = 177257,
    GAMEOBJECT_DOODAD_DIRE_MAULCRYSTAL_GENERATOR_03 = 177258,
    GAMEOBJECT_DOODAD_DIRE_MAULCRYSTAL_GENERATOR_04 = 179504,
    GAMEOBJECT_DOODAD_DIRE_MAULCRYSTAL_GENERATOR_05 = 179505,
    GAMEOBJECT_DOODAD_DIRE_MAUL_BOSS_FORCE_FIELD_01 = 179503,
};

enum DIRE_MAUL_BOSS
{
    BOSS_ZEVRIM_THORNHOOF = 0,
    BOSS_TENDRIS_WARPWOOD = 1,
    BOSS_PRINCE_TORTHELDRIN = 2,
    BOSS_IMMOLTHAR = 3,
};

enum DIRE_MAUL_WAYPOINT
{
    WAYPOINT_IRONBARK_THE_REDEEMED = 569430,
};

enum DIRE_MAUL_LINE_OLD_IRONBARK
{
    LINE_OLD_IRONBARK_0 = 0,
    LINE_OLD_IRONBARK_1 = 1,
};

enum DIRE_MAUL_LINE_IRONBARK_THE_REDEEMED
{
    LINE_IRONBARK_THE_REDEEMED_0 = 0,
    LINE_IRONBARK_THE_REDEEMED_1 = 1,    
};

enum DIRE_MAUL_LINE_WANDERING_EYE_OF_KILROGG
{
    LINE_WANDERING_EYE_OF_KILROGG_0 = 0,
};

enum DIRE_MAUL_LINE_TENDRIS_WARPWOOD
{
    LINE_TENDRIS_WARPWOOD_0 = 0,
};

enum DIRE_MAUL_LINE_HIGHBORNE_SUMMONER
{
    LINE_HIGHBORNE_SUMMONER_0 = 0,
};

enum DIRE_MAUL_LINE_PRINCE_TORTHELDRIN
{
    LINE_PRINCE_TORTHELDRIN_0 = 0,
};

enum DIRE_MAUL_DATA
{
    DATA_OLD_IRONBARK_REDEEM = 0,
    DATA_CONSERVATORY_DOOR_SPAWN_ID = 1,
    DATA_TEST_IMMO = 2,
    DATA_RESTRAIN_TALKER_SPAWNID = 56952,
    DATA_ILLYANNA_RAVENOAK_SPAWNID = 84381,
};

enum DIRE_MAUL_SPELL
{
    SPELL_CRIPPLE = 20812,
    //SPELL_RAIN_OF_FIRE = 4629,
    SPELL_RAIN_OF_FIRE = 11678,
    SPELL_REND = 21949,
    SPELL_WAR_STOMP = 20549,
    SPELL_SUMMON_NETHERWALKER = 22876,
    SPELL_CHARGE = 22911,
    SPELL_MAUL = 17156,
    SPELL_SUMMON_VISUAL = 26638,
};

enum DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED
{
    EVENT_TALK_0 = 1,
    EVENT_MOVE_WAY = 2,
    EVENT_OPEN_DOOR_EMOTE = 3,
    EVENT_DOOR_OPEN = 4,
    EVENT_TALK_1 = 5,    
    EVENT_DESPAWN = 6,
};

class instance_dire_maul : public InstanceMapScript
{
public:
    instance_dire_maul() : InstanceMapScript("instance_dire_maul", 429) { }

    struct instance_dire_maul_InstanceMapScript : public InstanceScript
    {
        instance_dire_maul_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            OGHighborneSummonerSet.clear();
            OGDoodadDireMaulCrystalGeneratorSet.clear();
            OGCrystalGuardiansSet.clear();
            OGDoodadDireMaulCrystalGenerator_GuardiansMap.clear();

            SetBossNumber(EncounterCount);
            SetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF, EncounterState::NOT_STARTED);
            SetBossState(DIRE_MAUL_BOSS::BOSS_TENDRIS_WARPWOOD, EncounterState::NOT_STARTED);
            SetBossState(DIRE_MAUL_BOSS::BOSS_IMMOLTHAR, EncounterState::NOT_STARTED);
            SetBossState(DIRE_MAUL_BOSS::BOSS_PRINCE_TORTHELDRIN, EncounterState::NOT_STARTED);

            allCrystalInitialized = false;
            playerFaction = 0;

            ironbarkWeakLined = false;
            ironbarkWeakLineCheckDelay = 3000;
        }

        ObjectGuid OGBossZevrimThornhoof;
        ObjectGuid OGBossTendrisWarpwood;
        ObjectGuid OGBossPrinceTortheldrin;
        ObjectGuid OGBossImmolthar;
        ObjectGuid OGOldIronbark;
        std::unordered_set<ObjectGuid> OGHighborneSummonerSet;

        uint32 siConservatoryDoor;
        ObjectGuid OGThePrinceChest;
        ObjectGuid OGDoodadDireMaulBossForceField01;
        std::unordered_set<ObjectGuid> OGDoodadDireMaulCrystalGeneratorSet;
        std::unordered_set<ObjectGuid> OGCrystalGuardiansSet;
        std::unordered_map<ObjectGuid, std::unordered_set< ObjectGuid>> OGDoodadDireMaulCrystalGenerator_GuardiansMap;
        bool allCrystalInitialized;
        int playerFaction;

        bool ironbarkWeakLined;
        int ironbarkWeakLineCheckDelay;

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case DIRE_MAUL_NPC::NPC_OLD_IRONBARK:
            {
                OGOldIronbark = creature->GetGUID();
                creature->RemoveFlag(EUnitFields::UNIT_NPC_FLAGS, NPCFlags::UNIT_NPC_FLAG_GOSSIP);
                creature->SetStandState(UnitStandStateType::UNIT_STAND_STATE_DEAD);
                break;
            }
            case DIRE_MAUL_NPC::NPC_ZEVRIM_THORNHOOF:
            {
                OGBossZevrimThornhoof = creature->GetGUID();
                break;
            }
            case DIRE_MAUL_NPC::NPC_WANDERING_EYE_OF_KILROGG:
            {
                creature->SetReactState(ReactStates::REACT_PASSIVE);
                break;
            }
            case DIRE_MAUL_NPC::NPC_NETHERWALKER:
            {
                creature->AI()->AttackStart(creature->SelectNearestPlayer(30.0f));
                break;
            }
            case DIRE_MAUL_NPC::NPC_TENDRIS_WARPWOOD:
            {
                OGBossTendrisWarpwood = creature->GetGUID();
                break;
            }
            case DIRE_MAUL_NPC::NPC_PRINCE_TORTHELDRIN:
            {
                OGBossPrinceTortheldrin = creature->GetGUID();
                break;
            }
            case DIRE_MAUL_NPC::NPC_IMMOLTHAR:
            {
                OGBossImmolthar = creature->GetGUID();
                break;
            }
            case DIRE_MAUL_NPC::NPC_HIGHBORNE_SUMMONER:
            {
                OGHighborneSummonerSet.insert(creature->GetGUID());
                break;
            }
            case DIRE_MAUL_NPC::NPC_ARCANE_ABERRATION:
            {
                OGCrystalGuardiansSet.insert(creature->GetGUID());
                break;
            }
            case DIRE_MAUL_NPC::NPC_MANA_REMNANT:
            {
                OGCrystalGuardiansSet.insert(creature->GetGUID());
                break;
            }
            case DIRE_MAUL_NPC::NPC_ILLYANNA_RAVENOAK:
            {
                creature->SummonCreature(DIRE_MAUL_NPC::NPC_FERRA, creature->GetFirstCollisionPosition(4.0f, 0));
                break;
            }
            default:
            {
                break;
            }
            }
        }

        void OnCreatureDied(Creature* creature) override
        {
            if (creature->GetEntry() == DIRE_MAUL_NPC::NPC_ARCANE_ABERRATION || creature->GetEntry() == DIRE_MAUL_NPC::NPC_MANA_REMNANT)
            {
                for (std::unordered_map<ObjectGuid, std::unordered_set<ObjectGuid>>::iterator crystalGuardiansIT = OGDoodadDireMaulCrystalGenerator_GuardiansMap.begin(); crystalGuardiansIT != OGDoodadDireMaulCrystalGenerator_GuardiansMap.end(); crystalGuardiansIT++)
                {
                    if (crystalGuardiansIT->second.find(creature->GetGUID()) != crystalGuardiansIT->second.end())
                    {
                        bool allGuardiansDead = true;
                        for (std::unordered_set<ObjectGuid>::iterator guardianIT = crystalGuardiansIT->second.begin(); guardianIT != crystalGuardiansIT->second.end(); guardianIT++)
                        {
                            if (Creature* checkC = instance->GetCreature(*guardianIT))
                            {
                                if (checkC->IsAlive())
                                {
                                    allGuardiansDead = false;
                                    break;
                                }
                            }
                        }
                        if (allGuardiansDead)
                        {
                            if (GameObject* checkGO = instance->GetGameObject(crystalGuardiansIT->first))
                            {
                                checkGO->SetGoState(GOState::GO_STATE_ACTIVE);
                                bool allActivated = true;
                                for (std::unordered_set<ObjectGuid>::iterator crystalIT = OGDoodadDireMaulCrystalGeneratorSet.begin(); crystalIT != OGDoodadDireMaulCrystalGeneratorSet.end(); crystalIT++)
                                {
                                    if (GameObject* eachCrystal = instance->GetGameObject(*crystalIT))
                                    {
                                        if (eachCrystal->GetGoState() != GOState::GO_STATE_ACTIVE)
                                        {
                                            allActivated = false;
                                            break;
                                        }
                                    }
                                }
                                if (allActivated)
                                {
                                    ActivateImmo();
                                }
                            }
                        }
                    }
                }
            }
            else if (creature->GetEntry() == DIRE_MAUL_NPC::NPC_IMMOLTHAR)
            {
                if (Creature* princeC = instance->GetCreature(OGBossPrinceTortheldrin))
                {
                    princeC->AI()->Talk(DIRE_MAUL_LINE_PRINCE_TORTHELDRIN::LINE_PRINCE_TORTHELDRIN_0);
                    princeC->SetFaction(14);
                    princeC->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    for (std::unordered_set<ObjectGuid>::iterator hsIT = OGHighborneSummonerSet.begin(); hsIT != OGHighborneSummonerSet.end(); hsIT++)
                    {
                        if (Creature* hsC = instance->GetCreature(*hsIT))
                        {
                            hsC->SetFaction(14);
                            hsC->SetReactState(ReactStates::REACT_AGGRESSIVE);
                        }
                    }
                }
                SetBossState(DIRE_MAUL_BOSS::BOSS_IMMOLTHAR, EncounterState::DONE);
            }
            else if (creature->GetEntry() == DIRE_MAUL_NPC::NPC_PRINCE_TORTHELDRIN)
            {
                if (GameObject* checkGO = instance->GetGameObject(OGThePrinceChest))
                {
                    if (checkGO->HasFlag(GAMEOBJECT_FLAGS, GameObjectFlags::GO_FLAG_NOT_SELECTABLE))
                    {
                        checkGO->RemoveFlag(GAMEOBJECT_FLAGS, GameObjectFlags::GO_FLAG_NOT_SELECTABLE);
                    }
                }
                SetBossState(DIRE_MAUL_BOSS::BOSS_PRINCE_TORTHELDRIN, EncounterState::DONE);
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case DIRE_MAUL_GAMEOBJECT::GAMEOBJECT_CONSERVATORY_DOOR:
            {
                siConservatoryDoor = go->GetSpawnId();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            case DIRE_MAUL_GAMEOBJECT::GAMEOBJECT_THE_PRINCE_CHEST:
            {
                OGThePrinceChest = go->GetGUID();
                //go->SetGoState(GOState::GO_STATE_READY);
                //if (!go->HasFlag(GAMEOBJECT_FLAGS, GameObjectFlags::GO_FLAG_NOT_SELECTABLE))
                //{
                //    go->SetFlag(GAMEOBJECT_FLAGS, GameObjectFlags::GO_FLAG_NOT_SELECTABLE);
                //}
                break;
            }
            case DIRE_MAUL_GAMEOBJECT::GAMEOBJECT_DOODAD_DIRE_MAULCRYSTAL_GENERATOR_01:
            {
                OGDoodadDireMaulCrystalGeneratorSet.insert(go->GetGUID());
                break;
            }
            case DIRE_MAUL_GAMEOBJECT::GAMEOBJECT_DOODAD_DIRE_MAULCRYSTAL_GENERATOR_02:
            {
                OGDoodadDireMaulCrystalGeneratorSet.insert(go->GetGUID());
                break;
            }
            case DIRE_MAUL_GAMEOBJECT::GAMEOBJECT_DOODAD_DIRE_MAULCRYSTAL_GENERATOR_03:
            {
                OGDoodadDireMaulCrystalGeneratorSet.insert(go->GetGUID());
                break;
            }
            case DIRE_MAUL_GAMEOBJECT::GAMEOBJECT_DOODAD_DIRE_MAULCRYSTAL_GENERATOR_04:
            {
                OGDoodadDireMaulCrystalGeneratorSet.insert(go->GetGUID());
                break;
            }
            case DIRE_MAUL_GAMEOBJECT::GAMEOBJECT_DOODAD_DIRE_MAULCRYSTAL_GENERATOR_05:
            {
                OGDoodadDireMaulCrystalGeneratorSet.insert(go->GetGUID());
                break;
            }
            case DIRE_MAUL_GAMEOBJECT::GAMEOBJECT_DOODAD_DIRE_MAUL_BOSS_FORCE_FIELD_01:
            {
                OGDoodadDireMaulBossForceField01 = go->GetGUID();
                break;
            }
            default:
            {
                break;
            }
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == DIRE_MAUL_DATA::DATA_OLD_IRONBARK_REDEEM)
            {
                if (Creature* checkC = instance->GetCreature(OGOldIronbark))
                {
                    checkC->AI()->Talk(DIRE_MAUL_LINE_OLD_IRONBARK::LINE_OLD_IRONBARK_0);
                    checkC->UpdateEntry(DIRE_MAUL_NPC::NPC_IRONBARK_THE_REDEEMED);
                    checkC->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);
                    checkC->SetFlag(EUnitFields::UNIT_NPC_FLAGS, NPCFlags::UNIT_NPC_FLAG_GOSSIP);
                }
            }
            else if (type == DIRE_MAUL_DATA::DATA_TEST_IMMO)
            {
                ActivateImmo();
            }
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == DIRE_MAUL_DATA::DATA_CONSERVATORY_DOOR_SPAWN_ID)
            {
                return siConservatoryDoor;
            }
            return 0;
        }

        void OnPlayerEnter(Player* player) override
        {
            playerFaction = player->GetFaction();
        }

        virtual void Update(uint32 diff) override
        {
            if (!allCrystalInitialized)
            {
                int setCount = 0;
                for (std::unordered_set<ObjectGuid>::iterator crystalIT = OGDoodadDireMaulCrystalGeneratorSet.begin(); crystalIT != OGDoodadDireMaulCrystalGeneratorSet.end(); crystalIT++)
                {
                    if (GameObject* eachCrystal = instance->GetGameObject(*crystalIT))
                    {
                        std::list<Unit*> gdList;
                        Trinity::AnyUnitInObjectRangeCheck u_check(eachCrystal, 20.0f);
                        Trinity::CreatureListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(eachCrystal, gdList, u_check);
                        Cell::VisitGridObjects(eachCrystal, searcher, 20.0f);
                        for (std::list<Unit*>::const_iterator i = gdList.begin(); i != gdList.end(); ++i)
                        {
                            if (Unit* eachU = (*i))
                            {
                                if (Creature* eachC = eachU->ToCreature())
                                {
                                    if (eachC->GetEntry() == DIRE_MAUL_NPC::NPC_ARCANE_ABERRATION || eachC->GetEntry() == DIRE_MAUL_NPC::NPC_MANA_REMNANT)
                                    {
                                        if (OGDoodadDireMaulCrystalGenerator_GuardiansMap[*crystalIT].find(eachC->GetGUID()) == OGDoodadDireMaulCrystalGenerator_GuardiansMap[*crystalIT].end())
                                        {
                                            OGDoodadDireMaulCrystalGenerator_GuardiansMap[*crystalIT].insert(eachC->GetGUID());
                                        }
                                        setCount++;
                                    }
                                }
                            }
                        }
                    }
                }
                if (setCount >= 40)
                {
                    allCrystalInitialized = true;
                }
            }
            if (GetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF) != EncounterState::DONE)
            {
                if (!ironbarkWeakLined)
                {
                    if (ironbarkWeakLineCheckDelay > 0)
                    {
                        ironbarkWeakLineCheckDelay -= diff;
                    }
                    else
                    {
                        ironbarkWeakLineCheckDelay = 3000;
                        if (Creature* checkIB = instance->GetCreature(OGOldIronbark))
                        {
                            if (checkIB->SelectNearestPlayer(10.0f))
                            {
                                checkIB->AI()->Talk(DIRE_MAUL_LINE_OLD_IRONBARK::LINE_OLD_IRONBARK_1);
                                ironbarkWeakLined = true;
                            }                            
                        }
                    }
                }
                if (GetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF) == EncounterState::NOT_STARTED)
                {
                    if (Creature* checkBoss = instance->GetCreature(OGBossZevrimThornhoof))
                    {
                        if (checkBoss->IsInCombat())
                        {
                            SetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF, EncounterState::IN_PROGRESS);
                        }
                    }
                }
                else if (GetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF) == EncounterState::IN_PROGRESS)
                {
                    if (Creature* checkBoss = instance->GetCreature(OGBossZevrimThornhoof))
                    {
                        if (!checkBoss->IsAlive())
                        {
                            SetData(DIRE_MAUL_DATA::DATA_OLD_IRONBARK_REDEEM, 0);
                            SetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF, EncounterState::DONE);
                        }
                        else if (!checkBoss->IsInCombat())
                        {
                            SetBossState(DIRE_MAUL_BOSS::BOSS_ZEVRIM_THORNHOOF, EncounterState::NOT_STARTED);
                        }
                    }
                }
            }            

            if (GetBossState(DIRE_MAUL_BOSS::BOSS_TENDRIS_WARPWOOD) == EncounterState::NOT_STARTED)
            {
                if (Creature* checkBoss = instance->GetCreature(OGBossTendrisWarpwood))
                {
                    if (!checkBoss->GetThreatManager().IsThreatListEmpty())
                    {
                        checkBoss->AI()->Talk(DIRE_MAUL_LINE_TENDRIS_WARPWOOD::LINE_TENDRIS_WARPWOOD_0);
                        std::unordered_map<ObjectGuid, Creature*> const& objects = instance->GetObjectsStore().GetElements()._elements._element;
                        for (std::unordered_map<ObjectGuid, Creature*>::const_iterator itr = objects.cbegin(); itr != objects.cend(); ++itr)
                        {
                            if (itr->second->GetEntry() == DIRE_MAUL_NPC::NPC_PETRIFIED_TREANT || itr->second->GetEntry() == DIRE_MAUL_NPC::NPC_PETRIFIED_GUARDIAN || itr->second->GetEntry() == DIRE_MAUL_NPC::NPC_IRONBARK_PROTECTOR)
                            {
                                itr->second->AI()->AttackStart(checkBoss->GetThreatManager().GetAnyTarget());
                            }
                        }
                        SetBossState(DIRE_MAUL_BOSS::BOSS_TENDRIS_WARPWOOD, EncounterState::IN_PROGRESS);
                    }
                }
            }
            else if (GetBossState(DIRE_MAUL_BOSS::BOSS_TENDRIS_WARPWOOD) == EncounterState::IN_PROGRESS)
            {
                if (Creature* checkBoss = instance->GetCreature(OGBossTendrisWarpwood))
                {
                    if (!checkBoss->IsAlive())
                    {
                        if (TempSummon* tsEquine = instance->SummonCreature(DIRE_MAUL_NPC::NPC_ANCIENT_EQUINE_SPIRIT, checkBoss->GetPosition()))
                        {
                            tsEquine->CastSpell(tsEquine, DIRE_MAUL_SPELL::SPELL_SUMMON_VISUAL);
                            tsEquine->SetWalk(false);
                            tsEquine->GetMotionMaster()->MovePoint(0, 39.754f, 488.723f, -23.27f, true, 3.56f);
                        }
                        SetBossState(DIRE_MAUL_BOSS::BOSS_TENDRIS_WARPWOOD, EncounterState::DONE);
                    }
                    else if (checkBoss->GetThreatManager().IsThreatListEmpty())
                    {
                        SetBossState(DIRE_MAUL_BOSS::BOSS_TENDRIS_WARPWOOD, EncounterState::NOT_STARTED);
                    }
                }
            }
        }

        void ActivateImmo()
        {
            if (Creature* checkHS = instance->GetCreatureBySpawnId(DIRE_MAUL_DATA::DATA_RESTRAIN_TALKER_SPAWNID))
            {
                checkHS->AI()->Talk(DIRE_MAUL_LINE_HIGHBORNE_SUMMONER::LINE_HIGHBORNE_SUMMONER_0);
            }
            if (GameObject* ff = instance->GetGameObject(OGDoodadDireMaulBossForceField01))
            {
                ff->SetGoState(GOState::GO_STATE_ACTIVE);
            }
            if (Creature* im = instance->GetCreature(OGBossImmolthar))
            {
                std::list<Unit*> hsList;
                Trinity::AnyUnitInObjectRangeCheck u_check(im, 100.0f);
                Trinity::CreatureListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(im, hsList, u_check);
                Cell::VisitGridObjects(im, searcher, 100.0f);
                for (std::list<Unit*>::const_iterator i = hsList.begin(); i != hsList.end(); ++i)
                {
                    if (Unit* eachU = (*i))
                    {
                        if (Creature* eachC = eachU->ToCreature())
                        {
                            if (eachC->GetEntry() == DIRE_MAUL_NPC::NPC_HIGHBORNE_SUMMONER)
                            {
                                eachC->SetWalk(false);
                                eachC->SetFaction(playerFaction);
                                eachC->GetThreatManager().AddThreat(im, 100);                                
                                im->GetThreatManager().AddThreat(eachC, 100);
                                eachC->AI()->AttackStart(im);
                            }
                        }
                    }
                }
            }
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_dire_maul_InstanceMapScript(map);
    }
};

class npc_ironbark_the_redeemed : public CreatureScript
{
public:
    npc_ironbark_the_redeemed() : CreatureScript("npc_ironbark_the_redeemed") { }

    struct npc_ironbark_the_redeemedAI : public ScriptedAI
    {
        npc_ironbark_the_redeemedAI(Creature* creature) : ScriptedAI(creature)
        {
            Reset();
        }

        void Reset() override
        {
            events.Reset();
        }

        bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (menuId == GOSSIP_MENU_IRONBARK_THE_REDEEMED && gossipListId == 0)
            {
                me->RemoveFlag(EUnitFields::UNIT_NPC_FLAGS, NPCFlags::UNIT_NPC_FLAG_GOSSIP);
                events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_TALK_0, 2000);
                events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_MOVE_WAY, 4000);
                return true;
            }
            return false;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE)
            {
                switch (id)
                {
                case 4:
                {
                    me->StopMoving();
                    me->GetMotionMaster()->Clear();
                    events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_OPEN_DOOR_EMOTE, 2000);
                    events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_OPEN_DOOR_EMOTE, 5000);
                    events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_DOOR_OPEN, 7000);
                    events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_TALK_1, 10000);                    
                    events.ScheduleEvent(DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_DESPAWN, 30000);
                    break;
                }
                default:
                {
                    break;
                }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);
            if (events.Empty())
            {
                return;
            }
            switch (events.ExecuteEvent())
            {
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_TALK_0:
            {
                me->AI()->Talk(DIRE_MAUL_LINE_IRONBARK_THE_REDEEMED::LINE_IRONBARK_THE_REDEEMED_0);
                break;
            }
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_MOVE_WAY:
            {
                me->StopMoving();
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePath(DIRE_MAUL_WAYPOINT::WAYPOINT_IRONBARK_THE_REDEEMED, false);
                break;
            }
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_OPEN_DOOR_EMOTE:
            {
                me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_ATTACK_UNARMED);
                break;
            }
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_DOOR_OPEN:
            {
                if (Map* myMap = me->GetMap())
                {
                    if (InstanceScript* is = me->GetInstanceScript())
                    {
                        if (GameObject* goDoor = myMap->GetGameObjectBySpawnId(is->GetData(DIRE_MAUL_DATA::DATA_CONSERVATORY_DOOR_SPAWN_ID)))
                        {
                            goDoor->SetGoState(GOState::GO_STATE_ACTIVE);
                        }
                    }
                }
                break;
            }
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_TALK_1:
            {
                me->AI()->Talk(DIRE_MAUL_LINE_IRONBARK_THE_REDEEMED::LINE_IRONBARK_THE_REDEEMED_1);
                break;
            }
            case DIRE_MAUL_EVENT_IRONBARK_THE_REDEEMED::EVENT_DESPAWN:
            {
                me->DespawnOrUnsummon(100, 24h * 7);
                break;
            }
            default:
            {
                break;
            }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ironbark_the_redeemedAI(creature);
    }
};

class npc_doomguard : public CreatureScript
{
public:
    npc_doomguard() : CreatureScript("npc_doomguard") { }

    struct npc_doomguardAI : public ScriptedAI
    {
        npc_doomguardAI(Creature* creature) : ScriptedAI(creature)
        {
            Reset();
        }

        void Reset() override
        {

        }

        void UpdateAI(uint32 diff) override
        {
            if (!me->GetThreatManager().IsThreatListEmpty())
            {
                if (Unit* myVictim = me->GetVictim())
                {
                    if (!me->IsNonMeleeSpellCast(false))
                    {
                        if (!myVictim->HasAura(DIRE_MAUL_SPELL::SPELL_CRIPPLE))
                        {
                            me->CastSpell(myVictim, DIRE_MAUL_SPELL::SPELL_CRIPPLE);
                            return;
                        }
                        if (!myVictim->HasAura(DIRE_MAUL_SPELL::SPELL_REND))
                        {
                            me->CastSpell(myVictim, DIRE_MAUL_SPELL::SPELL_REND);
                            return;
                        }
                        if (!me->GetSpellHistory()->HasCooldown(DIRE_MAUL_SPELL::SPELL_WAR_STOMP))
                        {
                            me->CastSpell(myVictim, DIRE_MAUL_SPELL::SPELL_WAR_STOMP);
                            return;
                        }
                        if (urand(0, 5) == 0)
                        {
                            me->CastSpell(myVictim, DIRE_MAUL_SPELL::SPELL_RAIN_OF_FIRE);
                            return;
                        }
                        DoMeleeAttackIfReady();
                    }
                }
                else
                {
                    me->AI()->AttackStart(me->GetThreatManager().GetAnyTarget());
                }
            }
            else
            {
                if (Unit* master = me->GetOwner())
                {
                    if (!master->GetThreatManager().IsThreatListEmpty())
                    {
                        if (Unit* victim = master->GetThreatManager().GetAnyTarget())
                        {
                            me->AI()->AttackStart(victim);
                        }
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_doomguardAI(creature);
    }
};

class npc_wandering_eye_of_kilrogg : public CreatureScript
{
public:
    npc_wandering_eye_of_kilrogg() : CreatureScript("npc_wandering_eye_of_kilrogg") { }

    struct npc_wandering_eye_of_kilroggAI : public ScriptedAI
    {
        npc_wandering_eye_of_kilroggAI(Creature* creature) : ScriptedAI(creature)
        {
            Reset();
        }

        void Reset() override
        {
            summonDelay = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (summonDelay > 0)
            {
                summonDelay -= diff;
            }
            if (Player* pInRange = me->SelectNearestPlayer(10.0f))
            {
                if (summonDelay <= 0)
                {
                    summonDelay = urand(12000, 20000);
                    me->AI()->Talk(DIRE_MAUL_LINE_WANDERING_EYE_OF_KILROGG::LINE_WANDERING_EYE_OF_KILROGG_0);
                    me->CastSpell(me, DIRE_MAUL_SPELL::SPELL_SUMMON_NETHERWALKER);
                }
            }
        }

    private:
        int summonDelay;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wandering_eye_of_kilroggAI(creature);
    }
};

class npc_ferra : public CreatureScript
{
public:
    npc_ferra() : CreatureScript("npc_ferra") { }

    struct npc_ferraAI : public ScriptedAI
    {
        int chargeDelay;
        int maulDelay;

        npc_ferraAI(Creature* creature) : ScriptedAI(creature)
        {
            Reset();
            chargeDelay = 0;
            maulDelay = 0;
        }

        void Reset() override
        {
            summonDelay = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (chargeDelay > 0)
            {
                chargeDelay -= diff;
            }
            if (maulDelay > 0)
            {
                maulDelay -= diff;
            }
            if (me->HasUnitState(UnitState::UNIT_STATE_ROAMING_MOVE))
            {
                return;
            }
            if (Map* map = me->GetMap())
            {
                if (Creature* master = map->GetCreatureBySpawnId(DIRE_MAUL_DATA::DATA_ILLYANNA_RAVENOAK_SPAWNID))
                {
                    if (!me->GetThreatManager().IsThreatListEmpty())
                    {
                        if (master->GetThreatManager().IsThreatListEmpty())
                        {
                            master->GetThreatManager().AddThreat(me->GetThreatManager().GetAnyTarget(), 100);
                        }
                        if (chargeDelay <= 0)
                        {
                            for (ThreatReference const* ref : me->GetThreatManager().GetUnsortedThreatList())
                            {
                                if (Unit* eachV = ref->GetVictim())
                                {
                                    float eachDistance = me->GetDistance(eachV);
                                    if (eachDistance > 8.0f&&eachDistance < 25.0f)
                                    {
                                        AttackStart(eachV);
                                        me->CastSpell(eachV, DIRE_MAUL_SPELL::SPELL_CHARGE);
                                        chargeDelay = 2000;
                                        return;
                                    }
                                }
                            }
                        }
                        if (maulDelay <= 0)
                        {
                            if (Unit* currentV = me->GetVictim())
                            {
                                if (!me->IsNonMeleeSpellCast(true))
                                {
                                    if (urand(0, 2) == 0)
                                    {
                                        me->CastSpell(currentV, DIRE_MAUL_SPELL::SPELL_MAUL);
                                        maulDelay = urand(4000, 8000);
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if (!master->GetThreatManager().IsThreatListEmpty())
                        {
                            AttackStart(master->GetThreatManager().GetAnyTarget());
                        }
                        else
                        {
                            me->StopMoving();
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveFollow(master, 4.0f, PET_FOLLOW_ANGLE);
                        }
                    }
                }
            }

            if (UpdateVictim())
            {
                DoMeleeAttackIfReady();
            }
        }

    private:
        int summonDelay;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ferraAI(creature);
    }
};

void AddSC_instance_dire_maul()
{
    new instance_dire_maul();
    new npc_ironbark_the_redeemed();
    new npc_doomguard();
    new npc_wandering_eye_of_kilrogg();
    new npc_ferra();
}
