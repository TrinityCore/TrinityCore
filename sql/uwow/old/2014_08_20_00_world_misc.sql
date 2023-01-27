update creature_template set flags_extra = 130 where entry = 27989;

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry = 50493;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 50493, 0, 0, 31, 0, 4, 0, 0, 0, 0, '', NULL);

delete from creature_template_addon where entry = 27989;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(27989, 0, 0, 0, 0, 0, '50314');

delete from spell_linked_spell where spell_trigger in (50315, 50317);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(50315, 50493, 0, 'Disco Ball'),
(50317, 50487, 0, 'Disco Ball');

delete from spell_radius where spell_id = 50493;
INSERT INTO `spell_radius` (`spell_id`, `effectradius0`, `effectradius1`, `effectradius2`, `effectradius3`, `effectradius4`, `comments`) VALUES 
(50493, 8, 0, 0, 0, 0, '5 yard');