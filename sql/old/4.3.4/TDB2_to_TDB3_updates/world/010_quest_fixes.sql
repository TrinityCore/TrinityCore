-- Quest #13521 Buzzbox 413 - fix: Adding the Corrupted Tide Crawler Flesh, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 32935 AND `item` = 44863;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(32935, 44863, -40, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 32935 WHERE `entry` = 32935; 

-- Quest #13528 Buzzbox 723 - fix: Adding the Corrupted Thistle Bear Guts, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 33905 AND `item` = 44913;
DELETE FROM `creature_loot_template` WHERE `entry` = 33009 AND `item` = 44913;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(33905, 44913, -35, 1, 0, 1, 1),
(33009, 44913, -32, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 33905 WHERE `entry` = 33905; 
UPDATE `creature_template` SET `lootid` = 33009 WHERE `entry` = 33009; 

-- Quest #13513 On the Brink - fix: Adding the Shatterspear Amulet, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 32860 AND `item` = 44942;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(32860, 44942, -83, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 32860 WHERE `entry` = 32860; 

-- Quest #13844 The Looting of Althalaxx - fix: create the Charred Book loot
DELETE FROM `gameobject_loot_template` WHERE `entry` = 24124 AND `item` = 45944;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(24124, 45944, -100, 1, 0, 1, 1);

-- Quest #13554 A Cure In The Dark - fix: Adding the Foul Ichor, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 33021 AND `item` = 44966;
DELETE FROM `creature_loot_template` WHERE `entry` = 33022 AND `item` = 44966;
DELETE FROM `creature_loot_template` WHERE `entry` = 33020 AND `item` = 44966;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(33021, 44966, -35, 1, 0, 1, 1),
(33022, 44966, -34, 1, 0, 1, 1),
(33020, 44966, -20, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 33021 WHERE `entry` = 33021; 
UPDATE `creature_template` SET `lootid` = 33022 WHERE `entry` = 33022; 
UPDATE `creature_template` SET `lootid` = 33020 WHERE `entry` = 33020; 

-- Quest #26264 What's Left Behind - fix: Adding the Recovered Possession, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 42184 AND `item` = 57987;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(42184, 57987, -89, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 42184 WHERE `entry` = 42184; 

-- Quest #26285 Get Me Explosives Back! - fix: Adding the Stolen Powder Keg, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 42221 AND `item` = 58202;
DELETE FROM `creature_loot_template` WHERE `entry` = 42222 AND `item` = 58202;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(42221, 58202, -95, 1, 0, 1, 1),
(42222, 58202, -86, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 42221 WHERE `entry` = 42221; 
UPDATE `creature_template` SET `lootid` = 42222 WHERE `entry` = 42222; 

-- Quest #25722 Sedimentary, My Dear - fix: Adding the Flood Sediment Sample
DELETE FROM `gameobject_loot_template` WHERE `entry` = 29569 AND `item` = 55231;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(29569, 55231, -100, 1, 0, 1, 1);

-- Quest #25726 A Dumpy Job - fix: Adding the Dumpy Level, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 41145 AND `item` = 55234;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(41145, 55234, -9, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 41145 WHERE `entry` = 41145; 

-- Quest #25727 Drungeld Glowerglare - fix: Adding the Glowerglare's Beard
DELETE FROM `creature_loot_template` WHERE `entry` = 41151 AND `item` = 55988;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(41151, 55988, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 41151 WHERE `entry` = 41151; 

-- Quest #25522 Gargantapid - fix: Adding the Gargantapid's Poison Gland
DELETE FROM `creature_loot_template` WHERE `entry` = 40581 AND `item` = 54855;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(40581, 54855, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 40581 WHERE `entry` = 40581; 

-- Quest #25521 I'm With Scorpid - fix: Adding the Duneclaw Stinger. the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 40656 AND `item` = 54856;
DELETE FROM `creature_loot_template` WHERE `entry` = 40717 AND `item` = 54856;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(40656, 54856, -49, 1, 0, 1, 1),
(40717, 54856, -48, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 40656 WHERE `entry` = 40656; 
UPDATE `creature_template` SET `lootid` = 40717 WHERE `entry` = 40717;

-- Quest #24931 Gazer Tag - fix: Adding the Ocular Crystal, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 5420 AND `item` = 51793;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(5420, 51793, -40, 1, 0, 1, 1);

-- Quest #28530 Scalding Signs - fix: Adding the Suspicious Green Sludge, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 48767 AND `item` = 64449;
DELETE FROM `creature_loot_template` WHERE `entry` = 48768 AND `item` = 64449;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(48767, 64449, -44, 1, 0, 1, 1),
(48768, 64449, -41, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 48767 WHERE `entry` = 48767; 
UPDATE `creature_template` SET `lootid` = 48768 WHERE `entry` = 48768; 

-- Quest #28625 Chop Chop - fix: Adding the Fresh-Cut Frostwood
DELETE FROM `creature_loot_template` WHERE `entry` = 48952 AND `item` = 64587;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(48952, 64587, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 48952 WHERE `entry` = 48952; 

-- Quest #28610 Rubble Trouble - fix: Adding the Prime Rubble Chunk, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 48960 AND `item` = 64586;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(48960, 64586, -71, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 48960 WHERE `entry` = 48960; 

-- Quest #28837 Altered Beasts - fix: Adding the Mana-Addled Brain, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 49161 AND `item` = 66052;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(49161, 66052, -42, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 49161 WHERE `entry` = 49161; 

-- Quest #28537 In Pursuit of Shades - fix: Adding the Shard of the Spiritspeaker
DELETE FROM `creature_loot_template` WHERE `entry` = 48678 AND `item` = 64463;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(48678, 64463, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 48678 WHERE `entry` = 48678; 

-- Quest #28540 Doin' De E'ko Magic - fix: Adding the Rimepelt's Heart
DELETE FROM `creature_loot_template` WHERE `entry` = 48765 AND `item` = 64465;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(48765, 64465, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 48765 WHERE `entry` = 48765; 

-- Quest #28631 The Perfect Horns - fix: Adding the Icewhomp's Pristine Horns, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 49235 AND `item` = 64664;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(49235, 64664, -57, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 49235 WHERE `entry` = 49235; 

-- Quest #28840 Winterwater - fix: Adding the Winterwater, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 50251 AND `item` = 65903;
DELETE FROM `creature_loot_template` WHERE `entry` = 50250 AND `item` = 65903;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(50251, 65903, -28, 1, 0, 1, 1),
(50250, 65903, -24, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 50251 WHERE `entry` = 50251; 
UPDATE `creature_template` SET `lootid` = 50250 WHERE `entry` = 50250; 

-- Quest #28518 Legacy of the High Elves - fix: Adding the Memory of Zin-Malor
DELETE FROM `creature_loot_template` WHERE `entry` = 48740 AND `item` = 64441;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(48740, 64441, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 48740 WHERE `entry` = 48740; 

-- Quest #25607 Ze Gnomecorder - fix: Adding the Filthy Goblin Technology, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 34590 AND `item` = 55144;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(34590, 55144, -55, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 34590 WHERE `entry` = 34590; 

-- Quest #13979 The Goblin Braintrust - fix: Adding the Sploder's Head
DELETE FROM `creature_loot_template` WHERE `entry` = 34591 AND `item` = 46768;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(34591, 46768, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 34591 WHERE `entry` = 34591; 
