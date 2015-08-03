-- Added equipment template, corrected unit_flags and fixed model bounding for The Etymidian
SET @EQUIP := 2477;

UPDATE `creature_template` SET `unit_flags`=`unit_flags`|8,`equipment_id`=@EQUIP WHERE `entry`=28222;
UPDATE `creature_model_info` SET `bounding_radius`=0.42,`combat_reach`=2.4 WHERE `modelid`=25928;

DELETE FROM `creature_equip_template` WHERE `entry`=@EQUIP;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@EQUIP,25316,0,0);
