--
SET @ENTRY := 18399;

UPDATE `smart_scripts` SET `event_phase_mask`=1 WHERE  `entryorguid`=18399 AND `source_type`=0 AND `id` IN(4,5);

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id` BETWEEN 6 AND 10;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,6,7,25,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Twin - On Reset - Set Event Phase 0"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,70,0,0,0,0,0,0,9,18399,0,100,0,0,0,0,"Murkblood Twin - On Reset - Respawn "),
(@ENTRY,0,8,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,18399,0,100,0,0,0,0,"Murkblood Twin - On Just Died - Set Data 1 1"),
(@ENTRY,0,9,10,38,0,100,0,1,1,0,0,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Twin - On Data Set 1 1 - Set Data 1 0"),
(@ENTRY,0,10,0,61,0,100,0,1,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Twin - Linked with Previous Event - Increment Phase");
