SET @GUID = 4522;
SET @SINK = 300177;

-- spawn TEMP South Sinkhole
DELETE FROM `gameobject` WHERE `guid`=@GUID AND `id`=@SINK;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GUID, @SINK, 571, 1, 1, 3488.48, 4515.98, -20.7394, 5.34436, 0, 0, 0.452361, -0.891835, 300, 0, 1);

-- increase TEMP South Sinkhole spellfocus radius
UPDATE `gameobject_template` SET `data1`=20 WHERE `entry`=@SINK;
