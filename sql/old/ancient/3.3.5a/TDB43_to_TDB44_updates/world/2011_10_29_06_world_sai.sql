SET @ENTRY := 28566; -- "Tipsy" McManus
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+8 AND `source_type`=9 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+7 AND `source_type`=9 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY*100+8,9,3,0,0,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 8 - Set gossip flag"),
(@ENTRY*100+7,9,2,0,0,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tipsy McManus - Script 7 - Set gossip flag");
