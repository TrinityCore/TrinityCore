SET @GUID          := 16397; -- 1 creature guid Set by TC
DELETE FROM `creature` WHERE `id`=16123;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`curhealth`) VALUES
(@GUID, 16123, 0, 1, 1, -14457.221680, 448.084534, 20.406971, 6.115618, 600, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (16123, 16033, 16016);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`, `emote`, `auras`) VALUES
(16123,0,0,0,"27614 17327 44816"),
(16033,0,0,0,"27614 17327"),
(16016,0,0,0,"27614 17327");
