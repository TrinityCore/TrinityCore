-- Mobu
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=25475;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25475 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25475, 0, 0, 0, 1, 0, 100, 0, 10000, 30000, 270000, 330000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mobu - Out Of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=25475;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25475, 0, 0, "What am I supposed to do without tools, Gorge!", 12, 1, 100, 18, 0, 0, 24701, 0, "Mobu"),
(25475, 0, 1, "Can't fix somethin' as complicated as a tank without the proper equipment, buddy!", 12, 1, 100, 1, 0, 0, 24702, 0, "Mobu"),
(25475, 0, 2, "Have you heard anything from Warsong? We gonna be gettin' some supplies soon?", 12, 1, 100, 0, 0, 0, 24703, 0, "Mobu"),
(25475, 0, 3, "I wanna go home... Take off this uniform and leave the Horde!", 12, 1, 100, 0, 0, 0, 24704, 0, "Mobu");
