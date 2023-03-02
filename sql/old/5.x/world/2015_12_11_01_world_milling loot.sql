-- Milling Loot Skill 25
-- Fix Milling loot for Mageroyal http://www.wowhead.com/item=785/mageroyal#milling
DELETE FROM `milling_loot_template` WHERE entry=785;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('785', '978859', '100', '1', '0', '-978859', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('785', '978860', '25', '1', '0', '-978860', '1');

DELETE FROM `reference_loot_template` WHERE entry in (978859,978860);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978859', '39334', '100', '1', '1', '2', '3');
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978860', '43103', '100', '1', '1', '1', '3');

-- Fix Milling loot for Briarthorn http://www.wowhead.com/item=2452/swiftthistle#milling
DELETE FROM `milling_loot_template` WHERE entry=2450;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('2450', '978859', '100', '1', '0', '-978859', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('2450', '978860', '25', '1', '0', '-978860', '1');

-- Fix Milling loot for Swiftthistle http://www.wowhead.com/item=2450/briarthorn#milling
DELETE FROM `milling_loot_template` WHERE entry=2452;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('2452', '978859', '100', '1', '0', '-978859', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('2452', '978860', '25', '1', '0', '-978860', '1');

-- Fix Milling loot for Swiftthistle http://www.wowhead.com/item=2453/bruiseweed
DELETE FROM `milling_loot_template` WHERE entry=2453;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('2453', '978861', '100', '1', '0', '-978859', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('2453', '978860', '50', '1', '0', '-978860', '1');
DELETE FROM `reference_loot_template` WHERE entry=978861;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978861', '39334', '100', '1', '1', '2', '4');

-- Fix Milling loot for stranglekelp http://www.wowhead.com/item=3820/stranglekelp#milling
DELETE FROM `milling_loot_template` WHERE entry=3820;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3820', '978861', '100', '1', '0', '-978861', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3820', '978860', '50', '1', '0', '-978860', '1');

-- Milling Loot for Skill 75

-- Fix Milling loot for Wild Steelbloom http://www.wowhead.com/item=3355/wild-steelbloom#milling
DELETE FROM `milling_loot_template` WHERE entry=3355;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3355', '978862', '100', '1', '0', '-978862', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3355', '978863', '25', '1', '0', '-978863', '1');

DELETE FROM `reference_loot_template` WHERE entry in (978862,978863);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978862', '39338', '100', '1', '1', '2', '3');
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978863', '43104', '100', '1', '1', '1', '3');

-- Fix Milling loot for Grave Moss http://www.wowhead.com/item=3369/grave-moss#milling
DELETE FROM `milling_loot_template` WHERE entry=3369;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3369', '978862', '100', '1', '0', '-978862', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3369', '978863', '25', '1', '0', '-978863', '1');

-- Fix Milling loot for Kingsblood http://www.wowhead.com/item=3356/kingsblood#milling
DELETE FROM `reference_loot_template` WHERE entry=978864;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978864', '39338', '100', '1', '1', '2', '4');
DELETE FROM `milling_loot_template` WHERE entry=3356;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3356', '978864', '100', '1', '0', '-978864', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3356', '978863', '50', '1', '0', '-978863', '1');

-- Fix Milling loot for Liferoot http://www.wowhead.com/item=3357/liferoot#milling
DELETE FROM `milling_loot_template` WHERE entry=3357;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3357', '978864', '100', '1', '0', '-978864', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3357', '978863', '50', '1', '0', '-978863', '1');

-- Milling Loot for Skill 125

-- Fix Milling loot for Fadeleaf http://www.wowhead.com/item=3818/fadeleaf#milling
DELETE FROM `milling_loot_template` WHERE entry=3818;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3818', '978865', '100', '1', '0', '-978865', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3818', '978866', '25', '1', '0', '-978866', '1');

DELETE FROM `reference_loot_template` WHERE entry in (978865,978866);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978865', '39339', '100', '1', '1', '2', '3');
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978866', '43105', '100', '1', '1', '1', '3');

-- Fix Milling Loot for Goldthorn http://www.wowhead.com/item=3821/goldthorn#milling
DELETE FROM `milling_loot_template` WHERE entry=3821;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3821', '978865', '100', '1', '0', '-978865', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3821', '978866', '25', '1', '0', '-978866', '1');

-- Fix Milling Loot for khadgars whisker http://www.wowhead.com/item=3358/khadgars-whisker#milling
DELETE FROM `reference_loot_template` WHERE entry=978867;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978867', '39339', '100', '1', '1', '3', '4');
DELETE FROM `milling_loot_template` WHERE entry=3358;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3358', '978867', '100', '1', '0', '-978867', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3358', '978866', '50', '1', '0', '-978866', '1');

