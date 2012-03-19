-- Ulduar Trash Loot including Skinning, Mining and Herbalism
-- Using Reference Loot for Epic Items for 10 and 25-Mode
-- Using Skinloot Templates for Mining and Herbalism
-- Data Sources from old.wowhead.com, modified by Hirndille

-- Skinloot Templates for Mining and Herbalism, especially for Ulduar Trash

-- Mining for NPCs 34085 and 34186
DELETE FROM `skinning_loot_template` WHERE entry = 100009;
INSERT INTO `skinning_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 100009, 39220, 98, 1, 0, 6, 8 ), -- Geodesic Fragments 
( 100009, 36909, 25, 1, 0, 5, 9 ), -- Cobalt Ore
( 100009, 37701, 25, 1, 0, 5, 8 ), -- Crystallized Earth
( 100009, 36923,  5, 1, 0, 1, 1 ), -- Chalcedony
( 100009, 36921,  4, 1, 0, 1, 1 ), -- Autumns Glow
( 100009, 36933,  4, 1, 0, 1, 1 ), -- Forest Emerald
( 100009, 36930,  4, 1, 0, 1, 1 ), -- Monarch Topaz
( 100009, 36918,  4, 1, 0, 1, 1 ), -- Scarlet Ruby
( 100009, 33927,  4, 1, 0, 1, 1 ), -- Twilight Opal
( 100009, 36917,  4, 1, 0, 1, 1 ), -- Bloodstone
( 100009, 36932,  4, 1, 0, 1, 1 ), -- Dark Jade
( 100009, 36926,  4, 1, 0, 1, 1 ), -- Shadow Crystal
( 100009, 36920,  4, 1, 0, 1, 1 ), -- Sun Crystal
( 100009, 36924,  3, 1, 0, 1, 1 ), -- Sky Sapphire
( 100009, 36929,  3, 1, 0, 1, 1 )  -- Huge Citrine
;
-- Mining for Ulduar Trash
DELETE FROM `skinning_loot_template` WHERE entry = 100011;
INSERT INTO `skinning_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 100011, 39220, 100, 1, 0, 1, 1 ), -- Geodesic Fragments
( 100011, 37701,   9, 1, 0, 1, 2 )  -- Crystallized Earth
;
-- Herbalism for Ulduar Trash
DELETE FROM `skinning_loot_template` WHERE entry = 100010;
INSERT INTO `skinning_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 100010, 39516, 39, 1, 0, 1, 1 ), -- Frosty Mushroom
( 100010, 35947, 28, 1, 0, 1, 1 ), -- Sparkling Frostcap
( 100010, 36901, 25, 1, 0, 1, 1 ), -- Goldclover
( 100010, 37704,  4, 1, 0, 1, 2 ), -- Crystallized Life
( 100010, 36904,  4, 1, 0, 1, 1 ), -- Tiger Lily
( 100010, 36903,  3, 1, 0, 1, 1 ), -- Adders Tongue
( 100010, 36905,  3, 1, 0, 1, 1 ), -- Lichbloom
( 100010, 36907,  3, 1, 0, 1, 1 ), -- Talandras Rose
( 100010, 36906,  2, 1, 0, 1, 1 ) -- Icethorn
;
-- ReferenzLoot 10mann
DELETE FROM `reference_loot_template` WHERE entry = 90003;
INSERT INTO `reference_loot_template` (entry,item,ChanceOrQuestChance,lootmode,groupid,mincountOrRef,maxcount)
VALUES
(90003,46339,0,1,1,1,1),
(90003,46340,0,1,1,1,1),
(90003,46341,0,1,1,1,1),
(90003,46342,0,1,1,1,1),
(90003,46343,0,1,1,1,1),
(90003,46344,0,1,1,1,1),
(90003,46345,0,1,1,1,1),
(90003,46346,0,1,1,1,1),
(90003,46347,0,1,1,1,1),
(90003,46350,0,1,1,1,1),
(90003,46351,0,1,1,1,1),

(90003,33470,25,1,0,2,7), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
(90003,43852,15,1,0,1,1); -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal


-- ReferenzLoot 25mann
DELETE FROM `reference_loot_template` WHERE entry = 90004;
INSERT INTO `reference_loot_template` (entry,item,ChanceOrQuestChance,lootmode,groupid,mincountOrRef,maxcount)
VALUES
(90004,45538,0,1,1,1,1),
(90004,45539,0,1,1,1,1),
(90004,45540,0,1,1,1,1),
(90004,45541,0,1,1,1,1),
(90004,45542,0,1,1,1,1),
(90004,45543,0,1,1,1,1),
(90004,45544,0,1,1,1,1),
(90004,45547,0,1,1,1,1),
(90004,45548,0,1,1,1,1),
(90004,45549,0,1,1,1,1),
(90004,45605,0,1,1,1,1),

(90004,33470,25,1,0,2,7), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
(90004,43852,15,1,0,1,1), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
(90004,33454, 2,1,0,1,1); -- Salted Venison, item level: 75, quality: NORMAL//WHITE, mode: Normal 25

-- Loot for Elder Ironbranch, ID: 32913

UPDATE `creature_template` SET `skinloot`=100010 WHERE `entry`=32913;
UPDATE `creature_template` SET `type_flags` = `type_flags` |256 WHERE `entry`=32913; -- Make mob herbable

-- Loot for Elder Stonebark, ID: 32914

DELETE FROM `creature_loot_template` where `entry` = 32914;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 32914, 36904, 0.1, 1, 0, 1, 1 ) -- Tiger Lily, item level: 72, quality: NORMAL//WHITE, mode: Outdoor/Dungeon
;
UPDATE `creature_template` SET `skinloot`=100010 WHERE `entry`=32914;
UPDATE `creature_template` SET `type_flags` = `type_flags` |256 WHERE `entry`=32914; -- Make mob herbable

-- Loot for Elder Brightleaf, ID: 32915

DELETE FROM `creature_loot_template` where `entry` = 32915;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 32915, 37704, 0.1, 1, 0, 2, 2 ) -- Crystallized Life, item level: 75, quality: NORMAL//WHITE, mode: Outdoor/Dungeon
;
UPDATE `creature_template` SET `skinloot`=100010 WHERE `entry`=32915;
UPDATE `creature_template` SET `type_flags` = `type_flags` |256 WHERE `entry`=32915; -- Make mob herbable

-- Loot for Corrupted Servitor, ID: 33354 and 33729 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33354;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33354, 36174, 1.4, 1, 0, 1, 1 ), -- Geist Gloves, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
( 33354, 90003 ,   3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33729;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33729, 33422, 0.8, 1, 0, 1, 1 ), -- Shattered Bow, item level: 125, quality: POOR//GREY, mode: Normal 25
( 33729, 90004 ,   3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
UPDATE `creature_template` SET `skinloot`=100010 WHERE `entry`=33354;
UPDATE `creature_template` SET `skinloot`=100010 WHERE `entry`=33729;
UPDATE `creature_template` SET `type_flags` = `type_flags` |256 WHERE `entry`=33354; -- Make mob herbable
UPDATE `creature_template` SET `type_flags` = `type_flags` |256 WHERE `entry`=33729; -- Make mob herbable

-- Loot for Mangrove Ent, ID: 33525 and 33735 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33525;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33525, 33470, 25, 1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 33525, 43852, 15, 1, 0, 1, 1 ) -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
;

DELETE FROM `creature_loot_template` where `entry` = 33735;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33735, 33470, 25,  1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 33735, 43852, 15,  1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 33735, 33454,  2, 80, 0, 1, 1 ), -- Salted Venison, item level: 75, quality: NORMAL//WHITE, mode: Unknown 80
( 33735, 36269,  1,  1, 0, 1, 1 ) -- Ulduar Breastplate, item level: 174, quality: UNCOMMON//GREEN, mode: Normal 25
;
UPDATE `creature_template` SET `skinloot`=100010 WHERE `entry`=33525;
UPDATE `creature_template` SET `skinloot`=100010 WHERE `entry`=33735;
UPDATE `creature_template` SET `type_flags` = `type_flags` |256 WHERE `entry`=33525; -- Make mob herbable
UPDATE `creature_template` SET `type_flags` = `type_flags` |256 WHERE `entry`=33735; -- Make mob herbable

-- Loot for Ironroot Lasher, ID: 33526 and 33734 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33526;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33526, 33470,  25, 1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 33526, 43852,  15, 1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 33526, 36570, 0.7, 1, 0, 1, 1 ) -- Corrupted Scythes, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
;
DELETE FROM `creature_loot_template` where `entry` = 33734;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33734, 33470,  25,  1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 33734, 43852,  15,  1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 33734, 36056,   1,  1, 0, 1, 1 ), -- Vizier Leggings, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 33734, 36064, 0.3, 64, 0, 1, 1 ), -- Coldwraith Pants, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
( 33734, 36280, 0.2, 64, 0, 1, 1 ) -- Spiderlord Legguards, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
;
-- Loot for Nature s Blade, ID: 33527 and 33741 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33527;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33527, 36382, 1, 1, 0, 1, 1 ), -- Golem Gauntlets, item level: 174, quality: UNCOMMON//GREEN, mode: Normal 10
( 33527, 90003 , 3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33741;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33741, 90004 , 3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for Misguided Nymph, ID: 33355 and 33737 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33355;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33355, 36053,  3, 1, 0, 1, 1 ), -- Vizier Robe, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 10
( 33355, 90003 ,  3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33737;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33737, 36540,  2, 1, 0, 1, 1 ), -- Petrified Sword, item level: 174, quality: UNCOMMON//GREEN, mode: Normal 25
( 33737, 90004 ,  3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for Guardian Lasher, ID: 33430 and 33732 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33430;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33430, 33470, 25, 1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 33430, 43852, 15, 1, 0, 1, 1 ) -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
;
DELETE FROM `creature_loot_template` where `entry` = 33732;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33732, 33417, 1.5, 1, 0, 1, 1 ), -- Frost-Worn Plate Pants, item level: 132, quality: POOR//GREY, mode: Normal 25
( 33732, 90004 ,   3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
UPDATE `creature_template` SET `skinloot`=100010 WHERE `entry`=33430;
UPDATE `creature_template` SET `skinloot`=100010 WHERE `entry`=33732;
UPDATE `creature_template` SET `type_flags` =`type_flags`|256 WHERE `entry`=33430;-- Makes Mob herbable
UPDATE `creature_template` SET `type_flags` =`type_flags`|256 WHERE `entry`=33732;-- Makes Mob herbable

-- Loot for Forest Swarmer, ID: 33431 and 33731 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33431;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33431, 33470, 22.987514, 1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Unknown 88
( 33431, 43852, 15.833929, 1, 0, 1, 1 ) -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
;
DELETE FROM `creature_loot_template` where `entry` = 33731;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33731, 33470, 22.987514,  1, 88, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Unknown 88
( 33731, 43852, 15.833929,  1,  0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 33731, 36428, 0.6796523,  1, 64, 1, 1 ), -- Bouquet Ring, item level: 174, quality: UNCOMMON//GREEN, mode: Unknown 64
( 33731, 36444, 0.295501,   1, 64, 1, 1 ), -- Ice Encrusted Amulet, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
( 33731, 36389, 0.2684134,  1, 64, 1, 1 ), -- Revenant Armor, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 33731, 33403, 0.26348838, 1, 64, 1, 1 ) -- Frigid Mail Shoulderpads, item level: 132, quality: POOR//GREY, mode: Unknown 64
;
UPDATE `creature_template` SET `skinloot`=100010 WHERE `entry`=33431;
UPDATE `creature_template` SET `skinloot`=100010 WHERE `entry`=33731;
UPDATE `creature_template` SET `type_flags` =`type_flags`|256 WHERE `entry`=33431;-- Makes Mob herbable
UPDATE `creature_template` SET `type_flags` =`type_flags`|256 WHERE `entry`=33731;-- Makes Mob herbable

-- Loot for Guardian of Life, ID: 33528 and 33733 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33528;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33528, 90003 ,  3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33733;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33733, 36682,  2, 1, 0, 1, 1 ), -- Seduced Blade, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 25
( 33733, 33447,  3, 1, 0, 1, 1 ), -- Runic Healing Potion, item level: 80, quality: NORMAL//WHITE, mode: Normal 25
( 33733, 90004 ,  3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for Storm Tempered Keeper, ID: 33699 and 33700

DELETE FROM `creature_loot_template` where `entry` = 33699;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33699, 39220,    3,  1, 0, 1, 1 ), -- Geodesic Fragments, item level: 1, quality: POOR//GREY, mode: Normal 10
( 33699, 33423,  1.3,  1, 0, 1, 1 ), -- Rime-Covered Mace, item level: 125, quality: POOR//GREY, mode: Normal 10
( 33699, 36289, 0.25, 32, 0, 1, 1 ), -- Spectral Mantle, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 32
( 33699, 90003 ,    3,  1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33700;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33700, 33470,  25,  1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 33700, 43852,  15, 88, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Unknown 88
( 33700, 33454,   2,  1, 0, 1, 1 ), -- Salted Venison, item level: 75, quality: NORMAL//WHITE, mode: Normal 25
( 33700, 33447,   1,  1, 0, 1, 1 ), -- Runic Healing Potion, item level: 80, quality: NORMAL//WHITE, mode: Normal 25
( 33700, 36393, 0.2, 64, 0, 1, 1 ) -- Revenant Epaulets, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
;
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=33699;-- Adds Skinloot
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=33700;-- Adds Skinloot
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=33699;-- Makes Mob mineable
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=33700;-- Makes Mob mineable

-- Loot for Storm Tempered Keeper, ID: 33722 and 33723 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33722;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33722, 39220,  3, 1, 0, 1, 1 ), -- Geodesic Fragments, item level: 1, quality: POOR//GREY, mode: Normal 10
( 33722, 90003 ,  3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33723;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33723, 33470,  25,  1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 33723, 43852,  15,  1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 33723, 33454,   2,  1, 0, 1, 1 ), -- Salted Venison, item level: 75, quality: NORMAL//WHITE, mode: Normal 25
( 33723, 33445, 1.2,  1, 0, 1, 1 ), -- Honeymint Tea, item level: 85, quality: NORMAL//WHITE, mode: Normal 25
( 33723, 36053, 0.6,  1, 0, 1, 1 ), -- Vizier Robe, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 33723, 36051, 0.6,  1, 0, 1, 1 ), -- Vizier Sash, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 33723, 33427, 0.5, 64, 0, 1, 1 ), -- Frost-Encrusted Rifle, item level: 125, quality: POOR//GREY, mode: Unknown 64
( 33723, 36058, 0.3, 64, 0, 1, 1 ), -- Vizier Bracelets, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 33723, 36057, 0.3, 64, 0, 1, 1 ), -- Vizier Mantle, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 33723, 43465, 0.1, 64, 0, 1, 1 ) -- Scroll of Strength VII, item level: 80, quality: NORMAL//WHITE, mode: Unknown 64
;
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=33722;-- Adds Skinloot
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=33723;-- Adds Skinloot
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=33722;-- Makes Mob mineable
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=33723;-- Makes Mob mineable

-- Loot for Faceless Horror, ID: 33772 and 33773 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33772;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33772, 36166, 0.7,  1, 0, 1, 1 ), -- Webspinner Gloves, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 10
( 33772, 90003 ,   3,  1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33773;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33773, 33448,   1,  1, 0, 1, 1 ), -- Runic Mana Potion, item level: 80, quality: NORMAL//WHITE, mode: Normal 25
( 33773, 33384,   1,  1, 0, 1, 1 ), -- Frozen Pants, item level: 132, quality: POOR//GREY, mode: Normal 25
( 33773, 36053, 0.4, 64, 0, 1, 1 ), -- Vizier Robe, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 33773, 36065, 0.2, 64, 0, 1, 1 ), -- Coldwraith Mantle, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
( 33773, 90004 ,   3,  1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for Twilight Adherent, ID: 33818 and 33827 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33818;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33818, 36280, 0.8, 1, 0, 1, 1 ), -- Spiderlord Legguards, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 10
( 33818, 90003 ,   3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33827;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33827, 33447,   3, 1, 0, 1, 5 ), -- Runic Healing Potion, item level: 80, quality: NORMAL//WHITE, mode: Normal 25
( 33827, 36053,   3, 1, 0, 1, 1 ), -- Vizier Robe, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 33827, 36443, 0.8, 1, 0, 1, 1 ), -- Platinum Medallion, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 33827, 43508, 0.8, 1, 0, 1, 1 ), -- Recipe: Last Weeks Mammoth, item level: 75, quality: UNCOMMON//GREEN, mode: Normal 25
( 33827, 90004 ,   3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for Twilight Frost Mage, ID: 33819 and 33829 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33819;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33819, 36400, 0.8, 1, 0, 1, 1 ), -- Necropolis Legplates, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
( 33819, 90003 ,   3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33829;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33829, 33470,  25, 88, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Unknown 88
( 33829, 43852,  15,  1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 33829, 33454, 2.5, 80, 0, 1, 1 ), -- Salted Venison, item level: 75, quality: NORMAL//WHITE, mode: Unknown 80
( 33829, 36064,   2,  1, 0, 1, 1 ), -- Coldwraith Pants, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 25
( 33829, 33447, 2.8,  1, 0, 1, 1 ), -- Runic Healing Potion, item level: 80, quality: NORMAL//WHITE, mode: Normal 25
( 33829, 33445,   1,  1, 0, 1, 1 ), -- Honeymint Tea, item level: 85, quality: NORMAL//WHITE, mode: Normal 25
( 33829, 36278,   1,  1, 0, 1, 1 ), -- Spiderlord Gauntlets, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 33829, 36065, 0.7,  1, 0, 1, 1 ), -- Coldwraith Mantle, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 25
( 33829, 33365, 0.7,  1, 0, 1, 1 ), -- Frost-Rimed Cloth Belt, item level: 132, quality: POOR//GREY, mode: Normal 25
( 33829, 36388, 0.3, 64, 0, 1, 1 ) -- Revenant Greaves, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
;
-- Loot for Twilight Pyromancer, ID: 33820 and 33830 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33820;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33820, 36286,   1, 1, 0, 1, 1 ), -- Spectral Gauntlets, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
( 33820, 36277,   1, 1, 0, 1, 1 ), -- Spiderlord Chestpiece, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 33820, 36541,   1, 1, 0, 1, 1 ), -- Wintry Claymore, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 10
( 33820, 33384, 0.7, 1, 0, 1, 1 ), -- Frozen Pants, item level: 132, quality: POOR//GREY, mode: Normal 10
( 33820, 90003 ,   3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33830;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33830, 33470, 25, 1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 33830, 43852, 15, 1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 33830, 33454,  2, 1, 0, 1, 1 ), -- Salted Venison, item level: 75, quality: NORMAL//WHITE, mode: Normal 25
( 33830, 33424,  2, 1, 0, 1, 1 ), -- Cracked Iron Staff, item level: 125, quality: POOR//GREY, mode: Normal 25
( 33830, 36277,  1, 1, 0, 1, 1 ) -- Spiderlord Chestpiece, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
;
-- Loot for Twilight Guardian, ID: 33822 and 33828 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33822;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33822, 33434, 1, 1, 0, 1, 1 ), -- Frozen Leather Helmet, item level: 132, quality: POOR//GREY, mode: Normal 10
( 33822, 90003 , 3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33828;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33828, 33445,   2,  1, 0, 1, 1 ), -- Honeymint Tea, item level: 85, quality: NORMAL//WHITE, mode: Normal 25
( 33828, 36430,   1,  1, 0, 1, 1 ), -- Puzzle Ring, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 25
( 33828, 36058,   1,  1, 0, 1, 1 ), -- Vizier Bracelets, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 33828, 36400, 0.7,  1, 0, 1, 1 ), -- Necropolis Legplates, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 25
( 33828, 33419, 0.7,  1, 0, 1, 1 ), -- Frost-Worn Plate Shoulderpads, item level: 132, quality: POOR//GREY, mode: Normal 25
( 33828, 36667, 0.3, 64, 0, 1, 1 ), -- Solid Ice Wand, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 33828, 36056, 0.3, 64, 0, 1, 1 ), -- Vizier Leggings, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 33828, 36064, 0.3, 64, 0, 1, 1 ), -- Coldwraith Pants, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
( 33828, 90004 ,   3,  1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for Twilight Slayer, ID: 33823 and 33832 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33823;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33823, 36064, 0.7, 1, 0, 1, 1 ), -- Coldwraith Pants, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
( 33823, 90003 ,   3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33832;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33832, 33470,  25, 88, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Unknown 88
( 33832, 43852,  15, 88, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Unknown 88
( 33832, 33454,  10,  1, 0, 1, 1 ), -- Salted Venison, item level: 75, quality: NORMAL//WHITE, mode: Normal 25
( 33832, 36052,   1,  1, 0, 1, 1 ), -- Vizier Slippers, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 33832, 36416, 0.3, 64, 0, 1, 1 ) -- Regal Cloak, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
;
-- Loot for Twilight Shadowblade, ID: 33824 and 33831 25-Version

DELETE FROM `creature_loot_template` where `entry` = 33824;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33824, 90003 , 3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 33831;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 33831, 90004 , 3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for Assault Bot, ID: 34057 and 34115 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34057;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34057, 46029, 100, 1, 0, 1, 1 ) -- Magnetic Core, item level: 1, quality: NORMAL//WHITE, mode: Normal
;
DELETE FROM `creature_loot_template` where `entry` = 34115;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34115, 46029, 100, 1, 0, 1, 1 ) -- Magnetic Core, item level: 1, quality: NORMAL//WHITE, mode: Normal
;
-- Loot for Molten Colossus, ID: 34069 and 34185 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34069;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34069, 39220, 2, 1, 0, 1, 1 ), -- Geodesic Fragments, item level: 1, quality: POOR//GREY, mode: Normal 10
( 34069, 36597, 1, 1, 0, 1, 1 ), -- Ice-Splintering Axe, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 10
( 34069, 36065, 1, 1, 0, 1, 1 ), -- Coldwraith Mantle, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
( 34069, 33397, 1, 1, 0, 1, 1 ), -- Frigid Mail Armor, item level: 132, quality: POOR//GREY, mode: Normal 10
( 34069, 90003 , 3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 34185;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34185, 36681,   1,  1, 0, 1, 1 ), -- Wisdom Carver, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 34185, 36667, 0.8, 64, 0, 1, 1 ), -- Solid Ice Wand, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34185, 33445, 0.6,  1, 0, 1, 1 ), -- Honeymint Tea, item level: 85, quality: NORMAL//WHITE, mode: Normal 25
( 34185, 36542, 0.2, 64, 0, 1, 1 ), -- Invasion Blade, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34185, 90004 ,   3,  1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34069;-- Adds Skinloot
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34185;-- Adds Skinloot
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34069;-- Makes Mob mineable
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34185;-- Makes Mob mineable

-- Loot for Forge Construct, ID: 34085 and 34186 25-Version
--
DELETE FROM `creature_loot_template` where `entry` = 34085;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34085, 39220, 4.5, 1, 0, 6, 8 ), -- Geodesic Fragments, item level: 1, quality: POOR//GREY, mode: Normal 10
( 34085, 90003 ,   3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 34186;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34085, 33470,  25, 1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Unknown 88
( 34085, 43852,  15, 1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 34186, 33454,   1, 1, 0, 1, 1 ), -- Salted Venison, item level: 75, quality: NORMAL//WHITE, mode: Normal 25
( 34186, 33424, 0.7, 1, 0, 1, 1 ), -- Cracked Iron Staff, item level: 125, quality: POOR//GREY, mode: Normal 25
( 34186, 36387, 0.6, 1, 0, 1, 1 ), -- Revenant Belt, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 34186, 36443, 0.4, 1, 0, 1, 1 ) -- Platinum Medallion, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
;
UPDATE `creature_template` SET `skinloot`=100009 WHERE `entry`=34085;
UPDATE `creature_template` SET `skinloot`=100009 WHERE `entry`=34186;
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34085;-- Make Mob mineable
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34186;-- Make Mob mineable
-- Loot for Magma Rager, ID: 34086 and 34201 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34086;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34086, 33470, 25, 1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 34086, 43852, 15, 1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 34086, 36056,  1, 1, 0, 1, 1 ), -- Vizier Leggings, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 10
( 34086, 33401,  1, 1, 0, 1, 1 ) -- Frigid Mail Gloves, item level: 132, quality: POOR//GREY, mode: Normal 10
;
DELETE FROM `creature_loot_template` where `entry` = 34201;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34201, 39220, 3, 1, 0, 1, 1 ), -- Geodesic Fragments, item level: 1, quality: POOR//GREY, mode: Normal 25
( 34201, 33445, 1, 1, 0, 1, 1 ), -- Honeymint Tea, item level: 85, quality: NORMAL//WHITE, mode: Normal 25
( 34201, 45538, 2, 1, 0, 1, 1 ), -- Titanstone Pendant, item level: 226, quality: EPIC//PURPLE, mode: Normal 25
( 34201, 90004 , 3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34086;-- Adds Skinloot
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34201;-- Adds Skinloot
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34086;-- Makes Mob mineable
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34201;-- Makes Mob mineable

-- Loot for Champion of Hodir, ID: 34133 and 34139 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34133;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34133, 90003 , 3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 34139;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34139, 36054, 1, 1, 0, 1, 1 ), -- Vizier Gloves, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 34139, 90004 , 3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for Winter Revenant, ID: 34134 and 34141 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34134;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34134, 39220, 4, 1, 0, 1, 1 ), -- Geodesic Fragments, item level: 1, quality: POOR//GREY, mode: Normal 10
( 34134, 36682, 1, 1, 0, 1, 1 ), -- Seduced Blade, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
( 34134, 90003 , 3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 34141;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34141, 33445, 0.8, 1, 0, 1, 1 ), -- Honeymint Tea, item level: 85, quality: NORMAL//WHITE, mode: Normal 25
( 34141, 36380, 0.8, 1, 0, 1, 1 ), -- Golem Sabatons, item level: 174, quality: UNCOMMON//GREEN, mode: Normal 25
( 34141, 33365, 0.6, 1, 0, 1, 1 ), -- Frost-Rimed Cloth Belt, item level: 132, quality: POOR//GREY, mode: Normal 25
( 34141, 33419, 0.5, 1, 0, 1, 1 ), -- Frost-Worn Plate Shoulderpads, item level: 132, quality: POOR//GREY, mode: Normal 25
( 34141, 90004 ,   3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34134;-- Adds Skinloot
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34141;-- Adds Skinloot
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34134;-- Makes Mob mineable
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34141;-- Makes Mob mineable

-- Loot for Winter Rumbler, ID: 34135 and 34142 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34135;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34135, 33470,  25, 88, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Unknown 88
( 34135, 43852,  15, 88, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Unknown 88
( 34135, 39220,   4,  1, 0, 1, 1 ), -- Geodesic Fragments, item level: 1, quality: POOR//GREY, mode: Normal
( 34135, 36177, 0.2, 32, 0, 1, 1 ) -- Geist Shoulders, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 32
;
DELETE FROM `creature_loot_template` where `entry` = 34142;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34142, 39220,   4,  1, 0, 1, 1 ), -- Geodesic Fragments, item level: 1, quality: POOR//GREY, mode: Normal
( 34142, 36430, 0.7,  1, 0, 1, 1 ), -- Puzzle Ring, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 25
( 34142, 36396, 0.2, 64, 0, 1, 1 ), -- Necropolis Sabatons, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34142, 90004 ,   3,  1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34135;-- Adds Skinloot
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34142;-- Adds Skinloot
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34135;-- Makes Mob mineable
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34142;-- Makes Mob mineable

-- Loot for Winter Jormungar, ID: 34137 and 34140 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34137;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34137, 33470,  25,  1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 34137, 43852,  15, 88, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Unknown 88
( 34137, 33568,   3,  1, 0, 1, 1 ), -- Borean Leather, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 34137, 36667, 0.3, 32, 0, 1, 1 ) -- Solid Ice Wand, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 32
;
DELETE FROM `creature_loot_template` where `entry` = 34140;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34140, 33470,  25,  1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 34140, 43852,  15, 88, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Unknown 88
( 34140, 33568,   3,  1, 0, 1, 1 ), -- Borean Leather, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 34140, 33454, 1.5, 80, 0, 1, 1 ), -- Salted Venison, item level: 75, quality: NORMAL//WHITE, mode: Unknown 80
( 34140, 33445, 0.7, 64, 0, 1, 1 ), -- Honeymint Tea, item level: 85, quality: NORMAL//WHITE, mode: Unknown 64
( 34140, 33400, 0.4, 64, 0, 1, 1 ), -- Frigid Mail Bracers, item level: 132, quality: POOR//GREY, mode: Unknown 64
( 34140, 33447, 0.4, 64, 0, 1, 1 ), -- Runic Healing Potion, item level: 80, quality: NORMAL//WHITE, mode: Unknown 64
( 34140, 36682, 0.4, 64, 0, 1, 1 ), -- Seduced Blade, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34140, 36060, 0.4, 64, 0, 1, 1 ), -- Coldwraith Boots, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34140, 36276, 0.3, 64, 0, 1, 1 ), -- Spiderlord Boots, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34140, 43509, 0.3, 64, 0, 1, 1 ), -- Recipe: Bad Clams, item level: 75, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34140, 33399, 0.3, 64, 0, 1, 1 ), -- Frigid Mail Boots, item level: 132, quality: POOR//GREY, mode: Unknown 64
( 34140, 33371, 0.2, 64, 0, 1, 1 ), -- Frost-Rimed Cloth Vest, item level: 132, quality: POOR//GREY, mode: Unknown 64
( 34140, 36401, 0.2, 64, 0, 1, 1 ), -- Necropolis Epaulets, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34140, 36457, 0.2, 64, 0, 1, 1 ), -- Ivory Shield, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34140, 36541, 0.1, 64, 0, 1, 1 ), -- Wintry Claymore, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34140, 36556, 0.1, 64, 0, 1, 1 ) -- Apocalyptic Staff, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
;
UPDATE `creature_template` SET `skinloot`=70207 WHERE `entry`=34137;-- Adds Skinloot
UPDATE `creature_template` SET `skinloot`=70207 WHERE `entry`=34140;-- Adds Skinloot
-- Loot for Arachnopod Destroyer, ID: 34183 and 34214 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34183;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34183, 33433,   3, 1, 0, 1, 1 ), -- Frigid Mail Circlet, item level: 132, quality: POOR//GREY, mode: Normal 10
( 34183, 36058,   2, 1, 0, 1, 1 ), -- Vizier Bracelets, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 10
( 34183, 33403,   1, 1, 0, 1, 1 ), -- Frigid Mail Shoulderpads, item level: 132, quality: POOR//GREY, mode: Normal 10
( 34183, 36147, 0.8, 1, 0, 1, 1 ), -- Pygmy Belt, item level: 170, quality: UNCOMMON//GREEN, mode: Normal 10
( 34183, 36155, 0.8, 1, 0, 1, 1 ), -- Wendigo Girdle, item level: 174, quality: UNCOMMON//GREEN, mode: Normal 10
( 34183, 36666, 0.8, 1, 0, 1, 1 ), -- Polar Wand, item level: 174, quality: UNCOMMON//GREEN, mode: Normal 10
( 34183, 33428, 0.8, 1, 0, 1, 1 ), -- Dulled Shiv, item level: 125, quality: POOR//GREY, mode: Normal 10
( 34183, 90003 ,   3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 34214;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34214, 36045, 1, 1, 0, 1, 1 ), -- Crystalsong Robe, item level: 174, quality: UNCOMMON//GREEN, mode: Normal 25
( 34214, 36282, 1, 1, 0, 1, 1 ), -- Spiderlord Bracers, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 34214, 43624, 1, 1, 0, 1, 1 ), -- Titanium Lockbox, item level: 78, quality: RARE//BLUE, mode: Normal 25
( 34214, 43509, 1, 1, 0, 1, 1 ), -- Recipe: Bad Clams, item level: 75, quality: UNCOMMON//GREEN, mode: Normal 25
( 34214, 90004 , 3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for Hardened Iron Golem, ID: 34190 and 34229 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34190;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34190, 39220, 3, 1, 0, 1, 1 ), -- Geodesic Fragments, item level: 1, quality: POOR//GREY, mode: Normal 10
( 34190, 33431, 1, 1, 0, 1, 1 ), -- Icesmashing Mace, item level: 125, quality: POOR//GREY, mode: Normal 10
( 34190, 33424, 1, 1, 0, 1, 1 ), -- Cracked Iron Staff, item level: 125, quality: POOR//GREY, mode: Normal 10
( 34190, 90003 , 3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 34229;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34229, 36429,   1, 64, 0, 1, 1 ), -- Spur Ring, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34229, 36391,   1,  1, 0, 1, 1 ), -- Revenant Helmet, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 34229, 36390, 0.7,  1, 0, 1, 1 ), -- Revenant Gauntlets, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 34229, 36282, 0.5, 64, 0, 1, 1 ), -- Spiderlord Bracers, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34229, 36286, 0.3, 64, 0, 1, 1 ), -- Spectral Gauntlets, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34229, 36709, 0.2, 64, 0, 1, 1 ), -- Crystal Woodstaff, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34229, 33380, 0.2, 64, 0, 1, 1 ), -- Frozen Belt, item level: 132, quality: POOR//GREY, mode: Unknown 64
( 34229, 33414, 0.2, 64, 0, 1, 1 ), -- Frost-Worn Plate Bracers, item level: 132, quality: POOR//GREY, mode: Unknown 64
( 34229, 36611, 0.1, 64, 0, 1, 1 ), -- Bleak Scythe, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34229, 90004 ,   3,  1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34190;-- Adds Skinloot
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34229;-- Adds Skinloot
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34190;-- Makes Mob mineable
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34229;-- Makes Mob mineable

-- Loot for Trash, ID: 34191 and 34217 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34191;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34191, 41338, 44, 1, 0, 1, 3 ), -- Sprung Whirlygig, item level: 1, quality: POOR//GREY, mode: Normal
( 34191, 41337, 40, 1, 0, 1, 3 ), -- Whizzed-Out Gizmo, item level: 1, quality: POOR//GREY, mode: Normal
( 34191, 39690, 10, 1, 0, 1, 3 ), -- Volatile Blasting Trigger, item level: 72, quality: NORMAL//WHITE, mode: Normal
( 34191, 39681,  5, 1, 0, 2, 4 ), -- Handful of Cobalt Bolts, item level: 71, quality: NORMAL//WHITE, mode: Normal
( 34191, 39683,  1, 1, 0, 1, 1 ) -- Froststeel Tube, item level: 70, quality: NORMAL//WHITE, mode: Normal 10
;
DELETE FROM `creature_loot_template` where `entry` = 34217;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34217, 41338, 44, 1, 0, 1, 3 ), -- Sprung Whirlygig, item level: 1, quality: POOR//GREY, mode: Normal
( 34217, 41337, 40, 1, 0, 1, 3 ), -- Whizzed-Out Gizmo, item level: 1, quality: POOR//GREY, mode: Normal
( 34217, 39690, 10, 1, 0, 1, 3 ), -- Volatile Blasting Trigger, item level: 72, quality: NORMAL//WHITE, mode: Normal
( 34217, 39681, 5, 1, 0, 2, 4 ) -- Handful of Cobalt Bolts, item level: 71, quality: NORMAL//WHITE, mode: Normal
;

-- Loot for Clockwork Sapper, ID: 34193 and 34220 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34193;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34193, 36511, 0.1, 32, 0, 1, 1 ), -- Arctic War Hammer, item level: 170, quality: UNCOMMON//GREEN, mode: Unknown 32
( 34193, 90003 ,   3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 34220;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34220, 36393, 2, 1, 0, 1, 1 ), -- Revenant Epaulets, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 34220, 90004 , 3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for Rune Etched Sentry, ID: 34196 and 34245 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34196;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34196, 33470,  25, 88, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Unknown 88
( 34196, 43852,  15,  1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 34196, 39220, 3.5,  1, 0, 1, 1 ), -- Geodesic Fragments, item level: 1, quality: POOR//GREY, mode: Normal
( 34196, 36064, 1.2,  1, 0, 1, 1 ), -- Coldwraith Pants, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
( 34196, 36392, 1.2,  1, 0, 1, 1 ), -- Revenant Legguards, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 10
( 34196, 36399,   1,  1, 0, 1, 1 ) -- Necropolis Helm, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
;
DELETE FROM `creature_loot_template` where `entry` = 34245;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34245, 39220, 3.5,  1, 0, 1, 1 ), -- Geodesic Fragments, item level: 1, quality: POOR//GREY, mode: Normal
( 34245, 36059, 0.8,  1, 0, 1, 1 ), -- Coldwraith Sash, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 25
( 34245, 36430, 0.8, 64, 0, 1, 1 ), -- Puzzle Ring, item level: 182, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34245, 33447, 0.6,  1, 0, 1, 1 ), -- Runic Healing Potion, item level: 80, quality: NORMAL//WHITE, mode: Normal 25
( 34245, 33385, 0.3, 64, 0, 1, 1 ), -- Frozen Shoulderpads, item level: 132, quality: POOR//GREY, mode: Unknown 64
( 34245, 90004 ,   3,  1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34196;-- Adds Skinloot
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34245;-- Adds Skinloot
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34196;-- Makes Mob mineable
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34245;-- Makes Mob mineable

-- Loot for Chamber Overseer, ID: 34197 and 34226 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34197;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34197, 39220, 3.5, 1, 0, 1, 1 ), -- Geodesic Fragments, item level: 1, quality: POOR//GREY, mode: Normal 10
( 34197, 36396, 1.3, 1, 0, 1, 1 ), -- Necropolis Sabatons, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
( 34197, 37835, 0.1, 32, 0, 1, 1 ), -- JeTzes Bell, item level: 200, quality: EPIC//PURPLE, mode: Unknown 32
( 34197, 90003 ,   3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 34226;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34226, 33445,   2,  1, 0, 1, 1 ), -- Honeymint Tea, item level: 85, quality: NORMAL//WHITE, mode: Normal 25
( 34226, 36166, 0.4, 64, 0, 1, 1 ), -- Webspinner Gloves, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34226, 36281, 0.3, 64, 0, 1, 1 ), -- Spiderlord Spaulders, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34226, 90004 ,   3,  1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34197;-- Adds Skinloot
UPDATE `creature_template` SET `skinloot`=100011 WHERE `entry`=34226;-- Adds Skinloot
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34197;-- Makes Mob mineable
UPDATE `creature_template` SET `type_flags` =`type_flags`|512 WHERE `entry`=34226;-- Makes Mob mineable

-- Loot for Iron Mender, ID: 34198 and 34236 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34198;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34198, 33470,  25, 1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 34198, 43852,  15, 1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 34198, 33423, 1.3, 1, 0, 1, 1 ), -- Rime-Covered Mace, item level: 125, quality: POOR//GREY, mode: Normal 10
( 34198, 36443,   1, 1, 0, 1, 1 ), -- Platinum Medallion, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 10
( 34198, 33426,   1, 1, 0, 1, 1 ), -- Chipped Timber Axe, item level: 125, quality: POOR//GREY, mode: Normal 10
( 34198, 36626, 0.6, 1, 0, 1, 1 ) -- Military Compound Bow, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
;
DELETE FROM `creature_loot_template` where `entry` = 34236;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34236, 36430, 2, 1, 0, 1, 1 ), -- Puzzle Ring, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 25
( 34236, 45912, 2, 1, 0, 1, 1 ), -- Book of Glyph Mastery, item level: 80, quality: UNCOMMON//GREEN, mode: Normal 25
( 34236, 90004 , 3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for Lightning Charged Iron Dwarf, ID: 34199 and 34237 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34199;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34199, 33470,  25, 1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 34199, 43852,  15, 1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 34199, 36178,   1, 1, 0, 1, 1 ), -- Geist Wristguards, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
( 34199, 36171, 0.8, 1, 0, 1, 1 ) -- Geist Belt, item level: 182, quality: UNCOMMON//GREEN, mode: Normal 10
;
DELETE FROM `creature_loot_template` where `entry` = 34237;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34237, 45540, 1.4, 1, 0, 1, 1 ), -- Bladebearers Signet, item level: 226, quality: EPIC//PURPLE, mode: Normal 25
( 34237, 33445, 1.4, 1, 0, 1, 1 ), -- Honeymint Tea, item level: 85, quality: NORMAL//WHITE, mode: Normal 25
( 34237, 36429, 1.2, 1, 0, 1, 1 ), -- Spur Ring, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 34237, 90004 ,   3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for Parts Recovery Technician, ID: 34267 and 34268 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34267;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34267, 33470,  25,  1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 34267, 43852,  15,  1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 34267, 36277,   1,  1, 0, 1, 1 ), -- Spiderlord Chestpiece, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 10
( 34267, 36045, 0.3, 32, 0, 1, 1 ) -- Crystalsong Robe, item level: 174, quality: UNCOMMON//GREEN, mode: Unknown 32
;
DELETE FROM `creature_loot_template` where `entry` = 34268;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34268, 33470,  25, 1, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Normal
( 34268, 43852,  15, 1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 34268, 36042,   1, 1, 0, 1, 1 ), -- Condor Bindings, item level: 170, quality: UNCOMMON//GREEN, mode: Normal 25
( 34268, 33454,   1, 1, 0, 1, 1 ), -- Salted Venison, item level: 75, quality: NORMAL//WHITE, mode: Normal 25
( 34268, 36037, 0.6, 1, 0, 1, 1 ), -- Condor Robe, item level: 170, quality: UNCOMMON//GREEN, mode: Normal 25
( 34268, 33445, 0.5, 1, 0, 1, 1 ), -- Honeymint Tea, item level: 85, quality: NORMAL//WHITE, mode: Normal 25
( 34268, 36375, 0.4, 1, 0, 1, 1 ) -- Kraken Helm, item level: 170, quality: UNCOMMON//GREEN, mode: Normal 25
;
-- Loot for XR-949 Salvagebot, ID: 34269 and 34270 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34269;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34269, 43509, 1.2, 1, 0, 1, 1 ), -- Recipe: Bad Clams, item level: 75, quality: UNCOMMON//GREEN, mode: Normal 10
( 34269, 33426,   1, 1, 0, 1, 1 ), -- Chipped Timber Axe, item level: 125, quality: POOR//GREY, mode: Normal 10
( 34269, 90003 ,   3, 1, 1, -90003, 1) -- Reference Loot ... Epic 10 Mann
;
DELETE FROM `creature_loot_template` where `entry` = 34270;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34270, 33470,  25, 88, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Unknown 88
( 34270, 43852,  15, 88, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Unknown 88
( 34270, 33454, 1.4,  1, 0, 1, 1 ), -- Salted Venison, item level: 75, quality: NORMAL//WHITE, mode: Normal 25
( 34270, 33447, 3.2,  1, 0, 1, 1 ), -- Runic Healing Potion, item level: 80, quality: NORMAL//WHITE, mode: Normal 25
( 34270, 33445, 0.6, 64, 0, 1, 1 ), -- Honeymint Tea, item level: 85, quality: NORMAL//WHITE, mode: Unknown 64
( 34270, 37761, 0.5,  1, 0, 1, 1 ), -- Shimmerthread Girdle, item level: 174, quality: RARE//BLUE, mode: Normal 25
( 34270, 33428, 0.4, 64, 0, 1, 1 ) -- Dulled Shiv, item level: 125, quality: POOR//GREY, mode: Unknown 64
;
-- Loot for XD-175 Compactobot, ID: 34271 and 34272 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34271;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34271, 33470,  25, 88, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Unknown 88
( 34271, 43852,  15, 88, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Unknown 88
( 34271, 36383, 1.2,  1, 0, 1, 1 ), -- Golem Helmet, item level: 174, quality: UNCOMMON//GREEN, mode: Normal 10
( 34271, 33384, 0.8,  1, 0, 1, 1 ) -- Frozen Pants, item level: 132, quality: POOR//GREY, mode: Normal 10
;
DELETE FROM `creature_loot_template` where `entry` = 34272;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34272, 33427, 0.6, 64, 0, 1, 1 ), -- Frost-Encrusted Rifle, item level: 125, quality: POOR//GREY, mode: Unknown 64
( 34272, 36457, 0.6,  1, 0, 1, 1 ), -- Ivory Shield, item level: 178, quality: UNCOMMON//GREEN, mode: Normal 25
( 34272, 33423, 0.5, 64, 0, 1, 1 ), -- Rime-Covered Mace, item level: 125, quality: POOR//GREY, mode: Unknown 64
( 34272, 43465, 0.5,  1, 0, 1, 1 ), -- Scroll of Strength VII, item level: 80, quality: NORMAL//WHITE, mode: Normal 25
( 34272, 36665, 0.4, 64, 0, 1, 1 ), -- Wasteland Wand, item level: 170, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34272, 36695, 0.4, 64, 0, 1, 1 ), -- Dogmatic Scepter, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34272, 36153, 0.2, 64, 0, 1, 1 ), -- Pygmy Shoulders, item level: 170, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34272, 36624, 0.1, 64, 0, 1, 1 ), -- Shrieking Bow, item level: 174, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34272, 90004 , 3, 1, 1, -90004, 1) -- Reference Loot ... Epic 25 Mann
;
-- Loot for XB-488 Disposalbot, ID: 34273 and 34274 25-Version

DELETE FROM `creature_loot_template` where `entry` = 34273;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34273, 33470,  25, 88, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Unknown 88
( 34273, 43852,  15,  1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 34273, 36386, 0.8,  1, 0, 1, 1 ) -- Golem Vambraces, item level: 174, quality: UNCOMMON//GREEN, mode: Normal 10
;
DELETE FROM `creature_loot_template` where `entry` = 34274;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
( 34274, 33470,  25, 88, 0, 2, 7 ), -- Frostweave Cloth, item level: 70, quality: NORMAL//WHITE, mode: Unknown 88
( 34274, 43852,  15,  1, 0, 1, 1 ), -- Thick Fur Clothing Scraps, item level: 70, quality: POOR//GREY, mode: Normal
( 34274, 41337,   3,  1, 0, 1, 3 ), -- Whizzed-Out Gizmo, item level: 1, quality: POOR//GREY, mode: Normal 25
( 34274, 33454,   3,  1, 0, 1, 1 ), -- Salted Venison, item level: 75, quality: NORMAL//WHITE, mode: Normal 25
( 34274, 36665, 0.7,  1, 0, 1, 1 ), -- Wasteland Wand, item level: 170, quality: UNCOMMON//GREEN, mode: Normal 25
( 34274, 36667, 0.3, 64, 0, 1, 1 ), -- Solid Ice Wand, item level: 178, quality: UNCOMMON//GREEN, mode: Unknown 64
( 34274, 33401, 0.1, 64, 0, 1, 1 ), -- Frigid Mail Gloves, item level: 132, quality: POOR//GREY, mode: Unknown 64
( 34274, 36610, 0.1, 64, 0, 1, 1 ) -- Plagued Pike, item level: 174, quality: UNCOMMON//GREEN, mode: Unknown 64
;