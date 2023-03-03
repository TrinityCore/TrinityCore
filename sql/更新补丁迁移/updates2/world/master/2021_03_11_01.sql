-- DB update 2021_03_11_00 -> 2021_03_11_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_11_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_11_00 2021_03_11_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615200382358521000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615200382358521000');

DELETE FROM `smart_scripts` WHERE (`source_type` = 9 AND `entryorguid` = 208000);
INSERT INTO `smart_scripts` VALUES
(208000, 9, 0, 0, 0, 0, 100, 0, 100, 100, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Denalan - Actionlist - Set Run Off'),
(208000, 9, 1, 0, 0, 0, 100, 0, 100, 100, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Denalan - Actionlist - Say Line 0'),
(208000, 9, 2, 0, 0, 0, 100, 0, 100, 100, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Denalan - Actionlist - Remove Npc Flags Questgiver'),
(208000, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 9506.29, 720.847, 1256.16, 2.83966, 'Denalan - Actionlist - Move To Position'),
(208000, 9, 4, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 14, 30276, 7510, 1, 0, 0, 0, 0, 0, 'Denalan - Actionlist - Set Orientation Closest Creature \'Sprouted Frond\''),
(208000, 9, 5, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Denalan - Actionlist - Play Emote 16'),
(208000, 9, 6, 0, 0, 0, 100, 0, 4500, 4500, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Denalan - Actionlist - Set Orientation Invoker'),
(208000, 9, 7, 0, 0, 0, 100, 0, 4600, 4600, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Denalan - Actionlist - Say Line 1'),
(208000, 9, 8, 0, 0, 0, 100, 0, 4900, 4900, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 9506.87, 713.719, 1255.89, 0.645772, 'Denalan - Actionlist - Move To Position'),
(208000, 9, 9, 0, 0, 0, 100, 0, 5200, 5200, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Denalan - Actionlist - Add Npc Flags Questgiver'),
(208000, 9, 10, 0, 0, 0, 100, 0, 5700, 5700, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Denalan - Actionlist - Evade');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
