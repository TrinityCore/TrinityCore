-- Pathing for Thulrin SAI
-- Remove old waypoint data and scripts
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=2352.691,`position_y`=5268.956,`position_z`=7.668962 WHERE `guid`=110115;
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid`=110115;
DELETE FROM `waypoint_data` WHERE `id`=1101150;
DELETE FROM waypoint_scripts WHERE `id` BETWEEN 1117 AND 1119;
-- SAI for Thulrin
UPDATE `creature_template` SET `AIName`='SmartAI',`equipment_id`=0 WHERE `entry`=25239;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=25239;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (2523900,2523901);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- AI
(25239,0,0,0,11,0,100,0,0,0,0,0,53,0,25239,1,0,0,0,1,0,0,0,0,0,0,0, 'Thulrin - Start WP movement'),
(25239,0,1,0,40,0,100,0,4,25239,0,0,80,2523900,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thulrin - Load script 1 at WP 4'),
(25239,0,2,0,40,0,100,0,9,25239,0,0,80,2523901,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thulrin - Load script 2 at WP 9'),
-- Script 1
(2523900,9,0,0,0,0,100,0,0,0,0,0,54,1500,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thulrin - Pause at WP 4'),
(2523900,9,1,0,0,0,100,0,0,0,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thulrin - Emote ONESHOT_KNEEL'),
(2523900,9,2,0,0,0,100,0,1000,1000,0,0,71,344,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thulrin - Equip sword'),
-- Script 2
(2523901,9,0,0,0,0,100,0,0,0,0,0,54,51000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thulrin - Pause at WP 9'),
(2523901,9,1,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.984513, 'Thulrin - Turn to pos'),
(2523901,9,2,0,0,0,100,0,1000,1000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thulrin - Emote STATE_USESTANDING_NOSHEATHE'),
(2523901,9,3,0,0,0,100,0,48000,48000,0,0,71,10000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thulrin - Equip nothing'),
(2523901,9,4,0,0,0,100,0,0,0,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thulrin - Emote STATE_STAND');
-- Waypoints for Thulrin from sniff
DELETE FROM `waypoints` WHERE `entry`=25239;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(25239,1,2347.805,5265.343,7.630844, 'Thulrin WP 1'),
(25239,2,2344.542,5267.178,7.668962, 'Thulrin WP 2'),
(25239,3,2340.221,5270.315,7.668962, 'Thulrin WP 3'),
(25239,4,2336.553,5273.868,7.793962, 'Thulrin WP 4'),
(25239,5,2339.075,5271.176,7.668962, 'Thulrin WP 5'),
(25239,6,2346.919,5265.093,7.630844, 'Thulrin WP 6'),
(25239,7,2351.8,5266.425,7.630844, 'Thulrin WP 7'),
(25239,8,2352.691,5268.956,7.668962, 'Thulrin WP 8'),
(25239,9,2352.691,5268.956,7.668962, 'Thulrin WP 9');
