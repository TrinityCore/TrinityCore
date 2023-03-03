-- DB update 2021_02_14_06 -> 2021_02_14_07
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_14_06';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_14_06 2021_02_14_07 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613242843051334000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613242843051334000');

/* Adjust Position and remove piece of Ham from Reese Langston
   Source: https://wow.gamepedia.com/Reese_Langston
*/

UPDATE `creature_equip_template` SET `ItemID2` = 0 WHERE (`CreatureID` = 1327);

DELETE FROM `creature` WHERE (`id` = 1327) AND (`guid` IN (79751));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(79751, 1327, 0, 0, 0, 1, 1, 0, 1, -8606.001953, 383.925995, 102.923599, 3.79168, 310, 0, 0, 1003, 0, 0, 0, 0, 0, '', 0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
