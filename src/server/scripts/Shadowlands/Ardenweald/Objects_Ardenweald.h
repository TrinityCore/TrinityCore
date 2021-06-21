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
#include "instance_de_other_side.cpp"
#include "zone_De_Other_Side.cpp"
#include "zone_De_Other_Side.h"
#include "npc_De_Other_Side.h"
#include "Objects_De_Other_Side.h"
#include "De_Other_Side.h"
#include "boss_dealer_xyexa.cpp"
#include "boss_hakkar_the_soulflayer_os.cpp"
#include "boss_muehzala.cpp"
#include "boss_the_manastorms.cpp"
#include "Heart_Of_The_Forest.cpp"
#include "zone_Heart_Of_The_Forest.cpp"
#include "zone_Heart_Of_The_Forest.h"
#include "npc_Heart_Of_The_Forest.h"
#include "Objects_Heart_Of_The_Forest.h"
#include "instance_mists_of_tirna_scithe.cpp"
#include "zone_mists_of_tirna_scithe.cpp"
#include "zone_mists_of_tirna_scithe.h"
#include "Objects_Mist_Of_Tirna_Scithe.h"
#include "npc_Mist_Of_Tirna_Scthithe.h"
#include "Boss_Ingra _Maloch.cpp"
#include "Boss_Mistcaller.cpp"
#include "Boss_Tred_ova.cpp"
#include "Ardenweald.cpp"
#include "zone_Ardenweald.cpp"
#include "zone_Ardenweald.h"
#include "npc_Ardenweald.cpp"
#include "AddSC_npc_Data_Ardenweald.h"

enum ObjectList
{
    Objects_A_Faintly_Glowing_Seed = "A Faintly Glowing Seed"
    Objects_A_Secret_Never_Spoken = "A Secret Never Spoken"
    Objects_Abandoned_Memento = "Abandoned Memento"
    Objects_Ancient_Cloudfeather_Egg = "Ancient Cloudfeather Egg"
    Objects_Animacone = "Animacone"
    Objects_Animacone_Basket = "Animacone Basket"
    Objects_Anvil = "Anvil"
    Objects_Ardenmoth_Cocoon = "Ardenmoth Cocoon"
    Objects_Aromatic_Flowers = "Aromatic Flowers"
    Objects_Basket_of_Enchanted_Wings = "Basket of Enchanted Wings"
    Objects_Battered_Journal = "Battered Journal"
    Objects_Broken_Harp = "Broken Harp"
    Objects_Broken_Spear = "Broken Spear"
    Objects_Burried_Cache = "Burried Cache"
    Objects_Cache_of_the_Moon = "Cache of the Moon"
    Objects_Cache_of_the_Night = "Cache of the Night"
    Objects_Collector = "Collector"
    Objects_Cracked_Soulweb = "Cracked Soulweb"
    Objects_Cracked_Vertosol = "Cracked Vertosol"
    Objects_Crafters_Basket = "Crafter's Basket"
    Objects_Crumpled_Journal_Page = "Crumpled Journal Page"
    Objects_Damp_Loam = "Damp Loam"
    Objects_Darkreach_Supplies = "Darkreach Supplies"
    Objects_Death_Blossom = "Death Blossom"
    Objects_Decayed_Husk = "Decayed Husk"
    Objects_Depleted_Wildseed = "Depleted Wildseed"
    Objects_Diary_of_the_Night = "Diary of the Night"
    Objects_Dim_Lunarlight_Pod = "Dim Lunarlight Pod"
    Objects_Discarded_Harp = "Discarded Harp"
    Objects_Discarded_Scroll = "Discarded Scroll"
    Objects_Drained_Animacone_Cluster = "Drained Animacone Cluster"
    Objects_Drained_Wildseed = "Drained Wildseed"
    Objects_Dreamsong_Heart = "Dreamsong Heart"
    Objects_Elethium_Deposit = "Elethium Deposit"
    Objects_Elusive_Faerie_Cache = "Elusive Faerie Cache"
    Objects_Enchanted_Bough = "Enchanted Bough"
    Objects_Enchanted_Cage = "Enchanted Cage"
    Objects_Enchanted_Chest = "Enchanted Chest"
    Objects_Enchanted_Dreamcatcher = "Enchanted Dreamcatcher"
    Objects_Expended_Wildseed = "Expended Wildseed"
    Objects_Extra_Gooey_Gorm_Gunk = "Extra Gooey Gorm Gunk"
    Objects_Fae_Basket = "Fae Basket"
    Objects_Fae_Flute = "Fae Flute"
    Objects_Fae_Ornament = "Fae Ornament"
    Objects_Faerie_Belongings = "Faerie Belongings"
    Objects_Faerie_Stash = "Faerie Stash"
    Objects_Faerie_Trove = "Faerie Trove"
    Objects_Forge = "Forge"
    Objects_Fresh_Ardenweald_Anima = "Fresh Ardenweald Anima"
    Objects_Freshleaf = "Freshleaf"
    Objects_Frilled_Filtershroom = "Frilled Filtershroom"
    Objects_Gardeners_Basket = "Gardener's Basket"
    Objects_Gardeners_Flute = "Gardener's Flute"
    Objects_Gardeners_Hammer = "Gardener's Hammer"
    Objects_Gardeners_Wand = "Gardener's Wand"
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
}   

