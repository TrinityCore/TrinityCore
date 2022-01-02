-- 
UPDATE `gameobject` SET `spawntimesecs`=60 WHERE `id` IN (20351,19879);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (20352,19901);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20352,19901) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20352, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 0, 99, 2, 0, 0, 0, 0, 0, 20, 20351, 5, 0, 0, 0, 0, 0, 'Circle of Imprisonment - In Loot state change - Set loot state'),
(19901, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 0, 99, 2, 0, 0, 0, 0, 0, 20, 19879, 5, 0, 0, 0, 0, 0, 'Circle of Imprisonment - In Loot state change - Set loot state');
