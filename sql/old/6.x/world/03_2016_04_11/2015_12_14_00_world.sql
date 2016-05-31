-- 
SET @Guid:=250887;
DELETE FROM `creature` WHERE `id`=44937 AND `guid` BETWEEN @guid+0 AND @guid+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseid`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(@guid+0, 44937, 530, 1, 0, 3019, 0, 10325, -6403.6, 37.2317, 2.93215, 300, 0, 0, 142, 0, 0),
(@guid+1, 44937, 530, 1, 0, 3019, 0, 10381.8, -6381.9, 37.8308, 0.977384, 300, 0, 0, 142, 0, 0),
(@guid+2, 44937, 530, 1, 0, 3019, 0, 10328.4, -6393.98, 37.1472, 2.63545, 300, 0, 0, 142, 0, 0),
(@guid+3, 44937, 530, 1, 0, 3019, 0, 10373.3, -6377.87, 37.2858, 1.29154, 300, 0, 0, 142, 0, 0),
(@guid+4, 44937, 530, 1, 0, 3019, 0, 10363.9, -6375.25, 37.0142, 1.58825, 300, 0, 0, 142, 0, 0),
(@guid+5, 44937, 530, 1, 0, 3019, 0, 10334.4, -6386.11, 36.5143, 2.3911, 300, 0, 0, 142, 0, 0);