-- Fix Milling Loot for dragons theeth http://www.wowhead.com/item=3819/dragons-teeth#milling
DELETE FROM `milling_loot_template` WHERE entry=3819;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3819', '978867', '100', '1', '0', '-978867', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('3819', '978866', '50', '1', '0', '-978866', '1');

-- Milling Loot for Skill 175

-- Fix Milling Loot for Firebloom http://www.wowhead.com/item=4625/firebloom#milling
DELETE FROM `milling_loot_template` WHERE entry=4625;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('4625', '978868', '100', '1', '0', '-978868', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('4625', '978869', '25', '1', '0', '-978869', '1');

DELETE FROM `reference_loot_template` WHERE entry in (978868,978869);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978868', '39340', '100', '1', '1', '2', '3');
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978869', '43106', '100', '1', '1', '1', '3');

-- Fix Milling Loot for Purple Lotus http://www.wowhead.com/item=8831/purple-lotus#milling
DELETE FROM `milling_loot_template` WHERE entry=8831;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('8831', '978868', '100', '1', '0', '-978868', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('8831', '978869', '25', '1', '0', '-978869', '1');

-- Fix Milling Loot for Arthas Tears http://www.wowhead.com/item=8836/arthas-tears
DELETE FROM `milling_loot_template` WHERE entry=8836;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('8836', '978868', '100', '1', '0', '-978868', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('8836', '978869', '25', '1', '0', '-978869', '1');

-- Fix Milling Loot for Sungrass http://www.wowhead.com/item=8838/sungrass#milling
DELETE FROM `milling_loot_template` WHERE entry=8838;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('8838', '978868', '100', '1', '0', '-978868', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('8838', '978869', '25', '1', '0', '-978869', '1');

-- Fix Milling Loot for Blindweed http://www.wowhead.com/item=8839/blindweed#milling
DELETE FROM `reference_loot_template` WHERE entry=978870;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978870', '39340', '100', '1', '1', '2', '4');
DELETE FROM `milling_loot_template` WHERE entry=8839;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('8839', '978870', '100', '1', '0', '-978870', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('8839', '978869', '50', '1', '0', '-978869', '1');

-- Fix Milling Loot for Ghost Mushroom http://www.wowhead.com/item=8845/ghost-mushroom#milling
DELETE FROM `milling_loot_template` WHERE entry=8845;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('8845', '978870', '100', '1', '0', '-978870', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('8845', '978869', '50', '1', '0', '-978869', '1');

-- Fix Milling Loot for Gromsblood http://www.wowhead.com/item=8846/gromsblood
DELETE FROM `milling_loot_template` WHERE entry=8846;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('8846', '978870', '100', '1', '0', '-978870', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('8846', '978869', '50', '1', '0', '-978869', '1');

-- Milling Loot for Skill 225

-- Fix Milling Loot for Golden Sansam http://www.wowhead.com/item=13464/golden-sansam#milling
DELETE FROM `milling_loot_template` WHERE entry=13464;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('13464', '978871', '100', '1', '0', '-978871', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('13464', '978872', '25', '1', '0', '-978872', '1');

DELETE FROM `reference_loot_template` WHERE entry in (978871,978872);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978871', '39341', '100', '1', '1', '2', '3');
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978872', '43107', '100', '1', '1', '1', '3');

-- Fix Milling Loot for Dreamfoil http://www.wowhead.com/item=13463/dreamfoil#milling
DELETE FROM `milling_loot_template` WHERE entry=13463;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('13463', '978871', '100', '1', '0', '-978871', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('13463', '978872', '25', '1', '0', '-978872', '1');

-- Fix Milling Loot for Mountain Silversage http://www.wowhead.com/item=13465/mountain-silversage#milling
DELETE FROM `reference_loot_template` WHERE entry=978873;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978873', '39341', '100', '1', '1', '2', '4');
DELETE FROM `milling_loot_template` WHERE entry=13465;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('13465', '978873', '100', '1', '0', '-978873', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('13465', '978872', '50', '1', '0', '-978872', '1');

-- http://www.wowhead.com/item=13466/sorrowmoss#milling
DELETE FROM `milling_loot_template` WHERE entry=13466;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('13466', '978873', '100', '1', '0', '-978873', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('13466', '978872', '50', '1', '0', '-978872', '1');

-- http://www.wowhead.com/item=13467/icecap#milling
DELETE FROM `milling_loot_template` WHERE entry=13467;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('13467', '978873', '100', '1', '0', '-978873', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('13467', '978872', '50', '1', '0', '-978872', '1');

-- Milling Loot for Skill 275

-- http://www.wowhead.com/item=22792/nightmare-vine#milling
DELETE FROM `milling_loot_template` WHERE entry=22792;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22792', '978874', '100', '1', '0', '-978874', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22792', '978875', '50', '1', '0', '-978875', '1');

DELETE FROM `reference_loot_template` WHERE entry in (978874,978875);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978874', '39342', '100', '1', '1', '2', '4');
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978875', '43108', '100', '1', '1', '1', '3');

-- http://www.wowhead.com/item=22793/mana-thistle#milling
DELETE FROM `milling_loot_template` WHERE entry=22793;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22793', '978874', '100', '1', '0', '-978874', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22793', '978875', '50', '1', '0', '-978875', '1');

-- http://www.wowhead.com/item=22791/netherbloom#milling
DELETE FROM `milling_loot_template` WHERE entry=22791;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22791', '978874', '100', '1', '0', '-978874', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22791', '978875', '50', '1', '0', '-978875', '1');

-- http://www.wowhead.com/item=22789/terocone#milling
DELETE FROM `milling_loot_template` WHERE entry=22789;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22789', '978876', '100', '1', '0', '-978876', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22789', '978875', '25', '1', '0', '-978875', '1');

DELETE FROM `reference_loot_template` WHERE entry=978876;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978876', '39342', '100', '1', '1', '2', '3');

-- http://www.wowhead.com/item=22785/felweed#milling
DELETE FROM `milling_loot_template` WHERE entry=22785;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22785', '978876', '100', '1', '0', '-978876', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22785', '978875', '25', '1', '0', '-978875', '1');

-- http://www.wowhead.com/item=22786/dreaming-glory#milling
DELETE FROM `milling_loot_template` WHERE entry=22786;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22786', '978876', '100', '1', '0', '-978876', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22786', '978875', '25', '1', '0', '-978875', '1');

-- http://www.wowhead.com/item=22790/ancient-lichen#milling
DELETE FROM `milling_loot_template` WHERE entry=22790;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22790', '978874', '100', '1', '0', '-978874', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22790', '978875', '50', '1', '0', '-978875', '1');

-- http://www.wowhead.com/item=22787/ragveil#milling
DELETE FROM `milling_loot_template` WHERE entry=22787;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22787', '978876', '100', '1', '0', '-978876', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('22787', '978875', '25', '1', '0', '-978875', '1');

-- Milling Loot for Skill 325

-- http://www.wowhead.com/item=37921/deadnettle#milling
DELETE FROM `milling_loot_template` WHERE entry=37921;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('37921', '978877', '100', '1', '0', '-978877', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('37921', '978878', '25', '1', '0', '-978878', '1');

DELETE FROM `reference_loot_template` WHERE entry in (978877,978878);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978877', '39343', '100', '1', '1', '2', '3');
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978878', '43109', '100', '1', '1', '1', '3');

-- http://www.wowhead.com/item=36906/icethorn#milling
DELETE FROM `milling_loot_template` WHERE entry=36906;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('36906', '978879', '100', '1', '0', '-978879', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('36906', '978878', '50', '1', '0', '-978878', '1');

DELETE FROM `reference_loot_template` WHERE entry=978879;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978879', '39343', '100', '1', '1', '2', '4');

-- http://www.wowhead.com/item=39970/fire-leaf#milling
DELETE FROM `milling_loot_template` WHERE entry=39970;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('39970', '978877', '100', '1', '0', '-978877', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('39970', '978878', '25', '1', '0', '-978878', '1');

-- http://de.wowhead.com/item=36901/goldklee#milling
DELETE FROM `milling_loot_template` WHERE entry=36901;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('36901', '978877', '100', '1', '0', '-978877', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('36901', '978878', '25', '1', '0', '-978878', '1');

-- http://www.wowhead.com/item=36905/lichbloom#milling
DELETE FROM `milling_loot_template` WHERE entry=36905;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('36905', '978879', '100', '1', '0', '-978879', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('36905', '978878', '50', '1', '0', '-978878', '1');

-- http://www.wowhead.com/item=36903/adders-tongue#milling
DELETE FROM `milling_loot_template` WHERE entry=36903;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('36903', '978879', '100', '1', '0', '-978879', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('36903', '978878', '50', '1', '0', '-978878', '1');

-- http://de.wowhead.com/item=36907/talandras-rose#milling
DELETE FROM `milling_loot_template` WHERE entry=36907;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('36907', '978877', '100', '1', '0', '-978877', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('36907', '978878', '25', '1', '0', '-978878', '1');

-- http://www.wowhead.com/item=36904/tiger-lily#milling
DELETE FROM `milling_loot_template` WHERE entry=36904;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('36904', '978877', '100', '1', '0', '-978877', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('36904', '978878', '25', '1', '0', '-978878', '1');

-- http://www.wowhead.com/item=39969/fire-seed#milling
DELETE FROM `milling_loot_template` WHERE entry=39969;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('39969', '978877', '100', '1', '0', '-978877', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('39969', '978878', '25', '1', '0', '-978878', '1');

-- Milling Loot for Skill 425

-- http://www.wowhead.com/item=52983/cinderbloom#milling
DELETE FROM `milling_loot_template` WHERE entry=52983;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('52983', '978880', '100', '1', '0', '-978880', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('52983', '978881', '25', '1', '0', '-978881', '1');

DELETE FROM `reference_loot_template` WHERE entry in (978880, 978881, 978882);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978880', '61979', '100', '1', '1', '2', '4');
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978881', '61980', '100', '1', '1', '1', '3');
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978882', '61979', '100', '1', '1', '2', '3');

-- http://www.wowhead.com/item=52984/stormvine#milling
DELETE FROM `milling_loot_template` WHERE entry=52984;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('52984', '978882', '100', '1', '0', '-978882', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('52984', '978881', '25', '1', '0', '-978881', '1');

-- http://www.wowhead.com/item=52985/azsharas-veil#milling
DELETE FROM `milling_loot_template` WHERE entry=52985;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('52985', '978882', '100', '1', '0', '-978882', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('52985', '978881', '25', '1', '0', '-978881', '1');

-- http://www.wowhead.com/item=52986/heartblossom#milling
DELETE FROM `milling_loot_template` WHERE entry=52986;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('52986', '978880', '100', '1', '0', '-978880', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('52986', '978881', '25', '1', '0', '-978881', '1');

-- http://www.wowhead.com/item=52987/twilight-jasmine#milling
DELETE FROM `milling_loot_template` WHERE entry=52987;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('52987', '978880', '100', '1', '0', '-978880', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('52987', '978881', '50', '1', '0', '-978881', '1');

-- http://www.wowhead.com/item=52988/whiptail#milling
DELETE FROM `milling_loot_template` WHERE entry=52988;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('52988', '978880', '100', '1', '0', '-978880', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('52988', '978881', '50', '1', '0', '-978881', '1');

-- Milling Loot for Skill 500
-- http://www.wowhead.com/item=72234/green-tea-leaf#milling
DELETE FROM `milling_loot_template` WHERE entry=72234;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('72234', '978885', '100', '1', '0', '-978885', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('72234', '978884', '25', '1', '0', '-978884', '1');

DELETE FROM `reference_loot_template` WHERE entry in (978883, 978884, 978885);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978883', '79251', '100', '1', '1', '2', '4');
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978884', '79253', '100', '1', '1', '1', '3');
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('978885', '79251', '100', '1', '1', '2', '3');

-- http://www.wowhead.com/item=72237/rain-poppy#milling
DELETE FROM `milling_loot_template` WHERE entry=72237;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('72237', '978885', '100', '1', '0', '-978885', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('72237', '978884', '25', '1', '0', '-978884', '1');

-- http://www.wowhead.com/item=72235/silkweed#milling
DELETE FROM `milling_loot_template` WHERE entry=72235;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('72235', '978885', '100', '1', '0', '-978885', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('72235', '978884', '25', '1', '0', '-978884', '1');

-- http://www.wowhead.com/item=79010/snow-lily#milling
DELETE FROM `milling_loot_template` WHERE entry=79010;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('79010', '978885', '100', '1', '0', '-978885', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('79010', '978884', '25', '1', '0', '-978884', '1');

-- http://www.wowhead.com/item=89639/desecrated-herb#milling
DELETE FROM `milling_loot_template` WHERE entry=89639;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('89639', '978885', '100', '1', '0', '-978885', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('89639', '978884', '25', '1', '0', '-978884', '1');

-- http://www.wowhead.com/item=79011/fools-cap#milling
DELETE FROM `milling_loot_template` WHERE entry=79011;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('79011', '978883', '100', '1', '0', '-978883', '1');
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES ('79011', '978884', '50', '1', '0', '-978884', '1');