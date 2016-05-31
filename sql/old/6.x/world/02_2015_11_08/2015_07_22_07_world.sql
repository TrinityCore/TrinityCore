-- 4.x + 6.x
-- Update Sen'jin 
-- 1. Sen'jin Watcher
SET @NPC := 309577;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-774.362,`position_y`=-4940.641,`position_z`=38.26371 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-774.362,-4940.641,38.26371,0,0,0,0,100,0),
(@PATH,2,-772.362,-4941.141,37.26371,0,0,0,0,100,0),
(@PATH,3,-770.362,-4941.641,36.01371,0,0,0,0,100,0),
(@PATH,4,-767.862,-4942.141,34.76371,0,0,0,0,100,0),
(@PATH,5,-765.112,-4943.391,34.01371,0,0,0,0,100,0),
(@PATH,6,-762.362,-4946.141,32.26371,0,0,0,0,100,0),
(@PATH,7,-762.112,-4951.641,30.51371,0,0,0,0,100,0),
(@PATH,8,-763.612,-4953.891,30.01371,0,0,0,0,100,0),
(@PATH,9,-766.862,-4955.891,28.76371,0,0,0,0,100,0),
(@PATH,10,-770.862,-4955.391,27.01371,0,0,0,0,100,0),
(@PATH,11,-778.612,-4952.391,22.76371,0,0,0,0,100,0),
(@PATH,12,-782.112,-4950.141,22.76371,0,0,0,0,100,0),
(@PATH,13,-785.862,-4945.641,22.76371,0,0,0,0,100,0),
(@PATH,14,-785.862,-4945.641,22.76371,0,0,0,0,100,0),
(@PATH,15,-782.112,-4950.141,22.76371,0,0,0,0,100,0),
(@PATH,16,-778.612,-4952.391,22.76371,0,0,0,0,100,0),
(@PATH,17,-770.862,-4955.391,27.01371,0,0,0,0,100,0),
(@PATH,18,-766.862,-4955.891,28.76371,0,0,0,0,100,0),
(@PATH,19,-763.612,-4953.891,30.01371,0,0,0,0,100,0),
(@PATH,20,-762.112,-4951.641,30.51371,0,0,0,0,100,0),
(@PATH,21,-762.362,-4946.141,32.26371,0,0,0,0,100,0),
(@PATH,22,-765.112,-4943.391,34.01371,0,0,0,0,100,0),
(@PATH,23,-767.862,-4942.141,34.76371,0,0,0,0,100,0);

