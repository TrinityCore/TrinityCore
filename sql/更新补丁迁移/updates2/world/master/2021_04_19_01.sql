-- DB update 2021_04_19_00 -> 2021_04_19_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_19_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_19_00 2021_04_19_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1618169172923159272'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1618169172923159272');

DELETE FROM `gameobject` WHERE (`id` = 2040) AND (`guid` IN (32880)); -- mithril vein duplicate
DELETE FROM `gameobject` WHERE (`id` = 3726) AND (`guid` IN (13596)); -- earthroot duplicate
DELETE FROM `gameobject` WHERE (`id` = 175404) AND (`guid` IN (17506, 17507)); -- rich thorium veins duplicate

-- fix spawn small thorium vein
DELETE FROM `gameobject` WHERE (`id` = 324) AND (`guid` IN (317));
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES
(317, 324, 1, 0, 0, 1, 1, -7213.251465, -2300.464355, -262.501099, 3.603, 0, 0, -0.973506, 0.228663, 2700, 100, 1, '', 0);

DELETE FROM `gameobject` WHERE (`id` = 324) AND (`guid` IN (374)); -- small thorium vein cluster (removed 1 on 3)

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
