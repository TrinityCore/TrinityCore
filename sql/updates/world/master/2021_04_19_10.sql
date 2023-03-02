-- DB update 2021_04_19_09 -> 2021_04_19_10
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_19_09';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_19_09 2021_04_19_10 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616252834972147900'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616252834972147900');
/*
 * Zone: Shadowmoon Valley
 * Update by Knindza | <www.azerothcore.org>
*/

/* SMARTSCRIPT */
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19788;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19788);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19788, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 38232, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Muckwatcher - On Aggro - Cast \'38232\' (No Repeat)'),
(19788, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 38029, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Muckwatcher - In Combat - Cast \'38029\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19784;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19784);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19784, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 15000, 20000, 11, 38030, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Cobra - In Combat - Cast \'38030\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19767;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19767);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19767, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 10000, 15000, 11, 32011, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Sorceress - In Combat - Cast \'32011\''),
(19767, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 38026, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Sorceress - Between 20-80% Health - Cast \'38026\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19765;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19765);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19765, 0, 0, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 38027, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Coilskar Myrmidon - Between 20-80% Health - Cast \'38027\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 20795;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 20795);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20795, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 10000, 15000, 11, 32011, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Keeper of the Cistern - In Combat - Cast \'32011\''),
(20795, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 11831, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Keeper of the Cistern - Between 20-80% Health - Cast \'11831\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21205;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21205);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21205, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 15000, 20000, 11, 38363, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ravenous Flayer Matriarch - In Combat - Cast \'38363\''),
(21205, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 36464, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ravenous Flayer Matriarch - Between 20-80% Health - Cast \'36464\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21196;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21196);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21196, 0, 0, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 37933, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ravenous Flayer - Between 20-80% Health - Cast \'37933\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21663;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21663);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21663, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 12550, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oronu the Elder - On Aggro - Cast \'12550\' (No Repeat)'),
(21663, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 34079, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oronu the Elder - Between 20-80% Health - Cast \'34079\' (No Repeat)'),
(21663, 0, 2, 0, 2, 0, 100, 1, 10, 30, 0, 0, 11, 11986, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oronu the Elder - Between 10-30% Health - Cast \'11986\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21803;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21803);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21803, 0, 0, 0, 2, 0, 100, 1, 5, 30, 0, 0, 11, 8599, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue Handler - Between 5-30% Health - Cast \'8599\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21802;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21802);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21802, 0, 0, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 38045, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Elekk Demolisher - Between 20-80% Health - Cast \'38045\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21453;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21453);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21453, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 12550, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue Shaman - On Aggro - Cast \'12550\' (No Repeat)'),
(21453, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 20000, 25000, 11, 32062, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue Shaman - In Combat - Cast \'32062\''),
(21453, 0, 2, 0, 2, 0, 100, 1, 5, 30, 0, 0, 11, 37067, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue Shaman - Between 5-30% Health - Cast \'37067\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21808;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21808);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21808, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 15000, 20000, 11, 11977, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Overseer - In Combat - Cast \'11977\''),
(21808, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 32736, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Overseer - Between 20-80% Health - Cast \'32736\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21455;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21455);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21455, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 15000, 20000, 11, 6016, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ashtongue Worker - In Combat - Cast \'6016\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 22037;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 22037);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22037, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 10000, 15000, 11, 13444, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Smith Gorlunk - In Combat - Cast \'13444\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 22859;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 22859);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22859, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 13338, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadowhoof Summoner - On Aggro - Cast \'13338\' (No Repeat)'),
(22859, 0, 1, 0, 0, 0, 100, 0, 2500, 4000, 8500, 10000, 11, 38386, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadowhoof Summoner - In Combat - Cast \'38386\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21166;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21166);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21166, 0, 0, 0, 0, 0, 100, 0, 2500, 4000, 8500, 10000, 11, 17287, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Dreadlord - In Combat - Cast \'17287\''),
(21166, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 12098, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Dreadlord - Between 20-80% Health - Cast \'12098\' (No Repeat)'),
(21166, 0, 2, 0, 2, 0, 100, 1, 5, 30, 0, 0, 11, 13704, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Dreadlord - Between 5-30% Health - Cast \'13704\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21908;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21908);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21908, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 15000, 20000, 11, 31553, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Spellbound Terrorguard - In Combat - Cast \'31553\''),
(21908, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 37488, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Spellbound Terrorguard - Between 20-80% Health - Cast \'37488\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21178;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21178);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21178, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 38010, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Varedis - On Aggro - Cast \'38010\' (No Repeat)'), 
(21178, 0, 1, 0, 0, 0, 100, 0, 5000, 15000, 25000, 35000, 11, 39262, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Varedis - In Combat - Cast \'39262\''), 
(21178, 0, 2, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 37683, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Varedis - Between 20-80% Health - Cast \'37683\' (No Repeat)'), 
(21178, 0, 3, 0, 0, 0, 100, 0, 25000, 35000, 55000, 75000, 11, 38608, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Varedis - In Combat - Cast \'38608\''),
(21178, 0, 4, 0, 2, 0, 100, 1, 45, 50, 0, 0, 11, 36298, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Varedis - Between 45-50% Health - Cast \'36298\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21171;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21171);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21171, 0, 0, 0, 0, 0, 100, 0, 5000, 15000, 25000, 35000, 11, 39262, 32, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Alandien - In Combat - Cast \'39262\''),
(21171, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 37683, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alandien - Between 20-80% Health - Cast \'37683\' (No Repeat)'), 
(21171, 0, 2, 0, 2, 0, 100, 1, 45, 50, 0, 0, 11, 36298, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alandien - Between 45-50% Health - Cast \'36298\' (No Repeat)'),
(21171, 0, 3, 0, 0, 0, 100, 0, 25000, 35000, 55000, 75000, 11, 39082, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Alandien - In Combat - Cast \'39082\''); 

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21164;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21164);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21164, 0, 0, 0, 0, 0, 100, 0, 5000, 15000, 25000, 35000, 11, 39262, 32, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Netharel - In Combat - Cast \'39262\''), 
(21164, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 37683, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netharel - Between 20-80% Health - Cast \'37683\' (No Repeat)'),
(21164, 0, 2, 0, 0, 0, 100, 0, 10000, 20000, 30000, 40000, 11, 39135, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Netharel - In Combat - Cast \'39135\''),
(21164, 0, 3, 0, 2, 0, 100, 1, 45, 50, 0, 0, 11, 36298, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Netharel - Between 45-50% Health - Cast \'36298\' (No Repeat)'); 

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21168;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21168);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21168, 0, 0, 0, 0, 0, 100, 0, 5000, 15000, 25000, 35000, 11, 39262, 32, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Theras - In Combat - Cast \'39262\''),
(21168, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 37683, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theras - Between 20-80% Health - Cast \'37683\' (No Repeat)'),
(21168, 0, 2, 0, 0, 0, 100, 0, 10000, 20000, 30000, 40000, 11, 35871, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Theras - In Combat - Cast \'35871\''),
(21168, 0, 3, 0, 2, 0, 100, 1, 45, 50, 0, 0, 11, 36298, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theras - Between 45-50% Health - Cast \'36298\' (No Repeat)'),
(21168, 0, 4, 0, 0, 0, 100, 0, 25000, 35000, 55000, 75000, 11, 31534, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theras - In Combat - Cast \'31534\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21505;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21505);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21505, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 10000, 15000, 11, 13901, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sunfury Summoner - In Combat - Cast \'13901\''),
(21505, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 14514, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sunfury Summoner - Between 20-80% Health - Cast \'14514\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21179;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21179);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21179, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 32720, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demon Hunter Supplicant - On Aggro - Cast \'32720\' (No Repeat)'),
(21179, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 37683, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demon Hunter Supplicant - Between 20-80% Health - Cast \'37683\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21180;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21180);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21180, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 36051, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Demon Hunter Initiate - On Aggro - Cast \'36051\' (No Repeat)'),
(21180, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 35871, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Demon Hunter Initiate - In Combat - Cast \'35871\''),
(21180, 0, 2, 0, 2, 0, 100, 1, 10, 30, 0, 0, 11, 27565, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Demon Hunter Initiate - Between 10-30% Health - Cast \'27565\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21742;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21742);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21742, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 38008, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sunfury Eradicator - On Aggro - Cast \'38008\' (No Repeat)'),
(21742, 0, 1, 0, 2, 0, 100, 1, 10, 30, 0, 0, 11, 17137, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sunfury Eradicator - Between 10-30% Health - Cast \'17137\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21827;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21827);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21827, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 38051, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Zandras - On Aggro - Cast \'38051\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19744;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19744);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19744, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 32736, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dreadwarden - In Combat - Cast \'32736\''),
(19744, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 11443, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dreadwarden - Between 20-80% Health - Cast \'11443\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19801;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19801);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19801, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 10000, 12500, 11, 36227, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Agonizer - In Combat - Cast \'36227\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21520;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21520);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21520, 0, 0, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 38051, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Jailor - Between 20-80% Health - Cast \'38051\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21478;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21478);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21478, 0, 0, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 33912, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rocknail Ripper - Between 20-80% Health - Cast \'33912\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21901;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21901);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21901, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 20000, 25000, 11, 36659, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Netherskate - In Combat - Cast \'36659\''),
(21901, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 17008, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Netherskate - Between 20-80% Health - Cast \'17008\' (No Repeat)'),
(21901, 0, 2, 0, 2, 0, 100, 1, 10, 30, 0, 0, 11, 35334, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Netherskate - Between 10-30% Health - Cast \'35334\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 23269;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 23269);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23269, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 32732, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Barash the Den Mother - On Aggro - Cast \'32732\' (No Repeat)'),
(23269, 0, 1, 0, 0, 0, 100, 0, 2500, 5000, 20000, 25000, 11, 13443, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Barash the Den Mother - In Combat - Cast \'13443\''),
(23269, 0, 2, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 33810, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Barash the Den Mother - Between 20-80% Health - Cast \'33810\' (No Repeat)'),
(23269, 0, 3, 0, 2, 0, 100, 1, 10, 30, 0, 0, 11, 40636, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Barash the Den Mother - Between 10-30% Health - Cast \'40636\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 23267;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 23267);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23267, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 32732, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arvoar the Rapacious - On Aggro - Cast \'32732\' (No Repeat)'),
(23267, 0, 1, 0, 0, 0, 100, 0, 2500, 5000, 20000, 25000, 11, 13443, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Arvoar the Rapacious - In Combat - Cast \'13443\''),
(23267, 0, 2, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 33810, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arvoar the Rapacious - Between 20-80% Health - Cast \'33810\' (No Repeat)'),
(23267, 0, 3, 0, 2, 0, 100, 1, 10, 30, 0, 0, 11, 40636, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Arvoar the Rapacious - Between 10-30% Health - Cast \'40636\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 23264;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 23264);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23264, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 20000, 25000, 11, 13443, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Overmine Flayer - In Combat - Cast \'13443\''),
(23264, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 33810, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Overmine Flayer - Between 20-80% Health - Cast \'33810\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 22274;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 22274);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22274, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 38859, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Skybreaker - On Aggro - Cast \'38859\' (No Repeat)'),
(22274, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 38861, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dragonmaw Skybreaker - In Combat - Cast \'38861\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21711;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21711);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21711, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 10000, 12500, 11, 9532, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Haalum - In Combat - Cast \'9532\''),
(21711, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 12058, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Haalum - Between 20-80% Health - Cast \'12058\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 22093;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 22093);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22093, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 32736, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Watcher - In Combat - Cast \'32736\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 22011;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 22011);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22011, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 12612, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Corok the Mighty - In Combat - Cast \'12612\''),
(22011, 0, 1, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 15550, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Corok the Mighty - Between 20-80% Health - Cast \'15550\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21979;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21979);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21979, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 10000, 12500, 11, 38094, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Val\'zareq the Conqueror - In Combat - Cast \'38094\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19824;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19824);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19824, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 15000, 20000, 11, 12612, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Son of Corok - In Combat - Cast \'12612\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21639;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21639);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21639, 0, 0, 1, 4, 0, 100, 1, 0, 0, 0, 0, 11, 22120, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Slayer - On Aggro - Cast \'22120\' (No Repeat)'),
(21639, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Illidari Slayer - On Aggro - Set Run Off (No Repeat)'),
(21639, 0, 2, 0, 0, 0, 100, 0, 2500, 5000, 10000, 15000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Slayer - In Combat - Cast \'15496\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21450;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21450);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21450, 0, 0, 0, 2, 0, 100, 1, 20, 80, 0, 0, 11, 38254, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Skethyl Owl - Between 20-80% Health - Cast \'38254\' (No Repeat)'),
(21450, 0, 1, 0, 2, 0, 100, 1, 10, 30, 0, 0, 11, 38021, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Skethyl Owl - Between 10-30% Health - Cast \'38021\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19757;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19757);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19757, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 15000, 20000, 11, 11969, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Infernal Soul - In Combat - Cast \'11969\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21337;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21337);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21337, 0, 0, 0, 1, 0, 100, 1, 1000, 1500, 0, 0, 11, 5916, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Illidari Shadowstalker - Out of Combat - Cast \'5916\' (No Repeat)'),
(21337, 0, 1, 0, 0, 0, 100, 0, 2500, 5000, 10000, 12500, 11, 7159, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Shadowstalker - In Combat - Cast \'7159\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21928;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21928);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21928, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 38166, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lothros - On Aggro - Cast \'38166\' (No Repeat)'),
(21928, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 20000, 25000, 11, 38167, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lothros - In Combat - Cast \'38167\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19800;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19800);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19800, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 10000, 15000, 11, 15968, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Painlasher - In Combat - Cast \'15968\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19799;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19799);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19799, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 38166, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Illidari Dreadbringer - On Aggro - Cast \'38166\' (No Repeat)'),
(19799, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 20000, 25000, 11, 38167, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Dreadbringer - In Combat - Cast \'38167\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21656;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21656);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21656, 0, 0, 0, 0, 0, 100, 0, 2500, 5000, 15000, 20000, 11, 38048, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Satyr - In Combat - Cast \'38048\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19802;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 19802);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19802, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 22120, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Shocktrooper - On Aggro - Cast \'22120\' (No Repeat)'),
(19802, 0, 1, 0, 0, 0, 100, 0, 2500, 5000, 10000, 15000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Illidari Shocktrooper - In Combat - Cast \'15496\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21408;
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21408);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21408, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 37941, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Felfire Diemetradon - On Aggro - Cast \'37941\' (No Repeat)'),
(21408, 0, 1, 0, 0, 0, 100, 0, 2500, 5000, 10000, 12500, 11, 36247, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Felfire Diemetradon - In Combat - Cast \'36247\'');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
