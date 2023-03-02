-- DB update 2021_02_09_02 -> 2021_02_09_03
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_09_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_09_02 2021_02_09_03 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612830072769679900'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612830072769679900');

-- Valiance Keep Footmen on Beach

DELETE FROM `creature_template_addon` WHERE (`entry` = 25313);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `isLarge`, `auras`) VALUES
(25313, 0, 0, 0, 1, 333, 0, '');

DELETE FROM `creature` WHERE (`id` = 25313) AND (`guid` IN (117601, 117608, 117612, 117613));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(117601, 25313, 571, 0, 0, 1, 1, 23031, 1, 2403.63, 5361.29, 1.1795, 1.56207, 300, 0, 0, 3992, 0, 0, 0, 0, 0, '', 0),
(117608, 25313, 571, 0, 0, 1, 1, 23031, 1, 2288.72, 5445.42, 2.50878, 1.26943, 300, 0, 0, 3992, 0, 0, 0, 0, 0, '', 0),
(117612, 25313, 571, 0, 0, 1, 1, 23031, 1, 2336.39, 5445.07, 1.60508, 1.19297, 300, 0, 0, 3992, 0, 0, 0, 0, 0, '', 0),
(117613, 25313, 571, 0, 0, 1, 1, 23031, 1, 2199.33, 5445.66, 1.44701, 4.63712, 300, 0, 0, 3992, 0, 0, 0, 0, 0, '', 0);

-- Valiance Keep Riflemen shooting at Firespitters

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25311;

DELETE FROM `smart_scripts` WHERE (`entryorguid` = 25311) AND (`source_type` = 0) AND (`id` IN (0));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25311, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 6000, 6000, 0, 11, 45761, 0, 0, 0, 0, 0, 19, 24921, 100, 0, 0, 0, 0, 0, 0, 'Valiance Keep Rifleman - Out of Combat - Cast \'Shoot Gun\'');

DELETE FROM `creature` WHERE (`id` = 25311) AND (`guid` IN (117234, 117235, 117236, 117272));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(117234, 25311, 571, 0, 0, 1, 1, 23077, 1, 2173.05835, 5365.190918, 32.893715, 1.240609, 300, 0, 0, 7984, 0, 0, 0, 0, 0, '', 0),
(117235, 25311, 571, 0, 0, 1, 1, 23077, 1, 2171.605225, 5365.785156, 24.299042, 1.236691, 300, 0, 0, 7984, 0, 0, 0, 0, 0, '', 0),
(117236, 25311, 571, 0, 0, 1, 1, 23077, 1, 2176.37207, 5364.32666, 24.247068, 1.197413, 300, 0, 0, 7984, 0, 0, 0, 0, 0, '', 0),
(117272, 25311, 571, 0, 0, 1, 1, 23077, 1, 2176.887207, 5364.059082, 33.037594, 1.25239, 300, 0, 0, 7984, 0, 0, 0, 0, 0, '', 0);

-- Unsheath weapons on Valiance Keep Defender to fall more in line with other guards patrolling and delete Scourged Flamespitter waypoint

DELETE FROM `creature_addon` WHERE (`guid` IN (112674, 112675, 112676, 112681, 118406));
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `isLarge`, `auras`) VALUES
(112674, 1126740, 0, 0, 1, 0, 0, NULL),
(112675, 1126750, 0, 0, 1, 0, 0, NULL),
(112676, 1126760, 0, 0, 1, 0, 0, NULL),
(112681, 1126810, 0, 0, 1, 0, 0, NULL);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
