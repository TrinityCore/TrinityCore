-- DB update 2021_01_26_00 -> 2021_01_27_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_01_26_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_01_26_00 2021_01_27_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1609769436615146000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1609769436615146000');
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (3892, 3894);
DELETE FROM `creature_text` WHERE (`CreatureID` IN (3892, 3894)) AND (`GroupID` BETWEEN 0 AND 13);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3892, 0, 0, '%s drinks the cure brought by $n.', 16, 0, 100, 0, 0, 0, 1336, 0, 'Relara Whitemoon'),
(3892, 1, 0, 'Uh... Father...?  Are you there?  I\'m hungry... can I have some stew?', 12, 7, 100, 0, 0, 0, 1337, 0, 'Relara Whitemoon'),
(3892, 2, 0, '%s stirs from her delirium.', 16, 0, 100, 0, 0, 0, 1441, 0, 'Relara Whitemoon'),
(3892, 3, 0, 'Mmmmh...', 12, 0, 100, 0, 0, 0, 1442, 0, 'Relara Whitemoon'),
(3892, 4, 0, 'Mmh... my eyes are not so heavy now, father.  Can we go out and play?', 12, 7, 100, 0, 0, 0, 1349, 0, 'Relara Whitemoon'),
(3894, 0, 0, 'Here you are, Relara.  Take this...', 12, 7, 100, 0, 0, 0, 1335, 0, 'Pelturas Whitemoon'),
(3894, 1, 0, 'What?', 12, 7, 100, 0, 0, 0, 1338, 0, 'Pelturas Whitemoon'),
(3894, 2, 0, 'You\'re awake??  Your cure must have worked!  Thank you, $n.', 12, 7, 100, 0, 0, 0, 1339, 0, 'Pelturas Whitemoon'),
(3894, 3, 0, '%s places the tear into a bowl of stew.', 16, 0, 100, 0, 0, 0, 1438, 0, 'Pelturas Whitemoon'),
(3894, 4, 0, 'Eat this, my daughter.  It will help you feel better.', 12, 7, 100, 0, 0, 0, 1439, 0, 'Pelturas Whitemoon'),
(3894, 5, 0, 'There you go...', 12, 7, 100, 0, 0, 0, 1440, 0, 'Pelturas Whitemoon'),
(3894, 6, 0, '%s places a poultice on Relara\'s head.', 16, 0, 100, 0, 0, 0, 1443, 0, 'Pelturas Whitemoon'),
(3894, 7, 0, '%s breathes a sigh of relief.', 16, 0, 100, 0, 0, 0, 1444, 0, 'Pelturas Whitemoon'),
(3894, 8, 0, '%s crushes the moonstones into a cup of tea.', 16, 0, 100, 0, 0, 0, 1346, 0, 'Pelturas Whitemoon'),
(3894, 9, 0, 'Here you are, Relara.  Drink this...', 12, 7, 100, 16, 0, 0, 1347, 0, 'Pelturas Whitemoon'),
(3894, 10, 0, 'Relara... you\'re awake?', 12, 7, 100, 0, 0, 0, 1350, 0, 'Pelturas Whitemoon'),
(3894, 11, 0, 'Rest now, my daughter.', 12, 7, 100, 1, 0, 0, 1351, 0, 'Pelturas Whitemoon'),
(3894, 12, 0, '%s looks at $n, and then weeps with joy.', 16, 0, 100, 0, 0, 0, 1352, 0, 'Pelturas Whitemoon'),
(3894, 13, 0, 'Relara is saved, $n.  Thank you.', 12, 7, 100, 18, 0, 0, 1353, 0, 'Pelturas Whitemoon');
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (3892, 3894)) AND (`source_type`= 0);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (389400, 389401, 389402, 389403)) AND (`source_type`= 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3892, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 0, 11, 46765, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Relara Whitemoon - Out Of Combat - Cast Self Visual - Sleep Until Cancelled  (DND)'),
(3894, 0, 0, 1, 20, 0, 100, 0, 1020, 0, 0, 0, 0, 80, 389400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Quest \'Orendil\'s Cure\' Finished - Run Script'),
(3894, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Quest \'Orendil\'s Cure\' Finished - Store Targetlist'),
(3894, 0, 2, 0, 20, 0, 100, 0, 1033, 0, 0, 0, 0, 80, 389401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Quest \'Elune\'s Tear\' Finished - Run Script'),
(3894, 0, 3, 0, 20, 0, 100, 0, 1034, 0, 0, 0, 0, 80, 389402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Quest \'The Ruins of Stardust\' Finished - Run Script'),
(3894, 0, 4, 0, 20, 0, 100, 0, 1035, 0, 0, 0, 0, 80, 389403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Quest \'Fallen Sky Lake\' Finished - Run Script'),
(389400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Remove Npc Flag Questgiver'),
(389400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 3892, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389400, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 0'),
(389400, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 3892, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Send Target'),
(389400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 3892, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Data'),
(389400, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389400, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 3892, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 1 (Relara Whitemoon)'),
(389400, 9, 7, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 1'),
(389400, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 3892, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389400, 9, 9, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 2'),
(389400, 9, 10, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389400, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Play Emote Bow'),
(389400, 9, 12, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389400, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Add Npc Flag Questgiver'),
(389401, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Remove Npc Flag Questgiver'),
(389401, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 3'),
(389401, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Run Off'),
(389401, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 2682.65, -456.624, 109.234, 0, 'Pelturas Whitemoon - On Script - Move to Position'),
(389401, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 3892, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389401, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 4'),
(389401, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 5'),
(389401, 9, 7, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 2682.14, -454.808, 109.233, 0, 'Pelturas Whitemoon - On Script - Move to Position'),
(389401, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 3892, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 2 (Relara Whitemoon)'),
(389401, 9, 9, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389401, 9, 10, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 3892, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 3 (Relara Whitemoon)'),
(389401, 9, 11, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Add Npc Flag Questgiver'),
(389402, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Remove Npc Flag Questgiver'),
(389402, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Run Off'),
(389402, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 2682.65, -456.624, 109.234, 0, 'Pelturas Whitemoon - On Script - Move to Position'),
(389402, 9, 3, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 3892, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389402, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 6'),
(389402, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 2682.14, -454.808, 109.233, 0, 'Pelturas Whitemoon - On Script - Move to Position'),
(389402, 9, 6, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389402, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 7'),
(389402, 9, 8, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Add Npc Flag Questgiver'),
(389403, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 83, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Remove Npc Flag Questgiver'),
(389403, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 8'),
(389403, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 3892, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389403, 9, 3, 0, 0, 0, 100, 0, 500, 500, 0, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 9'),
(389403, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389403, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 3892, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 4 (Relara Whitemoon)'),
(389403, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 10'),
(389403, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 3892, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389403, 9, 8, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 1, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 11'),
(389403, 9, 9, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 12, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 12'),
(389403, 9, 10, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389403, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 13, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Say Line 13'),
(389403, 9, 12, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Play Emote Bow'),
(389403, 9, 13, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Set Orientation'),
(389403, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 82, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Pelturas Whitemoon - On Script - Add Npc Flag Questgiver');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
