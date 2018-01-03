UPDATE `areatrigger_template` SET `Data0`=3, `Data1`=3, `Data2`=4, `Data3`=4, `VerifiedBuild`=25549 WHERE `Id`=6094;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25549 WHERE `Id`=11513;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25549 WHERE `Id`=9805;
UPDATE `areatrigger_template` SET `Flags`=24, `VerifiedBuild`=25549 WHERE `Id`=6095;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25549 WHERE `Id`=2947;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25549 WHERE `Id`=6966;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25549 WHERE `Id`=9170;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25549 WHERE `Id`=3841;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25549 WHERE `Id`=5972;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25549 WHERE `Id`=10194;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25549 WHERE `Id`=10466;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=25549 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25549 WHERE `Id`=3678;
UPDATE `areatrigger_template` SET `Data0`=4.516983, `Data1`=4.516983, `VerifiedBuild`=25549 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=2.5, `Data2`=3, `Data3`=2.5, `Data4`=2.5, `Data5`=3, `VerifiedBuild`=25549 WHERE `Id`=6197;
UPDATE `areatrigger_template` SET `Data0`=3, `Data1`=3, `Data2`=4, `Data3`=4, `Data4`=1, `Data5`=1, `VerifiedBuild`=25549 WHERE `Id`=9181;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=5084 AND `AreaTriggerId`=9805) OR (`SpellMiscId`=2392 AND `AreaTriggerId`=6966);
DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170) OR (`AreaTriggerId`=10194) OR (`SpellMiscId`=510 AND `AreaTriggerId`=3678) OR (`SpellMiscId`=4435 AND `AreaTriggerId`=9181);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(5084, 9805, 0, 0, 0, 0, 0, 0, 15000, 25549), -- SpellId : 194278
(2392, 6966, 0, 0, 0, 0, 0, 0, 60000, 25549), -- SpellId : 162496
(4424, 9170, 0, 0, 0, 0, 0, 0, 60000, 25549), -- SpellId : 187651
(5487, 10194, 1666, 1659, 0, 0, 0, 1381, 2250, 25549), -- SpellId : 198929
(510, 3678, 0, 0, 0, 0, 0, 0, 20000, 25549), -- SpellId : 132950
(4435, 9181, 0, 0, 0, 0, 0, 0, 60000, 25549); -- SpellId : 187699

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25549 WHERE (`SpellMiscId`=1613 AND `AreaTriggerId`=6094); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=25549 WHERE (`SpellMiscId`=7044 AND `AreaTriggerId`=11513); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2003, `TimeToTargetScale`=0, `VerifiedBuild`=25549 WHERE (`SpellMiscId`=1612 AND `AreaTriggerId`=6095); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25549 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25549 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25549 WHERE (`SpellMiscId`=1524 AND `AreaTriggerId`=5972); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2256, `TimeToTargetScale`=0, `VerifiedBuild`=25549 WHERE (`SpellMiscId`=5754 AND `AreaTriggerId`=10466); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7135, `VerifiedBuild`=25549 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25549 WHERE (`SpellMiscId`=8284 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25549 WHERE (`SpellMiscId`=6026 AND `AreaTriggerId`=10713); -- SpellId : 0
