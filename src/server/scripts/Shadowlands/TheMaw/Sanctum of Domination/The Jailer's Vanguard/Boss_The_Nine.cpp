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
};    

enum NPC_list
{
    NPC_Boss_Kyra = 178738,
    NPC_Boss_Signe = 177094,
    NPC_Boss_Skyja = 175726,
    Formless_Mass = 177407,    
};

enum Spells
{
	//npc kyra
    Wings_of_Rage = 350365,
    //npc Signe
    Reverberating_Refrain = 350385,
    //npc Skyja
    Fragments_of_Destiny =  350541,
    //Phase_1
    Unending_Strike = 350202,
    //Phase_2
    Pierce_Soul = 350475,
    Song_of_Dissolution = 350287,
    Siphon_Vitality = 350339, //Formless_Mass
    Call_of_the_Valkyr = 350467,
    Agathas_Eternal_Blade = 350031,
    Daschlas_Mighty_Impact = 350184,
    Annhyldes_Bright_Aegis = 350157,
    Aradnes_Falling_Strike = 350098,
    Brynjas_Mournful_Dirge = 350109,
    Arthuras_Crushing_Gaze = 350039,
    Link_Essence = 350482, //hc
    Aradnes_Falling_Strike = 350098, //hc
    Word_of_Recall = 350687, //hc
    Call_of_the_Valkyr = 350467,

};

enum NPC_loot
{
    Deadly_Chain = 182657,
};

enum sounds
{
    MON_KyrianMaw_Attack_00_183035 = 183035.
};

struct NPC_Boss_Kyra : public InstanceScript
{
    sanctum_of_domination(InstanceMap* map) : InstanceScript(map) { }
}; 

class NPC_Boss_Kyra : public PlayerScript
{
public:
    NPC_Boss_Kyra() : PlayerScript("NPC_Boss_Kyra") { }

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

class NPC_Boss_Kyra : public ZoneScript
{
public:
    NPC_Boss_Kyra() : ZoneScript("NPC_Boss_Kyra") { }

    void OnPlayerExit(Player* player) override
    {
        // Remove sanctuary flag when leaving sanctum of domination
        player->GoOutside(NPC_Boss_Kyra);
    }
};
    
struct NPC_Boss_Signe : public InstanceScript
{
    sanctum_of_domination(InstanceMap* map) : InstanceScript(map) { }
}; 

class NPC_Boss_Signe : public PlayerScript
{
public:
    NPC_Boss_Signe() : PlayerScript("NPC_Boss_Signe") { }

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

class NPC_Boss_Signe : public ZoneScript
{
public:
    NPC_Boss_Signe() : ZoneScript("NPC_Boss_Signe") { }

    void OnPlayerExit(Player* player) override
    {
        // Remove sanctuary flag when leaving sanctum of domination
        player->GoOutside(NPC_Boss_Signe);
    }
};

class NPC_Boss_Skyja : public ZoneScript
{
public:
    NPC_Boss_Skyja() : ZoneScript("NPC_Boss_Skyja") { }

    void OnPlayerExit(Player* player) override
    {
        // Remove sanctuary flag when leaving sanctum of domination
        player->GoOutside(NPC_Boss_Skyja);
    }
};
    
struct NPC_Boss_Skyja : public InstanceScript
{
    sanctum_of_domination(InstanceMap* map) : InstanceScript(map) { }
}; 

class NPC_Boss_Skyja : public PlayerScript
{
public:
    NPC_Boss_Skyja() : PlayerScript("NPC_Boss_Skyja") { }

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

class NPC_Boss_Skyja : public ZoneScript
{
public:
    NPC_Boss_Skyja() : ZoneScript("NPC_Boss_Skyja") { }

    void OnPlayerExit(Player* player) override
    {
        // Remove sanctuary flag when leaving sanctum of domination
        player->GoOutside(NPC_Boss_Skyja);
    }
};

struct Formless_Mass : public InstanceScript
{
    sanctum_of_domination(InstanceMap* map) : InstanceScript(map) { }
}; 

class Formless_Mass : public PlayerScript
{
public:
    Formless_Mass() : PlayerScript("Formless_Mass") { }

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

class Formless_Mass : public ZoneScript
{
public:
    Formless_Mass() : ZoneScript("Formless_Mass") { }

    void OnPlayerExit(Player* player) override
    {
        // Remove sanctuary flag when leaving sanctum of domination
        player->GoOutside(Formless_Mass);
    }
};       
 
struct NPC_Boss_Kyra : public BossAI
{
   NPC_Boss_Kyrar(Creature* creature) BossAI(creature, DATA_NPC_Boss_Kyra) { }
};

struct NPC_Boss_Signe : public BossAI
{
   NPC_Boss_Signe(Creature* creature) BossAI(creature, DATA_NPC_Boss_Signe) { }
};

struct NPC_Boss_Skyja : public BossAI
{
   NPC_Boss_Skyja(Creature* creature) BossAI(creature, DATA_NPC_Boss_Skyja) { }
};

{
void AddSC_NPC_Boss_Kyra(),
void AddSC_NPC_Boss_Signe(),
void NPC_Boss_Skyja(),
void Formless_Mass(),
};