enum Objects
{
	Object_A_Faintly_Glowing_Seed     = 364345,
	Objects_A_Secret_Never_Spoken     = 344607,
    Objects_Abandoned_Memento         = 339996,339997,339998,
    Objects_Ancient_Cloudfeather_Egg  = 354646,
    Objects_Animacone                 = 336906,349512,353874,
    Objects_Animacone_Basket          = 352628,
    Objects_Anvil                     = 192628,
    Objects_Ardenmoth_Cocoon          = 352047,
    Objects_Aromatic_Flowers          = 355271,
    Objects_Basket_of_Enchanted_Wings = 349383,
    Objects_Battered_Journal          = 349515,
    Objects_Broken_Harp               = 350804,
    Objects_Broken_Spear              = 357726,
    Objects_Burried_Cache             = 357771,
    Objects_Cache_of_the_Moon         = 355041,
    Objects_Cache_of_the_Night        = 355000,
    Objects_Collector                 = 357729,
    Objects_Cracked_Soulweb           = 355800,
    Objects_Cracked_Vertosol          = 358528,
    Objects_Crafters_Basket           = 356878, 
    Objects_Crumpled_Journal_Page     = 339340,
    Objects_Damp_Loam                 = 344732,
    Objects_Darkreach_Supplies        = 354648,
    Objects_Death_Blossom             = 336686,
    Objects_Decayed_Husk              = 353306,353323,353324,353326,353327,
    Objects_Depleted_Wildseed         = 337092,364332,
    Objects_Diary_of_the_Night        = 355216,
    Objects_Dim_Lunarlight_Pod        = 353769,353770,353771,353772,353773,356821,
    Objects_Discarded_Harp            = 351425,
    Objects_Discarded_Scroll          = 336415,
    Objects_Drained_Animacone_Cluster = 340448,
    Objects_Drained_Wildseed          = 353152,
    Objects_Dreamsong_Heart           = 354650,
    Objects_Elethium_Deposit          = 349900,
    Objects_Elusive_Faerie_Cache      = 354662,
    Objects_Enchanted_Bough           = 355020,
    Objects_Enchanted_Cage            = 339319,
    Objects_Enchanted_Chest           = 353233,
    Objects_Enchanted_Dreamcatcher    = 354651,
    Objects_Expended_Wildseed         = 340664,
    Objects_Extra_Gooey_Gorm_Gunk     = 358572,
    Objects_Fae_Basket                = 353680,353751,353763,353765,
    Objects_Fae_Flute                 = 357148,357519,
    Objects_Fae_Ornament              = 355021,
    Objects_Faerie_Belongings         = 339514,
    Objects_Faerie_Stash              = 353329,353330,353331,353332,353333,
    Objects_Faerie_Trove              = 354652,
    Objects_Forge                     = 1685,
    Objects_Fresh_Ardenweald_Anima    = 357336,
    Objects_Freshleaf                 = 338681,
    Objects_Frilled_Filtershroom      = 355805,
    Objects_Gardeners_Basket          = 355212,
    Objects_Gardeners_Flute           = 355215,
    Objects_Gardeners_Hammer          = 355211,
    Objects_Gardeners_Wand            = 355214,
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
    Objects_
};

enum map
{
	std::map<key, value> map;
};