-- 
UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry`=23616;
UPDATE `creature` SET `MovementType`=0 WHERE  `guid`=24762;
DELETE FROM `creature_addon` WHERE  `guid`=24762;
DELETE FROM `waypoint_data` WHERE `id`=247620; 
DELETE FROM `waypoints` WHERE `entry`=23616;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(23616, 1, -2454.94, -482.136, -8.97948, 'Kyle'),
(23616, 2, -2445.34, -476.395, -8.92086, 'Kyle'),
(23616, 3, -2433.79, -468.785, -9.20522, 'Kyle'),
(23616, 4, -2422.01, -460.858, -9.1759, 'Kyle'),
(23616, 5, -2407.47, -451.07, -8.70993, 'Kyle'),
(23616, 6, -2395.98, -443.42, -8.42222, 'Kyle'),
(23616, 7, -2383.8, -436.212, -8.78844, 'Kyle'),
(23616, 8, -2367.83, -425.967, -9.38671, 'Kyle'),
(23616, 9, -2355.15, -413.835, -9.75652, 'Kyle'),
(23616, 10, -2345.39, -403.032, -8.87064, 'Kyle'),
(23616, 11, -2338.73, -387.213, -7.97681, 'Kyle'),
(23616, 12, -2330.27, -374.08, -8.37519, 'Kyle'),
(23616, 13, -2314.64, -365.663, -9.41672, 'Kyle'),
(23616, 14, -2295.45, -360.874, -9.42468, 'Kyle'),
(23616, 15, -2279.85, -357.148, -9.42468, 'Kyle'),
(23616, 16, -2263.83, -363.376, -9.42468, 'Kyle'),
(23616, 17, -2248.52, -370.238, -9.42468, 'Kyle'),
(23616, 18, -2226.43, -386.156, -9.42468, 'Kyle'),
(23616, 19, -2232.14, -416.578, -9.42205, 'Kyle'),
(23616, 20, -2247.29, -439.615, -9.42475, 'Kyle'),
(23616, 21, -2252.91, -448.416, -9.09973, 'Kyle'),
(23616, 22, -2257.71, -455.921, -8.15442, 'Kyle'),
(23616, 23, -2271.66, -475.713, -7.80418, 'Kyle'),
(23616, 24, -2293.85, -483.264, -7.86093, 'Kyle'),
(23616, 25, -2302.71, -490.694, -7.92982, 'Kyle'),
(23616, 26, -2306.74, -494.585, -8.44247, 'Kyle'),
(23616, 27, -2324.17, -516.494, -9.32393, 'Kyle'),
(23616, 28, -2340.11, -535.209, -9.2326, 'Kyle'),
(23616, 29, -2357.69, -538.25, -9.158, 'Kyle'),
(23616, 30, -2372.68, -528.41, -9.15687, 'Kyle'),
(23616, 31, -2391.28, -518.477, -8.4459, 'Kyle'),
(23616, 32, -2404.81, -514.866, -7.4283, 'Kyle'),
(23616, 33, -2418.06, -510.431, -6.09458, 'Kyle'),
(23616, 34, -2431.22, -505.672, -6.06301, 'Kyle'),
(23616, 35, -2443.9, -499.738, -7.60161, 'Kyle'),
(23616, 36, -2462.4, -488.247, -9.27003, 'Kyle');

SET @ENTRY := 23616;
SET @Friendly:= 23622;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`IN (@ENTRY, @Friendly);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Friendly AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Friendly*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,1,23616,1,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Frenzied - On Reset - Start Waypoint"),
(@ENTRY,0,1,2,8,0,100,0,42222,0,55000,55000,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kyle the Frenzied - On Spellhit 'Lunch for Kyle' - Store Targetlist"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Frenzied - On Spellhit 'Lunch for Kyle' - Run Script");

-- Actionlist SAI
SET @ENTRY := 2361600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,55000,0,0,0,0,0,1,186265,50,0,0,0,0,0,"Kyle the Frenzied - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Frenzied - On Script - Say Line 0 (No Repeat)"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,17,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Frenzied - On Script - Set Emote State 393"),
(@ENTRY,9,3,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,20,186265,50,0,0,0,0,0,"Kyle the Frenzied - On Script - Move To Closest Gameobject 'Kyle's Lunch'"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Frenzied - On Script - Say Line 1"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Frenzied - On Script - Set Emote State 69"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,0,0,12,@Friendly,8,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Summon Kyle the Friendly"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Despawn"),

(@Friendly,0,0,0,25,0,100,0,0,0,0,0,80,@Friendly*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Friendly - On Reset - Run Script"),
(@Friendly*100,9,0,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Friendly - On Script - Say Line 2"),
(@Friendly*100,9,1,0,0,0,100,0,0,0,0,0,17,400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Friendly - On Script - Set Emote State 400"),
(@Friendly*100,9,2,0,0,0,100,0,0,0,0,0,33,23616,0,0,0,0,0,21,10,0,0,0,0,0,0,"Kyle the Friendly - On Script - Quest Credit 'Kyle's Gone Missing!'"),
(@Friendly*100,9,3,0,0,0,100,0,30000,30000,0,0,70,0,0,0,0,0,0,10,24762,23616,0,0,0,0,0,"Kyle the Friendly - On Script - respawn Kyle the Frenzied"),
(@Friendly*100,9,4,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyle the Friendly -On Script - Despawn");
