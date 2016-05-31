-- DB/Creature: Nalpak Spawn
SET @CGUID := 452399;
DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 5767, 43, 1, -150.298, 123.82, -75.95126, 3.228859, 7200, 0, 0); -- 5767 (Area: -1)
