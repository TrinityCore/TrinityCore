-- Twilight Ridge, Nagrand Update
SET @OGUID := 5479;
SET @CGUID := 77840;

DELETE FROM `gameobject` WHERE `guid`=@OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 186177, 530, 1, 1, -1537.953, 9728.839, 202.396, 3.141593, 0, 0, 0, 1, 120, 255, 1);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 22341, 530, 1, 1, -1442.521, 9847.013, 200.6711, 6.021386, 300, 0, 0),
(@CGUID+1, 22341, 530, 1, 1, -1455.099, 9854.964, 200.7248, 2.513274, 300, 0, 0),
(@CGUID+2, 22342, 530, 1, 1, -1452.337, 9837.591, 200.6221, 1.815142, 300, 0, 0);

DELETE FROM creature WHERE id IN (22362);

-- Deathshadow Overlord SAI
SET @ENTRY := 22393;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,15228,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Overlord - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,6000,8000,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Overlord - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,8000,15000,20000,35000,11,37579,32,0,0,0,0,6,0,0,0,0,0,0,0,"Deathshadow Overlord - In Combat - Cast 'Impending Doom'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Overlord - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Deathshadow Warlock SAI
SET @ENTRY := 22363;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM creature_addon WHERE guid IN (SELECT guid FROM creature WHERE id=@ENTRY);
UPDATE `creature_template_addon` SET `auras`= '39102' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Out of Combat - Cast 'Demon Armor'"),
(@ENTRY,0,1,0,25,0,100,1,3000,3000,0,0,11,38980,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - On Reset - Cast 'Summon Twilight Ridge Imp' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Warlock - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,3,0,0,0,100,0,4000,8000,18000,24000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Warlock - In Combat - Cast 'Immolate'"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Warlock - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Deathshadow Hound SAI
SET @ENTRY := 22394;
DELETE FROM creature_addon WHERE guid=78726;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`= '18950' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,6000,12000,11,30639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Hound - In Combat - Cast 'Carnivorous Bite'");

-- Deathshadow Imp SAI
SET @ENTRY := 22362;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,20801,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Imp - In Combat CMC - Cast 'Firebolt'");

-- Deathshadow Acolyte SAI
SET @ENTRY := 22341;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`= '39102' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,8000,14000,11,32000,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Acolyte - In Combat - Cast 'Mind Sear'");

-- Deathshadow Spellbinder SAI
SET @ENTRY := 22342;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`= '39102' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,20000,20000,11,39123,0,0,0,0,0,19,22400,35,0,0,0,0,0,"Deathshadow Spellbinder - Out of Combat - Cast 'Purple Beam'"),
(@ENTRY,0,1,0,1,0,100,0,15000,15000,20000,20000,92,0,39123,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Out of Combat - Interupt Cast 'Purple Beam'"),
(@ENTRY,0,2,0,0,0,100,0,0,40,2400,3800,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Spellbinder - In Combat CMC - Cast 'Arcane Missiles'"),
(@ENTRY,0,3,0,0,0,100,0,9000,14000,14000,20000,11,22744,0,0,0,0,0,5,0,0,0,0,0,0,0,"Deathshadow Spellbinder - In Combat - Cast 'Chains of Ice'"),
(@ENTRY,0,4,0,0,0,100,0,6000,9000,7000,14000,11,31999,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Spellbinder - In Combat - Cast 'Counterspell'"),
(@ENTRY,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Spellbinder - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Deathshadow Archon SAI
SET @ENTRY := 22343;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,12000,18000,11,31996,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Archon - In Combat - Cast 'Bloodthirst'"),
(@ENTRY,0,1,2,2,0,100,1,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Archon - Between 0-20% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathshadow Archon - Between 0-20% Health - Say Line 0 (No Repeat)");

-- Twilight Ridge Target
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid` IN (78732,78733,78734);
UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `id`=23026;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=22400;

-- Pathing for Reth'hedron the Subduer Entry: 22357
SET @NPC := 86754;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1470.79,`position_y`=9695.277,`position_z`=201.9155 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1470.79,9695.277,201.9155,0,0,0,0,100,0),
(@PATH,2,-1463.57,9667.397,201.1194,0,0,0,0,100,0),
(@PATH,3,-1435.975,9657.146,201.4469,0,0,0,0,100,0),
(@PATH,4,-1413.262,9667.886,200.9825,0,0,0,0,100,0),
(@PATH,5,-1402.246,9689.202,200.9537,0,0,0,0,100,0),
(@PATH,6,-1414.642,9716.702,202.2037,0,0,0,0,100,0),
(@PATH,7,-1441.109,9724.775,200.4537,0,0,0,0,100,0),
(@PATH,8,-1461.794,9742.569,200.4468,0,0,0,0,100,0),
(@PATH,9,-1469.654,9771.815,199.9872,0,0,0,0,100,0),
(@PATH,10,-1469.748,9806.641,201.1348,0,0,0,0,100,0),
(@PATH,11,-1502.839,9806.935,199.2431,0,0,0,0,100,0),
(@PATH,12,-1514.049,9782.884,199.0504,0,0,0,0,100,0),
(@PATH,13,-1507.741,9758.235,200.8756,0,0,0,0,100,0),
(@PATH,14,-1497.913,9735.084,200.8304,0,0,0,0,100,0),
(@PATH,15,-1479.92,9715.552,200.603,0,0,0,0,100,0);

