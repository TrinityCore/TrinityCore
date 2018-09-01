UPDATE `spell_script_names` SET `ScriptName`="spell_q13264_q13276_q13288_q13289_burst_at_the_seams" WHERE `spell_id` = 59576;

DELETE FROM `conditions` WHERE `SourceEntry` = 59576 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 59576, 0, 0, 31, 0, 3, 31142, 0, 0, 0, 0, "", "Spell 'Burst at the Seams' targets Icy Ghoul"),
(13, 2, 59576, 0, 1, 31, 0, 3, 31147, 0, 0, 0, 0, "", "Spell 'Burst at the Seams' targets Vicious Geist"),
(13, 2, 59576, 0, 2, 31, 0, 3, 31205, 0, 0, 0, 0, "", "Spell 'Burst at the Seams' targets Risen Alliance Soldier");
