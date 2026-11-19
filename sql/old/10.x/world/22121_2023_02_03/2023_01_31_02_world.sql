SET @CGUID := 1051929;
SET @OGUID := 600245;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 141900, 1, 141, 702, '0', '0', 0, 0, 0, 8177.9443359375, 998.91668701171875, 7.11283111572265625, 0, 120, 0, 0, 17621, 0, 0, 0, 0, 0, 47871); -- Niana Moontear (Area: Rut'theran Village - Difficulty: 0)

DELETE FROM `creature_template_addon` WHERE `entry` IN (141900 /*141900 (Niana Moontear)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(141900, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- 141900 (Niana Moontear)

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=141900; -- Niana Moontear

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 293886, 1, 141, 702, '0', '0', 0, 8177.5380859375, 1002.578125, 6.670926570892333984, 0, 0, 0, 0, 1, 120, 255, 0, 47871); -- Portal to Stormwind (Area: Rut'theran Village - Difficulty: 0)

DELETE FROM `gameobject_template_addon` WHERE `entry`=293886;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(293886, 1732, 0, 0, 0); -- Portal to Stormwind
