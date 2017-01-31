SET @CGUID  := 18; -- Set by TC, need 1
SET @NORTET := 38037;

DELETE FROM `creature` WHERE `guid`=@CGUID AND `id`=@NORTET;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, @NORTET, 1, 1, 1, -1171.352, -5440.788, 12.04206, 5.305801, 120, 0, 0);

UPDATE `creature_template` SET `gossip_menu_id`=10977, `npcflag`=19 WHERE `entry`=@NORTET;

DELETE FROM `creature_template_addon` WHERE `entry`=@NORTET;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@NORTET, 0, 0x0, 0x1, '');
