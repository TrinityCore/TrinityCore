UPDATE `spell_script_names` SET `ScriptName`='spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59576' WHERE `spell_id` = 59576;
UPDATE `spell_script_names` SET `ScriptName`='spell_q12690_burst_at_the_seams_52510' WHERE `spell_id` = 52510;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_q13264_q13276_q13288_q13289_bloated_abom_feign_death', 'spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59579', 'spell_q13264_q13276_q13288_q13289_area_restrict_abom', 'spell_q13264_q13276_q13288_q13289_assign_credit_to_master');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52593, 'spell_q13264_q13276_q13288_q13289_bloated_abom_feign_death'),
(59579, 'spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59579'),
(76245, 'spell_q13264_q13276_q13288_q13289_area_restrict_abom'),
(59590, 'spell_q13264_q13276_q13288_q13289_assign_credit_to_master'),
(60039, 'spell_q13264_q13276_q13288_q13289_assign_credit_to_master'),
(60041, 'spell_q13264_q13276_q13288_q13289_assign_credit_to_master');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (31692);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (31692) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31692,0,0,0, 54,0,100,0,0,0,0,0, 11,76244,2,0,0,0,0, 1,0,0,0,0,0,0,0, 'Reanimated Abomination - On Summoned - Cast "Reanimated Abomination Script"');

DELETE FROM `conditions` WHERE `SourceEntry` IN (59576,59579) AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 59576, 0, 0, 31, 0, 3, 31142, 0, 0, 0, 0, '', 'Spell "Burst at the Seams" targets Icy Ghoul'),
(13, 2, 59576, 0, 1, 31, 0, 3, 31147, 0, 0, 0, 0, '', 'Spell "Burst at the Seams" targets Vicious Geist'),
(13, 2, 59576, 0, 2, 31, 0, 3, 31205, 0, 0, 0, 0, '', 'Spell "Burst at the Seams" targets Risen Alliance Soldier'),
(13, 2, 59576, 0, 3, 31, 0, 4,     0, 0, 0, 0, 0, '', 'Spell "Burst at the Seams" targets Players'),
(13, 1, 59579, 0, 0, 31, 0, 3, 31142, 0, 0, 0, 0, '', 'Spell "Burst at the Seams" targets Icy Ghoul'),
(13, 1, 59579, 0, 1, 31, 0, 3, 31147, 0, 0, 0, 0, '', 'Spell "Burst at the Seams" targets Vicious Geist'),
(13, 1, 59579, 0, 2, 31, 0, 3, 31205, 0, 0, 0, 0, '', 'Spell "Burst at the Seams" targets Risen Alliance Soldier');

