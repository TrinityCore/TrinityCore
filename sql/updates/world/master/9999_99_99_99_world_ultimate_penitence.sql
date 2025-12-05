DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_ultimate_penitence', 'spell_pri_ultimate_penitence_channel', 'spell_pri_ultimate_penitence_jump');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(421453, 'spell_pri_ultimate_penitence'),
(421434, 'spell_pri_ultimate_penitence_channel'),
(432154, 'spell_pri_ultimate_penitence_jump');

DELETE FROM `jump_charge_params` WHERE `id` = 852;
INSERT INTO `jump_charge_params` (`id`, `speed`, `treatSpeedAsMoveTimeSeconds`, `jumpGravity`, `spellVisualId`, `progressCurveId`, `parabolicCurveId`, `triggerSpellId`) VALUES
(852, 7.69, 0, 19.2911, NULL, 68736, 69091, NULL);
