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
 SDName: Instance_Sunken_Temple
 SD%Complete: 100
 SDComment:Place Holder
 SDCategory: Sunken Temple
 EndScriptData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "sunken_temple.h"

 // EJ scripts
#include "GridNotifiers.h"
#include "GameObjectAI.h"
#include "SpellAuras.h"

enum Gameobject
{
    GO_ATALAI_STATUE1 = 148830,
    GO_ATALAI_STATUE2 = 148831,
    GO_ATALAI_STATUE3 = 148832,
    GO_ATALAI_STATUE4 = 148833,
    GO_ATALAI_STATUE5 = 148834,
    GO_ATALAI_STATUE6 = 148835,
    GO_ATALAI_LIGHT1 = 148883,
    GO_ATALAI_LIGHT2 = 148937,
};

enum CreatureIds
{
    NPC_ATALALARION = 8580
};

static Position const atalalarianPos = { -466.5134f, 95.19822f, -189.6463f, 0.03490658f };
static uint8 const nStatues = 6;
static Position const statuePositions[nStatues]
{
    { -515.553f,  95.25821f, -173.707f,  0.0f },
    { -419.8487f, 94.48368f, -173.707f,  0.0f },
    { -491.4003f, 135.9698f, -173.707f,  0.0f },
    { -491.4909f, 53.48179f, -173.707f,  0.0f },
    { -443.8549f, 136.1007f, -173.707f,  0.0f },
    { -443.4171f, 53.83124f, -173.707f,  0.0f }
};

