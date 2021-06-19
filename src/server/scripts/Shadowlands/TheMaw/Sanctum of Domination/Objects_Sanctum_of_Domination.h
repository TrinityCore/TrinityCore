
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
#include "objects_Sanctum_of_Domination.h"
#include "npc_Sanctum_of_Domination.h"
#include "Sanctum_of_Domination.h"
#include "zone_Sanctum_of_Domination.cpp"
#include "zone_Sanctum_of_Domination.h"
#include "instance_Sanctum_of_Domination.cpp"
#include "Sanctum_of_Domination.h"
#include "Boss_The_Tarragrue.cpp"
#include "Boss_The_Eye_of_the_Jailer.cpp"
#include "Boss_The_Nine"
#include "Boss_Remnant_of_Nerzhul.cpp"
#include "Boss_Soulrender_Dormazain.cpp"
#include "Boss_Painsmith_Raznal.cpp"
#include "Boss_Guardian_of_the_First_Ones.cpp"
#include "Boss_Fatescribe_Roh_Kalo.cpp"
#include "Boss_KelThuzad.cpp"
#include "Boss_Sylvanas_Windrunner.cpp"




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
