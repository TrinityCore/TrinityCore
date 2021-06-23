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
#include "GameObjectAI.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "LootMgr.h"
#include "QuestDef.h"

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
    Objects_Giggling_Basket = "Giggling Basket"
    Objects_Gorm_Giblet = "Gorm Giblet"
    Objects_Gorm_Gris = "Gorm Gris"
    Objects_Gossamer_Thread = "Gossamer Thread"
    Objects_Harmonic_Chest = "Harmonic Chest"
    Objects_Heart_of_Tirna_Noch = "Heart of Tirna Noch"
    Objects_Hearty_Dragon_Plume = "Hearty Dragon Plume"
    Objects_Heavy_Heartshroom = "Heavy Heartshroom"
    Objects_Intact_Husk = "Intact Husk"
    Objects_Laestrite_Deposit = "Laestrite Deposit"
    Objects_Lambent_Vigils_Torch = "Lambent Vigil's Torch"
    Objects_Large_Lunarlight_Pod = "Large Lunarlight Pod"
    Objects_Large_Thistledrop = "Large Thistledrop"
    Objects_Ligneous_Phaedrum_Deposit = "Ligneous Phaedrum Deposit"
    Objects_Lost_Satchel = "Lost Satchel"
    Objects_Lunarlight_Pod = "Lunarlight Pod"
    Objects_Mailbox = "Mailbox"
    Objects_Marasmius = "Marasmius"
    Objects_Misty_Mindshroom = "Misty Mindshroom"
    Objects_Muddy_Scroll = "Muddy Scroll"
    Objects_Night_Lilly = "Night Lilly"
    Objects_Nightshade = "Nightshade"
    Objects_Nox_Root = "Nox Root"
    Objects_Phaedrum_Deposit = "Phaedrum Deposit"
    Objects_Pile_of_Loam = "Pile of Loam"
    Objects_Pulsing_Animacone = "Pulsing Animacone"
    Objects_Raw_Dream_Silk = "Raw Dream Silk"
    Objects_Raw_Silkstrider_Silk = "Raw Silkstrider Silk"
    Objects_Rich_Elethium_Deposit = "Rich Elethium Deposit"
    Objects_Rich_Laestrite_Deposit = "Rich Laestrite Deposit"
    Objects_Rich_Phaedrum_Deposit = "Rich Phaedrum Deposit"
    Objects_Rich_Topsoil = "Rich Topsoil"
    Objects_Ripened_Anima_Seed = "Ripened Anima Seed"
    Objects_Riverblossoms_Flute = "Riverblossom's Flute"
    Objects_Shimmerdust_Pile = "Shimmerdust Pile"
    Objects_Shimmering_Soil = "Shimmering Soil"
    Objects_Shriveled_Shrub = "Shriveled Shrub"
    Objects_Silverheart_Vines = "Silverheart Vines"
    Objects_Snickering_Basket = "Snickering Basket"
    Objects_Snow_Patch = "Snow Patch"
    Objects_Spriggan_Sized_Polearm = "Spriggan-Sized Polearm"
    Objects_Spriggan_Sized_Wand = "Spriggan-Sized Wand"
    Objects_Stained_Journal_Page = "Stained Journal Page"
    Objects_Supply_Baskets = "Supply Baskets"
    Objects_Suspiciously_Untouched_Basket = "Suspiciously Untouched Basket"
    Objects_Suspiciously_Untouched_Harp = "Suspiciously Untouched Harp"
    Objects_Suspiciously_Untouched_Soulweb = "Suspiciously Untouched Soulweb"
    Objects_Swollen_Anima_Seed = "Swollen Anima Seed"
    Objects_Thistledrop_Frond = "Thistledrop Frond"
    Objects_Thistledrop_Growth = "Thistledrop Growth"
    Objects_Torn_Journal_Page = "Torn Journal Page"
    Objects_Very_Large_Silk_Bundle = "Very Large Silk Bundle"
    Objects_Vessel_of_Ardenweald = "Vessel of Ardenweald"
    Objects_Vigils_Torch = "Vigil's Torch"
    Objects_Violet_Frill = "Violet Frill"
    Objects_Water_Bucket = "Water Bucket"
    Objects_Wreath_of_Nights_Veil_Flowers = "Wreath of Night's Veil Flowers"
};   

