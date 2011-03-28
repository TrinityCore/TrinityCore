-- SAI for Gor'drek
-- This will remove 2 waypoint scripts that were spamming errors
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=21117;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=21117;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (2111700,2111701);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- AI
(21117,0,0,0,23,0,100,0,12550,0,2000,2000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gor''drek - Add Lightning Shield Aura'),
(21117,0,1,0,11,0,100,0,0,0,0,0,53,0,21117,1,0,0,0,1,0,0,0,0,0,0,0, 'Gor''drek - Start WP movement'),
(21117,0,2,0,40,0,100,0,2,21117,0,0,80,2111700,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gor''drek - Load script at WP 2'),
(21117,0,3,0,40,0,100,0,4,21117,0,0,80,2111701,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gor''drek - Load script at WP 4'),
-- Script 1
(2111700,9,0,0,0,0,100,0,0,0,0,0,54,128000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gor''drek - Pause at WP 2'),
(2111700,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.654867, 'Gor''drek - Turn to 5.654867'),
(2111700,9,2,0,0,0,100,0,2000,2000,0,0,11,28892,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gor''drek - Cast 42837'),
(2111700,9,3,0,0,0,100,0,120000,120000,0,0,92,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gor''drek - Stop Casting 42837'),
-- Script 2
(2111701,9,0,0,0,0,100,0,0,0,0,0,54,128000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gor''drek - Pause at WP 2'),
(2111701,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.677482, 'Gor''drek - Turn to 4.677482'),
(2111701,9,2,0,0,0,100,0,2000,2000,0,0,11,28892,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gor''drek - Cast 42837'),
(2111701,9,3,0,0,0,100,0,120000,120000,0,0,92,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gor''drek - Stop Casting 42837');
-- Update position and remove path for Gor'drek
UPDATE `creature` SET `position_x`=2313.006,`position_y`=6004.879,`position_z`=142.8264,`orientation`=4.677482,`MovementType`=0 WHERE `guid`=74168;
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid`=74168;
DELETE FROM `waypoint_data` WHERE `id`=741680;
DELETE FROM `waypoint_scripts` WHERE `id` IN (224,225);
-- Remove EAI
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=21117;
-- Proper waypoints for Gor'drek from sniff
DELETE FROM `waypoints` WHERE `entry`=21117;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(21117,1,2319.757,6007.015,142.7014,'Gor''drek WP 1'),
(21117,2,2325.909,6010.899,142.5764,'Gor''drek WP 2'),
(21117,3,2319.757,6007.015,142.7014,'Gor''drek WP 3'),
(21117,4,2313.006,6004.879,142.8264,'Gor''drek WP 4');
