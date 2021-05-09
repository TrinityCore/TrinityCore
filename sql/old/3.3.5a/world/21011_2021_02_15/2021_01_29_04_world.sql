--
ALTER TABLE `creature` MODIFY `VerifiedBuild` int(11) DEFAULT '0';

DELETE FROM `creature` WHERE `guid` = 43740 AND `id` = 6491;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(43740, 6491, 571, 1, 1, 0, 0, 2002.7415771484375, 5938.0986328125, 37.18986129760742187, 5.934119224548339843, 300, 0, 0, 37176);
