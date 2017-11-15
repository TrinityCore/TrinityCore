--
DELETE FROM `creature` WHERE `guid` IN (4151,4153);
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(4151, 1352, 0, 0, 0, 1, 1, 0, 0, -5546.13, -1301.88, 399.909, 1.25519, 370, 0, 0, 8, 0, 2, 0, 0, 0, '', 0),
(4153, 1263, 0, 0, 0, 1, 1, 0, 0, -5547.62, -1306.45, 398.409, 4.45606, 180, 0, 0, 42, 0, 0, 0, 0, 0, '', 0);
