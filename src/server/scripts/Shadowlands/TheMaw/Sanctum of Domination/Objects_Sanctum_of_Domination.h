/* 
 * Copyright 2021 Frozen
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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "Map.h"
#include "InstanceScript.h"
#include "Transport.h"
#include "TransportMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "zone_the_maw.cpp"
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
    Objects_unu = 0,
    Objects_doi = 0,
    Objects_trei = 0,
    Objects_patru = 0,
    Objects_cinci = 0,
    Objects_sase = 0,
}   

void Objects_unu
ObjectGuid unu;

void Objects_doi
ObjectGuid doi;

void Objects_trei
ObjectGuid trei;

void Objects_patru
ObjectGuid patru;

void Objects_cinci
ObjectGuid cinci;

void Objects_sase
ObjectGuid sase;

void OnGameObjectCreate(GameObject* go) override
{
    {
        switch (go->GetEntry())
        {
        case GO_Objects_unu:
            unu = go->GetGUID();
            break;
        }
    }
};

void OnGameObjectCreate(GameObject* go) override
{
    {
        switch (go->GetEntry())
        {
        case GO_Objects_doi:
            doi = go->GetGUID();
            break;
        }
    }
};

void OnGameObjectCreate(GameObject* go) override
{
    {
        switch (go->GetEntry())
        {
        case GO_Objects_trei:
            trei = go->GetGUID();
            break;
        }
    }
};

void OnGameObjectCreate(GameObject* go) override
{
    {
        switch (go->GetEntry())
        {
        case GO_Objects_patru:
            patru = go->GetGUID();
            break;
        }
    }
};

void OnGameObjectCreate(GameObject* go) override
{
    {
        switch (go->GetEntry())
        {
        case GO_Objects_cinci:
            cinci = go->GetGUID();
            break;
        }
    }
};

void OnGameObjectCreate(GameObject* go) override
{ 
    {
       swich (go->GetEntry())
       {
        case GO_Objects_sase:
            sase = go->GetGUID();
            break;
        }
    }
};
