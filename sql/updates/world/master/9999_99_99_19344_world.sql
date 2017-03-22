DELETE FROM `areatrigger_template` WHERE `Id`=10133;
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(10133, 0, 0, 8, 8, 0, 0, 0, 0, "", 23420);

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(5420, 10133, 0, 0, 0, 0, 0, 0, 7177, 23420); -- SpellId : 5740

DELETE FROM `spell_script_names` WHERE `spell_id`=5740;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(5740, "spell_warl_rain_of_fire");
