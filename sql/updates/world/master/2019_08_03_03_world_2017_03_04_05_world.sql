-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23310) AND source_type=0 AND id=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23310,0,4,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Portal Alarm - On respawn - set event phase 1");
UPDATE `smart_scripts` SET `event_phase_mask`=64 WHERE `entryorguid` IN (23310) AND `source_type`=0 AND `id` IN (2,3);
UPDATE `smart_scripts` SET `event_param3`=1000, `event_param4`=1000 WHERE `entryorguid` IN (23310) AND `source_type`=0 AND `id`=2;
UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=0, action_param1=1 WHERE `entryorguid` IN (23310) AND `source_type`=0 AND `id`=3; 
UPDATE `smart_scripts` SET `event_phase_mask`=63 WHERE `entryorguid` IN (23310) AND `source_type`=0 AND `id`=1;
