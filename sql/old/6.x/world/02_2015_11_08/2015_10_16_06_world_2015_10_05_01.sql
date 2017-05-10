-- 
DELETE FROM `creature_template_addon` WHERE `Entry`=38058;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`) VALUES (38058,50331648,1);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=38058;

DELETE FROM `smart_scripts` WHERE `entryorguid`=36725 AND `source_type`=0 AND `id`>4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(36725,0,5,0,4,0,100,31,0,0,0,0,11,69887,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nerub'ar Broodkeeper - On aggro - Cast Web Beam"),
(36725,0,6,0,0,0,100,31,4000,4000,0,0,91,2,3,0,0,0,0,1,0,0,0,0,0,0,0,"Nerub'ar Broodkeeper  - In combat no repeat - Remove Flag Hover");
