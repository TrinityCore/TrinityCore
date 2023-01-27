-- DB update 2021_04_01_21 -> 2021_04_02_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_21';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_21 2021_04_02_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616252213942835800'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616252213942835800');
/*
 * Zone: Hellfire Peninsula
 * Update by Knindza | <www.azerothcore.org>
*/

/* SMARTSCRIPT */
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 16927;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 16927);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16927, 0, 0, 1, 2, 0, 100, 1, 70, 90, 0, 0, 11, 33896, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stonescythe Whelp - Between 70-90% Health - Cast \'33896\' (No Repeat)'),
(16927, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 33897, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stonescythe Whelp - Between 70-90% Health - Remove Aura \'33897\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 16966;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 16966);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16966, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 10000, 12500, 11, 9532, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Haal\'eshi Windwalker - In Combat - Cast \'9532\''),
(16966, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 32717, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Haal\'eshi Windwalker - Between 20-80% Health - Cast \'32717\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 16967;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 16967);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16967, 0, 0, 0, 11, 0, 100, 1, 0, 0, 0, 0, 11, 29651, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Haal\'eshi Talonguard - On Respawn - Cast \'29651\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24920;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 24920);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24920, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 15000, 20000, 11, 46202, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorthorn Flayer - In Combat - Cast \'46202\''),
(24920, 0, 1, 0, 0, 0, 100, 0, 10000, 12500, 25000, 30000, 11, 13443, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Razorthorn Flayer - In Combat - Cast \'13443\''),
(24920, 0, 2, 3, 2, 0, 100, 1, 20, 80, 0, 0, 11, 33896, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razorthorn Flayer - Between 20-80% Health - Cast \'33896\' (No Repeat)'),
(24920, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 28, 33897, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razorthorn Flayer - Between 20-80% Health - Remove Aura \'33897\' (No Repeat)'),
(24920, 0, 4, 0, 2, 0, 100, 1, 10, 30, 0, 0, 11, 33898, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Razorthorn Flayer - Between 10-30% Health - Cast \'33898\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 16946;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 16946);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16946, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 32735, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Mo\'arg Forgefiend - On Aggro - Cast \'32735\' (No Repeat)'),
(16946, 0, 1, 0, 0, 0, 100, 0, 2500, 5000, 15000, 20000, 11, 36486, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Mo\'arg Forgefiend - In Combat - Cast \'36486\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 16947;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 16947);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16947, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 32003, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Gan\'arg Servant - In Combat - Cast \'32003\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 18974;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 18974);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18974, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 10000, 12500, 11, 32004, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Z\'kral - In Combat - Cast \'32004\''),
(18974, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 32003, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Z\'kral - In Combat - Cast \'32003\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19408;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19408);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19408, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 10000, 15000, 11, 15968, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Maiden of Pain - In Combat - Cast \'15968\''),
(19408, 0, 1, 0, 2, 0, 100, 1, 10, 30, 0, 0, 11, 40743, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiden of Pain - Between 10-30% Health - Cast \'40743\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 16879;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 16879);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16879, 0, 0, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 33908, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Starving Helboar - Between 20-80% Health - Cast \'33908\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 18978;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 18978);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18978, 0, 0, 0, 11, 0, 100, 1, 0, 0, 0, 0, 11, 11968, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Heckling Fel Sprite - On Respawn - Cast \'11968\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19261;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19261);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19261, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 19483, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infernal Warbringer - On Aggro - Cast \'19483\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 18975;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 18975);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18975, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 10000, 15000, 11, 33800, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wrathguard - In Combat - Cast \'33800\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19282;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19282);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19282, 0, 0, 0, 11, 0, 100, 1, 0, 0, 0, 0, 11, 29651, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Subjugator Shi\'aziv - On Respawn - Cast \'29651\' (No Repeat)'),
(19282, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 32026, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Subjugator Shi\'aziv - In Combat - Cast \'32026\''),
(19282, 0, 2, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 32000, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Subjugator Shi\'aziv - Between 20-80% Health - Cast \'32000\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19335;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19335);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19335, 0, 0, 0, 11, 0, 100, 1, 0, 0, 0, 0, 11, 29651, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Subjugator Yalqiz - On Respawn - Cast \'29651\' (No Repeat)'),
(19335, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 32026, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Yalqiz - In Combat - Cast \'32026\''),
(19335, 0, 2, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 32000, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Subjugator Yalqiz - Between 20-80% Health - Cast \'32000\' (No Repeat)');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
