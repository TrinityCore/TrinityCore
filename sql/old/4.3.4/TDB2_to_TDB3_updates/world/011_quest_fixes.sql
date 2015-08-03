-- Quest #24824 The Disturbed Earth - fix: Adding the Disturbed Earth Fragment, the drop % is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 37553 AND `item` = 50385;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(37553, 50385, -39, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 37553 WHERE `entry` = 37553; 

-- Quest #26159 (Alliance) & #25685 (Horde) The First Step - fix: Adding the Snickerfang Hyena Blood and Redstone Basilisk Blood, the drop rate is from wowhead
DELETE FROM `creature_loot_template` WHERE `entry` = 5985 AND `item` = 55826;
DELETE FROM `creature_loot_template` WHERE `entry` = 5990 AND `item` = 55827;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(5985, 55826, -69, 1, 0, 1, 1),
(5990, 55827, -64, 1, 0, 1, 1);

-- Quest #26172 (Alliance) & #25690 (Horde) A Bloodmage's Gotta Eat Too - fix: Adding the Ashmane Steak, the drop rate is from wow head
DELETE FROM `creature_loot_template` WHERE `entry` = 5992 AND `item` = 55828;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(5992, 55828, -29, 1, 0, 1, 1);

-- Quest #25716 Cultists at our Doorstep - fix: Adding the Intact Shadowsworn Spell Focus, the drop rate is from wow head
DELETE FROM `creature_loot_template` WHERE `entry` = 42297 AND `item` = 57134;
DELETE FROM `creature_loot_template` WHERE `entry` = 42296 AND `item` = 57134;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(42297, 57134, -78, 1, 0, 1, 1),
(42296, 57134, -71, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 42297 WHERE `entry` = 42297; 
UPDATE `creature_template` SET `lootid` = 42296 WHERE `entry` = 42296; 

-- Quest #26165 (Alliance) & #25692 (Horde) The Vile Blood of Demons - fix: Adding the Vile Demonic Blood, the drop rate is from wow head
DELETE FROM `creature_loot_template` WHERE `entry` = 6011 AND `item` = 55991;
DELETE FROM `creature_loot_template` WHERE `entry` = 41253 AND `item` = 55991;
DELETE FROM `creature_loot_template` WHERE `entry` = 6010 AND `item` = 55991;
DELETE FROM `creature_loot_template` WHERE `entry` = 41166 AND `item` = 55991;
DELETE FROM `creature_loot_template` WHERE `entry` = 41165 AND `item` = 55991;
DELETE FROM `creature_loot_template` WHERE `entry` = 41164 AND `item` = 55991;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(6011, 55991, -36, 1, 0, 1, 1),
(41253, 55991, -33, 1, 0, 1, 1),
(6010, 55991, -32, 1, 0, 1, 1),
(41166, 55991, -16, 1, 0, 1, 1),
(41165, 55991, -16, 1, 0, 1, 1),
(41164, 55991, -11, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 6011 WHERE `entry` = 6011; 
UPDATE `creature_template` SET `lootid` = 41253 WHERE `entry` = 41253; 
UPDATE `creature_template` SET `lootid` = 6010 WHERE `entry` = 6010; 
UPDATE `creature_template` SET `lootid` = 41166 WHERE `entry` = 41166; 
UPDATE `creature_template` SET `lootid` = 41165 WHERE `entry` = 41165; 
UPDATE `creature_template` SET `lootid` = 41164 WHERE `entry` = 41164;

-- Quest #26389 Blackrock Invasion - fix: Adding the Blackrock Orc Weapon
DELETE FROM `creature_loot_template` WHERE `entry` = 42937 AND `item` = 58361;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) 
VALUES (42937, 58361, -100, 1, 0, 1, 1);
UPDATE `creature_template` SET `lootid` = 42937 WHERE `entry` = 42937; 

-- Quest #26152 Wanted: James Clark - fix: Adding the James Clark's Head
DELETE FROM `creature_loot_template` WHERE `entry` = 13159 AND `item` = 57122;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) 
VALUES (13159, 57122, -100, 1, 0, 1, 1);

-- Quest #86 Pie for Billy - fix: Adding the Tender Boar Meat, the drop rates are from wow head
DELETE FROM `creature_loot_template` WHERE `entry` = 113 AND `item` = 60401;
DELETE FROM `creature_loot_template` WHERE `entry` = 524 AND `item` = 60401;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(113, 60401, -21, 1, 0, 1, 1),
(524, 60401, -12, 1, 0, 1, 1);
