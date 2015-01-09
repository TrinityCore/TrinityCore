/* Quests */

-- Fix the quest chain for quests 26845, 26864, 26927, 26928 & 26868 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26845 WHERE `Id` = 26864;
UPDATE `quest_template` SET `PrevQuestId` = 26864 WHERE `Id` = 26927;
UPDATE `quest_template` SET `PrevQuestId` = 26927 WHERE `Id` = 26928;
UPDATE `quest_template` SET `PrevQuestId` = 26928 WHERE `Id` = 26868;
-- Fix the quest chain for quests 25722, 25726 & 25734 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 25722 WHERE `Id` = 25726;
UPDATE `quest_template` SET `PrevQuestId` = 25726 WHERE `Id` = 25734;
-- Fix the quest chain for quests 25802, 25803, 25804 & 25805 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 25802 WHERE `Id` = 25803;
UPDATE `quest_template` SET `PrevQuestId` = 25803 WHERE `Id` = 25804;
UPDATE `quest_template` SET `PrevQuestId` = 25804 WHERE `Id` = 25805;
-- Fix the quest chain for quests 26980, 25864 & 25865 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26980 WHERE `Id` = 25864;
UPDATE `quest_template` SET `PrevQuestId` = 25864 WHERE `Id` = 25865;
-- Fix the quest chain for quests 25856 & 25857 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 25856 WHERE `Id` = 25857;
-- Fix the quest chain for quests 25854 & 25855 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 25854 WHERE `Id` = 25855;
-- Fix the quest chain for quests 25939 & 26196 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 25939 WHERE `Id` = 26196;
-- Fix the quest chain for quests 25926 & 25927 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 25926 WHERE `Id` = 25927;
-- Fix the quest chain for quests 26327, 26127, 26128 & 26139 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26327 WHERE `Id` = 26127;
UPDATE `quest_template` SET `PrevQuestId` = 26127 WHERE `Id` = 26128;
UPDATE `quest_template` SET `PrevQuestId` = 26128 WHERE `Id` = 26139;
-- Fix the quest chain for quests 13639, 309 & 13650 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 13639 WHERE `Id` = 309;
UPDATE `quest_template` SET `PrevQuestId` = 309 WHERE `Id` = 13650;
-- Fix the quest chain for quests 26981, 25849, 26189 & 26195 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26981 WHERE `Id` = 25849;
UPDATE `quest_template` SET `PrevQuestId` = 25849 WHERE `Id` = 26189;
UPDATE `quest_template` SET `PrevQuestId` = 26189 WHERE `Id` = 26195;
-- Fix the quest chain for quests 26035, 26036, 26037 & 26038 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26035 WHERE `Id` = 26036;
UPDATE `quest_template` SET `PrevQuestId` = 26036 WHERE `Id` = 26037;
UPDATE `quest_template` SET `PrevQuestId` = 26037 WHERE `Id` = 26038;
-- Fix the quest chain for quests 26113, 26110 & 26114 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26113 WHERE `Id` = 26110;
UPDATE `quest_template` SET `PrevQuestId` = 26110 WHERE `Id` = 26114;
-- Fix the quest chain for quests 26528, 26529, 26530, 26531 & 26532 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26528 WHERE `Id` = 26529;
UPDATE `quest_template` SET `PrevQuestId` = 26529 WHERE `Id` = 26530;
UPDATE `quest_template` SET `PrevQuestId` = 26530 WHERE `Id` = 26531;
UPDATE `quest_template` SET `PrevQuestId` = 26531 WHERE `Id` = 26532;
-- Fix the quest chain for quests 26641 & 26643 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26641 WHERE `Id` = 26643;
-- Fix the quest chain for quests 27775 & 27776 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 27775 WHERE `Id` = 27776;
-- Fix the quest chain for quests 27823 & 27824 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 27823 WHERE `Id` = 27824;
-- Fix the quest chain for quests 26961 & 13647 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 26961 WHERE `Id` = 13647;
-- Fix the quest chain for quests 27031, 27032, 27033, 27034, 27035 & 27074 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 27031 WHERE `Id` = 27032;
UPDATE `quest_template` SET `PrevQuestId` = 27032 WHERE `Id` = 27033;
UPDATE `quest_template` SET `PrevQuestId` = 27033 WHERE `Id` = 27034;
UPDATE `quest_template` SET `PrevQuestId` = 27034 WHERE `Id` = 27035;
UPDATE `quest_template` SET `PrevQuestId` = 27035 WHERE `Id` = 27074;
-- Fix the quest chain for quests 27036 & 27037 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 27036 WHERE `Id` = 27037;
-- Fix the quest chain for quests 27025 & 27026 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 27025 WHERE `Id` = 27026;
-- Fix the quest chain for quests 25841 & 25882 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 25841 WHERE `Id` = 25882;
-- Fix the quest chain for quests 27078, 27115 & 27116 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 27078 WHERE `Id` = 27115;
UPDATE `quest_template` SET `PrevQuestId` = 27115 WHERE `Id` = 27116;
-- Fix the quest chain for quests 24469 & 24470 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 24469 WHERE `Id` = 24470;
-- Fix the quest chain for quests 24474 & 24475 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 24474 WHERE `Id` = 24475;
-- Fix the quest chain for quests 24487 & 182 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 24487 WHERE `Id` = 182;
-- Fix the quest chain for quests 24477 & 24486 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 24477 WHERE `Id` = 24486;
-- Fix the quest chain for quests 218 & 24490 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 218 WHERE `Id` = 24490;
-- Fix the quest chain for quests 24491 & 24492 so they follow the chain correctly
UPDATE `quest_template` SET `PrevQuestId` = 24491 WHERE `Id` = 24492;

