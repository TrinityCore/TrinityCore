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
#include "GameObject.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "TaskScheduler.h"
#include "TemporarySummon.h"
#include "GameObjectAI.h"
#include "zone_Sanctum_of_Domination.h"

enum Objects
{
    Anvil = 192628,
    Domination-Etched Treasure Cache = 369898,
    Gold_Coins = 235985,
    Snow_Patch = 358375,
    Xyraths_Booby-Trapped Cache = 375536,
};

enum Quests
{
    Blingtron_7000 = 56042,
    Owlcat Soul = 62432,
    Sanctum of Domination_N - Damned If You Dont = 64597,
    Sanctum of Domination - Damned If You Dont_H = 64598,
    Sanctum of Domination - Damned If You Dont_M = 64599,
    Storming the Sanctum = 63903,
};

enum Loot
{
    Soothsayers_Runes = 71716,
    Owlcat_Soul = 182177,
    Runekeepers_Ingot = 187175,
};

enum Achievements 
{
    // Guild achievements
    Hall_of_Fame: Sylvanas_A = 15197,
    Hall_of_Fame: Sylvanas_H = 15196,
    Heroic: Sanctum_of_Domination_Guild_Run = 15183,
    Mythic: Sanctum_of_Domination_Guild_Run = 15184,
    Sanctum_of_Domination_Guild_Run = 15182,
    // Character Achievements
    Ahead_of_the_Curve: Sylvanas_Windrunner = 15134,
    Coming_to_Terms = 15399,
    Cutting_Edge: Sylvanas_Windrunner = 15135,
    Eye_Wish_You_Were_Here = 15065,
    Fate_of_Domination = 15667,
    Flawless_Fate = 15040,
    Heroic: Fate_of_Domination = 15668,
    Heroic: Sanctum_of_Domination = 15127,
    I_Used_to_Bullseye_Deeprun_Rats_Back_Home = 15058,
    Knowledge_is_Power = 15132,
    Mythic: Fate_of_Domination = 15669,
    Mythic: Fatescribe_Roh-Kalo = 15119,
    Mythic: Guardian of the First Ones = 15118,
    Mythic: KelThuzad = 15120,
    Mythic: Painsmith Raznal = 15117,
    Mythic: Remnant of Nerzhul = 15115,
    Mythic: Sanctum of Domination = 15128,
    Mythic: Soulrender Dormazain = 15116,
    Mythic: Sylvanas Windrunner = 15121,
    Mythic: The Eye of the Jailer = 15113,
    Mythic: The Nine = 15114,
    Mythic: The Tarragrue = 15112,
    Name A Better Duo, I_ll Wait = 14998,
    Sanctum of Domination = 15126,
    Shackles of Fate = 15124,
    The Dark Bastille = 15123,
    The Jailers Vanguard = 15122,
    The Reckoning = 15125,
    This World is a Prism = 15133,
    To the Nines = 15003,
    Together Forever = 15108,
    Tormentors Tango = 15105,
    Whack-A-Soul = 15131,
};

