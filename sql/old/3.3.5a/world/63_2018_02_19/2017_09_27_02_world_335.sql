-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6514;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6514 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6514, 0, 0, 1, 2, 0, 100, 1, 0, 25, 0, 0, 39, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Un'Goro Gorilla - Between 0-25% Health - Call For Help (No Repeat)"),
(6514, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Un'Goro Gorilla - Between 0-25% Health - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=6514;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6514, 0, 0, "%s pounds his chest, calling for help!", 16, 0, 100, 0, 0, 0, 4837, 0, "Un'Goro Gorilla");
UPDATE `smart_scripts` SET `event_param2`=50, `comment`="Un'Goro Stomper - Between 0-50% Health - Cast 'Enrage' (No Repeat)" WHERE `entryorguid`=6513 AND `id`=0;
UPDATE `smart_scripts` SET `comment`="Un'Goro Stomper - Between 0-50% Health - Say Line 0" WHERE `entryorguid`=6513 AND `id`=1;
