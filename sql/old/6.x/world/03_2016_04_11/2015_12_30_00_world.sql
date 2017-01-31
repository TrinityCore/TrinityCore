-- 
DELETE FROM `creature` WHERE `guid`=370491 AND `id`=47421; -- remove dup spawn
SET @guid=250000;
DELETE FROM `creature` WHERE `guid` BETWEEN @guid+0 AND @guid+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseid`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(@guid+0, 43010, 530,  1,  0,  33190, 1, 10381.3, -6422.5, 38.6156, 2.68781, 300, 0, 0, 102, 0, 0),
(@guid+1, 44036, 530,  1,  0,  33633, 0, 8743.85, -6651.69, 70.2161, 5.41052, 300, 0, 0, 232470, 0, 0),
(@guid+2, 27946, 530,  1,  0,  0, 0, 9510.306641, -6762.979, 16.668, 4.291251, 300, 0, 0, 0, 0, 0),
(@guid+3, 27946, 530,  1,  0,  0, 0, 9500.149414, -6759.082, 17.053, 4.237838, 300, 0, 0, 0, 0, 0),
(@guid+4, 27946, 530,  1,  0,  0, 0, 8738.1328, -6649.817, 70.456, 5.222682, 300, 0, 0, 0, 0, 0),
(@guid+5, 27946, 530,  1,  0,  0, 0, 8744.2753, -6646.436, 70.702, 4.932130, 300, 0, 0, 0, 0, 0);
