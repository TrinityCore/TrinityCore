-- The Missing Diplomat, id 1265

DELETE FROM `areatrigger_involvedrelation` WHERE `id` in (302,1667);
INSERT INTO `areatrigger_involvedrelation` VALUES (1667,1265);

DELETE FROM `areatrigger_scripts` WHERE `entry` = 302;
INSERT INTO `areatrigger_scripts` VALUES (302,'at_sentry_point');

DELETE FROM `creature_text` WHERE `CreatureID` = 4967 AND `GroupID` = 0 and `ID` = 0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4967, 0, 0, 'Go with grace, and may the Lady\'s magic protect you.', 12, 0, 100, 0, 0, 0, 1751, 0, "Archmage Tervosh - On Quest 'The Missing Diplomat' Finished");

DELETE FROM `smart_scripts` WHERE entryorguid = 4967 AND id in (2,3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4967, 0, 2, 3, 20, 0, 100, 0, 1265, 0, 0, 0, 11, 7120, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Archmage Tervosh - On Quest 'The Missing Diplomat' Finished - Cast Proudmoore's Defense"),
(4967, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Archmage Tervosh - On Quest 'The Missing Diplomat' Finished - Say Line 0");
