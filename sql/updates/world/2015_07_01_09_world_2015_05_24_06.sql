-- DB/Quest: Escape from the Staging Grounds
DELETE FROM `waypoints` WHERE `entry`=20763;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(20763, 1, 4081.3, 2296.6, 110.75),
(20763, 2, 4095.3, 2296.37, 108.392),
(20763, 3, 4123.42, 2297.51, 104.368),
(20763, 4, 4146.48, 2298.85, 102.475),
(20763, 5, 4169.75, 2301.11, 104.503),
(20763, 6, 4181.37, 2301.19, 108.692),
(20763, 7, 4195.51, 2301.28, 113.981),
(20763, 8, 4215.69, 2295.79, 122.162),
(20763, 9, 4229.79, 2295.09, 127.068),
(20763, 10, 4250.86, 2293.49, 128.848),
(20763, 11, 4271.72, 2290, 125.243),
(20763, 12, 4277.21, 2276.97, 125.337),
(20763, 13, 4269.13, 2262.97, 127.868),
(20763, 14, 4262.07, 2250.73, 131.257),
(20763, 15, 4253.95, 2236.66, 134.959),
(20763, 16, 4249.61, 2220.86, 137.445),
(20763, 17, 4251.74, 2186.12, 137.08),
(20763, 18, 4252, 2172.27, 137.678);

-- Captured Protectorate Vanguard SAI
SET @ENTRY := 20763;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,10425,0,0,0,1,0,0,0,0,0,0,21,10,0,0,0,0,0,0,"Captured Protectorate Vanguard - On Quest 'Escape from the Staging Grounds' Taken - Say Line 0"),
(@ENTRY,0,1,2,61,0,100,0,10425,0,0,0,53,0,20763,0,0,0,2,1,0,0,0,0,0,0,0,"Captured Protectorate Vanguard - On Quest 'Escape from the Staging Grounds' Taken - Start Waypoint"),
(@ENTRY,0,2,14,61,0,100,0,10425,0,0,0,64,1,0,0,0,0,0,21,10,0,0,0,0,0,0,"Captured Protectorate Vanguard - On Quest 'Escape from the Staging Grounds' Taken - Store Targetlist"),
(@ENTRY,0,7,0,40,0,100,0,16,20763,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Protectorate Vanguard - On Waypoint 16 Reached - Pause Waypoint"),
(@ENTRY,0,8,10,40,0,100,0,17,20763,0,0,15,10425,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Protectorate Vanguard - On Waypoint 17 Reached - Quest Credit 'Escape from the Staging Grounds'"),
(@ENTRY,0,9,0,6,0,100,0,0,0,0,0,6,10425,0,0,0,0,0,12,1,0,0,0,0,0,0,"Captured Protectorate Vanguard - On Just Died - Fail Quest 'Escape from the Staging Grounds'"),
(@ENTRY,0,10,0,61,0,100,0,17,20763,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Protectorate Vanguard - On Waypoint 17 Reached - Say Line 1"),
(@ENTRY,0,11,12,40,0,100,0,18,20763,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Protectorate Vanguard - On Waypoint 18 Reached - Say Line 2"),
(@ENTRY,0,12,13,61,0,100,0,18,20763,0,0,11,35517,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Protectorate Vanguard - On Waypoint 18 Reached - Cast 'Teleport'"),
(@ENTRY,0,13,0,61,0,100,0,18,20763,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Protectorate Vanguard - On Waypoint 18 Reached - Despawn In 3000 ms"),
(@ENTRY,0,14,0,61,0,100,0,10425,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Protectorate Vanguard - On Quest 'Escape from the Staging Grounds' Taken - Set Npc Flag "),
(@ENTRY,0,15,0,11,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Protectorate Vanguard - On Respawn - Set Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `entry`=20763;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(20763, 0, 0, 'We''re not too far from the Protectorate Watch Post, $n. This way!', 12, 0, 100, 0, 0, 0, 18566, 'Captured Protectorate Vanguard to Player'),
(20763, 1, 0, 'Commander! This fleshling rescued me!', 12, 0, 100, 0, 0, 0, 18567, 'Captured Protectorate Vanguard to Player'),
(20763, 2, 0, '%s salutes Commander Ameer.', 16, 0, 100, 0, 0, 0, 18568, 'Captured Protectorate Vanguard to Player');
