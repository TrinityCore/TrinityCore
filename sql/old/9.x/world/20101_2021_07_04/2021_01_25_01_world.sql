
SET @OGUID := 301847;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 323850, 1, 1637, 11386, '0', '0', 0, 1448.6434326171875, -4531.02099609375, 19.84333038330078125, 1.946041464805603027, 0, 0, 0.826589584350585937, 0.56280517578125, 120, 255, 1, 36839), -- Portal to Azsuna
(@OGUID+1, 323851, 1, 1637, 11386, '0', '0', 0, 1422.5894775390625, -4484.1494140625, 20.21439170837402343, 5.61123514175415039, 0, 0, -0.32968997955322265, 0.944089233875274658, 120, 255, 1, 36839), -- Portal to Dalaran, Crystalsong Forest
(@OGUID+2, 323852, 1, 1637, 11386, '0', '0', 0, 1416.71142578125, -4505.74853515625, 19.84333038330078125, 0.113445065915584564, 0, 0, 0.056692123413085937, 0.998391687870025634, 120, 255, 1, 36839), -- Portal to Honeydew Village
(@OGUID+3, 323854, 1, 1637, 11386, '0', '0', 0, 1463.7464599609375, -4480.1591796875, 19.84333038330078125, 3.953172922134399414, 0, 0, -0.91879081726074218, 0.394744753837585449, 120, 255, 1, 36839), -- Portal to Silvermoon
(@OGUID+4, 323855, 1, 1637, 11386, '0', '0', 0, 1427.4569091796875, -4525.2265625, 19.84333038330078125, 0.89884275197982788, 0, 0, 0.434444427490234375, 0.900698602199554443, 120, 255, 1, 36839); -- Portal to Zuldazar

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+0, 0, 0, 0.998391687870025634, -0.05669287219643592), -- Portal to Azsuna
(@OGUID+1, 0, 0, 0.998391687870025634, -0.05669287219643592), -- Portal to Dalaran, Crystalsong Forest
(@OGUID+2, 0, 0, 0.998391687870025634, -0.05669287219643592), -- Portal to Honeydew Village
(@OGUID+3, 0, 0, 0.998391687870025634, -0.05669287219643592), -- Portal to Silvermoon
(@OGUID+4, 0, 0, 0.998391687870025634, -0.05669287219643592); -- Portal to Zuldazar

UPDATE `gameobject_template` SET `ContentTuningId`=331, `VerifiedBuild`=36839 WHERE `entry`=323850; -- Portal to Azsuna
UPDATE `gameobject_template` SET `Data5`=76876, `ContentTuningId`=826, `VerifiedBuild`=36839 WHERE `entry`=323851; -- Portal to Dalaran, Crystalsong Forest
UPDATE `gameobject_template` SET `ContentTuningId`=57, `VerifiedBuild`=36839 WHERE `entry`=323852; -- Portal to Honeydew Village
UPDATE `gameobject_template` SET `ContentTuningId`=866, `VerifiedBuild`=36839 WHERE `entry`=323854; -- Portal to Silvermoon
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=36839 WHERE `entry`=323855; -- Portal to Zuldazar

UPDATE `gameobject_template_addon` SET `flags`=0x2000000, `AIAnimKitID`=3503 WHERE `entry`=323850; -- Portal to Azsuna
UPDATE `gameobject_template_addon` SET `flags`=0x2000000, `AIAnimKitID`=3503 WHERE `entry`=323851; -- Portal to Dalaran, Crystalsong Forest
UPDATE `gameobject_template_addon` SET `flags`=0x2000000, `AIAnimKitID`=3503 WHERE `entry`=323852; -- Portal to Honeydew Village
UPDATE `gameobject_template_addon` SET `flags`=0x2000000, `AIAnimKitID`=3503 WHERE `entry`=323854; -- Portal to Silvermoon
UPDATE `gameobject_template_addon` SET `flags`=0x2000000, `AIAnimKitID`=3503 WHERE `entry`=323855; -- Portal to Zuldazar

