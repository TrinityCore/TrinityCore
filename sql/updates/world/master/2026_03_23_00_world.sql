DELETE FROM `spell_script_names` WHERE `spell_id` IN (196884, 215802);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(196884, 'spell_sha_feral_lunge'),
(215802, 'spell_sha_feral_lunge_damage');

DELETE FROM `jump_charge_params` WHERE `id` = 1211;
INSERT INTO `jump_charge_params` (`id`, `speed`, `treatSpeedAsMoveTimeSeconds`, `unlimitedSpeed`, `minHeight`, `maxHeight`, `spellVisualId`, `progressCurveId`, `parabolicCurveId`, `triggerSpellId`) VALUES
(1211, 42, 0, 0, 2, NULL, NULL, NULL, 79789, 215802);
