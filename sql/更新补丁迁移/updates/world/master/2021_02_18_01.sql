-- DB update 2021_02_18_00 -> 2021_02_18_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_18_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_18_00 2021_02_18_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613390656721660682'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613390656721660682');

-- Tormek Stoneriver was removed in v3.3.0
DELETE FROM `creature` WHERE `guid`=244510;

-- Quests 'Dearest Colara,' should be marked as deprecated
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (8897,8898,8899);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1,8897,0,"","","Deprecated quest: Dearest Colara,"),
(1,8898,0,"","","Deprecated quest: Dearest Colara,"),
(1,8899,0,"","","Deprecated quest: Dearest Colara,");

-- Remove creature/quest relationship
DELETE FROM `creature_queststarter` WHERE `quest` IN (8897,8898,8899);
DELETE FROM `creature_questender` WHERE `quest` IN (8897,8898,8899);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
