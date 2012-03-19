/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "eye_of_eternity.h"

class instance_eye_of_eternity : public InstanceMapScript
{
public:
    instance_eye_of_eternity() : InstanceMapScript("instance_eye_of_eternity", 616) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_eye_of_eternity_InstanceMapScript(map);
    }

    struct instance_eye_of_eternity_InstanceMapScript : public InstanceScript
    {
        instance_eye_of_eternity_InstanceMapScript(Map* map) : InstanceScript(map) {};

        uint64 malygosGUID;
        uint64 platformGUID;
        uint64 exitPortalGUID;
        uint64 focusingIrisGUID;

        void Initialize()
        {
            SetBossNumber(MAX_ENCOUNTER);

            malygosGUID = 0;
            platformGUID = 0;
            exitPortalGUID = 0;
            focusingIrisGUID = 0;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_MALYGOS:
                    malygosGUID = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_PLATFORM:
                    platformGUID = go->GetGUID();
                    //if (GetBossState(BOSS_MALYGOS) == DONE)
                    //    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                    break;
                case GO_EXIT_PORTAL:
                    exitPortalGUID = go->GetGUID();
                    break;
                case GO_FOCUSING_IRIS_10:
                case GO_FOCUSING_IRIS_25:
                    focusingIrisGUID = go->GetGUID();
                    if (GetBossState(BOSS_MALYGOS) == DONE)
                        go->SetPhaseMask(2, true);
                    break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state)
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case BOSS_MALYGOS:
                    if (state == NOT_STARTED)
                    {
                        if (GameObject* focusingIris = instance->GetGameObject(focusingIrisGUID))
                        {
                            focusingIris->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            focusingIris->SetPhaseMask(1, true);
                        }

                        if (GameObject* exitPortal = instance->GetGameObject(exitPortalGUID))
                            exitPortal->SetPhaseMask(1, true);

                        if (GameObject* platform = instance->GetGameObject(platformGUID))
                            if (platform->HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED))
                                platform->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                    }
                    if (state == IN_PROGRESS)
                    {
                        if (GameObject* focusingIris = instance->GetGameObject(focusingIrisGUID))
                            focusingIris->SetPhaseMask(2, true);

                        if (GameObject* exitPortal = instance->GetGameObject(exitPortalGUID))
                            exitPortal->SetPhaseMask(2, true);
                    }
                    if (state == DONE)
                    {
                        if (GameObject* exitPortal = instance->GetGameObject(exitPortalGUID))
                            exitPortal->SetPhaseMask(1, true);
                    }
                    break;
            }
            return true;
        }

        uint64 GetData64(uint32 data)
        {
            switch (data)
            {
                case DATA_MALYGOS:
                    return malygosGUID;
                case DATA_PLATFORM:
                    return platformGUID;
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "E E " << GetBossSaveData();

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char* data)
        {
            if (!data)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(data);

            char dataHead1, dataHead2;
            uint16 data0;

            std::istringstream loadStream(data);
            loadStream >> dataHead1 >> dataHead2 >> data0;

            if (dataHead1 == 'E' && dataHead2 == 'E')
            {
                if (data0 == IN_PROGRESS || data0 > SPECIAL)
                    data0 = NOT_STARTED;

                SetBossState(BOSS_MALYGOS, EncounterState(data0));
            }
            else
                OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        void OnPlayerEnter(Player* player)
        {
            //if (GetBossState(BOSS_MALYGOS) == DONE)
            //{
            //   if (Creature* mount = player->SummonCreature(NPC_WYRMREST_SKYTALON, player->GetPositionX(), player->GetPositionY(), 260.0f, 0.0f))
            //    {
            //        mount->SetFlying(true);
            //        player->EnterVehicle(mount, 0);
            //    }
            //}
        }
    };
};

void AddSC_instance_eye_of_eternity()
{
    new instance_eye_of_eternity();
}