-- 2. Sen'jin Watcher
SET @NPC := 309553;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-788.7762,`position_y`=-4965.624,`position_z`=19.43634 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-788.7762,-4965.624,19.43634,0,0,0,0,100,0),
(@PATH,2,-781.7762,-4964.874,19.93634,0,0,0,0,100,0),
(@PATH,3,-775.0262,-4964.124,20.43634,0,0,0,0,100,0),
(@PATH,4,-774.7703,-4963.952,20.74989,0,0,0,0,100,0),
(@PATH,5,-773.0203,-4963.702,20.74989,0,0,0,0,100,0),
(@PATH,6,-768.5203,-4959.952,21.24989,0,0,0,0,100,0),
(@PATH,7,-765.3058,-4956.89,21.37057,0,0,0,0,100,0),
(@PATH,8,-759.7866,-4950.328,21.89624,0,0,0,0,100,0),
(@PATH,9,-751.9631,-4948.534,22.44588,0,0,0,0,100,0),
(@PATH,10,-805.9037,-4921.31,19.88782,0,0,0,0,100,0),
(@PATH,11,-750.4297,-4937.502,22.52872,0,0,0,0,100,0),
(@PATH,12,-749.4709,-4927.372,21.83175,0,0,0,0,100,0),
(@PATH,13,-748.5951,-4913.194,21.96598,0,0,0,0,100,0),
(@PATH,14,-749.0128,-4900.784,21.78021,0,0,0,0,100,0),
(@PATH,15,-754.0128,-4891.534,21.28021,0,0,0,0,100,0),
(@PATH,16,-756.5143,-4887.134,21.10391,0,0,0,0,100,0),
(@PATH,17,-767.7643,-4884.134,20.60391,0,0,0,0,100,0),
(@PATH,18,-768.1055,-4883.763,20.33025,0,0,0,0,100,0),
(@PATH,19,-769.6055,-4883.263,20.33025,0,0,0,0,100,0),
(@PATH,20,-778.4881,-4880.104,19.85901,0,0,0,0,100,0),
(@PATH,21,-779.7474,-4870.789,19.95952,0,0,0,0,100,0),
(@PATH,22,-787.483,-4865.899,19.7513,0,0,0,0,100,0),
(@PATH,23,-798.6328,-4862.984,19.64194,0,0,0,0,100,0),
(@PATH,24,-805.3547,-4861.628,20.10826,0,0,0,0,100,0),
(@PATH,25,-819.4501,-4861.991,20.30437,0,0,0,0,100,0),
(@PATH,26,-825.6534,-4863.626,20.41768,0,0,0,0,100,0),
(@PATH,27,-834.4034,-4864.626,20.91768,0,0,0,0,100,0),
(@PATH,28,-834.6238,-4865.104,20.96264,0,0,0,0,100,0),
(@PATH,29,-835.1238,-4865.104,20.96264,0,0,0,0,100,0),
(@PATH,30,-839.8738,-4865.354,21.46264,0,0,0,0,100,0),
(@PATH,31,-845.7614,-4865.818,20.94963,0,0,0,0,100,0),
(@PATH,32,-858.423,-4867.244,20.60074,0,0,0,0,100,0),
(@PATH,33,-862.423,-4866.494,19.85074,0,0,0,0,100,0),
(@PATH,34,-865.173,-4866.244,19.35074,0,0,0,0,100,0),
(@PATH,35,-867.173,-4865.994,18.85074,0,0,0,0,100,0),
(@PATH,36,-867.3206,-4865.913,18.5512,0,0,0,0,100,0),
(@PATH,37,-870.3206,-4865.413,17.8012,0,0,0,0,100,0),
(@PATH,38,-873.3206,-4865.413,17.0512,0,0,0,0,100,0),
(@PATH,39,-876.0706,-4865.663,16.5512,0,0,0,0,100,0),
(@PATH,40,-879.0706,-4865.663,16.0512,0,0,0,0,100,0),
(@PATH,41,-882.0706,-4865.663,15.3012,0,0,0,0,100,0),
(@PATH,42,-882.4172,-4865.551,15.09779,0,0,0,0,100,0),
(@PATH,43,-883.9172,-4865.551,15.09779,0,0,0,0,100,0),
(@PATH,44,-886.1672,-4867.551,14.34779,0,0,0,0,100,0),
(@PATH,45,-887.4172,-4868.801,13.84779,0,0,0,0,100,0),
(@PATH,46,-890.6672,-4871.051,13.09779,0,0,0,0,100,0),
(@PATH,47,-890.5367,-4871.14,12.67306,0,0,0,0,100,0),
(@PATH,48,-891.5367,-4871.89,12.67306,0,0,0,0,100,0),
(@PATH,49,-891.2867,-4875.89,11.92306,0,0,0,0,100,0),
(@PATH,50,-891.0367,-4878.64,11.42306,0,0,0,0,100,0),
(@PATH,51,-890.5367,-4882.64,10.92306,0,0,0,0,100,0),
(@PATH,52,-890.754,-4882.981,10.58318,0,0,0,0,100,0),
(@PATH,53,-890.504,-4885.481,10.58318,0,0,0,0,100,0),
(@PATH,54,-890.4144,-4901.542,11.04431,0,0,0,0,100,0),
(@PATH,55,-888.4144,-4906.792,11.54431,0,0,0,0,100,0),
(@PATH,56,-887.1644,-4910.542,12.29431,0,0,0,0,100,0),
(@PATH,57,-885.8495,-4913.504,13.02004,0,0,0,0,100,0),
(@PATH,58,-877.5995,-4916.004,13.27004,0,0,0,0,100,0),
(@PATH,59,-877.4609,-4916.193,13.52335,0,0,0,0,100,0),
(@PATH,60,-876.2109,-4916.693,14.27335,0,0,0,0,100,0),
(@PATH,61,-874.7109,-4919.193,14.77335,0,0,0,0,100,0),
(@PATH,62,-872.7109,-4922.193,15.77335,0,0,0,0,100,0),
(@PATH,63,-872.29,-4922.481,15.90952,0,0,0,0,100,0),
(@PATH,64,-871.29,-4924.731,16.15952,0,0,0,0,100,0),
(@PATH,65,-870.54,-4927.231,16.65952,0,0,0,0,100,0),
(@PATH,66,-869.6884,-4931.584,17.45385,0,0,0,0,100,0),
(@PATH,67,-869.9384,-4934.334,17.70385,0,0,0,0,100,0),
(@PATH,68,-870.2519,-4938.529,18.20204,0,0,0,0,100,0),
(@PATH,69,-880.9265,-4948.019,17.9512,0,0,0,0,100,0),
(@PATH,70,-883.6515,-4958.961,17.43941,0,0,0,0,100,0),
(@PATH,71,-878.4275,-4965.879,17.71656,0,0,0,0,100,0),
(@PATH,72,-871.6775,-4973.379,17.21656,0,0,0,0,100,0),
(@PATH,73,-869.9275,-4975.379,16.46656,0,0,0,0,100,0),
(@PATH,74,-868.6775,-4976.629,15.71656,0,0,0,0,100,0),
(@PATH,75,-867.1775,-4978.129,14.46656,0,0,0,0,100,0),
(@PATH,76,-866.6775,-4978.879,13.21656,0,0,0,0,100,0),
(@PATH,77,-865.1775,-4980.379,10.96656,0,0,0,0,100,0),
(@PATH,78,-864.4275,-4981.129,9.216558,0,0,0,0,100,0),
(@PATH,79,-863.1775,-4982.629,6.966558,0,0,0,0,100,0),
(@PATH,80,-861.9275,-4984.129,5.216558,0,0,0,0,100,0),
(@PATH,81,-861.1775,-4984.879,3.966558,0,0,0,0,100,0),
(@PATH,82,-861.5674,-4984.336,4.935531,0,0,0,0,100,0),
(@PATH,83,-860.8174,-4985.086,3.685531,0,0,0,0,100,0),
(@PATH,84,-860.3174,-4985.836,3.435531,0,0,0,0,100,0),
(@PATH,85,-859.3174,-4986.336,3.185531,0,0,0,0,100,0),
(@PATH,86,-857.5674,-4987.086,2.435531,0,0,0,0,100,0),
(@PATH,87,-836.4093,-4995.758,2.049099,0,0,0,0,100,0),
(@PATH,88,-827.9093,-4991.008,2.799099,0,0,0,0,100,0),
(@PATH,89,-825.1593,-4989.758,3.549099,0,0,0,0,100,0),
(@PATH,90,-824.4093,-4989.258,4.049099,0,0,0,0,100,0),
(@PATH,91,-823.4093,-4988.758,4.549099,0,0,0,0,100,0),
(@PATH,92,-821.6593,-4987.758,5.299099,0,0,0,0,100,0),
(@PATH,93,-823.2853,-4988.467,4.836733,0,0,0,0,100,0),
(@PATH,94,-821.5353,-4987.467,5.586733,0,0,0,0,100,0),
(@PATH,95,-820.2853,-4986.967,5.836733,0,0,0,0,100,0),
(@PATH,96,-819.0353,-4985.217,6.586733,0,0,0,0,100,0),
(@PATH,97,-818.0353,-4983.967,7.086733,0,0,0,0,100,0),
(@PATH,98,-817.2853,-4982.967,7.586733,0,0,0,0,100,0),
(@PATH,99,-816.2853,-4981.967,8.336733,0,0,0,0,100,0),
(@PATH,100,-815.2853,-4980.217,9.336733,0,0,0,0,100,0),
(@PATH,101,-814.5353,-4979.217,9.336733,0,0,0,0,100,0),
(@PATH,102,-814.5353,-4978.217,10.08673,0,0,0,0,100,0),
(@PATH,103,-814.1273,-4977.845,10.43529,0,0,0,0,100,0),
(@PATH,104,-814.1273,-4975.845,10.93529,0,0,0,0,100,0),
(@PATH,105,-814.3773,-4974.845,10.43529,0,0,0,0,100,0),
(@PATH,106,-813.3773,-4974.595,11.43529,0,0,0,0,100,0),
(@PATH,107,-812.6273,-4974.095,12.18529,0,0,0,0,100,0),
(@PATH,108,-811.6273,-4973.595,13.68529,0,0,0,0,100,0),
(@PATH,109,-810.8773,-4973.095,14.68529,0,0,0,0,100,0),
(@PATH,110,-809.8773,-4972.845,15.93529,0,0,0,0,100,0),
(@PATH,111,-808.8773,-4972.345,17.18529,0,0,0,0,100,0),
(@PATH,112,-808.1273,-4971.845,17.18529,0,0,0,0,100,0),
(@PATH,113,-807.3773,-4970.845,17.68529,0,0,0,0,100,0),
(@PATH,114,-804.1273,-4968.845,18.18529,0,0,0,0,100,0),
(@PATH,115,-800.5168,-4970.606,18.5153,0,0,0,0,100,0),
(@PATH,116,-793.2668,-4967.606,18.7653,0,0,0,0,100,0);

