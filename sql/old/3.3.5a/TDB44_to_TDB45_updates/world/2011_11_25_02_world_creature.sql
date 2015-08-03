-- re-guid
DELETE FROM `creature` WHERE `guid`=1022681 OR (`guid`=48191 AND `id`=18069);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(48191, 18069, 530, 1, 1, 0, 0, -714.823, 7931.65, 58.8672, 4.3693, 300, 0, 0, 60720, 29330, 0, 0, 0, 0);
