SET @CGUID := 21003519;
SET @OGUID := 21001371;

DELETE FROM `areatrigger_template` WHERE `Id` IN (13676, 13674, 14675, 13657, 11577, 16670, 13627, 14704, 14699, 14930, 14722, 14929, 14928, 13568, 16555, 13559, 16059, 15205, 15814, 14971);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(13676, 3, 0, 0, 0, 0, 0, 0, 0, 25961),
(13674, 4, 0, 3, 3, 150, 150, 50, 50, 25961),
(14675, 0, 2, 2, 2, 0, 0, 0, 0, 25961),
(13657, 0, 0, 6, 6, 0, 0, 0, 0, 25961),
(11577, 0, 4, 8, 8, 0, 0, 0, 0, 25961),
(16670, 0, 0, 3, 3, 0, 0, 0, 0, 25961),
(13627, 3, 0, 0, 0, 0, 0, 0, 0, 25961),
(14704, 0, 0, 2, 2, 0, 0, 0, 0, 25961),
(14699, 0, 0, 8, 8, 0, 0, 0, 0, 25961),
(14930, 0, 0, 2, 2, 0, 0, 0, 0, 25961),
(14722, 0, 0, 8, 8, 0, 0, 0, 0, 25961),
(14929, 0, 0, 3, 3, 0, 0, 0, 0, 25961),
(14928, 0, 0, 4, 4, 0, 0, 0, 0, 25961),
(13568, 3, 66, 0, 0, 0, 0, 0, 0, 25961),
(16555, 0, 16, 3, 3, 0, 0, 0, 0, 25961),
(13559, 3, 66, 0, 0, 0, 0, 0, 0, 25961),
(16059, 0, 896, 1.5, 1.5, 0, 0, 0, 0, 25961),
(15205, 4, 4, 1.5, 1.5, 3, 3, 0.3, 0.3, 25961),
(15814, 0, 4, 5, 5, 0, 0, 0, 0, 25961),
(14971, 0, 4, 1.5, 1.5, 0, 0, 0, 0, 25961);

UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=6211;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=8089;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=12929;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=5972;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=13436;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=11231;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=9736 AND `AreaTriggerId`=13676) OR (`AreaTriggerId`=13674) OR (`AreaTriggerId`=14675) OR (`SpellMiscId`=9693 AND `AreaTriggerId`=13657) OR (`AreaTriggerId`=5300) OR (`AreaTriggerId`=5302) OR (`SpellMiscId`=9449 AND `AreaTriggerId`=13436) OR (`SpellMiscId`=7108 AND `AreaTriggerId`=11577) OR (`AreaTriggerId`=16670) OR (`SpellMiscId`=9649 AND `AreaTriggerId`=13627) OR (`SpellMiscId`=9785 AND `AreaTriggerId`=14704) OR (`SpellMiscId`=9777 AND `AreaTriggerId`=14699) OR (`SpellMiscId`=10047 AND `AreaTriggerId`=14930) OR (`SpellMiscId`=9807 AND `AreaTriggerId`=14722) OR (`SpellMiscId`=10046 AND `AreaTriggerId`=14929) OR (`SpellMiscId`=10045 AND `AreaTriggerId`=14928) OR (`SpellMiscId`=9584 AND `AreaTriggerId`=13568) OR (`AreaTriggerId`=16555) OR (`SpellMiscId`=9568 AND `AreaTriggerId`=13559) OR (`SpellMiscId`=9583 AND `AreaTriggerId`=13568) OR (`SpellMiscId`=11284 AND `AreaTriggerId`=16059) OR (`SpellMiscId`=10335 AND `AreaTriggerId`=15205) OR (`SpellMiscId`=11007 AND `AreaTriggerId`=15814) OR (`SpellMiscId`=10097 AND `AreaTriggerId`=14971);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(9736, 13676, 0, 0, 0, 0, 164, 0, 20000, 25961), -- SpellId : 235989
-- (UNKNOWN, 13674, 0, 0, 0, 0, 0, 10000, 10000, 25961), -- SpellId : 235927
-- (UNKNOWN, 14675, 0, 2691, 0, 0, 105, 0, 30000, 25961), -- SpellId : 236235
(9693, 13657, 0, 0, 0, 0, 0, 0, 90000, 25961), -- SpellId : 235890
(1315, 5300, 392, 0, 0, 0, 0, 1550, 1000, 25961), -- SpellId : 123986
(1316, 5302, 393, 0, 0, 0, 0, 1550, 1000, 25961), -- SpellId : 123986
(9449, 13436, 0, 0, 0, 0, 0, 0, 6000, 25961), -- SpellId : 233487
(7108, 11577, 0, 0, 0, 0, 0, 0, 0, 25961), -- SpellId : 196935
-- (UNKNOWN, 16670, 0, 0, 0, 0, 0, 3111, 6000, 25961), -- SpellId : 256948
(9649, 13627, 0, 0, 0, 0, 0, 0, 0, 25961), -- SpellId : 235401
(9785, 14704, 0, 0, 0, 0, 0, 1067, 12000, 25961), -- SpellId : 236529
(9777, 14699, 0, 0, 0, 0, 0, 0, 12000, 25961), -- SpellId : 236442
(10047, 14930, 2778, 0, 0, 0, 0, 4386, 12000, 25961), -- SpellId : 239386
(9807, 14722, 0, 0, 0, 0, 0, 0, 0, 25961), -- SpellId : 236726
(10046, 14929, 2777, 0, 0, 0, 0, 3436, 12000, 25961), -- SpellId : 239383
(10045, 14928, 0, 0, 0, 0, 0, 3111, 12000, 25961), -- SpellId : 239379
(9584, 13568, 0, 0, 2641, 0, 0, 0, 54000, 25961), -- SpellId : 234659
-- (UNKNOWN, 16555, 0, 0, 0, 0, 0, 469, 2500, 25961), -- SpellId : 251947
(9568, 13559, 0, 0, 2639, 0, 0, 0, 54000, 25961), -- SpellId : 234565
(9583, 13568, 0, 0, 2642, 0, 0, 0, 54000, 25961), -- SpellId : 234657
(11284, 16059, 0, 0, 0, 0, 0, 0, 0, 25961), -- SpellId : 236357
(10335, 15205, 0, 0, 0, 0, 0, 0, 0, 25961), -- SpellId : 241604
(11007, 15814, 0, 0, 0, 0, 0, 0, 10000, 25961), -- SpellId : 243292
(10097, 14971, 0, 0, 0, 0, 0, 0, 0, 25961); -- SpellId : 239638

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=7267 AND `AreaTriggerId`=11721); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6539 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5000, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=6006 AND `AreaTriggerId`=10698); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=11883 AND `AreaTriggerId`=16572); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=1712 AND `AreaTriggerId`=6211); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=56349, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=3467 AND `AreaTriggerId`=8089); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1429, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=15592, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=15694, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=11744 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8284 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6026 AND `AreaTriggerId`=10713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=9034 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2126 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5030 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=56132, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2312, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2057 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=1524 AND `AreaTriggerId`=5972); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8000 WHERE (`SpellMiscId`=6615 AND `AreaTriggerId`=11203); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4070 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2935, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1661 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2785, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2674 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10435 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7045 WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2263, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=377, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2657 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6878 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2844, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1432, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1431, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1433, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2839, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=2329 AND `AreaTriggerId`=6870); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3366, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=11519 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1700 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3815, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=555, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=992, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=815, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1542, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1080, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1456, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1086, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1391, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1210, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2062, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1448, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1449, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1554, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2024, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1527, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1566, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1574, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1387, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1118, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1015, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1659, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3255, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1358, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1271, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=360, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1558, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1466, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1175, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1353, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1172, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1442, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1446, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1447, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1441, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1444, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1436, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1437, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1435, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1439, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1365, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=714, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=536, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1667 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1096, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1415, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1179, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1193, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1103, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1084, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=810, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2869, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1519, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1537, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1518, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1530, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1493, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1517, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1278, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=216, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3759, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2744, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=363, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3228, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1332, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=446, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1340, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3189, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1339, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1161, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1824, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=511, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3191, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8352 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2139 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1524, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=197, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3959, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2863, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1430, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1251, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1480, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1468, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1434, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1438, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1451, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1459, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1462, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2891, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2817, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1046, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1452, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=241, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1440, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3835, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1511, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2816, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1575, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2901, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2809, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=454, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10224 AND `AreaTriggerId`=15099); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10227 AND `AreaTriggerId`=15099); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10450 AND `AreaTriggerId`=15307); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2174, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1635 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=52, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2376, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8179 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=468, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2582, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2919, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10234 AND `AreaTriggerId`=15099); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1811, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2077 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=154, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2621, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=6659 AND `AreaTriggerId`=11231); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=90000 WHERE (`SpellMiscId`=7478 AND `AreaTriggerId`=11908); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1629 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1892, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=70, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10235 AND `AreaTriggerId`=15099); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10279 AND `AreaTriggerId`=15152); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10225 AND `AreaTriggerId`=15099); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=5014 AND `Idx`=0) OR (`ConversationId`=5016 AND `Idx`=0) OR (`ConversationId`=5015 AND `Idx`=0) OR (`ConversationId`=5002 AND `Idx`=1) OR (`ConversationId`=5002 AND `Idx`=0) OR (`ConversationId`=5013 AND `Idx`=2) OR (`ConversationId`=5013 AND `Idx`=1) OR (`ConversationId`=5013 AND `Idx`=0) OR (`ConversationId`=5004 AND `Idx`=1) OR (`ConversationId`=5004 AND `Idx`=0) OR (`ConversationId`=5027 AND `Idx`=2) OR (`ConversationId`=5027 AND `Idx`=1) OR (`ConversationId`=5027 AND `Idx`=0) OR (`ConversationId`=4809 AND `ConversationActorId`=57712 AND `Idx`=0) OR (`ConversationId`=4811 AND `ConversationActorId`=57712 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
-- (5014, UNKNOWN, 0, 25961), -- Full: 0x203CCCD180739980003116000079A701 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 118374 (Captain Yathae Moonstrike) Low: 7972609
-- (5016, UNKNOWN, 0, 25961), -- Full: 0x203CCCD18073BD80003116000079A701 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 118518 (Priestess Lunaspyre) Low: 7972609
-- (5015, UNKNOWN, 0, 25961), -- Full: 0x203CCCD18073BD80003116000079A701 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 118518 (Priestess Lunaspyre) Low: 7972609
-- (5002, UNKNOWN, 1, 25961), -- Full: 0x203CCCD18071F4C0003116000079A701 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 116691 (Belac) Low: 7972609
-- (5002, UNKNOWN, 0, 25961), -- Full: 0x203CCCD18071F440003116000079A700 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 116689 (Atrigan) Low: 7972608
-- (5013, UNKNOWN, 2, 25961), -- Full: 0x203CCCD180739980003116000079A701 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 118374 (Captain Yathae Moonstrike) Low: 7972609
-- (5013, UNKNOWN, 1, 25961), -- Full: 0x203CCCD18073BD80003116000079A701 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 118518 (Priestess Lunaspyre) Low: 7972609
-- (5013, UNKNOWN, 0, 25961), -- Full: 0x203CCCD18073BEC0003116000079A701 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 118523 (Huntress Kasparian) Low: 7972609
-- (5004, UNKNOWN, 1, 25961), -- Full: 0x203CCCD18071F440003116000079A700 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 116689 (Atrigan) Low: 7972608
-- (5004, UNKNOWN, 0, 25961), -- Full: 0x203CCCD18071F4C0003116000079A701 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 116691 (Belac) Low: 7972609
-- (5027, UNKNOWN, 2, 25961), -- Full: 0x203CCCD18073BEC0003116000079A701 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 118523 (Huntress Kasparian) Low: 7972609
-- (5027, UNKNOWN, 1, 25961), -- Full: 0x203CCCD180739980003116000079A701 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 118374 (Captain Yathae Moonstrike) Low: 7972609
-- (5027, UNKNOWN, 0, 25961), -- Full: 0x203CCCD18073BD80003116000079A701 Creature/0 R3891/S12566 Map: Tombe de Sargeras Entry: 118518 (Priestess Lunaspyre) Low: 7972609
(4809, 57712, 0, 25961),
(4811, 57712, 0, 25961);


DELETE FROM `conversation_line_template` WHERE `Id` IN (11184, 11188, 11187, 11152, 11151, 11150, 11149, 11183, 11182, 11181, 11158, 11157, 11222, 11223, 11221, 10733, 10735);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(11184, 0, 0, 0, 0, 25961),
(11188, 0, 3502189392, 0, 0, 25961),
(11187, 0, 0, 0, 0, 25961),
(11152, 31375, 0, 1, 0, 25961),
(11151, 19833, 0, 0, 0, 25961),
(11150, 8730, 0, 1, 0, 25961),
(11149, 0, 0, 0, 0, 25961),
(11183, 5463, 0, 2, 0, 25961),
(11182, 2894, 0, 1, 0, 25961),
(11181, 0, 0, 0, 0, 25961),
(11158, 8200, 1065353216, 1, 0, 25961),
(11157, 0, 1065353216, 0, 0, 25961),
(11222, 14459, 35, 2, 0, 25961),
(11223, 6223, 35, 1, 0, 25961),
(11221, 0, 35, 0, 0, 25961),
(10733, 0, 84, 0, 0, 25961),
(10735, 0, 84, 0, 0, 25961);


DELETE FROM `conversation_template` WHERE `Id` IN (4811, 5027, 5016, 5015, 5014, 5013, 4809, 5004, 5002);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(4811, 10735, 11718, 25961),
(5027, 11221, 20015, 25961),
(5016, 11188, 2920, 25961),
(5015, 11187, 2902, 25961),
(5014, 11184, 4480, 25961),
(5013, 11181, 8558, 25961),
(4809, 10733, 13710, 25961),
(5004, 11157, 14853, 25961),
(5002, 11149, 39218, 25961);


DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+429;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 92879, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6221.518, -795.743, 2974.679, 3.079738, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- SLG Generic Stalker (Gigantic AOI) (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+1, 121719, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6249.782, -795.6927, 2894.346, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Thal'kiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+2, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6151.452, -816.3941, 2971.452, 3.730094, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+3, 118022, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6141.421, -810.4236, 2971.627, 3.028565, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Infernal Chaosbringer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 242907 - Infernal (cosmétique))
(@CGUID+4, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6149.361, -821.4358, 2971.45, 5.084475, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+5, 121473, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6377.634, -812.8768, 3011.711, 1.840931, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Coercitor Nixa (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+6, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6137.22, -789.6702, 2971.804, 2.884756, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+7, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6151.604, -777.7604, 2971.454, 3.033364, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+8, 116689, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6424.464, -789.5052, 3011.711, 4.166087, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Atrigan (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 233423 - Faux d'os)
(@CGUID+9, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6141.419, -809.5018, 2971.627, 3.033364, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+10, 116691, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6422.076, -803.1094, 3011.711, 1.879828, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Belac (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+11, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6276.54, -796.0261, 2894.346, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+12, 45396, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6227.654, -804.2136, 2978.831, 2.747211, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI) (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 243149 -)
(@CGUID+13, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6170.205, -862.4809, 2923.872, 3.615596, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+14, 121630, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6227.654, -804.2136, 2981.715, 2.747211, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegis of Aggramar (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 154441 - Shadowy Ghost Cosmetic Spawn Spell)
(@CGUID+15, 121399, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6380.255, -806.7257, 3011.711, 3.709481, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Inquisitor Sebilus (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+16, 121400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6387.185, -814.6511, 3011.711, 2.657171, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Accusator Gnazh (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+17, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6156.383, -850.0938, 2923.872, 1.380585, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+18, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6132.11, -833.8403, 2971.622, 4.409331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+19, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6140.382, -856.8889, 2923.872, 1.306865, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+20, 122850, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6143.273, -869.618, 2923.226, 1.897053, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+21, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6112.878, -824.1702, 2971.907, 4.409331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+22, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6136.415, -855.5486, 2923.872, 1.096434, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+23, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6149.483, -854.2518, 2923.872, 2.396769, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+24, 122850, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6151.783, -866.1771, 2923.226, 1.971343, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+25, 120191, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6271.156, -977.4448, 2915.272, 2.279288, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Soulguard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+26, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6167.551, -860.809, 2923.872, 5.540995, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+27, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6113.519, -764.0191, 2971.627, 4.409331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+28, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6149.563, -868.1059, 2923.226, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240704 - Piège d'Aegwynn)
(@CGUID+29, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6131.063, -787.533, 2971.804, 5.616508, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+30, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6154.952, -882.7136, 2923.872, 1.74604, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+31, 120721, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6147.557, -867.8264, 2923.226, 1.924976, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+32, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6128.159, -764.9114, 2971.627, 3.727708, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+33, 117957, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6404.359, -934.3472, 3037.268, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tormented Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235305 - Prisonnier de la Légion)
(@CGUID+34, 120721, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6155.329, -865.2986, 2923.226, 1.904977, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+35, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6158.136, -848.882, 2923.872, 3.15077, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+36, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6151.534, -850.2239, 2923.872, 2.668225, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+37, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6113.585, -758.1024, 2971.627, 3.033364, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+38, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6125.111, -835.6042, 2971.626, 3.502233, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+39, 120789, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6146.792, -860.342, 2923.226, 5.017231, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lieutenant Silvermight (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+40, 118022, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6105.339, -782.0955, 2971.804, 3.302948, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Infernal Chaosbringer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 242984 - Aura d'immolation)
(@CGUID+41, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6098.388, -767.7761, 2971.804, 1.077174, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+42, 120182, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6291.217, -988.7639, 2910.594, 5.891399, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tormented Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+43, 120182, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6293.542, -985.8212, 2910.594, 5.494672, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tormented Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+44, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6190.855, -942.5816, 2892.158, 0.7219808, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+45, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6133.352, -876.3629, 2923.872, 2.777948, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+46, 120191, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6271.014, -981.5576, 2915.237, 4.086969, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Soulguard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+47, 119726, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6102.056, -803.9063, 2971.804, 5.683074, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Archmage Khadgar (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+48, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6193.093, -940.8438, 2892.177, 4.352847, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+49, 120182, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6271.519, -979.9467, 2915.075, 3.088653, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tormented Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+50, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6192.767, -943.5382, 2892.165, 1.685661, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+51, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6087.649, -758.2188, 2971.627, 1.568148, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+52, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6079.385, -818.9132, 2972.021, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+53, 119730, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6099.86, -823.75, 2971.804, 4.753371, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Maiev Shadowsong (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+54, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6101.764, -761.4219, 2971.804, 5.664975, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+55, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6131.198, -877.2361, 2923.872, 0.8344312, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+56, 118022, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6101.035, -847.467, 2971.804, 2.591949, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Infernal Chaosbringer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 242984 - Aura d'immolation)
(@CGUID+57, 119728, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6099.269, -795.8733, 2971.804, 6.25553, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Prophète Velen (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241186 - Egide de Lumière)
(@CGUID+58, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6089.397, -768.8021, 2971.804, 0.597248, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+59, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6130.702, -873.9913, 2923.872, 6.014011, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+60, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6231.766, -1003.892, 2923.65, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240825 - Piège d'Aegwynn)
(@CGUID+61, 120191, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6324.049, -1018.641, 2904.034, 1.4324, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Soulguard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+62, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6066.076, -790.1077, 2971.804, 0.9533232, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+63, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6288.424, -1022.697, 2909.756, 4.338016, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+64, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6060.458, -798.6788, 2971.804, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+65, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6204.583, -999.8577, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+66, 120191, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6316.772, -1020.788, 2904.034, 1.1246, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Soulguard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+67, 120191, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6311.22, -1016.401, 2904.034, 0.8105693, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Soulguard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+68, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6198.986, -996.7552, 2899.552, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+69, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6058.344, -829.9254, 2971.448, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+70, 119729, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6075.905, -767.0156, 2971.627, 2.889694, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Illidan Hurlorage (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+71, 121030, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6224.827, -1005.219, 2923.85, 3.327119, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fan'verg the Vicious (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241309 - Planer)
(@CGUID+72, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6060.813, -812.9688, 2971.627, 5.866366, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+73, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6208.688, -1004.262, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+74, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6192.613, -995.5, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+75, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6055.779, -800.1649, 2971.804, 6.131253, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+76, 120191, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6311.675, -1010.502, 2904.032, 0.6032822, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Soulguard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+77, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6069.898, -823.0643, 2971.627, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+78, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6063.499, -802.3073, 2971.804, 2.092449, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+79, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6212.21, -1009.979, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+80, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6051.967, -808.8403, 2971.45, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+81, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6186.337, -996.3264, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+82, 118374, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6215.127, -1019.958, 2899.552, 2.668253, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Captain Yathae Moonstrike (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235268 - Fantôme lunaire)
(@CGUID+83, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6180.156, -998.1163, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+84, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6111.198, -966.882, 2959.924, 3.424741, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+85, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6174.642, -1001.651, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+86, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6125.58, -982.1528, 2959.939, 2.691881, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+87, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6287.172, -1040.937, 2911.846, 4.277407, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+88, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6289.65, -1048.563, 2911.444, 4.10897, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+89, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6043.811, -822.1858, 2971.456, 0.491619, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+90, 120191, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6302.858, -1030.877, 2904.046, 4.004122, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Soulguard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+91, 120201, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6302.695, -1035.115, 2903.76, 4.085153, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spectral Guardian (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 244081 - Aura chatoyante)
(@CGUID+92, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6307.847, -1040.227, 2909.733, 3.957239, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+93, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6214.527, -1022.04, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+94, 120191, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6307.694, -1038.421, 2903.76, 4.091042, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Soulguard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+95, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6214.443, -1015.403, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+96, 120191, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6305.022, -1036.94, 2903.76, 4.125122, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Soulguard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+97, 120194, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6299.819, -1035.613, 2904.046, 1.100638, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghostly Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+98, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6306.838, -1046.088, 2910.151, 3.985336, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+99, 120182, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6349.061, -1031.299, 2910.594, 2.188382, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tormented Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+100, 120194, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6298.875, -1031.632, 2904.045, 5.872719, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghostly Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+101, 120182, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6353.063, -1025.335, 2910.594, 2.824198, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tormented Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+102, 121718, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6363.712, -1037.087, 2908.148, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Thal'kiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+103, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6123.472, -985.332, 2959.573, 2.237549, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante) (possible waypoints or random movement)
(@CGUID+104, 120194, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6305.065, -1050.439, 2904.754, 1.038924, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghostly Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+105, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6167.455, -1011.891, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+106, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6029.747, -800.2448, 2971.802, 4.192907, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+107, 122851, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6157.087, -999.4167, 2899.315, 2.735424, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+108, 120194, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6307.478, -1047.13, 2904.754, 3.984496, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghostly Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+109, 122850, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6108.598, -977.9323, 2958.774, 1.810478, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+110, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6212.952, -1028.507, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+111, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6170.444, -1006.307, 2899.554, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+112, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6030.049, -769.2691, 2971.456, 0.2585418, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+113, 118182, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6190.061, -1020.028, 2899.532, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Moon Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236357 - Fonts d'Elune)
(@CGUID+114, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6210.226, -1034.203, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+115, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6037.701, -792.0191, 2971.804, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+116, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6130.182, -993.4514, 2960.201, 6.040581, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+117, 120720, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6155.077, -1001.851, 2899.303, 2.735424, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+118, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6270.325, -1059.479, 2912.788, 4.462815, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+119, 122850, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6120.082, -960.1337, 2892.406, 0.06695081, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+120, 118518, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6208.682, -1037.313, 2899.552, 2.975522, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Priestess Lunaspyre (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235268 - Fantôme lunaire)
(@CGUID+121, 118523, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6208.613, -1026.842, 2899.559, 2.771113, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Huntress Kasparian (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234999 - Fantôme physique, 236324 - Fantôme physique (monture))
(@CGUID+122, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6360.545, -1035.429, 2910.26, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+123, 122850, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6123.7, -963.6805, 2892.406, 0.08118486, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+124, 122850, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6124.58, -972.4358, 2892.406, 0.3176629, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+125, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6123.396, -1009.12, 2960.201, 5.376779, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante) (possible waypoints or random movement)
(@CGUID+126, 122847, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6151.807, -1007.389, 2899.292, 2.735424, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+127, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6124.738, -1012.234, 2960.201, 1.513937, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+128, 122847, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6153.115, -1004.486, 2899.293, 2.735424, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+129, 120808, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6100.99, -986.4236, 2959.747, 1.56127, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lylth the Silent (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 50195 - Lévitation, 240526 - Lune croissante)
(@CGUID+130, 122850, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6097.596, -963.0833, 2896.765, 4.562388, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+131, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6200.76, -1041.811, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+132, 120194, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6295.33, -1060.785, 2904.754, 0.5198959, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghostly Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+133, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6252.113, -1055.793, 2901.792, 1.051911, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+134, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6281.962, -1067.847, 2913.92, 4.092694, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+135, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6166.417, -1018.151, 2899.554, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+136, 122847, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6097.588, -982.9566, 2959.373, 1.254951, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+137, 122851, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6096.112, -955.0833, 2897.768, 4.562388, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+138, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6206.023, -1038.797, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+139, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6166.479, -1024.568, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+140, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6100.988, -990.5469, 2959.747, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240700 - Piège d'Aegwynn)
(@CGUID+141, 122847, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6104.315, -983.217, 2959.45, 1.56127, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+142, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6125.947, -1009.597, 2960.201, 3.641993, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+143, 120720, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6152.092, -1011.099, 2899.301, 2.735424, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+144, 122850, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6120.905, -975.4705, 2892.406, 0.1298525, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+145, 122850, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6093.782, -978.0382, 2958.774, 1.237491, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+146, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6150.554, -1005.571, 2899.287, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+147, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6279.244, -1067.548, 2912.609, 4.031995, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+148, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6172.087, -1036.002, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+149, 122851, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6151.718, -1014.609, 2899.316, 2.735424, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+150, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6266.836, -1074.98, 2914.377, 4.442638, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+151, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6181.779, -1043.448, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+152, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6176.276, -1040.175, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+153, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6110.763, -1000.21, 2958.773, 4.277065, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+154, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6292.855, -1069.27, 2911.103, 3.715364, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+155, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6247.793, -1059.577, 2901.89, 0.8870408, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+156, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6194.877, -1043.622, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+157, 122851, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6093.252, -958.5087, 2897.776, 4.562388, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+158, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6188.231, -1044.752, 2899.553, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+159, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6249.061, -1057.925, 2901.91, 0.8808278, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+160, 122851, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6089.659, -955.3958, 2897.77, 4.562388, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+161, 122850, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6088.879, -963.0781, 2896.765, 4.562388, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+162, 119054, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6168.47, -1030.311, 2899.554, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Glaive Target (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+163, 122850, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6092.853, -965.0695, 2896.765, 4.562388, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+164, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6254.441, -1058.466, 2901.882, 1.070877, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+165, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6251.412, -1059.412, 2901.98, 1.333505, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+166, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6253.776, -1061.705, 2901.956, 1.090958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+167, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6251.138, -1062.984, 2901.879, 1.140124, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+168, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6113.608, -1004.846, 2958.773, 4.408826, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+169, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6076.031, -970.9445, 2960.201, 3.998352, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+170, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6248.983, -1061.602, 2901.873, 1.23863, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+171, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6267.877, -1076.207, 2914.778, 4.268126, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+172, 120851, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6120.585, -1011.71, 2908.812, 3.587894, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Hippogryph Lord Varah (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante, 240917 - Monture monstre fantôme lunaire)
(@CGUID+173, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6148.963, -1043.089, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+174, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6148.778, -1050.724, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+175, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6003.479, -789.5625, 2974.586, 1.792414, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+176, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6077.179, -988.0886, 2959.568, 0.09361863, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+177, 120201, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6284.788, -1084.495, 2904.754, 4.693359, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spectral Guardian (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 244081 - Aura chatoyante)
(@CGUID+178, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.908, -1085.866, 2918.878, 3.999619, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+179, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6087.835, -1004.184, 2958.775, 5.240832, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+180, 120191, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6262.933, -1072.583, 2904.754, 4.004122, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Soulguard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+181, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6150.059, -1043.01, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+182, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6150.116, -1046.684, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+183, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6149.853, -1039.363, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+184, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6004.943, -803.0538, 2974.587, 0.6956571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+185, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6073.229, -972.9063, 2960.201, 0.1548213, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+186, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6095.81, -1001.606, 2959.294, 4.882201, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+187, 120194, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6259.895, -1077.319, 2904.754, 1.100638, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghostly Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+188, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6002.359, -800.7639, 2974.586, 5.690412, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+189, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6136.211, -1039.406, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+190, 120194, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6258.951, -1073.339, 2904.754, 5.872719, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghostly Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+191, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6136.241, -1042.993, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+192, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6000.279, -787.1024, 2974.871, 3.966526, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+193, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6134.952, -1039.214, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+194, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6000.962, -794.3854, 2974.586, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+195, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6300.754, -1081.326, 2901.891, 0.9095108, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+196, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6303.874, -1082.708, 2901.84, 0.9059915, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+197, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6304.396, -1087.118, 2901.776, 0.9328928, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+198, 120201, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6287.242, -1087.957, 2904.754, 1.429194, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spectral Guardian (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 244081 - Aura chatoyante)
(@CGUID+199, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6301.14, -1084.185, 2901.98, 0.9348488, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+200, 120720, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6152.015, -1052.083, 2891.844, 2.224037, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+201, 121498, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6068.652, -970.6719, 2896.765, 0.2174556, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Twilight Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+202, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6302.988, -1089.187, 2901.777, 0.936627, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+203, 120201, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6281.182, -1088.3, 2904.754, 5.637279, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spectral Guardian (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 244081 - Aura chatoyante)
(@CGUID+204, 120721, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6146.491, -1072.333, 2967.069, 1.59169, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+205, 120720, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6133.838, -1060.172, 2965.386, 1.59169, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+206, 120720, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6151.196, -1060.271, 2965.387, 1.59169, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+207, 120201, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6272.686, -1101.51, 2904.754, 0.8482642, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spectral Guardian (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 244081 - Aura chatoyante)
(@CGUID+208, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6257.26, -1096.628, 2923.201, 3.009856, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+209, 120194, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6274.21, -1100.149, 2904.754, 3.85491, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghostly Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+210, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6247.38, -1085.639, 2921.133, 2.192854, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+211, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6251.951, -1091.657, 2922.722, 2.321586, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+212, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6299.955, -1089.002, 2901.764, 0.9490175, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+213, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6260.663, -1096.462, 2921.863, 3.25385, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+214, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6297.536, -1086.576, 2901.73, 0.9495296, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+215, 120720, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6149.01, -1048.347, 2891.844, 2.117763, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+216, 120188, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6298.517, -1086.094, 2901.722, 1.105008, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wailing Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 188236 - , 244081 - Aura chatoyante)
(@CGUID+217, 120720, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6144.784, -1051.729, 2891.844, 2.093157, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+218, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5984.767, -793.4167, 2978.209, 6.224468, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+219, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5862.79, -784.9167, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+220, 120720, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6143.582, -1059.141, 2891.844, 2.168783, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+221, 120988, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6438.127, -1089.924, 2897.823, 3.170981, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Swirling Souls (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241118 - Ames tourbillonnantes)
(@CGUID+222, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5951.07, -798.2222, 2978.209, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+223, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5960.486, -803.2292, 2977.906, 5.506678, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+224, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5862.79, -806.8524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+225, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5921.882, -793.6736, 2970.474, 0.964916, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+226, 120720, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6140.774, -1055.004, 2891.844, 2.013434, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+227, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5972.427, -797.7205, 2977.917, 0.964916, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+228, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5862.79, -804.4149, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+229, 120721, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6137.526, -1072.375, 2967.067, 1.59169, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+230, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5965.971, -788.0243, 2977.914, 0.9858042, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+231, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5862.79, -787.3524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+232, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5925.53, -797.1736, 2972.766, 3.308372, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+233, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5939.229, -794.5382, 2978.883, 3.308372, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+234, 120720, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6147.739, -1055.845, 2891.844, 2.210496, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Temple Guard (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+235, 120182, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6246.448, -1112.466, 2904.561, 3.853462, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tormented Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123167 - Échelle : 95-100%, 244081 - Aura chatoyante)
(@CGUID+236, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5953.122, -790.507, 2978.21, 3.502233, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+237, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5906.289, -793.7708, 2961.23, 1.84227, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+238, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5920.638, -797.8663, 2969.74, 0.4126073, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+239, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5854.153, -787.3524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+240, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5857.272, -784.9167, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+241, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5860.124, -804.4149, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+242, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5857.272, -787.3524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+243, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5860.124, -784.9167, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+244, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5854.153, -804.4149, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+245, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5860.124, -787.3524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+246, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5854.153, -806.8524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+247, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5854.153, -784.9167, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+248, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5857.272, -804.4149, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+249, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5860.124, -806.8524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961); -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5857.272, -806.8524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+251, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6260.349, -1067.672, 2904.754, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+252, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6334.838, -1054.653, 2904.754, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+253, 118699, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6407.378, -1109.629, 2881.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Font (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241576 - Fonts spirituels, 235113 - Barrière spirituelle)
(@CGUID+254, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6229.15, -1013.049, 2923.841, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+255, 118701, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6430.188, -1125.691, 2881.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Font (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241577 - Fonts spirituels, 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+256, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6282.41, -1048.566, 2904.417, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+257, 118699, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6402.558, -1082.194, 2881.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Font (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241576 - Fonts spirituels, 235113 - Barrière spirituelle)
(@CGUID+258, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6236.512, -1012.189, 2923.84, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+259, 118701, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6407.378, -1109.629, 2881.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Font (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241577 - Fonts spirituels, 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+260, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6283.588, -1062.186, 2904.207, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+261, 118699, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6418.497, -1059.29, 2881.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Font (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241576 - Fonts spirituels, 235113 - Barrière spirituelle)
(@CGUID+262, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6285.302, -1033.361, 2904.754, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+263, 118701, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6402.558, -1082.194, 2881.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Font (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241577 - Fonts spirituels, 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+264, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6295.306, -1072.063, 2904.754, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+265, 118699, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6446.127, -1054.335, 2881.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Font (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241576 - Fonts spirituels, 235113 - Barrière spirituelle)
(@CGUID+266, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6233.311, -1070.977, 2904.754, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+267, 118701, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6418.497, -1059.29, 2881.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Font (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241577 - Fonts spirituels, 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+268, 118462, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6461.069, -1088.023, 2881.605, 2.73537, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soul Queen Dejahna (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+269, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6225.562, -996.1754, 2923.832, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+270, 118460, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6456.637, -1105.83, 2881.605, 2.507201, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Engine of Souls (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235113 - Barrière spirituelle)
(@CGUID+271, 118699, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6468.974, -1070.344, 2881.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Font (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241576 - Fonts spirituels, 235113 - Barrière spirituelle)
(@CGUID+272, 118701, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6446.127, -1054.335, 2881.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Font (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241577 - Fonts spirituels, 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+273, 118715, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6444.915, -1101.773, 2881.611, 5.802058, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Reanimated Templar (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236513 - Armure thoracique, 235113 - Barrière spirituelle)
(@CGUID+274, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6232.177, -994.507, 2923.839, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+275, 118699, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6430.188, -1125.691, 2881.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Font (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241576 - Fonts spirituels, 235113 - Barrière spirituelle)
(@CGUID+276, 118701, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6468.974, -1070.344, 2881.992, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Font (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241577 - Fonts spirituels, 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+277, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6282.556, -1091.439, 2904.754, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+278, 118730, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6451.666, -1083.014, 2881.611, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soul Residue (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+279, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6265, -1096.622, 2904.046, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+280, 118730, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6449.338, -1095.122, 2881.611, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soul Residue (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+281, 118729, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6456.283, -1089.766, 2881.611, 0.3203676, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fallen Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+282, 118728, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6441.265, -1096.424, 2881.611, 5.696171, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghastly Bonewarden (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236513 - Armure thoracique, 235113 - Barrière spirituelle, 173746 - Canalisation de l’ombre)
(@CGUID+283, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6299.205, -1023.335, 2904.76, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+284, 118730, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6461.457, -1074.819, 2881.611, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soul Residue (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+285, 118729, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6460.058, -1082.431, 2881.611, 5.072557, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fallen Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+286, 118728, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6438.017, -1103.446, 2881.611, 6.072032, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghastly Bonewarden (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236513 - Armure thoracique, 235113 - Barrière spirituelle, 173746 - Canalisation de l’ombre)
(@CGUID+287, 120240, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6327.957, -1022.957, 2904.582, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redeemed Essence (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239638 - Essence rachetée)
(@CGUID+288, 32638, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6295.803, -793.8011, 2997.72, 6.281649, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Hakmud of Argus (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+289, 32639, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6295.797, -797.8011, 2997.72, 6.281649, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Gnimo (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+290, 121633, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5982.644, -791.9323, 2978.21, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wind Rush Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+291, 119730, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6197.137, -799.5643, 2974.587, 0.1447812, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Maiev Shadowsong (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+292, 119729, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6197.287, -789.0538, 2974.587, 6.207202, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Illidan Hurlorage (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+293, 119728, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6205.509, -803.5643, 2974.484, 0.4490127, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Prophète Velen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+294, 119726, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6203.99, -794.0625, 2974.482, 6.13843, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Archmage Khadgar (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+295, 119777, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5981.214, -790.2864, 2978.21, 6.252902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Durgan Roc-Tempête (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+296, 119723, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6212.216, -795.8068, 2974.843, 3.139253, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Image of Aegwynn (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241351 - Apparition cosmétique)
(@CGUID+297, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6372.249, -808.9078, 3011.719, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+298, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6412.184, -797.6174, 3011.711, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+299, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6426.738, -795.702, 3011.844, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+300, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6375.873, -798.9526, 3011.844, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+301, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6413.521, -803.6315, 3011.711, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+302, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6417.875, -802.158, 3011.711, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+303, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6411.928, -791.2719, 3011.844, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+304, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6413.453, -798.1177, 3011.711, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+305, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6416.564, -797.2708, 3011.711, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+306, 118727, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6437.719, -1089.524, 2881.605, 2.340336, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spiritual Barrier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235589 - Présence de l'esprit, 235629 - Présence de l'esprit, 235621 - Monde des esprits)
(@CGUID+307, 120368, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6459.563, -1106.944, 2895.395, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- The Desolate Host (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+308, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6397.936, -796.5761, 3011.711, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+309, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6136.251, -1046.66, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+310, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6148.97, -1054.451, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+311, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6201.01, -1108.342, 2903.498, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240822 - Piège d'Aegwynn)
(@CGUID+312, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6135.109, -1046.568, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+313, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6136.146, -1054.51, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+314, 122847, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6142.534, -1069.865, 2967.57, 1.59169, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+315, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6135.085, -1050.757, 2965.181, 4.693195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+316, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6394.557, -796.4552, 3011.711, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+317, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6409.757, -934.7612, 3037.257, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+318, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6413.065, -935.7642, 3037.255, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+319, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6407.601, -935.5882, 3037.251, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+320, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6414.367, -802.1992, 3011.711, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+321, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6428.956, -798.7095, 3011.844, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+322, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6414.309, -795.9121, 3011.711, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+323, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6411.602, -792.5756, 3011.711, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+324, 121111, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6402.073, -795.7257, 3015.393, 3.144097, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Hammer of Khaz'goroth (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 144373 - RShwayder Test 02)
(@CGUID+325, 45396, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6227.764, -787.2969, 2978.833, 3.524564, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI) (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 243149 -)
(@CGUID+326, 121494, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6227.764, -787.2969, 2981.715, 3.524564, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Hammer of Khaz'goroth (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 154441 - Shadowy Ghost Cosmetic Spawn Spell)
(@CGUID+327, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5893.361, -798.5382, 2954.41, 1.77362, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+328, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6077.446, -1001.684, 2959.958, 0.9638805, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+329, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5892.022, -794.7518, 2954.404, 5.802555, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+330, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6014.979, -1075.833, 2904.475, 2.344693, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+331, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5888.283, -797.2257, 2954.382, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+332, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5876.856, -803.7639, 2954.368, 0.2438955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+333, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5883.807, -796.9496, 2954.368, 0.6418293, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+334, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5882.648, -792.6979, 2954.368, 4.038858, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+335, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6022.766, -1090.752, 2898.222, 1.896396, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+336, 122847, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6092.133, -1030.391, 2896.395, 0.7401351, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+337, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5984.258, -1078.542, 2912.823, 3.266867, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+338, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5971.11, -1076.146, 2919.455, 4.117414, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+339, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5977.7, -1079.339, 2915.219, 3.268334, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+340, 122847, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6141.38, -1047.54, 2891.844, 5.351814, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+341, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6023.47, -1095.966, 2896.987, 1.869023, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+342, 122851, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6083.905, -1030.089, 2896.395, 2.179349, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+343, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6088.5, -1027.075, 2896.395, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240705 - Piège d'Aegwynn)
(@CGUID+344, 122851, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6090.708, -1033.37, 2897.159, 0.9604903, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+345, 122851, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6087.958, -1032.674, 2897.114, 1.388604, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+346, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6083.261, -1058.946, 2965.043, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240700 - Piège d'Aegwynn)
(@CGUID+347, 122847, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6088.554, -1026.852, 2896.395, 1.604249, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+348, 122851, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6084.791, -1032.477, 2897.144, 1.891482, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Umbral Archer (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+349, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6005.572, -1108.761, 2914.247, 1.454197, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+350, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5989.694, -1096.355, 2892.13, 1.53742, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+351, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6022.061, -1120.737, 2889.501, 0.984042, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+352, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6000.671, -1115.237, 2914.248, 0.3568967, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+353, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5986.875, -1102.086, 2892.13, 0.7994301, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+354, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5986.626, -1102.333, 2892.13, 0.764883, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante)
(@CGUID+355, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6013.121, -1133.215, 2882.98, 0.8837579, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+356, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6007.709, -1138.861, 2876.52, 0.6686372, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+357, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6035.633, -1058.936, 2965.043, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240700 - Piège d'Aegwynn)
(@CGUID+358, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6015.431, -1132.707, 2882.885, 0.9313277, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+359, 120196, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6020.768, -1126.137, 2887.683, 0.7265443, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Drifting Soul (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 222912 - Échelle : 175%, 244081 - Aura chatoyante) (possible waypoints or random movement)
(@CGUID+360, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5970.443, -1013.438, 2925.083, 2.022182, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+361, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5954.612, -1026.767, 2918.618, 2.248687, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+362, 121717, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6001.626, -1072.132, 2898.358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Thal'kiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+363, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5947.389, -1036.177, 2918.467, 2.26624, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+364, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5994.355, -1074.708, 2898.38, 4.562689, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+365, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5949.445, -1044.413, 2917.784, 1.109682, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante) (possible waypoints or random movement)
(@CGUID+366, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5954.597, -1047.379, 2917.509, 1.023319, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante) (possible waypoints or random movement)
(@CGUID+367, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5952.308, -1045.37, 2917.555, 1.028669, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante) (possible waypoints or random movement)
(@CGUID+368, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6002.719, -1078.672, 2898.353, 4.562689, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+369, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5998.874, -1076.821, 2898.363, 4.562689, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240526 - Lune croissante)
(@CGUID+370, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5966.676, -1096.29, 2853.148, 0.3022831, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante) (possible waypoints or random movement)
(@CGUID+371, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5957.623, -1107.15, 2852.986, 0.2697696, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante) (possible waypoints or random movement)
(@CGUID+372, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6036.023, -1118.913, 2879.275, 2.643234, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+373, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6033.454, -1115.087, 2879.338, 4.704806, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+374, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6029.924, -1118.215, 2879.3, 0.1995517, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante)
(@CGUID+375, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5975.149, -1125.791, 2853.216, 0.6246576, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante) (possible waypoints or random movement)
(@CGUID+376, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5965.188, -1121.677, 2852.889, 5.235201, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante) (possible waypoints or random movement)
(@CGUID+377, 120697, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5968.638, -1137.765, 2853.178, 5.482397, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Worshiper of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240528 - Lune décroissante) (possible waypoints or random movement)
(@CGUID+378, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6099.479, -983.0077, 2959.706, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+379, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6101.754, -979.4592, 2959.043, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+380, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6143.091, -871.2483, 2923.226, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+381, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6155.137, -986.8489, 2896.206, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+382, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6155.522, -996.6758, 2899.444, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+383, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6154.554, -997.238, 2899.321, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+384, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6170.981, -1011.021, 2899.557, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+385, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6174.632, -1021.941, 2899.565, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+386, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6197.691, -1022.553, 2899.644, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+387, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6199.74, -1012.88, 2899.57, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+388, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6187.083, -1028.062, 2899.644, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+389, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6197.024, -1016.161, 2899.575, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+390, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6172.391, -1017.168, 2899.644, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+391, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6191.526, -1018.966, 2899.583, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+392, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6194.9, -1018.848, 2899.579, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+393, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6201.389, -1013.66, 2899.568, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+394, 111374, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6191.394, -1020.521, 2899.532, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+395, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6164.382, -1010.463, 2899.644, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+396, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6149.412, -1010.656, 2899.483, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+397, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6335.508, -1021, 2904.006, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+398, 73400, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6337.278, -1024.552, 2903.952, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+399, 105422, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6334.545, -1028.524, 2904.672, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+400, 73400, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6424.175, -1061.994, 2881.611, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+401, 73400, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6460.862, -1086.256, 2881.611, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+402, 118715, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6448.589, -1097.068, 2881.605, 2.636833, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Reanimated Templar (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236513 - Armure thoracique)
(@CGUID+403, 118728, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6449.934, -1067.109, 2881.605, 4.385174, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghastly Bonewarden (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236513 - Armure thoracique)
(@CGUID+404, 118728, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6427.688, -1116.934, 2881.605, 1.058801, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghastly Bonewarden (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236513 - Armure thoracique)
(@CGUID+405, 105422, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6445.539, -1091.307, 2881.644, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+406, 105422, 1676, 8524, 8524, 245760, '8308', 0, 0, 0, 6451.85, -1114.603, 2881.613, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+407, 73400, 1676, 8524, 8524, 245760, '8308', 0, 0, 0, 6460.756, -1089.495, 2881.612, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+408, 73400, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6412.14, -1095.645, 2881.611, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+409, 118730, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6415.26, -1100.33, 2881.605, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soul Residue (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle)
(@CGUID+410, 118729, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6420.604, -1079.563, 2881.605, 5.757848, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fallen Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle)
(@CGUID+411, 118730, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6443.142, -1060.007, 2881.605, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soul Residue (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle)
(@CGUID+412, 118730, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6419.348, -1068.898, 2881.605, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soul Residue (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle)
(@CGUID+413, 118730, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6437.081, -1092.439, 2881.605, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soul Residue (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle)
(@CGUID+414, 118729, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6431.194, -1071.717, 2881.605, 5.194941, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fallen Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle)
(@CGUID+415, 105422, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6416.235, -1104.485, 2881.644, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+416, 118715, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6438.86, -1091.769, 2881.605, 2.59898, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Reanimated Templar (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236513 - Armure thoracique)
(@CGUID+417, 118715, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6440.858, -1070.295, 2881.605, 4.25388, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Reanimated Templar (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236513 - Armure thoracique)
(@CGUID+418, 118728, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6426.159, -1078.988, 2881.605, 5.450068, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ghastly Bonewarden (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 236513 - Armure thoracique)
(@CGUID+419, 105422, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6434.76, -1076.199, 2881.644, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidal Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+420, 118730, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6422.333, -1107.413, 2881.56, 0.4859456, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soul Residue (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+421, 118729, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6425.524, -1087.279, 2881.56, 0.2007877, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fallen Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+422, 118730, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6429.206, -1064.108, 2881.56, 5.994916, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soul Residue (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+423, 118729, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6454.044, -1078.168, 2881.56, 5.697212, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fallen Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+424, 73400, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6445.175, -1077.427, 2881.611, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Healing Ran Invisible Stalker DND (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 147490 - Healing Rain Visual)
(@CGUID+425, 118730, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6413.202, -1086.458, 2881.56, 0.4964632, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soul Residue (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+426, 118729, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6433.656, -1073.185, 2881.56, 5.93176, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fallen Priestess (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 235620 - Barrière spirituelle, 240851 - Transfert d'âme)
(@CGUID+427, 121110, 1676, 8524, 8524, 245760, '8309', 0, 0, 0, 6438.203, -1089.589, 2882.929, 2.520734, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tears of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 144373 - RShwayder Test 02)
(@CGUID+428, 121495, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6231.319, -792.3889, 2980.379, 3.260449, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tears of Elune (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 154441 - Shadowy Ghost Cosmetic Spawn Spell)
(@CGUID+429, 45396, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6231.319, -792.3889, 2978.833, 3.260449, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961); -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI) (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 243149 -)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+429;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SLG Generic Stalker (Gigantic AOI)
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, '242907'), -- Infernal Chaosbringer - 242907 - Infernal (cosmétique)
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Coercitor Nixa
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, '233423'), -- Atrigan - 233423 - Faux d'os
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Belac
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, '243149'), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI) - 243149 -
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+14, 0, 0, 50331648, 1, 0, 0, 0, 0, '154441'), -- Aegis of Aggramar - 154441 - Shadowy Ghost Cosmetic Spawn Spell
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Inquisitor Sebilus
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Accusator Gnazh
(@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+19, 0, 0, 8, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Guard - 240528 - Lune décroissante
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+22, 0, 0, 8, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+23, 0, 0, 8, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Guard - 240528 - Lune décroissante
(@CGUID+25, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Eternal Soulguard - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, '240704'), -- Aegwynn's Trap - 240704 - Piège d'Aegwynn
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+30, 0, 0, 1, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Temple Archer - 240526 - Lune croissante
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+33, 0, 0, 0, 1, 0, 0, 0, 0, '235305'), -- Tormented Soul - 235305 - Prisonnier de la Légion
(@CGUID+34, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Temple Archer - 240526 - Lune croissante
(@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+36, 0, 0, 8, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+37, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+38, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Lieutenant Silvermight - 240526 - Lune croissante
(@CGUID+40, 0, 0, 0, 1, 0, 0, 0, 0, '242984'), -- Infernal Chaosbringer - 242984 - Aura d'immolation
(@CGUID+41, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Tormented Priestess - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+43, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Tormented Priestess - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+45, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+46, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Eternal Soulguard - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Archmage Khadgar
(@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Tormented Priestess - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+50, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+51, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Maiev Shadowsong
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+56, 0, 0, 0, 1, 0, 0, 0, 0, '242984'), -- Infernal Chaosbringer - 242984 - Aura d'immolation
(@CGUID+57, 0, 0, 0, 1, 0, 0, 0, 0, '241186'), -- Prophète Velen - 241186 - Egide de Lumière
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+59, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, '240825'), -- Aegwynn's Trap - 240825 - Piège d'Aegwynn
(@CGUID+61, 0, 0, 8, 1, 0, 0, 0, 0, '123167 244081'), -- Eternal Soulguard - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+62, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+63, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+64, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+65, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+66, 0, 0, 8, 1, 0, 0, 0, 0, '123167 244081'), -- Eternal Soulguard - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+67, 0, 0, 8, 1, 0, 0, 0, 0, '123167 244081'), -- Eternal Soulguard - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+68, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+69, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+70, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Illidan Hurlorage
(@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, '241309'), -- Fan'verg the Vicious - 241309 - Planer
(@CGUID+72, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+73, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+75, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+76, 0, 0, 8, 1, 0, 0, 0, 0, '123167 244081'), -- Eternal Soulguard - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+78, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+79, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+80, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+81, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+82, 0, 0, 0, 1, 0, 0, 0, 0, '235268'), -- Captain Yathae Moonstrike - 235268 - Fantôme lunaire
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+84, 0, 0, 1, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+85, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+86, 0, 0, 1, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+87, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+88, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+89, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+90, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Eternal Soulguard - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+91, 0, 0, 0, 1, 0, 0, 0, 0, '244081'), -- Spectral Guardian - 244081 - Aura chatoyante
(@CGUID+92, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+93, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+94, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Eternal Soulguard - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+95, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+96, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Eternal Soulguard - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+97, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Ghostly Acolyte - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+98, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+99, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Tormented Priestess - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+100, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Ghostly Acolyte - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+101, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Tormented Priestess - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+102, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+103, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+104, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Ghostly Acolyte - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+105, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+106, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+107, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Archer - 240528 - Lune décroissante
(@CGUID+108, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Ghostly Acolyte - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+109, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Guard - 240528 - Lune décroissante
(@CGUID+110, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+111, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+112, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+113, 0, 0, 50331648, 1, 0, 0, 0, 0, '236357'), -- Moon Stalker - 236357 - Fonts d'Elune
(@CGUID+114, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+115, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+116, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+117, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Temple Guard - 240526 - Lune croissante
(@CGUID+118, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+119, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Guard - 240528 - Lune décroissante
(@CGUID+120, 0, 0, 0, 1, 0, 0, 0, 0, '235268'), -- Priestess Lunaspyre - 235268 - Fantôme lunaire
(@CGUID+121, 0, 75620, 0, 1, 0, 0, 0, 0, '234999 236324'), -- Huntress Kasparian - 234999 - Fantôme physique, 236324 - Fantôme physique (monture)
(@CGUID+122, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+123, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Guard - 240528 - Lune décroissante
(@CGUID+124, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Guard - 240528 - Lune décroissante
(@CGUID+125, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+126, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Umbral Priestess - 240526 - Lune croissante
(@CGUID+127, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+128, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Umbral Priestess - 240526 - Lune croissante
(@CGUID+129, 0, 0, 0, 1, 0, 0, 0, 0, '50195 240526'), -- Lylth the Silent - 50195 - Lévitation, 240526 - Lune croissante
(@CGUID+130, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Guard - 240528 - Lune décroissante
(@CGUID+131, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+132, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Ghostly Acolyte - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+133, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+134, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+135, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+136, 0, 0, 8, 1, 0, 0, 0, 0, '240526'), -- Umbral Priestess - 240526 - Lune croissante
(@CGUID+137, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Archer - 240528 - Lune décroissante
(@CGUID+138, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+139, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+140, 0, 0, 0, 1, 0, 0, 0, 0, '240700'), -- Aegwynn's Trap - 240700 - Piège d'Aegwynn
(@CGUID+141, 0, 0, 8, 1, 0, 0, 0, 0, '240526'), -- Umbral Priestess - 240526 - Lune croissante
(@CGUID+142, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+143, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Temple Guard - 240526 - Lune croissante
(@CGUID+144, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Guard - 240528 - Lune décroissante
(@CGUID+145, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Guard - 240528 - Lune décroissante
(@CGUID+146, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+147, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+148, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+149, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Archer - 240528 - Lune décroissante
(@CGUID+150, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+151, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+152, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+153, 0, 0, 8, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+154, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+155, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+156, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+157, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Archer - 240528 - Lune décroissante
(@CGUID+158, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+159, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+160, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Archer - 240528 - Lune décroissante
(@CGUID+161, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Guard - 240528 - Lune décroissante
(@CGUID+162, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Glaive Target
(@CGUID+163, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Guard - 240528 - Lune décroissante
(@CGUID+164, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+165, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+166, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+167, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+168, 0, 0, 8, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+169, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+170, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+171, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+172, 0, 63626, 50331648, 1, 0, 0, 0, 0, '240526 240917'), -- Hippogryph Lord Varah - 240526 - Lune croissante, 240917 - Monture monstre fantôme lunaire
(@CGUID+173, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+174, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+175, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+176, 0, 0, 1, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+177, 0, 0, 3, 1, 0, 0, 0, 0, '244081'), -- Spectral Guardian - 244081 - Aura chatoyante
(@CGUID+178, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+179, 0, 0, 8, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+180, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Eternal Soulguard - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+181, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+182, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+183, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+184, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+185, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+186, 0, 0, 8, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+187, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Ghostly Acolyte - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+188, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+189, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+190, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Ghostly Acolyte - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+191, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+192, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+193, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+194, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+195, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+196, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+197, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+198, 0, 0, 3, 1, 0, 0, 0, 0, '244081'), -- Spectral Guardian - 244081 - Aura chatoyante
(@CGUID+199, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+200, 0, 0, 0, 0, 0, 0, 0, 0, '240526'), -- Temple Guard - 240526 - Lune croissante
(@CGUID+201, 0, 0, 33554432, 1, 0, 0, 0, 0, '240528'), -- Twilight Soul - 240528 - Lune décroissante
(@CGUID+202, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+203, 0, 0, 3, 1, 0, 0, 0, 0, '244081'), -- Spectral Guardian - 244081 - Aura chatoyante
(@CGUID+204, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Temple Archer - 240526 - Lune croissante
(@CGUID+205, 0, 0, 8, 1, 0, 0, 0, 0, '240526'), -- Temple Guard - 240526 - Lune croissante
(@CGUID+206, 0, 0, 8, 1, 0, 0, 0, 0, '240526'), -- Temple Guard - 240526 - Lune croissante
(@CGUID+207, 0, 0, 1, 1, 0, 0, 0, 0, '244081'), -- Spectral Guardian - 244081 - Aura chatoyante
(@CGUID+208, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+209, 0, 0, 1, 1, 0, 0, 0, 0, '123167 244081'), -- Ghostly Acolyte - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+210, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+211, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+212, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+213, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+214, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+215, 0, 0, 0, 0, 0, 0, 0, 0, '240526'), -- Temple Guard - 240526 - Lune croissante
(@CGUID+216, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- Wailing Soul - 188236 - , 244081 - Aura chatoyante
(@CGUID+217, 0, 0, 0, 0, 0, 0, 0, 0, '240526'), -- Temple Guard - 240526 - Lune croissante
(@CGUID+218, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+219, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+220, 0, 0, 0, 0, 0, 0, 0, 0, '240526'), -- Temple Guard - 240526 - Lune croissante
(@CGUID+221, 0, 0, 0, 1, 0, 0, 0, 0, '241118'), -- Swirling Souls - 241118 - Ames tourbillonnantes
(@CGUID+222, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+223, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+224, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+225, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+226, 0, 0, 0, 0, 0, 0, 0, 0, '240526'), -- Temple Guard - 240526 - Lune croissante
(@CGUID+227, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+228, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+229, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Temple Archer - 240526 - Lune croissante
(@CGUID+230, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+231, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+232, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+233, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+234, 0, 0, 0, 0, 0, 0, 0, 0, '240526'), -- Temple Guard - 240526 - Lune croissante
(@CGUID+235, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- Tormented Priestess - 123167 - Échelle : 95-100%, 244081 - Aura chatoyante
(@CGUID+236, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+237, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+238, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+239, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+240, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+241, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+242, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+243, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+244, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+245, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+246, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+247, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+248, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+249, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Soldat du Déclin

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+250, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+251, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+252, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+253, 0, 0, 0, 1, 0, 0, 0, 0, '241576 235113'), -- Spiritual Font - 241576 - Fonts spirituels, 235113 - Barrière spirituelle
(@CGUID+254, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+255, 0, 0, 0, 1, 0, 0, 0, 0, '241577 235620 240851'), -- Spiritual Font - 241577 - Fonts spirituels, 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+256, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+257, 0, 0, 0, 1, 0, 0, 0, 0, '241576 235113'), -- Spiritual Font - 241576 - Fonts spirituels, 235113 - Barrière spirituelle
(@CGUID+258, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+259, 0, 0, 0, 1, 0, 0, 0, 0, '241577 235620 240851'), -- Spiritual Font - 241577 - Fonts spirituels, 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+260, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+261, 0, 0, 0, 1, 0, 0, 0, 0, '241576 235113'), -- Spiritual Font - 241576 - Fonts spirituels, 235113 - Barrière spirituelle
(@CGUID+262, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+263, 0, 0, 0, 1, 0, 0, 0, 0, '241577 235620 240851'), -- Spiritual Font - 241577 - Fonts spirituels, 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+264, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+265, 0, 0, 0, 1, 0, 0, 0, 0, '241576 235113'), -- Spiritual Font - 241576 - Fonts spirituels, 235113 - Barrière spirituelle
(@CGUID+266, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+267, 0, 0, 0, 1, 0, 0, 0, 0, '241577 235620 240851'), -- Spiritual Font - 241577 - Fonts spirituels, 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+268, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- Soul Queen Dejahna - 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+269, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+270, 0, 0, 0, 1, 0, 0, 0, 0, '235113'), -- Engine of Souls - 235113 - Barrière spirituelle
(@CGUID+271, 0, 0, 0, 1, 0, 0, 0, 0, '241576 235113'), -- Spiritual Font - 241576 - Fonts spirituels, 235113 - Barrière spirituelle
(@CGUID+272, 0, 0, 0, 1, 0, 0, 0, 0, '241577 235620 240851'), -- Spiritual Font - 241577 - Fonts spirituels, 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+273, 0, 0, 0, 1, 0, 0, 0, 0, '236513 235113'), -- Reanimated Templar - 236513 - Armure thoracique, 235113 - Barrière spirituelle
(@CGUID+274, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+275, 0, 0, 0, 1, 0, 0, 0, 0, '241576 235113'), -- Spiritual Font - 241576 - Fonts spirituels, 235113 - Barrière spirituelle
(@CGUID+276, 0, 0, 0, 1, 0, 0, 0, 0, '241577 235620 240851'), -- Spiritual Font - 241577 - Fonts spirituels, 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+277, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+278, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- Soul Residue - 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+279, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+280, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- Soul Residue - 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+281, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- Fallen Priestess - 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+282, 0, 0, 0, 1, 0, 0, 0, 0, '236513 235113 173746'), -- Ghastly Bonewarden - 236513 - Armure thoracique, 235113 - Barrière spirituelle, 173746 - Canalisation de l’ombre
(@CGUID+283, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+284, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- Soul Residue - 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+285, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- Fallen Priestess - 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+286, 0, 0, 0, 1, 0, 0, 0, 0, '236513 235113 173746'), -- Ghastly Bonewarden - 236513 - Armure thoracique, 235113 - Barrière spirituelle, 173746 - Canalisation de l’ombre
(@CGUID+287, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- Redeemed Essence - 239638 - Essence rachetée
(@CGUID+288, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Hakmud of Argus
(@CGUID+289, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Gnimo
(@CGUID+290, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wind Rush Totem
(@CGUID+291, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Maiev Shadowsong
(@CGUID+292, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Illidan Hurlorage
(@CGUID+293, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Prophète Velen
(@CGUID+294, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Archmage Khadgar
(@CGUID+295, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Durgan Roc-Tempête
(@CGUID+296, 0, 0, 0, 257, 0, 0, 0, 0, '241351'), -- Image of Aegwynn - 241351 - Apparition cosmétique
(@CGUID+297, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+298, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+299, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+300, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+301, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+302, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+303, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+304, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+305, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+306, 0, 0, 0, 1, 0, 0, 0, 0, '235589 235629 235621'), -- Spiritual Barrier - 235589 - Présence de l'esprit, 235629 - Présence de l'esprit, 235621 - Monde des esprits
(@CGUID+307, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- The Desolate Host
(@CGUID+308, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+309, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+310, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+311, 0, 0, 0, 1, 0, 0, 0, 0, '240822'), -- Aegwynn's Trap - 240822 - Piège d'Aegwynn
(@CGUID+312, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+313, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+314, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Umbral Priestess - 240526 - Lune croissante
(@CGUID+315, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+316, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+317, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+318, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+319, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+320, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+321, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+322, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+323, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+324, 0, 0, 50331648, 1, 0, 0, 0, 0, '144373'), -- Hammer of Khaz'goroth - 144373 - RShwayder Test 02
(@CGUID+325, 0, 0, 0, 1, 0, 0, 0, 0, '243149'), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI) - 243149 -
(@CGUID+326, 0, 0, 50331648, 1, 0, 0, 0, 0, '154441'), -- Hammer of Khaz'goroth - 154441 - Shadowy Ghost Cosmetic Spawn Spell
(@CGUID+327, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+328, 0, 0, 1, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+329, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+330, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+331, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+332, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+333, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+334, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+335, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+336, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Umbral Priestess - 240526 - Lune croissante
(@CGUID+337, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+338, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+339, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+340, 0, 0, 0, 0, 0, 0, 0, 0, '240526'), -- Umbral Priestess - 240526 - Lune croissante
(@CGUID+341, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+342, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Archer - 240528 - Lune décroissante
(@CGUID+343, 0, 0, 0, 1, 0, 0, 0, 0, '240705'), -- Aegwynn's Trap - 240705 - Piège d'Aegwynn
(@CGUID+344, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Archer - 240528 - Lune décroissante
(@CGUID+345, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Archer - 240528 - Lune décroissante
(@CGUID+346, 0, 0, 0, 1, 0, 0, 0, 0, '240700'), -- Aegwynn's Trap - 240700 - Piège d'Aegwynn
(@CGUID+347, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Umbral Priestess - 240526 - Lune croissante
(@CGUID+348, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Umbral Archer - 240528 - Lune décroissante
(@CGUID+349, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+350, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+351, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+352, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+353, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+354, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+355, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+356, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+357, 0, 0, 0, 1, 0, 0, 0, 0, '240700'), -- Aegwynn's Trap - 240700 - Piège d'Aegwynn
(@CGUID+358, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+359, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- Drifting Soul - 222912 - Échelle : 175%, 244081 - Aura chatoyante
(@CGUID+360, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+361, 0, 0, 1, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+362, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+363, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+364, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+365, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+366, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+367, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+368, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+369, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- Worshiper of Elune - 240526 - Lune croissante
(@CGUID+370, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Worshiper of Elune - 240528 - Lune décroissante
(@CGUID+371, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Worshiper of Elune - 240528 - Lune décroissante
(@CGUID+372, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Worshiper of Elune - 240528 - Lune décroissante
(@CGUID+373, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Worshiper of Elune - 240528 - Lune décroissante
(@CGUID+374, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Worshiper of Elune - 240528 - Lune décroissante
(@CGUID+375, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Worshiper of Elune - 240528 - Lune décroissante
(@CGUID+376, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Worshiper of Elune - 240528 - Lune décroissante
(@CGUID+377, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- Worshiper of Elune - 240528 - Lune décroissante
(@CGUID+378, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+379, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+380, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+381, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+382, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+383, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+384, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+385, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+386, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+387, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+388, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+389, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+390, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+391, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+392, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+393, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+394, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+395, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+396, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+397, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+398, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+399, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+400, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+401, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+402, 0, 0, 0, 1, 0, 0, 0, 0, '236513'), -- Reanimated Templar - 236513 - Armure thoracique
(@CGUID+403, 0, 0, 0, 1, 0, 0, 0, 0, '236513'), -- Ghastly Bonewarden - 236513 - Armure thoracique
(@CGUID+404, 0, 0, 0, 1, 0, 0, 0, 0, '236513'), -- Ghastly Bonewarden - 236513 - Armure thoracique
(@CGUID+405, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+406, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+407, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+408, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+409, 0, 0, 0, 1, 0, 0, 0, 0, '235620'), -- Soul Residue - 235620 - Barrière spirituelle
(@CGUID+410, 0, 0, 0, 1, 0, 0, 0, 0, '235620'), -- Fallen Priestess - 235620 - Barrière spirituelle
(@CGUID+411, 0, 0, 0, 1, 0, 0, 0, 0, '235620'), -- Soul Residue - 235620 - Barrière spirituelle
(@CGUID+412, 0, 0, 0, 1, 0, 0, 0, 0, '235620'), -- Soul Residue - 235620 - Barrière spirituelle
(@CGUID+413, 0, 0, 0, 1, 0, 0, 0, 0, '235620'), -- Soul Residue - 235620 - Barrière spirituelle
(@CGUID+414, 0, 0, 0, 1, 0, 0, 0, 0, '235620'), -- Fallen Priestess - 235620 - Barrière spirituelle
(@CGUID+415, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+416, 0, 0, 0, 1, 0, 0, 0, 0, '236513'), -- Reanimated Templar - 236513 - Armure thoracique
(@CGUID+417, 0, 0, 0, 1, 0, 0, 0, 0, '236513'), -- Reanimated Templar - 236513 - Armure thoracique
(@CGUID+418, 0, 0, 0, 1, 0, 0, 0, 0, '236513'), -- Ghastly Bonewarden - 236513 - Armure thoracique
(@CGUID+419, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidal Totem
(@CGUID+420, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- Soul Residue - 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+421, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- Fallen Priestess - 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+422, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- Soul Residue - 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+423, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- Fallen Priestess - 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+424, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- Healing Ran Invisible Stalker DND - 147490 - Healing Rain Visual
(@CGUID+425, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- Soul Residue - 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+426, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- Fallen Priestess - 235620 - Barrière spirituelle, 240851 - Transfert d'âme
(@CGUID+427, 0, 0, 50331648, 1, 0, 0, 0, 0, '144373'), -- Tears of Elune - 144373 - RShwayder Test 02
(@CGUID+428, 0, 0, 50331648, 1, 0, 0, 0, 0, '154441'), -- Tears of Elune - 154441 - Shadowy Ghost Cosmetic Spawn Spell
(@CGUID+429, 0, 0, 0, 1, 0, 0, 0, 0, '243149'); -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI) - 243149 -

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+70;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 269975, 1676, 8524, 8524, 245760, '0', 0, 6194.761, -795.798, 2973.522, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+1, 269780, 1676, 8524, 8524, 245760, '0', 0, 6402.042, -795.7916, 3011.507, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+2, 269164, 1676, 8524, 8524, 245760, '0', 0, 6221.104, -795.7595, 2974.113, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+3, 269842, 1676, 8524, 8524, 245760, '0', 0, 6260.061, -852.3503, 3041.751, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+4, 269839, 1676, 8524, 8524, 245760, '0', 0, 6146.559, -762.0251, 2970.903, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+5, 268579, 1676, 8524, 8524, 245760, '0', 0, 6341.295, -795.7725, 3037.665, 4.71239, 0, 0, -0.7071066, 0.7071069, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+6, 268580, 1676, 8524, 8524, 245760, '0', 0, 6289.381, -795.5262, 3029.027, 4.71239, 0, 0, -0.7071066, 0.7071069, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+7, 269988, 1676, 8524, 8524, 245760, '0', 0, 6295.383, -795.3216, 2886.927, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+8, 269973, 1676, 8524, 8524, 245760, '0', 0, 6099.743, -856.0253, 2974.152, 4.71239, 0, 0, -0.7071066, 0.7071069, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+9, 272802, 1676, 8524, 8524, 245760, '0', 0, 6112.376, -733.7028, 2984.274, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+10, 268750, 1676, 8524, 8524, 245760, '0', 0, 6188.131, -945.7178, 2892.065, 1.118474, 0, 0, 0.5305395, 0.8476602, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+11, 268748, 1676, 8524, 8524, 245760, '0', 0, 6289.318, -985.2384, 2909.796, 5.680764, 0, 0, -0.2966766, 0.954978, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+12, 269838, 1676, 8524, 8524, 245760, '0', 0, 6112.478, -733.6039, 2984.402, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+13, 268366, 1676, 8524, 8524, 245760, '0', 0, 6133.625, -971.8979, 2959.992, 0.5235979, 0, 0, 0.2588186, 0.9659259, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+14, 268514, 1676, 8524, 8524, 245760, '0', 0, 6101.104, -919.1578, 2998.948, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+15, 269841, 1676, 8524, 8524, 245760, '0', 0, 6114.529, -927.6913, 2976.787, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+16, 269258, 1676, 8524, 8524, 245760, '0', 0, 6132.23, -937.5658, 2901.712, 4.948084, 0.004547596, -0.003584862, -0.6190538, 0.7853272, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+17, 268819, 1676, 8524, 8524, 245760, '0', 0, 6243.467, -1001.754, 2923.611, 0.178153, -0.000004291534, 0.00005149841, 0.08895874, 0.9960353, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+18, 269840, 1676, 8524, 8524, 245760, '0', 0, 6087.842, -927.6913, 2976.787, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+19, 268749, 1676, 8524, 8524, 245760, '0', 0, 6354.415, -1030.835, 2909.796, 5.680764, 0, 0, -0.2966766, 0.954978, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+20, 269045, 1676, 8524, 8524, 245760, '0', 0, 6169.401, -1012.846, 2913.108, 5.93412, 0, 0, -0.1736479, 0.9848078, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+21, 268365, 1676, 8524, 8524, 245760, '0', 0, 6133.636, -1009.464, 2959.992, 2.617989, 0, 0, 0.9659252, 0.2588213, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+22, 269974, 1676, 8524, 8524, 245760, '0', 0, 6010.043, -793.4874, 2973.959, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+23, 269781, 1676, 8524, 8524, 245760, '0', 0, 6385.965, -1052.795, 2902.235, 5.678986, 0, 0, -0.2975254, 0.9547139, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+24, 268364, 1676, 8524, 8524, 245760, '0', 0, 6068.479, -1009.354, 2959.992, 3.665196, 0, 0, -0.9659252, 0.2588213, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+25, 269779, 1676, 8524, 8524, 245760, '0', 0, 6438.216, -1089.601, 2881.37, 2.529184, 0, 0, 0.9534845, 0.3014419, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+26, 269120, 1676, 8524, 8524, 245760, '0', 0, 5935.24, -949.2632, 2920.025, 0.5109373, 0, 0, 0.2526989, 0.967545, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+27, 268752, 1676, 8524, 8524, 245760, '0', 0, 5987.114, -1017.305, 2927.477, 3.77578, 0, 0, -0.9501457, 0.3118062, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+28, 269192, 1676, 8524, 8524, 245760, '0', 0, 5937.457, -879.8716, 2920.775, 2.420397, 0, 0, 0.9356861, 0.3528335, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+29, 268751, 1676, 8524, 8524, 245760, '0', 0, 6152.908, -1083.313, 2892.168, 5.198888, 0, 0, -0.5159779, 0.8566019, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+30, 269976, 1676, 8524, 8524, 245760, '0', 0, 5825.933, -1216.871, 2787.371, 0.8726639, 0, 0, 0.4226179, 0.9063079, 604800, 255, 0, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+31, 270940, 1676, 8524, 8524, 245760, '0', 0, 5950.437, -1095.415, 2912.443, 2.81584, 0, 0, 0.9867649, 0.1621574, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+32, 267701, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+33, 267707, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+34, 267709, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+35, 267934, 1676, 8524, 8524, 245760, '0', 0, 6607.75, -795.1597, 1661.2, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+36, 269262, 1676, 8524, 8524, 245760, '0', 0, 6486.747, -795.6044, 1664.717, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+37, 269261, 1676, 8524, 8524, 245760, '0', 0, 6389.573, -795.6044, 1652.382, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+38, 253126, 1676, 8524, 8524, 245760, '0', 0, 5831.302, -796.2049, 2957.74, 0.004934316, 0, 0, 0.002467155, 0.999997, 604800, 255, 1, 25961), -- Instance Portal (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+39, 267716, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+40, 267722, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+41, 267724, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+42, 268574, 1676, 8524, 8524, 245760, '0', 0, 6348.021, -795.5745, 1650.51, 1.570796, 0, 0, 0.7071066, 0.7071069, 604800, 255, 24, 25961), -- 0 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+43, 267703, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+44, 267702, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+45, 267700, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+46, 267706, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+47, 267705, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+48, 267704, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+49, 267711, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+50, 267710, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+51, 267708, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+52, 267715, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+53, 267714, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+54, 267713, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+55, 267712, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+56, 267719, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+57, 267718, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+58, 267717, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+59, 267723, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+60, 267721, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+61, 267720, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+62, 269987, 1676, 8524, 8524, 245760, '0', 0, 6676.665, -804.6313, 1527.098, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
-- (@OGUID+63, 233282, 1676, 8524, 8524, 245760, '0', 0, 6343.136, -794.096, 3013.96, 6.210965, 0, 0, -0.03610229, 0.9993481, 604800, 255, 1, 25961), -- Refreshment Table (Area: Tombe de Sargeras - Difficulty: Outil Raids) - !!! might be temporary spawn !!!
(@OGUID+64, 269256, 1676, 8524, 8524, 245760, '0', 0, 5964.035, -845.1113, 2982.594, 0.583428, 0.07358789, 0.02209663, 0.2867441, 0.9549211, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+65, 272386, 1676, 8524, 8524, 245760, '0', 0, 5828.875, -1273.423, 2788.735, 2.44346, 0, 0, 0.9396925, 0.3420205, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+66, 272385, 1676, 8524, 8524, 245760, '0', 0, 5769.848, -1224.092, 2788.735, 5.585054, 0, 0, -0.34202, 0.9396927, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+67, 269782, 1676, 8524, 8524, 245760, '0', 0, 5799.276, -1248.567, 2786.034, 4.01426, 0, 0, -0.9063072, 0.4226195, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+68, 269259, 1676, 8524, 8524, 245760, '0', 0, 5906.929, -928.6493, 2863.702, 5.512276, 0.06567383, -0.02664661, -0.3750353, 0.9242973, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+69, 272384, 1676, 8524, 8524, 245760, '0', 0, 5774.697, -1278.278, 2788.735, 0.8726639, 0, 0, 0.4226179, 0.9063079, 604800, 255, 1, 25961), -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+70, 269260, 1676, 8524, 8524, 245760, '0', 0, 5971.748, -1068.649, 2857.058, 5.23479, 0.005013466, -0.002898216, -0.5005102, 0.8657113, 604800, 255, 1, 25961); -- -Unknown- (Area: Tombe de Sargeras - Difficulty: Outil Raids)
-- (@OGUID+71, 181621, 1676, 8524, 8524, 245760, '8309', 0, 6409.144, -1080.289, 2881.561, 5.779568, 0, 0, -0.249156, 0.9684634, 604800, 255, 1, 25961); -- Soulwell (Area: Tombe de Sargeras - Difficulty: Outil Raids) - !!! might be temporary spawn !!!
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+70;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+1, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+2, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+3, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+4, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+5, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+6, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+7, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+8, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+9, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+10, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+11, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+12, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+13, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+14, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+15, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+16, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+17, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+18, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+19, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+20, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+21, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+22, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+23, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+24, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+25, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+26, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+27, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+28, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+29, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+30, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+31, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+32, 0, 0, 0, 1), -- -Unknown-
(@OGUID+33, 0, 0, 0, 1), -- -Unknown-
(@OGUID+34, 0, 0, 0, 1), -- -Unknown-
(@OGUID+35, 0, 0, 0, 1), -- -Unknown-
(@OGUID+36, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+37, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+39, 0, 0, 0, 1), -- -Unknown-
(@OGUID+40, 0, 0, 0, 1), -- -Unknown-
(@OGUID+41, 0, 0, 0, 1), -- -Unknown-
(@OGUID+42, 0, 0, 1, -0.00000004371139), -- 0
(@OGUID+43, 0, 0, 0, 1), -- -Unknown-
(@OGUID+44, 0, 0, 0, 1), -- -Unknown-
(@OGUID+45, 0, 0, 0, 1), -- -Unknown-
(@OGUID+46, 0, 0, 0, 1), -- -Unknown-
(@OGUID+47, 0, 0, 0, 1), -- -Unknown-
(@OGUID+48, 0, 0, 0, 1), -- -Unknown-
(@OGUID+49, 0, 0, 0, 1), -- -Unknown-
(@OGUID+50, 0, 0, 0, 1), -- -Unknown-
(@OGUID+51, 0, 0, 0, 1), -- -Unknown-
(@OGUID+52, 0, 0, 0, 1), -- -Unknown-
(@OGUID+53, 0, 0, 0, 1), -- -Unknown-
(@OGUID+54, 0, 0, 0, 1), -- -Unknown-
(@OGUID+55, 0, 0, 0, 1), -- -Unknown-
(@OGUID+56, 0, 0, 0, 1), -- -Unknown-
(@OGUID+57, 0, 0, 0, 1), -- -Unknown-
(@OGUID+58, 0, 0, 0, 1), -- -Unknown-
(@OGUID+59, 0, 0, 0, 1), -- -Unknown-
(@OGUID+60, 0, 0, 0, 1), -- -Unknown-
(@OGUID+61, 0, 0, 0, 1), -- -Unknown-
(@OGUID+62, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+63, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+64, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+65, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+66, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+67, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+68, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+69, 0, 0, 1, -0.00000004371139), -- -Unknown-
(@OGUID+70, 0, 0, 1, -0.00000004371139); -- -Unknown-

DELETE FROM `spell_target_position` WHERE (`ID`=248860 AND `EffectIndex`=0) OR (`ID`=235295 AND `EffectIndex`=0) OR (`ID`=235293 AND `EffectIndex`=0) OR (`ID`=233679 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(248860, 0, 1676, 6351.452, -799.5743, 3013.16, 25961), -- Spell: Téléportation des personnages-joueurs Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(235295, 0, 0, 0, 0, 0, 25961), -- Spell: Vestige d'espoir Efffect: 98 (SPELL_EFFECT_KNOCK_BACK)
(235293, 0, 1676, 6422.04, -803.26, 3022.21, 25961), -- Spell: Vestige d'espoir Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(233679, 0, 1676, 6402.85, -933.4, 3069.89, 25961); -- Spell: Confession Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_addon` WHERE `entry` IN (121495 /*121495 (Tears of Elune) - Shadowy Ghost Cosmetic Spawn Spell*/, 121110 /*121110 (Tears of Elune) - RShwayder Test 02*/, 121494 /*121494 (Hammer of Khaz'goroth) - Shadowy Ghost Cosmetic Spawn Spell*/, 121111 /*121111 (Hammer of Khaz'goroth) - RShwayder Test 02*/, 120368 /*120368 (The Desolate Host)*/, 118727 /*118727 (Spiritual Barrier) - Présence de l'esprit, Présence de l'esprit, Monde des esprits*/, 105422 /*105422 (Tidal Totem)*/, 118728 /*118728 (Ghastly Bonewarden) - Armure thoracique, Barrière spirituelle, Canalisation de l’ombre*/, 118729 /*118729 (Fallen Priestess) - Barrière spirituelle, Transfert d'âme*/, 118730 /*118730 (Soul Residue) - Barrière spirituelle, Transfert d'âme*/, 118715 /*118715 (Reanimated Templar) - Armure thoracique, Barrière spirituelle*/, 118460 /*118460 (Engine of Souls) - Barrière spirituelle*/, 118462 /*118462 (Soul Queen Dejahna) - Barrière spirituelle, Transfert d'âme*/, 118701 /*118701 (Spiritual Font) - Fonts spirituels, Barrière spirituelle, Transfert d'âme*/, 118699 /*118699 (Spiritual Font) - Fonts spirituels, Barrière spirituelle*/, 120240 /*120240 (Redeemed Essence) - Essence rachetée*/, 120988 /*120988 (Swirling Souls) - Ames tourbillonnantes*/, 121498 /*121498 (Twilight Soul) - Lune décroissante*/, 120851 /*120851 (Hippogryph Lord Varah) - Lune croissante, Monture monstre fantôme lunaire*/, 120188 /*120188 (Wailing Soul) - , Aura chatoyante*/, 120808 /*120808 (Lylth the Silent) - Lévitation, Lune croissante*/, 122847 /*122847 (Umbral Priestess) - Lune croissante*/, 118523 /*118523 (Huntress Kasparian) - Fantôme physique, Fantôme physique (monture)*/, 118518 /*118518 (Priestess Lunaspyre) - Fantôme lunaire*/, 120720 /*120720 (Temple Guard) - Lune croissante*/, 118182 /*118182 (Moon Stalker) - Fonts d'Elune*/, 122851 /*122851 (Umbral Archer) - Lune décroissante*/, 121718 /*121718 (Thal'kiel)*/, 120194 /*120194 (Ghostly Acolyte) - Échelle : 95-100%, Aura chatoyante*/, 120201 /*120201 (Spectral Guardian) - Aura chatoyante*/, 118374 /*118374 (Captain Yathae Moonstrike) - Fantôme lunaire*/, 121030 /*121030 (Fan'verg the Vicious) - Planer*/, 119054 /*119054 (Glaive Target)*/, 120196 /*120196 (Drifting Soul) - Échelle : 175%, Aura chatoyante*/, 120182 /*120182 (Tormented Priestess) - Échelle : 95-100%, Aura chatoyante*/, 120789 /*120789 (Lieutenant Silvermight) - Lune croissante*/, 117957 /*117957 (Tormented Soul) - Prisonnier de la Légion*/, 120721 /*120721 (Temple Archer) - Lune croissante*/, 120191 /*120191 (Eternal Soulguard) - Échelle : 95-100%, Aura chatoyante*/, 122850 /*122850 (Umbral Guard) - Lune décroissante*/, 121400 /*121400 (Accusator Gnazh)*/, 121399 /*121399 (Inquisitor Sebilus)*/, 120697 /*120697 (Worshiper of Elune) - Lune croissante*/, 116691 /*116691 (Belac)*/, 116689 /*116689 (Atrigan) - Faux d'os*/, 121473 /*121473 (Coercitor Nixa)*/, 118022 /*118022 (Infernal Chaosbringer) - Infernal (cosmétique)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(121495, 0, 0, 50331648, 1, 0, 0, 0, 0, '154441'), -- 121495 (Tears of Elune) - Shadowy Ghost Cosmetic Spawn Spell
(121110, 0, 0, 50331648, 1, 0, 0, 0, 0, '144373'), -- 121110 (Tears of Elune) - RShwayder Test 02
(121494, 0, 0, 50331648, 1, 0, 0, 0, 0, '154441'), -- 121494 (Hammer of Khaz'goroth) - Shadowy Ghost Cosmetic Spawn Spell
(121111, 0, 0, 50331648, 1, 0, 0, 0, 0, '144373'), -- 121111 (Hammer of Khaz'goroth) - RShwayder Test 02
(120368, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 120368 (The Desolate Host)
(118727, 0, 0, 0, 1, 0, 0, 0, 0, '235589 235629 235621'), -- 118727 (Spiritual Barrier) - Présence de l'esprit, Présence de l'esprit, Monde des esprits
(105422, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105422 (Tidal Totem)
(118728, 0, 0, 0, 1, 0, 0, 0, 0, '236513 235113 173746'), -- 118728 (Ghastly Bonewarden) - Armure thoracique, Barrière spirituelle, Canalisation de l’ombre
(118729, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- 118729 (Fallen Priestess) - Barrière spirituelle, Transfert d'âme
(118730, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- 118730 (Soul Residue) - Barrière spirituelle, Transfert d'âme
(118715, 0, 0, 0, 1, 0, 0, 0, 0, '236513 235113'), -- 118715 (Reanimated Templar) - Armure thoracique, Barrière spirituelle
(118460, 0, 0, 0, 1, 0, 0, 0, 0, '235113'), -- 118460 (Engine of Souls) - Barrière spirituelle
(118462, 0, 0, 0, 1, 0, 0, 0, 0, '235620 240851'), -- 118462 (Soul Queen Dejahna) - Barrière spirituelle, Transfert d'âme
(118701, 0, 0, 0, 1, 0, 0, 0, 0, '241577 235620 240851'), -- 118701 (Spiritual Font) - Fonts spirituels, Barrière spirituelle, Transfert d'âme
(118699, 0, 0, 0, 1, 0, 0, 0, 0, '241576 235113'), -- 118699 (Spiritual Font) - Fonts spirituels, Barrière spirituelle
(120240, 0, 0, 0, 1, 0, 0, 0, 0, '239638'), -- 120240 (Redeemed Essence) - Essence rachetée
(120988, 0, 0, 0, 1, 0, 0, 0, 0, '241118'), -- 120988 (Swirling Souls) - Ames tourbillonnantes
(121498, 0, 0, 33554432, 1, 0, 0, 0, 0, '240528'), -- 121498 (Twilight Soul) - Lune décroissante
(120851, 0, 63626, 50331648, 1, 0, 0, 0, 0, '240526 240917'), -- 120851 (Hippogryph Lord Varah) - Lune croissante, Monture monstre fantôme lunaire
(120188, 0, 0, 0, 1, 0, 0, 0, 0, '188236 244081'), -- 120188 (Wailing Soul) - , Aura chatoyante
(120808, 0, 0, 0, 1, 0, 0, 0, 0, '50195 240526'), -- 120808 (Lylth the Silent) - Lévitation, Lune croissante
(122847, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- 122847 (Umbral Priestess) - Lune croissante
(118523, 0, 75620, 0, 1, 0, 0, 0, 0, '234999 236324'), -- 118523 (Huntress Kasparian) - Fantôme physique, Fantôme physique (monture)
(118518, 0, 0, 0, 1, 0, 0, 0, 0, '235268'), -- 118518 (Priestess Lunaspyre) - Fantôme lunaire
(120720, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- 120720 (Temple Guard) - Lune croissante
(118182, 0, 0, 50331648, 1, 0, 0, 0, 0, '236357'), -- 118182 (Moon Stalker) - Fonts d'Elune
(122851, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- 122851 (Umbral Archer) - Lune décroissante
(121718, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121718 (Thal'kiel)
(120194, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- 120194 (Ghostly Acolyte) - Échelle : 95-100%, Aura chatoyante
(120201, 0, 0, 0, 1, 0, 0, 0, 0, '244081'), -- 120201 (Spectral Guardian) - Aura chatoyante
(118374, 0, 0, 0, 1, 0, 0, 0, 0, '235268'), -- 118374 (Captain Yathae Moonstrike) - Fantôme lunaire
(121030, 0, 0, 0, 1, 0, 0, 0, 0, '241309'), -- 121030 (Fan'verg the Vicious) - Planer
(119054, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 119054 (Glaive Target)
(120196, 0, 0, 50331648, 1, 0, 0, 0, 0, '222912 244081'), -- 120196 (Drifting Soul) - Échelle : 175%, Aura chatoyante
(120182, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- 120182 (Tormented Priestess) - Échelle : 95-100%, Aura chatoyante
(120789, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- 120789 (Lieutenant Silvermight) - Lune croissante
(117957, 0, 0, 0, 1, 0, 0, 0, 0, '235305'), -- 117957 (Tormented Soul) - Prisonnier de la Légion
(120721, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- 120721 (Temple Archer) - Lune croissante
(120191, 0, 0, 0, 1, 0, 0, 0, 0, '123167 244081'), -- 120191 (Eternal Soulguard) - Échelle : 95-100%, Aura chatoyante
(122850, 0, 0, 0, 1, 0, 0, 0, 0, '240528'), -- 122850 (Umbral Guard) - Lune décroissante
(121400, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121400 (Accusator Gnazh)
(121399, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121399 (Inquisitor Sebilus)
(120697, 0, 0, 0, 1, 0, 0, 0, 0, '240526'), -- 120697 (Worshiper of Elune) - Lune croissante
(116691, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116691 (Belac)
(116689, 0, 0, 0, 1, 0, 0, 0, 0, '233423'), -- 116689 (Atrigan) - Faux d'os
(121473, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121473 (Coercitor Nixa)
(118022, 0, 0, 0, 1, 0, 0, 0, 0, '242907'); -- 118022 (Infernal Chaosbringer) - Infernal (cosmétique)

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=32639; -- 32639 (Gnimo)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=32638; -- 32638 (Hakmud of Argus)

DELETE FROM `creature_template_scaling` WHERE `Entry`=120784;
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(120784, 0, 25961);


DELETE FROM `creature_model_info` WHERE `DisplayID` IN (76104, 76105, 76138, 76059, 76139, 74496, 74861, 76005, 75975, 75933, 74874, 74775, 75673, 75672, 75671, 75675, 74748, 76069, 75665, 75923, 75669, 75664, 75663, 75960, 75615, 75937, 75925, 75668, 75934, 75930, 75924, 74283, 76099, 75099);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(76104, 0.7, 1.5, 0, 25961),
(76105, 0.7, 1.5, 0, 25961),
(76138, 0.4279, 1.65, 0, 25961),
(76059, 0.3672, 1.8, 0, 25961),
(76139, 0.56405, 2.175, 0, 25961),
(74496, 18.45296, 12, 0, 25961),
(74861, 0.765, 3.75, 0, 25961),
(76005, 0.3825, 1.875, 0, 25961),
(75975, 0.3825, 1.875, 0, 25961),
(75933, 0.3519, 1.725, 0, 25961),
(74874, 0.8086742, 5, 0, 25961),
(74775, 0.612, 4, 0, 25961),
(75673, 0.3366, 1.65, 0, 25961),
(75672, 0.3366, 1.65, 0, 25961),
(75671, 0.3366, 1.65, 0, 25961),
(75675, 0.7696956, 1.5, 0, 25961),
(74748, 0.612, 4, 0, 25961),
(76069, 0.6885, 3.375, 0, 25961),
(75665, 0.4743, 2.325, 0, 25961),
(75923, 0.306, 1.5, 0, 25961),
(75669, 0.44735, 1.725, 0, 25961),
(75664, 0.4743, 2.325, 0, 25961),
(75663, 0.4743, 2.325, 0, 25961),
(75960, 0.3825, 1.875, 0, 25961),
(75615, 5.853109, 4, 0, 25961),
(75937, 0.3519, 1.725, 0, 25961),
(75925, 0.306, 1.5, 0, 25961),
(75668, 0.44735, 1.725, 0, 25961),
(75934, 0.3825, 1.875, 0, 25961),
(75930, 0.306, 1.5, 0, 25961),
(75924, 0.306, 1.5, 0, 25961),
(74283, 4.491861, 9, 0, 25961),
(76099, 2.676251, 4.5, 0, 25961),
(75099, 2.332612, 6.5, 0, 25961);

UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=23501;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=21342;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=69144;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=28282;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=28111;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=30779;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=65995;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=70551;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=65812;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=63747;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=64719;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=118728 AND `ID`=1) OR (`CreatureID`=118729 AND `ID`=1) OR (`CreatureID`=118715 AND `ID`=1) OR (`CreatureID`=118462 AND `ID`=1) OR (`CreatureID`=120851 AND `ID`=1) OR (`CreatureID`=118523 AND `ID`=1) OR (`CreatureID`=118518 AND `ID`=1) OR (`CreatureID`=120720 AND `ID`=1) OR (`CreatureID`=122851 AND `ID`=1) OR (`CreatureID`=120194 AND `ID`=1) OR (`CreatureID`=118374 AND `ID`=1) OR (`CreatureID`=121030 AND `ID`=1) OR (`CreatureID`=120182 AND `ID`=1) OR (`CreatureID`=120789 AND `ID`=1) OR (`CreatureID`=120721 AND `ID`=1) OR (`CreatureID`=120191 AND `ID`=1) OR (`CreatureID`=122850 AND `ID`=1) OR (`CreatureID`=121400 AND `ID`=1) OR (`CreatureID`=116689 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(118728, 1, 82813, 0, 0, 116914, 0, 0, 0, 0, 0), -- Ghastly Bonewarden
(118729, 1, 12532, 0, 0, 0, 0, 0, 0, 0, 0), -- Fallen Priestess
(118715, 1, 119707, 0, 0, 0, 0, 0, 0, 0, 0), -- Reanimated Templar
(118462, 1, 18609, 0, 0, 0, 0, 0, 0, 0, 0), -- Soul Queen Dejahna
(120851, 1, 0, 0, 0, 0, 0, 0, 128829, 0, 0), -- Hippogryph Lord Varah
(118523, 1, 144320, 0, 0, 144321, 0, 0, 0, 0, 0), -- Huntress Kasparian
(118518, 1, 94840, 0, 0, 0, 0, 0, 0, 0, 0), -- Priestess Lunaspyre
(120720, 1, 127142, 0, 0, 43222, 0, 0, 0, 0, 0), -- Temple Guard
(122851, 1, 0, 0, 0, 0, 0, 0, 43928, 0, 0), -- Umbral Archer
(120194, 1, 126525, 0, 0, 0, 0, 0, 0, 0, 0), -- Ghostly Acolyte
(118374, 1, 23225, 0, 0, 74051, 0, 0, 144237, 0, 0), -- Captain Yathae Moonstrike
(121030, 1, 34182, 0, 0, 0, 0, 0, 0, 0, 0), -- Fan'verg the Vicious
(120182, 1, 116572, 0, 0, 0, 0, 0, 0, 0, 0), -- Tormented Priestess
(120789, 1, 141345, 0, 0, 144321, 0, 0, 0, 0, 0), -- Lieutenant Silvermight
(120721, 1, 0, 0, 0, 0, 0, 0, 43928, 0, 0), -- Temple Archer
(120191, 1, 126521, 0, 0, 120261, 0, 0, 0, 0, 0), -- Eternal Soulguard
(122850, 1, 127142, 0, 0, 43222, 0, 0, 0, 0, 0), -- Umbral Guard
(121400, 1, 132821, 0, 0, 0, 0, 0, 0, 0, 0), -- Accusator Gnazh
(116689, 1, 143627, 0, 0, 0, 0, 0, 0, 0, 0); -- Atrigan



UPDATE `creature_template` SET `faction`=94, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1140852736 WHERE `entry`=121495; -- Tears of Elune
UPDATE `creature_template` SET `faction`=94, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=121110; -- Tears of Elune
UPDATE `creature_template` SET `faction`=94, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1140852736 WHERE `entry`=121494; -- Hammer of Khaz'goroth
UPDATE `creature_template` SET `faction`=94, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=121111; -- Hammer of Khaz'goroth
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=320, `unit_flags2`=67108864, `unit_flags3`=1 WHERE `entry`=120368; -- The Desolate Host
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=118727; -- Spiritual Barrier
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `faction`=58, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432 WHERE `entry`=105422; -- Tidal Totem
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=32639; -- Gnimo
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=3.6, `speed_run`=1.285714, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags2`=2097152 WHERE `entry`=118728; -- Ghastly Bonewarden
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=3.6, `speed_run`=1.285714, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2097152 WHERE `entry`=118729; -- Fallen Priestess
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=1.6, `speed_run`=0.5714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2097152 WHERE `entry`=118730; -- Soul Residue
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=3.6, `speed_run`=1.285714, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags2`=2097152 WHERE `entry`=118715; -- Reanimated Templar
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=64, `unit_flags2`=2129920 WHERE `entry`=118460; -- Engine of Souls
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=64, `unit_flags2`=2097152 WHERE `entry`=118462; -- Soul Queen Dejahna
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=69765120, `unit_flags3`=1 WHERE `entry`=118701; -- Spiritual Font
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=69240832, `unit_flags3`=1 WHERE `entry`=118699; -- Spiritual Font
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=614, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33588032, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=120240; -- Redeemed Essence
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=69208064 WHERE `entry`=120988; -- Swirling Souls
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=121498; -- Twilight Soul
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=1917, `speed_walk`=3.2, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=120851; -- Hippogryph Lord Varah
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=120188; -- Wailing Soul
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=1917, `speed_walk`=2, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=120808; -- Lylth the Silent
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=1917, `speed_walk`=1.2, `speed_run`=1.714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122847; -- Umbral Priestess
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=118523; -- Huntress Kasparian
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=4196352 WHERE `entry`=118518; -- Priestess Lunaspyre
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=1917, `speed_walk`=1.2, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=120720; -- Temple Guard
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4229120, `unit_flags3`=1 WHERE `entry`=118182; -- Moon Stalker
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=1917, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122851; -- Umbral Archer
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=121718; -- Thal'kiel
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=120194; -- Ghostly Acolyte
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=120201; -- Spectral Guardian
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=4196352 WHERE `entry`=118374; -- Captain Yathae Moonstrike
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=121030; -- Fan'verg the Vicious
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=119054; -- Glaive Target
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33588032, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=120196; -- Drifting Soul
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=120182; -- Tormented Priestess
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=1917, `speed_walk`=1.2, `speed_run`=1.714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=120789; -- Lieutenant Silvermight
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=117957; -- Tormented Soul
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=1917, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=120721; -- Temple Archer
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=120191; -- Eternal Soulguard
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=1917, `speed_walk`=1.2, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122850; -- Umbral Guard
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=121400; -- Accusator Gnazh
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=121399; -- Inquisitor Sebilus
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `speed_walk`=1.2, `speed_run`=1.714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=120697; -- Worshiper of Elune
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=1073741824 WHERE `entry`=116691; -- Belac
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=1073741824 WHERE `entry`=116689; -- Atrigan
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=121473; -- Coercitor Nixa
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=1.2, `speed_run`=0.4285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2099200 WHERE `entry`=118022; -- Infernal Chaosbringer

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (118699, 118701, 121111, 121110);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(118699, 235732, 0, 0),
(118701, 235590, 0, 0),
(121111, 190910, 0, 0),
(121110, 190910, 0, 0);

DELETE FROM `creature_template` WHERE `entry`=131072;
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(131072, 0, 0, 79002, 0, 0, 0, 'Voidstalker', NULL, NULL, NULL, NULL, 0, 0, 0, 0, 161, 1, 1, 0, 1, 1, 0, 43, 25961); -- Traqueur du Vide

UPDATE `creature_template` SET `modelid1`=76104, `HealthScalingExpansion`=6, `RequiredExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=121495; -- Tears of Elune
UPDATE `creature_template` SET `modelid1`=76104, `HealthScalingExpansion`=6, `RequiredExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=121110; -- Tears of Elune
UPDATE `creature_template` SET `modelid1`=18783, `modelid2`=21342, `IconName`='interact', `HealthScalingExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=118924; -- Engine of Souls
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=111374; -- Xal'atath
UPDATE `creature_template` SET `modelid1`=75101, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097260, `type_flags2`=128, `HealthModifier`=75.0469, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=119205; -- Moontalon
UPDATE `creature_template` SET `modelid1`=75960, `HealthScalingExpansion`=5, `rank`=1, `type`=6, `type_flags`=3145800, `HealthModifier`=200, `movementId`=165, `VerifiedBuild`=25961 WHERE `entry`=120989; -- Echo Stalker
UPDATE `creature_template` SET `modelid1`=16925, `modelid2`=1060, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=120987; -- Moon Strike Line Invisible Stalker
UPDATE `creature_template` SET `KillCredit1`=125121, `modelid1`=78341, `modelid2`=78343, `HealthScalingExpansion`=6, `type`=3, `HealthModifier`=3, `VerifiedBuild`=25961 WHERE `entry`=125129; -- Tireuse funeste nathraxéenne
UPDATE `creature_template` SET `modelid1`=76105, `HealthScalingExpansion`=6, `RequiredExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=121494; -- Hammer of Khaz'goroth
UPDATE `creature_template` SET `modelid1`=76105, `HealthScalingExpansion`=6, `RequiredExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=121111; -- Hammer of Khaz'goroth
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=23501, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097260, `type_flags2`=65536, `HealthModifier`=400, `ManaModifier`=30, `VerifiedBuild`=25961 WHERE `entry`=120368; -- The Desolate Host
UPDATE `creature_template` SET `modelid1`=18783, `modelid2`=21342, `IconName`='interact', `HealthScalingExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=118727; -- Spiritual Barrier
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25961 WHERE `entry`=15705; -- Petite assistante de l'Hiver
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25961 WHERE `entry`=53006; -- Spirit Link Totem
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25961 WHERE `entry`=100099; -- Voodoo Totem
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `type`=11, `VerifiedBuild`=25961 WHERE `entry`=59764; -- Healing Tide Totem
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=105422; -- Tidal Totem
UPDATE `creature_template` SET `modelid1`=25204, `HealthScalingExpansion`=6, `RequiredExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=118562; -- Remnant of Hope
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25961 WHERE `entry`=3527; -- Healing Stream Totem
UPDATE `creature_template` SET `modelid1`=1126, `modelid2`=11686, `HealthScalingExpansion`=4, `type_flags`=1024, `movementId`=187, `VerifiedBuild`=25961 WHERE `entry`=73400; -- Healing Ran Invisible Stalker DND
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25961 WHERE `entry`=2630; -- Earthbind Totem
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=11686, `HealthScalingExpansion`=6, `rank`=1, `type`=10, `type_flags`=17826816, `VerifiedBuild`=25961 WHERE `entry`=124815; -- Fel Line Stalker
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type`=11, `VerifiedBuild`=25961 WHERE `entry`=60849; -- Jade Serpent Statue
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=51677; -- Bébé de Berceau-de-l’Hiver
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=32639; -- Gnimo
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=32638; -- Hakmud of Argus
UPDATE `creature_template` SET `modelid1`=76059, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=46.06875, `movementId`=138, `VerifiedBuild`=25961 WHERE `entry`=118729; -- Fallen Priestess
UPDATE `creature_template` SET `modelid1`=76138, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=25, `movementId`=138, `VerifiedBuild`=25961 WHERE `entry`=118728; -- Ghastly Bonewarden
UPDATE `creature_template` SET `modelid1`=30779, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=4.3875, `movementId`=84, `VerifiedBuild`=25961 WHERE `entry`=118730; -- Soul Residue
UPDATE `creature_template` SET `modelid1`=74496, `HealthScalingExpansion`=6, `rank`=1, `type`=9, `type_flags`=2097260, `type_flags2`=65664, `HealthModifier`=1239, `ManaModifier`=30, `VerifiedBuild`=25961 WHERE `entry`=118460; -- Engine of Souls
UPDATE `creature_template` SET `modelid1`=76139, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=40, `movementId`=138, `VerifiedBuild`=25961 WHERE `entry`=118715; -- Reanimated Templar
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=11686, `IconName`='interact', `HealthScalingExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=118699; -- Spiritual Font
UPDATE `creature_template` SET `modelid1`=74861, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097260, `type_flags2`=65664, `HealthModifier`=1239, `ManaModifier`=30, `VerifiedBuild`=25961 WHERE `entry`=118462; -- Soul Queen Dejahna
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=11686, `IconName`='interact', `HealthScalingExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=118701; -- Spiritual Font
UPDATE `creature_template` SET `modelid1`=64055, `modelid2`=11686, `HealthScalingExpansion`=6, `type`=6, `type_flags`=2097224, `HealthModifier`=6, `VerifiedBuild`=25961 WHERE `entry`=120240; -- Redeemed Essence
UPDATE `creature_template` SET `modelid1`=18783, `modelid2`=65995, `IconName`='interact', `HealthScalingExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=120988; -- Swirling Souls
UPDATE `creature_template` SET `modelid1`=70551, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=200, `VerifiedBuild`=25961 WHERE `entry`=121498; -- Twilight Soul
UPDATE `creature_template` SET `modelid1`=76005, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2099272, `HealthModifier`=120, `movementId`=187, `VerifiedBuild`=25961 WHERE `entry`=120851; -- Hippogryph Lord Varah
UPDATE `creature_template` SET `modelid1`=65812, `HealthScalingExpansion`=6, `type`=6, `type_flags`=2097224, `HealthModifier`=6, `VerifiedBuild`=25961 WHERE `entry`=120188; -- Wailing Soul
UPDATE `creature_template` SET `modelid1`=75975, `HealthScalingExpansion`=5, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=120, `movementId`=184, `VerifiedBuild`=25961 WHERE `entry`=120808; -- Lylth the Silent
UPDATE `creature_template` SET `modelid1`=75933, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=40, `movementId`=165, `VerifiedBuild`=25961 WHERE `entry`=122847; -- Umbral Priestess
UPDATE `creature_template` SET `modelid1`=74775, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097260, `type_flags2`=128, `HealthModifier`=1400, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=118518; -- Priestess Lunaspyre
UPDATE `creature_template` SET `modelid1`=75934, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=50, `movementId`=165, `VerifiedBuild`=25961 WHERE `entry`=120720; -- Temple Guard
UPDATE `creature_template` SET `modelid1`=75937, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=45, `VerifiedBuild`=25961 WHERE `entry`=122851; -- Umbral Archer
UPDATE `creature_template` SET `modelid1`=29297, `modelid2`=11686, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=121718; -- Thal'kiel
UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=68857, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=118182; -- Moon Stalker
UPDATE `creature_template` SET `modelid1`=74874, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2099308, `type_flags2`=128, `HealthModifier`=1400, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=118523; -- Huntress Kasparian
UPDATE `creature_template` SET `modelid1`=74748, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097260, `type_flags2`=128, `HealthModifier`=1400, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=118374; -- Captain Yathae Moonstrike
UPDATE `creature_template` SET `modelid1`=75675, `HealthScalingExpansion`=6, `family`=2, `type`=6, `type_flags`=2097224, `HealthModifier`=22, `VerifiedBuild`=25961 WHERE `entry`=120201; -- Spectral Guardian
UPDATE `creature_template` SET `modelid1`=75671, `modelid2`=75672, `modelid3`=75673, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=45, `VerifiedBuild`=25961 WHERE `entry`=120194; -- Ghostly Acolyte
UPDATE `creature_template` SET `modelid1`=45580, `modelid2`=11686, `HealthScalingExpansion`=6, `rank`=1, `type`=10, `type_flags`=1048576, `HealthModifier`=3, `VerifiedBuild`=25961 WHERE `entry`=119054; -- Glaive Target
UPDATE `creature_template` SET `modelid1`=65812, `HealthScalingExpansion`=6, `type`=6, `type_flags`=2097224, `HealthModifier`=6, `VerifiedBuild`=25961 WHERE `entry`=120196; -- Drifting Soul
UPDATE `creature_template` SET `modelid1`=76069, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=80, `VerifiedBuild`=25961 WHERE `entry`=121030; -- Fan'verg the Vicious
UPDATE `creature_template` SET `modelid1`=75663, `modelid2`=75664, `modelid3`=75665, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=70, `VerifiedBuild`=25961 WHERE `entry`=120182; -- Tormented Priestess
UPDATE `creature_template` SET `modelid1`=75668, `modelid2`=75669, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=55, `VerifiedBuild`=25961 WHERE `entry`=120191; -- Eternal Soulguard
UPDATE `creature_template` SET `modelid1`=75960, `HealthScalingExpansion`=5, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=120, `movementId`=165, `VerifiedBuild`=25961 WHERE `entry`=120789; -- Lieutenant Silvermight
UPDATE `creature_template` SET `modelid1`=75934, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=50, `movementId`=165, `VerifiedBuild`=25961 WHERE `entry`=122850; -- Umbral Guard
UPDATE `creature_template` SET `modelid1`=75937, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=45, `VerifiedBuild`=25961 WHERE `entry`=120721; -- Temple Archer
UPDATE `creature_template` SET `modelid1`=75615, `HealthScalingExpansion`=6, `rank`=1, `type`=15, `type_flags`=2097228, `type_flags2`=128, `HealthModifier`=999, `ManaModifier`=50, `VerifiedBuild`=25961 WHERE `entry`=117957; -- Tormented Soul
UPDATE `creature_template` SET `modelid1`=75923, `modelid2`=75924, `modelid3`=75925, `modelid4`=75930, `HealthScalingExpansion`=6, `rank`=1, `type`=6, `type_flags`=2097224, `HealthModifier`=9, `movementId`=165, `VerifiedBuild`=25961 WHERE `entry`=120697; -- Worshiper of Elune
UPDATE `creature_template` SET `modelid1`=74282, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=270532716, `type_flags2`=128, `HealthModifier`=1500, `movementId`=180, `VerifiedBuild`=25961 WHERE `entry`=116689; -- Atrigan
UPDATE `creature_template` SET `modelid1`=74283, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097260, `type_flags2`=128, `HealthModifier`=1500, `VerifiedBuild`=25961 WHERE `entry`=116691; -- Belac
UPDATE `creature_template` SET `modelid1`=63747, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=270532680, `HealthModifier`=145, `movementId`=841, `VerifiedBuild`=25961 WHERE `entry`=121400; -- Accusator Gnazh
UPDATE `creature_template` SET `modelid1`=64719, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097224, `HealthModifier`=120, `VerifiedBuild`=25961 WHERE `entry`=121399; -- Inquisitor Sebilus
UPDATE `creature_template` SET `modelid1`=76099, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097224, `HealthModifier`=90, `movementId`=144, `VerifiedBuild`=25961 WHERE `entry`=121473; -- Coercitor Nixa
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=25961 WHERE `entry`=49799; -- Lord Victor Nefarius

