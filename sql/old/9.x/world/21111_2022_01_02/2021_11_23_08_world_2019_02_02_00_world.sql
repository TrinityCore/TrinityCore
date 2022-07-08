-- 
UPDATE `gameobject` SET `position_x`=1862.02, `position_y`=-6184.39, `position_z`=25.2394, `orientation`=2.24799 WHERE `guid`=150054;

DELETE FROM `script_waypoint` WHERE `entry` IN (24156);
DELETE FROM `waypoints` WHERE `entry`=24156;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(24156,1,1860.67,-6181.49,24.4529,'Plaguehound Tracker'),
(24156,2,1867.4,-6174.74,24.0396,'Plaguehound Tracker'),
(24156,3,1878.91,-6171.04,23.8547,'Plaguehound Tracker'),
(24156,4,1883.01,-6168.53,23.7649,'Plaguehound Tracker'),
(24156,5,1891.14,-6168.5,23.7235,'Plaguehound Tracker'),
(24156,6,1899.65,-6170.57,23.6586,'Plaguehound Tracker'),
(24156,7,1908.06,-6170.44,23.6803,'Plaguehound Tracker'),
(24156,8,1911.27,-6173.19,24.0866,'Plaguehound Tracker'),
(24156,9,1930.91,-6177,24.3168,'Plaguehound Tracker'),
(24156,10,1954.76,-6182.63,24.1432,'Plaguehound Tracker'),
(24156,11,1987.13,-6178.86,23.131,'Plaguehound Tracker'),
(24156,12,2006.38,-6170.3,15.3212,'Plaguehound Tracker'),
(24156,13,2009.97,-6164.83,15.7361,'Plaguehound Tracker'),
(24156,14,2014.19,-6158.24,13.2915,'Plaguehound Tracker'),
(24156,15,2013.73,-6145.65,7.8703,'Plaguehound Tracker'),
(24156,16,2041.4,-6116.02,4.79356,'Plaguehound Tracker'),
(24156,17,2058.39,-6112.69,5.85019,'Plaguehound Tracker'),
(24156,18,2086.18,-6103.4,6.93077,'Plaguehound Tracker'),
(24156,19,2098.62,-6101.4,4.95018,'Plaguehound Tracker'),
(24156,20,2114.68,-6098.66,5.20728,'Plaguehound Tracker'),
(24156,21,2126.52,-6101.74,6.62395,'Plaguehound Tracker'),
(24156,22,2159.06,-6109.57,3.01272,'Plaguehound Tracker'),
(24156,23,2201.07,-6110.33,1.05585,'Plaguehound Tracker'),
(24156,24,2225.83,-6096.46,0.541609,'Plaguehound Tracker'),
(24156,25,2238.62,-6077.75,2.62115,'Plaguehound Tracker'),
(24156,26,2258.13,-6060.8,1.93668,'Plaguehound Tracker'),
(24156,27,2267.67,-6056.66,1.2167,'Plaguehound Tracker'),
(24156,28,2287.67,-6048.15,1.24615,'Plaguehound Tracker'),
(24156,29,2307.23,-6024.91,2.63326,'Plaguehound Tracker'),
(24156,30,2306.47,-6023.57,2.82203,'Plaguehound Tracker'),
(24156,31,2299.93,-6026.67,2.35618,'Plaguehound Tracker'),
(24156,32,2289.84,-6040.9,2.20458,'Plaguehound Tracker'),
(24156,33,2267.99,-6056.47,1.22536,'Plaguehound Tracker');

-- Plaguehound Tracker (24156)
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=24156;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24156 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24156,0,0,0,54,0,100,0,0,0,0,0,0,53,0,24156,0,0,0,0,1,0,0,0,0,0,0,0,0,"Plaguehound Tracker - On Just Spawned - Start Waypoint'"),
(24156,0,1,0,40,0,100,0,8,24156,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Plaguehound Tracker - On Waypoint 8 Reached - set run on"),
(24156,0,2,0,40,0,100,0,8,24156,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Plaguehound Tracker - On Waypoint 8 Reached - Say emote"),
(24156,0,3,0,40,0,100,0,8,24156,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Plaguehound Tracker - On Waypoint 8 Reached - Paussse wp"),
(24156,0,4,0,40,0,100,0,30,24156,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Plaguehound Tracker - On Waypoint 30 Reached - Say emote"),
(24156,0,5,0,40,0,100,0,30,24156,0,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Plaguehound Tracker - On Waypoint 30 Reached - Paussse wp"),
(24156,0,6,0,40,0,100,0,33,24156,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Plaguehound Tracker - On Waypoint 33 Reached - Despawn");

DELETE FROM `creature_text` WHERE `CreatureID`=24156;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24156,0,0,"The hound appears to pick up a scent from the north and prepares to sprint to its source.",16,0,100,0,0,0,22843,0,'Plaguehound Tracker'),
(24156,1,0,"Upon reaching its destination the hound becomes startled by noise up ahead and appears ready to flee.",16,0,100,0,0,0,22844,0,'Plaguehound Tracker');
