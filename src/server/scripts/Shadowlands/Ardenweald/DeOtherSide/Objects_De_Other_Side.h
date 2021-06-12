
/*
 * Copyright 2021 Thordekk
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
#include "instance_de_other_side.cpp"
#include "Zone_De_Other_Side.h"
#include "Objects_De_Other_Side.h"
#include "npc_De_Other_Side.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "NpcObject.h"
#include "NpcObjectAI.h"
#include "SpellAuraEffects.h"
#include "boss_dealer_xyexa.cpp"
#include "boss_hakkar_the_soulflayer_os.cpp"
#include "boss_muehzala.cpp"




enum Objects
{
    Objects_Anvil                           = 192628,
    Objects_Challengers_Cache               = 354985,
    Objects_Crate_of_Gnomish_Machinations   = 355436,
    Objects_Dusty_Cache_of_Ancient_Treasure = 355295,
    Objects_Haunted_Urn                     = 357744,
    Objects_Snow_Patch                      = 358375,
}   

void Objects_Anvil 
ObjectGuid Anvil;

void Objects_Challengers_Cache
ObjectGuid Challengers_Cache;

void Objects_Crate_of_Gnomish_Machinations
ObjectGuid Crate_of_Gnomish_Machinations;

void Objects_Dusty_Cache_of_Ancient_Treasure
ObjectGuid Dusty_Cache_of_Ancient_Treasure;

void Objects_Haunted_Urn
ObjectGuid Haunted_Urn;

void Objects_Snow_Patch
ObjectGuid Snow_Patch;

void OnGameObjectCreate(GameObject* go) override
{
    {
        switch (go->GetEntry())
        {
        case GO_Objects_Anvil:
            Anvil = go->GetGUID();
            break;
        }
    }
};

void OnGameObjectCreate(GameObject* go) override
{
    {
        switch (go->GetEntry())
        {
        case GO_Objects_Challengers_Cache:
            Challengers_Cache = go->GetGUID();
            break;
        }
    }
};

void OnGameObjectCreate(GameObject* go) override
{
    {
        switch (go->GetEntry())
        {
        case GO_Objects_Crate_of_Gnomish_Machinations:
            Crate_of_Gnomish_Machinations = go->GetGUID();
            break;
        }
    }
};

void OnGameObjectCreate(GameObject* go) override
{
    {
        switch (go->GetEntry())
        {
        case GO_Objects_Dusty_Cache_of_Ancient_Treasure:
            Dusty_Cache_of_Ancient_Treasure = go->GetGUID();
            break;
        }
    }
};

void OnGameObjectCreate(GameObject* go) override
{
    {
        switch (go->GetEntry())
        {
        case GO_Objects_Haunted_Urn:
            Haunted_Urn = go->GetGUID();
            break;
        }
    }
};

void OnGameObjectCreate(GameObject* go) override
{ 
    {
       swich (go->GetEntry())
       {
        case GO_Objects_Snow_Patch:
            Snow_Patch = go->GetGUID();
            break;
        }
    }
};
