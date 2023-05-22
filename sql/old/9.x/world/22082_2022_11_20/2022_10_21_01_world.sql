SET @CGUID := 850660;
SET @OGUID := 501822;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 141903, 1, 141, 702, '0', 0, 0, 0, 0, 8339.4501953125, 1163.3975830078125, 4.617352962493896484, 0, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 45745); -- Eranril Moontear (Area: Rut'theran Village - Difficulty: 0)

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 293885, 1, 141, 702, '0', 0, 0, 8343.5126953125, 1164.0850830078125, 4.208178997039794921, 0, 0, 0, 0, 1, 120, 255, 1, 45745), -- Portal to Exodar (Area: Rut'theran Village - Difficulty: 0)
(@OGUID+1, 293894, 530, 3479, 3479, '0', 0, 0, -4264.56103515625, -11330.1162109375, 5.276190757751464843, 0, 0, 0, 0, 1, 120, 255, 0, 45745); -- Portal to Darnassus (Area: The Veiled Sea - Difficulty: 0)

-- Creature template addon
DELETE FROM `creature_template_addon` WHERE `entry` = (141903 /*141903 (Eranril Moontear)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(141903, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- 141903 (Eranril Moontear)

-- GameObject Template addon
DELETE FROM `gameobject_template_addon` WHERE `entry`=293885;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(293885, 35, 0, 0, 0); -- Portal to Exodar

-- Spell Target position
DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (282530,282498));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(282530, 0, 1, 8343.740234375, 1158.1700439453125, 4.800000190734863281, 45745), -- Spell: 282530 (Portal: Darnassus) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(282498, 0, 530, -4264.10986328125, -11335.2001953125, 5.869999885559082031, 45745); -- Spell: 282498 (Portal: Exodar) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
