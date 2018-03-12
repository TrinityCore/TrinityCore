SET @CGUID := 21003200;
SET @OGUID := 21001300;

UPDATE areatrigger SET ScriptName = "" WHERE guid IN (34, 35);
DELETE FROM areatrigger_teleport WHERE ID IN (-34, -35);
INSERT INTO areatrigger_teleport VALUES
(-34, 5889, "Tomb of Sargeras entrance"),
(-35, 5890, "Tomb of Sargeras exit");

DELETE FROM `instance_template` WHERE `map` = 1676;
INSERT INTO `instance_template` VALUES
(1676, 1220, "instance_tomb_of_sargeras", 0, 1);

DELETE FROM `areatrigger_template` WHERE `Id` IN (16572, 13360, 13368, 14871, 13369, 15104, 16713, 13347, 15039, 15099, 13251, 15307, 15235, 13412, 15152);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(16572, 0, 0, 2.5, 2.5, 0, 0, 0, 0, 25961),
(13360, 0, 4, 10, 10, 0, 0, 0, 0, 25961),
(13368, 0, 4, 23, 23, 0, 0, 0, 0, 25961),
(14871, 0, 0, 200, 200, 0, 0, 0, 0, 25961),
(13369, 0, 0, 5, 5, 0, 0, 0, 0, 25961),
(15104, 3, 0, 0, 0, 0, 0, 0, 0, 25961),
(16713, 4, 0, 6, 6, 4, 4, 0.3, 0.3, 25961),
(13347, 4, 4, 4.3, 4.3, 50, 50, 3, 3, 25961),
(15039, 0, 0, 7.5, 7.5, 0, 0, 0, 0, 25961),
(15099, 0, 4, 4, 4, 0, 0, 0, 0, 25961),
(13251, 0, 0, 6, 6, 0, 0, 0, 0, 25961),
(15307, 0, 0, 15, 15, 0, 0, 0, 0, 25961),
(15235, 0, 4, 3, 3, 0, 0, 0, 0, 25961),
(13412, 4, 0, 6, 6, 10, 10, 0.3, 0.3, 25961),
(15152, 0, 4, 20, 20, 0, 0, 0, 0, 25961);

UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=11908;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=8352;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=10698;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `Data0`=6, `Data1`=6, `VerifiedBuild`=25961 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=11721;
UPDATE `areatrigger_template` SET `Data0`=8, `Data1`=8, `VerifiedBuild`=25961 WHERE `Id`=5802;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=5300;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=5302;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=10470;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=2947;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=11833;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=6870;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=10529;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=11513;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=9110;
UPDATE `areatrigger_template` SET `Data0`=4.025391, `Data1`=4.025391, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=6197;
UPDATE `areatrigger_template` SET `Data0`=4.025146, `Data1`=4.025146, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Data0`=4.02832, `Data1`=4.02832, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=13677;
UPDATE `areatrigger_template` SET `Data0`=4.026123, `Data1`=4.026123, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Flags`=2, `VerifiedBuild`=25961 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `Type`=0, `Flags`=4, `Data0`=15, `Data1`=15, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0, `VerifiedBuild`=25961 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=3153;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=10133;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=11203;
UPDATE `areatrigger_template` SET `Data0`=4.228027, `Data1`=4.228027, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Data0`=4.015381, `Data1`=4.015381, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=9181;
UPDATE `areatrigger_template` SET `Data0`=4.102539, `Data1`=4.102539, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Data0`=4.066895, `Data1`=4.066895, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Data0`=4.116211, `Data1`=4.116211, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Data0`=4.117188, `Data1`=4.117188, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Data0`=4.117432, `Data1`=4.117432, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Data0`=4.123047, `Data1`=4.123047, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Data0`=4.123535, `Data1`=4.123535, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Data0`=4.11377, `Data1`=4.11377, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Data0`=4.045166, `Data1`=4.045166, `VerifiedBuild`=25961 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=10727;

DELETE FROM `spell_areatrigger` WHERE `SpellMiscId`=4488 OR (`SpellMiscId`=11883 AND `AreaTriggerId`=16572) OR (`SpellMiscId`=9368 AND `AreaTriggerId`=13360) OR (`SpellMiscId`=9980 AND `AreaTriggerId`=14871) OR (`SpellMiscId`=10915 AND `AreaTriggerId`=13368) OR (`SpellMiscId`=9377 AND `AreaTriggerId`=13369) OR (`SpellMiscId`=1489 AND `AreaTriggerId`=5802) OR (`SpellMiscId`=10231 AND `AreaTriggerId`=15104) OR (`AreaTriggerId`=5300) OR (`AreaTriggerId`=5302) OR (`SpellMiscId`=12002 AND `AreaTriggerId`=16713) OR (`SpellMiscId`=2329 AND `AreaTriggerId`=6870) OR (`SpellMiscId`=4366 AND `AreaTriggerId`=9110) OR (`SpellMiscId`=9606 AND `AreaTriggerId`=13347) OR (`SpellMiscId`=10170 AND `AreaTriggerId`=15039) OR (`SpellMiscId`=10641 AND `AreaTriggerId`=0) OR (`SpellMiscId`=10234 AND `AreaTriggerId`=15099) OR (`SpellMiscId`=9230 AND `AreaTriggerId`=13251) OR (`SpellMiscId`=10450 AND `AreaTriggerId`=15307) OR (`SpellMiscId`=10373 AND `AreaTriggerId`=15235) OR (`SpellMiscId`=9417 AND `AreaTriggerId`=13412) OR (`SpellMiscId`=10235 AND `AreaTriggerId`=15099) OR (`SpellMiscId`=10224 AND `AreaTriggerId`=15099) OR (`SpellMiscId`=10227 AND `AreaTriggerId`=15099) OR (`SpellMiscId`=10225 AND `AreaTriggerId`=15099) OR `SpellMiscId`=10279;
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(4488, 9228, 0, 0, 0, 0, 0, 0, 7856, 25961), -- SpellId : 26573
(11883, 16572, 0, 0, 0, 0, 0, 0, 15000, 25961), -- SpellId : 253320
(9368, 13360, 0, 0, 0, 0, 0, 0, 0, 25961), -- SpellId : 232884
(9980, 14871, 0, 0, 0, 0, 0, 0, 600000, 25961), -- SpellId : 232745
(10915, 13368, 0, 0, 0, 0, 0, 0, 0, 25961), -- SpellId : 232886
(9377, 13369, 0, 0, 0, 0, 0, 0, 120000, 25961), -- SpellId : 232905
(1489, 5802, 0, 0, 0, 0, 0, 0, 10000, 25961), -- SpellId : 62618
(10231, 15104, 0, 0, 0, 0, 149, 0, 7000, 25961), -- SpellId : 240759
(1315, 5300, 392, 0, 0, 0, 0, 1550, 1000, 25961), -- SpellId : 123986
(1316, 5302, 393, 0, 0, 0, 0, 1550, 1000, 25961), -- SpellId : 123986
(12002, 16713, 0, 0, 0, 0, 0, 0, 6000, 25961), -- SpellId : 256820
(2329, 6870, 0, 0, 0, 0, 0, 0, 60000, 25961), -- SpellId : 161642
(4366, 9110, 0, 0, 0, 0, 0, 1428, 1750, 25961), -- SpellId : 186775
(9606, 13347, 0, 0, 0, 0, 0, 0, 0, 25961), -- SpellId : 234809
(10170, 15039, 0, 0, 0, 0, 0, 0, 12000, 25961), -- SpellId : 240173
(10641, 0, 0, 0, 0, 0, 169, 0, 3999, 25961), -- SpellId : 244554
(10234, 15099, 0, 0, 0, 0, 150, 0, 0, 25961), -- SpellId : 240822
(9230, 13251, 0, 0, 0, 0, 187, 0, 600000, 25961), -- SpellId : 231754
(10450, 15307, 0, 0, 0, 0, 0, 0, 0, 25961), -- SpellId : 243002
(10373, 15235, 0, 0, 0, 0, 0, 0, 599999, 25961), -- SpellId : 233019
(9417, 13412, 0, 0, 0, 0, 0, 796, 10000, 25961), -- SpellId : 233279
(10235, 15099, 0, 0, 0, 0, 150, 0, 0, 25961), -- SpellId : 240825
(10224, 15099, 0, 0, 0, 0, 150, 0, 0, 25961), -- SpellId : 240700
(10227, 15099, 0, 0, 0, 0, 150, 0, 0, 25961), -- SpellId : 240705
(10225, 15099, 0, 0, 0, 0, 150, 0, 0, 25961), -- SpellId : 240704
(10279, 15152, 0, 0, 0, 0, 0, 0, 0, 25961); -- SpellId : 241186

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=7478 AND `AreaTriggerId`=11908); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=3680 AND `AreaTriggerId`=8352); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=6006 AND `AreaTriggerId`=10698); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5179, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5308, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2800, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=7267 AND `AreaTriggerId`=11721); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=62947, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1730, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3201, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5355, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=7385 AND `AreaTriggerId`=11833); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6732, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6880, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3082, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6839, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3319, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=94772, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3446, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5823 AND `AreaTriggerId`=10529); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=14000, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=7044 AND `AreaTriggerId`=11513); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2249, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6900, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6962, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6485, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5000, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8284 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5000, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=6026 AND `AreaTriggerId`=10713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6623, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6869, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3095, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6513, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=61233, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6931, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2953, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1525, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6834, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1799, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5758 AND `AreaTriggerId`=10470); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2939, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2882, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=337 AND `AreaTriggerId`=3153); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7219, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=66370, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=6615 AND `AreaTriggerId`=11203); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2810, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6774, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2809, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2801, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2807, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2826, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6918, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5292, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2929, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4093, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5261, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2803, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1071, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=56571, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2802, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2289, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2837, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3199, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1000, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=6039 AND `AreaTriggerId`=10727); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=4951 AND `Idx`=2) OR (`ConversationId`=4951 AND `Idx`=1) OR (`ConversationId`=4951 AND `Idx`=0) OR (`ConversationId`=4963 AND `Idx`=0) OR (`ConversationId`=4963 AND `Idx`=1) OR (`ConversationId`=4810 AND `ConversationActorId`=57712 AND `Idx`=0) OR (`ConversationId`=4808 AND `ConversationActorId`=57715 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
-- (4951, UNKNOWN, 2, 25961), -- Full: 0x0
-- (4951, UNKNOWN, 1, 25961), -- Full: 0x203098D18074EAC0001D7C000079A253 Creature/0 R3110/S7548 Map: Tombe de Sargeras Entry: 119723 (Image of Aegwynn) Low: 7971411
-- (4951, UNKNOWN, 0, 25961), -- Full: 0x0
-- (4963, UNKNOWN, 0, 25961), -- Full: 0x203098D180765800001D7C000079A102 Creature/0 R3110/S7548 Map: Tombe de Sargeras Entry: 121184 (Mistress Sassz'ine) Low: 7971074
-- (4963, UNKNOWN, 1, 25961), -- Full: 0x203098D18071ADC0001D7C000079A102 Creature/0 R3110/S7548 Map: Tombe de Sargeras Entry: 116407 (Harjatan) Low: 7971074
(4810, 57712, 0, 25961),
(4808, 57715, 0, 25961);


DELETE FROM `conversation_actor_template` WHERE `Id` IN (57712, 57715);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(57712, 119723, 76079, 25961),
(57715, 119729, 75059, 25961);


DELETE FROM `conversation_line_template` WHERE `Id` IN (10990, 10989, 10988, 10987, 10986, 10985, 11045, 11044, 11043, 10734, 10732);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(10990, 54789, 0, 2, 0, 25961),
(10989, 51815, 0, 2, 0, 25961),
(10988, 35648, 0, 1, 0, 25961),
(10987, 21324, 0, 1, 0, 25961),
(10986, 6977, 0, 1, 0, 25961),
(10985, 0, 0, 0, 0, 25961),
(11045, 10466, 2470368736, 0, 0, 25961),
(11044, 5634, 2470368736, 1, 0, 25961),
(11043, 0, 2470368736, 0, 0, 25961),
(10734, 0, 84, 0, 0, 25961),
(10732, 0, 296, 0, 0, 25961);


DELETE FROM `conversation_template` WHERE `Id` IN (4810, 4963, 4808, 4951);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(4810, 10734, 13832, 25961),
(4963, 11043, 14287, 25961),
(4808, 10732, 17513, 25961),
(4951, 10985, 65119, 25961);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (266938 /*Pointe infernale*/, 269257 /*Rune orque*/, 269779 /*269779*/, 269260 /*Rune orque*/, 269258 /*Rune orque*/, 269987 /*Doodad_7DU_TombOfSargeras_Felstorm_Collision001*/, 267708 /*267708*/, 267710 /*267710*/, 267711 /*267711*/, 267704 /*267704*/, 267705 /*267705*/, 267706 /*267706*/, 267700 /*267700*/, 267702 /*267702*/, 267703 /*267703*/, 267720 /*267720*/, 267721 /*267721*/, 267723 /*267723*/, 267716 /*267716*/, 267717 /*267717*/, 267718 /*267718*/, 267719 /*267719*/, 267712 /*267712*/, 267713 /*267713*/, 267714 /*267714*/, 267715 /*267715*/, 269988 /*Doodad_7DU_TombOfSargeras_Felstorm_Collision002*/, 268748 /*Door*/, 268749 /*Door*/, 268751 /*Door*/, 267934 /*267934*/, 269780 /*269780*/, 269781 /*Barrière fantomatique*/, 269782 /*269782*/, 268580 /*Door*/, 268579 /*Door*/, 267709 /*267709*/, 267707 /*267707*/, 267701 /*267701*/, 272384 /*272384*/, 272385 /*272385*/, 272386 /*272386*/, 267724 /*267724*/, 267722 /*267722*/, 269976 /*Door d’eau*/, 269261 /*Doors du caveau*/, 269262 /*Doors du caveau*/, 268819 /*Door*/, 268750 /*Door*/, 269842 /*269842*/, 268365 /*Door*/, 268366 /*Door*/, 269164 /*Autel*/, 270940 /*Door*/, 269045 /*Barrière*/, 269975 /*Doodad_7DU_TombofSargeras_FireDoor01*/, 269839 /*269839*/, 268364 /*Door*/, 268514 /*Door*/, 272802 /*272802*/, 269838 /*269838*/, 268752 /*Door*/, 269973 /*Doodad_6FX_Firewall_DoorSMFel001*/, 269120 /*Door de la maîtresse*/, 269974 /*Doodad_6FX_Firewall_DoorSMFel002*/, 269259 /*Rune orque*/, 269192 /*Door d’entrée*/, 269256 /*Rune orque*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(266938, 14, 32), -- Pointe infernale
(269257, 0, 16), -- Rune orque
(269779, 0, 48), -- 269779
(269260, 0, 16), -- Rune orque
(269258, 0, 16), -- Rune orque
(269987, 0, 48), -- Doodad_7DU_TombOfSargeras_Felstorm_Collision001
(267708, 0, 1048624), -- 267708
(267710, 0, 1048624), -- 267710
(267711, 0, 1048624), -- 267711
(267704, 0, 1048624), -- 267704
(267705, 0, 1048624), -- 267705
(267706, 0, 1048624), -- 267706
(267700, 0, 1048624), -- 267700
(267702, 0, 1048624), -- 267702
(267703, 0, 1048608), -- 267703
(267720, 0, 1048624), -- 267720
(267721, 0, 1048624), -- 267721
(267723, 0, 1048624), -- 267723
(267716, 0, 1048624), -- 267716
(267717, 0, 1048624), -- 267717
(267718, 0, 1048624), -- 267718
(267719, 0, 1048624), -- 267719
(267712, 0, 1048624), -- 267712
(267713, 0, 1048624), -- 267713
(267714, 0, 1048624), -- 267714
(267715, 0, 1048624), -- 267715
(269988, 1375, 48), -- Doodad_7DU_TombOfSargeras_Felstorm_Collision002
(268748, 114, 32), -- Door
(268749, 1375, 48), -- Door
(268751, 1375, 48), -- Door
(267934, 0, 1048624), -- 267934
(269780, 0, 48), -- 269780
(269781, 1375, 48), -- Barrière fantomatique
(269782, 0, 48), -- 269782
(268580, 1375, 48), -- Door
(268579, 1375, 32), -- Door
(267709, 0, 1048624), -- 267709
(267707, 0, 1048624), -- 267707
(267701, 0, 1048624), -- 267701
(272384, 0, 48), -- 272384
(272385, 0, 48), -- 272385
(272386, 0, 48), -- 272386
(267724, 0, 1048624), -- 267724
(267722, 0, 1048624), -- 267722
(269976, 1375, 48), -- Door d’eau
(269261, 0, 48), -- Doors du caveau
(269262, 0, 48), -- Doors du caveau
(268819, 0, 32), -- Door
(268750, 0, 32), -- Door
(269842, 0, 48), -- 269842
(268365, 0, 32), -- Door
(268366, 1375, 32), -- Door
(269164, 1375, 32), -- Autel
(270940, 0, 32), -- Door
(269045, 1375, 48), -- Barrière
(269975, 1375, 48), -- Doodad_7DU_TombofSargeras_FireDoor01
(269839, 0, 48), -- 269839
(268364, 1375, 32), -- Door
(268514, 1375, 32), -- Door
(272802, 0, 48), -- 272802
(269838, 0, 48), -- 269838
(268752, 0, 50), -- Door
(269973, 0, 48), -- Doodad_6FX_Firewall_DoorSMFel001
(269120, 0, 48), -- Door de la maîtresse
(269974, 114, 32), -- Doodad_6FX_Firewall_DoorSMFel002
(269259, 0, 16), -- Rune orque
(269192, 0, 48), -- Door d’entrée
(269256, 0, 16); -- Rune orque


DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+318;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5862.79, -787.3524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+1, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5857.272, -787.3524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+2, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5862.79, -784.9167, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+3, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5854.153, -804.4149, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+4, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5857.272, -806.8524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+5, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5857.272, -804.4149, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+6, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5854.153, -806.8524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+7, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5888.283, -797.2257, 2954.382, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+8, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5860.124, -804.4149, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+9, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5862.79, -806.8524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+10, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5876.856, -803.7639, 2954.368, 0.2438955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+11, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5883.807, -796.9496, 2954.368, 0.6418293, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+12, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5854.153, -787.3524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+13, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5882.648, -792.6979, 2954.368, 4.038858, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+14, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5893.361, -798.5382, 2954.41, 1.77362, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+15, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5860.124, -784.9167, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+16, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5892.022, -794.7518, 2954.404, 5.802555, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+17, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5862.79, -804.4149, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+18, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5860.124, -806.8524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+19, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5860.124, -787.3524, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+20, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5854.153, -784.9167, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+21, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5857.272, -784.9167, 2953.176, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+22, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5951.07, -798.2222, 2978.209, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+23, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5939.229, -794.5382, 2978.883, 3.308372, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+24, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5920.638, -797.8663, 2969.74, 0.4126073, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+25, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5885.771, -884.9008, 2924.56, 0.418927, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+26, 117596, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5902.191, -875.428, 2941.079, 5.843959, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Gladiator (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239907 - Lame ruisselante)
(@CGUID+27, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5925.53, -797.1736, 2972.766, 3.308372, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+28, 117596, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5880.107, -882.0306, 2932.294, 4.778452, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Gladiator (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239907 - Lame ruisselante)
(@CGUID+29, 117596, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5876.871, -886.2305, 2932.662, 0.7928628, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Gladiator (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239907 - Lame ruisselante)
(@CGUID+30, 117154, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5899.573, -880.0764, 2920.126, 3.916384, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+31, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5871.432, -900.9549, 2942.946, 5.467842, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+32, 121011, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5896.947, -887.1458, 2919.768, 0.1560399, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidescale Witch (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+33, 117596, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5869.361, -903.4132, 2938.219, 5.904538, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Gladiator (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239907 - Lame ruisselante)
(@CGUID+34, 117154, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5905.499, -885.8559, 2919.587, 3.431125, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+35, 117154, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5903.368, -882.2726, 2919.917, 3.643366, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+36, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5906.289, -793.7708, 2961.23, 1.84227, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+37, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5921.882, -793.6736, 2970.474, 0.964916, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+38, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5898.825, -879.8507, 2941.018, 5.467842, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+39, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5970.369, -847.2823, 2902.94, 4.333325, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+40, 117154, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5901.707, -894.1007, 2919.485, 2.393577, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+41, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5873.786, -902.5903, 2923.797, 6.259804, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+42, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5965.971, -788.0243, 2977.914, 0.9858042, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+43, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5960.486, -803.2292, 2977.906, 5.506678, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+44, 121004, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5910.895, -910.993, 2919.432, 3.980361, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Myrmidon (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+45, 121004, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5915.752, -910.3889, 2919.442, 3.849401, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Myrmidon (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+46, 121004, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5911.549, -906.0695, 2919.438, 4.061642, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Myrmidon (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+47, 116407, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5890.917, -920.1077, 2920.99, 0.3374598, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Harjatan (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 233071 - Armure abrasive)
(@CGUID+48, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5972.427, -797.7205, 2977.917, 0.964916, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+49, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5953.122, -790.507, 2978.21, 3.502233, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+50, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5972.422, -834.3955, 2900.24, 3.379288, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+51, 117154, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5904.164, -890.9514, 2919.491, 2.456405, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Acolyte (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+52, 121004, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5914.783, -915.3871, 2919.451, 4.138361, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Myrmidon (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+53, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6012.292, -758.3177, 2969.823, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+54, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5955.08, -916.1285, 2936.188, 3.325892, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+55, 117123, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5907.119, -917.9184, 2919.438, 0.803481, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidescale Legionnaire (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+56, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5991.408, -839.9396, 2900.35, 3.122722, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+57, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6002.359, -800.7639, 2974.586, 5.690412, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+58, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6000.774, -799.6687, 2974.703, 3.373455, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+59, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6003.479, -789.5625, 2974.586, 1.792414, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+60, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5984.223, -830.281, 2898.957, 1.168648, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+61, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6006.951, -768.4913, 2969.838, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+62, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6004.895, -820.5278, 2969.844, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+63, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6000.279, -787.1024, 2974.871, 3.966526, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+64, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6004.895, -820.5278, 2969.844, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+65, 117596, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5951.976, -902.309, 2935.489, 3.075161, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Gladiator (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239907 - Lame ruisselante)
(@CGUID+66, 121004, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5919.466, -914.8889, 2919.461, 2.874681, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Myrmidon (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+67, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6004.943, -803.0538, 2974.587, 0.6956571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+68, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5998.155, -800.287, 2975.364, 0.2318622, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+69, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5953.905, -907.2292, 2935.649, 3.633401, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+70, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5983.79, -846.8148, 2899.593, 1.550885, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+71, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5984.767, -793.4167, 2978.209, 6.224468, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+72, 117596, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5955.706, -912.217, 2935.682, 3.206546, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Gladiator (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239907 - Lame ruisselante)
(@CGUID+73, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6000.962, -794.3854, 2974.586, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+74, 121184, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5888.364, -936.2222, 2930.175, 0.8030395, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Mistress Sassz'ine (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+75, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6019.319, -750.6094, 2969.823, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+76, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6008.784, -792.0452, 2974.307, 0.3271619, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+77, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6033.625, -779.2493, 2971.56, 6.224216, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+78, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6024.862, -806.1099, 2972.289, 5.810506, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+79, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6011.065, -791.2708, 2973.565, 3.468766, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+80, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6030.049, -769.2691, 2971.456, 0.2585418, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+81, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6037.092, -782.7944, 2971.56, 1.940719, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+82, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6026.324, -804.023, 2971.76, 5.049908, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+83, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6035.603, -822.8073, 2971.456, 6.136105, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+84, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6032.635, -820.1633, 2971.561, 4.657468, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+85, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6008.49, -788.8482, 2974.535, 5.528403, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+86, 119777, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6035.708, -796.4636, 2971.804, 2.978935, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Durgan Roc-Tempête (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+87, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6032.458, -823.3784, 2971.561, 1.515875, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+88, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6025.135, -848.5972, 2969.823, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+89, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6027.537, -807.4777, 2971.959, 2.668914, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+90, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6027.952, -741.9236, 2969.823, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+91, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6029.747, -800.2448, 2971.802, 4.192907, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+92, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6035.308, -766.8058, 2971.56, 0.6889895, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+93, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5957.95, -927.6597, 2936.867, 2.197428, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+94, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6012.994, -836.2066, 2969.823, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+95, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6035.896, -779.7112, 2971.56, 2.940949, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+96, 117596, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5954.607, -923.5364, 2936.71, 4.166272, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Gladiator (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 239907 - Lame ruisselante)
(@CGUID+97, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6060.562, -775.3695, 2971.56, 2.533923, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+98, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6060.458, -798.6788, 2971.804, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+99, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6043.811, -822.1858, 2971.456, 0.491619, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+100, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6037.541, -764.9667, 2971.56, 3.830582, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+101, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6058.706, -774.0784, 2971.56, 5.675516, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+102, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5906.853, -970.7101, 2852.261, 4.240101, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+103, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6041.867, -854.0486, 2969.823, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+104, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6058.344, -829.9254, 2971.448, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+105, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6052.04, -790.3626, 2971.898, 1.038527, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+106, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6058.229, -823.2885, 2971.56, 5.573329, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+107, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6055.779, -800.1649, 2971.804, 6.131253, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+108, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6050.267, -787.6528, 2971.804, 0.2431391, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+109, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6056.355, -825.0137, 2971.56, 0.05167751, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+110, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6053.002, -854.8455, 2969.787, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+111, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6041.21, -736.6424, 2969.823, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+112, 121021, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6060.017, -824.8243, 2971.56, 2.431806, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur lige d'ombre (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+113, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6054.157, -804.704, 2971.976, 1.070853, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+114, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6043.144, -812.2254, 2971.561, 1.969125, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+115, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6053.987, -736.132, 2969.784, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+116, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6060.813, -812.9688, 2971.627, 5.866366, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+117, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6053.731, -787.4905, 2971.935, 4.18016, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+118, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6051.967, -808.8403, 2971.45, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+119, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6037.701, -792.0191, 2971.804, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+120, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6055.675, -801.9248, 2971.847, 1.070824, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+121, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6041.864, -809.1843, 2971.561, 5.110718, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+122, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6069.898, -823.0643, 2971.627, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+123, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5908.267, -976.7525, 2849.142, 5.33582, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+124, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6067.871, -854.5417, 2969.736, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+125, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5900.925, -978.9059, 2853.638, 3.950317, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+126, 119729, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6075.905, -767.0156, 2971.627, 2.161178, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Illidan Hurlorage (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+127, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5926.561, -980.7045, 2846.607, 5.083076, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+128, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6070.026, -841.4012, 2971.511, 2.765768, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+129, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5918.557, -984.905, 2847.791, 3.150614, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+130, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6075.556, -854.3438, 2969.704, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+131, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6078.333, -826.8985, 2971.56, 1.884465, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+132, 121005, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6077.682, -775.4925, 3025.858, 0.9010627, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Dreadwing (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+133, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6066.076, -790.1077, 2971.804, 0.9533232, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+134, 121028, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5973.221, -977.8055, 2953.324, 2.958332, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Cove Seagull (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+135, 121021, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6073.678, -763.6929, 2971.589, 5.30277, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur lige d'ombre (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+136, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6066.892, -735.1667, 2969.811, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+137, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5909.646, -987.2493, 2850.736, 0.0366904, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+138, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6077.533, -824.4313, 2971.56, 5.026116, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+139, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6067.081, -840.2388, 2971.54, 2.765781, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+140, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6079.385, -818.9132, 2972.021, 5.79471, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+141, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6060.893, -854.8021, 2969.763, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+142, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6063.499, -802.3073, 2971.804, 2.092449, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+143, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6089.846, -804.9114, 2971.804, 3.729139, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+144, 121005, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6061.717, -816.2795, 3064.678, 2.073797, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Dreadwing (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+145, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6075.588, -736.1458, 2969.704, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+146, 120482, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5870.193, -1018.128, 2859.399, 1.064018, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidescale Seacaller (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+147, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6087.649, -758.2188, 2971.627, 1.568148, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+148, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6113.585, -758.1024, 2971.627, 3.033364, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+149, 120477, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5874.29, -1014.771, 2859.849, 1.439484, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Deep Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+150, 119726, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6102.056, -803.9063, 2971.804, 5.683074, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Archmage Khadgar (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: ) (possible waypoints or random movement)
(@CGUID+151, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6101.983, -763.3153, 2971.792, 5.361639, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+152, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6101.764, -761.4219, 2971.804, 5.664975, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+153, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6098.733, -828.5691, 2971.815, 0.4318659, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+154, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6112.439, -786.9045, 2971.804, 0.9281234, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+155, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6103.824, -829.666, 2971.76, 2.160745, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+156, 120477, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5869.458, -1014.031, 2859.243, 0.730912, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Deep Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+157, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6109.085, -784.2118, 2971.804, 0.5639792, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+158, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6100.068, -760.793, 2971.801, 5.36165, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+159, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6112.878, -824.1702, 2971.907, 4.409331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+160, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6098.388, -767.7761, 2971.804, 1.077174, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+161, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6094.729, -807.7899, 2971.804, 4.328328, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+162, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6113.519, -764.0191, 2971.627, 4.409331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+163, 119730, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6102.063, -827.0345, 2971.76, 5.302286, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Maiev Shadowsong (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+164, 119728, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6099.269, -795.8733, 2971.804, 6.25553, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Prophète Velen (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241186 - Egide de Lumière) (possible waypoints or random movement)
(@CGUID+165, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6091.643, -784.4167, 2971.804, 2.524686, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+166, 121190, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5870.112, -1014.453, 2859.257, 1.172388, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Mistress Sassz'ine (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+167, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6089.397, -768.8021, 2971.804, 0.597248, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+168, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6127.867, -736.6702, 2969.71, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+169, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6128.159, -764.9114, 2971.627, 3.727708, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+170, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6129.84, -764.6593, 2971.603, 1.633775, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+171, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6135.798, -813.2449, 2971.561, 2.036806, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+172, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6137.22, -789.6702, 2971.804, 2.884756, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+173, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6121.495, -834.4305, 2971.627, 6.136105, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+174, 120482, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5850.948, -1047.293, 2855.87, 4.684569, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidescale Seacaller (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+175, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6124.741, -818.4054, 2971.979, 2.376478, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+176, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6131.063, -787.533, 2971.804, 5.616508, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+177, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6129.633, -761.3686, 2971.588, 4.775368, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+178, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6125.111, -835.6042, 2971.626, 3.502233, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+179, 121005, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6115.419, -764.1183, 3039.666, 6.088256, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Dreadwing (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+180, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6127.026, -820.598, 2971.561, 2.376749, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+181, 120473, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5850.791, -1051.835, 2854.123, 1.46892, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidescale Combatant (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+182, 121005, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6124.687, -799.7197, 3034.5, 1.46802, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Dreadwing (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+183, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6134.375, -810.4159, 2971.632, 2.036805, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+184, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6132.11, -833.8403, 2971.622, 4.409331, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+185, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6131.147, -842.882, 2971.443, 3.422352, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+186, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6133.757, -737.1945, 2969.735, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+187, 121005, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6117.187, -813.434, 3048.309, 4.221863, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Dreadwing (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+188, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6128.076, -854.9305, 2969.711, 3.062992, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+189, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6145.277, -737.4653, 2969.776, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+190, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6163.554, -852.2327, 2969.823, 3.062992, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+191, 121024, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6151.452, -816.3941, 2971.452, 3.730094, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felguard Invader (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+192, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6140.929, -771.6528, 2971.626, 1.577269, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+193, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6147.016, -774.0884, 2971.514, 2.4496, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+194, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6144.193, -771.7488, 2971.502, 1.941228, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+195, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5874.536, -1077.836, 2848.952, 5.200687, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+196, 121005, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6128.564, -820.8951, 3056.034, 3.818897, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Dreadwing (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+197, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6160.726, -739.2309, 2969.823, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+198, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6144.166, -789.373, 2971.953, 3.080978, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+199, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6149.361, -821.4358, 2971.45, 5.084475, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+200, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6156.479, -853.5156, 2969.819, 3.062992, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+201, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6143.427, -769.7782, 2971.501, 3.785266, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+202, 120477, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5810.358, -1083.237, 2827.201, 1.745504, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Deep Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123978 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+203, 119768, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6140.509, -789.1511, 2971.804, 0.0503412, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Soldat du Déclin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+204, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6146.76, -854.7083, 2969.78, 3.062992, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+205, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6151.604, -777.7604, 2971.454, 3.033364, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+206, 120482, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5885.048, -1093.462, 2846.84, 2.025985, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidescale Seacaller (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+207, 121023, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6141.419, -809.5018, 2971.627, 3.033364, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legionfall Soldier (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+208, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6136.683, -854.75, 2969.748, 3.062992, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+209, 119742, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6160.647, -810.9861, 2971.455, 3.422352, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Envahisseur gangregarde (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 35356 - Apparition de Feindre la mort)
(@CGUID+210, 120482, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5881.308, -1094.76, 2845.893, 1.879958, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidescale Seacaller (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+211, 120463, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5875.84, -1160.72, 2832.321, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Undersea Custodian (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240154 - Bulle d'eau)
(@CGUID+212, 120477, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5822.946, -1145.265, 2828.381, 4.843588, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Deep Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123978 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+213, 120473, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5878.986, -1129.244, 2834.605, 4.297601, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidescale Combatant (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+214, 120473, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5883.6, -1131.26, 2834.917, 4.285635, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidescale Combatant (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+215, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6185.73, -836.7864, 2969.823, 3.062992, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+216, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6190.021, -828.7118, 2969.823, 3.062992, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+217, 120477, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5841.522, -1098.257, 2830.379, 5.866316, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Deep Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123978 - Échelle : 95-120%) (possible waypoints or random movement)
(@CGUID+218, 92879, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6221.518, -795.743, 2974.679, 3.079738, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- SLG Generic Stalker (Gigantic AOI) (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+219, 115892, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6194.413, -842.9305, 3042.719, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ember Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+220, 45396, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6227.654, -804.2136, 2978.831, 2.747211, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI) (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 243149 -)
(@CGUID+221, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6184.656, -752.7743, 2969.823, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+222, 121630, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6227.654, -804.2136, 2981.715, 2.747211, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegis of Aggramar (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 154441 - Shadowy Ghost Cosmetic Spawn Spell)
(@CGUID+223, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6175.449, -743.9462, 2969.823, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+224, 120463, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5867.588, -1155.243, 2831.449, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Undersea Custodian (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240154 - Bulle d'eau)
(@CGUID+225, 120996, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6264.688, -796.2396, 2996.946, 3.141949, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Atrigan (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 160758 - Mod Scale 140%, 241219 - Invocation)
(@CGUID+226, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6190.582, -760.2864, 2969.823, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+227, 117931, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6178.121, -843.9114, 2969.823, 3.062992, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Lava Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+228, 115767, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5799.708, -1248.49, 2785.667, 1.015644, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Mistress Sassz'ine (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+229, 121605, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6266.077, -848.3542, 3063.243, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Breach (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+230, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6149.563, -868.1059, 2923.226, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240704 - Piège d'Aegwynn)
(@CGUID+231, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6100.988, -990.5469, 2959.747, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240700 - Piège d'Aegwynn)
(@CGUID+232, 121717, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6001.626, -1072.132, 2898.358, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Thal'kiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+233, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6088.5, -1027.075, 2896.395, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240705 - Piège d'Aegwynn)
(@CGUID+234, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6035.633, -1058.936, 2965.043, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240700 - Piège d'Aegwynn)
(@CGUID+235, 115844, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6103.044, -748.2031, 2971.803, 4.711344, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Goroth (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 233081 -)
(@CGUID+236, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6083.261, -1058.946, 2965.043, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240700 - Piège d'Aegwynn)
(@CGUID+237, 121719, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6249.782, -795.6927, 2894.346, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Thal'kiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+238, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6150.554, -1005.571, 2899.287, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+239, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6276.54, -796.0261, 2894.346, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+240, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6231.766, -1003.892, 2923.65, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240825 - Piège d'Aegwynn)
(@CGUID+241, 121633, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5982.644, -791.9323, 2978.21, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Wind Rush Totem (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+242, 119723, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6213.164, -795.809, 2975.086, 3.139258, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Image of Aegwynn (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 241351 - Apparition cosmétique)
(@CGUID+243, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5874.74, -1067.414, 2851.125, 5.207652, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+244, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5870.364, -1069.654, 2850.538, 5.161686, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+245, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5874.804, -1078.319, 2848.871, 5.208262, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+246, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5868.028, -1076.25, 2847.898, 5.179012, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+247, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5836.959, -1099.98, 2812.849, 4.97902, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+248, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5834.094, -1108.092, 2814.057, 4.615876, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+249, 120477, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5772.385, -1193.268, 2831.438, 2.131649, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961); -- Deep Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123978 - Échelle : 95-120%)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5839.872, -1112.134, 2814.973, 5.394885, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+251, 116841, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5813.549, -1211.531, 2785.974, 4.358604, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+252, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5808.977, -1111.388, 2819.74, 5.719998, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+253, 120477, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5707.328, -1168.47, 2825.465, 5.193728, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Deep Stalker (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123978 - Échelle : 95-120%)
(@CGUID+254, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5826.48, -1118.641, 2815.957, 5.75929, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+255, 116841, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5833.007, -1227.46, 2785.97, 3.70948, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+256, 116841, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5781.108, -1212.403, 2786.327, 5.190104, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+257, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5823.196, -1129.009, 2817.569, 5.371785, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+258, 116843, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5771.402, -1218.026, 2785.667, 5.483056, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Sarukel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 232745 - Gueule vorace)
(@CGUID+259, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5798.668, -1125.17, 2819.884, 4.524967, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+260, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5790.917, -1124.322, 2821.836, 0.5768955, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+261, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5807.095, -1138.535, 2822.049, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+262, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5774.977, -1124.977, 2821.811, 6.233266, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+263, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5795.438, -1137.063, 2819.642, 2.643707, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+264, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5789.654, -1134.153, 2821.63, 2.448124, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+265, 116841, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5761.982, -1231.073, 2786.327, 5.849496, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+266, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5809.08, -1150.264, 2824.743, 5.048641, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+267, 116841, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5837.624, -1261.568, 2786.327, 2.811138, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+268, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5755.19, -1126.841, 2827.459, 0.4768252, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+269, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5898.825, -879.8507, 2941.018, 5.467842, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+270, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5957.95, -927.6597, 2936.867, 2.197428, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+271, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5884.842, -885.8542, 2924.583, 5.467842, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+272, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5955.08, -916.1285, 2936.188, 3.325892, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+273, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5898.825, -879.8507, 2941.018, 5.467842, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+274, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5957.95, -927.6597, 2936.867, 2.197428, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+275, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5765.771, -1131.369, 2823.194, 1.881895, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+276, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5764.844, -1153.799, 2822.576, 0.3266345, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+277, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5757.601, -1143.712, 2823.362, 5.635435, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+278, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5884.842, -885.8542, 2924.583, 0.04117671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+279, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5955.08, -916.1285, 2936.188, 3.325892, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+280, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5898.825, -879.8507, 2941.018, 5.467842, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+281, 116569, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5957.95, -927.6597, 2936.867, 2.197428, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Wavemender (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+282, 116843, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5826.77, -1275.802, 2785.667, 2.328129, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Sarukel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+283, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5739.577, -1140.595, 2825.452, 0.8526615, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%) (possible waypoints or random movement)
(@CGUID+284, 116843, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5770.53, -1275.339, 2785.667, 0.7665323, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Sarukel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 232745 - Gueule vorace)
(@CGUID+285, 116841, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5818.79, -1283.594, 2786.327, 2.066933, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+286, 116841, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5763.953, -1267.113, 2786.327, 0.4758515, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+287, 116841, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5784.158, -1286.023, 2786.327, 1.173546, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+288, 120784, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6201.01, -1108.342, 2903.498, 4.238152, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Aegwynn's Trap (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 240822 - Piège d'Aegwynn)
(@CGUID+289, 111221, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5832.234, -1210.899, 2788.482, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+290, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5733.281, -1143.435, 2825.47, 1.496109, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+291, 121712, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5818.345, -1225.785, 2786.221, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Thal'kiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+292, 120516, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5719.678, -1154.515, 2825.308, 3.919639, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Razorjaw Swift-fin (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 214567 - Échelle : 90-110%)
(@CGUID+293, 116881, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5833.752, -1260.852, 2785.667, 2.784772, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ossunet (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234178 - Encre répugnante)
(@CGUID+294, 116881, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5762.726, -1233.019, 2785.667, 5.9199, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ossunet (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+295, 116881, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5784.009, -1282.965, 2785.667, 1.179193, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ossunet (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234178 - Encre répugnante)
(@CGUID+296, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5759.14, -1268.767, 2785.663, 0.5248545, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+297, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5735.708, -1232.849, 2785.663, 0.5248545, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+298, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5779.357, -1308.04, 2785.663, 0.5248545, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+299, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5773.781, -1294.967, 2785.663, 0.5248545, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+300, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5766.201, -1281.177, 2785.663, 0.5248545, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+301, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5746.47, -1244.968, 2785.663, 0.5248545, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+302, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5752.611, -1256.639, 2785.667, 0.5248545, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+303, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5855.82, -1221.134, 2785.663, 4.403097, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+304, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5772.979, -1194.754, 2785.663, 4.403097, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+305, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5785.879, -1200.7, 2785.663, 4.403097, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+306, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5800.771, -1205.811, 2785.663, 4.403097, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+307, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5839.714, -1219.383, 2785.663, 4.403097, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+308, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5827.309, -1214.861, 2785.667, 4.403097, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+309, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5814.321, -1210.258, 2785.663, 4.403097, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+310, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5804.235, -1196.708, 2785.663, 5.162069, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+311, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5792.136, -1201.941, 2785.667, 5.162069, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+312, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5779.549, -1207.545, 2785.663, 5.162069, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+313, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5817.136, -1186.899, 2785.663, 5.162069, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+314, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5738.882, -1224.767, 2785.663, 5.162069, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+315, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5752.335, -1220.188, 2785.663, 5.162069, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+316, 118286, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5766.652, -1213.66, 2785.663, 5.162069, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Piranhado (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 234809 - Tornade tranchante)
(@CGUID+317, 121105, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 5799.287, -1248.491, 2789.573, 0.8818414, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tidestone of Golganneth (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 144373 - RShwayder Test 02)
(@CGUID+318, 121496, 1676, 8524, 8524, 245760, '0', 0, 0, 0, 6231.388, -799.0191, 2982.07, 3.005056, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961); -- Tidestone of Golganneth (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 154441 - Shadowy Ghost Cosmetic Spawn Spell)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+318;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+14, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+25, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, '239907'), -- Razorjaw Gladiator - 239907 - Lame ruisselante
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, '239907'), -- Razorjaw Gladiator - 239907 - Lame ruisselante
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, '239907'), -- Razorjaw Gladiator - 239907 - Lame ruisselante
(@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Acolyte
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidescale Witch
(@CGUID+33, 0, 0, 0, 1, 0, 0, 0, 0, '239907'), -- Razorjaw Gladiator - 239907 - Lame ruisselante
(@CGUID+34, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Acolyte
(@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Acolyte
(@CGUID+36, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+37, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+38, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+40, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Acolyte
(@CGUID+41, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+43, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Myrmidon
(@CGUID+45, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Myrmidon
(@CGUID+46, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Myrmidon
(@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, '233071'), -- Harjatan - 233071 - Armure abrasive
(@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+50, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+51, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Acolyte
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Myrmidon
(@CGUID+53, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidescale Legionnaire
(@CGUID+56, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+57, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Envahisseur gangregarde
(@CGUID+59, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+61, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+62, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+63, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+64, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+65, 0, 0, 0, 1, 0, 0, 0, 0, '239907'), -- Razorjaw Gladiator - 239907 - Lame ruisselante
(@CGUID+66, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Myrmidon
(@CGUID+67, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+68, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+69, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+70, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+72, 0, 0, 0, 1, 0, 0, 0, 0, '239907'), -- Razorjaw Gladiator - 239907 - Lame ruisselante
(@CGUID+73, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mistress Sassz'ine
(@CGUID+75, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+76, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+78, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+79, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Envahisseur gangregarde
(@CGUID+80, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+81, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+82, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+84, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+85, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+86, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Durgan Roc-Tempête
(@CGUID+87, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+88, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+89, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+90, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+91, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+92, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+93, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+94, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+95, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+96, 0, 0, 0, 1, 0, 0, 0, 0, '239907'), -- Razorjaw Gladiator - 239907 - Lame ruisselante
(@CGUID+97, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+98, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+99, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+100, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+101, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+102, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+103, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+104, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+105, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+106, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+107, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+108, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+109, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+110, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+111, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+112, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur lige d'ombre - 35356 - Apparition de Feindre la mort
(@CGUID+113, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+114, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+115, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+116, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+117, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+118, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+119, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+120, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+121, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+122, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+123, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+124, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+125, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+126, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Illidan Hurlorage
(@CGUID+127, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+128, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+129, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+130, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+131, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+132, 0, 0, 50331648, 1, 0, 0, 0, 0, '35356'), -- Dreadwing - 35356 - Apparition de Feindre la mort
(@CGUID+133, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+134, 0, 0, 0, 1, 0, 9181, 0, 0, ''), -- Cove Seagull
(@CGUID+135, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur lige d'ombre - 35356 - Apparition de Feindre la mort
(@CGUID+136, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+137, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+138, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+139, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+140, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+141, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+142, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+143, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+144, 0, 0, 50331648, 1, 0, 0, 0, 0, '35356'), -- Dreadwing - 35356 - Apparition de Feindre la mort
(@CGUID+145, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+146, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidescale Seacaller
(@CGUID+147, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+148, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+149, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Deep Stalker - 123978 - Échelle : 95-120%
(@CGUID+150, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Archmage Khadgar
(@CGUID+151, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+152, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+153, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+154, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+155, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+156, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Deep Stalker - 123978 - Échelle : 95-120%
(@CGUID+157, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+158, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+159, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+160, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+161, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+162, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+163, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Maiev Shadowsong
(@CGUID+164, 0, 0, 0, 1, 0, 0, 0, 0, '241186'), -- Prophète Velen - 241186 - Egide de Lumière
(@CGUID+165, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soldat du Déclin
(@CGUID+166, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mistress Sassz'ine
(@CGUID+167, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+168, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+169, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+170, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+171, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+172, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+173, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+174, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidescale Seacaller
(@CGUID+175, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+176, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+177, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+178, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+179, 0, 0, 50331648, 1, 0, 0, 0, 0, '35356'), -- Dreadwing - 35356 - Apparition de Feindre la mort
(@CGUID+180, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+181, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidescale Combatant
(@CGUID+182, 0, 0, 50331648, 1, 0, 0, 0, 0, '35356'), -- Dreadwing - 35356 - Apparition de Feindre la mort
(@CGUID+183, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+184, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+185, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+186, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+187, 0, 0, 50331648, 1, 0, 0, 0, 0, '35356'), -- Dreadwing - 35356 - Apparition de Feindre la mort
(@CGUID+188, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+189, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+190, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+191, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Felguard Invader - 35356 - Apparition de Feindre la mort
(@CGUID+192, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+193, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+194, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+195, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+196, 0, 0, 50331648, 1, 0, 0, 0, 0, '35356'), -- Dreadwing - 35356 - Apparition de Feindre la mort
(@CGUID+197, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+198, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+199, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+200, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+201, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+202, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Deep Stalker - 123978 - Échelle : 95-120%
(@CGUID+203, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Soldat du Déclin - 35356 - Apparition de Feindre la mort
(@CGUID+204, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+205, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+206, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidescale Seacaller
(@CGUID+207, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Legionfall Soldier - 35356 - Apparition de Feindre la mort
(@CGUID+208, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+209, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur gangregarde - 35356 - Apparition de Feindre la mort
(@CGUID+210, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidescale Seacaller
(@CGUID+211, 0, 0, 33554432, 1, 0, 0, 0, 0, '240154'), -- Undersea Custodian - 240154 - Bulle d'eau
(@CGUID+212, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Deep Stalker - 123978 - Échelle : 95-120%
(@CGUID+213, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidescale Combatant
(@CGUID+214, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tidescale Combatant
(@CGUID+215, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+216, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+217, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Deep Stalker - 123978 - Échelle : 95-120%
(@CGUID+218, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SLG Generic Stalker (Gigantic AOI)
(@CGUID+219, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Ember Stalker
(@CGUID+220, 0, 0, 0, 1, 0, 0, 0, 0, '243149'), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI) - 243149 -
(@CGUID+221, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+222, 0, 0, 50331648, 1, 0, 0, 0, 0, '154441'), -- Aegis of Aggramar - 154441 - Shadowy Ghost Cosmetic Spawn Spell
(@CGUID+223, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+224, 0, 0, 33554432, 1, 0, 0, 0, 0, '240154'), -- Undersea Custodian - 240154 - Bulle d'eau
(@CGUID+225, 0, 0, 0, 1, 0, 0, 0, 0, '160758 241219'), -- Atrigan - 160758 - Mod Scale 140%, 241219 - Invocation
(@CGUID+226, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+227, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Lava Stalker
(@CGUID+228, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mistress Sassz'ine
(@CGUID+229, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Breach
(@CGUID+230, 0, 0, 0, 1, 0, 0, 0, 0, '240704'), -- Aegwynn's Trap - 240704 - Piège d'Aegwynn
(@CGUID+231, 0, 0, 0, 1, 0, 0, 0, 0, '240700'), -- Aegwynn's Trap - 240700 - Piège d'Aegwynn
(@CGUID+232, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+233, 0, 0, 0, 1, 0, 0, 0, 0, '240705'), -- Aegwynn's Trap - 240705 - Piège d'Aegwynn
(@CGUID+234, 0, 0, 0, 1, 0, 0, 0, 0, '240700'), -- Aegwynn's Trap - 240700 - Piège d'Aegwynn
(@CGUID+235, 0, 0, 0, 1, 0, 0, 0, 0, '233081'), -- Goroth - 233081 -
(@CGUID+236, 0, 0, 0, 1, 0, 0, 0, 0, '240700'), -- Aegwynn's Trap - 240700 - Piège d'Aegwynn
(@CGUID+237, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+238, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+239, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+240, 0, 0, 0, 1, 0, 0, 0, 0, '240825'), -- Aegwynn's Trap - 240825 - Piège d'Aegwynn
(@CGUID+241, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wind Rush Totem
(@CGUID+242, 0, 0, 0, 257, 0, 0, 0, 0, '241351'), -- Image of Aegwynn - 241351 - Apparition cosmétique
(@CGUID+243, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+244, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+245, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+246, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+247, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+248, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+249, 0, 0, 0, 1, 0, 0, 0, 0, '123978'); -- Deep Stalker - 123978 - Échelle : 95-120%

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+250, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+251, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Piranhado
(@CGUID+252, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+253, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- Deep Stalker - 123978 - Échelle : 95-120%
(@CGUID+254, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+255, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Piranhado
(@CGUID+256, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Piranhado
(@CGUID+257, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+258, 0, 0, 50331648, 1, 0, 0, 0, 0, '232745'), -- Sarukel - 232745 - Gueule vorace
(@CGUID+259, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+260, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+261, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+262, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+263, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+264, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+265, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Piranhado
(@CGUID+266, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+267, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Piranhado
(@CGUID+268, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+269, 0, 0, 0, 1, 0, 12379, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+270, 0, 0, 0, 1, 0, 12379, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+271, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+272, 0, 0, 0, 1, 0, 12379, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+273, 0, 0, 0, 1, 0, 12379, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+274, 0, 0, 0, 1, 0, 12379, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+275, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+276, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+277, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+278, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+279, 0, 0, 0, 1, 0, 12379, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+280, 0, 0, 0, 1, 0, 12379, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+281, 0, 0, 0, 1, 0, 12379, 0, 0, ''), -- Razorjaw Wavemender
(@CGUID+282, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sarukel
(@CGUID+283, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+284, 0, 0, 50331648, 1, 0, 0, 0, 0, '232745'), -- Sarukel - 232745 - Gueule vorace
(@CGUID+285, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Piranhado
(@CGUID+286, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Piranhado
(@CGUID+287, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Piranhado
(@CGUID+288, 0, 0, 0, 1, 0, 0, 0, 0, '240822'), -- Aegwynn's Trap - 240822 - Piège d'Aegwynn
(@CGUID+289, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+290, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+291, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+292, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- Razorjaw Swift-fin - 214567 - Échelle : 90-110%
(@CGUID+293, 0, 0, 50331648, 1, 0, 0, 0, 0, '234178'), -- Ossunet - 234178 - Encre répugnante
(@CGUID+294, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Ossunet
(@CGUID+295, 0, 0, 50331648, 1, 0, 0, 0, 0, '234178'), -- Ossunet - 234178 - Encre répugnante
(@CGUID+296, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+297, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+298, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+299, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+300, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+301, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+302, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+303, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+304, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+305, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+306, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+307, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+308, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+309, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+310, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+311, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+312, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+313, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+314, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+315, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+316, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- Piranhado - 234809 - Tornade tranchante
(@CGUID+317, 0, 0, 50331648, 1, 0, 0, 0, 0, '144373'), -- Tidestone of Golganneth - 144373 - RShwayder Test 02
(@CGUID+318, 0, 0, 50331648, 1, 0, 0, 0, 0, '154441'); -- Tidestone of Golganneth - 154441 - Shadowy Ghost Cosmetic Spawn Spell

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+70;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 253126, 1676, 8524, 8524, 245760, '0', 0, 5831.302, -796.2049, 2957.74, 0.004934316, 0, 0, 0.002467155, 0.999997, 604800, 255, 1, 25961), -- Instance Portal (Area: Tombe de Sargeras - Difficulty: Outil Raids)
-- (@OGUID+1, 181621, 1676, 8524, 8524, 245760, '0', 0, 5865.563, -795.976, 2953.16, 6.254162, 0, 0, -0.01451111, 0.9998947, 604800, 255, 1, 25961), -- Soulwell (Area: Tombe de Sargeras - Difficulty: Outil Raids) - !!! might be temporary spawn !!!
(@OGUID+2, 269192, 1676, 8524, 8524, 245760, '0', 0, 5937.457, -879.8716, 2920.775, 2.420397, 0, 0, 0.9356861, 0.3528335, 604800, 255, 0, 25961), -- Door d’entrée (Area: Tombe de Sargeras - Difficulty: Outil Raids)
-- (@OGUID+3, 181621, 1676, 8524, 8524, 245760, '0', 0, 5968.74, -795.945, 2978.025, 6.260051, 0, 0, -0.01156712, 0.9999331, 604800, 255, 1, 25961), -- Soulwell (Area: Tombe de Sargeras - Difficulty: Outil Raids) - !!! might be temporary spawn !!!
(@OGUID+4, 269974, 1676, 8524, 8524, 245760, '0', 0, 6010.043, -793.4874, 2973.959, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- Doodad_6FX_Firewall_DoorSMFel002 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+5, 269120, 1676, 8524, 8524, 245760, '0', 0, 5935.24, -949.2632, 2920.025, 0.5109373, 0, 0, 0.2526989, 0.967545, 604800, 255, 1, 25961), -- Door de la maîtresse (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+6, 269973, 1676, 8524, 8524, 245760, '0', 0, 6099.743, -856.0253, 2974.152, 4.71239, 0, 0, -0.7071066, 0.7071069, 604800, 255, 0, 25961), -- Doodad_6FX_Firewall_DoorSMFel001 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+7, 268752, 1676, 8524, 8524, 245760, '0', 0, 5987.114, -1017.305, 2927.477, 3.77578, 0, 0, -0.9501457, 0.3118062, 604800, 255, 1, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+8, 269838, 1676, 8524, 8524, 245760, '0', 0, 6112.478, -733.6039, 2984.402, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- 269838 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+9, 272802, 1676, 8524, 8524, 245760, '0', 0, 6112.376, -733.7028, 2984.274, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- 272802 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+10, 269840, 1676, 8524, 8524, 245760, '0', 0, 6087.842, -927.6913, 2976.787, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- Interrupteur antique (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+11, 268514, 1676, 8524, 8524, 245760, '0', 0, 6101.104, -919.1578, 2998.948, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+12, 268364, 1676, 8524, 8524, 245760, '0', 0, 6068.479, -1009.354, 2959.992, 3.665196, 0, 0, -0.9659252, 0.2588213, 604800, 255, 1, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+13, 269839, 1676, 8524, 8524, 245760, '0', 0, 6146.559, -762.0251, 2970.903, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- 269839 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+14, 269841, 1676, 8524, 8524, 245760, '0', 0, 6114.529, -927.6913, 2976.787, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- Interrupteur antique (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+15, 269975, 1676, 8524, 8524, 245760, '0', 0, 6194.761, -795.798, 2973.522, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- Doodad_7DU_TombofSargeras_FireDoor01 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+16, 269045, 1676, 8524, 8524, 245760, '0', 0, 6169.401, -1012.846, 2913.108, 5.93412, 0, 0, -0.1736479, 0.9848078, 604800, 255, 0, 25961), -- Barrière (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+17, 270940, 1676, 8524, 8524, 245760, '0', 0, 5950.437, -1095.415, 2912.443, 2.81584, 0, 0, 0.9867649, 0.1621574, 604800, 255, 1, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+18, 269164, 1676, 8524, 8524, 245760, '0', 0, 6221.104, -795.7595, 2974.113, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- Autel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+19, 268366, 1676, 8524, 8524, 245760, '0', 0, 6133.625, -971.8979, 2959.992, 0.5235979, 0, 0, 0.2588186, 0.9659259, 604800, 255, 0, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+20, 268365, 1676, 8524, 8524, 245760, '0', 0, 6133.636, -1009.464, 2959.992, 2.617989, 0, 0, 0.9659252, 0.2588213, 604800, 255, 1, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+21, 269842, 1676, 8524, 8524, 245760, '0', 0, 6260.061, -852.3503, 3041.751, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- 269842 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+22, 268750, 1676, 8524, 8524, 245760, '0', 0, 6188.131, -945.7178, 2892.065, 1.118474, 0, 0, 0.5305395, 0.8476602, 604800, 255, 1, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+23, 268819, 1676, 8524, 8524, 245760, '0', 0, 6243.467, -1001.754, 2923.611, 0.178153, -0.000004291534, 0.00005149841, 0.08895874, 0.9960353, 604800, 255, 1, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+24, 269262, 1676, 8524, 8524, 245760, '0', 0, 6486.747, -795.6044, 1664.717, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- Doors du caveau (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+25, 269261, 1676, 8524, 8524, 245760, '0', 0, 6389.573, -795.6044, 1652.382, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- Doors du caveau (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+26, 269976, 1676, 8524, 8524, 245760, '0', 0, 5825.933, -1216.871, 2787.371, 0.8726639, 0, 0, 0.4226179, 0.9063079, 604800, 255, 0, 25961), -- Door d’eau (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+27, 267722, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267722 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+28, 267724, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267724 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+29, 272386, 1676, 8524, 8524, 245760, '0', 0, 5828.875, -1273.423, 2788.735, 2.44346, 0, 0, 0.9396925, 0.3420205, 604800, 255, 1, 25961), -- 272386 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+30, 272385, 1676, 8524, 8524, 245760, '0', 0, 5769.848, -1224.092, 2788.735, 5.585054, 0, 0, -0.34202, 0.9396927, 604800, 255, 1, 25961), -- 272385 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+31, 272384, 1676, 8524, 8524, 245760, '0', 0, 5774.697, -1278.278, 2788.735, 0.8726639, 0, 0, 0.4226179, 0.9063079, 604800, 255, 1, 25961), -- 272384 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+32, 267701, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267701 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+33, 267707, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267707 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+34, 267709, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267709 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+35, 268579, 1676, 8524, 8524, 245760, '0', 0, 6341.295, -795.7725, 3037.665, 4.71239, 0, 0, -0.7071066, 0.7071069, 604800, 255, 0, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+36, 268580, 1676, 8524, 8524, 245760, '0', 0, 6289.381, -795.5262, 3029.027, 4.71239, 0, 0, -0.7071066, 0.7071069, 604800, 255, 1, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+37, 269782, 1676, 8524, 8524, 245760, '0', 0, 5799.276, -1248.567, 2786.034, 4.01426, 0, 0, -0.9063072, 0.4226195, 604800, 255, 1, 25961), -- 269782 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+38, 269781, 1676, 8524, 8524, 245760, '0', 0, 6385.965, -1052.795, 2902.235, 5.678986, 0, 0, -0.2975254, 0.9547139, 604800, 255, 0, 25961), -- Barrière fantomatique (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+39, 269780, 1676, 8524, 8524, 245760, '0', 0, 6402.042, -795.7916, 3011.507, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- 269780 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+40, 267934, 1676, 8524, 8524, 245760, '0', 0, 6607.75, -795.1597, 1661.2, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- 267934 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+41, 268751, 1676, 8524, 8524, 245760, '0', 0, 6152.908, -1083.313, 2892.168, 5.198888, 0, 0, -0.5159779, 0.8566019, 604800, 255, 1, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+42, 268749, 1676, 8524, 8524, 245760, '0', 0, 6354.415, -1030.835, 2909.796, 5.680764, 0, 0, -0.2966766, 0.954978, 604800, 255, 1, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+43, 268748, 1676, 8524, 8524, 245760, '0', 0, 6289.318, -985.2384, 2909.796, 5.680764, 0, 0, -0.2966766, 0.954978, 604800, 255, 0, 25961), -- Door (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+44, 269988, 1676, 8524, 8524, 245760, '0', 0, 6295.383, -795.3216, 2886.927, 3.141593, 0, 0, -1, 0, 604800, 255, 0, 25961), -- Doodad_7DU_TombOfSargeras_Felstorm_Collision002 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+45, 268574, 1676, 8524, 8524, 245760, '0', 0, 6348.021, -795.5745, 1650.51, 1.570796, 0, 0, 0.7071066, 0.7071069, 604800, 255, 24, 25961), -- 0 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+46, 267715, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267715 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+47, 267714, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267714 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+48, 267713, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267713 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+49, 267712, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267712 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+50, 267719, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267719 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+51, 267718, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267718 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+52, 267717, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267717 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+53, 267716, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267716 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+54, 267723, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267723 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+55, 267721, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267721 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+56, 267720, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267720 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+57, 267703, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267703 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+58, 267702, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267702 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+59, 267700, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267700 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+60, 267706, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267706 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+61, 267705, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267705 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+62, 267704, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267704 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+63, 267711, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267711 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+64, 267710, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267710 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+65, 267708, 1676, 8524, 8524, 245760, '0', 0, 6599.8, -794.1996, 1508.5, 0, 0, 0, 0, 1, 604800, 255, 1, 25961), -- 267708 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+66, 269987, 1676, 8524, 8524, 245760, '0', 0, 6676.665, -804.6313, 1527.098, 3.141593, 0, 0, -1, 0, 604800, 255, 1, 25961), -- Doodad_7DU_TombOfSargeras_Felstorm_Collision001 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
-- (@OGUID+67, 233282, 1676, 8524, 8524, 245760, '0', 0, 5873.865, -796.2169, 2954.222, 6.254162, 0, 0, -0.01451111, 0.9998947, 604800, 255, 1, 25961), -- Refreshment Table (Area: Tombe de Sargeras - Difficulty: Outil Raids) - !!! might be temporary spawn !!!
(@OGUID+68, 269260, 1676, 8524, 8524, 245760, '0', 0, 5971.748, -1068.649, 2857.058, 5.23479, 0.005013466, -0.002898216, -0.5005102, 0.8657113, 604800, 255, 1, 25961), -- Rune orque (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+69, 269779, 1676, 8524, 8524, 245760, '0', 0, 6438.216, -1089.601, 2881.37, 2.529184, 0, 0, 0.9534845, 0.3014419, 604800, 255, 1, 25961), -- 269779 (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+70, 269257, 1676, 8524, 8524, 245760, '0', 0, 6155.16, -1069.225, 2971.071, 3.155597, 0.00309515, -0.04773331, -0.9988317, 0.006862046, 604800, 255, 1, 25961); -- Rune orque (Area: Tombe de Sargeras - Difficulty: Outil Raids)
-- (@OGUID+71, 266938, 1676, 8524, 8524, 245760, '0', 0, 6091.983, -799.7098, 2971.765, 1.232505, 0, 0, 0.577981, 0.8160502, 604800, 255, 1, 25961); -- Pointe infernale (Area: Tombe de Sargeras - Difficulty: Outil Raids) - !!! might be temporary spawn !!!
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+70;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+1, 0, 0, 1, -0.00000004371139), -- Rune orque
(@OGUID+2, 0, 0, 1, -0.00000004371139), -- Door d’entrée
(@OGUID+3, 0, 0, 1, -0.00000004371139), -- Rune orque
(@OGUID+4, 0, 0, 1, -0.00000004371139), -- Doodad_6FX_Firewall_DoorSMFel002
(@OGUID+5, 0, 0, 1, -0.00000004371139), -- Door de la maîtresse
(@OGUID+6, 0, 0, 1, -0.00000004371139), -- Doodad_6FX_Firewall_DoorSMFel001
(@OGUID+7, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+8, 0, 0, 1, -0.00000004371139), -- 269838
(@OGUID+9, 0, 0, 1, -0.00000004371139), -- 272802
(@OGUID+10, 0, 0, 1, -0.00000004371139), -- Interrupteur antique
(@OGUID+11, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+12, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+13, 0, 0, 1, -0.00000004371139), -- 269839
(@OGUID+14, 0, 0, 1, -0.00000004371139), -- Interrupteur antique
(@OGUID+15, 0, 0, 1, -0.00000004371139), -- Doodad_7DU_TombofSargeras_FireDoor01
(@OGUID+16, 0, 0, 1, -0.00000004371139), -- Barrière
(@OGUID+17, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+18, 0, 0, 1, -0.00000004371139), -- Autel
(@OGUID+19, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+20, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+21, 0, 0, 1, -0.00000004371139), -- 269842
(@OGUID+22, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+23, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+24, 0, 0, 1, -0.00000004371139), -- Doors du caveau
(@OGUID+25, 0, 0, 1, -0.00000004371139), -- Doors du caveau
(@OGUID+26, 0, 0, 1, -0.00000004371139), -- Door d’eau
(@OGUID+27, 0, 0, 0, 1), -- 267722
(@OGUID+28, 0, 0, 0, 1), -- 267724
(@OGUID+29, 0, 0, 1, -0.00000004371139), -- 272386
(@OGUID+30, 0, 0, 1, -0.00000004371139), -- 272385
(@OGUID+31, 0, 0, 1, -0.00000004371139), -- 272384
(@OGUID+32, 0, 0, 0, 1), -- 267701
(@OGUID+33, 0, 0, 0, 1), -- 267707
(@OGUID+34, 0, 0, 0, 1), -- 267709
(@OGUID+35, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+36, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+37, 0, 0, 1, -0.00000004371139), -- 269782
(@OGUID+38, 0, 0, 1, -0.00000004371139), -- Barrière fantomatique
(@OGUID+39, 0, 0, 1, -0.00000004371139), -- 269780
(@OGUID+40, 0, 0, 0, 1), -- 267934
(@OGUID+41, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+42, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+43, 0, 0, 1, -0.00000004371139), -- Door
(@OGUID+44, 0, 0, 1, -0.00000004371139), -- Doodad_7DU_TombOfSargeras_Felstorm_Collision002
(@OGUID+45, 0, 0, 1, -0.00000004371139), -- 0
(@OGUID+46, 0, 0, 0, 1), -- 267715
(@OGUID+47, 0, 0, 0, 1), -- 267714
(@OGUID+48, 0, 0, 0, 1), -- 267713
(@OGUID+49, 0, 0, 0, 1), -- 267712
(@OGUID+50, 0, 0, 0, 1), -- 267719
(@OGUID+51, 0, 0, 0, 1), -- 267718
(@OGUID+52, 0, 0, 0, 1), -- 267717
(@OGUID+53, 0, 0, 0, 1), -- 267716
(@OGUID+54, 0, 0, 0, 1), -- 267723
(@OGUID+55, 0, 0, 0, 1), -- 267721
(@OGUID+56, 0, 0, 0, 1), -- 267720
(@OGUID+57, 0, 0, 0, 1), -- 267703
(@OGUID+58, 0, 0, 0, 1), -- 267702
(@OGUID+59, 0, 0, 0, 1), -- 267700
(@OGUID+60, 0, 0, 0, 1), -- 267706
(@OGUID+61, 0, 0, 0, 1), -- 267705
(@OGUID+62, 0, 0, 0, 1), -- 267704
(@OGUID+63, 0, 0, 0, 1), -- 267711
(@OGUID+64, 0, 0, 0, 1), -- 267710
(@OGUID+65, 0, 0, 0, 1), -- 267708
(@OGUID+66, 0, 0, 1, -0.00000004371139), -- Doodad_7DU_TombOfSargeras_Felstorm_Collision001
(@OGUID+67, 0, 0, 1, -0.00000004371139), -- Rune orque
(@OGUID+68, 0, 0, 1, -0.00000004371139), -- Rune orque
(@OGUID+69, 0, 0, 1, -0.00000004371139), -- 269779
(@OGUID+70, 0, 0, 1, -0.00000004371139); -- Rune orque

DELETE FROM `spell_target_position` WHERE (`ID`=248045 AND `EffectIndex`=0) OR (`ID`=250362 AND `EffectIndex`=0) OR (`ID`=251162 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(248045, 0, 1669, 388.85, 1416.41, 769.59, 25961), -- Spell: Téléportation Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(250362, 0, 1669, 380, 1412.5, 769.6, 25961), -- Spell: Téléportation vers le Vindicaar Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(251162, 0, 1220, -828.72, 4371.78, 738.64, 25961); -- Spell: Téléportation : Dalaran Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_addon` WHERE `entry` IN (121496 /*121496 (Tidestone of Golganneth) - Shadowy Ghost Cosmetic Spawn Spell*/, 121105 /*121105 (Tidestone of Golganneth) - RShwayder Test 02*/, 118286 /*118286 (Piranhado) - Tornade tranchante*/, 116881 /*116881 (Ossunet) - Encre répugnante*/, 121712 /*121712 (Thal'kiel)*/, 116843 /*116843 (Sarukel) - Gueule vorace*/, 116841 /*116841 (Piranhado)*/, 119723 /*119723 (Image of Aegwynn) - Apparition cosmétique*/, 121633 /*121633 (Wind Rush Totem)*/, 121719 /*121719 (Thal'kiel)*/, 115844 /*115844 (Goroth)*/, 121717 /*121717 (Thal'kiel)*/, 120784 /*120784 (Aegwynn's Trap) - Piège d'Aegwynn*/, 121605 /*121605 (Breach)*/, 115767 /*115767 (Mistress Sassz'ine)*/, 120996 /*Atrigan - Mod Scale 140%, Invocation*/, 121630 /*121630 (Aegis of Aggramar) - Shadowy Ghost Cosmetic Spawn Spell*/, 45396 /*Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI)*/, 115892 /*115892 (Ember Stalker)*/, 120463 /*120463 (Undersea Custodian) - Bulle d'eau*/, 120473 /*120473 (Tidescale Combatant)*/, 121190 /*121190 (Mistress Sassz'ine)*/, 119728 /*Prophète Velen - Egide de Lumière*/, 119730 /*119730 (Maiev Shadowsong)*/, 119726 /*119726 (Archmage Khadgar)*/, 120477 /*120477 (Deep Stalker) - Échelle : 95-120%*/, 120482 /*120482 (Tidescale Seacaller)*/, 121028 /*121028 (Cove Seagull)*/, 121005 /*121005 (Dreadwing) - Apparition de Feindre la mort*/, 119729 /*Illidan Hurlorage*/, 121021 /*Envahisseur lige d'ombre - Apparition de Feindre la mort*/, 119777 /*Durgan Roc-Tempête*/, 121184 /*121184 (Mistress Sassz'ine)*/, 119742 /*Envahisseur gangregarde*/, 117123 /*117123 (Tidescale Legionnaire)*/, 117931 /*117931 (Lava Stalker)*/, 116407 /*116407 (Harjatan) - Armure abrasive*/, 121004 /*121004 (Razorjaw Myrmidon)*/, 120516 /*120516 (Razorjaw Swift-fin) - Échelle : 90-110%*/, 121011 /*121011 (Tidescale Witch)*/, 117154 /*117154 (Razorjaw Acolyte)*/, 117596 /*117596 (Razorjaw Gladiator) - Lame ruisselante*/, 116569 /*116569 (Razorjaw Wavemender)*/, 121023 /*121023 (Legionfall Soldier) - Apparition de Feindre la mort*/, 121024 /*121024 (Felguard Invader) - Apparition de Feindre la mort*/, 119768 /*Soldat du Déclin*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(121496, 0, 0, 50331648, 1, 0, 0, 0, 0, '154441'), -- 121496 (Tidestone of Golganneth) - Shadowy Ghost Cosmetic Spawn Spell
(121105, 0, 0, 50331648, 1, 0, 0, 0, 0, '144373'), -- 121105 (Tidestone of Golganneth) - RShwayder Test 02
(118286, 0, 0, 50331648, 1, 0, 0, 0, 0, '234809'), -- 118286 (Piranhado) - Tornade tranchante
(116881, 0, 0, 50331648, 1, 0, 0, 0, 0, '234178'), -- 116881 (Ossunet) - Encre répugnante
(121712, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121712 (Thal'kiel)
(116843, 0, 0, 50331648, 1, 0, 0, 0, 0, '232745'), -- 116843 (Sarukel) - Gueule vorace
(116841, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 116841 (Piranhado)
(119723, 0, 0, 0, 257, 0, 0, 0, 0, '241351'), -- 119723 (Image of Aegwynn) - Apparition cosmétique
(121633, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121633 (Wind Rush Totem)
(121719, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121719 (Thal'kiel)
(115844, 0, 0, 0, 1, 0, 0, 0, 0, '233081'), -- 115844 (Goroth)
(121717, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121717 (Thal'kiel)
(120784, 0, 0, 0, 1, 0, 0, 0, 0, '240704'), -- 120784 (Aegwynn's Trap) - Piège d'Aegwynn
(121605, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 121605 (Breach)
(115767, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115767 (Mistress Sassz'ine)
(120996, 0, 0, 0, 1, 0, 0, 0, 0, '160758 241219'), -- Atrigan - Mod Scale 140%, Invocation
(121630, 0, 0, 50331648, 1, 0, 0, 0, 0, '154441'), -- 121630 (Aegis of Aggramar) - Shadowy Ghost Cosmetic Spawn Spell
(45396, 0, 0, 0, 1, 0, 0, 0, 0, '243149'), -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI)
(115892, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 115892 (Ember Stalker)
(120463, 0, 0, 33554432, 1, 0, 0, 0, 0, '240154'), -- 120463 (Undersea Custodian) - Bulle d'eau
(120473, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120473 (Tidescale Combatant)
(121190, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121190 (Mistress Sassz'ine)
(119728, 0, 0, 0, 1, 0, 0, 0, 0, '241186'), -- Prophète Velen - Egide de Lumière
(119730, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 119730 (Maiev Shadowsong)
(119726, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 119726 (Archmage Khadgar)
(120477, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- 120477 (Deep Stalker) - Échelle : 95-120%
(120482, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120482 (Tidescale Seacaller)
(121028, 0, 0, 0, 1, 0, 9181, 0, 0, ''), -- 121028 (Cove Seagull)
(121005, 0, 0, 50331648, 1, 0, 0, 0, 0, '35356'), -- 121005 (Dreadwing) - Apparition de Feindre la mort
(119729, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Illidan Hurlorage
(121021, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- Envahisseur lige d'ombre - Apparition de Feindre la mort
(119777, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Durgan Roc-Tempête
(121184, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121184 (Mistress Sassz'ine)
(119742, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Envahisseur gangregarde
(117123, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 117123 (Tidescale Legionnaire)
(117931, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 117931 (Lava Stalker)
(116407, 0, 0, 0, 1, 0, 0, 0, 0, '233071'), -- 116407 (Harjatan) - Armure abrasive
(121004, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121004 (Razorjaw Myrmidon)
(120516, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 120516 (Razorjaw Swift-fin) - Échelle : 90-110%
(121011, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121011 (Tidescale Witch)
(117154, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 117154 (Razorjaw Acolyte)
(117596, 0, 0, 0, 1, 0, 0, 0, 0, '239907'), -- 117596 (Razorjaw Gladiator) - Lame ruisselante
(116569, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116569 (Razorjaw Wavemender)
(121023, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- 121023 (Legionfall Soldier) - Apparition de Feindre la mort
(121024, 0, 0, 0, 1, 0, 0, 0, 0, '35356'), -- 121024 (Felguard Invader) - Apparition de Feindre la mort
(119768, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Soldat du Déclin


DELETE FROM `creature_template_scaling` WHERE `Entry` IN (120784, 121028);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(120784, 0, 25961),
(121028, 0, 25961);


DELETE FROM `creature_model_info` WHERE `DisplayID` IN (78177, 76095, 76079, 74493, 74287, 74282, 75786, 75789, 75801, 75802, 76094, 75790, 75059, 75495, 76160, 74438, 74020, 76064, 74939, 74934, 74933);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(78177, 7, 10, 0, 25961),
(76095, 1.690802, 0.45, 0, 25961),
(76079, 0.364, 2.625, 0, 25961),
(74493, 10.21286, 16, 0, 25961),
(74287, 3.004086, 6, 0, 25961),
(74282, 3.426014, 10, 0, 25961),
(75786, 0.33, 4.4, 0, 25961),
(75789, 2.198914, 3, 0, 25961),
(75801, 0.75, 1.5, 0, 25961),
(75802, 1.058963, 1.75, 0, 25961),
(76094, 1.690802, 0.45, 0, 25961),
(75790, 1.690802, 0.45, 0, 25961),
(75059, 3.551577, 2, 0, 25961),
(75495, 0.39905, 1.725, 0, 25961),
(76160, 4.005448, 8, 0, 25961),
(74438, 2.748642, 3.75, 0, 25961),
(74020, 7.450409, 10.25, 0, 25961),
(76064, 1.789856, 2.5, 0, 25961),
(74939, 0.372, 1.5, 0, 25961),
(74934, 1, 1.5, 0, 25961),
(74933, 0.306, 1.5, 0, 25961);

UPDATE `creature_model_info` SET `CombatReach`=1.5, `VerifiedBuild`=25961 WHERE `DisplayID`=69148;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=31183;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=25961 WHERE `DisplayID`=30736;
UPDATE `creature_model_info` SET `BoundingRadius`=3.675, `CombatReach`=6, `VerifiedBuild`=25961 WHERE `DisplayID`=73362;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=21072;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=27824;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=61871;
UPDATE `creature_model_info` SET `BoundingRadius`=1.288697, `VerifiedBuild`=25961 WHERE `DisplayID`=66152;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=51409;
UPDATE `creature_model_info` SET `BoundingRadius`=3.173497, `VerifiedBuild`=25961 WHERE `DisplayID`=66118;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=63270;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=67001;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=11686;
UPDATE `creature_model_info` SET `CombatReach`=1.666667, `VerifiedBuild`=25961 WHERE `DisplayID`=31;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=652;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=1.363636, `VerifiedBuild`=25961 WHERE `DisplayID`=1762;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=1079;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=5306;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6, `CombatReach`=1.5, `VerifiedBuild`=25961 WHERE `DisplayID`=65971;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=7970;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=63759;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=115767 AND `ID`=1) OR (`CreatureID`=120996 AND `ID`=1) OR (`CreatureID`=120473 AND `ID`=1) OR (`CreatureID`=119728 AND `ID`=1) OR (`CreatureID`=119730 AND `ID`=1) OR (`CreatureID`=119726 AND `ID`=1) OR (`CreatureID`=120482 AND `ID`=1) OR (`CreatureID`=119729 AND `ID`=1) OR (`CreatureID`=119768 AND `ID`=3) OR (`CreatureID`=119768 AND `ID`=2) OR (`CreatureID`=121184 AND `ID`=1) OR (`CreatureID`=119768 AND `ID`=1) OR (`CreatureID`=119742 AND `ID`=1) OR (`CreatureID`=117123 AND `ID`=1) OR (`CreatureID`=121004 AND `ID`=1) OR (`CreatureID`=117154 AND `ID`=1) OR (`CreatureID`=117596 AND `ID`=1) OR (`CreatureID`=116569 AND `ID`=1) OR (`CreatureID`=121024 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(115767, 1, 147440, 0, 0, 0, 0, 0, 45872, 0, 0), -- Mistress Sassz'ine
(120996, 1, 143627, 0, 0, 0, 0, 0, 0, 0, 0), -- Atrigan
(120473, 1, 85185, 0, 0, 0, 0, 0, 0, 0, 0), -- Tidescale Combatant
(119728, 1, 35714, 0, 0, 0, 0, 0, 0, 0, 0), -- Prophète Velen
(119730, 1, 32425, 0, 0, 0, 0, 0, 0, 0, 0), -- Maiev Shadowsong
(119726, 1, 28067, 0, 0, 0, 0, 0, 0, 0, 0), -- Archmage Khadgar
(120482, 1, 70226, 0, 0, 0, 0, 0, 0, 0, 0), -- Tidescale Seacaller
(119729, 1, 150732, 0, 0, 150732, 0, 0, 0, 0, 0), -- Illidan Hurlorage
(119768, 3, 116453, 0, 0, 0, 0, 0, 0, 0, 0), -- Soldat du Déclin
(119768, 2, 108726, 0, 0, 0, 0, 0, 0, 0, 0), -- Soldat du Déclin
(121184, 1, 147440, 0, 0, 0, 0, 0, 45872, 0, 0), -- Mistress Sassz'ine
(119768, 1, 136591, 0, 0, 116647, 0, 0, 0, 0, 0), -- Soldat du Déclin
(119742, 1, 132821, 0, 0, 0, 0, 0, 0, 0, 0), -- Envahisseur gangregarde
(117123, 1, 54538, 0, 0, 0, 0, 0, 0, 0, 0), -- Tidescale Legionnaire
(121004, 1, 38128, 0, 0, 0, 0, 0, 0, 0, 0), -- Razorjaw Myrmidon
(117154, 1, 31414, 0, 0, 0, 0, 0, 0, 0, 0), -- Razorjaw Acolyte
(117596, 1, 36529, 0, 0, 0, 0, 0, 0, 0, 0), -- Razorjaw Gladiator
(116569, 1, 55228, 0, 0, 0, 0, 0, 0, 0, 0), -- Razorjaw Wavemender
(121024, 1, 132821, 0, 0, 0, 0, 0, 0, 0, 0); -- Felguard Invader



UPDATE `creature_template` SET `faction`=94, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1140852736 WHERE `entry`=121496; -- Tidestone of Golganneth
UPDATE `creature_template` SET `faction`=94, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=121105; -- Tidestone of Golganneth
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=0.8571429, `BaseAttackTime`=3000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=118286; -- Piranhado
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=3000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=116881; -- Ossunet
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=121712; -- Thal'kiel
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=3000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=69208064, `unit_flags3`=1 WHERE `entry`=116843; -- Sarukel
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=3000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=69208064, `unit_flags3`=1 WHERE `entry`=116841; -- Piranhado
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=119723; -- Image of Aegwynn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=4194304 WHERE `entry`=121633; -- Wind Rush Totem
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=121719; -- Thal'kiel
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags2`=1073741824, `VehicleId`=5274 WHERE `entry`=115844; -- Goroth
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=121717; -- Thal'kiel
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=120784; -- Aegwynn's Trap
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1073743872 WHERE `entry`=121605; -- Breach
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=3.6, `speed_run`=1.285714, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=64, `unit_flags2`=4194304 WHERE `entry`=115767; -- Mistress Sassz'ine
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=5.6, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=120996; -- Atrigan
UPDATE `creature_template` SET `faction`=94, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1140852736 WHERE `entry`=121630; -- Aegis of Aggramar
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=45396; -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI)
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=115892; -- Ember Stalker
UPDATE `creature_template` SET `unit_flags2`=1077938176 WHERE `entry`=92879; -- SLG Generic Stalker (Gigantic AOI)
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=2, `speed_run`=0.7142857, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags2`=2099200, `HoverHeight`=3.3 WHERE `entry`=120463; -- Undersea Custodian
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200, `VehicleId`=5367 WHERE `entry`=120473; -- Tidescale Combatant
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=3.6, `speed_run`=1.285714, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33555264, `unit_flags2`=69206016 WHERE `entry`=121190; -- Mistress Sassz'ine
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2263, `speed_walk`=3.2, `speed_run`=1.857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=37748736, `unit_flags3`=3 WHERE `entry`=119728; -- Prophète Velen
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2501, `speed_walk`=3.2, `speed_run`=1.857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=37750784 WHERE `entry`=119730; -- Maiev Shadowsong
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2007, `speed_walk`=3.2, `speed_run`=1.857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=119726; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=3.6, `speed_run`=1.285714, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=120477; -- Deep Stalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2099200, `VehicleId`=5367 WHERE `entry`=120482; -- Tidescale Seacaller
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=2156, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=6293504, `HoverHeight`=1.5 WHERE `entry`=121028; -- Cove Seagull
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=37750784 WHERE `entry`=121005; -- Dreadwing
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2501, `speed_walk`=3.2, `speed_run`=1.857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=37750784 WHERE `entry`=119729; -- Illidan Hurlorage
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=2502, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=37750784 WHERE `entry`=121021; -- Envahisseur lige d'ombre
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1770, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=256, `unit_flags2`=37750784 WHERE `entry`=119777; -- Durgan Roc-Tempête
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=3.6, `speed_run`=1.285714, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=832, `unit_flags2`=2097152 WHERE `entry`=121184; -- Mistress Sassz'ine
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=2502, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags2`=35653632 WHERE `entry`=119742; -- Envahisseur gangregarde
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=117123; -- Tidescale Legionnaire
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=117931; -- Lava Stalker
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags2`=2097152 WHERE `entry`=116407; -- Harjatan
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=121004; -- Razorjaw Myrmidon
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_walk`=1.6, `speed_run`=1.285714, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=120516; -- Razorjaw Swift-fin
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=121011; -- Tidescale Witch
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=117154; -- Razorjaw Acolyte
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=117596; -- Razorjaw Gladiator
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=116569; -- Razorjaw Wavemender
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2501, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570425344, `unit_flags2`=35653633, `unit_flags3`=8193 WHERE `entry`=121023; -- Legionfall Soldier
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=2502, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=570425344, `unit_flags2`=2099201, `unit_flags3`=8193 WHERE `entry`=121024; -- Felguard Invader
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2501, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=37750784 WHERE `entry`=119768; -- Soldat du Déclin

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 121105;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(121105, 190910, 0, 0);


UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25961 WHERE `entry`=9662; -- Jeune fée fléchetteuse
UPDATE `creature_template` SET `modelid1`=69148, `HealthScalingExpansion`=6, `RequiredExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=121496; -- Tidestone of Golganneth
UPDATE `creature_template` SET `modelid1`=69148, `HealthScalingExpansion`=6, `RequiredExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=121105; -- Tidestone of Golganneth
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=48634; -- Guild Battle Standard
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=78177, `HealthScalingExpansion`=6, `rank`=1, `type`=10, `type_flags`=3145800, `HealthModifier`=30, `movementId`=100, `VerifiedBuild`=25961 WHERE `entry`=118286; -- Piranhado
UPDATE `creature_template` SET `modelid1`=32311, `modelid2`=31, `modelid3`=346, `modelid4`=1762, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=8.1648, `movementId`=138, `VerifiedBuild`=25961 WHERE `entry`=115902; -- Razorjaw Waverunner
UPDATE `creature_template` SET `modelid1`=75438, `HealthScalingExpansion`=6, `rank`=1, `type`=1, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=25.5092, `movementId`=138, `VerifiedBuild`=25961 WHERE `entry`=115795; -- Abyss Stalker
UPDATE `creature_template` SET `modelid1`=65850, `HealthScalingExpansion`=6, `rank`=1, `type`=1, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=3.136, `movementId`=138, `VerifiedBuild`=25961 WHERE `entry`=115896; -- Electrifying Jellyfish
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=31183, `HealthScalingExpansion`=6, `rank`=1, `type`=10, `type_flags`=3145800, `HealthModifier`=30, `VerifiedBuild`=25961 WHERE `entry`=116881; -- Ossunet
UPDATE `creature_template` SET `modelid1`=29297, `modelid2`=11686, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=121712; -- Thal'kiel
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25961 WHERE `entry`=101297; -- Yu'lon
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=31183, `HealthScalingExpansion`=6, `rank`=1, `type`=10, `type_flags`=3145800, `HealthModifier`=30, `VerifiedBuild`=25961 WHERE `entry`=116843; -- Sarukel
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=31183, `HealthScalingExpansion`=6, `rank`=1, `type`=10, `type_flags`=3145800, `HealthModifier`=30, `VerifiedBuild`=25961 WHERE `entry`=116841; -- Piranhado
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=32485; -- King Krush
UPDATE `creature_template` SET `modelid1`=76079, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=16777220, `HealthModifier`=200, `VerifiedBuild`=25961 WHERE `entry`=119723; -- Image of Aegwynn
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25961 WHERE `entry`=53225; -- Jeune pterreurdactyle
UPDATE `creature_template` SET `modelid1`=30736, `HealthScalingExpansion`=6, `type`=11, `HealthModifier`=1.1, `VerifiedBuild`=25961 WHERE `entry`=121633; -- Wind Rush Totem
UPDATE `creature_template` SET `modelid1`=11686, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1096, `VerifiedBuild`=25961 WHERE `entry`=121643; -- Flame Rift
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=99887; -- Shadowy Tear
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=99904; -- T'uure
UPDATE `creature_template` SET `modelid1`=3126, `modelid2`=35802, `modelid3`=36544, `modelid4`=4440, `HealthScalingExpansion`=6, `type`=1, `VerifiedBuild`=25961 WHERE `entry`=121661; -- Sneaky Snake
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=108493; -- Chaos Tear
UPDATE `creature_template` SET `IconName`='interact', `HealthScalingExpansion`=0, `type`=11, `type_flags`=1611924480, `VerifiedBuild`=25961 WHERE `entry`=59262; -- Door des démons
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=94584; -- Unstable Tear
UPDATE `creature_template` SET `IconName`='interact', `HealthScalingExpansion`=0, `type`=11, `type_flags`=1611924480, `VerifiedBuild`=25961 WHERE `entry`=59271; -- Door des démons
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25961 WHERE `entry`=62982; -- Mindbender
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=98680; -- Sphere of Insanity
UPDATE `creature_template` SET `HealthScalingExpansion`=2, `VerifiedBuild`=25961 WHERE `entry`=60199; -- Rune of Power
UPDATE `creature_template` SET `modelid1`=64390, `HealthScalingExpansion`=6, `rank`=1, `type`=10, `type_flags`=1076887628, `VerifiedBuild`=25961 WHERE `entry`=116976; -- Infernal Spike
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=31216; -- Mirror Image
UPDATE `creature_template` SET `modelid1`=79787, `type`=15, `HealthModifier`=1.7, `movementId`=48, `VerifiedBuild`=25961 WHERE `entry`=128142; -- Engeance du Vide
UPDATE `creature_template` SET `modelid1`=39541, `HealthScalingExpansion`=0, `type`=15, `VerifiedBuild`=25961 WHERE `entry`=19668; -- Shadowfiend
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=94365; -- Ashbringer
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=47649; -- Efflorescence
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=59738; -- Light's Hammer
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=94358; -- Ashbringer
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=98167; -- Void Tendril
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type_flags2`=16, `VerifiedBuild`=25961 WHERE `entry`=43499; -- Consecration
UPDATE `creature_template` SET `modelid1`=29297, `modelid2`=11686, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=121719; -- Thal'kiel
UPDATE `creature_template` SET `modelid1`=75099, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097224, `HealthModifier`=75, `movementId`=76, `VerifiedBuild`=25961 WHERE `entry`=118022; -- Infernal Chaosbringer
UPDATE `creature_template` SET `modelid1`=74493, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097260, `type_flags2`=128, `HealthModifier`=1189.19, `ManaModifier`=0, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=115844; -- Goroth
UPDATE `creature_template` SET `modelid1`=29297, `modelid2`=11686, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=121717; -- Thal'kiel
UPDATE `creature_template` SET `modelid1`=23980, `modelid2`=11686, `HealthScalingExpansion`=6, `rank`=1, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=120784; -- Aegwynn's Trap
UPDATE `creature_template` SET `modelid1`=4587, `HealthScalingExpansion`=-1, `type`=11, `type_flags`=1024, `HealthModifier`=0.05, `VerifiedBuild`=25961 WHERE `entry`=120357; -- Healing Stream Totem
UPDATE `creature_template` SET `modelid1`=74287, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097260, `type_flags2`=65664, `HealthModifier`=1456, `ManaModifier`=30, `movementId`=138, `VerifiedBuild`=25961 WHERE `entry`=115767; -- Mistress Sassz'ine
UPDATE `creature_template` SET `modelid1`=16480, `modelid2`=11686, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=121605; -- Breach
UPDATE `creature_template` SET `modelid1`=74282, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4, `HealthModifier`=1200, `movementId`=912, `VerifiedBuild`=25961 WHERE `entry`=120996; -- Atrigan
UPDATE `creature_template` SET `modelid1`=75786, `HealthScalingExpansion`=6, `rank`=1, `type`=1, `type_flags`=2097224, `HealthModifier`=84, `movementId`=94, `VerifiedBuild`=25961 WHERE `entry`=120463; -- Undersea Custodian
UPDATE `creature_template` SET `modelid1`=73362, `HealthScalingExpansion`=6, `RequiredExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25961 WHERE `entry`=121630; -- Aegis of Aggramar
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=45396; -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI)
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=25961 WHERE `entry`=92879; -- SLG Generic Stalker (Gigantic AOI)
UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=68857, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=115892; -- Ember Stalker
UPDATE `creature_template` SET `modelid1`=75789, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=64, `movementId`=144, `VerifiedBuild`=25961 WHERE `entry`=120473; -- Tidescale Combatant
UPDATE `creature_template` SET `modelid1`=75802, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=150, `movementId`=179, `VerifiedBuild`=25961 WHERE `entry`=119730; -- Maiev Shadowsong
UPDATE `creature_template` SET `modelid1`=61871, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4, `HealthModifier`=200, `ManaModifier`=80, `movementId`=179, `VerifiedBuild`=25961 WHERE `entry`=119726; -- Archmage Khadgar
UPDATE `creature_template` SET `modelid1`=75801, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=262208, `HealthModifier`=200, `ManaModifier`=15, `movementId`=179, `VerifiedBuild`=25961 WHERE `entry`=119728; -- Prophète Velen
UPDATE `creature_template` SET `modelid1`=66152, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=58, `movementId`=144, `VerifiedBuild`=25961 WHERE `entry`=120482; -- Tidescale Seacaller
UPDATE `creature_template` SET `modelid1`=76160, `modelid2`=27824, `HealthScalingExpansion`=6, `rank`=1, `type`=10, `type_flags`=1076887656, `HealthModifier`=990, `ManaModifier`=30, `movementId`=138, `VerifiedBuild`=25961 WHERE `entry`=121190; -- Mistress Sassz'ine
UPDATE `creature_template` SET `modelid1`=75790, `modelid2`=76094, `modelid3`=76095, `HealthScalingExpansion`=6, `rank`=1, `type`=1, `type_flags`=2097224, `HealthModifier`=24, `movementId`=138, `VerifiedBuild`=25961 WHERE `entry`=120477; -- Deep Stalker
UPDATE `creature_template` SET `modelid1`=66118, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097224, `HealthModifier`=45, `movementId`=144, `VerifiedBuild`=25961 WHERE `entry`=121005; -- Dreadwing
UPDATE `creature_template` SET `modelid1`=75059, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=268435460, `HealthModifier`=250, `movementId`=179, `VerifiedBuild`=25961 WHERE `entry`=119729; -- Illidan Hurlorage
UPDATE `creature_template` SET `modelid1`=51409, `HealthScalingExpansion`=6, `type`=1, `type_flags`=2097224, `HealthModifier`=50, `movementId`=144, `VerifiedBuild`=25961 WHERE `entry`=121028; -- Cove Seagull
UPDATE `creature_template` SET `modelid1`=63270, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097224, `HealthModifier`=120, `VerifiedBuild`=25961 WHERE `entry`=121021; -- Envahisseur lige d'ombre
UPDATE `creature_template` SET `modelid1`=75495, `HealthScalingExpansion`=6, `type`=7, `type_flags`=2097224, `HealthModifier`=60, `VerifiedBuild`=25961 WHERE `entry`=119777; -- Durgan Roc-Tempête
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=111221; -- Xal'atath
UPDATE `creature_template` SET `modelid1`=7970, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097224, `HealthModifier`=75, `movementId`=841, `VerifiedBuild`=25961 WHERE `entry`=119742; -- Envahisseur gangregarde
UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=68857, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=117931; -- Lava Stalker
UPDATE `creature_template` SET `modelid1`=76160, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097260, `type_flags2`=65536, `HealthModifier`=990, `ManaModifier`=30, `movementId`=138, `VerifiedBuild`=25961 WHERE `entry`=121184; -- Mistress Sassz'ine
UPDATE `creature_template` SET `modelid1`=74438, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=65, `movementId`=144, `VerifiedBuild`=25961 WHERE `entry`=117123; -- Tidescale Legionnaire
UPDATE `creature_template` SET `modelid1`=74020, `HealthScalingExpansion`=6, `rank`=1, `type`=5, `type_flags`=2097260, `type_flags2`=128, `HealthModifier`=1263.04, `movementId`=180, `VerifiedBuild`=25961 WHERE `entry`=116407; -- Harjatan
UPDATE `creature_template` SET `modelid1`=31, `modelid2`=31, `modelid3`=1762, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=20, `movementId`=134, `VerifiedBuild`=25961 WHERE `entry`=120516; -- Razorjaw Swift-fin
UPDATE `creature_template` SET `modelid1`=652, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=30, `VerifiedBuild`=25961 WHERE `entry`=121004; -- Razorjaw Myrmidon
UPDATE `creature_template` SET `modelid1`=76064, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=55, `VerifiedBuild`=25961 WHERE `entry`=121011; -- Tidescale Witch
UPDATE `creature_template` SET `modelid1`=1079, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=25, `VerifiedBuild`=25961 WHERE `entry`=117154; -- Razorjaw Acolyte
UPDATE `creature_template` SET `modelid1`=65971, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=11.25704, `movementId`=180, `VerifiedBuild`=25961 WHERE `entry`=116569; -- Razorjaw Wavemender
UPDATE `creature_template` SET `modelid1`=5306, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `type_flags2`=128, `HealthModifier`=12.75797, `VerifiedBuild`=25961 WHERE `entry`=117596; -- Razorjaw Gladiator
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=90202; -- Abyssius
UPDATE `creature_template` SET `movementId`=121, `VerifiedBuild`=25961 WHERE `entry`=85007; -- Glisseur des fourrés
UPDATE `creature_template` SET `modelid1`=7970, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097224, `HealthModifier`=75, `movementId`=841, `VerifiedBuild`=25961 WHERE `entry`=121024; -- Felguard Invader
UPDATE `creature_template` SET `modelid1`=74939, `modelid2`=74933, `modelid3`=74934, `modelid4`=63759, `HealthScalingExpansion`=6, `type`=7, `type_flags`=2097224, `HealthModifier`=6.5, `VerifiedBuild`=25961 WHERE `entry`=121023; -- Legionfall Soldier
UPDATE `creature_template` SET `modelid1`=74939, `modelid2`=74933, `modelid3`=74934, `modelid4`=63759, `HealthScalingExpansion`=6, `type`=7, `type_flags`=64, `HealthModifier`=6.5, `VerifiedBuild`=25961 WHERE `entry`=119768; -- Soldat du Déclin
UPDATE `creature_template` SET `modelid1`=64799, `HealthScalingExpansion`=4, `type_flags`=262144, `type_flags2`=1, `ManaModifier`=2, `VerifiedBuild`=25961 WHERE `entry`=416; -- Diablotin

DELETE FROM `gameobject_template` WHERE `entry` IN (266938 /*Pointe infernale*/, 269987 /*Doodad_7DU_TombOfSargeras_Felstorm_Collision001*/, 267705 /*267705*/, 267706 /*267706*/, 267719 /*267719*/, 267703 /*267703*/, 267720 /*267720*/, 267710 /*267710*/, 267718 /*267718*/, 267717 /*267717*/, 267714 /*267714*/, 267713 /*267713*/, 267715 /*267715*/, 267721 /*267721*/, 267700 /*267700*/, 267702 /*267702*/, 267711 /*267711*/, 267723 /*267723*/, 267708 /*267708*/, 267704 /*267704*/, 267716 /*267716*/, 267712 /*267712*/, 267722 /*267722*/, 267724 /*267724*/, 267701 /*267701*/, 267707 /*267707*/, 267709 /*267709*/, 269262 /*Doors du caveau*/, 269261 /*Doors du caveau*/, 268574 /*Doodad_7DU_TombOfSargeras_Titan_Elevator*/, 267934 /*267934*/, 269781 /*Barrière fantomatique*/, 268749 /*Door*/, 268579 /*Door*/, 268748 /*Door*/, 269976 /*Door d’eau*/, 269988 /*Doodad_7DU_TombOfSargeras_Felstorm_Collision002*/, 268819 /*Door*/, 268580 /*Door*/, 268751 /*Door*/, 269045 /*Barrière*/, 268750 /*Door*/, 269164 /*Autel*/, 268365 /*Door*/, 269975 /*Doodad_7DU_TombofSargeras_FireDoor01*/, 268366 /*Door*/, 270940 /*Door*/, 268364 /*Door*/, 268514 /*Door*/, 272802 /*272802*/, 268752 /*Door*/, 269973 /*Doodad_6FX_Firewall_DoorSMFel001*/, 269120 /*Door de la maîtresse*/, 269974 /*Doodad_6FX_Firewall_DoorSMFel002*/, 269192 /*Door d’entrée*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(266938, 5, 37971, 'Pointe infernale', '', '', '', 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Pointe infernale
(269987, 0, 42416, 'Doodad_7DU_TombOfSargeras_Felstorm_Collision001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Doodad_7DU_TombOfSargeras_Felstorm_Collision001
(267705, 33, 40415, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267705
(267706, 33, 40411, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267706
(267719, 33, 40420, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267719
(267703, 33, 40406, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267703
(267720, 33, 40425, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 222, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267720
(267710, 33, 40402, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 211, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267710
(267718, 33, 40419, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267718
(267717, 33, 40424, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 221, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267717
(267714, 33, 40405, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267714
(267713, 33, 40410, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267713
(267715, 33, 40423, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 220, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267715
(267721, 33, 40418, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267721
(267700, 33, 40414, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267700
(267702, 33, 40409, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267702
(267711, 33, 40404, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267711
(267723, 33, 40422, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267723
(267708, 33, 40413, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 209, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267708
(267704, 33, 40408, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267704
(267716, 33, 40417, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 214, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267716
(267712, 33, 40403, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267712
(267722, 33, 40421, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267722
(267724, 33, 40416, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 213, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267724
(267701, 33, 40407, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 203, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267701
(267707, 33, 40412, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267707
(267709, 33, 40398, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267709
(269262, 0, 41976, 'Vault doors', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Vault doors
(269261, 0, 41976, 'Vault doors', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Vault doors
(268574, 11, 41205, 'Doodad_7DU_TombOfSargeras_Titan_Elevator', '', '', '', 0.9999998, 33, 0, 0, 0, 0, -1, 39000, 0, 86667, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Doodad_7DU_TombOfSargeras_Titan_Elevator
(267934, 33, 40650, '', '', '', '', 1, 0, 0, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 267934
(269781, 0, 41762, 'Barrière fantomatique', '', '', '', 1.147318, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Barrière fantomatique
(268749, 0, 40920, 'Door', '', '', '', 0.8092345, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(268579, 0, 41166, 'Door', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(268748, 0, 40920, 'Door', '', '', '', 0.8092345, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(269976, 0, 42397, 'Water door', '', '', '', 0.8968711, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door d’eau
(269988, 0, 42417, 'Doodad_7DU_TombOfSargeras_Felstorm_Collision002', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Doodad_7DU_TombOfSargeras_Felstorm_Collision002
(268819, 0, 40920, 'Door', '', '', '', 0.5414141, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(268580, 0, 41166, 'Door', '', '', '', 1.314212, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(268751, 0, 40920, 'Door', '', '', '', 1.00616, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(269045, 0, 41762, 'Barrière', '', '', '', 0.9999999, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Barrière
(268750, 0, 40920, 'Door', '', '', '', 0.9967877, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(269164, 0, 41871, 'Autel', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Autel
(268365, 0, 40920, 'Door', '', '', '', 0.8024516, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(269975, 0, 42396, 'Doodad_7DU_TombofSargeras_FireDoor01', '', '', '', 0.9999999, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Doodad_7DU_TombofSargeras_FireDoor01
(268366, 0, 40920, 'Door', '', '', '', 0.8024516, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(270940, 0, 40920, 'Door', '', '', '', 0.8824456, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(268364, 0, 40920, 'Door', '', '', '', 0.8024517, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(268514, 0, 41166, 'Door', '', '', '', 0.9999998, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(272802, 0, 43799, '', '', '', '', 0.9999999, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- 272802
(268752, 0, 40920, 'Door', '', '', '', 0.796352, 0, 0, 10000, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door
(269973, 0, 26056, 'Doodad_6FX_Firewall_DoorSMFel001', '', '', '', 1.255354, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Doodad_6FX_Firewall_DoorSMFel001
(269120, 0, 41617, 'Mistress door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Door de la maîtresse
(269974, 0, 26056, 'Doodad_6FX_Firewall_DoorSMFel002', '', '', '', 1.48612, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Doodad_6FX_Firewall_DoorSMFel002
(269192, 0, 41617, 'Front door', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961); -- Door d’entrée

UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=25961 WHERE `entry`=191083; -- Demonic Circle: Summon
UPDATE `gameobject_template` SET `type`=10, `displayId`=41975, `Data10`=241742, `Data23`=1, `VerifiedBuild`=25961 WHERE `entry`=269257; -- Rune orque
UPDATE `gameobject_template` SET `type`=10, `displayId`=42094, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269779; -- 269779
UPDATE `gameobject_template` SET `type`=10, `displayId`=41975, `Data10`=241742, `Data23`=1, `VerifiedBuild`=25961 WHERE `entry`=269260; -- Rune orque
UPDATE `gameobject_template` SET `type`=10, `displayId`=41975, `Data10`=241742, `Data23`=1, `VerifiedBuild`=25961 WHERE `entry`=269258; -- Rune orque
UPDATE `gameobject_template` SET `VerifiedBuild`=25961 WHERE `entry`=233282; -- Refreshment Table
UPDATE `gameobject_template` SET `type`=10, `displayId`=42095, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269780; -- 269780
UPDATE `gameobject_template` SET `type`=10, `displayId`=43369, `name`='', `size`=1.05759, `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=272384; -- 272384
UPDATE `gameobject_template` SET `type`=10, `displayId`=43369, `name`='', `size`=1.05759, `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=272386; -- 272386
UPDATE `gameobject_template` SET `type`=10, `displayId`=42096, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269782; -- 269782
UPDATE `gameobject_template` SET `type`=10, `displayId`=43369, `name`='', `size`=1.05759, `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=272385; -- 272385
UPDATE `gameobject_template` SET `type`=10, `displayId`=42213, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269842; -- 269842
UPDATE `gameobject_template` SET `type`=10, `displayId`=42212, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269839; -- 269839
UPDATE `gameobject_template` SET `type`=10, `displayId`=33855, `size`=1.90945, `VerifiedBuild`=25961 WHERE `entry`=269841; -- Interrupteur antique
UPDATE `gameobject_template` SET `type`=10, `displayId`=33855, `size`=1.90945, `VerifiedBuild`=25961 WHERE `entry`=269840; -- Interrupteur antique
UPDATE `gameobject_template` SET `type`=10, `displayId`=42211, `name`='', `Data13`=1, `VerifiedBuild`=25961 WHERE `entry`=269838; -- 269838
UPDATE `gameobject_template` SET `type`=10, `displayId`=41975, `Data10`=241742, `Data23`=1, `VerifiedBuild`=25961 WHERE `entry`=269259; -- Rune orque
UPDATE `gameobject_template` SET `type`=10, `displayId`=41975, `Data10`=241742, `Data23`=1, `VerifiedBuild`=25961 WHERE `entry`=269256; -- Rune orque
UPDATE `gameobject_template` SET `VerifiedBuild`=25961 WHERE `entry`=253126; -- Instance Portal
UPDATE `gameobject_template` SET `Data1`=-1, `VerifiedBuild`=25961 WHERE `entry`=181621; -- Soulwell

UPDATE creature SET spawndist = 0, MovementType = 0 WHERE guid IN (21003364, 21003350);
UPDATE creature_template SET inhabitType = 4 WHERE entry = 121605;

