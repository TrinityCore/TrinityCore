/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Instance_Blackfathom_Deeps
SD%Complete: 50
SDComment:
SDCategory: Blackfathom Deeps
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "blackfathom_deeps.h"

const Position LorgusPosition[4] =
{
    { -458.500610f, -38.343079f, -33.474445f, 0.0f },
    { -469.423615f, -88.400513f, -39.265102f, 0.0f },
    { -622.354980f, -10.350100f, -22.777000f, 0.0f },
    { -759.640564f,  16.658913f, -29.159529f, 0.0f }
};

const Position SpawnsLocation[] =
{
    {-775.431f, -153.853f, -25.871f, 3.207f},
    {-775.404f, -174.132f, -25.871f, 3.185f},
    {-862.430f, -154.937f, -25.871f, 0.060f},
    {-862.193f, -174.251f, -25.871f, 6.182f},
    {-863.895f, -458.899f, -33.891f, 5.637f}
};

class instance_blackfathom_deeps : public InstanceMapScript
{
public:
    instance_blackfathom_deeps() : InstanceMapScript("instance_blackfathom_deeps", 48) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_blackfathom_deeps_InstanceMapScript(map);
    }

    struct instance_blackfathom_deeps_InstanceMapScript : public InstanceScript
    {
        instance_blackfathom_deeps_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);

            countFires = 0;
            deathTimes = 0;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_TWILIGHT_LORD_KELRIS:
                    twilightLordKelrisGUID = creature->GetGUID();
                    break;
                case NPC_LORGUS_JETT:
                    creature->SetHomePosition(LorgusPosition[urand(0, 3)]);
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_FIRE_OF_AKU_MAI_1:
                    shrine1GUID = go->GetGUID();
                    break;
                case GO_FIRE_OF_AKU_MAI_2:
                    shrine2GUID = go->GetGUID();
                    break;
                case GO_FIRE_OF_AKU_MAI_3:
                    shrine3GUID = go->GetGUID();
                    break;
                case GO_FIRE_OF_AKU_MAI_4:
                    shrine4GUID = go->GetGUID();
                    break;
                case GO_SHRINE_OF_GELIHAST:
                    shrineOfGelihastGUID = go->GetGUID();
                    if (GetBossState(DATA_GELIHAST) != DONE)
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    break;
                case GO_ALTAR_OF_THE_DEEPS:
                    altarOfTheDeepsGUID = go->GetGUID();
                    if (GetBossState(DATA_AKU_MAI) != DONE)
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    break;
                case GO_AKU_MAI_DOOR:
                    if (GetBossState(DATA_AKU_MAI) == DONE)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    mainDoorGUID = go->GetGUID();
                    break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_FIRE:
                    countFires = data;
                    switch (countFires)
                    {
                        case 1:
                            if (GameObject* go = instance->GetGameObject(shrine1GUID))
                            {
                                for (uint8 i = 0; i < 4; ++i)
                                    go->SummonCreature(NPC_AKU_MAI_SNAPJAW, SpawnsLocation[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                            }
                            break;
                        case 2:
                            if (GameObject* go = instance->GetGameObject(shrine1GUID))
                            {
                                for (uint8 i = 0; i < 2; ++i)
                                {
                                    go->SummonCreature(NPC_MURKSHALLOW_SOFTSHELL, SpawnsLocation[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                    go->SummonCreature(NPC_MURKSHALLOW_SOFTSHELL, SpawnsLocation[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                    go->SummonCreature(NPC_MURKSHALLOW_SOFTSHELL, SpawnsLocation[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                    go->SummonCreature(NPC_MURKSHALLOW_SOFTSHELL, SpawnsLocation[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                }
                            }
                            break;
                        case 3:
                            if (GameObject* go = instance->GetGameObject(shrine1GUID))
                            {
                                go->SummonCreature(NPC_AKU_MAI_SERVANT, SpawnsLocation[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                                go->SummonCreature(NPC_AKU_MAI_SERVANT, SpawnsLocation[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                            }
                            break;
                        case 4:
                            if (GameObject* go = instance->GetGameObject(shrine1GUID))
                            {
                                for (uint8 i = 0; i < 4; ++i)
                                    go->SummonCreature(NPC_BARBED_CRUSTACEAN, SpawnsLocation[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                            }
                            break;
                    }
                    break;
                case DATA_EVENT:
                    deathTimes = data;
                    if (deathTimes == 18)
                        HandleGameObject(mainDoorGUID, true);
                    break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case DATA_GELIHAST:
                    if (state == DONE)
                        if (GameObject* go = instance->GetGameObject(shrineOfGelihastGUID))
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                case DATA_AKU_MAI:
                    if (state == DONE)
                        if (GameObject* go = instance->GetGameObject(altarOfTheDeepsGUID))
                        {
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            go->SummonCreature(NPC_MORRIDUNE, SpawnsLocation[4], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
                        }
                    break;
                default:
                    break;
            }

            return true;
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_FIRE:
                    return countFires;
                case DATA_EVENT:
                    return deathTimes;
            }

            return 0;
        }

        ObjectGuid GetGuidData(uint32 data) const override
        {
            switch (data)
            {
                case DATA_TWILIGHT_LORD_KELRIS:
                    return twilightLordKelrisGUID;
                case DATA_SHRINE1:
                    return shrine1GUID;
                case DATA_SHRINE2:
                    return shrine2GUID;
                case DATA_SHRINE3:
                    return shrine3GUID;
                case DATA_SHRINE4:
                    return shrine4GUID;
                case DATA_SHRINE_OF_GELIHAST:
                    return shrineOfGelihastGUID;
                case DATA_MAINDOOR:
                    return mainDoorGUID;
            }

            return ObjectGuid::Empty;
        }

    private:
        ObjectGuid twilightLordKelrisGUID;
        ObjectGuid shrine1GUID;
        ObjectGuid shrine2GUID;
        ObjectGuid shrine3GUID;
        ObjectGuid shrine4GUID;
        ObjectGuid shrineOfGelihastGUID;
        ObjectGuid altarOfTheDeepsGUID;
        ObjectGuid mainDoorGUID;
        uint8 countFires;
        uint8 deathTimes;
    };
};

void AddSC_instance_blackfathom_deeps()
{
    new instance_blackfathom_deeps();
}
