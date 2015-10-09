-- 
UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry`=2983;
-- The Plains Vision SAI
SET @ENTRY := 2983;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,53,1,2983,0,0,0,0,1,0,0,0,0,0,0,0,"The Plains Vision - On Just Summoned - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,50,2983,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Plains Vision - On Waypoint 50 Reached - Despawn In 1000 ms");

DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@ENTRY, 1, -2226.32, -408.095, -9.36235, 'The Plains Vision'), 
(@ENTRY, 2, -2203.04, -437.212, -5.72498, 'The Plains Vision'),  
(@ENTRY, 3, -2163.91, -457.851, -7.09049, 'The Plains Vision'),
(@ENTRY, 4, -2123.87, -448.137, -9.29591, 'The Plains Vision'),    
(@ENTRY, 5, -2104.66, -427.166, -6.49513, 'The Plains Vision'),  
(@ENTRY, 6, -2101.48, -422.826, -5.3567, 'The Plains Vision'),   
(@ENTRY, 7, -2097.56, -417.083, -7.16716, 'The Plains Vision'),   
(@ENTRY, 8, -2084.87, -398.626, -9.88973, 'The Plains Vision'),
(@ENTRY, 9, -2072.71, -382.324, -10.2488, 'The Plains Vision'),  
(@ENTRY, 10, -2054.05, -356.728, -6.22468, 'The Plains Vision'),
(@ENTRY, 11, -2051.8, -353.645, -5.35791, 'The Plains Vision'), 
(@ENTRY, 12, -2049.08, -349.912, -6.15723, 'The Plains Vision'), 
(@ENTRY, 13, -2030.6, -310.724, -9.59302, 'The Plains Vision'),    
(@ENTRY, 14, -2002.15, -249.308, -10.8124, 'The Plains Vision'), 
(@ENTRY, 15, -1972.85, -195.811, -10.6316, 'The Plains Vision'),
(@ENTRY, 16, -1940.93, -147.652, -11.7055, 'The Plains Vision'),
(@ENTRY, 17, -1888.06, -81.943, -11.4404, 'The Plains Vision'), 
(@ENTRY, 18, -1837.05, -34.0109, -12.258, 'The Plains Vision'), 
(@ENTRY, 19, -1796.12, -14.6462, -10.3581, 'The Plains Vision'), 
(@ENTRY, 20, -1732.61, -4.27746, -10.0213, 'The Plains Vision'), 
(@ENTRY, 21, -1688.94, -0.829945, -11.7103, 'The Plains Vision'), 
(@ENTRY, 22, -1681.32, 13.0313, -9.48056, 'The Plains Vision'), 
(@ENTRY, 23, -1677.04, 36.8349, -7.10318, 'The Plains Vision'), 
(@ENTRY, 24, -1675.2, 68.559, -8.95384, 'The Plains Vision'),
(@ENTRY, 25, -1676.57, 89.023, -9.65104, 'The Plains Vision'), 
(@ENTRY, 26, -1678.16, 110.939, -10.1782, 'The Plains Vision'), 
(@ENTRY, 27, -1677.86, 128.681, -5.73869, 'The Plains Vision'), 
(@ENTRY, 28, -1675.27, 144.324, -3.47916, 'The Plains Vision'), 
(@ENTRY, 29, -1671.7, 163.169, -1.23098, 'The Plains Vision'),
(@ENTRY, 30, -1666.61, 181.584, 5.26145, 'The Plains Vision'), 
(@ENTRY, 31, -1661.51, 196.154,  8.95252, 'The Plains Vision'), 
(@ENTRY, 32, -1655.47, 210.811, 8.38727, 'The Plains Vision'), 
(@ENTRY, 33, -1647.07, 226.947, 5.27755, 'The Plains Vision'), 
(@ENTRY, 34, -1621.65, 232.91, 2.69579, 'The Plains Vision'), 
(@ENTRY, 35, -1600.23, 237.641, 2.98539, 'The Plains Vision'),
(@ENTRY, 36, -1576.07, 242.546, 4.66541, 'The Plains Vision'),
(@ENTRY, 37, -1554.57, 248.494, 6.60377, 'The Plains Vision'), 
(@ENTRY, 38, -1547.53, 259.302, 10.6741, 'The Plains Vision'),
(@ENTRY, 39, -1541.7, 269.847, 16.4418, 'The Plains Vision'), 
(@ENTRY, 40, -1539.83, 278.989, 21.0597, 'The Plains Vision'),
(@ENTRY, 41, -1540.16, 290.219, 27.8247, 'The Plains Vision'), 
(@ENTRY, 42, -1538.99, 298.983, 34.0032, 'The Plains Vision'),
(@ENTRY, 43, -1540.38, 307.337, 41.3557, 'The Plains Vision'), 
(@ENTRY, 44, -1536.61, 314.884, 48.0179, 'The Plains Vision'),
(@ENTRY, 45, -1532.42, 323.277, 55.6667, 'The Plains Vision'),
(@ENTRY, 46, -1528.77, 329.774, 61.1525, 'The Plains Vision'), 
(@ENTRY, 47, -1525.65, 333.18, 63.2161, 'The Plains Vision'),  
(@ENTRY, 48, -1517.01, 350.713, 62.4286, 'The Plains Vision'), 
(@ENTRY, 49, -1511.39, 362.537, 62.4539, 'The Plains Vision'), 
(@ENTRY, 50, -1508.68, 366.822, 62.733, 'The Plains Vision');  
