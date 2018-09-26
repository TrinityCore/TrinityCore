DELETE FROM `spell_script_names` WHERE `spell_id` = 59576;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (31692);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(31692,0, 0,0, 8,0,100,1, 59576,0,0,0, 41,0,0,0,0,0,0, 1,0,0,0,0,0,0,0, 'despawn');


DELETE FROM `conditions` WHERE `SourceEntry` = 59576 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 59576, 0, 0, 31, 0, 3, 31142, 0, 0, 0, 0, "", "Spell 'Burst at the Seams' targets Icy Ghoul"),
(13, 2, 59576, 0, 1, 31, 0, 3, 31147, 0, 0, 0, 0, "", "Spell 'Burst at the Seams' targets Vicious Geist"),
(13, 2, 59576, 0, 2, 31, 0, 3, 31205, 0, 0, 0, 0, "", "Spell 'Burst at the Seams' targets Risen Alliance Soldier"),
(13, 2, 59576, 0, 3, 31, 0, 4,     0, 0, 0, 0, 0, "", "Spell 'Burst at the Seams' targets Players");

