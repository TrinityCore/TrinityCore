DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_shift';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1234796, 'spell_dh_shift');

DELETE FROM `jump_charge_params` WHERE `id`=1466;
INSERT INTO `jump_charge_params` (`id`, `speed`, `treatSpeedAsMoveTimeSeconds`, `unlimitedSpeed`, `minHeight`, `maxHeight`, `spellVisualId`, `progressCurveId`, `parabolicCurveId`, `triggerSpellId`) VALUES
(1466, 0.1, 1, 1, 0.5, NULL, 164063, 88051, 88052, NULL);
