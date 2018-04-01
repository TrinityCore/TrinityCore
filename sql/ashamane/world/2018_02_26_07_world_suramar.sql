DELETE FROM `areatrigger_template` WHERE `Id` IN (10673, 12273, 11441, 10068, 11419, 9913, 11368, 10527, 9771, 13667);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(10673, 0, 4, 20, 20, 0, 0, 0, 0, 25996),
(12273, 0, 0, 4, 4, 0, 0, 0, 0, 25996),
(11441, 3, 0, 0, 0, 0, 0, 0, 0, 25996),
(10068, 4, 4, 4.5, 4.5, 5, 5, 0.3, 0.3, 25996),
(11419, 0, 0, 3, 3, 0, 0, 0, 0, 25996),
(9913, 4, 0, 4, 4, 4, 4, 0.3, 0.3, 25996),
(11368, 4, 0, 8, 8, 4, 4, 1, 1, 25996),
(10527, 3, 4, 0, 0, 0, 0, 0, 0, 25996),
(9771, 4, 2, 4, 4, 4, 4, 0.3, 0.3, 25996),
(13667, 0, 0, 5, 5, 0, 0, 0, 0, 25996);

UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10202;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10698;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=16572;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=13120;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10205;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=5802;
UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=2.5, `Data2`=3, `Data3`=2.5, `Data4`=2.5, `Data5`=3 WHERE `Id`=6197;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=3020;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11483;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11482;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11481;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11479;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11394;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11480;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12904;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12897;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10471;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12892;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=25996 WHERE `Id`=12892;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=8382;
UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=25996 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12968;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=13354;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=13353;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=13352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=13189;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=13188;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12922;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=3841;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=9181;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=13689;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12882;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12851;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=3921;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=13112;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12879;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12893;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12894;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=3153;
UPDATE `areatrigger_template` SET `Flags`=5 WHERE `Id`=10003;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11612;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12113;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11313;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=7567;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10714;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11791;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=6889 AND `AreaTriggerId`=11394) OR (`SpellMiscId`=7007 AND `AreaTriggerId`=11481) OR (`SpellMiscId`=7006 AND `AreaTriggerId`=11480) OR (`SpellMiscId`=7009 AND `AreaTriggerId`=11483) OR (`SpellMiscId`=7008 AND `AreaTriggerId`=11482) OR (`SpellMiscId`=7005 AND `AreaTriggerId`=11479) OR (`SpellMiscId`=5428 AND `AreaTriggerId`=6197) OR (`SpellMiscId`=8835 AND `AreaTriggerId`=12904) OR (`SpellMiscId`=8829 AND `AreaTriggerId`=12897) OR (`SpellMiscId`=5760 AND `AreaTriggerId`=10471) OR (`SpellMiscId`=8823 AND `AreaTriggerId`=12892) OR (`SpellMiscId`=8906 AND `AreaTriggerId`=12968) OR (`SpellMiscId`=9358 AND `AreaTriggerId`=13352) OR (`SpellMiscId`=9359 AND `AreaTriggerId`=13353) OR (`SpellMiscId`=9355 AND `AreaTriggerId`=13354) OR (`SpellMiscId`=8858 AND `AreaTriggerId`=12922)  OR (`SpellMiscId`=8813 AND `AreaTriggerId`=12882) OR (`SpellMiscId`=8767 AND `AreaTriggerId`=12851) OR (`SpellMiscId`=9070 AND `AreaTriggerId`=13112) OR (`SpellMiscId`=8771 AND `AreaTriggerId`=12851) OR (`SpellMiscId`=8810 AND `AreaTriggerId`=12879) OR (`SpellMiscId`=8825 AND `AreaTriggerId`=12893) OR (`SpellMiscId`=8826 AND `AreaTriggerId`=12894) OR (`SpellMiscId`=5985 AND `AreaTriggerId`=10673) OR (`SpellMiscId`=8007 AND `AreaTriggerId`=12273) OR (`SpellMiscId`=6940 AND `AreaTriggerId`=11441) OR (`SpellMiscId`=5355 AND `AreaTriggerId`=10068) OR (`SpellMiscId`=6915 AND `AreaTriggerId`=11419) OR (`SpellMiscId`=5186 AND `AreaTriggerId`=9913) OR (`SpellMiscId`=6847 AND `AreaTriggerId`=11368) OR (`SpellMiscId`=5821 AND `AreaTriggerId`=10527) OR (`SpellMiscId`=5053 AND `AreaTriggerId`=9771) OR (`SpellMiscId`=7790 AND `AreaTriggerId`=12113) OR (`SpellMiscId`=9703 AND `AreaTriggerId`=13667) OR (`SpellMiscId`=2946 AND `AreaTriggerId`=7567) OR (`SpellMiscId`=7341 AND `AreaTriggerId`=11791);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(6889, 11394, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 206797
(7007, 11481, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 212589
(7006, 11480, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 212588
(7009, 11483, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 212591
(7008, 11482, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 212590
(7005, 11479, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 212585
(5428, 6197, 0, 0, 0, 0, 0, 0, 15000, 25996), -- SpellId : 234199
(8835, 12904, 0, 0, 0, 0, 87, 0, 0, 25996), -- SpellId : 228121
(8829, 12897, 0, 0, 0, 0, 0, 15000, 15000, 25996), -- SpellId : 228027
(5760, 10471, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 198839
(8823, 12892, 0, 0, 0, 0, 105, 0, 500, 25996), -- SpellId : 227992
(8906, 12968, 0, 2342, 0, 0, 0, 1880, 4000, 25996), -- SpellId : 228853
(9358, 13352, 0, 0, 0, 0, 115, 0, 5000, 25996), -- SpellId : 232804
(9359, 13353, 0, 0, 0, 0, 116, 0, 5000, 25996), -- SpellId : 232805
(9355, 13354, 0, 0, 0, 0, 117, 0, 5000, 25996), -- SpellId : 232801
(8858, 12922, 0, 2317, 0, 0, 91, 0, 60000, 25996), -- SpellId : 228370
(8813, 12882, 0, 0, 0, 0, 0, 0, 300000, 25996), -- SpellId : 227804
(8767, 12851, 0, 0, 0, 0, 0, 0, 35000, 25996), -- SpellId : 227448
(9070, 13112, 0, 0, 0, 0, 0, 0, 30000, 25996), -- SpellId : 230141
(8771, 12851, 0, 0, 0, 0, 0, 0, 35000, 25996), -- SpellId : 227456
(8810, 12879, 0, 0, 0, 0, 0, 12500, 12500, 25996), -- SpellId : 227782
(8825, 12893, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 228006
(8826, 12894, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 228016
(5985, 10673, 0, 0, 0, 0, 0, 0, 120000, 25996), -- SpellId : 203882
(8007, 12273, 0, 0, 0, 0, 26, 0, 20000, 25996), -- SpellId : 220441
(6940, 11441, 0, 0, 0, 0, 0, 8286, 20000, 25996), -- SpellId : 212030
(5355, 10068, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 197542
(6915, 11419, 0, 0, 0, 0, 0, 0, 20000, 25996), -- SpellId : 211744
(5186, 9913, 0, 0, 0, 0, 0, 0, 15000, 25996), -- SpellId : 195523
(6847, 11368, 0, 0, 0, 0, 0, 0, 30000, 25996), -- SpellId : 211037
(5821, 10527, 0, 0, 0, 0, 0, 0, 5000, 25996), -- SpellId : 202223
(5053, 9771, 0, 1611, 1606, 0, 0, 0, 30000, 25996), -- SpellId : 193942
(7790, 12113, 0, 0, 0, 0, 0, 1114, 15000, 25996), -- SpellId : 218850
(9703, 13667, 0, 0, 0, 0, 0, 0, 15000, 25996), -- SpellId : 235917
(2946, 7567, 0, 0, 0, 0, 0, 0, 6000, 25996), -- SpellId : 169001
(7341, 11791, 0, 0, 0, 0, 0, 0, 30000, 25996); -- SpellId : 215131

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=5977 AND `AreaTriggerId`=10665); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=6710 AND `AreaTriggerId`=11266); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=5972 AND `AreaTriggerId`=10660); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=90000 WHERE (`SpellMiscId`=7478 AND `AreaTriggerId`=11908); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=5280 AND `AreaTriggerId`=10003); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6006 AND `AreaTriggerId`=10698); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=11884, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12002 AND `AreaTriggerId`=16713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=15000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=11883 AND `AreaTriggerId`=16572); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=6500, `TimeToTargetScale`=10000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=9080 AND `AreaTriggerId`=13120); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2548, `TimeToTargetScale`=3000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=55999, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2495 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=1489 AND `AreaTriggerId`=5802); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8284 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6026 AND `AreaTriggerId`=10713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1441, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=4114, `TimeToTargetScale`=3000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=9141, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1668, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=70, `TimeToTarget`=0, `TimeToTargetScale`=1000 WHERE (`SpellMiscId`=8430 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1500, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6814 WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2800, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=1250 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=561, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=314 AND `AreaTriggerId`=3020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1996 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2605, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6039 AND `AreaTriggerId`=10727); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2898, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1518, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4928 AND `AreaTriggerId`=9645); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6000 WHERE (`SpellMiscId`=6321 AND `AreaTriggerId`=10991); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3425, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2682 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7999 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1429, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1822, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2831, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2782, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7998 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2923, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2105 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3590, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=3691 AND `AreaTriggerId`=8382); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1310, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1250, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=984, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1430, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1342, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1253, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7038, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1512, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1548, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1450, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1479, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1457, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2341, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9449 AND `AreaTriggerId`=13436); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1797, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1446, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1445, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1694, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2808, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1619 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1755, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2806, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1786, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2393, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=894, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1585, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=63720, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=989, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1026, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1487, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1492, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1481, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1478, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1470, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1475, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1471, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1480, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1494, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1498, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1537, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1358, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1608, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1599, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1590, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1602, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1863, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1223, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=750, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2585, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1499, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=759, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1549, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1516, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2851, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1442, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3215, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=658 AND `AreaTriggerId`=3921); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2043, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1358, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2801, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1515, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1516, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2215, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9569, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3577, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10813, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9336, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10767, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10978, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9631, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10692, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9625, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10017, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9619, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10741, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9563, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10461, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10247, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10821, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8425 AND `AreaTriggerId`=12579); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=600000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=337 AND `AreaTriggerId`=3153); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6878 AND `AreaTriggerId`=11382); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6622 AND `AreaTriggerId`=11209); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=7158 AND `AreaTriggerId`=11612); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1468, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1285, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1438, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1439, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=461, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1463, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=42224, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1428, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1071, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1258, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1084, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=896, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=992, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=897, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1435, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1447, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=895, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1434, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1462, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1466, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6818 AND `AreaTriggerId`=11346); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1441, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1484, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1641, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=93218, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=95132, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1436, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1431, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1472, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1474, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1476, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=46811, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1518, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=46330, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1437, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=95259, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1265, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=90888, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1465, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=90887, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=56790, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=57407, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9683, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3570, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=7263 AND `AreaTriggerId`=11719); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=758, `TimeToTargetScale`=3000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5503 AND `AreaTriggerId`=10205); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1432, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=40930, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=115949, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=76216, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=52315, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=133551, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=48643, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=44216, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=154171, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=84663, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=78608, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=120192, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=51964, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=112824, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=98618, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=153586, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=78841, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=77970, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=75941, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=42071, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=146907, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=83371, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=123551, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=51374, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=49550, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=64053, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=88363, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=166938, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=52587, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=91450, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=92076, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=93291, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=129874, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=183003, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=103576, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=17, `TimeToTarget`=107696, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=6919 AND `AreaTriggerId`=11422); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=76239, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=82000, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=41210, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=104747, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=34468, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=64777, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=57235, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=129021, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=49740, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=101562, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=81812, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=154161, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=77970, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=130415, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=66608, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=100133, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=57926, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=125711, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=49419, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=174032, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=68584, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=49492, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=76268, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=64023, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=123693, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=66711, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=62121, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=66398, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=119998, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=54436, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=146816, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=111311, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=175044, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6683 AND `AreaTriggerId`=11313); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=7363 AND `AreaTriggerId`=12515); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6027 AND `AreaTriggerId`=10714); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2000 WHERE (`SpellMiscId`=6039 AND `AreaTriggerId`=10727); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1611, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1131, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1020, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1613, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1610, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2170, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1561, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1633, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5768, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=7296, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=7000, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10104 AND `AreaTriggerId`=14978); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=7597 AND `AreaTriggerId`=12013); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=7179 AND `AreaTriggerId`=12770); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=585, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2439, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1664, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1217, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2374, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2518, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1748, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2496, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1761, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1743, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5915, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=4382, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=6470, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=4935, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=13334, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=4378, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=11973, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=4093, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5814, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=7208, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=6214, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=6768, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=6300, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=14270, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=7617, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5075, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=13775, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6505 WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10382, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8743, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=6729, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10222, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8716, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9095, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10156, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9175, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10195, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10397, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8666, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8785, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8788, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8800, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10394, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10212, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8968, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=8698, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=9951 AND `AreaTriggerId`=14843); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=3540 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=3273 AND `Idx`=1) OR (`ConversationId`=3273 AND `Idx`=0) OR (`ConversationId`=3259 AND `ConversationActorId`=49625 AND `Idx`=0) OR (`ConversationId`=3917 AND `ConversationActorId`=55620 AND `Idx`=0) OR (`ConversationId`=3910 AND `Idx`=1) OR (`ConversationId`=3910 AND `Idx`=2) OR (`ConversationId`=3910 AND `Idx`=0) OR (`ConversationId`=4114 AND `Idx`=0) OR (`ConversationId`=3916 AND `ConversationActorId`=55620 AND `Idx`=0) OR (`ConversationId`=4009 AND `ConversationActorId`=53609 AND `Idx`=0) OR (`ConversationId`=2970 AND `Idx`=0) OR (`ConversationId`=3821 AND `Idx`=0) OR (`ConversationId`=3821 AND `Idx`=2) OR (`ConversationId`=3821 AND `Idx`=1) OR (`ConversationId`=2968 AND `Idx`=0) OR (`ConversationId`=2547 AND `ConversationActorId`=50835 AND `Idx`=0) OR (`ConversationId`=3797 AND `Idx`=0) OR (`ConversationId`=3801 AND `ConversationActorId`=51629 AND `Idx`=0) OR (`ConversationId`=2546 AND `ConversationActorId`=50835 AND `Idx`=0) OR (`ConversationId`=2969 AND `Idx`=0) OR (`ConversationId`=2972 AND `Idx`=0) OR (`ConversationId`=2971 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(3540, 53609, 0, 25996),
-- (3273, UNKNOWN, 1, 25996), -- Full: 0x243CD4BE006556400056E600001155EC Vehicle/0 R3893/S22246 Map: Le Cauchemar d’émeraude Entry: 103769 (Xavius) Low: 1136108
-- (3273, UNKNOWN, 0, 25996), -- Full: 0x203CD4BE0066C7400056E600001155FA Creature/0 R3893/S22246 Map: Le Cauchemar d’émeraude Entry: 105245 (Dream of Ysera) Low: 1136122
(3259, 49625, 0, 25996),
(3917, 55620, 0, 25996),
-- (3910, UNKNOWN, 1, 25996), -- Full: 0x2016EC988070A2800047B20000910BE7 Creature/0 R1467/S18354 Map: Îles Brisées Entry: 115338 (Rebellious Citizen) Low: 9505767
-- (3910, UNKNOWN, 2, 25996), -- Full: 0x2016EC988070A2800047B20001110BE7 Creature/0 R1467/S18354 Map: Îles Brisées Entry: 115338 (Rebellious Citizen) Low: 17894375
-- (3910, UNKNOWN, 0, 25996), -- Full: 0x2016EC988070A2800047B20000110BE7 Creature/0 R1467/S18354 Map: Îles Brisées Entry: 115338 (Rebellious Citizen) Low: 1117159
-- (4114, UNKNOWN, 0, 25996), -- Full: 0x2016F4CE006FAE000037260000115170 Creature/0 R1469/S14118 Map: Le Jugement des Valeureux Entry: 114360 (Hyrja) Low: 1134960
(3916, 55620, 0, 25996),
(4009, 53609, 0, 25996),
-- (2970, UNKNOWN, 0, 25996), -- Full: 0x2016EC98806BF2800047B20000114D56 Creature/0 R1467/S18354 Map: Îles Brisées Entry: 110538 (Valewalker Farodin) Low: 1133910
-- (3821, UNKNOWN, 0, 25996), -- Full: 0x2016F4CE006F95C00037260000115170 Creature/0 R1469/S14118 Map: Le Jugement des Valeureux Entry: 114263 (Odyn) Low: 1134960
-- (3821, UNKNOWN, 2, 25996), -- Full: 0x2016F4CE006FAE000037260000115170 Creature/0 R1469/S14118 Map: Le Jugement des Valeureux Entry: 114360 (Hyrja) Low: 1134960
-- (3821, UNKNOWN, 1, 25996), -- Full: 0x2016F4CE006FAE400037260000115170 Creature/0 R1469/S14118 Map: Le Jugement des Valeureux Entry: 114361 (Hymdall) Low: 1134960
-- (2968, UNKNOWN, 0, 25996), -- Full: 0x2016EC98806BF2800047B20000114D56 Creature/0 R1467/S18354 Map: Îles Brisées Entry: 110538 (Valewalker Farodin) Low: 1133910
(2547, 50835, 0, 25996),
-- (3797, UNKNOWN, 0, 25996), -- Full: 0x203CD4BE00679A000056E60000115568 Creature/0 R3893/S22246 Map: Le Cauchemar d’émeraude Entry: 106088 (Cenarius) Low: 1135976
(3801, 51629, 0, 25996),
(2546, 50835, 0, 25996);
-- (2969, UNKNOWN, 0, 25996), -- Full: 0x2016EC98806BF2800047B20000114D56 Creature/0 R1467/S18354 Map: Îles Brisées Entry: 110538 (Valewalker Farodin) Low: 1133910
-- (2972, UNKNOWN, 0, 25996), -- Full: 0x2016EC98806BF2800047B20000114D56 Creature/0 R1467/S18354 Map: Îles Brisées Entry: 110538 (Valewalker Farodin) Low: 1133910
-- (2971, UNKNOWN, 0, 25996); -- Full: 0x2016EC98806BF2800047B20000114D56 Creature/0 R1467/S18354 Map: Îles Brisées Entry: 110538 (Valewalker Farodin) Low: 1133910


DELETE FROM `conversation_actor_template` WHERE `Id` IN (49625, 55620, 50835, 51629);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(49625, 97979, 68213, 25996),
(55620, 114263, 67230, 25996),
(50835, 101497, 65843, 25996),
(51629, 98208, 65794, 25996);

UPDATE `conversation_actor_template` SET `CreatureId`=97140, `CreatureModelId`=65100 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=98548, `CreatureModelId`=65843 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=98548, `CreatureModelId`=65843 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=98548, `CreatureModelId`=65843 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=98548, `CreatureModelId`=65843 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=98548, `CreatureModelId`=65843 WHERE `Id`=53609;

DELETE FROM `conversation_line_template` WHERE `Id` IN (7900, 6908, 6907, 6865, 8935, 8919, 8918, 8917, 8916, 9435, 8934, 9151, 6309, 8540, 8886, 8885, 8884, 8539, 8538, 6307, 5376, 8457, 8456, 8455, 8454, 8467, 5375, 6308, 6313, 6311, 6310);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(7900, 0, 576, 0, 0, 25996),
(6908, 8221, 0, 1, 0, 25996),
(6907, 0, 0, 0, 0, 25996),
(6865, 0, 149, 0, 0, 25996),
(8935, 0, 680, 0, 0, 25996),
(8919, 15850, 0, 1, 0, 25996),
(8918, 11450, 0, 2, 0, 25996),
(8917, 5550, 0, 1, 0, 25996),
(8916, 0, 0, 0, 0, 25996),
(9435, 0, 3179205104, 0, 0, 25996),
(8934, 0, 680, 0, 0, 25996),
(9151, 0, 575, 0, 0, 25996),
(6309, 0, 0, 0, 0, 25996),
(8540, 50312, 0, 0, 0, 25996),
(8886, 43338, 0, 2, 0, 25996),
(8885, 36164, 0, 0, 0, 25996),
(8884, 29724, 0, 1, 0, 25996),
(8539, 16466, 0, 0, 19066, 25996),
(8538, 0, 0, 0, 0, 25996),
(6307, 0, 0, 0, 0, 25996),
(5376, 0, 793, 0, 0, 25996),
(8457, 35128, 1568065888, 0, 0, 25996),
(8456, 22073, 1568065888, 0, 0, 25996),
(8455, 6726, 1568065888, 0, 8252, 25996),
(8454, 0, 1568065888, 0, 0, 25996),
(8467, 0, 793, 0, 0, 25996),
(5375, 0, 793, 0, 0, 25996),
(6308, 0, 0, 0, 0, 25996),
(6313, 8798, 94775957, 0, 21526, 25996),
(6311, 0, 94775957, 0, 0, 25996),
(6310, 0, 0, 0, 0, 25996);

UPDATE `conversation_line_template` SET `StartTime`=3395, `Unk`=8240 WHERE `Id`=4840;
UPDATE `conversation_line_template` SET `Unk`=8240 WHERE `Id`=4838;

DELETE FROM `conversation_template` WHERE `Id` IN (3910, 3797, 3273, 3259, 3917, 3916, 4114, 3821, 2972, 2971, 2970, 2969, 2968, 3540, 2547, 2546, 3801, 4009);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(3910, 8916, 20850, 25996),
(3797, 8454, 50677, 25996),
(3273, 6907, 11097, 25996),
(3259, 6865, 14930, 25996),
(3917, 8935, 9074, 25996),
(3916, 8934, 9770, 25996),
(4114, 9435, 5772, 25996),
(3821, 8538, 56217, 25996),
(2972, 6311, 15327, 25996),
(2971, 6310, 5030, 25996),
(2970, 6309, 6656, 25996),
(2969, 6308, 5944, 25996),
(2968, 6307, 5757, 25996),
(3540, 7900, 7616, 25996),
(2547, 5376, 3719, 25996),
(2546, 5375, 10558, 25996),
(3801, 8467, 14285, 25996),
(4009, 9151, 8002, 25996);

UPDATE `conversation_template` SET `FirstLineID`=4840, `LastLineEndTime`=11239 WHERE `Id`=2292;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (265459 /*Doodad_7sr_hubmanatree004*/, 266889 /*Light Ray*/, 266890 /*Light Ray*/, 266917 /*Doodad_7vr_Vrykul_fence004*/, 266914 /*Doodad_7vr_Vrykul_fence001*/, 266915 /*Doodad_7vr_Vrykul_fence002*/, 266916 /*Doodad_7vr_Vrykul_fence003*/, 243404 /*Collision Wall*/, 266532 /*Guarm_Boss_Door01*/, 266533 /*Guarm_Boss_Door02*/, 265596 /*Ritual Stone*/, 242454 /*Hellfire Gate*/, 266845 /*Doodad_7du_valhalla_door001*/, 260526 /*Spoils*/, 253130 /*Instance Portal*/, 254001 /*Misplaced Chest*/, 251641 /*Suramar Leyline Map*/, 250279 /*Pipe*/, 250635 /*Door I*/, 250276 /*Door K*/, 250637 /*Door L*/, 250636 /*Door J*/, 250277 /*Door H*/, 252164 /*Catacombs Grate*/, 250275 /*Door G*/, 250634 /*Door F*/, 250274 /*Door D (Top)*/, 248997 /*Fel Rune*/, 250278 /*Door B*/, 250273 /*Door D (Bottom)*/, 245968 /*Catacombs Door*/, 250272 /*Door A*/, 250434 /*Door C*/, 250633 /*Doodad_7DU_SuramarCatacombs_Door007*/, 281340 /*Warchief's Command Board*/, 243292 /*Torch*/, 243293 /*Barricade*/, 266850 /*Teleporter Pad*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(265459, 0, 8192), -- Doodad_7sr_hubmanatree004
(266889, 114, 32), -- Light Ray
(266890, 114, 32), -- Light Ray
(266917, 1375, 16), -- Doodad_7vr_Vrykul_fence004
(266914, 1375, 16), -- Doodad_7vr_Vrykul_fence001
(266915, 1375, 16), -- Doodad_7vr_Vrykul_fence002
(266916, 1375, 16), -- Doodad_7vr_Vrykul_fence003
(243404, 0, 8192), -- Collision Wall
(266532, 1375, 48), -- Guarm_Boss_Door01
(266533, 1375, 48), -- Guarm_Boss_Door02
(265596, 0, 48), -- Ritual Stone
(242454, 0, 48), -- Hellfire Gate
(266845, 114, 32), -- Doodad_7du_valhalla_door001
(260526, 94, 16416), -- Spoils
(253130, 0, 32), -- Instance Portal
(254001, 0, 278560), -- Misplaced Chest
(251641, 0, 4), -- Suramar Leyline Map
(250279, 1375, 48), -- Pipe
(250635, 1375, 48), -- Door I
(250276, 1375, 48), -- Door K
(250637, 1375, 48), -- Door L
(250636, 1375, 48), -- Door J
(250277, 1375, 48), -- Door H
(252164, 1375, 48), -- Catacombs Grate
(250275, 1375, 48), -- Door G
(250634, 1375, 48), -- Door F
(250274, 1375, 48), -- Door D (Top)
(248997, 1375, 16), -- Fel Rune
(250278, 1375, 48), -- Door B
(250273, 1375, 48), -- Door D (Bottom)
(245968, 1375, 48), -- Catacombs Door
(250272, 1375, 48), -- Door A
(250434, 1375, 48), -- Door C
(250633, 1375, 48), -- Doodad_7DU_SuramarCatacombs_Door007
(281340, 29, 262144), -- Warchief's Command Board
(243292, 0, 8192), -- Torch
(243293, 0, 8192), -- Barricade
(266850, 114, 0); -- Teleporter Pad

UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=252850; -- Small Treasure Chest
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=209078; -- Lilly Pad
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=252839; -- Small Treasure Chest
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=252844; -- Treasure Chest
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=257546; -- Treasure Chest
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=252841; -- Small Treasure Chest
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=252807; -- Small Treasure Chest
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=252010; -- Crystallized Bough
UPDATE `gameobject_template_addon` SET `flags`=2105344 WHERE `entry`=254009; -- Volatile Leyline Crystal
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=244775; -- Dreamleaf
UPDATE `gameobject_template_addon` SET `faction`=1734 WHERE `entry`=187376; -- NPC Fishing Bobber
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=16 WHERE `entry`=202816; -- Brazier
UPDATE `gameobject_template_addon` SET `faction`=29 WHERE `entry`=259114; -- [DNT] Command Table Collision Cylinder
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=237738; -- Portal to Ashran
UPDATE `gameobject_template_addon` SET `flags`=48 WHERE `entry`=223739; -- The Gates of Orgrimmar
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=48 WHERE `entry`=223814; -- Doodad_OGRaid_FrontGate_Back
UPDATE `gameobject_template_addon` SET `faction`=1735, `flags`=32 WHERE `entry`=235877; -- Portal to Blasted Lands
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=251493; -- Shadefruit
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=251492; -- Purified Water
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=252876; -- Small Treasure Chest
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=246229; -- Cracked Warpsleeve
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=251494; -- Silver Jasmine

DELETE FROM `spell_target_position` WHERE (`ID`=225949 AND `EffectIndex`=0) OR (`ID`=228104 AND `EffectIndex`=0) OR (`ID`=234199 AND `EffectIndex`=0) OR (`ID`=231166 AND `EffectIndex`=0) OR (`ID`=205814 AND `EffectIndex`=0) OR (`ID`=220892 AND `EffectIndex`=0) OR (`ID`=225293 AND `EffectIndex`=0) OR (`ID`=247057 AND `EffectIndex`=1);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(225949, 0, 1520, -2976.79, 8558.08, 33.44, 25996), -- Spell: Téléportation vers le Rêve d’émeraude Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(228104, 0, 1648, 519.86, 686.24, 2.06, 25996), -- Spell: Réanimation Efffect: 179 (SPELL_EFFECT_CREATE_AREATRIGGER)
(234199, 0, 1648, 503.81, 596.85, 2.81, 25996), -- Spell: Réanimation Efffect: 179 (SPELL_EFFECT_CREATE_AREATRIGGER)
(231166, 0, 1648, 3296.33, 5932.27, 446.26, 25996), -- Spell: Chute libre Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(205814, 0, 1220, 4115.21, 4441.16, 768.31, 25996), -- Spell: Saut céleste vers Haut-Roc Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(220892, 0, 1220, 372.29, 3996.95, 3.16, 25996), -- Spell: Téléportation vers la taverne Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(225293, 0, 1220, 1143.82, 4255.53, 21.33, 25996), -- Spell: Sort de descente volontaire de véhicule - Annulation d’immunité Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(247057, 1, 1, 1776.5, -4338.8, -7.48, 25996); -- Spell: Portail : Orgrimmar Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=193759 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=224669 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `MapID`=1159, `PositionX`=1936.9, `PositionY`=341.35, `PositionZ`=90.28 WHERE (`ID`=171253 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=222548 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=220883 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=130696 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=217765 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (115566 /*115566 (Starving Felstalker)*/, 116084 /*116084 (Volatile Fel)*/, 109469 /*109469 (Great Eagle)*/, 97532 /*Violetta*/, 106540 /*106540 (Elothir)*/, 106543 /*106543 (Thaon Moonclaw)*/, 106539 /*106539 (Elerethe Renferal)*/, 111298 /*111298 (Purified Life Essence)*/, 106015 /*106015 (Dreambound Druid) - Forme de vol rapide*/, 106088 /*106088 (Cenarius)*/, 106381 /*106381 (Dreambound Druid) - Forme de vol rapide*/, 106380 /*106380 (Dreambound Druid) - Forme de vol rapide*/, 106379 /*106379 (Dreambound Druid) - Forme de vol rapide*/, 106385 /*106385 (Ysera) - Scintillement fantomatique, Marche sur l’eau*/, 106477 /*106477 (Lethon)*/, 106478 /*106478 (Taerar)*/, 106475 /*106475 (Emeriss)*/, 106474 /*106474 (Ysondre)*/, 106463 /*106463 (Ursoc)*/, 106008 /*106008 (Verdant Ancient)*/, 106010 /*106010 (Dreamwisp)*/, 105996 /*105996 (Emerald Dryad) - Échelle : 95-120%, Poison engourdissant*/, 106531 /*106531 (Glade Sprite)*/, 106544 /*106544 (Glade Sprite)*/, 97206 /*Jeune dragonnet du Rêve*/, 110732 /*110732 (Creature of Madness) - Couverture des ombres*/, 105245 /*105245 (Dream of Ysera) - Ghost-Talon Owl Cosmetics*/, 103769 /*103769 (Xavius) - Xavius - Dynamiser - Phase 1*/, 111405 /*111405 (Shadow Pounder)*/, 111398 /*Amalgame du Cauchemar*/, 111413 /*111413 (Dark Devourers)*/, 111370 /*111370 (Creature in the Shadows)*/, 105343 /*105343 (Dread Abomination)*/, 109847 /*109847 (Rift of Aln) - Brouillard de la faille d’Aln*/, 104548 /*104548 (Arena Bounds) - Limites de l’arène*/, 111350 /*111350 (Skittering Shadows)*/, 116760 /*116760 (Odyn) - Téléportation d'Odyn*/, 114535 /*114535 (Orb of Corrosion)*/, 114566 /*114566 (Orb of Corrosion) - Orbe de corrosion*/, 114568 /*114568 (Decaying Minion) - Atteint de la rage*/, 114812 /*114812 (Night Watch Mariner) - Charge de pirate*/, 100733 /*100733 (Charge) - Charge de pirate*/, 114809 /*114809 (Night Watch Mariner) - Ride Vehicle Hardcoded, Chaloupe kvaldir*/, 114709 /*114709 (Grimelord) - Ancre, Ride Vehicle Hardcoded, Chaloupe kvaldir*/, 115941 /*115941 (Kvaldir Longboat) - Chaloupe kvaldir*/, 114905 /*114905 (Gripping Tentacle) - Helya*/, 114901 /*114901 (Gripping Tentacle) - Helya*/, 114900 /*114900 (Gripping Tentacle)*/, 116214 /*116214 (Orb of Corruption) - Ride Vehicle Hardcoded*/, 115166 /*115166 (Orb of Corruption)*/, 114523 /*114523 (Orb of Corruption) - Orbe de corruption*/, 114923 /*114923 (Shatterbone Skeleton)*/, 114811 /*114811 (Kvaldir Coral Maiden)*/, 114813 /*114813 (Kvaldir Tide Witch)*/, 114932 /*114932 (Deepbrine Monstrosity) - Algue*/, 114323 /*114323 (Guarm) - Têtes multiples*/, 114344 /*Guarm - Ride Vehicle Hardcoded*/, 114341 /*Guarm - Ride Vehicle Hardcoded*/, 114343 /*Guarm - Ride Vehicle Hardcoded*/, 114922 /*114922 (Dark Seraph)*/, 117784 /*117784 (Gripping Tentacle) - Helya*/, 117783 /*117783 (Gripping Tentacle) - Helya*/, 114537 /*114537 (Helya) - Helya*/, 114639 /*114639 (Kvaldir Reefcaller)*/, 114614 /*114614 (Kvaldir Spiritrender)*/, 114539 /*114539 (Kvaldir Reefcaller)*/, 114546 /*114546 (Risen Bonethrall)*/, 114672 /*114672 (Brazier Stalker)*/, 114548 /*114548 (Rotsoul Giant)*/, 114534 /*114534 (Helhound)*/, 114547 /*114547 (Ancient Bonethrall)*/, 114538 /*114538 (Kvaldir Spiritrender)*/, 114532 /*114532 (Bonespeaker Soulbinder)*/, 116229 /*116229 (Mythical Champion of the Chosen Dead) - Sculptural*/, 116245 /*116245 (Heroic Champion of the Chosen Dead) - Sculptural*/, 116241 /*116241 (Champion of the Chosen Dead) - Sculptural*/, 116242 /*116242 (Aspiring Champion of the Chosen Dead) - Sculptural*/, 114360 /*114360 (Hyrja) - Lien des Valarjar*/, 114361 /*114361 (Hymdall) - Lien des Valarjar, Lien des Valarjar*/, 114263 /*114263 (Odyn)*/, 114785 /*114785 (Valarjar Marksman) - Échelle : 95-120%*/, 114787 /*114787 (Valarjar Runecarver) - Échelle : 95-120%*/, 114791 /*114791 (Chosen of Eyir)*/, 114784 /*114784 (Valarjar Champion) - Échelle : 95-120%*/, 114786 /*114786 (Valarjar Mystic) - Échelle : 95-120%*/, 114788 /*Mande-tonnerre valarjar*/, 114789 /*114789 (Stormforged Sentinel)*/, 112967 /*112967 (Valewalker Farodin)*/, 110908 /*110908 (Spellblade Aluriel) - Sorcelame Aluriel*/, 110946 /*110946 (Haughty Aristocrat)*/, 106113 /*106113 (Lifesized Nightborne Statue) - Statue*/, 106018 /*106018 (Bazaar Goods) - Marchandises*/, 108422 /*108422 (Automated Sweeper) - Balayeur automatique*/, 108421 /*108421 (Mana Kitten) - Ride Vehicle Hardcoded, Échelle : -40%*/, 105160 /*105160 (Fel Orb) - Orbe gangrené*/, 103130 /*103130 (Timeless Wraith) - Brèche*/, 98208 /*Conseiller Vandros*/, 100393 /*100393 (Dread Felbat) - Bombardement*/, 99628 /*99628 (Suppression Protocol)*/, 98734 /*98734 (Night Crystal)*/, 98435 /*98435 (Unstable Oozeling)*/, 105845 /*105845 (Glowing Spiderling) - Ecrabouillage de jeune araignée, Lueur*/, 98426 /*98426 (Unstable Ooze)*/, 99446 /*99446 (Pipe Stalker) - Jaillissement d’énergie*/, 98205 /*Corstilax*/, 98203 /*Ivanyr*/, 98207 /*Nal’tira - Apparition de renfort héroïque*/, 110833 /*110833 (Infernal)*/, 98759 /*98759 (Vicious Manafang)*/, 105876 /*105876 (Enchanted Broodling) - Volatil*/, 98206 /*Général Xakal*/, 105921 /*105921 (Nightborne Spellsword) - Barrière des Arcanes*/, 105915 /*105915 (Nightborne Reclaimer)*/, 105848 /*105848 (Wyrm Corpse) - Feindre la mort permanent*/, 106059 /*106059 (Warp Shade)*/, 106013 /*106013 (Unstable Amalgamation Corpse) - Feindre la mort permanent*/, 102351 /*102351 (Mana Wyrm)*/, 105651 /*105651 (Dreadborne Seer)*/, 98756 /*98756 (Arcane Anomaly)*/, 105682 /*105682 (Felguard Destroyer) - Cosmétique : Immolation*/, 102541 /*102541 (Withered Corpse) - Feindre la mort permanent*/, 105706 /*105706 (Priestess of Misery)*/, 105952 /*Ame en peine de mana flétrie*/, 105629 /*105629 (Wyrmtongue Scavenger)*/, 98772 /*98772 (Dread Felbat)*/, 98770 /*98770 (Wrathguard Felblade)*/, 98728 /*98728 (Acidic Bile) - Corrosif*/, 105617 /*105617 (Eredar Chaosbringer)*/, 98732 /*98732 (Plagued Rat) - Atteint de la rage*/, 98733 /*98733 (Withered Fiend)*/, 98425 /*98425 (Unstable Amalgamation)*/, 105493 /*105493 (Withered Corpse) - Feindre la mort permanent*/, 111918 /*111918 (Almon)*/, 110965 /*Elisande*/, 110967 /*110967 (Coryn)*/, 110736 /*110736 (Haughty Noble)*/, 115600 /*115600 (Terrified Nightfallen)*/, 116118 /*116118 (Felborne Magus) - Détecteur, Détection de l'invisibilité et du camouflage, Canalisation gangrenée*/, 110804 /*110804 (Ailen)*/, 110876 /*110876 (Disgruntled Servant) - Plateau - homme*/, 110875 /*110875 (Shamed Noble)*/, 112870 /*112870 (Stelleris Attendant)*/, 110680 /*110680 (Ailen Astravar) - Cosmetic - Stun (Permanent - Head Swirl Only, Attached to Top of Head)*/, 110874 /*110874 (Distraught Noble)*/, 120600 /*120600 (Druid of the Talon)*/, 108641 /*108641 (Boneflux)*/, 109306 /*109306 (Myria Glenbrook)*/, 108304 /*108304 (Guviena Bladesong)*/, 114840 /*114840 (PvP Training Dummy) - Marqueur de mannequin d’entraînement, Règles JcJ activées pour le leurre, Masque d’orc*/, 66437 /*66437 (Arcanist Xu) - Canalisation des Arcanes*/, 133271 /*133271 (Highmountain Pathfinder)*/, 19176 /*19176 (Tauren Commoner) - Gossip NPC Appearance - Default, Gossip NPC Periodic - Despawn, Gossip NPC Periodic - Fidget, Gossip NPC Periodic - Talk*/, 130911 /*130911 (Charles Gastly)*/, 15579 /*15579 (Elder Darkhorn) - Tache lumineuse*/, 47897 /*47897 (Lunar Festival Vendor)*/, 14720 /*14720 (High Overlord Saurfang)*/, 112130 /*Archimage Khadgar - Lire le parchemin*/, 112227 /*112227 (Atiesh) - Visuel d’Atiesh*/, 115264 /*115264 (Illnea Bloodthorn)*/, 97493 /*Narestel Pâlétoile*/, 106460 /*106460 (Savyn Valorborn)*/, 113485 /*113485 (Menagerie Shopkeeper)*/, 115755 /*115755 (Scathing Felbeast) - Morsure pénétrante, Cosmetic - Sleep Zzz*/, 110651 /*110651 (Lylandre's Frost Crystal)*/, 110679 /*110679 (Aurore)*/, 105323 /*Oeufs des catacombes anciens - Maître des familiers*/, 65343 /*Araignée des ossements*/, 108870 /*108870 (Sylverin)*/, 115561 /*115561 (Duskwatch Felblade)*/, 115562 /*115562 (Duskwatch Felblade)*/, 115563 /*115563 (Captured Nightfallen)*/, 107350 /*107350 (Cyrille)*/, 107348 /*107348 (Sylessa)*/, 107349 /*107349 (Lorin) - Lire le parchemin*/, 110987 /*110987 (Nighteyes)*/, 113487 /*113487 (Menagerie Shopkeeper)*/, 116360 /*116360 (Duskwatch Scryer) - Détecteur, Détection de l'invisibilité et du camouflage*/, 112547 /*112547 (Tempomancer Virinya)*/, 116655 /*116655 (High Society Harpist)*/, 116653 /*116653 (Loyalist Spectator)*/, 114869 /*Bourreau du moteur d’âmes*/, 114959 /*Molosse du moteur d’âmes - Image démoniaque, Détection de l'invisibilité et du camouflage*/, 114997 /*114997 (Felsoul Ferry)*/, 114904 /*Geôlier du moteur d’âmes*/, 116660 /*116660 (Felsoul Ferry)*/, 115012 /*115012 (Felborne Conspirator)*/, 111904 /*111904 (Waning Crescent Porter)*/, 109411 /*109411 (Shadescale Flyeater)*/, 109158 /*109158 (Underglow Locust)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(115566, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115566 (Starving Felstalker)
(116084, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116084 (Volatile Fel)
(109469, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 109469 (Great Eagle)
(97532, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Violetta
(106540, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 106540 (Elothir)
(106543, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 106543 (Thaon Moonclaw)
(106539, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 106539 (Elerethe Renferal)
(111298, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111298 (Purified Life Essence)
(106015, 0, 0, 50331648, 1, 0, 0, 0, 0, '100205'), -- 106015 (Dreambound Druid) - Forme de vol rapide
(106088, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 106088 (Cenarius)
(106381, 0, 0, 50331648, 1, 0, 0, 0, 0, '100203'), -- 106381 (Dreambound Druid) - Forme de vol rapide
(106380, 0, 0, 50331648, 1, 0, 0, 0, 0, '100202'), -- 106380 (Dreambound Druid) - Forme de vol rapide
(106379, 0, 0, 50331648, 1, 0, 0, 0, 0, '100204'), -- 106379 (Dreambound Druid) - Forme de vol rapide
(106385, 0, 0, 0, 1, 0, 0, 0, 0, '204063 115790'), -- 106385 (Ysera) - Scintillement fantomatique, Marche sur l’eau
(106477, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 106477 (Lethon)
(106478, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 106478 (Taerar)
(106475, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 106475 (Emeriss)
(106474, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 106474 (Ysondre)
(106463, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 106463 (Ursoc)
(106008, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 106008 (Verdant Ancient)
(106010, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 106010 (Dreamwisp)
(105996, 0, 0, 0, 1, 0, 0, 0, 0, '123978 183196'), -- 105996 (Emerald Dryad) - Échelle : 95-120%, Poison engourdissant
(106531, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 106531 (Glade Sprite)
(106544, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 106544 (Glade Sprite)
(97206, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Jeune dragonnet du Rêve
(110732, 0, 0, 0, 1, 0, 0, 0, 0, '220180'), -- 110732 (Creature of Madness) - Couverture des ombres
(105245, 0, 0, 50331648, 1, 0, 0, 0, 0, '178200'), -- 105245 (Dream of Ysera) - Ghost-Talon Owl Cosmetics
(103769, 0, 0, 0, 1, 0, 0, 0, 0, '226184'), -- 103769 (Xavius) - Xavius - Dynamiser - Phase 1
(111405, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111405 (Shadow Pounder)
(111398, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Amalgame du Cauchemar
(111413, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111413 (Dark Devourers)
(111370, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111370 (Creature in the Shadows)
(105343, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105343 (Dread Abomination)
(109847, 0, 0, 0, 1, 0, 0, 0, 0, '218606'), -- 109847 (Rift of Aln) - Brouillard de la faille d’Aln
(104548, 0, 0, 0, 1, 0, 0, 0, 0, '206797 212585 212588 212589 212590 212591'), -- 104548 (Arena Bounds) - Limites de l’arène
(111350, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111350 (Skittering Shadows)
(116760, 0, 0, 0, 1, 0, 0, 0, 0, '232580'), -- 116760 (Odyn) - Téléportation d'Odyn
(114535, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 114535 (Orb of Corrosion)
(114566, 0, 0, 0, 1, 0, 0, 0, 0, '228057'), -- 114566 (Orb of Corrosion) - Orbe de corrosion
(114568, 0, 0, 0, 1, 0, 0, 0, 0, '202476'), -- 114568 (Decaying Minion) - Atteint de la rage
(114812, 0, 0, 0, 1, 0, 0, 0, 0, '228638'), -- 114812 (Night Watch Mariner) - Charge de pirate
(100733, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- 100733 (Charge) - Charge de pirate
(114809, 0, 0, 0, 0, 0, 0, 0, 0, '46598 167910'), -- 114809 (Night Watch Mariner) - Ride Vehicle Hardcoded, Chaloupe kvaldir
(114709, 0, 0, 0, 1, 0, 0, 0, 0, '228376 46598 167910'), -- 114709 (Grimelord) - Ancre, Ride Vehicle Hardcoded, Chaloupe kvaldir
(115941, 0, 0, 0, 1, 0, 0, 0, 0, '230464'), -- 115941 (Kvaldir Longboat) - Chaloupe kvaldir
(114905, 0, 0, 0, 1, 0, 0, 0, 0, '228778'), -- 114905 (Gripping Tentacle) - Helya
(114901, 0, 0, 0, 1, 0, 0, 0, 0, '228772'), -- 114901 (Gripping Tentacle) - Helya
(114900, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114900 (Gripping Tentacle)
(116214, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598'), -- 116214 (Orb of Corruption) - Ride Vehicle Hardcoded
(115166, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 115166 (Orb of Corruption)
(114523, 0, 0, 0, 1, 0, 0, 0, 0, '227906'), -- 114523 (Orb of Corruption) - Orbe de corruption
(114923, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114923 (Shatterbone Skeleton)
(114811, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114811 (Kvaldir Coral Maiden)
(114813, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114813 (Kvaldir Tide Witch)
(114932, 0, 0, 0, 1, 0, 0, 0, 0, '217128'), -- 114932 (Deepbrine Monstrosity) - Algue
(114323, 0, 0, 0, 1, 0, 0, 0, 0, '227512'), -- 114323 (Guarm) - Têtes multiples
(114344, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598'), -- Guarm - Ride Vehicle Hardcoded
(114341, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598'), -- Guarm - Ride Vehicle Hardcoded
(114343, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598'), -- Guarm - Ride Vehicle Hardcoded
(114922, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 114922 (Dark Seraph)
(117784, 0, 0, 0, 1, 0, 0, 0, 0, '234204'), -- 117784 (Gripping Tentacle) - Helya
(117783, 0, 0, 0, 1, 0, 0, 0, 0, '234205'), -- 117783 (Gripping Tentacle) - Helya
(114537, 0, 0, 0, 1, 0, 0, 0, 0, '232229'), -- 114537 (Helya) - Helya
(114639, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114639 (Kvaldir Reefcaller)
(114614, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114614 (Kvaldir Spiritrender)
(114539, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114539 (Kvaldir Reefcaller)
(114546, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114546 (Risen Bonethrall)
(114672, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114672 (Brazier Stalker)
(114548, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114548 (Rotsoul Giant)
(114534, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114534 (Helhound)
(114547, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 114547 (Ancient Bonethrall)
(114538, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114538 (Kvaldir Spiritrender)
(114532, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114532 (Bonespeaker Soulbinder)
(116229, 0, 0, 0, 1, 0, 0, 0, 0, '231599'), -- 116229 (Mythical Champion of the Chosen Dead) - Sculptural
(116245, 0, 0, 0, 1, 0, 0, 0, 0, '231597'), -- 116245 (Heroic Champion of the Chosen Dead) - Sculptural
(116241, 0, 0, 0, 1, 0, 0, 0, 0, '231576'), -- 116241 (Champion of the Chosen Dead) - Sculptural
(116242, 0, 0, 0, 1, 0, 0, 0, 0, '231591'), -- 116242 (Aspiring Champion of the Chosen Dead) - Sculptural
(114360, 0, 0, 0, 1, 0, 0, 0, 0, '228018'), -- 114360 (Hyrja) - Lien des Valarjar
(114361, 0, 0, 0, 1, 0, 0, 0, 0, '228016 228018'), -- 114361 (Hymdall) - Lien des Valarjar, Lien des Valarjar
(114263, 0, 0, 0, 1, 0, 0, 0, 0, '229168'), -- 114263 (Odyn)
(114785, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- 114785 (Valarjar Marksman) - Échelle : 95-120%
(114787, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- 114787 (Valarjar Runecarver) - Échelle : 95-120%
(114791, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 114791 (Chosen of Eyir)
(114784, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- 114784 (Valarjar Champion) - Échelle : 95-120%
(114786, 0, 0, 0, 1, 0, 0, 0, 0, '191450'), -- 114786 (Valarjar Mystic) - Échelle : 95-120%
(114788, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mande-tonnerre valarjar
(114789, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114789 (Stormforged Sentinel)
(112967, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112967 (Valewalker Farodin)
(110908, 0, 0, 0, 1, 0, 0, 0, 0, '220633'), -- 110908 (Spellblade Aluriel) - Sorcelame Aluriel
(110946, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110946 (Haughty Aristocrat)
(106113, 0, 0, 0, 1, 0, 0, 0, 0, '210319'), -- 106113 (Lifesized Nightborne Statue) - Statue
(106018, 0, 0, 0, 1, 0, 0, 0, 0, '210106'), -- 106018 (Bazaar Goods) - Marchandises
(108422, 0, 0, 0, 1, 0, 0, 0, 0, '215245'), -- 108422 (Automated Sweeper) - Balayeur automatique
(108421, 0, 0, 0, 1, 0, 0, 0, 0, '46598 215251'), -- 108421 (Mana Kitten) - Ride Vehicle Hardcoded, Échelle : -40%
(105160, 0, 0, 0, 1, 0, 0, 0, 0, '208275'), -- 105160 (Fel Orb) - Orbe gangrené
(103130, 0, 0, 0, 1, 0, 0, 0, 0, '203952'), -- 103130 (Timeless Wraith) - Brèche
(98208, 0, 0, 0, 1, 0, 0, 0, 0, '214709'), -- Conseiller Vandros
(100393, 0, 0, 50331648, 1, 0, 0, 0, 0, '197786'), -- 100393 (Dread Felbat) - Bombardement
(99628, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99628 (Suppression Protocol)
(98734, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98734 (Night Crystal)
(98435, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98435 (Unstable Oozeling)
(105845, 0, 0, 0, 1, 0, 0, 0, 0, '209828 209826'), -- 105845 (Glowing Spiderling) - Ecrabouillage de jeune araignée, Lueur
(98426, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98426 (Unstable Ooze)
(99446, 0, 0, 0, 1, 0, 0, 0, 0, '195516'), -- 99446 (Pipe Stalker) - Jaillissement d’énergie
(98205, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Corstilax
(98203, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ivanyr
(98207, 0, 0, 50331648, 1, 0, 0, 0, 0, '220763'), -- Nal’tira - Apparition de renfort héroïque
(110833, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110833 (Infernal)
(98759, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 98759 (Vicious Manafang)
(105876, 0, 0, 0, 1, 0, 0, 0, 0, '217705'), -- 105876 (Enchanted Broodling) - Volatil
(98206, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Général Xakal
(105921, 0, 0, 0, 1, 0, 0, 0, 0, '210868'), -- 105921 (Nightborne Spellsword) - Barrière des Arcanes
(105915, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105915 (Nightborne Reclaimer)
(105848, 0, 0, 0, 1, 0, 0, 0, 0, '70628'), -- 105848 (Wyrm Corpse) - Feindre la mort permanent
(106059, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 106059 (Warp Shade)
(106013, 0, 0, 0, 1, 0, 0, 0, 0, '70628'), -- 106013 (Unstable Amalgamation Corpse) - Feindre la mort permanent
(102351, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102351 (Mana Wyrm)
(105651, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105651 (Dreadborne Seer)
(98756, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98756 (Arcane Anomaly)
(105682, 0, 0, 0, 1, 0, 0, 0, 0, '209504'), -- 105682 (Felguard Destroyer) - Cosmétique : Immolation
(102541, 0, 0, 0, 1, 0, 0, 0, 0, '70628'), -- 102541 (Withered Corpse) - Feindre la mort permanent
(105706, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105706 (Priestess of Misery)
(105952, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ame en peine de mana flétrie
(105629, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105629 (Wyrmtongue Scavenger)
(98772, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 98772 (Dread Felbat)
(98770, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98770 (Wrathguard Felblade)
(98728, 0, 0, 0, 1, 0, 0, 0, 0, '202158 209227'), -- 98728 (Acidic Bile) - Corrosif
(105617, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105617 (Eredar Chaosbringer)
(98732, 0, 0, 0, 1, 0, 0, 0, 0, '202476'), -- 98732 (Plagued Rat) - Atteint de la rage
(98733, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98733 (Withered Fiend)
(98425, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98425 (Unstable Amalgamation)
(105493, 0, 0, 0, 1, 0, 0, 0, 0, '70628'), -- 105493 (Withered Corpse) - Feindre la mort permanent
(111918, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111918 (Almon)
(110965, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Elisande
(110967, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110967 (Coryn)
(110736, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110736 (Haughty Noble)
(115600, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115600 (Terrified Nightfallen)
(116118, 0, 0, 0, 0, 0, 0, 0, 0, '203761 67236 229992'), -- 116118 (Felborne Magus) - Détecteur, Détection de l'invisibilité et du camouflage, Canalisation gangrenée
(110804, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110804 (Ailen)
(110876, 0, 0, 0, 1, 0, 0, 0, 0, '209887'), -- 110876 (Disgruntled Servant) - Plateau - homme
(110875, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110875 (Shamed Noble)
(112870, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112870 (Stelleris Attendant)
(110680, 0, 0, 0, 1, 0, 0, 0, 0, '224686'), -- 110680 (Ailen Astravar) - Cosmetic - Stun (Permanent - Head Swirl Only, Attached to Top of Head)
(110874, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110874 (Distraught Noble)
(120600, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 120600 (Druid of the Talon)
(108641, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108641 (Boneflux)
(109306, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 109306 (Myria Glenbrook)
(108304, 0, 0, 0, 1, 0, 0, 0, 0, '215145'), -- 108304 (Guviena Bladesong)
(114840, 0, 0, 0, 1, 0, 0, 0, 0, '98892 228695 228689'), -- 114840 (PvP Training Dummy) - Marqueur de mannequin d’entraînement, Règles JcJ activées pour le leurre, Masque d’orc
(66437, 0, 0, 0, 1, 0, 0, 0, 0, '32783'), -- 66437 (Arcanist Xu) - Canalisation des Arcanes
(133271, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 133271 (Highmountain Pathfinder)
(19176, 0, 0, 0, 257, 0, 0, 0, 0, '65523 33209 33207 33208'), -- 19176 (Tauren Commoner) - Gossip NPC Appearance - Default, Gossip NPC Periodic - Despawn, Gossip NPC Periodic - Fidget, Gossip NPC Periodic - Talk
(130911, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 130911 (Charles Gastly)
(15579, 0, 0, 0, 1, 0, 0, 0, 0, '25824'), -- 15579 (Elder Darkhorn) - Tache lumineuse
(47897, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 47897 (Lunar Festival Vendor)
(14720, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 14720 (High Overlord Saurfang)
(112130, 0, 0, 0, 1, 0, 0, 0, 0, '212171'), -- Archimage Khadgar - Lire le parchemin
(112227, 0, 0, 33554432, 1, 0, 0, 0, 0, '223476'), -- 112227 (Atiesh) - Visuel d’Atiesh
(115264, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115264 (Illnea Bloodthorn)
(97493, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Narestel Pâlétoile
(106460, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 106460 (Savyn Valorborn)
(113485, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113485 (Menagerie Shopkeeper)
(115755, 0, 0, 0, 1, 0, 0, 0, 0, '231772 84186'), -- 115755 (Scathing Felbeast) - Morsure pénétrante, Cosmetic - Sleep Zzz
(110651, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110651 (Lylandre's Frost Crystal)
(110679, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110679 (Aurore)
(105323, 0, 0, 0, 1, 0, 0, 0, 0, '170758'), -- Oeufs des catacombes anciens - Maître des familiers
(65343, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Araignée des ossements
(108870, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108870 (Sylverin)
(115561, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115561 (Duskwatch Felblade)
(115562, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115562 (Duskwatch Felblade)
(115563, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115563 (Captured Nightfallen)
(107350, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107350 (Cyrille)
(107348, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 107348 (Sylessa)
(107349, 0, 0, 0, 1, 0, 0, 0, 0, '133464'), -- 107349 (Lorin) - Lire le parchemin
(110987, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 110987 (Nighteyes)
(113487, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113487 (Menagerie Shopkeeper)
(116360, 0, 0, 0, 1, 0, 0, 0, 0, '203761 67236'), -- 116360 (Duskwatch Scryer) - Détecteur, Détection de l'invisibilité et du camouflage
(112547, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112547 (Tempomancer Virinya)
(116655, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116655 (High Society Harpist)
(116653, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116653 (Loyalist Spectator)
(114869, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bourreau du moteur d’âmes
(114959, 0, 0, 0, 1, 0, 0, 0, 0, '213486 67236'), -- Molosse du moteur d’âmes - Image démoniaque, Détection de l'invisibilité et du camouflage
(114997, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114997 (Felsoul Ferry)
(114904, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Geôlier du moteur d’âmes
(116660, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116660 (Felsoul Ferry)
(115012, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115012 (Felborne Conspirator)
(111904, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111904 (Waning Crescent Porter)
(109411, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 109411 (Shadescale Flyeater)
(109158, 0, 0, 50331648, 1, 0, 0, 0, 0, ''); -- 109158 (Underglow Locust)

UPDATE `creature_template_addon` SET `auras`='221092' WHERE `entry`=111053; -- 111053 (THUNDER BUNNY)
UPDATE `creature_template_addon` SET `auras`='215282' WHERE `entry`=101878; -- Inquisiteur gangrâme
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=110973; -- 110973 (Worthy Vrykul)
UPDATE `creature_template_addon` SET `auras`='220840' WHERE `entry`=110976; -- 110976 (Chosen Stalker)
UPDATE `creature_template_addon` SET `auras`='184840 191995 221829' WHERE `entry`=93094; -- Ancêtre sans repos
UPDATE `creature_template_addon` SET `auras`='213105' WHERE `entry`=107435; -- 107435 (Suspicious Noble)
UPDATE `creature_template_addon` SET `auras`='209344' WHERE `entry`=68553; -- 68553 (SLG Generic MoP (Large AOI))
UPDATE `creature_template_addon` SET `auras`='209901 209898' WHERE `entry`=111903; -- 111903 (Lunastre Attendant)
UPDATE `creature_template_addon` SET `auras`='221687' WHERE `entry`=110354; -- 110354 (Coryn)
UPDATE `creature_template_addon` SET `auras`='225291' WHERE `entry`=113185; -- 113185 (Mana-Infused Bushtail)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=104224; -- Grogneur de Suramar
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=113096; -- 113096 (Eternal Priestess)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=103711; -- 103711 (Feathermane Kitten)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=106764; -- Spoliateur sombrefiel
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=103540; -- 103540 (Starclutch Screecher)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=97555; -- Bassaris rusé acajou
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=93319; -- 93319 (Ashmaw Cub)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=93318; -- 93318 (Ashmaw Mauler)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=105897; -- Pilleur sombrefiel
UPDATE `creature_template_addon` SET `auras`='209916' WHERE `entry`=59113; -- Generic Bunny
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=95720; -- 95720 (Druid of the Antler)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='153971' WHERE `entry`=95719; -- 95719 (Druid of the Antler)
UPDATE `creature_template_addon` SET `bytes2`=256, `auras`='18950' WHERE `entry`=93462; -- 93462 (Lorlathil Sentry)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=93508; -- 93508 (Lorlathil Druid)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=92388; -- 92388 (Vale Flitter)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=109382; -- 109382 (Val'sharah Druid)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=93313; -- 93313 (Gleamhoof Stag)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=95626; -- 95626 (Auburn Ringtail)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=93314; -- 93314 (Gleamhoof Doe)
UPDATE `creature_template_addon` SET `auras`='61573 98892' WHERE `entry`=32666; -- 32666 (Training Dummy)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=65065; -- 65065 (Red Dragon Turtle)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=65061; -- 65061 (Brown Dragon Turtle)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=65060; -- 65060 (Blue Dragon Turtle)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=65058; -- 65058 (Black Dragon Turtle)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=65071; -- 65071 (Great Green Dragon Turtle)
UPDATE `creature_template_addon` SET `auras`='65523 33209 33207 33208' WHERE `entry`=19175; -- 19175 (Orc Commoner)
UPDATE `creature_template_addon` SET `auras`='98892 61573' WHERE `entry`=46647; -- 46647 (Training Dummy)
UPDATE `creature_template_addon` SET `auras`='98892 61573' WHERE `entry`=31146; -- 31146 (Raider's Training Dummy)
UPDATE `creature_template_addon` SET `auras`='65523 33209 33207 33208' WHERE `entry`=19177; -- 19177 (Troll Commoner)
UPDATE `creature_template_addon` SET `auras`='81245' WHERE `entry`=44158; -- 44158 (Orgrimmar Skyway Peon)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=3329; -- 3329 (Kor'jus)
UPDATE `creature_template_addon` SET `auras`='56384' WHERE `entry`=47246; -- 47246 (Ureda)
UPDATE `creature_template_addon` SET `auras`='79849 56384' WHERE `entry`=47248; -- 47248 (Gija)
UPDATE `creature_template_addon` SET `bytes2`=0, `emote`=0 WHERE `entry`=96698; -- Chevalier de sang
UPDATE `creature_template_addon` SET `bytes2`=0, `emote`=0 WHERE `entry`=96708; -- Chevalier de sang
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=58237; -- 58237 (Tweek)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=92183; -- 92183 (Alard Schmied)
UPDATE `creature_template_addon` SET `auras`='211577' WHERE `entry`=106655; -- 106655 (Arcanomancer Vridiel)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=96808; -- 96808 (Sandra Bartan)
UPDATE `creature_template_addon` SET `auras`='98892' WHERE `entry`=114558; -- 114558 (Greater Sparring Partner)
UPDATE `creature_template_addon` SET `auras`='79968' WHERE `entry`=122130; -- 122130
UPDATE `creature_template_addon` SET `auras`='210063' WHERE `entry`=96782; -- 96782 (Lucian Trias)
UPDATE `creature_template_addon` SET `auras`='60913 61354' WHERE `entry`=96778; -- 96778 (Aemara)
UPDATE `creature_template_addon` SET `auras`='60913 61354' WHERE `entry`=107326; -- 107326 (Draemus)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=121541; -- Ban Lu
UPDATE `creature_template_addon` SET `auras`='79849' WHERE `entry`=104091; -- Gardien du Kirin Tor
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=100775; -- 100775 (Lilryia Dawnwind)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='225291' WHERE `entry`=113201; -- 113201 (Thicket Manahunter)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=111921; -- 111921 (Buried Exile)
UPDATE `creature_template_addon` SET `bytes1`=8, `bytes2`=1 WHERE `entry`=100778; -- 100778 (Nightborne Trapper)
UPDATE `creature_template_addon` SET `auras`='152209' WHERE `entry`=104404; -- 104404 (Thicket Hunter)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=115926; -- Sentinelle de Darnassus
UPDATE `creature_template_addon` SET `auras`='152209' WHERE `entry`=99749; -- 99749 (Moonlight Hunter)
UPDATE `creature_template_addon` SET `auras`='203761 67236' WHERE `entry`=111619; -- 111619 (Duskwatch Shroud)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=108411; -- 108411 (Silgryn)
UPDATE `creature_template_addon` SET `auras`='210868' WHERE `entry`=114929; -- 114929 (Duskwatch Defender)
UPDATE `creature_template_addon` SET `mount`=0 WHERE `entry`=114897; -- Sentinelle de Darnassus
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='195230 67236' WHERE `entry`=113707; -- 113707 (Duskwatch Astralite)
UPDATE `creature_template_addon` SET `auras`='226086' WHERE `entry`=104844; -- 104844 ("Old Wise" Ewaye)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=109461; -- 109461 (Vineyard Porter)
UPDATE `creature_template_addon` SET `auras`='205061' WHERE `entry`=105640; -- 105640 (Bound Goat)
UPDATE `creature_template_addon` SET `auras`='203761 67236' WHERE `entry`=112489; -- 112489 (Callus)
UPDATE `creature_template_addon` SET `auras`='216397' WHERE `entry`=108931; -- 108931 (Vineyard Laborer)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=107296; -- 107296 (Suramar Aristocrat)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=112530; -- 112530 (Garion)
UPDATE `creature_template_addon` SET `auras`='216450' WHERE `entry`=108943; -- Domestique du vignoble
UPDATE `creature_template_addon` SET `aiAnimKit`=12291 WHERE `entry`=109669; -- 109669 (High Society Entertainer)
UPDATE `creature_template_addon` SET `auras`='228119' WHERE `entry`=107342; -- 107342 (Duskwatch Spell-Fencer)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=110654; -- 110654 (Frightened Laborer)
UPDATE `creature_template_addon` SET `auras`='203761 67236' WHERE `entry`=112531; -- 112531 (Leleyna)
UPDATE `creature_template_addon` SET `auras`='228118' WHERE `entry`=111485; -- 111485 (Duskwatch Spellshield)
UPDATE `creature_template_addon` SET `auras`='203373' WHERE `entry`=111649; -- 111649 (Ambassador D'vwinn)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=109650; -- 109650 (Duskwatch Spell-Fencer)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='203761 67236 228118' WHERE `entry`=109647; -- 109647 (Imperial Arcbinder)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=108189; -- 108189 (Imperial Servant)
UPDATE `creature_template_addon` SET `auras`='213486 67236' WHERE `entry`=107727; -- 107727 (Legion Harbinger)
UPDATE `creature_template_addon` SET `auras`='213486 67236' WHERE `entry`=107521; -- 107521 (Legion Emissary)
UPDATE `creature_template_addon` SET `auras`='213486' WHERE `entry`=107717; -- 107717 (Burning Chaplain)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=113618; -- Loyaliste de Suramar
UPDATE `creature_template_addon` SET `bytes1`=5 WHERE `entry`=113619; -- 113619 (Suramar Loyalist)
UPDATE `creature_template_addon` SET `auras`='213486 67236' WHERE `entry`=107720; -- 107720 (Felwing Doombringer)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=112190; -- Jeune sabre curieux
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=114892; -- Civil flétrissant
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=114889; -- Civile shal’dorei
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=113752; -- 113752 (Shal'dorei Civilian)
UPDATE `creature_template_addon` SET `bytes1`=5 WHERE `entry`=107451; -- 107451 (Shal'dorei Civilian)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=108811; -- 108811 (Audric)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=113184; -- 113184 (Cunning Bushtail)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=104234; -- 104234 (Val'Sharah Refugee)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=104235; -- 104235 (Val'Sharah Refugee)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=107712; -- 107712 (Verene)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='133464' WHERE `entry`=111902; -- 111902 (Suramar Refugee)
UPDATE `creature_template_addon` SET `auras`='133464' WHERE `entry`=111901; -- 111901 (Suramar Refugee)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (114472, 114931, 104694, 113190, 115381, 111747, 111363, 114958, 116653, 104400, 108419, 114474, 113124, 111699, 114468, 111749, 105653, 111557, 113619, 111485, 111490, 113618, 114929, 111446, 107342, 111484, 106609, 114904, 119907, 115566, 114480, 99638, 110043, 112687, 103639, 108096, 113679, 111489, 111870, 115562, 105296, 110418, 116716, 107449, 105759, 109382, 108875, 107151, 105613, 116715, 108871, 101688, 113634, 116122, 111045, 106654, 111730, 114876, 102415, 114470, 98555, 111523, 113195, 110728, 102960, 95842, 109411, 112336, 109670, 106415, 114927, 109650, 114718, 114926, 104810, 113184, 107435, 107727, 111750, 112827, 114897, 119081, 107324, 111872, 108422, 110050, 113633, 111675, 111618, 113096, 114845, 105645, 114865, 115690, 111612, 111050, 105014, 115606, 113102, 107472, 93447, 113850, 115806, 113198, 104845, 112910, 104844, 106648, 105897, 115561, 107720, 107470, 93469, 93329, 93750, 99765, 95834, 114880, 107717, 100778, 104837, 109647, 111558, 110042, 115012, 108406, 104404, 113268, 103540, 110949, 109473, 109463, 93314, 113270, 103805, 106837, 109819, 97087, 111056, 108641, 105650, 106032, 102748, 111376, 93316, 93094, 105652, 115924, 111445, 107486, 115926, 110656, 106426, 114995, 114866, 120600, 102746, 93313, 109795, 107471, 115691, 104245, 112796, 112331, 113738, 99762, 117412, 112489, 110365, 104147, 104695, 109023, 99581, 112825, 111649, 109509, 99755, 104224, 105232, 102747, 112370, 105554, 103631, 108188, 113201, 105756, 109652, 116360, 119060, 118678, 109364, 116206, 108710, 113765, 111197, 99749, 114869, 111364, 112530, 111389, 112697, 112699, 110726, 106764, 110973, 58237, 111622, 122130, 110734, 110415, 112972, 119077, 106296, 95726, 117355, 108327, 105654, 107756, 111619, 93508, 108259, 107567, 110944, 100047, 113707, 105646, 93318, 105640, 111372, 99070, 109199, 107141, 104696, 111365, 111366, 111367, 115526, 111362, 116063, 101878, 105655, 112948, 112392, 111685, 133271, 115279, 107281, 114924, 116068, 111869, 109950, 111620, 106901, 111556, 105644, 113205, 114879, 107442, 96574, 95599, 106055, 103841, 111871, 115594, 114849, 111651, 114874, 103497, 111937, 105117, 111653, 69759, 92307, 112531, 105249, 107772, 93319, 111621, 121416, 115595, 105656, 93462, 114946, 102495, 105481, 105719, 108421, 115607, 93327, 112484, 112483, 112482, 110354, 121411, 101821, 93333, 93330, 113675, 116117, 108314, 108675, 108628, 115216, 114560, 106263, 106262, 107350, 106810, 105765, 101825, 105160, 110694, 108942, 121415, 107349, 96698, 106113, 107521, 110652, 111007, 110649, 110651, 96708, 109809, 103223, 100237, 99584, 105372, 106804, 100496, 103089, 107559, 108190, 116116, 108154, 112497, 121413, 3225, 113110, 106018, 109782, 113606, 105882, 105410, 99075, 108401, 110958, 106110, 105625, 107333, 113617, 111921, 121412, 107348, 102819, 100780, 115517, 95320, 112543, 105903, 113185, 112545, 105729, 110960, 116118, 110959, 109055, 100777, 101435, 100635, 116119, 102303, 106468, 110727, 104220, 93464, 106532, 105920, 113394, 105480, 119064, 115901, 99789, 107564, 110946, 115700, 110681, 107994);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(114472, 0, 25996),
(114931, 0, 25996),
(104694, 0, 25996),
(113190, 0, 25996),
(115381, 0, 25996),
(111747, 0, 25996),
(111363, 0, 25996),
(114958, 0, 25996),
(116653, 0, 25996),
(104400, 2, 25996),
(108419, 0, 25996),
(114474, 0, 25996),
(113124, 0, 25996),
(111699, 0, 25996),
(114468, 0, 25996),
(111749, 0, 25996),
(105653, 0, 25996),
(111557, 0, 25996),
(113619, 0, 25996),
(111485, 0, 25996),
(111490, 0, 25996),
(113618, 0, 25996),
(114929, 0, 25996),
(111446, 0, 25996),
(107342, 0, 25996),
(111484, 0, 25996),
(106609, 0, 25996),
(114904, 0, 25996),
(119907, 0, 25996),
(115566, 0, 25996),
(114480, 0, 25996),
(99638, 0, 25996),
(110043, 0, 25996),
(112687, 0, 25996),
(103639, 0, 25996),
(108096, 0, 25996),
(113679, 0, 25996),
(111489, 0, 25996),
(111870, 0, 25996),
(115562, 0, 25996),
(105296, 0, 25996),
(110418, 0, 25996),
(116716, 0, 25996),
(107449, 0, 25996),
(105759, 0, 25996),
(109382, 0, 25996),
(108875, 0, 25996),
(107151, 0, 25996),
(105613, 0, 25996),
(116715, 0, 25996),
(108871, 0, 25996),
(101688, 0, 25996),
(113634, 0, 25996),
(116122, 0, 25996),
(111045, 0, 25996),
(106654, 0, 25996),
(111730, 0, 25996),
(114876, 0, 25996),
(102415, 0, 25996),
(114470, 0, 25996),
(98555, 0, 25996),
(111523, 0, 25996),
(113195, 0, 25996),
(110728, 0, 25996),
(102960, 0, 25996),
(95842, 0, 25996),
(109411, 0, 25996),
(112336, 0, 25996),
(109670, 0, 25996),
(106415, 0, 25996),
(114927, 0, 25996),
(109650, 0, 25996),
(114718, 0, 25996),
(114926, 0, 25996),
(104810, 0, 25996),
(113184, 0, 25996),
(107435, 0, 25996),
(107727, 0, 25996),
(111750, 0, 25996),
(112827, 0, 25996),
(114897, 0, 25996),
(119081, 0, 25996),
(107324, 0, 25996),
(111872, 0, 25996),
(108422, 0, 25996),
(110050, 0, 25996),
(113633, 0, 25996),
(111675, 0, 25996),
(111618, 0, 25996),
(113096, 0, 25996),
(114845, 0, 25996),
(105645, 0, 25996),
(114865, 0, 25996),
(115690, 0, 25996),
(111612, 0, 25996),
(111050, 0, 25996),
(105014, 0, 25996),
(115606, 0, 25996),
(113102, 0, 25996),
(107472, 0, 25996),
(93447, 0, 25996),
(113850, 0, 25996),
(115806, 0, 25996),
(113198, 0, 25996),
(104845, 0, 25996),
(112910, 0, 25996),
(104844, 0, 25996),
(106648, 0, 25996),
(105897, 0, 25996),
(115561, 0, 25996),
(107720, 0, 25996),
(107470, 0, 25996),
(93469, 0, 25996),
(93329, 0, 25996),
(93750, 0, 25996),
(99765, 0, 25996),
(95834, 0, 25996),
(114880, 0, 25996),
(107717, 0, 25996),
(100778, 0, 25996),
(104837, 0, 25996),
(109647, 0, 25996),
(111558, 0, 25996),
(110042, 0, 25996),
(115012, 0, 25996),
(108406, 0, 25996),
(104404, 0, 25996),
(113268, 0, 25996),
(103540, 0, 25996),
(110949, 0, 25996),
(109473, 0, 25996),
(109463, 0, 25996),
(93314, 0, 25996),
(113270, 0, 25996),
(103805, 0, 25996),
(106837, 0, 25996),
(109819, 0, 25996),
(97087, 0, 25996),
(111056, 0, 25996),
(108641, 0, 25996),
(105650, 0, 25996),
(106032, 0, 25996),
(102748, 0, 25996),
(111376, 0, 25996),
(93316, 0, 25996),
(93094, 0, 25996),
(105652, 0, 25996),
(115924, 0, 25996),
(111445, 0, 25996),
(107486, 0, 25996),
(115926, 0, 25996),
(110656, 0, 25996),
(106426, 0, 25996),
(114995, 0, 25996),
(114866, 0, 25996),
(120600, 0, 25996),
(102746, 0, 25996),
(93313, 0, 25996),
(109795, 0, 25996),
(107471, 0, 25996),
(115691, 0, 25996),
(104245, 0, 25996),
(112796, 0, 25996),
(112331, 0, 25996),
(113738, 0, 25996),
(99762, 0, 25996),
(117412, 0, 25996),
(112489, 0, 25996),
(110365, 0, 25996),
(104147, 0, 25996),
(104695, 0, 25996),
(109023, 0, 25996),
(99581, 0, 25996),
(112825, 0, 25996),
(111649, 0, 25996),
(109509, 0, 25996),
(99755, 0, 25996),
(104224, 0, 25996),
(105232, 0, 25996),
(102747, 0, 25996),
(112370, 0, 25996),
(105554, 0, 25996),
(103631, 0, 25996),
(108188, 0, 25996),
(113201, 0, 25996),
(105756, 0, 25996),
(109652, 0, 25996),
(116360, 0, 25996),
(119060, 0, 25996),
(118678, 0, 25996),
(109364, 0, 25996),
(116206, 0, 25996),
(108710, 0, 25996),
(113765, 0, 25996),
(111197, 0, 25996),
(99749, 0, 25996),
(114869, 0, 25996),
(111364, 0, 25996),
(112530, 0, 25996),
(111389, 0, 25996),
(112697, 0, 25996),
(112699, 0, 25996),
(110726, 0, 25996),
(106764, 0, 25996),
(110973, 0, 25996),
(58237, 0, 25996),
(111622, 0, 25996),
(122130, 0, 25996),
(110734, 0, 25996),
(110415, 0, 25996),
(112972, 0, 25996),
(119077, 0, 25996),
(106296, 0, 25996),
(95726, 0, 25996),
(117355, 0, 25996),
(108327, 0, 25996),
(105654, 0, 25996),
(107756, 0, 25996),
(111619, 0, 25996),
(93508, 0, 25996),
(108259, 0, 25996),
(107567, 0, 25996),
(110944, 0, 25996),
(100047, 0, 25996),
(113707, 0, 25996),
(105646, 0, 25996),
(93318, 0, 25996),
(105640, 0, 25996),
(111372, 0, 25996),
(99070, 0, 25996),
(109199, 0, 25996),
(107141, 0, 25996),
(104696, 0, 25996),
(111365, 0, 25996),
(111366, 0, 25996),
(111367, 0, 25996),
(115526, 0, 25996),
(111362, 0, 25996),
(116063, 0, 25996),
(101878, 0, 25996),
(105655, 0, 25996),
(112948, 0, 25996),
(112392, 0, 25996),
(111685, 0, 25996),
(133271, 0, 25996),
(115279, 0, 25996),
(107281, 2, 25996),
(114924, 0, 25996),
(116068, 0, 25996),
(111869, 0, 25996);

INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(109950, 0, 25996),
(111620, 0, 25996),
(106901, 0, 25996),
(111556, 0, 25996),
(105644, 0, 25996),
(113205, 0, 25996),
(114879, 0, 25996),
(107442, 0, 25996),
(96574, 1, 25996),
(95599, 0, 25996),
(106055, 0, 25996),
(103841, 0, 25996),
(111871, 0, 25996),
(115594, 0, 25996),
(114849, 0, 25996),
(111651, 0, 25996),
(114874, 0, 25996),
(103497, 0, 25996),
(111937, 0, 25996),
(105117, 0, 25996),
(111653, 0, 25996),
(69759, 0, 25996),
(92307, 0, 25996),
(112531, 0, 25996),
(105249, 0, 25996),
(107772, 0, 25996),
(93319, 0, 25996),
(111621, 0, 25996),
(121416, 0, 25996),
(115595, 0, 25996),
(105656, 0, 25996),
(93462, 0, 25996),
(114946, 0, 25996),
(102495, 0, 25996),
(105481, 0, 25996),
(105719, 0, 25996),
(108421, -2, 25996),
(115607, 0, 25996),
(93327, 0, 25996),
(112484, 0, 25996),
(112483, 0, 25996),
(112482, 0, 25996),
(110354, 0, 25996),
(121411, 0, 25996),
(101821, 0, 25996),
(93333, 0, 25996),
(93330, 0, 25996),
(113675, 0, 25996),
(116117, 0, 25996),
(108314, 0, 25996),
(108675, 0, 25996),
(108628, 0, 25996),
(115216, 0, 25996),
(114560, 0, 25996),
(106263, 0, 25996),
(106262, 0, 25996),
(107350, 0, 25996),
(106810, 0, 25996),
(105765, 2, 25996),
(101825, 0, 25996),
(105160, 0, 25996),
(110694, 0, 25996),
(108942, 0, 25996),
(121415, 0, 25996),
(107349, 0, 25996),
(96698, 0, 25996),
(106113, 0, 25996),
(107521, 0, 25996),
(110652, 0, 25996),
(111007, 0, 25996),
(110649, 0, 25996),
(110651, 0, 25996),
(96708, 0, 25996),
(109809, 0, 25996),
(103223, 0, 25996),
(100237, 0, 25996),
(99584, 0, 25996),
(105372, 0, 25996),
(106804, 0, 25996),
(100496, 0, 25996),
(103089, 0, 25996),
(107559, 2, 25996),
(108190, 0, 25996),
(116116, 0, 25996),
(108154, 0, 25996),
(112497, 0, 25996),
(121413, 0, 25996),
(3225, 0, 25996),
(113110, 0, 25996),
(106018, 0, 25996),
(109782, 0, 25996),
(113606, 0, 25996),
(105882, 0, 25996),
(105410, 0, 25996),
(99075, 0, 25996),
(108401, 0, 25996),
(110958, 0, 25996),
(106110, 0, 25996),
(105625, 0, 25996),
(107333, 0, 25996),
(113617, 0, 25996),
(111921, 0, 25996),
(121412, 0, 25996),
(107348, 0, 25996),
(102819, 0, 25996),
(100780, 0, 25996),
(115517, 0, 25996),
(95320, 0, 25996),
(112543, 0, 25996),
(105903, 0, 25996),
(113185, 0, 25996),
(112545, 0, 25996),
(105729, 0, 25996),
(110960, 0, 25996),
(116118, 0, 25996),
(110959, 0, 25996),
(109055, 1, 25996),
(100777, 0, 25996),
(101435, 0, 25996),
(100635, 0, 25996),
(116119, 0, 25996),
(102303, 0, 25996),
(106468, 0, 25996),
(110727, 0, 25996),
(104220, 0, 25996),
(93464, 0, 25996),
(106532, 0, 25996),
(105920, 0, 25996),
(113394, 0, 25996),
(105480, 0, 25996),
(119064, 0, 25996),
(115901, 0, 25996),
(99789, 0, 25996),
(107564, 2, 25996),
(110946, 0, 25996),
(115700, 0, 25996),
(110681, 0, 25996),
(107994, 0, 25996);


DELETE FROM `creature_model_info` WHERE `DisplayID` IN (82820, 83227, 81476);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(82820, 0.8725, 3.75, 0, 25996),
(83227, 0.8725, 3.75, 0, 25996),
(81476, 0.383, 1.5, 0, 25996);

UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `VerifiedBuild`=25996 WHERE `DisplayID`=69822;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=74041;
UPDATE `creature_model_info` SET `BoundingRadius`=5.371643, `VerifiedBuild`=25996 WHERE `DisplayID`=70334;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=23748;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65254;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69630;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69631;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69628;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=39539;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=38252;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65509;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66177;
UPDATE `creature_model_info` SET `BoundingRadius`=2.073652, `VerifiedBuild`=25996 WHERE `DisplayID`=37729;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21243;
UPDATE `creature_model_info` SET `BoundingRadius`=2.071419, `VerifiedBuild`=25996 WHERE `DisplayID`=21244;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `VerifiedBuild`=25996 WHERE `DisplayID`=69588;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73296;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73295;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69604;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73297;
UPDATE `creature_model_info` SET `BoundingRadius`=6.07745, `VerifiedBuild`=25996 WHERE `DisplayID`=69592;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65938;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68977;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12064;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65526;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62504;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65121;
UPDATE `creature_model_info` SET `BoundingRadius`=19.248, `VerifiedBuild`=25996 WHERE `DisplayID`=71922;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65636;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72236;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70155;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68972;
UPDATE `creature_model_info` SET `BoundingRadius`=4.251018, `VerifiedBuild`=25996 WHERE `DisplayID`=71621;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71808;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68213;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66184;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73462;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73393;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73534;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73533;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73547;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73469;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73471;
UPDATE `creature_model_info` SET `BoundingRadius`=4.027484, `VerifiedBuild`=25996 WHERE `DisplayID`=73549;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70104;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=38795;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73591;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66680;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=74600;
UPDATE `creature_model_info` SET `CombatReach`=35.2, `VerifiedBuild`=25996 WHERE `DisplayID`=66238;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73306;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71165;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73307;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73305;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=30364;
UPDATE `creature_model_info` SET `BoundingRadius`=5.640248, `VerifiedBuild`=25996 WHERE `DisplayID`=73314;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66090;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64729;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71163;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71164;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73304;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63112;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73312;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73310;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73311;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66121;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73303;
UPDATE `creature_model_info` SET `BoundingRadius`=0.52, `CombatReach`=3.75, `VerifiedBuild`=25996 WHERE `DisplayID`=74108;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765, `CombatReach`=3.75, `VerifiedBuild`=25996 WHERE `DisplayID`=74111;
UPDATE `creature_model_info` SET `BoundingRadius`=0.52, `CombatReach`=3.75, `VerifiedBuild`=25996 WHERE `DisplayID`=74112;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765, `CombatReach`=3.75, `VerifiedBuild`=25996 WHERE `DisplayID`=74113;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65076;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67155;
UPDATE `creature_model_info` SET `BoundingRadius`=1.07522, `CombatReach`=4, `VerifiedBuild`=25996 WHERE `DisplayID`=71661;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=69493;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6106094, `CombatReach`=1.38, `VerifiedBuild`=25996 WHERE `DisplayID`=70034;
UPDATE `creature_model_info` SET `CombatReach`=1.5625 WHERE `DisplayID`=70100;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=69465;
UPDATE `creature_model_info` SET `CombatReach`=2.5, `VerifiedBuild`=25996 WHERE `DisplayID`=64588;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=68991;
UPDATE `creature_model_info` SET `CombatReach`=1.744186 WHERE `DisplayID`=70101;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7684871, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=70113;
UPDATE `creature_model_info` SET `CombatReach`=1.744186 WHERE `DisplayID`=70090;
UPDATE `creature_model_info` SET `CombatReach`=1.530612 WHERE `DisplayID`=70095;
UPDATE `creature_model_info` SET `CombatReach`=1.06383 WHERE `DisplayID`=70091;
UPDATE `creature_model_info` SET `CombatReach`=1.271186 WHERE `DisplayID`=70078;
UPDATE `creature_model_info` SET `CombatReach`=1.304348 WHERE `DisplayID`=70036;
UPDATE `creature_model_info` SET `CombatReach`=1.293103 WHERE `DisplayID`=70077;
UPDATE `creature_model_info` SET `CombatReach`=1.293103 WHERE `DisplayID`=70037;
UPDATE `creature_model_info` SET `CombatReach`=1.282051 WHERE `DisplayID`=70039;
UPDATE `creature_model_info` SET `CombatReach`=1.304348 WHERE `DisplayID`=70038;
UPDATE `creature_model_info` SET `CombatReach`=1.271186 WHERE `DisplayID`=70081;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34772;
UPDATE `creature_model_info` SET `BoundingRadius`=1.714496, `CombatReach`=3.01875, `VerifiedBuild`=25996 WHERE `DisplayID`=65794;
UPDATE `creature_model_info` SET `BoundingRadius`=3.028595, `CombatReach`=8, `VerifiedBuild`=25996 WHERE `DisplayID`=67930;
UPDATE `creature_model_info` SET `BoundingRadius`=0.0775, `CombatReach`=0.25, `VerifiedBuild`=25996 WHERE `DisplayID`=35924;
UPDATE `creature_model_info` SET `BoundingRadius`=4.63126, `CombatReach`=8, `VerifiedBuild`=25996 WHERE `DisplayID`=65791;
UPDATE `creature_model_info` SET `BoundingRadius`=1.072994, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=65741;
UPDATE `creature_model_info` SET `BoundingRadius`=3.638236, `CombatReach`=5.25, `VerifiedBuild`=25996 WHERE `DisplayID`=65793;
UPDATE `creature_model_info` SET `BoundingRadius`=10.7659, `VerifiedBuild`=25996 WHERE `DisplayID`=68734;
UPDATE `creature_model_info` SET `BoundingRadius`=1.22464, `CombatReach`=2.15625, `VerifiedBuild`=25996 WHERE `DisplayID`=69432;
UPDATE `creature_model_info` SET `BoundingRadius`=1.106701, `CombatReach`=0.9, `VerifiedBuild`=25996 WHERE `DisplayID`=69416;
UPDATE `creature_model_info` SET `BoundingRadius`=3.211639, `CombatReach`=10, `VerifiedBuild`=25996 WHERE `DisplayID`=65792;
UPDATE `creature_model_info` SET `BoundingRadius`=1.468884, `CombatReach`=2.32875, `VerifiedBuild`=25996 WHERE `DisplayID`=69434;
UPDATE `creature_model_info` SET `BoundingRadius`=1.360078, `CombatReach`=2.15625, `VerifiedBuild`=25996 WHERE `DisplayID`=69433;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=31471;
UPDATE `creature_model_info` SET `BoundingRadius`=0.62, `CombatReach`=2, `VerifiedBuild`=25996 WHERE `DisplayID`=33112;
UPDATE `creature_model_info` SET `BoundingRadius`=2.26048, `CombatReach`=6, `VerifiedBuild`=25996 WHERE `DisplayID`=67378;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=55131;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=39908;
UPDATE `creature_model_info` SET `BoundingRadius`=1.16312, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=70254;
UPDATE `creature_model_info` SET `BoundingRadius`=3.436033, `CombatReach`=2.75, `VerifiedBuild`=25996 WHERE `DisplayID`=21542;
UPDATE `creature_model_info` SET `BoundingRadius`=1.343588, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=65211;
UPDATE `creature_model_info` SET `BoundingRadius`=1.4539, `VerifiedBuild`=25996 WHERE `DisplayID`=70161;
UPDATE `creature_model_info` SET `BoundingRadius`=1.75, `CombatReach`=2.625, `VerifiedBuild`=25996 WHERE `DisplayID`=63997;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66332;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66118;
UPDATE `creature_model_info` SET `BoundingRadius`=2.150898, `CombatReach`=5, `VerifiedBuild`=25996 WHERE `DisplayID`=64693;
UPDATE `creature_model_info` SET `BoundingRadius`=0.62, `CombatReach`=2, `VerifiedBuild`=25996 WHERE `DisplayID`=46333;
UPDATE `creature_model_info` SET `BoundingRadius`=1.75, `CombatReach`=2.625, `VerifiedBuild`=25996 WHERE `DisplayID`=63998;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27972;
UPDATE `creature_model_info` SET `BoundingRadius`=1.046808, `CombatReach`=0.9, `VerifiedBuild`=25996 WHERE `DisplayID`=70160;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=33922;
UPDATE `creature_model_info` SET `BoundingRadius`=1.16312, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=70253;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69082;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71665;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72376;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71607;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66582;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5489194, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73755;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5088412, `CombatReach`=1.15, `VerifiedBuild`=25996 WHERE `DisplayID`=73754;
UPDATE `creature_model_info` SET `BoundingRadius`=1.328041, `CombatReach`=1.08 WHERE `DisplayID`=69273;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=30060;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69425;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26364;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70883;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70886;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64498;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64501;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64502;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64496;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35095;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62734;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71148;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72814;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63571;
UPDATE `creature_model_info` SET `BoundingRadius`=1.555239, `CombatReach`=0.75, `VerifiedBuild`=25996 WHERE `DisplayID`=73889;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67191;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63772;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15405;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70663;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=31228;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=74537;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66130;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63572;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65639;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=892;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63631;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64347;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40263;
UPDATE `creature_model_info` SET `BoundingRadius`=0.117737, `VerifiedBuild`=25996 WHERE `DisplayID`=36620;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70658;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70518;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70517;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37771;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70971;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29408;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70636;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62317;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71224;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70970;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70505;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70734;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70722;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70502;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=51292;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63674;
UPDATE `creature_model_info` SET `BoundingRadius`=0.235474, `VerifiedBuild`=25996 WHERE `DisplayID`=38693;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62315;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62482;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5535;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=48578;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7082875, `VerifiedBuild`=25996 WHERE `DisplayID`=14575;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4464;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35843;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=39910;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35844;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1379;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=9571;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=23521;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8315721, `VerifiedBuild`=25996 WHERE `DisplayID`=23519;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35827;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=6807;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11414;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=247;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1373;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73494;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2328;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35819;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35816;
UPDATE `creature_model_info` SET `BoundingRadius`=1.4, `CombatReach`=1.75, `VerifiedBuild`=25996 WHERE `DisplayID`=27692;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27690;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=23517;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=43721;
UPDATE `creature_model_info` SET `BoundingRadius`=0.195, `CombatReach`=0.975, `VerifiedBuild`=25996 WHERE `DisplayID`=23515;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35193;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35195;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45319;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45170;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=43719;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=43718;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=43717;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=43669;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45320;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=46093;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35194;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35192;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=43720;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=43724;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=47982;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45863;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=43722;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45862;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32982;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=39637;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45864;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=44740;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=46986;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=43725;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15369;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=43726;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=47465;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15352;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45106;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19181;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35198;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1333;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1332;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35301;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=31737;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19182;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15988;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15984;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35185;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35184;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35187;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35183;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35186;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35766;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=42384;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1381;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36615;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1317;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4384;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2956;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1386;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=49770;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1387;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4350;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14499;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3850;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1316;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5846;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=744;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1388;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1321;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64259;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71669;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28048;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4386;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7136;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7135;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1389;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10472;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37722;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27510;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35242;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=42388;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=42387;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1393;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=6839;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5770;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5769;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35241;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1371;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1372;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32938;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10186;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12229;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=33194;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35244;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10589;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1369;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1366;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10578;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34932;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7921;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35243;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1368;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1367;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35545;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35544;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35538;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=8971;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=38631;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=24806;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26749;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34108;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=13341;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=51000;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4231;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2141;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18269;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32936;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4534;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34107;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34066;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32937;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34109;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34111;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19183;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=61763;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34110;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34113;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1322;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=9392;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19184;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34112;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34114;
UPDATE `creature_model_info` SET `BoundingRadius`=1.423153, `VerifiedBuild`=25996 WHERE `DisplayID`=30501;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15322;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=9391;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34059;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34045;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34058;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34046;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2165736, `VerifiedBuild`=25996 WHERE `DisplayID`=36585;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37724;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40012;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=56698;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15511;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35695;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29569;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=31840;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2165736, `VerifiedBuild`=25996 WHERE `DisplayID`=36584;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14415;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29396;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37328;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=8848;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=24164;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62532;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37331;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72816;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37330;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15467;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37329;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45903;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5705;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45902;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15607;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15468;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15877;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37020;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=33700;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15875;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=31760;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35910;
UPDATE `creature_model_info` SET `BoundingRadius`=1.960739, `VerifiedBuild`=25996 WHERE `DisplayID`=31988;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=37437;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19185;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1311;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34185;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=7511;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8121765, `VerifiedBuild`=25996 WHERE `DisplayID`=14732;
UPDATE `creature_model_info` SET `BoundingRadius`=0.212633, `VerifiedBuild`=25996 WHERE `DisplayID`=30413;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19186;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34184;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=33701;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=33698;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=42389;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=8572;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2165736, `VerifiedBuild`=25996 WHERE `DisplayID`=36598;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34049;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34047;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4492;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1334;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2165736, `VerifiedBuild`=25996 WHERE `DisplayID`=36583;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1335;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1328;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4354;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=61027;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=61026;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4449;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4545;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1330;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4355;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4073;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1327;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=61028;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35497;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=55538;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1331;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1329;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35498;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35504;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35499;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35500;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3758;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62151;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62155;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26103;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25596;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=79000;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25598;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70903;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70201;
UPDATE `creature_model_info` SET `BoundingRadius`=1.222084, `VerifiedBuild`=25996 WHERE `DisplayID`=39555;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72956;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26413;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25611;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63051;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70532;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=60926;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=60927;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=60924;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35280;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36904;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69682;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26339;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64586;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65257;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73730;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65232;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65250;
UPDATE `creature_model_info` SET `BoundingRadius`=2.914272, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=73430;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25799;
UPDATE `creature_model_info` SET `BoundingRadius`=0.31, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=71252;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25800;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65369;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65240;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65452;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27681;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69152;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=59102;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27720;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40674;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73451;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73453;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70697;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70461;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73454;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73452;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70460;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70934;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70753;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71606;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71158;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72736;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4440;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2205311, `VerifiedBuild`=25996 WHERE `DisplayID`=43899;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3307967, `VerifiedBuild`=25996 WHERE `DisplayID`=43898;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4410623, `VerifiedBuild`=25996 WHERE `DisplayID`=43897;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3126;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70754;
UPDATE `creature_model_info` SET `BoundingRadius`=1.65039 WHERE `DisplayID`=68393;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70746;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70922;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71037;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71060;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71038;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70486;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26069;
UPDATE `creature_model_info` SET `BoundingRadius`=3.627138, `VerifiedBuild`=25996 WHERE `DisplayID`=41425;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66562;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70832;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=913;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=24978;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66564;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2702;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71582;
UPDATE `creature_model_info` SET `BoundingRadius`=3.0042, `VerifiedBuild`=25996 WHERE `DisplayID`=45448;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71874;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70760;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5233;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66570;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71875;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66556;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70748;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70627;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71655;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66267;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63525;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70759;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72936;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10191;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70758;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71123;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71121;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71120;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70128;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71122;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70757;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73504;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71118;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62553;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73659;
UPDATE `creature_model_info` SET `BoundingRadius`=1.595593, `VerifiedBuild`=25996 WHERE `DisplayID`=73535;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69991;
UPDATE `creature_model_info` SET `BoundingRadius`=1.028736, `CombatReach`=1.5 WHERE `DisplayID`=61927;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70747;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=55318;


UPDATE `npc_vendor` SET `slot`=14, `maxcount`=1, `VerifiedBuild`=25996 WHERE (`entry`=111903 AND `item`=138295 AND `ExtendedCost`=0 AND `type`=1); -- Rouge royal de Farondis
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=111903 AND `item`=138294 AND `ExtendedCost`=0 AND `type`=1); -- Brise marine
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=111903 AND `item`=128833 AND `ExtendedCost`=0 AND `type`=1); -- Liqueur de gingembre kaldorei
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=25996 WHERE (`entry`=111903 AND `item`=128834 AND `ExtendedCost`=0 AND `type`=1); -- Liqueur d'ajonc de Ruissecôte
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=111903 AND `item`=128841 AND `ExtendedCost`=0 AND `type`=1); -- Bière de maïs de Haut-Roc
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=111903 AND `item`=128842 AND `ExtendedCost`=0 AND `type`=1); -- Bière de miel mörgestran
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=111903 AND `item`=138292 AND `ExtendedCost`=0 AND `type`=1); -- Eau enrichie en énergie tellurique
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=111903 AND `item`=128853 AND `ExtendedCost`=0 AND `type`=1); -- Eau de source de Haut-Roc
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=111903 AND `item`=141215 AND `ExtendedCost`=0 AND `type`=1); -- Jus d'arquebaie
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=111903 AND `item`=140298 AND `ExtendedCost`=0 AND `type`=1); -- Cidre pétillant de Mananelle
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Charbon
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur élémentaire
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur puissant
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur léger
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Marteau de forgeron
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Pioche de mineur
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Charbon
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur élémentaire
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur puissant
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur léger
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Marteau de forgeron
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Pioche de mineur
UPDATE `npc_vendor` SET `slot`=9 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Charbon
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur élémentaire
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur puissant
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur léger
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Marteau de forgeron
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=113516 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Pioche de mineur
UPDATE `npc_vendor` SET `slot`=9 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=97532 AND `ID`=1) OR (`CreatureID`=105996 AND `ID`=1) OR (`CreatureID`=116760 AND `ID`=1) OR (`CreatureID`=114568 AND `ID`=1) OR (`CreatureID`=114812 AND `ID`=1) OR (`CreatureID`=100733 AND `ID`=1) OR (`CreatureID`=114809 AND `ID`=1) OR (`CreatureID`=114709 AND `ID`=1) OR (`CreatureID`=114923 AND `ID`=1) OR (`CreatureID`=114811 AND `ID`=1) OR (`CreatureID`=114813 AND `ID`=1) OR (`CreatureID`=114922 AND `ID`=1) OR (`CreatureID`=114639 AND `ID`=1) OR (`CreatureID`=114614 AND `ID`=1) OR (`CreatureID`=114539 AND `ID`=1) OR (`CreatureID`=114547 AND `ID`=1) OR (`CreatureID`=114538 AND `ID`=1) OR (`CreatureID`=114532 AND `ID`=1) OR (`CreatureID`=114360 AND `ID`=1) OR (`CreatureID`=114361 AND `ID`=1) OR (`CreatureID`=114263 AND `ID`=1) OR (`CreatureID`=114785 AND `ID`=1) OR (`CreatureID`=114791 AND `ID`=1) OR (`CreatureID`=114784 AND `ID`=1) OR (`CreatureID`=114788 AND `ID`=1) OR (`CreatureID`=112967 AND `ID`=1) OR (`CreatureID`=110908 AND `ID`=1) OR (`CreatureID`=98208 AND `ID`=1) OR (`CreatureID`=98206 AND `ID`=1) OR (`CreatureID`=105921 AND `ID`=1) OR (`CreatureID`=105915 AND `ID`=1) OR (`CreatureID`=105682 AND `ID`=1) OR (`CreatureID`=98770 AND `ID`=1) OR (`CreatureID`=105617 AND `ID`=1) OR (`CreatureID`=116118 AND `ID`=1) OR (`CreatureID`=108304 AND `ID`=1) OR (`CreatureID`=3296 AND `ID`=2) OR (`CreatureID`=133271 AND `ID`=1) OR (`CreatureID`=44158 AND `ID`=3) OR (`CreatureID`=44158 AND `ID`=2) OR (`CreatureID`=97493 AND `ID`=1) OR (`CreatureID`=106460 AND `ID`=1) OR (`CreatureID`=115561 AND `ID`=1) OR (`CreatureID`=115562 AND `ID`=1) OR (`CreatureID`=107350 AND `ID`=1) OR (`CreatureID`=107348 AND `ID`=1) OR (`CreatureID`=107349 AND `ID`=1) OR (`CreatureID`=116360 AND `ID`=1) OR (`CreatureID`=115012 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(97532, 1, 124381, 0, 0, 0, 0, 0, 0, 0, 0), -- Violetta
(105996, 1, 60765, 0, 0, 0, 0, 0, 0, 0, 0), -- Emerald Dryad
(116760, 1, 115802, 0, 0, 0, 0, 0, 0, 0, 0), -- Odyn
(114568, 1, 118289, 0, 0, 0, 0, 0, 0, 0, 0), -- Decaying Minion
(114812, 1, 1925, 0, 0, 130101, 0, 0, 0, 0, 0), -- Night Watch Mariner
(100733, 1, 1925, 0, 0, 130101, 0, 0, 0, 0, 0), -- Charge
(114809, 1, 118083, 0, 0, 118083, 0, 0, 0, 0, 0), -- Night Watch Mariner
(114709, 1, 115802, 0, 0, 0, 0, 0, 0, 0, 0), -- Grimelord
(114923, 1, 3350, 0, 0, 0, 0, 0, 0, 0, 0), -- Shatterbone Skeleton
(114811, 1, 85951, 0, 0, 108594, 0, 0, 0, 0, 0), -- Kvaldir Coral Maiden
(114813, 1, 41180, 0, 0, 0, 0, 0, 0, 0, 0), -- Kvaldir Tide Witch
(114922, 1, 138736, 0, 0, 49777, 0, 0, 0, 0, 0), -- Dark Seraph
(114639, 1, 36543, 0, 0, 0, 0, 0, 0, 0, 0), -- Kvaldir Reefcaller
(114614, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0), -- Kvaldir Spiritrender
(114539, 1, 36543, 0, 0, 0, 0, 0, 0, 0, 0), -- Kvaldir Reefcaller
(114547, 1, 56193, 0, 0, 56174, 0, 0, 0, 0, 0), -- Ancient Bonethrall
(114538, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0), -- Kvaldir Spiritrender
(114532, 1, 129726, 0, 0, 0, 0, 0, 0, 0, 0), -- Bonespeaker Soulbinder
(114360, 1, 140345, 0, 0, 143547, 0, 0, 0, 0, 0), -- Hyrja
(114361, 1, 109641, 0, 0, 0, 0, 0, 0, 0, 0), -- Hymdall
(114263, 1, 115802, 0, 0, 0, 0, 0, 0, 0, 0), -- Odyn
(114785, 1, 34816, 0, 0, 0, 0, 0, 109238, 0, 0), -- Valarjar Marksman
(114791, 1, 124548, 0, 0, 34590, 0, 0, 0, 0, 0), -- Chosen of Eyir
(114784, 1, 137263, 0, 0, 0, 0, 0, 0, 0, 0), -- Valarjar Champion
(114788, 1, 36543, 0, 0, 0, 0, 0, 0, 0, 0), -- Mande-tonnerre valarjar
(112967, 1, 28650, 0, 0, 0, 0, 0, 0, 0, 0), -- Valewalker Farodin
(110908, 1, 137254, 0, 0, 137253, 0, 0, 0, 0, 0), -- Spellblade Aluriel
(98208, 1, 133174, 0, 0, 0, 0, 0, 0, 0, 0), -- Conseiller Vandros
(98206, 1, 128279, 0, 0, 0, 0, 0, 0, 0, 0), -- Général Xakal
(105921, 1, 132170, 0, 0, 132249, 0, 0, 0, 0, 0), -- Nightborne Spellsword
(105915, 1, 133175, 0, 0, 0, 0, 0, 0, 0, 0), -- Nightborne Reclaimer
(105682, 1, 138481, 0, 0, 0, 0, 0, 0, 0, 0), -- Felguard Destroyer
(98770, 1, 132920, 0, 0, 132920, 0, 0, 0, 0, 0), -- Wrathguard Felblade
(105617, 1, 127419, 0, 0, 0, 0, 0, 0, 0, 0), -- Eredar Chaosbringer
(116118, 1, 140089, 0, 0, 0, 0, 0, 0, 0, 0), -- Felborne Magus
(108304, 1, 126319, 0, 0, 126319, 0, 0, 0, 0, 0), -- Guviena Bladesong
(3296, 2, 0, 0, 0, 0, 0, 0, 2507, 0, 0), -- Orgrimmar Grunt
(133271, 1, 0, 0, 0, 0, 0, 0, 34268, 0, 0), -- Highmountain Pathfinder
(44158, 3, 1902, 0, 0, 0, 0, 0, 0, 0, 0), -- Orgrimmar Skyway Peon
(44158, 2, 3367, 0, 0, 0, 0, 0, 0, 0, 0), -- Orgrimmar Skyway Peon
(97493, 1, 124379, 0, 0, 0, 0, 0, 0, 0, 0), -- Narestel Pâlétoile
(106460, 1, 51949, 0, 0, 0, 0, 0, 0, 0, 0), -- Savyn Valorborn
(115561, 1, 137257, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Felblade
(115562, 1, 137257, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Felblade
(107350, 1, 133176, 0, 0, 137253, 0, 0, 0, 0, 0), -- Cyrille
(107348, 1, 132170, 0, 0, 132170, 0, 0, 0, 0, 0), -- Sylessa
(107349, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Lorin
(116360, 1, 133174, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Scryer
(115012, 1, 140089, 0, 0, 0, 0, 0, 0, 0, 0); -- Felborne Conspirator

UPDATE `creature_equip_template` SET `ItemID2`=133177, `ItemID3`=0 WHERE (`CreatureID`=110734 AND `ID`=1); -- Stelleris Thug
UPDATE `creature_equip_template` SET `ItemID2`=11505, `ItemID3`=0 WHERE (`CreatureID`=105903 AND `ID`=1); -- Broll Bearmantle
UPDATE `creature_equip_template` SET `ItemID3`=38185 WHERE (`CreatureID`=93462 AND `ID`=1); -- Lorlathil Sentry
UPDATE `creature_equip_template` SET `ItemID1`=155857 WHERE (`CreatureID`=14720 AND `ID`=1); -- High Overlord Saurfang
UPDATE `creature_equip_template` SET `ItemID1`=1903 WHERE (`CreatureID`=44158 AND `ID`=1); -- Orgrimmar Skyway Peon
UPDATE `creature_equip_template` SET `ItemID1`=112261, `ItemID2`=138831 WHERE (`CreatureID`=122130 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID2`=132249, `ItemID3`=0 WHERE (`CreatureID`=102303 AND `ID`=1); -- Lieutenant Strathmar
UPDATE `creature_equip_template` SET `ItemID2`=132170, `ItemID3`=0 WHERE (`CreatureID`=107342 AND `ID`=1); -- Duskwatch Spell-Fencer
UPDATE `creature_equip_template` SET `ItemID2`=137257, `ItemID3`=0 WHERE (`CreatureID`=111730 AND `ID`=1); -- Felsworn Noble
UPDATE `creature_equip_template` SET `ItemID2`=137257, `ItemID3`=0 WHERE (`CreatureID`=111747 AND `ID`=1); -- Felsworn Noble
UPDATE `creature_equip_template` SET `ItemID2`=137253, `ItemID3`=0 WHERE (`CreatureID`=111485 AND `ID`=1); -- Duskwatch Spellshield
UPDATE `creature_equip_template` SET `ItemID2`=132170, `ItemID3`=0 WHERE (`CreatureID`=109650 AND `ID`=1); -- Duskwatch Spell-Fencer
UPDATE `creature_equip_template` SET `ItemID2`=137253, `ItemID3`=0 WHERE (`CreatureID`=111484 AND `ID`=1); -- Duskwatch Spellshield

DELETE FROM `gossip_menu` WHERE (`MenuID`=19960 AND `TextID`=28198) OR (`MenuID`=19301 AND `TextID`=28397) OR (`MenuID`=19960 AND `TextID`=28199) OR (`MenuID`=18723 AND `TextID`=12487) OR (`MenuID`=19588 AND `TextID`=29001) OR (`MenuID`=20849 AND `TextID`=29996) OR (`MenuID`=20502 AND `TextID`=30698) OR (`MenuID`=18748 AND `TextID`=27380) OR (`MenuID`=18724 AND `TextID`=27208) OR (`MenuID`=18747 AND `TextID`=27251) OR (`MenuID`=19764 AND `TextID`=29265) OR (`MenuID`=19722 AND `TextID`=29253) OR (`MenuID`=19515 AND `TextID`=28836) OR (`MenuID`=19096 AND `TextID`=27923) OR (`MenuID`=19687 AND `TextID`=29172) OR (`MenuID`=20376 AND `TextID`=28901) OR (`MenuID`=20391 AND `TextID`=30491) OR (`MenuID`=19783 AND `TextID`=29308) OR (`MenuID`=20119 AND `TextID`=29909) OR (`MenuID`=19696 AND `TextID`=30287) OR (`MenuID`=6944 AND `TextID`=7778) OR (`MenuID`=20111 AND `TextID`=29891) OR (`MenuID`=20110 AND `TextID`=29890) OR (`MenuID`=20112 AND `TextID`=29892) OR (`MenuID`=20506 AND `TextID`=14014) OR (`MenuID`=83 AND `TextID`=580) OR (`MenuID`=19706 AND `TextID`=29209) OR (`MenuID`=19704 AND `TextID`=29210) OR (`MenuID`=19705 AND `TextID`=29208) OR (`MenuID`=19929 AND `TextID`=29607);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(19960, 28198), -- 98548 (Chief Telemancer Oculeth)
(19301, 28397), -- 103155 (Arcanist Valtrois)
(19960, 28199), -- 98548 (Chief Telemancer Oculeth)
(18723, 12487), -- 96813 (Aludane Whitecloud)
(19588, 29001), -- 106088 (Cenarius)
(20849, 29996), -- 116760 (Odyn)
(20502, 30698), -- 114263 (Odyn)
(18748, 27380), -- 97140 (First Arcanist Thalyssra)
(18724, 27208), -- 96679 (Aerylia)
(18747, 27251), -- 97389 (Eye of Odyn)
(19764, 29265), -- 107435 (Suspicious Noble)
(19722, 29253), -- 106468 (Ly'leth Lunastre)
(19515, 28836), -- 105729 (Signal Lantern)
(19096, 27923), -- 100635 (Skyseer Ghrent)
(19687, 29172), -- 104618 (Theryn)
(20376, 28901), -- 111903 (Lunastre Attendant)
(20391, 30491), -- 113516 (Dasdonia)
(19783, 29308), -- Ly’leth Lunastre
(20119, 29909), -- Ly’leth Lunastre
(19696, 30287), -- 107253 (Arluin)
(6944, 7778), -- 114718 (Ancient Cloudwing)
(20111, 29891), -- 110874 (Distraught Noble)
(20110, 29890), -- 110876 (Disgruntled Servant)
(20112, 29892), -- 110875 (Shamed Noble)
(20506, 14014), -- 96830 (Linda Ann Kastinglow)
(83, 580), -- 6491 (Spirit Healer)
(19706, 29209), -- 107350 (Cyrille)
(19704, 29210), -- 107348 (Sylessa)
(19705, 29208), -- 107349 (Lorin)
(19929, 29607); -- 109409 (Nightborne Wretch)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=19960 AND `OptionIndex`=1) OR (`MenuId`=19301 AND `OptionIndex`=8) OR (`MenuId`=19301 AND `OptionIndex`=0) OR (`MenuId`=20849 AND `OptionIndex`=1) OR (`MenuId`=20502 AND `OptionIndex`=0) OR (`MenuId`=18748 AND `OptionIndex`=3) OR (`MenuId`=20391 AND `OptionIndex`=0) OR (`MenuId`=20119 AND `OptionIndex`=0) OR (`MenuId`=20111 AND `OptionIndex`=0) OR (`MenuId`=20110 AND `OptionIndex`=0) OR (`MenuId`=20112 AND `OptionIndex`=0) OR (`MenuId`=19696 AND `OptionIndex`=4) OR (`MenuId`=20506 AND `OptionIndex`=1) OR (`MenuId`=19696 AND `OptionIndex`=3) OR (`MenuId`=19706 AND `OptionIndex`=0) OR (`MenuId`=19704 AND `OptionIndex`=0) OR (`MenuId`=19705 AND `OptionIndex`=0) OR (`MenuId`=19696 AND `OptionIndex`=2);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(19960, 1, 0, '<Gain Warpwalking for 10 |TINTERFACE\\ICONS\\INV_MISC_ANCIENT_MANA.BLP:20|t Ancient Mana.>', 121607),
(19301, 8, 0, '<Gain Leyline Mastery for 10 |TINTERFACE\\ICONS\\INV_MISC_ANCIENT_MANA.BLP:20|t Ancient Mana.>', 121650),
(19301, 0, 0, 'All conduits are active. Can you amplify the feed?', 119710),
(20849, 1, 0, 'I am ready to leave now.', 125916),
(20502, 0, 0, 'I will fight her in your name, Odyn!', 123259),
(18748, 3, 0, 'I''ve come to help the withered with their combat training.', 120520),
(20391, 0, 1, 'I''d like to see what goods you have for sale.', 68295),
(20119, 0, 0, 'I am ready to face Coryn.', 119387),
(20111, 0, 0, 'There is talk in the streets that they found a silver crescent near his corpse- is that true?', 119175),
(20110, 0, 0, 'I heard that Coryn Stelleris has begun to purchase the remaining Duskmere attendants - is that true?', 119173),
(20112, 0, 0, 'I overheard a rather crude joke at poor Ruven''s expense while visiting the Stelleris family. I can''t imagine you would want to hear it...', 119174),
(19696, 4, 0, 'Offer: 1200x |TINTERFACE\\ICONS\\INV_MISC_ANCIENT_MANA.BLP:20|t|Hcurrency:1155|h|cFFFFFFFF Ancient Mana|h|r', 121778),
(20506, 1, 0, 'Transmogrification', 56155),
(19696, 3, 0, 'We need your help ''persuading'' some noble houses to support Ly''leth''s bid for advisor. Are you in?', 119241),
(19706, 0, 0, 'The owl hoots at dusk.', 111641),
(19704, 0, 0, 'The cruel caskmaster has breathed his last.', 111639),
(19705, 0, 0, 'The saber prowls the plaza.', 111640),
(19696, 2, 0, 'Offer: 800x |TINTERFACE\\ICONS\\INV_MISC_ANCIENT_MANA.BLP:20|t|Hcurrency:1155|h|cFFFFFFFF Ancient Mana|h|r', 115303);

DELETE FROM `creature_template` WHERE `entry` IN (133271 /*Highmountain Pathfinder*/, 130911 /*Charles Gastly*/);
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `VehicleId`, `HoverHeight`, `VerifiedBuild`) VALUES
(133271, 0, 0, 82820, 82821, 83227, 83228, 'Highmountain Pathfinder', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 64, 0, 1, 1, 0, 0, 0, 110, 110, 83, 0, 1, 1.142857, 2000, 2000, 1, 33024, 2048, 0, 0, 0, 1, 25996), -- Highmountain Pathfinder
(130911, 0, 0, 81476, 0, 0, 0, 'Charles Gastly', NULL, 'Undercity Goods', NULL, NULL, -1, 0, 0, 0, 0, 7, 0, 0, 3, 1, 0, 0, 0, 110, 110, 68, 128, 1, 1.142857, 2000, 2000, 1, 512, 2048, 0, 0, 0, 1, 25996); -- Charles Gastly

UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115566; -- Starving Felstalker
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=107028; -- Arcane Circle
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2099200, `unit_flags3`=1, `HoverHeight`=3 WHERE `entry`=116084; -- Volatile Fel
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=1, `HoverHeight`=3 WHERE `entry`=109469; -- Great Eagle
UPDATE `creature_template` SET `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=39859; -- Dave's Industrial Light and Magic Bunny (Large)(Sessile)
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `faction`=1732, `npcflag`=17179869184, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=97532; -- Violetta
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=4196352 WHERE `entry`=106540; -- Elothir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=4196352 WHERE `entry`=106543; -- Thaon Moonclaw
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=4196352 WHERE `entry`=106539; -- Elerethe Renferal
UPDATE `creature_template` SET `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=111298; -- Purified Life Essence
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=106015; -- Dreambound Druid
UPDATE `creature_template` SET `gossip_menu_id`=19588, `minlevel`=113, `maxlevel`=113, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=4196352 WHERE `entry`=106088; -- Cenarius
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=106381; -- Dreambound Druid
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=106380; -- Dreambound Druid
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=106379; -- Dreambound Druid
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33555200, `unit_flags2`=4196352 WHERE `entry`=106385; -- Ysera
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=1073743872 WHERE `entry`=106477; -- Lethon
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=1073743872 WHERE `entry`=106478; -- Taerar
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=1073743872 WHERE `entry`=106475; -- Emeriss
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=1073743872 WHERE `entry`=106474; -- Ysondre
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=4196352 WHERE `entry`=106463; -- Ursoc
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=4196352 WHERE `entry`=106008; -- Verdant Ancient
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=106010; -- Dreamwisp
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=4196352 WHERE `entry`=105996; -- Emerald Dryad
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=4196352 WHERE `entry`=106531; -- Glade Sprite
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=4196352 WHERE `entry`=106544; -- Glade Sprite
UPDATE `creature_template` SET `npcflag`=1073741824, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=97206; -- Jeune dragonnet du Rêve
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=1771, `speed_walk`=3.2, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=110732; -- Creature of Madness
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587200, `unit_flags2`=1073776640 WHERE `entry`=105245; -- Dream of Ysera
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=1771, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=64, `unit_flags2`=2097152, `VehicleId`=4978 WHERE `entry`=103769; -- Xavius
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=111405; -- Shadow Pounder
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=1771, `speed_walk`=0.8, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=111398; -- Amalgame du Cauchemar
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1771, `speed_walk`=3.6, `speed_run`=1.285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=111413; -- Dark Devourers
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=1771, `speed_walk`=0.8, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=111370; -- Creature in the Shadows
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1771, `speed_walk`=2.8, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=105343; -- Dread Abomination
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=109847; -- Rift of Aln
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=104548; -- Arena Bounds
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1771, `speed_walk`=0.8, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=111350; -- Skittering Shadows
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110973; -- Worthy Vrykul
UPDATE `creature_template` SET `gossip_menu_id`=20849, `minlevel`=113, `maxlevel`=113, `npcflag`=3, `speed_walk`=4.8, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4 WHERE `entry`=116760; -- Odyn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=0.8, `speed_run`=0.2857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=5076 WHERE `entry`=114535; -- Orb of Corrosion
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=37750784, `unit_flags3`=1 WHERE `entry`=114566; -- Orb of Corrosion
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.285714, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33554432 WHERE `entry`=114568; -- Decaying Minion
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=114812; -- Night Watch Mariner
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=100733; -- Charge
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=3.2, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=262208 WHERE `entry`=114809; -- Night Watch Mariner
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=3.2, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=262208 WHERE `entry`=114709; -- Grimelord
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=2.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=5067 WHERE `entry`=115941; -- Kvaldir Longboat
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=114905; -- Gripping Tentacle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=114901; -- Gripping Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=37781504, `unit_flags3`=1, `VehicleId`=5010 WHERE `entry`=114900; -- Gripping Tentacle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=116214; -- Orb of Corruption
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=0.8, `speed_run`=0.2857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=5076 WHERE `entry`=115166; -- Orb of Corruption
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=37750784, `unit_flags3`=1 WHERE `entry`=114523; -- Orb of Corruption
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=114923; -- Shatterbone Skeleton
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=4.5 WHERE `entry`=114811; -- Kvaldir Coral Maiden
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=4.2 WHERE `entry`=114813; -- Kvaldir Tide Witch
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114932; -- Deepbrine Monstrosity
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32832, `unit_flags2`=2097152, `VehicleId`=4995 WHERE `entry`=114323; -- Guarm
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=0.5714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags3`=1 WHERE `entry`=114344; -- Guarm
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=0.5714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags3`=1 WHERE `entry`=114341; -- Guarm
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=0.5714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags3`=1 WHERE `entry`=114343; -- Guarm
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=6 WHERE `entry`=114922; -- Dark Seraph
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33816576, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=117784; -- Gripping Tentacle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33816576, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=117783; -- Gripping Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33600, `unit_flags2`=1073741824, `VehicleId`=5002 WHERE `entry`=114537; -- Helya
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=114639; -- Kvaldir Reefcaller
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=114614; -- Kvaldir Spiritrender
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=114539; -- Kvaldir Reefcaller
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114546; -- Risen Bonethrall
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=268437504 WHERE `entry`=114672; -- Brazier Stalker
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=2, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=114548; -- Rotsoul Giant
UPDATE `creature_template` SET `unit_flags`=33587456, `unit_flags3`=1 WHERE `entry`=109795; -- Os négligés
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=114534; -- Helhound
UPDATE `creature_template` SET `unit_flags`=33587968, `unit_flags3`=1 WHERE `entry`=93094; -- Ancêtre sans repos
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=1.2, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=114547; -- Ancient Bonethrall
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=114538; -- Kvaldir Spiritrender
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=114532; -- Bonespeaker Soulbinder
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2844, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=116229; -- Mythical Champion of the Chosen Dead
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2844, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=116245; -- Heroic Champion of the Chosen Dead
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2844, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=116241; -- Champion of the Chosen Dead
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2844, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=116242; -- Aspiring Champion of the Chosen Dead
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `speed_walk`=4.8, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags2`=4196352, `HoverHeight`=9 WHERE `entry`=114360; -- Hyrja
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `speed_walk`=4.8, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags2`=4196352 WHERE `entry`=114361; -- Hymdall
UPDATE `creature_template` SET `minlevel`=98, `unit_flags`=33587520, `unit_flags3`=1 WHERE `entry`=95834; -- Valarjar Mystic
UPDATE `creature_template` SET `unit_flags`=33587520, `unit_flags3`=1 WHERE `entry`=95842; -- Mande-tonnerre valarjar
UPDATE `creature_template` SET `minlevel`=98, `unit_flags`=33587520, `unit_flags3`=1 WHERE `entry`=97087; -- Valarjar Champion
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `unit_flags`=33587520, `unit_flags3`=1 WHERE `entry`=96574; -- Stormforged Sentinel
UPDATE `creature_template` SET `gossip_menu_id`=20502, `minlevel`=113, `maxlevel`=113, `speed_walk`=6, `speed_run`=2.142857, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags2`=1073741824 WHERE `entry`=114263; -- Odyn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33088, `unit_flags2`=35653632 WHERE `entry`=114785; -- Valarjar Marksman
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33088, `unit_flags2`=2099200 WHERE `entry`=114787; -- Valarjar Runecarver
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_walk`=4, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33088, `unit_flags2`=4196352, `HoverHeight`=6 WHERE `entry`=114791; -- Chosen of Eyir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33088, `unit_flags2`=2099200 WHERE `entry`=114784; -- Valarjar Champion
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33088, `unit_flags2`=2099200 WHERE `entry`=114786; -- Valarjar Mystic
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33088, `unit_flags2`=2099200 WHERE `entry`=114788; -- Mande-tonnerre valarjar
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `speed_walk`=1.6, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33088, `unit_flags2`=4196352 WHERE `entry`=114789; -- Stormforged Sentinel
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112967; -- Valewalker Farodin
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2735, `speed_walk`=1.2, `speed_run`=0.4285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33600, `unit_flags2`=2097152, `unit_flags3`=1, `VehicleId`=4827 WHERE `entry`=110908; -- Spellblade Aluriel
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=110946; -- Haughty Aristocrat
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=106113; -- Lifesized Nightborne Statue
UPDATE `creature_template` SET `gossip_menu_id`=19764 WHERE `entry`=112699; -- Suspicious Noble
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=69240832, `unit_flags3`=1 WHERE `entry`=106018; -- Bazaar Goods
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_walk`=0.4, `speed_run`=0.1428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048, `VehicleId`=4821 WHERE `entry`=108422; -- Automated Sweeper
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2735, `speed_walk`=0.4, `speed_run`=0.1428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33587456, `unit_flags2`=2048 WHERE `entry`=108421; -- Mana Kitten
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=69240832, `unit_flags3`=1 WHERE `entry`=105160; -- Fel Orb
UPDATE `creature_template` SET `gossip_menu_id`=19764 WHERE `entry`=107435; -- Suspicious Noble
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=103130; -- Timeless Wraith
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=1073743872 WHERE `entry`=98208; -- Conseiller Vandros
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=2.8, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=100393; -- Dread Felbat
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_walk`=5.6, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048 WHERE `entry`=99628; -- Suppression Protocol
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2621440 WHERE `entry`=98734; -- Night Crystal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=98435; -- Unstable Oozeling
UPDATE `creature_template` SET `faction`=2156, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=105845; -- Glowing Spiderling
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=98426; -- Unstable Ooze
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=99446; -- Pipe Stalker
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98205; -- Corstilax
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4194304 WHERE `entry`=98203; -- Ivanyr
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200, `unit_flags3`=1, `HoverHeight`=7.5 WHERE `entry`=98207; -- Nal’tira
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=110833; -- Infernal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=98759; -- Vicious Manafang
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=105876; -- Enchanted Broodling
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=98206; -- Général Xakal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=105921; -- Nightborne Spellsword
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=105915; -- Nightborne Reclaimer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570721024, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=105848; -- Wyrm Corpse
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=0.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=106059; -- Warp Shade
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.2, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570721024, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=106013; -- Unstable Amalgamation Corpse
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=102351; -- Mana Wyrm
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=105651; -- Dreadborne Seer
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=0.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98756; -- Arcane Anomaly
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=105682; -- Felguard Destroyer
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570721024, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=102541; -- Withered Corpse
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=105706; -- Priestess of Misery
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=0.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=105952; -- Ame en peine de mana flétrie
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=3.2, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=105629; -- Wyrmtongue Scavenger
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=98772; -- Dread Felbat
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98770; -- Wrathguard Felblade
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=98728; -- Acidic Bile
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=3.2, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=105617; -- Eredar Chaosbringer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98732; -- Plagued Rat
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=0.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=98733; -- Withered Fiend
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.2, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=35653632 WHERE `entry`=98425; -- Unstable Amalgamation
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=2.4, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570721024, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=105493; -- Withered Corpse
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=640, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=111918; -- Almon
UPDATE `creature_template` SET `gossip_menu_id`=20376, `speed_run`=1.142857 WHERE `entry`=111903; -- Lunastre Attendant
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=110965; -- Elisande
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2823, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=110967; -- Coryn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=110736; -- Haughty Noble
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2802, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=115600; -- Terrified Nightfallen
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116118; -- Felborne Magus
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=110804; -- Ailen
UPDATE `creature_template` SET `gossip_menu_id`=20110, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=110876; -- Disgruntled Servant
UPDATE `creature_template` SET `gossip_menu_id`=20112, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=110875; -- Shamed Noble
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=112870; -- Stelleris Attendant
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=110680; -- Ailen Astravar
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110734; -- Stelleris Thug
UPDATE `creature_template` SET `gossip_menu_id`=20111, `minlevel`=110, `maxlevel`=110, `faction`=2855, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=110874; -- Distraught Noble
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=93319; -- Ashmaw Cub
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100496; -- Silvered Streaker
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32768 WHERE `entry`=93318; -- Ashmaw Mauler
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=105882; -- Sylendra Gladesong
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105920; -- Darkfiend Raider
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105897; -- Pilleur sombrefiel
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=0 WHERE `entry`=95720; -- Druid of the Antler
UPDATE `creature_template` SET `unit_flags`=537165824, `unit_flags2`=2049 WHERE `entry`=95719; -- Druid of the Antler
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=91462; -- Malfurion Stormrage
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=93512; -- Azalea
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=93316; -- Gleamhoof Fawn
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=35, `speed_run`=1.357143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=120600; -- Druid of the Talon
UPDATE `creature_template` SET `faction`=31, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=62178; -- Lapin elfique
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048 WHERE `entry`=72654; -- General Purpose Stalker (RKS)
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107635; -- Keeper of the Grove
UPDATE `creature_template` SET `faction`=2892, `unit_flags2`=33556480 WHERE `entry`=93462; -- Lorlathil Sentry
UPDATE `creature_template` SET `npcflag`=82 WHERE `entry`=98135; -- Wildcrafter Osme
UPDATE `creature_template` SET `minlevel`=110 WHERE `entry`=93508; -- Lorlathil Druid
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=110, `speed_run`=1.142857 WHERE `entry`=93469; -- Majestic Gladewatcher
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=94179; -- Aranelle
UPDATE `creature_template` SET `faction`=31, `unit_flags2`=2048 WHERE `entry`=63607; -- Squirrel
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=108712; -- Shriektalon Totem
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=108364; -- Goop Jelly
UPDATE `creature_template` SET `unit_flags3`=8192 WHERE `entry`=108362; -- Blood Drip
UPDATE `creature_template` SET `minlevel`=98, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=108641; -- Boneflux
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `npcflag`=4225, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=109306; -- Myria Glenbrook
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=108612; -- Goop Jelly
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=93313; -- Gleamhoof Stag
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109809; -- Deepwoods Owl
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112991; -- Fawn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=108304; -- Guviena Bladesong
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=0, `unit_flags2`=2048 WHERE `entry`=94460; -- Brown Squirrel
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=93314; -- Gleamhoof Doe
UPDATE `creature_template` SET `unit_flags`=131072, `unit_flags3`=1 WHERE `entry`=32666; -- Training Dummy
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=82 WHERE `entry`=4752; -- Kildar
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3357; -- Makaru
UPDATE `creature_template` SET `maxlevel`=79, `faction`=29 WHERE `entry`=31757; -- Stabled Hunter Pet
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=47788; -- Guldor
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=12353; -- Timber Riding Wolf
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3 WHERE `entry`=3352; -- Ormak Grimshot
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=47767; -- Korla
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=131072, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=114840; -- PvP Training Dummy
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=5195; -- Brown Riding Wolf
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=47771; -- Drukma
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=47764; -- Murog
UPDATE `creature_template` SET `minlevel`=76, `maxlevel`=76 WHERE `entry`=31758; -- Stabled Hunter Pet
UPDATE `creature_template` SET `maxlevel`=78, `faction`=29 WHERE `entry`=31756; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=76, `maxlevel`=76 WHERE `entry`=31769; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=75, `maxlevel`=80, `faction`=29, `speed_walk`=1 WHERE `entry`=31755; -- Stabled Hunter Pet
UPDATE `creature_template` SET `speed_run`=1.385714, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=65065; -- Red Dragon Turtle
UPDATE `creature_template` SET `minlevel`=75, `maxlevel`=75, `faction`=29, `speed_run`=1.142857 WHERE `entry`=31768; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=46638; -- Auctioneer Vizput
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=46640; -- Auctioneer Kuvi
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `unit_flags`=33536 WHERE `entry`=16869; -- Jising
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `unit_flags`=33536 WHERE `entry`=16868; -- Winsum
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=2, `speed_run`=1.385714, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=65061; -- Brown Dragon Turtle
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=2, `speed_run`=1.385714, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=65060; -- Blue Dragon Turtle
UPDATE `creature_template` SET `speed_run`=1.385714, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=65058; -- Black Dragon Turtle
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `unit_flags`=33536 WHERE `entry`=5034; -- Winwa
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `unit_flags`=33536 WHERE `entry`=5029; -- Jiming
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `unit_flags`=33536 WHERE `entry`=2756; -- Chao-Ju
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=46639; -- Auctioneer Zilbeena
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=46637; -- Auctioneer Drezbit
UPDATE `creature_template` SET `speed_run`=1.385714, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=65063; -- Purple Dragon Turtle
UPDATE `creature_template` SET `speed_run`=1.385714, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=65074; -- Great Blue Dragon Turtle
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=70301; -- Softpaws
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=2, `speed_run`=1.385714, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=65071; -- Great Green Dragon Turtle
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3 WHERE `entry`=42638; -- Herezegor Flametusk
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1, `unit_flags2`=2048 WHERE `entry`=62445; -- Ji Firepaw
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=65008; -- Huojin Monk
UPDATE `creature_template` SET `npcflag`=1, `unit_flags2`=2048 WHERE `entry`=66022; -- Turtlemaster Odai
UPDATE `creature_template` SET `speed_run`=0.8571429, `unit_flags2`=2048 WHERE `entry`=68869; -- Luo Luo
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=2, `speed_run`=1.385714, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=65076; -- Great Brown Dragon Turtle
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=15186; -- Bourbie
UPDATE `creature_template` SET `speed_run`=1.385714, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=65078; -- Great Purple Dragon Turtle
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=69333; -- Disciple Jusi
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=7951; -- Zas'Tysh
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=66437; -- Arcanist Xu
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=46642; -- Innkeeper Nufa
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3332; -- Lumak
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=43239; -- Razgar
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19175; -- Orc Commoner
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=16076; -- Tharl Stonebleeder
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=16069; -- Gloubie
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=47663; -- Scout Obrok
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=62193; -- Rok'kal
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3 WHERE `entry`=49750; -- Warchief's Herald
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=2855; -- Snang
UPDATE `creature_template` SET `faction`=2268, `unit_flags`=32768, `unit_flags3`=0 WHERE `entry`=72559; -- Thunder Bluff Protector
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3365; -- Karolek
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=5811; -- Kamari
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=14451; -- Orphan Matron Battlewail
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=20, `unit_flags`=570556416, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=3225; -- Corrupted Mottled Boar
UPDATE `creature_template` SET `maxlevel`=3, `speed_run`=1.142857 WHERE `entry`=14499; -- Horde Orphan
UPDATE `creature_template` SET `unit_flags`=131072, `unit_flags3`=1 WHERE `entry`=46647; -- Training Dummy
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=2857; -- Thund
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3413; -- Sovik
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3412; -- Nogg
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=83 WHERE `entry`=11017; -- Roxxik
UPDATE `creature_template` SET `gossip_menu_id`=0, `RangeAttackTime`=2000 WHERE `entry`=23635; -- Krixx
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `unit_flags3`=1 WHERE `entry`=31146; -- Raider's Training Dummy
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=62197; -- Zazzle
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=62196; -- Flekky Nox
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=7010; -- Zilzibin Drumlore
UPDATE `creature_template` SET `npcflag`=80 WHERE `entry`=46716; -- Nerog
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=10880; -- Warcaller Gorlach
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=12136; -- Snurk Bucksquick
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=11066; -- Jhag
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=3348; -- Kor'geld
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=83 WHERE `entry`=3345; -- Godan
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=11046; -- Whuut
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=46181; -- Enchanter Farendin
UPDATE `creature_template` SET `gossip_menu_id`=0, `unit_class`=4 WHERE `entry`=8659; -- Jes'rimon
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=81 WHERE `entry`=46741; -- Muraga
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3347; -- Yelmak
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=47321; -- Zugra Flamefist
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=54004; -- Jaga
UPDATE `creature_template` SET `gossip_menu_id`=0, `unit_flags3`=1 WHERE `entry`=58199; -- Lord Itharius
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=50088; -- Waters of Farseeing
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=58193; -- Wyrmrest Protector
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3 WHERE `entry`=13417; -- Sagorne Creststrider
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=72939; -- Terga Earthbreaker
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=3403; -- Sian'tsu
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=5, `speed_run`=1.142857 WHERE `entry`=42548; -- Muddy Crawfish
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=44785; -- Miwana
UPDATE `creature_template` SET `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=61367; -- Serpent d'eau
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=44788; -- Lonto
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=44787; -- Auctioneer Sowata
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3322; -- Kaja
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=19176; -- Tauren Commoner
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=44781; -- Opuno Ironhorn
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=44783; -- Hiwahi Three-Feathers
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=15188; -- Cenarion Emissary Blackhoof
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=44743; -- Nohi Plainswalker
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=44723; -- Nahu Ragehoof
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=44740; -- Sahi Cloudsinger
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3 WHERE `entry`=44726; -- Shalla Whiteleaf
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=47571; -- Belloc Brightblade
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=35068; -- Gotura Fourwinds
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=29143; -- Bebri Coifcurl
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=74228; -- Darkspear Headhunter
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=14377; -- Scout Tharr
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=34765; -- Zelli Hotnozzle
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=9564; -- Frezza
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=26537; -- Greeb Ramrocket
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109912; -- Captive Wyrmtongue
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=51346; -- Coursier du vent d’Orgrimmar
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=15476; -- Scorpid
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=14881; -- Spider
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=15579; -- Elder Darkhorn
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=8, `maxlevel`=8 WHERE `entry`=44160; -- Suspicious Peon
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=62114; -- Lézard épineux
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3310; -- Doras
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=1735, `npcflag`=3, `speed_walk`=2, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=14720; -- High Overlord Saurfang
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19177; -- Troll Commoner
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=44158; -- Orgrimmar Skyway Peon
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=44735; -- Seer Liwatha
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=44725; -- Sunwalker Atohmo
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=5875; -- Mordak Darkfist
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=49837; -- Spiny Lizard
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3328; -- Ormok
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3327; -- Gest
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3216; -- Arnak Fireblade
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=47233; -- Gordul
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3296; -- Orgrimmar Grunt
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=47246; -- Ureda
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=47253; -- Rundok
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=47247; -- Marud
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=47248; -- Gija
UPDATE `creature_template` SET `minlevel`=98 WHERE `entry`=96698; -- Chevalier de sang
UPDATE `creature_template` SET `minlevel`=98 WHERE `entry`=96708; -- Chevalier de sang
UPDATE `creature_template` SET `npcflag`=131073 WHERE `entry`=96817; -- Teller Rames
UPDATE `creature_template` SET `npcflag`=131073 WHERE `entry`=96819; -- Teller Althiellis
UPDATE `creature_template` SET `npcflag`=131073 WHERE `entry`=96818; -- Teller Hanners
UPDATE `creature_template` SET `minlevel`=98, `unit_flags3`=1 WHERE `entry`=108710; -- Guardian Orb
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110 WHERE `entry`=107622; -- Gloutonia
UPDATE `creature_template` SET `minlevel`=82, `maxlevel`=90, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=58237; -- Tweek
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=92183; -- Alard Schmied
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=51200, `VehicleId`=4927 WHERE `entry`=112130; -- Archimage Khadgar
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `HoverHeight`=1.5 WHERE `entry`=112227; -- Atiesh
UPDATE `creature_template` SET `npcflag`=19 WHERE `entry`=92464; -- Kuhuine Tenderstride
UPDATE `creature_template` SET `minlevel`=98 WHERE `entry`=108401; -- Blacksmith Kyriel
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=93189; -- Mama Diggs
UPDATE `creature_template` SET `npcflag`=4307 WHERE `entry`=106655; -- Arcanomancer Vridiel
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=92185; -- Braeg Stoutbeard
UPDATE `creature_template` SET `minlevel`=75, `maxlevel`=75, `faction`=2007, `unit_class`=8, `unit_flags`=32768 WHERE `entry`=32454; -- Dalaran Citizen
UPDATE `creature_template` SET `faction`=2839, `npcflag`=130, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=115264; -- Illnea Bloodthorn
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `faction`=1732, `npcflag`=17179869184, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=97493; -- Narestel Pâlétoile
UPDATE `creature_template` SET `npcflag`=17179869184, `unit_flags3`=32 WHERE `entry`=97515; -- Tristesse
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=96586; -- Master Smith Helgar
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=111774; -- Matilda Skoptidottir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1168231104515, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2048, `HoverHeight`=4 WHERE `entry`=106460; -- Savyn Valorborn
UPDATE `creature_template` SET `gossip_menu_id`=19096 WHERE `entry`=100635; -- Skyseer Ghrent
UPDATE `creature_template` SET `minlevel`=98, `speed_run`=1.142857 WHERE `entry`=113270; -- Vierge guerrière
UPDATE `creature_template` SET `minlevel`=102, `maxlevel`=108 WHERE `entry`=105904; -- Raven
UPDATE `creature_template` SET `npcflag`=17179869184, `unit_flags3`=32 WHERE `entry`=97509; -- Grand maléficieur Ohodo
UPDATE `creature_template` SET `gossip_menu_id`=18723 WHERE `entry`=96813; -- Aludane Whitecloud
UPDATE `creature_template` SET `minlevel`=101, `maxlevel`=101 WHERE `entry`=96636; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=109, `maxlevel`=109 WHERE `entry`=96641; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=107, `maxlevel`=107 WHERE `entry`=96635; -- Stabled Hunter Pet
UPDATE `creature_template` SET `gossip_menu_id`=20506 WHERE `entry`=96830; -- Linda Ann Kastinglow
UPDATE `creature_template` SET `minlevel`=101, `maxlevel`=101 WHERE `entry`=96592; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105 WHERE `entry`=96639; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2847, `npcflag`=640, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=113485; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115755; -- Scathing Felbeast
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=110656; -- Arcanist Lylandre
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=42, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=110651; -- Lylandre's Frost Crystal
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108190; -- Magisterial Sleuth
UPDATE `creature_template` SET `npcflag`=0, `speed_run`=1.142857 WHERE `entry`=109202; -- Vintner Iltheux
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=109310; -- Shadefruit Stalker
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=109305; -- Arcwine Event Missile Target
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=109313; -- Night Lily Stalker
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=109312; -- Purified Water Stalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=110679; -- Aurore
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=100775; -- Lilryia Dawnwind
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103223; -- Hertha Grimdottir
UPDATE `creature_template` SET `minlevel`=25, `maxlevel`=25, `faction`=188, `npcflag`=16777216, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=105323; -- Oeufs des catacombes anciens
UPDATE `creature_template` SET `faction`=31, `unit_flags2`=2048 WHERE `entry`=65343; -- Araignée des ossements
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108874; -- Vineyard Attendant
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=2 WHERE `entry`=107632; -- Ly’leth Lunastre
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=108870; -- Sylverin
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=115561; -- Duskwatch Felblade
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=115562; -- Duskwatch Felblade
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2802, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=115563; -- Captured Nightfallen
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=107225; -- Deline
UPDATE `creature_template` SET `gossip_menu_id`=19706, `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=107350; -- Cyrille
UPDATE `creature_template` SET `gossip_menu_id`=19704, `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=107348; -- Sylessa
UPDATE `creature_template` SET `gossip_menu_id`=19705, `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=107349; -- Lorin
UPDATE `creature_template` SET `npcflag`=32769, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=72676; -- Spirit Healer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102303; -- Lieutenant Strathmar
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103131; -- Keelay Moongrow
UPDATE `creature_template` SET `unit_flags`=570721024, `unit_flags2`=33556481, `unit_flags3`=8192 WHERE `entry`=113707; -- Duskwatch Astralite
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111685; -- Loyalist Aristocrat
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111771; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113843; -- Kieule
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=104844; -- "Old Wise" Ewaye
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109463; -- Magisterial Escort
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99638; -- Caged Polar Bear
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109461; -- Vineyard Porter
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110987; -- Nighteyes
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109509; -- Spellsinger Quiris
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2847, `npcflag`=640, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=113487; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113486; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=113675; -- Wyrmtongue Scribe
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116360; -- Duskwatch Scryer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110786; -- Astravar Attendant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110783; -- Courtly Noble
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110780; -- Astravar Attendant
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=105646; -- Captive Basilisk
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111651; -- Degren
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=112547; -- Tempomancer Virinya
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111699; -- Loyalist Aristocrat
UPDATE `creature_template` SET `gossip_menu_id`=83 WHERE `entry`=6491; -- Spirit Healer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112489; -- Callus
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111653; -- Miasu
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111557; -- Legion Battlematron
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108931; -- Vineyard Laborer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112530; -- Garion
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109669; -- High Society Entertainer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110655; -- Duskmere Smuggler
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107342; -- Duskwatch Spell-Fencer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110365; -- Ruven
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110654; -- Frightened Laborer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109652; -- Duskwatch Warpcaster
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112531; -- Leleyna
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111558; -- Felgaze Doomseer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111523; -- Duskwatch Warpcaster
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111730; -- Felsworn Noble
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111749; -- Felborne Collaborator
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111750; -- Felborne Collaborator
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111747; -- Felsworn Noble
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108188; -- Imperial Arcbinder
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111485; -- Duskwatch Spellshield
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111649; -- Ambassador D'vwinn
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109650; -- Duskwatch Spell-Fencer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109647; -- Imperial Arcbinder
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111489; -- Loyalist Sycophant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108189; -- Imperial Servant
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111490; -- Flagorneur loyaliste
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110728; -- Marina Sentry
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111484; -- Duskwatch Spellshield
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109670; -- Chronarch Defender
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111498; -- Imperial Servant
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=116655; -- High Society Harpist
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2886, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116653; -- Loyalist Spectator
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2851, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114869; -- Bourreau du moteur d’âmes
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2851, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114959; -- Molosse du moteur d’âmes
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `VehicleId`=5023 WHERE `entry`=114997; -- Felsoul Ferry
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2851, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114904; -- Geôlier du moteur d’âmes
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `VehicleId`=5087 WHERE `entry`=116660; -- Felsoul Ferry
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2886, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115012; -- Felborne Conspirator
UPDATE `creature_template` SET `gossip_menu_id`=19696, `speed_run`=1.142857 WHERE `entry`=107253; -- Arluin
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=103005; -- Bowl of Fruit
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=114892; -- Civil flétrissant
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=114889; -- Civile shal’dorei
UPDATE `creature_template` SET `unit_flags2`=34816 WHERE `entry`=107598; -- Vanthir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2855, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=111904; -- Waning Crescent Porter
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=108063; -- Korine
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100096; -- Thaedris Feathersong
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2200, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=109411; -- Shadescale Flyeater
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2575, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=109158; -- Underglow Locust
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=111675; -- Ancient Cloudwing

SET @GROUP_ID := 0;
SET @ID := 0;

REPLACE INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(97140, @GROUP_ID+0, @ID+0, 'We will carry this burden, Valewalker. Have a little faith.', 12, 0, 100, 0, 0, 0, 119829, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+1, @ID+0, 'What is happening?', 12, 0, 100, 0, 0, 67312, 120007, 'First Arcanist Thalyssra to Player'), -- BroadcastTextID: 13848 - 41765 - 45913 - 120007
(97140, @GROUP_ID+2, @ID+0, 'Outlander, speak with Valtrois at once!', 12, 0, 100, 0, 0, 67315, 118614, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+3, @ID+0, 'Valtrois, can you think of any way to draw more power? Even briefly?', 12, 0, 100, 0, 0, 67320, 118618, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+4, @ID+0, 'What could make the leyline flare up?', 12, 0, 100, 0, 0, 67323, 118622, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+5, @ID+0, 'Spare us the details, just make it happen. I am counting on you.', 12, 0, 100, 0, 0, 67327, 118626, 'First Arcanist Thalyssra to Player'),
(98203, @GROUP_ID+0, @ID+0, 'Stay back! It''s mine!', 14, 0, 100, 0, 0, 57762, 101906, 'Ivanyr to Player'),
(98203, @GROUP_ID+1, @ID+0, 'Thieves! The mana is MINE!', 14, 0, 100, 0, 0, 57765, 101907, 'Ivanyr to Player'),
(98203, @GROUP_ID+2, @ID+0, 'Go away!', 14, 0, 100, 0, 0, 57757, 101910, 'Ivanyr'), -- BroadcastTextID: 60662 - 76912 - 77511 - 89307 - 101910
(98203, @GROUP_ID+3, @ID+0, 'More... more...', 14, 0, 100, 0, 0, 57764, 101914, 'Ivanyr to Player'),
(98206, @GROUP_ID+0, @ID+0, 'Form up, maggots! Secure the breach until we receive orders from Gul''dan!', 14, 0, 100, 0, 0, 57770, 105710, 'General Xakal to Player'),
(98206, @GROUP_ID+1, @ID+0, 'Good! Some entertainment! I was getting restless!', 14, 0, 100, 0, 0, 57772, 105711, 'General Xakal to Player'),
(98206, @GROUP_ID+2, @ID+0, 'No... NO! None can best... the great Xakal...', 14, 0, 100, 0, 0, 57771, 105713, 'General Xakal to Player'),
(98208, @GROUP_ID+0, @ID+0, 'I have not survived for ten thousand years just to fall to a swarm of rats.', 14, 0, 100, 0, 0, 57783, 105700, 'Advisor Vandros to Player'),
(98208, @GROUP_ID+1, @ID+0, 'I am a conduit of the Nightwell''s glorious power! I am NIGHTBORNE!', 14, 0, 100, 0, 0, 57784, 105708, 'Advisor Vandros'),
(98208, @GROUP_ID+2, @ID+0, '|TInterface\\Icons\\Spell_Holy_BorrowedTime:20|tRe-engage Advisor Vandros before you are |cFFF00000|Hspell:203935|h[Lost In Time]|h|r!', 41, 0, 100, 0, 0, 0, 105697, 'Advisor Vandros'),
(98208, @GROUP_ID+3, @ID+0, 'Enough! You little beasts are getting out of hand!', 14, 0, 100, 0, 0, 57786, 105706, 'Advisor Vandros to Player'),
(98208, @GROUP_ID+4, @ID+0, 'The Grand Magistrix... will have your heads for this...', 14, 0, 100, 0, 0, 57782, 105701, 'Advisor Vandros to Player'),
(98548, @GROUP_ID+0, @ID+0, 'A manastorm might do the trick.', 12, 0, 100, 0, 0, 67324, 118623, 'Chief Telemancer Oculeth to Player'),
(98548, @GROUP_ID+1, @ID+0, 'Yes. But it could work! We create a localized warp field, then-', 12, 0, 100, 0, 0, 67326, 118625, 'Chief Telemancer Oculeth to Player'),
(98548, @GROUP_ID+2, @ID+0, 'Yes, ma''am!', 12, 0, 100, 0, 0, 67328, 118627, 'Chief Telemancer Oculeth to Player'),
(98548, @GROUP_ID+3, @ID+0, 'Ahh, thank you.', 12, 0, 100, 0, 0, 71457, 121587, 'Chief Telemancer Oculeth to Player'),
(103155, @GROUP_ID+0, @ID+0, 'Every leyline feed is active and at full power!', 12, 0, 100, 0, 0, 67318, 118616, 'Arcanist Valtrois to Player'),
(103155, @GROUP_ID+1, @ID+0, 'Hmm... The main conduit beneath Suramar city pulls ten times what we have here.', 12, 0, 100, 0, 0, 67321, 118619, 'Arcanist Valtrois to Player'),
(103155, @GROUP_ID+2, @ID+0, 'If that leyline were to flare up, the surge could theoretically reach all the way back to Shal''Aran.', 12, 0, 100, 0, 0, 67322, 118620, 'Arcanist Valtrois to Player'),
(103155, @GROUP_ID+3, @ID+0, 'A manastorm, are you insane?', 12, 0, 100, 0, 0, 67325, 118624, 'Arcanist Valtrois to Player'),
(103155, @GROUP_ID+4, @ID+0, 'Right away.', 12, 0, 100, 0, 0, 67329, 118628, 'Arcanist Valtrois to Player'), -- BroadcastTextID: 80702 - 112284 - 118628
(103769, @GROUP_ID+0, @ID+0, 'The Nightmare has corrupted dragons, gods, and legends. Your downfall will be simple and swift!', 14, 0, 100, 0, 0, 58726, 109326, 'Xavius'),
(103769, @GROUP_ID+1, @ID+0, 'I''ll slice into the heart of you!', 14, 0, 100, 0, 0, 58737, 109348, 'Xavius to Player'),
(103769, @GROUP_ID+2, @ID+0, 'Time to crush your dreams!', 14, 0, 100, 0, 0, 58751, 109353, 'Xavius'),
(103769, @GROUP_ID+3, @ID+0, 'Nightmares are... never... forgotten...', 14, 0, 100, 0, 0, 58736, 109347, 'Xavius to Player'),
(104215, @GROUP_ID+0, @ID+0, 'No trespassers allowed!', 14, 0, 100, 0, 0, 58627, 108480, 'Patrol Captain Gerdo to Player'),
(104215, @GROUP_ID+1, @ID+0, 'I need reinforcements!', 14, 0, 100, 0, 0, 58636, 108486, 'Patrol Captain Gerdo'),
(104215, @GROUP_ID+2, @ID+0, '|TInterface\\Icons\\ability_socererking_arcaneacceleration|t%s begins to cast |cFFFF0000|Hspell:207278|h[Arcane Lockdown]|h|r! Jump to remove the effect!', 41, 0, 100, 0, 0, 0, 111983, 'Patrol Captain Gerdo'),
(104215, @GROUP_ID+3, @ID+0, 'This will even the odds!', 14, 0, 100, 0, 0, 58629, 108488, 'Patrol Captain Gerdo'),
(104215, @GROUP_ID+4, @ID+0, 'My watch... is ended.', 14, 0, 100, 0, 0, 58628, 108484, 'Patrol Captain Gerdo to Player'),
(104217, @GROUP_ID+0, @ID+0, 'Make yourself useful and take a look around!', 14, 0, 100, 0, 0, 58644, 108509, 'Talixae Flamewreath to Felbound Enforcer'),
(104217, @GROUP_ID+1, @ID+0, 'What are you waiting for? Check out that noise!', 14, 0, 100, 0, 0, 58645, 108510, 'Talixae Flamewreath to Felbound Enforcer'),
(104217, @GROUP_ID+2, @ID+0, 'You! Have a look over there!', 14, 0, 100, 0, 0, 58646, 108512, 'Talixae Flamewreath to Felbound Enforcer'),
(104217, @GROUP_ID+3, @ID+0, 'Who needs henchmen? I''ll burn you myself!', 14, 0, 100, 0, 0, 58639, 108517, 'Talixae Flamewreath to Player'),
(104217, @GROUP_ID+4, @ID+0, 'Mortal flesh... so pretty when it burns!', 14, 0, 100, 0, 0, 58640, 108514, 'Talixae Flamewreath'),
(104217, @GROUP_ID+5, @ID+0, 'My funeral pyre... will be... glorious...', 14, 0, 100, 0, 0, 58643, 108507, 'Talixae Flamewreath to Player'),
(104218, @GROUP_ID+0, @ID+0, 'Must you leave so soon, Grand Magistrix?', 12, 0, 100, 0, 0, 67729, 117105, 'Advisor Melandrus to Player'),
(104218, @GROUP_ID+1, @ID+0, 'Impossible! My guards would never permit such an intrusion!', 12, 0, 100, 0, 0, 67728, 117088, 'Advisor Melandrus to Player'),
(104218, @GROUP_ID+2, @ID+0, 'Finally. I''ll make this quick.', 14, 0, 100, 0, 0, 58650, 108987, 'Advisor Melandrus to Player'),
(104218, @GROUP_ID+3, @ID+0, 'If you blink... you bleed!', 14, 0, 100, 0, 0, 58654, 108998, 'Advisor Melandrus'),
(104218, @GROUP_ID+4, @ID+0, 'The wind slices to the bone!', 14, 0, 100, 0, 0, 58655, 108993, 'Advisor Melandrus'),
(104218, @GROUP_ID+5, @ID+0, 'Bleed for the Grand Magistrix!', 14, 0, 100, 0, 0, 58657, 108995, 'Advisor Melandrus'),
(104218, @GROUP_ID+6, @ID+0, 'Elisande... forgive me!', 14, 0, 100, 0, 0, 58658, 109002, 'Advisor Melandrus to Player'),
(104245, @GROUP_ID+0, @ID+0, '|TInterface\\Icons\\INV_Misc_Bell_01:20|tAn alarm has been sounded! A reinforcement has entered the fray!', 41, 0, 100, 0, 0, 0, 109270, 'Arcane Beacon to Duskwatch Sentry'),
(104251, @GROUP_ID+0, @ID+0, '|TInterface\\Icons\\INV_Misc_Bell_01:20|tA %s has been alerted to your presence!', 41, 0, 100, 0, 0, 0, 109269, 'Duskwatch Sentry to Player'),
(104278, @GROUP_ID+0, @ID+0, 'The Legion.. will prevail!', 14, 0, 100, 0, 0, 71114, 109577, 'Felbound Enforcer to Player'),
(104278, @GROUP_ID+1, @ID+0, 'You will never stop our plans!', 14, 0, 100, 0, 0, 71111, 109580, 'Felbound Enforcer to Player'),
(104278, @GROUP_ID+2, @ID+0, 'The Emissary must be notified!', 14, 0, 100, 0, 0, 71112, 109579, 'Felbound Enforcer to Player'),
(104694, @GROUP_ID+0, @ID+0, 'Hey, keep it down out there! We''re trying to have a party!', 14, 0, 100, 5, 0, 0, 116332, 'Suramar Citizen to Player'),
(104695, @GROUP_ID+0, @ID+0, 'You''re not welcome here!', 12, 0, 100, 0, 0, 0, 121050, 'Suramar Merchant'),
(104695, @GROUP_ID+1, @ID+0, '%s runs away in terror!', 16, 0, 100, 11, 0, 0, 121586, 'Suramar Merchant'),
(104696, @GROUP_ID+0, @ID+0, 'Outsiders!', 12, 0, 100, 0, 0, 0, 121049, 'Suramar Civilian'),
(104696, @GROUP_ID+1, @ID+0, 'How did you get in here?', 12, 0, 100, 0, 0, 0, 121051, 'Suramar Civilian'),
(105296, @GROUP_ID+0, @ID+0, 'Your arrival is fortuitous. Tonight, the nobles have gathered in honor of the Grand Magistrix.', 12, 0, 100, 396, 0, 70446, 108582, 'Ly''leth Lunastre to Player'),
(105296, @GROUP_ID+1, @ID+0, 'Our spies report that Elisande herself will attend. This presents a rare opportunity to catch her away from her source of power.', 12, 0, 100, 396, 0, 70447, 108583, 'Ly''leth Lunastre to Player'),
(105296, @GROUP_ID+2, @ID+0, 'We''ll take a side entrance to the grounds... too many eyes are watching the front.', 12, 0, 100, 396, 0, 70448, 108584, 'Ly''leth Lunastre to Player'),
(105296, @GROUP_ID+3, @ID+0, 'This is your best chance to eliminate the Grand Magistrix. Good luck!', 12, 0, 100, 396, 0, 70449, 108586, 'Ly''leth Lunastre to Player'),
(105759, @GROUP_ID+0, @ID+0, 'Who goes there?!', 12, 0, 100, 0, 0, 66005, 124631, 'High Mage of the Duskwatch to Player'), -- BroadcastTextID: 105557 - 118520 - 124631
(105759, @GROUP_ID+1, @ID+0, 'Something''s not quite right...', 12, 0, 100, 0, 0, 65803, 124630, 'High Mage of the Duskwatch to Player'), -- BroadcastTextID: 105558 - 118519 - 124630
(105759, @GROUP_ID+2, @ID+0, 'An illusion! What are you hiding?', 12, 0, 100, 0, 0, 66003, 124629, 'High Mage of the Duskwatch to Player'), -- BroadcastTextID: 105559 - 118518 - 124629
(105759, @GROUP_ID+3, @ID+0, 'None may challenge us!', 12, 0, 100, 0, 0, 66026, 116701, 'High Mage of the Duskwatch to Player'), -- BroadcastTextID: 116687 - 116701
(106468, @GROUP_ID+0, @ID+0, 'You''ve done well so far, but we must ensure you blend in at the party. I''ll enhance your disguise, infusing it with latent magic to make you appear as one of the nobles.', 12, 0, 100, 396, 0, 70450, 108585, 'Ly''leth Lunastre'),
(106616, @GROUP_ID+0, @ID+0, 'You can''t break through the force fields! The shields are too strong!', 12, 0, 100, 0, 0, 65988, 112869, 'Nightborne Child'), -- BroadcastTextID: 112866 - 112869
(106616, @GROUP_ID+1, @ID+0, 'No fair, you always get to be the Grand Magistrix!', 12, 0, 100, 0, 0, 65976, 112871, 'Nightborne Child'),
(106617, @GROUP_ID+0, @ID+0, 'Pew pew pew! Lightning Missiles!', 12, 0, 100, 0, 0, 65974, 112868, 'Nightborne Child'), -- BroadcastTextID: 112867 - 112868
(107126, @GROUP_ID+0, @ID+0, 'Meet me at the temple of Fal''adora. We must study the past to preserve our future.', 12, 0, 100, 0, 0, 66380, 118552, 'Valewalker Farodin to Player'),
(107126, @GROUP_ID+1, @ID+0, 'Even in this state, the arcan''dor continues to grow.', 12, 0, 100, 0, 0, 66382, 118554, 'Valewalker Farodin to Player'),
(107126, @GROUP_ID+2, @ID+0, 'A pure life essence... I only hope it is enough.', 12, 0, 100, 0, 0, 0, 119827, 'Valewalker Farodin to Player'),
(107126, @GROUP_ID+3, @ID+0, '[Relieved Sigh] ... Balance is restored. The Arcan''dor will not fail.', 12, 0, 100, 0, 0, 0, 119828, 'Valewalker Farodin to Player'),
(107126, @GROUP_ID+4, @ID+0, 'The arcan''dor is at a critical stage.', 12, 0, 100, 0, 0, 67313, 118611, 'Valewalker Farodin to Player'),
(107126, @GROUP_ID+5, @ID+0, 'Without enough power to mature into its final form, it will die.', 12, 0, 100, 0, 0, 67314, 118612, 'Valewalker Farodin to Player'),
(107126, @GROUP_ID+6, @ID+0, 'It is not enough...', 12, 0, 100, 0, 0, 67319, 118617, 'Valewalker Farodin to Player'),
(107253, @GROUP_ID+0, @ID+0, 'You''ll find Lorin in the square. Sylessa frequents the canals. Just search the bazaar for Cyrille. They''ll catch your eye.', 12, 0, 100, 0, 0, 66207, 117194, 'Arluin to Player'),
(107253, @GROUP_ID+1, @ID+0, 'Is that what she''s up to? Brave girl. I''d be delighted to help, but...', 12, 0, 100, 0, 0, 68043, 119243, 'Arluin to Player'),
(107253, @GROUP_ID+2, @ID+0, 'Always a pleasure. Do things my way and she''ll be advisor before dinner.', 12, 0, 100, 0, 0, 66192, 116295, 'Arluin to Player'),
(107253, @GROUP_ID+3, @ID+0, 'Arluin beckons you over.', 16, 0, 100, 0, 0, 0, 121788, 'Arluin to Player'),
(107253, @GROUP_ID+4, @ID+0, 'I... will go home. I have no business among such esteemed individuals.', 12, 0, 100, 1, 0, 66188, 116511, 'Arluin to Player'),
(107253, @GROUP_ID+5, @ID+0, 'I accept your gratitude, by the way!', 12, 0, 100, 603, 0, 66189, 116512, 'Arluin to Player'),
(107324, @GROUP_ID+0, @ID+0, 'Intruders!', 12, 0, 100, 0, 0, 0, 121052, 'Suramar Child'), -- BroadcastTextID: 1727 - 71536 - 73342 - 78530 - 82412 - 91233 - 121052
(107333, @GROUP_ID+0, @ID+0, 'Intruder! Face my blade!', 12, 0, 100, 0, 0, 69824, 115553, 'Overseer Durant'),
(107333, @GROUP_ID+1, @ID+0, 'She sealed her fate, as you have sealed yours!', 12, 0, 100, 0, 0, 69825, 115554, 'Overseer Durant'),
(107333, @GROUP_ID+2, @ID+0, 'You cannot defy me!', 12, 0, 100, 0, 0, 69827, 115597, 'Overseer Durant'),
(107333, @GROUP_ID+3, @ID+0, 'Elisande will have your heads for this!', 12, 0, 100, 0, 0, 69828, 115598, 'Overseer Durant'),
(107333, @GROUP_ID+4, @ID+0, 'T-traitors...', 12, 0, 100, 0, 0, 69829, 111870, 'Overseer Durant to Player'),
(107342, @GROUP_ID+0, @ID+0, 'You will bow to us!', 12, 0, 100, 0, 0, 65667, 116700, 'Duskwatch Spell-Fencer to Player'), -- BroadcastTextID: 116686 - 116700
(107348, @GROUP_ID+0, @ID+0, 'Understood.', 12, 0, 100, 0, 0, 0, 132592, 'Sylessa to Player'), -- BroadcastTextID: 18146 - 67718 - 132592
(107349, @GROUP_ID+0, @ID+0, 'Very well.', 12, 0, 100, 0, 0, 0, 114217, 'Lorin to Player'), -- BroadcastTextID: 18047 - 53933 - 53936 - 80374 - 82319 - 90890 - 103121 - 111532 - 111654 - 114217 - 128544
(107350, @GROUP_ID+0, @ID+0, 'Say no more.', 12, 0, 100, 0, 0, 0, 111644, 'Cyrille to Player'),
(107350, @GROUP_ID+1, @ID+0, 'Vengeance for Margaux!', 12, 0, 100, 0, 0, 69825, 115599, 'Cyrille to Overseer Durant'),
(107350, @GROUP_ID+2, @ID+0, 'I can see why Arluin put his faith in you. Give him our regards.', 12, 0, 100, 0, 0, 0, 111927, 'Cyrille to Player'),
(107350, @GROUP_ID+3, @ID+0, 'Cyrille places a Dusk Lily atop Overseer Durant''s corpse.', 16, 0, 100, 0, 0, 0, 120682, 'Cyrille to Player'),
(107435, @GROUP_ID+0, @ID+0, 'You insult my honor, $n. Who exactly are you?', 12, 0, 100, 463, 0, 0, 111881, 'Suspicious Noble to Player'),
(107435, @GROUP_ID+1, @ID+0, '$n, you think I would spy on my own? Maybe we should look closer at you instead!', 12, 0, 100, 463, 0, 0, 111882, 'Suspicious Noble to Player'),
(107435, @GROUP_ID+2, @ID+0, 'Now now, let''s not be hasty $n. Why don''t you follow me so we can talk about this in a more private setting...', 12, 0, 100, 463, 0, 0, 111875, 'Suspicious Noble to Player'),
(107435, @GROUP_ID+3, @ID+0, 'How dare you accuse me of such a thing, $n? Do you know who I am? I don''t recognize you at all...', 12, 0, 100, 463, 0, 0, 111874, 'Suspicious Noble to Player'),
(107435, @GROUP_ID+4, @ID+0, 'I don''t know how you found me out, but now it''s time to die!', 12, 0, 100, 11, 0, 0, 111886, 'Suspicious Noble to Player'),
(107598, @GROUP_ID+0, @ID+0, 'Of course. I agree that this whole business is... distasteful. Even still, the sort of influence you would have...', 12, 0, 100, 1, 0, 67586, 116280, 'Vanthir to Player'),
(107603, @GROUP_ID+0, @ID+0, 'I''m starving!', 12, 0, 100, 0, 0, 0, 114601, 'Shal''dorei Civilian to Vineyard Enforcer'), -- BroadcastTextID: 42353 - 114601
(107632, @GROUP_ID+0, @ID+0, 'There is a reason we live on the opposite side of the city, my friend.', 12, 0, 100, 274, 0, 67567, 116281, 'Ly''leth Lunastre to Player'),
(107632, @GROUP_ID+1, @ID+0, 'I could change much for our people... yes...', 12, 0, 100, 1, 0, 67568, 116282, 'Ly''leth Lunastre to Player'),
(107632, @GROUP_ID+2, @ID+0, 'Meet me within the Sanctum of Order. I must prepare for the ceremony.', 12, 0, 100, 1, 0, 68065, 119291, 'Ly''leth Lunastre to Player'),
(107632, @GROUP_ID+3, @ID+0, 'I humbly accept this appointment. It is an honor beyond words.', 12, 0, 100, 0, 0, 66267, 116515, 'Ly''leth Lunastre to Player'),
(107632, @GROUP_ID+4, @ID+0, 'My lord, you have lost your sense of decorum. It is already decided.', 12, 0, 100, 1, 0, 66265, 116519, 'Ly''leth Lunastre to Player'),
(107632, @GROUP_ID+5, @ID+0, 'Tal''ashar it is. I name my friend here as my champion.', 12, 0, 100, 25, 0, 68147, 119381, 'Ly''leth Lunastre to Player'),
(107632, @GROUP_ID+6, @ID+0, 'I am modifying your disguise to allow you to fight like one of us.', 15, 0, 100, 0, 0, 68150, 119388, 'Ly''leth Lunastre to Player'),
(107632, @GROUP_ID+7, @ID+0, 'Win me a title, won''t you?', 12, 0, 100, 1, 0, 68151, 119389, 'Ly''leth Lunastre to Player'),
(107632, @GROUP_ID+8, @ID+0, 'I wish this had not been necessary, but you have done well.', 12, 0, 100, 0, 0, 68152, 119395, 'Ly''leth Lunastre to Player'),
(107632, @GROUP_ID+9, @ID+0, 'I will send you back to the tavern when you are ready.', 12, 0, 100, 0, 0, 68153, 119396, 'Ly''leth Lunastre to Player'),
(108411, @GROUP_ID+0, @ID+0, 'They are waiting for you in the tavern.', 12, 0, 100, 0, 0, 67575, 116279, 'Silgryn to Player'),
(108871, @GROUP_ID+0, @ID+0, 'I shall dispose of you, lowborn!', 12, 0, 100, 0, 0, 66024, 116678, 'Vineyard Warden to Player'), -- BroadcastTextID: 116678 - 116692
(108871, @GROUP_ID+1, @ID+0, 'The shal''dorei are... chosen...', 12, 0, 100, 0, 0, 66014, 116624, 'Vineyard Warden to Player'), -- BroadcastTextID: 116624 - 116710
(108871, @GROUP_ID+2, @ID+0, 'The shal''dorei will rule!', 12, 0, 100, 0, 0, 65801, 116707, 'Vineyard Warden to Player'), -- BroadcastTextID: 100933 - 116707
(108875, @GROUP_ID+0, @ID+0, 'The Vineyards are open to special guests only. You must leave immediately.', 12, 0, 100, 0, 0, 0, 114600, 'Vineyard Enforcer'),
(108875, @GROUP_ID+1, @ID+0, 'You are not authorized to enter the Vineyard.', 12, 0, 100, 0, 0, 0, 114598, 'Vineyard Enforcer'),
(109048, @GROUP_ID+0, @ID+0, 'To me, servant!', 12, 0, 100, 0, 0, 65706, 114785, 'Arcane Engineer to Player'),
(109461, @GROUP_ID+0, @ID+0, 'My hand slipped! Forgive me!', 12, 0, 100, 430, 0, 0, 121692, 'Vineyard Porter to Player'),
(109461, @GROUP_ID+1, @ID+0, 'Flee! The Magistrix will kill us for failing her!', 12, 0, 100, 430, 0, 0, 115419, 'Vineyard Porter to Spellsinger Quiris'),
(109461, @GROUP_ID+2, @ID+0, 'Thank you.', 12, 0, 100, 0, 0, 0, 115479, 'Vineyard Porter to Spellsinger Quiris'), -- BroadcastTextID: 4590 - 13214 - 38169 - 64352 - 77983 - 98217 - 111252 - 111253 - 115479 - 115661 - 119221 - 119622 - 131567
(109461, @GROUP_ID+3, @ID+0, 'Take the arcwine. I am getting out of here.', 12, 0, 100, 1, 0, 0, 115481, 'Vineyard Porter to Spellsinger Quiris'),
(109509, @GROUP_ID+0, @ID+0, 'This shipment is worth more than you are! How dare you treat it so carelessly!', 12, 0, 100, 0, 0, 0, 121691, 'Spellsinger Quiris to Player'),
(109509, @GROUP_ID+1, @ID+0, 'You will pay for this delay!', 12, 0, 100, 0, 0, 0, 115487, 'Spellsinger Quiris to Player'),
(109509, @GROUP_ID+2, @ID+0, 'Elisande... will hear... of this...', 12, 0, 100, 0, 0, 0, 115488, 'Spellsinger Quiris to Player'),
(109670, @GROUP_ID+0, @ID+0, 'Show your identification. COMPLY.', 12, 0, 100, 0, 0, 0, 119796, 'Chronarch Defender to Player'),
(109670, @GROUP_ID+1, @ID+0, 'Scanning arcane essence...', 12, 0, 100, 0, 0, 65819, 119797, 'Chronarch Defender to Player'),
(109670, @GROUP_ID+2, @ID+0, 'Stand by for screening.', 12, 0, 100, 0, 0, 66004, 119794, 'Chronarch Defender to Player'),
(110354, @GROUP_ID+0, @ID+0, 'I will wrestle my title from your champion''s lifeless hands, Ly''leth!', 12, 0, 100, 0, 0, 66216, 116532, 'Coryn'),
(110354, @GROUP_ID+1, @ID+0, 'You cannot match me! I am your better!', 12, 0, 100, 0, 0, 66217, 116533, 'Coryn'),
(110354, @GROUP_ID+2, @ID+0, 'I will have what is owed me!', 12, 0, 100, 0, 0, 66220, 116534, 'Coryn'),
(110354, @GROUP_ID+3, @ID+0, 'I was... framed...', 12, 0, 100, 0, 0, 66221, 116535, 'Coryn to Enhanced Illusion'),
(110365, @GROUP_ID+0, @ID+0, 'A challenger? Don''t make me laugh!', 12, 0, 100, 0, 0, 66332, 116536, 'Ruven'),
(110365, @GROUP_ID+1, @ID+0, 'The Legion brings us power unending!', 12, 0, 100, 0, 0, 66333, 116537, 'Ruven'),
(110365, @GROUP_ID+2, @ID+0, 'I will not be defeated by the likes of you!', 12, 0, 100, 0, 0, 66335, 116539, 'Ruven'),
(110365, @GROUP_ID+3, @ID+0, 'They... promised...', 12, 0, 100, 0, 0, 66336, 116540, 'Ruven to Player'),
(110443, @GROUP_ID+0, @ID+0, 'Do you expect me to waste time chattering with vapid nobles even as my enemies close in? Look there, you fool! We are not alone.', 12, 0, 100, 0, 0, 67614, 117106, 'Elisande to Player'),
(110443, @GROUP_ID+1, @ID+0, 'Yet another failure, Melandrus. Consider this your chance to correct it. Dispose of these outsiders. I must return to the Nighthold.', 12, 0, 100, 0, 0, 67613, 117104, 'Elisande to Player'),
(110538, @GROUP_ID+0, @ID+0, 'We must learn why the old arcan''dor failed. Its shattered bones may have the answers.', 12, 0, 100, 0, 0, 66383, 118555, 'Valewalker Farodin to Player'),
(110654, @GROUP_ID+0, @ID+0, 'Run!', 12, 0, 100, 0, 0, 66336, 118743, 'Frightened Laborer to Player'), -- BroadcastTextID: 7324 - 47820 - 53325 - 81264 - 84722 - 84840 - 118743
(110655, @GROUP_ID+0, @ID+0, 'Get moving!', 12, 0, 100, 0, 0, 0, 118738, 'Duskmere Smuggler to Player'), -- BroadcastTextID: 111945 - 118738
(110656, @GROUP_ID+0, @ID+0, 'You will not interfere with my research!', 12, 0, 100, 0, 0, 0, 118752, 'Arcanist Lylandre to Lylandre''s Fire Crystal'),
(110679, @GROUP_ID+0, @ID+0, 'You are not leaving my sight until an advisor is appointed. Promise me!', 12, 0, 100, 0, 0, 0, 119494, 'Aurore to Player'),
(110679, @GROUP_ID+1, @ID+0, 'Thank you. Do let Ly''leth know that I stand with her.', 12, 0, 100, 0, 0, 65866, 119496, 'Aurore to Player'),
(110680, @GROUP_ID+0, @ID+0, 'I think they meant to kill me!', 12, 0, 100, 603, 0, 0, 118819, 'Ailen Astravar to Player'),
(110680, @GROUP_ID+1, @ID+0, 'I am getting off this infernal ship! I will return to my mother at once.', 12, 0, 100, 603, 0, 0, 119490, 'Ailen Astravar to Player'),
(110804, @GROUP_ID+0, @ID+0, 'Yes, mother.', 12, 0, 100, 0, 0, 0, 119495, 'Ailen to Player'), -- BroadcastTextID: 49448 - 119495
(110874, @GROUP_ID+0, @ID+0, 'That is the symbol of House Stelleris... but that could not be. Coryn was Ruven''s dearest friend...', 12, 0, 100, 1, 0, 0, 119179, 'Distraught Noble to Player'),
(110874, @GROUP_ID+1, @ID+0, 'No, that''s simply impossible...', 12, 0, 100, 274, 0, 0, 119180, 'Distraught Noble to Player'),
(110875, @GROUP_ID+0, @ID+0, 'Preposterous! A joke at my lord''s expense? Only a madman would attempt it!', 12, 0, 100, 5, 0, 0, 119181, 'Shamed Noble to Player'),
(110875, @GROUP_ID+1, @ID+0, '... But if anyone would laugh, it would be THEM.', 12, 0, 100, 1, 0, 0, 119182, 'Shamed Noble to Player'),
(110876, @GROUP_ID+0, @ID+0, 'Absolutely NOT! Why would he do such a thing? Has he no honor?!', 12, 0, 100, 5, 0, 0, 119177, 'Disgruntled Servant to Player'),
(110876, @GROUP_ID+1, @ID+0, '... Why WOULD he do such a thing...?', 12, 0, 100, 1, 0, 0, 119178, 'Disgruntled Servant to Player'),
(110958, @GROUP_ID+0, @ID+0, 'This wine is terrible. I''ll wager Melandrus watered it down.', 12, 0, 100, 1, 0, 0, 118921, 'Fancy Noble'),
(110958, @GROUP_ID+1, @ID+0, 'I saw Spellblade Aluriel pacing about. She always seems so... angry.', 12, 0, 100, 1, 0, 0, 118920, 'Fancy Noble'),
(110967, @GROUP_ID+0, @ID+0, 'Filthy backstabbing cretin! That title should have been mine!', 12, 0, 100, 603, 0, 66003, 116517, 'Coryn to Player'),
(110967, @GROUP_ID+1, @ID+0, 'You impinge upon my honor! You besmirch my name with baseless accusations!', 12, 0, 100, 603, 0, 66214, 116518, 'Coryn to Player'),
(110967, @GROUP_ID+2, @ID+0, 'I will reclaim my honor! I invoke the ancient rite- Tal''ashar!', 12, 0, 100, 603, 0, 66219, 116524, 'Coryn to Player'),
(110967, @GROUP_ID+3, @ID+0, 'I have no need to hide behind a champion. I will defend my own honor.', 12, 0, 100, 1, 0, 68148, 119382, 'Coryn to Player'),
(110967, @GROUP_ID+4, @ID+0, 'Meet me atop the Sanctum when you are ready to die, whelp.', 12, 0, 100, 603, 0, 68149, 119383, 'Coryn to Player'),
(111484, @GROUP_ID+0, @ID+0, 'Now is the age of the shal''dorei!', 12, 0, 100, 0, 0, 65707, 116677, 'Duskwatch Spellshield to Hungering Withered'), -- BroadcastTextID: 116677 - 116691
(111485, @GROUP_ID+0, @ID+0, 'Lowborn scum!', 12, 0, 100, 0, 0, 65907, 116685, 'Duskwatch Spellshield to Player'), -- BroadcastTextID: 116685 - 116699
(111485, @GROUP_ID+1, @ID+0, 'Anath''ashar!', 12, 0, 100, 0, 0, 65910, 116688, 'Duskwatch Spellshield to Player'), -- BroadcastTextID: 100935 - 116681 - 116688 - 116695 - 116702 - 116709
(111485, @GROUP_ID+2, @ID+0, 'Die, outlander!', 12, 0, 100, 0, 0, 65909, 116708, 'Duskwatch Spellshield to Player'), -- BroadcastTextID: 6226 - 100934 - 116708
(111485, @GROUP_ID+3, @ID+0, 'Feel the might of the shal''dorei!', 12, 0, 100, 6, 0, 65663, 116676, 'Duskwatch Spellshield to Player'), -- BroadcastTextID: 116676 - 116690
(111489, @GROUP_ID+0, @ID+0, 'Your death is fated!', 12, 0, 100, 273, 0, 65864, 116703, 'Loyalist Sycophant to Hungering Withered'), -- BroadcastTextID: 100929 - 116703
(111489, @GROUP_ID+1, @ID+0, 'Your star is fading!', 12, 0, 100, 0, 0, 65866, 116684, 'Loyalist Sycophant to Hungering Withered'), -- BroadcastTextID: 116684 - 116698
(111489, @GROUP_ID+2, @ID+0, 'We have... failed.', 12, 0, 100, 0, 0, 65859, 116789, 'Loyalist Sycophant to Player'), -- BroadcastTextID: 116758 - 116789
(111490, @GROUP_ID+0, @ID+0, 'Tremble before our strength!', 12, 0, 100, 273, 0, 65664, 116683, 'Loyalist Sycophant to Player'), -- BroadcastTextID: 116683 - 116697
(111621, @GROUP_ID+0, @ID+0, 'Our magic will break you!', 12, 0, 100, 0, 0, 66022, 116704, 'Duskwatch Executor to Player'), -- BroadcastTextID: 100930 - 116704
(111621, @GROUP_ID+1, @ID+0, 'No! It is not my time....', 12, 0, 100, 0, 0, 66015, 116768, 'Duskwatch Executor to Player'), -- BroadcastTextID: 116768 - 116778
(111903, @GROUP_ID+0, @ID+0, 'The Lunastre Attendant nods to you and calmly exits the tavern.', 16, 0, 100, 0, 0, 0, 121185, 'Lunastre Attendant to Player'),
(114263, @GROUP_ID+0, @ID+0, 'Well done... so far! But I will judge for myself whether you are worthy!', 14, 0, 100, 0, 0, 77575, 123103, 'Odyn to Hymdall'),
(114263, @GROUP_ID+1, @ID+0, 'It seems I have been too gentle. Have at thee!', 14, 0, 100, 0, 0, 77574, 123102, 'Odyn'),
(114263, @GROUP_ID+2, @ID+0, 'A shocking weakness!', 14, 0, 100, 0, 0, 77587, 123669, 'Odyn'),
(114263, @GROUP_ID+3, @ID+0, '|TInterface\\Icons\\INV_Polearm_2H_OdynSpear_D_01.blp:20|t Odyn targets you with a |cFFFF0404|Hspell:228918|h[Stormforged Spear]|h|r!', 42, 0, 100, 0, 0, 0, 123528, 'Odyn to Player'),
(114263, @GROUP_ID+4, @ID+0, 'Feel the fury of the storm!', 14, 0, 100, 0, 0, 77586, 123668, 'Odyn'),
(114263, @GROUP_ID+5, @ID+0, 'ENOUGH! Your worth is proven! With you as my champions, Helya will fall and I will at long last be free of the curse that binds me here.', 14, 0, 100, 0, 0, 77579, 123114, 'Odyn'),
(114323, @GROUP_ID+0, @ID+0, '|TInterface\\Icons\\SPELL_FIRE_TWILIGHTFLAMEBREATH.BLP:20|t%s begins to cast |cFFFF0000|Hspell:227573|h[Guardian''s Breath]|h|r!', 41, 0, 100, 0, 0, 0, 124841, 'Guarm to Player'),
(114360, @GROUP_ID+0, @ID+0, 'Fall in line!', 14, 0, 100, 0, 0, 77598, 123659, 'Hyrja to Player'),
(114360, @GROUP_ID+1, @ID+0, '|TInterface\\Icons\\ABILITY_PRIEST_FLASHOFLIGHT.BLP:20|t Hyrja targets |cFFFF0000$n|r with |cFFFF0404|Hspell:228162|h[Shield of Light]|h|r!', 41, 0, 100, 0, 0, 77598, 124555, 'Hyrja to Player'),
(114361, @GROUP_ID+0, @ID+0, '|TInterface\\Icons\\INV_Misc_Horn_03:20|t Hymdall begins to blow the |cFFFF0404|Hspell:228012|h[Horn of Valor]|h|r!', 41, 0, 100, 0, 0, 77592, 123522, 'Hymdall'),
(114361, @GROUP_ID+1, @ID+0, 'Only cowards fear the call of battle!', 14, 0, 100, 0, 0, 77592, 123661, 'Hymdall'),
(114474, @GROUP_ID+0, @ID+0, 'No mercy for outlanders!', 12, 0, 100, 0, 0, 65710, 116680, 'Duskwatch Highblade to Player'), -- BroadcastTextID: 116680 - 116694
(114537, @GROUP_ID+0, @ID+0, 'Oh no... Odyn''s mighty champions have come to end my reign. Whatever shall I do?', 14, 0, 100, 0, 0, 77477, 123584, 'Helya to Player'),
(114537, @GROUP_ID+1, @ID+0, 'So kind of you to deliver your souls to me... it will save my Val''kyr the trouble of fetching them from the surface world.', 14, 0, 100, 0, 0, 77478, 123585, 'Helya to Player'),
(114537, @GROUP_ID+2, @ID+0, 'Come, mortals. You have earned an eternity of torment!', 14, 0, 100, 0, 0, 77479, 123586, 'Helya to Deepbrine Monstrosity'),
(114537, @GROUP_ID+3, @ID+0, 'Your souls belong to me!', 14, 0, 100, 0, 0, 77480, 123587, 'Helya to Player'),
(114537, @GROUP_ID+4, @ID+0, 'Relish the cold kiss of the sea!', 14, 0, 100, 0, 0, 77492, 123605, 'Helya to Player'),
(114537, @GROUP_ID+5, @ID+0, 'Darkness upon your soul!', 14, 0, 100, 0, 0, 77490, 123603, 'Helya'),
(114537, @GROUP_ID+6, @ID+0, 'Soon you will join the ranks of my Kvaldir!', 14, 0, 100, 0, 0, 77495, 123608, 'Helya to Helya'),
(114537, @GROUP_ID+7, @ID+0, 'Your doom lurks within the fog!', 14, 0, 100, 0, 0, 77498, 123611, 'Helya to Helya'),
(114537, @GROUP_ID+8, @ID+0, 'Your efforts are for naught, mortals! Odyn will NEVER be free!', 14, 0, 100, 0, 0, 77496, 123609, 'Helya to Helya'),
(114537, @GROUP_ID+9, @ID+0, 'You''ll catch your death of cold!', 14, 0, 100, 0, 0, 77500, 123613, 'Helya'),
(114537, @GROUP_ID+10, @ID+0, 'Breathe deep... and despair!', 14, 0, 100, 0, 0, 77501, 123614, 'Helya'),
(114537, @GROUP_ID+11, @ID+0, 'He... must not... win...', 14, 0, 100, 0, 0, 77488, 123601, 'Helya to Player'),
(114876, @GROUP_ID+0, @ID+0, 'Stay inside if you want to live!', 12, 0, 100, 0, 0, 0, 124633, 'Vengeful Wrathguard'),
(115166, @GROUP_ID+0, @ID+0, '|TInterface\\Icons\\INV_Icon_ShadowCouncilOrb_purple.blp:20|t An |cFFFF0000|Hspell:227920|h[Orb of Corruption]|h|r is following you!', 42, 0, 100, 0, 0, 0, 123580, 'Orb of Corruption to Player');

UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115277; -- Nightborne Rebel Arcanist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=119064; -- Guerrier chanteguerre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111958; -- Survey Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111053; -- THUNDER BUNNY
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=2925; -- Silvermane Howler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107028; -- Arcane Circle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109469; -- Great Eagle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97532; -- Violetta
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=59037; -- Kung Din
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=40064; -- Jungle Panther
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=51663; -- Pogeyan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106478; -- Taerar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106477; -- Lethon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106475; -- Emeriss
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106474; -- Ysondre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106544; -- Glade Sprite
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106543; -- Thaon Moonclaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106540; -- Elothir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106539; -- Elerethe Renferal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106531; -- Glade Sprite
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106463; -- Ursoc
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106088; -- Cenarius
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106008; -- Verdant Ancient
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105996; -- Emerald Dryad
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106385; -- Ysera
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106381; -- Dreambound Druid
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106380; -- Dreambound Druid
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106379; -- Dreambound Druid
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106015; -- Dreambound Druid
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106010; -- Dreamwisp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97206; -- Jeune dragonnet du Rêve
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111298; -- Purified Life Essence
UPDATE `creature_template` SET `HealthModifier`=6.75422, `VerifiedBuild`=25996 WHERE `entry`=104592; -- Nightmare Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104422; -- Nightmare Blades
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110732; -- Creature of Madness
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103694; -- Lurking Terror
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15631; -- Spotlight
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104096; -- Sleeping Version
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105245; -- Dream of Ysera
UPDATE `creature_template` SET `HealthScalingExpansion`=2, `VerifiedBuild`=25996 WHERE `entry`=63508; -- Xuen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98463; -- Broute
UPDATE `creature_template` SET `HealthModifier`=12, `VerifiedBuild`=25996 WHERE `entry`=111405; -- Shadow Pounder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97930; -- Bloodstalker
UPDATE `creature_template` SET `HealthModifier`=30, `VerifiedBuild`=25996 WHERE `entry`=111398; -- Amalgame du Cauchemar
UPDATE `creature_template` SET `HealthModifier`=6, `VerifiedBuild`=25996 WHERE `entry`=111413; -- Dark Devourers
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=43499; -- Consecration
UPDATE `creature_template` SET `HealthModifier`=40, `VerifiedBuild`=25996 WHERE `entry`=111370; -- Creature in the Shadows
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105343; -- Dread Abomination
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111350; -- Skittering Shadows
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104548; -- Arena Bounds
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109847; -- Rift of Aln
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=126111; -- Progéniture de Ven'orn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97979; -- Vethir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92307; -- God-King Skovald
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97986; -- Vethir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110976; -- Chosen Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110973; -- Worthy Vrykul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116760; -- Odyn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114535; -- Orb of Corrosion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114566; -- Orb of Corrosion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=53006; -- Spirit Link Totem
UPDATE `creature_template` SET `rank`=1, `HealthModifier`=4, `VerifiedBuild`=25996 WHERE `entry`=114568; -- Decaying Minion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114812; -- Night Watch Mariner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100733; -- Charge
UPDATE `creature_template` SET `type_flags`=270532680, `HealthModifier`=23.8, `VerifiedBuild`=25996 WHERE `entry`=114709; -- Grimelord
UPDATE `creature_template` SET `HealthModifier`=13.5, `VerifiedBuild`=25996 WHERE `entry`=114809; -- Night Watch Mariner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115941; -- Kvaldir Longboat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114905; -- Gripping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114901; -- Gripping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114900; -- Gripping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116214; -- Orb of Corruption
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115166; -- Orb of Corruption
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114523; -- Orb of Corruption
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114553; -- Bilewater Slime
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114923; -- Shatterbone Skeleton
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=100943; -- Earthen Shield Totem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114811; -- Kvaldir Coral Maiden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114813; -- Kvaldir Tide Witch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114932; -- Deepbrine Monstrosity
UPDATE `creature_template` SET `HealthModifier`=747, `VerifiedBuild`=25996 WHERE `entry`=114537; -- Helya
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=117783; -- Gripping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=117784; -- Gripping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114344; -- Guarm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114343; -- Guarm
UPDATE `creature_template` SET `HealthModifier`=495, `VerifiedBuild`=25996 WHERE `entry`=114323; -- Guarm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114341; -- Guarm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114922; -- Dark Seraph
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114639; -- Kvaldir Reefcaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114614; -- Kvaldir Spiritrender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114539; -- Kvaldir Reefcaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114546; -- Risen Bonethrall
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114548; -- Rotsoul Giant
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=114672; -- Brazier Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114534; -- Helhound
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109795; -- Os négligés
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93094; -- Ancêtre sans repos
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114547; -- Ancient Bonethrall
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114538; -- Kvaldir Spiritrender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114532; -- Bonespeaker Soulbinder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116122; -- Sky Jump
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116242; -- Aspiring Champion of the Chosen Dead
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116241; -- Champion of the Chosen Dead
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116245; -- Heroic Champion of the Chosen Dead
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116229; -- Mythical Champion of the Chosen Dead
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114485; -- Raging Tempest
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=59764; -- Healing Tide Totem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114467; -- Spear of Light
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type`=11, `VerifiedBuild`=25996 WHERE `entry`=78001; -- Cloudburst Totem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114560; -- Dancing Blade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=95061; -- Greater Fire Elemental
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108452; -- Infernal
UPDATE `creature_template` SET `modelid1`=72978, `HealthScalingExpansion`=4, `family`=108, `type`=3, `type_flags2`=1, `VerifiedBuild`=25996 WHERE `entry`=89; -- Infernal
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `type_flags`=16777216, `VerifiedBuild`=25996 WHERE `entry`=69791; -- Fire Spirit
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `type_flags`=16778240, `HealthModifier`=0.3, `VerifiedBuild`=25996 WHERE `entry`=69792; -- Earth Spirit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99625; -- Wind Spirit
UPDATE `creature_template` SET `HealthModifier`=140, `VerifiedBuild`=25996 WHERE `entry`=114360; -- Hyrja
UPDATE `creature_template` SET `HealthModifier`=140, `VerifiedBuild`=25996 WHERE `entry`=114361; -- Hymdall
UPDATE `creature_template` SET `HealthModifier`=450, `VerifiedBuild`=25996 WHERE `entry`=114263; -- Odyn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114785; -- Valarjar Marksman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114791; -- Chosen of Eyir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114786; -- Valarjar Mystic
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114789; -- Stormforged Sentinel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114787; -- Valarjar Runecarver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114784; -- Valarjar Champion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114788; -- Mande-tonnerre valarjar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111912; -- Ashtongue Warrior
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99526; -- Rejeton de ligne tellurique
UPDATE `creature_template` SET `HealthModifier`=570.356, `VerifiedBuild`=25996 WHERE `entry`=103769; -- Xavius
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=63600; -- Stonebound Watcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110538; -- Valewalker Farodin
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=32791; -- Lapin du printemps
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110908; -- Spellblade Aluriel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110946; -- Haughty Aristocrat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106113; -- Lifesized Nightborne Statue
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106018; -- Bazaar Goods
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108422; -- Automated Sweeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108421; -- Mana Kitten
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105160; -- Fel Orb
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107073; -- Duskwatch Reinforcement
UPDATE `creature_template` SET `type_flags`=2147483649, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=3475; -- Echeyakee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106415; -- Valarjar forge-foudre
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=42720; -- Young Tallstrider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=38453; -- Arcturis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=119969; -- Ancient Skyfin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=1114; -- Jungle Thunderer
UPDATE `creature_template` SET `movementId`=961, `VerifiedBuild`=25996 WHERE `entry`=106550; -- Hati
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=2408; -- Snapjaw
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62189; -- Tamia alpin
UPDATE `creature_template` SET `type_flags2`=128, `VerifiedBuild`=25996 WHERE `entry`=103130; -- Timeless Wraith
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102849; -- Chrono Shard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103109; -- Chrono Shard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98208; -- Conseiller Vandros
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100393; -- Dread Felbat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100342; -- Fissure
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98776; -- Felswarm Imp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106754; -- Portal: Argus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106757; -- Eye of the Beast
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99628; -- Suppression Protocol
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=62982; -- Mindbender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106546; -- Astral Spark
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98734; -- Night Crystal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98435; -- Unstable Oozeling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105845; -- Glowing Spiderling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98426; -- Unstable Ooze
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99446; -- Pipe Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98205; -- Corstilax
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98203; -- Ivanyr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98207; -- Nal’tira
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110833; -- Infernal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105876; -- Enchanted Broodling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98759; -- Vicious Manafang
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98206; -- Général Xakal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105915; -- Nightborne Reclaimer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105921; -- Nightborne Spellsword
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106059; -- Warp Shade
UPDATE `creature_template` SET `modelid1`=19285, `VerifiedBuild`=25996 WHERE `entry`=105848; -- Wyrm Corpse
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105651; -- Dreadborne Seer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106013; -- Unstable Amalgamation Corpse
UPDATE `creature_template` SET `modelid1`=19285, `VerifiedBuild`=25996 WHERE `entry`=102351; -- Mana Wyrm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98756; -- Arcane Anomaly
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105706; -- Priestess of Misery
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105682; -- Felguard Destroyer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102541; -- Withered Corpse
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105952; -- Ame en peine de mana flétrie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98772; -- Dread Felbat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105629; -- Wyrmtongue Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105617; -- Eredar Chaosbringer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98770; -- Wrathguard Felblade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98732; -- Plagued Rat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98733; -- Withered Fiend
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98728; -- Acidic Bile
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98425; -- Unstable Amalgamation
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105493; -- Withered Corpse
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `HealthModifier`=10, `VerifiedBuild`=25996 WHERE `entry`=121415; -- Assassin sans-couronne
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111918; -- Almon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111903; -- Lunastre Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110681; -- Enhanced Illusion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110965; -- Elisande
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110967; -- Coryn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110736; -- Haughty Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106152; -- Bébé noble-bois
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=76597; -- Frost Wolf Alpha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=31216; -- Mirror Image
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=58456; -- Thundermaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115901; -- Infiltrateur shal’dorei
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116118; -- Felborne Magus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110804; -- Ailen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98167; -- Void Tendril
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=25996 WHERE `entry`=68655; -- M. Bigglesworth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100820; -- Spirit Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110876; -- Disgruntled Servant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112870; -- Stelleris Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110734; -- Stelleris Thug
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=91250; -- Iron Warwolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110875; -- Shamed Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110874; -- Distraught Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110680; -- Ailen Astravar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115338; -- Rebellious Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=119060; -- Apprenti de la Tirisgarde
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100496; -- Silvered Streaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93319; -- Ashmaw Cub
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93318; -- Ashmaw Mauler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93481; -- Wisp
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105882; -- Sylendra Gladesong
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105903; -- Broll Bearmantle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105897; -- Pilleur sombrefiel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105920; -- Darkfiend Raider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=59113; -- Generic Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=95720; -- Druid of the Antler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=95719; -- Druid of the Antler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=91462; -- Malfurion Stormrage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113394; -- Phil Greenoak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93512; -- Azalea
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109738; -- Fleuris Asterleaf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93750; -- Fey Darter
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `type_flags`=6144, `HealthModifier`=2, `movementId`=875, `VerifiedBuild`=25996 WHERE `entry`=120600; -- Druid of the Talon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93460; -- Feonir Cloudthistle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93316; -- Gleamhoof Fawn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101435; -- Nymia Shadesong
UPDATE `creature_template` SET `modelid3`=62734, `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62178; -- Lapin elfique
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107635; -- Keeper of the Grove
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=63607; -- Squirrel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=94179; -- Aranelle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113937; -- Invisible Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99114; -- Lorlathil Druid
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93464; -- Callista Swiftglaive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99555; -- Moonfeather Statue
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=93469; -- Majestic Gladewatcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98135; -- Wildcrafter Osme
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93462; -- Lorlathil Sentry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93508; -- Lorlathil Druid
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109818; -- Gleamhoof Fawn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108675; -- Mooncrazed Owlbeast
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108712; -- Shriektalon Totem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108364; -- Goop Jelly
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108362; -- Blood Drip
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108641; -- Boneflux
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109306; -- Myria Glenbrook
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=4485; -- Belgrom Rockmaul
UPDATE `creature_template` SET `modelid1`=48578, `HealthScalingExpansion`=0, `type_flags2`=8192, `VerifiedBuild`=25996 WHERE `entry`=32666; -- Training Dummy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=14539; -- Swift Timber Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47808; -- Black Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=4752; -- Kildar
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=25996 WHERE `entry`=57922; -- Taryssa Lazuria
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=114840; -- PvP Training Dummy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47818; -- Tusker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47817; -- Scuttler
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=47815; -- Grimfang
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47809; -- Brown Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47788; -- Guldor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47771; -- Drukma
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47767; -- Korla
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47764; -- Murog
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=31757; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=12353; -- Timber Riding Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=5195; -- Brown Riding Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3352; -- Ormak Grimshot
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3357; -- Makaru
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=31769; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=31758; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=31756; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=31755; -- Stabled Hunter Pet
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `movementId`=140, `VerifiedBuild`=25996 WHERE `entry`=65065; -- Red Dragon Turtle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=31768; -- Stabled Hunter Pet
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=46638; -- Auctioneer Vizput
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=46640; -- Auctioneer Kuvi
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=42721; -- Young Raptor
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=46637; -- Auctioneer Drezbit
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=46639; -- Auctioneer Zilbeena
UPDATE `creature_template` SET `modelid1`=46093, `HealthScalingExpansion`=4, `HealthModifier`=1, `VerifiedBuild`=25996 WHERE `entry`=2756; -- Chao-Ju
UPDATE `creature_template` SET `modelid1`=45319, `HealthScalingExpansion`=4, `VerifiedBuild`=25996 WHERE `entry`=16869; -- Jising
UPDATE `creature_template` SET `modelid1`=45320, `HealthScalingExpansion`=4, `VerifiedBuild`=25996 WHERE `entry`=5029; -- Jiming
UPDATE `creature_template` SET `modelid1`=45170, `HealthScalingExpansion`=4, `VerifiedBuild`=25996 WHERE `entry`=16868; -- Winsum
UPDATE `creature_template` SET `modelid1`=43669, `HealthScalingExpansion`=4, `VerifiedBuild`=25996 WHERE `entry`=5034; -- Winwa
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `movementId`=140, `VerifiedBuild`=25996 WHERE `entry`=65060; -- Blue Dragon Turtle
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `movementId`=140, `VerifiedBuild`=25996 WHERE `entry`=65058; -- Black Dragon Turtle
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `movementId`=140, `VerifiedBuild`=25996 WHERE `entry`=65074; -- Great Blue Dragon Turtle
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `movementId`=140, `VerifiedBuild`=25996 WHERE `entry`=65061; -- Brown Dragon Turtle
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `movementId`=140, `VerifiedBuild`=25996 WHERE `entry`=65063; -- Purple Dragon Turtle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=42638; -- Herezegor Flametusk
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `movementId`=140, `VerifiedBuild`=25996 WHERE `entry`=65071; -- Great Green Dragon Turtle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=70301; -- Softpaws
UPDATE `creature_template` SET `HealthModifier`=1, `VerifiedBuild`=25996 WHERE `entry`=62445; -- Ji Firepaw
UPDATE `creature_template` SET `HealthModifier`=1, `VerifiedBuild`=25996 WHERE `entry`=66022; -- Turtlemaster Odai
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=25996 WHERE `entry`=65008; -- Huojin Monk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=69333; -- Disciple Jusi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=68869; -- Luo Luo
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `movementId`=140, `VerifiedBuild`=25996 WHERE `entry`=65076; -- Great Brown Dragon Turtle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=66437; -- Arcanist Xu
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=15186; -- Bourbie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=7951; -- Zas'Tysh
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=46642; -- Innkeeper Nufa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=43239; -- Razgar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3333; -- Shankys
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3332; -- Lumak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19175; -- Orc Commoner
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=16069; -- Gloubie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16076; -- Tharl Stonebleeder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=46618; -- Fibi
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=47663; -- Scout Obrok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=46619; -- Binzella
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=46620; -- Vink
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=46622; -- Vuvanzi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=46621; -- Pank
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=25996 WHERE `entry`=62193; -- Rok'kal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=49750; -- Warchief's Herald
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3359; -- Kiro
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3364; -- Borya
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=2855; -- Snang
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3317; -- Ollanus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=4953; -- Water Snake
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=72559; -- Thunder Bluff Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=14498; -- Tosamina
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=14499; -- Horde Orphan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=14451; -- Orphan Matron Battlewail
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3225; -- Corrupted Mottled Boar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=5811; -- Kamari
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=7088; -- Thuwd
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3365; -- Karolek
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3321; -- Morgum
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3316; -- Handor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3366; -- Tamar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=95057; -- Illidari Darkdealer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114104; -- Adept Yad M'Sivart
UPDATE `creature_template` SET `type_flags2`=8192, `VerifiedBuild`=25996 WHERE `entry`=46647; -- Training Dummy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23635; -- Krixx
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `type_flags`=524292, `type_flags2`=8192, `HealthModifier`=1400, `VerifiedBuild`=25996 WHERE `entry`=31146; -- Raider's Training Dummy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=2857; -- Thund
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=11017; -- Roxxik
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3413; -- Sovik
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=52032; -- Sinzi Sparkscribe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3412; -- Nogg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3367; -- Felika
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=46718; -- Moraka
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=46716; -- Nerog
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=25996 WHERE `entry`=62196; -- Flekky Nox
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=25996 WHERE `entry`=62197; -- Zazzle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=7010; -- Zilzibin Drumlore
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3371; -- Tamaro
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3372; -- Sarlek
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=6987; -- Malton Droffers
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=6986; -- Dran Droffers
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=10880; -- Warcaller Gorlach
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3351; -- Magenius
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3350; -- Asoran
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=12136; -- Snurk Bucksquick
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=51230; -- Earthmender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3348; -- Kor'geld
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=46742; -- Brunda
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=11046; -- Whuut
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3347; -- Yelmak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=8659; -- Jes'rimon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=46741; -- Muraga
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3345; -- Godan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3346; -- Kithas
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=11066; -- Jhag
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=46181; -- Enchanter Farendin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47336; -- Baradin Grunt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47321; -- Zugra Flamefist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47335; -- Baradin Grunt
UPDATE `creature_template` SET `family`=0, `type_flags`=0, `VerifiedBuild`=25996 WHERE `entry`=54113; -- Spooks
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=54004; -- Jaga
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=50088; -- Waters of Farseeing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=58199; -- Lord Itharius
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=58193; -- Wyrmrest Protector
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44780; -- Isashi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44779; -- Owato
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=72939; -- Terga Earthbreaker
UPDATE `creature_template` SET `modelid1`=18269, `modelid2`=32937, `modelid3`=32936, `modelid4`=32938, `HealthScalingExpansion`=2, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=42548; -- Muddy Crawfish
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44770; -- Tatepi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3403; -- Sian'tsu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=5892; -- Searn Firewarder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=13417; -- Sagorne Creststrider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44785; -- Miwana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=1420; -- Toad
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61367; -- Serpent d'eau
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=88805; -- Grommie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44788; -- Lonto
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19176; -- Tauren Commoner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44782; -- Rento
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=44745; -- Sunwalker Atohmo's Kodo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44783; -- Hiwahi Three-Feathers
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=44787; -- Auctioneer Sowata
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=89713; -- Koak Hoburn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3322; -- Kaja
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44781; -- Opuno Ironhorn
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=44726; -- Shalla Whiteleaf
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=25996 WHERE `entry`=15188; -- Cenarion Emissary Blackhoof
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=44740; -- Sahi Cloudsinger
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=44743; -- Nohi Plainswalker
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=44723; -- Nahu Ragehoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=58155; -- Rugok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=52034; -- Togar
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=74228; -- Darkspear Headhunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=46140; -- Silvermoon Delegation Guardian
UPDATE `creature_template` SET `HealthScalingExpansion`=2, `VerifiedBuild`=25996 WHERE `entry`=29143; -- Bebri Coifcurl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47571; -- Belloc Brightblade
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=88543; -- Orgrimmar Mage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=5910; -- Zankaja
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=35068; -- Gotura Fourwinds
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62115; -- Bousier
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=14377; -- Scout Tharr
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=34765; -- Zelli Hotnozzle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=32520; -- Totally Generic Bunny (All Phase)
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=28960; -- Lapin à tout faire (JSB)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=9564; -- Frezza
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=26537; -- Greeb Ramrocket
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93223; -- Generic Stalker
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `HealthModifier`=1.5, `VerifiedBuild`=25996 WHERE `entry`=51346; -- Coursier du vent d’Orgrimmar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109912; -- Captive Wyrmtongue
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113395; -- Illidari Enforcer
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=63626; -- Varzok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=14881; -- Spider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93447; -- Elyssia Winterdusk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15579; -- Elder Darkhorn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44160; -- Suspicious Peon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=38821; -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=25996 WHERE `entry`=62114; -- Lézard épineux
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=50488; -- Stone Guard Nargol
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47897; -- Lunar Festival Vendor
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=50477; -- Champion Uru'zin
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=50323; -- Frizzo Villamar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=49131; -- Goblin Hot Rod
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `type_flags`=76, `HealthModifier`=1200, `RacialLeader`=1, `movementId`=151, `VerifiedBuild`=25996 WHERE `entry`=14720; -- High Overlord Saurfang
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=3310; -- Doras
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=49743; -- Dung Beetle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44919; -- Maztha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44918; -- Drakma
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44948; -- Wind Rider Cub
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=44158; -- Orgrimmar Skyway Peon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19177; -- Troll Commoner
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=45230; -- Orgrimmar Brave
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=44725; -- Sunwalker Atohmo
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=44735; -- Seer Liwatha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=62198; -- Omakka Wolfbrother
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=25996 WHERE `entry`=49837; -- Spiny Lizard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3334; -- Rekkul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=5875; -- Mordak Darkfist
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=88705; -- Kranosh
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=88704; -- Gran'dul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3335; -- Hagrus
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=89175; -- Dysong
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=88706; -- Murgul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47254; -- Gizput
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3328; -- Ormok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=5909; -- Cazul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3189; -- Kor'ghan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3327; -- Gest
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3330; -- Muragus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=5816; -- Katis
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=47233; -- Gordul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92553; -- Kirin Tor Summoner
UPDATE `creature_template` SET `modelid1`=61028, `VerifiedBuild`=25996 WHERE `entry`=3216; -- Arnak Fireblade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3331; -- Kareth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=3329; -- Kor'jus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=5639; -- Craven Drok
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=47246; -- Ureda
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=3296; -- Orgrimmar Grunt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47247; -- Marud
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47248; -- Gija
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=47253; -- Rundok
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96708; -- Chevalier de sang
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96698; -- Chevalier de sang
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=58237; -- Tweek
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97493; -- Narestel Pâlétoile
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106283; -- Jeune corgi
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61703; -- Minuscule tornade
UPDATE `creature_template` SET `type_flags`=2147483649, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=6585; -- Uhk'loc
UPDATE `creature_template` SET `HealthModifier`=3, `VerifiedBuild`=25996 WHERE `entry`=4512; -- Rotting Agam'ar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113485; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115755; -- Scathing Felbeast
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110694; -- Lylandre's Fel Crystal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110652; -- Lylandre's Fire Crystal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110656; -- Arcanist Lylandre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108190; -- Magisterial Sleuth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110651; -- Lylandre's Frost Crystal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110649; -- Lylandre's Arcane Crystal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109202; -- Vintner Iltheux
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109313; -- Night Lily Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109312; -- Purified Water Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109310; -- Shadefruit Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109305; -- Arcwine Event Missile Target
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110679; -- Aurore
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103223; -- Hertha Grimdottir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105323; -- Oeufs des catacombes anciens
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=65343; -- Araignée des ossements
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113278; -- Tenebrous Snake
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108874; -- Vineyard Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107487; -- Starbuck
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=57239; -- Wise Turtle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108870; -- Sylverin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111962; -- Illidari Adept
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107350; -- Cyrille
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107348; -- Sylessa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111960; -- Survey Bunny
UPDATE `creature_template` SET `modelid1`=77405, `modelid2`=77406, `modelid3`=77407, `VerifiedBuild`=25996 WHERE `entry`=99737; -- Diablotin sauvage
UPDATE `creature_template` SET `modelid1`=77402, `modelid2`=77403, `modelid3`=77404, `VerifiedBuild`=25996 WHERE `entry`=98035; -- Traqueffroi
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=72676; -- Spirit Healer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107349; -- Lorin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102303; -- Lieutenant Strathmar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103131; -- Keelay Moongrow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116161; -- Arcane Minion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111685; -- Loyalist Aristocrat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111771; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113843; -- Kieule
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109056; -- Luxurious Palanquin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109463; -- Magisterial Escort
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99638; -- Caged Polar Bear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104844; -- "Old Wise" Ewaye
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105654; -- Captive Penguin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110987; -- Nighteyes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109461; -- Vineyard Porter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109509; -- Spellsinger Quiris
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113487; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113486; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105652; -- Confined Wind Serpent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113675; -- Wyrmtongue Scribe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116360; -- Duskwatch Scryer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110786; -- Astravar Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110783; -- Courtly Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110780; -- Astravar Attendant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111651; -- Degren
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105646; -- Captive Basilisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112547; -- Tempomancer Virinya
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111699; -- Loyalist Aristocrat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112483; -- Rebel Arcanist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112484; -- Rebel Strongarm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112482; -- Rebel Assassin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111664; -- Lavish Palanquin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=6491; -- Spirit Healer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112489; -- Callus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109180; -- Tattered Silkwing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111653; -- Miasu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108931; -- Vineyard Laborer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111557; -- Legion Battlematron
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112530; -- Garion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115988; -- Flétri affamé
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109669; -- High Society Entertainer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110650; -- Gondola
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110655; -- Duskmere Smuggler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107342; -- Duskwatch Spell-Fencer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110654; -- Frightened Laborer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109652; -- Duskwatch Warpcaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112531; -- Leleyna
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110365; -- Ruven
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111558; -- Felgaze Doomseer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111523; -- Duskwatch Warpcaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111749; -- Felborne Collaborator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111730; -- Felsworn Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113778; -- Deactivated Security Module
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111556; -- Felsoul Courtesan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111485; -- Duskwatch Spellshield
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108188; -- Imperial Arcbinder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111750; -- Felborne Collaborator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111747; -- Felsworn Noble
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111649; -- Ambassador D'vwinn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111489; -- Loyalist Sycophant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111490; -- Flagorneur loyaliste
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109647; -- Imperial Arcbinder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111484; -- Duskwatch Spellshield
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108189; -- Imperial Servant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110728; -- Marina Sentry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109650; -- Duskwatch Spell-Fencer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109670; -- Chronarch Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111498; -- Imperial Servant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116655; -- High Society Harpist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116653; -- Loyalist Spectator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114869; -- Bourreau du moteur d’âmes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114959; -- Molosse du moteur d’âmes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114997; -- Felsoul Ferry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116660; -- Felsoul Ferry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110358; -- Lapin grappin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115012; -- Felborne Conspirator
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111904; -- Waning Crescent Porter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=1713; -- Elder Shadowmaw Panther
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109411; -- Shadescale Flyeater
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109158; -- Underglow Locust

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=98208 AND `Idx`=5) OR (`CreatureEntry`=108675 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(98208, 5, 146678, 25996), -- Conseiller Vandros
(108675, 0, 144444, 25996); -- Mooncrazed Owlbeast

UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=59037 AND `Idx`=0); -- Kung Din
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114785 AND `Idx`=0); -- Valarjar Marksman
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114786 AND `Idx`=0); -- Valarjar Mystic
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114789 AND `Idx`=0); -- Stormforged Sentinel
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114787 AND `Idx`=0); -- Valarjar Runecarver
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114784 AND `Idx`=0); -- Valarjar Champion
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114788 AND `Idx`=0); -- Mande-tonnerre valarjar
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=3475 AND `Idx`=0); -- Echeyakee
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=98208 AND `Idx`=4); -- Conseiller Vandros
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=98208 AND `Idx`=3); -- Conseiller Vandros
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=98208 AND `Idx`=2); -- Conseiller Vandros
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=98208 AND `Idx`=1); -- Conseiller Vandros
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=98208 AND `Idx`=0); -- Conseiller Vandros
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102351 AND `Idx`=1); -- Mana Wyrm
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102351 AND `Idx`=0); -- Mana Wyrm
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=98732 AND `Idx`=0); -- Plagued Rat
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100496 AND `Idx`=0); -- Silvered Streaker
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=93318 AND `Idx`=4); -- Ashmaw Mauler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=93318 AND `Idx`=3); -- Ashmaw Mauler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=93318 AND `Idx`=2); -- Ashmaw Mauler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=93318 AND `Idx`=1); -- Ashmaw Mauler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=93318 AND `Idx`=0); -- Ashmaw Mauler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=108190 AND `Idx`=0); -- Magisterial Sleuth
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=107487 AND `Idx`=2); -- Starbuck
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=107487 AND `Idx`=1); -- Starbuck
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=107487 AND `Idx`=0); -- Starbuck
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105654 AND `Idx`=0); -- Captive Penguin
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105652 AND `Idx`=1); -- Confined Wind Serpent
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105652 AND `Idx`=0); -- Confined Wind Serpent
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113675 AND `Idx`=2); -- Wyrmtongue Scribe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113675 AND `Idx`=1); -- Wyrmtongue Scribe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113675 AND `Idx`=0); -- Wyrmtongue Scribe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105646 AND `Idx`=1); -- Captive Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105646 AND `Idx`=0); -- Captive Basilisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=109670 AND `Idx`=0); -- Chronarch Defender
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114869 AND `Idx`=0); -- Bourreau du moteur d’âmes
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114959 AND `Idx`=2); -- Molosse du moteur d’âmes
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114959 AND `Idx`=1); -- Molosse du moteur d’âmes
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114959 AND `Idx`=0); -- Molosse du moteur d’âmes
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=1713 AND `Idx`=1); -- Elder Shadowmaw Panther
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=1713 AND `Idx`=0); -- Elder Shadowmaw Panther

DELETE FROM `gameobject_template` WHERE `entry` IN (265459 /*Doodad_7sr_hubmanatree004*/, 252011 /*Life Essence Pedestal*/, 266917 /*Doodad_7vr_Vrykul_fence004*/, 266915 /*Doodad_7vr_Vrykul_fence002*/, 266914 /*Doodad_7vr_Vrykul_fence001*/, 266916 /*Doodad_7vr_Vrykul_fence003*/, 242454 /*Hellfire Gate*/, 266533 /*Guarm_Boss_Door02*/, 266532 /*Guarm_Boss_Door01*/, 243404 /*Collision Wall*/, 266530 /*Bonfire*/, 266531 /*Bonfire*/, 260251 /*Portal to Shal'Aran*/, 258546 /*Doodad_7nb_nightborn_pillowpile014*/, 258542 /*Doodad_7nb_nightborn_pillowpile011*/, 258549 /*Doodad_7nb_nightborn_rug012*/, 258545 /*Doodad_7nb_nightborn_rug013*/, 258543 /*Doodad_7nb_nightborn_rug015*/, 258550 /*Doodad_7nb_nightborn_pillowpile013*/, 258556 /*Doodad_7nb_nightborn_pillowpile03_wall003*/, 258555 /*Doodad_7nb_nightborn_pillowpile004*/, 258554 /*Doodad_7nb_nightborn_pillowpile03_wall002*/, 258544 /*Doodad_7nb_nightborn_rug014*/, 258553 /*Doodad_7nb_nightborn_rug002*/, 250279 /*Pipe*/, 250635 /*Door I*/, 250637 /*Door L*/, 250636 /*Door J*/, 250276 /*Door K*/, 252164 /*Catacombs Grate*/, 250277 /*Door H*/, 250275 /*Door G*/, 250634 /*Door F*/, 248997 /*Fel Rune*/, 250274 /*Door D (Top)*/, 250278 /*Door B*/, 245968 /*Catacombs Door*/, 250273 /*Door D (Bottom)*/, 250272 /*Door A*/, 250434 /*Door C*/, 250633 /*Doodad_7DU_SuramarCatacombs_Door007*/, 258619 /*Doodad_7nb_nightborn_pillowpile03_wall002*/, 258618 /*Doodad_7nb_nightborn_pillowpile003*/, 258617 /*Doodad_7nb_nightborn_pillowpile005*/, 259255 /*Doodad_7nb_nightborn_gameboard002*/, 258610 /*Doodad_7nb_nightborn_pillowpile007*/, 258612 /*Doodad_7nb_nightborn_pillowpile002*/, 258611 /*Doodad_7nb_nightborn_rug003*/, 258609 /*Doodad_7nb_nightborn_pillowpile006*/, 258608 /*Doodad_7nb_nightborn_pillowpile03_wall004*/, 258613 /*Doodad_7nb_nightborn_pillowpile004*/, 258614 /*Doodad_7nb_nightborn_pillowpile03_wall003*/, 258604 /*Doodad_7nb_nightborn_pillowpile017*/, 258560 /*Doodad_7nb_nightborn_pillowpile03_wall006*/, 258559 /*Doodad_7nb_nightborn_pillowpile009*/, 258562 /*Doodad_7nb_nightborn_pillowpile008*/, 258599 /*Doodad_7nb_nightborn_scrollbag025*/, 258564 /*Doodad_7nb_nightborn_pillowpile03_wall005*/, 258601 /*Doodad_7nb_nightborn_rug020*/, 259254 /*Doodad_7nb_nightborn_gameboard001*/, 258565 /*Doodad_7nb_nightborn_pillowpile002*/, 258594 /*Doodad_7nb_nightborn_scrollbag003*/, 258592 /*Doodad_7nb_nightborn_scrollbag005*/, 258571 /*Doodad_7nb_nightborn_scrollbag011*/, 258591 /*Doodad_7nb_nightborn_pillowpile03_wall014*/, 259249 /*Doodad_7nb_nightborn_fruit002*/, 259253 /*Doodad_7nb_nightborn_platter003*/, 259251 /*Doodad_7nb_nightborn_platter001*/, 259248 /*Doodad_7nb_nightborn_fruit001*/, 259245 /*Doodad_7nb_nightborn_foodpastry001*/, 259247 /*Doodad_7nb_nightborn_foodpastry002*/, 253771 /*Right Chamber - H - Clean - Rug*/, 258574 /*Doodad_7nb_nightborn_pillowpile003*/, 259252 /*Doodad_7nb_nightborn_platter002*/, 259250 /*Doodad_7nb_nightborn_fruit003*/, 258589 /*Doodad_7nb_nightborn_pillowpile018*/, 259243 /*Doodad_7nb_nightborn_fruitbasket001*/, 258572 /*Doodad_7nb_nightborn_pillowpile006*/, 258575 /*Doodad_7nb_nightborn_pillowpile03_wall001*/, 258588 /*Doodad_7nb_nightborn_pillowpile03_wall015*/, 258577 /*Doodad_7nb_nightborn_scrollbag008*/, 258578 /*Doodad_7nb_nightborn_scrollpile003*/, 258522 /*Doodad_7nb_nightborn_pillowpile015*/, 258521 /*Doodad_7nb_nightborn_clothbolt004*/, 258520 /*Doodad_7nb_nightborn_clothbolt003*/, 258519 /*Doodad_7nb_nightborn_floorpillow002*/, 258514 /*Doodad_7nb_nightborn_pillowpile03_wall001*/, 258516 /*Doodad_7nb_nightborn_crate011*/, 258513 /*Doodad_7nb_nightborn_plantlight001*/, 258508 /*Bazaarbasketset001*/, 258506 /*Doodad_7nb_nightborn_crate009*/, 258383 /*Doodad_7nb_nightborn_lantern01_unlit001*/, 258507 /*Doodad_7nb_nightborn_bookpile001*/, 258382 /*Doodad_7nb_nightborn_hookah001*/, 258503 /*Doodad_7nb_nightborn_scrollbag001*/, 258344 /*Doodad_7nb_nightborn_chair001*/, 258347 /*Doodad_7nb_nightborn_basketstack008*/, 258345 /*Doodad_7nb_nightborn_bazaarbasketset007*/, 258411 /*Doodad_7xp_leycrystal_a002*/, 258350 /*Doodad_7nb_nightborn_plantlight005*/, 258396 /*Doodad_7nb_nightborn_rug008*/, 258358 /*Doodad_7nb_nightborn_basketstack011*/, 258398 /*Doodad_7nb_nightborn_rug005*/, 258360 /*Doodad_7nb_nightborn_clothbolt005*/, 258406 /*Doodad_7xp_leycrystal_a001*/, 258361 /*Doodad_7nb_nightborn_pillowpile016*/, 253777 /*Right Chamber - J - Clean - Basketset*/, 258357 /*Doodad_7nb_nightborn_plantlight004*/, 253729 /*Right Chamber - G - Clean - Pillowpile 02*/, 253780 /*Right Chamber - G - Clean - Pillowpile 03*/, 259238 /*Doodad_7nb_nightborn_crate015*/, 253726 /*Right Chamber - G - Clean - Hookah*/, 253776 /*Right Chamber - J - Clean - Scrollpile 01*/, 253700 /*Right Chamber - G - Clean - Rug*/, 253760 /*Right Chamber - J - Clean - Shelf*/, 253773 /*Right Chamber - J - Clean - Scrollbag*/, 253770 /*Right Chamber - F - Clean - Owldesk*/, 258353 /*Doodad_7nb_nightborn_plantlight007*/, 253727 /*Right Chamber - G - Clean - Pillowpile 01*/, 253708 /*Right Chamber - E - Clean - Bookpile 05*/, 258464 /*Doodad_7nb_nightborn_scrollbag001*/, 258354 /*Doodad_7nb_nightborn_plantlight008*/, 253734 /*Right Chamber - E - Clean - Scroll*/, 253711 /*Right Chamber - E - Clean - Scrollpile 01*/, 253707 /*Right Chamber - E - Clean - Bookpile 04*/, 258463 /*Doodad_7nb_nightborn_scrollpile001*/, 253710 /*Right Chamber - E - Clean - Lantern*/, 253706 /*Right Chamber - E - Clean - Bookpile 03*/, 253733 /*Right Chamber - E - Clean - Scrollpile 02*/, 253715 /*Right Chamber - E - Clean - Bookpile 06*/, 258461 /*Doodad_7nb_nightborn_scroll001*/, 253709 /*Right Chamber - E - Clean - Scrollbag 01*/, 253736 /*Right Chamber - E - Clean - Scrollbag 03*/, 258460 /*Doodad_7nb_nightborn_tablesmall001*/, 258459 /*Doodad_7nb_nightborn_hookah001*/, 253697 /*Right Chamber - E - Clean - Bookpile 01*/, 253698 /*Right Chamber - E - Clean - Bookpile 02*/, 258393 /*Doodad_7nb_nightborn_scroll001*/, 258392 /*Doodad_7nb_nightborn_scroll002*/, 258391 /*Doodad_7nb_nightborn_scrollpile002*/, 253696 /*Right Chamber - D - Clean - Rug*/, 258378 /*Doodad_7nb_nightborn_plantlight006*/, 253759 /*Right Chamber - K - Clean - Shelf*/, 258390 /*Doodad_7nb_nightborn_scrollpile003*/, 258430 /*Main Chamber - 3 - Clean - Rug 01*/, 258428 /*Main Chamber - 3 - Clean - Knife 01*/, 258427 /*Main Chamber - 3 - Clean - Map 01*/, 258454 /*Doodad_7nb_nightborn_tablesmall002*/, 258455 /*Doodad_7nb_nightborn_lantern001*/, 253735 /*Right Chamber - C - Clean - Scrollpile 01*/, 253694 /*Right Chamber - C - Clean - Bookpile 03*/, 253692 /*Right Chamber - C - Clean - Bookpile 02*/, 253693 /*Right Chamber - C - Clean - Lantern 01*/, 258377 /*Doodad_7nb_nightborn_plantlight009*/, 253719 /*Right Chamber - C - Clean - Quill*/, 253717 /*Right Chamber - B - Clean - Cratestack 01*/, 253763 /*Right Chamber - B - Clean - Cratestack 03*/, 258349 /*Doodad_7nb_nightborn_plantlight010*/, 258362 /*Doodad_7nb_nightborn_bazaarbasketset003*/, 258379 /*Doodad_7nb_nightborn_bazaarbasketset002*/, 258351 /*Doodad_7nb_nightborn_lantern004*/, 258365 /*Doodad_7nb_nightborn_basketstack001*/, 258446 /*Doodad_7nb_nightborn_lantern003*/, 258431 /*Main Chamber - 2 - Clean - Rug 01*/, 258432 /*Main Chamber - 2 - Clean - Chair 01*/, 258441 /*Main Chamber - 2 - Clean - Quill 01*/, 258442 /*Main Chamber - 2 - Clean - Scroll 02*/, 258440 /*Main Chamber - 2 - Clean - Bottle 01*/, 258443 /*Main Chamber - 2 - Clean - Scroll 01*/, 258439 /*Main Chamber - 2 - Clean - Book 01*/, 258444 /*Main Chamber - 2 - Clean - Crate 01*/, 258452 /*Main Chamber - 1 - Clean - Pillow 02*/, 258448 /*Main Chamber - 1 - Clean - Cloth 01*/, 258451 /*Main Chamber - 1 - Clean - Cloth 02*/, 258449 /*Main Chamber - 1 - Clean - Pillow 01*/, 254689 /*Bench*/, 258984 /*Devilsaur Egg*/, 255104 /*Bench*/, 255100 /*Bench*/, 255099 /*Bench*/, 255098 /*Bench*/, 254463 /*Bench*/, 269949 /*Auction Materials*/, 281340 /*Warchief's Command Board*/, 243292 /*Torch*/, 243293 /*Barricade*/, 252305 /*Portal to Dalaran*/, 258620 /*Doodad_7nb_nightborn_bazaarbasketset009*/, 258603 /*Doodad_7nb_nightborn_rug017*/, 258561 /*Doodad_7nb_nightborn_bazaarbasketset004*/, 258558 /*Doodad_7nb_nightborn_rug005*/, 258598 /*Doodad_7nb_nightborn_crate013*/, 258597 /*Doodad_7nb_nightborn_scrollbag002*/, 258602 /*Doodad_7nb_nightborn_rug019*/, 258563 /*Doodad_7nb_nightborn_rug004*/, 258595 /*Doodad_7nb_nightborn_scrollpile002*/, 258569 /*Doodad_7nb_nightborn_scrollpile001*/, 258590 /*Doodad_7nb_nightborn_rug018*/, 258576 /*Doodad_7nb_nightborn_rug001*/, 258580 /*Doodad_7nb_nightborn_scrollbag006*/, 258523 /*Doodad_7nb_nightborn_basketstack012*/, 258518 /*Doodad_7nb_nightborn_scrollbag020*/, 258537 /*Doodad_7nb_nightborn_crate012*/, 258515 /*Doodad_7nb_nightborn_scrollbag013*/, 258509 /*Doodad_7nb_nightborn_crate008*/, 258381 /*Doodad_7nb_nightborn_basketstack009*/, 258502 /*Doodad_7nb_nightborn_crate007*/, 258408 /*Doodad_6hu_enchanting_crystalblue003*/, 258407 /*Doodad_7db_drogbar_crystalblue001*/, 258404 /*Doodad_6br_goren_crystal_blue002*/, 258470 /*Main Chamber - 4 - Clean - Crate 06*/, 258359 /*Doodad_7nb_nightborn_basketstack013*/, 258394 /*Doodad_7nb_nightborn_crate001*/, 258355 /*Doodad_7nb_nightborn_benchlong001*/, 258352 /*Doodad_7nb_nightborn_benchlong002*/, 258462 /*Doodad_7nb_nightborn_benchshort001*/, 258458 /*Doodad_7nb_nightborn_benchshort002*/, 258356 /*Doodad_7nb_nightborn_benchlong003*/, 253701 /*Right Chamber - C - Clean - Scrollpile 02*/, 253699 /*Right Chamber - C - Clean - Bookpile 01*/, 258423 /*Main Chamber - 3 - Clean - Scroll 04*/, 258456 /*Doodad_7nb_nightborn_benchshort003*/, 258389 /*Doodad_7nb_nightborn_shelf01_empty001*/, 253720 /*Right Chamber - C - Clean - Scroll 01*/, 253695 /*Right Chamber - C - Clean - Scrollpile 03*/, 258419 /*Main Chamber - 3 - Clean - Book 03*/, 258388 /*Doodad_7nb_nightborn_scrollbag016*/, 258426 /*Main Chamber - 3 - Clean - Scroll 02*/, 258429 /*Main Chamber - 3 - Clean - Scroll 01*/, 258453 /*Doodad_7nb_nightborn_benchshort004*/, 253764 /*Right Chamber - B - Clean - Cratestack 04*/, 253762 /*Right Chamber - B - Clean - Cratestack 02*/, 253752 /*Right Chamber - A - Clean - Scrollbag*/, 258363 /*Doodad_7nb_nightborn_basketstack002*/, 258436 /*Doodad_6hu_blacksmith_paper_002*/, 258438 /*Main Chamber - 2 - Clean - Desk 01*/, 258445 /*Main Chamber - 2 - Clean - Dresser 01*/, 258437 /*Doodad_7af_paladin_map002*/, 258447 /*Main Chamber - 1 - Clean - Basketset 02*/, 255173 /*Bench*/, 265423 /*Blood Elf Wagon*/, 266191 /*Black Rook Crates*/, 266192 /*Black Rook Ballista*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(265459, 5, 32752, 'Doodad_7sr_hubmanatree004', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7sr_hubmanatree004
(252011, 5, 30630, 'Life Essence Pedestal', '', '', '', 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Life Essence Pedestal
(266917, 5, 39573, 'Doodad_7vr_Vrykul_fence004', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vr_Vrykul_fence004
(266915, 5, 39573, 'Doodad_7vr_Vrykul_fence002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vr_Vrykul_fence002
(266914, 5, 39573, 'Doodad_7vr_Vrykul_fence001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vr_Vrykul_fence001
(266916, 5, 39573, 'Doodad_7vr_Vrykul_fence003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7vr_Vrykul_fence003
(242454, 0, 10403, 'Hellfire Gate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Hellfire Gate
(266533, 0, 31091, 'Guarm_Boss_Door02', '', '', '', 1.85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Guarm_Boss_Door02
(266532, 0, 31091, 'Guarm_Boss_Door01', '', '', '', 1.01, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Guarm_Boss_Door01
(243404, 5, 6391, 'Collision Wall', '', '', '', 0.9, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Collision Wall
(266530, 8, 7748, 'Bonfire', '', '', '', 1, 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bonfire
(266531, 8, 7748, 'Bonfire', '', '', '', 1, 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bonfire
(260251, 22, 36654, 'Portal to Shal''Aran', '', '', '', 1, 202605, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal to Shal'Aran
(258546, 5, 36387, 'Doodad_7nb_nightborn_pillowpile014', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile014
(258542, 5, 36376, 'Doodad_7nb_nightborn_pillowpile011', '', '', '', 0.8245044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile011
(258549, 5, 34374, 'Doodad_7nb_nightborn_rug012', '', '', '', 0.8599997, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug012
(258545, 5, 34374, 'Doodad_7nb_nightborn_rug013', '', '', '', 0.8599997, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug013
(258543, 5, 34374, 'Doodad_7nb_nightborn_rug015', '', '', '', 0.8599995, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug015
(258550, 5, 36387, 'Doodad_7nb_nightborn_pillowpile013', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile013
(258556, 5, 37520, 'Doodad_7nb_nightborn_pillowpile03_wall003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile03_wall003
(258555, 5, 37493, 'Doodad_7nb_nightborn_pillowpile004', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile004
(258554, 5, 37520, 'Doodad_7nb_nightborn_pillowpile03_wall002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile03_wall002
(258544, 5, 36368, 'Doodad_7nb_nightborn_rug014', '', '', '', 2.893154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug014
(258553, 5, 36368, 'Doodad_7nb_nightborn_rug002', '', '', '', 1.38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug002
(250279, 5, 34025, 'Pipe', '', '', '', 3.11378, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Pipe
(250635, 0, 34023, 'Door I', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Door I
(250637, 0, 34024, 'Door L', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Door L
(250636, 0, 34024, 'Door J', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Door J
(250276, 0, 34024, 'Door K', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Door K
(252164, 0, 34945, 'Catacombs Grate', '', '', '', 2.8, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Catacombs Grate
(250277, 0, 34023, 'Door H', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Door H
(250275, 0, 34023, 'Door G', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Door G
(250634, 0, 34023, 'Door F', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Door F
(248997, 5, 30992, 'Fel Rune', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Fel Rune
(250274, 0, 34023, 'Door D (Top)', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Door D (Top)
(250278, 0, 34024, 'Door B', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Door B
(245968, 0, 34023, 'Catacombs Door', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Catacombs Door
(250273, 0, 34023, 'Door D (Bottom)', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Door D (Bottom)
(250272, 0, 34023, 'Door A', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Door A
(250434, 0, 34023, 'Door C', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Door C
(250633, 0, 34023, 'Doodad_7DU_SuramarCatacombs_Door007', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7DU_SuramarCatacombs_Door007
(258619, 5, 37520, 'Doodad_7nb_nightborn_pillowpile03_wall002', '', '', '', 1.01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile03_wall002
(258618, 5, 36376, 'Doodad_7nb_nightborn_pillowpile003', '', '', '', 0.95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile003
(258617, 5, 36387, 'Doodad_7nb_nightborn_pillowpile005', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile005
(259255, 5, 38101, 'Doodad_7nb_nightborn_gameboard002', '', '', '', 0.86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_gameboard002
(258610, 5, 34373, 'Doodad_7nb_nightborn_pillowpile007', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile007
(258612, 5, 36387, 'Doodad_7nb_nightborn_pillowpile002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile002
(258611, 5, 34374, 'Doodad_7nb_nightborn_rug003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug003
(258609, 5, 37493, 'Doodad_7nb_nightborn_pillowpile006', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile006
(258608, 5, 37520, 'Doodad_7nb_nightborn_pillowpile03_wall004', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile03_wall004
(258613, 5, 36376, 'Doodad_7nb_nightborn_pillowpile004', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile004
(258614, 5, 37520, 'Doodad_7nb_nightborn_pillowpile03_wall003', '', '', '', 1.01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile03_wall003
(258604, 5, 37493, 'Doodad_7nb_nightborn_pillowpile017', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile017
(258560, 5, 37520, 'Doodad_7nb_nightborn_pillowpile03_wall006', '', '', '', 1.01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile03_wall006
(258559, 5, 36387, 'Doodad_7nb_nightborn_pillowpile009', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile009
(258562, 5, 36376, 'Doodad_7nb_nightborn_pillowpile008', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile008
(258599, 5, 36370, 'Doodad_7nb_nightborn_scrollbag025', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag025
(258564, 5, 37520, 'Doodad_7nb_nightborn_pillowpile03_wall005', '', '', '', 1.01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile03_wall005
(258601, 5, 34374, 'Doodad_7nb_nightborn_rug020', '', '', '', 1.271076, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug020
(259254, 5, 38101, 'Doodad_7nb_nightborn_gameboard001', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_gameboard001
(258565, 5, 36376, 'Doodad_7nb_nightborn_pillowpile002', '', '', '', 0.8245044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile002
(258594, 5, 36370, 'Doodad_7nb_nightborn_scrollbag003', '', '', '', 0.99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag003
(258592, 5, 35102, 'Doodad_7nb_nightborn_scrollbag005', '', '', '', 0.99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag005
(258571, 5, 36370, 'Doodad_7nb_nightborn_scrollbag011', '', '', '', 0.99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag011
(258591, 5, 37520, 'Doodad_7nb_nightborn_pillowpile03_wall014', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile03_wall014
(259249, 5, 38099, 'Doodad_7nb_nightborn_fruit002', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_fruit002
(259253, 5, 38100, 'Doodad_7nb_nightborn_platter003', '', '', '', 0.8099999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_platter003
(259251, 5, 38100, 'Doodad_7nb_nightborn_platter001', '', '', '', 0.7400001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_platter001
(259248, 5, 38098, 'Doodad_7nb_nightborn_fruit001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_fruit001
(259245, 5, 38096, 'Doodad_7nb_nightborn_foodpastry001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_foodpastry001
(259247, 5, 38097, 'Doodad_7nb_nightborn_foodpastry002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_foodpastry002
(253771, 5, 36381, 'Right Chamber - H - Clean - Rug', '', '', '', 1.71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - H - Clean - Rug
(258574, 5, 36387, 'Doodad_7nb_nightborn_pillowpile003', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile003
(259252, 5, 38100, 'Doodad_7nb_nightborn_platter002', '', '', '', 0.7399999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_platter002
(259250, 5, 35800, 'Doodad_7nb_nightborn_fruit003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_fruit003
(258589, 5, 37493, 'Doodad_7nb_nightborn_pillowpile018', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile018
(259243, 5, 36175, 'Doodad_7nb_nightborn_fruitbasket001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_fruitbasket001
(258572, 5, 36387, 'Doodad_7nb_nightborn_pillowpile006', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile006
(258575, 5, 37520, 'Doodad_7nb_nightborn_pillowpile03_wall001', '', '', '', 1.01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile03_wall001
(258588, 5, 37520, 'Doodad_7nb_nightborn_pillowpile03_wall015', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile03_wall015
(258577, 5, 36370, 'Doodad_7nb_nightborn_scrollbag008', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag008
(258578, 5, 34363, 'Doodad_7nb_nightborn_scrollpile003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollpile003
(258522, 5, 37493, 'Doodad_7nb_nightborn_pillowpile015', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile015
(258521, 5, 37492, 'Doodad_7nb_nightborn_clothbolt004', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_clothbolt004
(258520, 5, 37492, 'Doodad_7nb_nightborn_clothbolt003', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_clothbolt003
(258519, 5, 37513, 'Doodad_7nb_nightborn_floorpillow002', '', '', '', 0.9999998, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_floorpillow002
(258514, 5, 37520, 'Doodad_7nb_nightborn_pillowpile03_wall001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile03_wall001
(258516, 5, 37501, 'Doodad_7nb_nightborn_crate011', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_crate011
(258513, 5, 37491, 'Doodad_7nb_nightborn_plantlight001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_plantlight001
(258508, 5, 37188, 'Bazaarbasketset001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bazaarbasketset001
(258506, 5, 37501, 'Doodad_7nb_nightborn_crate009', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_crate009
(258383, 5, 31748, 'Doodad_7nb_nightborn_lantern01_unlit001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_lantern01_unlit001
(258507, 5, 37511, 'Doodad_7nb_nightborn_bookpile001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_bookpile001
(258382, 5, 36375, 'Doodad_7nb_nightborn_hookah001', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_hookah001
(258503, 5, 36370, 'Doodad_7nb_nightborn_scrollbag001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag001
(258344, 5, 34334, 'Doodad_7nb_nightborn_chair001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_chair001
(258347, 5, 37490, 'Doodad_7nb_nightborn_basketstack008', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_basketstack008
(258345, 5, 36384, 'Doodad_7nb_nightborn_bazaarbasketset007', '', '', '', 0.8200001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_bazaarbasketset007
(258411, 5, 28519, 'Doodad_7xp_leycrystal_a002', '', '', '', 0.23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7xp_leycrystal_a002
(258350, 5, 37491, 'Doodad_7nb_nightborn_plantlight005', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_plantlight005
(258396, 5, 36381, 'Doodad_7nb_nightborn_rug008', '', '', '', 1.475276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug008
(258358, 5, 36279, 'Doodad_7nb_nightborn_basketstack011', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_basketstack011
(258398, 5, 36365, 'Doodad_7nb_nightborn_rug005', '', '', '', 0.8700002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug005
(258360, 5, 37492, 'Doodad_7nb_nightborn_clothbolt005', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_clothbolt005
(258406, 5, 26437, 'Doodad_7xp_leycrystal_a001', '', '', '', 0.1911609, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7xp_leycrystal_a001
(258361, 5, 37493, 'Doodad_7nb_nightborn_pillowpile016', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_pillowpile016
(253777, 5, 36384, 'Right Chamber - J - Clean - Basketset', '', '', '', 0.63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - J - Clean - Basketset
(258357, 5, 37491, 'Doodad_7nb_nightborn_plantlight004', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_plantlight004
(253729, 5, 36376, 'Right Chamber - G - Clean - Pillowpile 02', '', '', '', 0.9500002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - G - Clean - Pillowpile 02
(253780, 5, 36387, 'Right Chamber - G - Clean - Pillowpile 03', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - G - Clean - Pillowpile 03
(259238, 5, 37501, 'Doodad_7nb_nightborn_crate015', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_crate015
(253726, 5, 36375, 'Right Chamber - G - Clean - Hookah', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - G - Clean - Hookah
(253776, 5, 34582, 'Right Chamber - J - Clean - Scrollpile 01', '', '', '', 0.7799999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - J - Clean - Scrollpile 01
(253700, 5, 36368, 'Right Chamber - G - Clean - Rug', '', '', '', 2.92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - G - Clean - Rug
(253760, 5, 36383, 'Right Chamber - J - Clean - Shelf', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - J - Clean - Shelf
(253773, 5, 35102, 'Right Chamber - J - Clean - Scrollbag', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - J - Clean - Scrollbag
(253770, 5, 36386, 'Right Chamber - F - Clean - Owldesk', '', '', '', 1.01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - F - Clean - Owldesk
(258353, 5, 37491, 'Doodad_7nb_nightborn_plantlight007', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_plantlight007
(253727, 5, 36376, 'Right Chamber - G - Clean - Pillowpile 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - G - Clean - Pillowpile 01
(253708, 5, 36366, 'Right Chamber - E - Clean - Bookpile 05', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - E - Clean - Bookpile 05
(258464, 5, 35102, 'Doodad_7nb_nightborn_scrollbag001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag001
(258354, 5, 37491, 'Doodad_7nb_nightborn_plantlight008', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_plantlight008
(253734, 5, 36374, 'Right Chamber - E - Clean - Scroll', '', '', '', 0.8600001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - E - Clean - Scroll
(253711, 5, 34582, 'Right Chamber - E - Clean - Scrollpile 01', '', '', '', 0.6700001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - E - Clean - Scrollpile 01
(253707, 5, 36366, 'Right Chamber - E - Clean - Bookpile 04', '', '', '', 0.9500002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - E - Clean - Bookpile 04
(258463, 5, 34363, 'Doodad_7nb_nightborn_scrollpile001', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollpile001
(253710, 5, 31748, 'Right Chamber - E - Clean - Lantern', '', '', '', 0.92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - E - Clean - Lantern
(253706, 5, 36366, 'Right Chamber - E - Clean - Bookpile 03', '', '', '', 0.7800002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - E - Clean - Bookpile 03
(253733, 5, 34363, 'Right Chamber - E - Clean - Scrollpile 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - E - Clean - Scrollpile 02
(253715, 5, 36367, 'Right Chamber - E - Clean - Bookpile 06', '', '', '', 0.8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - E - Clean - Bookpile 06
(258461, 5, 37515, 'Doodad_7nb_nightborn_scroll001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scroll001
(253709, 5, 36370, 'Right Chamber - E - Clean - Scrollbag 01', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - E - Clean - Scrollbag 01
(253736, 5, 35102, 'Right Chamber - E - Clean - Scrollbag 03', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - E - Clean - Scrollbag 03
(258460, 5, 34054, 'Doodad_7nb_nightborn_tablesmall001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_tablesmall001
(258459, 5, 36375, 'Doodad_7nb_nightborn_hookah001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_hookah001
(253697, 5, 36367, 'Right Chamber - E - Clean - Bookpile 01', '', '', '', 0.66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - E - Clean - Bookpile 01
(253698, 5, 36366, 'Right Chamber - E - Clean - Bookpile 02', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - E - Clean - Bookpile 02
(258393, 5, 37500, 'Doodad_7nb_nightborn_scroll001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scroll001
(258392, 5, 36374, 'Doodad_7nb_nightborn_scroll002', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scroll002
(258391, 5, 34363, 'Doodad_7nb_nightborn_scrollpile002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollpile002
(253696, 5, 34374, 'Right Chamber - D - Clean - Rug', '', '', '', 1.54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - D - Clean - Rug
(258378, 5, 37491, 'Doodad_7nb_nightborn_plantlight006', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_plantlight006
(253759, 5, 36382, 'Right Chamber - K - Clean - Shelf', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - K - Clean - Shelf
(258390, 5, 34582, 'Doodad_7nb_nightborn_scrollpile003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollpile003
(258430, 5, 36381, 'Main Chamber - 3 - Clean - Rug 01', '', '', '', 1.335338, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 3 - Clean - Rug 01
(258428, 5, 29674, 'Main Chamber - 3 - Clean - Knife 01', '', '', '', 1.320001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 3 - Clean - Knife 01
(258427, 5, 30018, 'Main Chamber - 3 - Clean - Map 01', '', '', '', 1.65341, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 3 - Clean - Map 01
(258454, 5, 34054, 'Doodad_7nb_nightborn_tablesmall002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_tablesmall002
(258455, 5, 37514, 'Doodad_7nb_nightborn_lantern001', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_lantern001
(253735, 5, 34363, 'Right Chamber - C - Clean - Scrollpile 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Clean - Scrollpile 01
(253694, 5, 36366, 'Right Chamber - C - Clean - Bookpile 03', '', '', '', 0.9500004, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Clean - Bookpile 03
(253692, 5, 36366, 'Right Chamber - C - Clean - Bookpile 02', '', '', '', 0.78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Clean - Bookpile 02
(253693, 5, 31748, 'Right Chamber - C - Clean - Lantern 01', '', '', '', 0.92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Clean - Lantern 01
(258377, 5, 37491, 'Doodad_7nb_nightborn_plantlight009', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_plantlight009
(253719, 5, 31664, 'Right Chamber - C - Clean - Quill', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Clean - Quill
(253717, 5, 36279, 'Right Chamber - B - Clean - Cratestack 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - B - Clean - Cratestack 01
(253763, 5, 36279, 'Right Chamber - B - Clean - Cratestack 03', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - B - Clean - Cratestack 03
(258349, 5, 37491, 'Doodad_7nb_nightborn_plantlight010', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_plantlight010
(258362, 5, 36384, 'Doodad_7nb_nightborn_bazaarbasketset003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_bazaarbasketset003
(258379, 5, 36384, 'Doodad_7nb_nightborn_bazaarbasketset002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_bazaarbasketset002
(258351, 5, 37378, 'Doodad_7nb_nightborn_lantern004', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_lantern004
(258365, 5, 37490, 'Doodad_7nb_nightborn_basketstack001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_basketstack001
(258446, 5, 37378, 'Doodad_7nb_nightborn_lantern003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_lantern003
(258431, 5, 34374, 'Main Chamber - 2 - Clean - Rug 01', '', '', '', 1.183825, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Rug 01
(258432, 5, 34334, 'Main Chamber - 2 - Clean - Chair 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Chair 01
(258441, 5, 31664, 'Main Chamber - 2 - Clean - Quill 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Quill 01
(258442, 5, 36374, 'Main Chamber - 2 - Clean - Scroll 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Scroll 02
(258440, 5, 34982, 'Main Chamber - 2 - Clean - Bottle 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Bottle 01
(258443, 5, 37500, 'Main Chamber - 2 - Clean - Scroll 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Scroll 01
(258439, 5, 37510, 'Main Chamber - 2 - Clean - Book 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Book 01
(258444, 5, 37501, 'Main Chamber - 2 - Clean - Crate 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Crate 01
(258452, 5, 37493, 'Main Chamber - 1 - Clean - Pillow 02', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Clean - Pillow 02
(258448, 5, 37492, 'Main Chamber - 1 - Clean - Cloth 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Clean - Cloth 01
(258451, 5, 37492, 'Main Chamber - 1 - Clean - Cloth 02', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Clean - Cloth 02
(258449, 5, 37513, 'Main Chamber - 1 - Clean - Pillow 01', '', '', '', 0.9999997, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Clean - Pillow 01
(254689, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(258984, 5, 16497, 'Devilsaur Egg', '', '', '', 2.3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Devilsaur Egg
(255104, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(255100, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(255099, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(255098, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254463, 7, 36542, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(269949, 5, 42371, 'Auction Materials', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Auction Materials
(281340, 10, 10014, 'Warchief''s Command Board', '', '', '', 1, 2824, 0, 0, 0, 0, 0, 0, 0, 0, 0, 261655, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 25996), -- Warchief's Command Board
(243292, 5, 27354, 'Torch', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Torch
(243293, 5, 26917, 'Barricade', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Barricade
(252305, 22, 8111, 'Portal to Dalaran', '', '', '', 1, 221228, -1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal to Dalaran
(258620, 5, 36384, 'Doodad_7nb_nightborn_bazaarbasketset009', '', '', '', 1.01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_bazaarbasketset009
(258603, 5, 36368, 'Doodad_7nb_nightborn_rug017', '', '', '', 1.38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug017
(258561, 5, 36384, 'Doodad_7nb_nightborn_bazaarbasketset004', '', '', '', 1.09, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_bazaarbasketset004
(258558, 5, 34374, 'Doodad_7nb_nightborn_rug005', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug005
(258598, 5, 37501, 'Doodad_7nb_nightborn_crate013', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_crate013
(258597, 5, 35102, 'Doodad_7nb_nightborn_scrollbag002', '', '', '', 0.99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag002
(258602, 5, 36368, 'Doodad_7nb_nightborn_rug019', '', '', '', 2.647061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug019
(258563, 5, 36368, 'Doodad_7nb_nightborn_rug004', '', '', '', 1.76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug004
(258595, 5, 34582, 'Doodad_7nb_nightborn_scrollpile002', '', '', '', 0.99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollpile002
(258569, 5, 34363, 'Doodad_7nb_nightborn_scrollpile001', '', '', '', 0.9899999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollpile001
(258590, 5, 36368, 'Doodad_7nb_nightborn_rug018', '', '', '', 1.38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug018
(258576, 5, 34374, 'Doodad_7nb_nightborn_rug001', '', '', '', 0.8599998, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_rug001
(258580, 5, 35102, 'Doodad_7nb_nightborn_scrollbag006', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag006
(258523, 5, 37490, 'Doodad_7nb_nightborn_basketstack012', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_basketstack012
(258518, 5, 35102, 'Doodad_7nb_nightborn_scrollbag020', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag020
(258537, 5, 37501, 'Doodad_7nb_nightborn_crate012', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_crate012
(258515, 5, 34981, 'Doodad_7nb_nightborn_scrollbag013', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag013
(258509, 5, 37501, 'Doodad_7nb_nightborn_crate008', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_crate008
(258381, 5, 36279, 'Doodad_7nb_nightborn_basketstack009', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_basketstack009
(258502, 5, 37501, 'Doodad_7nb_nightborn_crate007', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_crate007
(258408, 5, 37506, 'Doodad_6hu_enchanting_crystalblue003', '', '', '', 1.36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_6hu_enchanting_crystalblue003
(258407, 5, 37505, 'Doodad_7db_drogbar_crystalblue001', '', '', '', 1.37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7db_drogbar_crystalblue001
(258404, 5, 37504, 'Doodad_6br_goren_crystal_blue002', '', '', '', 0.6899999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_6br_goren_crystal_blue002
(258470, 5, 37501, 'Main Chamber - 4 - Clean - Crate 06', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 4 - Clean - Crate 06
(258359, 5, 37490, 'Doodad_7nb_nightborn_basketstack013', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_basketstack013
(258394, 5, 37501, 'Doodad_7nb_nightborn_crate001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_crate001
(258355, 5, 34367, 'Doodad_7nb_nightborn_benchlong001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_benchlong001
(258352, 5, 34367, 'Doodad_7nb_nightborn_benchlong002', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_benchlong002
(258462, 5, 36542, 'Doodad_7nb_nightborn_benchshort001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_benchshort001
(258458, 5, 36542, 'Doodad_7nb_nightborn_benchshort002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_benchshort002
(258356, 5, 34367, 'Doodad_7nb_nightborn_benchlong003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_benchlong003
(253701, 5, 34363, 'Right Chamber - C - Clean - Scrollpile 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Clean - Scrollpile 02
(253699, 5, 36366, 'Right Chamber - C - Clean - Bookpile 01', '', '', '', 0.78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Clean - Bookpile 01
(258423, 5, 34582, 'Main Chamber - 3 - Clean - Scroll 04', '', '', '', 0.6500005, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 3 - Clean - Scroll 04
(258456, 5, 36542, 'Doodad_7nb_nightborn_benchshort003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_benchshort003
(258389, 5, 37494, 'Doodad_7nb_nightborn_shelf01_empty001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_shelf01_empty001
(253720, 5, 36374, 'Right Chamber - C - Clean - Scroll 01', '', '', '', 0.86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Clean - Scroll 01
(253695, 5, 34582, 'Right Chamber - C - Clean - Scrollpile 03', '', '', '', 0.6700003, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Clean - Scrollpile 03
(258419, 5, 37510, 'Main Chamber - 3 - Clean - Book 03', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 3 - Clean - Book 03
(258388, 5, 34981, 'Doodad_7nb_nightborn_scrollbag016', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_scrollbag016
(258426, 5, 37500, 'Main Chamber - 3 - Clean - Scroll 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 3 - Clean - Scroll 02
(258429, 5, 34726, 'Main Chamber - 3 - Clean - Scroll 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 3 - Clean - Scroll 01
(258453, 5, 36542, 'Doodad_7nb_nightborn_benchshort004', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_benchshort004
(253764, 5, 34880, 'Right Chamber - B - Clean - Cratestack 04', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - B - Clean - Cratestack 04
(253762, 5, 36279, 'Right Chamber - B - Clean - Cratestack 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - B - Clean - Cratestack 02
(253752, 5, 35102, 'Right Chamber - A - Clean - Scrollbag', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - A - Clean - Scrollbag
(258363, 5, 34880, 'Doodad_7nb_nightborn_basketstack002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7nb_nightborn_basketstack002
(258436, 5, 26059, 'Doodad_6hu_blacksmith_paper_002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_6hu_blacksmith_paper_002
(258438, 5, 34371, 'Main Chamber - 2 - Clean - Desk 01', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Desk 01
(258445, 5, 37512, 'Main Chamber - 2 - Clean - Dresser 01', '', '', '', 1.01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Clean - Dresser 01
(258437, 5, 30018, 'Doodad_7af_paladin_map002', '', '', '', 0.7935421, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7af_paladin_map002
(258447, 5, 37490, 'Main Chamber - 1 - Clean - Basketset 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Clean - Basketset 02
(255173, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(265423, 5, 17197, 'Blood Elf Wagon', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blood Elf Wagon
(266191, 5, 39014, 'Black Rook Crates', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Black Rook Crates
(266192, 5, 39013, 'Black Rook Ballista', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996); -- Black Rook Ballista

UPDATE `gameobject_template` SET `name`='Portal to Shal''Aran', `VerifiedBuild`=25996 WHERE `entry`=260263; -- Portal to Shal'Aran
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=209078; -- Lilly Pad
UPDATE `gameobject_template` SET `name`='Tideskorn Cage', `VerifiedBuild`=25996 WHERE `entry`=248581; -- Tideskorn Cage
UPDATE `gameobject_template` SET `name`='Gateway', `VerifiedBuild`=25996 WHERE `entry`=243799; -- Gateway
UPDATE `gameobject_template` SET `name`='Instance Portal', `VerifiedBuild`=25996 WHERE `entry`=252237; -- Instance Portal
UPDATE `gameobject_template` SET `name`='Meeting Stone', `VerifiedBuild`=25996 WHERE `entry`=252332; -- Meeting Stone
UPDATE `gameobject_template` SET `name`='Meeting Stone', `VerifiedBuild`=25996 WHERE `entry`=255345; -- Meeting Stone
UPDATE `gameobject_template` SET `type`=10, `displayId`=39530, `Data13`=1, `VerifiedBuild`=25996 WHERE `entry`=266890; -- Light Ray
UPDATE `gameobject_template` SET `type`=10, `displayId`=39529, `Data13`=1, `VerifiedBuild`=25996 WHERE `entry`=266889; -- Light Ray
UPDATE `gameobject_template` SET `type`=10, `displayId`=38979, `Data13`=1, `VerifiedBuild`=25996 WHERE `entry`=265596; -- Ritual Stone
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266845; -- Doodad_7du_valhalla_door001
UPDATE `gameobject_template` SET `type`=3, `displayId`=8685, `size`=2, `Data0`=1634, `Data1`=70585, `Data3`=1, `Data10`=1, `Data11`=1, `Data12`=1, `Data13`=1, `Data15`=1, `Data20`=100, `Data25`=1958, `Data27`=1, `Data30`=70673, `Data32`=2, `VerifiedBuild`=25996 WHERE `entry`=260526; -- Spoils
UPDATE `gameobject_template` SET `name`='Refreshment Table', `VerifiedBuild`=25996 WHERE `entry`=233282; -- Refreshment Table
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246433; -- Hearty Feast
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=253130; -- Instance Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181621; -- Soulwell
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250581; -- Nightborn Chest
UPDATE `gameobject_template` SET `type`=50, `displayId`=33264, `IconName`='openhand', `size`=1.25, `Data0`=43, `Data1`=68493, `Data6`=120, `Data12`=105, `Data15`=1, `Data17`=1630, `Data18`=5, `Data19`=1, `VerifiedBuild`=25996 WHERE `entry`=254001; -- Misplaced Chest
UPDATE `gameobject_template` SET `type`=3, `displayId`=34692, `IconName`='questinteract', `size`=3, `Data0`=2412, `Data30`=66866, `VerifiedBuild`=25996 WHERE `entry`=251641; -- Suramar Leyline Map
UPDATE `gameobject_template` SET `name`='Instance Portal', `VerifiedBuild`=25996 WHERE `entry`=252247; -- Instance Portal
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258163; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258162; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258161; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258160; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=191605; -- Portable Mailbox
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255123; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255103; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255102; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255097; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255052; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255056; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255095; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255074; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255070; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255075; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255062; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255155; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255084; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255079; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255078; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255076; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255072; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255051; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254351; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255091; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255082; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255068; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255065; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255059; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255058; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255053; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254348; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266354; -- Basic Campfire
UPDATE `gameobject_template` SET `Data1`=62218, `Data6`=30, `VerifiedBuild`=25996 WHERE `entry`=244775; -- Dreamleaf
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=242644; -- Treasure Chest
UPDATE `gameobject_template` SET `castBarCaption`='Examining', `VerifiedBuild`=25996 WHERE `entry`=249356; -- Altar of Malorne
UPDATE `gameobject_template` SET `name`='Totem', `VerifiedBuild`=25996 WHERE `entry`=249853; -- Totem
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=242678; -- Treasure Chest
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=243322; -- Guardian Stone
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=240608; -- Small Treasure Chest
UPDATE `gameobject_template` SET `name`='rock', `VerifiedBuild`=25996 WHERE `entry`=246153; -- rock
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266416; -- Mailbox
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=242346; -- Small Treasure Chest
UPDATE `gameobject_template` SET `castBarCaption`='Preparing', `VerifiedBuild`=25996 WHERE `entry`=251271; -- Shriektalon Totem
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=186238; -- Zeppelin, Horde (The Mighty Wind)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207642; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204716; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204715; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207645; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204718; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204717; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204712; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204711; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207107; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204692; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204703; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204683; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207639; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204682; -- Brazier
UPDATE `gameobject_template` SET `name`='Portal to Honeydew Village', `Data3`=1, `Data5`=923, `VerifiedBuild`=25996 WHERE `entry`=215424; -- Portal to Honeydew Village
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204705; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180759; -- Orc Hero Portrait
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204714; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207637; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204713; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180775; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180767; -- Lantern
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207640; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=205108; -- Guild Vault
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204702; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204638; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206787; -- Lantern (Scale 2)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207638; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=205142; -- Generic Human Chair Low End - Prop (Unusable)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=205109; -- Guild Vault
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204685; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204637; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=187376; -- NPC Fishing Bobber
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207636; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204701; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202805; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206965; -- Banner (Scale 1.5)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202803; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204684; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204636; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204635; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204614; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204618; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204616; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204681; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204938; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204615; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204617; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204619; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=195222; -- Stage
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204936; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=208269; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204612; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=208270; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202809; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=193981; -- Lexicon of Power
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204694; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204707; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204937; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207631; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202808; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204613; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204708; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204680; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=209049; -- Shady Lady Croc
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=209050; -- Shady Lady Falcon
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202817; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204706; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=209045; -- Shady Lady Figurine
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204941; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204698; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207632; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204940; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202816; -- Brazier
UPDATE `gameobject_template` SET `Data5`=37428, `VerifiedBuild`=25996 WHERE `entry`=207686; -- Portal to Twilight Highlands
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197259; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202813; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202814; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202811; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197261; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202815; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202812; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=208054; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204678; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204679; -- Brazier
UPDATE `gameobject_template` SET `Data5`=923, `VerifiedBuild`=25996 WHERE `entry`=206595; -- Portal to Tol Barad
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197260; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202810; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206740; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=237942; -- Engraved Stone Plaque
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204643; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207635; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204699; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=207634; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204726; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204700; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=50805; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=50803; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3301; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204689; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180761; -- Tauren Hero Portrait
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=50804; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=205091; -- Guild Vault
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=205090; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204727; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204688; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206739; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206738; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204721; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206909; -- Banner (Scale 1.5)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204719; -- Brazier
UPDATE `gameobject_template` SET `Data2`=7810, `VerifiedBuild`=25996 WHERE `entry`=207149; -- Barbershop Chair
UPDATE `gameobject_template` SET `Data2`=7810, `VerifiedBuild`=25996 WHERE `entry`=207148; -- Barbershop Chair
UPDATE `gameobject_template` SET `Data2`=7810, `VerifiedBuild`=25996 WHERE `entry`=207147; -- Barbershop Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204626; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206735; -- Mailbox
UPDATE `gameobject_template` SET `name`='[DNT] Command Table Collision Cylinder' WHERE `entry`=259114; -- [DNT] Command Table Collision Cylinder
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204621; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206733; -- Mailbox
UPDATE `gameobject_template` SET `Data2`=7810, `VerifiedBuild`=25996 WHERE `entry`=207150; -- Barbershop Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=237738; -- Portal to Ashran
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204198; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204628; -- Torch
UPDATE `gameobject_template` SET `Data2`=7810, `VerifiedBuild`=25996 WHERE `entry`=207146; -- Barbershop Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204605; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204194; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204640; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175787; -- Unadorned Stake
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204724; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204723; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204722; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204720; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204725; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204610; -- Grommash Throne
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175788; -- Unadorned Stake
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204197; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=175080; -- Zeppelin (The Iron Eagle)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=164871; -- Zeppelin (The Thundercaller)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=223739; -- The Gates of Orgrimmar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=223814; -- Doodad_OGRaid_FrontGate_Back
UPDATE `gameobject_template` SET `Data1`=-1, `VerifiedBuild`=25996 WHERE `entry`=207414; -- Waters of Farseeing
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=210181; -- Deathwing Trophy (0.7)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206110; -- Portal to Moonglade
UPDATE `gameobject_template` SET `name`='Ward', `VerifiedBuild`=25996 WHERE `entry`=243301; -- Ward
UPDATE `gameobject_template` SET `name`='Tent', `VerifiedBuild`=25996 WHERE `entry`=243332; -- Tent
UPDATE `gameobject_template` SET `name`='Rug', `VerifiedBuild`=25996 WHERE `entry`=253169; -- Rug
UPDATE `gameobject_template` SET `name`='Weapon Rack', `VerifiedBuild`=25996 WHERE `entry`=243294; -- Weapon Rack
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206609; -- Elevator
UPDATE `gameobject_template` SET `name`='Book', `VerifiedBuild`=25996 WHERE `entry`=245923; -- Book
UPDATE `gameobject_template` SET `name`='Tent', `VerifiedBuild`=25996 WHERE `entry`=243296; -- Tent
UPDATE `gameobject_template` SET `name`='Scrying Bowl', `VerifiedBuild`=25996 WHERE `entry`=243298; -- Scrying Bowl
UPDATE `gameobject_template` SET `name`='Rug', `VerifiedBuild`=25996 WHERE `entry`=254068; -- Rug
UPDATE `gameobject_template` SET `name`='Table', `VerifiedBuild`=25996 WHERE `entry`=243324; -- Table
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=243333; -- Stool
UPDATE `gameobject_template` SET `name`='Weapon Rack', `VerifiedBuild`=25996 WHERE `entry`=243295; -- Weapon Rack
UPDATE `gameobject_template` SET `name`='Supplies', `VerifiedBuild`=25996 WHERE `entry`=252281; -- Supplies
UPDATE `gameobject_template` SET `name`='Crate', `VerifiedBuild`=25996 WHERE `entry`=243300; -- Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=243302; -- Trap
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206741; -- Mailbox
UPDATE `gameobject_template` SET `name`='Banner', `VerifiedBuild`=25996 WHERE `entry`=243299; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180770; -- Lights
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206608; -- Elevator
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204606; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204608; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206732; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204200; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206736; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204607; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204205; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206610; -- Elevator
UPDATE `gameobject_template` SET `Data1`=30021, `VerifiedBuild`=25996 WHERE `entry`=203969; -- Prickly Pear Fruit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206730; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197257; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197207; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197309; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197310; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204191; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204196; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204192; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=180769; -- Lights
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197307; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197315; -- Meeting Stone
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206729; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=202717; -- Brazier
UPDATE `gameobject_template` SET `name`='Portal to Hellfire Peninsula', `VerifiedBuild`=25996 WHERE `entry`=195142; -- Portal to Hellfire Peninsula
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197314; -- Darkfire Enclave
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204195; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197313; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197276; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206547; -- Rekkul's Poisons
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197311; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197286; -- Shadowdeep Reagents
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197278; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197285; -- Brazier
UPDATE `gameobject_template` SET `name`='Portal to Dalaran', `VerifiedBuild`=25996 WHERE `entry`=254292; -- Portal to Dalaran
UPDATE `gameobject_template` SET `name`='Collision PC Size', `VerifiedBuild`=25996 WHERE `entry`=216056; -- Collision PC Size
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=212212; -- Legacy of the Masters (Part 1)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206549; -- Shadowswift Brotherhood
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206548; -- Ironwood Staves and Wands
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=105576; -- Summoning Circle
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197312; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197280; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197279; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206529; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197322; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206530; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197284; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206538; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197287; -- Dark Earth
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206545; -- The Slow Blade
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204632; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204631; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206539; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204634; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=204633; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=235877; -- Portal to Blasted Lands
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=197323; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=206546; -- Arcane Enclave
UPDATE `gameobject_template` SET `name`='Portal to Sanctum of Light', `VerifiedBuild`=25996 WHERE `entry`=251305; -- Portal to Sanctum of Light
UPDATE `gameobject_template` SET `name`='Doodad_7dl_dalaran_chair002', `VerifiedBuild`=25996 WHERE `entry`=260236; -- Doodad_7dl_dalaran_chair002
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=259391; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=259392; -- Stool
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259395; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259393; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259394; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242229; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242230; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Portal to Shal''Aran', `VerifiedBuild`=25996 WHERE `entry`=260268; -- Portal to Shal'Aran
UPDATE `gameobject_template` SET `name`='Telemancy Beacon', `VerifiedBuild`=25996 WHERE `entry`=253393; -- Telemancy Beacon
UPDATE `gameobject_template` SET `name`='Teleporter', `VerifiedBuild`=25996 WHERE `entry`=253134; -- Teleporter
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255140; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255141; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255134; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255120; -- Bench
UPDATE `gameobject_template` SET `type`=3, `displayId`=33265, `castBarCaption`='Opening', `Data0`=57, `Data2`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data29`=1598, `Data30`=67976, `RequiredLevel`=110, `VerifiedBuild`=25996 WHERE `entry`=252880; -- Treasure Chest
UPDATE `gameobject_template` SET `Data3`=0, `Data20`=1, `VerifiedBuild`=25996 WHERE `entry`=251493; -- Shadefruit
UPDATE `gameobject_template` SET `Data3`=0, `Data20`=1, `VerifiedBuild`=25996 WHERE `entry`=251492; -- Purified Water
UPDATE `gameobject_template` SET `name`='Manafruit Extractor', `VerifiedBuild`=25996 WHERE `entry`=251475; -- Manafruit Extractor
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255898; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255897; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255112; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255158; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255007; -- Bench
UPDATE `gameobject_template` SET `name`='Infused Arcwine', `VerifiedBuild`=25996 WHERE `entry`=251566; -- Infused Arcwine
UPDATE `gameobject_template` SET `name`='Right Chamber - J - Clean - Scrollpile 02', `VerifiedBuild`=25996 WHERE `entry`=253774; -- Right Chamber - J - Clean - Scrollpile 02
UPDATE `gameobject_template` SET `name`='Right Chamber - J - Clean - Book', `VerifiedBuild`=25996 WHERE `entry`=253772; -- Right Chamber - J - Clean - Book
UPDATE `gameobject_template` SET `name`='Right Chamber - J - Clean - Scrollopen', `VerifiedBuild`=25996 WHERE `entry`=253775; -- Right Chamber - J - Clean - Scrollopen
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Clean - Scrollbag 02', `VerifiedBuild`=25996 WHERE `entry`=253732; -- Right Chamber - E - Clean - Scrollbag 02
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Clean - Bookshelf 02', `VerifiedBuild`=25996 WHERE `entry`=253712; -- Right Chamber - E - Clean - Bookshelf 02
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Clean - Bookcase 03', `VerifiedBuild`=25996 WHERE `entry`=253714; -- Right Chamber - E - Clean - Bookcase 03
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Clean - Bookshelf 01', `VerifiedBuild`=25996 WHERE `entry`=253713; -- Right Chamber - E - Clean - Bookshelf 01
UPDATE `gameobject_template` SET `name`='Right Chamber - K - Clean - Scrollopen', `VerifiedBuild`=25996 WHERE `entry`=253718; -- Right Chamber - K - Clean - Scrollopen
UPDATE `gameobject_template` SET `name`='Right Chamber - K - Clean - quillink', `VerifiedBuild`=25996 WHERE `entry`=253723; -- Right Chamber - K - Clean - quillink
UPDATE `gameobject_template` SET `name`='Right Chamber - K - Clean - Book', `VerifiedBuild`=25996 WHERE `entry`=253721; -- Right Chamber - K - Clean - Book
UPDATE `gameobject_template` SET `name`='Doodad_7sr_hubmanatree005', `VerifiedBuild`=25996 WHERE `entry`=265462; -- Doodad_7sr_hubmanatree005
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258206; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258205; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258204; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258120; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258119; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258118; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258188; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258117; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258116; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258136; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258137; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258133; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258139; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258135; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258134; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258142; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258141; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258140; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258132; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258131; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254282; -- Frozen Friends
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254280; -- Frozen Friends
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254284; -- Frozen Friends
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254283; -- Misty Monsters
UPDATE `gameobject_template` SET `name`='Spilled Arcwine', `VerifiedBuild`=25996 WHERE `entry`=254069; -- Spilled Arcwine
UPDATE `gameobject_template` SET `name`='Arcwine Barrel', `VerifiedBuild`=25996 WHERE `entry`=254067; -- Arcwine Barrel
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251626; -- Thousand-Year Arcwine
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254286; -- Aquatic Wonders
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254285; -- Aquatic Wonders
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255008; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258014; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255009; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254287; -- Desolate Deserts
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258029; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258028; -- Bench
UPDATE `gameobject_template` SET `type`=3, `displayId`=33264, `castBarCaption`='Opening', `Data0`=57, `Data2`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data29`=1597, `Data30`=67975, `RequiredLevel`=110, `VerifiedBuild`=25996 WHERE `entry`=252876; -- Small Treasure Chest
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255114; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255113; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255130; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255131; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255129; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255128; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258016; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258015; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258020; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258022; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258018; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258017; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258021; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258019; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252883; -- Treasure Chest
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255047; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255146; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255145; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255144; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255127; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255126; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255175; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255174; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255125; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255124; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255181; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255180; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255179; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255178; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255177; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255176; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255106; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255105; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255027; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255026; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255030; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255023; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255022; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Placing seal.', `VerifiedBuild`=25996 WHERE `entry`=252779; -- Arcway Outlet
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258192; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258191; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258190; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258189; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258184; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258147; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258146; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258145; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258076; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258075; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258074; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258030; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258025; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255025; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255021; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255020; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255019; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255187; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258198; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258197; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258196; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258195; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258194; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258193; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258183; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258182; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258172; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258171; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258170; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258166; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258165; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258164; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258033; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258032; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258031; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258013; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255029; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255028; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255024; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255018; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255017; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255016; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255015; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255014; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255013; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255012; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255011; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255010; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266663; -- Duskwatch Scrying Orb
UPDATE `gameobject_template` SET `Data3`=0, `Data20`=1, `VerifiedBuild`=25996 WHERE `entry`=251494; -- Silver Jasmine
UPDATE `gameobject_template` SET `name`='Collision PC Size x2.5', `VerifiedBuild`=25996 WHERE `entry`=230609; -- Collision PC Size x2.5
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255048; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255043; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255039; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255116; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255115; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255119; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255117; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255138; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255118; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255136; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255137; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255139; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255135; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Inspecting', `VerifiedBuild`=25996 WHERE `entry`=247615; -- Crown of Mavrana Mooncrest
UPDATE `gameobject_template` SET `name`='Crown Pillar', `VerifiedBuild`=25996 WHERE `entry`=247614; -- Crown Pillar
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255049; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255038; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255169; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255165; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255170; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255168; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255045; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255042; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Placing seal.', `VerifiedBuild`=25996 WHERE `entry`=252783; -- Arcway Outlet
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255172; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255166; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255171; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255167; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255162; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255161; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255160; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255046; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255044; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255041; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255040; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255005; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255003; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255006; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255004; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252881; -- Treasure Chest
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255164; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255110; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255002; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252882; -- Treasure Chest
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255182; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255032; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255031; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255033; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255034; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255037; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255036; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255035; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255163; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255109; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255111; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255122; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255094; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255149; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255151; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255153; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255071; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255066; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255152; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255087; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255069; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255092; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255055; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255156; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255054; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255060; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255067; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255150; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255081; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255050; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255090; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255157; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255093; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254350; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255154; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255064; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255096; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254353; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255073; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254349; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254373; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254347; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255086; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255077; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255088; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255085; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266850; -- Teleporter Pad
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255057; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255061; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255063; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255089; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255083; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=255080; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258125; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254352; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258138; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254360; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254367; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254368; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258126; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258124; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258127; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258123; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258128; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258122; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258143; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254361; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254371; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254359; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254366; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254357; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254363; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254358; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254356; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254355; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254365; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254364; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254354; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254372; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254461; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254455; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254370; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254362; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254341; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254456; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254343; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254339; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254466; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254462; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254344; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254460; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254459; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254458; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254457; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254369; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254346; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254342; -- Bench
UPDATE `gameobject_template` SET `name`='Portal to Shal''Aran', `VerifiedBuild`=25996 WHERE `entry`=260269; -- Portal to Shal'Aran
UPDATE `gameobject_template` SET `name`='Portal to Twilight Vineyards', `VerifiedBuild`=25996 WHERE `entry`=254139; -- Portal to Twilight Vineyards
UPDATE `gameobject_template` SET `name`='Portal to Felsoul Hold', `VerifiedBuild`=25996 WHERE `entry`=254131; -- Portal to Felsoul Hold


UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=251641 AND `Idx`=0); -- Suramar Leyline Map
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=203969 AND `Idx`=0); -- Prickly Pear Fruit

DELETE FROM `npc_text` WHERE `ID` IN (29996 /*29996*/, 30698 /*30698*/, 27923 /*27923*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(29996, 1, 0, 0, 0, 0, 0, 0, 0, 119956, 0, 0, 0, 0, 0, 0, 0, 25996), -- 29996
(30698, 1, 0, 0, 0, 0, 0, 0, 0, 123260, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30698
(27923, 1, 0, 0, 0, 0, 0, 0, 0, 102706, 0, 0, 0, 0, 0, 0, 0, 25996); -- 27923

UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29001; -- 29001
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29909; -- 29909
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29891; -- 29891
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29890; -- 29890
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29892; -- 29892
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14014; -- 14014
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=30491; -- 30491
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29209; -- 29209
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29210; -- 29210
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=29208; -- 29208
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=580; -- 580
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=30287; -- 30287

