-- DB update 2021_03_10_01 -> 2021_03_11_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_10_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_10_01 2021_03_11_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613964585221980000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613964585221980000');

-- setting the rares always spawned to have a chance to despawn in SAI, that's how the others are already implemented
-- setting them all to 85% chance to despawn 
-- reinserting their other actions to update the IDs 

-- Bannok Grimaxe 
SET @ENTRY := 9596;
DELETE FROM smart_scripts WHERE entryOrGuid = 9596 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 85, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - None: Despawn in 0.5 s"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 2300, 3200, 9500, 11000, 11, 6466, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Every 9.5 - 11 seconds (2.3 - 3.2s initially)  - Self: Cast spell Axe Toss (6466) on Random hostile");

-- crystal fang
SET @ENTRY := 10376;
DELETE FROM smart_scripts WHERE entryOrGuid = 10376 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 85, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - None: Despawn in 0.5 s"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 2, 5000, 10000, 5000, 10000, 11, 16416, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Every 5 - 10 seconds  - Self: Cast spell Summon Spire Spiderling (16416) on Random hostile");

-- spirestone battle lord
SET @ENTRY := 9218;
DELETE FROM smart_scripts WHERE entryOrGuid = 9218 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 85, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - None: Despawn in 0.5 s"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 2100, 3300, 12500, 14000, 11, 13496, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 12.5 - 14 seconds (2.1 - 3.3s initially)  - Self: Cast spell Dazed (13496) on Victim (flags: 32)");

-- spirestone butcher
SET @ENTRY := 9219;
DELETE FROM smart_scripts WHERE entryOrGuid = 9219 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 85, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - None: Despawn in 0.5 s"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 2100, 3300, 12500, 14000, 11, 13496, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 12.5 - 14 seconds (2.1 - 3.3s initially)  - Self: Cast spell Dazed (13496) on Victim (flags: 32)");

