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
SDName: Boss_Eye_of_the_jailer
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
//#include "zone_the_maw.cpp"
//#include "zone_Sanctum_of_Domination.cpp"

enum Phases
{
    Phase_1,
    Phase_2,
    Phase_3,
};    

enum NPC_list
{
    NPC_Boss_Eye_of_the_Jailer = 180018,
    NPC_Deathseeker_Eye = 179942, // N mode
    NPC_Stygian_Abductor = 176521, // hc mode
    
};

enum Spells
{
    Fractured_Soul = 350034,
    Annihilating_Glare = 350763,
    Desolation_Beam = 350847.
    Spreading_Misery = 350816,
    Jailers_Misery = 350808,
    Deathlink = 350828,
    Suffering = 351826,
    Slothful_Corruption = 350713,
    Titanic_Death_Gaze = 349028,
    Immediate_Extermination = 348969,
    Piercing_Lens = 350803,
    Dragging_Chains = 349979. //hc
    Assailing_Lance = 348074, //hc
};

enum NPC_loot
{
    Artifice_of_the_Archmage = 181738,
};

enum sounds
{
    MON_Crucible_Soulseeker_Attack_01_174592 = 176548.
};

struct NPC_Boss_Eye_of_the_Jailer : public InstanceScript
{
    sanctum_of_domination(InstanceMap* map) : InstanceScript(map) { }
}; 

class NPC_Boss_Eye_of_the_Jailer : public PlayerScript
{
public:
    NPC_Boss_Eye_of_the_Jailer() : PlayerScript("NPC_Boss_Eye_of_the_Jailer") { }

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

class NPC_Boss_Eye_of_the_Jailer : public ZoneScript
{
public:
    NPC_Boss_Eye_of_the_Jailer() : ZoneScript("NPC_Boss_Eye_of_the_Jailer") { }

    void OnPlayerExit(Player* player) override
    {
        // Remove sanctuary flag when leaving sanctum of domination
        player->GoOutside(NPC_Boss_Eye_of_the_Jailer);
    }
};
    
struct NPC_Deathseeker_Eye : public InstanceScript
{
    sanctum_of_domination(InstanceMap* map) : InstanceScript(map) { }
}; 

class NPC_Deathseeker_Eye : public PlayerScript
{
public:
    NPC_Deathseeker_Eye() : PlayerScript("NPC_Deathseeker_Eye") { }

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

class NPC_Deathseeker_Eye : public ZoneScript
{
public:
    NPC_Deathseeker_Eye() : ZoneScript("NPC_Deathseeker_Eye") { }

    void OnPlayerExit(Player* player) override
    {
        // Remove sanctuary flag when leaving sanctum of domination
        player->GoOutside(NPC_Deathseeker_Eye);
    }
};

class NPC_Stygian_Abductor : public ZoneScript
{
public:
    NPC_Stygian_Abductor() : ZoneScript("NPC_Stygian_Abductor") { }

    void OnPlayerExit(Player* player) override
    {
        // Remove sanctuary flag when leaving sanctum of domination
        player->GoOutside(NPC_Stygian_Abductor);
    }
};
    
struct NPC_Stygian_Abductor : public InstanceScript
{
    sanctum_of_domination(InstanceMap* map) : InstanceScript(map) { }
}; 

class NPC_Stygian_Abductor : public PlayerScript
{
public:
    NPC_Stygian_Abductor() : PlayerScript("NPC_Stygian_Abductor") { }

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

class NPC_Stygian_Abductor : public ZoneScript
{
public:
    NPC_Stygian_Abductor() : ZoneScript("NPC_Stygian_Abductor") { }

    void OnPlayerExit(Player* player) override
    {
        // Remove sanctuary flag when leaving sanctum of domination
        player->GoOutside(NPC_Stygian_Abductor);
    }
};       
 
struct NPC_Boss_Eye_of_the_Jailer : public BossAI
{
   NPC_Boss_Eye_of_the_Jailer(Creature* creature) BossAI(creature, DATA_NPC_Boss_Eye_of_the_Jailer) { }
};

struct NPC_Deathseeker_Eye : public BossAI
{
   NPC_Deathseeker_Eye(Creature* creature) BossAI(creature, DATA_NPC_Deathseeker_Eye) { }
};

struct NPC_Stygian_Abductor : public BossAI
{
   NPC_Stygian_Abductor(Creature* creature) BossAI(creature, DATA_NPC_Stygian_Abductor) { }
};

{
void AddSC_NPC_Boss_Eye_of_the_Jailer(),
void AddSC_NPC_Deathseeker_Eye(),
void AddSC_NPC_Stygian_Abductor(),
};