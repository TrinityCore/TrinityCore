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
    Objects_
};

enum map
{
	std::map<key, value> map;
};