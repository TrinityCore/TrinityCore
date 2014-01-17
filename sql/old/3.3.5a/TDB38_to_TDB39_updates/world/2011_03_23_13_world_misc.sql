-- Pathing for Chief Engineer Galpen Rolltie SAI
SET @ENTRY := 26600;
-- Remove old waypoint data and scripts
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=4136.725,`position_y`=5316.553,`position_z`=28.726,`orientation`=0.3286853 WHERE `guid`=117890;
-- SAI for Chief Engineer Galpen Rolltie
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- AI
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Chief Engineer Galpen Rolltie - On spawn - Start WP movement'),
(@ENTRY,0,1,2,40,0,100,0,1,@ENTRY,0,0,54,16000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Engineer Galpen Rolltie - Reach wp 1 - pause path'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Engineer Galpen Rolltie - Reach wp 1 - STATE_WORK_MINING'),
(@ENTRY,0,3,4,40,0,100,0,7,@ENTRY,0,0,54,9000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Engineer Galpen Rolltie - Reach wp 7 - pause path'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Engineer Galpen Rolltie - Reach wp 7 - STATE_WORK_MINING'),
(@ENTRY,0,5,6,40,0,100,0,15,@ENTRY,0,0,54,14000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Engineer Galpen Rolltie - Reach wp 15 - pause path'),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Engineer Galpen Rolltie - Reach wp 15 - STATE_WORK_MINING');
-- Waypoints for Chief Engineer Galpen Rolltie from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,4138.141,5318.302,28.81850, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,2,4140.475,5319.229,29.29604, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,3,4141.725,5323.979,29.04604, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,4,4139.975,5327.229,29.29604, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,5,4136.975,5328.229,29.29604, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,6,4134.975,5327.229,29.29604, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,7,4135.308,5325.655,28.77358, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,8,4135.063,5327.819,29.27233, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,9,4140.063,5327.819,29.27233, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,10,4143.313,5325.319,29.27233, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,11,4141.313,5317.819,29.77233, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,12,4137.063,5314.819,29.02233, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,13,4132.313,5316.569,29.02233, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,14,4130.313,5319.819,29.27233, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,15,4131.816,5320.484,28.77108, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,16,4130.521,5321.019,29.24854, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,17,4131.021,5317.769,29.24854, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,18,4133.771,5315.769,28.99854, 'Chief Engineer Galpen Rolltie'),
(@ENTRY,19,4136.725,5316.553,28.72600, 'Chief Engineer Galpen Rolltie');

-- Pathing for Willis Wobblewheel SAI
SET @ENTRY := 26599;
-- Remove old waypoint data and scripts
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=4135.779,`position_y`=5282.234,`position_z`=25.11416,`orientation`=1.19467 WHERE `guid`=117866;
-- SAI for Willis Wobblewheel
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ENTRY*100,@ENTRY*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Willis Wobblewheel - On spawn - Start WP movement'),
(@ENTRY,0,1,2,40,0,100,0,1,@ENTRY,0,0,54,17000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Willis Wobblewheel - Reach wp 1 - pause path'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Willis Wobblewheel - Reach wp 1 - STATE_WORK_MINING'),
(@ENTRY,0,3,4,40,0,100,0,3,@ENTRY,0,0,54,16000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Willis Wobblewheel - Reach wp 3 - pause path'),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.288348, 'Willis Wobblewheel - Reach wp 3 - turn to'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Willis Wobblewheel - Reach wp 1 - STATE_USESTANDING');
-- Waypoints for Willis Wobblewheel from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,4137.04,5285.097,25.23916, 'Willis Wobblewheel'),
(@ENTRY,2,4135.779,5282.234,25.11416, 'Willis Wobblewheel'),
(@ENTRY,3,4135.004,5281.168,25.11416, 'Willis Wobblewheel'),
(@ENTRY,4,4135.779,5282.234,25.11416, 'Willis Wobblewheel');

