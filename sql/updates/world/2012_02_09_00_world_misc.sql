SET @ENTRY := 35826;
UPDATE `creature_template` SET `npcflag`=`npcflag`|128 WHERE `entry`=@ENTRY;

DELETE FROM `npc_vendor` WHERE `entry`=@ENTRY;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(@ENTRY,0,10609,1,1800,0),
(@ENTRY,1,16054,1,1800,0),
(@ENTRY,2,13311,1,1800,0);

DELETE FROM `spell_target_position` WHERE `id`=68081;
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(68081,571,5857.358887, 516.444275, 599.817688, 3.253991);