-- Pathing for Deathshadow Overlord Entry: 22393
SET @NPC := 78720;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1472.134,`position_y`=9677.515,`position_z`=200.7376 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1472.134,9677.515,200.7376,0,0,0,0,100,0),
(@PATH,2,-1491.902,9675.239,200.4876,0,0,0,0,100,0),
(@PATH,3,-1513.64,9685.378,199.8625,0,0,0,0,100,0),
(@PATH,4,-1520.162,9704.591,199.7671,0,0,0,0,100,0),
(@PATH,5,-1524.718,9729.45,200.9875,0,0,0,0,100,0),
(@PATH,6,-1530.212,9756.966,199.9298,0,0,0,0,100,0),
(@PATH,7,-1532.913,9774.135,199.8195,0,0,0,0,100,0),
(@PATH,8,-1530.212,9756.966,199.9298,0,0,0,0,100,0),
(@PATH,9,-1524.718,9729.45,200.9875,0,0,0,0,100,0),
(@PATH,10,-1520.162,9704.591,199.7671,0,0,0,0,100,0),
(@PATH,11,-1513.64,9685.378,199.8625,0,0,0,0,100,0),
(@PATH,12,-1491.902,9675.239,200.4876,0,0,0,0,100,0);

-- Pathing for Deathshadow Overlord Entry: 22393
SET @NPC := 78721;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1612.896,`position_y`=9760.403,`position_z`=201.8589 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1612.896,9760.403,201.8589,0,0,0,0,100,0),
(@PATH,2,-1607.772,9783.831,203.7104,0,0,0,0,100,0),
(@PATH,3,-1612.043,9799.692,204.3501,0,0,0,0,100,0),
(@PATH,4,-1619.067,9821.793,203.2391,0,0,0,0,100,0),
(@PATH,5,-1611.496,9847.096,202.69,0,0,0,0,100,0),
(@PATH,6,-1599.807,9862.187,202.3747,0,0,0,0,100,0),
(@PATH,7,-1581.539,9874.061,201.7294,0,0,0,0,100,0),
(@PATH,8,-1555.31,9883.893,201.0461,0,0,0,0,100,0),
(@PATH,9,-1526.078,9884.972,201.6419,0,0,0,0,100,0),
(@PATH,10,-1499.578,9886.692,200.8129,0,0,0,0,100,0),
(@PATH,11,-1526.078,9884.972,201.6419,0,0,0,0,100,0),
(@PATH,12,-1555.31,9883.893,201.0461,0,0,0,0,100,0),
(@PATH,13,-1581.539,9874.061,201.7294,0,0,0,0,100,0),
(@PATH,14,-1599.807,9862.187,202.3747,0,0,0,0,100,0),
(@PATH,15,-1611.496,9847.096,202.69,0,0,0,0,100,0),
(@PATH,16,-1619.067,9821.793,203.2391,0,0,0,0,100,0),
(@PATH,17,-1612.043,9799.692,204.3501,0,0,0,0,100,0),
(@PATH,18,-1607.772,9783.831,203.7104,0,0,0,0,100,0);

