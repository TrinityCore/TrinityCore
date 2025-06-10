--
DELETE FROM `spell_scripts` WHERE `id` IN (55770,36153);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_cast_caster_to_target';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(55770, 'spell_gen_cast_caster_to_target'),
(36153, 'spell_gen_cast_caster_to_target');

DELETE FROM `spell_scripts` WHERE `id` IN (44876,48724,48726,48728,48730,54640);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_cast_target_to_target';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(44876, 'spell_gen_cast_target_to_target'),
(48724, 'spell_gen_cast_target_to_target'),
(48726, 'spell_gen_cast_target_to_target'),
(48728, 'spell_gen_cast_target_to_target'),
(48730, 'spell_gen_cast_target_to_target'),
(54640, 'spell_gen_cast_target_to_target');
UPDATE `smart_scripts` SET `action_type` = 11, `action_param2` = 2 WHERE `entryorguid` IN (27234,27235,27236,27237) AND `id` = 1;
UPDATE `conditions` SET `ConditionTypeOrReference`=32,`ConditionValue1`=144,`ConditionValue2`=0 WHERE `SourceEntry` IN (48724,48726,48728,48730) AND `SourceTypeOrReferenceId` = 13;

DELETE FROM `spell_scripts` WHERE `id` IN (28698);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_dreaming_glory';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(28698, 'spell_gen_dreaming_glory');

DELETE FROM `spell_scripts` WHERE `id` = 55048;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_storm_peaks_free_brunnhildar_prisoner';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(55048, 'spell_storm_peaks_free_brunnhildar_prisoner');

DELETE FROM `spell_scripts` WHERE `id` = 32580;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_bem_wicked_strong_fetish';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32580, 'spell_bem_wicked_strong_fetish');
