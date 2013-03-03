SET @GUID = 209102;

-- add creatures
DELETE FROM `creature` WHERE `id` IN (28601, 28602) AND `map`=1;
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(@GUID+00,28601, 1, -6027.13, -1249.12, -146.765, 0.0407544),
(@GUID+01,28602, 1, -6165.74, -1250.34, -162.183, 3.16428),
(@GUID+02,28602, 1, -6118.16, -1258.77, -143.281, 3.17606),
(@GUID+03,28602, 1, -6118.18, -1241.33, -143.281, 3.12169),
(@GUID+04,28602, 1, -6104.87, -1256.41, -143.281, 3.04315),
(@GUID+05,28602, 1, -6104.56, -1243.58, -143.281, 3.07064),
(@GUID+06,28602, 1, -6067.35, -1243.76, -143.481, 3.17274),
(@GUID+07,28602, 1, -6067.17, -1255.45, -143.430, 3.15703),
(@GUID+08,28602, 1, -6038.16, -1243.56, -146.897, 3.15153),
(@GUID+09,28602, 1, -6036.82, -1255.32, -146.901, 3.19238),
(@GUID+10,28602, 1, -6042.26, -1249.25, -146.887, 3.19238);

-- add weapons to creatures
DELETE FROM `creature_equip_template` WHERE `entry`=2476;
INSERT INTO `creature_equip_template` VALUES
(2476, 7714, 0, 0);

-- correct creature_template
UPDATE `creature_template` SET `faction_A` = 2080, `faction_H` = 2080, `lootid` = `entry` WHERE `entry` IN (28601, 28602);
UPDATE `creature_template` SET `equipment_id` = 1803 WHERE `entry`=28601;
UPDATE `creature_template` SET `equipment_id` = 2476 WHERE `entry`=28601;

-- create questloot
DELETE FROM `creature_loot_template` WHERE `entry`=28601;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(28601, 38708, -100, 1, 0, 1, 1);
