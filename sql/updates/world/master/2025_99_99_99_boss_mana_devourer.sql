UPDATE `creature_template` SET `ScriptName`='boss_mana_devourer' WHERE `entry`=114252; -- Mana Devourer

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mana_devourer_coalesce_power', 'spell_mana_devourer_energize', 'spell_mana_devourer_energy_discharge', 'spell_mana_devourer_energy_void');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(227297, 'spell_mana_devourer_coalesce_power'),
(227451, 'spell_mana_devourer_energize'),
(227457, 'spell_mana_devourer_energy_discharge'),
(227524, 'spell_mana_devourer_energy_void');

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (8791,8754));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(8791, 0, 12858, 0, 2, 0, 2294, 0, 0, -1, 0, 85, NULL, 120000, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 'at_mana_devourer_energy_void', 61967), -- Spell: 227523 (Energy Void)
(8754, 0, 12831, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 14.09541225433349609, 0, 3, 3, 0, 0, 0, 0, 0, 0, 'at_mana_devourer_loose_mana', 61967); -- Spell: 227296 (Loose Mana)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (12858,12831));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(12858, 0, 0, 61967),
(12831, 0, 0, 61967);

DELETE FROM `spell_target_position` WHERE `ID` = 231499;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(231499, 0, 0, 1651, 4151.8818359375, -2030.8836669921875, 730.5565185546875, 61967); -- Spell: 231499 (Teleport)
