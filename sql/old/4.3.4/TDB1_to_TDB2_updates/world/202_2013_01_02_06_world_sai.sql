DELETE FROM `gameobject_scripts` WHERE `id`=12148;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (17156,17157);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17156,17157) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Stonewraught Gate
(17156,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,30084,150138,0,0,0,0,0,'Door lever - On activate - Activate Door'), -- autoclose is set to 3s, old script suggested 15s !?
(17157,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14, 6943,150137,0,0,0,0,0,'Door lever - On activate - Activate Door'); -- autoclose is set to 3s, old script suggested 15s !?
-- uldaman shit
DELETE FROM `gameobject_scripts` where `id` =14393; -- the keystone already has a cpp, if the door doesnt open, then add it there!
