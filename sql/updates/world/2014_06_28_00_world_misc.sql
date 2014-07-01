--
SET @CGUID:= 43496;
DELETE FROM `game_graveyard_zone` WHERE `id`=2;
INSERT INTO `game_graveyard_zone` (`id`, `ghost_zone`, `faction`) VALUES (2, 44, 469);

INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`) VALUES
(@CGUID, 6491, 0, 1, 1, -9190.865, -2308.829, 89.63705, 4.13643, 120, 0, 0); -- 6491 (Area: 44)