-- Pathing for Deathshadow Overlord Entry: 22393
SET @NPC := 78722;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1403.312,`position_y`=9723.152,`position_z`=202.818 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1403.312,9723.152,202.818,0,0,0,0,100,0),
(@PATH,2,-1401.001,9745.885,201.6062,0,0,0,0,100,0),
(@PATH,3,-1406.874,9760.674,203.3052,0,0,0,0,100,0),
(@PATH,4,-1421.809,9777.302,201.2571,0,0,0,0,100,0),
(@PATH,5,-1437.867,9789.925,200.9305,0,0,0,0,100,0),
(@PATH,6,-1439.766,9805.536,201.9659,0,0,0,0,100,0),
(@PATH,7,-1454.237,9824.521,199.9593,0,0,0,0,100,0),
(@PATH,8,-1472.978,9831.495,200.4266,0,0,0,0,100,0),
(@PATH,9,-1497.168,9823.096,199.8583,0,0,0,0,100,0),
(@PATH,10,-1472.978,9831.495,200.4266,0,0,0,0,100,0),
(@PATH,11,-1454.237,9824.521,199.9593,0,0,0,0,100,0),
(@PATH,12,-1439.766,9805.536,201.9659,0,0,0,0,100,0),
(@PATH,13,-1437.867,9789.925,200.9305,0,0,0,0,100,0),
(@PATH,14,-1421.809,9777.302,201.2571,0,0,0,0,100,0),
(@PATH,15,-1406.874,9760.674,203.3052,0,0,0,0,100,0),
(@PATH,16,-1401.001,9745.885,201.6062,0,0,0,0,100,0);

-- Pathing for Deathshadow Overlord Entry: 22393
SET @NPC := 78723;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1453.536,`position_y`=9636.821,`position_z`=201.6882 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1453.536,9636.821,201.6882,0,0,0,0,100,0),
(@PATH,2,-1432.65,9646.109,201.1936,0,0,0,0,100,0),
(@PATH,3,-1405.079,9634.173,200.4417,0,0,0,0,100,0),
(@PATH,4,-1376.064,9616.104,201.409,0,0,0,0,100,0),
(@PATH,5,-1359.878,9605.575,202.9046,0,0,0,0,100,0),
(@PATH,6,-1340.019,9602.568,203.2547,0,0,0,0,100,0),
(@PATH,7,-1324.825,9604.699,203.3278,0,0,0,0,100,0),
(@PATH,8,-1307.901,9605.091,203.8469,0,0,0,0,100,0),
(@PATH,9,-1324.825,9604.699,203.3278,0,0,0,0,100,0),
(@PATH,10,-1340.019,9602.568,203.2547,0,0,0,0,100,0),
(@PATH,11,-1359.878,9605.575,202.9046,0,0,0,0,100,0),
(@PATH,12,-1376.064,9616.104,201.409,0,0,0,0,100,0),
(@PATH,13,-1405.079,9634.173,200.4417,0,0,0,0,100,0),
(@PATH,14,-1432.65,9646.109,201.1936,0,0,0,0,100,0);

-- Pathing for Deathshadow Overlord Entry: 22393
SET @NPC := 78724;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1402.76,`position_y`=9588.803,`position_z`=204.4954 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1402.76,9588.803,204.4954,0,0,0,0,100,0),
(@PATH,2,-1419.219,9590.156,203.1769,0,0,0,0,100,0),
(@PATH,3,-1438.877,9599.831,202.1304,0,0,0,0,100,0),
(@PATH,4,-1453.35,9623.946,201.2587,0,0,0,0,100,0),
(@PATH,5,-1456.293,9653.96,201.7509,0,0,0,0,100,0),
(@PATH,6,-1453.35,9623.946,201.2587,0,0,0,0,100,0),
(@PATH,7,-1438.877,9599.831,202.1304,0,0,0,0,100,0),
(@PATH,8,-1419.219,9590.156,203.1769,0,0,0,0,100,0);

