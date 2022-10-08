-- DB update 2021_04_18_02 -> 2021_04_18_03
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_18_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_18_02 2021_04_18_03 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1618147391543148390'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1618147391543148390');

DELETE FROM `creature` WHERE (`id` = 6909) AND (`guid` IN (2499));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(2499, 6909, 1, 0, 0, 1, 1, 0, 0, 11077.9, 1902.37, 1342.63, 2.18262, 516, 0, 0, 247, 0, 2, 0, 0, 0, '', 0);

DELETE FROM `creature_addon` WHERE (`guid` IN (2499));
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `isLarge`, `auras`) VALUES
(2499, 24990, 0, 0, 4097, 0, 0, NULL);

DELETE FROM `waypoint_data` WHERE `id` = 24990;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(24990, 1, 11052.318359, 1921.549927, 1332.641724, 2.536241, 0, 0, 0, 100, 0),
(24990, 2, 11021.328125, 1909.217896, 1327.031128, 3.541551, 12000, 0, 0, 100, 0),
(24990, 3, 11027.135742, 1911.013672, 1327.976685, 1.816816, 5000, 0, 0, 100, 0),
(24990, 4, 11052.318359, 1921.549927, 1332.641724, 2.536241, 0, 0, 0, 100, 0),
(24990, 5, 11077.9, 1902.37, 1342.63, 2.18262, 3000, 0, 0, 100, 0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
