-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=23899 AND `source_type`=0 AND `id` IN (8,9);
UPDATE `smart_scripts` SET `link`=9 WHERE `entryorguid`=23899 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23899,0,8,0,54,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tethyr - On Just Summoned - Set Active ON"),
(23899,0,9,0,61,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tethyr - On wp reached - Set Active OFF");