enum Sanctum_Of_Domination
{
    Remnant_of_ner_zhul                = 175729,
    Painsmith_raznal                   = 176523,
    Kyra                               = 178738,
    Kel_Thuzad                         = 175559,
    guardian_of_the_first_ones         = 175731,
    Fatescribe_Roh_kalo                = 179390,
    eye_of_the_jailer                  = 180018,
    the_tarragrue                      = 152253,
    Soulrender_Dormazain               = 175727,
    Sylvanas_Windrunner                = 175732,
    Acrobatic_Steward                  = 175588,
    Agatha                             = 177096,
    Ancient_Gazelle                    = 151847,
    Ancient_Kodo                       = 151843,
    Ancient_Plainstrider               = 151844,
    Ancient_Swoop                      = 151846,
    Anduin_Wrynn                       = 178072,
    Annhylde                           = 177097,
    Annoying_Construct                 = 170165,
    Aradne                             = 177100,
    Arthura                            = 177098,
    Ashen_Phylactery                   = 178523,
    Blingtron_7000                     = 153897,
    Bonesteel                          = 178731,
    Borr-Gahn                          = 178824,
    Bound_Soul_Remnant                 = 178629,
    Brigade_Member                     = 148048,
    Brynja                             = 177101,
    Burning_Shade                      = 179257,
    Burning_Soul                       = 177613,
    Burning_Stygia                     = 178851,
    Buttons                            = 178763,
    Buttons_0                          = 178782,
    Caged_Soul_Remnant                 = 180758,
    Chaotic_Essence                    = 189706,
    Chaotic_Mote                       = 189707,
    Collector_Unta                     = 142666,
    Condemned_Soul_Remnant             = 180385,
    Consumed_Soul                      = 180782,
    Cranky_Crab                        = 149189,
    Curious_Squirrel                   = 93997,
    Dark_Sentinel                      = 176404,
    Daschla                            = 177099,
    Deathseeker_Eye                    = 176531,
    Deathseeker_Eye_1                  = 179894,
    Deathseeker_Eye_2                  = 179942,
    Deathseeker_Husk                   = 178729,
    Decrepit_Orb                       = 178008,
    Domination_Arrow                   = 176920,
    Doomguard                          = 168932,
    Dreadmaw                           = 180780,
    Ebon_Blade_Acolyte                 = 181133,
    Ethereal_Transmorpher              = 149596,
    Experimental_Slime                 = 175647,
    Eye_of_the_Jailer                  = 175725,
    Fatescribe_Roh-Kalo                = 175730,
    Fatespawn_Anomaly                  = 179010,
    Fatespawn_Monstrosity              = 180323,
    Feeding_Horror                     = 180426,
    Felguard                           = 169421,
    Felhound                           = 169425,
    Formless_Mass                      = 177407,
    Frostbound_Devoted                 = 176703, 
    Gibbering_Soul                     = 180665,
    Glacial_Spike                      = 175861,
    Gorgoan_Sentinel                   = 180407,
    Gormling                           = 175665,
    Gravid_Devourer_Mite               = 175692,
    Helm_of_Suffering                  = 177268,
    High_Inquisitor_Whitemane          = 178613,
    Highlord_Bolvar_Fordragon          = 178081,
    Highlord_Darion_Mograine           = 178615,
    Hollowsoul                         = 176879,
    Infernal                           = 169426,
    Infused_Goliath                    = 176535,
    Infused_Goliath_1                  = 176536,
    Infused_Goliath_2                  = 176537,
    Infused_Goliath_3                  = 176538,
    Innocent_Soul                      = 180501,
    KelThuzad_1                        = 180384,
    Knight_of_the_Ebon_Blade           = 178616,
    Kyra_1                             = 177095,
    Lady_Jaina_Proudmoore              = 176533,
    Lady_Jaina_Proudmoore_1            = 179152,
    Loom_Artificer                     = 180417,
    Loom_Guardian                      = 180427,
    Maw_Assassin                       = 178071,
    Mawforged_Colossus                 = 177893,
    Mawforged_Goliath                  = 177892,
    Mawforged_Souljudge                = 177889,
    Mawforged_Summoner                 = 177891,
    Mawrat                             = 178626,
    Mawsworn_Agonizer                  = 177594,
    Mawsworn_Arbalest                  = 180379,
    Mawsworn_Archer                    = 178625,                   
    Mawsworn_Axeguard                  = 180415,
    Mawsworn_Commander                 = 178631,
    Mawsworn_Darkcaster                = 178628,
    Mawsworn_Destructor                = 178445,
    Mawsworn_Embermage                 = 176949,
    Mawsworn_Flamehand                 = 176953,
    Mawsworn_Guard                     = 178623,
    Mawsworn_Hopebreaker               = 177787,
    Mawsworn_Husk                      = 178734,
    Mawsworn_Infuser                   = 180664,
    Mawsworn_Interceptor               = 178661,
    Mawsworn Lancer                    = 178043,
    

    //
   // QUEST_DAMNED_IF_YOU_DONT           = 64597,64598,
   // QUEST_STORMING_THE_SANCTUM         = 63903,

    AREA_SANCTUM_OF_DOMINATION         = 13561,
};

//178592
struct npc_Highlord_Bolvar_Fordragon_178592 : public ScriptedAI
{
    npc_Highlord_Bolvar_Fordragon_178592(Creature* creature) : ScriptedAI(creature) { }

    void OnClick(Unit* clicker, bool& /*result*/) override
    {
        if (Player* player) = GetQuest(64597);
        return;
        if (Player* player) = GetQuest(64598);
        return;
        if (Player* player) = GetQuest(63903);
        return;
        if (Player* player = clicker->npc_Highlord_Bolvar_Fordragon_178592())
        {
            if (player->GetQuestStatus(QUEST_DAMNED_IF_YOU_DONT) == QUEST_STATUS_INCOMPLETE)
            {
                clicker->ToPlayer()->Phylactery_Shard(187529);
                me->CollectItem(ITEM_PHYLACTERY_SHARD);
                PHYLACTERY_SHARD->npc_kelthuzad_175559;
                {
                    if (me && player)
                    {
                        player->KilledNpc_kelthuzad_175559(175559);
                        player->Loot(187529)->Npc_kelthuzad_175559();
                    };
                };
            }
            if (player->GetQuestStatus(QUEST_DAMNED_IF_YOU_DONT) == QUEST_STATUS_COMPLETE)
            {
                if (me && player)    
                {
                    player->GetLoot(187529) = 4;
                }
            }    
        }
    }
private:
    TaskScheduler _scheduler;
    std::unordered_set<uint32> _randomEmotes;
};

class zone_Sanctum_of_Domination : public ZoneScript
{    

    Sanctum_of_Domination() : ZoneScript(Sanctum_of_Domination) { }

    void OnPlayerExit(Player* player) override
    {
        // Remove sanctuary flag when leaving sanctum of domination
        player->GoOutside(sanctum_of_domination);
    }
    void OnPlayerEnter(Player* player) override
    {
        // Add sanctuary flag when enter on sanctum of domination
        player=>GoInside(sanctum_of_domination);
    };
};
 
struct zone_Sanctum_of_Domination : public InstanceScript
{
    Sanctum_of_Domination(InstanceMap* map) : InstanceScript(map, Sanctum_of_Domination) { }
};
 
void AddSC_Sanctum_of_Domination()
{
    void AddSC_Sanctum_of_Domination();
};

void sanctum_of_domination::AddSC_Sanctum_of_Domination()
{
}
