-- DB update 2021_04_01_14 -> 2021_04_01_15
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_14';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_14 2021_04_01_15 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617176680426521000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617176680426521000');

UPDATE `creature_template` SET `speed_walk` = 0.9, `speed_run` = 1.1 WHERE `entry` IN (15958, 15656);

DELETE FROM `creature_summon_groups` WHERE (`summonerId` = 15402);

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 15958);
INSERT INTO `smart_scripts` VALUES
(15958, 0, 4, 0, 75, 0, 100, 0, 0, 15402, 53, 900, 0, 49, 0, 0, 0, 0, 0, 0, 19, 15402, 53, 0, 0, 0, 0, 0, 0, 'Gharsul the Remorseless - On Distance To Creature - Start Attacking');

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 15656);
INSERT INTO `smart_scripts` VALUES
(15656, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Angershade - Between 0-30% Health - Cast \'Enrage\' (No Repeat)'),
(15656, 0, 1, 0, 61, 0, 100, 0, 0, 30, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Angershade - Between 0-30% Health - Say Line 0 (No Repeat)'),
(15656, 0, 2, 0, 75, 0, 100, 0, 0, 15402, 53, 900, 0, 49, 0, 0, 0, 0, 0, 0, 19, 15402, 53, 0, 0, 0, 0, 0, 0, 'Angershade - On Distance To Creature - Start Attacking');

DELETE FROM `waypoints` WHERE (`entry` IN (15656, 15958));

UPDATE `creature_template` SET `HealthModifier` = 2, `ManaModifier` = 3, `ArmorModifier` = 1 WHERE (`entry` = 15402);

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 15402);
INSERT INTO `smart_scripts` VALUES
(15402, 0, 0, 0, 20, 0, 100, 0, 8487, 0, 0, 0, 0, 80, 1540200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - On Quest \'Corrupted Soil\' Finished - Run Script'),
(15402, 0, 1, 2, 19, 0, 100, 0, 8488, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - On Quest \'Unexpected Results\' Taken - Store Targetlist'),
(15402, 0, 2, 0, 61, 0, 100, 0, 8488, 0, 0, 0, 0, 80, 1540201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - On Quest \'Unexpected Results\' Taken - Run Script'),
(15402, 0, 3, 0, 0, 0, 100, 0, 900, 900, 3000, 4000, 0, 11, 20811, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - In Combat - Cast \'Fireball\''),
(15402, 0, 4, 0, 6, 1, 100, 0, 0, 0, 0, 0, 0, 6, 8488, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - On Just Died - Fail Quest \'Unexpected Results\' (Phase 1)'),
(15402, 0, 5, 6, 7, 1, 100, 0, 0, 0, 0, 0, 0, 15, 8488, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - On Evade - Quest Credit \'Unexpected Results\' (Phase 1)'),
(15402, 0, 6, 0, 61, 1, 100, 0, 0, 0, 0, 0, 0, 80, 1540202, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - On Evade - Run Script (Phase 1)'),
(15402, 0, 7, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Apprentice Mirveda - On Respawn - Set Flags Immune To NPC\'s');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
