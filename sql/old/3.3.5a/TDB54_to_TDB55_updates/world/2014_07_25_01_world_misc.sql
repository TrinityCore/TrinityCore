-- Pathing for Captain Dranarus Entry: 25138
SET @NPC := 96619;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1842.622,`position_y`=5313.065,`position_z`=-12.42815 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_scripts` WHERE `id` BETWEEN 10 AND 14;
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`guid`) VALUES
(10,0,1,5,10),(11,0,1,18,11),(12,0,1,21,12),(13,0,1,273,13),(14,0,1,22,14),(14,0,16,9739,15);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1842.622,5313.065,-12.42815,0,2000,0,0,100,0),
(@PATH,2,-1842.622,5313.065,-12.42815,2.478368,4000,0,50,100,0), -- OneShotPoint (25)
(@PATH,3,-1842.622,5313.065,-12.42815,0,4000,0,1006,100,0), -- OneShotQuestion (6)
(@PATH,4,-1842.622,5313.065,-12.42815,0,12000,0,14,100,0), -- OneShotShot (22) -- play sound 9739
(@PATH,5,-1842.622,5313.065,-12.42815,0,4000,0,11,100,0), -- OneShotCry (18)
(@PATH,6,-1850.026,5310.596,-12.42815,0,0,0,0,100,0),
(@PATH,7,-1852.461,5313.779,-12.42815,0,0,0,0,100,0),
(@PATH,8,-1851.368,5318.353,-12.42815,0,0,0,0,100,0),
(@PATH,9,-1843.579,5320.41,-12.42815,0,0,0,0,100,0),
(@PATH,10,-1840.255,5319.294,-12.42815,0,1000,0,0,100,0),
(@PATH,11,-1840.255,5319.294,-12.42815,4.502949,4000,0,50,100,0), -- OneShotPoint (25)
(@PATH,12,-1840.255,5319.294,-12.42815,0,13000,0,10,100,0), -- OneShotExclamation (5)
(@PATH,13,-1840.255,5319.294,-12.42815,0,4000,0,12,100,0), -- OneShotApplaud (21)
(@PATH,14,-1835.1,5320.241,-12.42815,0,0,0,0,100,0),
(@PATH,15,-1835.244,5316.951,-12.42815,0,1000,0,0,100,0),
(@PATH,16,-1835.23,5317.261,-12.42815,3.141593,20000,0,0,100,0),
(@PATH,17,-1835.23,5317.261,-12.42815,0,11000,0,14,100,0), -- OneShotShot (22) -- play sound 9739
(@PATH,18,-1840.227,5311.866,-12.42815,0,0,0,0,100,0),
(@PATH,19,-1842.643,5312.999,-12.42815,0,1000,0,0,100,0),
(@PATH,20,-1842.643,5312.999,-12.42815,1.239184,4000,0,50,100,0), -- OneShotPoint (25)
(@PATH,21,-1842.643,5312.999,-12.42815,0,7000,0,1012,100,0), -- OneShotNo (274)
(@PATH,22,-1842.643,5312.999,-12.42815,0,3000,0,50,100,0), -- OneShotPoint (25)
(@PATH,23,-1842.643,5312.999,-12.42815,0,7000,0,484,100,0), -- OneShotLaugh (11)
(@PATH,24,-1847.878,5310.522,-12.42815,0,0,0,0,100,0),
(@PATH,25,-1851.1,5314.04,-12.42815,0,1000,0,0,100,0),
(@PATH,26,-1851.1,5314.04,-12.42815,0.08726646,5000,0,0,100,0),
(@PATH,27,-1851.1,5314.04,-12.42815,0,21000,0,14,100,0), -- OneShotShot (22) -- play sound 9739
(@PATH,28,-1846.24,5319.435,-12.42815,0,0,0,0,100,0),
(@PATH,29,-1843.72,5318.517,-12.42815,0,0,0,0,100,0),
(@PATH,30,-1843.72,5318.517,-12.42815,5.445427,7000,0,50,100,0), -- OneShotPoint (25)
(@PATH,31,-1843.72,5318.517,-12.42815,0,4000,0,13,100,0), -- OneShotYes (273)
(@PATH,32,-1843.72,5318.517,-12.42815,0,11000,0,12,100,0), -- OneShotApplaud (21)
(@PATH,33,-1836.766,5321.29,-12.42815,0,0,0,0,100,0),
(@PATH,34,-1835.244,5316.951,-12.42815,0,21000,0,0,100,0),
(@PATH,35,-1835.244,5316.951,-12.42815,3.141593,10000,0,14,100,0), -- OneShotShot (22) -- play sound 9739
(@PATH,36,-1840.227,5311.866,-12.42815,0,0,0,0,100,0);

-- Shattered Sun Trainee SAI "Emotes 36 and 54 missing sounds 134, 147, 149, 1002, 7080 core issue"
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (25134,25135,25136,25137);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-96595,-96596,-96600,-96603,-96604,-96610,-96611,-96612);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-96595,0,0,0,1,0,100,0,0,3000,3000,3000,10,36,43,54,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Trainee - Out of Combat - Emote OneShotAttack1H or OneShotParryShield"),
(-96596,0,0,0,1,0,100,0,0,3000,3000,3000,10,36,43,54,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Trainee - Out of Combat - Emote OneShotAttack1H or OneShotParryShield"),
(-96600,0,0,0,1,0,100,0,0,3000,3000,3000,10,36,43,54,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Trainee - Out of Combat - Emote OneShotAttack1H or OneShotParryShield"),
(-96603,0,0,0,1,0,100,0,0,3000,3000,3000,10,36,43,54,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Trainee - Out of Combat - Emote OneShotAttack1H or OneShotParryShield"),
(-96604,0,0,0,1,0,100,0,0,3000,3000,3000,10,36,43,54,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Trainee - Out of Combat - Emote OneShotAttack1H or OneShotParryShield"),
(-96610,0,0,0,1,0,100,0,0,3000,3000,3000,10,36,43,54,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Trainee - Out of Combat - Emote OneShotAttack1H or OneShotParryShield"),
(-96611,0,0,0,1,0,100,0,0,3000,3000,3000,10,36,43,54,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Trainee - Out of Combat - Emote OneShotAttack1H or OneShotParryShield"),
(-96612,0,0,0,1,0,100,0,0,3000,3000,3000,10,36,43,54,0,0,0,1,0,0,0,0,0,0,0,"Shattered Sun Trainee - Out of Combat - Emote OneShotAttack1H or OneShotParryShield");

-- Skyguard Neather Ray Should not be moving
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE guid=79011;

-- Add missing Shattrath City Peacekeeper
DELETE FROM `creature` WHERE `guid`=45075;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(45075, 19687, 530, 1, 1, -1976.909, 5112.424, 7.589328, 4.276057, 120, 0, 0);

-- Pathing for Shattrath City Peacekeeper Entry: 19687
SET @NPC := 70228;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1966.495,`position_y`=5121.907,`position_z`=10.32379 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,17063, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1966.495,5121.907,10.32379,0,0,0,0,100,0),
(@PATH,2,-1951.699,5166.294,17.25317,0,0,0,0,100,0),
(@PATH,3,-1938.637,5205.161,15.87822,0,0,0,0,100,0),
(@PATH,4,-1931.686,5226.178,13.69076,0,0,0,0,100,0),
(@PATH,5,-1916.49,5271.667,3.115327,0,0,0,0,100,0),
(@PATH,6,-1907.977,5296.765,1.137226,0,0,0,0,100,0),
(@PATH,7,-1901.641,5315.616,0.8860542,0,0,0,0,100,0),
(@PATH,8,-1907.977,5296.765,1.137226,0,0,0,0,100,0),
(@PATH,9,-1916.49,5271.667,3.115327,0,0,0,0,100,0),
(@PATH,10,-1931.686,5226.178,13.69076,0,0,0,0,100,0),
(@PATH,11,-1938.637,5205.161,15.87822,0,0,0,0,100,0),
(@PATH,12,-1951.699,5166.294,17.25317,0,0,0,0,100,0);

-- Pathing for Vekax Entry: 22429
SET @NPC := 78783;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1668.65,`position_y`=5531.648,`position_z`=2.084388 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1668.65,5531.648,2.084388,0,0,0,0,100,0),
(@PATH,2,-1675.535,5539.932,4.808745,0,0,0,0,100,0),
(@PATH,3,-1669.465,5544.53,5.413347,0,0,0,0,100,0),
(@PATH,4,-1656.403,5534.61,6.1091,0,0,0,0,100,0),
(@PATH,5,-1642.701,5537.171,6.172705,0,0,0,0,100,0),
(@PATH,6,-1641.732,5532.27,5.289427,0,0,0,0,100,0),
(@PATH,7,-1638.772,5516.784,-3.276233,0,0,0,0,100,0),
(@PATH,8,-1633.397,5489.191,-14.53821,0,0,0,0,100,0),
(@PATH,9,-1629.011,5484.991,-14.49736,0,0,0,0,100,0),
(@PATH,10,-1624.565,5486.951,-14.3688,0,0,0,0,100,0),
(@PATH,11,-1615.755,5487.401,-14.04851,0,0,0,0,100,0),
(@PATH,12,-1606.827,5480.522,-14.09892,0,0,0,0,100,0),
(@PATH,13,-1602.518,5469.729,-14.09986,0,0,0,0,100,0),
(@PATH,14,-1604.27,5462.537,-14.10011,0,0,0,0,100,0),
(@PATH,15,-1612.627,5453.875,-14.09042,0,0,0,0,100,0),
(@PATH,16,-1623.32,5451.606,-14.07838,0,0,0,0,100,0),
(@PATH,17,-1633.862,5457.565,-14.19732,0,0,0,0,100,0),
(@PATH,18,-1637.261,5469.756,-14.69115,0,0,0,0,100,0),
(@PATH,19,-1632.431,5481.022,-14.52123,0,0,0,0,100,0),
(@PATH,20,-1637.261,5469.756,-14.69115,0,0,0,0,100,0),
(@PATH,21,-1633.862,5457.565,-14.19732,0,0,0,0,100,0),
(@PATH,22,-1623.32,5451.606,-14.07838,0,0,0,0,100,0),
(@PATH,23,-1612.843,5453.652,-14.09002,0,0,0,0,100,0),
(@PATH,24,-1604.27,5462.537,-14.10011,0,0,0,0,100,0),
(@PATH,25,-1602.518,5469.729,-14.09986,0,0,0,0,100,0),
(@PATH,26,-1606.827,5480.522,-14.09892,0,0,0,0,100,0),
(@PATH,27,-1615.755,5487.401,-14.04851,0,0,0,0,100,0),
(@PATH,28,-1624.565,5486.951,-14.3688,0,0,0,0,100,0),
(@PATH,29,-1629.011,5484.991,-14.49736,0,0,0,0,100,0),
(@PATH,30,-1633.36,5489.002,-14.55791,0,0,0,0,100,0),
(@PATH,31,-1638.772,5516.784,-3.276233,0,0,0,0,100,0),
(@PATH,32,-1641.732,5532.27,5.289427,0,0,0,0,100,0),
(@PATH,33,-1642.701,5537.171,6.172705,0,0,0,0,100,0),
(@PATH,34,-1656.217,5534.645,6.133076,0,0,0,0,100,0),
(@PATH,35,-1669.465,5544.53,5.413347,0,0,0,0,100,0),
(@PATH,36,-1675.535,5539.932,4.808745,0,0,0,0,100,0),
(@PATH,37,-1668.774,5531.669,2.197366,0,0,0,0,100,0),
(@PATH,38,-1648.668,5528.287,-5.18554,0,0,0,0,100,0);

-- Pathing for Skettis Outcast Entry: 19075
SET @NPC := 68385;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1622.079,`position_y`=5473.997,`position_z`=-4.175363 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1622.079,5473.997,-4.175363,0,0,0,0,100,0),
(@PATH,2,-1624.692,5470.754,-4.14517,0,0,0,0,100,0),
(@PATH,3,-1624.417,5467.651,-4.055672,0,0,0,0,100,0),
(@PATH,4,-1622.095,5464.667,-4.021505,0,0,0,0,100,0),
(@PATH,5,-1618.157,5464.342,-4.122393,0,0,0,0,100,0),
(@PATH,6,-1614.648,5466.909,-3.965191,0,0,0,0,100,0),
(@PATH,7,-1614.635,5471.312,-4.240356,0,0,0,0,100,0),
(@PATH,8,-1618.361,5474.586,-3.982594,0,0,0,0,100,0);
