SET @FrostLotus := 12009; 

DELETE FROM `reference_loot_template` WHERE `entry` = @FrostLotus;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@FrostLotus,36908,100,1,0,1,1); -- Frost Lotus (trick)

DELETE FROM `gameobject_loot_template` WHERE `entry` IN (1414,1415,1416,1417,1418,1419,1420,1421,1424,1730,1731,1423,1732,1733,1734,2292,2512,2511,2513,2514,2515,2516,6142,6150,6151,6152,6312,6313,13945,13946,13947,13948,13949,13950,13965,13966,13967,13968,13969,13970,17201,17200,17204,17202,17203,18009,18111,18112,18113,18114,18115,18116,18117,18118,18119,19627,19628,19629,19630,22071,24093,24224,24225,24226,24227,25094,25096,25095,24228,25093,25089,34868);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- -------------------
-- -- Classic Zones -- 
-- -------------------
-- Peacebloom
(1415,2447,100,1,0,1,3), -- Peacebloom
(2512,2447,100,1,0,2,2), -- Peacebloom
-- Silverleaf
(1414, 765,100,1,0,1,3), -- Silverleaf
(1414,5056,-40,1,0,1,1), -- Root Sample (Quest Item)
(2511,765,100,1,0,2,2), -- Silverleaf
-- Earthroot
(1416,2449,100,1,0,1,3), -- Earthroot
(2513,2449,100,1,0,2,2), -- Earthroot
-- Mageroyal
(1417,785,100,1,0,1,3), -- Mageroyal
(1417,2452,20,1,0,1,2), -- Swiftthistle
(2514,785,100,1,0,2,2), -- Mageroyal
-- Briarthorn
(1418,2450,100,1,0,1,3), -- Briarthorn
(1418,2452,40,1,0,1,2), -- Swiftthistle
(2515,2450,100,1,0,2,2), -- Briarthorn
-- Bruiseweed
(1419,2453,100,1,0,1,3), -- Bruiseweed
(2516,2453,100,1,0,2,2), -- Bruiseweed
-- Strangekelp
(1733,3820,100,1,0,1,3), -- Strangekelp
-- Grave Moss
(1424,3369,100,1,0,1,3), -- Grave Moss
-- Wild Steelbloom
(1420,3355,100,1,0,1,3), -- Wild Steelbloom
-- Kingsblood
(1421,3356,100,1,0,1,3), -- Kingsblood
-- Liferoot
(1730,3357,100,1,0,1,3), -- Liferoot
-- Fadeleaf
(1731,3818,100,1,0,1,3), -- Fadeleaf
-- Goldthorn
(1734,3821,100,1,0,1,3), -- Goldthorn
-- Khadgar's Whisker
(1423,3358,100,1,0,1,3), -- Khadgar's Whisker
-- Dragon's Teeth (WINTERSBITE rename only, ids are same) 
(1732,3819,100,1,0,1,3), -- Dragon's Teeth
-- Firebloom
(2292,4625,100,1,0,1,3), -- Firebloom
-- Purple Lotus
(6142,8831,100,1,0,1,3), -- Purple Lotus
(6142,8153, 10,1,0,1,1), -- Wildvine
-- Arthas' Tears
(6150,8836,100,1,0,1,3), -- Arthas' Tears
-- Sungrass
(6151,8838,100,1,0,1,3), -- Sungrass
-- Blindweed
(6152,8839,100,1,0,1,3), -- Blindweed
-- Ghost Mushroom
(6312,8845,100,1,0,1,3), -- Ghost Mushroom
-- Gromsblood
(6313,8846,100,1,0,1,3), -- Gromsblood (Default)
-- Golden Sansam
(13945,13464,100,1,0,1,3), -- Golden Sansam (Default)
-- Dreamfoil
(13946,13463,100,1,0,1,3), -- Dreamfoil (Default)
-- Mountain Silversage
(13947,13465,100,1,0,1,3), -- Mountain Silversage (Default)
-- Sorrowmoss (Plaguebloom)
(13948,13466,100,1,0,1,3), -- Sorrowmoss
-- Black Lotus
(13950,13468,100,1,0,1,3), -- Black Lotus
-- Icecap
(13949,13467,100,1,0,1,3), -- Icecap
-- -------------------------
-- -- The Burning Crusade -- 
-- -------------------------
-- Bloodthistle
(18009,22710,100,1,0,1,3), -- Bloodthistle
-- Felweed
(18111,22785,100,1,0,1,3), -- Felweed
(18111,22575, 15,1,0,1,2), -- Mote of life
(18111,22794,  2,1,0,1,1), -- Fel Lotus
-- Dreaming Glory
(18112,22786,100,1,0,1,3), -- Dreaming Glory
(18112,22575, 15,1,0,1,3), -- Mote of life
(18112,22794,  2,1,0,1,1), -- Fel Lotus
-- Ragveil
(18113,22787,100,1,0,1,3), -- Ragveil
(18113,22575, 15,1,0,1,3), -- Mote of life
(18113,22794,  2,1,0,1,1), -- Fel Lotus
-- Flame Cap
(18114,22788,100,1,0,1,3), -- Flame Cap
(18114,22794,  2,1,0,1,1), -- Fel Lotus
(18114,35229,-25,1,0,1,1), -- Nether Residue (Questitem)
-- Terocone
(18115,22789,100,1,0,1,3), -- Terocone
(18115,22575, 15,1,0,1,3), -- Mote of life
(18115,22794,  3,1,0,1,1), -- Fel Lotus
(18115,35229,-25,1,0,1,1), -- Nether Residue (Questitem)
-- Ancient Lichen
(18116,22790,100,1,0,1,3), -- Ancient Lichen
(18116,22794,  2,1,0,1,1), -- Fel Lotus
(18116,35229,-25,1,0,1,1), -- Nether Residue (Questitem)
-- Netherbloom
(18117,22791,100,1,0,1,3), -- Netherbloom
(18117,22576, 15,1,0,1,3), -- Mote of mana
(18117,22794,  3,1,0,1,1), -- Fel Lotus
(18117,35229,-25,1,0,1,1), -- Nether Residue (Questitem)
-- Nightmare Vine
(18118,22792,100,1,0,1,3), -- Nightmare Vine
(18118,22575, 10,1,0,1,3), -- Nightmare Seed
(18118,22794,  3,1,0,1,1), -- Fel Lotus
(18118,35229,-25,1,0,1,1), -- Nether Residue (Questitem)
-- Mana Thistle
(18119,22793,100,1,0,1,3), -- Mana Thistle
(18119,22575, 15,1,0,1,3), -- Mote of life
(18119,22794,  3,1,0,1,1), -- Fel Lotus
(18119,35229,-25,1,0,1,1), -- Nether Residue (Questitem)
-- Netherdust Bush
(22071,32468,100,1,0,1,3), -- Netherdust Pollen
(22071,22576,15,1,0,1,3), -- Mote of Mana
(22071,22794,  2,1,0,1,1), -- Fel Lotus
(22071,32506,  1,1,0,1,1), -- Netherwing Egg
-- ----------------------------------
-- -- Wrath of the Lich King Zones -- 
-- ----------------------------------
-- Goldclover
(24093,36901,100,1,0,1,3), -- GoldClover
(24093,37921, 35,1,0,1,3), -- Deadnettle
(24093,37704, 20,1,0,1,3), -- Crystallized Life
(24093,36908,  5,1,0,1,1), -- Frost Lotus
-- Firethorn
(25089,39969,50,1,1,2,3), -- Fire Seed
(25089,39970,50,1,1,2,3), -- Fire Leaf 
(25089,37704,25,1,0,1,3), -- Crystallized Life
(25089,36908, 5,1,0,1,1), -- Frost Lotus
-- Tiger Lily
(24224,36904,100,1,0,1,3), -- Tiger Lily
(24224,37921, 35,1,0,1,3), -- Deadnettle
(24224,37704, 20,1,0,1,3), -- Crystallized Life
(24224,36908,  5,1,0,1,1), -- Frost Lotus
-- Talandra's Rose
(24225,36907,100,1,0,1,3), -- Talandra's 
(24225,37921, 35,1,0,1,3), -- Deadnettle
(24225,37704, 20,1,0,1,3), -- Crystallized Life
(24225,36908,  5,1,0,1,1), -- Frost LotusRose
-- Frozen Herb
-- Dragonblight
(25094,36901,60,1,1,1,3), -- Goldclover
(25094,36904,20,1,1,1,3), -- Tiger Lily
(25094,36907,20,1,1,1,3), -- Talandra's Rose
-- Zul Drak & Wintergrasp
(25095,36901,60,1,1,1,4), -- Goldclover
(25095,36904,20,1,1,1,4), -- Tiger Lily
(25095,36907,20,1,1,1,4), -- Talandra's Rose
-- The Nexus
(25096,36901,60,1,1,2,6), -- Goldclover
(25096,36904,20,1,1,2,6), -- Tiger Lily
(25096,36907,20,1,1,2,6), -- Talandra's Rose
-- Adder's Tongue
(25093,36903,100,1,0,1,3), -- Adder's Tongue
(25093,37704, 25,1,0,1,3), -- Crystallized Life
(25093,36908,  5,1,0,1,1), -- Frost Lotus
-- Lichbloom
(24226,36905,100,1,0,1,3), -- Lichbloom
(24226,37704, 25,1,0,1,3), -- Crystallized Life
(24226,36908,  5,1,0,1,1), -- Frost Lotus
-- Icethorn
(24227,36906,100,1,0,1,3), -- Icethorn
(24227,37704, 25,1,0,1,3), -- Crystallized Life
(24227,36908,  5,1,0,1,3), -- Frost Lotus
-- Frost Lotus
(24228,36908,95,1,1,1,1), -- Frost Lotus (95% for 1)
(24228,1, 5,1,1,-@FrostLotus,1), -- Frost Lotus (5% for 2)
(24228,37921, 35,1,0,1,3), -- Deadnettle
(24228,37704, 25,1,0,1,3), -- Crystallized Life
-- --------------------------------
-- -- Felwood Fel Creep Specials --
-- --------------------------------
-- Sungrass
(13965, 8838,100,1,0,1,3), -- Sungrass
(13965,11514, 50,1,0,1,2), -- Fel Creep
-- Gromsblood
(13966, 8846,100,1,0,1,3), -- Gromsblood
(13966,11514, 50,1,0,1,2), -- Fel Creep
-- Golden Sansam
(13967,13464,100,1,0,1,3), -- Golden Sansam
(13967,11514, 50,1,0,1,2), -- Fel Creep
-- Dreamfoil
(13968,13463,100,1,0,1,3), -- Dreamfoil
(13968,11514, 50,1,0,1,2), -- Fel Creep
-- Mountain Silversage
(13969,13465,100,1,0,1,3), -- Mountain Silversage
(13969,11514, 10,1,0,1,2), -- Fel Creep
-- Arthas'Tears
(13970, 8836,100,1,0,1,3), -- Arthas' Tears
(13970,11514, 50,1,0,1,3), -- Fel Creep
-- ----------------------------------
-- -- Zul Gurub Bloodvine Specials --
-- ----------------------------------
-- Purple Lotus
(17200,8831,100,1,0,1,3), -- Purple Lotus
(17200, 8153, 10,1,0,1,1), -- Wildvine
(17200,19726,15,1,0,1,3), -- Bloodvine
-- Sungrass
(17201,8838,100,1,0,1,3), -- Sungrass
(17201,19726,15,1,0,1,3), -- Bloodvine
-- Golden Sansam
(17202,13464,100,1,0,1,3), -- Golden Sansam
(17202,19726, 15,1,0,1,3), -- Bloodvine
-- Dreamfoil
(17203,13463,100,1,0,1,3), -- Dreamfoil
(17203,19726, 15,1,0,1,3), -- Bloodvine
-- Mountain Silversage
(17204,13465,100,1,0,1,3), -- Mountain Silversage
(17204,19726, 15,1,0,1,3), -- Bloodvine
-- --------------------------
-- -- Zangermarsh Specials -- 
-- --------------------------
-- Ragveil
(19627,22787,100,1,0,1,3), -- Ragveil
(19627,22575, 15,1,0,1,3), -- Mote of life
(19627,22794,  2,1,0,1,1), -- Fel Lotus
(19627,24401, 10,1,0,1,3), -- Unidentified Plant Parts
-- Felweed
(19628,22785,100,1,0,1,3), -- Felweed
(19628,22575, 15,1,0,1,2), -- Mote of life
(19628,22794,  2,1,0,1,1), -- Fel Lotus
(19628,24401, 10,1,0,1,3), -- Unidentified Plant Parts
-- Dreaming Glory
(19629,22786,100,1,0,1,3), -- Dreaming Glory
(19629,22575, 15,1,0,1,3), -- Mote of life
(19629,22794,  2,1,0,1,1), -- Fel Lotus
(19629,24401, 10,1,0,1,3), -- Unidentified Plant Parts
-- Blindweed (Zangermarsh)
(19630, 8839,100,1,0,1,3), -- Blindweed
(19630,24401, 10,1,0,1,3); -- Unidentified Plant Parts

-- Cleanups
DELETE FROM `reference_loot_template` WHERE `entry` IN (12010,12011,12012,12013,12014,12015,12016,12017); 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 4 AND `SourceGroup` IN (6150,6313,13948) AND `SourceEntry`=11514;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup` IN (12010,12012,12013,12014) AND `SourceEntry`=11514;