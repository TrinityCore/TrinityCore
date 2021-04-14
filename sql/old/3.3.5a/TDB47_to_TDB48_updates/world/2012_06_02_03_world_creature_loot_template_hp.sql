SET @RefDLK := 26043;
SET @HFP := 6000;
SET @HFP1 := @HFP+1;
SET @HFP2 := @HFP+2;
SET @Scrolls := @HFP+3;
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
DELETE FROM `reference_loot_template` WHERE `entry` IN (@RefDLK,@HFP,@HFP1,@HFP2,@Scrolls);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Generic Lowlevel Ref1
(@HFP,1,20,1,0,-4000,1), -- Grey level 61
(@HFP,2,5,1,0,-4001,1), -- Grey level 64
(@HFP,3,2,1,0,-4100,1), -- Green level 57
(@HFP,4,2,1,0,-4101,1), -- Green level 58
(@HFP,5,2,1,0,-4102,1), -- Green level 59
(@HFP,6,2,1,0,-4103,1), -- Green level 60
(@HFP,7,2,1,0,-4104,1), -- Green level 61
(@HFP,8,2,1,0,-4105,1), -- Green level 62
(@HFP,9,0.5,1,0,-4200,1), -- Blue level 60
(@HFP,10,0.5,1,0,-4201,1), -- Blue level 61
(@HFP,11,0.5,1,0,-4202,1), -- Blue level 62
(@HFP,12,0.5,1,0,-4203,1), -- Blue level 63
(@HFP,13,0.5,1,0,-4204,1), -- Blue level 64
(@HFP,4500,0.1,1,0,1,1), -- Traveler's Backpack
(@HFP,3914,0.05,1,0,1,1), -- Journeyman's Backpack
-- Generic Lowlevel Ref2
(@HFP1,1,20,1,0,-4000,1), -- Grey level 61
(@HFP1,2,5,1,0,-4001,1), -- Grey level 64
(@HFP1,3,2,1,0,-4103,1), -- Green level 60
(@HFP1,4,2,1,0,-4104,1), -- Green level 61
(@HFP1,5,2,1,0,-4105,1), -- Green level 62
(@HFP1,6,0.5,1,0,-4200,1), -- Blue level 60
(@HFP1,7,0.5,1,0,-4201,1), -- Blue level 61
(@HFP1,8,0.5,1,0,-4202,1), -- Blue level 62
(@HFP1,9,0.5,1,0,-4203,1), -- Blue level 63
(@HFP1,10,0.5,1,0,-4204,1), -- Blue level 64
-- High level Ref
(@HFP2,1,30,1,1,-4002,1), -- Grey level 64 items (ilvl 69)
(@HFP2,2,30,1,1,-4002,1), -- Grey level 67 items (ilvl 72)
(@HFP2,3,2,1,2,-4110,1), -- Green level 67 items (ilvl 111)
(@HFP2,4,2,1,2,-4111,1), -- Green level 68 items (ilvl 114)
(@HFP2,5,2,1,2,-4112,1), -- Green level 69 items (ilvl 117)
(@HFP2,6,0.5,1,3,-4208,1), -- Blue level 68 items (ilvl 115)
(@HFP2,7,0.5,1,3,-4209,1), -- Blue level 69 items (ilvl 115)
(@HFP2,8,0.5,1,3,-4210,1), -- Blue level 70 items (ilvl 115)
-- TBC Scrolls
(@Scrolls,33459,0,1,1,1,1), -- Scroll of Protection VI
(@Scrolls,33457,0,1,1,1,1), -- Scroll of Agility VI
(@Scrolls,33458,0,1,1,1,1), -- Scroll of Intellect VI
(@Scrolls,33460,0,1,1,1,1), -- Scroll of Spirit VI
(@Scrolls,33461,0,1,1,1,1), -- Scroll of Stamina VI
(@Scrolls,33462,0,1,1,1,1), -- Scroll of Strength VI
-- Doom Lord Kazzak
(@RefDLK,30732,0,1,1,1,1), -- Exodar Life-Staff
(@RefDLK,30733,0,1,1,1,1), -- Hope Ender
(@RefDLK,30734,0,1,1,1,1), -- Leggings of the Seventh Circle
(@RefDLK,30735,0,1,1,1,1), -- Ancient Spellcloak of the Highborne
(@RefDLK,30736,0,1,1,1,1), -- Ring of Flowing Light
(@RefDLK,30737,0,1,1,1,1), -- Gold-Leaf Wildboots
(@RefDLK,30738,0,1,1,1,1), -- Ring of Reciprocity
(@RefDLK,30739,0,1,1,1,1), -- Scaled Greaves of the Marksman
(@RefDLK,30740,0,1,1,1,1), -- Ripfiend Shoulderplates
(@RefDLK,30741,0,1,1,1,1); -- Topaz-Studded Battlegrips
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
DELETE FROM `creature_loot_template` WHERE `entry` IN (18728,187281,19191,16977,19354,17084,17057,16873,16871,19422,16907,19424,19423,16903,16901,19701,16876,16925,18952,16972,16973,17014,16844,19299,16847,16863,18981,16959,19434,16938,16937,19312,22461,19190,18733,24918,18977,17034,19459,19136,19264,16954,18678,18827,16947,16845,19457,16967,16966,22374,18978,16880,17058,22323,19261,17035,17053,16978,16846,16912,16911,19408,17039,16857,18677,19192,16946,16950,16934,19189,19188,16932,16933,20798,19458,16974,19415,16878,16870,19295,16867,19414,19413,19410,19411,16960,16879,16929,16928,16927,19282,19335,19443,16951,19349,19350,16968,26222,26223,16975,20145,16904,16906,16905,19527,16939,18679,19263,19298,16964,19442,24919,18975);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Doom Lord Kazzak, NPC 18728
-- ---------------------------------------------------
(18728,1,100,1,0,-@RefDLK,2), -- Two from Doom Loor Kazzak Reference
(18728,2,5,1,0,-4113,1), -- Level 70 TBC Green Reference
-- ---------------------------------------------------
-- Arazzius the Cruel, NPC 19191
-- ---------------------------------------------------
(19191,21877,50,1,0,1,3), -- Netherweave Cloth
(19191,27854,5,1,0,1,1), -- Smoked Talbuk Venison
(19191,28399,5,1,0,1,1), -- Filtered Draenic Water
(19191,13446,1.5,1,0,1,1), -- Major Healing Potion
(19191,13444,1.5,1,0,1,1), -- Major Mana Potion
(19191,1,15,1,0,-4000,1), -- Grey itemlevel 66 (level 61 items)
(19191,2,5,1,0,-4001,1), -- Grey itemlevel 69 (lvl 64 items)
(19191,3,7.5,1,0,-4103,1), -- Green itemlevel 90
(19191,4,5,1,0,-4104,1), -- Green itemlevel 93
(19191,5,2.5,1,0,-4105,1), -- Green itemlevel 96
(19191,6,0.5,1,0,-4201,1), -- Blues level 61
(19191,7,0.5,1,0,-4202,1), -- Blues level 62
(19191,8,0.5,1,0,-4203,1), -- Blues level 63
(19191,9,0.5,1,0,-4204,1), -- Blues level 64
-- ---------------------------------------------------
-- Arch Mage Xintor, NPC 16977
-- ---------------------------------------------------
(16977,21877,55,1,0,1,1), -- Netherweave Cloth
(16977,14047,15,1,0,1,3), -- Runecloth
(16977,27859,10,1,0,1,1), -- Zanger Caps
(16977,28399,5,1,0,1,1), -- Filtered Draenic Water
(16977,13446,2,1,0,1,1), -- Major Healing Potion
(16977,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Arzeth the Merciless, NPC 19354
-- ---------------------------------------------------
(19354,21877,70,1,0,1,1), -- Netherweave Cloth
(19354,27854,7,1,0,1,1), -- Smoked Talbuk Venison
(19354,28399,3,1,0,1,1), -- Filtered Draenic Water
(19354,13446,3,1,0,1,1), -- Major Healing Potion
(19354,13444,1,1,0,1,1), -- Major Healing Potion
(19354,5760,1,1,0,1,1), -- Eternium Lockbox
(19354,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Avruu, NPC 17084
-- ---------------------------------------------------
(17084,23580,80,1,0,1,1), -- Avruu's Orb
(17084,21877,45,1,0,1,3), -- Netherweave Cloth
(17084,17056,30,1,0,1,1), -- Light Feather
(17084,23483,-10,1,0,1,1), -- QItem: Haal'eshi Scroll
(17084,27854,5,1,0,1,1), -- Smoked Talbuk Venison
(17084,28399,3,1,0,1,1), -- Filtered Draenic Water
(17084,13446,3,1,0,1,1), -- Major Healing Potion
(17084,13444,1,1,0,1,1), -- Major Healing Potion
(17084,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Blacktalon teh Savage, NPC 17057
-- ---------------------------------------------------
(17057,23687,-100,1,0,1,1), -- QItem: Blacktalon's Claws
(17057,24516,75,1,0,1,1), -- Damaged Rock Flayer Talon
(17057,21877,40,1,0,1,1), -- Netherweave Cloth
(17057,24517,20,1,0,1,1), -- Blood Soaked Tail
(17057,27854,3,1,0,1,1), -- Smoked Talbuk Venison
(17057,28399,2,1,0,1,1), -- Filtered Draenic Water
(17057,13446,1.5,1,0,1,1), -- Major Healing Potion
(17057,13444,0.75,1,0,1,1), -- Major Healing Potion
(17057,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Bleeding Hollow Dark Shaman, NPC 16873
-- ---------------------------------------------------
(16873,30157,-25,1,0,1,1), -- QItem: Cursed Talisman
(16873,30425,-17,1,0,1,1), -- QItem: Bleeding Hollow Blood
(16873,28399,3,1,0,1,1), -- Filtered Draenic Water
(16873,13446,2,1,0,1,1), -- Major Healing Potion
(16873,5760,0.1,1,0,1,1), -- Eternium Lockbox
(16873,1,2,1,0,-6003,1), -- Scroll of * Reference
(16873,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Bleeding Hollow Grunt, NPC 16871
-- ---------------------------------------------------
(16871,30157,-25,1,0,1,1), -- QItem: Cursed Talisman
(16871,30425,-17,1,0,1,1), -- QItem: Bleeding Hollow Blood
(16871,28399,3,1,0,1,1), -- Filtered Draenic Water
(16871,13446,2,1,0,1,1), -- Major Healing Potion
(16871,5760,0.1,1,0,1,1), -- Eternium Lockbox
(16871,1,2,1,0,-6003,1), -- Scroll of * Reference
(16871,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Bleeding Hollow Necrolyte, NPC 19422
-- ---------------------------------------------------
(19422,30157,-25,1,0,1,1), -- QItem: Cursed Talisman
(19422,30425,-17,1,0,1,1), -- QItem: Bleeding Hollow Blood
(19422,28399,3,1,0,1,1), -- Filtered Draenic Water
(19422,13446,2,1,0,1,1), -- Major Healing Potion
(19422,5760,0.1,1,0,1,1), -- Eternium Lockbox
(19422,1,2,1,0,-6003,1), -- Scroll of * Reference
(19422,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Bleeding Hollow Peon, NPC 16907
-- ---------------------------------------------------
(16907,30157,-25,1,0,1,1), -- QItem: Cursed Talisman
(16907,30425,-17,1,0,1,1), -- QItem: Bleeding Hollow Blood
(16907,28399,3,1,0,1,1), -- Filtered Draenic Water
(16907,13446,2,1,0,1,1), -- Major Healing Potion
(16907,5760,0.1,1,0,1,1), -- Eternium Lockbox
(16907,1,2,1,0,-6003,1), -- Scroll of * Reference
(16907,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Bleeding Hollow Tormentor, NPC 19424
-- ---------------------------------------------------
(19424,30157,-25,1,0,1,1), -- QItem: Cursed Talisman
(19424,30425,-17,1,0,1,1), -- QItem: Bleeding Hollow Blood
(19424,28399,3,1,0,1,1), -- Filtered Draenic Water
(19424,13446,2,1,0,1,1), -- Major Healing Potion
(19424,5760,0.1,1,0,1,1), -- Eternium Lockbox
(19424,1,2,1,0,-6003,1), -- Scroll of * Reference
(19424,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Bleeding Hollow Worg, NPC 19423
-- ---------------------------------------------------
(19423,3299,70,1,0,1,1), -- Fractured Canine
(19423,33547,25,1,0,1,1), -- Hardened Claw
(19423,4583,1,1,0,1,1), -- Thick Furry Mane
(19423,4584,1,1,0,1,1), -- Large Trophy Paw
(19423,5759,0.2,1,0,1,1), -- Thorium Lockbox
(19423,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Blistering Oozeling, NPC 16903
-- ---------------------------------------------------
(16903,25444,100,1,0,1,1), -- Corrosive Ichor
(16903,23339,-25,1,0,1,1), -- QItem: Arelion's Journal
(16903,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Blistering Rot, NPC 16901
-- ---------------------------------------------------
(16901,25444,80,1,1,1,1), -- Corrosive Ichor
(16901,25446,20,1,1,1,1), -- Brittle Skull
(16901,5760,0.2,1,0,1,1), -- Eternium Lockbox
(16901,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Bonechewer Evoker, NPC 19701
-- ---------------------------------------------------
(19701,21877,55,1,0,1,1), -- Netherweave Cloth
(19701,30327,-30,1,0,1,1), -- QItem: Bonechewer Blood
(19701,14047,20,1,0,1,3), -- Runecloth
(19701,27854,7,1,0,1,1), -- Smoked Talbuk Venison
(19701,28399,3,1,0,1,1), -- Filtered Draenic Water
(19701,13446,3,1,0,1,1), -- Major Healing Potion
(19701,13444,1,1,0,1,1), -- Major Healing Potion
(19701,5759,0.2,1,0,1,1), -- Thorium Lockbox
(19701,1,2,1,0,-6003,1), -- Scroll of * Reference
(19701,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Bonechewer Mutant, NPC 16876
-- ---------------------------------------------------
(16876,21877,55,1,0,1,1), -- Netherweave Cloth
(16876,30327,-30,1,0,1,1), -- QItem: Bonechewer Blood
(16876,14047,20,1,0,1,3), -- Runecloth
(16876,27854,7,1,0,1,1), -- Smoked Talbuk Venison
(16876,28399,3,1,0,1,1), -- Filtered Draenic Water
(16876,13446,3,1,0,1,1), -- Major Healing Potion
(16876,13444,1,1,0,1,1), -- Major Healing Potion
(16876,5759,0.2,1,0,1,1), -- Thorium Lockbox
(16876,1,2,1,0,-6003,1), -- Scroll of * Reference
(16876,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Bonechewer Raider, NPC 16925
-- ---------------------------------------------------
(16925,21877,55,1,0,1,1), -- Netherweave Cloth
(16925,30327,-30,1,0,1,1), -- QItem: Bonechewer Blood
(16925,14047,20,1,0,1,3), -- Runecloth
(16925,27859,7,1,0,1,1), -- Zanger Caps
(16925,28399,3,1,0,1,1), -- Filtered Draenic Water
(16925,13446,3,1,0,1,1), -- Major Healing Potion
(16925,13444,1,1,0,1,1), -- Major Healing Potion
(16925,5759,0.2,1,0,1,1), -- Thorium Lockbox
(16925,1,2,1,0,-6003,1), -- Scroll of * Reference
(16925,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Bonechewer Scavenger, NPC 18952
-- ---------------------------------------------------
(18952,21877,55,1,0,1,1), -- Netherweave Cloth
(18952,30327,-30,1,0,1,1), -- QItem: Bonechewer Blood
(18952,14047,20,1,0,1,3), -- Runecloth
(18952,27854,7,1,0,1,1), -- Smoked Talbuk Venison
(18952,28399,3,1,0,1,1), -- Filtered Draenic Water
(18952,13446,3,1,0,1,1), -- Major Healing Potion
(18952,13444,1,1,0,1,1), -- Major Healing Potion
(18952,5759,0.2,1,0,1,1), -- Thorium Lockbox
(18952,1,2,1,0,-6003,1), -- Scroll of * Reference
(18952,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Bonestripper Buzzard, NPC 16972
-- ---------------------------------------------------
(16972,25425,80,1,0,1,1), -- Molted Feather
(16972,27671,50,1,0,1,1), -- Buzzard Meat
(16972,23239,-10,1,0,1,1), -- Plump Buzzard Wing
(16972,17056,30,1,0,1,1), -- Light Feather
(16972,25427,19,1,0,1,1), -- Beaten Talon
(16972,5759,0.2,1,0,1,1), -- Thorium Lockbox
(16972,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Bonestripper Vulture, NPC 16973
-- ---------------------------------------------------
(16973,25425,80,1,0,1,1), -- Molted Feather
(16973,27671,50,1,0,1,1), -- Buzzard Meat
(16973,23387,-40,1,0,1,1), -- Bonestripper Tail Feather
(16973,25427,19,1,0,1,1), -- Beaten Talon
(16973,5760,0.2,1,0,1,1), -- Eternium Lockbox
(16973,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Collapsing Voidwalker, NPC 17014
-- ---------------------------------------------------
(17014,29161,-100,1,0,1,3), -- Void Ridge Soul Shard
(17014,22577,20,1,0,1,2), -- Mote of Shadow
(17014,1,50,1,1,-6000,1), -- Generic HellfirePeninsula Loot
(17014,2,50,1,1,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Crust Burster, NPC 16844
-- ---------------------------------------------------
(16844,25434,80,1,0,1,1), -- Fractured Carapace
(16844,25436,20,1,0,1,1), -- Twitching Leg
(16844,1,80,1,1,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Deathwhisperer, NPC 19299
-- ---------------------------------------------------
(19299,21877,10,1,0,2,3), -- Netherweave Cloth
(19299,27854,2,1,0,1,1), -- Smoked Talbuk Venison
(19299,28399,2,1,0,1,1), -- Filtered Draenic Water
(19299,13444,1,1,0,1,1), -- Major Mana Potion
(19299,1,90,1,1,-6000,1), -- Generic HellfirePeninsula Loot
(19299,31902,0.05,1,0,1,1), -- Eight of Furies
(19299,31911,0.05,1,0,1,1), -- Eight of Lunacy
-- ---------------------------------------------------
-- Debilitated Mag'har Grunt, NPC 16847
-- ---------------------------------------------------
(16847,23589,-50,1,0,1,1), -- QItem: Mag'har Ancestral Beads
(16847,21877,50,1,0,1,1), -- Netherweave Cloth
(16847,14047,15,1,0,1,3), -- Runecloth
(16847,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(16847,28399,3,1,0,1,1), -- Filtered Draenic Water
(16847,13446,2,1,0,1,1), -- Major Healing Potion
(16847,13444,1,1,0,1,1), -- Major Healing Potion
(16847,5759,0.15,1,0,1,1), -- Thorium Lockbox
(16847,1,2,1,0,-6003,1), -- Scroll of * Reference
(16847,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Deranged Helboar, NPC 16863
-- ---------------------------------------------------
(16863,23270,-40,1,0,1,1), -- QItem: Tainted Helboar Meat
(16863,3403,40,1,1,1,1), -- Ivory Boar Tusk
(16863,2295,40,1,1,1,1), -- Large Boar Tusk
(16863,44754,15,1,1,1,1), -- Severed Boar Tusk
(16863,25440,1.5,1,1,1,1), -- Cracked Boar Tusk
(16863,25442,0.5,1,0,1,1), -- Mangled Snout
(16863,1,2,1,0,-6003,1), -- Scroll of * Reference
(16863,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Doomwhisperer, NPC 18981
-- ---------------------------------------------------
(18981,28513,-50,1,0,1,1), -- QItem: Demonic Rune Stone
(18981,21877,50,1,0,1,1), -- Netherweave Cloth
(18981,14047,15,1,0,1,3), -- Runecloth
(18981,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(18981,28399,3,1,0,1,1), -- Filtered Draenic Water
(18981,13446,2,1,0,1,1), -- Major Healing Potion
(18981,13444,1,1,0,1,1), -- Major Healing Potion
(18981,5759,0.15,1,0,1,1), -- Thorium Lockbox
(18981,1,2,1,0,-6003,1), -- Scroll of * Reference
(18981,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Dread Tactician, NPC 16959
-- ---------------------------------------------------
(16959,21877,13,1,0,1,1), -- Netherweave Cloth
(16959,14047,15,1,0,1,3), -- Runecloth
(16959,27854,2,1,0,1,1), -- Smoked Talbuk Venison
(16959,27860,3,1,0,1,1), -- Purified Draenic Water
(16959,22829,0.5,1,0,1,1), -- Super Healing Potion
(16959,22832,0.25,1,0,1,1), -- Super Mana Potion
(16959,1,80,1,0,-6002,1), -- Generic HellfirePeninsula Loot2
-- ---------------------------------------------------
-- Dreadcaller, NPC 19434
-- ---------------------------------------------------
(19434,21877,60,1,0,1,1), -- Netherweave Cloth
(19434,14047,15,1,0,1,3), -- Runecloth
(19434,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(19434,28399,3,1,0,1,1), -- Filtered Draenic Water
(19434,13446,2,1,0,1,1), -- Major Healing Potion
(19434,13444,1,1,0,1,1), -- Major Healing Potion
(19434,5759,0.2,1,0,1,1), -- Thorium Lockbox
(19434,1,2,1,0,-6003,1), -- Scroll of * Reference
(19434,2,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Dreghood Brute, NPC 16938
-- ---------------------------------------------------
(16938,21877,70,1,0,1,1), -- Netherweave Cloth
(16938,27854,11,1,0,1,1), -- Mag'har Grainbread
(16938,28399,3,1,0,1,1), -- Filtered Draenic Water
(16938,13446,2,1,0,1,1), -- Major Healing Potion
(16938,13444,1,1,0,1,1), -- Major Healing Potion
(16938,1,2,1,0,-6003,1), -- Scroll of * Reference
-- ---------------------------------------------------
-- Dreghood Geomancer, NPC 16937
-- ---------------------------------------------------
(16937,21877,70,1,0,1,1), -- Netherweave Cloth
(16937,27854,11,1,0,1,1), -- Mag'har Grainbread
(16937,28399,3,1,0,1,1), -- Filtered Draenic Water
(16937,13446,2,1,0,1,1), -- Major Healing Potion
(16937,13444,1,1,0,1,1), -- Major Healing Potion
-- ---------------------------------------------------
-- Drillmaster Zurok, NPC 19312
-- ---------------------------------------------------
(19312,21877,60,1,0,1,1), -- Netherweave Cloth
(19312,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(19312,28399,3,1,0,1,1), -- Filtered Draenic Water
(19312,13446,2,1,0,1,1), -- Major Healing Potion
(19312,13444,1,1,0,1,1), -- Major Healing Potion
(19312,5760,0.2,1,0,1,1), -- Eternium Lockbox
(19312,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Fel Canon MKI, NPC 22461
-- ---------------------------------------------------
(22461,31944,80,1,1,1,1), -- Demonic Capacitor
(22461,31945,20,1,1,1,1), -- Shadow Circuit
-- ---------------------------------------------------
-- Fel Handler, NPC 19190
-- ---------------------------------------------------
(19190,28513,-50,1,0,1,1), -- QItem: Demonic Rune Stone
(19190,27854,10,1,0,1,1), -- Smoked Talbuk Venison
(19190,28399,5,1,0,1,1), -- Filtered Draenic Water
(19190,13446,3,1,0,1,1), -- Major Healing Potion
(19190,13444,1.5,1,0,1,1), -- Major Mana Potion
(19190,5759,0.2,1,0,1,1), -- Thorium Lockbox
(19190,1,2,1,0,-6003,1), -- Scroll of * Reference
(19190,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Fel Reaver, NPC 18733
-- ---------------------------------------------------
(18733,1,100,1,0,-6002,1), -- Generic HellfirePeninsula Loot2
-- ---------------------------------------------------
-- Felblood Initiate, NPC 24918
-- ---------------------------------------------------
(24918,21877,75,1,0,1,3), -- Netherweave Cloth
(24918,27857,8,1,0,1,1), -- Garadar Sharp
(24918,27860,5,1,0,1,1), -- Filtered Draenic Water
(24918,22829,3,1,0,1,1), -- Super Healing Potion
(24918,22832,1.5,1,0,1,1), -- Super Healing Potion
(24918,31952,0.2,1,0,1,1), -- Khorium Lockbox
(24918,31888,0.01,1,0,1,1), -- Three of Blessings
(24918,31908,0.01,1,0,1,1), -- Three of Furies
(24918,1,80,1,0,-6002,1), -- Generic HellfirePeninsula Loot2
-- ---------------------------------------------------
-- Felguard Destroyer, NPC 18977
-- ---------------------------------------------------
(18977,21877,40,1,0,1,3), -- Netherweave Cloth
(18977,27854,5,1,0,1,1), -- Smoked Talbuk Venison
(18977,28399,4,1,0,1,1), -- Filtered Draenic Water
(18977,13446,2,1,0,1,1), -- Major Healing Potion
(18977,13444,1,1,0,1,1), -- Major Mana Potion
(18977,5759,0.3,1,0,1,1), -- Thorium Lockbox
(18977,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Female Kaliri Hatchling, NPC 17034
-- ---------------------------------------------------
(17034,23588,-40,1,0,1,1), -- QItem: Kaliri Feather
(17034,25425,81,1,1,1,1), -- Molted Feather
(17034,25427,19,1,1,1,1), -- Beaten Talon
(17034,5760,0.2,1,0,1,1), -- Eternium Lockbox
(17034,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Feng, NPC 19459
-- ---------------------------------------------------
(19459,3299,70,1,0,1,1), -- Fractured Canine
(19459,33547,30,1,0,1,1), -- Hardened Claw
(19459,5759,0.3,1,0,1,1), -- Thorium Lockbox
(19459,4583,0.3,1,0,1,1), -- Thick Furry Mane
(19459,4584,0.2,1,0,1,1), -- Large Trophy Paw
(19459,1,70,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Flamewalker Imp, NPC 19136
-- ---------------------------------------------------
(19136,21877,92,1,0,1,1), -- Netherweave Cloth
(19136,22785,0.05,1,0,1,3), -- Felweed
-- ---------------------------------------------------
-- Force-Commander Gorax, NPC 19264
-- ---------------------------------------------------
(19264,21877,80,1,0,1,3), -- Netherweave Cloth
(19264,27854,10,1,0,1,1), -- Smoked Talbuk Venison
(19264,28399,5,1,0,1,1), -- Filtered Draenic Water
(19264,13446,3,1,0,1,1), -- Major Healing Potion
(19264,13444,1.5,1,0,1,1), -- Major Mana Potion
(19264,5760,0.3,1,0,1,1), -- Eternium Lockbox
(19264,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Forge-Camp Legionnaire, NPC 16954
-- ---------------------------------------------------
(16954,21877,80,1,0,1,3), -- Netherweave Cloth
(16954,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(16954,28399,4,1,0,1,1), -- Filtered Draenic Water
(16954,13446,2,1,0,1,1), -- Major Healing Potion
(16954,13444,1,1,0,1,1), -- Major Mana Potion
(16954,5759,0.3,1,0,1,1), -- Thorium Lockbox
(16954,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot
(16954,2,2,1,0,-6003,1), -- Scroll of * Reference
-- ---------------------------------------------------
-- Fulgorge, NPC 18678
-- ---------------------------------------------------
(18678,31176,0,1,1,1,1), -- Rockwurm Plate Handguards
(18678,31177,0,1,1,1,1), -- Rockwurm Scale Gauntlets
(18678,31179,0,1,1,1,1), -- Rockwurm Hide Gloves
(18678,31181,0,1,1,1,1), -- Rockwurm Hide Handwraps
(18678,25434,1,1,0,1,3), -- Fractured Carapace
(18678,25436,0.2,1,0,2,4), -- Twitching Leg
-- ---------------------------------------------------
-- Gan'arg Sapper, NPC 18827
-- ---------------------------------------------------
(18827,21877,83,1,0,1,3), -- Netherweave Cloth
(18827,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(18827,28399,4,1,0,1,1), -- Filtered Draenic Water
(18827,13446,3,1,0,1,1), -- Major Healing Potion
(18827,13444,1.5,1,0,1,1), -- Major Mana Potion
(18827,5759,0.2,1,0,1,1), -- Thorium Lockbox
(18827,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot
(18827,2,3,1,0,-6003,1), -- Scroll of * Reference
-- ---------------------------------------------------
-- Gan'arg Servant, NPC 16947
-- ---------------------------------------------------
(16947,21877,83,1,0,1,3), -- Netherweave Cloth
(16947,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(16947,28399,4,1,0,1,1), -- Filtered Draenic Water
(16947,13446,3,1,0,1,1), -- Major Healing Potion
(16947,13444,1.5,1,0,1,1), -- Major Mana Potion
(16947,5759,0.1,1,0,1,1), -- Thorium Lockbox
(16947,1,95,1,0,-6000,1), -- Generic HellfirePeninsula Loot
(16947,2,3,1,0,-6003,1), -- Scroll of * Reference
-- ---------------------------------------------------
-- Gorkan Bloodfist, NPC 16845
-- ---------------------------------------------------
(16845,21877,3,1,0,2,3), -- Netherweave Cloth
(16845,27854,1,1,0,1,1), -- Smoked Talbuk Venison
(16845,22829,0.5,1,0,1,1), -- Super Healing Potion
(16845,1,2,1,0,-4110,1), -- Level 67 Green Items (ilvl 111)
-- ---------------------------------------------------
-- Grillok "Darkeye", NPC 19457
-- ---------------------------------------------------
(19457,31529,-100,1,0,1,1), -- QItem: Grillok's Eyepatch
(19457,21877,45,1,0,1,3), -- Netherweave Cloth
(19457,30157,-5,1,0,1,1), -- QItem: Cursed Talisman
(19457,30425,-10,1,0,1,1), -- QItem: Bleeding Hollow Blood
(19457,27854,4,1,0,1,1), -- Smoked Talbuk Venison
(19457,28399,2,1,0,1,1), -- Filtered Draenic Water
(19457,13446,2,1,0,1,1), -- Major Healing Potion
(19457,13444,1,1,0,1,1), -- Major Mana Potion
(19457,5760,0.1,1,0,1,1), -- Eternium Lockbox
(19457,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Haal'eshi Talonguard, NPC 16967
-- ---------------------------------------------------
(16967,21877,60,1,0,1,3), -- Netherweave Cloth
(16967,17056,42,1,0,1,1), -- Light Feather
(16967,23483,-15,1,0,1,1), -- QItem: Haal'eshi Scroll
(16967,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(16967,28399,3,1,0,1,1), -- Filtered Draenic Water
(16967,13446,2,1,0,1,1), -- Major Healing Potion
(16967,13444,1,1,0,1,1), -- Major Mana Potion
(16967,5760,0.1,1,0,1,1), -- Eternium Lockbox
(16967,1,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
(16967,2,3,1,0,-6003,1), -- Scroll of * Reference
-- ---------------------------------------------------
-- Haal'eshi Windwalker, NPC 16966
-- ---------------------------------------------------
(16966,21877,60,1,0,1,3), -- Netherweave Cloth
(16966,17056,42,1,0,1,1), -- Light Feather
(16966,23483,-15,1,0,1,1), -- QItem: Haal'eshi Scroll
(16966,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(16966,28399,3,1,0,1,1), -- Filtered Draenic Water
(16966,13446,2,1,0,1,1), -- Major Healing Potion
(16966,13444,1,1,0,1,1), -- Major Mana Potion
(16966,5760,0.1,1,0,1,1), -- Eternium Lockbox
(16966,1,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
(16966,2,3,1,0,-6003,1), -- Scroll of * Reference
-- ---------------------------------------------------
-- Hand of Kargath, NPC 22374
-- ---------------------------------------------------
(22374,31706,-100,1,0,1,1), -- QItem: The Head of the Hand of Kargath
(22374,21877,40,1,0,1,3), -- Netherweave Cloth
(22374,27854,4,1,0,1,1), -- Smoked Talbuk Venison
(22374,28399,2,1,0,1,1), -- Filtered Draenic Water
(22374,13446,1,1,0,1,1), -- Major Healing Potion
(22374,13444,0.5,1,0,1,1), -- Major Mana Potion
(22374,5760,0.1,1,0,1,1), -- Eternium Lockbox
(22374,1,80,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Heckling Fel Sprite, NPC 18978
-- ---------------------------------------------------
(18978,21877,95,1,0,1,1), -- Netherweave Cloth
-- ---------------------------------------------------
-- Hulking Helboar, NPC 16880
-- ---------------------------------------------------
(16880,23336,-30,1,0,1,1), -- QItem: Helboar Blood Sample
(16880,23270,-5,1,0,1,1), -- QItem: Tainted Hellboar Meat
(16880,3403,82,1,1,1,1), -- Ivory Boar Tusk
(16880,25440,1.5,1,1,1,1), -- Cracked Boar Tusk
(16880,25442,0.3,1,2,1,1), -- Mangled Snout
(16880,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Illidari Taskmaster, NPC 17058
-- ---------------------------------------------------
(17058,29113,-50,1,0,1,1), -- QItem: Demonic Essence
(17058,21877,60,1,0,1,3), -- Netherweave Cloth
(17058,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(17058,28399,3,1,0,1,1), -- Filtered Draenic Water
(17058,13446,2,1,0,1,1), -- Major Healing Potion
(17058,13444,1,1,0,1,1), -- Major Mana Potion
(17058,5760,0.2,1,0,1,1), -- Eternium Lockbox
(17058,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
(17058,2,2,1,0,-6003,1), -- Scroll of * Reference
-- ---------------------------------------------------
-- Incandescent Fel Spark, NPC 22323
-- ---------------------------------------------------
(22323,24508,80,1,1,1,1), -- Elemental Fragment
(22323,24511,20,1,1,1,1), -- Primordial Essence
(22323,22574,35,1,0,1,2), -- Mote of Fire
(22323,1,90,1,0,-6002,1), -- Generic HellfirePeninsula Loot2
-- ---------------------------------------------------
-- Infernal Warbringer, NPC 19261
-- ---------------------------------------------------
(19261,1,70,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Kaliri Matriarch, NPC 17035
-- ---------------------------------------------------
(17035,23588,-27,1,0,1,1), -- QItem: Kaliri Feather
(17035,25425,81,1,1,1,1), -- Molted Feather
(17035,25427,19,1,1,1,1), -- Beaten Talon
(17035,5760,0.07,1,0,1,1), -- Eternium Lockbox
(17035,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Kaliri Swooper, NPC 17053
-- ---------------------------------------------------
(17053,23588,-25,1,0,1,1), -- QItem: Kaliri Feather
(17053,25425,81,1,1,1,1), -- Molted Feather
(17053,25427,19,1,1,1,1), -- Beaten Talon
(17053,5760,0.05,1,0,1,1), -- Eternium Lockbox
(17053,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Lieutenant Commander Thalvos, NPC 16978
-- ---------------------------------------------------
(16978,28562,-100,1,0,1,1), -- QItem: Unyielding Battle Horn
(16978,21877,55,1,0,1,1), -- Netherweave Cloth
(16978,27859,5,1,0,1,1), -- Zanger Caps
(16978,28399,2.5,1,0,1,1), -- Filtered Draenic Water
(16978,13446,2,1,0,1,1), -- Major Healing Potion
(16978,13444,2,1,0,1,1), -- Major Mana Potion
(16978,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Mag'har Grunt, NPC 16846
-- ---------------------------------------------------
(16846,23589,-50,1,0,1,1), -- QItem: Mag'har Ancestral Beads
(16846,21877,60,1,0,1,1), -- Netherweave Cloth
(16846,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(16846,28399,3,1,0,1,1), -- Filtered Draenic Water
(16846,13446,2,1,0,1,1), -- Major Healing Potion
(16846,13444,1,1,0,1,1), -- Major Healing Potion
(16846,5759,0.15,1,0,1,1), -- Eternium Lockbox
(16846,1,2,1,0,-6003,1), -- Scroll of * Reference
(16846,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Mag'har Hunter, NPC 16912
-- ---------------------------------------------------
(16912,21877,60,1,0,1,1), -- Netherweave Cloth
(16912,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(16912,28399,3,1,0,1,1), -- Filtered Draenic Water
(16912,13446,2,1,0,1,1), -- Major Healing Potion
(16912,13444,1,1,0,1,1), -- Major Healing Potion
(16912,5759,0.15,1,0,1,1), -- Eternium Lockbox
(16912,1,2,1,0,-6003,1), -- Scroll of * Reference
(16912,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Mag'har Watcher, NPC 16911
-- ---------------------------------------------------
(16911,21877,60,1,0,1,1), -- Netherweave Cloth
(16911,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(16911,28399,3,1,0,1,1), -- Filtered Draenic Water
(16911,13446,2,1,0,1,1), -- Major Healing Potion
(16911,13444,1,1,0,1,1), -- Major Healing Potion
(16911,5759,0.15,1,0,1,1), -- Eternium Lockbox
(16911,1,2,1,0,-6003,1), -- Scroll of * Reference
(16911,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Maiden of Pain, NPC 19408
-- ---------------------------------------------------
(19408,14047,15,1,0,1,3), -- Runecloth
(19408,27854,9,1,0,1,1), -- Smoked Talbuk Venison
(19408,28399,4,1,0,1,1), -- Filtered Draenic Water
(19408,13446,3,1,0,1,1), -- Major Healing Potion
(19408,13444,1.5,1,0,1,1), -- Major Healing Potion
(19408,5760,0.15,1,0,1,1), -- Eternium Lockbox
(19408,1,2,1,0,-6003,1), -- Scroll of * Reference
(19408,2,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Male Kaliri Hatchling, NPC 17039
-- ---------------------------------------------------
(17039,23588,-25,1,0,1,1), -- QItem: Kaliri Feather
(17039,25425,81,1,1,1,1), -- Molted Feather
(17039,25427,19,1,1,1,1), -- Beaten Talon
(17039,5760,0.2,1,0,1,1), -- Eternium Lockbox
(17039,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Marauding Crust Burster, NPC 16857
-- ---------------------------------------------------
(16857,23338,7,1,0,1,1), -- Eroded Leather Case
(16857,25434,80,1,0,1,1), -- Fractured Carapace
(16857,25436,20,1,0,1,1), -- Twitching Leg
(16857,5759,0.1,1,0,1,1), -- Thorium Lockbox
(16857,1,80,1,1,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Mekthorg the Wild, NPC 18677
-- ---------------------------------------------------
(18677,31168,0,1,1,1,1), -- Demon-Forged Chestguard
(18677,31170,0,1,1,1,1), -- Demon-Forged Hauberk
(18677,31172,0,1,1,1,1), -- Demon-Cured Tunic
(18677,31174,0,1,1,1,1), -- Demonweave Raiment
(18677,21877,40,1,0,1,3), -- Netherweave Cloth
(18677,27854,4,1,0,1,1), -- Smoked Talbuk Venison
(18677,28399,2,1,0,1,3), -- Netherweave Cloth
-- ---------------------------------------------------
-- Mistress of Doom, NPC 19192
-- ---------------------------------------------------
(19192,21877,80,1,0,1,3), -- Netherweave Cloth
(19192,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(19192,28399,5,1,0,1,1), -- Filtered Draenic Water
(19192,13446,3,1,0,1,1), -- Major Healing Potion
(19192,13444,1.5,1,0,1,1), -- Major Healing Potion
(19192,5759,0.15,1,0,1,1), -- Eternium Lockbox
(19192,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Mo'arg Forgefiend, NPC 16946
-- ---------------------------------------------------
(16946,21877,80,1,0,1,3), -- Netherweave Cloth
(16946,27854,9,1,0,1,1), -- Smoked Talbuk Venison
(16946,28399,4,1,0,1,1), -- Filtered Draenic Water
(16946,13446,3,1,0,1,1), -- Major Healing Potion
(16946,13444,1.5,1,0,1,1), -- Major Healing Potion
(16946,5760,0.15,1,0,1,1), -- Eternium Lockbox
(16946,1,2,1,0,-6003,1), -- Scroll of * Reference
(16946,2,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Netherhound, NPC 16950
-- ---------------------------------------------------
(16950,28513,-60,1,0,1,1), -- QItem: Demonic Rune Stone
(16950,3299,43,1,0,1,1), -- Fractured Canine
(16950,33547,17,1,0,1,1), -- Hardened Claw
(16950,4583,0.5,1,0,1,1), -- Thick Furry Mane
(16950,4584,0.2,1,0,1,1), -- Large Trophy Paw
(16950,5759,0.05,1,0,1,1), -- Thorium Lockbox
(16950,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Quillfang Ravager, NPC 16934
-- ---------------------------------------------------
(16934,27674,50,1,0,1,1), -- Ravager Flesh
(16934,23965,81,1,1,1,1), -- Chipped Ravager Claw
(16934,23979,19,1,1,1,1), -- Chipped Ravager Carapace
(16934,1,85,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Quillfang Skitterer, NPC 19189
-- ---------------------------------------------------
(19189,27674,50,1,0,1,1), -- Ravager Flesh
(19189,23217,-4,1,0,1,1), -- QItem: Ravager Egg
(19189,23965,81,1,1,1,1), -- Chipped Ravager Claw
(19189,23979,19,1,1,1,1), -- Chipped Ravager Carapace
(19189,1,85,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Raging Colossus, NPC 19188
-- ---------------------------------------------------
(19188,29579,80,1,0,2,4), -- Crystalized Stone Chips
(19188,29476,19,1,0,1,1), -- Crimson Crystal Shard
(19188,29578,19,1,0,2,4), -- Crystalized Stone
(19188,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Razorfang Hatchling, NPC 16932
-- ---------------------------------------------------
(16932,23217,-1,1,0,1,1), -- QItem: Ravager Egg
(16932,27674,50,1,0,1,1), -- Ravager Flesh
(16932,23976,0,1,1,1,1), -- Gnarled Ravager Carapace
(16932,23977,0,1,1,1,1), -- Gnarled Ravager Fang
(16932,23978,0,1,1,1,1), -- Gnarled Ravager Claw
(16932,1,85,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Razorfang Ravager, NPC 16933
-- ---------------------------------------------------
(16933,23965,81,1,1,1,1), -- Chipped Ravager Claw
(16933,23979,19,1,1,1,1), -- Chipped Ravager Carapace
(16933,27674,50,1,0,1,1), -- Ravager Flesh
(16933,23217,-20,1,0,1,1), -- QItem: Ravager Egg
(16933,1,85,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Razorsaw, NPC 20798
-- ---------------------------------------------------
(20798,29590,55,1,0,1,1), -- Burning Legion Missive
(20798,29586,-100,1,0,1,1), -- QItem: Head of Forgefiend Razorsaw
(20798,21877,50,1,0,1,3), -- Netherweave Cloth
(20798,27854,5,1,0,1,1), -- Smoked Talbuk Venison
(20798,28399,2.5,1,0,1,1), -- Filtered Draenic Water
(20798,13446,1.5,1,0,1,1), -- Major Healing Potion
(20798,13444,0.75,1,0,1,1), -- Major Mana Potion
(20798,5760,0.15,1,0,1,1), -- Eternium Lockbox
(20798,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Ripp, NPC 19458
-- ---------------------------------------------------
(19458,3299,70,1,0,1,1), -- Fractured Canine
(19458,33547,25,1,0,1,1), -- Hardened Claw
(19458,4583,1,1,0,1,1), -- Thick Furry Mane
(19458,4584,1,1,0,1,1), -- Large Trophy Paw
(19458,5759,0.2,1,0,1,1), -- Thorium Lockbox
(19458,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Rogue Voidwalker, NPC 16974
-- ---------------------------------------------------
(16974,23218,-85,1,0,1,1), -- Condensed Voidwalker Essence
(16974,22577,20,1,0,1,1), -- Mote of Shadow
(16974,1,90,1,0,-6000,1), -- Generic HellfirePeninsule Loot
-- ---------------------------------------------------
-- Shattered Hand Acolyte, NPC 19415
-- ---------------------------------------------------
(19415,21877,70,1,0,1,3), -- Netherweave Cloth
(19415,27854,9,1,0,1,1), -- Smoked Talbuk Venison
(19415,28399,4,1,0,1,1), -- Filtered Draenic Water
(19415,13446,2,1,0,1,1), -- Major Healing Potion
(19415,13444,1,1,0,1,1), -- Major Healing Potion
(19415,5760,0.2,1,0,1,1), -- Eternium Lockbox
(19415,1,2,1,0,-6003,1), -- Scroll of * Reference
(19415,2,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Shattered Hand Berserker, NPC 16878
-- ---------------------------------------------------
(16878,21877,82,1,0,1,3), -- Netherweave Cloth
(16878,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(16878,28399,4,1,0,1,1), -- Filtered Draenic Water
(16878,13446,3,1,0,1,1), -- Major Healing Potion
(16878,13444,1.5,1,0,1,1), -- Major Healing Potion
(16878,5760,0.2,1,0,1,1), -- Eternium Lockbox
(16878,1,2,1,0,-6003,1), -- Scroll of * Reference
(16878,2,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Shattered Hand Captain, NPC 16870
-- ---------------------------------------------------
(16870,21877,80,1,0,1,3), -- Netherweave Cloth
(16870,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(16870,28399,4,1,0,1,1), -- Filtered Draenic Water
(16870,13446,2,1,0,1,1), -- Major Healing Potion
(16870,13444,1,1,0,1,1), -- Major Healing Potion
(16870,5760,0.2,1,0,1,1), -- Eternium Lockbox
(16870,1,2,1,0,-6003,1), -- Scroll of * Reference
(16870,2,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Shattered Hand Grenadier, NPC 19295
-- ---------------------------------------------------
(19295,21877,85,1,0,1,3), -- Netherweave Cloth
(19295,27854,9,1,0,1,1), -- Smoked Talbuk Venison
(19295,28399,4,1,0,1,1), -- Filtered Draenic Water
(19295,13446,2,1,0,1,1), -- Major Healing Potion
(19295,13444,1,1,0,1,1), -- Major Healing Potion
(19295,1,75,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Shattered Hand Grunt, NPC 16867
-- ---------------------------------------------------
(16867,21877,80,1,0,1,3), -- Netherweave Cloth
(16867,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(16867,28399,4,1,0,1,1), -- Filtered Draenic Water
(16867,13446,2,1,0,1,1), -- Major Healing Potion
(16867,13444,1,1,0,1,1), -- Major Healing Potion
(16867,5760,0.18,1,0,1,1), -- Eternium Lockbox
(16867,1,2,1,0,-6003,1), -- Scroll of * Reference
(16867,2,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Shattered Hand Guard, NPC 19414
-- ---------------------------------------------------
(19414,21877,80,1,0,1,3), -- Netherweave Cloth
(19414,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(19414,28399,4,1,0,1,1), -- Filtered Draenic Water
(19414,13446,3,1,0,1,1), -- Major Healing Potion
(19414,13444,1.5,1,0,1,1), -- Major Healing Potion
(19414,5760,0.18,1,0,1,1), -- Eternium Lockbox
(19414,1,2,1,0,-6003,1), -- Scroll of * Reference
(19414,2,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Shattered Hand Mage, NPC 19413
-- ---------------------------------------------------
(19413,21877,60,1,0,1,3), -- Netherweave Cloth
(19413,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(19413,28399,3,1,0,1,1), -- Filtered Draenic Water
(19413,13446,2,1,0,1,1), -- Major Healing Potion
(19413,13444,1,1,0,1,1), -- Major Healing Potion
(19413,1,2,1,0,-6003,1), -- Scroll of * Reference
(19413,2,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Shattered Hand Neophyte, NPC 19410
-- ---------------------------------------------------
(19410,21877,80,1,0,1,3), -- Netherweave Cloth
(19410,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(19410,28399,4,1,0,1,1), -- Filtered Draenic Water
(19410,13446,2,1,0,1,1), -- Major Healing Potion
(19410,13444,1,1,0,1,1), -- Major Healing Potion
(19410,5760,0.18,1,0,1,1), -- Eternium Lockbox
(19410,1,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Shattered Hand Warlock, NPC 19411
-- ---------------------------------------------------
(19411,21877,80,1,0,1,3), -- Netherweave Cloth
(19411,27854,9,1,0,1,1), -- Smoked Talbuk Venison
(19411,28399,4,1,0,1,1), -- Filtered Draenic Water
(19411,13446,2,1,0,1,1), -- Major Healing Potion
(19411,13444,1,1,0,1,1), -- Major Healing Potion
(19411,5760,0.18,1,0,1,1), -- Eternium Lockbox
(19411,1,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Sister of Grief, NPC 16960
-- ---------------------------------------------------
(16960,21877,80,1,0,1,3), -- Netherweave Cloth
(16960,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(16960,28399,4,1,0,1,1), -- Filtered Draenic Water
(16960,13446,2,1,0,1,1), -- Major Healing Potion
(16960,13444,1,1,0,1,1), -- Major Healing Potion
(16960,1,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Starving Helboar, NPC 16879
-- ---------------------------------------------------
(16879,23270,-5,1,0,1,1), -- QItem: Tainted Helboar Meat
(16879,2295,74,1,1,1,1), -- Large Boar Tusk
(16879,44754,24,1,1,1,1), -- Severed Boar Tusk
(16879,25440,2,1,1,1,1), -- Cracked Boar Tusk
(16879,25442,0.5,1,0,1,1), -- Mangled Snout
(16879,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Stonescythe Alpha, NPC 16929
-- ---------------------------------------------------
(16929,24516,81,1,1,1,1), -- Damaged Rock Flayer Talon
(16929,24517,19,1,1,1,1), -- Blood Soaked Tail
(16929,27854,4,1,0,1,1), -- Smoked Talbuk Venison
(16929,28399,2,1,0,1,1), -- Filtered Draenic Water
(16929,13446,1.2,1,0,1,1), -- Major Healing Potion
(16929,13444,0.6,1,0,1,1), -- Major Healing Potion
(16929,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
(16929,2,2,1,0,-6003,1), -- Scroll of * Reference
-- ---------------------------------------------------
-- Stonescythe Ambusher, NPC 16928
-- ---------------------------------------------------
(16928,24516,81,1,1,1,1), -- Damaged Rock Flayer Talon
(16928,24517,19,1,1,1,1), -- Blood Soaked Tail
(16928,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Stonescythe Whelp, NPC 16927
-- ---------------------------------------------------
(16927,24516,81,1,1,1,1), -- Damaged Rock Flayer Talon
(16927,24517,19,1,1,1,1), -- Blood Soaked Tail
(16927,27854,4,1,0,1,1), -- Smoked Talbuk Venison
(16927,28399,2,1,0,1,1), -- Filtered Draenic Water
(16927,13446,1.2,1,0,1,1), -- Major Healing Potion
(16927,13444,0.6,1,0,1,1), -- Major Healing Potion
(16927,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
(16927,2,2,1,0,-6003,1), -- Scroll of * Reference
-- ---------------------------------------------------
-- Subjugator Shi'aziv, NPC 19282
-- ---------------------------------------------------
(19282,28513,-25,1,0,1,1), -- QItem: Demonic Rune Stone
(19282,27854,3,1,0,1,1), -- Smoked Talbuk Venison
(19282,28399,1.5,1,0,1,1), -- Filtered Draenic Water
(19282,13446,1,1,0,1,1), -- Major Healing Potion
(19282,13444,0.5,1,0,1,1), -- Major Healing Potion
(19282,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Subjugator Yalqiz, NPC 19335
-- ---------------------------------------------------
(19335,27854,1.2,1,0,1,1), -- Smoked Talbuk Venison
(19335,28399,0.6,1,0,1,1), -- Filtered Draenic Water
(19335,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Tagar Spinebreaker, NPC 19443
-- ---------------------------------------------------
(19443,21877,33,1,0,1,3), -- Netherweave Cloth
(19443,27854,4,1,0,1,1), -- Smoked Talbuk Venison
(19443,28399,2,1,0,1,1), -- Filtered Draenic Water
(19443,13446,1,1,0,1,1), -- Major Healing Potion
(19443,13444,0.5,1,0,1,1), -- Major Healing Potion
(19443,1,70,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Terrorfiend, NPC 16951
-- ---------------------------------------------------
(16951,21877,70,1,0,1,3), -- Netherweave Cloth
(16951,23269,-25,1,0,1,1), -- Felblood Sample
(16951,27854,7,1,0,1,1), -- Smoked Talbuk Venison
(16951,28399,3.5,1,0,1,1), -- Filtered Draenic Water
(16951,13446,2,1,0,1,1), -- Major Healing Potion
(16951,13444,1,1,0,1,1), -- Major Healing Potion
(16951,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot
(16951,2,2,1,0,-6003,1), -- Scroll of * Reference
-- ---------------------------------------------------
-- Thornfang Ravager, NPC 19349
-- ---------------------------------------------------
(19349,27674,50,1,0,1,1), -- Ravager Flesh
(19349,23965,81,1,1,1,1), -- Chipped Ravager Claw
(19349,23979,19,1,1,1,1), -- Chipped Ravager Carapace
(19349,5760,0.1,1,0,1,1), -- Eternium Lockbox
(19349,1,85,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Thornfang Venomspitter, NPC 19350
-- ---------------------------------------------------
(19350,23965,81,1,1,1,1), -- Chipped Ravager Claw
(19350,23979,19,1,1,1,1), -- Chipped Ravager Carapace
(19350,1,85,1,0,-6001,1), -- Generic HellfirePeninsula Loot1
-- ---------------------------------------------------
-- Tunneler, NPC 16968
-- ---------------------------------------------------
(16968,23338,5,1,0,1,1), -- Eroded Leather Case
(16968,25434,81,1,1,1,1), -- Fractured Carapace
(16968,25436,19,1,1,1,1), -- Twitching Leg
(16968,5760,0.1,1,0,1,1), -- Eternium Lockbox
(16968,1,80,1,1,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Twilight Cryomancer, NPC 26222
-- ---------------------------------------------------
(26222,14047,85,1,0,1,2), -- Runecloth
(26222,8952,9,1,0,1,2), -- Roasted Quail
(26222,8766,4.5,1,0,1,2), -- Morning Glory Dew
(26222,13446,6,1,0,1,2), -- Major Healing Potion
(26222,13444,3,1,0,1,2), -- Major Mana Potion
(26222,1,10,1,0,-1052,1), -- Level 52 Grey reference
(26222,2,10,1,0,-1053,1), -- Level 53 Grey reference
-- ---------------------------------------------------
-- Twilight Frostblade, NPC 26223
-- ---------------------------------------------------
(26223,14047,85,1,0,1,2), -- Runecloth
(26223,8952,9,1,0,1,2), -- Roasted Quail
(26223,8766,4.5,1,0,1,2), -- Morning Glory Dew
(26223,13446,6,1,0,1,2), -- Major Healing Potion
(26223,13444,3,1,0,1,2), -- Major Mana Potion
(26223,1,10,1,0,-1052,1), -- Level 52 Grey reference
(26223,2,10,1,0,-1053,1), -- Level 53 Grey reference
-- ---------------------------------------------------
-- Uncontrolled Voidwalker, NPC 16975
-- ---------------------------------------------------
(16975,23218,-80,1,0,1,1), -- Condensed Voidwalker Essence
(16975,22577,20,1,0,1,1), -- Mote of Shadow
(16975,1,90,1,0,-6000,1), -- Generic HellfirePeninsule Loot
-- ---------------------------------------------------
-- Unstable Voidwalker, NPC 20145
-- ---------------------------------------------------
(20145,29051,-100,1,0,1,1), -- QItem: Warp Nether
-- ---------------------------------------------------
-- Unyielding Footman, NPC 16904
-- ---------------------------------------------------
(16904,21877,60,1,0,1,1), -- Netherweave Cloth
(16904,14047,20,1,0,1,3), -- Runecloth
(16904,27859,8,1,0,1,1), -- Zanger Caps
(16904,28399,4,1,0,1,1), -- Filtered Draenic Water
(16904,13446,2,1,0,1,1), -- Major Healing Potion
(16904,13444,1,1,0,1,1), -- Major Mana Potion
(16904,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Unyielding Knight, NPC 16906
-- ---------------------------------------------------
(16906,28552,15,1,0,1,1), -- A Mysterious Tome
(16906,21877,60,1,0,1,1), -- Netherweave Cloth
(16906,14047,20,1,0,1,3), -- Runecloth
(16906,27859,8,1,0,1,1), -- Zanger Caps
(16906,28399,4,1,0,1,1), -- Filtered Draenic Water
(16906,13446,2,1,0,1,1), -- Major Healing Potion
(16906,13444,1,1,0,1,1), -- Major Mana Potion
(16906,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
(16906,2,2,1,0,-6003,1), -- Scroll of * Reference
-- ---------------------------------------------------
-- Unyielding Sorcerer, NPC 16905
-- ---------------------------------------------------
(16905,21877,60,1,0,1,1), -- Netherweave Cloth
(16905,14047,20,1,0,1,3), -- Runecloth
(16905,27859,8,1,0,1,1), -- Zanger Caps
(16905,28399,4,1,0,1,1), -- Filtered Draenic Water
(16905,13446,2,1,0,1,1), -- Major Healing Potion
(16905,13444,1,1,0,1,1), -- Major Mana Potion
(16905,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
(16905,2,2,1,0,-6003,1), -- Scroll of * Reference
-- ---------------------------------------------------
-- Vacillating Voidcaller, NPC 19527
-- ---------------------------------------------------
(19527,29161,-100,1,0,1,3), -- Void Ridge Soul Shard
(19527,22577,20,1,0,1,2), -- Mote of Shadow
(19527,1,50,1,1,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Void Baron Galaxis, NPC 16939
-- ---------------------------------------------------
(16939,29162,-100,1,0,1,1), -- Galaxis Soul Shard
-- ---------------------------------------------------
-- Vorakem Doomspeaker, NPC 18679
-- ---------------------------------------------------
(18679,31182,0,1,1,1,1), -- Legion Helm
(18679,31183,0,1,1,1,1), -- Legion Coif
(18679,31184,0,1,1,1,1), -- Legion Headguard
(18679,31185,0,1,1,1,1), -- Legion Crown
(18679,21877,40,1,0,1,3), -- Netherweave Cloth
(18679,27854,4,1,0,1,1), -- Smoked Talbuk Venison
(18679,28399,2.5,1,0,1,1), -- Filtered Draenic Water
(18679,13446,1,1,0,1,1), -- Major Healing Potion
(18679,13444,0.5,1,0,1,1), -- Major Healing Potion
-- ---------------------------------------------------
-- Warboss Nekrogg, NPC 19263
-- ---------------------------------------------------
(19263,21877,90,1,0,1,1), -- Netherweave Cloth
(19263,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Warbringer Arix'Amal, NPC 19298
-- ---------------------------------------------------
(19298,29795,-85,1,0,1,1), -- QItem: Burning Legion Gate Key
(19298,29588,50,1,0,1,1), -- Burning Legion Gate Key
(19298,21877,46,1,0,1,3), -- Netherweave Cloth
(19298,27854,5,1,0,1,1), -- Smoked Talbuk Venison
(19298,28399,2.5,1,0,1,1), -- Filtered Draenic Water
(19298,13446,1.4,1,0,1,1), -- Major Healing Potion
(19298,13444,0.7,1,0,1,1), -- Major Healing Potion
(19298,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Warlord Morkh, NPC 16964
-- ---------------------------------------------------
(16964,30158,-100,1,0,1,1), -- QItem: Morkh's Shattered Armor
(16964,21877,35,1,0,1,1), -- Netherweave Cloth
(16964,14047,10,1,0,1,3), -- Runecloth
(16964,27854,4,1,0,1,1), -- Smoked Talbuk Venison
(16964,28399,2,1,0,1,1), -- Filtered Draenic Water
(16964,13446,1,1,0,1,1), -- Major Healing Potion
(16964,13444,0.5,1,0,1,1), -- Major Healing Potion
(16964,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Worg Master Kruush, NPC 19442
-- ---------------------------------------------------
(19442,31374,-100,1,0,1,1), -- QItem: Worg Master's Head
(19442,30425,-25,1,0,1,1), -- QItem: Bleeding Hollow Blood
(19442,30157,-10,1,0,1,1), -- QItem: Cursed Talisman
(19442,21877,45,1,0,1,3), -- Netherweave Cloth
(19442,27854,4,1,0,1,1), -- Smoked Talbuk Venison
(19442,28399,2,1,0,1,1), -- Filtered Draenic Water
(19442,13446,1,1,0,1,1), -- Major Healing Potion
(19442,13444,0.5,1,0,1,1), -- Major Mana Potion
(19442,5759,0.1,1,0,1,1), -- Thorium Lockbox
(19442,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot
-- ---------------------------------------------------
-- Wrath Herald, NPC 24919
-- ---------------------------------------------------
(24919,34259,-100,1,0,1,1), -- Demonic Blood
(24919,21877,45,1,0,1,3), -- Netherweave Cloth
(24919,27854,4,1,0,1,1), -- Smoked Talbuk Venison
(24919,27860,2,1,0,1,1), -- Purified Draenic Water
(24919,22829,1.6,1,0,1,1), -- Super Healing Potion
(24919,22832,0.8,1,0,1,1), -- Super Mana Potion
(24919,1,100,1,0,-6002,1), -- Generic HellfirePeninsula Loot2
-- ---------------------------------------------------
-- Wrathguard, NPC 18975
-- ---------------------------------------------------
(18975,28513,-85,1,0,1,1), -- QItem: Demonic Rune Stone
(18975,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(18975,28399,4,1,0,1,1), -- Filtered Draenic Water
(18975,13446,3,1,0,1,1), -- Major Healing Potion
(18975,13444,1.5,1,0,1,1), -- Major Healing Potion
(18975,5759,0.15,1,0,1,1), -- Thorium Lockbox
(18975,1,2,1,0,-6003,1), -- Scroll of * Reference
(18975,2,90,1,0,-6000,1); -- Generic HellfirePeninsula Loot

UPDATE `creature_template` SET `lootid`=`entry` WHERE `entry` IN (26222,26223);
DELETE FROM `reference_loot_template` WHERE `entry`=34081;
