-- DB update 2021_04_18_01 -> 2021_04_18_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_18_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_18_01 2021_04_18_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614130170345582600'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614130170345582600');

DELETE FROM `creature` WHERE `id` IN (2603, 2604, 2605, 2606, 14231, 14233, 14235, 14236, 14237, 14429);
DELETE FROM `creature_addon` WHERE `guid` IN (301300, 301292, 300777);
DELETE FROM `waypoint_data` WHERE `id` IN (3013000, 3012920, 3007770);
DELETE FROM `pool_creature` WHERE `pool_entry` IN (2605, 2606, 42939, 43157);
DELETE FROM `pool_template` WHERE `entry` IN (2605, 2606, 42939, 43157);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES 
(2605, 1, 'zalas witherbark'),
(2606, 1, 'nimar the slayer'),
(42939, 1, 'Drogoth the Roamer'),
(43157, 1, 'Ripscale');

-- arathi highlands
-- Kovork,
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES (300753, 2603, 0, -1192.92, -2079.91, 44.328, 1.92247, 27000, 0, 0);
-- molok the crusher
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES (300754, 2604, 0, -2044.39, -2803.18, 72.7163, 5.29147, 54000, 5, 1);
-- zalas witherbark
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES
(300757, 2605, 0, -2044.94, -3359.01, 60.6886, 0.443181, 252000, 5, 1),
(301300, 2605, 0, -2056.85, -3271.49, 49.4426, 3.13338, 252000, 0, 2),
(301301, 2605, 0, -2021.36, -3309.32, 54.3502, 5.92935, 252000, 0, 0),
(301302, 2605, 0, -2075.02, -3289.68, 67.3143, 3.72238, 252000, 5, 1);
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES 
(301300, 2605, 0, 'Zalas Witherbark (Youfie)'),
(301301, 2605, 0, 'Zalas Witherbark (Youfie)'),
(301302, 2605, 0, 'Zalas Witherbark (Youfie)'),
(300757, 2605, 0, 'Zalas Witherbark (Youfie)');
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `isLarge`, `auras`) VALUES (301300, 3013000, 0, 0, 1, 0, 0, '');
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(3013000, 1, -2056.85, -3271.49, 49.4426, 3.13338, 0),
(3013000, 2, -2061.19, -3271.54, 50.2861, 3.15301, 500000),
(3013000, 3, -2083.62, -3276.01, 51.4356, 3.35722, 0),
(3013000, 4, -2098.75, -3286.29, 51.7022, 4.22115, 10000),
(3013000, 5, -2106.52, -3322.71, 56.8964, 1.3191, 0),
(3013000, 6, -2115.63, -3344.91, 58.7511, 4.33895, 10000),
(3013000, 7, -2109.39, -3369.78, 61.0127, 5.03795, 0),
(3013000, 8, -2091.81, -3381.89, 59.4361, 5.79586, 5000),
(3013000, 9, -2095.79, -3366.71, 59.3, 2.34403, 0),
(3013000, 10, -2093.88, -3364.27, 59.1176, 0.808577, 500000),
(3013000, 11, -2099.47, -3360.35, 59.2716, 2.55215, 0),
(3013000, 12, -2102.05, -3333.13, 58.104, 1.66465, 10000),
(3013000, 13, -2095.42, -3295.27, 52.4655, 1.09524, 0),
(3013000, 14, -2078.4, -3272.51, 51.7336, 0.965648, 0),
(3013000, 15, -2055.61, -3271.22, 49.3672, 3.19225, 0);
-- add two missing spells to Zalas and correct his timers based on vmangos
SET @ENTRY := 2605;
DELETE FROM smart_scripts WHERE entryOrGuid = 2605 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 80, 0, 5000, 5000, 15000, 25000, 11, 512, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 15 - 25 seconds (5 - 5s initially)  - Self: Cast spell Chains of Ice (512) on Victim"),
(@ENTRY, 0, 1, 0, 0, 0, 80, 0, 3000, 3000, 15000, 15000, 11, 851, 1, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, "Every 15 seconds (3s initially)  - Self: Cast spell Polymorph: Sheep (851) on Random hostile (not top) (flags: interrupt previous)"),
(@ENTRY, 0, 2, 0, 60, 0, 100, 0, 1000, 3000, 5000, 15000, 11, 4974, 32, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Every 5 - 15 seconds (1 - 3s initially) - Self: Cast spell Wither Touch (4974) on Random hostile (flags: aura not present)"),
(@ENTRY, 0, 3, 0, 60, 0, 100, 0, 5000, 8000, 8000, 15000, 11, 9081, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Every 8 - 15 seconds (5 - 8s initially) - Self: Cast spell Shadow Bolt Volley (9081) on Random hostile");


-- nimar the slayer
-- TODO : he has a script or emote where he eats meat
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES
(300755, 2606, 0, -1902.16, -3193.09, 56.5808, 5.63212, 27000, 0, 0),
(301290, 2606, 0, -1810.14, -3417.2, 45.4232, 0.985671, 27000, 0, 0),
(301291, 2606, 0, -1701.21, -3509.16, 60.2556, 6.26748, 27000, 5, 1),
(301292, 2606, 0, -1672.56, -3246.93, 25.7297, 4.51998, 27000, 0, 2);
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES 
(300755, 2606, 0, 'Nimar the Slayer (Youfie)'),
(301290, 2606, 0, 'Nimar the Slayer (Youfie)'),
(301291, 2606, 0, 'Nimar the Slayer (Youfie)'),
(301292, 2606, 0, 'Nimar the Slayer (Youfie)');
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `isLarge`, `auras`) VALUES (301292, 3012920, 0, 0, 1, 0, 0, '');
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(3012920, 1, -1672.56, -3246.93, 25.7297, 4.51998, 0),
(3012920, 2, -1673.33, -3252.4, 25.7306, 4.57495, 120000),
(3012920, 3, -1679.78, -3257.49, 25.5371, 3.8406, 0),
(3012920, 4, -1678.29, -3264.48, 24.3447, 5.92976, 0),
(3012920, 5, -1650.41, -3263.6, 26.8072, 6.20386, 0),
(3012920, 6, -1642.67, -3252.82, 31.5431, 1.3933, 0),
(3012920, 7, -1645.48, -3241.07, 33.4071, 2.38133, 0),
(3012920, 8, -1654.84, -3232.66, 33.5165, 2.42452, 0),
(3012920, 9, -1670.32, -3228.45, 34.6906, 2.91933, 0),
(3012920, 10, -1693.22, -3231.79, 29.2882, 6.01379, 0),
(3012920, 11, -1693.78, -3246.29, 26.4924, 4.78071, 0),
(3012920, 12, -1672.47, -3263.53, 25.0571, 5.57397, 15000),
(3012920, 13, -1668.16, -3255.58, 25.73, 2.7269, 0),
(3012920, 14, -1673.27, -3253.71, 25.7309, 1.5056, 0);
-- add cleave and berserker stance
SET @ENTRY := 2606;
DELETE FROM smart_scripts WHERE entryOrGuid = 2606 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 1000, 1000, 240000, 240000, 11, 2458, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 240 seconds (1s initially) - Self: Cast spell Berserker Stance (2458) on Self"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 7800, 10000, 11100, 24200, 11, 17207, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 11.1 - 24.2 seconds (7.8 - 10s initially)  - Self: Cast spell Whirlwind (17207) on Victim"),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 7000, 13000, 7000, 23000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 7 - 23 seconds (7 - 13s initially)  - Self: Cast spell Cleave (15496) on Victim"),
(@ENTRY, 0, 3, 0, 12, 0, 100, 1, 0, 30, 0, 0, 11, 7160, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When victim health between 0 - 30 (check every 0 - 0) - Self: Cast spell Execute (7160) on Victim (flags: interrupt previous)"),
(@ENTRY, 0, 4, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When health between 0 and 15 (check every 0 - 0 ms) - Self: Flee for assist");

-- dustwallow marsh
-- drogoth the roamer
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES
(300769, 14231, 1, -2608.36, -3011.72, 29.4168, 0.0195422, 27000, 10, 1),
(300770, 14231, 1, -2799.72, -3129.45, 28.7032, 4.41743, 27000, 5, 1);
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES (300769, 42939, 0, 'Dustwallow Marsh: Drogoth the Roamer');
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES (300770, 42939, 0, 'Dustwallow Marsh: Drogoth the Roamer');
-- ripscale
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES
(300775, 14233, 1, -3969.57, -3182.07, 28.8974, 3.08685, 38000, 10, 1),
(300776, 14233, 1, -4040.93, -3557.63, 28.5225, 5.65789, 38000, 10, 1);
DELETE FROM `pool_creature` WHERE `guid` IN (300775,300776);
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(300775, 43157, 0, 'Dustwallow Marsh: Ripscale'),
(300776, 43157, 0, 'Dustwallow Marsh: Ripscale');
-- The rot
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES (300773, 14235, 1, -4042.09, -3753.6, 43.2492, 6.26622, 108000, 5, 1);
-- lord angler
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES (300771, 14236, 1, -4250.64, -3849.09, -6.71606, 5.12114, 108000, 5, 1);
-- oozeworm
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES (300772, 14237, 1, -4207.99, -2911.04, 44.9497, 2.051, 180000, 5, 1);

-- teldrassil
-- grimmaw
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES (300777, 14429, 1, 9132.61, 1651.7, 1322.14, 4.25837, 9000, 0, 2);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `isLarge`, `auras`) VALUES (300777, 3007770, 0, 0, 1, 0, 0, '');
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(3007770, 1, 9132.81, 1664.76, 1320.77, 4.74146, 0),
(3007770, 2, 9141.27, 1690.01, 1320.05, 1.23858, 0),
(3007770, 3, 9141.58, 1727.6, 1319.16, 1.73339, 0),
(3007770, 4, 9137.61, 1753.82, 1319.01, 1.808, 0),
(3007770, 5, 9116, 1771.33, 1321.66, 2.04362, 0),
(3007770, 6, 9109.14, 1808.41, 1325.54, 1.66663, 0),
(3007770, 7, 9111.24, 1823.84, 1328.53, 4.67864, 0),
(3007770, 8, 9108.77, 1809.06, 1325.75, 4.86517, 0),
(3007770, 9, 9115.99, 1771.94, 1321.74, 5.14595, 0),
(3007770, 10, 9136.82, 1754.07, 1318.87, 4.75914, 0),
(3007770, 11, 9141.64, 1726.7, 1319.16, 4.60991, 0),
(3007770, 12, 9141.35, 1689.69, 1320.03, 4.60991, 0),
(3007770, 13, 9131.44, 1665.16, 1320.95, 4.71202, 0),
(3007770, 14, 9132.59, 1646.61, 1322.61, 4.6806, 0);
-- add missing spell vicious bite
SET @ENTRY := 14429;
DELETE FROM smart_scripts WHERE entryOrGuid = 14429 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 6000, 8000, 11, 19319, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 6 - 8 seconds (4 - 4s initially)  - Self: Cast spell Vicious Bite (19319) on Victim");

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
