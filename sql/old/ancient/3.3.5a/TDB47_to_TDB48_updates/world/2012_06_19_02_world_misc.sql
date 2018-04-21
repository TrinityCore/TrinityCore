-- Add missing spawns
SET @GUID  := 42875;
SET @ENTRY := 26257;
DELETE FROM `creature` WHERE `guid` IN (@GUID,@GUID+1);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,@ENTRY,571,1,1,0,0,3369.694,2528.735,197.4004,3.490659,180,0,0,1,0,0),
(@GUID+1,@ENTRY,571,1,1,0,0,3346.363,2534.127,197.4004,4.258604,180,0,0,1,0,0);
-- Add SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-42875,-42876,-109574,-109575) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-42875,0,0,0,1,0,100,1,1000,1000,30000,30000,11,46906,2,0,0,0,0,10,115101,27853,0,0,0,0,0,'Surge Needle Sorcerer - OOC - Cast Surge Needle Beam'),
(-42875,0,1,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Surge Needle Sorcerer - Combat - Cast Arcane Blast on victim'),
(-42876,0,0,0,1,0,100,1,1000,1000,30000,30000,11,46906,2,0,0,0,0,10,115101,27853,0,0,0,0,0,'Surge Needle Sorcerer - OOC - Cast Surge Needle Beam'),
(-42876,0,1,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Surge Needle Sorcerer - Combat - Cast Arcane Blast on victim'),
(-109574,0,0,0,1,0,100,1,1000,1000,30000,30000,11,46906,2,0,0,0,0,10,115101,27853,0,0,0,0,0,'Surge Needle Sorcerer - OOC - Cast Surge Needle Beam'),
(-109574,0,1,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Surge Needle Sorcerer - Combat - Cast Arcane Blast on victim'),
(-109575,0,0,0,1,0,100,1,1000,1000,30000,30000,11,46906,2,0,0,0,0,10,115101,27853,0,0,0,0,0,'Surge Needle Sorcerer - OOC - Cast Surge Needle Beam'),
(-109575,0,1,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Surge Needle Sorcerer - Combat - Cast Arcane Blast on victim');
-- Add missing go
SET @GUID  := 325;
SET @ENTRY := 188448;
DELETE FROM `gameobject` WHERE `guid` IN (@GUID);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID,@ENTRY,571,1,1,3346.398,2534.092,197.3171,2.82743,0,0,0.9876881,0.1564362,180,255,1);

-- Pathing for Nexus Guardian
SET @NPC := 111304;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26276,571,1,1,0,0,3560.472,1769.351,171.9977,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`) VALUES (@NPC,@PATH,50331648,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3560.472,1769.351,171.9977,0,0,0,100,0),
(@PATH,2,3567.688,1720.065,171.9977,0,0,0,100,0),
(@PATH,3,3575.305,1671.264,171.9977,0,0,0,100,0),
(@PATH,4,3614.985,1641.572,171.9977,0,0,0,100,0),
(@PATH,5,3661.11,1627.888,179.4142,0,0,0,100,0),
(@PATH,6,3710.721,1625.472,184.0807,0,0,0,100,0),
(@PATH,7,3758.05,1626.899,186.8029,0,0,0,100,0),
(@PATH,8,3806.817,1636.863,186.8029,0,0,0,100,0),
(@PATH,9,3855.013,1638.274,186.8029,0,0,0,100,0),
(@PATH,10,3893.953,1607.221,186.8029,0,0,0,100,0),
(@PATH,11,3908.07,1563.533,186.8029,0,0,0,100,0),
(@PATH,12,3892.732,1516.304,186.8029,0,0,0,100,0),
(@PATH,13,3853.05,1486.712,186.8029,0,0,0,100,0),
(@PATH,14,3804.016,1484.734,186.8029,0,0,0,100,0),
(@PATH,15,3768.95,1518.886,186.8029,0,0,0,100,0),
(@PATH,16,3741.332,1558.961,193.6083,0,0,0,100,0),
(@PATH,17,3735.918,1607.949,197.9415,0,0,0,100,0),
(@PATH,18,3726.846,1656.945,201.9971,0,0,0,100,0),
(@PATH,19,3706.031,1701.895,208.3303,0,0,0,100,0),
(@PATH,20,3693.807,1748.982,208.3303,0,0,0,100,0),
(@PATH,21,3686.946,1791.952,208.3303,0,0,0,100,0),
(@PATH,22,3684.135,1840.943,208.3303,0,0,0,100,0),
(@PATH,23,3693.31,1889.799,208.3303,0,0,0,100,0),
(@PATH,24,3710.331,1936.957,208.3303,0,0,0,100,0),
(@PATH,25,3708.896,1985.871,203.9415,0,0,0,100,0),
(@PATH,26,3711.546,2034.778,199.0248,0,0,0,100,0),
(@PATH,27,3700.25,2079.795,185.8581,0,0,0,100,0),
(@PATH,28,3671.014,2118.18,175.6918,0,0,0,100,0),
(@PATH,29,3627.495,2141.961,170.8588,0,0,0,100,0),
(@PATH,30,3582.266,2162.844,165.0257,0,0,0,100,0),
(@PATH,31,3536.079,2181.72,161.0814,0,0,0,100,0),
(@PATH,32,3492.185,2203.827,153.3039,0,0,0,100,0),
(@PATH,33,3449.847,2227.899,147.0816,0,0,0,100,0),
(@PATH,34,3411.07,2258.388,138.6929,0,0,0,100,0),
(@PATH,35,3372.244,2288.043,130.0542,0,0,0,100,0),
(@PATH,36,3334.966,2320.363,127.8878,0,0,0,100,0),
(@PATH,37,3302.867,2358.885,123.2211,0,0,0,100,0),
(@PATH,38,3272.494,2397.996,120.9432,0,0,0,100,0),
(@PATH,39,3239.637,2434.888,118.8322,0,0,0,100,0),
(@PATH,40,3212.678,2476.519,116.0821,0,0,0,100,0),
(@PATH,41,3211.545,2525.56,108.0818,0,0,0,100,0),
(@PATH,42,3250.958,2578.278,107.5538,0,0,0,100,0),
(@PATH,43,3293.958,2602.603,107.5538,0,0,0,100,0),
(@PATH,44,3342.687,2610.276,112.9983,0,0,0,100,0),
(@PATH,45,3386.911,2594.68,123.2483,0,0,0,100,0),
(@PATH,46,3415.89,2554.956,128.7483,0,0,0,100,0),
(@PATH,47,3424.978,2506.423,128.7483,0,0,0,100,0),
(@PATH,48,3417.17,2457.855,128.7483,0,0,0,100,0),
(@PATH,49,3403.204,2427.43,128.7483,0,0,0,100,0),
(@PATH,50,3373.681,2392.189,128.7483,0,0,0,100,0),
(@PATH,51,3355.053,2347.842,128.7483,0,0,0,100,0),
(@PATH,52,3358.651,2298.717,128.7483,0,0,0,100,0),
(@PATH,53,3365.574,2249.818,135.9983,0,0,0,100,0),
(@PATH,54,3382.769,2202.925,136.9983,0,0,0,100,0),
(@PATH,55,3406.081,2159.531,144.9981,0,0,0,100,0),
(@PATH,56,3435.854,2119.649,151.8868,0,0,0,100,0),
(@PATH,57,3465.756,2080.089,151.8868,0,0,0,100,0),
(@PATH,58,3482.463,2041.774,142.5257,0,0,0,100,0),
(@PATH,59,3503.596,1996.099,137.0257,0,0,0,100,0),
(@PATH,60,3521.709,1951.099,137.0257,0,0,0,100,0),
(@PATH,61,3531.027,1914.229,150.5535,0,0,0,100,0),
(@PATH,62,3542.625,1866.008,158.9424,0,0,0,100,0),
(@PATH,63,3550.662,1817.174,163.9979,0,0,0,100,0);
