-- DB update 2021_03_09_01 -> 2021_03_09_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_09_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_09_01 2021_03_09_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615132077108569700'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615132077108569700');

-- Draenei Commoner BloodElf Commoner --
DELETE FROM `creature` WHERE (`id` = 19171) AND (`guid` IN (91587));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(91587, 19171, 530, 0, 0, 1, 1, 18842, 1, -3807.906738, -11710.348633, -106.454651, 3.477165, 180, 0, 0, 42, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE (`id` = 19171) AND (`guid` IN (91588));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(91588, 19171, 530, 0, 0, 1, 1, 18842, 1, -3812.004639, -11712.501953, -106.513107, 0.934427, 180, 0, 0, 42, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `game_event_creature` WHERE (`eventEntry` = 12) AND (`guid` IN (84418,84419,84423,84424,84400,84402,84409,84410,84430,84435,84440,84441));
INSERT INTO `game_event_creature` VALUES
(12, 84418),
(12, 84419),
(12, 84423),
(12, 84424),
(12, 84400),
(12, 84402),
(12, 84409),
(12, 84410),
(12, 84430),
(12, 84435),
(12, 84440),
(12, 84441);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
