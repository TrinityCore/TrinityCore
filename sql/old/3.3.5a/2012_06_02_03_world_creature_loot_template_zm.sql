SET @ZM1:=6010;
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
DELETE FROM `reference_loot_template` WHERE `entry`=@ZM1;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
(@ZM1,1,30,1,0,-4000,1), -- Grey Items level 61 (ilvl 66)
(@ZM1,2,30,1,0,-4001,1), -- Grey Items level 64 (ilvl 69)
(@ZM1,3,2,1,0,-4103,1), -- Green Items level 60 (ilvl 90)
(@ZM1,4,2,1,0,-4104,1), -- Green Items level 61 (ilvl 93)
(@ZM1,5,2,1,0,-4105,1), -- Green Items level 62 (ilvl 96)
(@ZM1,6,2,1,0,-4106,1), -- Green Items level 63 (ilvl 99)
(@ZM1,7,0.5,1,0,-4203,1), -- Blue items level 63 (ilvl 94)
(@ZM1,8,0.5,1,0,-4204,1), -- Blue items level 64 (ilvl 97)
(@ZM1,9,0.5,1,0,-4205,1), -- Blue items level 65 (ilvl 97)
(@ZM1,5760,0.5,1,0,1,1); -- Eternium Lockbox
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
DELETE FROM `creature_loot_template` WHERE `entry` IN (18285,18119,18120,18117,20443,20444,18118,18121,19732,18283,20792,18088,20088,20090,18089,20089,20196,18127,18682,20197,18281,20293,20295,20294,18159,20442,18992,19174,18681,18116,18115,19733,20079,18087,19946,19947,18086,18122,18134,18214,20198,20270,18113,18114,19734,18129,19730,19729,18080,20290,20291,18282,20445,20292,18137,18136,18135,18130,18131,18133,20283,19706,18680,18213,18286,18212,18160,20324,20279,20280,18046,18044,18128,18280,18154,19519,18125,18340,20477,18138,18077,18079,20115,18132,19402,18124,18123,20387);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- "Count" Ungula, NPC 18285
-- ---------------------------------------------------
(18285,25459,-100,1,0,1,1), -- QItem: "Count" Ungula's Mandible
(18285,25434,80,1,1,1,1), -- Fractured Carapace
(18285,25436,20,1,1,1,1), -- Twitsching Leg
(18285,24493,-10,1,0,1,1), -- QItem: Marshfang Slicer Blade
(18285,1,100,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Ango'rosh Brute, NPC 18119
-- ---------------------------------------------------
(18119,21877,10,1,0,1,3), -- Netherweave Cloth
(18119,27854,1.2,1,0,1,1), -- Smoked Talbuk Venison
(18119,28399,0.6,1,0,1,1), -- Filtered Draenic Water
(18119,1,80,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Ango'rosh Mauler, NPC 18120
-- ---------------------------------------------------
(18120,24240,-50,1,0,1,1), -- QItem: Box of Mushrooms
(18120,21877,70,1,0,1,3), -- Netherweave Cloth
(18120,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(18120,28399,3,1,0,1,1), -- Filtered Draenic Water
(18120,13446,2,1,0,1,1), -- Major Healing Potion
(18120,13444,1,1,0,1,1), -- Major Mana Potion
(18120,1,2,1,0,-6003,1), -- Scroll of * VI Reference
(18120,2,85,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Ango'rosh Ogre, NPC 18117
-- ---------------------------------------------------
(18117,24238,-50,1,0,1,1), -- QItem: Mushroom Sample
(18117,21877,62,1,0,1,3), -- Netherweave Cloth
(18117,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(18117,28399,3,1,0,1,1), -- Filtered Draenic Water
(18117,13446,2,1,0,1,1), -- Major Healing Potion
(18117,13444,1,1,0,1,1), -- Major Mana Potion
(18117,1,2,1,0,-6003,1), -- Scroll of * VI Reference
(18117,2,90,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Ango'rosh Sentry, NPC 20443
-- ---------------------------------------------------
(20443,24238,-50,1,0,1,1), -- QItem: Mushroom Sample
(20443,21877,44,1,0,1,3), -- Netherweave Cloth
(20443,27854,4,1,0,1,1), -- Smoked Talbuk Venison
(20443,28399,2,1,0,1,1), -- Filtered Draenic Water
(20443,13446,1.5,1,0,1,1), -- Major Healing Potion
(20443,13444,0.75,1,0,1,1), -- Major Mana Potion
(20443,1,80,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Ango'rosh Shadowmage, NPC 20444
-- ---------------------------------------------------
(20444,24240,-40,1,0,1,1), -- QItem: Box of Mushrooms
(20444,21877,70,1,0,1,3), -- Netherweave Cloth
(20444,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(20444,28399,3,1,0,1,1), -- Filtered Draenic Water
(20444,13446,2,1,0,1,1), -- Major Healing Potion
(20444,13444,1,1,0,1,1), -- Major Mana Potion
(20444,2,85,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Ango'rosh Shaman, NPC 18118
-- ---------------------------------------------------
(18118,24238,-45,1,0,1,1), -- QItem: Mushroom Sample
(18118,21877,60,1,0,1,3), -- Netherweave Cloth
(18118,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(18118,28399,3,1,0,1,1), -- Filtered Draenic Water
(18118,13446,2,1,0,1,1), -- Major Healing Potion
(18118,13444,1,1,0,1,1), -- Major Mana Potion
(18118,2,2,1,0,-6003,1), -- Scroll of * VI Reference
(18118,1,80,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Ango'rosh Souleater, NPC 18121
-- ---------------------------------------------------
(18121,24240,-35,1,0,1,1), -- QItem: Box of Mushrooms
(18121,21877,70,1,0,1,3), -- Netherweave Cloth
(18121,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(18121,28399,3,1,0,1,1), -- Filtered Draenic Water
(18121,13446,2,1,0,1,1), -- Major Healing Potion
(18121,13444,1,1,0,1,1), -- Major Mana Potion
(18121,1,2,1,0,-6003,1), -- Scroll of * VI Reference
(18121,2,90,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Ango'rosh Warlock, NPC 19732
-- ---------------------------------------------------
(19732,21877,82,1,0,1,3), -- Netherweave Cloth
(19732,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(19732,28399,4,1,0,1,1), -- Filtered Draenic Water
(19732,13446,3,1,0,1,1), -- Major Healing Potion
(19732,13444,1.5,1,0,1,1), -- Major Mana Potion
(19732,1,100,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Blacksting, NPC 18283
-- ---------------------------------------------------
(18283,25448,-100,1,0,1,1), -- QItem: Blacksting's Stinger
(18283,25434,80,1,1,1,1), -- Fractured Carapace
(18283,25436,18,1,1,1,1), -- Twitching Leg
(18283,24372,-10,1,0,1,1), -- QItem: Diaphanous Wing
(18283,1,100,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Bloodscale Elemental, NPC 20792
-- ---------------------------------------------------
(20792,24507,81,1,1,1,1), -- Elemental Shard
(20792,24510,19,1,1,1,1), -- Primordial Core
(20792,22578,19,1,0,1,2), -- Mote of Water
(20792,7080,1,1,0,1,2), -- Essence of Water
(20792,1,95,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Bloodscale Enchantress, NPC 18088
-- ---------------------------------------------------
(18088,24401,35,1,0,1,1), -- Unidentified Plant Parts
(18088,17057,33,1,0,1,1), -- Shiny Fish Scales
(18088,17058,30,1,0,1,1), -- Fish Oil
(18088,24476,19,1,0,1,1), -- Jaggal Clam
(18088,24280,-10,1,0,1,1), -- QItem: Naga Claws
(18088,24330,-1,1,0,1,1), -- QItem: Drain Schematics
(18088,27858,4,1,0,1,3), -- Sunspring Carp
(18088,28399,2,1,0,1,1), -- Filtered Draenic Water
(18088,13446,1.5,1,0,1,1), -- Major Healing Potion
(18088,13444,0.75,1,0,1,1), -- Major Mana Potion
(18088,1,2,1,0,-6003,1), -- Scroll of * VI Reference
(18088,2,90,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Bloodscale Overseer, NPC 20088
-- ---------------------------------------------------
(20088,24280,-80,1,0,1,1), -- QItem: Naga Claws
(20088,24401,30,1,0,1,1), -- Unidentified Plant Parts
(20088,17057,25,1,0,1,1), -- Shiny Fish Scales
(20088,17058,20,1,0,1,1), -- Fish Oil
(20088,24476,15,1,0,1,1), -- Jaggal Clam
(20088,24330,-2,1,0,1,1), -- QItem: Drain Schematics
(20088,27858,4,1,0,1,3), -- Sunspring Carp
(20088,28399,2,1,0,1,1), -- Filtered Draenic Water
(20088,13446,1,1,0,1,1), -- Major Healing Potion
(20088,13444,0.5,1,0,1,1), -- Major Mana Potion
(20088,1,2,1,0,-6003,1), -- Scroll of * VI Reference
(20088,2,90,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Bloodscale Sentry, NPC 20090
-- ---------------------------------------------------
(20090,24507,68,1,1,1,1), -- Elemental Shard
(20090,24510,17,1,1,1,1), -- Primordial Core
(20090,22578,15,1,0,1,2), -- Mote of Water
(20090,7080,1,1,0,1,2), -- Essence of Water
(20090,1,95,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Bloodscale Slavedriver, NPC 18089
-- ---------------------------------------------------
(18089,24401,35,1,0,1,1), -- Unidentified Plant Parts
(18089,17057,33,1,0,1,1), -- Shiny Fish Scales
(18089,17058,30,1,0,1,1), -- Fish Oil
(18089,24476,19,1,0,1,1), -- Jaggal Clam
(18089,24280,-5,1,0,1,1), -- QItem: Naga Claws
(18089,24330,-0.5,1,0,1,1), -- QItem: Drain Schematics
(18089,27858,4,1,0,1,3), -- Sunspring Carp
(18089,28399,2,1,0,1,1), -- Filtered Draenic Water
(18089,13446,1.5,1,0,1,1), -- Major Healing Potion
(18089,13444,0.75,1,0,1,1), -- Major Mana Potion
(18089,1,1,1,0,-6003,1), -- Scroll of * VI Reference
(18089,2,90,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Bloodscale Wavecaller, NPC 20089
-- ---------------------------------------------------
(20089,24280,-80,1,0,1,1), -- QItem: Naga Claws
(20089,24401,30,1,0,1,1), -- Unidentified Plant Parts
(20089,17057,25,1,0,1,1), -- Shiny Fish Scales
(20089,17058,20,1,0,1,1), -- Fish Oil
(20089,24476,15,1,0,1,1), -- Jaggal Clam
(20089,24330,-2,1,0,1,1), -- QItem: Drain Schematics
(20089,27858,4,1,0,1,3), -- Sunspring Carp
(20089,28399,2,1,0,1,1), -- Filtered Draenic Water
(20089,13446,1,1,0,1,1), -- Major Healing Potion
(20089,13444,0.5,1,0,1,1), -- Major Mana Potion
(20089,1,2,1,0,-6003,1), -- Scroll of * VI Reference
(20089,2,90,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Bloodthirsty Marshfang, NPC 20196
-- ---------------------------------------------------
(20196,28058,81,1,1,1,1), -- Shredded Wyrm Wing
(20196,28059,19,1,1,1,1), -- Iridescent Eye
(20196,22578,19,1,0,1,1), -- Mote of Water
(20196,7080,1,1,0,1,1), -- Essence of Water
(20196,1,95,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Bog Lord, NPC 18127
-- ---------------------------------------------------
(18127,25450,82,1,0,1,1), -- Creeping Moss
(18127,25452,18,1,1,1,1), -- Blighted Fungus
(18127,24291,-35,1,0,1,1), -- QItem: Bog Lord Tendril
(18127,24401,25,1,0,1,1), -- Unidentified Plant Parts
(18127,22575,19,1,0,1,1), -- Mote of Life
(18127,1,100,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Bog Lurker, NPC 18682
-- ---------------------------------------------------
(18682,31247,0,1,1,1,1), -- Bog Pauldrons
(18682,31248,0,1,1,1,1), -- Bog Epaulets
(18682,31249,0,1,1,1,1), -- Bog Spaulders
(18682,31250,0,1,1,1,1), -- Bog Mantle
(18682,25456,80,1,2,1,1), -- Glowing Spores
(18682,25454,20,1,2,1,1), -- Luminescent Globe
-- ---------------------------------------------------
-- Bogflare Needler, NPC 20197
-- ---------------------------------------------------
(20197,25434,81,1,1,1,1), -- Fractured Carapace
(20197,25436,19,1,1,1,1), -- Twitching Leg
(20197,24372,-2,1,0,1,1), -- QItem: Diaphanous Wing
(20197,29960,0.05,1,0,1,1), -- Captured Firefly
(20197,1,100,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Boglash, NPC 18281
-- ---------------------------------------------------
(18281,25434,80,1,1,1,1), -- Fractured Carapace
(18281,25436,18,1,1,1,1), -- Twitching Leg
(18281,27676,50,1,0,1,1), -- Strange Spores
(18281,24449,-35,1,0,1,1), -- QItem: Fertile Spores
(18281,1,100,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Bogstrok Clacker, NPC 20293
-- ---------------------------------------------------
(20293,24401,40,1,0,1,1), -- Unidentified Plant Parts
(20293,17057,33,1,0,1,1), -- Shiny Fish Scales
(20293,17058,30,1,0,1,1), -- Fish Oil
(20293,24476,20,1,0,1,1), -- Jaggal Clam
(20293,27858,4,1,0,1,3), -- Sunspring Carp
(20293,28399,2,1,0,1,1), -- Filtered Draenic Water
(20293,13446,1.5,1,0,1,1), -- Major Healing Potion
(20293,13444,0.75,1,0,1,1), -- Major Mana Potion
(20293,1,100,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Bogstrok Crusher, NPC 20295
-- ---------------------------------------------------
(20295,24401,40,1,0,1,1), -- Unidentified Plant Parts
(20295,17057,33,1,0,1,1), -- Shiny Fish Scales
(20295,17058,30,1,0,1,1), -- Fish Oil
(20295,24476,20,1,0,1,1), -- Jaggal Clam
(20295,27858,4,1,0,1,3), -- Sunspring Carp
(20295,28399,2,1,0,1,1), -- Filtered Draenic Water
(20295,13446,1.5,1,0,1,1), -- Major Healing Potion
(20295,13444,0.75,1,0,1,1), -- Major Mana Potion
(20295,1,100,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Bogstrok Razorclaw, NPC 20294
-- ---------------------------------------------------
(20294,24401,40,1,0,1,1), -- Unidentified Plant Parts
(20294,17057,33,1,0,1,1), -- Shiny Fish Scales
(20294,17058,30,1,0,1,1), -- Fish Oil
(20294,24476,20,1,0,1,1), -- Jaggal Clam
(20294,27858,4,1,0,1,3), -- Sunspring Carp
(20294,28399,2,1,0,1,1), -- Filtered Draenic Water
(20294,13446,1.5,1,0,1,1), -- Major Healing Potion
(20294,13444,0.75,1,0,1,1), -- Major Mana Potion
(20294,1,100,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Boss Grog'ak, NPC 18159
-- ---------------------------------------------------
(18159,24472,-100,1,0,1,1), -- QItem: Boss Grog'ak's Head
(18159,24238,-100,1,0,1,1), -- QItem: Mushroom Sample
(18159,21877,45,1,0,1,3), -- Netherweave Cloth
(18159,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(18159,28399,3,1,0,1,1), -- Filtered Draenic Water
(18159,13446,2,1,0,1,1), -- Major Healing Potion
(18159,13444,1,1,0,1,1), -- Major Mana Potion
(18159,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Captain Bo'kar, NPC 20442
-- ---------------------------------------------------
(20442,24240,-50,1,0,1,1), -- QItem: Box of Mushrooms
(20442,21877,80,1,0,1,3), -- Netherweave Cloth
(20442,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(20442,28399,3,1,0,1,1), -- Filtered Draenic Water
(20442,13446,2,1,0,1,1), -- Major Healing Potion
(20442,13444,1,1,0,1,1), -- Major Mana Potion
(20442,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Captain Krosh, NPC 18992
-- ---------------------------------------------------
(18992,24240,-5,1,0,1,1), -- QItem: Box of Mushrooms
(18992,21877,25,1,0,1,3), -- Netherweave Cloth
(18992,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(18992,28399,3,1,0,1,1), -- Filtered Draenic Water
(18992,13446,2,1,0,1,1), -- Major Healing Potion
(18992,13444,1,1,0,1,1), -- Major Mana Potion
(18992,1,90,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Chieftain Mummaki, NPC 19174
-- ---------------------------------------------------
(19174,27943,-100,1,0,1,1), -- QItem: Chieftain Mummaki's Totem
(19174,21877,25,1,0,1,3), -- Netherweave Cloth
(19174,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(19174,28399,3,1,0,1,1), -- Filtered Draenic Water
(19174,13446,2,1,0,1,1), -- Major Healing Potion
(19174,13444,1,1,0,1,1), -- Major Mana Potion
(19174,1,90,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Coilfang Emissary, NPC 18681
-- ---------------------------------------------------
(18681,31242,0,1,1,1,1), -- Nagascale Legplates
(18681,31243,0,1,1,1,1), -- Nagascale Legguard
(18681,31244,0,1,1,1,1), -- Nagahide Pants
(18681,31245,0,1,1,1,1), -- Nagahide Leggings
(18681,17057,40,1,0,1,2), -- Shiny Fish Scales
(18681,21877,40,1,0,1,3), -- Netherweave Cloth
(18681,17058,25,1,0,1,1), -- Fish Oil
-- ---------------------------------------------------
-- Daggerfen Assassin, NPC 18116
-- ---------------------------------------------------
(18116,21877,75,1,0,1,3), -- Netherweave Cloth
(18116,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(18116,28399,4,1,0,1,1), -- Filtered Draenic Water
(18116,13446,2,1,0,1,1), -- Major Healing Potion
(18116,13444,1,1,0,1,1), -- Major Mana Potion
(18116,1,90,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Daggerfen Muckdweller, NPC 18115
-- ---------------------------------------------------
(18115,21877,75,1,0,1,3), -- Netherweave Cloth
(18115,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(18115,28399,4,1,0,1,1), -- Filtered Draenic Water
(18115,13446,2,1,0,1,1), -- Major Healing Potion
(18115,13444,1,1,0,1,1), -- Major Mana Potion
(18115,1,80,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Daggerfen Servant, NPC 19733
-- ---------------------------------------------------
(19733,17057,33,1,0,1,1), -- Shiny Fish Scales
(19733,17058,30,1,0,1,1), -- Fish Oil
(19733,24476,20,1,0,1,1), -- Jaggal Clam
(19733,27858,4,1,0,1,3), -- Sunspring Carp
(19733,28399,2,1,0,1,1), -- Filtered Draenic Water
(19733,13446,1.5,1,0,1,1), -- Major Healing Potion
(19733,13444,0.75,1,0,1,1), -- Major Mana Potion
(19733,1,100,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Darkcrest Sentry, NPC 20079
-- ---------------------------------------------------
(20079,24507,70,1,1,1,1), -- Elemental Shard
(20079,24510,15,1,1,1,1), -- Primordial Core
(20079,22578,15,1,0,1,2), -- Mote of Water
(20079,7080,1,1,0,1,2), -- Essence of Water
(20079,1,95,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Darkcrest Siren, NPC 18087
-- ---------------------------------------------------
(18087,24280,-80,1,0,1,1), -- QItem: Naga Claws
(18087,24401,30,1,0,1,1), -- Unidentified Plant Parts
(18087,17057,25,1,0,1,1), -- Shiny Fish Scales
(18087,17058,20,1,0,1,1), -- Fish Oil
(18087,24476,15,1,0,1,1), -- Jaggal Clam
(18087,27858,3,1,0,1,3), -- Sunspring Carp
(18087,28399,1.5,1,0,1,1), -- Filtered Draenic Water
(18087,13446,1,1,0,1,1), -- Major Healing Potion
(18087,13444,0.5,1,0,1,1), -- Major Mana Potion
(18087,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Darkcrest Slaver, NPC 19946
-- ---------------------------------------------------
(19946,24280,-95,1,0,1,1), -- QItem: Naga Claws
(19946,24401,30,1,0,1,1), -- Unidentified Plant Parts
(19946,17057,25,1,0,1,1), -- Shiny Fish Scales
(19946,17058,20,1,0,1,1), -- Fish Oil
(19946,24476,15,1,0,1,1), -- Jaggal Clam
(19946,27858,3,1,0,1,3), -- Sunspring Carp
(19946,28399,1.5,1,0,1,1), -- Filtered Draenic Water
(19946,13446,1,1,0,1,1), -- Major Healing Potion
(19946,13444,0.5,1,0,1,1), -- Major Mana Potion
(19946,1,2,1,0,-6003,1), -- Scroll of * VI Reference
(19946,2,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Darkcrest Sorceress, NPC 19947
-- ---------------------------------------------------
(19947,24280,-95,1,0,1,1), -- QItem: Naga Claws
(19947,24401,30,1,0,1,1), -- Unidentified Plant Parts
(19947,17057,25,1,0,1,1), -- Shiny Fish Scales
(19947,17058,20,1,0,1,1), -- Fish Oil
(19947,24476,15,1,0,1,1), -- Jaggal Clam
(19947,27858,3,1,0,1,3), -- Sunspring Carp
(19947,28399,1.5,1,0,1,1), -- Filtered Draenic Water
(19947,13446,1,1,0,1,1), -- Major Healing Potion
(19947,13444,0.5,1,0,1,1), -- Major Mana Potion
(19947,1,2,1,0,-6003,1), -- Scroll of * VI Reference
(19947,2,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Darkcrest Taskmaster, NPC 18086
-- ---------------------------------------------------
(18086,24280,-80,1,0,1,1), -- QItem: Naga Claws
(18086,24401,30,1,0,1,1), -- Unidentified Plant Parts
(18086,17057,25,1,0,1,1), -- Shiny Fish Scales
(18086,17058,20,1,0,1,1), -- Fish Oil
(18086,24476,15,1,0,1,1), -- Jaggal Clam
(18086,27858,3,1,0,1,3), -- Sunspring Carp
(18086,28399,1.5,1,0,1,1), -- Filtered Draenic Water
(18086,13446,1,1,0,1,1), -- Major Healing Potion
(18086,13444,0.5,1,0,1,1), -- Major Mana Potion
(18086,1,2,1,0,-6003,1), -- Scroll of * VI Reference
(18086,2,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Dreghood Drudge, NPC 18122
-- ---------------------------------------------------
(18122,21877,60,1,0,1,3), -- Netherweave Cloth
(18122,24401,35,1,0,1,1), -- Unidentified Plant Parts
(18122,27854,3,1,0,1,1), -- Smoked Talbuk Venison
(18122,28399,1.5,1,0,1,1), -- Filtered Draenic Water
(18122,13446,1,1,0,1,1), -- Major Healing Potion
(18122,13444,0.5,1,0,1,1), -- Major Mana Potion
(18122,2,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Fen Strider, NPC 18134
-- ---------------------------------------------------
(18134,25434,81,1,1,1,1), -- Fractured Carapace
(18134,25436,19,1,1,1,1), -- Twitching Leg
(18134,27676,50,1,0,1,1), -- Strange Spores
(18134,24449,-35,1,0,1,1), -- QItem: Fertile Spores
(18134,24427,20,1,0,1,1), -- QItem: Fen Strider Tentacle
(18134,1,100,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Fenclaw Thrasher, NPC 18214
-- ---------------------------------------------------
(18214,25429,81,1,1,1,1), -- Grime-Encrusted Scale
(18214,25431,19,1,1,1,1), -- Ripped Fin
(18214,24486,-50,1,0,1,1), -- QItem: Fenclaw Hide
(18214,24401,25,1,0,1,1), -- Unidentified Plant Parts
(18214,24476,15,1,0,1,1), -- Jaggal Clam
(18214,24375,-15,1,0,1,1), -- QItem: Thick Hydra Scale
(18214,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Fenglow Stinger, NPC 20198
-- ---------------------------------------------------
(20198,25434,80,1,1,1,1), -- Fractured Carapace
(20198,25436,20,1,1,1,1), -- Twitching Leg
(20198,24372,-10,1,0,1,1), -- QItem: Diaphanous Wing
(20198,24401,25,1,0,1,1), -- Unidentified Plant Parts
(20198,24485,-30,1,0,1,1), -- QItem: Marshlight Bleeder Venom
(20198,1,100,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Feralfen Druid, NPC 20270
-- ---------------------------------------------------
(20270,24497,-25,1,0,1,1), -- QItem: Feralfen Protection Totem
(20270,21877,60,1,0,1,3), -- Netherweave Cloth
(20270,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(20270,28399,3,1,0,1,1), -- Filtered Draenic Water
(20270,13446,2,1,0,1,1), -- Major Healing Potion
(20270,13444,1,1,0,1,1), -- Major Mana Potion
(20270,1,80,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
(20270,2,2,1,0,-6003,1), -- Scroll of * VI Reference
-- ---------------------------------------------------
-- Feralfen Hunter, NPC 18113
-- ---------------------------------------------------
(18113,24497,-10,1,0,1,1), -- QItem: Feralfen Protection Totem
(18113,21877,60,1,0,1,3), -- Netherweave Cloth
(18113,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(18113,28399,3,1,0,1,1), -- Filtered Draenic Water
(18113,13446,2,1,0,1,1), -- Major Healing Potion
(18113,13444,1,1,0,1,1), -- Major Mana Potion
(18113,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
(18113,2,2,1,0,-6003,1), -- Scroll of * VI Reference
-- ---------------------------------------------------
-- Feralfen Mystic, NPC 18114
-- ---------------------------------------------------
(18114,24497,-40,1,0,1,1), -- QItem: Feralfen Protection Totem
(18114,21877,60,1,0,1,3), -- Netherweave Cloth
(18114,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(18114,28399,3,1,0,1,1), -- Filtered Draenic Water
(18114,13446,2,1,0,1,1), -- Major Healing Potion
(18114,13444,1,1,0,1,1), -- Major Mana Potion
(18114,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
(18114,2,2,1,0,-6003,1), -- Scroll of * VI Reference
-- ---------------------------------------------------
-- Fungal Giant, NPC 19734
-- ---------------------------------------------------
(19734,25450,81,1,0,1,1), -- Creeping Moss
(19734,25452,19,1,1,1,1), -- Blighted Fungus
(19734,24401,25,1,0,1,1), -- Unidentified Plant Parts
(19734,22575,19,1,0,1,3), -- Mote of Life
(19734,12803,1,1,0,1,1), -- Living Essence
(19734,1,100,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Greater Sporebat, NPC 18129
-- ---------------------------------------------------
(18129,25456,81,1,1,1,1), -- Glowing Spores
(18129,25454,19,1,1,1,1), -- Luminescent Globe
(18129,27676,50,1,0,1,1), -- Strange Spores
(18129,24449,-35,1,0,1,1), -- QItem: Fertile Spores
(18129,24401,26,1,0,1,1), -- Unidentified Plant Parts
(18129,1,95,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Ironspine Gazer, NPC 19730
-- ---------------------------------------------------
(19730,1701,80,1,1,1,1), -- Curved Basilisk Claw
(19730,11389,17,1,1,1,1), -- Shimmering Basilisk Sking
(19730,29553,2,1,1,1,1), -- Basilisk Guts
(19730,29554,1,1,1,1,1), -- Encrusted Basilisk Skin
(19730,27677,45,1,0,1,1), -- Chunk O'Basilisk
(19730,1,100,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Ironspine Threshalisk, NPC 19729
-- ---------------------------------------------------
(19729,1701,80,1,1,1,1), -- Curved Basilisk Claw
(19729,11389,17,1,1,1,1), -- Shimmering Basilisk Sking
(19729,29553,2,1,1,1,1), -- Basilisk Guts
(19729,29554,1,1,1,1,1), -- Encrusted Basilisk Skin
(19729,1,100,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Kataru, NPC 18080
-- ---------------------------------------------------
(18080,21877,60,1,0,1,3), -- Netherweave Cloth
(18080,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(18080,28399,3,1,0,1,1), -- Filtered Draenic Water
(18080,13446,2,1,0,1,1), -- Major Healing Potion
(18080,13444,1,1,0,1,1), -- Major Mana Potion
(18080,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Lagoon Eel, NPC 20290
-- ---------------------------------------------------
(20290,28058,81,1,1,1,1), -- Shredded Wyrm Wing
(20290,28059,19,1,1,1,1), -- Iridescent Eye
(20290,22578,19,1,0,1,1), -- Mote of Water
(20290,7080,1,1,0,1,1), -- Essence of Water
(20290,1,85,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Lagoon Walker, NPC 20291
-- ---------------------------------------------------
(20291,25450,82,1,0,1,1), -- Creeping Moss
(20291,25452,18,1,1,1,1), -- Blighted Fungus
(20291,24401,25,1,0,1,1), -- Unidentified Plant Parts
(20291,22575,19,1,0,1,2), -- Mote of Life
(20291,12803,1.5,1,0,1,2), -- Living Essence
(20291,1,100,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Lord Klaq, NPC 18282
-- ---------------------------------------------------
(18282,24401,30,1,0,1,1), -- Unidentified Plant Parts
(18282,17057,30,1,0,1,1), -- Shiny Fish Scales
(18282,17058,25,1,0,1,1), -- Fish Oil
(18282,24476,15,1,0,1,1), -- Jaggal Clam
(18282,27858,4,1,0,1,3), -- Sunspring Carp
(18282,28399,2,1,0,1,1), -- Filtered Draenic Water
(18282,13446,1,1,0,1,1), -- Major Healing Potion
(18282,13444,0.5,1,0,1,1), -- Major Mana Potion
(18282,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Mal'druk the Soulrender, NPC 20445
-- ---------------------------------------------------
(20445,21877,72,1,0,1,3), -- Netherweave Cloth
(20445,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(20445,28399,8,1,0,1,1), -- Filtered Draenic Water
(20445,13446,2,1,0,1,1), -- Major Healing Potion
(20445,13444,1,1,0,1,1), -- Major Mana Potion
(20445,1,100,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Marsh Baron Brok, NPC 20292
-- ---------------------------------------------------
(20292,25450,80,1,0,1,1), -- Creeping Moss
(20292,25452,20,1,1,1,1), -- Blighted Fungus
(20292,24401,25,1,0,1,1), -- Unidentified Plant Parts
(20292,22575,19,1,0,1,2), -- Mote of Life
(20292,12803,1,1,0,1,2), -- Living Essence
(20292,1,100,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Marsh Dredger, NPC 18137
-- ---------------------------------------------------
(18137,24401,35,1,0,1,1), -- Unidentified Plant Parts
(18137,17057,33,1,0,1,1), -- Shiny Fish Scales
(18137,17058,30,1,0,1,1), -- Fish Oil
(18137,24476,20,1,0,1,1), -- Jaggal Clam
(18137,27858,4,1,0,1,3), -- Sunspring Carp
(18137,28399,2,1,0,1,1), -- Filtered Draenic Water
(18137,13446,1,1,0,1,1), -- Major Healing Potion
(18137,13444,0.5,1,0,1,1), -- Major Mana Potion
(18137,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
(18137,2,2,1,0,-6003,1), -- Scroll of * VI Reference
-- ---------------------------------------------------
-- Marsh Lurker, NPC 18136
-- ---------------------------------------------------
(18136,24401,35,1,0,1,1), -- Unidentified Plant Parts
(18136,17057,33,1,0,1,1), -- Shiny Fish Scales
(18136,17058,30,1,0,1,1), -- Fish Oil
(18136,24476,20,1,0,1,1), -- Jaggal Clam
(18136,27858,4,1,0,1,3), -- Sunspring Carp
(18136,28399,2,1,0,1,1), -- Filtered Draenic Water
(18136,13446,1,1,0,1,1), -- Major Healing Potion
(18136,13444,0.5,1,0,1,1), -- Major Mana Potion
(18136,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
(18136,2,2,1,0,-6003,1), -- Scroll of * VI Reference
-- ---------------------------------------------------
-- Marsh Walker, NPC 18135
-- ---------------------------------------------------
(18135,25434,81,1,1,1,1), -- Fractured Carapace
(18135,25436,19,1,1,1,1), -- Twitching Leg
(18135,27676,50,1,0,1,1), -- Strange Spores
(18135,24449,-35,1,0,1,1), -- QItem: Fertile Spores
(18135,1,100,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Marshfang Ripper, NPC 18130
-- ---------------------------------------------------
(18130,25434,81,1,1,1,1), -- Fractured Carapace
(18130,25436,19,1,1,1,1), -- Twitching Leg
(18130,24401,25,1,0,1,1), -- Unidentified Plant Parts
(18130,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Marshfang Slicer, NPC 18131
-- ---------------------------------------------------
(18131,24493,-100,1,0,1,1), -- QItem: Marshfang Slicer Blade
(18131,25434,81,1,1,1,1), -- Fractured Carapace
(18131,25436,19,1,1,1,1), -- Twitching Leg
(18131,24401,25,1,0,1,1), -- Unidentified Plant Parts
(18131,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Marshlight Bleeder, NPC 18133
-- ---------------------------------------------------
(18133,25434,80,1,1,1,1), -- Fractured Carapace
(18133,25436,20,1,1,1,1), -- Twitching Leg
(18133,24401,25,1,0,1,1), -- Unidentified Plant Parts
(18133,24372,-10,1,0,1,1), -- QItem: Diaphanous Wing
(18133,24485,-30,1,0,1,1), -- QItem: Marshlight Bleeder Venom
(18133,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Marshrock Stomper, NPC 20283
-- ---------------------------------------------------
(20283,1701,80,1,1,1,1), -- Curved Basilisk Claw
(20283,11389,17,1,1,1,1), -- Shimmering Basilisk Sking
(20283,29553,2,1,1,1,1), -- Basilisk Guts
(20283,29554,1,1,1,1,1), -- Encrusted Basilisk Skin
(20283,27677,45,1,0,1,1), -- Chunk O'Basilisk
(20283,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Marshrock Threshalisk, NPC 19706
-- ---------------------------------------------------
(19706,1701,81,1,1,1,1), -- Curved Basilisk Claw
(19706,11389,18,1,1,1,1), -- Shimmering Basilisk Sking
(19706,29553,1,1,1,1,1), -- Basilisk Guts
(19706,27677,50,1,0,1,1), -- Chunk O'Basilisk
(19706,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Marticar, NPC 18680
-- ---------------------------------------------------
(18680,31254,100,1,0,1,1), -- Striderhide Cloak
(18680,25456,80,1,1,2,4), -- Glowing Spores
(18680,25454,20,1,1,2,4), -- Luminescent Glove
-- ---------------------------------------------------
-- Mire Hydra, NPC 18213
-- ---------------------------------------------------
(18213,25429,81,1,1,1,1), -- Grime-Encrusted Scale
(18213,25431,19,1,1,1,1), -- Ripped Fin
(18213,24375,-100,1,0,1,1), -- QItem: Thick Hydra Scale
(18213,24401,25,1,0,1,1), -- Unidentified Plant Parts
(18213,24476,15,1,0,1,1), -- Jaggal Clam
(18213,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Mragesh, NPC 18286
-- ---------------------------------------------------
(18286,25429,81,1,1,1,1), -- Grime-Encrusted Scale
(18286,25431,19,1,1,1,1), -- Ripped Fin
(18286,24401,25,1,0,1,1), -- Unidentified Plant Parts
(18286,24476,15,1,0,1,1), -- Jaggal Clam
(18286,1,100,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Mudfin Frenzy, NPC 18212
-- ---------------------------------------------------
(18212,25429,80,1,1,1,1), -- Grime-Encrusted Scale
(18212,25431,20,1,1,1,1), -- Ripped Fin
(18212,24401,25,1,0,1,1), -- Unidentified Plant Parts
(18212,1,10,1,0,-4000,1), -- Grey lvl 61 Item
(18212,2,10,1,0,-4001,1), -- Grey lvl 64 Item
-- ---------------------------------------------------
-- Overlord Gorefist, NPC 18160
-- ---------------------------------------------------
(18160,24240,-20,1,0,1,1), -- QItem: Box of Mushrooms
(18160,21877,55,1,0,1,3), -- Netherweave Cloth
(18160,27854,6,1,0,1,1), -- Smoked Talbuk Venison
(18160,28399,3,1,0,1,1), -- Filtered Draenic Water
(18160,13446,2,1,0,1,1), -- Major Healing Potion
(18160,13444,1,1,0,1,1), -- Major Mana Potion
(18160,2,85,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Parched Hydra, NPC 20324
-- ---------------------------------------------------
(20324,25429,81,1,1,1,1), -- Grime-Encrusted Scale
(20324,25431,19,1,1,1,1), -- Ripped Fin
(20324,24401,25,1,0,1,1), -- Unidentified Plant Parts
(20324,24375,-100,1,0,1,1), -- QItem: Thick Hydra Scale
(20324,24476,15,1,0,1,1), -- Jaggal Clam
(20324,29480,-15,1,0,1,1), -- QItem: Parched Hydra Sample
(20324,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Ragestone Threshalisk, NPC 20279
-- ---------------------------------------------------
(20279,1701,80,1,1,1,1), -- Curved Basilisk Claw
(20279,11389,17,1,1,1,1), -- Shimmering Basilisk Sking
(20279,29553,2,1,1,1,1), -- Basilisk Guts
(20279,29554,1,1,1,1,1), -- Encrusted Basilisk Skin
(20279,27677,45,1,0,1,1), -- Chunk O'Basilisk
(20279,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Ragestone Trampler, NPC 20280
-- ---------------------------------------------------
(20280,1701,80,1,1,1,1), -- Curved Basilisk Claw
(20280,11389,17,1,1,1,1), -- Shimmering Basilisk Sking
(20280,29553,2,1,1,1,1), -- Basilisk Guts
(20280,29554,1,1,1,1,1), -- Encrusted Basilisk Skin
(20280,27677,45,1,0,1,1), -- Chunk O'Basilisk
(20280,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Rajah Haghazed, NPC 18046
-- ---------------------------------------------------
(18046,24280,-65,1,0,1,1), -- QItem: Naga Claws
(18046,24476,26,1,0,1,1), -- Jaggal Clam
(18046,17057,25,1,0,1,1), -- Shiny Fish Scales
(18046,17058,20,1,0,1,1), -- Fish Oil
(18046,27858,4,1,0,1,3), -- Sunspring Carp
(18046,28399,2,1,0,1,1), -- Filtered Draenic Water
(18046,13446,1,1,0,1,1), -- Major Healing Potion
(18046,13444,0.5,1,0,1,1), -- Major Mana Potion
(18046,2,90,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Rajis Fyashe, NPC 18044
-- ---------------------------------------------------
(18044,24280,-65,1,0,1,1), -- QItem: Naga Claws
(18044,24476,26,1,0,1,1), -- Jaggal Clam
(18044,17057,25,1,0,1,1), -- Shiny Fish Scales
(18044,17058,20,1,0,1,1), -- Fish Oil
(18044,27858,4,1,0,1,3), -- Sunspring Carp
(18044,28399,2,1,0,1,1), -- Filtered Draenic Water
(18044,13446,1,1,0,1,1), -- Major Healing Potion
(18044,13444,0.5,1,0,1,1), -- Major Mana Potion
(18044,2,90,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Sporebat, NPC 18128
-- ---------------------------------------------------
(18128,25456,80,1,1,1,1), -- Glowing Spores
(18128,25454,20,1,1,1,1), -- Luminescent Globe
(18128,27676,50,1,0,1,1), -- Strange Spores
(18128,24449,-35,1,0,1,1), -- QItem: Fertile Spores
(18128,24401,26,1,0,1,1), -- Unidentified Plant Parts
(18128,24426,-20,1,0,1,1), -- QItem: Sporebat Eye
(18128,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Sporewing, NPC 18280
-- ---------------------------------------------------
(18280,25456,80,1,1,1,1), -- Glowing Spores
(18280,25454,20,1,1,1,1), -- Luminescent Globe
(18280,27676,50,1,0,1,1), -- Strange Spores
(18280,24449,-35,1,0,1,1), -- QItem: Fertile Spores
(18280,24401,26,1,0,1,1), -- Unidentified Plant Parts
(18280,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Ssslith, NPC 18154
-- ---------------------------------------------------
(18154,24476,30,1,0,1,1), -- Jaggal Clam
(18154,17057,25,1,0,1,1), -- Shiny Fish Scales
(18154,17058,20,1,0,1,1), -- Fish Oil
(18154,27858,4,1,0,1,3), -- Sunspring Carp
(18154,28399,2,1,0,1,1), -- Filtered Draenic Water
(18154,1,100,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Starving Bog Lord, NPC 19519
-- ---------------------------------------------------
(19519,25450,80,1,0,1,1), -- Creeping Moss
(19519,25452,20,1,1,1,1), -- Blighted Fungus
(19519,24291,-20,1,0,1,1), -- QItem: Bog Lord Tendril
(19519,24401,25,1,0,1,1), -- Unidentified Plant Parts
(19519,22575,19,1,0,1,1), -- Mote of Life
(19519,12803,1,1,0,1,1), -- Living Essence
(19519,1,100,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Starving Fungal Giant, NPC 18125
-- ---------------------------------------------------
(18125,25450,80,1,0,1,1), -- Creeping Moss
(18125,25452,20,1,1,1,1), -- Blighted Fungus
(18125,24291,-20,1,0,1,1), -- QItem: Bog Lord Tendril
(18125,24401,25,1,0,1,1), -- Unidentified Plant Parts
(18125,22575,19,1,0,1,1), -- Mote of Life
(18125,12803,1,1,0,1,1), -- Living Essence
(18125,1,100,1,0,-6010,1), -- Generic Zangermarsh Loot
-- ---------------------------------------------------
-- Steam Pump Overseer, NPC 18340
-- ---------------------------------------------------
(18340,24280,-45,1,0,1,1), -- QItem: Naga Claws
(18340,24401,35,1,0,1,1), -- Unidentified Plant Parts
(18340,17057,30,1,0,1,1), -- Shiny Fish Scales
(18340,17058,25,1,0,1,1), -- Fish Oil
(18340,24476,15,1,0,1,1), -- Jaggal Clam
(18340,24330,-40,1,0,1,1), -- QItem: Drain Schematics
(18340,27858,4,1,0,1,3), -- Sunspring Carp
(18340,28399,2,1,0,1,1), -- Filtered Draenic Water
(18340,13446,1.5,1,0,1,1), -- Major Healing Potion
(18340,13444,0.75,1,0,1,1), -- Major Mana Potion
(18340,1,2,1,0,-6003,1), -- Scroll of * VI Reference
(18340,2,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Terrorclaw, NPC 20477
-- ---------------------------------------------------
(20477,17057,34,1,0,1,1), -- Shiny Fish Scales
(20477,24401,34,1,0,1,1), -- Unidentified Plant Parts
(20477,17058,30,1,0,1,1), -- Fish Oil
(20477,24476,20,1,0,1,1), -- Jaggal Clam
(20477,27858,4,1,0,1,3), -- Sunspring Carp
(20477,28399,2,1,0,1,1), -- Filtered Draenic Water
(20477,13446,1.5,1,0,1,1), -- Major Healing Potion
(20477,13444,0.75,1,0,1,1), -- Major Mana Potion
(20477,1,90,1,0,-6001,1), -- Generic HellfirePeninsula Loot1 (YES FOR ZM)
-- ---------------------------------------------------
-- Umbrafen Eel, NPC 18138
-- ---------------------------------------------------
(18138,25429,80,1,1,1,1), -- Grime-Encrusted Scale
(18138,25431,20,1,1,1,1), -- Ripped Fin
(18138,24374,-40,1,0,1,1), -- QItem: Eel Filet
(18138,1,90,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Umbrafen Oracle, NPC 18077
-- ---------------------------------------------------
(18077,21877,80,1,0,1,3), -- Netherweave Cloth
(18077,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(18077,28399,4,1,0,1,1), -- Filtered Draenic Water
(18077,13446,2,1,0,1,1), -- Major Healing Potion
(18077,13444,1,1,0,1,1), -- Major Mana Potion
(18077,2,2,1,0,-6003,1), -- Scroll of * VI Reference
(18077,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Umbrafen Seer, NPC 18079
-- ---------------------------------------------------
(18079,21877,80,1,0,1,3), -- Netherweave Cloth
(18079,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(18079,28399,4,1,0,1,1), -- Filtered Draenic Water
(18079,13446,2,1,0,1,1), -- Major Healing Potion
(18079,13444,1,1,0,1,1), -- Major Mana Potion
(18079,2,2,1,0,-6003,1), -- Scroll of * VI Reference
(18079,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Umbrafen Witchdoctor, NPC 20115
-- ---------------------------------------------------
(20115,21877,80,1,0,1,3), -- Netherweave Cloth
(20115,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(20115,28399,4,1,0,1,1), -- Filtered Draenic Water
(20115,13446,2,1,0,1,1), -- Major Healing Potion
(20115,13444,1,1,0,1,1), -- Major Mana Potion
(20115,2,2,1,0,-6003,1), -- Scroll of * VI Reference
(20115,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Umbraglow Stinger, NPC 18132
-- ---------------------------------------------------
(18132,25434,80,1,1,1,1), -- Fractured Carapace
(18132,25436,20,1,1,1,1), -- Twitching Leg
(18132,24372,-40,1,0,1,1), -- QItem: Diaphanous Wing
(18132,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Withered Bog Lord, NPC 19402
-- ---------------------------------------------------
(19402,25450,80,1,0,1,1), -- Creeping Moss
(19402,25452,20,1,1,1,1), -- Blighted Fungus
(19402,24291,-30,1,0,1,1), -- QItem: Bog Lord Tendril
(19402,24401,25,1,0,1,1), -- Unidentified Plant Parts
(19402,22575,19,1,0,1,1), -- Mote of Life
(19402,29481,-15,1,0,1,1), -- QItem: Withered Bog Lord Sample
(19402,12803,1,1,0,1,1), -- Living Essence
(19402,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Withered Giant, NPC 18124
-- ---------------------------------------------------
(18124,25450,80,1,0,1,1), -- Creeping Moss
(18124,25452,20,1,1,1,1), -- Blighted Fungus
(18124,24401,25,1,0,1,1), -- Unidentified Plant Parts
(18124,24291,-20,1,0,1,1), -- QItem: Bog Lord Tendril
(18124,22575,19,1,0,1,1), -- Mote of Life
(18124,24373,-5,1,0,1,1), -- QItem: Scout Jyoba's Report
(18124,24483,2,1,0,1,1), -- Withered Basidium Ally
(18124,24484,2,1,0,1,1), -- Withered Basidium Horde
(18124,12803,1,1,0,1,1), -- Living Essence
(18124,1,100,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Wrekt Slave, NPC 18123
-- ---------------------------------------------------
(18123,21877,75,1,0,1,3), -- Netherweave Cloth
(18123,27854,8,1,0,1,1), -- Smoked Talbuk Venison
(18123,28399,4,1,0,1,1), -- Filtered Draenic Water
(18123,13446,2,1,0,1,1), -- Major Healing Potion
(18123,13444,1,1,0,1,1), -- Major Mana Potion
(18123,2,2,1,0,-6003,1), -- Scroll of * VI Reference
(18123,1,80,1,0,-6000,1), -- Generic HellfirePeninsula Loot (YES FOR ZM)
-- ---------------------------------------------------
-- Young Sporebat, NPC 20387
-- ---------------------------------------------------
(20387,25456,80,1,1,1,1), -- Glowing Spores
(20387,25454,20,1,1,1,1), -- Luminescent Globe
(20387,27676,50,1,0,1,1), -- Strange Spores
(20387,24401,26,1,0,1,1), -- Unidentified Plant Parts
(20387,1,90,1,0,-6000,1); -- Generic HellfirePeninsula Loot (YES FOR ZM)
