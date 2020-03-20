-- 
DELETE FROM `creature` WHERE `guid`=85786 AND `id`=9098;
DELETE FROM `linked_respawn` WHERE `guid` IN (85786);

UPDATE `creature_template` SET `RegenHealth`=0 WHERE `entry` IN (13020);
UPDATE `creature` SET `curhealth`=999300 WHERE `id` IN (13020);

UPDATE `creature` SET `unit_flags`=768 WHERE `guid` IN (84605, 84616, 84606, 84603, 84615, 84614);
DELETE FROM `areatrigger_scripts` WHERE `entry`= 3626;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (3626, "SmartTrigger");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-84605, -84616, -84606, -84603, -84615, -84614) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3626) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3626,2,0,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,84605,13996,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(3626,2,1,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,84616,13996,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(3626,2,2,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,84606,13996,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(3626,2,3,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,84603,13996,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(3626,2,4,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,84615,13996,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(3626,2,5,0,46,0,100,0,3626,0,0,0,45,1,1,0,0,0,0,10,84614,13996,0,0,0,0,0,"Area trigger 3626 - On area trigger - Set data"),
(-84605,0,0,0,38,0,100,1,1,1,0,0,53,1,1399600,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - Data set - Start waypoint"),
(-84605,0,1,0,58,0,100,1,0,1399600,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - On waypoint ended - Despawn"),
(-84616,0,0,0,38,0,100,1,1,1,0,0,53,1,1399600,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - Data set - Start waypoint"),
(-84616,0,1,0,58,0,100,1,0,1399600,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - On waypoint ended - Despawn"),
(-84606,0,0,0,38,0,100,1,1,1,0,0,53,1,1399600,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - Data set - Start waypoint"),
(-84606,0,1,0,58,0,100,1,0,1399600,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - On waypoint ended - Despawn"),
(-84603,0,0,0,38,0,100,1,1,1,0,0,53,1,1399601,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - Data set - Start waypoint"),
(-84603,0,1,0,58,0,100,1,0,1399601,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - On waypoint ended - Despawn"),
(-84615,0,0,1,38,0,100,1,1,1,0,0,53,1,1399601,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - Data set - Start waypoint"),
(-84615,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - Data set - Say text"),
(-84615,0,2,0,58,0,100,1,0,1399601,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - On waypoint ended - Despawn"),
(-84614,0,0,0,38,0,100,1,1,1,0,0,53,1,1399601,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - Data set - Start waypoint"),
(-84614,0,1,0,58,0,100,1,0,1399601,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Technician - On waypoint ended - Despawn");

DELETE FROM `waypoints` WHERE `entry` IN (1399600,1399601);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(1399600, 1, -7466.55, -1015.38, 408.566,"Blackwing Technician"),
(1399600, 2, -7453.62, -1019.73, 408.57,"Blackwing Technician"),
(1399600, 3, -7443.76, -1031.75, 408.613,"Blackwing Technician"),
(1399600, 4, -7436.59, -1037.8, 408.646,"Blackwing Technician"),
(1399600, 5, -7433.49, -1032.99, 408.641,"Blackwing Technician"),
(1399600, 6, -7436.15, -1025.96, 414.025,"Blackwing Technician"),
(1399600, 7, -7441.49, -1017.68, 423.096,"Blackwing Technician"),
(1399600, 8, -7443.33, -1015.06, 423.666,"Blackwing Technician"),
(1399600, 9, -7456.49, -996.301, 423.666,"Blackwing Technician"),
(1399600, 10, -7483.34, -962.278, 423.809,"Blackwing Technician"),
(1399600, 11, -7488.85, -962.927, 423.693,"Blackwing Technician"),
(1399600, 12, -7506.71, -972.992, 423.607,"Blackwing Technician"),
(1399600, 13, -7514.11, -974.566, 423.477,"Blackwing Technician"),
(1399600, 14, -7519.98, -969.585, 423.429,"Blackwing Technician"),
(1399600, 15, -7526.96, -961.592, 427.805,"Blackwing Technician"),
(1399601, 1, -7487.86, -1036.58, 408.562,"Blackwing Technician"),
(1399601, 2, -7490.35, -1046.43, 408.571,"Blackwing Technician"),
(1399601, 3, -7478.75, -1064.94, 408.633,"Blackwing Technician"),
(1399601, 4, -7483.2, -1069.96, 408.636 ,"Blackwing Technician"),
(1399601, 5, -7491.67, -1062.21, 415.998,"Blackwing Technician"),
(1399601, 6, -7496.75, -1054.78, 423.665,"Blackwing Technician"),
(1399601, 7, -7512.88, -1032.64, 423.665,"Blackwing Technician"),
(1399601, 8, -7531.46, -1007.4, 423.665,"Blackwing Technician"),
(1399601, 9, -7534.84, -997.096, 423.764,"Blackwing Technician"),
(1399601, 10, -7520.4, -979.642, 423.502,"Blackwing Technician"),
(1399601, 11, -7519.79, -976.306, 423.43,"Blackwing Technician"),
(1399601, 12, -7526.15, -964.647, 426.48,"Blackwing Technician"),
(1399601, 13, -7529.9, -959.013, 427.93,"Blackwing Technician");

DELETE FROM `creature_text` WHERE `CreatureID` IN (13996);
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(13996, 0, 0, 'Run! They are coming!', 14, 0, 100, 0, 0, 0, 9031, 'Blackwing Technician');
