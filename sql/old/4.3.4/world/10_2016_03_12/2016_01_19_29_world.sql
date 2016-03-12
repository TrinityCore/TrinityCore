--
UPDATE creature SET `position_x`=1725.56, `position_y`=-4515.26, `position_z`=30.7725, `orientation`=0.61086 WHERE id=54472;
DELETE FROM `creature` WHERE `id` IN (54471);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseid`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(250020, 54471, 1,  1,  169,  38799, 0, 1721.14, -4513.19, 31.3289, 0.314159, 120, 0, 0, 185976, 58182, 0);
