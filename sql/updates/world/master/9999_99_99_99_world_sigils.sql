-- 
UPDATE `areatrigger_template` SET `ScriptName`='areatrigger_dh_sigil_of_silence', `VerifiedBuild`=40120 WHERE `Id`=10714;
UPDATE `areatrigger_template` SET `ScriptName`='areatrigger_dh_sigil_of_misery', `VerifiedBuild`=40120 WHERE `Id`=11023;
UPDATE `areatrigger_template` SET `ScriptName`='areatrigger_dh_sigil_of_flame', `VerifiedBuild`=40120 WHERE `Id`=10727;
UPDATE `areatrigger_template` SET `ScriptName`='areatrigger_dh_sigil_of_chains', `VerifiedBuild`=40120 WHERE `Id`=10718;

DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (6027,6351,6039,6031);
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `VerifiedBuild`) VALUES
(6027, 10714, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 8, 8, 0, 0, 0, 0, 40120), -- SpellId : 202137 Sigil of Silence
(6351, 11023, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 8, 8, 0, 0, 0, 0, 40120), -- SpellId : 207684 Sigil of Misery
(6039, 10727, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 8, 8, 0, 0, 0, 0, 40120), -- SpellId : 204596 Sigil of Flame
(6031, 10718, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 8, 8, 0, 0, 0, 0, 40120); -- SpellId : 202138 Sigil of Chains

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_sigil_of_chains';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(204834, 'spell_dh_sigil_of_chains');
