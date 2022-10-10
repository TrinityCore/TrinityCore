-- DB update 2021_02_15_02 -> 2021_02_16_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_15_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_15_02 2021_02_16_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613367143020390000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613367143020390000');

/* Quest 'The Attack!' Improvements
*/

DELETE FROM `creature` WHERE `id` = 7779;

/*  Not part of 'The Attack!', but in the same area - NPC was stuck in the wall
*/

DELETE FROM `creature` WHERE (`id` = 24729) AND (`guid` IN (49591));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(49591, 24729, 0, 0, 0, 1, 1, 344, 0, -8406.450195, 482.553864, 123.759903, 1.84221, 180, 3, 0, 8982, 0, 1, 0, 0, 0, '', 0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
