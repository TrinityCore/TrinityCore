DELETE FROM `areatrigger_template` WHERE `Id` IN (2947, 16718, 9228, 18327, 16712, 23951, 9181, 9170);
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(2947, 1, 0, 0, 8, 8, 0, 0, 0, 0, 38134),
(16718, 1, 0, 4, 4, 4, 0, 0, 0, 0, 38134),
(9228, 1, 0, 0, 8, 8, 0, 0, 0, 0, 38134),
(18327, 1, 0, 0, 4, 4, 0, 0, 0, 0, 38134),
(16712, 1, 0, 2, 5, 5, 0, 0, 0, 0, 38134),
(23951, 1, 0, 4, 40, 40, 0, 0, 0, 0, 38134),
(9181, 1, 4, 0, 3, 3, 4, 4, 1, 1, 38134),
(9170, 1, 4, 0, 3, 3, 4, 4, 1, 1, 38134);

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=12007 AND `AreaTriggerId`=16718) OR (`SpellMiscId`=13858 AND `AreaTriggerId`=18327) OR (`SpellMiscId`=12001 AND `AreaTriggerId`=16712) OR (`SpellMiscId`=20004 AND `AreaTriggerId`=23951);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(12007, 16718, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 38134), -- SpellId : 257314
(13858, 18327, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 38134), -- SpellId : 274386
(12001, 16712, 0, 5085, 0, 0, 0, 0, 210, 0, 30000, 38134), -- SpellId : 257273
(20004, 23951, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- SpellId : 325270

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12018 AND `AreaTriggerId`=16728); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12004 AND `AreaTriggerId`=16715); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5529, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5395, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5339, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5795, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5396, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5529, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=4813, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5667, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5381, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5395, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=4765, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5623, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5868, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=4736, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=6052, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=4511, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12070 AND `AreaTriggerId`=16776); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=13632 AND `AreaTriggerId`=18148); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=13632 AND `AreaTriggerId`=18148); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=11912 AND `AreaTriggerId`=16608); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=11912 AND `AreaTriggerId`=16608); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=11912 AND `AreaTriggerId`=16608); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=11912 AND `AreaTriggerId`=16608); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=11912 AND `AreaTriggerId`=16608); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=11912 AND `AreaTriggerId`=16608); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=11912 AND `AreaTriggerId`=16608); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0


REPLACE INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(9659, 64799, 0, 38134);


DELETE FROM `conversation_line_template` WHERE `Id` IN (14327, 14326, 14325, 14324, 14323, 14322, 14329, 14328, 14470, 14469, 21773, 21772, 21771, 22084, 22083, 22082, 14335, 14517);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(14327, 42994, 0, 1, 0, 38134),
(14326, 32001, 0, 1, 0, 38134),
(14325, 11211, 0, 1, 0, 38134),
(14324, 8197, 0, 0, 0, 38134),
(14323, 3488, 0, 1, 0, 38134),
(14322, 0, 0, 0, 0, 38134),
(14329, 6977, 0, 0, 0, 38134),
(14328, 0, 0, 0, 0, 38134),
(14470, 4018, 0, 0, 0, 38134),
(14469, 0, 0, 0, 0, 38134),
(21773, 8634, 0, 2, 0, 38134),
(21772, 4777, 0, 1, 0, 38134),
(21771, 0, 0, 0, 0, 38134),
(22084, 17634, 1081, 0, 0, 38134),
(22083, 8576, 1081, 0, 0, 38134),
(22082, 0, 1081, 0, 0, 38134),
(14335, 12288, 0, 0, 0, 38134),
(14517, 0, 0, 0, 0, 38134);

DELETE FROM `conversation_template` WHERE `Id` IN (6366, 6364, 6363, 9575, 9659, 6422);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(6366, 14517, 30316, 0, 38134),
(6364, 14328, 24415, 0, 38134),
(6363, 14322, 50346, 0, 38134),
(9575, 21771, 12330, 0, 38134),
(9659, 22082, 33250, 0, 38134),
(6422, 14469, 8004, 0, 38134);


UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=186456; -- Blacksmith Smoke
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=215764; -- Dark Fast Smoke
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=215318; -- Archimonde Fire
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=212969; -- Incense Bundle
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=215036; -- Alliance Banner
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=215031; -- Alliance Banner
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=215844; -- Flagpole
UPDATE `gameobject_template_addon` SET `faction`=84 WHERE `entry`=204100; -- Snake Trap
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=214962; -- Requisitioned Firework Launcher
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=212325; -- Doodad_hz_camp_fire_001
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=215033; -- Alliance Banner
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=215037; -- Alliance Banner
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=215034; -- Alliance Banner
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=215032; -- Alliance Banner
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=215035; -- Alliance Banner
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=215038; -- Alliance Banner
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=215845; -- Alliance Flag
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=210804; -- Portal to Orgrimmar
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=214988; -- Mailbox
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=216302; -- Stove
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=212184; -- Ancient Statue Shoulder
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=212186; -- Ancient Statue Head
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=212183; -- Ancient Statue Arm
UPDATE `gameobject_template_addon` SET `faction`=1375 WHERE `entry`=215694; -- Barricade Supports - Burning
UPDATE `gameobject_template_addon` SET `WorldEffectID`=1149 WHERE `entry`=215695; -- Barrel of Honeybrew
UPDATE `gameobject_template_addon` SET `faction`=1375 WHERE `entry`=215692; -- Honeybrew Barrel Broken
UPDATE `gameobject_template_addon` SET `flags`=36 WHERE `entry`=212181; -- Ancient Statue
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=215693; -- Barricade Supports - Burning
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=215859; -- Sha GroundPatch Small Tendrils
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=215563; -- Jade Forest Horde Ship Cosmetic
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=215422; -- Jade Forest Alliance Ship Cosmetic
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=215423; -- Jade Forest Alliance Ship Cosmetic
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=215860; -- Sha GroundPatch Med Tendrils
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=215564; -- Jade Forest Horde Ship Cosmetic
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=215562; -- Jade Forest Horde Ship Cosmetic
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=209353; -- Rain Poppy
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=215688; -- Horde Supplies
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=215685; -- Horde Supplies
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=209349; -- Green Tea Leaf
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=212182; -- Ancient Statue Torso
UPDATE `gameobject_template_addon` SET `faction`=94, `flags`=278528 WHERE `entry`=209311; -- Ghost Iron Deposit
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=215686; -- Horde Supplies
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=215687; -- Barricade Supports
UPDATE `gameobject_template_addon` SET `faction`=1735, `flags`=32 WHERE `entry`=215766; -- Gunship Portal
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=215684; -- Horde Supplies
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=215767; -- Horde Gunship Portal Effects
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=215683; -- Horde Barricade