class instance_sunken_temple : public InstanceMapScript
{
public:
    instance_sunken_temple() : InstanceMapScript(STScriptName, 109) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_sunken_temple_InstanceMapScript(map);
    }

    struct instance_sunken_temple_InstanceMapScript : public InstanceScript
    {
        instance_sunken_temple_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            State = 0;

            s1 = false;
            s2 = false;
            s3 = false;
            s4 = false;
            s5 = false;
            s6 = false;

            SetBossNumber(SUNKEN_TEMPLE_DATA_BOSS::BOSS_COUNT);
            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_GASHER, EncounterState::NOT_STARTED);
            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_HUKKU, EncounterState::NOT_STARTED);
            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_LORO, EncounterState::NOT_STARTED);
            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_MIJAN, EncounterState::NOT_STARTED);
            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_ZOLO, EncounterState::NOT_STARTED);
            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_ZULLOR, EncounterState::NOT_STARTED);
            shieldBossFinished = false;

            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_JAMMALAN, EncounterState::NOT_STARTED);
            jammalanFinished = false;

            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_DREAM_SCYTHE, EncounterState::NOT_STARTED);
            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_WEAVER, EncounterState::NOT_STARTED);
            jammalanSummonHandled = false;

            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_SHADE_OF_ERANIKUS, EncounterState::NOT_STARTED);
            eranikusEnabled = false;

            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_AVATAR_OF_HAKKAR, EncounterState::NOT_STARTED);

            OGGOEvilCircleMap.clear();

            hakkarMinionSummonDelay = 5000;
            bloodKeeperSummonDelay = 20000;
            summonBloodKeeper = true;
            hakkarSummoned = false;
            suppressionTime = 0;
        }

        ObjectGuid GOAtalaiStatue1;
        ObjectGuid GOAtalaiStatue2;
        ObjectGuid GOAtalaiStatue3;
        ObjectGuid GOAtalaiStatue4;
        ObjectGuid GOAtalaiStatue5;
        ObjectGuid GOAtalaiStatue6;

        ObjectGuid OGGOJammalanBarrier;

        ObjectGuid OGGOHakkarDoor1;
        ObjectGuid OGGOHakkarDoor2;
        std::unordered_map<uint32, ObjectGuid> OGGOEvilCircleMap;
        uint32 SIGOEternalFlame1;
        uint32 SIGOEternalFlame2;
        uint32 SIGOEternalFlame3;
        uint32 SIGOEternalFlame4;

        ObjectGuid OGBossGasher;
        ObjectGuid OGBossHukku;
        ObjectGuid OGBossLoro;
        ObjectGuid OGBossMijan;
        ObjectGuid OGBossZolo;
        ObjectGuid OGBossZullor;

        ObjectGuid OGBossJammalan;
        ObjectGuid OGBossShadeOfEranikus;
        ObjectGuid OGBossDreamScythe;
        ObjectGuid OGBossWeaver;

        ObjectGuid OGAvatarOfHakkar;
        ObjectGuid OGBloodKeeper;
        ObjectGuid OGNightmareSuppressor;

        uint32 State;

        bool s1;
        bool s2;
        bool s3;
        bool s4;
        bool s5;
        bool s6;

        bool shieldBossFinished;
        bool jammalanFinished;
        bool jammalanSummonHandled;
        bool eranikusEnabled;

        int hakkarMinionSummonDelay;
        int bloodKeeperSummonDelay;
        bool summonBloodKeeper;
        bool hakkarSummoned;
        int suppressionTime;

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case SUNKEN_TEMPLE_NPC::NPC_GASHER:
            {
                OGBossGasher = creature->GetGUID();
                break;
            }
            case SUNKEN_TEMPLE_NPC::NPC_HUKKU:
            {
                OGBossHukku = creature->GetGUID();
                break;
            }
            case SUNKEN_TEMPLE_NPC::NPC_LORO:
            {
                OGBossLoro = creature->GetGUID();
                break;
            }
            case SUNKEN_TEMPLE_NPC::NPC_MIJAN:
            {
                OGBossMijan = creature->GetGUID();
                break;
            }
            case SUNKEN_TEMPLE_NPC::NPC_ZOLO:
            {
                OGBossZolo = creature->GetGUID();
                break;
            }
            case SUNKEN_TEMPLE_NPC::NPC_ZULLOR:
            {
                OGBossZullor = creature->GetGUID();
                break;
            }
            case SUNKEN_TEMPLE_NPC::NPC_JAMMALAN:
            {
                OGBossJammalan = creature->GetGUID();
                break;
            }
            case SUNKEN_TEMPLE_NPC::NPC_SHADE_OF_ERANIKUS:
            {
                OGBossShadeOfEranikus = creature->GetGUID();
                creature->SetImmuneToAll(true);
                break;
            }
            case SUNKEN_TEMPLE_NPC::NPC_DREAM_SCYTHE:
            {
                OGBossDreamScythe = creature->GetGUID();
                break;
            }
            case SUNKEN_TEMPLE_NPC::NPC_WEAVER:
            {
                OGBossWeaver = creature->GetGUID();
                break;
            }
            case SUNKEN_TEMPLE_NPC::NPC_AVATAR_OF_HAKKAR:
            {
                if (GetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_AVATAR_OF_HAKKAR) == EncounterState::DONE)
                {
                    creature->DespawnOrUnsummon(0, 24h * 7);
                }
                else
                {
                    OGAvatarOfHakkar = creature->GetGUID();
                    creature->SetImmuneToAll(true);
                    creature->AI()->Talk(SUNKEN_TEMPLE_LINES_HAKKAR_AVATAR::HAKKAR_AVATAR_LINE_0);
                    SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_AVATAR_OF_HAKKAR, EncounterState::IN_PROGRESS);
                    if (GameObject* hd = instance->GetGameObject(OGGOHakkarDoor1))
                    {
                        hd->SetGoState(GOState::GO_STATE_READY);
                    }
                    if (GameObject* hd = instance->GetGameObject(OGGOHakkarDoor2))
                    {
                        hd->SetGoState(GOState::GO_STATE_READY);
                    }
                    if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame1))
                    {
                        ef->SetGoState(GOState::GO_STATE_READY);
                        if (ef->HasFlag(GAMEOBJECT_FLAGS, GameObjectFlags::GO_FLAG_NOT_SELECTABLE))
                        {
                            ef->RemoveFlag(GAMEOBJECT_FLAGS, GameObjectFlags::GO_FLAG_NOT_SELECTABLE);
                        }
                    }
                    if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame2))
                    {
                        ef->SetGoState(GOState::GO_STATE_READY);
                        if (ef->HasFlag(GAMEOBJECT_FLAGS, GameObjectFlags::GO_FLAG_NOT_SELECTABLE))
                        {
                            ef->RemoveFlag(GAMEOBJECT_FLAGS, GameObjectFlags::GO_FLAG_NOT_SELECTABLE);
                        }
                    }
                    if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame3))
                    {
                        ef->SetGoState(GOState::GO_STATE_READY);
                        if (ef->HasFlag(GAMEOBJECT_FLAGS, GameObjectFlags::GO_FLAG_NOT_SELECTABLE))
                        {
                            ef->RemoveFlag(GAMEOBJECT_FLAGS, GameObjectFlags::GO_FLAG_NOT_SELECTABLE);
                        }
                    }
                    if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame4))
                    {
                        ef->SetGoState(GOState::GO_STATE_READY);
                        if (ef->HasFlag(GAMEOBJECT_FLAGS, GameObjectFlags::GO_FLAG_NOT_SELECTABLE))
                        {
                            ef->RemoveFlag(GAMEOBJECT_FLAGS, GameObjectFlags::GO_FLAG_NOT_SELECTABLE);
                        }
                    }
                    for (std::unordered_map<uint32, ObjectGuid>::iterator it = OGGOEvilCircleMap.begin(); it != OGGOEvilCircleMap.end(); it++)
                    {
                        if (GameObject* ec = instance->GetGameObject(it->second))
                        {
                            ec->SetGoState(GOState::GO_STATE_READY);
                        }
                    }
                }
                break;
            }
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_ATALAI_STATUE1: GOAtalaiStatue1 = go->GetGUID();   break;
            case GO_ATALAI_STATUE2: GOAtalaiStatue2 = go->GetGUID();   break;
            case GO_ATALAI_STATUE3: GOAtalaiStatue3 = go->GetGUID();   break;
            case GO_ATALAI_STATUE4: GOAtalaiStatue4 = go->GetGUID();   break;
            case GO_ATALAI_STATUE5: GOAtalaiStatue5 = go->GetGUID();   break;
            case GO_ATALAI_STATUE6: GOAtalaiStatue6 = go->GetGUID();   break;
            case SUNKEN_TEMPLE_GO::GO_JAMMALAN_BARRIER:
            {
                OGGOJammalanBarrier = go->GetGUID();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            case SUNKEN_TEMPLE_GO::GO_HAKKAR_DOOR_1:
            {
                OGGOHakkarDoor1 = go->GetGUID();
                go->SetGoState(GOState::GO_STATE_ACTIVE);
                break;
            }
            case SUNKEN_TEMPLE_GO::GO_HAKKAR_DOOR_2:
            {
                OGGOHakkarDoor2 = go->GetGUID();
                go->SetGoState(GOState::GO_STATE_ACTIVE);
                break;
            }
            case SUNKEN_TEMPLE_GO::GO_ETERNAL_FLAME_1:
            {
                SIGOEternalFlame1 = go->GetSpawnId();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            case SUNKEN_TEMPLE_GO::GO_ETERNAL_FLAME_2:
            {
                SIGOEternalFlame2 = go->GetSpawnId();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            case SUNKEN_TEMPLE_GO::GO_ETERNAL_FLAME_3:
            {
                SIGOEternalFlame3 = go->GetSpawnId();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            case SUNKEN_TEMPLE_GO::GO_ETERNAL_FLAME_4:
            {
                SIGOEternalFlame4 = go->GetSpawnId();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            case SUNKEN_TEMPLE_GO::GO_EVIL_CIRCLE:
            {
                OGGOEvilCircleMap[OGGOEvilCircleMap.size()] = go->GetGUID();
                go->SetGoState(GOState::GO_STATE_READY);
                break;
            }
            }
        }

        virtual void Update(uint32 diff) override // correct order goes form 1-6
        {
            switch (State)
            {
            case GO_ATALAI_STATUE1:
                if (!s1 && !s2 && !s3 && !s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue1 = instance->GetGameObject(GOAtalaiStatue1))
                        UseStatue(pAtalaiStatue1);
                    s1 = true;
                    State = 0;
                };
                break;
            case GO_ATALAI_STATUE2:
                if (s1 && !s2 && !s3 && !s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue2 = instance->GetGameObject(GOAtalaiStatue2))
                        UseStatue(pAtalaiStatue2);
                    s2 = true;
                    State = 0;
                };
                break;
            case GO_ATALAI_STATUE3:
                if (s1 && s2 && !s3 && !s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue3 = instance->GetGameObject(GOAtalaiStatue3))
                        UseStatue(pAtalaiStatue3);
                    s3 = true;
                    State = 0;
                };
                break;
            case GO_ATALAI_STATUE4:
                if (s1 && s2 && s3 && !s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue4 = instance->GetGameObject(GOAtalaiStatue4))
                        UseStatue(pAtalaiStatue4);
                    s4 = true;
                    State = 0;
                }
                break;
            case GO_ATALAI_STATUE5:
                if (s1 && s2 && s3 && s4 && !s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue5 = instance->GetGameObject(GOAtalaiStatue5))
                        UseStatue(pAtalaiStatue5);
                    s5 = true;
                    State = 0;
                }
                break;
            case GO_ATALAI_STATUE6:
                if (s1 && s2 && s3 && s4 && s5 && !s6)
                {
                    if (GameObject* pAtalaiStatue6 = instance->GetGameObject(GOAtalaiStatue6))
                    {
                        UseStatue(pAtalaiStatue6);
                        UseLastStatue(pAtalaiStatue6);
                    }
                    s6 = true;
                    State = 0;
                }
                break;
            }
            if (!shieldBossFinished)
            {
                bool allDead = true;
                if (GetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_GASHER) != EncounterState::DONE)
                {
                    allDead = false;
                    if (Creature* checkBoss = instance->GetCreature(OGBossGasher))
                    {
                        if (!checkBoss->IsAlive())
                        {
                            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_GASHER, EncounterState::DONE);
                        }
                    }
                }
                if (GetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_HUKKU) != EncounterState::DONE)
                {
                    allDead = false;
                    if (Creature* checkBoss = instance->GetCreature(OGBossHukku))
                    {
                        if (!checkBoss->IsAlive())
                        {
                            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_HUKKU, EncounterState::DONE);
                        }
                    }
                }
                if (GetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_LORO) != EncounterState::DONE)
                {
                    allDead = false;
                    if (Creature* checkBoss = instance->GetCreature(OGBossLoro))
                    {
                        if (!checkBoss->IsAlive())
                        {
                            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_LORO, EncounterState::DONE);
                        }
                    }
                }
                if (GetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_MIJAN) != EncounterState::DONE)
                {
                    allDead = false;
                    if (Creature* checkBoss = instance->GetCreature(OGBossMijan))
                    {
                        if (!checkBoss->IsAlive())
                        {
                            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_MIJAN, EncounterState::DONE);
                        }
                    }
                }
                if (GetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_ZOLO) != EncounterState::DONE)
                {
                    allDead = false;
                    if (Creature* checkBoss = instance->GetCreature(OGBossZolo))
                    {
                        if (!checkBoss->IsAlive())
                        {
                            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_ZOLO, EncounterState::DONE);
                        }
                    }
                }
                if (GetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_ZULLOR) != EncounterState::DONE)
                {
                    allDead = false;
                    if (Creature* checkBoss = instance->GetCreature(OGBossZullor))
                    {
                        if (!checkBoss->IsAlive())
                        {
                            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_ZULLOR, EncounterState::DONE);
                        }
                    }
                }
                if (allDead)
                {
                    DoUseDoorOrButton(OGGOJammalanBarrier);
                    if (Creature* checkBoss = instance->GetCreature(OGBossJammalan))
                    {
                        if (checkBoss->IsAlive())
                        {
                            checkBoss->AI()->Talk(SUNKEN_TEMPLE_LINES_JAMMALAN::JAMMALAN_LINE_0);
                        }
                    }
                    shieldBossFinished = true;
                }
            }

            if (!jammalanFinished)
            {
                if (GetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_JAMMALAN) != EncounterState::DONE)
                {
                    if (Creature* checkBoss = instance->GetCreature(OGBossJammalan))
                    {
                        if (!checkBoss->IsAlive())
                        {
                            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_JAMMALAN, EncounterState::DONE);
                            jammalanFinished = true;
                        }
                    }
                }
            }
            else if (!jammalanSummonHandled)
            {
                bool handle1 = false;
                bool handle2 = false;
                if (Creature* checkBoss = instance->GetCreature(OGBossDreamScythe))
                {
                    if (checkBoss->IsAlive())
                    {
                        checkBoss->AI()->AttackStart(checkBoss->SelectNearestPlayer(500.0f));
                        handle1 = true;
                    }
                }
                if (Creature* checkBoss = instance->GetCreature(OGBossWeaver))
                {
                    if (checkBoss->IsAlive())
                    {
                        checkBoss->AI()->AttackStart(checkBoss->SelectNearestPlayer(500.0f));
                        handle2 = true;
                    }
                }
                if (handle1 && handle2)
                {
                    jammalanSummonHandled = true;
                }
            }
            else if (!eranikusEnabled)
            {
                bool bothDead = true;
                if (Creature* checkBoss = instance->GetCreature(OGBossDreamScythe))
                {
                    if (checkBoss->IsAlive())
                    {
                        checkBoss->AI()->AttackStart(checkBoss->SelectNearestPlayer(500.0f));
                        bothDead = false;
                    }
                }
                if (Creature* checkBoss = instance->GetCreature(OGBossWeaver))
                {
                    if (checkBoss->IsAlive())
                    {
                        checkBoss->AI()->AttackStart(checkBoss->SelectNearestPlayer(500.0f));
                        bothDead = false;
                    }
                }
                if (bothDead)
                {
                    SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_DREAM_SCYTHE, EncounterState::DONE);
                    SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_WEAVER, EncounterState::DONE);
                    if (Creature* soe = instance->GetCreature(OGBossShadeOfEranikus))
                    {
                        soe->SetImmuneToAll(false);
                        eranikusEnabled = true;
                    }
                }
            }
            else
            {
                if (GetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_SHADE_OF_ERANIKUS) == EncounterState::NOT_STARTED)
                {
                    if (Creature* soe = instance->GetCreature(OGBossShadeOfEranikus))
                    {
                        if (soe->IsInCombat())
                        {
                            std::unordered_map<ObjectGuid, Creature*> const& objects = instance->GetObjectsStore().GetElements()._elements._element;
                            for (std::unordered_map<ObjectGuid, Creature*>::const_iterator itr = objects.cbegin(); itr != objects.cend(); ++itr)
                            {
                                if (itr->second->GetEntry() == SUNKEN_TEMPLE_NPC::NPC_NIGHTMARE_SCALEBANE || itr->second->GetEntry() == SUNKEN_TEMPLE_NPC::NPC_NIGHTMARE_WANDERER || itr->second->GetEntry() == SUNKEN_TEMPLE_NPC::NPC_NIGHTMARE_WHELP || itr->second->GetEntry() == SUNKEN_TEMPLE_NPC::NPC_NIGHTMARE_WYRMKIN || itr->second->GetEntry() == SUNKEN_TEMPLE_NPC::NPC_HAZZAS || itr->second->GetEntry() == SUNKEN_TEMPLE_NPC::NPC_MORPHAZ)
                                {
                                    itr->second->AI()->AttackStart(soe->GetVictim());
                                }
                            }
                            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_SHADE_OF_ERANIKUS, EncounterState::IN_PROGRESS);
                        }
                    }
                }
                else if (GetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_SHADE_OF_ERANIKUS) == EncounterState::IN_PROGRESS)
                {
                    if (Creature* soe = instance->GetCreature(OGBossShadeOfEranikus))
                    {
                        if (!soe->IsAlive())
                        {
                            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_SHADE_OF_ERANIKUS, EncounterState::DONE);
                        }
                        else if (!soe->IsInCombat())
                        {
                            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_SHADE_OF_ERANIKUS, EncounterState::NOT_STARTED);
                        }
                    }
                }
            }

            if (GetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_AVATAR_OF_HAKKAR) == EncounterState::IN_PROGRESS)
            {
                if (Creature* aoh = instance->GetCreature(OGAvatarOfHakkar))
                {
                    std::list<Player*> players;
                    Trinity::AnyPlayerInObjectRangeCheck checker(aoh, 200.0f);
                    Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(aoh, players, checker);
                    Cell::VisitWorldObjects(aoh, searcher, 200.0f);
                    bool allDead = true;
                    for (std::list<Player*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        if ((*itr)->IsAlive())
                        {
                            allDead = false;
                            break;
                        }
                    }
                    if (allDead)
                    {
                        SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_AVATAR_OF_HAKKAR, EncounterState::FAIL);
                    }
                    else
                    {
                        if (!hakkarSummoned)
                        {
                            hakkarMinionSummonDelay -= diff;
                            bloodKeeperSummonDelay -= diff;
                            bool allDowsed = true;
                            if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame1))
                            {
                                if (ef->GetGoState() != GOState::GO_STATE_ACTIVE)
                                {
                                    allDowsed = false;
                                }
                            }
                            if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame2))
                            {
                                if (ef->GetGoState() != GOState::GO_STATE_ACTIVE)
                                {
                                    allDowsed = false;
                                }
                            }
                            if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame3))
                            {
                                if (ef->GetGoState() != GOState::GO_STATE_ACTIVE)
                                {
                                    allDowsed = false;
                                }
                            }
                            if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame4))
                            {
                                if (ef->GetGoState() != GOState::GO_STATE_ACTIVE)
                                {
                                    allDowsed = false;
                                }
                            }
                            if (allDowsed)
                            {
                                aoh->CastSpell(aoh, SUNKEN_TEMPLE_DATA_SPELL::SPELL_SUMMON_AVATAR);
                            }
                            else
                            {
                                if (hakkarMinionSummonDelay < 0)
                                {
                                    hakkarMinionSummonDelay = 30000;
                                    // Summon at all circles
                                    for (std::unordered_map<uint32, ObjectGuid>::iterator ecIT = OGGOEvilCircleMap.begin(); ecIT != OGGOEvilCircleMap.end(); ++ecIT)
                                    {
                                        if (GameObject* ec = instance->GetGameObject(ecIT->second))
                                        {
                                            aoh->SummonCreature(NPC_HAKKARI_MINION, ec->GetPositionX(), ec->GetPositionY(), ec->GetPositionZ(), 0, TempSummonType::TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                                        }
                                    }
                                }
                                if (bloodKeeperSummonDelay < 0)
                                {
                                    bloodKeeperSummonDelay = 30000;
                                    Creature* bk = instance->GetCreature(OGBloodKeeper);
                                    Creature* ns = instance->GetCreature(OGNightmareSuppressor);
                                    if (!bk && !ns)
                                    {
                                        if (summonBloodKeeper)
                                        {
                                            int randomECIndex = urand(0, OGGOEvilCircleMap.size() - 1);
                                            if (GameObject* ec = instance->GetGameObject(OGGOEvilCircleMap[randomECIndex]))
                                            {
                                                TempSummon* tsBK = aoh->SummonCreature(NPC_BLOODKEEPER, ec->GetPositionX(), ec->GetPositionY(), ec->GetPositionZ(), 0, TempSummonType::TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                                                OGBloodKeeper = tsBK->GetGUID();
                                                summonBloodKeeper = false;
                                            }
                                        }
                                        else
                                        {
                                            int doorIndex = urand(0, 1);
                                            TempSummon* tsNS = aoh->SummonCreature(NPC_NIGHTMARE_SUPPRESSOR, aHakkariDoorLocations[doorIndex].m_fX, aHakkariDoorLocations[doorIndex].m_fY, aHakkariDoorLocations[doorIndex].m_fZ, 0, TempSummonType::TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
                                            tsNS->SetFacingToObject(aoh);
                                            tsNS->Yell("NO! YOU MUST NOT DO THIS!", Language::LANG_UNIVERSAL);
                                            OGNightmareSuppressor = tsNS->GetGUID();
                                            summonBloodKeeper = true;
                                        }
                                    }
                                }

                                if (Aura* supprestionAura = aoh->GetAura(SUNKEN_TEMPLE_DATA_SPELL::SPELL_SUPPRESSION))
                                {
                                    suppressionTime += diff;
                                    if (suppressionTime > 100000)
                                    {
                                        SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_AVATAR_OF_HAKKAR, EncounterState::FAIL);
                                    }
                                }
                                else
                                {
                                    suppressionTime = 0;
                                }
                            }
                        }
                        else if (!aoh->IsAlive())
                        {
                            if (GameObject* hd = instance->GetGameObject(OGGOHakkarDoor1))
                            {
                                hd->SetGoState(GOState::GO_STATE_ACTIVE);
                            }
                            if (GameObject* hd = instance->GetGameObject(OGGOHakkarDoor2))
                            {
                                hd->SetGoState(GOState::GO_STATE_ACTIVE);
                            }
                            SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_AVATAR_OF_HAKKAR, EncounterState::DONE);
                        }
                    }
                }
            }
            else if (GetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_AVATAR_OF_HAKKAR) == EncounterState::FAIL)
            {
                if (Creature* aoh = instance->GetCreature(OGAvatarOfHakkar))
                {
                    aoh->DespawnOrUnsummon(100, 24h * 7);
                }
                if (Creature* bk = instance->GetCreature(OGBloodKeeper))
                {
                    bk->DespawnOrUnsummon(100, 24h * 7);
                }
                if (Creature* ns = instance->GetCreature(OGNightmareSuppressor))
                {
                    ns->DespawnOrUnsummon(100, 24h * 7);
                }
                if (GameObject* hd = instance->GetGameObject(OGGOHakkarDoor1))
                {
                    hd->SetGoState(GOState::GO_STATE_ACTIVE);
                }
                if (GameObject* hd = instance->GetGameObject(OGGOHakkarDoor2))
                {
                    hd->SetGoState(GOState::GO_STATE_ACTIVE);
                }
                if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame1))
                {
                    ef->DespawnOrUnsummon(100ms, 2s);
                }
                if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame2))
                {
                    ef->DespawnOrUnsummon(100ms, 2s);
                }
                if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame3))
                {
                    ef->DespawnOrUnsummon(100ms, 2s);
                }
                if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame4))
                {
                    ef->DespawnOrUnsummon(100ms, 2s);
                }
                for (std::unordered_map<uint32, ObjectGuid>::iterator it = OGGOEvilCircleMap.begin(); it != OGGOEvilCircleMap.end(); it++)
                {
                    if (GameObject* ec = instance->GetGameObject(it->second))
                    {
                        ec->SetGoState(GOState::GO_STATE_READY);
                    }
                }
                hakkarMinionSummonDelay = 5000;
                bloodKeeperSummonDelay = 20000;
                hakkarSummoned = false;
                summonBloodKeeper = true;
                suppressionTime = 0;
                SetBossState(SUNKEN_TEMPLE_DATA_BOSS::BOSS_AVATAR_OF_HAKKAR, EncounterState::NOT_STARTED);
            }
        };

        void UseStatue(GameObject* go)
        {
            go->SummonGameObject(GO_ATALAI_LIGHT1, *go, QuaternionData(), 0);
            go->SetUInt32Value(GAMEOBJECT_FLAGS, 4);
        }

        void UseLastStatue(GameObject* go)
        {
            for (uint8 i = 0; i < nStatues; ++i)
                go->SummonGameObject(GO_ATALAI_LIGHT2, statuePositions[i], QuaternionData(), 0);

            go->SummonCreature(NPC_ATALALARION, atalalarianPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 600000);
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == EVENT_STATE)
            {
                State = data;
            }
            else if (type == STEvents::DOWSE_ETERNAL_FLAME)
            {
                GameObject* ef = instance->GetGameObjectBySpawnId(data);
                if (ef)
                {
                    ef->SetLootState(LootState::GO_READY);
                    ef->SetGoState(GOState::GO_STATE_ACTIVE);
                }
                int dowsedCount = 0;
                if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame1))
                {
                    if (ef->GetGoState() == GOState::GO_STATE_ACTIVE)
                    {
                        dowsedCount++;
                    }
                }
                if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame2))
                {
                    if (ef->GetGoState() == GOState::GO_STATE_ACTIVE)
                    {
                        dowsedCount++;
                    }
                }
                if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame3))
                {
                    if (ef->GetGoState() == GOState::GO_STATE_ACTIVE)
                    {
                        dowsedCount++;
                    }
                }
                if (GameObject* ef = instance->GetGameObjectBySpawnId(SIGOEternalFlame4))
                {
                    if (ef->GetGoState() == GOState::GO_STATE_ACTIVE)
                    {
                        dowsedCount++;
                    }
                }
                if (Creature* aoh = instance->GetCreature(OGAvatarOfHakkar))
                {
                    switch (dowsedCount)
                    {
                    case 1:
                    {
                        aoh->AI()->Talk(SUNKEN_TEMPLE_LINES_HAKKAR_AVATAR::HAKKAR_AVATAR_LINE_1);
                        break;
                    }
                    case 2:
                    {
                        aoh->AI()->Talk(SUNKEN_TEMPLE_LINES_HAKKAR_AVATAR::HAKKAR_AVATAR_LINE_2);
                        break;
                    }
                    case 3:
                    {
                        aoh->AI()->Talk(SUNKEN_TEMPLE_LINES_HAKKAR_AVATAR::HAKKAR_AVATAR_LINE_3);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                }
            }
            else if (type == STEvents::HAKKAR_SUMMONED)
            {
                hakkarSummoned = true;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == EVENT_STATE)
                return State;
            return 0;
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
            {
                return false;
            }

            return true;
        }
    };
};