-- 3. Sen'jin Watcher
SET @NPC := 309550;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-844.9097,`position_y`=-5010.656,`position_z`=1.994938 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-844.9097,-5010.656,1.994938,0,0,0,0,100,0),
(@PATH,2,-842.6597,-5001.656,1.994938,0,0,0,0,100,0),
(@PATH,3,-837.4097,-4992.406,1.994938,0,0,0,0,100,0),
(@PATH,4,-832.4097,-4984.906,3.994938,0,0,0,0,100,0),
(@PATH,5,-826.4097,-4971.656,8.994938,0,0,0,0,100,0),
(@PATH,6,-824.4097,-4962.156,12.49494,0,0,0,0,100,0),
(@PATH,7,-824.8302,-4945.764,18.41039,0,0,0,0,100,0),
(@PATH,8,-824.8302,-4944.014,18.91039,0,0,0,0,100,0),
(@PATH,9,-824.8184,-4942.014,19.3798,4.764749,0,0,0,100,0),
(@PATH,10,-824.6479,-4945.156,18.46435,0,0,0,0,100,0),
(@PATH,11,-824.6479,-4952.156,16.21435,0,0,0,0,100,0),
(@PATH,12,-824.3979,-4961.656,12.71435,0,0,0,0,100,0),
(@PATH,13,-827.1479,-4971.656,8.964352,0,0,0,0,100,0),
(@PATH,14,-834.1479,-4988.906,2.714352,0,0,0,0,100,0),
(@PATH,15,-840.8979,-4997.656,1.964352,0,0,0,0,100,0),
(@PATH,16,-844.8979,-5009.406,1.964352,0,0,0,0,100,0);

