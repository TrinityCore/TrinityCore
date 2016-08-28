-- 
SET @ENTRY_THE_LICH_KING := 25462;
SET @QUEST_IN_SERVICE_OF_THE_LICH_KING := 12593;

-- The Lich King Timed Actionlist
DELETE FROM `smart_scripts` WHERE (source_type = 9 AND entryorguid = @ENTRY_THE_LICH_KING * 100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY_THE_LICH_KING * 100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 14970, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Script - Play Sound 14970'),
(@ENTRY_THE_LICH_KING * 100, 9, 1, 0, 0, 0, 100, 0, 21000, 21000, 0, 0, 4, 14971, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Script - Play Sound 14971'),
(@ENTRY_THE_LICH_KING * 100, 9, 2, 0, 0, 0, 100, 0, 26000, 26000, 0, 0, 4, 14972, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Script - Play Sound 14972');

-- The Lich King Timed Actionlist Trigger
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = @ENTRY_THE_LICH_KING);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY_THE_LICH_KING, 0, 0, 0, 19, 0, 100, 0, @QUEST_IN_SERVICE_OF_THE_LICH_KING, 0, 0, 0, 80, 2546200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Lich King - On Quest \'In service of The Lich King Taken\' - Run Script');

-- 'In service of The Lich King' quest details
DELETE FROM `quest_details` WHERE `ID` = @QUEST_IN_SERVICE_OF_THE_LICH_KING;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `EmoteDelay1`, `VerifiedBuild`) VALUES
(@QUEST_IN_SERVICE_OF_THE_LICH_KING, 396, 397, 396, 396, 500, 1000, 1000, 1000, 20886);
