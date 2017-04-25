DELETE FROM `smart_scripts` WHERE `entryorguid`=2964700 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(29647,29884) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29647, 0, 0, 1, 62, 0, 100, 0, 9852, 2, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gymer - On Gossip Option 2 Selected - Close Gossip'), -- 21:50:33.764
(29647, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 55568, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gymer - On Gossip Option 2 Selected - Cast Summon Gymer (Force)'), -- 21:50:33.967
(29647, 0, 4, 0, 1, 0, 100, 0, 10000, 20000, 30000, 40000, 1, 1, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gymer - Out of Combat - Say Line 1'),
(29647, 0, 5, 0, 20, 0, 100, 0, 12916, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gymer - On Quest reward - Say Line 7'),
(29884, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 86, 55430, 2, 7, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gymer - On Just Summoned - Cast Gymers Buddy'), -- 21:50:35.090
(29884, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gymer - On Just Summoned - Set Passive'),
(29884, 0, 2, 3, 27, 0, 100, 1, 0, 0, 0, 0, 44, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gymer - On Passenger Boarded - Set Phase 256'),
(29884, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gymer - On Passenger Boarded - Say Line 8 (No Repeat)'),
(29884, 0, 4, 0, 61, 0, 100, 1, 0, 0, 0, 0, 11, 55461, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gymer - On Passenger Boarded - Cast Storms Fury'),
(29884, 0, 5, 6, 28, 0, 100, 1, 0, 0, 0, 0, 44, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gymer - On Passenger Removed - Set Phase 1'),
(29884, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gymer - On Passenger Removed - Say Line 10'),
(29884, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gymer - On Passenger Removed - Despawn after 5 seconds');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=29884;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 6, 29884, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Gymer only despawns if player leaves vehicle (not if mob thrown)');