-- Randmovement
UPDATE `creature` SET `spawndist`=4, `MovementType`=1 WHERE  `guid`=309541;
UPDATE `creature` SET `spawndist`=8, `MovementType`=1 WHERE  `id` IN (3106, 3125, 3099);

-- Emotes

-- Trayexir SAI
SET @ENTRY := 10369;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,7000,15000,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trayexir - Out of Combat - Play Emote 11");

-- K'waii SAI
SET @ENTRY := 3186;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,7000,15000,5,94,0,0,0,0,0,1,0,0,0,0,0,0,0,"K'waii - Out of Combat - Play Emote 94");


-- Tai'tasi SAI
SET @ENTRY := 3187;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,7000,15000,5,94,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tai'tasi - Out of Combat - Play Emote 94");

-- Parata SAI
SET @ENTRY := 50001;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,3000,5000,10,1,5,0,0,0,0,1,0,0,0,0,0,0,0,"Parata - Out of Combat - Play Random Emote (1, 5)");

-- Bomsanchu SAI
SET @ENTRY := 50002;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,3000,5000,10,1,5,0,0,0,0,1,0,0,0,0,0,0,0,"Bomsanchu - Out of Combat - Play Random Emote (1, 5)");

-- Gusini SAI
SET @ENTRY := 49998;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,3000,5000,10,1,5,0,0,0,0,1,0,0,0,0,0,0,0,"Gusini - Out of Combat - Play Random Emote (1, 5)");

-- Cona SAI
SET @ENTRY := 50011;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,3000,5000,10,1,5,0,0,0,0,1,0,0,0,0,0,0,0,"Cona - Out of Combat - Play Random Emote (1, 5)");

-- Den'chulu SAI
SET @ENTRY := 49997;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,3000,5000,10,1,5,0,0,0,0,1,0,0,0,0,0,0,0,"Den'chulu - Out of Combat - Play Random Emote (1, 5)");

DELETE FROM `creature_template_addon` WHERE `entry` IN (5942, 3184);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(5942,0,0,0,1,94, ''),
(3184,0,0,0,1,94, '');
