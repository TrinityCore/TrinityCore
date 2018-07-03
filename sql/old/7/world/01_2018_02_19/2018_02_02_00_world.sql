--
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=42562;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33536 WHERE `entry` IN (42560);
DELETE FROM `creature` WHERE `id`IN (42403,42402,42401,42399);

SET @CGUID := 251569;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+0,42560,0,40,109,1,169,0,0,0,-9855.679, 1277.568, 40.96358,5.427974,120,0,0,0,0,0,0,0,0,'',0),
(@CGUID+1,42386,0,40,109,1,169,0,0,0,-9851.216, 1273.403, 41.19444,2.583087,120,0,0,0,0,0,0,0,0,'',0),
(@CGUID+2,42384,0,40,109,1,169,0,0,0,-9859.457, 1279.47, 41.09737,5.480334,120,0,0,0,0,0,0,0,0,'',0),
(@CGUID+3,42384,0,40,109,1,169,0,0,0,-9861.16, 1276.556, 40.83781,0.122173,120,0,0,0,0,0,0,0,0,'',0),
(@CGUID+4,42559,0,40,109,1,169,0,0,0,-9852.603, 1274.115, 41.0983,5.88176,120,0,0,0,0,0,0,0,0,'',0),
(@CGUID+5,42559,0,40,109,1,169,0,0,0,-9859.658, 1275.504, 40.86245,2.373648,120,0,0,0,0,0,0,0,0,'',0),
(@CGUID+6,42558,0,40,109,1,169,0,0,0,-9855.285, 1275.561, 40.97787,1.413717,120,0,0,0,0,0,0,0,0,'',0);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0,0,0,65536,1,0,0,0,0,'79343 79372 29266'),
(@CGUID+1,0,0,65536,1,431,0,0,0,'79343'),
(@CGUID+2,0,0,65536,1,431,0,0,0,'79343'),
(@CGUID+3,0,0,65536,1,431,0,0,0,'79343'),
(@CGUID+4,0,0,65536,1,0,0,0,0,'79343'),
(@CGUID+5,0,0,65536,1,0,0,0,0,'79343'),
(@CGUID+6,0,0,65544,1,0,0,0,0,'79343');
