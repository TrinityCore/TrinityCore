--
DELETE FROM `waypoints` WHERE `entry` = 20129;
DELETE FROM `waypoints` WHERE `entry` BETWEEN 2012900 AND 2012905;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(2012900,1,-8383.2,-4244.22,-206.636,0,0,"Custodian of Time"),
(2012900,2,-8401.54,-4229.18,-206.776,0,0,"Custodian of Time"),
(2012900,3,-8431.32,-4205.24,-209.299,0,0,"Custodian of Time"),
(2012900,4,-8446.2,-4199.22,-211.198,0,0,"Custodian of Time"),

(2012901,1,-8458.11,-4211.28,-213.04,0,0,"Custodian of Time"),
(2012901,2,-8474.04,-4211.07,-214.483,0,0,"Custodian of Time"),
(2012901,3,-8496.17,-4213.95,-214.466,0,0,"Custodian of Time"),
(2012901,4,-8535.09,-4218.91,-213.081,0,0,"Custodian of Time"),
(2012901,5,-8570.05,-4231.13,-211.343,0,0,"Custodian of Time"),
(2012901,6,-8598.16,-4247.17,-210.842,0,0,"Custodian of Time"),
(2012901,7,-8627.35,-4268.63,-210.4,0,0,"Custodian of Time"),

(2012902,1,-8621.29,-4292.29,-210.653,0,0,"Custodian of Time"),
(2012902,2,-8607.38,-4337.51,-211.931,0,0,"Custodian of Time"),

(2012903,1,-8577.15,-4359.43,-214.543,0,0,"Custodian of Time"),
(2012903,2,-8561.28,-4380.34,-215.375,0,0,"Custodian of Time"),
(2012903,3,-8540.86,-4399.46,-216.243,0,0,"Custodian of Time"),
(2012903,4,-8523.85,-4407.74,-216.447,0,0,"Custodian of Time"),

(2012904,1,-8488.36,-4429.71,-215.938,0,0,"Custodian of Time"),
(2012904,2,-8443.82,-4427.04,-213.414,0,0,"Custodian of Time"),
(2012904,3,-8409.72,-4412.88,-211.283,0,0,"Custodian of Time"),
(2012904,4,-8379.64,-4393.75,-208.275,0,0,"Custodian of Time"),
(2012904,5,-8359.08,-4369.81,-208.167,0,0,"Custodian of Time"),
(2012904,6,-8358.58,-4360.84,-208.144,0,0,"Custodian of Time"),

(2012905,1,-8363,-4342.1,-208.549,0,0,"Custodian of Time"),
(2012905,2,-8367.57,-4306.75,-209.519,0,0,"Custodian of Time"),
(2012905,3,-8374,-4286.13,-208.73,0,0,"Custodian of Time");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 20129 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2012900 AND 2012906 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20129,0,0,0,11,0,100,0,0,0,0,0,0,80,2012900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Spawn - Run Script"),
(20129,0,1,0,58,0,100,0,0,2012900,0,0,0,80,2012901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Waypoint Finished - Run Script"),
(20129,0,2,0,58,0,100,0,0,2012901,0,0,0,80,2012902,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Waypoint Finished - Run Script"),
(20129,0,3,0,58,0,100,0,0,2012902,0,0,0,80,2012903,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Waypoint Finished - Run Script"),
(20129,0,4,0,58,0,100,0,0,2012903,0,0,0,80,2012904,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Waypoint Finished - Run Script"),
(20129,0,5,0,58,0,100,0,0,2012904,0,0,0,80,2012905,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Waypoint Finished - Run Script"),
(20129,0,6,0,58,0,100,0,0,2012905,0,0,0,80,2012906,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Waypoint Finished - Run Script"),

(2012900,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Set Orientation Owner"),
(2012900,9,1,0,0,0,100,0,0,0,0,0,0,11,17321,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Cast 'Spirit Spawn-in'"),
(2012900,9,2,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 0"),
(2012900,9,3,0,0,0,100,0,10000,10000,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 1"),
(2012900,9,4,0,0,0,100,0,15000,15000,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 2"),
(2012900,9,5,0,0,0,100,0,11000,11000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 3"),
(2012900,9,6,0,0,0,100,0,2000,2000,0,0,0,53,0,2012900,0,0,0,3,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Start Waypoint"),

(2012901,9,1,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Set Orientation Owner"),
(2012901,9,2,0,0,0,100,0,1000,1000,0,0,0,1,4,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 4"),
(2012901,9,3,0,0,0,100,0,10000,10000,0,0,0,1,5,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 5"),
(2012901,9,4,0,0,0,100,0,15000,15000,0,0,0,1,6,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 6"),
(2012901,9,5,0,0,0,100,0,10000,10000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,1.46607,"Custodian of Time - On Script - Set Orientation"),
(2012901,9,6,0,0,0,100,0,1000,1000,0,0,0,1,7,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 7"),
(2012901,9,7,0,0,0,100,0,6000,6000,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Play Emote 25"),
(2012901,9,8,0,0,0,100,0,12000,12000,0,0,0,1,8,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 8"),
(2012901,9,9,0,0,0,100,0,7000,7000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Set Orientation Owner"),
(2012901,9,10,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Play Emote 1"),
(2012901,9,11,0,0,0,100,0,14000,14000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 3"),
(2012901,9,12,0,0,0,100,0,6000,6000,0,0,0,53,0,2012901,0,0,0,3,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Start Waypoint"),

(2012902,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,2.58308,"Custodian of Time - On Script - Set Orientation"),
(2012902,9,2,0,0,0,100,0,2000,2000,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Play Emote 25"),
(2012902,9,3,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Set Orientation Owner"),
(2012902,9,4,0,0,0,100,0,1000,1000,0,0,0,1,9,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 9"),
(2012902,9,5,0,0,0,100,0,10000,10000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 3"),
(2012902,9,6,0,0,0,100,0,6000,6000,0,0,0,53,0,2012902,0,0,0,3,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Start Waypoint"),

(2012903,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.92699,"Custodian of Time - On Script - Set Orientation"),
(2012903,9,2,0,0,0,100,0,1000,1000,0,0,0,1,10,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 10"),
(2012903,9,3,0,0,0,100,0,3000,3000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Play Emote 1"),
(2012903,9,4,0,0,0,100,0,6000,6000,0,0,0,53,0,2012903,0,0,0,3,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Start Waypoint"),

(2012904,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Set Orientation Owner"),
(2012904,9,2,0,0,0,100,0,2000,2000,0,0,0,1,11,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 11"),
(2012904,9,3,0,0,0,100,0,20000,20000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 3"),
(2012904,9,4,0,0,0,100,0,6000,6000,0,0,0,53,0,2012904,0,0,0,3,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Start Waypoint"),

(2012905,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.19198,"Custodian of Time - On Script - Set Orientation"),
(2012905,9,2,0,0,0,100,0,1000,1000,0,0,0,1,12,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 12"),
(2012905,9,3,0,0,0,100,0,10000,10000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 3"),
(2012905,9,4,0,0,0,100,0,6000,6000,0,0,0,53,0,2012905,0,0,0,3,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Start Waypoint"),

(2012906,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Set Orientation Owner"),
(2012906,9,1,0,0,0,100,0,1000,1000,0,0,0,1,13,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 13"),
(2012906,9,2,0,0,0,100,0,0,0,0,0,0,11,34883,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Cast 'QID 10277'"),
(2012906,9,3,0,0,0,100,0,6000,6000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Despawn");
