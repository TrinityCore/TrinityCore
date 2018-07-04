-- Reposition npcs, remove some, add one
SET @CGUID :=452570;
DELETE FROM `creature` WHERE `guid` IN (280027,314280,314300,314301,314274);
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 6774, 0, 0, 0, 1, 1, 169, 0, 0, -9073.705, -39.39063, 87.85996, 5.379836, 120, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- Falkhaan Isenstrider
(@CGUID+1, 1750, 0, 0, 0, 1, 1, 169, 0, 0, -8374.146, 237.8924, 155.409, 5.759586, 120, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- Grand Admiral Jes-Tereth
(@CGUID+2, 107574, 0, 0, 0, 1, 1, 169, 0, 0, -8363.292, 232.5469, 157.0733, 2.249798, 120, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- Anduin Wrynn <King of Stormwind>
(@CGUID+3, 15187, 0, 0, 0, 1, 1, 169, 0, 0, -8338.654, 286.2708, 156.9159, 5.11218, 120, 0, 0, 0, 0, 0, 0, 0, 0, 24015); -- Cenarion Emissary Jademoon

-- Reposition spawn for master
SET @OGUID :=301113;
DELETE FROM `gameobject` WHERE `guid` IN (220440,@OGUID);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID, 206110, 0, 0, 0, 1, 169, 0, -8339.884, 288.7882, 156.8326, 5.037568, 0, 0, -0.5833187, 0.8122433, 120, 255, 1, 24015); -- Portal to Moonglade
