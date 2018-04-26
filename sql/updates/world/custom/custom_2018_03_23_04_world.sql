UPDATE `creature_template` SET `InhabitType`= 1 WHERE `entry` IN (43873, 43874);
UPDATE `creature_template` SET `InhabitType`= 4, `flags_extra`= 131 WHERE `entry` IN
(45572, 45504, 47085, 45981);

UPDATE `creature_text` SET `Sound`= 0 WHERE `CreatureID`= 43875 AND `GroupID`= 2;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_supremacy_of_the_storm_visual',
'spell_static_cling');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(86715, 'spell_supremacy_of_the_storm_visual'),
(87618, 'spell_static_cling');

DELETE FROM `conditions` WHERE `SourceEntry`= 96260 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO conditions (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 96260, 0, 0, 31, 0, 3, 43875, 0, 0, 0, '', 'Summon Skyfall Star - Target Asaad');
