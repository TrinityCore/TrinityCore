SET @CGUID := 1051927;
SET @OGUID := 600244;

UPDATE `gameobject_template_addon` SET `flags`=33554432, `AIAnimKitID`=3503 WHERE `entry`=323853; -- Portal to Shattrath

DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 323853, 1, 1637, 5170, '0', 0, 0, 1424.099609375, -4506.412109375, -3.16643524169921875, 0.754637539386749267, 0, 0, 0.368429183959960937, 0.929655849933624267, 120, 255, 1, 47213); -- Portal to Shattrath (Area: Valley of Strength - Difficulty: 0)

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 148795, 1, 1637, 5170, '0', 0, 0, 0, 1, 1429.0867919921875, -4504.77587890625, -3.2527625560760498, 3.627566099166870117, 120, 0, 0, 2198, 2175, 0, 0, 0, 0, 47213), -- Consortium Arcanist (Area: Valley of Strength - Difficulty: 0) (Auras: 288540 - Shattrath Portal Channel)
(@CGUID+1, 148795, 1, 1637, 5170, '0', 0, 0, 0, 1, 1425.1285400390625, -4501.34912109375, -3.2365119457244873, 4.642745018005371093, 120, 0, 0, 2198, 2175, 0, 0, 0, 0, 47213); -- Consortium Arcanist (Area: Valley of Strength - Difficulty: 0) (Auras: 288540 - Shattrath Portal Channel)

DELETE FROM `creature_template_addon` WHERE `entry` = 148795; -- 148795 (Consortium Arcanist) - Shattrath Portal Channel
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(148795, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '288540'); -- 148795 (Consortium Arcanist) - Shattrath Portal Channel

UPDATE `creature_template_scaling` SET `VerifiedBuild`=47213 WHERE (`DifficultyID`=0 AND `Entry` = 148795);
UPDATE `creature_template` SET `VerifiedBuild`=47213 WHERE `entry` = 148795;
UPDATE `creature_template_model` SET `VerifiedBuild`=47213 WHERE (`Idx`=0 AND `CreatureID` = 148795);
UPDATE `creature_equip_template` SET `VerifiedBuild`=47213 WHERE (`ID`=1 AND `CreatureID` = 148795);