/* Loot */

-- Quest #25865 The Mosshide Job - fix: Adding the Ironforge Ingot
DELETE FROM `creature_loot_template` WHERE `entry` IN (41390, 41391) AND `item` = 56088;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(41390, 56088, -90, 1, 0, 1, 1),
(41391, 56088, -90, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 41390 WHERE `entry` = 41390; 
UPDATE `creature_template` SET `lootid` = 41391 WHERE `entry` = 41391; 
-- Quest #25867 Gnoll Escape - fix: Adding the Trapper's Key
DELETE FROM `creature_loot_template` WHERE `entry` IN (41409, 44225) AND `item` = 56081;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(41409, 56081, -100, 1, 0, 1, 1),
(44225, 56081, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 41409 WHERE `entry` = 41409; 
UPDATE `creature_template` SET `lootid` = 44225 WHERE `entry` = 44225; 
-- Quest #25856 Crocolisk Hides - fix: Adding the Marshy Crocolisk Hide
DELETE FROM `creature_loot_template` WHERE `entry` = 41419 AND `item` = 56087;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(41419, 56087, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 41419 WHERE `entry` = 41419; 
-- Quest #25857 Hunting Horrorjaw - fix: Adding the Horrorjaw's Hide
DELETE FROM `creature_loot_template` WHERE `entry` = 41420 AND `item` = 56089;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(41420, 56089, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 41420 WHERE `entry` = 41420; 
-- Quest #26528 The Eye of Shadra - fix: Adding the Eye of Shadra
DELETE FROM `gameobject_loot_template` WHERE `entry` = 30439 AND `item` = 58282;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(30439, 58282, -100, 1, 0, 1, 1);
-- Quest #26530 The Shell of Shadra - fix: Adding the Shell of Shadra
DELETE FROM `creature_loot_template` WHERE `entry` = 42919 AND `item` = 58779;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(42919, 58779, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 42919 WHERE `entry` = 42919; 
-- Quest #27823 A Dwarf's Got Needs - fix: Adding the Shadowstout
DELETE FROM `creature_loot_template` WHERE `entry` IN (2739, 2740) AND `item` = 62510;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(2739, 62510, -90, 1, 0, 1, 2),
(2740, 62510, -90, 1, 0, 1, 2);
