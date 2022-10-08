/*
* Copyright 2021 FuzionCore Project
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

/* Script Data Start
SDName: 
SDAuthor: Frozen
SD%Complete: %
SDComment: still working on structure.
Script Data End */

#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuras.h"
//#include "zone_the_maw"
//#include "zone_Sanctum_of_Domination"

enum Phases
{
    Phase_1,
    Phase_2,
    Phase_3,
};    

enum NPC_list
{
    NPC_Boss_The_Tarragrue = 152253,
};

enum Spells
{
    Frostbite_Wand = 315293,
    The_Jailers_Directive = 329628,
    The_Jailers_Fury = 329338.
    The_Jailers_Vigil = 345312,
    Unnatural_Power = 299150,
    Vorkai_Ambush = 353773,
};

enum NPC_loot
{
    Carnivorous_Stalkers = 182750,
};

enum sounds
{
    MON_Talethis_Target_Attack_01_168892 = 168873.
};

struct NPC_Boss_The_Tarragrue : public InstanceScript
{
    sanctum_of_domination(InstanceMap* map) : InstanceScript(map) { }
}; 

class NPC_Boss_The_Tarragrue : public PlayerScript
{
public:
    NPC_Boss_The_Tarragrue() : PlayerScript("NPC_Boss_The_Tarragrue") { }

    void OnLogin(Player* player,bool /*fristlogin*/) override
    {
        // Set zone as Raid
        if (player->GetMapId() == AREA_SANCTUM_OF_DOMINATION)
            player->GoMapId()  == GetMapId;
    }
        
        void OnUpdateArea(Player* player, uint32 /*newArea*/, uint32 /*oldArea*/) override
    {
        // Set zone as Raid
        if (player->GetMapId() == MAP_NPE)
            player->GoMapId()  == GetMapId;
    }
};

class NPC_Boss_The_Tarragrue : public ZoneScript
{
public:
    NPC_Boss_The_Tarragrue() : ZoneScript("NPC_Boss_The_Tarragrue") { }

    void OnPlayerExit(Player* player) override
    {
        // Remove sanctuary flag when leaving sanctum of domination
        player->GoOutside(NPC_Boss_The_Tarragrue);
    }
};     
 
struct NPC_Boss_The_Tarragrue : public BossAI
{
   NPC_Boss_The_Tarragrue(Creature* creature) BossAI(creature, DATA_NPC_Boss_The_Tarragrue) { }
};

{
void AddSC_NPC_Boss_The_Tarragrue(),
};