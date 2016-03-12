DELETE FROM `creature` WHERE `guid` IN (52283, 52284, 52285, 52286, 69717, 69718, 69719, 69720);

SET @GUID          := 69717; -- 4 creature guid Set by TC
SET @OGUID         := 5510; -- 1 GOB guid set by TC
DELETE FROM `creature` WHERE `id`=23142;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`curhealth`) VALUES
(@GUID+0, 23142, 530, 1, 1, -5121.06, 598.424, 84.7603, 0.0581088, 600, 6542),
(@GUID+1, 23142, 530, 1, 1, -5119.60, 601.834, 84.8180, 5.1726200, 600, 6542),
(@GUID+2, 23142, 530, 1, 1, -5115.02, 601.537, 85.0292, 4.0204400, 600, 6542),
(@GUID+3, 23142, 530, 1, 1, -5114.25, 597.062, 85.1574, 2.7049000, 600, 6542);

DELETE FROM `gameobject` WHERE `guid` IN (@OGUID);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID,50983,530,1,1, -5116.788574, 631.188660, 85.055522,0.949811,0,0,0.457254, 0.889336, 300, 0, 1);

DELETE FROM `creature_equip_template` WHERE `entry`=23146;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`, `VerifiedBuild`) VALUES (23146, 1, 31603, 0, 0, 0);
UPDATE `creature` SET `position_x`= -5158.237305, `position_y`= 584.302612, `position_z`= 81.074142, `orientation`= 5.954358 WHERE `guid`= 78136;
UPDATE `creature` SET `position_x`= -5156.172363, `position_y`= 590.695251, `position_z`= 80.769630, `orientation`= 5.502757 WHERE `guid`= 78135;
UPDATE `creature` SET `position_x`= -5152.365723, `position_y`= 592.303040, `position_z`= 81.361931, `orientation`= 4.705578 WHERE `guid`= 78137;
UPDATE `creature` SET `position_x`= -5113.345703, `position_y`= 623.850159, `position_z`= 86.736343, `orientation`= 1.033840 WHERE `guid`= 78160;
UPDATE `creature` SET `position_x`= -5123.593750, `position_y`= 626.638916, `position_z`= 86.629669, `orientation`= 1.395123 WHERE `guid`= 78159;
UPDATE `creature` SET `position_x`= -5165.503418, `position_y`= 568.109131, `position_z`= 80.523895, `orientation`= 2.707489 WHERE `guid`= 52107;
