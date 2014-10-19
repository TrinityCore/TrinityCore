-- *** FIXES FOR DUN MOROGH ***

-- Quest #24475 fix : All the Other Stuff.  Add the quest loot to the timber wolf, young wolf and boar
DELETE FROM `creature_loot_template` WHERE `entry` = 708 AND `item` = 49747;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (708, 49747, -39, 1, 0, 1, 1);
DELETE FROM `creature_loot_template` WHERE `entry` = 705 AND `item` = 49748;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (705, 49748, -64, 1, 0, 1, 1);
DELETE FROM `creature_loot_template` WHERE `entry` = 704 AND `item` = 49748;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (704, 49748, -70, 1, 0, 1, 1);


-- Quest #24486 fix : Make Hay While the Sun Shines.  Add the Priceless Rockjaw Artifact loot to the Rockjaw Scavenger so you can complete the quest
DELETE FROM `creature_loot_template` WHERE `entry` = 37105 AND `item` = 49751;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (37105, 49751, -90, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 37105 WHERE `entry` = 37105; 


-- Quest #384 fix: Adding the tender boar meat to the crag boar, the 41% rate is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 1125 AND `item` = 60496;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (1125, 60496, -41, 1, 0, 1, 1);
-- Quest #384 fix: Last gossip_menu_id was 1297 but it was preventing players from trading with the innkeeper and setting their heartstone in that region
UPDATE `creature_template` SET `gossip_menu_id` = 0 WHERE `entry` = 1247; 


-- Quest #25997 fix: Adding Dark Iron Attack Plans
DELETE FROM `creature_loot_template` WHERE `entry` = 6124 AND `item` = 56264;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (6124, 56264, -100, 1, 0, 1, 1);



-- *** FIXES FOR LOCH MODAN ***

-- Quest #26845 fix: Adding the Foreman Sharpsneer's Head
DELETE FROM `creature_loot_template` WHERE `entry` = 44198 AND `item` = 60404;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (44198, 60404, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 44198 WHERE `entry` = 44198; 


-- Quest #26842 fix: Adding Mosshide Ear
DELETE FROM `creature_loot_template` WHERE `entry` = 44162 AND `item` = 60402;
DELETE FROM `creature_loot_template` WHERE `entry` = 44161 AND `item` = 60402;
DELETE FROM `creature_loot_template` WHERE `entry` = 45384 AND `item` = 60402;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(44162, 60402, -100, 1, 0, 1, 1),
(44161, 60402, -100, 1, 0, 1, 1),
(45384, 60402, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 44162 WHERE `entry` = 44162; 
UPDATE `creature_template` SET `lootid` = 44161 WHERE `entry` = 44161; 
UPDATE `creature_template` SET `lootid` = 45384 WHERE `entry` = 45384; 


-- Quest #26928 fix: Adding Murloc Scent Gland, the drop rates are from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 44176 AND `item` = 60511;
DELETE FROM `creature_loot_template` WHERE `entry` = 44292 AND `item` = 60511;
DELETE FROM `creature_loot_template` WHERE `entry` = 45401 AND `item` = 60511;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(44176, 60511, -45, 1, 0, 1, 1),
(44292, 60511, -38, 1, 0, 1, 1),
(45401, 60511, -30, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 44176 WHERE `entry` = 44176; 
UPDATE `creature_template` SET `lootid` = 44292 WHERE `entry` = 44292; 
UPDATE `creature_template` SET `lootid` = 45401 WHERE `entry` = 45401; 


-- Quest #26929 fix: Adding Intact Crocolisk Jaw, the 44% drop rates is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 1693 AND `item` = 57131;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(1693, 57131, -44, 1, 0, 1, 1);


-- Quest #26860 fix: Adding Bear Rump, the 56% drop rates is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 1186 AND `item` = 60497;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(1186, 60497, -56, 1, 0, 1, 1);


-- Quest #27031 Wing Nut - fix: Adding the Pristine Flight Feather, the 34% drop rate is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 44628 AND `item` = 60792;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) 
VALUES (44628, 60792, -34, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 44628 WHERE `entry` = 44628; 


-- Quest #27028 Hornet Hunting - fix: Adding the Glassy Hornet Wing, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 44620 AND `item` = 60754;
DELETE FROM `creature_loot_template` WHERE `entry` = 45402 AND `item` = 60754;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(44620, 60754, -41, 1, 0, 1, 1),
(45402, 60754, -32, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 44620 WHERE `entry` = 44620; 
UPDATE `creature_template` SET `lootid` = 45402 WHERE `entry` = 45402; 


-- Quest #27030 Foxtails by the handful - fix: Adding the Fluffy Fox Tail, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 44635 AND `item` = 60755;
DELETE FROM `creature_loot_template` WHERE `entry` = 45380 AND `item` = 60755;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(44635, 60755, -81, 1, 0, 1, 1),
(45380, 60755, -53, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 44635 WHERE `entry` = 44635; 
UPDATE `creature_template` SET `lootid` = 45380 WHERE `entry` = 45380; 



-- *** FIXES FOR THE WETLANDS ***

-- Quest #25800 When Life Gives You Crabs - fix: Adding the Meaty Crawler Claw, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 44116 AND `item` = 56013;
DELETE FROM `creature_loot_template` WHERE `entry` = 41295 AND `item` = 56013;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(44116, 56013, -43, 1, 0, 1, 1),
(41295, 56013, -36, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 44116 WHERE `entry` = 44116; 
UPDATE `creature_template` SET `lootid` = 41295 WHERE `entry` = 41295;


-- Quest #25723 Thresh Out of Luck - fix: Adding the Threshadon Chunk, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 41137 AND `item` = 55232;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(41137, 55232, -94, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 41137 WHERE `entry` = 41137; 


-- Quest #25849 When Archaeology Attacks - fix: Adding the Fossilized Bone, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 41388 AND `item` = 56083;
DELETE FROM `creature_loot_template` WHERE `entry` = 44226 AND `item` = 56083;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(41388, 56083, -68, 1, 0, 1, 3),
(44226, 56083, -5, 1, 0, 1, 3);
UPDATE `creature_template` SET `lootid` = 41388 WHERE `entry` = 41388; 
UPDATE `creature_template` SET `lootid` = 44226 WHERE `entry` = 44226; 


-- Quest #25853 Tooling Around - fix: Adding the Archaeologist's Tools
DELETE FROM `gameobject_loot_template` WHERE `entry` = 29626 AND `item` = 56082;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(29626, 56082, -100, 1, 0, 1, 1);



-- *** FIXES FOR THE HINTERLANDS ***

-- Quest #26490 (Alliance) & #26283 (Horde) Prime Slime - fix: Adding the Direglob Sample
DELETE FROM `creature_loot_template` WHERE `entry` = 42592 AND `item` = 58082;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(42592, 58082, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 42592 WHERE `entry` = 42592; 
