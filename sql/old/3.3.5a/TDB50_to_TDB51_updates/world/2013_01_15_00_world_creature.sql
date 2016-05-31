SET @CGUID :=43501;
SET @ENTRY :=25233; -- Lunk-tusk

UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=@ENTRY;

DELETE FROM `creature` WHERE `id`=@ENTRY;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, @ENTRY, 571, 1, 1, 1230.617, -3349.278, 203.7188, 3.385939, 120, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@ENTRY, 0, 0x1, 0x1, '');