DELETE FROM `scene_template` WHERE (`SceneId`=101 AND `ScriptPackageID`=254) OR (`SceneId`=96 AND `ScriptPackageID`=251) OR (`SceneId`=87 AND `ScriptPackageID`=228);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(101, 0, 254, 0),
(96, 0, 251, 0),
(87, 11, 228, 0);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (31776 /*-Unknown-*/, 31775 /*-Unknown-*/, 31778 /*-Unknown-*/, 31777 /*-Unknown-*/, 29804 /*-Unknown-*/, 29765 /*-Unknown-*/, 29743 /*-Unknown-*/, 31774 /*-Unknown-*/, 29694 /*-Unknown-*/, 31773 /*-Unknown-*/, 31978 /*-Unknown-*/, 31771 /*-Unknown-*/, 31770 /*-Unknown-*/, 31769 /*-Unknown-*/, 31768 /*-Unknown-*/, 31767 /*-Unknown-*/, 31766 /*-Unknown-*/, 31765 /*-Unknown-*/, 29690 /*-Unknown-*/, 31853 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(31776, 66, 0, 0, 0, 0, 0, 0, 0, 'Blood and thunder, $n. Blood and thunder.', 38134), -- -Unknown-
(31775, 1, 0, 0, 0, 0, 0, 0, 0, 'The best thing about killing Alliance in Pandaria? It\'ll be months before they get any reinforcements.$b$bThis land will belong to the Horde, $c. We\'re nearly finished.', 38134), -- -Unknown-
(31778, 1, 1, 0, 0, 0, 0, 0, 0, 'Although I can\'t understand why you chose to bring your war to our land, I can clearly see which side is more virtuous.$b$bThank you for your aid, $r.', 38134), -- -Unknown-
(31777, 11, 0, 0, 0, 0, 0, 0, 0, 'I hope those ding-dongs enjoyed the party you threw for them!', 38134), -- -Unknown-
(29804, 6, 15, 0, 0, 0, 0, 0, 0, 'Zin\'jun is lost?$b$bThis is a dark day indeed, $gbrother:sister;. These vermin will pay!', 38134), -- -Unknown-
(29765, 0, 0, 0, 0, 0, 0, 0, 0, '<Zin\'Jun sobs...you think.>$b$bDey done killed Snuff...$b$bWhat\'d \'ol Snuff ever do ta dem? ', 38134), -- -Unknown-
(29743, 0, 0, 0, 0, 0, 0, 0, 0, 'As you look over your sketch, you can\'t help but hope that these creatures don\'t really exist.', 38134), -- -Unknown-
(31774, 5, 0, 0, 0, 0, 0, 0, 0, '<Zin\'Jun is grievously wounded, but senses that you\'re friendly.>$b$bMonkey-tings! Everywhere dere be dese monkey-tings!', 38134), -- -Unknown-
(29694, 6, 274, 1, 0, 0, 0, 0, 0, 'These are the only survivors, $n?$b$bSo be it. We will play the hand fate has dealt us.$b$b<Gorrok lifts his head up high.>$b$bNumbers be damned. This is where heroes are made.', 38134), -- -Unknown-
(31773, 1, 0, 0, 0, 0, 0, 0, 0, 'Ah, so your conflict at the ruins is beginning to pollute the local wildlife? This is very troubling - I have never seen a reaction so intense.$b$bThank you for protecting the village, but it is a tragedy that those poor animals had to die.', 38134), -- -Unknown-
(31978, 1, 0, 0, 0, 0, 0, 0, 0, 'Well, it\'s not as much as I would have hoped, but it will have to do. I guess there is no sense in cryin\' over spilled brew.', 38134), -- -Unknown-
(31771, 0, 0, 0, 0, 0, 0, 0, 0, 'I am glad you took responsibility for your actions. Left unchecked, negative emotions can quickly overwhelm an individual here, just as they started to overwhelm the one you call \"Nazgrim.\"', 38134), -- -Unknown-
(31770, 5, 274, 1, 0, 0, 0, 0, 0, 'Your fighting has brought about much destruction for our tiny village!$b$bWe have no interest in your war, but we will not turn your injured away.', 38134), -- -Unknown-
(31769, 1, 1, 0, 0, 0, 500, 0, 0, 'An air base - they had a hidden airbase here this entire time! Had I known I would\'ve kept more men on the guns, I would\'ve - Uaaghh -$b$b<The color drains from Nazgrim\'s face, and his body begins to exude a mysterious dark energy.>', 38134), -- -Unknown-
(31768, 0, 0, 0, 0, 0, 0, 0, 0, 'Haha! Good work, $n.$b$bLeave \'em nothing!', 38134), -- -Unknown-
(31767, 0, 0, 0, 0, 0, 0, 0, 0, 'Good work, $c! We have them on their heels!', 38134), -- -Unknown-
(31766, 1, 0, 0, 0, 0, 0, 0, 0, 'There you are!$b$bI was starting to worry we\'d have to charge in and have all the fun without you.', 38134), -- -Unknown-
(31765, 0, 0, 0, 0, 0, 0, 0, 0, 'Superior Horde firepower at its finest!$B$B...and you did okay too I guess.', 38134), -- -Unknown-
(29690, 5, 0, 0, 0, 0, 0, 0, 0, '$n!?$b$bThey told me you were dead...$b$bI\'m glad to see it wasn\'t true. There\'s Alliance to kill!', 38134), -- -Unknown-
(31853, 0, 0, 0, 0, 0, 0, 0, 0, 'Welcome aboard Hellscream\'s Fist, $n!$b$bThis\'ll be her maiden voyage. Ain\'t she a beauty?', 38134); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=31778 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=31778 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=31778 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29743 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=29743 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=29743 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29743 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29743 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29765 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=29765 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=29765 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=29765 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29765 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29765 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=31767 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=31767 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=31767 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(31778, 0, 2, 32, 0, 0, 870, 371, 0, 0, 0, 0, 0, 713003, 0, 38134), -- -Unknown-
(31778, 0, 1, 0, 269036, 65974, 870, 371, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31778, 0, 0, -1, 0, 0, 870, 371, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29743, 0, 4, 32, 0, 0, 870, 371, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29743, 0, 3, 3, 258566, 55392, 870, 371, 0, 1, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29743, 0, 2, 2, 258565, 55388, 870, 371, 0, 1, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29743, 0, 1, 1, 258564, 55383, 870, 371, 0, 1, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29743, 0, 0, 0, 258563, 55379, 870, 371, 0, 1, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29765, 0, 5, 32, 0, 0, 870, 371, 0, 0, 0, 0, 0, 606926, 0, 38134), -- -Unknown-
(29765, 0, 4, 3, 264326, 74163, 870, 371, 0, 1, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29765, 0, 3, 2, 264325, 74162, 870, 371, 0, 1, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29765, 0, 2, 1, 264324, 74161, 870, 371, 0, 1, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29765, 0, 1, 0, 264323, 74160, 870, 371, 0, 1, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29765, 0, 0, -1, 0, 0, 870, 371, 0, 1, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31767, 0, 2, 32, 0, 0, 870, 371, 0, 0, 0, 0, 0, 713964, 0, 38134), -- -Unknown-
(31767, 0, 1, 0, 269102, 66285, 870, 371, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31767, 0, 0, -1, 0, 0, 870, 371, 0, 0, 0, 0, 0, 721252, 0, 38134); -- -Unknown-

DELETE FROM `quest_poi_points` WHERE (`QuestID`=31778 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=31778 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=31778 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=31778 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=31778 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=31778 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=31778 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=31778 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=31778 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=31778 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=31778 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=31778 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=31778 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29743 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=29743 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29743 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29743 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29743 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29765 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=29765 AND `Idx1`=4 AND `Idx2`=8) OR (`QuestID`=29765 AND `Idx1`=4 AND `Idx2`=7) OR (`QuestID`=29765 AND `Idx1`=4 AND `Idx2`=6) OR (`QuestID`=29765 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=29765 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=29765 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=29765 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=29765 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=29765 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=29765 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=29765 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=29765 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=29765 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=29765 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=29765 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=29765 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=29765 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=29765 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29765 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=29765 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=29765 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=29765 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=29765 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=29765 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=29765 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=29765 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=29765 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29765 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=29765 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=29765 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=29765 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=29765 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=29765 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=29765 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=29765 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=29765 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29765 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=31767 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=31767 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=31767 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=31767 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=31767 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=31767 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=31767 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=31767 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=31767 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=31767 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=31767 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=31767 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=31767 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=31767 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(31778, 2, 0, 2639, -742, 313, 38134), -- -Unknown-
(31778, 1, 10, 2512, -665, 356, 38134), -- -Unknown-
(31778, 1, 9, 2492, -613, 357, 38134), -- -Unknown-
(31778, 1, 8, 2471, -471, 342, 38134), -- -Unknown-
(31778, 1, 7, 2473, -468, 341, 38134), -- -Unknown-
(31778, 1, 6, 2491, -459, 336, 38134), -- -Unknown-
(31778, 1, 5, 2547, -432, 336, 38134), -- -Unknown-
(31778, 1, 4, 2574, -433, 330, 38134), -- -Unknown-
(31778, 1, 3, 2601, -578, 330, 38134), -- -Unknown-
(31778, 1, 2, 2602, -584, 330, 38134), -- -Unknown-
(31778, 1, 1, 2600, -597, 347, 38134), -- -Unknown-
(31778, 1, 0, 2555, -669, 347, 38134), -- -Unknown-
(31778, 0, 0, 2639, -742, 313, 38134), -- -Unknown-
(29743, 4, 0, 2837, -705, 255, 38134), -- -Unknown-
(29743, 3, 0, 2562, -633, 337, 38134), -- -Unknown-
(29743, 2, 0, 2626, -531, 325, 38134), -- -Unknown-
(29743, 1, 0, 2672, -622, 293, 38134), -- -Unknown-
(29743, 0, 0, 2769, -568, 252, 38134), -- -Unknown-
(29765, 5, 0, 2836, -723, 260, 38134), -- -Unknown-
(29765, 4, 8, 2579, -708, 341, 38134), -- -Unknown-
(29765, 4, 7, 2571, -692, 342, 38134), -- -Unknown-
(29765, 4, 6, 2599, -528, 254, 38134), -- -Unknown-
(29765, 4, 5, 2677, -513, 231, 38134), -- -Unknown-
(29765, 4, 4, 2843, -558, 231, 38134), -- -Unknown-
(29765, 4, 3, 2849, -597, 243, 38134), -- -Unknown-
(29765, 4, 2, 2793, -671, 247, 38134), -- -Unknown-
(29765, 4, 1, 2769, -688, 281, 38134), -- -Unknown-
(29765, 4, 0, 2649, -746, 313, 38134), -- -Unknown-
(29765, 3, 8, 2579, -708, 341, 38134), -- -Unknown-
(29765, 3, 7, 2571, -692, 342, 38134), -- -Unknown-
(29765, 3, 6, 2599, -528, 254, 38134), -- -Unknown-
(29765, 3, 5, 2677, -513, 231, 38134), -- -Unknown-
(29765, 3, 4, 2843, -558, 231, 38134), -- -Unknown-
(29765, 3, 3, 2849, -597, 243, 38134), -- -Unknown-
(29765, 3, 2, 2793, -671, 247, 38134), -- -Unknown-
(29765, 3, 1, 2769, -688, 281, 38134), -- -Unknown-
(29765, 3, 0, 2649, -746, 313, 38134), -- -Unknown-
(29765, 2, 8, 2579, -708, 341, 38134), -- -Unknown-
(29765, 2, 7, 2571, -692, 342, 38134), -- -Unknown-
(29765, 2, 6, 2599, -528, 254, 38134), -- -Unknown-
(29765, 2, 5, 2677, -513, 231, 38134), -- -Unknown-
(29765, 2, 4, 2843, -558, 231, 38134), -- -Unknown-
(29765, 2, 3, 2849, -597, 243, 38134), -- -Unknown-
(29765, 2, 2, 2793, -671, 247, 38134), -- -Unknown-
(29765, 2, 1, 2769, -688, 281, 38134), -- -Unknown-
(29765, 2, 0, 2649, -746, 313, 38134), -- -Unknown-
(29765, 1, 8, 2579, -708, 341, 38134), -- -Unknown-
(29765, 1, 7, 2571, -692, 342, 38134), -- -Unknown-
(29765, 1, 6, 2599, -528, 254, 38134), -- -Unknown-
(29765, 1, 5, 2677, -513, 231, 38134), -- -Unknown-
(29765, 1, 4, 2843, -558, 231, 38134), -- -Unknown-
(29765, 1, 3, 2849, -597, 243, 38134), -- -Unknown-
(29765, 1, 2, 2793, -671, 247, 38134), -- -Unknown-
(29765, 1, 1, 2769, -688, 281, 38134), -- -Unknown-
(29765, 1, 0, 2649, -746, 313, 38134), -- -Unknown-
(29765, 0, 0, 2836, -723, 260, 38134), -- -Unknown-
(31767, 2, 0, 3126, -749, 228, 38134), -- -Unknown-
(31767, 1, 11, 3248, -1021, 258, 38134), -- -Unknown-
(31767, 1, 10, 3143, -991, 324, 38134), -- -Unknown-
(31767, 1, 9, 3037, -953, 258, 38134), -- -Unknown-
(31767, 1, 8, 3022, -944, 258, 38134), -- -Unknown-
(31767, 1, 7, 3029, -882, 258, 38134), -- -Unknown-
(31767, 1, 6, 3043, -801, 229, 38134), -- -Unknown-
(31767, 1, 5, 3305, -755, 229, 38134), -- -Unknown-
(31767, 1, 4, 3314, -759, 232, 38134), -- -Unknown-
(31767, 1, 3, 3341, -779, 246, 38134), -- -Unknown-
(31767, 1, 2, 3384, -828, 246, 38134), -- -Unknown-
(31767, 1, 1, 3392, -850, 246, 38134), -- -Unknown-
(31767, 1, 0, 3331, -1042, 258, 38134), -- -Unknown-
(31767, 0, 0, 3157, -976, 281, 38134); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID` IN (31779 /*-Unknown-*/, 31777 /*-Unknown-*/, 31778 /*-Unknown-*/, 31776 /*-Unknown-*/, 31775 /*-Unknown-*/, 29804 /*-Unknown-*/, 29743 /*-Unknown-*/, 29765 /*-Unknown-*/, 31774 /*-Unknown-*/, 31978 /*-Unknown-*/, 31773 /*-Unknown-*/, 29694 /*-Unknown-*/, 31770 /*-Unknown-*/, 31771 /*-Unknown-*/, 31769 /*-Unknown-*/, 31768 /*-Unknown-*/, 31767 /*-Unknown-*/, 31766 /*-Unknown-*/, 31765 /*-Unknown-*/, 29690 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(31779, 1, 6, 15, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31777, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31778, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31776, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31775, 1, 71, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29804, 396, 396, 0, 0, 0, 1000, 0, 0, 38134), -- -Unknown-
(29743, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29765, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31774, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31978, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31773, 1, 5, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29694, 5, 1, 25, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31770, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31771, 5, 25, 274, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31769, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31768, 1, 5, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31767, 1, 5, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31766, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31765, 5, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(29690, 396, 396, 0, 0, 0, 1000, 0, 0, 38134); -- -Unknown-


DELETE FROM `quest_request_items` WHERE `ID`=29765;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29765, 0, 0, 0, 0, 'You got me goods, mon?', 0); -- -Unknown-

DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (258351,103883,102988,103028,103015,131357,102971,131396,131469,102930,329135));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(258351, 0, 1754, -1731.0400390625, -1017.17999267578125, 46.59999847412109375, 38134), -- Spell: 258351 (Teleport Despawn) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(103883, 0, 870, 2835.93994140625, -722.5830078125, 259.894012451171875, 38134), -- Spell: 103883 (Summon Zin'Jun) Efffect: 28 (SPELL_EFFECT_SUMMON)
(102988, 0, 870, 3316.889892578125, -679.62200927734375, 227.5500030517578125, 38134), -- Spell: 102988 (Summon Rivett) Efffect: 28 (SPELL_EFFECT_SUMMON)
(103028, 0, 870, 3257.6201171875, -603.072998046875, 245.03900146484375, 38134), -- Spell: 103028 (Summon Shokia) Efffect: 28 (SPELL_EFFECT_SUMMON)
(103015, 0, 870, 3109.93994140625, -683.26202392578125, 230.425994873046875, 38134), -- Spell: 103015 (Summon Gorrok) Efffect: 28 (SPELL_EFFECT_SUMMON)
(131357, 0, 0, 3029.3798828125, -786.8590087890625, 227.5529937744140625, 38134), -- Spell: 131357 (Summon Kai-Lin) Efffect: 28 (SPELL_EFFECT_SUMMON)
(102971, 0, 870, 3030.760009765625, -786.6199951171875, 227.464996337890625, 38134), -- Spell: 102971 (Summon Kiryn) Efffect: 28 (SPELL_EFFECT_SUMMON)
(131396, 0, 0, 3034.139892578125, -781.7659912109375, 227.322998046875, 38134), -- Spell: 131396 (Summon Gi-Oh) Efffect: 28 (SPELL_EFFECT_SUMMON)
(131469, 0, 870, 3171.4599609375, -687.301025390625, 321.024993896484375, 38134), -- Spell: 131469 (Gunship Portal Click) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(102930, 0, 870, 3138.8701171875, -721.25, 325, 38134), -- Spell: 102930 (Teleport Player to Crash Site) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(329135, 0, 2222, -1834.18994140625, 1542.469970703125, 5274.16015625, 38134); -- Spell: 329135 (Portal to Oribos) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

DELETE FROM `creature_template_addon` WHERE `entry` IN (55674 /*55674 (Recovered Gyrocopter)*/, 55172 /*55172 (General Nazgrim) - Generic Quest Invisibility 1*/, 55622 /*55622 (Dook Ookem)*/, 62870 /*62870 (Rocket Jumpers Shoreline Bunny)*/, 66896 /*66896 (Strongarm Gyrocopter) - Ride Vehicle Hardcoded, Permanent Feign Death*/, 66897 /*66897 (Strongarm Gyrocopter)*/, 55610 /*55610 (Lurching Blossom) - Cosmetic - Loot Sparkles - GREEN*/, 66052 /*66052 (Captain Doren) - Dual Wield*/, 58943 /*58943 (Hozen Gutripper) - Hozen Rage*/, 58945 /*58945 (Hozen Nibstabber)*/, 55555 /*55555 (Hozen Mudflinger)*/, 62930 /*62930 (Water Sprite)*/, 63467 /*63467 (Enraged Treant)*/, 66743 /*66743 (Doubt)*/, 65883 /*65883 (Gyro-Mechanic Lavenderp)*/, 65882 /*65882 (Master Engineer Cogswing)*/, 65881 /*65881 (Corporal Jackson Silver)*/, 65842 /*65842 (Strongarm Medic)*/, 65906 /*65906 (Strongarm Laborer)*/, 65905 /*65905 (Strongarm Lieutenant)*/, 65841 /*65841 (Strongarm Private)*/, 65974 /*65974 (Pandaren Volunteer)*/, 67090 /*67090 (Pandaren Volunteer)*/, 65880 /*65880 (Morgus Grimhatchet)*/, 66000 /*66000 (Strongarm Ace)*/, 55522 /*55522 (Sergeant Gorrok)*/, 55523 /*55523 (Shokia)*/, 55180 /*55180 (Shademaster Kiryn) - Stealth*/, 65999 /*65999 (General Nazgrim)*/, 65998 /*65998 (Merchant Zin)*/, 55521 /*55521 (Rivett Clutchpop)*/, 55509 /*55509 (Konk)*/, 136445 /*136445 (Captain Rez'okun)*/, 129758 /*129758 (Irontide Grenadier) - Black Powder Bomb*/, 135938 /*135938 (Bilge Rat Party Animal) - Holding Empty Mug*/, 138676 /*138676 (Bilge Rat Party Animal) - Mod Scale 105-110%, Holding Empty Mug*/, 135978 /*135978 (Bilge Rat Grog Jerk) - Mod Scale 105-110%, Holding Empty Mug*/, 67019 /*67019 (Ancient Statue Shoulder)*/, 67018 /*67018 (Ancient Statue Head)*/, 66911 /*66911 (Lorbu Sadsummon)*/, 67017 /*67017 (Ancient Statue Arm)*/, 55392 /*55392 (Head Kill Credit Bunny)*/, 62994 /*62994 (Emerald Turtle)*/, 55388 /*55388 (Shoulder Kill Credit Bunny)*/, 66917 /*66917 (Hozen Groundpounder) - Ride Vehicle Hardcoded*/, 66916 /*66916 (Hozen Dangler VEHICLE)*/, 67016 /*67016 (Ancient Statue Torso)*/, 66694 /*66694 (General Nazgrim)*/, 59782 /*59782 (Cypress Condor)*/, 55383 /*55383 (Arm Kill Credit Bunny)*/, 55403 /*55403 (Zin'Jun) - Blood Spurts Periodic, Generic Quest Invisibility 29*/, 55404 /*55404 (Zin'Jun's Eye Socket) - Ride Vehicle Hardcoded*/, 61507 /*61507 (Zin'Jun's Left Hand) - Ride Vehicle Hardcoded*/, 55470 /*55470 (Hozen Groundpounder)*/, 55379 /*55379 (Torso Kill Credit Bunny)*/, 67250 /*67250 (Rivett Clutchpop)*/, 66847 /*66847 (Shokia)*/, 66825 /*66825 (Ellie Honeypaw)*/, 66857 /*66857 (Parachute Bunny) - Cosmetic - Parachute*/, 55146 /*55146 (Rivett Clutchpop) - Cosmetic - Parachute Back-Pack*/, 66660 /*66660 (Ellie Honeypaw) - Poking Stick*/, 63004 /*63004 (Grove Viper)*/, 66659 /*66659 (Sue-Ji the Tender)*/, 63003 /*63003 (Masked Tanuki)*/, 55170 /*55170 (Shokia) - Generic Quest Invisibility 7*/, 66346 /*66346 (Blacktalon Watcher)*/, 66848 /*66848 (Ellie Honeypaw)*/, 66222 /*66222 (Elder Muur)*/, 66430 /*66430 (Ethan Graveborn)*/, 66845 /*66845 (Sergeant Gorrok)*/, 66219 /*66219 (Kofa the Swift)*/, 66236 /*66236 (Brewmother Kiki)*/, 66347 /*66347 (Blacktalon Agent) - Assassin's Gear*/, 66230 /*66230 (Su Mi)*/, 66218 /*66218 (Lo Don)*/, 66238 /*66238 (Herim Woo)*/, 66665 /*66665 (Taran Zhu)*/, 66223 /*66223 (Elder Honeypaw)*/, 66237 /*66237 (Kan the Spiritful)*/, 66220 /*66220 (Mayor Honeydew)*/, 66235 /*66235 (Fieldwatcher Mao)*/, 66228 /*66228 (Tau Be)*/, 67252 /*67252 (Shademaster Kiryn)*/, 66265 /*66265 (Lu Jon Sun)*/, 66841 /*66841 (Kai-Lin Honeydew)*/, 55464 /*55464 (Hozen Corpse) - Ride Vehicle Hardcoded, Permanent Feign Death, Untrackable*/, 61535 /*61535 (Hozen Corpse) - Ride Vehicle Hardcoded, Permanent Feign Death (No Anim) (Root), Untrackable*/, 55463 /*55463 (Hozen Corpse Cluster)*/, 55162 /*55162 (Sergeant Gorrok) - Generic Quest Invisibility 6*/, 66668 /*66668 (Sha-Infested Prowler) - Sha-Corrupted*/, 66662 /*66662 (Gi-Oh)*/, 66840 /*66840 (Brew bunny) - Spilled Brew*/, 55141 /*55141 (Shademaster Kiryn)*/, 66838 /*66838 (Kai-Lin Honeydew)*/, 56198 /*56198 (Thicket Stalker) - Cosmetic - Sleep Zzz Breakable*/, 56199 /*56199 (Lightwing Hunter)*/, 66657 /*66657 (Taran Zhu)*/, 66656 /*66656 (General Nazgrim) - Filled with Doubt, Nazgrim's Axe - Sheathed*/, 58811 /*58811 (Jade Snapping Turtle)*/, 66928 /*66928 (Sha Shooter) - Sha Shooter Spawn [DNT], Stealth Detection*/, 66948 /*66948 (Twisted Corpse) - [DNT] Sha Transform FX Both Weapons (Until Cancelled)*/, 66425 /*66425 (Sha Haunt)*/, 66426 /*66426 (Sha Harbinger)*/, 66654 /*66654 (Thunder Hold Supplies)*/, 66688 /*66688 (Sha Tendrils) - Sha Tendrils*/, 66283 /*66283 (Captain Doren) - Dual Wield*/, 66555 /*66555 (Alliance Barricade)*/, 66556 /*66556 (Alliance Barricade)*/, 64776 /*64776 (Masked Tanuki Pup)*/, 66484 /*66484 (Thunder Hold Laborer) - Carry Sack (Peasant)*/, 66507 /*66507 (Thunder Hold Sharp-Shooter) - Wounded, [DNT] Injured*/, 66503 /*66503 (Thunder Hold Infantryman)*/, 66554 /*66554 (Alliance Barricade)*/, 67158 /*67158 (Kor'kron Elite)*/, 66915 /*66915 (Kor'kron Elite)*/, 66308 /*66308 (Thunder Hold Munitions) - Don't Cast On Me*/, 66286 /*66286 (Thunder Hold Mender) - Seal of Righteousness*/, 66742 /*66742 (Thunder Hold Fire Effects Bunny - Scorched Ground) - Scorched Ground*/, 66446 /*66446 (Thunder Hold Mender) - Seal of Righteousness*/, 66336 /*66336 (Thunder Hold Fire Effects Bunny) - Tents on Fire*/, 66506 /*66506 (Thunder Hold Cannoneer) - Wounded*/, 66320 /*66320 (Thunder Hold Explosive)*/, 66505 /*66505 (Thunder Hold Armsman) - Wounded, [DNT] Injured*/, 66646 /*66646 (General Nazgrim)*/, 66287 /*66287 (Thunder Hold Lieutenant)*/, 66649 /*66649 (Thunder Hold Mender) - Permanent Feign Death*/, 66651 /*66651 (Thunder Hold Laborer) - Permanent Feign Death*/, 66348 /*66348 (Thunder Hold Armsman)*/, 66650 /*66650 (Thunder Hold Infantryman) - Permanent Feign Death*/, 66647 /*66647 (Thunder Hold Sharp-Shooter) - Permanent Feign Death*/, 66307 /*66307 (Flame Bunny) - Cosmetic Gunship Fires*/, 66285 /*66285 (Thunder Hold Infantryman)*/, 66477 /*66477 (Thunder Hold Cannon Fire Effects Bunny) - Tents on Fire*/, 66648 /*66648 (Thunder Hold Lieutenant) - Permanent Feign Death*/, 66288 /*66288 (Thunder Hold Sharp-Shooter)*/, 66395 /*66395 (Thunder Hold Cannoneer)*/, 66284 /*66284 (Thunder Hold Laborer) - WA Carry Bomb Thunder Hold New Peasant*/, 66394 /*66394 (Thunder Hold Cannon)*/, 66634 /*66634 (Hellscream's Vanguard)*/, 66190 /*66190 (General Nazgrim)*/, 67071 /*67071 (Wary Forest Prowler)*/, 66214 /*66214 (Terrified Field Worker)*/, 65840 /*65840 (Strongarm Airman) - Ride Vehicle Hardcoded*/, 65843 /*65843 (Strongarm Gyrocopter)*/, 64874 /*64874 (Cannoneer Buczacki)*/, 64871 /*64871 (Warbringer Ho'Gan)*/, 64867 /*64867 (Kor'kron Shin)*/, 65148 /*65148 (Shikyo)*/, 64872 /*64872 (Sky Marshal Schwind)*/, 64873 /*64873 (Cannoneer Powell)*/, 64868 /*64868 (Kor'kron Dubs)*/, 64869 /*64869 (Kor'kron Jo'mag)*/, 67131 /*67131 (Hellscream's Vanguard) - Rappelling Rope Aura*/, 67129 /*67129 (Rapelling Manfred)*/, 64775 /*64775 (Masked Tanuki)*/, 66183 /*66183 (Gunship Turret)*/, 66676 /*66676 (Gunship Turret)*/, 66677 /*66677 (Gunship Turret)*/, 66674 /*66674 (Gunship Turret)*/, 64870 /*64870 (Kor'kron Spisak)*/, 64856 /*64856 (Sky Master Corpora)*/, 59312 /*59312 (Grove Viper)*/, 64761 /*64761 (Jumping Spider)*/, 67136 /*67136 (Exploding Manfred)*/, 66667 /*66667 (Rivett Clutchpop)*/, 63919 /*63919 (Leopard Tree Frog)*/, 64774 /*64774 (Leopard Tree Frog)*/, 59666 /*59666 (Emerald Turtle)*/, 66291 /*66291 (Thunder Hold Soldier)*/, 55135 /*55135 (General Nazgrim)*/, 66210 /*66210 (Thunder Hold Explosive Barrel)*/, 66795 /*66795 (Gunship Fire Bunny)*/, 66202 /*66202 (Thunder Hold Laborer)*/, 66793 /*66793 (Hellscream's Fist Engineer)*/, 66203 /*66203 (Thunder Hold Cannon)*/, 66200 /*66200 (Thunder Hold Soldier)*/, 61869 /*61869 (Snuff)*/, 61868 /*61868 (Zin'jun)*/, 61846 /*61846 (Gorrok)*/, 67040 /*67040 (Hellscream's Fist Deckswabber) - Arcane Channeling*/, 61844 /*61844 (Rivett Clutchpop)*/, 61867 /*61867 (Kiryn)*/, 61866 /*61866 (Shokia)*/, 61845 /*61845 (Hellscream's Vanguard)*/, 67032 /*67032 (Gunship Turret)*/, 67038 /*67038 (Hellscream's Fist Engineer)*/, 141669 /*141669*/, 141656 /*141656 - Set Health (Random 15%-55%)*/, 148795 /*148795 - Shattrath Portal Channel*/, 148770 /*148770 - Ashran Portal Channel*/, 168459 /*168459*/, 72559 /*72559*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(55674, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 55674 (Recovered Gyrocopter)
(55172, 0, 0, 65536, 1, 0, 0, 0, 0, '49414'), -- 55172 (General Nazgrim) - Generic Quest Invisibility 1
(55622, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55622 (Dook Ookem)
(62870, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 62870 (Rocket Jumpers Shoreline Bunny)
(66896, 0, 0, 0, 1, 0, 0, 0, 0, '46598 29266'), -- 66896 (Strongarm Gyrocopter) - Ride Vehicle Hardcoded, Permanent Feign Death
(66897, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66897 (Strongarm Gyrocopter)
(55610, 0, 0, 0, 1, 0, 0, 0, 0, '122170'), -- 55610 (Lurching Blossom) - Cosmetic - Loot Sparkles - GREEN
(66052, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 66052 (Captain Doren) - Dual Wield
(58943, 0, 0, 0, 1, 0, 0, 0, 0, '115006'), -- 58943 (Hozen Gutripper) - Hozen Rage
(58945, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 58945 (Hozen Nibstabber)
(55555, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55555 (Hozen Mudflinger)
(62930, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 62930 (Water Sprite)
(63467, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63467 (Enraged Treant)
(66743, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66743 (Doubt)
(65883, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65883 (Gyro-Mechanic Lavenderp)
(65882, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65882 (Master Engineer Cogswing)
(65881, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65881 (Corporal Jackson Silver)
(65842, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65842 (Strongarm Medic)
(65906, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65906 (Strongarm Laborer)
(65905, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65905 (Strongarm Lieutenant)
(65841, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65841 (Strongarm Private)
(65974, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65974 (Pandaren Volunteer)
(67090, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67090 (Pandaren Volunteer)
(65880, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 65880 (Morgus Grimhatchet)
(66000, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66000 (Strongarm Ace)
(55522, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 55522 (Sergeant Gorrok)
(55523, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55523 (Shokia)
(55180, 0, 0, 0, 1, 0, 0, 0, 0, '114943'), -- 55180 (Shademaster Kiryn) - Stealth
(65999, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 65999 (General Nazgrim)
(65998, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 65998 (Merchant Zin)
(55521, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 55521 (Rivett Clutchpop)
(55509, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55509 (Konk)
(136445, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136445 (Captain Rez'okun)
(129758, 0, 0, 0, 1, 0, 0, 0, 0, '257314'), -- 129758 (Irontide Grenadier) - Black Powder Bomb
(135938, 0, 0, 0, 0, 0, 0, 0, 0, '267324'), -- 135938 (Bilge Rat Party Animal) - Holding Empty Mug
(138676, 0, 0, 0, 0, 0, 0, 0, 0, '123169 267324'), -- 138676 (Bilge Rat Party Animal) - Mod Scale 105-110%, Holding Empty Mug
(135978, 0, 0, 0, 0, 0, 0, 0, 0, '123169 267324'), -- 135978 (Bilge Rat Grog Jerk) - Mod Scale 105-110%, Holding Empty Mug
(67019, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67019 (Ancient Statue Shoulder)
(67018, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67018 (Ancient Statue Head)
(66911, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66911 (Lorbu Sadsummon)
(67017, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67017 (Ancient Statue Arm)
(55392, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55392 (Head Kill Credit Bunny)
(62994, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 62994 (Emerald Turtle)
(55388, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55388 (Shoulder Kill Credit Bunny)
(66917, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 66917 (Hozen Groundpounder) - Ride Vehicle Hardcoded
(66916, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 66916 (Hozen Dangler VEHICLE)
(67016, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67016 (Ancient Statue Torso)
(66694, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66694 (General Nazgrim)
(59782, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 59782 (Cypress Condor)
(55383, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55383 (Arm Kill Credit Bunny)
(55403, 0, 0, 65544, 1, 0, 0, 0, 0, '103617 89304'), -- 55403 (Zin'Jun) - Blood Spurts Periodic, Generic Quest Invisibility 29
(55404, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 55404 (Zin'Jun's Eye Socket) - Ride Vehicle Hardcoded
(61507, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 61507 (Zin'Jun's Left Hand) - Ride Vehicle Hardcoded
(55470, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55470 (Hozen Groundpounder)
(55379, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55379 (Torso Kill Credit Bunny)
(67250, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67250 (Rivett Clutchpop)
(66847, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 66847 (Shokia)
(66825, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66825 (Ellie Honeypaw)
(66857, 0, 0, 0, 1, 0, 0, 0, 0, '131372'), -- 66857 (Parachute Bunny) - Cosmetic - Parachute
(55146, 0, 0, 50331648, 0, 0, 3166, 0, 0, '131129'), -- 55146 (Rivett Clutchpop) - Cosmetic - Parachute Back-Pack
(66660, 0, 0, 0, 1, 0, 3169, 0, 0, '131154'), -- 66660 (Ellie Honeypaw) - Poking Stick
(63004, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63004 (Grove Viper)
(66659, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66659 (Sue-Ji the Tender)
(63003, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63003 (Masked Tanuki)
(55170, 0, 0, 65544, 1, 0, 0, 0, 0, '85096'), -- 55170 (Shokia) - Generic Quest Invisibility 7
(66346, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 66346 (Blacktalon Watcher)
(66848, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66848 (Ellie Honeypaw)
(66222, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66222 (Elder Muur)
(66430, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66430 (Ethan Graveborn)
(66845, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 66845 (Sergeant Gorrok)
(66219, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66219 (Kofa the Swift)
(66236, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66236 (Brewmother Kiki)
(66347, 0, 0, 0, 0, 0, 0, 0, 0, '106283'), -- 66347 (Blacktalon Agent) - Assassin's Gear
(66230, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66230 (Su Mi)
(66218, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66218 (Lo Don)
(66238, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66238 (Herim Woo)
(66665, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66665 (Taran Zhu)
(66223, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66223 (Elder Honeypaw)
(66237, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66237 (Kan the Spiritful)
(66220, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66220 (Mayor Honeydew)
(66235, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66235 (Fieldwatcher Mao)
(66228, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66228 (Tau Be)
(67252, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 67252 (Shademaster Kiryn)
(66265, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66265 (Lu Jon Sun)
(66841, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66841 (Kai-Lin Honeydew)
(55464, 0, 0, 262144, 1, 0, 0, 0, 0, '46598 29266 28559'), -- 55464 (Hozen Corpse) - Ride Vehicle Hardcoded, Permanent Feign Death, Untrackable
(61535, 0, 0, 262144, 1, 0, 0, 0, 0, '46598 64461 28559'), -- 61535 (Hozen Corpse) - Ride Vehicle Hardcoded, Permanent Feign Death (No Anim) (Root), Untrackable
(55463, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55463 (Hozen Corpse Cluster)
(55162, 0, 0, 65539, 257, 0, 0, 0, 0, '82358'), -- 55162 (Sergeant Gorrok) - Generic Quest Invisibility 6
(66668, 0, 0, 0, 1, 0, 0, 0, 0, '128906'), -- 66668 (Sha-Infested Prowler) - Sha-Corrupted
(66662, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 66662 (Gi-Oh)
(66840, 0, 0, 0, 1, 0, 0, 0, 0, '131316'), -- 66840 (Brew bunny) - Spilled Brew
(55141, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 55141 (Shademaster Kiryn)
(66838, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 66838 (Kai-Lin Honeydew)
(56198, 0, 0, 0, 1, 0, 0, 0, 0, '120703'), -- 56198 (Thicket Stalker) - Cosmetic - Sleep Zzz Breakable
(56199, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 56199 (Lightwing Hunter)
(66657, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66657 (Taran Zhu)
(66656, 0, 0, 0, 1, 0, 0, 0, 0, '131812 131651'), -- 66656 (General Nazgrim) - Filled with Doubt, Nazgrim's Axe - Sheathed
(58811, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 58811 (Jade Snapping Turtle)
(66928, 0, 0, 0, 1, 0, 0, 0, 0, '131531 8279'), -- 66928 (Sha Shooter) - Sha Shooter Spawn [DNT], Stealth Detection
(66948, 0, 0, 0, 1, 0, 0, 0, 0, '131598'), -- 66948 (Twisted Corpse) - [DNT] Sha Transform FX Both Weapons (Until Cancelled)
(66425, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66425 (Sha Haunt)
(66426, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66426 (Sha Harbinger)
(66654, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66654 (Thunder Hold Supplies)
(66688, 0, 0, 0, 1, 0, 0, 0, 0, '131011'), -- 66688 (Sha Tendrils) - Sha Tendrils
(66283, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 66283 (Captain Doren) - Dual Wield
(66555, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66555 (Alliance Barricade)
(66556, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66556 (Alliance Barricade)
(64776, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 64776 (Masked Tanuki Pup)
(66484, 0, 0, 0, 1, 0, 0, 0, 0, '282130'), -- 66484 (Thunder Hold Laborer) - Carry Sack (Peasant)
(66507, 0, 0, 3, 2, 0, 0, 0, 0, '130763 130607'), -- 66507 (Thunder Hold Sharp-Shooter) - Wounded, [DNT] Injured
(66503, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66503 (Thunder Hold Infantryman)
(66554, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66554 (Alliance Barricade)
(67158, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67158 (Kor'kron Elite)
(66915, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66915 (Kor'kron Elite)
(66308, 0, 0, 0, 1, 0, 0, 0, 0, '130509'), -- 66308 (Thunder Hold Munitions) - Don't Cast On Me
(66286, 0, 0, 0, 1, 0, 0, 0, 0, '130433'), -- 66286 (Thunder Hold Mender) - Seal of Righteousness
(66742, 0, 0, 0, 1, 0, 0, 0, 0, '131096'), -- 66742 (Thunder Hold Fire Effects Bunny - Scorched Ground) - Scorched Ground
(66446, 0, 0, 0, 1, 0, 0, 0, 0, '130433'), -- 66446 (Thunder Hold Mender) - Seal of Righteousness
(66336, 0, 0, 0, 1, 0, 0, 0, 0, '130555'), -- 66336 (Thunder Hold Fire Effects Bunny) - Tents on Fire
(66506, 0, 0, 0, 1, 0, 0, 0, 0, '130763'), -- 66506 (Thunder Hold Cannoneer) - Wounded
(66320, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66320 (Thunder Hold Explosive)
(66505, 0, 0, 0, 1, 0, 0, 0, 0, '130763 130607'), -- 66505 (Thunder Hold Armsman) - Wounded, [DNT] Injured
(66646, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66646 (General Nazgrim)
(66287, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66287 (Thunder Hold Lieutenant)
(66649, 0, 0, 262144, 1, 0, 0, 0, 0, '130966'), -- 66649 (Thunder Hold Mender) - Permanent Feign Death
(66651, 0, 0, 262144, 1, 0, 0, 0, 0, '130966'), -- 66651 (Thunder Hold Laborer) - Permanent Feign Death
(66348, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66348 (Thunder Hold Armsman)
(66650, 0, 0, 262144, 1, 0, 0, 0, 0, '130966'), -- 66650 (Thunder Hold Infantryman) - Permanent Feign Death
(66647, 0, 0, 262144, 2, 0, 0, 0, 0, '130966'), -- 66647 (Thunder Hold Sharp-Shooter) - Permanent Feign Death
(66307, 0, 0, 0, 1, 0, 0, 0, 0, '130755'), -- 66307 (Flame Bunny) - Cosmetic Gunship Fires
(66285, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66285 (Thunder Hold Infantryman)
(66477, 0, 0, 0, 1, 0, 0, 0, 0, '130555'), -- 66477 (Thunder Hold Cannon Fire Effects Bunny) - Tents on Fire
(66648, 0, 0, 262144, 1, 0, 0, 0, 0, '130966'), -- 66648 (Thunder Hold Lieutenant) - Permanent Feign Death
(66288, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 66288 (Thunder Hold Sharp-Shooter)
(66395, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66395 (Thunder Hold Cannoneer)
(66284, 0, 0, 0, 1, 0, 0, 0, 0, '282237'), -- 66284 (Thunder Hold Laborer) - WA Carry Bomb Thunder Hold New Peasant
(66394, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66394 (Thunder Hold Cannon)
(66634, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66634 (Hellscream's Vanguard)
(66190, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66190 (General Nazgrim)
(67071, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67071 (Wary Forest Prowler)
(66214, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 66214 (Terrified Field Worker)
(65840, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 65840 (Strongarm Airman) - Ride Vehicle Hardcoded
(65843, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 65843 (Strongarm Gyrocopter)
(64874, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64874 (Cannoneer Buczacki)
(64871, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64871 (Warbringer Ho'Gan)
(64867, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64867 (Kor'kron Shin)
(65148, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 65148 (Shikyo)
(64872, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 64872 (Sky Marshal Schwind)
(64873, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64873 (Cannoneer Powell)
(64868, 0, 0, 8, 257, 0, 0, 0, 0, ''), -- 64868 (Kor'kron Dubs)
(64869, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 64869 (Kor'kron Jo'mag)
(67131, 0, 0, 262144, 1, 0, 0, 0, 0, '131992'), -- 67131 (Hellscream's Vanguard) - Rappelling Rope Aura
(67129, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67129 (Rapelling Manfred)
(64775, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 64775 (Masked Tanuki)
(66183, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66183 (Gunship Turret)
(66676, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66676 (Gunship Turret)
(66677, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66677 (Gunship Turret)
(66674, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66674 (Gunship Turret)
(64870, 0, 0, 8, 257, 0, 0, 0, 0, ''), -- 64870 (Kor'kron Spisak)
(64856, 0, 0, 3, 257, 0, 0, 0, 0, ''), -- 64856 (Sky Master Corpora)
(59312, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59312 (Grove Viper)
(64761, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 64761 (Jumping Spider)
(67136, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67136 (Exploding Manfred)
(66667, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66667 (Rivett Clutchpop)
(63919, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 63919 (Leopard Tree Frog)
(64774, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 64774 (Leopard Tree Frog)
(59666, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59666 (Emerald Turtle)
(66291, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66291 (Thunder Hold Soldier)
(55135, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55135 (General Nazgrim)
(66210, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66210 (Thunder Hold Explosive Barrel)
(66795, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66795 (Gunship Fire Bunny)
(66202, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66202 (Thunder Hold Laborer)
(66793, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66793 (Hellscream's Fist Engineer)
(66203, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66203 (Thunder Hold Cannon)
(66200, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66200 (Thunder Hold Soldier)
(61869, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61869 (Snuff)
(61868, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61868 (Zin'jun)
(61846, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61846 (Gorrok)
(67040, 0, 0, 0, 1, 0, 0, 0, 0, '131804'), -- 67040 (Hellscream's Fist Deckswabber) - Arcane Channeling
(61844, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61844 (Rivett Clutchpop)
(61867, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61867 (Kiryn)
(61866, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61866 (Shokia)
(61845, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 61845 (Hellscream's Vanguard)
(67032, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67032 (Gunship Turret)
(67038, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67038 (Hellscream's Fist Engineer)
(141669, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141669
(141656, 0, 0, 50331648, 1, 0, 0, 0, 0, '244971'), -- 141656 - Set Health (Random 15%-55%)
(148795, 0, 0, 0, 257, 0, 0, 0, 0, '288540'), -- 148795 - Shattrath Portal Channel
(148770, 0, 0, 0, 257, 0, 0, 0, 0, '288462'), -- 148770 - Ashran Portal Channel
(168459, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168459
(72559, 0, 0, 1, 256, 0, 0, 0, 0, ''); -- 72559

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=1 AND `Entry` IN (136445,129758,131092,129448,129359,126969,127106,130850,129352,130090,130172,130099,129350,129699,130086,130157,136539,127019,130012,130400,129673,129645,126983,129601,129529,129547,129600,129599,126847,126848,138705,138718,130011,129527,130404,130024,130521,135938,138676,135978,129550,129548,129559,129526,129092,127111,130522,127124,127119));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(136445, 1, 1, 50, 0, 0, 842, 38134),
(129758, 1, 10, 50, 0, 0, 1220, 38134),
(131092, 1, 10, 50, 0, 0, 830, 38134),
(129448, 1, 10, 50, 2, 2, 1220, 38134),
(129359, 1, 10, 50, 2, 2, 1220, 38134),
(126969, 1, 10, 50, 2, 2, 1220, 38134),
(127106, 1, 10, 50, 1, 1, 1220, 38134),
(130850, 1, 10, 50, 2, 2, 1220, 38134),
(129352, 1, 10, 50, 0, 0, 1220, 38134),
(130090, 1, 10, 50, 0, 0, 1220, 38134),
(130172, 1, 10, 50, 1, 1, 1220, 38134),
(130099, 1, 10, 50, 0, 0, 1220, 38134),
(129350, 1, 10, 50, 0, 0, 1220, 38134),
(129699, 1, 10, 50, 1, 1, 1220, 38134),
(130086, 1, 10, 50, 0, 0, 1220, 38134),
(130157, 1, 10, 50, 0, 0, 1220, 38134),
(136539, 1, 10, 50, 0, 0, 1220, 38134),
(127019, 1, 10, 50, 0, 0, 186, 38134),
(130012, 1, 10, 50, 0, 0, 1220, 38134),
(130400, 1, 10, 50, 1, 1, 1220, 38134),
(129673, 1, 10, 50, 1, 1, 1220, 38134),
(129645, 1, 10, 50, 1, 1, 1220, 38134),
(126983, 1, 10, 50, 2, 2, 1220, 38134),
(129601, 1, 10, 50, 0, 0, 1220, 38134),
(129529, 1, 10, 50, 0, 0, 1220, 38134),
(129547, 1, 10, 50, 0, 0, 1220, 38134),
(129600, 1, 10, 50, 0, 0, 1220, 38134),
(129599, 1, 10, 50, 0, 0, 1220, 38134),
(126847, 1, 10, 50, 2, 2, 1220, 38134),
(126848, 1, 10, 50, 2, 2, 1220, 38134),
(138705, 1, 10, 50, 0, 0, 1220, 38134),
(138718, 1, 10, 50, 0, 0, 1220, 38134),
(130011, 1, 10, 50, 0, 0, 1220, 38134),
(129527, 1, 10, 50, 0, 0, 1220, 38134),
(130404, 1, 10, 50, 0, 0, 1220, 38134),
(130024, 1, 10, 50, 0, 0, 1220, 38134),
(130521, 1, 10, 50, 0, 0, 1220, 38134),
(135938, 1, 10, 50, 0, 0, 1220, 38134),
(138676, 1, 10, 50, 0, 0, 1220, 38134),
(135978, 1, 10, 50, 0, 0, 1220, 38134),
(129550, 1, 10, 50, 0, 0, 1220, 38134),
(129548, 1, 10, 50, 0, 0, 1220, 38134),
(129559, 1, 10, 50, 0, 0, 1220, 38134),
(129526, 1, 10, 50, 0, 0, 1220, 38134),
(129092, 1, 10, 50, 0, 0, 186, 38134),
(127111, 1, 10, 50, 0, 0, 1220, 38134),
(130522, 1, 10, 50, 0, 0, 1220, 38134),
(127124, 1, 10, 50, 0, 0, 1220, 38134),
(127119, 1, 10, 50, 0, 0, 1220, 38134);

UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55674 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55172 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55622 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=62870 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66896 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=44775 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66897 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55610 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66052 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=59357 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=62992 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=58943 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=58945 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55555 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=62930 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=63467 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=657, `VerifiedBuild`=38134 WHERE (`Entry`=63420 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66743 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65883 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65882 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65881 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=41200 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65842 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65906 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65905 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65841 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65974 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=67090 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65880 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66000 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55522 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55523 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55180 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65999 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65998 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55521 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55509 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1220, `VerifiedBuild`=38134 WHERE (`Entry`=126832 AND `DifficultyID`=1);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1220, `VerifiedBuild`=38134 WHERE (`Entry`=129743 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1220, `VerifiedBuild`=38134 WHERE (`Entry`=129732 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1220, `VerifiedBuild`=38134 WHERE (`Entry`=126845 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=1220, `VerifiedBuild`=38134 WHERE (`Entry`=126919 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1220, `VerifiedBuild`=38134 WHERE (`Entry`=129602 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=130689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=1220, `VerifiedBuild`=38134 WHERE (`Entry`=126918 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126519 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=1220, `VerifiedBuild`=38134 WHERE (`Entry`=126928 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1220, `VerifiedBuild`=38134 WHERE (`Entry`=128551 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=1220, `VerifiedBuild`=38134 WHERE (`Entry`=129598 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126497 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=1220, `VerifiedBuild`=38134 WHERE (`Entry`=129788 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=67019 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=67018 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66911 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=67017 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55392 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=62994 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55388 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66917 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66916 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=67016 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66694 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=59782 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55383 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55403 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55404 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=61507 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55470 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55379 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=67250 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66847 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66825 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66857 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55146 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66660 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=63004 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66659 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=63003 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55170 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=657, `VerifiedBuild`=38134 WHERE (`Entry`=66346 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66848 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66222 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66430 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66845 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66219 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66236 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=657, `VerifiedBuild`=38134 WHERE (`Entry`=66347 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66230 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66218 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66238 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66665 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66223 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66237 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66220 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66235 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66228 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=67252 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66265 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66841 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55464 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=61535 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55463 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55162 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66668 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66662 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66840 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55141 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66838 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=56198 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=56199 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66657 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66656 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=58811 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66928 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66948 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66425 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66426 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66654 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66688 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66283 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66555 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66556 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=64776 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66484 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66507 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66503 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=63715 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=67158 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=2112, `VerifiedBuild`=38134 WHERE (`Entry`=66915 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=62167 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66308 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66286 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66742 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66446 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66336 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66506 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66320 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66505 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66646 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66287 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66649 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66651 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66348 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66650 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66647 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66307 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66285 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66477 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66648 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66288 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66395 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66284 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66394 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66634 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66190 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=67071 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66214 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65840 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65843 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=64874 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=64871 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=64867 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=65148 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=64872 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=64873 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=64868 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=64869 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=67131 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=67129 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=64775 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66183 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66676 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66677 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66674 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=64870 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=64856 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=59312 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=64761 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=67136 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66667 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=63919 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=64774 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=59666 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66291 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55135 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66210 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66795 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66202 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66793 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66203 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=66200 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=61869 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=61868 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=61846 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=887, `VerifiedBuild`=38134 WHERE (`Entry`=67040 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=61844 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=61867 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=61866 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=17213 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=40789 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=61845 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=67032 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=887, `VerifiedBuild`=38134 WHERE (`Entry`=67038 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=57, `VerifiedBuild`=38134 WHERE (`Entry`=55054 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=61158 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=62121 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=2, `VerifiedBuild`=38134 WHERE (`Entry`=36989 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=2, `VerifiedBuild`=38134 WHERE (`Entry`=36385 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=6, `VerifiedBuild`=38134 WHERE (`Entry`=830 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=2, `VerifiedBuild`=38134 WHERE (`Entry`=36384 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=60761 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=46985 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3353 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46667 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=171691 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3354 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMin`=3, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=31146 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=168621 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=168598 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=168596 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=168623 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=168597 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=42709 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=35845 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=347, `VerifiedBuild`=38134 WHERE (`Entry`=175084 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46642 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=347, `VerifiedBuild`=38134 WHERE (`Entry`=176261 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=42638 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=158789 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3359 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46619 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46621 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46622 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46618 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=153285 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46620 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3316 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=23635 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3366 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3365 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=3225 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=7088 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=5811 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3317 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=375, `VerifiedBuild`=38134 WHERE (`Entry`=14451 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=2855 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMax`=0, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=62200 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=62199 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=-4, `LevelScalingDeltaMax`=-2, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=14499 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=378, `VerifiedBuild`=38134 WHERE (`Entry`=14498 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3321 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3363 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3364 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3315 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=861, `VerifiedBuild`=38134 WHERE (`Entry`=52810 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=861, `VerifiedBuild`=38134 WHERE (`Entry`=52812 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3369 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=52809 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=68979 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=54473 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=54472 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=303, `VerifiedBuild`=38134 WHERE (`Entry`=57801 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44725 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=24935 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=24931 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=24930 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=24929 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=25081 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=25075 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=45230 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=24926 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=966, `VerifiedBuild`=38134 WHERE (`Entry`=24924 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3330 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3328 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3327 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=378, `VerifiedBuild`=38134 WHERE (`Entry`=3334 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=378, `VerifiedBuild`=38134 WHERE (`Entry`=5816 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=47233 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3189 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44735 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=12136 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3335 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=5875 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=49737 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=88705 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=88704 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=830, `VerifiedBuild`=38134 WHERE (`Entry`=141528 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=5909 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=378, `VerifiedBuild`=38134 WHERE (`Entry`=3368 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=293, `VerifiedBuild`=38134 WHERE (`Entry`=130911 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=9564 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=47254 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=88706 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=43, `VerifiedBuild`=38134 WHERE (`Entry`=20486 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46708 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=861, `VerifiedBuild`=38134 WHERE (`Entry`=43062 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=378, `VerifiedBuild`=38134 WHERE (`Entry`=3367 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44918 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=42506 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=43, `VerifiedBuild`=38134 WHERE (`Entry`=20490 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=43, `VerifiedBuild`=38134 WHERE (`Entry`=20493 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=43, `VerifiedBuild`=38134 WHERE (`Entry`=20488 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46709 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44948 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=50477 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=43, `VerifiedBuild`=38134 WHERE (`Entry`=20491 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=50488 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=43, `VerifiedBuild`=38134 WHERE (`Entry`=20492 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=50323 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=43, `VerifiedBuild`=38134 WHERE (`Entry`=20489 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44919 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=63626 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=3310 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3216 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=15476 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=14881 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3331 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141310 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=378, `VerifiedBuild`=38134 WHERE (`Entry`=5639 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=47248 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=62194 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=47247 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=47246 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=378, `VerifiedBuild`=38134 WHERE (`Entry`=3329 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=62198 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=62822 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=62821 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=72654 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3323 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=44868 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44867 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44866 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44865 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=378, `VerifiedBuild`=38134 WHERE (`Entry`=10880 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=829, `VerifiedBuild`=38134 WHERE (`Entry`=149404 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=145714 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=148265 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=347, `VerifiedBuild`=38134 WHERE (`Entry`=148768 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=61325 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=42859 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=711, `VerifiedBuild`=38134 WHERE (`Entry`=71100 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=347, `VerifiedBuild`=38134 WHERE (`Entry`=149616 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=172, `VerifiedBuild`=38134 WHERE (`Entry`=149297 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=817, `VerifiedBuild`=38134 WHERE (`Entry`=148263 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=494, `VerifiedBuild`=38134 WHERE (`Entry`=141669 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=494, `VerifiedBuild`=38134 WHERE (`Entry`=141656 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=40891 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=47253 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=820, `VerifiedBuild`=38134 WHERE (`Entry`=148795 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=15, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=959, `VerifiedBuild`=38134 WHERE (`Entry`=155739 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=867, `VerifiedBuild`=38134 WHERE (`Entry`=6566 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=867, `VerifiedBuild`=38134 WHERE (`Entry`=50304 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=820, `VerifiedBuild`=38134 WHERE (`Entry`=150131 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=847, `VerifiedBuild`=38134 WHERE (`Entry`=149279 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=494, `VerifiedBuild`=38134 WHERE (`Entry`=141652 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=847, `VerifiedBuild`=38134 WHERE (`Entry`=151937 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=178, `VerifiedBuild`=38134 WHERE (`Entry`=149626 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=7, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=11, `VerifiedBuild`=38134 WHERE (`Entry`=149258 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=494, `VerifiedBuild`=38134 WHERE (`Entry`=142856 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=11156 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=14558 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=12343 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=34238 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=347, `VerifiedBuild`=38134 WHERE (`Entry`=133186 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=494, `VerifiedBuild`=38134 WHERE (`Entry`=141691 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=826, `VerifiedBuild`=38134 WHERE (`Entry`=149296 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=35169 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=816, `VerifiedBuild`=38134 WHERE (`Entry`=148770 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=847, `VerifiedBuild`=38134 WHERE (`Entry`=149523 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=494, `VerifiedBuild`=38134 WHERE (`Entry`=141693 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=12342 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=12341 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=871, `VerifiedBuild`=38134 WHERE (`Entry`=148250 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=871, `VerifiedBuild`=38134 WHERE (`Entry`=148242 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=494, `VerifiedBuild`=38134 WHERE (`Entry`=141702 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=847, `VerifiedBuild`=38134 WHERE (`Entry`=149522 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=7395 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=149270 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=88702 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=88701 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=6466 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=5611 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=5610 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=44871 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=44872 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=494, `VerifiedBuild`=38134 WHERE (`Entry`=141647 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137762 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135202 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=5817 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=5614 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=5613 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=5609 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=5606 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3313 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=6929 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=158637 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=168459 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=62195 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=14392 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=88703 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=378, `VerifiedBuild`=38134 WHERE (`Entry`=14375 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=44338 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=44876 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44856 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=44878 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44852 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44853 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=44877 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=378, `VerifiedBuild`=38134 WHERE (`Entry`=3312 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44854 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=44851 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=298, `VerifiedBuild`=38134 WHERE (`Entry`=89830 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=859, `VerifiedBuild`=38134 WHERE (`Entry`=72559 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=298, `VerifiedBuild`=38134 WHERE (`Entry`=27489 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=378, `VerifiedBuild`=38134 WHERE (`Entry`=3342 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=17098 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=861, `VerifiedBuild`=38134 WHERE (`Entry`=49750 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=861, `VerifiedBuild`=38134 WHERE (`Entry`=45337 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46572 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=46140 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3370 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3144 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=23128 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=47571 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135201 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=44, `VerifiedBuild`=38134 WHERE (`Entry`=26537 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=52034 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46556 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=861, `VerifiedBuild`=38134 WHERE (`Entry`=45339 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46555 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=4047 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=49622 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=51195 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=58155 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=20, `LevelScalingDeltaMax`=0, `ContentTuningID`=79, `VerifiedBuild`=38134 WHERE (`Entry`=49131 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=44160 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=75, `VerifiedBuild`=38134 WHERE (`Entry`=46142 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=34765 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=35068 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=5910 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=70, `VerifiedBuild`=38134 WHERE (`Entry`=44158 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=62115 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=45565 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46512 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=29929 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=172558 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=69978 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46358 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=69977 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=63086 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=373, `VerifiedBuild`=38134 WHERE (`Entry`=63085 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=37072 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=52036 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=46755 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=30611 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=42548 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=12798 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3314 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=48513 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46357 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=46754 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=824, `VerifiedBuild`=38134 WHERE (`Entry`=167032 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=73151 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=45563 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=74228 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=45553 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=121541 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=45552 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=12796 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=32642 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=12795 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=32641 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=28960 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=12794 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=12793 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=146626 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=12790 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=12789 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=49743 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=14376 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=3319 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=674, `VerifiedBuild`=38134 WHERE (`Entry`=158141 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=674, `VerifiedBuild`=38134 WHERE (`Entry`=158138 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=48510 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=62114 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=674, `VerifiedBuild`=38134 WHERE (`Entry`=158133 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=674, `VerifiedBuild`=38134 WHERE (`Entry`=158131 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=19850 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=54657 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=38821 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=293, `VerifiedBuild`=38134 WHERE (`Entry`=133261 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=52033 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=3296 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=293, `VerifiedBuild`=38134 WHERE (`Entry`=133523 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=175050 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=494, `VerifiedBuild`=38134 WHERE (`Entry`=141119 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=45814 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=49837 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=12797 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=32520 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=51346 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=483, `VerifiedBuild`=38134 WHERE (`Entry`=12791 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46359 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=378, `VerifiedBuild`=38134 WHERE (`Entry`=5188 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=866, `VerifiedBuild`=38134 WHERE (`Entry`=46082 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `BoundingRadius`=3.56083536148071289, `CombatReach`=4.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=42857;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=37616;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=29999;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=30122;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44762;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=40716;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=40713;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=40692;
UPDATE `creature_model_info` SET `BoundingRadius`=1.424334168434143066, `CombatReach`=1.760000109672546386, `VerifiedBuild`=38134 WHERE `DisplayID`=42528;
UPDATE `creature_model_info` SET `BoundingRadius`=0.399049997329711914, `CombatReach`=2.299999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=42681;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=40691;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=16925;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44661;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44660;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44708;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44704;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44659;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45756;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44707;
UPDATE `creature_model_info` SET `BoundingRadius`=0.399049997329711914, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=45790;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44702;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45761;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44705;
UPDATE `creature_model_info` SET `BoundingRadius`=0.399049997329711914, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=45791;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44706;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44700;
UPDATE `creature_model_info` SET `BoundingRadius`=0.399049997329711914, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=44732;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45757;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44701;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44709;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44703;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45762;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44658;
UPDATE `creature_model_info` SET `BoundingRadius`=0.399049997329711914, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=44731;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44730;
UPDATE `creature_model_info` SET `BoundingRadius`=1.780417680740356445, `VerifiedBuild`=38134 WHERE `DisplayID`=41120;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81389;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=32542;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80613;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55657;
UPDATE `creature_model_info` SET `BoundingRadius`=0.451388567686080932, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=81286;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79068;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80548;
UPDATE `creature_model_info` SET `BoundingRadius`=1.335313200950622558, `CombatReach`=1.649999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=80940;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81295;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80391;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80547;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80792;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80087;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79072;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80090;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78630;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78999;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=28047;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81508;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80343;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=68059;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80336;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71849;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80779;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80841;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81208;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80344;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80380;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81207;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79067;
UPDATE `creature_model_info` SET `BoundingRadius`=0.80699998140335083, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=80475;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80335;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79066;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79065;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81060;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87973;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80346;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85954;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85960;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765639662742614746, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=81403;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79069;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765639662742614746, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=81401;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87975;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765639662742614746, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=81402;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80340;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79064;
UPDATE `creature_model_info` SET `BoundingRadius`=1.335313200950622558, `CombatReach`=1.649999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=81424;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80320;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80089;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81279;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87974;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80389;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80339;
UPDATE `creature_model_info` SET `BoundingRadius`=0.890208840370178222, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=80322;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81280;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80088;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78483;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78623;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80438;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79078;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40905;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=30221;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88577;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88576;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80382;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80532;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81224;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382499992847442626, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=88575;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53316;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79077;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88578;
UPDATE `creature_model_info` SET `BoundingRadius`=0.260000020265579223, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=81253;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382499992847442626, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=88574;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=51414;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=30223;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382499992847442626, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=81254;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36499;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79071;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=30222;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=30224;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36357;
UPDATE `creature_model_info` SET `BoundingRadius`=0.908434152603149414, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88571;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4959;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382499992847442626, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=81255;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=35802;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45499;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=23985;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=39117;
UPDATE `creature_model_info` SET `BoundingRadius`=1.335313320159912109, `VerifiedBuild`=38134 WHERE `DisplayID`=41044;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2957;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45269;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44995;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45270;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44878;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45095;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44876;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44892;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=44983;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44886;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44875;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44894;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44879;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44893;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44877;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44891;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44885;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44928;
UPDATE `creature_model_info` SET `BoundingRadius`=1.335313320159912109, `VerifiedBuild`=38134 WHERE `DisplayID`=41066;
UPDATE `creature_model_info` SET `BoundingRadius`=1.335313320159912109, `VerifiedBuild`=38134 WHERE `DisplayID`=41063;
UPDATE `creature_model_info` SET `BoundingRadius`=1.335313320159912109, `VerifiedBuild`=38134 WHERE `DisplayID`=41064;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45272;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=39039;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45389;
UPDATE `creature_model_info` SET `BoundingRadius`=1.033499956130981445, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=45682;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=10828;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416666418313980102, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=45518;
UPDATE `creature_model_info` SET `BoundingRadius`=0.716146051883697509, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=42234;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=40625;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=0.60000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=44411;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41677;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85280;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45117;
UPDATE `creature_model_info` SET `BoundingRadius`=0.489600002765655517, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=45057;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=43194;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88841;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45128;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45126;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45144;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45151;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=44985;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85293;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59357;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=44984;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45153;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45150;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=44986;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59359;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45119;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45112;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44994;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45114;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45115;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45143;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45130;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45137;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45129;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45113;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45152;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45141;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45136;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44873;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45142;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45125;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45131;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45135;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45134;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59358;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=45103;
UPDATE `creature_model_info` SET `BoundingRadius`=1.192499995231628417, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=40358;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44872;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=44634;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=28038;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45501;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=30511;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=1829;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=6303;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45503;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45502;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=32200;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=40093;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=14360;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=39276;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2955;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=43199;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306865453720092773, `VerifiedBuild`=38134 WHERE `DisplayID`=43311;
UPDATE `creature_model_info` SET `BoundingRadius`=0.255721211433410644, `VerifiedBuild`=38134 WHERE `DisplayID`=6296;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27883;
UPDATE `creature_model_info` SET `BoundingRadius`=0.413100004196166992, `CombatReach`=2.02500009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=85277;
UPDATE `creature_model_info` SET `BoundingRadius`=0.520500004291534423, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=44863;
UPDATE `creature_model_info` SET `BoundingRadius`=0.413100004196166992, `CombatReach`=2.02500009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=85292;
UPDATE `creature_model_info` SET `BoundingRadius`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44868;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=39810;
UPDATE `creature_model_info` SET `BoundingRadius`=0.312000006437301635, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=44862;
UPDATE `creature_model_info` SET `BoundingRadius`=0.583500027656555175, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=44864;
UPDATE `creature_model_info` SET `BoundingRadius`=0.413100004196166992, `CombatReach`=2.02500009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=59356;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=45101;
UPDATE `creature_model_info` SET `BoundingRadius`=0.458999991416931152, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=44861;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41931;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=39116;
UPDATE `creature_model_info` SET `BoundingRadius`=0.409200012683868408, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=39047;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45680;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45665;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=39044;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45663;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=39207;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=39049;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=16910;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45664;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=32575;
UPDATE `creature_model_info` SET `BoundingRadius`=1.899999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=44851;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45666;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=32791;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27881;
UPDATE `creature_model_info` SET `BoundingRadius`=0.989395022392272949, `VerifiedBuild`=38134 WHERE `DisplayID`=6764;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=30101;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=30100;
UPDATE `creature_model_info` SET `BoundingRadius`=1.066211581230163574, `CombatReach`=1.392857074737548828 WHERE `DisplayID`=342;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=30099;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45880;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4008;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=7995;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4052;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=99427;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=34047;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=1330;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=1328;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=1327;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=1334;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=99457;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=99460;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=99459;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=34049;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=12229;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=99454;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=99461;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61027;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61026;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=64307;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4545;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81476;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=99455;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=17700;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=17721;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=17701;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=17699;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27597;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33699;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=90314;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90258;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=24164;

DELETE FROM `creature_equip_template` WHERE (`ID`=2 AND `CreatureID` IN (65906,67090,65974,130521,130522,129529,66348,66291,66793)) OR (`ID`=1 AND `CreatureID` IN (41200,65906,65974,67090,129529,130521,130522,135938,138676,135978,61845,141669,168459)) OR (`ID`=3 AND `CreatureID`=130522);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(65906, 2, 45123, 0, 0, 0, 0, 0, 0, 0, 0), -- Strongarm Laborer
(67090, 2, 45123, 0, 0, 0, 0, 0, 0, 0, 0), -- Pandaren Volunteer
(41200, 1, 1896, 0, 0, 37119, 0, 0, 0, 0, 0), -- Generic Bunny - PRK
(65974, 2, 45123, 0, 0, 0, 0, 0, 0, 0, 0), -- Pandaren Volunteer
(65906, 1, 84777, 0, 0, 0, 0, 0, 0, 0, 0), -- Strongarm Laborer
(65974, 1, 84777, 0, 0, 0, 0, 0, 0, 0, 0), -- Pandaren Volunteer
(67090, 1, 84777, 0, 0, 0, 0, 0, 0, 0, 0), -- Pandaren Volunteer
(130522, 3, 2202, 0, 0, 0, 0, 0, 0, 0, 0), -- Freehold Shipmate
(130521, 2, 2703, 0, 0, 0, 0, 0, 0, 0, 0), -- Freehold Deckhand
(130522, 2, 155894, 0, 0, 0, 0, 0, 0, 0, 0), -- Freehold Shipmate
(129529, 2, 80580, 0, 0, 159852, 0, 0, 0, 0, 0), -- Blacktooth Scrapper
(129529, 1, 159852, 0, 0, 159852, 0, 0, 0, 0, 0), -- Blacktooth Scrapper
(130521, 1, 155894, 0, 0, 0, 0, 0, 0, 0, 0), -- Freehold Deckhand
(130522, 1, 2703, 0, 0, 0, 0, 0, 0, 0, 0), -- Freehold Shipmate
(135938, 1, 3362, 0, 0, 13605, 0, 0, 0, 0, 0), -- Bilge Rat Party Animal
(138676, 1, 1897, 0, 0, 0, 0, 0, 0, 0, 0), -- Bilge Rat Party Animal
(135978, 1, 5283, 0, 0, 5283, 0, 0, 0, 0, 0), -- Bilge Rat Grog Jerk
(66348, 2, 31824, 0, 0, 0, 0, 0, 12523, 0, 0), -- Thunder Hold Armsman
(66291, 2, 0, 0, 0, 0, 0, 0, 12523, 0, 0), -- Thunder Hold Soldier
(66793, 2, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- Hellscream's Fist Engineer
(61845, 1, 5289, 0, 0, 0, 0, 0, 0, 0, 0), -- Hellscream's Vanguard
(141669, 1, 5303, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(168459, 1, 5289, 0, 0, 0, 0, 0, 2507, 0, 0); -- -Unknown-

UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=66346 AND `ID`=1); -- Blacktalon Watcher
UPDATE `creature_equip_template` SET `ItemID1`=1903 WHERE (`CreatureID`=66348 AND `ID`=1); -- Thunder Hold Armsman
UPDATE `creature_equip_template` SET `ItemID1`=1906, `ItemID3`=6088 WHERE (`CreatureID`=66395 AND `ID`=1); -- Thunder Hold Cannoneer
UPDATE `creature_equip_template` SET `ItemID1`=1906, `ItemID3`=6088 WHERE (`CreatureID`=66291 AND `ID`=1); -- Thunder Hold Soldier
UPDATE `creature_equip_template` SET `ItemID1`=13607 WHERE (`CreatureID`=66793 AND `ID`=1); -- Hellscream's Fist Engineer
UPDATE `creature_equip_template` SET `ItemID1`=5289, `ItemID2`=0 WHERE (`CreatureID`=30611 AND `ID`=1); -- -Unknown-

DELETE FROM `gossip_menu` WHERE (`MenuId`=14930 AND `TextId`=19314) OR (`MenuId`=15119 AND `TextId`=21636) OR (`MenuId`=15122 AND `TextId`=21637) OR (`MenuId`=13126 AND `TextId`=18464) OR (`MenuId`=13127 AND `TextId`=18465) OR (`MenuId`=13125 AND `TextId`=18462) OR (`MenuId`=13123 AND `TextId`=18461) OR (`MenuId`=13090 AND `TextId`=18388) OR (`MenuId`=13098 AND `TextId`=18392) OR (`MenuId`=15033 AND `TextId`=21267) OR (`MenuId`=13091 AND `TextId`=18389) OR (`MenuId`=15085 AND `TextId`=21407) OR (`MenuId`=13087 AND `TextId`=18387) OR (`MenuId`=15031 AND `TextId`=21263) OR (`MenuId`=14988 AND `TextId`=21186);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(14930, 19314, 38134), -- 65999 (General Nazgrim)
(15119, 21636, 38134), -- 65974 (Pandaren Volunteer)
(15122, 21637, 38134), -- 67090 (Pandaren Volunteer)
(13126, 18464, 38134), -- 212184
(13127, 18465, 38134), -- 212186
(13125, 18462, 38134), -- 212183
(13123, 18461, 38134), -- 212182
(13090, 18388, 38134), -- 55146 (Rivett Clutchpop)
(13098, 18392, 38134), -- 55170 (Shokia)
(15033, 21267, 38134), -- 66665 (Taran Zhu)
(13091, 18389, 38134), -- 55162 (Sergeant Gorrok)
(15085, 21407, 38134), -- 66870 (Gi-Oh)
(13087, 18387, 38134), -- 55141 (Shademaster Kiryn)
(15031, 21263, 38134), -- 66656 (General Nazgrim)
(14988, 21186, 38134); -- 55054 (General Nazgrim)

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=4342 AND `TextId`=5516); -- 0
DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=0 AND `MenuId` IN (15119,15122,13126,13127,13125,13123,13090,13098,13091,13087)) OR (`OptionIndex`=7 AND `MenuId`=4342);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(15119, 0, 0, 'You can go home now. I\'ll cover your back.', 68580, 38134),
(15122, 0, 0, 'You can go home to your family now.', 68670, 38134),
(13126, 0, 0, '<Create a sketch of the statue piece.>', 53792, 38134),
(13127, 0, 0, '<Create a sketch of the statue piece.>', 53792, 38134),
(13125, 0, 0, '<Create a sketch of the statue piece.>', 53792, 38134),
(13123, 0, 0, '<Create a sketch of the statue piece.>', 53792, 38134),
(13090, 0, 0, 'Quit messing around and use your knife! Nazgrim wants you to report to the village immediately.', 53485, 38134),
(13098, 0, 0, 'On your feet! Nazgrim is organizing a counter-attack. We\'re regrouping in the village.', 53504, 38134),
(13091, 0, 0, 'We need to regroup, Sergeant! Go to the nearby village.', 53494, 38134),
(13087, 0, 0, 'Snap out of it! You\'re alive! Nazgrim has ordered us to report to the nearby village.', 53474, 38134),
(4342, 7, 0, 'I need a flight to Hellscream\'s Fist.', 0, 38134);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=67518, `VerifiedBuild`=38134 WHERE (`MenuId`=14988 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=67518, `VerifiedBuild`=38134 WHERE (`MenuId`=14988 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3409, `VerifiedBuild`=38134 WHERE (`MenuId`=4342 AND `OptionIndex`=0);

UPDATE `quest_template` SET `RewardMoney`=86400, `RewardBonusMoney`=1860, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31779; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=38050, `RewardBonusMoney`=1440, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31777; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=38050, `RewardBonusMoney`=1440, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31778; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=38050, `RewardBonusMoney`=1440, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31776; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=38050, `RewardBonusMoney`=1440, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31775; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=38050, `RewardBonusMoney`=1440, `RewardSpell`=81040, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29804; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=32900, `RewardBonusMoney`=1320, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=31725; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=3290, `RewardBonusMoney`=180, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=51101; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=65800, `RewardBonusMoney`=1680, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=47706; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=65800, `RewardBonusMoney`=1680, `FlagsEx`=2097216, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=38134 WHERE `ID`=51091; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=65800, `RewardBonusMoney`=1680, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=47439; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2700, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=27365; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=16450, `RewardBonusMoney`=660, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=26642; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=32900, `RewardBonusMoney`=1320, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=32603; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097472, `VerifiedBuild`=38134 WHERE `ID`=53602; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=137400, `RewardBonusMoney`=2900, `FlagsEx`=2097472, `VerifiedBuild`=38134 WHERE `ID`=51979; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=420000, `RewardBonusMoney`=14700, `FlagsEx`=6299712, `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0, `VerifiedBuild`=38134 WHERE `ID`=53437; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=137400, `RewardBonusMoney`=2900, `FlagsEx`=2097472, `VerifiedBuild`=38134 WHERE `ID`=52746; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=32900, `RewardBonusMoney`=1320, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29593; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=32900, `RewardBonusMoney`=1320, `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29530; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=32900, `RewardBonusMoney`=1320, `Flags`=134217736, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29527; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=53500, `RewardBonusMoney`=1680, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=27605; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=53500, `RewardBonusMoney`=1680, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=27604; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=32900, `RewardBonusMoney`=1320, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=27305; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=32900, `RewardBonusMoney`=1320, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=27185; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=79250, `RewardBonusMoney`=2040, `Flags`=8, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=13151; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=79250, `RewardBonusMoney`=2040, `Flags`=0, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=12924; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1020, `Flags`=0, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=12041; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1320, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=192; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1320, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=186; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1320, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29743; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=32900, `RewardBonusMoney`=1320, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29765; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=32900, `RewardBonusMoney`=1320, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31774; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27750, `RewardBonusMoney`=1260, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31978; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27750, `RewardBonusMoney`=1260, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31773; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27750, `RewardBonusMoney`=1260, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=30079; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27750, `RewardBonusMoney`=1260, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29981; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=2775, `RewardBonusMoney`=150, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29907; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27750, `RewardBonusMoney`=1260, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29745; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=2775, `RewardBonusMoney`=150, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29618; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27750, `RewardBonusMoney`=1260, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=29694; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27750, `RewardBonusMoney`=1260, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31770; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27750, `RewardBonusMoney`=1260, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31771; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27750, `RewardBonusMoney`=1260, `FlagsEx`=2097218, `VerifiedBuild`=38134 WHERE `ID`=31769; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27750, `RewardBonusMoney`=1260, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31768; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27750, `RewardBonusMoney`=1260, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31767; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=27750, `RewardBonusMoney`=1260, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31766; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=22600, `RewardBonusMoney`=1200, `RewardSpell`=81040, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=31765; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=2260, `RewardBonusMoney`=150, `FlagsEx`=1075839040, `VerifiedBuild`=38134 WHERE `ID`=29690; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1200, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=14129; -- -Unknown-


UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=269223; -- 269223
UPDATE `quest_objectives` SET `Description`='Strongarm Gyrocopter shot down', `VerifiedBuild`=38134 WHERE `ID`=269001; -- 269001
UPDATE `quest_objectives` SET `Description`='Indentured Pandaren freed', `VerifiedBuild`=38134 WHERE `ID`=269036; -- 269036
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=269008; -- 269008
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=269007; -- 269007
UPDATE `quest_objectives` SET `Description`='Master Engineer Cogswing and Gyro-Mechanic Lavenderp slain', `VerifiedBuild`=38134 WHERE `ID`=268997; -- 268997
UPDATE `quest_objectives` SET `Description`='Strongarm troop slain', `VerifiedBuild`=38134 WHERE `ID`=269035; -- 269035
UPDATE `quest_objectives` SET `Description`='Konk Slain', `VerifiedBuild`=38134 WHERE `ID`=264331; -- 264331
UPDATE `quest_objectives` SET `Description`='Defeat Lindsay', `VerifiedBuild`=38134 WHERE `ID`=268950; -- 268950
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=290785; -- 290785
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334729; -- 334729
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=334728; -- 334728
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=293261; -- 293261
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=255570; -- 255570
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=255569; -- 255569
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=255568; -- 255568
UPDATE `quest_objectives` SET `Description`='Defeat Skitterer Xi\'a', `VerifiedBuild`=38134 WHERE `ID`=270140; -- 270140
UPDATE `quest_objectives` SET `Description`='Defeat Nitun', `VerifiedBuild`=38134 WHERE `ID`=270139; -- 270139
UPDATE `quest_objectives` SET `Description`='Defeat Dos-Ryga', `VerifiedBuild`=38134 WHERE `ID`=270138; -- 270138
UPDATE `quest_objectives` SET `Description`='Defeat Kafi', `VerifiedBuild`=38134 WHERE `ID`=270137; -- 270137
UPDATE `quest_objectives` SET `Description`='Defeat Ti\'un the Wanderer', `VerifiedBuild`=38134 WHERE `ID`=270136; -- 270136
UPDATE `quest_objectives` SET `Description`='Defeat Lucky Yi', `VerifiedBuild`=38134 WHERE `ID`=270135; -- 270135
UPDATE `quest_objectives` SET `Description`='Defeat Greyhoof', `VerifiedBuild`=38134 WHERE `ID`=270134; -- 270134
UPDATE `quest_objectives` SET `Description`='Defeat No-No', `VerifiedBuild`=38134 WHERE `ID`=270133; -- 270133
UPDATE `quest_objectives` SET `Description`='Defeat Gorespine', `VerifiedBuild`=38134 WHERE `ID`=270132; -- 270132
UPDATE `quest_objectives` SET `Description`='Defeat Ka\'wi the Gorger', `VerifiedBuild`=38134 WHERE `ID`=270131; -- 270131
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=341733; -- 341733
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=337644; -- 337644
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=341372; -- 341372
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=339656; -- 339656
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=256637; -- 256637
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=252364; -- 252364
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=252185; -- 252185
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=252184; -- 252184
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=257822; -- 257822
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=257478; -- 257478
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=262331; -- 262331
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=265934; -- 265934
UPDATE `quest_objectives` SET `Description`='Mal\'Ganis Defeated', `VerifiedBuild`=38134 WHERE `ID`=264359; -- 264359
UPDATE `quest_objectives` SET `Description`='Fjorn\'s Anvil Brought to Dun Niffelem', `VerifiedBuild`=38134 WHERE `ID`=263960; -- 263960
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=263164; -- 263164
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=252245; -- 252245
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=252594; -- 252594
UPDATE `quest_objectives` SET `Description`='Statue Head Sketched', `VerifiedBuild`=38134 WHERE `ID`=258566; -- 258566
UPDATE `quest_objectives` SET `Description`='Statue Shoulder Sketched', `VerifiedBuild`=38134 WHERE `ID`=258565; -- 258565
UPDATE `quest_objectives` SET `Description`='Statue Arm Sketched', `VerifiedBuild`=38134 WHERE `ID`=258564; -- 258564
UPDATE `quest_objectives` SET `Description`='Statue Torso Sketched', `VerifiedBuild`=38134 WHERE `ID`=258563; -- 258563
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=264326; -- 264326
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=264325; -- 264325
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=264324; -- 264324
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=264323; -- 264323
UPDATE `quest_objectives` SET `Description`='Barrel of Honeybrew', `VerifiedBuild`=38134 WHERE `ID`=269318; -- 269318
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=269229; -- 269229
UPDATE `quest_objectives` SET `Description`='Speak with Mei', `VerifiedBuild`=38134 WHERE `ID`=252062; -- 252062
UPDATE `quest_objectives` SET `Description`='Speak with Yun', `VerifiedBuild`=38134 WHERE `ID`=252061; -- 252061
UPDATE `quest_objectives` SET `Description`='Speak with Sunni', `VerifiedBuild`=38134 WHERE `ID`=252060; -- 252060
UPDATE `quest_objectives` SET `Description`='Speak with Despondent Warden of Zhu', `VerifiedBuild`=38134 WHERE `ID`=252059; -- 252059
UPDATE `quest_objectives` SET `Description`='Ik\'thik mantid slain', `VerifiedBuild`=38134 WHERE `ID`=252176; -- 252176
UPDATE `quest_objectives` SET `Description`='Follow Chen and Li Li to Pang\'s Stead', `VerifiedBuild`=38134 WHERE `ID`=252227; -- 252227
UPDATE `quest_objectives` SET `Description`='Source of the destroyers found', `VerifiedBuild`=38134 WHERE `ID`=264219; -- 264219
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=264218; -- 264218
UPDATE `quest_objectives` SET `Description`='Shokia Rescued', `VerifiedBuild`=38134 WHERE `ID`=252616; -- 252616
UPDATE `quest_objectives` SET `Description`='Sergeant Gorrok Rescued', `VerifiedBuild`=38134 WHERE `ID`=252615; -- 252615
UPDATE `quest_objectives` SET `Description`='Rivett Clutchpop Rescued', `VerifiedBuild`=38134 WHERE `ID`=252614; -- 252614
UPDATE `quest_objectives` SET `Description`='Shademaster Kiryn Rescued', `VerifiedBuild`=38134 WHERE `ID`=252613; -- 252613
UPDATE `quest_objectives` SET `Description`='Speak with Mayor Honeydew', `VerifiedBuild`=38134 WHERE `ID`=269224; -- 269224
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=269144; -- 269144
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=269143; -- 269143
UPDATE `quest_objectives` SET `Description`='Find Captain Doren', `VerifiedBuild`=38134 WHERE `ID`=269206; -- 269206
UPDATE `quest_objectives` SET `Description`='Destroy the third barricade', `VerifiedBuild`=38134 WHERE `ID`=269205; -- 269205
UPDATE `quest_objectives` SET `Description`='Destroy the second barricade', `VerifiedBuild`=38134 WHERE `ID`=269204; -- 269204
UPDATE `quest_objectives` SET `Description`='Destroy the first barricade', `VerifiedBuild`=38134 WHERE `ID`=269203; -- 269203
UPDATE `quest_objectives` SET `Description`='Thunder Hold Munitions destroyed', `VerifiedBuild`=38134 WHERE `ID`=269103; -- 269103
UPDATE `quest_objectives` SET `Description`='Thunder Hold troops slain', `VerifiedBuild`=38134 WHERE `ID`=269102; -- 269102
UPDATE `quest_objectives` SET `Description`='Rappel into Honeydew Glade', `VerifiedBuild`=38134 WHERE `ID`=269231; -- 269231
UPDATE `quest_objectives` SET `Description`='Thunder Hold cannons destroyed', `VerifiedBuild`=38134 WHERE `ID`=269074; -- 269074
UPDATE `quest_objectives` SET `Description`='Thunder Hold troops slain', `VerifiedBuild`=38134 WHERE `ID`=269073; -- 269073
UPDATE `quest_objectives` SET `Description`='Discovered Pandaria', `VerifiedBuild`=38134 WHERE `ID`=264975; -- 264975
UPDATE `quest_objectives` SET `Description`='Runaway Shredder Captured', `VerifiedBuild`=38134 WHERE `ID`=266900; -- 266900


UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269036 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269036 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269036 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=268997 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=268997 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=268997 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=268997 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=268950 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334728 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=293261 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341733 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337644 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=258566 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=258565 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=258564 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=258563 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269318 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=252062 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=252061 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=252060 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=252059 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=252616 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=252615 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=252614 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=252613 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269224 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269205 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269205 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269204 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269204 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269203 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269203 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269103 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269231 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269074 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269074 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269074 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269073 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269073 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269073 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=264975 AND `Index`=0);


UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130689; -- Wandering Mouser
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65905; -- Strongarm Lieutenant
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=65906; -- Strongarm Laborer
UPDATE `creature_template` SET `unit_class`=4, `VerifiedBuild`=38134 WHERE `entry`=67032; -- Gunship Turret
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67038; -- Hellscream's Fist Engineer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67040; -- Hellscream's Fist Deckswabber
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129598; -- Freehold Pack Mule
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129599; -- Cutwater Knife Juggler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129600; -- Bilge Rat Brinescale
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129601; -- Cutwater Harpooner
UPDATE `creature_template` SET `type_flags2`=4194304, `VerifiedBuild`=38134 WHERE `entry`=129602; -- Irontide Enforcer
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `movementId`=100, `VerifiedBuild`=38134 WHERE `entry`=63715; -- Jumping Spider
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67071; -- Wary Forest Prowler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=77137; -- Dread Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=106181; -- Sunborne Val'kyr
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67090; -- Pandaren Volunteer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64856; -- Sky Master Corpora
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65974; -- Pandaren Volunteer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=61507; -- Zin'Jun's Left Hand
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129645; -- Gryff
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64867; -- Kor'kron Shin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64868; -- Kor'kron Dubs
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64869; -- Kor'kron Jo'mag
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64870; -- Kor'kron Spisak
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64871; -- Warbringer Ho'Gan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64872; -- Sky Marshal Schwind
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64873; -- Cannoneer Powell
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64874; -- Cannoneer Buczacki
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=44775; -- Generic Bunny - PRK (Large AOI)
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65998; -- Merchant Zin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65999; -- General Nazgrim
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=128551; -- Irontide Mastiff
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66000; -- Strongarm Ace
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=61535; -- Hozen Corpse
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129673; -- Stevin
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=67129; -- Rapelling Manfred
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67131; -- Hellscream's Vanguard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=59312; -- Grove Viper
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=67136; -- Exploding Manfred
UPDATE `creature_template` SET `family`=0, `type`=7, `VerifiedBuild`=38134 WHERE `entry`=129699; -- Ludwig Von Tortollan
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=36989; -- Spitelash Invader
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67153; -- Zin'Jun
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67158; -- Kor'kron Elite
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66052; -- Captain Doren
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=59357; -- Bucktooth Flapper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129732; -- Skycap'n Kragg
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130850; -- Irontide Cannon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=138676; -- Bilge Rat Party Animal
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136445; -- Captain Rez'okun
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129743; -- Sharkbait
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129747; -- Swiftwind Saber
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129758; -- Irontide Grenadier
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=138705; -- Gourmet Parrot Chow
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=138718; -- Sharkbait's Empty Dish
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129788; -- Irontide Bonesaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67250; -- Rivett Clutchpop
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67252; -- Shademaster Kiryn
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=38134 WHERE `entry`=63919; -- Leopard Tree Frog
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=136539; -- Booty Fanatic
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126497; -- Shiprat
UPDATE `creature_template` SET `unit_class`=4, `VerifiedBuild`=38134 WHERE `entry`=66183; -- Gunship Turret
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=109751; -- Lightsworn Anchorite
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66190; -- General Nazgrim
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66200; -- Thunder Hold Soldier
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126519; -- Tiragarde Gull
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=66202; -- Thunder Hold Laborer
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=38134 WHERE `entry`=66203; -- Thunder Hold Cannon
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=38134 WHERE `entry`=66210; -- Thunder Hold Explosive Barrel
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66214; -- Terrified Field Worker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66218; -- Lo Don
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66219; -- Kofa the Swift
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66220; -- Mayor Honeydew
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=62870; -- Rocket Jumpers Shoreline Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66222; -- Elder Muur
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66223; -- Elder Honeypaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55054; -- General Nazgrim
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66228; -- Tau Be
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66230; -- Su Mi
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66235; -- Fieldwatcher Mao
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66236; -- Brewmother Kiki
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66237; -- Kan the Spiritful
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66238; -- Herim Woo
UPDATE `creature_template` SET `KillCredit1`=0, `VerifiedBuild`=38134 WHERE `entry`=56198; -- Thicket Stalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=56199; -- Lightwing Hunter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66265; -- Lu Jon Sun
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65148; -- Shikyo
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=62930; -- Water Sprite
UPDATE `creature_template` SET `HealthModifier`=4, `VerifiedBuild`=38134 WHERE `entry`=66283; -- Captain Doren
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=66284; -- Thunder Hold Laborer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66285; -- Thunder Hold Infantryman
UPDATE `creature_template` SET `unit_class`=8, `VerifiedBuild`=38134 WHERE `entry`=66286; -- Thunder Hold Mender
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66287; -- Thunder Hold Lieutenant
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66288; -- Thunder Hold Sharp-Shooter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66291; -- Thunder Hold Soldier
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=103159; -- Baby Winston
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55135; -- General Nazgrim
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=131092; -- Bonfire Spawn (DNT)
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66307; -- Flame Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66308; -- Thunder Hold Munitions
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55141; -- Shademaster Kiryn
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55142; -- Shademaster Kiryn
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=61844; -- Rivett Clutchpop
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=61845; -- Hellscream's Vanguard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=61846; -- Gorrok
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55146; -- Rivett Clutchpop
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55149; -- Rivett Clutchpop
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=38134 WHERE `entry`=66320; -- Thunder Hold Explosive
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55162; -- Sergeant Gorrok
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=61866; -- Shokia
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=61867; -- Kiryn
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66336; -- Thunder Hold Fire Effects Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=61868; -- Zin'jun
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=61869; -- Snuff
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55169; -- Sergeant Gorrok
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55170; -- Shokia
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55171; -- Shokia
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55172; -- General Nazgrim
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130011; -- Irontide Buccaneer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=62992; -- Bucktooth Flapper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130012; -- Irontide Ravager
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=62994; -- Emerald Turtle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66346; -- Blacktalon Watcher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60761; -- Shore Crab
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66347; -- Blacktalon Agent
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66348; -- Thunder Hold Armsman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=119965; -- Doom Guard LT Stalker
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55180; -- Shademaster Kiryn
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=38134 WHERE `entry`=63003; -- Masked Tanuki
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=130024; -- Soggy Shiprat
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=38134 WHERE `entry`=63004; -- Grove Viper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=17213; -- Broom
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=59666; -- Emerald Turtle
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=38134 WHERE `entry`=66394; -- Thunder Hold Cannon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66395; -- Thunder Hold Cannoneer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130086; -- Davey "Two Eyes"
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130090; -- Gukguk "The Motivator"
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=66425; -- Sha Haunt
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66426; -- Sha Harbinger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130099; -- Lightning
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=6112; -- Windfury Totem
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66430; -- Ethan Graveborn
UPDATE `creature_template` SET `unit_class`=2, `VerifiedBuild`=38134 WHERE `entry`=66446; -- Thunder Hold Mender
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=10598; -- Smolderweb Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66477; -- Thunder Hold Cannon Fire Effects Bunny
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type_flags`=1611662336, `VerifiedBuild`=38134 WHERE `entry`=40789; -- Generic Controller Bunny (CSA)
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=66484; -- Thunder Hold Laborer
UPDATE `creature_template` SET `family`=7, `VerifiedBuild`=38134 WHERE `entry`=59782; -- Cypress Condor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130157; -- Shell Target
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130172; -- Ken "the Pig Thrower"
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66503; -- Thunder Hold Infantryman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66505; -- Thunder Hold Armsman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66506; -- Thunder Hold Cannoneer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66507; -- Thunder Hold Sharp-Shooter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127947; -- Blazehound
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=126832; -- Skycap'n Kragg
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=44180; -- Viper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126841; -- Sharkbait
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126845; -- Captain Jolly
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126847; -- Captain Raoul
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126848; -- Captain Eudora
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=129092; -- Hozen Hang Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=36384; -- Zapper Gnome
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=36385; -- Netgun Gnome
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55379; -- Torso Kill Credit Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55383; -- Arm Kill Credit Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66554; -- Alliance Barricade
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66555; -- Alliance Barricade
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66556; -- Alliance Barricade
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55388; -- Shoulder Kill Credit Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55392; -- Head Kill Credit Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66571; -- Barricade 1 Missile Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66572; -- Barricade 1 Explode Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55403; -- Zin'Jun
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55404; -- Zin'Jun's Eye Socket
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=38134 WHERE `entry`=66577; -- Barricade 2 Missile Bunny
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=38134 WHERE `entry`=62121; -- Turquoise Turtle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126918; -- Irontide Crackshot
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126919; -- Irontide Stormcaller
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126928; -- Irontide Corsair
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=25291; -- Librarian Garren
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=58811; -- Jade Snapping Turtle
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55463; -- Hozen Corpse Cluster
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66634; -- Hellscream's Vanguard
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55464; -- Hozen Corpse
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66640; -- Rappelling Rope
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55470; -- Hozen Groundpounder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66643; -- General Nazgrim
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66644; -- Taran Zhu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66646; -- General Nazgrim
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66647; -- Thunder Hold Sharp-Shooter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66648; -- Thunder Hold Lieutenant
UPDATE `creature_template` SET `unit_class`=8, `VerifiedBuild`=38134 WHERE `entry`=66649; -- Thunder Hold Mender
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66650; -- Thunder Hold Infantryman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126969; -- Trothak
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=66651; -- Thunder Hold Laborer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=91226; -- Graves
UPDATE `creature_template` SET `KillCredit1`=0, `VerifiedBuild`=38134 WHERE `entry`=66654; -- Thunder Hold Supplies
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66656; -- General Nazgrim
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66657; -- Taran Zhu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66659; -- Sue-Ji the Tender
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66660; -- Ellie Honeypaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66662; -- Gi-Oh
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=126983; -- Harlan Sweete
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66665; -- Taran Zhu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66667; -- Rivett Clutchpop
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55497; -- Zin'Jun
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66668; -- Sha-Infested Prowler
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=35396; -- Darting Hatchling
UPDATE `creature_template` SET `unit_class`=4, `VerifiedBuild`=38134 WHERE `entry`=66674; -- Gunship Turret
UPDATE `creature_template` SET `unit_class`=4, `VerifiedBuild`=38134 WHERE `entry`=66676; -- Gunship Turret
UPDATE `creature_template` SET `unit_class`=4, `VerifiedBuild`=38134 WHERE `entry`=66677; -- Gunship Turret
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66679; -- Shademaster Kiryn
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55509; -- Konk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66680; -- Rivett Clutchpop
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=38134 WHERE `entry`=66681; -- Sergeant Gorrok
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66682; -- General Nazgrim
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66683; -- Shokia
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66684; -- Merchant Zin
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135938; -- Bilge Rat Party Animal
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66688; -- Sha Tendrils
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55521; -- Rivett Clutchpop
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55522; -- Sergeant Gorrok
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55523; -- Shokia
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66694; -- General Nazgrim
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127019; -- Training Dummy
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=135978; -- Bilge Rat Grog Jerk
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55555; -- Hozen Mudflinger
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130400; -- Irontide Crusher
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=830; -- Sand Crawler
UPDATE `creature_template` SET `type_flags2`=4194304, `VerifiedBuild`=38134 WHERE `entry`=130404; -- Vermin Trapper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66742; -- Thunder Hold Fire Effects Bunny - Scorched Ground
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=66743; -- Doubt
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=38134 WHERE `entry`=61158; -- Shore Crab
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=29888; -- Herbalism Flower
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=90208; -- Hyjal Wisp
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=58943; -- Hozen Gutripper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=58945; -- Hozen Nibstabber
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=38134 WHERE `entry`=63420; -- SLG Generic MoP
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=86883; -- Raptor
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55610; -- Lurching Blossom
UPDATE `creature_template` SET `type_flags2`=4194304, `VerifiedBuild`=38134 WHERE `entry`=127106; -- Irontide Officer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55622; -- Dook Ookem
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=127111; -- Irontide Oarsman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66793; -- Hellscream's Fist Engineer
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66795; -- Gunship Fire Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66796; -- Captain Doren
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129350; -- Gurgthock
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66798; -- Doren's Gyrocopter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129352; -- Wodin the Troll-Servant
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=127119; -- Freehold Deckhand
UPDATE `creature_template` SET `rank`=1, `VerifiedBuild`=38134 WHERE `entry`=127124; -- Freehold Barhand
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129359; -- Sawtooth Shark
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=63467; -- Enraged Treant
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66825; -- Ellie Honeypaw
UPDATE `creature_template` SET `unit_class`=2, `VerifiedBuild`=38134 WHERE `entry`=66838; -- Kai-Lin Honeydew
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66840; -- Brew bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66841; -- Kai-Lin Honeydew
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=55674; -- Recovered Gyrocopter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66845; -- Sergeant Gorrok
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66847; -- Shokia
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66848; -- Ellie Honeypaw
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130521; -- Freehold Deckhand
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=130522; -- Freehold Shipmate
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66853; -- Kai-Lin Honeydew
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66857; -- Parachute Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66870; -- Gi-Oh
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66888; -- Thunder Hold Conversation Bunny
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=41200; -- Generic Bunny - PRK
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66896; -- Strongarm Gyrocopter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129448; -- Hammer Shark
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66897; -- Strongarm Gyrocopter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=60199; -- Rune of Power
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=61325; -- Adder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66911; -- Lorbu Sadsummon
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66915; -- Kor'kron Elite
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=38134 WHERE `entry`=66916; -- Hozen Dangler VEHICLE
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66917; -- Hozen Groundpounder
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66928; -- Sha Shooter
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=66948; -- Twisted Corpse
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=43499; -- Consecration
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65840; -- Strongarm Airman
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65841; -- Strongarm Private
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65842; -- Strongarm Medic
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65843; -- Strongarm Gyrocopter
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=66961; -- General Nazgrim
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=17817; -- Greater Bogstrok
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129526; -- Bilge Rat Swabby
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=138463; -- Whirlpool of Blades
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129527; -- Bilge Rat Buccaneer
UPDATE `creature_template` SET `rank`=6, `VerifiedBuild`=38134 WHERE `entry`=66976; -- Alebrain
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129529; -- Blacktooth Scrapper
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=170866; -- Orgrimmar Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129547; -- Blacktooth Knuckleduster
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64761; -- Jumping Spider
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129548; -- Blacktooth Brute
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65880; -- Morgus Grimhatchet
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65881; -- Corporal Jackson Silver
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129550; -- Bilge Rat Padfoot
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=65882; -- Master Engineer Cogswing
UPDATE `creature_template` SET `unit_class`=2, `VerifiedBuild`=38134 WHERE `entry`=65883; -- Gyro-Mechanic Lavenderp
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=134021; -- Revitalizing Brew
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67003; -- Taran Zhu
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=129559; -- Cutwater Duelist
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=38134 WHERE `entry`=64774; -- Leopard Tree Frog
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64775; -- Masked Tanuki
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=64776; -- Masked Tanuki Pup
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67016; -- Ancient Statue Torso
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67017; -- Ancient Statue Arm
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67018; -- Ancient Statue Head
UPDATE `creature_template` SET `VerifiedBuild`=38134 WHERE `entry`=67019; -- Ancient Statue Shoulder


UPDATE `creature_template_model` SET `Probability`=0.5 WHERE (`CreatureID`=126497 AND `Idx`=0); -- Shiprat


UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=38134 WHERE `entry`=186456; -- Blacksmith Smoke
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215764; -- Dark Fast Smoke
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215318; -- Archimonde Fire
UPDATE `gameobject_template` SET `ContentTuningId`=57, `VerifiedBuild`=38134 WHERE `entry`=212969; -- Incense Bundle
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=212193; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215882; -- Doren's Logs
UPDATE `gameobject_template` SET `name`='Alliance Banner', `VerifiedBuild`=38134 WHERE `entry`=215036; -- Alliance Banner
UPDATE `gameobject_template` SET `name`='Alliance Banner', `VerifiedBuild`=38134 WHERE `entry`=215031; -- Alliance Banner
UPDATE `gameobject_template` SET `ContentTuningId`=57, `VerifiedBuild`=38134 WHERE `entry`=215844; -- Flagpole
UPDATE `gameobject_template` SET `ContentTuningId`=328, `VerifiedBuild`=38134 WHERE `entry`=204100; -- Snake Trap
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214864; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214791; -- Campfire
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `Data1`=0, `Data30`=43475, `ContentTuningId`=57, `VerifiedBuild`=38134 WHERE `entry`=214962; -- Requisitioned Firework Launcher
UPDATE `gameobject_template` SET `type`=8, `Data0`=5705760, `Data2`=5614196, `Data4`=5705884, `VerifiedBuild`=38134 WHERE `entry`=212325; -- Doodad_hz_camp_fire_001
UPDATE `gameobject_template` SET `Data21`=0, `VerifiedBuild`=38134 WHERE `entry`=288636; -- Council's Tribute
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302893; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302884; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302882; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=226773; -- Table
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=226771; -- Iron Bars
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=226770; -- Blacksmithing Tub
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=226769; -- Copper Bars
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=225568; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=225567; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=226772; -- Silver Bars
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295778; -- Fire
UPDATE `gameobject_template` SET `ContentTuningId`=482, `VerifiedBuild`=38134 WHERE `entry`=207387; -- Refreshment Table
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302899; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302891; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302888; -- Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278415; -- Invisible Platform
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278291; -- Outlaw Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302892; -- Campfire
UPDATE `gameobject_template` SET `name`='Alliance Banner', `VerifiedBuild`=38134 WHERE `entry`=215033; -- Alliance Banner
UPDATE `gameobject_template` SET `name`='Alliance Banner', `VerifiedBuild`=38134 WHERE `entry`=215037; -- Alliance Banner
UPDATE `gameobject_template` SET `name`='Alliance Banner', `VerifiedBuild`=38134 WHERE `entry`=215034; -- Alliance Banner
UPDATE `gameobject_template` SET `name`='Alliance Banner', `VerifiedBuild`=38134 WHERE `entry`=215032; -- Alliance Banner
UPDATE `gameobject_template` SET `name`='Alliance Banner', `VerifiedBuild`=38134 WHERE `entry`=215035; -- Alliance Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214723; -- Campfire
UPDATE `gameobject_template` SET `name`='Alliance Banner', `VerifiedBuild`=38134 WHERE `entry`=215038; -- Alliance Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215845; -- Alliance Flag
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=219095; -- Mogu Statue Feet - Collision
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215709; -- Rock
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215702; -- Tree Branch
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215691; -- Wagon Piece
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215690; -- Wagon
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214567; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214566; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215756; -- Brew Cart
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214894; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214893; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214570; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=212625; -- Bed
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=212623; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=212621; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=210804; -- Portal to Orgrimmar
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214988; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=212624; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=212622; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=216302; -- Stove
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214569; -- Stool
UPDATE `gameobject_template` SET `size`=17.73905181884765625, `Data0`=0, `Data1`=0, `Data3`=3000, `Data9`=2, `Data13`=1, `Data17`=1, `Data19`=13126, `VerifiedBuild`=38134 WHERE `entry`=212184; -- Ancient Statue Shoulder
UPDATE `gameobject_template` SET `size`=18.90002250671386718, `Data0`=0, `Data1`=0, `Data3`=3000, `Data9`=2, `Data13`=1, `Data17`=1, `Data19`=13127, `VerifiedBuild`=38134 WHERE `entry`=212186; -- Ancient Statue Head
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=214568; -- Stool
UPDATE `gameobject_template` SET `Data4`=0, `VerifiedBuild`=38134 WHERE `entry`=216301; -- Stove
UPDATE `gameobject_template` SET `Data0`=0, `Data1`=0, `Data3`=3000, `Data9`=2, `Data13`=1, `Data17`=1, `Data19`=13125, `VerifiedBuild`=38134 WHERE `entry`=212183; -- Ancient Statue Arm
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215694; -- Barricade Supports - Burning
UPDATE `gameobject_template` SET `Data26`=1, `ContentTuningId`=57, `VerifiedBuild`=38134 WHERE `entry`=215695; -- Barrel of Honeybrew
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215692; -- Honeybrew Barrel Broken
UPDATE `gameobject_template` SET `size`=7.690011501312255859, `Data0`=0, `Data1`=16627, `Data2`=2, `Data3`=0, `Data8`=1, `Data9`=1, `VerifiedBuild`=38134 WHERE `entry`=212181; -- Ancient Statue
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215693; -- Barricade Supports - Burning
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215859; -- Sha GroundPatch Small Tendrils
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215860; -- Sha GroundPatch Med Tendrils
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215564; -- Jade Forest Horde Ship Cosmetic
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215563; -- Jade Forest Horde Ship Cosmetic
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215562; -- Jade Forest Horde Ship Cosmetic
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215423; -- Jade Forest Alliance Ship Cosmetic
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215422; -- Jade Forest Alliance Ship Cosmetic
UPDATE `gameobject_template` SET `type`=50, `IconName`='', `Data0`=2859, `Data1`=40327, `Data3`=0, `Data4`=25, `Data5`=50, `Data6`=30, `Data12`=680, `Data13`=1, `Data18`=10, `Data19`=0, `Data23`=0, `Data24`=0, `VerifiedBuild`=38134 WHERE `entry`=209353; -- Rain Poppy
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215646; -- Barricade
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215647; -- Barricade
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215650; -- Thunder Hold Explosives
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215649; -- Thunder Hold Munitions
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215681; -- Barricade
UPDATE `gameobject_template` SET `name`='Water Barrel', `VerifiedBuild`=38134 WHERE `entry`=215641; -- Water Barrel
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215588; -- Damaged Thunder Hold Cannon
UPDATE `gameobject_template` SET `name`='Horde Supplies', `VerifiedBuild`=38134 WHERE `entry`=215688; -- Horde Supplies
UPDATE `gameobject_template` SET `name`='Horde Supplies', `VerifiedBuild`=38134 WHERE `entry`=215685; -- Horde Supplies
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215967; -- Stack of Cannonballs
UPDATE `gameobject_template` SET `type`=50, `IconName`='', `Data0`=2859, `Data3`=0, `Data5`=25, `Data6`=30, `Data12`=683, `Data13`=1, `Data18`=10, `Data19`=0, `Data23`=0, `Data24`=0, `VerifiedBuild`=38134 WHERE `entry`=209349; -- Green Tea Leaf
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=200296; -- Washing Tub
UPDATE `gameobject_template` SET `type`=50, `Data0`=2867, `Data1`=40258, `Data3`=0, `Data4`=25, `Data5`=75, `Data6`=30, `Data12`=680, `Data13`=1, `Data18`=10, `Data19`=0, `Data23`=0, `Data24`=0, `VerifiedBuild`=38134 WHERE `entry`=209311; -- Ghost Iron Deposit
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215766; -- Gunship Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215689; -- Rappelling Rope
UPDATE `gameobject_template` SET `Data1`=42522, `VerifiedBuild`=38134 WHERE `entry`=212171; -- Jade Lungfish School
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215686; -- Horde Supplies
UPDATE `gameobject_template` SET `Data0`=0, `Data1`=0, `Data3`=3000, `Data9`=2, `Data13`=1, `Data17`=1, `Data19`=13123, `Data22`=12861, `VerifiedBuild`=38134 WHERE `entry`=212182; -- Ancient Statue Torso
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215767; -- Horde Gunship Portal Effects
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215683; -- Horde Barricade
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215687; -- Barricade Supports
UPDATE `gameobject_template` SET `name`='Hellscream\'s Fist Alarm', `VerifiedBuild`=38134 WHERE `entry`=215711; -- Hellscream's Fist Alarm
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=215684; -- Horde Supplies
UPDATE `gameobject_template` SET `name`='Hellscream\'s Fist Fuel Cell', `VerifiedBuild`=38134 WHERE `entry`=215718; -- Hellscream's Fist Fuel Cell
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=191640; -- Anvil
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=38134 WHERE `entry`=195638; -- Goblin Mortar
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=207889; -- Doodad_Goblin_elevator01
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=204246; -- Doodad_Goblin_elevator01
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=196837; -- Doodad_Goblin_PoolElevator01
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=204243; -- Doodad_Goblin_elevator01
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=196475; -- Secret Lab Archives
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=38134 WHERE `entry`=195639; -- Goblin Mortar
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=190942; -- Death Gate


UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=214962 AND `Idx`=0); -- Requisitioned Firework Launcher

DELETE FROM `page_text` WHERE `ID` IN (4679 /*4679*/, 4678 /*4678*/, 4677 /*4677*/, 4676 /*4676*/, 4675 /*4675*/, 4674 /*4674*/, 4673 /*4673*/);
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(4679, 'Day 14$b$bWoke up to news of a signal flare from off the coast. There\'s a shadow moving through the fog. A horde gunship?$b$bI\'ve dispatched a messenger to scramble the gyrocopters. They may not get here in time. Ordering everyone to the guns. This is it.$b$bI feel overpowered with anger and dread. I am not myself. Perhaps in victory I will find solace?$b$bIf it is truly a single Horde airship, then they stand no chance. We will decimate them.', 0, 0, 0, 38134), -- 4679
(4678, 'Day 12$b$bEvery day I scan the horizon for Horde airships. We are not ready. Our airbase is in shambles, with a half-complete tower. Some pandaren have offered to help, and I\'ve drafted them.$b$bYears ago, I once hunted down Colonel Kurzen when madness overtook him in Stranglethorn. I never understood his spiral into darkness until now. I am alone. At night I lie awake in the oppressive heat, and swear the shadows are whispering to me of my own demise. Must get that airbase finished. I\'ll clap the pandaren in manacles if I have to. The Horde... The Horde...', 4679, 0, 0, 38134), -- 4678
(4677, 'Day 9$b$bThe Skyseeker reported that it picked up Horde prisoners from an engagement at sea this morning, then suddenly fell silent. I fear the worst.$b$bActually, I fear a lot of things. We\'re alone here. Reinforcements from Stormwind are weeks away. Taylor\'s flagship is missing, and now the Skyseeker is silent. Are we losing the war at sea? Doubts churn within me. I can\'t think straight. I swear my skin is losing color. What is wrong with me?', 4678, 0, 0, 38134), -- 4677
(4676, 'Day 7$b$bThe pandaren are full of questions, but no help at all. I admit I\'m feeling immensely uneasy, and I can\'t put my finger on why. It seems like all of my doubts are magnified here. The Horde will come back; I am certain of it. How many will come? Will they come by sea or by air? I must be ready!$b$bThe men are working double-time with half rations. The pandaren have offered food in trade but are not interested in Stormwind promissory notes and laugh at the quality of our steel. For some reason, this makes me furious. Do they know that they are about to be in the middle of a battlefield?', 4677, 0, 0, 38134), -- 4676
(4675, 'Day 5$b$bThe Skyseeker has left behind a full complement of gyrocopters to help us construct a base. My men have claimed a series of abandoned ruins as a stronghold. The ruins and surrounding jungle are too dangerous for air traffic, we\'ve been using some clearings to the south as a temporary airbase.$b$bThis morning we made our first contact with the natives. They are pandaren! I didn\'t think they were real. Could this be some sort of mythical pandaren homeland?', 4676, 0, 0, 38134), -- 4675
(4674, 'Day 2$b$bThe Skyseeker has arrived and dispatched its gyrocopters. This is no mere uncharted island - we have discovered an entire continent! I will begin shuttling men and materials up the cliff walls immediately. From this higher ground, we will have a commanding view of the nearby seas.$b$bCommunication among the fleet is sporadic and confusing. The Horde seems to be everywhere at once; we have lost contact with Admiral Taylor\'s flagship, which likely engaged the Horde fleet we thumped a couple of days ago. Light help him; they were out or blood.$b$bWith no news from Stormwind, I am going to take the initiative and secure this land.', 4675, 0, 0, 38134), -- 4674
(4673, 'Landfall!$b$bWe engaged a Horde fleet many times our number in a series of sporadic encounters throughout the night. Our losses were high, but we gave more than we got. We took advantage of a dense fog that cloaked our movements; no doubt they thought our numbers were much greater, hence they fled southeast by morning light.$b$bWe were astounded to discover a great cliff wall as the fog burned away. Land! It\'s not on any of our charts. I\'ve messaged the Skyseeker in order to arrange for air support.', 4674, 0, 0, 38134); -- 4673


DELETE FROM `npc_text` WHERE `ID`=21407;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(21407, 1, 0, 0, 0, 0, 0, 0, 0, 68131, 0, 0, 0, 0, 0, 0, 0, 38134); -- 21407

