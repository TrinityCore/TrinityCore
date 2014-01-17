SET @GUID := 42575;
SET @ENTRY := 36095; -- Highlord Tirion Fordring

DELETE FROM `creature` WHERE `id`=@ENTRY;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(@GUID,@ENTRY,649,15,1,648.9167,131.0208,141.6161,0,7200,0,0);

DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@ENTRY,0,0x0,0x1,'57545');
