--
DELETE FROM `waypoints` WHERE `entry` IN (14121);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(14121, 1, 44.334, 1180.138, -121.573, 'Deeprun Diver'),
(14121, 2, 33.919, 1141.767, -122.757, 'Deeprun Diver'),
(14121, 3, 45.891, 1193.066, -121.714, 'Deeprun Diver'),
(14121, 4, 55.744, 1206.163, -121.63, 'Deeprun Diver');
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid`=53790;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (14121);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-53790) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-53790, 0, 0, 0, 1, 0, 100, 1, 1, 1, 0, 0, 53, 0, 14121, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Deeprun Diver - ooc no repeat - Start wp'),
(-53790, 0, 1, 2, 40, 0, 100, 0, 4, 14121, 0, 0, 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Deeprun Diver - On wp reached - pause wp'),
(-53790, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 20, 179345, 10, 0, 0, 0, 0,0,'Deeprun Diver - On wp reached - activate object');
