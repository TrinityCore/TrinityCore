/*
 * Copyright 2021 
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
#include "instance_instance_necrotic_wake.cpp"
#include "necrotic_wake.cpp"
#include "necrotic_wake.h"
#include "boss_amarth.cpp"
#include "boss_blightbone.cpp"
#include "boss_nalthor.cpp"
#include "boss_surgeon_stitchflesh.cpp"
#include "instance_spires_of_ascension.cpp"
#include "spires_of_ascension.h"
#include "boss_devos.cpp"
#include "boss_kintara.cpp"
#include "boss_oryphrion.cpp"
#include "boss_ventunax.cpp"
#include "zone_zone_Bastion.cpp"
#include "zone_zone_Bastion.h"
#include "Objects_Bastion.h"
#include "npc_Bastion.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "NpcObject.h"
#include "NpcObjectAI.h"
#include "SpellAuraEffects.h"

enum Objects
{
    Objects_Abandoned_Stockpile                           = 354202,
    Objects_Acolytes_Spear                                = 361261,
    Objects_Adrimas_Lily                                  = 336680,363992,
    Objects_Aged_Windcheese                               = 357333,
    Objects_Agthian_Spear                                 = 336444,
    Objects_Ancient_Memorial                              = 353807,
    Objects_Anima_Canister                                = 349706,
    Objects_Anima_Conflux                                 = 349976,

}   

void Objects_Abandoned_Stockpile 
ObjectGuid Abandoned_Stockpile;

void OnGameObjectCreate(GameObject* go) override
{
    {
        switch (go->GetEntry())
        {
        case GO_Objects_Abandoned_Stockpile:
            Abandoned_Stockpile = go->GetGUID();
            break;
        }
    }
};

