-- DB update 2021_02_28_01 -> 2021_02_28_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_28_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_28_01 2021_02_28_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614416165680486700'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614416165680486700');

DELETE FROM `smart_scripts` WHERE (`entryorguid` = 356800) AND (`source_type` = 9);

DELETE FROM `smart_scripts` WHERE (`entryorguid` = 356801) AND (`source_type` = 9);

DELETE FROM `creature_template` WHERE (`entry` = 3568);
INSERT INTO `creature_template` VALUES
(3568, 0, 0, 0, 0, 0, 599, 0, 0, 0, 'Mist', '', '', 0, 10, 10, 0, 80, 2, 1, 1.2, 1, 0, 11, 14, 0, 10, 1, 1500, 1500, 1, 4608, 2048, 0, 2, 0, 0, 0, 0, 7, 10, 5, 1, 4096, 0, 0, 100001, 150, 150, 150, 150, 150, 150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, '', 12340);

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3568);
INSERT INTO `smart_scripts` VALUES
(3568, 0, 0, 1, 19, 0, 100, 0, 938, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mist - On Quest \'Mist\' Taken - Set Event Phase 1'),
(3568, 0, 1, 2, 61, 1, 100, 0, 938, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mist - On Quest \'Mist\' Taken - Remove Npc Flags Questgiver'),
(3568, 0, 2, 3, 61, 1, 100, 0, 938, 0, 0, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mist - On Quest \'Mist\' Taken - Remove Flags Immune To NPC\'s'),
(3568, 0, 3, 4, 61, 1, 100, 0, 938, 0, 0, 0, 0, 29, 1, 1, 3519, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Mist - On Quest \'Mist\' Taken - Start Follow Invoker'),
(3568, 0, 4, 0, 61, 1, 100, 0, 938, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mist - On Quest \'Mist\' Taken - Set Event Phase 0'),
(3568, 0, 5, 0, 1, 0, 100, 1, 100, 100, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mist - Out of Combat - Set Reactstate Defensive (No Repeat)'),
(3568, 0, 6, 0, 75, 0, 100, 0, 0, 3519, 9, 900, 0, 15, 938, 0, 0, 0, 0, 0, 18, 9, 0, 0, 0, 0, 0, 0, 0, 'Mist - On Distance To Creature - Quest Credit \'Mist\''),
(3568, 0, 7, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 6, 938, 0, 0, 0, 0, 0, 18, 30, 0, 0, 0, 0, 0, 0, 0, 'Mist - On Just Died - Fail Quest \'Mist\''),
(3568, 0, 8, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 70, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mist - On Just Died - Respawn Self'),
(3568, 0, 9, 10, 11, 0, 100, 0, 1, 1, 141, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mist - On Respawn - Set Event Phase 1'),
(3568, 0, 10, 11, 61, 1, 100, 0, 1, 1, 141, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mist - On Respawn - Set Flags Immune To NPC\'s'),
(3568, 0, 11, 0, 61, 1, 100, 0, 1, 1, 141, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mist - On Respawn - Set Npc Flags Questgiver'),
(3568, 0, 12, 0, 65, 0, 100, 0, 0, 0, 0, 0, 0, 70, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mist - On Follow Complete - Respawn Self'),
(3568, 0, 13, 0, 75, 0, 100, 1, 0, 3519, 10, 500, 0, 1, 0, 1000, 1, 0, 0, 0, 19, 3519, 10, 0, 0, 0, 0, 0, 0, 'Mist - On Distance To Creature - Say Line 0 (No Repeat)'),
(3568, 0, 14, 0, 75, 0, 100, 1, 0, 3519, 10, 500, 0, 1, 0, 1000, 0, 0, 0, 0, 19, 3519, 10, 0, 0, 0, 0, 0, 0, 'Mist - On Distance To Creature - Say Line 0 (No Repeat)');

DELETE FROM `factiontemplate_dbc` WHERE (`ID` = 80);
INSERT INTO `factiontemplate_dbc` VALUES (80, 69, 72, 3, 2, 12, 0, 0, 0, 0, 69, 0, 0, 0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
