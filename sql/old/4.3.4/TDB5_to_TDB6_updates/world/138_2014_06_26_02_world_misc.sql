-- Pure Energy
SET @ENTRY := 24745;
UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=@ENTRY;

DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@ENTRY, 0, 0x0, 0x0, '44326 46156');