SET @CGUID := 459907;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 145714, 1, 1637, 11386, '0', '0', 0, 0, 0, 1427.1475830078125, -4525.68408203125, 19.82146835327148437, 0, 120, 0, 0, 4579, 1807, 0, 0, 0, 0, 36839), -- Use the Portal to Zuldazar
(@CGUID+1, 148265, 1, 1637, 11386, '0', '0', 0, 0, 0, 1427.296875, -4521.01904296875, 20.04938888549804687, 4.534610748291015625, 120, 0, 0, 4945, 4393, 0, 0, 0, 0, 36839), -- Zandalari Arcanital
(@CGUID+2, 148265, 1, 1637, 11386, '0', '0', 0, 0, 0, 1431.51220703125, -4525.18603515625, 20.02359199523925781, 3.537615299224853515, 120, 0, 0, 4945, 4393, 0, 0, 0, 0, 36839), -- Zandalari Arcanital
(@CGUID+3, 148768, 1, 1637, 11386, '0', '0', 0, 0, 0, 1451.55908203125, -4527.77783203125, 20.06750679016113281, 4.350827693939208984, 120, 0, 0, 1921, 3801, 0, 0, 0, 0, 36839), -- Shal'dorei Arcanist
(@CGUID+4, 148768, 1, 1637, 11386, '0', '0', 0, 0, 0, 1445.2291259765625, -4527.62841796875, 20.06750679016113281, 5.279233932495117187, 120, 0, 0, 1921, 3801, 0, 0, 0, 0, 36839), -- Shal'dorei Arcanist
(@CGUID+5, 148263, 1, 1637, 11386, '0', '0', 0, 0, 0, 1420.892333984375, -4502.72412109375, 20.06750679016113281, 3.772001504898071289, 120, 0, 0, 2148, 2680, 0, 0, 0, 0, 36839), -- Huojin Magister
(@CGUID+6, 148263, 1, 1637, 11386, '0', '0', 0, 0, 0, 1421, -4508.42529296875, 20.06750679016113281, 2.842155218124389648, 120, 0, 0, 2148, 2680, 0, 0, 0, 0, 36839), -- Huojin Magister
(@CGUID+7, 149258, 1, 1637, 1637, '0', '0', 0, 0, 0, 1424.329833984375, -4489.44970703125, 20.06750679016113281, 2.054926395416259765, 120, 0, 0, 1732, 2175, 0, 0, 0, 0, 36839), -- Argent Mage
(@CGUID+8, 149258, 1, 1637, 1637, '0', '0', 0, 0, 0, 1428.2691650390625, -4484.65478515625, 20.06750679016113281, 3.02477574348449707, 120, 0, 0, 1732, 2175, 0, 0, 0, 0, 36839), -- Argent Mage
(@CGUID+9, 148250, 1, 1637, 11386, '0', '0', 0, 0, 0, 1462.8367919921875, -4484.65625, 20.06750869750976562, 1.361590147018432617, 120, 0, 0, 4945, 4393, 0, 0, 0, 0, 36839), -- Silvermoon Magistrix
(@CGUID+10, 148242, 1, 1637, 11386, '0', '0', 0, 0, 0, 1459.3541259765625, -4481.42529296875, 20.06750679016113281, 0.490184634923934936, 120, 0, 0, 4945, 4393, 0, 0, 0, 0, 36839); -- Silvermoon Magister

DELETE FROM `creature_template_addon` WHERE `entry` IN (145714,148265,148768,148263,149258,148250,148242);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(145714, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 145714 (Use the Portal to Zuldazar)
(148265, 0, 0, 0, 257, 0, 0, 0, 0, '287470'), -- 148265 (Zandalari Arcanital)
(148768, 0, 0, 0, 257, 0, 0, 0, 0, '288451'), -- 148768 (Shal'dorei Arcanist)
(148263, 0, 0, 0, 257, 0, 0, 0, 0, '286709'), -- 148263 (Huojin Magister)
(149258, 0, 0, 0, 257, 0, 0, 0, 0, '289141'), -- 149258 (Argent Mage)
(148250, 0, 0, 0, 257, 0, 0, 0, 0, '287432'), -- 148250 (Silvermoon Magistrix)
(148242, 0, 0, 0, 257, 0, 0, 0, 0, '287432'); -- 148242 (Silvermoon Magister)

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=148768; -- Shal'dorei Arcanist
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=145714; -- Use the Portal to Zuldazar
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=148265; -- Zandalari Arcanital
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35 WHERE `entry`=148263; -- Huojin Magister
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=149258; -- Argent Mage
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=148250; -- Silvermoon Magistrix
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=148242; -- Silvermoon Magister