class go_sunken_temple_eternal_flame : public GameObjectScript
{
public:
    go_sunken_temple_eternal_flame() : GameObjectScript("go_sunken_temple_eternal_flame") { }

    struct go_sunken_temple_eternal_flameAI : public GameObjectAI
    {
        go_sunken_temple_eternal_flameAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

        InstanceScript* instance;

        void SpellHit(Unit* caster, SpellInfo const* spellInfo)
        {
            instance->SetData(DOWSE_ETERNAL_FLAME, me->GetSpawnId());
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetSunkenTempleAI<go_sunken_temple_eternal_flameAI>(go);
    }
};

class spell_summon_hakkar : public SpellScriptLoader
{
public:
    spell_summon_hakkar() : SpellScriptLoader("spell_summon_hakkar") { }

    class spell_summon_hakkar_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_summon_hakkar_SpellScript);

        void HandleDummy(SpellEffIndex effIndex)
        {
            if (const SpellInfo* pSI = GetSpellInfo())
            {
                if (pSI->Id == SPELL_SUMMON_AVATAR && effIndex == EFFECT_0)
                {
                    if (Unit* me = GetCaster())
                    {
                        if (Creature* meC = me->ToCreature())
                        {
                            meC->CastSpell(meC, SUNKEN_TEMPLE_DATA_SPELL::SPELL_AVATAR_SUMMONED);
                            meC->SetImmuneToAll(false);
                            meC->AI()->Talk(SUNKEN_TEMPLE_LINES_HAKKAR_AVATAR::HAKKAR_AVATAR_LINE_4);
                            meC->AI()->AttackStart(meC->SelectNearestPlayer(200.0f));
                            if (InstanceScript* is = meC->GetInstanceScript())
                            {
                                is->SetData(STEvents::HAKKAR_SUMMONED, 1);
                            }
                        }
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_summon_hakkar_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_summon_hakkar_SpellScript();
    }
};

void AddSC_instance_sunken_temple()
{
    new instance_sunken_temple();
    new go_sunken_temple_eternal_flame();
    new spell_summon_hakkar();
}
