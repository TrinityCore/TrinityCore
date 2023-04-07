/*
 * Copyright 2023 AzgathCore
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
#include "Player.h"
#include "InstanceScript.h"
#include "temple_of_sethraliss.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    { 292551, DATA_ADDERIS_AND_ASPIX, DOOR_TYPE_ROOM },
    { 290906, DATA_MEREKTHA, DOOR_TYPE_ROOM },
    { 292414, DATA_GALVAZZT, DOOR_TYPE_ROOM },
};

//struct instance_temple_of_sethraliss : public InstanceScript
//{
//    instance_temple_of_sethraliss(InstanceMap* map) : InstanceScript(map)
//    {
//        SetHeaders(DataHeader);
//        SetBossNumber(EncounterCount);
//    }
//
//    void Initialize() override
//    {
//        LoadDoorData(doorData);
//    }
//
//    void OnGameObjectCreate(GameObject* go) override
//    {
//        switch (go->GetEntry())
//        {
//        case GO_SETHRALISS_TREASURE:
//            go->SetFlags(GO_FLAG_LOCKED);
//            break;
//        }
//    }
//};
//
//void AddSC_instance_temple_of_sethraliss()
//{
//    RegisterInstanceScript(instance_temple_of_sethraliss, 1877);
//}
