-- Crystalline Ice Giant
DELETE FROM `creature` WHERE `guid`=74033;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(74033, 26291, 571, 0, 0, 1, 1, 0, 1, 5001.1665, 292.13882, 156.07475, 0.994837641716003417, 300, 0, 0, 29820, 0, 0, 0, 0, 0, '', 53262);

-- Emote OneShotAttackUnarmed
DELETE FROM `creature_addon` WHERE `guid`=74033;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `auras`) VALUES
(74033, 0, 0, 0, 0, 0, 1, 0, 35, ''); -- Crystalline Ice Giant
