DELETE FROM `spell_areatrigger` WHERE `SpellMiscId`=5420 AND `AreaTriggerId`=10133;
INSERT INTO `spell_areatrigger` (`SpellMiscId`,`AreaTriggerId`,`MoveCurveId`,`ScaleCurveId`,`MorphCurveId`,`FacingCurveId`,`DecalPropertiesId`,`TimeToTarget`,`TimeToTargetScale`,`VerifiedBuild`) VALUES
(5420,10133,0,0,0,0,0,0,7177,23420); -- SpellId : 5740

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warl_rain_of_fire';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(5740,'spell_warl_rain_of_fire');
