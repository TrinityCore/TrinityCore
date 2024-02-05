SET @GUID := NULL;
DELETE FROM `gameobject` WHERE guid = @GUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneid`, `areaid`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GUID,149431,109,0,0,1,1,-518.154,-85.2353,-74.488,3.14159,0,0,0,0,43200,100,1);