-- Deathshadow Archon / Hound Formations
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (78605,78607,78608,78609,78611);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`)VALUES
(78605,78605,0,0,2),(78605,78725,3,90,2),
(78607,78607,0,0,2),(78607,78726,3,90,2),
(78608,78608,0,0,2),(78608,78727,3,90,2),
(78609,78609,0,0,2),(78609,78728,3,90,2),
(78611,78611,0,0,2),(78611,78729,3,90,2);

-- Pathing for Deathshadow Archon Entry: 22343
SET @NPC := 78605;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1534.346,`position_y`=9692.919,`position_z`=201.5745 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1534.346,9692.919,201.5745,0,0,0,0,100,0),
(@PATH,2,-1528.828,9701.563,200.6345,0,0,0,0,100,0),
(@PATH,3,-1524.337,9711.724,200.1727,0,0,0,0,100,0),
(@PATH,4,-1523.669,9722.655,200.5154,0,0,0,0,100,0),
(@PATH,5,-1526.62,9737.559,201.3112,0,0,0,0,100,0),
(@PATH,6,-1532.228,9749.707,201.0745,0,0,0,0,100,0),
(@PATH,7,-1541.164,9759.324,201.4725,0,0,0,0,100,0),
(@PATH,8,-1549.85,9760.534,201.3854,0,0,0,0,100,0),
(@PATH,9,-1556.002,9754.084,202.2479,0,0,0,0,100,0),
(@PATH,10,-1561.292,9745.524,202.4582,0,0,0,0,100,0),
(@PATH,11,-1556.002,9754.084,202.2479,0,0,0,0,100,0),
(@PATH,12,-1549.85,9760.534,201.3854,0,0,0,0,100,0),
(@PATH,13,-1541.164,9759.324,201.4725,0,0,0,0,100,0),
(@PATH,14,-1532.228,9749.707,201.0745,0,0,0,0,100,0),
(@PATH,15,-1526.62,9737.559,201.3112,0,0,0,0,100,0),
(@PATH,16,-1523.669,9722.655,200.5154,0,0,0,0,100,0),
(@PATH,17,-1524.337,9711.724,200.1727,0,0,0,0,100,0),
(@PATH,18,-1528.828,9701.563,200.6345,0,0,0,0,100,0);

-- Pathing for Deathshadow Archon Entry: 22343
SET @NPC := 78607;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1440.525,`position_y`=9826.043,`position_z`=200.2045 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1440.525,9826.043,200.2045,0,0,0,0,100,0),
(@PATH,2,-1450.976,9827.416,199.9427,0,0,0,0,100,0),
(@PATH,3,-1462.63,9831.848,200.9427,0,0,0,0,100,0),
(@PATH,4,-1473.203,9842.879,199.9138,0,0,0,0,100,0),
(@PATH,5,-1480.496,9852.528,200.9736,0,0,0,0,100,0),
(@PATH,6,-1482.375,9864.082,200.7059,0,0,0,0,100,0),
(@PATH,7,-1473.433,9874.989,200.3353,0,0,0,0,100,0),
(@PATH,8,-1455.629,9873.264,200.673,0,0,0,0,100,0),
(@PATH,9,-1441.467,9870.78,201.3422,0,0,0,0,100,0),
(@PATH,10,-1428.149,9859.59,200.5119,0,0,0,0,100,0),
(@PATH,11,-1425.271,9844.913,200.1369,0,0,0,0,100,0);

-- Pathing for Deathshadow Archon Entry: 22343
SET @NPC := 78608;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1380.653,`position_y`=9741.172,`position_z`=204.1218 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1380.653,9741.172,204.1218,0,0,0,0,100,0),
(@PATH,2,-1366.514,9729.669,205.0716,0,0,0,0,100,0),
(@PATH,3,-1358.867,9717.195,205.8663,0,0,0,0,100,0),
(@PATH,4,-1359.007,9702.771,204.7408,0,0,0,0,100,0),
(@PATH,5,-1362.371,9691.935,204.1954,0,0,0,0,100,0),
(@PATH,6,-1372.498,9687.396,203.4136,0,0,0,0,100,0),
(@PATH,7,-1382.632,9687.841,202.6673,0,0,0,0,100,0),
(@PATH,8,-1392.327,9693.781,202.8044,0,0,0,0,100,0),
(@PATH,9,-1401.115,9712.122,204.2574,0,0,0,0,100,0),
(@PATH,10,-1400.316,9733.862,202.404,0,0,0,0,100,0),
(@PATH,11,-1391.65,9744.087,202.7115,0,0,0,0,100,0);

-- Pathing for Deathshadow Archon Entry: 22343
SET @NPC := 78609;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1319.207,`position_y`=9624.372,`position_z`=202.1915 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1319.207,9624.372,202.1915,0,0,0,0,100,0),
(@PATH,2,-1313.734,9614.496,202.0793,0,0,0,0,100,0),
(@PATH,3,-1307.775,9608.104,203.4543,0,0,0,0,100,0),
(@PATH,4,-1296.253,9600.599,204.4624,0,0,0,0,100,0),
(@PATH,5,-1288.214,9592.333,205.6772,0,0,0,0,100,0),
(@PATH,6,-1281.956,9581.45,207.4987,0,0,0,0,100,0),
(@PATH,7,-1278.26,9572.817,209.6956,0,0,0,0,100,0),
(@PATH,8,-1274.736,9562.393,213.2931,0,0,0,0,100,0),
(@PATH,9,-1278.26,9572.813,209.7968,0,0,0,0,100,0),
(@PATH,10,-1281.956,9581.45,207.4987,0,0,0,0,100,0),
(@PATH,11,-1288.214,9592.333,205.6772,0,0,0,0,100,0),
(@PATH,12,-1296.253,9600.599,204.4624,0,0,0,0,100,0),
(@PATH,13,-1307.6,9607.918,203.4799,0,0,0,0,100,0),
(@PATH,14,-1313.734,9614.496,202.0793,0,0,0,0,100,0);

-- Pathing for Deathshadow Archon Entry: 22343
SET @NPC := 78611;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1404.827,`position_y`=9588.393,`position_z`=204.2825 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1404.827,9588.393,204.2825,0,0,0,0,100,0),
(@PATH,2,-1394.6,9596.54,203.1423,0,0,0,0,100,0),
(@PATH,3,-1383.312,9601.47,202.3112,0,0,0,0,100,0),
(@PATH,4,-1368.525,9602.146,202.7189,0,0,0,0,100,0),
(@PATH,5,-1356.474,9599.088,203.8475,0,0,0,0,100,0),
(@PATH,6,-1350.076,9591.939,205.7526,0,0,0,0,100,0),
(@PATH,7,-1356.474,9599.088,203.8475,0,0,0,0,100,0),
(@PATH,8,-1368.525,9602.146,202.7189,0,0,0,0,100,0),
(@PATH,9,-1383.312,9601.47,202.3112,0,0,0,0,100,0),
(@PATH,10,-1394.6,9596.54,203.1423,0,0,0,0,100,0);

-- Pathing for Deathshadow Hound Entry: 22394
SET @NPC := 78725;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1534.346,`position_y`=9692.919,`position_z`=201.5745 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1534.346,9692.919,201.5745,0,0,0,0,100,0),
(@PATH,2,-1528.828,9701.563,200.6345,0,0,0,0,100,0),
(@PATH,3,-1524.337,9711.724,200.1727,0,0,0,0,100,0),
(@PATH,4,-1523.669,9722.655,200.5154,0,0,0,0,100,0),
(@PATH,5,-1526.62,9737.559,201.3112,0,0,0,0,100,0),
(@PATH,6,-1532.228,9749.707,201.0745,0,0,0,0,100,0),
(@PATH,7,-1541.164,9759.324,201.4725,0,0,0,0,100,0),
(@PATH,8,-1549.85,9760.534,201.3854,0,0,0,0,100,0),
(@PATH,9,-1556.002,9754.084,202.2479,0,0,0,0,100,0),
(@PATH,10,-1561.292,9745.524,202.4582,0,0,0,0,100,0),
(@PATH,11,-1556.002,9754.084,202.2479,0,0,0,0,100,0),
(@PATH,12,-1549.85,9760.534,201.3854,0,0,0,0,100,0),
(@PATH,13,-1541.164,9759.324,201.4725,0,0,0,0,100,0),
(@PATH,14,-1532.228,9749.707,201.0745,0,0,0,0,100,0),
(@PATH,15,-1526.62,9737.559,201.3112,0,0,0,0,100,0),
(@PATH,16,-1523.669,9722.655,200.5154,0,0,0,0,100,0),
(@PATH,17,-1524.337,9711.724,200.1727,0,0,0,0,100,0),
(@PATH,18,-1528.828,9701.563,200.6345,0,0,0,0,100,0);

-- Pathing for Deathshadow Hound Entry: 22394
SET @NPC := 78726;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1440.525,`position_y`=9826.043,`position_z`=200.2045 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1440.525,9826.043,200.2045,0,0,0,0,100,0),
(@PATH,2,-1450.976,9827.416,199.9427,0,0,0,0,100,0),
(@PATH,3,-1462.63,9831.848,200.9427,0,0,0,0,100,0),
(@PATH,4,-1473.203,9842.879,199.9138,0,0,0,0,100,0),
(@PATH,5,-1480.496,9852.528,200.9736,0,0,0,0,100,0),
(@PATH,6,-1482.375,9864.082,200.7059,0,0,0,0,100,0),
(@PATH,7,-1473.433,9874.989,200.3353,0,0,0,0,100,0),
(@PATH,8,-1455.629,9873.264,200.673,0,0,0,0,100,0),
(@PATH,9,-1441.467,9870.78,201.3422,0,0,0,0,100,0),
(@PATH,10,-1428.149,9859.59,200.5119,0,0,0,0,100,0),
(@PATH,11,-1425.271,9844.913,200.1369,0,0,0,0,100,0);

-- Pathing for Deathshadow Hound Entry: 22394
SET @NPC := 78727;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1380.653,`position_y`=9741.172,`position_z`=204.1218 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1380.653,9741.172,204.1218,0,0,0,0,100,0),
(@PATH,2,-1366.514,9729.669,205.0716,0,0,0,0,100,0),
(@PATH,3,-1358.867,9717.195,205.8663,0,0,0,0,100,0),
(@PATH,4,-1359.007,9702.771,204.7408,0,0,0,0,100,0),
(@PATH,5,-1362.371,9691.935,204.1954,0,0,0,0,100,0),
(@PATH,6,-1372.498,9687.396,203.4136,0,0,0,0,100,0),
(@PATH,7,-1382.632,9687.841,202.6673,0,0,0,0,100,0),
(@PATH,8,-1392.327,9693.781,202.8044,0,0,0,0,100,0),
(@PATH,9,-1401.115,9712.122,204.2574,0,0,0,0,100,0),
(@PATH,10,-1400.316,9733.862,202.404,0,0,0,0,100,0),
(@PATH,11,-1391.65,9744.087,202.7115,0,0,0,0,100,0);

-- Pathing for Deathshadow Hound Entry: 22394
SET @NPC := 78728;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1319.207,`position_y`=9624.372,`position_z`=202.1915 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1319.207,9624.372,202.1915,0,0,0,0,100,0),
(@PATH,2,-1313.734,9614.496,202.0793,0,0,0,0,100,0),
(@PATH,3,-1307.775,9608.104,203.4543,0,0,0,0,100,0),
(@PATH,4,-1296.253,9600.599,204.4624,0,0,0,0,100,0),
(@PATH,5,-1288.214,9592.333,205.6772,0,0,0,0,100,0),
(@PATH,6,-1281.956,9581.45,207.4987,0,0,0,0,100,0),
(@PATH,7,-1278.26,9572.817,209.6956,0,0,0,0,100,0),
(@PATH,8,-1274.736,9562.393,213.2931,0,0,0,0,100,0),
(@PATH,9,-1278.26,9572.813,209.7968,0,0,0,0,100,0),
(@PATH,10,-1281.956,9581.45,207.4987,0,0,0,0,100,0),
(@PATH,11,-1288.214,9592.333,205.6772,0,0,0,0,100,0),
(@PATH,12,-1296.253,9600.599,204.4624,0,0,0,0,100,0),
(@PATH,13,-1307.6,9607.918,203.4799,0,0,0,0,100,0),
(@PATH,14,-1313.734,9614.496,202.0793,0,0,0,0,100,0);

-- Pathing for Deathshadow Hound Entry: 22394
SET @NPC := 78729;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1404.827,`position_y`=9588.393,`position_z`=204.2825 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1404.827,9588.393,204.2825,0,0,0,0,100,0),
(@PATH,2,-1394.6,9596.54,203.1423,0,0,0,0,100,0),
(@PATH,3,-1383.312,9601.47,202.3112,0,0,0,0,100,0),
(@PATH,4,-1368.525,9602.146,202.7189,0,0,0,0,100,0),
(@PATH,5,-1356.474,9599.088,203.8475,0,0,0,0,100,0),
(@PATH,6,-1350.076,9591.939,205.7526,0,0,0,0,100,0),
(@PATH,7,-1356.474,9599.088,203.8475,0,0,0,0,100,0),
(@PATH,8,-1368.525,9602.146,202.7189,0,0,0,0,100,0),
(@PATH,9,-1383.312,9601.47,202.3112,0,0,0,0,100,0),
(@PATH,10,-1394.6,9596.54,203.1423,0,0,0,0,100,0);
