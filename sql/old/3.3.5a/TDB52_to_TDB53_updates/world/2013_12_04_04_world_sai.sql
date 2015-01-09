-- Fix SAI script for Denalan
DELETE FROM `smart_scripts` WHERE `entryorguid`=208000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(208000,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,9507.291,714.583,1255.89,2.5643, 'Denalan - Script - Move'),
(208000,9,1,0,0,0,100,0,100,100,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Denalan - Script - Say 0'),
(208000,9,2,0,0,0,100,0,500,500,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Script - Remove questgiver flag'),
(208000,9,3,0,0,0,100,0,6500,6500,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Script - Play emote'),
(208000,9,4,0,0,0,100,0,9500,9500,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Denalan - Script - Turn to player'),
(208000,9,5,0,0,0,100,0,100,100,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Denalan - Script - Say 1'),
(208000,9,6,0,0,0,100,0,10000,10000,0,0,69,0,0,0,0,0,0,14,0,0,0,9506.866,713.7188,1255.885,0.6457718, 'Denalan - Script - Move'),
(208000,9,7,0,0,0,100,0,8000,8000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Denalan - Script - Add questgiver flag');
-- Fix emotes for Denalan text
UPDATE `creature_text` SET `emote`=0 WHERE `entry`=2080 AND `groupid`=0;
UPDATE `creature_text` SET `emote`=2 WHERE `entry`=2080 AND `groupid`=1;
