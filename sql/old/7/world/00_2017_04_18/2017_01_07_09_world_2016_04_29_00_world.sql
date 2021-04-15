-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=29796;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29796 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29796,0,0,0,19,0,100,0,12886,0,0,0,85,55253,0,0,0,0,0,7,0,0,0,0,0,0,0,'Gretta the Arbiter - On quest accept - cast Spell');

DELETE FROM `smart_scripts` WHERE `entryorguid`=29694 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29694, 0, 0, 0, 0, 0, 100, 0, 2000, 5000, 10000, 15000, 11, 32736, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Hyldsmeet Drakerider - In Combat - Cast 'Mortal Strike'"),
(29694, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 33, 29800, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Hyldsmeet Drakerider - On Death - Kill credit Spell");

UPDATE `creature_template` SET  `AIName`='SmartAI', `InhabitType`=4, `speed_run`=3.2 WHERE `entry` IN (29679);
DELETE FROM `smart_scripts` WHERE `entryorguid`=29679 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29679, 0, 0, 0, 27, 0, 100, 0, 0, 0, 0, 0, 53, 1, 29679, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hyldsmeet Proto-Drake -  ON PASSENGER_BOARDED - Start waypoint');

DELETE FROM `creature_template_addon` WHERE `entry`=29679;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(29679, 0, 0, 33554432, 0, 0, '55971');

DELETE FROM `waypoints` WHERE `entry`=29679;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(29679,1,6985.165039, -1662.842163, 868.941956, 'Hyldsmeet Proto-Drake'),
(29679,2,6935.585449, -1516.853760, 968.493896, 'Hyldsmeet Proto-Drake'),
(29679,3,6926.762207, -1282.424927, 1127.864380, 'Hyldsmeet Proto-Drake'),
(29679,4,7365.684082, -644.429688, 1928.750610, 'Hyldsmeet Proto-Drake'),
(29679,5,7388.145508, -652.783569, 1909.863647, 'Hyldsmeet Proto-Drake'),
(29679,6,7439.698730, -661.380981, 1887.756714, 'Hyldsmeet Proto-Drake'),
(29679,7,7494.946777, -650.403015, 1883.039795, 'Hyldsmeet Proto-Drake'),
(29679,8,7548.416992, -601.006348, 1882.505737, 'Hyldsmeet Proto-Drake'),
(29679,9,7575.110352, -541.134949, 1881.668701, 'Hyldsmeet Proto-Drake'),
(29679,10,7550.558594, -458.574036, 1877.870972, 'Hyldsmeet Proto-Drake'),
(29679,11,7482.576172, -404.054077, 1878.095581, 'Hyldsmeet Proto-Drake'),
(29679,12,7390.999023, -404.312683, 1882.240234, 'Hyldsmeet Proto-Drake'),
(29679,13,7324.988770, -455.605713, 1874.051270, 'Hyldsmeet Proto-Drake'),
(29679,14,7289.477051, -552.180786, 1879.989258, 'Hyldsmeet Proto-Drake'),
(29679,15,7332.199707, -623.493713, 1887.427734, 'Hyldsmeet Proto-Drake'),
(29679,16,7367.857910, -647.534546, 1895.689453, 'Hyldsmeet Proto-Drake'),
(29679,17,7388.145508, -652.783569, 1909.863647, 'Hyldsmeet Proto-Drake'),
(29679,18,7439.698730, -661.380981, 1887.756714, 'Hyldsmeet Proto-Drake'),
(29679,19,7494.946777, -650.403015, 1883.039795, 'Hyldsmeet Proto-Drake'),
(29679,20,7548.416992, -601.006348, 1882.505737, 'Hyldsmeet Proto-Drake'),
(29679,21,7575.110352, -541.134949, 1881.668701, 'Hyldsmeet Proto-Drake'),
(29679,22,7550.558594, -458.574036, 1877.870972, 'Hyldsmeet Proto-Drake'),
(29679,23,7482.576172, -404.054077, 1878.095581, 'Hyldsmeet Proto-Drake'),
(29679,24,7390.999023, -404.312683, 1882.240234, 'Hyldsmeet Proto-Drake'),
(29679,25,7324.988770, -455.605713, 1874.051270, 'Hyldsmeet Proto-Drake'),
(29679,26,7289.477051, -552.180786, 1879.989258, 'Hyldsmeet Proto-Drake'),
(29679,27,7332.199707, -623.493713, 1887.427734, 'Hyldsmeet Proto-Drake'),
(29679,28,6926.762207, -1282.424927, 1127.864380, 'Hyldsmeet Proto-Drake'),
(29679,29,6935.585449, -1516.853760, 968.493896, 'Hyldsmeet Proto-Drake'),
(29679,30,6985.165039, -1662.842163, 868.941956, 'Hyldsmeet Proto-Drake'),
(29679,31,6998.042969, -1664.234253, 867.953247, 'Hyldsmeet Proto-Drake'),
(29679,32,7037.400879, -1725.409302, 838.695618, 'Hyldsmeet Proto-Drake'),
(29679,33,7076.637695, -1770.263184, 825.775391, 'Hyldsmeet Proto-Drake');
