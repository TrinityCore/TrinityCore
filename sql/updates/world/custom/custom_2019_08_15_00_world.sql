DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_vp_catch_fall';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(89522, 'spell_vp_catch_fall');

DELETE FROM `spell_target_position` WHERE `ID`= 89526;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(89526, 0, 657, -361.0174, -6.359375, 632.7807, 0.0);