enum Objects
{
	Object_A_Faintly_Glowing_Seed          = 364345,
	Objects_A_Secret_Never_Spoken          = 344607,
    Objects_Abandoned_Memento              = 339996,339997,339998,
    Objects_Ancient_Cloudfeather_Egg       = 354646,
    Objects_Animacone                      = 336906,349512,353874,
    Objects_Animacone_Basket               = 352628,
    Objects_Anvil                          = 192628,
    Objects_Ardenmoth_Cocoon               = 352047,
    Objects_Aromatic_Flowers               = 355271,
    Objects_Basket_of_Enchanted_Wings      = 349383,
    Objects_Battered_Journal               = 349515,
    Objects_Broken_Harp                    = 350804,
    Objects_Broken_Spear                   = 357726,
    Objects_Burried_Cache                  = 357771,
    Objects_Cache_of_the_Moon              = 355041,
    Objects_Cache_of_the_Night             = 355000,
    Objects_Collector                      = 357729,
    Objects_Cracked_Soulweb                = 355800,
    Objects_Cracked_Vertosol               = 358528,
    Objects_Crafters_Basket                = 356878, 
    Objects_Crumpled_Journal_Page          = 339340,
    Objects_Damp_Loam                      = 344732,
    Objects_Darkreach_Supplies             = 354648,
    Objects_Death_Blossom                  = 336686,
    Objects_Decayed_Husk                   = 353306,353323,353324,353326,353327,
    Objects_Depleted_Wildseed              = 337092,364332,
    Objects_Diary_of_the_Night             = 355216,
    Objects_Dim_Lunarlight_Pod             = 353769,353770,353771,353772,353773,356821,
    Objects_Discarded_Harp                 = 351425,
    Objects_Discarded_Scroll               = 336415,
    Objects_Drained_Animacone_Cluster      = 340448,
    Objects_Drained_Wildseed               = 353152,
    Objects_Dreamsong_Heart                = 354650,
    Objects_Elethium_Deposit               = 349900,
    Objects_Elusive_Faerie_Cache           = 354662,
    Objects_Enchanted_Bough                = 355020,
    Objects_Enchanted_Cage                 = 339319,
    Objects_Enchanted_Chest                = 353233,
    Objects_Enchanted_Dreamcatcher         = 354651,
    Objects_Expended_Wildseed              = 340664,
    Objects_Extra_Gooey_Gorm_Gunk          = 358572,
    Objects_Fae_Basket                     = 353680,353751,353763,353765,
    Objects_Fae_Flute                      = 357148,357519,
    Objects_Fae_Ornament                   = 355021,
    Objects_Faerie_Belongings              = 339514,
    Objects_Faerie_Stash                   = 353329,353330,353331,353332,353333,
    Objects_Faerie_Trove                   = 354652,
    Objects_Forge                          = 1685,
    Objects_Fresh_Ardenweald_Anima         = 357336,
    Objects_Freshleaf                      = 338681,
    Objects_Frilled_Filtershroom           = 355805,
    Objects_Gardeners_Basket               = 355212,
    Objects_Gardeners_Flute                = 355215,
    Objects_Gardeners_Hammer               = 355211,
    Objects_Gardeners_Wand                 = 355214,
    Objects_Giggling_Basket                = 338492,
    Objects_Gorm_Giblet                    = 357417,
    Objects_Gorm_Gris                      = 338489,
    Objects_Gossamer_Thread                = 338682,
    Objects_Harmonic_Chest                 = 355355,
    Objects_Heart_of_Tirna_Noch            = 340028,
    Objects_Hearty_Dragon_Plume            = 354647,
    Objects_Heavy_Heartshroom              = 355804,
    Objects_Intact_Husk                    = 335776,
    Objects_Laestrite_Deposit              = 349898,
    Objects_Lambent_Vigils_Torch           = 356538,
    Objects_Large_Lunarlight_Pod           = 356820,
    Objects_Large_Thistledrop              = 357257,
    Objects_Ligneous_Phaedrum_Deposit      = 356400, 
    Objects_Lost_Satchel                   = 354645,
    Objects_Lunarlight_Pod                 = 353681,353683,353684,353685,353686,
    Objects_Mailbox                        = 32349,
    Objects_Marasmius                      = 334880,
    Objects_Misty_Mindshroom               = 355795,
    Objects_Muddy_Scroll                   = 348747,
    Objects_Night_Lilly                    = 357582,352058,358369,
    Objects_Nightshade                     = 336691,
    Objects_Nox_Root                       = 357710,
    Objects_Phaedrum_Deposit               = 349982,355508,
    Objects_Pile_of_Loam                   = 350997,
    Objects_Pulsing_Animacone              = 353194,
    Objects_Raw_Dream_Silk                 = 355019,
    Objects_Raw_Silkstrider_Silk           = 350886,
    Objects_Rich_Elethium_Deposit          = 350082,
    Objects_Rich_Laestrite_Deposit         = 349899,
    Objects_Rich_Phaedrum_Deposit          = 350087,355507,
    Objects_Rich_Topsoil                   = 358527,
    Objects_Ripened_Anima_Seed             = 348723,
    Objects_Riverblossoms_Flute            = 357727,
    Objects_Shimmerdust_Pile               = 338680,
    Objects_Shimmering_Soil                = 358526,
    Objects_Shriveled_Shrub                = 340449,
    Objects_Silverheart_Vines              = 355807,
    Objects_Snickering_Basket              = 352088,
    Objects_Snow_Patch                     = 358375,
    Objects_Spriggan_Sized_Polearm         = 352182,
    Objects_Spriggan_Sized_Wand            = 352181,
    Objects_Stained_Journal_Page           = 278825,
    Objects_Supply_Baskets                 = 352089,
    Objects_Suspiciously_Untouched_Basket  = 338493,
    Objects_Suspiciously_Untouched_Harp    = 338614,
    Objects_Suspiciously_Untouched_Soulweb = 338613,
    Objects_Swollen_Anima_Seed             = 354911,
    Objects_Thistledrop_Frond              = 357255,
    Objects_Thistledrop_Growth             = 357256,
    Objects_Torn_Journal_Page              = 339339,
    Objects_Very_Large_Silk_Bundle         = 351427,
    Objects_Vessel_of_Ardenweald           = 344608,
    Objects_Vigils_Torch                   = 336688,
    Objects_Violet_Frill                   = 356607,
    Objects_Water_Bucket                   = 338476,
    Objects_Wreath_of_Nights_Veil_Flowers  = 341814,
};

