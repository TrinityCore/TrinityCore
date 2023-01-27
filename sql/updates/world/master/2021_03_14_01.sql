-- DB update 2021_03_14_00 -> 2021_03_14_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_14_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_14_00 2021_03_14_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615207809116814300'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615207809116814300');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 3375;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3375);
INSERT INTO `smart_scripts` VALUES
(3375, 0, 0, 0, 0, 0, 100, 1, 100, 100, 1000, 1000, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bael\'dun Foreman - In Combat - Enable Combat Movement (No Repeat)'),
(3375, 0, 1, 0, 0, 0, 100, 0, 1000, 2000, 3000, 4000, 0, 11, 6257, 64, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 'Bael\'dun Foreman - In Combat - Cast \'Torch Toss\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 5849;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 5849);
INSERT INTO `smart_scripts` VALUES
(5849, 0, 0, 0, 0, 0, 80, 0, 12500, 12500, 10000, 10000, 0, 11, 6253, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Digger Flameforge - In Combat - Cast \'Backhand\''),
(5849, 0, 1, 0, 0, 0, 100, 1, 100, 100, 1000, 1000, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Digger Flameforge - In Combat - Enable Combat Movement (No Repeat)'),
(5849, 0, 2, 0, 0, 0, 100, 0, 2000, 2000, 2000, 2000, 0, 11, 7978, 64, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 'Digger Flameforge - In Combat - Cast \'Throw Dynamite\'');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
