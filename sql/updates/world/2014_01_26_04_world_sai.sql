-- [11796] Emergency Protocol: Section 8.2, Paragraph D
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(25845,25846,25847);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25845,25846,25847);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25845, 0, 0, 0, 8,  0, 100, 0, 46171, 0, 0, 0, 33, 25845   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Northwest Crash - On Spellhit - Kill Credit'),
(25846, 0, 0, 0, 8,  0, 100, 0, 46171, 0, 0, 0, 33, 25846   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'South Crash - On Spellhit - Kill Credit'),
(25847, 0, 0, 0, 8,  0, 100, 0, 46171, 0, 0, 0, 33, 25847   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'East Crash - On Spellhit - Kill Credit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13  AND `SourceEntry`=46171;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,46171,0,0,31,0,3,25845,0,0,0,0,'','Scuttle Wrecked Flying Machine targets Northwest Crash'),
(13,1,46171,0,1,31,0,3,25846,0,0,0,0,'','Scuttle Wrecked Flying Machine targets South Crash'),
(13,1,46171,0,2,31,0,3,25847,0,0,0,0,'','Scuttle Wrecked Flying Machine Flare targets East Crash');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=46171;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0, 46171, 64, '', '', 'Ignore LOS on Scuttle Wrecked Flying Machine');
