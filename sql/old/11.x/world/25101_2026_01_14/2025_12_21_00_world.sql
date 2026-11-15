DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_ultimate_penitence', 'spell_pri_ultimate_penitence_channel', 'spell_pri_ultimate_penitence_jump');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(421453, 'spell_pri_ultimate_penitence'),
(421434, 'spell_pri_ultimate_penitence_channel'),
(432154, 'spell_pri_ultimate_penitence_jump');

DELETE FROM `jump_charge_params` WHERE `id`=852;
INSERT INTO `jump_charge_params` (`id`,`speed`,`treatSpeedAsMoveTimeSeconds`,`progressCurveId`,`parabolicCurveId`) VALUES
(852, 0.65, 1, 68736, 69091);

DELETE FROM `creature_immunities` WHERE `ID`=2408;
INSERT INTO `creature_immunities` (`ID`,`MechanicsMask`,`Effects`,`Auras`,`Comment`) VALUES
(2408,0x459676E6,'98,124,144,145','','Immune to CC+knockback');