-- spirestone lord magus
SET @ENTRY := 9217;
DELETE FROM smart_scripts WHERE entryOrGuid = 9217 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 85, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - None: Despawn in 0.5 s"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 2, 0, 0, 2400, 3800, 11, 15230, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 2.4 - 3.8 seconds (0 - 0s initially)  - Self: Cast spell Arcane Bolt (15230) on Victim (flags: 64)"),
(@ENTRY, 0, 2, 0, 0, 0, 100, 2, 7000, 12000, 14000, 19000, 11, 13323, 1, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, "Every 14 - 19 seconds (7 - 12s initially)  - Self: Cast spell Polymorph (13323) on Random hostile (not top) (flags: 1)"),
(@ENTRY, 0, 3, 0, 2, 0, 100, 2, 0, 50, 25000, 30000, 11, 8365, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0 and 50 (check every 25000 - 30000 ms) - Self: Cast spell Enlarge (8365) on Self (flags: 1)"),
(@ENTRY, 0, 4, 0, 2, 0, 100, 2, 0, 30, 30000, 35000, 11, 6742, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0 and 30 (check every 30000 - 35000 ms) - Self: Cast spell Bloodlust (6742) on Self (flags: 1)");

-- meshlok the harvester
SET @ENTRY := 12237;
DELETE FROM smart_scripts WHERE entryOrGuid = 12237 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 85, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - None: Despawn in 0.5 s"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 1000, 5000, 5000, 7000, 11, 13446, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 5 - 7 seconds (1 - 5s initially)  - Self: Cast spell Strike (13446) on Victim"),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 4000, 15000, 18500, 24000, 11, 15593, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 18.5 - 24 seconds (4 - 15s initially)  - Self: Cast spell War Stomp (15593) on Self");

-- Jed runewatcher
SET @ENTRY := 10509;
DELETE FROM smart_scripts WHERE entryOrGuid = 10509 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 85, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - None: Despawn in 0.5 s"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 2, 5000, 7000, 4000, 6000, 11, 14516, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 4 - 6 seconds (5 - 7s initially)  - Self: Cast spell Strike (14516) on Victim"),
(@ENTRY, 0, 2, 0, 0, 0, 100, 2, 10000, 10000, 10000, 10000, 11, 11972, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 10 seconds  - Self: Cast spell Shield Bash (11972) on Victim"),
(@ENTRY, 0, 3, 0, 0, 0, 100, 2, 10000, 10000, 5000, 15000, 11, 15749, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Every 5 - 15 seconds (10 - 10s initially)  - Self: Cast spell Shield Charge (15749) on Random hostile");

-- goraluk anvilcrack
SET @ENTRY := 10899;
DELETE FROM smart_scripts WHERE entryOrGuid = 10899 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 85, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - None: Despawn in 0.5 s"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 2, 5000, 7000, 4000, 6000, 11, 15580, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 4 - 6 seconds (5 - 7s initially)  - Self: Cast spell Strike (15580) on Victim"),
(@ENTRY, 0, 2, 0, 0, 0, 100, 2, 5000, 10000, 20000, 20000, 11, 16172, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 20 - 20 seconds (5 - 10s initially)  - Self: Cast spell Head Crack (16172) on Victim"),
(@ENTRY, 0, 3, 0, 0, 0, 100, 2, 10000, 10000, 10000, 10000, 11, 6253, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 10 seconds  - Self: Cast spell Backhand (6253) on Victim");

-- warder stilgiss and Verek
-- verek is his pet, give the warder a command to despawn his pet with himself, added some waits otherwise it doesn't work.
SET @ENTRY := 9041;
DELETE FROM smart_scripts WHERE entryOrGuid = 9041 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 80, 0, 0, 0, 0, 0, 67, 1, 500, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Trigger timed event #1 in 500 - 500 ms // -meta_wait"),
(@ENTRY, 0, 1, 2, 59, 0, 100, 0, 1, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 10, 47775, 9042, 0, 0, 0, 0, 0, "On timed event 1 triggered - None: Despawn in 0.5 s"),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On link - None: Despawn in 1 s"),
(@ENTRY, 0, 3, 0, 1, 0, 100, 2, 1000, 1000, 1800000, 1800000, 11, 12544, 33, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 1800 seconds (1s initially)  - Self: Cast spell Frost Armor (12544) on Self (flags: interrupt previous, aura not present)"),
(@ENTRY, 0, 4, 0, 0, 0, 100, 2, 0, 0, 2400, 3800, 11, 12675, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 2.4 - 3.8 seconds (0 - 0s initially)  - Self: Cast spell Frostbolt (12675) on Victim (flags: combat move)"),
(@ENTRY, 0, 5, 0, 0, 0, 100, 2, 7000, 9000, 14000, 18000, 11, 12674, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 14 - 18 seconds (7 - 9s initially)  - Self: Cast spell Frost Nova (12674) on Self (flags: interrupt previous)"),
(@ENTRY, 0, 6, 0, 0, 0, 100, 2, 3000, 4000, 65000, 70000, 11, 15044, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 65 - 70 seconds (3 - 4s initially)  - Self: Cast spell Frost Ward (15044) on Self (flags: interrupt previous)"),
(@ENTRY, 0, 7, 0, 2, 0, 100, 3, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0 and 15 (check every 0 - 0 ms) - Self: Flee for assist");

-- Adding missing spawns
-- TODO : add them the chance to despawn 

DELETE FROM `creature` WHERE `guid` IN (300627, 56961, 300376, 300742, 300768, 160358, 160355, 300452);
DELETE FROM `creature_addon` WHERE `guid` IN (300627, 56961, 300376, 300742, 300768, 160358, 160355);
DELETE FROM `waypoint_data` WHERE `id` IN (3000627, 3000376, 3000768);

-- BRD : Panzor the Invincible
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES (300627, 8923, 230, 0, 0, 1, 1, 0, 0, 1135.47, -163.023, -74.9241, 1.82485, 86400, 0, 0, 13495, 0, 2, 0, 0, 0, '', 0);
-- creature addon
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `isLarge`, `auras`) VALUES (300627, 3000627, 0, 0, 0, 0, 0, '9941');
-- waypoints
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES 
(3000627, 1, 1135.47, -163.023, -74.9241, 4.04912, 0),
(3000627, 2, 1151.34, -149.749, -74.9109, 0.577659, 0),
(3000627, 3, 1174.82, -157.929, -74.3609, 5.78171, 0),
(3000627, 4, 1185.95, -150.753, -74.3652, 0.672688, 0),
(3000627, 5, 1171.12, -136.046, -74.3652, 2.59848, 0),
(3000627, 6, 1158.67, -131.772, -74.3652, 3.14984, 0),
(3000627, 7, 1133.39, -127.555, -74.3622, 3.11213, 0),
(3000627, 8, 1111.74, -136.947, -74.3463, 3.78758, 0),
(3000627, 9, 1098.5, -150.236, -65.3899, 3.97372, 0),
(3000627, 10, 1083.84, -166.332, -65.3101, 3.97372, 0),
(3000627, 11, 1068.86, -185.53, -64.1101, 3.97372, 0),
(3000627, 12, 1055.53, -197.829, -62.8376, 3.86298, 0),
(3000627, 13, 1045.28, -208.278, -61.8399, 0.815619, 0),
(3000627, 14, 1061.09, -194.831, -63.2302, 0.888661, 0),
(3000627, 15, 1075.18, -178.83, -65.0597, 0.888661, 0),
(3000627, 16, 1084.06, -168.537, -65.3082, 0.667178, 0),
(3000627, 17, 1094.07, -167.277, -65.3082, 5.77227, 0),
(3000627, 18, 1113.1, -187.895, -65.4175, 5.59948, 0),
(3000627, 19, 1126.49, -198.759, -65.4502, 5.8186, 0),
(3000627, 20, 1140.48, -202.571, -65.3502, 0.086769, 0),
(3000627, 21, 1153.21, -201.446, -65.374, 0.343594, 0),
(3000627, 22, 1172.86, -191.437, -65.4455, 0.786559, 0),
(3000627, 23, 1159.8, -203.03, -65.4447, 3.6352, 0),
(3000627, 24, 1144.47, -202.718, -65.3172, 3.01081, 0),
(3000627, 25, 1124.53, -196.103, -65.4567, 2.5702, 0),
(3000627, 26, 1114.1, -185.864, -65.3084, 2.31102, 0),
(3000627, 27, 1100.52, -171.005, -65.3084, 2.31102, 0),
(3000627, 28, 1099.18, -151.247, -65.3098, 1.07166, 0),
(3000627, 29, 1110.93, -139.12, -74.253, 0.800697, 0),
(3000627, 30, 1128.29, -136.767, -74.3582, 5.57121, 0),
(3000627, 31, 1135.2, -148.836, -74.3582, 4.87142, 0),
(3000627, 32, 1136.29, -155.672, -74.9172, 4.87142, 0);

-- Dire maul : Tsu'Zee
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES (56961, 11467, 429, 0, 0, 1, 1, 0, 1, 128.643, 561.759, -4.31221, 3.12414, 86400, 0, 0, 18642, 0, 0, 0, 0, 0, '', 0);
-- update tsu'zee to have her daggers drawn (blizzlike)
UPDATE `creature_template_addon` SET `bytes2`='1' WHERE  `entry`=11467;

-- Dark Iron Ambassador
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES (300376, 6228, 90, 0, 0, 1, 1, 0, 1, -718.106, 565.242, -289.116, 6.03311, 86400, 0, 0, 3660, 0, 2, 0, 0, 0, '', 0);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `isLarge`, `auras`) VALUES (300376, 3000376, 0, 0, 1, 0, 0, '');
-- waypoints
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES 
(3000376, 1, -698.351, 559.918, -282.06, 6.01478, 0),
(3000376, 2, -736.867, 569.914, -291.06, 4.36542, 0),
(3000376, 3, -743.754, 581.403, -291.06, 2.05638, 0),
(3000376, 4, -734.431, 619.357, -300.06, 1.31614, 0),
(3000376, 5, -726.929, 649.513, -309.06, 1.34361, 0),
(3000376, 6, -717.134, 687.832, -318.06, 1.26506, 0),
(3000376, 7, -705.253, 694.829, -318.06, 0.471789, 0),
(3000376, 8, -717.059, 687.506, -318.06, 4.36151, 0),
(3000376, 9, -726.776, 650.171, -309.06, 4.389, 0),
(3000376, 10, -734.225, 619.203, -300.06, 1.31416, 0),
(3000376, 11, -743.649, 581.74, -291.06, 4.92503, 0),
(3000376, 12, -736.919, 569.825, -291.06, 5.79487, 0);

-- LBRS : Ghok Bashguud
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES (300742, 9718, 229, 0, 0, 1, 1, 0, 1, -89.99, -291.27, 70.9524, 3.86922, 86400, 0, 0, 9321, 0, 0, 0, 0, 0, '', 0);

-- Maraudon entrance : Cursed centaur
-- TODO : his speed is bugged
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES (300768, 11688, 1, 0, 0, 1, 1, 0, 0, -1367.46, 2863.52, 76.9984, 4.55409, 27000, 0, 0, 2060, 0, 2, 0, 0, 0, '', 0);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `isLarge`, `auras`) VALUES (300768, 3000768, 0, 0, 0, 0, 0, '');

INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES 
(3000768, 1, -1367.46, 2863.52, 76.9984, 0),
(3000768, 2, -1393.99, 2851.21, 77.72, 0),
(3000768, 3, -1426.31, 2868.61, 86.2046, 0),
(3000768, 4, -1427.88, 2884.84, 89.9063, 0),
(3000768, 5, -1420.99, 2906.7, 94.5393, 0),
(3000768, 6, -1418.45, 2928.4, 94.7818, 0),
(3000768, 7, -1433.51, 2944.64, 94.8155, 0),
(3000768, 8, -1432.78, 2965.33, 98.78, 0),
(3000768, 9, -1428.64, 2976.88, 100.431, 0),
(3000768, 10, -1417.76, 2980.47, 100.451, 0),
(3000768, 11, -1396.98, 2982, 106.209, 0),
(3000768, 12, -1398.01, 2992.11, 106.395, 0),
(3000768, 13, -1430.1, 2989.54, 115.13, 0),
(3000768, 14, -1437.65, 3005.34, 115.32, 0),
(3000768, 15, -1450.26, 2993.12, 114.956, 0),
(3000768, 16, -1477.64, 2978.38, 117.61, 0),
(3000768, 17, -1493.41, 2968.92, 119.813, 0),
(3000768, 18, -1495.62, 2957.85, 120.792, 0),
(3000768, 19, -1486.37, 2950.08, 121.468, 0),
(3000768, 20, -1469.83, 2953.44, 121.791, 0),
(3000768, 21, -1441.3, 2962, 123.975, 0),
(3000768, 22, -1418.32, 2959.49, 123.981, 0),
(3000768, 23, -1401.41, 2956.93, 126.774, 0),
(3000768, 24, -1404.8, 2983.21, 130.022, 0),
(3000768, 25, -1425.63, 2982.74, 133.145, 0),
(3000768, 26, -1425.4, 2963, 134.552, 0),
(3000768, 27, -1426.04, 2946.67, 134.535, 0),
(3000768, 28, -1423.48, 2933.21, 135.64, 0),
(3000768, 29, -1426.04, 2946.67, 134.535, 0),
(3000768, 30, -1425.4, 2963, 134.552, 0),
(3000768, 31, -1425.63, 2982.74, 133.145, 0),
(3000768, 32, -1404.87, 2983.71, 130.018, 0),
(3000768, 33, -1401.17, 2956.9, 126.803, 0),
(3000768, 34, -1418.32, 2959.49, 123.981, 0),
(3000768, 35, -1441.02, 2961.97, 123.979, 0),
(3000768, 36, -1469.83, 2953.44, 121.791, 0),
(3000768, 37, -1486.37, 2950.08, 121.468, 0),
(3000768, 38, -1495.62, 2957.85, 120.792, 0),
(3000768, 39, -1493.41, 2968.92, 119.813, 0),
(3000768, 40, -1477.64, 2978.38, 117.61, 0),
(3000768, 41, -1450.26, 2993.12, 114.956, 0),
(3000768, 42, -1437.65, 3005.34, 115.32, 0),
(3000768, 43, -1430.1, 2989.54, 115.13, 0),
(3000768, 44, -1398.01, 2992.11, 106.395, 0),
(3000768, 45, -1396.98, 2982, 106.209, 0),
(3000768, 46, -1417.5, 2980.56, 100.429, 0),
(3000768, 47, -1428.64, 2976.88, 100.431, 0),
(3000768, 48, -1432.78, 2965.33, 98.78, 0),
(3000768, 49, -1433.51, 2944.64, 94.8155, 0),
(3000768, 50, -1418.45, 2928.4, 94.7818, 0),
(3000768, 51, -1420.99, 2906.7, 94.5393, 0),
(3000768, 52, -1427.88, 2884.84, 89.9063, 0),
(3000768, 53, -1426.31, 2868.61, 86.2046, 0),
(3000768, 54, -1393.99, 2851.21, 77.72, 0),
(3000768, 55, -1367.46, 2863.52, 76.9984, 0),
(3000768, 56, -1351.69, 2867.27, 76.8984, 0);
-- missing spell : curse of the tribes
SET @ENTRY := 11688;
DELETE FROM smart_scripts WHERE entryOrGuid = 11688 AND source_type = 0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry= @ENTRY;
INSERT INTO smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z, target_o, comment) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 9000, 14000, 25000, 35000, 11, 21048, 32, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Every 25 - 35 seconds (9 - 14s initially)  - Self: Cast spell Curse of the Tribes (21048) on Random hostile (flags: aura not present)");

-- Trigore the Lasher
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES (300452, 3652, 1, 0, 0, 1, 1, 0, 0, -621.612, -2270.82, 18.8419, 2.67112, 216000, 0, 0, 483, 0, 0, 0, 0, 0, '', 0);

-- Veyzhak the Cannibal
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES (160358, 5399, 0, 0, 0, 1, 1, 0, 1, -10301, -4028.2, -74.8377, 2.79036, 28800, 0, 0, 3093, 0, 0, 0, 0, 0, '', 0);

-- zekkis
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES (160355, 5400, 0, 0, 0, 1, 1, 0, 1, -10250.9, -4006.4, -99.7118, 0.401091, 28800, 0, 0, 3093, 0, 0, 0, 0, 0, '', 0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
