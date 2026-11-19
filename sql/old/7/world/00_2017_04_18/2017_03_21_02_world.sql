DELETE FROM `spell_script_names` WHERE `spell_id` = 121536;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(121536, "spell_pri_angelic_feather_trigger");

DELETE FROM `areatrigger_template` WHERE `Id`=3153;
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(3153, 0, 0, 3, 3, 0, 0, 0, 0, "areatrigger_pri_angelic_feather", 23420);

DELETE FROM `spell_areatrigger` WHERE `SpellMiscId`=337;
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(337, 3153, 0, 0, 0, 0, 0, 0, 600000, 23420); -- SpellId : 158624
