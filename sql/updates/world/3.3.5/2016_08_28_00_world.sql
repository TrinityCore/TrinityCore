DELETE FROM `smart_scripts` WHERE `entryorguid`=23618 AND  `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2361800 AND  `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23618, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - On Reset - Set Phase 1'),
(23618, 0, 1, 2, 10, 1, 100, 0, 1, 10, 30000, 30000, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - Within 1-10 Range Out of Combat LoS (Phase 1) - Face Invoker'),
(23618, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - Within 1-10 Range Out of Combat LoS - Set Phase 2'),
(23618, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - Within 1-10 Range Out of Combat LoS - Set Emote State'),
(23618, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 3367, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - Within 1-10 Range Out of Combat LoS - Set Equipment'),
(23618, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - Within 1-10 Range Out of Combat LoS - Say Line 0'),
(23618, 0, 6, 7, 1, 2, 100, 0, 10000, 10000, 10000, 10000, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.9773844, 'Ahab Wheathoof - OOC (Phase 2) - Set Orientation'),
(23618, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - OOC (Phase 2) - Set Emote State'),
(23618, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2028, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - OOC (Phase 2) - Set Equipment'),
(23618, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - OOC (Phase 2) - Set Phase 1'),
(23618, 0, 10, 0, 1, 1, 100, 0, 60000, 90000, 60000, 90000, 80, 2361800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - OOC (Phase 1) - Run Script'),
(23618, 0, 11, 12, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - On Spawn - Set Active'),
(23618, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2028, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - On Spawn - Set Equipment'),
(2361800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.9773844, 'Ahab Wheathoof - Script - Set Orientation'),
(2361800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2028, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - Script - Equip Itwm'),
(2361800, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - Script - Set Emote State'),
(2361800, 9, 3, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - Script - Set Emote State'),
(2361800, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2028, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ahab Wheathoof - Script - Set Emote State');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=23618;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 2, 23618, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Ahab Wheathoof - Only run SAI if invoker is player');