-- Pathing for Fizzcrank Watcher Rupert Keeneye SAI
SET @ENTRY := 26634;
-- Remove old waypoint data and scripts
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=4183.354,`position_y`=5318.837,`position_z`=58.1593 WHERE `guid`=97336;
-- SAI for Fizzcrank Watcher Rupert Keeneye
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ENTRY*100,@ENTRY*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Watcher Rupert Keeneye - On spawn - Start WP movement'),
(@ENTRY,0,1,0,40,0,100,0,2,@ENTRY,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Watcher Rupert Keeneye - Reach wp 2 - pause path'),
(@ENTRY,0,2,3,40,0,100,0,6,@ENTRY,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Watcher Rupert Keeneye - Reach wp 6 - pause path'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.8901179, 'Fizzcrank Watcher Rupert Keeneye - Reach wp 6 - turn to');
-- Waypoints for Fizzcrank Watcher Rupert Keeneye from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,4186.929,5321.105,58.13441, 'Fizzcrank Watcher Rupert Keeneye'),
(@ENTRY,2,4185.132,5318.713,58.1639, 'Fizzcrank Watcher Rupert Keeneye'),
(@ENTRY,3,4186.515,5316.936,58.15049, 'Fizzcrank Watcher Rupert Keeneye'),
(@ENTRY,4,4186.929,5321.105,58.13441, 'Fizzcrank Watcher Rupert Keeneye'),
(@ENTRY,5,4191.268,5319.607,58.12418, 'Fizzcrank Watcher Rupert Keeneye'),
(@ENTRY,6,4189.929,5324.715,58.08976, 'Fizzcrank Watcher Rupert Keeneye'),
(@ENTRY,7,4184.381,5325.549,58.05596, 'Fizzcrank Watcher Rupert Keeneye'),
(@ENTRY,8,4183.354,5318.837,58.1593, 'Fizzcrank Watcher Rupert Keeneye');
-- Fizzcrank Watcher Rupert Keeneye dupe spawn
DELETE FROM `creature` WHERE `guid`=97346;
DELETE FROM `creature_addon` WHERE `guid`=97346;

-- Pathing for Fizzcrank Engineering Crew SAI
SET @ENTRY := 26645;
SET @PATH  := @ENTRY*100;
SET @PATH2 := @ENTRY*100+1;
-- Remove old waypoint data and scripts
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=4153.918,`position_y`=5347.379,`position_z`=29.03030 WHERE `guid`=98042;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=4145.670,`position_y`=5329.370,`position_z`=28.68240 WHERE `guid`=98043;
-- SAI for Fizzcrank Engineering Crew
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-98042,-98043);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-98042,0,0,0,11,0,100,0,0,0,0,0,53,0,@PATH,1,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - On spawn - Start WP movement'),
(-98042,0,1,2,40,0,100,0,1,@PATH,0,0,54,16000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 1 - pause path'),
(-98042,0,2,0,61,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 1 - STATE_USESTANDING'),
(-98042,0,3,4,40,0,100,0,6,@PATH,0,0,54,19000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 6 - pause path'),
(-98042,0,4,0,61,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 6 - STATE_USESTANDING'),
(-98042,0,5,6,40,0,100,0,10,@PATH,0,0,54,16000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 10 - pause path'),
(-98042,0,6,0,61,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 10 - STATE_USESTANDING'),
(-98042,0,7,8,40,0,100,0,14,@PATH,0,0,54,24000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 14 - pause path'),
(-98042,0,8,0,61,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 14 - STATE_USESTANDING'),
(-98043,0,0,0,11,0,100,0,0,0,0,0,53,0,@PATH2,1,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - On spawn - Start WP movement'),
(-98043,0,1,2,40,0,100,0,5,@PATH2,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 5 - pause path'),
(-98043,0,2,0,61,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 5 - STATE_USESTANDING'),
(-98043,0,3,4,40,0,100,0,10,@PATH2,0,0,54,23000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 10 - pause path'),
(-98043,0,4,0,61,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 10 - STATE_WORK_MINING'),
(-98043,0,5,6,40,0,100,0,18,@PATH2,0,0,54,25000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 18 - pause path'),
(-98043,0,6,0,61,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 18 - STATE_WORK_MINING'),
(-98043,0,7,8,40,0,100,0,24,@PATH2,0,0,54,25000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 24 - pause path'),
(-98043,0,8,0,61,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Engineering Crew - Reach wp 24 - STATE_USESTANDING');
-- Waypoints for Fizzcrank Engineering Crew from sniff
DELETE FROM `waypoints` WHERE `entry` IN (@PATH,@PATH2);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@PATH,1,4153.728,5344.668,29.34072, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,2,4152.786,5345.597,29.62969, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,3,4157.786,5346.597,29.62969, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,4,4160.786,5343.097,30.37969, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,5,4158.286,5341.347,29.62969, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,6,4156.344,5341.525,29.41866, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,7,4158.535,5340.623,29.56693, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,8,4159.285,5338.123,29.06693, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,9,4157.035,5336.123,29.06693, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,10,4152.727,5336.721,28.71519, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,11,4152.224,5335.373,29.05804, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,12,4150.224,5335.873,29.05804, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,13,4148.974,5337.873,29.30804, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,14,4149.720,5343.525,28.90088, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,15,4148.819,5340.952,29.46559, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,16,4149.319,5336.702,29.21559, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,17,4154.319,5334.202,29.21559, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,18,4158.569,5336.702,28.96559, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,19,4160.819,5343.202,30.21559, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,20,4158.069,5347.202,29.71559, 'Fizzcrank Engineering Crew wp 1'),
(@PATH,21,4153.918,5347.379,29.03030, 'Fizzcrank Engineering Crew wp 1'),
(@PATH2,1,4147.00,5327.734,29.32715, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,2,4149.25,5326.734,29.07715, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,3,4151.50,5329.484,29.32715, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,4,4150.25,5330.734,29.32715, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,5,4148.829,5329.599,28.9719, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,6,4150.054,5331.477,29.32324, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,7,4152.054,5333.477,29.07324, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,8,4150.804,5335.727,29.07324, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,9,4147.554,5336.477,29.07324, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,10,4143.779,5335.355,28.67457, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,11,4146.732,5336.823,29.20758, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,12,4150.982,5335.573,29.20758, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,13,4153.232,5331.323,28.95758, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,14,4150.482,5326.823,28.70758, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,15,4144.732,5324.573,29.45758, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,16,4141.482,5326.823,29.20758, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,17,4139.686,5329.791,28.74058, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,18,4141.878,5331.735,28.69350, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,19,4141.274,5330.552,29.18795, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,20,4141.774,5328.302,29.18795, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,21,4142.774,5326.052,29.18795, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,22,4145.524,5326.052,29.43795, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,23,4146.774,5328.052,29.18795, 'Fizzcrank Engineering Crew wp 2'),
(@PATH2,24,4145.670,5329.370,28.68240, 'Fizzcrank Engineering Crew wp 2');
-- Fizzcrank Engineering Crew dupe spawn
DELETE FROM `creature` WHERE `guid`=98029;
DELETE FROM `creature_addon` WHERE `guid`=98029;

-- Pathing for Fizzcrank bomber Entry: 25765
SET @NPC := 111360;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4235.847,`position_y`=5353.55,`position_z`=81.03476 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4222.374,5370.328,72.03476,0,1,0,100,0),
(@PATH,2,4193.999,5364.787,66.81252,0,1,0,100,0),
(@PATH,3,4161.166,5319.937,66.81252,0,1,0,100,0),
(@PATH,4,4149.038,5289.545,66.81252,0,1,0,100,0),
(@PATH,5,4158.851,5255.303,66.81252,0,1,0,100,0),
(@PATH,6,4193.628,5230.504,79.17356,0,1,0,100,0),
(@PATH,7,4259.787,5211.473,79.20131,0,1,0,100,0),
(@PATH,8,4293.693,5221.593,80.20133,0,1,0,100,0),
(@PATH,9,4296.654,5282.716,82.20137,0,1,0,100,0),
(@PATH,10,4261.68,5314.814,89.8682,0,1,0,100,0),
(@PATH,11,4224.254,5366.333,98.86811,0,1,0,100,0),
(@PATH,12,4174.309,5345.78,98.86811,0,1,0,100,0),
(@PATH,13,4150.472,5287.501,98.86811,0,1,0,100,0),
(@PATH,14,4188.47,5251.628,102.757,0,1,0,100,0),
(@PATH,15,4241.055,5236.796,102.757,0,1,0,100,0),
(@PATH,16,4280.259,5260.132,105.6182,0,1,0,100,0),
(@PATH,17,4271.736,5301.975,105.6182,0,1,0,100,0),
(@PATH,18,4235.847,5353.55,81.03476,0,1,0,100,0);
-- Fizzcrank bomber dupe spawn
DELETE FROM `creature` WHERE `guid` IN (111361,111426);
DELETE FROM `creature_addon` WHERE `guid` IN (111361,111426);

-- Rig Hauler AC-9 SAI
SET @ENTRY := 25766;
UPDATE `creature` SET `position_x`=4170.335,`position_y`=5359.113,`position_z`=30.06447,`orientation`=2.740167 WHERE `guid`=111472;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,10000,210000,210000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rig Hauler AC-9 - OOC 3.5 min - start script 1'),
(@ENTRY,0,1,0,40,0,100,0,1,@ENTRY,0,0,45,0,1,0,0,0,0,11,25765,20,0,0,0,0,0, 'Rig Hauler AC-9 - Reach wp 1 - dataset 0 1 nearest Fizzcrank Bomber'),
(@ENTRY,0,2,3,40,0,100,0,5,@ENTRY,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rig Hauler AC-9 - Reach wp 5 - pause wp'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,92,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rig Hauler AC-9 - Reach wp 5 - INTERRUPT_SPELL'),
(@ENTRY,0,4,0,40,0,100,0,6,@ENTRY,0,0,45,0,1,0,0,0,0,10,106069,15214,0,0,0,0,0, 'Rig Hauler AC-9 - Reach wp 6 - dataset 0 1 Invisable Stalker'),
(@ENTRY,0,5,0,40,0,100,0,25,@ENTRY,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.740167, 'Rig Hauler AC-9 - Reach wp 25 - turn to'),
-- Script
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,12,25765,3,360000,0,0,0,8,0,0,0,4165.76,5354.39,30.1116,2.35619, 'Rig Hauler AC-9 - script - summon 25765'),
(@ENTRY*100,9,1,0,0,0,100,0,6000,6000,0,0,11,45967,0,0,0,0,0,11,25765,10,0,0,0,0,0, 'Rig Hauler AC-9 - script - cast 45967'),
(@ENTRY*100,9,2,0,0,0,100,0,3000,3000,0,0,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0, 'Rig Hauler AC-9 - script - Start WP movement');
-- Waypoints for Rig Hauler AC-9 from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,4149.316,5357.732,29.11953, 'Rig Hauler AC-9'),
(@ENTRY,2,4136.816,5345.482,29.11953, 'Rig Hauler AC-9'),
(@ENTRY,3,4125.566,5333.982,29.11953, 'Rig Hauler AC-9'),
(@ENTRY,4,4115.297,5323.852,28.67458, 'Rig Hauler AC-9'),
(@ENTRY,5,4108.158,5316.849,28.75930, 'Rig Hauler AC-9'),
(@ENTRY,6,4111.660,5313.279,28.75930, 'Rig Hauler AC-9'),
(@ENTRY,7,4112.747,5314.946,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,8,4116.997,5314.946,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,9,4118.997,5316.946,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,10,4125.247,5323.196,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,11,4127.247,5325.196,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,12,4129.497,5326.696,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,13,4131.497,5328.446,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,14,4133.497,5328.446,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,15,4134.747,5329.446,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,16,4135.747,5333.696,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,17,4141.997,5337.196,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,18,4143.997,5341.946,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,19,4145.997,5344.946,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,20,4147.247,5346.196,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,21,4150.247,5348.196,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,22,4152.247,5350.196,29.16189, 'Rig Hauler AC-9'),
(@ENTRY,23,4162.747,5356.196,29.66189, 'Rig Hauler AC-9'),
(@ENTRY,24,4166.997,5358.696,30.41189, 'Rig Hauler AC-9'),
(@ENTRY,25,4170.335,5359.113,30.06447, 'Rig Hauler AC-9');
-- Rig Hauler AC-9 dupe spawn
DELETE FROM `creature` WHERE `guid`=111501;
DELETE FROM `creature_addon` WHERE `guid`=111501;

-- Fizzcrank Bomber SAI
SET @ENTRY := 25765;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,0,1,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Bomber - on dataset 0 1 - dataset 0 0'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Bomber - on dataset 0 1 - Start WP movement'),
(@ENTRY,0,2,3,40,0,100,0,22,@ENTRY,0,0,54,45000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Bomber - Reach wp 22 - pause wp'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Bomber - Reach wp 22 - Set Speed run'),
(@ENTRY,0,4,5,40,0,100,0,74,@ENTRY,0,0,11,47460,3,0,0,0,0,11,26817,5,0,0,0,0,0, 'Fizzcrank Bomber - Reach wp 74 - cast 47460 on Fizzcrank fighter'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Bomber - Reach wp 74 - despawn');
-- Waypoints for Fizzcrank Bomber from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,4164.758,5354.723,30.19215, 'Fizzcrank Bomber wp 1'),
(@ENTRY,2,4162.034,5355.368,30.09748, 'Fizzcrank Bomber wp 1'),
(@ENTRY,3,4159.190,5355.827,30.01153, 'Fizzcrank Bomber wp 1'),
(@ENTRY,4,4156.273,5356.132,29.94405, 'Fizzcrank Bomber wp 1'),
(@ENTRY,5,4154.659,5355.736,29.91132, 'Fizzcrank Bomber wp 1'),
(@ENTRY,6,4152.153,5354.786,29.86976, 'Fizzcrank Bomber wp 1'),
(@ENTRY,7,4149.633,5353.545,29.83581, 'Fizzcrank Bomber wp 1'),
(@ENTRY,8,4147.138,5352.081,29.80874, 'Fizzcrank Bomber wp 1'),
(@ENTRY,9,4144.689,5350.449,29.78749, 'Fizzcrank Bomber wp 1'),
(@ENTRY,10,4142.290,5348.694,29.77098, 'Fizzcrank Bomber wp 1'),
(@ENTRY,11,4139.963,5346.840,29.76581, 'Fizzcrank Bomber wp 1'),
(@ENTRY,12,4137.673,5344.909,29.76182, 'Fizzcrank Bomber wp 1'),
(@ENTRY,13,4135.418,5342.924,29.75874, 'Fizzcrank Bomber wp 1'),
(@ENTRY,14,4133.194,5340.901,29.75638, 'Fizzcrank Bomber wp 1'),
(@ENTRY,15,4130.993,5338.848,29.75706, 'Fizzcrank Bomber wp 1'),
(@ENTRY,16,4128.794,5336.785,29.75758, 'Fizzcrank Bomber wp 1'),
(@ENTRY,17,4126.612,5334.716,29.75798, 'Fizzcrank Bomber wp 1'),
(@ENTRY,18,4124.430,5332.629,29.75829, 'Fizzcrank Bomber wp 1'),
(@ENTRY,19,4121.542,5329.849,29.75858, 'Fizzcrank Bomber wp 1'),
(@ENTRY,20,4118.184,5326.597,29.75881, 'Fizzcrank Bomber wp 1'),
(@ENTRY,21,4116.024,5324.498,29.75892, 'Fizzcrank Bomber wp 1'),
(@ENTRY,22,4113.869,5322.398,29.75901, 'Fizzcrank Bomber wp 1'),
(@ENTRY,23,4090.109,5298.56,29.70082, 'Fizzcrank Bomber wp 1'),
(@ENTRY,24,4079.459,5287.617,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,25,4066.779,5274.603,31.53571, 'Fizzcrank Bomber wp 1'),
(@ENTRY,26,4041.215,5249.248,31.45236, 'Fizzcrank Bomber wp 1'),
(@ENTRY,27,4020.432,5218.824,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,28,4002.392,5190.421,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,29,4000.105,5146.331,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,30,3993.002,5119.754,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,31,3976.405,5093.208,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,32,3983.637,5055.651,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,33,3990.106,5011.049,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,34,3992.433,4984.051,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,35,3988.744,4946.948,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,36,3975.796,4912.274,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,37,3958.111,4895.366,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,38,3928.622,4858.76,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,39,3921.781,4825.03,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,40,3935.435,4790.436,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,41,3966.323,4756.983,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,42,3987.75,4763.042,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,43,4025.366,4755.083,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,44,4050.189,4787.045,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,45,4082.41,4825.174,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,46,4084.739,4845.887,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,47,4082.781,4879.066,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,48,4075.255,4897.705,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,49,4063.763,4936.532,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,50,4066.78,4968.409,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,51,4082.993,4997.696,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,52,4110.507,5030.572,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,53,4141.148,5060.043,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,54,4164.455,5087.176,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,55,4189.664,5124.69,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,56,4214.33,5154.247,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,57,4237.962,5194.166,29.8968, 'Fizzcrank Bomber wp 1'),
(@ENTRY,58,4228.307,5238.578,42.11903, 'Fizzcrank Bomber wp 1'),
(@ENTRY,59,4200.375,5271.218,46.75792, 'Fizzcrank Bomber wp 1'),
(@ENTRY,60,4211.719,5318.444,47.13599, 'Fizzcrank Bomber wp 1'),
(@ENTRY,61,4229.69,5356.218,47.13599, 'Fizzcrank Bomber wp 1'),
(@ENTRY,62,4229.779,5396.165,53.08044, 'Fizzcrank Bomber wp 1'),
(@ENTRY,63,4231.299,5419.959,53.71933, 'Fizzcrank Bomber wp 1'),
(@ENTRY,64,4228.378,5466.135,57.13599, 'Fizzcrank Bomber wp 1'),
(@ENTRY,65,4249.183,5490.759,47.13599, 'Fizzcrank Bomber wp 1'),
(@ENTRY,66,4282.767,5500.858,48.85822, 'Fizzcrank Bomber wp 1'),
(@ENTRY,67,4300.521,5486.341,48.386, 'Fizzcrank Bomber wp 1'),
(@ENTRY,68,4291.369,5470.349,48.91378, 'Fizzcrank Bomber wp 1'),
(@ENTRY,69,4277.046,5454.25,47.13599, 'Fizzcrank Bomber wp 1'),
(@ENTRY,70,4253.641,5434.851,47.13599, 'Fizzcrank Bomber wp 1'),
(@ENTRY,71,4227.768,5423.928,47.13599, 'Fizzcrank Bomber wp 1'),
(@ENTRY,72,4204.012,5411.217,37.52486, 'Fizzcrank Bomber wp 1'),
(@ENTRY,73,4194.847,5402.538,32.41374, 'Fizzcrank Bomber wp 1'),
(@ENTRY,74,4178.285,5386.063,30.94151, 'Fizzcrank Bomber wp 1');
-- Remove Fizzcrank Bomber spawn
DELETE FROM `creature` WHERE `guid`=111452;
DELETE FROM `creature_addon` WHERE `guid`=111452;

-- Invisable Stalker SAI
SET @ENTRY := 15214;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=-106069;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-106069,0,0,1,38,0,100,0,0,1,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisable Stalker - on dataset 0 1 - dataset 0 0'),
(-106069,0,1,0,61,0,100,0,0,0,0,0,11,47453,3,0,0,0,0,11,25766,200,0,0,0,0,0, 'Invisable Stalker - on dataset 0 1 - Cast 47453 on Rig Hauler AC-9');

-- Fizzcrank Fighter SAI
SET @ENTRY := 26817;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Fighter - on spawn - start wp'),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Fighter - on spawn - say text 0'),
(@ENTRY,0,2,0,40,0,100,0,15,@ENTRY,0,0,11,43671,3,0,0,0,0,11,25765,20,0,0,0,0,0, 'Fizzcrank Fighter - Reach wp 15 - cast 43671 on Fizzcrank Bomber');
-- NPC talk text for Fizzcrank Fighter
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I''ll blast those gnomish wannabes back to the scrap heap!',0,7,100,0,0,0, 'Fizzcrank Fighter'),
(@ENTRY,0,1, 'You''re sending me back there?!',0,7,100,0,0,0, 'Fizzcrank Fighter');
-- Waypoints for Fizzcrank Fighter from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,4176.501,5280.566,27.17445, 'Fizzcrank Fighter'),
(@ENTRY,2,4167.001,5282.066,27.17445, 'Fizzcrank Fighter'),
(@ENTRY,3,4164.751,5282.566,26.92445, 'Fizzcrank Fighter'),
(@ENTRY,4,4162.655,5282.681,26.48916, 'Fizzcrank Fighter'),
(@ENTRY,5,4158.462,5280.628,26.26419, 'Fizzcrank Fighter'),
(@ENTRY,6,4155.712,5279.378,25.76419, 'Fizzcrank Fighter'),
(@ENTRY,7,4154.958,5278.939,24.86416, 'Fizzcrank Fighter'),
(@ENTRY,8,4147.710,5281.817,24.86416, 'Fizzcrank Fighter'),
(@ENTRY,9,4144.757,5295.502,25.61416, 'Fizzcrank Fighter'),
(@ENTRY,10,4142.652,5300.067,26.94346, 'Fizzcrank Fighter'),
(@ENTRY,11,4137.876,5308.749,27.94350, 'Fizzcrank Fighter'),
(@ENTRY,12,4135.610,5310.586,28.93834, 'Fizzcrank Fighter'),
(@ENTRY,13,4131.433,5312.564,28.75930, 'Fizzcrank Fighter'),
(@ENTRY,14,4123.820,5317.622,28.75930, 'Fizzcrank Fighter'),
(@ENTRY,15,4115.430,5321.649,28.75930, 'Fizzcrank Fighter');
-- Remove Fizzcrank Fighter spawns
DELETE FROM `creature` WHERE `guid` IN (114142,114143,114165);
DELETE FROM `creature_addon` WHERE `guid` IN (114142,114143,114165);

-- Pathing for Crafty Wobblesprocket SAI
SET @ENTRY := 25477;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=4172.788,`position_y`=5254.925,`position_z`=26.12851 WHERE `guid`=108021;
-- SAI for Crafty Wobblesprocket
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ENTRY*100,@ENTRY*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Crafty Wobblesprocket - On spawn - Start WP movement'),
(@ENTRY,0,1,2,40,0,100,0,1,@ENTRY,0,0,54,45000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crafty Wobblesprocket - Reach wp 1 - pause path'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crafty Wobblesprocket - Reach wp 1 - STATE_USESTANDING'),
(@ENTRY,0,3,4,40,0,100,0,6,@ENTRY,0,0,54,35000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crafty Wobblesprocket - Reach wp 6 - pause path'),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.4712389, 'Crafty Wobblesprocket - Reach wp 6 - turn to'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crafty Wobblesprocket - Reach wp 6 - STATE_WORK_MINING');
-- Waypoints for Crafty Wobblesprocket from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,4179.099,5251.51,26.37851, 'Crafty Wobblesprocket'),
(@ENTRY,2,4177.94,5250.202,26.87851, 'Crafty Wobblesprocket'),
(@ENTRY,3,4181.048,5243.429,24.87851, 'Crafty Wobblesprocket'),
(@ENTRY,4,4182.067,5222.448,25.00868, 'Crafty Wobblesprocket'),
(@ENTRY,5,4193.037,5217.233,25.13368, 'Crafty Wobblesprocket'),
(@ENTRY,6,4193.037,5217.233,25.13368, 'Crafty Wobblesprocket'),
(@ENTRY,7,4190.718,5217.938,25.25868, 'Crafty Wobblesprocket'),
(@ENTRY,8,4176.049,5229.444,24.50868, 'Crafty Wobblesprocket'),
(@ENTRY,9,4166.732,5248.798,24.75351, 'Crafty Wobblesprocket'),
(@ENTRY,10,4172.788,5254.925,26.12851, 'Crafty Wobblesprocket');
-- Remove Crafty Wobblesprocket dupe spawn
DELETE FROM `creature` WHERE `guid`=108025;
DELETE FROM `creature_addon` WHERE `guid`=108025;
-- Fix addon for Crafty Wobblesprocket
DELETE FROM `creature_addon` WHERE `guid`=108021;
DELETE FROM `creature_template_addon` WHERE `entry`=25477;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`) VALUES (25477,257);

-- SAI for ELM General Purpose Bunny
SET @ENTRY := 23837;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-98575,-98576);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-98575,0,0,0,1,0,100,0,10000,20000,90000,105000,11,45931,3,0,0,0,0,10,98576,23837,0,0,0,0,0, 'ELM General Purpose Bunny - OOC timed - cast 45931 on target'),
(-98576,0,0,0,8,0,100,0,45931,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit - run script'),
(@ENTRY*100,9,0,0,0,0,100,0,4000,4000,0,0,12,25783,3,60000,0,0,0,8,0,0,0,4181.491,5258.655,27.19127,3.857178, 'ELM General Purpose Bunny - script - summon 25783'),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,0,0,5,5,0,0,0,0,0,11,25747,10,0,0,0,0,0, 'ELM General Purpose Bunny - script - send emote to 25747'),
(@ENTRY*100,9,2,0,0,0,100,0,4000,4000,0,0,45,0,1,0,0,0,0,11,25783,10,0,0,0,0,0, 'ELM General Purpose Bunny - script - set data 0 1 on 25783');

-- SAI for Fizzcrank Airstrip Survivor
SET @ENTRY := 25783;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,34427,3,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Airstrip Survivor - on spawn - cast 34427 on self'),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Airstrip Survivor - on spawn - say text 0'),
(@ENTRY,0,2,3,38,0,100,0,0,1,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Airstrip Survivor - on dataset 0 1 - dataset 0 0'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Airstrip Survivor - on dataset 0 1 - Start WP movement'),
(@ENTRY,0,4,0,40,0,100,0,6,@ENTRY,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Airstrip Survivor - Reach wp 6 - despawn');
-- Waypoints for Fizzcrank Airstrip Survivor from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,4168.529,5251.933,24.87851, 'Fizzcrank Airstrip Survivor'),
(@ENTRY,2,4156.656,5256.007,24.62325, 'Fizzcrank Airstrip Survivor'),
(@ENTRY,3,4151.527,5268.997,25.36416, 'Fizzcrank Airstrip Survivor'),
(@ENTRY,4,4159.549,5281.078,26.23916, 'Fizzcrank Airstrip Survivor'),
(@ENTRY,5,4173.898,5280.844,26.69306, 'Fizzcrank Airstrip Survivor'),
(@ENTRY,6,4179.473,5282.701,26.69306, 'Fizzcrank Airstrip Survivor');
-- Remove Fizzcrank Airstrip Survivor spawn
DELETE FROM `creature` WHERE `guid` IN (88109);
DELETE FROM `creature_addon` WHERE `guid` IN (88109);
-- NPC talk text for Fizzcrank Survivor
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I''m flesh and blood again. That''s all that matters!',0,7,100,5,0,0, 'Fizzcrank Survivor');

-- Model and creature addon info (Nay)
UPDATE `creature_model_info` SET `bounding_radius`=0.3694949,`combat_reach`=1.81125,`gender`=1 WHERE `modelid`=23967; -- Chief Engineer Galpen Rolltie
UPDATE `creature_model_info` SET `bounding_radius`=0.3694949,`combat_reach`=1.81125,`gender`=1 WHERE `modelid`=23220; -- Crafty Wobblesprocket
-- Addon data for creature 26600 (Chief Engineer Galpen Rolltie)
DELETE FROM `creature_template_addon` WHERE `entry` IN (26600,26599,26634,26645,25766,15214,26817,23837,25783);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(26600,0,0,257,0, NULL), -- Chief Engineer Galpen Rolltie
(26599,0,0,257,0, NULL), -- Willis Wobblewheel
(26634,0,0,257,0, NULL), -- Fizzcrank Watcher Rupert Keeneye
(26645,0,0,257,0, NULL), -- Fizzcrank Engineering Crew
(25766,0,0,1,0, NULL), -- Rig Hauler AC-9
(15214,0,0,1,0, NULL), -- Invisible Stalker
(26817,0,0,257,0, NULL), -- Fizzcrank Fighter
(23837,0,0,1,0, NULL), -- ELM General Purpose Bunny
(25783,0,0,257,0, NULL); -- Fizzcrank Airstrip Survivor