enum ObjectLoot
{
    Objects_Wreath_of_Nights_Veil_Flowers;
}

enum map
{
	std::map<key, value> map;
};

void AddSC_npc_Ardenweald() 
{
  RegisterObjectsAI(Object_A_Faintly_Glowing_Seed);
  RegisterObjectsAI(Objects_A_Secret_Never_Spoken);         
  RegisterObjectsAI(Objects_Abandoned_Memento);              
  RegisterObjectsAI(Objects_Ancient_Cloudfeather_Egg);       
  RegisterObjectsAI(Objects_Animacone);                      
  RegisterObjectsAI(Objects_Animacone_Basket);               
  RegisterObjectsAI(Objects_Anvil);                         
  RegisterObjectsAI(Objects_Ardenmoth_Cocoon);               
  RegisterObjectsAI(Objects_Aromatic_Flowers);              
  RegisterObjectsAI(Objects_Basket_of_Enchanted_Wings);      
  RegisterObjectsAI(Objects_Battered_Journal);               
  RegisterObjectsAI(Objects_Broken_Harp);                    
  RegisterObjectsAI(Objects_Broken_Spear);                   
  RegisterObjectsAI(Objects_Burried_Cache);                
  RegisterObjectsAI(Objects_Cache_of_the_Moon);              
  RegisterObjectsAI(Objects_Cache_of_the_Night);             
  RegisterObjectsAI(Objects_Collector);                      
  RegisterObjectsAI(Objects_Cracked_Soulweb);                
  RegisterObjectsAI(Objects_Cracked_Vertosol);               
  RegisterObjectsAI(Objects_Crafters_Basket);                 
  RegisterObjectsAI(Objects_Crumpled_Journal_Page);          
  RegisterObjectsAI(Objects_Damp_Loam);                      
  RegisterObjectsAI(Objects_Darkreach_Supplies);           
  RegisterObjectsAI(Objects_Death_Blossom);                 
  RegisterObjectsAI(Objects_Decayed_Husk);                   
  RegisterObjectsAI(Objects_Depleted_Wildseed);                           
  RegisterObjectsAI(Objects_Diary_of_the_Night);            
  RegisterObjectsAI(Objects_Dim_Lunarlight_Pod);             
  RegisterObjectsAI(Objects_Discarded_Harp);                
  RegisterObjectsAI(Objects_Discarded_Scroll);               
  RegisterObjectsAI(Objects_Drained_Animacone_Cluster);      
  RegisterObjectsAI(Objects_Drained_Wildseed);               
  RegisterObjectsAI(Objects_Dreamsong_Heart);                
  RegisterObjectsAI(Objects_Elethium_Deposit);               
  RegisterObjectsAI(Objects_Elusive_Faerie_Cache);          
  RegisterObjectsAI(Objects_Enchanted_Bough);               
  RegisterObjectsAI(Objects_Enchanted_Cage);                 
  RegisterObjectsAI(Objects_Enchanted_Chest);                
  RegisterObjectsAI(Objects_Enchanted_Dreamcatcher);         
  RegisterObjectsAI(Objects_Expended_Wildseed);              
  RegisterObjectsAI(Objects_Extra_Gooey_Gorm_Gunk);          
  RegisterObjectsAI(Objects_Fae_Basket);                     
  RegisterObjectsAI(Objects_Fae_Flute);                      
  RegisterObjectsAI(Objects_Fae_Ornament);                   
  RegisterObjectsAI(Objects_Faerie_Belongings);             
  RegisterObjectsAI(Objects_Faerie_Stash);                  
  RegisterObjectsAI(Objects_Faerie_Trove);                 
  RegisterObjectsAI(Objects_Forge);                          
  RegisterObjectsAI(Objects_Fresh_Ardenweald_Anima);         
  RegisterObjectsAI(Objects_Freshleaf);                      
  RegisterObjectsAI(Objects_Frilled_Filtershroom);           
  RegisterObjectsAI(Objects_Gardeners_Basket);              
  RegisterObjectsAI(Objects_Gardeners_Flute);                
  RegisterObjectsAI(Objects_Gardeners_Hammer);               
  RegisterObjectsAI(Objects_Gardeners_Wand);                 
  RegisterObjectsAI(Objects_Giggling_Basket);                
  RegisterObjectsAI(Objects_Gorm_Giblet);                    
  RegisterObjectsAI(Objects_Gorm_Gris);                     
  RegisterObjectsAI(Objects_Gossamer_Thread);               
  RegisterObjectsAI(Objects_Harmonic_Chest);                 
  RegisterObjectsAI(Objects_Heart_of_Tirna_Noch);           
  RegisterObjectsAI(Objects_Hearty_Dragon_Plume);           
  RegisterObjectsAI(Objects_Heavy_Heartshroom);              
  RegisterObjectsAI(Objects_Intact_Husk);                   
  RegisterObjectsAI(Objects_Laestrite_Deposit);             
  RegisterObjectsAI(Objects_Lambent_Vigils_Torch);           
  RegisterObjectsAI(Objects_Large_Lunarlight_Pod);           
  RegisterObjectsAI(Objects_Large_Thistledrop);              
  RegisterObjectsAI(Objects_Ligneous_Phaedrum_Deposit);       
  RegisterObjectsAI(Objects_Lost_Satchel);                   
  RegisterObjectsAI(Objects_Lunarlight_Pod);                 
  RegisterObjectsAI(Objects_Mailbox);                        
  RegisterObjectsAI(Objects_Marasmius);                      
  RegisterObjectsAI(Objects_Misty_Mindshroom);              
  RegisterObjectsAI(Objects_Muddy_Scroll);                  
  RegisterObjectsAI(Objects_Night_Lilly);                   
  RegisterObjectsAI(Objects_Nightshade);                 
  RegisterObjectsAI(Objects_Nox_Root);                     
  RegisterObjectsAI(Objects_Phaedrum_Deposit);            
  RegisterObjectsAI(Objects_Pile_of_Loam);               
  RegisterObjectsAI(Objects_Pulsing_Animacone);        
  RegisterObjectsAI(Objects_Raw_Dream_Silk);           
  RegisterObjectsAI(Objects_Raw_Silkstrider_Silk);     
  RegisterObjectsAI(Objects_Rich_Elethium_Deposit);     
  RegisterObjectsAI(Objects_Rich_Laestrite_Deposit);    
  RegisterObjectsAI(Objects_Rich_Phaedrum_Deposit);      
  RegisterObjectsAI(Objects_Rich_Topsoil);                
  RegisterObjectsAI(Objects_Ripened_Anima_Seed);       
  RegisterObjectsAI(Objects_Riverblossoms_Flute);       
  RegisterObjectsAI(Objects_Shimmerdust_Pile);           
  RegisterObjectsAI(Objects_Shimmering_Soil);           
  RegisterObjectsAI(Objects_Shriveled_Shrub);            
  RegisterObjectsAI(Objects_Silverheart_Vines);             
  RegisterObjectsAI(Objects_Snickering_Basket);            
  RegisterObjectsAI(Objects_Snow_Patch);                   
  RegisterObjectsAI(Objects_Spriggan_Sized_Polearm);        
  RegisterObjectsAI(Objects_Spriggan_Sized_Wand);           
  RegisterObjectsAI(Objects_Stained_Journal_Page);           
  RegisterObjectsAI(Objects_Supply_Baskets);                 
  RegisterObjectsAI(Objects_Suspiciously_Untouched_Basket);  
  RegisterObjectsAI(Objects_Suspiciously_Untouched_Harp);    
  RegisterObjectsAI(Objects_Suspiciously_Untouched_Soulweb); 
  RegisterObjectsAI(Objects_Swollen_Anima_Seed);            
  RegisterObjectsAI(Objects_Thistledrop_Frond);              
  RegisterObjectsAI(Objects_Thistledrop_Growth);             
  RegisterObjectsAI(Objects_Torn_Journal_Page);              
  RegisterObjectsAI(Objects_Very_Large_Silk_Bundle);         
  RegisterObjectsAI(Objects_Vessel_of_Ardenweald);           
  RegisterObjectsAI(Objects_Vigils_Torch);                   
  RegisterObjectsAI(Objects_Violet_Frill);                  
  RegisterObjectsAI(Objects_Water_Bucket);                  
  RegisterObjectsAI(Objects_Wreath_of_Nights_Veil_Flowers);                     
};

void AddSC_Object_Data_Ardenweald()
{
  RegisterAuraScript(ObjectAura);
  RegisterSpellScript(ObjectSpell);
  RegisterEffectScript(ObjectEffect);
  RegisterSpawnScript(ObjectSpawn);
  RegisterNpcLootScript(ObjectLoot);
  RegisterNpcDataScript(ObjectData);
};